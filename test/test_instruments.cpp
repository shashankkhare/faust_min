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
#include "../src/FaustMixer.hpp"
#include "../src/InstrumentMapper.hpp"
#include "../src/FaustInstrument.hpp"

// =====================================================
// INSTRUMENT-SPECIFIC TEST FUNCTIONS
// =====================================================

static float gTestVelocity = 0.8f;
static float gTestPressure = -1.0f; // -1 means use default or LUT
static float gTestAmplitude = 0.8f;
static double gTestFrequency = -1.0; // -1 means use default test sequence

static std::vector<double> getTestFreqsDouble(const std::vector<double>& defaultFreqs) {
    if (gTestFrequency > 0.0) {
        return { gTestFrequency };
    }
    return defaultFreqs;
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
    std::vector<double> freqs = getTestFreqsDouble({ 130.81, 170.00, 210.00, 261.63 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        float strike = static_cast<float>(i % 4);
        std::cout << "  -> Note: " << freq << " Hz, Strike: " << strike << std::endl;
        inst->noteOn(freq, 0.8f, strike);
        usleep(2500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1500000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testBayan(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bayan ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(1, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::vector<double> freqs = getTestFreqsDouble({ 65.41, 85.00, 105.00, 130.81 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        float strike = static_cast<float>(i % 4);
        std::cout << "  -> Note: " << freq << " Hz, Strike: " << strike << std::endl;
        inst->noteOn(freq, 0.8f, strike);
        usleep(2500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1500000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testKick(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Kick ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(2, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::vector<double> freqs = getTestFreqsDouble({ 65.41, 98.00, 130.81 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f, 1.0f);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testSnare(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Snare (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(3, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 150.0, 180.0, 220.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testHiHat(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] HiHat ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(4, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::cout << "  -> Closed HiHat" << std::endl;
    inst->noteOn(0.0f, 0.7f, 1.0f);
    usleep(2000000);
    inst->noteOff();
    usleep(1000000);
    std::cout << "  -> Open HiHat" << std::endl;
    inst->noteOn(0.0f, 0.8f, 2.0f);
    usleep(2500000);
    inst->noteOff();
    usleep(1500000);
    mixer.removeTrack(track);
}

void testTom(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tom (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(5, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 80.0, 110.0, 140.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testRide(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Ride (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(6, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 4000.0, 5500.0, 7000.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(2500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testBell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bell ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(7, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::vector<double> freqs = getTestFreqsDouble({ 261.63, 329.63, 392.00 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(3500000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1500000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testBowl(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bowl ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(8, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::vector<double> freqs = getTestFreqsDouble({ 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(2500000); // 2.5 seconds ring time
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(800000); // 0.8 seconds gap
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testSitar(FaustMixer& mixer, DSPExecutionType execType) {
    auto inst = std::make_shared<FaustInstrument>(9, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::vector<double> freqs;
    std::vector<float> amps;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
        amps = { gTestAmplitude > 0.0f ? gTestAmplitude : 0.8f };
        std::cout << "\n=== [Test] Sitar (single: " << freqs[0] << " Hz @ " << amps[0] << ") ===" << std::endl;
    } else {
        std::cout << "\n=== [Test] Sitar (80–600 Hz CSV range) ===" << std::endl;
        freqs = { 140, 165, 196, 220, 261, 293, 330, 392, 440, 523, 587, 659 };
        amps = { 0.2f, 0.5f, 0.9f };
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        for (size_t j = 0; j < amps.size(); ++j) {
            double freq = freqs[i];
            float amp = amps[j];
            std::cout << "  -> freq=" << freq << " Hz  amp=" << amp << std::endl;
            inst->noteOn(freq, amp, -1.0f, amp);
            usleep(1800000);
            inst->noteOff();
            if (j < amps.size() - 1) usleep(800000);
        }
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testFlute(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Flute (C4 to C6 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(10, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestAmplitude);
    mixer.addInstrumentToTrack(track, inst.get());
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
        // Play C major scale from C4 (MIDI 60) to C6 (MIDI 84)
        std::vector<int> scale = {60, 62, 64, 65, 67, 69, 71, 72, 74, 76, 77, 79, 81, 83, 84};
        for (int m : scale) {
            freqs.push_back(440.0 * pow(2.0, (m - 69.0) / 12.0));
        }
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(2000000); // 2 seconds hold to hear vibrato
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(200000); // 200ms spacing
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testTanpura(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tanpura ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(11, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 130.00, 180.50, 231.00 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->setParam("freq1", freq * 1.5f);
        std::cout << "  -> Note Sa: " << freq << " Hz, Pa: " << freq * 1.5f << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(4000000); // reduced from 12s to play faster
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(500000); // reduced spacing
    }
    usleep(500000);
    mixer.removeTrack(track);
}

void testPiano(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Piano (C2 to C5 Chromatic) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(12, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
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
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(1000000); // 1 second hold
        inst->noteOff();
        usleep(200000);  // 0.2 second spacing
    }
    usleep(1500000); // Release tail
    mixer.removeTrack(track);
}

void testSax(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sax (C3 to C5 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(13, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
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
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(1000000); // 1 second hold
        inst->noteOff();
        usleep(200000);  // 0.2 second spacing
    }
    usleep(1500000); // Release tail
    mixer.removeTrack(track);
}

void testTrumpet(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Trumpet (C3 to C5 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(15, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
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
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(1000000); // 1 second hold
        inst->noteOff();
        usleep(200000);  // 0.2 second spacing
    }
    usleep(1500000); // Release tail
    mixer.removeTrack(track);
}


void testShakuhachi(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Shakuhachi (Minyo Pentatonic Scale: D4 to D6) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(16, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestAmplitude);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        // Plays Minyo pentatonic scale across two octaves (D4 to D6)
        std::vector<int> minyoScale = {62, 65, 67, 69, 72, 74, 77, 79, 81, 84, 86};
        for (int midi : minyoScale) {
            freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(2000000); // 2 seconds hold to hear vibrato and breathiness
        inst->noteOff();
        usleep(300000);  // 0.3 second spacing
    }
    usleep(1500000); // Release tail
    mixer.removeTrack(track);
}

void testBansuri(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bansuri (7 Swaras — Sa Re Ga Ma Pa Dha Ni) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(17, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestAmplitude);
    mixer.addInstrumentToTrack(track, inst.get());
    
    inst->setParam("glide", 0.05f);

    if (gTestFrequency > 0.0) {
        std::cout << "  -> Note: " << gTestFrequency << " Hz" << std::endl;
        inst->noteOn(gTestFrequency, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(2000000); // 2 seconds hold to hear vibrato
        inst->noteOff();
        usleep(100000);
    } else {
        // Standard 7 swaras (Bilawal/natural scale) using just intonation
        const char* swaraNames[7] = { "Sa", "Re", "Ga", "Ma", "Pa", "Dha", "Ni" };
        const double swaraRatios[7] = { 1.0, 9.0/8.0, 5.0/4.0, 4.0/3.0, 3.0/2.0, 5.0/3.0, 15.0/8.0 };
        // Realistic range for Bansuri: bass register (222 Hz) and soprano/alto register (444 Hz)
        std::vector<double> octaves = {222.0, 444.0};

        for (double baseFreq : octaves) {
            std::cout << "\n  -> Base (Sa): " << baseFreq << " Hz" << std::endl;
            for (int i = 0; i < 7; ++i) {
                double freq = baseFreq * swaraRatios[i];
                std::cout << "    -> " << swaraNames[i] << ": " << freq << " Hz" << std::endl;
                inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
                usleep(2000000); // 2 seconds hold to hear vibrato
                inst->noteOff();
                usleep(200000); // 200ms gap
            }
            usleep(1000000); // 1 second gap between octaves
        }
    }

    usleep(1500000);
    mixer.removeTrack(track);
}


void testViolin(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Violin (G3 to E5, D Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(18, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(gTestAmplitude);
    mixer.addInstrumentToTrack(track, inst.get());
    if (gTestPressure >= 0.0f) {
        inst->setParam("bowPressure", gTestPressure);
    }

    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        std::vector<int> dMajorScale = {55, 57, 59, 62, 64, 66, 69, 71, 74, 76};
        for (int midi : dMajorScale) {
            freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000); // 1.5 second bowing per note
        inst->noteOff();
        usleep(200000);  // 0.2 second gap between notes
    }
    usleep(1500000); // Final release tail
    mixer.removeTrack(track);
}

void testCowbell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cowbell (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(14, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 400.0, 560.0, 700.0 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(2000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1000000);
    }
    usleep(1500000);
    mixer.removeTrack(track);
}

void testRainmaker(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Rainmaker (Ambient Endless Physics) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(19, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(1.0f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    // Test Bamboo material (220Hz warm)
    std::cout << "  -> Material: Bamboo (0), Frequency: 220Hz" << std::endl;
    inst->setParam("Instrument_Material", 0.0f);
    inst->setParam("Tilt_Speed_Hz", 0.05f); // Slow soothing tilt
    inst->noteOn(220.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(5000000); // 5 seconds of ambient rain
    
    // Test Metal material (880Hz bright)
    std::cout << "  -> Material: Metal (1), Frequency: 880Hz" << std::endl;
    inst->setParam("Instrument_Material", 1.0f);
    inst->setParam("Tilt_Speed_Hz", 0.2f); // Faster tilt
    inst->noteOn(880.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(5000000); // 5 seconds of ambient rain
    
    inst->noteOff();
    usleep(2000000); // Wait for the massive 12s reverb tail to partially decay
    mixer.removeTrack(track);
}

void testChurchBell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Church Bell (with Master Reverb Bus) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(20, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(1.0f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    // Turn on reverb to compare the difference
    inst->setReverbSend(0.8f);
    
    // Play a Westminster Chimes sequence in the optimal 100-220Hz range (Hum pitches E3, C3, D3, G2)
    std::vector<double> freqs = getTestFreqsDouble({ 164.81, 130.81, 146.83, 98.00 }); // E3, C3, D3, G2
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(6000000); // Wait 6 seconds to let the modes ring out properly between strikes
        inst->noteOff();
    }
    
    usleep(4000000); // Let the massive hum ring out
    mixer.removeTrack(track);
}

void testAcousticGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Acoustic Guitar (C3 Major Chords / Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(21, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    // Play a sequence of notes
    std::vector<double> notes = getTestFreqsDouble({ 130.81, 164.81, 196.00, 261.63 }); // C3, E3, G3, C4
    for (double freq : notes) {
        std::cout << "  -> Plucking: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000); // 1.5 seconds decay
        inst->noteOff();
        usleep(300000);
    }
    
    usleep(1000000);
    mixer.removeTrack(track);
}

void testElectricGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Electric Guitar (A2 Power Chords / Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(22, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    // Set drive and sustain parameters to verify they are processed correctly
    inst->setParam("drive", 0.8f);
    inst->setParam("sustain", 0.7f);
    
    std::vector<double> notes = getTestFreqsDouble({ 110.00, 165.00, 220.00 }); // A2, E3, A3
    for (double freq : notes) {
        std::cout << "  -> Plucking: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000); // 1.5 seconds decay
        inst->noteOff();
        usleep(300000);
    }
    
    usleep(1000000);
    mixer.removeTrack(track);
}

void testBassGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    auto inst = std::make_shared<FaustInstrument>(23, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::vector<double> notes;
    std::vector<float> amps;
    if (gTestFrequency > 0.0) {
        notes = { gTestFrequency };
        amps = { gTestAmplitude > 0.0f ? gTestAmplitude : 0.8f };
        std::cout << "\n=== [Test] Bass Guitar (single: " << notes[0] << " Hz @ " << amps[0] << ") ===" << std::endl;
    } else {
        std::cout << "\n=== [Test] Bass Guitar (B1-D3: 50-150 Hz, 3 amp levels) ===" << std::endl;
        notes = { 61.74, 82.41, 110.00, 130.81, 146.83 };
        amps = { 0.2f, 0.5f, 0.9f };
    }
    for (double freq : notes) {
        for (float amp : amps) {
            std::cout << "  -> freq=" << freq << " Hz  amp=" << amp << std::endl;
            inst->noteOn(freq, amp, -1.0f, amp);
            usleep(1500000);
            inst->noteOff();
            if (&amp != &amps.back()) usleep(300000);
        }
    }
    usleep(1000000);
    mixer.removeTrack(track);
}

void testCello(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cello (C2 to G3 Bowed Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(24, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    // Play a sequence of bowed notes: C2 (65.41 Hz), G2 (98.00 Hz), D3 (146.83 Hz), G3 (196.00 Hz)
    std::vector<double> notes = getTestFreqsDouble({ 65.41, 98.00, 146.83, 196.00 });
    for (double freq : notes) {
        std::cout << "  -> Bowing Cello: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(2000000); // 2.0 seconds bow hold
        inst->noteOff();
        usleep(400000);
    }
    
    usleep(1000000);
    mixer.removeTrack(track);
}

void testCricket(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cricket (ambient chirping) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(25, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::cout << "  -> Starting cricket ambience for 8 seconds..." << std::endl;
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(8000000);
    inst->noteOff();
    usleep(500000);
    mixer.removeTrack(track);
}

void testCuckoo(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cuckoo ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(26, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    // 1. Asian Cuckoo (4 notes, "One-More-Bot-Tle")
    std::cout << "  -> Mode: Asian Cuckoo (4 notes), Base Freq: 587.33 Hz" << std::endl;
    inst->setParam("type", 0.0f);
    inst->noteOn(587.33f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(4000000); // 4 seconds
    inst->noteOff();
    usleep(2500000); // 2.5 seconds gap to clearly distinguish calls

    // 2. Western Cuckoo (2 notes, descending minor third)
    std::cout << "  -> Mode: Western Cuckoo (2 notes), Base Freq: 659.25 Hz" << std::endl;
    inst->setParam("type", 1.0f);
    inst->noteOn(659.25f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(4000000); // 4 seconds
    inst->noteOff();
    usleep(2500000); // 2.5 seconds gap to clearly distinguish calls

    // 3. Indian Cuckoo (4 notes, "One-More-Bot-Tle" natural frequency changes)
    std::cout << "  -> Mode: Indian Cuckoo (4 notes), Base Freq: 1301.0 Hz" << std::endl;
    inst->setParam("type", 2.0f);
    inst->noteOn(1301.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(4000000); // 4 seconds
    inst->noteOff();
    usleep(500000);

    mixer.removeTrack(track);
}

void testWaterfall(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Waterfall (multi-band ambient) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(27, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    std::cout << "  -> Starting waterfall ambience for 6 seconds..." << std::endl;
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(6000000);
    inst->noteOff();
    usleep(500000);
    mixer.removeTrack(track);
}

void testDjembe(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Djembe ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(28, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<float> freqs = getTestFreqsFloat({110.0f, 150.0f, 220.0f});
    std::vector<float> positions = {0.1f, 0.5f, 0.9f};
    for (size_t i = 0; i < freqs.size(); ++i) {
        std::cout << "  -> Note: " << freqs[i] << " Hz, Position: " << positions[i] << std::endl;
        inst->setParam("position", positions[i]);
        inst->setParam("strike", 0.5f + 0.15f * i);
        inst->noteOn(freqs[i], gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000);
        inst->noteOff();
        usleep(500000);
    }
    mixer.removeTrack(track);
}

void testMarimba(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Marimba ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(29, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<float> freqs = getTestFreqsFloat({220.0f, 246.94f, 277.18f, 329.63f, 392.00f});
    std::vector<float> positions = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    for (size_t i = 0; i < freqs.size(); ++i) {
        std::cout << "  -> Note: " << freqs[i] << " Hz, Bar Position: " << positions[i] << std::endl;
        inst->setParam("position", positions[i]);
        inst->setParam("strike", 0.3f + 0.15f * i);
        inst->noteOn(freqs[i], gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1000000);
        inst->noteOff();
        usleep(300000);
    }
    mixer.removeTrack(track);
}

void testConga(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Conga (Tuning Range 100-200Hz) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(30, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<float> freqs = getTestFreqsFloat({100.0f, 120.0f, 140.0f, 160.0f, 180.0f, 200.0f});
    std::vector<int> strikes = {0, 1, 2};
    std::vector<float> positions = {0.0f, 1.0f, 2.0f};
    
    for (float freq : freqs) {
        for (int strike : strikes) {
            float pos = positions[strike];
            std::cout << "  -> Strike: " << strike << ", Freq: " << freq << " Hz, Position: " << pos << std::endl;
            inst->setParam("position", pos);
            inst->setParam("strike", strike);
            inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
            usleep(1000000);
            inst->noteOff();
            usleep(300000);
        }
    }
    mixer.removeTrack(track);
}

void testBongo(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bongo (Tuning Range 100-200Hz) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(31, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<float> freqs = getTestFreqsFloat({100.0f, 120.0f, 140.0f, 160.0f, 180.0f, 200.0f});
    std::vector<int> strikes = {0, 1, 2};
    std::vector<float> positions = {0.0f, 1.0f, 2.0f};
    
    for (float freq : freqs) {
        for (int strike : strikes) {
            float pos = positions[strike];
            std::cout << "  -> Strike: " << strike << ", Freq: " << freq << " Hz, Position: " << pos << std::endl;
            inst->setParam("position", pos);
            inst->setParam("strike", strike);
            inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
            usleep(1000000);
            inst->noteOff();
            usleep(300000);
        }
    }
    mixer.removeTrack(track);
}

void testVoice(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Singing Voice (Vowel Morphing) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(32, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<float> vowels = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<std::string> names = {"aa (aah)", "ee (eh)", "ii (ee)", "oo (oh)", "uu (oo)"};
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        freqs = { 100.0, 200.0, 300.0, 400.0, 500.0, 600.0, 700.0, 800.0 };
    }

    for (double f : freqs) {
        std::cout << "  -> Pitch: " << f << " Hz" << std::endl;
        inst->noteOn(f, gTestVelocity, -1.0f, gTestAmplitude);
        for (size_t i = 0; i < vowels.size(); ++i) {
            std::cout << "     -> Vowel: " << names[i] << " (value: " << vowels[i] << ")" << std::endl;
            inst->setParam("vowel", vowels[i]);
            usleep(600000);
        }
        inst->noteOff();
        usleep(400000);
    }
    mixer.removeTrack(track);
}

void testShaker(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Shaker ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(33, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(2000000);
    inst->noteOff();
    usleep(1000000);
    mixer.removeTrack(track);
}

void testSeaWave(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sea Wave ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(34, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(5000000);
    inst->noteOff();
    usleep(2000000);
    mixer.removeTrack(track);
}

void testChouGong(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Chou Gong ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(35, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    float testFreq = (gTestFrequency > 0.0) ? (float)gTestFrequency : 100.0f;
    std::cout << "[Direct Run] Testing Chou Gong at freq: " << testFreq << " Hz" << std::endl;
    inst->noteOn(testFreq, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(4000000);
    inst->noteOff();
    usleep(2000000);
    mixer.removeTrack(track);
}

void testLagNga(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Lag Nga ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(36, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> notes;
    if (gTestFrequency > 0.0) {
        notes = { gTestFrequency };
    } else {
        notes = { 85.0, 111.0, 150.0, 200.0 };
    }
    
    for (double freq : notes) {
        std::cout << "[Direct Run] Testing Lag Nga at freq: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(2000000);
        inst->noteOff();
        usleep(1500000);
    }
    mixer.removeTrack(track);
}

void testNgachen(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Nga Chen ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(48, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> notes;
    if (gTestFrequency > 0.0) {
        notes = { gTestFrequency };
    } else {
        notes = { 50.0, 60.0, 72.0, 85.0 };
    }
    
    for (double freq : notes) {
        std::cout << "[Direct Run] Testing Nga Chen at freq: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(2000000);
        inst->noteOff();
        usleep(1500000);
    }
    mixer.removeTrack(track);
}

void testDholak(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dholak ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(37, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<std::pair<float, std::string>> strokes = {
        { 0.0f, "Bayan Open (Bass)" },
        { 1.0f, "Bayan Closed (Bass Slap)" },
        { 2.0f, "Dayan Open (Treble)" },
        { 3.0f, "Dayan Closed (Treble Click)" },
        { 4.0f, "Composite (Dha/Dhin)" }
    };
    for (const auto& stroke : strokes) {
        std::cout << "[Direct Run] Testing Dholak stroke: " << stroke.second << " (strikeVal=" << stroke.first << ")" << std::endl;
        inst->noteOn(110.0f, gTestVelocity, stroke.first, gTestAmplitude);
        usleep(1500000);
        inst->noteOff();
        usleep(500000);
    }
    mixer.removeTrack(track);
}

void testDhol(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dhol ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(38, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<std::pair<float, std::string>> strokes = {
        { 0.0f, "Dagga Open (Bass Stick)" },
        { 1.0f, "Dagga Closed (Bass Slap)" },
        { 2.0f, "Tilli Open (Treble Stick Center)" },
        { 3.0f, "Tilli Closed (Treble Stick Edge/Rim)" },
        { 4.0f, "Composite (Dha/Dhin)" }
    };
    for (const auto& stroke : strokes) {
        std::cout << "[Direct Run] Testing Dhol stroke: " << stroke.second << " (strikeVal=" << stroke.first << ")" << std::endl;
        inst->noteOn(110.0f, gTestVelocity, stroke.first, gTestAmplitude);
        usleep(1500000);
        inst->noteOff();
        usleep(500000);
    }
    mixer.removeTrack(track);
}

void testGuzheng(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Guzheng ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(39, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 261.63, 392.00, 523.25, 783.99, 1046.50 });
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000);
        inst->noteOff();
        usleep(300000);
    }
    mixer.removeTrack(track);
}

void testErhu(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Erhu ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(40, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    // Test the actual playable range of the Erhu (D4 to D6/D7)
    std::vector<double> freqs = getTestFreqsDouble({ 293.66, 440.00, 659.25, 880.00, 1174.66 });
    for (double freq : freqs) {
        std::cout << "  -> Bowing: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(2000000);
        inst->noteOff();
        usleep(400000);
    }
    mixer.removeTrack(track);
}

void testWind(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Wind ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(41, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(5000000);
    inst->noteOff();
    usleep(1000000);
    mixer.removeTrack(track);
}

void testThunder(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Thunder ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(42, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(5000000);
    inst->noteOff();
    usleep(2000000);
    mixer.removeTrack(track);
}

void testDagu(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Dagu ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(43, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(3000000);
    inst->noteOff();
    usleep(1000000);
    mixer.removeTrack(track);
}

void testSarod(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sarod ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(44, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 130.81, 146.83, 164.81, 196.00 });
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000);
        inst->noteOff();
        usleep(300000);
    }
    mixer.removeTrack(track);
}

void testSantoor(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Santoor ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(45, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 523.25, 587.33, 659.25, 783.99 });
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1000000);
        inst->noteOff();
        usleep(200000);
    }
    mixer.removeTrack(track);
}

void testTumbi(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tumbi ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(46, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    int track = mixer.addTrack(0.8f);
    mixer.addInstrumentToTrack(track, inst.get());
    
    std::vector<double> freqs = getTestFreqsDouble({ 659.25, 739.99, 830.61 });
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1000000);
        inst->noteOff();
        usleep(300000);
    }
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
    std::vector<double> freqs = getTestFreqsDouble({ 111.0, 222.0 });
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity >= 0.0f ? gTestVelocity : 0.8f);
        usleep(4000000);
        inst->noteOff();
        usleep(1500000);
    }
    mixer.removeTrack(track);
}

int main(int argc, char* argv[]) {
    std::cout << "--- Standalone Instrument Validation (Bypassing Orchestrator) ---" << std::endl;

    DSPExecutionType execType = DSPExecutionType::InterpretedByte;
    int directID = -1;
    bool hasDirectID = false;
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--static" || arg == "-s") {
            execType = DSPExecutionType::StaticCompiled;
        } else if (arg == "--interpreter" || arg == "-i") {
            execType = DSPExecutionType::InterpretedByte;
        } else {
            if (arg.substr(0, 2) == "v=") {
                try { gTestVelocity = std::stof(arg.substr(2)); } catch (...) {}
            } else if (arg.substr(0, 2) == "p=") {
                try { gTestPressure = std::stof(arg.substr(2)); } catch (...) {}
            } else if (arg.substr(0, 2) == "a=") {
                try { gTestAmplitude = std::stof(arg.substr(2)); } catch (...) {}
            } else if (arg.substr(0, 2) == "f=") {
                try { gTestFrequency = std::stod(arg.substr(2)); } catch (...) {}
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
        {48, "Ngachen"}
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
            std::cout << "[Direct Run] Testing Instrument ID: " << directID << " at velocity: " << gTestVelocity << std::endl;
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
                std::cout << ">>> Enter amplitude (0.0 to 1.0) [default 0.8]: ";
                std::string ampStr;
                std::cin.ignore(10000, '\n'); // Clear the newline from the ID input
                std::getline(std::cin, ampStr);
                if (!ampStr.empty()) {
                    try {
                        gTestAmplitude = std::stof(ampStr);
                        if (gTestAmplitude < 0.0f) gTestAmplitude = 0.0f;
                        if (gTestAmplitude > 1.0f) gTestAmplitude = 1.0f;
                    } catch (...) {
                        gTestAmplitude = 0.8f;
                    }
                } else {
                    gTestAmplitude = 0.8f;
                }

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
