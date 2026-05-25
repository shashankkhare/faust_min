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
    mixer.registerInstrument(inst.get(), 0.8f);
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
    mixer.unregisterInstrument(inst.get());
}

void testBayan(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bayan ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(1, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
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
    mixer.unregisterInstrument(inst.get());
}

void testKick(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Kick ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(2, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
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
    mixer.unregisterInstrument(inst.get());
}

void testSnare(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Snare (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(3, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testHiHat(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] HiHat ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(4, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
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
    mixer.unregisterInstrument(inst.get());
}

void testTom(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tom (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(5, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testRide(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Ride (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(6, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testBell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bell ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(7, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
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
    mixer.unregisterInstrument(inst.get());
}

void testBowl(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bowl ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(8, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
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
    mixer.unregisterInstrument(inst.get());
}

void testSitar(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sitar ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(9, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    std::vector<double> freqs = getTestFreqsDouble({ 261.63, 329.63, 392.00 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(3000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(1500000);
    }
    usleep(1500000);
    mixer.unregisterInstrument(inst.get());
}

void testFlute(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Flute ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(10, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), gTestAmplitude);
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
        for (int m = 48; m <= 84; ++m) {
            freqs.push_back(440.0 * pow(2.0, (m - 69.0) / 12.0));
        }
    }
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(400000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(100000);
    }
    usleep(1500000);
    mixer.unregisterInstrument(inst.get());
}

void testTanpura(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Tanpura ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(11, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
    std::vector<double> freqs = getTestFreqsDouble({ 130.81, 196.00, 261.63 });
    for (size_t i = 0; i < freqs.size(); ++i) {
        double freq = freqs[i];
        inst->setParam("freq1", freq * 1.5f);
        std::cout << "  -> Note Sa: " << freq << " Hz, Pa: " << freq * 1.5f << " Hz" << std::endl;
        inst->noteOn(freq, 0.8f);
        usleep(12000000);
        inst->noteOff();
        if (i < freqs.size() - 1) usleep(2000000);
    }
    usleep(1500000);
    mixer.unregisterInstrument(inst.get());
}

void testPiano(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Piano (C2 to C5 Chromatic) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(12, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
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
    mixer.unregisterInstrument(inst.get());
}

void testSax(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Sax (C3 to C5 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(13, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testTrumpet(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Trumpet (C3 to C5 Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(15, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}


void testShakuhachi(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Shakuhachi (Minyo Pentatonic Scale: D4 to D5) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(16, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), gTestAmplitude);
    
    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        std::vector<int> minyoScale = {62, 65, 67, 69, 72, 74};
        for (int midi : minyoScale) {
            freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1200000); // 1.2 second hold
        inst->noteOff();
        usleep(300000);  // 0.3 second spacing
    }
    usleep(1500000); // Release tail
    mixer.unregisterInstrument(inst.get());
}

void testBansuri(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bansuri (Raga Bhupali Scale with Glide/Meend: C4 to C5) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(17, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), gTestAmplitude);
    
    // Set glide time to 150ms for expressive meend transitions
    inst->setParam("glide", 0.15f);

    std::vector<double> freqs;
    if (gTestFrequency > 0.0) {
        freqs = { gTestFrequency };
    } else {
        std::vector<int> bhupaliScale = {60, 62, 64, 67, 69, 72};
        for (int midi : bhupaliScale) {
            freqs.push_back(440.0 * std::pow(2.0, (midi - 69.0) / 12.0));
        }
    }
    for (double freq : freqs) {
        std::cout << "  -> Note: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1200000); // 1.2 second hold (slides will happen dynamically at noteOn!)
        inst->noteOff();
        usleep(300000);  // 0.3 second spacing
    }
    usleep(1500000); // Release tail
    mixer.unregisterInstrument(inst.get());
}

void testViolin(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Violin (G3 to E5, D Major Scale) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(18, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), gTestAmplitude);
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
    mixer.unregisterInstrument(inst.get());
}

void testCowbell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cowbell (Tuning Test) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(14, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testRainmaker(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Rainmaker (Ambient Endless Physics) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(19, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 1.0f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testChurchBell(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Church Bell (with Master Reverb Bus) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(20, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 1.0f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testAcousticGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Acoustic Guitar (C3 Major Chords / Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(21, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testElectricGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Electric Guitar (A2 Power Chords / Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(22, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
    std::vector<double> notes = getTestFreqsDouble({ 110.00, 165.00, 220.00 }); // A2, E3, A3
    for (double freq : notes) {
        std::cout << "  -> Plucking: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000); // 1.5 seconds decay
        inst->noteOff();
        usleep(300000);
    }
    
    usleep(1000000);
    mixer.unregisterInstrument(inst.get());
}

void testBassGuitar(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bass Guitar (B1-D3: 50-150 Hz, speaker-safe) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(23, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
    // Notes between 50-150 Hz — above most laptop speaker cutoff (~80 Hz)
    // B1=61.7, E2=82.4, A2=110, D3=146.8
    std::vector<double> notes = getTestFreqsDouble({ 61.74, 82.41, 110.00, 130.81, 146.83 });
    for (double freq : notes) {
        std::cout << "  -> Plucking Bass: " << freq << " Hz" << std::endl;
        inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000); // 1.5 seconds decay
        inst->noteOff();
        usleep(300000);
    }
    
    usleep(1000000);
    mixer.unregisterInstrument(inst.get());
}

void testCello(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cello (C2 to G3 Bowed Notes) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(24, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testCricket(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cricket (ambient chirping) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(25, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    std::cout << "  -> Starting cricket ambience for 8 seconds..." << std::endl;
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(8000000);
    inst->noteOff();
    usleep(500000);
    mixer.unregisterInstrument(inst.get());
}

void testCuckoo(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Cuckoo ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(26, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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

    mixer.unregisterInstrument(inst.get());
}

void testWaterfall(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Waterfall (multi-band ambient) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(27, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    std::cout << "  -> Starting waterfall ambience for 6 seconds..." << std::endl;
    inst->noteOn(-1.0f, gTestVelocity, -1.0f, gTestAmplitude);
    usleep(6000000);
    inst->noteOff();
    usleep(500000);
    mixer.unregisterInstrument(inst.get());
}

void testDjembe(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Djembe ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(28, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testMarimba(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Marimba ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(29, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

void testConga(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Conga ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(30, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
    std::vector<float> freqs = getTestFreqsFloat({130.0f, 150.0f, 150.0f});
    std::vector<float> positions = {0.0f, 2.0f, 1.0f};
    std::vector<int> strikes = {0, 1, 2};
    for (size_t i = 0; i < freqs.size(); ++i) {
        std::cout << "  -> Strike: " << strikes[i] << ", Freq: " << freqs[i] << " Hz, Position: " << positions[i] << std::endl;
        inst->setParam("position", positions[i]);
        inst->setParam("strike", strikes[i]);
        inst->noteOn(freqs[i], gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1500000);
        inst->noteOff();
        usleep(500000);
    }
    mixer.unregisterInstrument(inst.get());
}

void testBongo(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Bongo ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(31, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
    std::vector<float> freqs = getTestFreqsFloat({220.0f, 350.0f, 350.0f});
    std::vector<float> positions = {0.0f, 0.0f, 2.0f};
    std::vector<int> strikes = {0, 0, 1};
    for (size_t i = 0; i < freqs.size(); ++i) {
        std::cout << "  -> Strike: " << strikes[i] << ", Freq: " << freqs[i] << " Hz, Position: " << positions[i] << std::endl;
        inst->setParam("position", positions[i]);
        inst->setParam("strike", strikes[i]);
        inst->noteOn(freqs[i], gTestVelocity, -1.0f, gTestAmplitude);
        usleep(1200000);
        inst->noteOff();
        usleep(400000);
    }
    mixer.unregisterInstrument(inst.get());
}

void testVoice(FaustMixer& mixer, DSPExecutionType execType) {
    std::cout << "\n=== [Test] Singing Voice (Vowel Morphing) ===" << std::endl;
    auto inst = std::make_shared<FaustInstrument>(32, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    
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
    mixer.unregisterInstrument(inst.get());
}

// =====================================================
// MAIN EXECUTION
// =====================================================

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
        {32, "Voice"}
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
