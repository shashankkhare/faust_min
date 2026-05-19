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

void testInstrument(FaustMixer& mixer, int id, const std::string& name, bool isPercussion, DSPExecutionType execType) {
    std::cout << "\n=============================================" << std::endl;
    std::cout << "[Test] Loading Instrument ID " << id << " (" << name << ")" << std::endl;
    std::cout << "=============================================" << std::endl;

    // Instantiate directly
    auto inst = std::make_shared<FaustInstrument>(id, execType, InstrumentMapper::DEFAULT_SAMPLE_RATE);

    // Register with Mixer
    mixer.registerInstrument(inst.get(), 0.8f);

    if (isPercussion) {
        // Play Bols / Strikes
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
        // Play Major Notes (C4, E4, G4)
        double c4 = 261.63;
        double e4 = 329.63;
        double g4 = 392.00;

        std::cout << "  -> Playing Note C4 (" << c4 << " Hz)" << std::endl;
        inst->noteOn(c4, 0.8f, -1.0f);
        usleep(2500000); // 2.5s hold
        inst->noteOff();
        usleep(1000000); // 1.0s spacing

        std::cout << "  -> Playing Note E4 (" << e4 << " Hz)" << std::endl;
        inst->noteOn(e4, 0.8f, -1.0f);
        usleep(2500000);
        inst->noteOff();
        usleep(1000000);

        std::cout << "  -> Playing Note G4 (" << g4 << " Hz)" << std::endl;
        inst->noteOn(g4, 0.9f, -1.0f);
        usleep(3500000); // 3.5s hold
        inst->noteOff();
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
