/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * test_instruments.cpp
 * Directly instantiates FaustInstrument wrappers and tests them using instrument-specific testing functions.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unistd.h>
#include <memory>
#include <algorithm>
#include <chrono>
#include <fftw3.h>
#include "../src/FaustMixer.hpp"
#include "../src/InstrumentMapper.hpp"
#include "../src/FaustInstrument.hpp"

// =====================================================
// HELPER: compute RMS and peak from stereo buffer
// =====================================================
static float computeRMS(const float* buf, int numFrames) {
    float sumSq = 0.0f;
    for (int i = 0; i < numFrames * 2; ++i)
        sumSq += buf[i] * buf[i];
    return std::sqrt(sumSq / (numFrames * 2));
}

static float computePeak(const float* buf, int numFrames) {
    float peak = 0.0f;
    for (int i = 0; i < numFrames * 2; ++i) {
        float a = std::abs(buf[i]);
        if (a > peak) peak = a;
    }
    return peak;
}

// =====================================================
// HELPER: FFTW-based pitch detection
// =====================================================
// FFTW3 (libfftw3) computes the FFT; we window the steady-state tail with a
// Hann window, find the spectral peak within nominal*(0.8..1.2), then parabolic
// interpolation gives a sub-bin frequency estimate.
// Returns estimated pitch in Hz, or 0 if unreliable.
static float detectPitchFFT(const float* mono, int len, float sampleRate, float nominalFreq) {
    int n = 1;
    while (n * 2 <= len) n <<= 1;
    if (n < 64) return 0.0f;

    std::vector<double> in(n, 0.0);
    std::vector<fftw_complex> out(n / 2 + 1);
    int start = len - n;
    for (int i = 0; i < n; ++i) {
        double w = 0.5 * (1.0 - std::cos(2.0 * M_PI * i / (n - 1)));
        in[i] = mono[start + i] * w;
    }

    fftw_plan plan = fftw_plan_dft_r2c_1d(n, in.data(), out.data(), FFTW_ESTIMATE);
    if (!plan) return 0.0f;
    fftw_execute(plan);
    fftw_destroy_plan(plan);

    int kMin = std::max(1, (int)(nominalFreq * 0.8 * n / sampleRate));
    int kMax = std::min(n / 2 - 1, (int)(nominalFreq * 1.2 * n / sampleRate));
    if (kMax <= kMin) return 0.0f;

    int peak = kMin;
    double bestMag = -1.0;
    for (int k = kMin; k <= kMax; ++k) {
        double mag = std::sqrt(out[k][0] * out[k][0] + out[k][1] * out[k][1]);
        if (mag > bestMag) { bestMag = mag; peak = k; }
    }
    if (peak <= kMin || peak >= kMax || bestMag <= 0.0) return 0.0f;

    double mPrev = std::sqrt(out[peak - 1][0] * out[peak - 1][0] + out[peak - 1][1] * out[peak - 1][1]);
    double mNext = std::sqrt(out[peak + 1][0] * out[peak + 1][0] + out[peak + 1][1] * out[peak + 1][1]);
    double denom = mPrev - 2.0 * bestMag + mNext;
    double delta = (std::abs(denom) > 1e-9) ? 0.5 * (mPrev - mNext) / denom : 0.0;
    delta = std::max(-0.5, std::min(0.5, delta));
    return (float)((peak + delta) * sampleRate / n);
}


// =====================================================
// HELPER: print horizontal freq,energy from diagnostic logs
// =====================================================
static void printEnergy(FaustInstrument* inst, double baseFreq) {
    if (!inst) return;
    auto logs = inst->getDiagnosticLogs();
    if (logs.empty()) {
        std::cout << "{ " << baseFreq << ", 0.0, 0.0 }";
        return;
    }

    auto targets = inst->getDiagnosticFreqs();
    float sampleRate = inst->getSampleRate();

    // value3 is now RMS (sqrt of power), just average it directly
    float sumRMS = 0.0f;
    float maxPeak = 0.0f;
    std::vector<float> sumSqGoertzel(targets.size(), 0.0f);

    for (const auto& log : logs) {
        sumRMS += log.value3;
        if (log.peak > maxPeak) maxPeak = log.peak;
        
        if (!log.rawAudio.empty() && !targets.empty()) {
            int remaining = log.rawAudio.size() / 2; // Stereo interleaved
            for (size_t t = 0; t < targets.size(); ++t) {
                float targetFreq = targets[t];
                float k = (remaining * targetFreq) / sampleRate;
                float omega = (2.0f * M_PI * k) / remaining;
                float coeff = 2.0f * cos(omega);
                float q1 = 0.0f;
                float q2 = 0.0f;
                for (int i = 0; i < remaining; ++i) {
                    float x = (log.rawAudio[i * 2] + log.rawAudio[i * 2 + 1]) * 0.5f;
                    float q0 = coeff * q1 - q2 + x;
                    q2 = q1;
                    q1 = q0;
                }
                float magnitudeSq = q1 * q1 + q2 * q2 - q1 * q2 * coeff;
                float magnitude = sqrt(std::max(0.0f, magnitudeSq)) / remaining;
                sumSqGoertzel[t] += magnitude * magnitude;
            }
        }
    }

    float avgRMS = sumRMS / logs.size();
    std::cout << "{ " << baseFreq << ", " << avgRMS << ", P=" << maxPeak;
    for (size_t t = 0; t < targets.size(); ++t) {
        float avgGoertzel = std::sqrt(sumSqGoertzel[t] / logs.size());
        std::cout << ", G" << t << "=" << avgGoertzel;
    }
    std::cout << " }";
}

// =====================================================
// INSTRUMENT-SPECIFIC TEST FUNCTIONS
// =====================================================

static float gTestVelocity = 0.8f;
static float gTestPressure = -1.0f; // -1 means use default or LUT
static double gTestFrequency = -1.0; // -1 means use default test sequence
static float gTestStrike = 0.0f; // default strike for calibration
static bool gTestScan = false;
static std::string gDumpWav; // if non-empty, write the last rendered buffer to this path
static std::map<std::string,float> gParamOverrides; // applied right after noteOn (bypasses LUT)

static std::vector<double> getTestFreqsDouble(FaustInstrument* inst, const std::vector<double>& defaultFreqs) {
    if (gTestFrequency > 0.0) {
        return { gTestFrequency };
    }
    float fmin = 0, fmax = 0;
    if (inst && inst->getParamBounds("freq", fmin, fmax)) {
        std::vector<double> dynamicFreqs;
        for (int midi = 12; midi <= 108; midi += 4) {
            double freq = 440.0 * std::pow(2.0, (midi - 69.0) / 12.0);
            if (freq >= fmin && freq <= fmax) {
                dynamicFreqs.push_back(freq);
            }
        }
        if (!dynamicFreqs.empty()) return dynamicFreqs;
        return { fmin, fmin + (fmax - fmin)*0.5, fmax };
    }
    return defaultFreqs;
}

static std::vector<double> getTestFreqsDouble(const std::vector<double>& defaultFreqs) { // fallback
    if (gTestFrequency > 0.0) {
        return { gTestFrequency };
    }
    return defaultFreqs;
}


static void testPolyphonicChord(FaustInstrument* inst) {
    if (!inst) return;
    std::cout << "\n  [Polyphony Test] C4 aug7 Chord (C4, E4, G#4, Bb4) ..." << std::endl;
    std::vector<double> chord = { 261.63, 329.63, 415.30, 466.16 };
    inst->clearDiagnosticLogs();
    for (double f : chord) inst->noteOn(f, gTestVelocity, gTestVelocity);
    usleep(2000000);
    for (double f : chord) inst->noteOff();
    usleep(500000);
    std::cout << "  Polyphony Energy: ";
    printEnergy(inst, 261.63);
    std::cout << std::endl;
}

static std::vector<float> getTestFreqsFloat(const std::vector<float>& defaultFreqs) {
    if (gTestFrequency > 0.0) {
        return { static_cast<float>(gTestFrequency) };
    }
    return defaultFreqs;
}



void testDayan(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dayan ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(0, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);

    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 130.81, 170.00, 210.00, 261.63 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::vector<float> strikes = { 0.0f, 1.0f, 2.0f, 3.0f };
        if (gTestStrike >= 0.0f) strikes = { gTestStrike };
        for (float strike : strikes) {
            int s = static_cast<int>(strike);
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq * 1.0f);
            inst->addDiagnosticFreq(freq * 1.593f);
            inst->addDiagnosticFreq(freq * 2.0f);
            inst->addDiagnosticFreq(freq * 2.135f);
            inst->addDiagnosticFreq(freq * 2.295f);
            inst->addDiagnosticFreq(freq * 2.653f);
            inst->addDiagnosticFreq(freq * 3.0f);
            inst->addDiagnosticFreq(freq * 4.0f);
            inst->addDiagnosticFreq(freq * 5.0f);
            
            inst->clearDiagnosticLogs();
            if (s == 0 || s == 3) {
                inst->setDiagnosticSamplingTimes({0.05f, 0.10f, 0.15f});
            } else {
                inst->setDiagnosticSamplingTimes({0.30f, 0.50f, 0.70f});
            }
            std::cout << "freq:" << freq << " strike:" << strike << "\n";
            inst->noteOn(freq, gTestVelocity, strike);
            usleep(1000000);
            inst->noteOff();
            usleep(500000);
            
            printEnergy(inst.get(), freq);
            std::cout << "\n" << std::flush;
        }
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testBayan(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bayan ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(1, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.4f); // Reduced from 0.8f to prevent clipping
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 65.41, 85.00, 105.00, 130.81 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::vector<float> strikes = { 0.0f, 1.0f, 2.0f, 3.0f };
        if (gTestStrike >= 0.0f) strikes = { gTestStrike };
        for (float strike : strikes) {
            int s = static_cast<int>(strike);
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq * 1.0f);
            inst->addDiagnosticFreq(freq * 1.593f);
            inst->addDiagnosticFreq(freq * 2.0f);
            inst->addDiagnosticFreq(freq * 2.135f);
            inst->addDiagnosticFreq(freq * 2.295f);
            inst->addDiagnosticFreq(freq * 2.653f);
            inst->addDiagnosticFreq(freq * 3.0f);
            inst->addDiagnosticFreq(freq * 4.0f);
            inst->addDiagnosticFreq(freq * 5.0f);
            
            inst->clearDiagnosticLogs();
            if (s == 0 || s == 3) {
                inst->setDiagnosticSamplingTimes({0.05f, 0.10f, 0.15f});
            } else {
                inst->setDiagnosticSamplingTimes({0.30f, 0.50f, 0.70f});
            }
            std::cout << "freq:" << freq << " strike:" << strike << "\n";
            inst->noteOn(freq, gTestVelocity, strike);
            usleep(1000000);
            inst->noteOff();
            usleep(500000);
            
            printEnergy(inst.get(), freq);
            std::cout << "\n" << std::flush;
        }
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testMridangam(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Mridangam ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(49, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 146.83, 146.83, 146.83, 146.83, 146.83, 146.83 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        float strike = static_cast<float>(i % 6);
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, strike);
        usleep(2500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1500000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testGhatam(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Ghatam ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(50, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 130.81, 130.81, 130.81, 130.81, 130.81 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        float strike = static_cast<float>(i % 5);
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, strike);
        usleep(2500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1500000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testKick(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Kick ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(2, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 65.41, 98.00, 130.81 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, 1.0f);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testSnare(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Snare (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(3, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 150.0, 180.0, 220.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testHiHat(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] HiHat ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(4, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    struct { float strike; const char* bol; int sleep; } hits[] = {
        {0.0f, "ch", 2000000},
        {1.0f, "oh", 2500000},
        {2.0f, "fc", 1500000},
    };
    for (int i = 0; i < 3; ++i) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(0);
        inst->clearDiagnosticLogs();
        inst->noteOn(0.0f, gTestVelocity, gTestVelocity);
        usleep(hits[i].sleep);
        inst->noteOff();
        if (i < 2) usleep(1000000);
        printEnergy(inst.get(), 0.0);
        std::cout << "_" << hits[i].bol;
        if (i < 2) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testTom(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tom (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(5, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 80.0, 110.0, 140.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testRide(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Ride (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(6, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 4000.0, 5500.0, 7000.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testBell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bell ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(7, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 261.63, 329.63, 392.00 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, 0.0f);
        usleep(3500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1500000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testBowl(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bowl ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(8, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, 0.0f);
        usleep(2500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(800000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testSitar(FaustMixer& mixer, DSPExecutionType execType) {
    auto inst = std::make_shared<FaustInstrument>(9, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs;
    std::vector<float> amps;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
        amps = { gTestVelocity > 0.0f ? gTestVelocity : 0.8f };
        std::cout << "\n=== [Test] Sitar (single: " << freqs[0] << " Hz @ " << amps[0] << ") ===" << std::endl;
    } else {
        std::cout << "\n=== [Test] Sitar (80–600 Hz CSV range) ===" << std::endl;
        freqs = { 140, 165, 196, 220, 261, 293, 330, 392, 440, 523, 587, 659 };
        amps = { 0.2f, 0.5f, 0.9f };
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        for (size_t j = 0; j < amps.size(); ++j) {
            float amp = amps[j];
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq);
            inst->clearDiagnosticLogs();
            inst->noteOn(freq, amp, amp);
            usleep(1800000);
            inst->noteOff();
            if (j < amps.size() - 1) usleep(800000);
            printEnergy(inst.get(), (double)(int)freq);
            std::cout << "_" << amp;
            if (j < amps.size() - 1) std::cout << " , ";
            std::cout << std::flush;
        }
        if (i < freqs.size() - 1) std::cout << " | ";
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testFlute(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Flute (C4 to C6 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(10, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestVelocity);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    if (gTestPressure >= 0.0f) {
        inst->setParam("pressure", gTestPressure);
    } else {
        inst->setParam("pressure", 0.40f);
    }
    inst->setParam("vibrato", 0.05f);
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        std::vector<int> scale = {60, 62, 64, 65, 67, 69, 71, 72, 74, 76, 77, 79, 81, 83, 84};
        for (int m : scale) {
            freqs.push_back(440.0 * pow(2.0, (m - 69.0) / 12.0));
        }
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(200000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testTanpura(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tanpura Polyphony ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(11, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    // Add all three frequencies as diagnostic targets to measure their energies simultaneously
    inst->clearDiagnosticFreqs();
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
        inst->addDiagnosticFreq(gTestFrequency);
    } else {
        freqs = { 130.00, 180.50, 231.00 };
        inst->addDiagnosticFreq(130.00);
        inst->addDiagnosticFreq(180.50);
        inst->addDiagnosticFreq(231.00);
    }

    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        std::cout << "\n";
    }
    std::cout << std::endl;

    if (gTestFrequency <= 0.0) {
        // Fire all three notes sequentially with overlapping sustains (no noteOff)
        inst->noteOn(130.00, gTestVelocity, -1.0f);
        usleep(500000); // 500ms between plucks
        
        inst->noteOn(180.50, gTestVelocity, -1.0f);
        usleep(500000); // 500ms between plucks
        
        inst->noteOn(231.00, gTestVelocity, -1.0f);
        usleep(500000); 

        inst->noteOn(260.00, gTestVelocity, -1.0f);
        usleep(2000000); // Let them ring out together for 2.0s, capturing logs
        
        auto now = std::chrono::system_clock::now();
        auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
        std::cout << "[TIMESTAMP " << ms << "] Polyphony Verification { Base, RMS, E_130, E_180_5, E_231 }: ";
        printEnergy(inst.get(), 0.0);
        std::cout << std::endl;

        if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    }

    mixer.removeTrack(track);
}

void testPiano(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Piano (C2 to C5 Chromatic) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(12, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->setDiagnosticSamplingTimes({0.1f, 0.2f, 0.3f});
    inst->setParam("stiffness", 0.15f);
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        for (int midi = 36; midi <= 72; ++midi) {
            freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1000000);
        inst->noteOff();
        usleep(200000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

void testSax(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sax (C3 to C5 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(13, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        for (int midi = 48; midi <= 72; ++midi) {
            int noteInOctave = midi % 12;
            if (noteInOctave == 0 || noteInOctave == 2 || noteInOctave == 4 || 
                noteInOctave == 5 || noteInOctave == 7 || noteInOctave == 9 || 
                noteInOctave == 11) {
                freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
            }
        }
    }
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1000000);
        inst->noteOff();
        usleep(200000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testTrumpet(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Trumpet (C3 to C5 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(15, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        for (int midi = 48; midi <= 72; ++midi) {
            int noteInOctave = midi % 12;
            if (noteInOctave == 0 || noteInOctave == 2 || noteInOctave == 4 || 
                noteInOctave == 5 || noteInOctave == 7 || noteInOctave == 9 || 
                noteInOctave == 11) {
                freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
            }
        }
    }
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1000000);
        inst->noteOff();
        usleep(200000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}


void testShakuhachi(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Shakuhachi (Minyo Pentatonic Scale: D4 to D6) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(16, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestVelocity);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        std::vector<int> minyoScale = {62, 65, 67, 69, 72, 74, 77, 79, 81, 84, 86};
        for (int midi : minyoScale) {
            freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testBansuri(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bansuri (7 Swaras — Sa Re Ga Ma Pa Dha Ni) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(17, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestVelocity);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    inst->setParam("glide", 0.05f);

    if (gTestFrequency > 0.0) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(gTestFrequency);
        inst->clearDiagnosticLogs();
        inst->noteOn(gTestFrequency, gTestVelocity, gTestVelocity);
        usleep(2000000);
        inst->noteOff();
        usleep(100000);
        printEnergy(inst.get(), gTestFrequency);
        std::cout << std::endl;
    } else {
        const char* swaraNames[7] = { "Sa", "Re", "Ga", "Ma", "Pa", "Dha", "Ni" };
        const double swaraRatios[7] = { 1.0, 9.0/8.0, 5.0/4.0, 4.0/3.0, 3.0/2.0, 5.0/3.0, 15.0/8.0 };
        std::vector<double> octaves = {222.0, 444.0};

        for (double baseFreq : octaves) {
            for (int i = 0; i < 7; ++i) {
                double freq = baseFreq * swaraRatios[i];
                inst->clearDiagnosticFreqs();
                inst->addDiagnosticFreq(freq);
                inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, 0.0f);
                usleep(2000000);
                inst->noteOff();
                usleep(200000);
                printEnergy(inst.get(), freq);
                std::cout << "_" << swaraNames[i];
                if (i < 6) std::cout << " , ";
                std::cout << std::flush;
            }
            if (&baseFreq != &octaves.back()) std::cout << " | ";
        }
        std::cout << std::endl;
    }

    usleep(1500000);
    mixer.removeTrack(track);
}


void testViolin(FaustMixer& mixer, DSPExecutionType execType) {
    // Only print to std::cout what is strictly requested
    auto inst = std::make_shared<FaustInstrument>(18, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(1.0f); // fixed 1.0 amplitude for test
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        freqs = {110.0, 146.8, 196.0, 220.0, 246.9, 293.7, 329.6, 392.0, 440.0, 493.9, 523.3, 587.3, 659.3, 783.9, 880.0, 1046.5, 1174.6, 1400.0};
    }
    
    std::vector<float> strikes;
    if (gTestStrike >= 0.0f) {
        strikes = { gTestStrike };
    } else {
        strikes = {0.0f, 1.0f, 2.0f};
    }

    inst->enableDiagnosticLogging(true);
    
    for (float strike : strikes) {
        std::cout << "S" << (int)strike << ": " << std::flush;
        for (size_t i = 0; i < freqs.size(); ++i) {
            double freq = freqs[i];
            
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq);
            inst->clearDiagnosticLogs();
            
            // Note On
            inst->noteOn(freq, gTestVelocity, gTestStrike);
            
            // Original timing: keep bowing up to 1.5s total before release
            usleep(1500000);
            inst->noteOff();
            
            // Wait for tail to decay
            usleep(200000);
            
            // Read captured logs and compute RMS energy over all snapshots for stability
            auto logs = inst->getDiagnosticLogs();
            float avgEnergy = 0.0f;
            if (!logs.empty()) {
                float sumSq = 0.0f;
                for (const auto& log : logs) {
                    sumSq += log.value3 * log.value3;
                }
                avgEnergy = std::sqrt(sumSq / logs.size());
            }
            
            std::cout << freq << "," << avgEnergy;
            if (i < freqs.size() - 1) std::cout << " , ";
            std::cout << std::flush; // Force output to show in real time
            
            // Original gap timing
            usleep(200000); 
        }
        std::cout << std::endl;
    }

    mixer.removeTrack(track);
}

void testCowbell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cowbell (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(14, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 400.0, 560.0, 700.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testRainmaker(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Rainmaker (Ambient Endless Physics) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(19, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(1.0f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    // Bamboo: tube resonance ~220Hz, slow tilt
    inst->setParam("Instrument_Material", 0.0f);
    inst->setParam("Tilt_Speed_Hz", 0.02f);
    inst->clearDiagnosticFreqs();
    inst->addDiagnosticFreq(220);
    inst->clearDiagnosticLogs();
    inst->setDiagnosticSamplingTimes({4.0f, 6.0f, 8.0f});
    inst->noteOn(220.0f, gTestVelocity, gTestVelocity);
    usleep(10000000);
    printEnergy(inst.get(), 220.0);
    std::cout << "_bamboo , " << std::flush;
    
    inst->noteOff();
    usleep(2000000);
    
    // Metal: tube resonance ~880Hz, faster tilt
    inst->setParam("Instrument_Material", 1.0f);
    inst->setParam("Tilt_Speed_Hz", 0.2f);
    inst->clearDiagnosticFreqs();
    inst->addDiagnosticFreq(880);
    inst->clearDiagnosticLogs();
    inst->setDiagnosticSamplingTimes({4.0f, 6.0f, 8.0f});
    inst->noteOn(880.0f, gTestVelocity, gTestVelocity);
    usleep(10000000);
    printEnergy(inst.get(), 880.0);
    std::cout << "_metal" << std::flush;
    
    inst->noteOff();
    usleep(2000000);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testChurchBell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Church Bell (with Master Reverb Bus) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(20, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(1.0f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    inst->setReverbSend(0.8f);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 164.81, 130.81, 146.83, 98.00 });
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(6000000);
        inst->noteOff();
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(4000000);
    mixer.removeTrack(track);
}

void testAcousticGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    auto inst = std::make_shared<FaustInstrument>(21, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);

    std::vector<double> notes;
    std::vector<float> amps;
    if (gTestFrequency > 0.0) {
        notes = { gTestFrequency };
        amps = { gTestVelocity > 0.0f ? gTestVelocity : 0.8f };
        std::cout << "\n=== [Test] Acoustic Guitar (single: " << notes[0] << " Hz @ " << amps[0] << ") ===" << std::endl;
    } else {
        std::cout << "\n=== [Test] Acoustic Guitar (C3 Major Chords / Notes) ===" << std::endl;
        notes = getTestFreqsDouble(inst.get(), { 130.81, 164.81, 196.00, 261.63 });
        amps = { 0.8f };
    }
    for (double freq : notes) {
        for (float amp : amps) {
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq * 1.0f);
            inst->addDiagnosticFreq(freq * 2.0f);
            inst->addDiagnosticFreq(freq * 3.0f);
            inst->addDiagnosticFreq(freq * 4.0f);
            inst->addDiagnosticFreq(freq * 5.0f);
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq);
            inst->clearDiagnosticLogs();
            inst->setDiagnosticSamplingTimes({0.10f, 0.50f, 1.00f});
            inst->noteOn(freq, amp, gTestStrike);
            usleep(1500000);
            inst->noteOff();
            usleep(300000);
            printEnergy(inst.get(), freq);
            if (&freq != &notes.back() || &amp != &amps.back()) std::cout << " , ";
            std::cout << std::flush;
        }
    }
    std::cout << std::endl;
    usleep(1000000);
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

void testElectricGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Electric Guitar (A2 Power Chords / Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(22, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    inst->setParam("drive", 0.8f);
    inst->setParam("sustain", 0.7f);
    
    std::vector<double> notes = getTestFreqsDouble(inst.get(), { 110.00, 165.00, 220.00 });
    for (double freq : notes) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1500000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        if (&freq != &notes.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1000000);
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

void testBassGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    auto inst = std::make_shared<FaustInstrument>(23, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> notes;
    std::vector<float> amps;
    if (gTestFrequency > 0.0) {
        notes = { gTestFrequency };
        amps = { gTestVelocity > 0.0f ? gTestVelocity : 0.8f };
        std::cout << "\n=== [Test] Bass Guitar (single: " << notes[0] << " Hz @ " << amps[0] << ") ===" << std::endl;
    } else {
        std::cout << "\n=== [Test] Bass Guitar (B1-D3: 50-150 Hz, 3 amp levels) ===" << std::endl;
        notes = { 61.74, 82.41, 110.00, 130.81, 146.83 };
        amps = { 0.2f, 0.5f, 0.9f };
    }
    for (double freq : notes) {
        for (float amp : amps) {
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq);
            inst->clearDiagnosticLogs();
            inst->noteOn(freq, amp, amp);
            usleep(1500000);
            inst->noteOff();
            if (&amp != &amps.back()) usleep(300000);
            printEnergy(inst.get(), freq);
            std::cout << "_" << amp;
            if (&amp != &amps.back()) std::cout << " , ";
            std::cout << std::flush;
        }
        if (&freq != &notes.back()) std::cout << " | ";
    }
    std::cout << std::endl;
    usleep(1000000);
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

void testCello(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cello (C2 to G3 Bowed Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(24, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> notes = getTestFreqsDouble(inst.get(), { 65.41, 98.00, 146.83, 196.00 });
    for (double freq : notes) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        usleep(400000);
        printEnergy(inst.get(), freq);
        if (&freq != &notes.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1000000);
    mixer.removeTrack(track);
}

void testCricket(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cricket (ambient chirping) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(25, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->clearDiagnosticLogs();
    inst->noteOn(-1.0f, gTestVelocity, gTestVelocity);
    usleep(8000000);
    inst->noteOff();
    usleep(500000);
    printEnergy(inst.get(), -1.0);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testCuckoo(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cuckoo ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(26, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    struct { float type; double freq; const char* name; } modes[] = {
        {0.0f, 587.33, "Asian"},
        {1.0f, 659.25, "Western"},
        {2.0f, 1301.0, "Indian"},
    };
    for (int i = 0; i < 3; ++i) {
        inst->setParam("type", modes[i].type);
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(modes[i].freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(modes[i].freq, gTestVelocity, gTestVelocity);
        usleep(4000000);
        inst->noteOff();
        usleep(2500000);
        printEnergy(inst.get(), modes[i].freq);
        std::cout << "_" << modes[i].name;
        if (i < 2) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testWaterfall(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Waterfall (multi-band ambient) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(27, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->clearDiagnosticLogs();
    inst->noteOn(-1.0f, gTestVelocity, gTestVelocity);
    usleep(6000000);
    inst->noteOff();
    usleep(500000);
    printEnergy(inst.get(), -1.0);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testDjembe(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Djembe ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(28, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<float> freqs = getTestFreqsFloat({110.0f, 150.0f, 220.0f});
    std::vector<float> positions = {0.1f, 0.5f, 0.9f};
    for (size_t i = 0; i < freqs.size(); ++i) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freqs[i]);
        inst->clearDiagnosticLogs();
        inst->setParam("position", positions[i]);
        inst->setParam("strike", 0.5f + 0.15f * i);
        inst->noteOn(freqs[i], gTestVelocity, gTestVelocity);
        usleep(1500000);
        inst->noteOff();
        usleep(500000);
        printEnergy(inst.get(), freqs[i]);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testMarimba(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Marimba ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(29, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<float> freqs = getTestFreqsFloat({220.0f, 246.94f, 277.18f, 329.63f, 392.00f});
    std::vector<float> positions = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    for (size_t i = 0; i < freqs.size(); ++i) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freqs[i]);
        inst->clearDiagnosticLogs();
        inst->setParam("position", positions[i]);
        inst->setParam("strike", 0.3f + 0.15f * i);
        inst->noteOn(freqs[i], gTestVelocity, gTestVelocity);
        usleep(1000000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freqs[i]);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

void testConga(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Conga (Tuning Range 100-200Hz) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(30, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<float> freqs = getTestFreqsFloat({100.0f, 120.0f, 140.0f, 160.0f, 180.0f, 200.0f});
    std::vector<int> strikes = {0, 1, 2};
    std::vector<float> positions = {0.0f, 1.0f, 2.0f};
    
    for (float freq : freqs) {
        for (int strike : strikes) {
            float pos = positions[strike];
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq);
            inst->clearDiagnosticLogs();
            inst->setParam("position", pos);
            inst->setParam("strike", strike);
            inst->noteOn(freq, gTestVelocity, gTestStrike);
            usleep(1000000);
            inst->noteOff();
            usleep(300000);
            printEnergy(inst.get(), freq);
            std::cout << "_s" << strike;
            if (strike != strikes.back()) std::cout << " , ";
            std::cout << std::flush;
        }
        if (&freq != &freqs.back()) std::cout << " | ";
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testBongo(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bongo (Tuning Range 100-200Hz) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(31, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<float> freqs = getTestFreqsFloat({100.0f, 120.0f, 140.0f, 160.0f, 180.0f, 200.0f});
    std::vector<int> strikes = {0, 1, 2};
    std::vector<float> positions = {0.0f, 1.0f, 2.0f};
    
    for (float freq : freqs) {
        for (int strike : strikes) {
            float pos = positions[strike];
            inst->clearDiagnosticFreqs();
            inst->addDiagnosticFreq(freq);
            inst->clearDiagnosticLogs();
            inst->setParam("position", pos);
            inst->setParam("strike", strike);
            inst->noteOn(freq, gTestVelocity, gTestStrike);
            usleep(1000000);
            inst->noteOff();
            usleep(300000);
            printEnergy(inst.get(), freq);
            std::cout << "_s" << strike;
            if (strike != strikes.back()) std::cout << " , ";
            std::cout << std::flush;
        }
        if (&freq != &freqs.back()) std::cout << " | ";
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testVoice(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Singing Voice (Vowel Morphing) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(32, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<float> vowels = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<std::string> names = {"aa (aah)", "ee (eh)", "ii (ee)", "oo (oh)", "uu (oo)"};
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        freqs = { 100.0, 200.0, 300.0, 400.0, 500.0, 600.0, 700.0, 800.0 };
    }

    for (double f : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(f);
        inst->clearDiagnosticLogs();
        inst->noteOn(f, gTestVelocity, gTestVelocity);
        for (size_t i = 0; i < vowels.size(); ++i) {
            inst->setParam("vowel", vowels[i]);
            usleep(600000);
        }
        inst->noteOff();
        usleep(400000);
        printEnergy(inst.get(), f);
        if (&f != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testShaker(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Shaker ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(33, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->clearDiagnosticLogs();
    inst->noteOn(-1.0f, gTestVelocity, gTestVelocity);
    usleep(2000000);
    inst->noteOff();
    usleep(1000000);
    printEnergy(inst.get(), -1.0);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testSeaWave(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sea Wave ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(34, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->clearDiagnosticLogs();
    inst->setDiagnosticSamplingTimes({1.0f, 2.0f, 3.0f});
    inst->noteOn(-1.0f, gTestVelocity, gTestVelocity);
    usleep(4000000);
    inst->noteOff();
    usleep(500000);
    printEnergy(inst.get(), -1.0);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testChouGong(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Chou Gong ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(35, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    float testFreq = (gTestFrequency > 0.0) ? (float)gTestFrequency : 100.0f;
    inst->clearDiagnosticFreqs();
    inst->addDiagnosticFreq(testFreq);
    inst->clearDiagnosticLogs();
    inst->noteOn(testFreq, gTestVelocity, gTestVelocity);
    usleep(4000000);
    inst->noteOff();
    usleep(2000000);
    printEnergy(inst.get(), testFreq);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testLagNga(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Lag Nga ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(36, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> notes;
    if (gTestFrequency > 0.0) {
        notes = { gTestFrequency };
    } else {
        notes = { 85.0, 111.0, 150.0, 200.0 };
    }
    
    for (double freq : notes) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        usleep(1500000);
        printEnergy(inst.get(), freq);
        if (&freq != &notes.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testNgachen(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Nga Chen ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(48, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> notes;
    if (gTestFrequency > 0.0) {
        notes = { gTestFrequency };
    } else {
        notes = { 50.0, 60.0, 72.0, 85.0 };
    }
    
    for (double freq : notes) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        usleep(1500000);
        printEnergy(inst.get(), freq);
        if (&freq != &notes.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testDholak(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dholak ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(37, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<std::pair<float, std::string>> strokes = {
        { 0.0f, "Bayan Open (Bass)" },
        { 1.0f, "Bayan Closed (Bass Slap)" },
        { 2.0f, "Dayan Open (Treble)" },
        { 3.0f, "Dayan Closed (Treble Click)" },
        { 4.0f, "Composite (Dha/Dhin)" }
    };
    for (size_t i = 0; i < strokes.size(); ++i) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(110);
        inst->clearDiagnosticLogs();
        inst->noteOn(110.0f, gTestVelocity, gTestVelocity);
        usleep(1500000);
        inst->noteOff();
        usleep(500000);
        printEnergy(inst.get(), 110.0);
        std::cout << "_s" << (int)strokes[i].first;
        if (i < strokes.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testDhol(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dhol ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(38, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<std::pair<float, std::string>> strokes = {
        { 0.0f, "Dagga Open (Bass Stick)" },
        { 1.0f, "Dagga Closed (Bass Slap)" },
        { 2.0f, "Tilli Open (Treble Stick Center)" },
        { 3.0f, "Tilli Closed (Treble Stick Edge/Rim)" },
        { 4.0f, "Composite (Dha/Dhin)" }
    };
    for (size_t i = 0; i < strokes.size(); ++i) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(110);
        inst->clearDiagnosticLogs();
        inst->noteOn(110.0f, gTestVelocity, gTestVelocity);
        usleep(1500000);
        inst->noteOff();
        usleep(500000);
        printEnergy(inst.get(), 110.0);
        std::cout << "_s" << (int)strokes[i].first;
        if (i < strokes.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testGuzheng(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Guzheng ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(39, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 261.63, 392.00, 523.25, 783.99, 1046.50 });
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1500000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

void testErhu(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Erhu ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(40, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    // Test the actual playable range of the Erhu (D4 to D6/D7)
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 293.66, 440.00, 659.25, 880.00, 1174.66 });
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        usleep(400000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testWind(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Wind ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(41, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->clearDiagnosticLogs();
    inst->noteOn(-1.0f, gTestVelocity, gTestVelocity);
    usleep(5000000);
    inst->noteOff();
    usleep(1000000);
    printEnergy(inst.get(), -1.0);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testThunder(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Thunder ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(42, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->clearDiagnosticLogs();
    inst->noteOn(-1.0f, gTestVelocity, gTestVelocity);
    usleep(5000000);
    inst->noteOff();
    usleep(2000000);
    printEnergy(inst.get(), -1.0);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testDagu(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dagu ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(43, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->clearDiagnosticLogs();
    inst->noteOn(-1.0f, gTestVelocity, gTestVelocity);
    usleep(3000000);
    inst->noteOff();
    usleep(1000000);
    printEnergy(inst.get(), -1.0);
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testSarod(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sarod ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(44, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 
        65.41, 73.42, 82.41, 87.31, 98.00, 110.00, 123.47,
        130.81, 146.83, 164.81, 174.61, 196.00, 220.00, 246.94,
        261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88,
        523.25, 587.33, 659.25, 698.46, 783.99, 880.00, 987.77
    });
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, -1.0f);
        usleep(1500000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    // Only play chikari test when strike=1
    if (gTestStrike == 1.0f) {
        std::cout << " , ";

        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freqs.back());
        inst->clearDiagnosticLogs();
        inst->setParam("chikari_freq1", 111.0f);
        inst->setParam("chikari_freq2", 166.5f);
        inst->noteOn(freqs.back(), gTestVelocity, 1.0f);
        usleep(2000000);
        inst->noteOff();
        usleep(500000);
        printEnergy(inst.get(), freqs.back());
        std::cout << "_chikari" << std::flush;
    }
    std::cout << std::endl;

    mixer.removeTrack(track);
}

void testSantoor(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Santoor ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(45, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 523.25, 587.33, 659.25, 783.99 });
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1000000);
        inst->noteOff();
        usleep(200000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

void testTumbi(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tumbi ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(46, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 659.25, 739.99, 830.61 });
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    }
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1000000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        std::cout << "_flesh , " << std::flush;
        
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1000000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        std::cout << "_nail" << std::flush;
        if (&freq != &freqs.back()) std::cout << " | ";
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}
// =====================================================
// MAIN EXECUTION
// =====================================================

void testTibetanbowl(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tibetan Bowl STK ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(47, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 111.0, 222.0 });
    for (double freq : freqs) {
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(4000000);
        inst->noteOff();
        usleep(1500000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    mixer.removeTrack(track);
}

void testPanflute(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Panflute ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(51, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestVelocity);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        for (int midi = 45; midi <= 72; ++midi) {
            freqs.push_back(440.0 * pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(200000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testNativeAmericanFlute(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Native American Flute ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(52, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestVelocity);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        for (int midi = 45; midi <= 72; ++midi) {
            freqs.push_back(440.0 * pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(200000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1500000);
    mixer.removeTrack(track);
}

void testDizi(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dizi ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(53, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestVelocity);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        for (int midi = 57; midi <= 84; ++midi) {
            freqs.push_back(440.0 * pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        usleep(1500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(200000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1000000);
    mixer.removeTrack(track);
}

void testHarmonium(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Harmonium ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(54, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestVelocity);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    
    // Set custom settings
    inst->setParameter("pressure", gTestPressure >= 0.0f ? gTestPressure : 0.8f);
    inst->setParameter("reed_octaves", 1.0f);

    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
        inst->addDiagnosticFreq(gTestFrequency);
    } else {
        // Yaman chords or chromatic runs (Sa, Ga, Pa, Ni)
        freqs = { 222.0, 277.5, 333.0, 416.25, 444.0 };
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->clearDiagnosticFreqs();
        inst->addDiagnosticFreq(freq);
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestStrike >= 0.0f ? gTestStrike : 0.0f);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(300000);
        printEnergy(inst.get(), freq);
        if (i < freqs.size() - 1) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;
    usleep(1000000);
    if (gTestFrequency <= 0.0) testPolyphonicChord(inst.get());
    mixer.removeTrack(track);
}

// =====================================================
// RENDER MODE: Direct render() bypasses mixer/miniaudio
// Renders 1 second in a tight loop — instant results
// =====================================================
static void testRenderMode(int instrumentID, DSPExecutionType execType, float startSec = 0.04f, float durationSec = 0.96f) {
    const float sampleRate = InstrumentMapper::DEFAULT_SAMPLE_RATE;
    const int startFrame = static_cast<int>(startSec * sampleRate);
    const int totalFrames = static_cast<int>(durationSec * sampleRate);
    const int chunkSize = 512;

    auto inst = std::make_shared<FaustInstrument>(instrumentID, execType, sampleRate);

    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        switch (instrumentID) {
            case 12: // Piano — C2 to C5
                for (int midi = 36; midi <= 72; ++midi)
                    freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
                break;
            default:
                freqs = { 261.63 };
                break;
        }
    }

    std::cout << "\n=== [Render] Instrument " << instrumentID
              << " — " << freqs.size() << " freqs, "
              << durationSec << "s each, measuring [" << startSec << "s .. " << (startSec + durationSec) << "s] ===" << std::endl;

    for (double freq : freqs) {
        inst->setParamImmediate("freq", static_cast<float>(freq));
        inst->setParamImmediate("velocity", gTestVelocity);
        inst->setParamImmediate("strike", gTestStrike);
        inst->setParamImmediate("vibrato_depth", 0.0f);
        inst->noteOn(freq, gTestVelocity, gTestStrike);
        for (const auto& po : gParamOverrides)
            inst->setParamImmediate(po.first.c_str(), po.second);

        auto t0 = std::chrono::high_resolution_clock::now();

        std::vector<float> buf(totalFrames * 2, 0.0f);
        int rendered = 0;
        while (rendered < totalFrames) {
            int n = std::min(chunkSize, totalFrames - rendered);
            inst->render(n, buf.data() + rendered * 2);
            rendered += n;
        }

        auto t1 = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();

        int measureFrames = totalFrames - startFrame;
        float rms = computeRMS(buf.data() + startFrame * 2, measureFrames);
        float peak = computePeak(buf.data() + startFrame * 2, measureFrames);

        auto goertzel = [&](float targetFreq) -> float {
            if (measureFrames <= 0 || targetFreq <= 0.0f || targetFreq >= sampleRate * 0.5f)
                return 0.0f;
            float k = (measureFrames * targetFreq) / sampleRate;
            float omega = (2.0f * M_PI * k) / measureFrames;
            float coeff = 2.0f * cosf(omega);
            float q1 = 0.0f, q2 = 0.0f;
            for (int i = startFrame; i < totalFrames; ++i) {
                float x = (buf[i * 2] + buf[i * 2 + 1]) * 0.5f;
                float q0 = coeff * q1 - q2 + x;
                q2 = q1;
                q1 = q0;
            }
            float magSq = q1 * q1 + q2 * q2 - q1 * q2 * coeff;
            return sqrtf(std::max(0.0f, magSq)) / measureFrames;
        };

        float gh[9] = {0.0f};
        for (int h = 1; h <= 8; ++h)
            gh[h] = goertzel(freq * h);

        float gdiv2 = goertzel(freq / 2.0f);
        float gdiv3 = goertzel(freq / 3.0f);
        float gdiv4 = goertzel(freq / 4.0f);

        float g_pred = goertzel(340.0f / (340.0f / freq - 0.08f));

        std::cout << "{ " << freq << ", " << rms
                  << ", P=" << peak << ", G=" << gh[1]
                  << ", G2=" << gh[2] << ", G3=" << gh[3]
                  << ", G4=" << gh[4] << ", G5=" << gh[5]
                  << ", G6=" << gh[6] << ", G7=" << gh[7] << ", G8=" << gh[8]
                  << ", G/2=" << gdiv2 << ", G/3=" << gdiv3 << ", G/4=" << gdiv4
                  << " }  (" << ms << " ms)";

        if (gTestScan) {
            std::vector<float> mono(measureFrames);
            for (int i = 0; i < measureFrames; ++i)
                mono[i] = (buf[(startFrame + i) * 2] + buf[(startFrame + i) * 2 + 1]) * 0.5f;
            float estPitch = detectPitchFFT(mono.data(), (int)mono.size(), sampleRate, (float)freq);
            std::cout << "\nSCAN " << estPitch;
        }

        if (!gDumpWav.empty()) {
            FILE* f = fopen(gDumpWav.c_str(), "wb");
            if (f) {
                const int sr = (int)sampleRate;
                const int ch = 2;
                int dataSize = totalFrames * ch * 2;
                unsigned char hdr[44] = {0};
                hdr[0]='R'; hdr[1]='I'; hdr[2]='F'; hdr[3]='F';
                hdr[4]=(unsigned char)((36+dataSize)&0xFF); hdr[5]=(unsigned char)(((36+dataSize)>>8)&0xFF);
                hdr[6]=(unsigned char)(((36+dataSize)>>16)&0xFF); hdr[7]=(unsigned char)(((36+dataSize)>>24)&0xFF);
                hdr[8]='W'; hdr[9]='A'; hdr[10]='V'; hdr[11]='E';
                hdr[12]='f'; hdr[13]='m'; hdr[14]='t'; hdr[15]=' ';
                hdr[16]=16; hdr[17]=0; hdr[18]=0; hdr[19]=0;
                hdr[20]=1; hdr[21]=0;
                hdr[22]=(unsigned char)ch; hdr[23]=0;
                hdr[24]=(unsigned char)(sr&0xFF); hdr[25]=(unsigned char)((sr>>8)&0xFF);
                hdr[26]=(unsigned char)((sr>>16)&0xFF); hdr[27]=(unsigned char)((sr>>24)&0xFF);
                int byteRate = sr*ch*2;
                hdr[28]=(unsigned char)(byteRate&0xFF); hdr[29]=(unsigned char)((byteRate>>8)&0xFF);
                hdr[30]=(unsigned char)((byteRate>>16)&0xFF); hdr[31]=(unsigned char)((byteRate>>24)&0xFF);
                hdr[32]=(unsigned char)(ch*2); hdr[33]=0;
                hdr[34]=16; hdr[35]=0;
                hdr[36]='d'; hdr[37]='a'; hdr[38]='t'; hdr[39]='a';
                hdr[40]=(unsigned char)(dataSize&0xFF); hdr[41]=(unsigned char)((dataSize>>8)&0xFF);
                hdr[42]=(unsigned char)((dataSize>>16)&0xFF); hdr[43]=(unsigned char)((dataSize>>24)&0xFF);
                fwrite(hdr, 1, 44, f);
                std::vector<short> pcm(totalFrames*ch);
                for (int i = 0; i < totalFrames; ++i) {
                    float l = buf[i*2], r = buf[i*2+1];
                    if (l < -1.0f) l = -1.0f; if (l > 1.0f) l = 1.0f;
                    if (r < -1.0f) r = -1.0f; if (r > 1.0f) r = 1.0f;
                    pcm[i*2]   = (short)(l * 32767.0f);
                    pcm[i*2+1] = (short)(r * 32767.0f);
                }
                fwrite(pcm.data(), 2, pcm.size(), f);
                fclose(f);
                std::cout << "  [DUMP] wrote " << gDumpWav << std::endl;
            }
        }

        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << "\n" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "--- Standalone Instrument Validation (Bypassing Orchestrator) ---" << std::endl;

    DSPExecutionType execType = DSPExecutionType::InterpretedByte;
    int directID = -1;
    bool hasDirectID = false;
    bool renderMode = false;
    float gTestStartSec = -1.0f;
    float gTestDurSec = -1.0f;
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--static" || arg == "-s") {
            execType = DSPExecutionType::StaticCompiled;
        } else if (arg == "--interpreter" || arg == "-i") {
            execType = DSPExecutionType::InterpretedByte;
        } else if (arg == "--scan") {
            gTestScan = true;
        } else if (arg.substr(0, 9) == "--dumpwav") {
            if (i + 1 < argc) gDumpWav = argv[++i];
        } else if (arg == "--render") {
            renderMode = true;
        } else {
            if (arg.substr(0, 2) == "v=") {
                try { gTestVelocity = std::stof(arg.substr(2)); } catch (...) {}
            } else if (arg.substr(0, 2) == "p=") {
                try { gTestPressure = std::stof(arg.substr(2)); } catch (...) {}
            } else if (arg.substr(0, 2) == "f=") {
                try { gTestFrequency = std::stod(arg.substr(2)); } catch (...) {}
            } else if (arg.substr(0, 2) == "s=") {
                try { gTestStrike = std::stof(arg.substr(2)); } catch (...) {}
            } else if (arg.substr(0, 6) == "start=") {
                try { gTestStartSec = std::stof(arg.substr(6)); } catch (...) {}
            } else if (arg.substr(0, 4) == "dur=") {
                try { gTestDurSec = std::stof(arg.substr(4)); } catch (...) {}
            } else if (arg.find('=') != std::string::npos) {
                size_t eq = arg.find('=');
                std::string pn = arg.substr(0, eq);
                float pv = 0.0f;
                try { pv = std::stof(arg.substr(eq + 1)); }
                catch (...) { continue; }
                gParamOverrides[pn] = pv;
            } else if (!hasDirectID) {
                try {
                    directID = std::stoi(arg);
                    hasDirectID = true;
                } catch (...) {}
            } else {
                try {
                    gTestVelocity = std::stof(arg);
                    if (gTestVelocity < 0.0f) gTestVelocity = 0.0f;
                    if (gTestVelocity > 1.0f) gTestVelocity = 1.0f;
                } catch (...) {}
            }
        }
    }

    std::cout << "[Config] Using Execution Mode: " 
              << (execType == DSPExecutionType::StaticCompiled ? "StaticCompiled" : "Interpreter (InterpretedByte)") 
              << std::endl;

    if (renderMode && hasDirectID) {
        float startSec = (gTestStartSec >= 0.0f) ? gTestStartSec : InstrumentMapper::getMeasureStart(directID);
        float durationSec = (gTestDurSec > 0.0f) ? gTestDurSec : InstrumentMapper::getMeasureDuration(directID);
        testRenderMode(directID, execType, startSec, durationSec);
        return 0;
    }

    FaustMixer& mixer = FaustMixer::getInstance();
    
    std::cout << "[Test] Initializing Mixer..." << std::endl;
    mixer.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    
    mixer.start();

    std::vector<std::pair<int, std::string>> instruments = {
        {0, "Dayan"},
        {1, "Bayan"},
        {2, "Kick"},
        {3, "Snare"},
        {4, "HiHat"},
        {5, "Tom"},
        {6, "Ride"},
        {7, "Bell"},
        {8, "Bowl"},
        {9, "Sitar"},
        {10, "Flute"},
        {11, "Tanpura"},
        {12, "Piano"},
        {13, "Sax"},
        {14, "Cowbell"},
        {15, "Trumpet"},
        {16, "Shakuhachi"},
        {17, "Bansuri"},
        {18, "Violin"},
        {19, "Rainmaker"},
        {20, "ChurchBell"},
        {21, "AcousticGuitar"},
        {22, "ElectricGuitar"},
        {23, "BassGuitar"},
        {24, "Cello"},
        {25, "Cricket"},
        {26, "Cuckoo"},
        {27, "Waterfall"},
        {28, "Djembe"},
        {29, "Marimba"},
        {30, "Conga"},
        {31, "Bongo"},
        {32, "Voice"},
        {33, "Shaker"},
        {34, "SeaWave"},
        {35, "ChouGong"},
        {36, "LagNga"},
        {37, "Dholak"},
        {38, "Dhol"},
        {39, "Guzheng"},
        {40, "Erhu"},
        {41, "Wind"},
        {42, "Thunder"},
        {43, "Dagu"},
        {44, "Sarod"},
        {45, "Santoor"},
        {46, "Tumbi"},
        {47, "Tibetanbowl"},
        {48, "Ngachen"},
        {49, "Mridangam"},
        {50, "Ghatam"},
        {51, "Panflute"},
        {52, "NativeAmericanFlute"},
        {53, "Dizi"},
        {54, "Harmonium"}
    };

    std::cout << "\n--- Available Instruments ---" << std::endl;
    for (const auto& pair : instruments) {
        std::cout << "  ID " << pair.first << " : " << pair.second << std::endl;
    }

    if (hasDirectID) {
        auto it = std::find_if(instruments.begin(), instruments.end(), [directID](const std::pair<int, std::string>& p) {
            return p.first == directID;
        });
        if (it != instruments.end()) {
            std::cout << "[Direct Run] ID: " << directID
                      << "  vel=" << gTestVelocity
                      << "  freq=" << (gTestFrequency > 0 ? gTestFrequency : -1)
                      << "  strike=" << gTestStrike
                      << std::endl;
            switch(directID) {
                case 0: testDayan(mixer, execType); break;
                case 1: testBayan(mixer, execType); break;
                case 2: testKick(mixer, execType); break;
                case 3: testSnare(mixer, execType); break;
                case 4: testHiHat(mixer, execType); break;
                case 5: testTom(mixer, execType); break;
                case 6: testRide(mixer, execType); break;
                case 7: testBell(mixer, execType); break;
                case 8: testBowl(mixer, execType); break;
                case 9: testSitar(mixer, execType); break;
                case 10: testFlute(mixer, execType); break;
                case 11: testTanpura(mixer, execType); break;
                case 12: testPiano(mixer, execType); break;
                case 13: testSax(mixer, execType); break;
                case 14: testCowbell(mixer, execType); break;
                case 15: testTrumpet(mixer, execType); break;
                case 16: testShakuhachi(mixer, execType); break;
                case 17: testBansuri(mixer, execType); break;
                case 18: testViolin(mixer, execType); break;
                case 19: testRainmaker(mixer, execType); break;
                case 20: testChurchBell(mixer, execType); break;
                case 21: testAcousticGuitar(mixer, execType); break;
                case 22: testElectricGuitar(mixer, execType); break;
                case 23: testBassGuitar(mixer, execType); break;
                case 24: testCello(mixer, execType); break;
                case 25: testCricket(mixer, execType); break;
                case 26: testCuckoo(mixer, execType); break;
                case 27: testWaterfall(mixer, execType); break;
                case 28: testDjembe(mixer, execType); break;
                case 29: testMarimba(mixer, execType); break;
                case 30: testConga(mixer, execType); break;
                case 31: testBongo(mixer, execType); break;
                case 32: testVoice(mixer, execType); break;
                case 33: testShaker(mixer, execType); break;
                case 34: testSeaWave(mixer, execType); break;
                case 35: testChouGong(mixer, execType); break;
                case 36: testLagNga(mixer, execType); break;
                case 37: testDholak(mixer, execType); break;
                case 38: testDhol(mixer, execType); break;
                case 39: testGuzheng(mixer, execType); break;
                case 40: testErhu(mixer, execType); break;
                case 41: testWind(mixer, execType); break;
                case 42: testThunder(mixer, execType); break;
                case 43: testDagu(mixer, execType); break;
                case 44: testSarod(mixer, execType); break;
                case 45: testSantoor(mixer, execType); break;
                case 46: testTumbi(mixer, execType); break;
                case 47: testTibetanbowl(mixer, execType); break;
                case 48: testNgachen(mixer, execType); break;
                case 49: testMridangam(mixer, execType); break;
                case 50: testGhatam(mixer, execType); break;
                case 51: testPanflute(mixer, execType); break;
                case 52: testNativeAmericanFlute(mixer, execType); break;
                case 53: testDizi(mixer, execType); break;
                case 54: testHarmonium(mixer, execType); break;
                default: break;
            }
        } else {
            std::cout << "Invalid Instrument ID: " << directID << std::endl;
        }
    } else {
        while (true) {
            std::cout << "\n>>> Enter Instrument ID to test (or -1 to quit): ";
            int inputID;
            if (!(std::cin >> inputID) || inputID == -1) {
                break;
            }

            auto it = std::find_if(instruments.begin(), instruments.end(), [inputID](const std::pair<int, std::string>& p) {
                return p.first == inputID;
            });

            if (it != instruments.end()) {
                std::cin.ignore(10000, '\n'); // Clear the newline from the ID input

                std::cout << ">>> Enter frequency in Hz (or press Enter for default sequence): ";
                std::string freqStr;
                std::getline(std::cin, freqStr);
                if (!freqStr.empty()) {
                    try {
                        gTestFrequency = std::stod(freqStr);
                    } catch (...) {
                        gTestFrequency = -1.0;
                    }
                } else {
                    gTestFrequency = -1.0;
                }

                switch(inputID) {
                    case 0: testDayan(mixer, execType); break;
                    case 1: testBayan(mixer, execType); break;
                    case 2: testKick(mixer, execType); break;
                    case 3: testSnare(mixer, execType); break;
                    case 4: testHiHat(mixer, execType); break;
                    case 5: testTom(mixer, execType); break;
                    case 6: testRide(mixer, execType); break;
                    case 7: testBell(mixer, execType); break;
                    case 8: testBowl(mixer, execType); break;
                    case 9: testSitar(mixer, execType); break;
                    case 10: testFlute(mixer, execType); break;
                    case 11: testTanpura(mixer, execType); break;
                    case 12: testPiano(mixer, execType); break;
                    case 13: testSax(mixer, execType); break;
                    case 14: testCowbell(mixer, execType); break;
                    case 15: testTrumpet(mixer, execType); break;
                    case 16: testShakuhachi(mixer, execType); break;
                    case 17: testBansuri(mixer, execType); break;
                    case 18: testViolin(mixer, execType); break;
                    case 19: testRainmaker(mixer, execType); break;
                    case 20: testChurchBell(mixer, execType); break;
                    case 21: testAcousticGuitar(mixer, execType); break;
                    case 22: testElectricGuitar(mixer, execType); break;
                    case 23: testBassGuitar(mixer, execType); break;
                    case 24: testCello(mixer, execType); break;
                    case 25: testCricket(mixer, execType); break;
                    case 26: testCuckoo(mixer, execType); break;
                    case 27: testWaterfall(mixer, execType); break;
                    case 28: testDjembe(mixer, execType); break;
                    case 29: testMarimba(mixer, execType); break;
                    case 30: testConga(mixer, execType); break;
                    case 31: testBongo(mixer, execType); break;
                    case 32: testVoice(mixer, execType); break;
                    case 33: testShaker(mixer, execType); break;
                    case 34: testSeaWave(mixer, execType); break;
                    case 35: testChouGong(mixer, execType); break;
                    case 36: testLagNga(mixer, execType); break;
                    case 37: testDholak(mixer, execType); break;
                    case 38: testDhol(mixer, execType); break;
                    case 39: testGuzheng(mixer, execType); break;
                    case 40: testErhu(mixer, execType); break;
                    case 41: testWind(mixer, execType); break;
                    case 42: testThunder(mixer, execType); break;
                    case 43: testDagu(mixer, execType); break;
                    case 44: testSarod(mixer, execType); break;
                    case 45: testSantoor(mixer, execType); break;
                    case 46: testTumbi(mixer, execType); break;
                    case 47: testTibetanbowl(mixer, execType); break;
                    case 48: testNgachen(mixer, execType); break;
                    case 49: testMridangam(mixer, execType); break;
                    case 50: testGhatam(mixer, execType); break;
                    case 51: testPanflute(mixer, execType); break;
                    case 52: testNativeAmericanFlute(mixer, execType); break;
                    case 53: testDizi(mixer, execType); break;
                    case 54: testHarmonium(mixer, execType); break;
                    default: break;
                }
            } else {
                std::cout << "Invalid Instrument ID. Please try again." << std::endl;
            }
        }
    }

    mixer.stop();
    std::cout << "\nSUCCESS: All instruments tested sequentially." << std::endl;
    std::cout << "--- Test Complete ---" << std::endl;
    return 0;
}
