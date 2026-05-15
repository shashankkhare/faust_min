/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file test_orchestrator.cpp
 * @brief Implementation file for test_orchestrator
 * 
 * DESIGN: Hardware-level validation suite. It verifies the pure Controller-Sink model by running a real-time playback loop through the system's audio driver.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unistd.h>
#include "../src/SequenceOrchestrator.hpp"
#include "../src/FaustMixer.hpp"
#include "../src/UMLParser.hpp"
#include "../src/InstrumentMapper.hpp"

/**
 * @brief Standalone C++ Engine Validation Test.
 * 
 * Demonstrates explicit registration of instruments into the FaustMixer 
 * and manual driving of the audio loop for signal verification.
 */
int main() {
    std::cout << "--- Standalone C++ Engine Validation ---" << std::endl;

    // 1. Setup Orchestrator and Mixer
    SequenceOrchestrator& orch = SequenceOrchestrator::getInstance();
    FaustMixer& mixer = FaustMixer::getInstance();
    
    std::cout << "[Test] Initializing engine..." << std::endl;
    orch.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.start(); 

    // 2. Define a rhythmic Dayan (Tabla) sequence
    std::string uml = 
        "grid: 4\n"
        "basefreq: 293.66\n"
        "\n"
        "9Na..tk..5Tin..Tun..";

    std::cout << "[Test] Creating UMLSequence..." << std::endl;
    UMLSequence* seq = new UMLSequence("TestDayan", 0, uml);
    
    // 3. Register sequence with Orchestrator
    std::cout << "[Test] Adding sequence to Orchestrator..." << std::endl;
    orch.addSequence("TestDayan", seq);

    // 4. Trigger Playback
    std::cout << "[Test] Starting Playback (Real-time hardware)..." << std::endl;
    orch.play("TestDayan");
    
    // 5. Auditory Verification Loop
    std::cout << "[Test] Playing for 5 seconds. Please listen to the output..." << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "  " << (5 - i) << "s remaining..." << std::endl;
        sleep(1);
    }

    std::cout << "\nSUCCESS: Test playback cycle completed." << std::endl;
    std::cout << "--- Test Complete ---" << std::endl;
    return 0;
}
