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

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unistd.h>
#include <algorithm>
#include "../src/SequenceOrchestrator.hpp"
#include "../src/FaustMixer.hpp"
#include "../src/UMLParser.hpp"
#include "../src/InstrumentMapper.hpp"

// Helper structure to group sequences for a style
struct SequenceGroup {
    std::string name;
    std::vector<std::pair<std::string, UMLSequence*>> sequences;
    std::vector<float> volumes;
};

// Global stop flag for playback thread wait
static bool gStopPlayback = false;

void playSequenceGroup(FaustMixer& mixer, SequenceOrchestrator& orch, SequenceGroup& group, int durationSeconds) {
    std::cout << "\n=== Starting Sequence: " << group.name << " ===" << std::endl;
    
    // 1. Register sequences and instruments
    for (size_t i = 0; i < group.sequences.size(); ++i) {
        auto& seqPair = group.sequences[i];
        orch.addSequence(seqPair.first, seqPair.second);
        mixer.registerInstrument(seqPair.second->getFaustInstrument(), group.volumes[i]);
    }

    // 2. Play
    for (auto& seqPair : group.sequences) {
        orch.play(seqPair.first);
    }

    std::cout << "[Playback] Playing for " << durationSeconds << " seconds. Listen closely..." << std::endl;
    for (int i = 0; i < durationSeconds; ++i) {
        std::cout << "  " << (durationSeconds - i) << "s remaining..." << std::endl;
        sleep(1);
    }

    // 3. Stop and Unload
    orch.stop();
    for (auto& seqPair : group.sequences) {
        mixer.unregisterInstrument(seqPair.second->getFaustInstrument());
    }
    orch.clearSequences();

    // 4. Free memory
    for (auto& seqPair : group.sequences) {
        delete seqPair.second;
    }
    group.sequences.clear();
    
    std::cout << "=== Finished Sequence: " << group.name << " ===\n" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "--- Standalone Multi-Style Sequence Validation Runner ---" << std::endl;

    // 1. Setup Orchestrator and Mixer
    SequenceOrchestrator& orch = SequenceOrchestrator::getInstance();
    FaustMixer& mixer = FaustMixer::getInstance();
    
    mixer.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.setPreRenderCallback(SequenceOrchestrator::staticPreRender, &orch);
    mixer.start(); 

    // Command-line or interactive selection
    int selection = -1;
    if (argc > 1) {
        try {
            selection = std::stoi(argv[1]);
        } catch (...) {
            selection = -1;
        }
    }

    while (true) {
        if (selection == -1) {
            std::cout << "\nSelect a sequence to play:" << std::endl;
            std::cout << "  1. Indian Classical (Sitar, Tanpura, Tabla, Bansuri)" << std::endl;
            std::cout << "  2. Jazz Ensemble (Piano, Sax, Bass, Drums)" << std::endl;
            std::cout << "  3. Rock Band (Electric Guitar, Bass, Drums)" << std::endl;
            std::cout << "  4. Tibetan Bowl with Rain (Bowl, Bell, Rainmaker)" << std::endl;
            std::cout << "  5. Acoustic Hotel California (Acoustic Guitar, 3 Congas, Bass, Drums)" << std::endl;
            std::cout << "  6. Exit" << std::endl;
            std::cout << ">>> Enter selection (1-6): ";
            if (!(std::cin >> selection)) {
                break;
            }
        }

        if (selection == 6) {
            break;
        }

        SequenceGroup group;
        int duration = 15; // default duration 15s

        if (selection == 1) {
            group.name = "Indian Classical";
            
            std::string umlTanpura = 
                "grid: 2\n"
                "basefreq: 130.81\n"
                "instrument: tanpura\n"
                "notation: Indian\n"
                "\n"
                "5Pa...... 5Sa...... 5Pa...... 5Sa......";
                
            std::string umlSitar = 
                "grid: 4\n"
                "basefreq: 130.81\n"
                "instrument: sitar\n"
                "notation: Indian\n"
                "\n"
                "6Sa..6Re..6Ga.._.. 6Pa..6Dha..8Sa.._.. 8Sa..6Dha..6Pa.._.. 6Ga..6Re..6Sa.._..";
                
            std::string umlBansuri = 
                "grid: 4\n"
                "basefreq: 261.63\n"
                "instrument: bansuri\n"
                "notation: Indian\n"
                "\n"
                "_.... 6Sa...... 6Ga...... 6Pa...... 6Dha...... 8Sa...... 6Dha...... 6Pa...... 6Ga...... 6Re...... 6Sa......";
                
            std::string umlDayan = 
                "grid: 4\n"
                "basefreq: 293.66\n"
                "instrument: dayan\n"
                "\n"
                "1Na..1tk..2Tin..2Tun.. 3Na..4tk..5Tin..5Tun.. 6Na..7tk..8Tin..8Tun.. 9Na..9tk..9Tin..9Tun..";
                
            std::string umlBayan = 
                "grid: 4\n"
                "basefreq: 110.0\n"
                "instrument: bayan\n"
                "\n"
                "1Ghe.._..2Ka.._.. 3Ghe.._..4Ka.._.. 5Ghe.._..6Ka.._.. 8Ghe.._..9Ka.._..";

            group.sequences.push_back({"Tanpura", new UMLSequence("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Sitar", new UMLSequence("Sitar", 9, umlSitar)});
            group.sequences.push_back({"Bansuri", new UMLSequence("Bansuri", 17, umlBansuri)});
            group.sequences.push_back({"Dayan", new UMLSequence("Dayan", 0, umlDayan)});
            group.sequences.push_back({"Bayan", new UMLSequence("Bayan", 1, umlBayan)});
            
            group.volumes = { 0.5f, 0.7f, 0.6f, 0.6f, 0.8f };
            duration = 20;

        } else if (selection == 2) {
            group.name = "Jazz Ensemble";

            std::string umlPiano = 
                "grid: 4\n"
                "basefreq: 261.63\n"
                "instrument: piano\n"
                "notation: Indian\n"
                "\n"
                "6Sa...... 6Ga...... 6Pa...... 6Ni...... 8Sa...... 6Ni...... 6Pa...... 6Ga......";
                
            std::string umlSax = 
                "grid: 4\n"
                "basefreq: 261.63\n"
                "instrument: sax\n"
                "notation: Indian\n"
                "\n"
                "_... 6Re...... 6Ma...... 6Dha...... 6Ni...... 8Sa...... 6Dha...... 6Ma...... 6Re......";
                
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

            group.sequences.push_back({"JazzPiano", new UMLSequence("JazzPiano", 12, umlPiano)});
            group.sequences.push_back({"JazzSax", new UMLSequence("JazzSax", 13, umlSax)});
            group.sequences.push_back({"JazzKick", new UMLSequence("JazzKick", 2, umlKick)});
            group.sequences.push_back({"JazzSnare", new UMLSequence("JazzSnare", 3, umlSnare)});
            group.sequences.push_back({"JazzHihat", new UMLSequence("JazzHihat", 4, umlHihat)});
            
            group.volumes = { 0.6f, 0.7f, 0.8f, 0.7f, 0.5f };
            duration = 15;

        } else if (selection == 3) {
            group.name = "Rock Band (Hotel California)";

            std::string umlEGuitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: electricguitar\n"
                "notation: Western\n"
                "\n"
                // Measure 1-4 (Bm, F#, A, E)
                "B3 D4 F#4 D4 B3 D4 F#4 D4 "
                "A#3 C#4 F#4 C#4 A#3 C#4 F#4 C#4 "
                "A3 C#4 E4 C#4 A3 C#4 E4 C#4 "
                "G#3 B3 E4 B3 G#3 B3 E4 B3 "
                // Measure 5-8 (G, D, Em, F#)
                "G3 B3 D4 B3 G3 B3 D4 B3 "
                "F#3 A3 D4 A3 F#3 A3 D4 A3 "
                "E3 G3 B3 G3 E3 G3 B3 G3 "
                "F#3 A#3 C#4 A#3 F#3 A#3 C#4 A#3 "
                // Repeat Measure 1-4
                "B3 D4 F#4 D4 B3 D4 F#4 D4 "
                "A#3 C#4 F#4 C#4 A#3 C#4 F#4 C#4 "
                "A3 C#4 E4 C#4 A3 C#4 E4 C#4 "
                "G#3 B3 E4 B3 G#3 B3 E4 B3 "
                // Repeat Measure 5-8
                "G3 B3 D4 B3 G3 B3 D4 B3 "
                "F#3 A3 D4 A3 F#3 A3 D4 A3 "
                "E3 G3 B3 G3 E3 G3 B3 G3 "
                "F#3 A#3 C#4 A#3 F#3 A#3 C#4 A#3";
                
            std::string umlBGuitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: bassguitar\n"
                "notation: Western\n"
                "\n"
                // Measures 1-8 (Bm, F#, A, E, G, D, Em, F#)
                "B1. B1. F#1. F#1. A1. A1. E1. E1. "
                "G1. G1. D2. D2. E1. E1. F#1. F#1. "
                // Repeat Measures 1-8
                "B1. B1. F#1. F#1. A1. A1. E1. E1. "
                "G1. G1. D2. D2. E1. E1. F#1. F#1.";
                
            std::string umlKick = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: kick\n"
                "\n"
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x.";
                
            std::string umlSnare = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: snare\n"
                "\n"
                "_. 8x. _. 8x. _. 8x. _. 8x. "
                "_. 8x. _. 8x. _. 8x. _. 8x. "
                "_. 8x. _. 8x. _. 8x. _. 8x. "
                "_. 8x. _. 8x. _. 8x. _. 8x.";
                
            std::string umlHihat = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: hihat\n"
                "\n"
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x";

            group.sequences.push_back({"RockEGuitar", new UMLSequence("RockEGuitar", 22, umlEGuitar)});
            group.sequences.push_back({"RockBGuitar", new UMLSequence("RockBGuitar", 23, umlBGuitar)});
            group.sequences.push_back({"RockKick", new UMLSequence("RockKick", 2, umlKick)});
            group.sequences.push_back({"RockSnare", new UMLSequence("RockSnare", 3, umlSnare)});
            group.sequences.push_back({"RockHihat", new UMLSequence("RockHihat", 4, umlHihat)});

            group.volumes = { 0.7f, 0.8f, 0.9f, 0.8f, 0.6f };
            duration = 24;

        } else if (selection == 4) {
            group.name = "Tibetan Bowl with Rain";

            std::string umlRainmaker = 
                "grid: 1\n"
                "instrument: rainmaker\n"
                "\n"
                "8x................................";
                
            std::string umlBowl = 
                "grid: 2\n"
                "basefreq: 140.0\n"
                "instrument: bowl\n"
                "notation: Indian\n"
                "\n"
                "8Sa................ 8Ga................ 8Pa................ 8Sa................";
                
            std::string umlBell = 
                "grid: 2\n"
                "basefreq: 440.0\n"
                "instrument: bell\n"
                "notation: Indian\n"
                "\n"
                "_... 6Sa................ 6Pa................ 6Ni................";

            group.sequences.push_back({"AmbientRain", new UMLSequence("AmbientRain", 19, umlRainmaker)});
            group.sequences.push_back({"AmbientBowl", new UMLSequence("AmbientBowl", 8, umlBowl)});
            group.sequences.push_back({"AmbientBell", new UMLSequence("AmbientBell", 7, umlBell)});

            group.volumes = { 0.9f, 0.7f, 0.6f };
            duration = 20;
        } else if (selection == 5) {
            group.name = "Acoustic Hotel California (Acoustic Guitar, 3 Congas, Bass, Drums)";

            std::string umlAGuitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: acousticguitar\n"
                "notation: Western\n"
                "\n"
                // Measure 1-4 (Bm, F#, A, E)
                "B3 D4 F#4 D4 B3 D4 F#4 D4 "
                "A#3 C#4 F#4 C#4 A#3 C#4 F#4 C#4 "
                "A3 C#4 E4 C#4 A3 C#4 E4 C#4 "
                "G#3 B3 E4 B3 G#3 B3 E4 B3 "
                // Measure 5-8 (G, D, Em, F#)
                "G3 B3 D4 B3 G3 B3 D4 B3 "
                "F#3 A3 D4 A3 F#3 A3 D4 A3 "
                "E3 G3 B3 G3 E3 G3 B3 G3 "
                "F#3 A#3 C#4 A#3 F#3 A#3 C#4 A#3 "
                // Repeat Measure 1-4
                "B3 D4 F#4 D4 B3 D4 F#4 D4 "
                "A#3 C#4 F#4 C#4 A#3 C#4 F#4 C#4 "
                "A3 C#4 E4 C#4 A3 C#4 E4 C#4 "
                "G#3 B3 E4 B3 G#3 B3 E4 B3 "
                // Repeat Measure 5-8
                "G3 B3 D4 B3 G3 B3 D4 B3 "
                "F#3 A3 D4 A3 F#3 A3 D4 A3 "
                "E3 G3 B3 G3 E3 G3 B3 G3 "
                "F#3 A#3 C#4 A#3 F#3 A#3 C#4 A#3";

            std::string umlBGuitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: bassguitar\n"
                "notation: Western\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-8: Active chord-aligned sustain notes (64 steps total: 8 steps per chord)
                "G1....... D2....... E1....... F#1....... "
                "B1....... F#1....... A1....... E1.......";

            // Tumba (Low Conga, e.g. 130 Hz): plays deep, syncopated accents on beats 1, 3, and "and" of 2/4
            std::string umlCongaLow = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 130.0\n"
                "instrument: conga\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-8: Active patterns (4 repeats of 16-step pattern = 64 steps)
                "ba _ _ _  _ ba _ _  ba _ _ _  _ ba _ _ "
                "ba _ _ _  _ ba _ _  ba _ _ _  _ ba _ _ "
                "ba _ _ _  _ ba _ _  ba _ _ _  _ ba _ _ "
                "ba _ _ _  _ ba _ _  ba _ _ _  _ ba _ _";

            // Segundo (Mid Conga, e.g. 175 Hz): steady mid open tones on beats 3 and 4
            std::string umlCongaMid = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 175.0\n"
                "instrument: conga\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-8: Active patterns (4 repeats of 16-step pattern = 64 steps)
                "mu mu to _  mu mu to _  mu mu to _  mu mu to _ "
                "mu mu to _  mu mu to _  mu mu to _  mu mu to _ "
                "mu mu to _  mu mu to _  mu mu to _  mu mu to _ "
                "mu mu to _  mu mu to _  mu mu to _  mu mu to _";

            // Quinto (High Conga, e.g. 225 Hz): sharp edge slaps (sl) and muted taps (mu)
            std::string umlCongaHigh = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 225.0\n"
                "instrument: conga\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-8: Active patterns (4 repeats of 16-step pattern = 64 steps)
                "sl _ mu mu  _ sl mu mu  sl _ mu mu  _ sl mu mu "
                "sl _ mu mu  _ sl mu mu  sl _ mu mu  _ sl mu mu "
                "sl _ mu mu  _ sl mu mu  sl _ mu mu  _ sl mu mu "
                "sl _ mu mu  _ sl mu mu  sl _ mu mu  _ sl mu mu";

            std::string umlKick = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: kick\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-8: Active patterns (8 repeats of 8-step pattern = 64 steps)
                "8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _";
                
            std::string umlSnare = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: snare\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-8: Active patterns (8 repeats of 8-step pattern = 64 steps)
                "_ _ 8x. _  _ _ 8x. _  "
                "_ _ 8x. _  _ _ 8x. _  "
                "_ _ 8x. _  _ _ 8x. _  "
                "_ _ 8x. _  _ _ 8x. _  "
                "_ _ 8x. _  _ _ 8x. _  "
                "_ _ 8x. _  _ _ 8x. _  "
                "_ _ 8x. _  _ _ 8x. _  "
                "_ _ 8x. _  _ _ 8x. _";

            group.sequences.push_back({"AcousticGuitar", new UMLSequence("AcousticGuitar", 21, umlAGuitar)});
            group.sequences.push_back({"AcousticBass", new UMLSequence("AcousticBass", 23, umlBGuitar)});
            group.sequences.push_back({"CongaLow", new UMLSequence("CongaLow", 30, umlCongaLow)});
            group.sequences.push_back({"CongaMid", new UMLSequence("CongaMid", 30, umlCongaMid)});
            group.sequences.push_back({"CongaHigh", new UMLSequence("CongaHigh", 30, umlCongaHigh)});
            group.sequences.push_back({"AcousticKick", new UMLSequence("AcousticKick", 2, umlKick)});
            group.sequences.push_back({"AcousticSnare", new UMLSequence("AcousticSnare", 3, umlSnare)});

            group.volumes = { 0.7f, 1.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f };
            duration = 32;
        }

        if (!group.sequences.empty()) {
            playSequenceGroup(mixer, orch, group, duration);
        } else {
            std::cout << "Invalid selection. Please try again." << std::endl;
        }

        // If run with command line arg, exit after playing once
        if (argc > 1) {
            break;
        }
        
        selection = -1; // Reset for next loop in interactive mode
    }

    mixer.stop();
    std::cout << "--- Runner Complete ---" << std::endl;
    return 0;
}
