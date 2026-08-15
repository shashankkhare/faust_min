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
    mixer.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    
    // Connect the Brain to the Heartbeat (Now required due to decoupling)
    mixer.setPreRenderCallback(SequenceOrchestrator::staticPreRender, &orch);
    
    mixer.start(); 

    // 2. Define a rhythmic Dayan (Tabla) sequence with a velocity ramp
    std::string umlDayan = 
        "grid: 4\n"
        "basefreq: 293.66\n"
        "\n"
        "1Na..1tk..2Tin..2Tun.. 3Na..4tk..5Tin..5Tun.. 6Na..7tk..8Tin..8Tun.. 9Na..9tk..9Tin..9Tun..";

    // Define a rhythmic Bayan sequence with a velocity ramp
    std::string umlBayan = 
        "grid: 4\n"
        "basefreq: 110.0\n"
        "\n"
        "1Ghe.._..2Ka.._.. 3Ghe.._..4Ka.._.. 5Ghe.._..6Ka.._.. 8Ghe.._..9Ka.._..";

    // 2b. Define a Flute sequence with a velocity/pressure ramp
    std::string umlFlute = 
        "grid: 4\n"
        "basefreq: 293.66\n"
        "instrument: flute\n"
        "notation: Indian\n"
        "\n"
        "2Sa...... 3Re...... 4Ga...... 5Ma...... 6Pa...... 7Dha...... 8Ni...... 9Sa......";

    std::cout << "[Test] Creating UMLSequences..." << std::endl;
    auto seqDayan = std::make_shared<UMLSequence>("TestDayan", 0, umlDayan);
    auto seqBayan = std::make_shared<UMLSequence>("TestBayan", 1, umlBayan);
    auto seqFlute = std::make_shared<UMLSequence>("TestFlute", 10, umlFlute);
    
    // 3. Register sequences with Orchestrator (The Brain)
    std::cout << "[Test] Adding sequences to Orchestrator..." << std::endl;
    orch.addSequence("TestDayan", seqDayan);
    orch.addSequence("TestBayan", seqBayan);
    orch.addSequence("TestFlute", seqFlute);
    
    // 3.1 SUPPLY INSTRUMENTS TO MIXER (The Heartbeat)
    std::cout << "[Test] Supplying instruments to Mixer..." << std::endl;
    int percussionTrack = mixer.addTrack(1.0f);
    int melodyTrack = mixer.addTrack(0.8f);
    
    mixer.addInstrumentToTrack(percussionTrack, seqDayan->getFaustInstrument(), 0.8f);
    mixer.addInstrumentToTrack(percussionTrack, seqBayan->getFaustInstrument(), 0.9f);
    mixer.addInstrumentToTrack(melodyTrack, seqFlute->getFaustInstrument(), 0.6f);

    // 4. Trigger Playback
    std::cout << "[Test] Starting Playback (Real-time hardware)..." << std::endl;
    orch.play("TestDayan");
    orch.play("TestBayan");
    orch.play("TestFlute");
    
    // 5. Auditory Verification Loop
    std::cout << "[Test] Playing for 10 seconds. Please listen to the output..." << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "  " << (10 - i) << "s remaining..." << std::endl;
        sleep(1);
    }

    std::cout << "\n[Test] --- TRANSITION: Unloading Tabla ---" << std::endl;
    // 1. Unregister from Mixer (The Muscle)
    mixer.removeTrack(percussionTrack);
    mixer.removeTrack(melodyTrack);

    // 2. Clear from Orchestrator (The Brain)
    orch.clearSequences(); 

    // 3. Sequences are reference-counted: they self-free when the orchestrator's
    //    last reference is dropped. No manual delete.

    std::cout << "\n[Test] --- ACT II: Jazz Orchestra ---" << std::endl;

    std::string umlPiano = 
        "grid: 4\n"
        "basefreq: 261.63\n"
        "instrument: piano\n"
        "notation: Western\n"
        "\n"
        "5C4.._..5Eb4.._.. 5F4.._..5G4.._.. 5Bb4.._..5C5.._.. 5Eb5.._..5F5.._..";

    std::string umlSax = 
        "grid: 4\n"
        "basefreq: 261.63\n"
        "instrument: sax\n"
        "notation: Western\n"
        "\n"
        "6G4...... 7Bb4...... 8C5...... 7G4...... 6F4...... 5Eb4...... 4C4...... 3C4......";

    std::string umlKick = 
        "grid: 4\n"
        "instrument: kick\n"
        "\n"
        "8x.._.._.._.. 8x.._.._.._.. 8x.._..8x.._.. 8x.._.._.._..";

    std::string umlSnare = 
        "grid: 4\n"
        "instrument: snare\n"
        "\n"
        "_.._..8x.._.. _.._..8x.._.. _.._..8x.._.. _.._..8x.._..";

    std::string umlHihat = 
        "grid: 4\n"
        "instrument: hihat\n"
        "\n"
        "6x.._..6x..7x.. 6x.._..6x..7x.. 6x.._..6x..7x.. 6x.._..6x..7x..";

    auto seqPiano = std::make_shared<UMLSequence>("JazzPiano", -1, umlPiano);
    auto seqSax = std::make_shared<UMLSequence>("JazzSax", -1, umlSax);
    auto seqKick = std::make_shared<UMLSequence>("JazzKick", -1, umlKick);
    auto seqSnare = std::make_shared<UMLSequence>("JazzSnare", -1, umlSnare);
    auto seqHihat = std::make_shared<UMLSequence>("JazzHihat", -1, umlHihat);

    orch.addSequence("JazzPiano", seqPiano);
    orch.addSequence("JazzSax", seqSax);
    orch.addSequence("JazzKick", seqKick);
    orch.addSequence("JazzSnare", seqSnare);
    orch.addSequence("JazzHihat", seqHihat);

    int jazzMelodyTrack = mixer.addTrack(1.0f);
    int jazzDrumTrack = mixer.addTrack(1.0f);

    mixer.addInstrumentToTrack(jazzMelodyTrack, seqPiano->getFaustInstrument(), 0.7f);
    mixer.addInstrumentToTrack(jazzMelodyTrack, seqSax->getFaustInstrument(), 0.8f);
    mixer.addInstrumentToTrack(jazzDrumTrack, seqKick->getFaustInstrument(), 0.9f);
    mixer.addInstrumentToTrack(jazzDrumTrack, seqSnare->getFaustInstrument(), 0.8f);
    mixer.addInstrumentToTrack(jazzDrumTrack, seqHihat->getFaustInstrument(), 0.6f);

    std::cout << "[Test] Playing Jazz Piano for 4 seconds..." << std::endl;
    orch.play("JazzPiano");
    for (int i = 0; i < 4; i++) { sleep(1); }
    orch.stop();

    std::cout << "[Test] Playing Jazz Sax for 4 seconds..." << std::endl;
    orch.play("JazzSax");
    for (int i = 0; i < 4; i++) { sleep(1); }
    orch.stop();

    std::cout << "[Test] Playing Jazz Kick for 4 seconds..." << std::endl;
    orch.play("JazzKick");
    for (int i = 0; i < 4; i++) { sleep(1); }
    orch.stop();

    std::cout << "[Test] Playing Jazz Snare for 4 seconds..." << std::endl;
    orch.play("JazzSnare");
    for (int i = 0; i < 4; i++) { sleep(1); }
    orch.stop();

    std::cout << "[Test] Playing Jazz Hihat for 4 seconds..." << std::endl;
    orch.play("JazzHihat");
    for (int i = 0; i < 4; i++) { sleep(1); }
    orch.stop();

    std::cout << "[Test] Playing FULL Jazz Orchestra for 6 seconds..." << std::endl;
    orch.play("JazzPiano");
    orch.play("JazzSax");
    orch.play("JazzKick");
    orch.play("JazzSnare");
    orch.play("JazzHihat");
    for (int i = 0; i < 6; i++) { sleep(1); }

    mixer.stop();
    mixer.removeTrack(jazzMelodyTrack);
    mixer.removeTrack(jazzDrumTrack);
    orch.clearSequences();

    std::cout << "\nSUCCESS: Test playback cycle completed." << std::endl;
    std::cout << "--- Test Complete ---" << std::endl;
    return 0;
}
