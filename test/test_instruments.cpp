/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * test_instruments.cpp
 * Directly instantiates FaustInstrument for every mapped ID and tests them sequentially via FaustMixer, bypassing SequenceOrchestrator.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unistd.h>
#include <memory>
#include "../src/FaustMixer.hpp"
#include "../src/InstrumentMapper.hpp"
#include "../src/FaustInstrument.hpp"

std::vector<double> getTestFrequencies(int id) {
    if (id == 0) { // Dayan
        return { 130.81, 170.00, 210.00, 261.63 }; // 130 to 260 Hz range, covering all 4 strikes
    }
    if (id == 1) { // Bayan
        return { 65.41, 85.00, 105.00, 130.81 }; // 65 to 130 Hz range, covering all 4 strikes
    }
    if (id == 2) { // Kick
        return { 65.41, 98.00, 130.81 }; // 65 to 130 Hz range
    }
    if (id == 11) { // Tanpura
        return { 130.81, 196.00, 261.63 }; // 130 to 260 Hz range
    }
    // Unpitched percussion (Snare, HiHat, Tom, Ride, Cowbell)
    if (id == 3 || id == 4 || id == 5 || id == 6 || id == 14) {
        return {};
    }
    // Default frequencies for other melodic instruments (C4, E4, G4)
    return { 261.63, 329.63, 392.00 };
}

void testInstrument(FaustMixer& mixer, int id, const std::string& name, bool isPercussion, DSPExecutionType execType) {
    std::cout << "\n=============================================" << std::endl;
    std::cout << "[Test] Loading Instrument ID " << id << " (" << name << ")" << std::endl;
    std::cout << "=============================================" << std::endl;

    // Instantiate directly
    auto inst = std::make_shared<FaustInstrument>(id, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);

    // Register with Mixer
    mixer.registerInstrument(inst.get(), 0.8f);

    std::vector<double> freqs = getTestFrequencies(id);
    if (freqs.empty()) {
        // Play Bols / Strikes for unpitched percussion
        std::cout << "  -> Playing Strike 1" << std::endl;
        inst->noteOn(0.0f, 0.8f, 1.0f); // Velocity 0.8, Strike type 1.0
        usleep(2500000); // 2.5s hold
        inst->noteOff();
        usleep(1000000); // 1.0s spacing

        std::cout << "  -> Playing Strike 2" << std::endl;
        inst->noteOn(0.0f, 0.9f, 2.0f);
        usleep(2500000);
        inst->noteOff();
    } else {
        long holdTime = (id == 11) ? 12000000 : 2500000; // 12s for Tanpura plucks to resolve
        long lastHoldTime = (id == 11) ? 12000000 : 3500000;

        for (size_t i = 0; i < freqs.size(); ++i) {
            double freq = freqs[i];
            long currentHold = (i == freqs.size() - 1) ? lastHoldTime : holdTime;
            
            float strikeParam = -1.0f;
            if (id == 0 || id == 1) { // Dayan, Bayan
                strikeParam = static_cast<float>(i % 4); // Loop through strike types 0, 1, 2, 3
            } else if (id == 2) { // Kick
                strikeParam = 1.0f; // generic trigger
            }

            if (id == 11) { // Tanpura
                inst->setParam("freq1", freq * 1.5f);
            }

            std::cout << "  -> Playing Note (" << freq << " Hz), Strike: " << strikeParam << std::endl;
            inst->noteOn(freq, (i == freqs.size() - 1) ? 0.9f : 0.8f, strikeParam);
            usleep(currentHold);
            inst->noteOff();
            if (i < freqs.size() - 1) {
                usleep(1500000); // 1.5s spacing
            }
        }
    }

    usleep(1500000); // Wait for release tail

    // Unregister cleanly
    mixer.unregisterInstrument(inst.get());
    std::cout << "[Test] Finished " << name << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "--- Standalone Instrument Validation (Bypassing Orchestrator) ---" << std::endl;

    DSPExecutionType execType = DSPExecutionType::InterpretedByte; // Default to InterpretedByte
    
    // Parse arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--static" || arg == "-s") {
            execType = DSPExecutionType::StaticCompiled;
        } else if (arg == "--interpreter" || arg == "-i") {
            execType = DSPExecutionType::InterpretedByte;
        }
    }

    std::cout << "[Config] Using Execution Mode: " 
              << (execType == DSPExecutionType::StaticCompiled ? "StaticCompiled" : "Interpreter (InterpretedByte)") 
              << std::endl;

    FaustMixer& mixer = FaustMixer::getInstance();
    
    std::cout << "[Test] Initializing Mixer..." << std::endl;
    mixer.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    
    mixer.start();

    // Map of ID -> Name -> IsPercussion
    std::vector<std::tuple<int, std::string, bool>> instruments = {
        {0, "Dayan", true},
        {1, "Bayan", true},
        {2, "Kick", true},
        {3, "Snare", true},
        {4, "HiHat", true},
        {5, "Tom", true},
        {6, "Ride", true},
        {7, "Bell", false},
        {8, "Bowl", false},
        {9, "Sitar", false},
        {10, "Flute", false},
        {11, "Tanpura", false},
        {12, "Piano", false},
        {13, "Sax", false},
        {14, "Cowbell", true}
    };

    std::cout << "\n--- Available Instruments ---" << std::endl;
    for (const auto& tup : instruments) {
        std::cout << "  ID " << std::get<0>(tup) << " : " << std::get<1>(tup) << std::endl;
    }

    while (true) {
        std::cout << "\n>>> Enter Instrument ID to test (or -1 to quit): ";
        int inputID;
        if (!(std::cin >> inputID) || inputID == -1) {
            break;
        }

        auto it = std::find_if(instruments.begin(), instruments.end(), [inputID](const std::tuple<int, std::string, bool>& t) {
            return std::get<0>(t) == inputID;
        });

        if (it != instruments.end()) {
            std::string name = std::get<1>(*it);
            bool isPercussion = std::get<2>(*it);
            testInstrument(mixer, inputID, name, isPercussion, execType);
        } else {
            std::cout << "Invalid Instrument ID. Please try again." << std::endl;
        }
    }

    mixer.stop();
    std::cout << "\nSUCCESS: All instruments tested sequentially." << std::endl;
    std::cout << "--- Test Complete ---" << std::endl;
    return 0;
}
