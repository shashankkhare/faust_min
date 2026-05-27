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

    // Enable looping feature
    orch.setLooping(true);

    // 2. Play
    for (auto& seqPair : group.sequences) {
        orch.play(seqPair.first);
    }

    // Play indefinitely until user presses a key
    std::cout << "[Playback] Playing Sequence (Looping Enabled). Press ENTER to stop..." << std::endl;
    
    // Clear the input buffer from the previous selection
    std::cin.ignore(10000, '\n');
    // Wait for the user to press ENTER
    std::cin.get();

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
            std::cout << "  1. Indian Classical — Bhopali (Bansuri, Tanpura, Tabla)" << std::endl;
            std::cout << "  2. Jazz Ensemble (Piano, Sax, Bass, Drums)" << std::endl;
            std::cout << "  3. Rock Band (Electric Guitar, Bass, Drums)" << std::endl;
            std::cout << "  4. Tibetan Bowl with Rain (Bowl, Bell, Rainmaker)" << std::endl;
            std::cout << "  5. Acoustic Hotel California (Acoustic Guitar, 3 Congas, Bass, Drums)" << std::endl;
            std::cout << "  6. Sitar — Raag Yaman + Tabla" << std::endl;
            std::cout << "  7. Indian Folk (Dholak Percussion)" << std::endl;
            std::cout << "  8. Punjabi Folk (Dhol Percussion)" << std::endl;
            std::cout << "  9. Exit" << std::endl;
            std::cout << ">>> Enter selection (1-9): ";
            if (!(std::cin >> selection)) {
                break;
            }
        }

        if (selection == 9) {
            break;
        }

        SequenceGroup group;
        int duration = 15; // default duration 15s

        if (selection == 1) {
            group.name = "Indian Classical — Raag Bhopali (Bansuri, Tanpura) + Tabla Jawab-Talab";
            
            std::string umlTanpura = 
                "grid: 2\n"
                "basefreq: 111.0\n"
                "instrument: tanpura\n"
                "notation: Indian\n"
                "\n"
                "5Sa............... _............... "
                "5Sa............... _...............";
                
            std::string umlBansuri = 
                "grid: 4\n"
                "basefreq: 222\n"
                "instrument: bansuri\n"
                "notation: Indian\n"
                "parameters: vibrato=0.8\n"
                "\n"
                "6Sa...6Re...6Ga...6Pa...6Dha...6Pa...6Ga...6Re... "
                "6Sa...6Ga...6Pa...6Dha...6Pa...6Ga...6Re...6Sa..._ "
                "_... _... _... _... "
                "6Sa...6Re...6Ga...6Pa... "
                "_... _... _... _... "
                "6Dha...6Pa...6Ga...6Re... "
                "_... _... _... _... "
                "6Sa..._...";
                
            std::string umlDayan = 
                "grid: 4\n"
                "basefreq: 222\n"
                "instrument: dayan\n"
                "\n"
                "Na... Tin... Tun... tk... Na... Tin... Na... tk... "
                "Tun... Tin... Na... Tun... Na... tk... Tin... Tun... "
                "Na... Tin... Tun... tk... _... _... _... _... "
                "Tun... Tin... Na... Tun... _... _... _... _... "
                "Na... Tin... Tun... tk... _... _... _... _...";

            std::string umlBayan = 
                "grid: 4\n"
                "basefreq: 111\n"
                "instrument: bayan\n"
                "\n"
                "Ghe... _... _... Ka... _... Ka... Ghe... _... "
                "Ghe... Ka... Ghe... Ke... Ghi... Ghe... Ka... Ghe... "
                "Ghe... _... _... Ka... _... _... _... _... "
                "Ghe... Ka... Ghe... Ke... _... _... _... _... "
                "Ghi... Ghe... Ka... Ghe... _... _... _... _...";

            group.sequences.push_back({"Tanpura", new UMLSequence("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Bansuri", new UMLSequence("Bansuri", 17, umlBansuri)});
            group.sequences.push_back({"Dayan", new UMLSequence("Dayan", 0, umlDayan)});
            group.sequences.push_back({"Bayan", new UMLSequence("Bayan", 1, umlBayan)});
            
            group.volumes = { 2.2f, 0.9f, 0.9f, 1.0f };
            duration = 16;
        } else if (selection == 2) {
            group.name = "Jazz Ensemble";

            std::string umlPiano = 
                "grid: 4\n"
                "basefreq: 261.63\n"
                "instrument: piano\n"
                "notation: Western\n"
                "\n"
                "C4... E4... G4... B4... D4... F4... A4... C5... "
                "B3... D4... F4... G4... C4... E4... G4... C5... "
                "E5.. D5.. C5.. B4.. A4.. G4.. F4.. E4.. "
                "D4.. C4.. B3.. A3.. G3.. F3.. E3.. C3..";
                
            std::string umlSax = 
                "grid: 4\n"
                "basefreq: 261.63\n"
                "instrument: sax\n"
                "notation: Western\n"
                "\n"
                "_... G4... B4... D5... _... F4... A4... C5... "
                "_... E4... G4... B4... _... D4... F4... A4... "
                "G4.. A4.. B4.. C5.. D5.. C5.. B4.. A4.. "
                "G4.. F4.. E4.. D4.. C4.. B3.. C4.. _...";
                
            std::string umlBass = 
                "grid: 4\n"
                "instrument: bassguitar\n"
                "notation: Western\n"
                "\n"
                "C2.. _.. E2.. _.. G2.. _.. B2.. _.. "
                "D2.. _.. F2.. _.. A2.. _.. C3.. _.. "
                "B1.. _.. D2.. _.. F2.. _.. G2.. _.. "
                "C2.. _.. E2.. _.. G2.. _.. C3.. _..";
                
            std::string umlKick = 
                "grid: 4\n"
                "instrument: kick\n"
                "\n"
                "8x... _... _... _... 8x... _... 8x... _... "
                "_... 8x... _... _... 8x... _... _... 8x... "
                "8x... _... _... _... 8x... _... 8x... _... "
                "_... 8x... _... _... 8x... _... _... _...";
                
            std::string umlSnare = 
                "grid: 4\n"
                "instrument: snare\n"
                "\n"
                "_... _... 8x... _... _... _... 8x... _... "
                "_... 8x... _... _... 8x... _... _... _... "
                "_... _... 8x... 8x.. _... _... 8x... _... "
                "_... 8x... _... _... 8x... _... _... _...";
                
            std::string umlRide = 
                "grid: 4\n"
                "instrument: ride\n"
                "\n"
                "8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x. "
                "8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x. "
                "8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x. "
                "8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x. 8x... 8x.8x.";

            group.sequences.push_back({"JazzPiano", new UMLSequence("JazzPiano", 12, umlPiano)});
            group.sequences.push_back({"JazzSax", new UMLSequence("JazzSax", 13, umlSax)});
            group.sequences.push_back({"JazzBass", new UMLSequence("JazzBass", 23, umlBass)});
            group.sequences.push_back({"JazzKick", new UMLSequence("JazzKick", 2, umlKick)});
            group.sequences.push_back({"JazzSnare", new UMLSequence("JazzSnare", 3, umlSnare)});
            group.sequences.push_back({"JazzRide", new UMLSequence("JazzRide", 6, umlRide)});
            
            group.volumes = { 0.5f, 0.7f, 0.7f, 0.6f, 0.5f, 0.4f };
            duration = 20;

        } else if (selection == 3) {
            group.name = "Rock Band (Hotel California)";

            std::string umlEGuitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: electricguitar\n"
                "notation: Western\n"
                "parameters: drive=0.75,sustain=0.8\n"
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
                "B1. B1. F#1. F#1. A1. A1. E1. E1. "
                "G1. G1. D2. D2. E1. E1. F#1. F#1. "
                "B1. B1. F#1. F#1. A1. A1. E1. E1. "
                "G1. G1. D2. D2. E1. E1. F#1. F#1. "
                "B1. B1. F#1. F#1. A1. A1. E1. E1. "
                "G1. G1. D2. D2. E1. E1. F#1. F#1.";
                
            std::string umlKick = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: kick\n"
                "\n"
                "8x _ _ 8x  _ 8x _ _  8x _ _ 8x  _ _ 8x _ "
                "8x _ _ _  8x 8x _ _  8x _ 8x _  _ _ 8x _ "
                "8x _ 8x _  _ 8x _ 8x  8x _ _ _  8x 8x _ _ "
                "8x _ _ 8x  _ _ 8x _  8x 8x _ 8x  _ 8x 8x _ "
                "8x _ _ 8x  _ 8x _ _  8x _ _ 8x  _ _ 8x _ "
                "8x _ _ _  8x 8x _ _  8x _ 8x _  _ _ 8x _ "
                "8x _ 8x _  _ 8x _ 8x  8x _ _ _  8x 8x _ _ "
                "8x _ _ 8x  _ _ 8x _  8x 8x _ 8x  _ 8x 8x _";
                
            std::string umlSnare = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: snare\n"
                "\n"
                "_ _ _ _ 8x _ _ 8x _ _ _ _ 8x _ _ _ "
                "_ _ _ 8x 8x _ _ _ _ 8x _ _ 8x _ 8x 8x "
                "_ _ _ _ 8x _ _ _ _ _ 8x _ 8x _ _ _ "
                "_ _ 8x _ 8x _ _ 8x _ 8x _ 8x 8x 8x 8x 8x "
                "_ _ _ _ 8x _ _ 8x _ _ _ _ 8x _ _ _ "
                "_ _ _ 8x 8x _ _ _ _ 8x _ _ 8x _ 8x 8x "
                "_ _ _ _ 8x _ _ _ _ _ 8x _ 8x _ _ _ "
                "_ 8x _ 8x 8x _ 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x";
                
            std::string umlHihat = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: hihat\n"
                "\n"
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x _ 8x _ 8x 8x 8x 8x 8x _ 8x _ 8x 8x 8x 8x "
                "8x 8x 8x 8x _ 8x 8x 8x 8x 8x 8x 8x _ 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x _ _ _ _ _ _ _ "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x _ 8x _ 8x 8x 8x 8x 8x _ 8x _ 8x 8x 8x 8x "
                "8x 8x 8x 8x _ 8x 8x 8x 8x 8x 8x 8x _ 8x 8x 8x "
                "8x 8x _ _ _ _ _ _ _ _ _ _ _ _ _ _";

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
                "7x..............................7x.";
                
            std::string umlBowl = 
                "grid: 2\n"
                "basefreq: 111.0\n"
                "instrument: bowl\n"
                "notation: Indian\n"
                "\n"
                "8Sa................ 8Sa................ 8Sa................ 8Sa................";
                
            std::string umlBell =  
                "grid: 2\n"
                "basefreq: 222.0\n"
                "instrument: bell\n"
                "notation: Indian\n"
                "\n"
                "6Sa.... 6r2.... 6Re.... 6g2.... 6Ga.... 6Ma.... 6M2.... 6Pa.... 6d2.... 6Dha.... 6n2.... 6Ni.... _...";

            group.sequences.push_back({"AmbientRain", new UMLSequence("AmbientRain", 19, umlRainmaker)});
            group.sequences.push_back({"AmbientBowl", new UMLSequence("AmbientBowl", 8, umlBowl)});
            group.sequences.push_back({"AmbientBell", new UMLSequence("AmbientBell", 7, umlBell)});

            group.volumes = { 0.9f, 0.7f, 0.3f };
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
                "5B2. 5F#3 6B3 6B2 5F#3 6B3. 6F#4... 5D4... "
                "5F#2. 5F#3 6A#3. 5C#4. 6A#3 5F#4....... "
                "6A2. 6E3 6A3. 5C#4. 5A3 5A4... 6C#4... "
                "6B2. 5E3 5G#3. 5B2 6E2 5B2 6E4....... "
                // Measure 5-8 (G, D, Em, F#)
                "6G3. 6B3 6G3. 5B3. 6G3 5C#4... 5D4... "
                "_ . 6A3 6D4. 5F#4.. 6F#4... 6D4... "
                "_ . 6B3 5G3. 5B3 6A3. 5B3... 5G3... "
                "6F#2. 6F#3 6A#3. 5C#4. 6A#3 6F#4....... "
                // Repeat Measure 1-4
                "5B2. 5F#3 6B3 6B2 5F#3 6B3. 6F#4... 5D4... "
                "5F#2. 5F#3 6A#3. 5C#4. 6A#3 5F#4....... "
                "6A2. 6E3 6A3. 5C#4. 5A3 5A4... 6C#4... "
                "6B2. 5E3 5G#3. 5B2 6E2 5B2 6E4....... "
                // Repeat Measure 5-8
                "6G3. 6B3 6G3. 5B3. 6G3 5C#4... 5D4... "
                "_ . 6A3 6D4. 5F#4.. 6F#4... 6D4... "
                "_ . 6B3 5G3. 5B3 6A3. 5B3... 5G3... "
                "6F#2. 6F#3 6A#3. 5C#4. 6A#3 6F#4.......";

            std::string umlBGuitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: bassguitar\n"
                "notation: Western\n"
                "\n"
                // Measures 1-4: Bm, F#, A, E (intro/verse 1)
                "B1............... F#1............... A1............... E1............... "
                // Measures 5-8: G, D, Em, F# (verse 2)
                "G1............... D2............... E1............... F#1............... "
                // Measures 9-12: Bm, F#, A, E (verse 3)
                "B1............... F#1............... A1............... E1............... "
                // Measures 13-16: G, D, Em, F# (verse 4)
                "G1............... D2............... E1............... F#1...............";

            // Tumba (Low Conga, e.g. 130 Hz): matches MIDI Low Conga pattern (1a, 2+, 3+)
            std::string umlCongaLow = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 130.0\n"
                "instrument: conga\n"
                "\n"
                // Measures 1-16: MIDI Low Conga pattern — hits on 1a, 2+, 3+
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _ "
                "_ _ _ to  _ _ to _  _ _ to _  _ _ _ _";

            // Segundo (Mid Conga, e.g. 175 Hz): matches MIDI Open Hi Conga pattern (1, 1+, 2, 3, 4, 4+)
            std::string umlCongaMid = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 175.0\n"
                "instrument: conga\n"
                "\n"
                // Measures 1-16: MIDI Open Hi Conga pattern — hits on 1, 1+, 2, 3, 4, 4+
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _ "
                "to _ to _  to _ _ _  to _ _ _  to _ to _";

            // Quinto (High Conga, e.g. 225 Hz): complementary slap accents on beats 2 and 4
            std::string umlCongaHigh = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 225.0\n"
                "instrument: conga\n"
                "\n"
                // Measures 1-16: complementary slap/mute pattern on beats 2 and 4
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _ "
                "_ _ _ _  sl _ mu _  _ _ _ _  sl _ mu _";

            std::string umlKick = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: kick\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-16: Active patterns (192 steps total)
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  "
                "8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _  8x. _ 8x. _";
                
            std::string umlSnare = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: snare\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-8: Active patterns (64 steps: 3 measures silence, 1 measure with snare at end)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ 8x. _  "
                // Repeat Measures 1-4 (Measures 9-12): Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Repeat Measures 5-8 (Measures 13-16): Active patterns (64 steps: 3 measures silence, 1 measure with snare at end)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ 8x. _";

            std::string umlShaker = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 3000.0\n"
                "instrument: shaker\n"
                "\n"
                // Measures 1-4: Silence (64 steps)
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                "_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ "
                // Measures 5-16: Active patterns (192 steps total)
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  "
                "8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _  8sh _ 8sh _";

            group.sequences.push_back({"AcousticGuitar", new UMLSequence("AcousticGuitar", 21, umlAGuitar)});
            group.sequences.push_back({"AcousticBass", new UMLSequence("AcousticBass", 23, umlBGuitar)});
            group.sequences.push_back({"CongaLow", new UMLSequence("CongaLow", 30, umlCongaLow)});
            group.sequences.push_back({"CongaMid", new UMLSequence("CongaMid", 30, umlCongaMid)});
            group.sequences.push_back({"CongaHigh", new UMLSequence("CongaHigh", 30, umlCongaHigh)});
            group.sequences.push_back({"AcousticKick", new UMLSequence("AcousticKick", 2, umlKick)});
            group.sequences.push_back({"AcousticSnare", new UMLSequence("AcousticSnare", 3, umlSnare)});
            group.sequences.push_back({"Shaker", new UMLSequence("Shaker", 33, umlShaker)});

            group.volumes = { 2.5f, 1.1f, 0.3f, 0.3f, 0.3f, 0.4f, 0.15f, 0.25f };
            duration = 64;

        } else if (selection == 6) {
            group.name = "Sitar — Raag Yaman + Tabla Jawab-Talab";
            
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
                "6Ni...6Re...6Ga...6Ma...6Dha...6Ni...6Re...6Sa... "
                "6Ni...6Dha...6Pa...6Ma...6Ga...6Re...6Sa...6Sa... "
                "_... _... _... _... "
                "6Ni...6Re...6Ga...6Ma... "
                "_... _... _... _... "
                "6Dha...6Ni...6Re...6Sa... "
                "_... _... _... _... "
                "6Ni..._...";
                
            std::string umlDayan = 
                "grid: 4\n"
                "instrument: dayan\n"
                "\n"
                "Na... Tin... Tun... tk... Na... Tin... Na... tk... "
                "Tun... Tin... Na... Tun... Na... tk... Tin... Tun... "
                "Na... Tin... Tun... tk... _... _... _... _... "
                "Tun... Tin... Na... Tun... _... _... _... _... "
                "Na... Tin... Tun... tk... _... _... _... _...";
                
            std::string umlBayan = 
                "grid: 4\n"
                "instrument: bayan\n"
                "\n"
                "Ghe... _... _... Ka... _... Ka... Ghe... _... "
                "Ghe... Ka... Ghe... Ke... Ghi... Ghe... Ka... Ghe... "
                "Ghe... _... _... Ka... _... _... _... _... "
                "Ghe... Ka... Ghe... Ke... _... _... _... _... "
                "Ghi... Ghe... Ka... Ghe... _... _... _... _...";

            group.sequences.push_back({"Tanpura", new UMLSequence("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Sitar", new UMLSequence("Sitar", 9, umlSitar)});
            group.sequences.push_back({"Dayan", new UMLSequence("Dayan", 0, umlDayan)});
            group.sequences.push_back({"Bayan", new UMLSequence("Bayan", 1, umlBayan)});
            
            group.volumes = { 0.4f, 0.6f, 0.5f, 0.7f };
            duration = 20;
        } else if (selection == 7) {
            group.name = "Indian Folk (Dholak Percussion)";
            
            std::string umlDholak = 
                "grid: 8\n"
                "bpm: 60\n"
                "basefreq: 110.0\n"
                "instrument: dholak\n"
                "\n"
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na "
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na "
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na "
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na";
                
            group.sequences.push_back({"Dholak", new UMLSequence("Dholak", 37, umlDholak)});
            group.volumes = { 0.8f };
            duration = 16;
        } else if (selection == 8) {
            group.name = "Punjabi Folk (Dhol Percussion)";
            
            std::string umlDhol = 
                "grid: 16\n"
                "bpm: 120\n"
                "basefreq: 110.0\n"
                "instrument: dhol\n"
                "\n"
                "Dha _ _ Na Na _ _ Na Na _ _ Dha Dha _ _ Na "
                "Dha _ _ Na Na _ _ Na Na _ _ Dha Dha _ _ Na "
                "Dha _ _ Na Na _ _ Tin Na _ _ Dha Dha _ _ Na "
                "Dha _ _ Na Na _ _ Tin Na _ _ Dha Dha _ _ Na";

            group.sequences.push_back({"Dhol", new UMLSequence("Dhol", 38, umlDhol)});
            group.volumes = { 0.8f };
            duration = 16;
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
