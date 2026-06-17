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
#include <sys/resource.h>
#include <sys/time.h>
#include <fstream>
#include "../src/SequenceOrchestrator.hpp"
#include "../src/FaustMixer.hpp"
#include "../src/UMLParser.hpp"
#include "../src/InstrumentMapper.hpp"

// Helper structure to group sequences for a style
struct SequenceGroup {
    std::string name;
    std::vector<std::pair<std::string, UMLSequence*>> sequences;
    float percussionTrackWeight = 0.7f;
    float melodyTrackWeight = 1.0f;
    float backgroundTrackWeight = 1.0f;
};

// Global stop flag for playback thread wait
static bool gStopPlayback = false;

static long readVmRSS() {
    std::ifstream f("/proc/self/status");
    std::string line;
    while (std::getline(f, line)) {
        if (line.find("VmRSS:") == 0) {
            return std::stol(line.substr(6));
        }
    }
    return 0;
}

void playSequenceGroup(FaustMixer& mixer, SequenceOrchestrator& orch, SequenceGroup& group, int durationSeconds) {
    std::cout << "\n=== Starting Sequence: " << group.name << " ===" << std::endl;
    
    // Perf measurement start
    struct rusage cpuStart, cpuEnd;
    struct timeval wallStart, wallEnd;
    long rssStart = readVmRSS();
    gettimeofday(&wallStart, nullptr);
    getrusage(RUSAGE_SELF, &cpuStart);
    
    // Create Demo Tracks
    int percussionTrack = mixer.addTrack(group.percussionTrackWeight);
    int melodyTrack = mixer.addTrack(group.melodyTrackWeight);
    int backgroundTrack = mixer.addTrack(group.backgroundTrackWeight);

    // 1. Register sequences and instruments
    for (size_t i = 0; i < group.sequences.size(); ++i) {
        auto& seqPair = group.sequences[i];
        double samplesPerGrid = (60.0 / seqPair.second->bpm) * InstrumentMapper::DEFAULT_SAMPLE_RATE / seqPair.second->grid;
        double cellCount = seqPair.second->totalDurationSamples / samplesPerGrid;
        std::cout << "[Native] Adding Sequence Object: " << seqPair.first 
                  << " (InstID: " << seqPair.second->instrumentID << ")" 
                  << " | BPM: " << seqPair.second->bpm 
                  << " | BaseFreq: " << seqPair.second->baseFreq << " Hz" 
                  << " | DurationSamples: " << seqPair.second->totalDurationSamples
                  << " | Cells: " << std::round(cellCount) << std::endl;

        orch.addSequence(seqPair.first, seqPair.second);

        std::cout << "[Diagnostic] Parsed NoteOn events for " << seqPair.first << ":" << std::endl;
        for (size_t eIdx = 0; eIdx < seqPair.second->events.size(); ++eIdx) {
            const auto& ev = seqPair.second->events[eIdx];
            if (ev.type == UMLEventType::NoteOn) {
                double durMs = ev.durationSamples * 1000.0 / InstrumentMapper::DEFAULT_SAMPLE_RATE;
                std::cout << "  Event " << eIdx << ": Note: " << ev.note 
                          << " | Freq: " << ev.frequency << " Hz" 
                          << " | Dur: " << durMs << "ms" 
                          << " | Amp: " << ev.amplitude;
                if (ev.strikeVal >= 0.0f) {
                    std::cout << " | Strike: " << ev.strikeVal;
                }
                std::cout << " | SampleOffset: " << ev.sampleOffset << std::endl;
            } else if (ev.type == UMLEventType::FreqGlide) {
                std::cout << "  Event " << eIdx << ": Glide -> Freq: " << ev.targetFrequency 
                          << " Hz | Vel: " << ev.targetVelocity 
                          << " | DurSamples: " << ev.durationSamples 
                          << " | SampleOffset: " << ev.sampleOffset << std::endl;
            } else if (ev.type == UMLEventType::VibratoOn) {
                std::cout << "  Event " << eIdx << ": VibratoOn at SampleOffset: " << ev.sampleOffset << std::endl;
            } else if (ev.type == UMLEventType::NoteOff) {
                std::cout << "  Event " << eIdx << ": NoteOff at SampleOffset: " << ev.sampleOffset << std::endl;
            }
        }
        
        int id = seqPair.second->instrumentID;
        int targetTrack = melodyTrack;
        // Background (ambient/drone)
        if (id == 11 || id == 19 || id == 27 || id == 34 || id == 41 || id == 42) {
            targetTrack = backgroundTrack;
        // Membrane percussion → percussion bus
        } else if (InstrumentMapper::isMembraneophone(id)) {
            targetTrack = percussionTrack;
        // Idiophones stay on melodyTrack (default)
        }
        
        mixer.addInstrumentToTrack(targetTrack, seqPair.second->getFaustInstrument());
    }

    // Enable looping feature
    orch.setLooping(true);

    // 2. Play
    for (auto& seqPair : group.sequences) {
        orch.play(seqPair.first);
    }

    // Play indefinitely until user presses a key
    orch.enableDiagnostics(true);
    if (durationSeconds < 0) {
        std::cout << "[Playback] Playing indefinitely until Ctrl+C..." << std::endl;
        while (!gStopPlayback) {
            usleep(100000);
        }
    } else {
        std::cout << "[Playback] Playing for " << durationSeconds << " seconds..." << std::endl;
        usleep(durationSeconds * 1000000);
    }

    // 3. Stop and Unload
    orch.stop();
    mixer.removeTrack(percussionTrack);
    mixer.removeTrack(melodyTrack);
    mixer.removeTrack(backgroundTrack);
    
    // Perf measurement end
    getrusage(RUSAGE_SELF, &cpuEnd);
    gettimeofday(&wallEnd, nullptr);
    long rssEnd = readVmRSS();

    double wallSec = (wallEnd.tv_sec - wallStart.tv_sec)
                   + (wallEnd.tv_usec - wallStart.tv_usec) / 1000000.0;
    double cpuSec = (cpuEnd.ru_utime.tv_sec - cpuStart.ru_utime.tv_sec)
                  + (cpuEnd.ru_utime.tv_usec - cpuStart.ru_utime.tv_usec) / 1000000.0
                  + (cpuEnd.ru_stime.tv_sec - cpuStart.ru_stime.tv_sec)
                  + (cpuEnd.ru_stime.tv_usec - cpuStart.ru_stime.tv_usec) / 1000000.0;
    int cpuPct = (int)(cpuSec / wallSec * 100.0);

    std::cout << "[PERF] wall=" << (int)wallSec << "s"
              << " cpu=" << cpuPct << "%"
              << " rss=" << (rssEnd / 1024) << "MB"
              << " rss_delta=" << ((rssEnd - rssStart) / 1024) << "MB"
              << " seqs=" << group.sequences.size()
              << std::endl;

    orch.dumpInstrumentDiagnostics();
    orch.enableDiagnostics(false);
    
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
    int timeoutSec = -1;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (arg == "-t" && i + 1 < argc) {
            timeoutSec = std::stoi(argv[++i]);
        } else if (arg == "-s" && i + 1 < argc) {
            selection = std::stoi(argv[++i]);
        } else if (selection == -1) {
            try { selection = std::stoi(arg); } catch (...) {}
        }
    }

    while (true) {
        if (selection == -1) {
            std::cout << "\nSelect a sequence to play:" << std::endl;
            std::cout << "  1. Indian Classical — Darbari Kanada (Sarod, Tanpura, Tabla) [12 semitone]" << std::endl;
            std::cout << "  2. Jazz Ensemble (Piano, Sax, Bass, Drums)" << std::endl;
            std::cout << "  3. Rock Band (Electric Guitar, Bass, Drums)" << std::endl;
            std::cout << "  4. Tibetan Bowl with Rain + LagNga (Bowl, Rainmaker, LagNga)" << std::endl;
            std::cout << "  5. Acoustic Hotel California (Acoustic Guitar, 3 Congas, Bass, Drums)" << std::endl;
            std::cout << "  6. Sitar — Raag Yaman + Tabla" << std::endl;
            std::cout << "  7. North Indian Folk (Dholak Percussion)" << std::endl;
            std::cout << "  8. Punjabi Folk (Bhangra beats)" << std::endl;
            std::cout << "  9. Exit" << std::endl;
            std::cout << " 10. Sarod — Raag Yaman (Fast, with Meend Glides) [12 semitone]" << std::endl;
            std::cout << " 11. Carnatic Classical — Raag Hamsadhwani (Violin, Mridangam, Ghatam)" << std::endl;
            std::cout << " 12. Last of the Mohicans — Promontory & Elk Hunt (Panflute, NAF, Rainmaker, Dhol)" << std::endl;
            std::cout << ">>> Enter selection (1-12): ";
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
            group.name = "Indian Classical — Raag Darbari Kanada (Sarod, Tanpura, Tabla) [12 semitone]";
            
            std::string umlTanpura = 
                "grid: 4\n"
                "bpm: 70\n"
                "basefreq: 222.0\n"
                "instrument: tanpura\n"
                "notation: Hindustani\n"
                "loop: true\n"
                "\n"
                "5Sa............... _............... "
                "5Sa............... _...............";
            
            // Raag Darbari Kanada — late-night, majestic, deep
            // Arohana: Sa Re ga ma Pa dha ni Sa*
            // Vadi: Re, Samvadi: Pa
            // Structure: Alaap (slow, meend, rests) → Jod (medium) → Jhala (fast chikari)
            std::string umlSarod = 
                "grid: 4\n"
                "bpm: 70\n"
                "basefreq: 222.0\n"
                "instrument: sarod\n"
                "notation: Hindustani\n"
                "glide: 0.03\n"
                "vibrato_depth: 0.02\n"
                "vibrato_rate: 5.5\n"
                // --- Alaap (64 cells) — slow, spacious, meend between notes, rests separate phrases ---
                "5Sa.. _ _ _ _ _ \n"                      // Sa rings 3 cells, 5 cells rest
                "5Sa.^ 8re.. _ _ _ \n"                    // Sa→meend, re rings, 3 cells rest
                "8re.^ 8ga.. _ _ _ \n"                    // re→meend, ga rings, 3 cells rest
                "8ga.. _ _ _ _ _ \n"                      // ga rings 3 cells (andolan), 5 rest
                "3Ma _ 8ga.^ 8re _ _ _ \n"                // Ma, rest, ga→re meend, re, rest
                "8re.^ 5Sa.. _ _ _ \n"                    // re→Sa meend, Sa rings, 3 rest
                "8ni _ 6dha _ _ _ _ _ \n"                 // ni, rest, dha, 5 cells rest
                "6dha.^ 5Sa.. _ _ _ \n"                   // dha→Sa meend, Sa rings, 3 rest
                // --- Jod (128 cells) — medium pulse, rhythmic Darbari patterns ---
                "8re . 8ga . 8re . 5Sa . \n"
                "8re . 8ga . 3Ma . 6Pa . \n"
                "6dha . 8ni . 6dha . 6Pa . \n"
                "3Ma . 8ga . 8re . 5Sa . \n"
                "8ni . 6dha . 6Pa . 3Ma . \n"
                "8ga . 3Ma . 6dha . 8ni . \n"
                "8re . 8ga . 8re . 5Sa . \n"
                "6Pa . 3Ma . 8ga . 8re . \n"
                "8re . 8ga . 6dha . 8ni . \n"
                "6dha . 6Pa . 3Ma . 8ga . \n"
                "8re . 8ga . 8re . 5Sa . \n"
                "8ni . 6dha . 6Pa . 3Ma . \n"
                "8ga . 3Ma . 6Pa . 3Ma . \n"
                "8ga . 8re . 5Sa . 8re . \n"
                "8ga . 3Ma . 6dha . 6Pa . \n"
                "8re . 8ga . 8re . 5Sa . \n"
                // --- Jhala (144 cells) — fast chikari patterns ---
                "61Sa 8ga~ 61Sa 8ga~ 61Sa 8re~ 61Sa 8ga~ \n"
                "61Sa 8ni~ 61Sa 8dha~ 61Sa 6Pa~ 61Sa 3Ma~ \n"
                "61Sa 8ga~ 61Sa 8re~ 61Sa 5Sa~ 61Sa 8ga~ \n"
                "81re 8ga~ 81re 8ga~ 81ni 8dha~ 81ni 6Pa~ \n"
                "81re 8ga~ 81re 5Sa~ 81re 8ga~ 81re 3Ma~ \n"
                "81ga 8re~ 81ga 8re~ 81ga 5Sa~ 81ga 8re~ \n"
                "61Sa 8ga~ 61Sa 8ni~ 61Sa 8dha~ 61Sa 6Pa~ \n"
                "81re 8ga~ 81ni 8dha~ 81re 8ga~ 81ni 6Pa~ \n"
                "61Sa 8ga~ 61Sa 8re~ 61Sa 8ga~ 61Sa 5Sa~ \n"
                "81ni 8dha~ 81ni 6Pa~ 81ni 3Ma~ 81ni 8ga~ \n"
                "81re 8ga~ 81re 8ni~ 81re 8dha~ 81re 6Pa~ \n"
                "61Sa 8ga~ 61Sa 5Sa~ 61Sa 8ga~ 61Sa 5Sa~ \n"
                "81re 8ga~ 81re 8ni~ 81ni 8dha~ 81ni 6Pa~ \n"
                "61Sa 8ga~ 61Sa 8re~ 61Sa 8ga~ 61Sa 8re~ \n"
                "81ga 8re~ 81ga 5Sa~ 81ga 8re~ 81ga 5Sa~ \n"
                "61Sa 8ga~ 61Sa 8re~ 61Sa 8ga~ 61Sa 8re~ \n"
                "61Sa 8ga~ 61Sa 8re~ 61Sa 5Sa~ 61Sa 5Sa~ \n"
                "5Sa . . . . . . . \n";
            
            // Total sarod cells: 64 + 128 + 144 = 336
            // All instruments at BPM=70, same grid=4, same total cells
            
            auto buildDayan = [bpm = 70]() -> std::string {
                std::string s = "grid: 4\nbpm: ";
                s += std::to_string(bpm) + "\nbasefreq: 222.0\ninstrument: dayan\n\n";
                std::string alaap = "Na... Tin... Tun... tk... Na... Tin... Na... tk... "; // 32 cells
                std::string med   = "Na. Tin. Tun. tk. Na. Tin. Na. tk. "; // 16 cells
                std::string jhala = "Na Tin Tun tk Na Tin Na tk "; // 8 cells
                for (int i = 0; i < 2;  i++) s += alaap;  // 2×32 = 64 ✓
                for (int i = 0; i < 8;  i++) s += med;    // 8×16 = 128 ✓
                for (int i = 0; i < 18; i++) s += jhala;  // 18×8 = 144 ✓
                return s;
            };
            
            auto buildBayan = [bpm = 70]() -> std::string {
                std::string s = "grid: 4\nbpm: ";
                s += std::to_string(bpm) + "\nbasefreq: 111.0\ninstrument: bayan\n\n";
                std::string alaap = "Ghe... _... _... Ka... _... Ka... Ghe... _... "; // 32 cells
                std::string med   = "Ghe. _. _. Ka. _. Ka. Ghe. _. "; // 16 cells
                std::string jhala = "Ghe _ _ Ka _ Ka Ghe _ "; // 8 cells
                for (int i = 0; i < 2;  i++) s += alaap;  // 2×32 = 64 ✓
                for (int i = 0; i < 8;  i++) s += med;    // 8×16 = 128 ✓
                for (int i = 0; i < 18; i++) s += jhala;  // 18×8 = 144 ✓
                return s;
            };
            
            std::string umlDayan = buildDayan();
            std::string umlBayan = buildBayan();

            group.sequences.push_back({"Tanpura", new UMLSequence("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Sarod", new UMLSequence("Sarod", 44, umlSarod)});
            group.sequences.push_back({"Dayan", new UMLSequence("Dayan", 0, umlDayan)});
            group.sequences.push_back({"Bayan", new UMLSequence("Bayan", 1, umlBayan)});
            
            group.percussionTrackWeight = 1.3f;
            group.backgroundTrackWeight = 0.3f;
            group.melodyTrackWeight = 1.0f;
            duration = 30;
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
            
            duration = 20;

        } else if (selection == 3) {
            group.name = "Rock Band (Hotel California)";

            std::string umlEGuitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: electricguitar\n"
                "notation: Western\n"
                "drive: 0.75\n"
                "sustain: 0.8\n"
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

            duration = 24;

        } else if (selection == 4) {
            duration = -1;
            group.name = "Tibetan Bowl with Rain + LagNga";

            std::string umlRainmaker = 
                "grid: 1\n"
                "instrument: rainmaker\n"
                "loop: true\n"
                "\n"
                "9x..............................9x.";
                
            std::string umlBowl = 
                "grid: 1\n"
                "bpm: 60\n"
                "basefreq: 111.0\n"
                "instrument: bowl\n"
                "loop: true\n"
                "\n"
                "80X...................";
                
            std::string umlLagngaHigh =  
                "grid: 2\n"
                "bpm: 60\n"
                "basefreq: 222.0\n"
                "instrument: lagnga\n"
                "mallet_softness: 0.6\n"
                "loop: true\n"
                "\n"
                "7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. ";

            std::string umlLagngaLow =  
                "grid: 2\n"
                "bpm: 60\n"
                "basefreq: 111.0\n"
                "instrument: lagnga\n"
                "mallet_softness: 0.6\n"
                "loop: true\n"
                "\n"
                "_. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. ";

            std::string umlBowl222 =
                "grid: 1\n"
                "bpm: 60\n"
                "basefreq: 222.0\n"
                "instrument: bowl\n"
                "loop: true\n"
                "\n"
                "....80X................";

            std::string umlBowl444 =
                "grid: 1\n"
                "bpm: 60\n"
                "basefreq: 444.0\n"
                "instrument: bowl\n"
                "loop: true\n"
                "\n"
                "........80X............";

            group.percussionTrackWeight = 1.3f;
            group.backgroundTrackWeight = 1.5f;
            group.melodyTrackWeight = 3.0f;

            group.sequences.push_back({"AmbientRain", new UMLSequence("AmbientRain", 19, umlRainmaker)});
            group.sequences.push_back({"AmbientBowl", new UMLSequence("AmbientBowl", 8, umlBowl)});
            group.sequences.push_back({"LagNgaHigh", new UMLSequence("LagNgaHigh", 36, umlLagngaHigh)});
            group.sequences.push_back({"LagNgaLow", new UMLSequence("LagNgaLow", 36, umlLagngaLow)});
            group.sequences.push_back({"Bowl222", new UMLSequence("Bowl222", 8, umlBowl222)});
            group.sequences.push_back({"Bowl444", new UMLSequence("Bowl444", 8, umlBowl444)});

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

            duration = 64;

        } else if (selection == 6) {
            group.name = "Sitar — Raag Yaman + Tabla Jawab-Talab";
            
            std::string umlTanpura = 
                "grid: 2\n"
                "basefreq: 111.0\n"
                "instrument: tanpura\n"
                "notation: Hindustani\n"
                "loop: true\n\n"
                "5Pa...... 5Sa...... "; // Short sequence that loops independently
                
            std::string umlSitar = 
                "grid: 4\n"
                "basefreq: 222.0\n"
                "instrument: sitar\n"
                "notation: Hindustani\n\n";
            // Alap (256 cells of slow, meditative phrases)
            umlSitar += "6Ni...^ 6Re...^ 6Ga... _... 6ma...^ 6Pa...^ 6Dha... _... ";
            umlSitar += "6Ni...^ 6Sa*2... _... _... 6Sa*2...^ 6Ni...^ 6Dha...^ 6Pa... ";
            umlSitar += "6ma...^ 6Ga...^ 6Re...^ 6Sa... 6Ni/2...^ 6Re...^ 6Ga...^ 6Sa... ";
            umlSitar += "6ma...^ 6Ga...^ 6Re...^ 6Sa... _... _... _... _... ";
            umlSitar += "6Ni...^ 6Re...^ 6Ga... _... 6ma...^ 6Pa...^ 6Dha... _... ";
            umlSitar += "6Ni...^ 6Sa*2... _... _... 6Sa*2...^ 6Ni...^ 6Dha...^ 6Pa... ";
            umlSitar += "6ma...^ 6Ga...^ 6Re...^ 6Sa... 6Ni/2...^ 6Re...^ 6Ga...^ 6Sa... ";
            umlSitar += "6ma...^ 6Ga...^ 6Re...^ 6Sa... _... _... _... _... ";
            // Jod (128 cells of medium-paced rhythmic movement)
            for (int i = 0; i < 2; ++i) {
                umlSitar += "6Ni/2 . 6Re . 6Ga . 6ma . 6Pa . 6ma . 6Ga . 6Re . ";
                umlSitar += "6Ga . 6ma . 6Dha . 6Ni . 6Sa*2 . 6Ni . 6Dha . 6Pa . ";
                umlSitar += "6ma . 6Dha . 6Ni . 6Sa*2 . 6Re*2 . 6Sa*2 . 6Ni . 6Dha . ";
                umlSitar += "6Pa . 6ma . 6Ga . 6Re . 6Sa . . . _ . . . ";
            }
            // Jhala (256 cells: 128 cells of rapid triads + 128 cells of Tihai and trailing rests)
            for (int i = 0; i < 2; ++i) {
                umlSitar += "6Ga 6Sa*2 6Re 6Sa*2 6Ga 6Sa*2 6ma 6Sa*2 6Pa 6Sa*2 6ma 6Sa*2 6Ga 6Sa*2 6Re 6Sa*2 ";
                umlSitar += "6ma 6Sa*2 6Pa 6Sa*2 6Dha 6Sa*2 6Ni 6Sa*2 6Sa*2 6Sa*2 6Ni 6Sa*2 6Dha 6Sa*2 6Pa 6Sa*2 ";
                umlSitar += "6Ni 6Sa*2 6Sa*2 6Sa*2 6Re*2 6Sa*2 6Sa*2 6Sa*2 6Ga*2 6Sa*2 6Re*2 6Sa*2 6Sa*2 6Sa*2 6Ni 6Sa*2 ";
                umlSitar += "6Sa*2 6Sa*2 6Ni 6Sa*2 6Dha 6Sa*2 6Pa 6Sa*2 6ma 6Sa*2 6Ga 6Sa*2 6Re 6Sa*2 6Sa 6Sa*2 ";
            }
            // Tihai
            umlSitar += "6Pa 6Sa*2 6Dha 6Sa*2 6Sa*2 . . . 6Pa 6Sa*2 6Dha 6Sa*2 6Sa*2 . . . ";
            umlSitar += "6Pa 6Sa*2 6Dha 6Sa*2 6Sa*2 . . . _ . . . _ . . . ";
            for (int i = 0; i < 6; ++i) {
                umlSitar += "_ . . . _ . . . _ . . . _ . . . ";
            }
                
            std::string umlDayan = 
                "grid: 4\n"
                "basefreq: 222.0\n"
                "instrument: dayan\n\n";
            // Alap: Silent (256 cells)
            for (int i = 0; i < 32; ++i) {
                umlDayan += "_ . . . _ . . . ";
            }
            // Jod: Vilambit Teental (128 cells)
            for (int i = 0; i < 8; ++i) {
                umlDayan += "Na . . . Tin . . . Tun . . . tk . . . ";
            }
            // Jhala: Drut Teental (256 cells)
            for (int i = 0; i < 32; ++i) {
                umlDayan += "Na tk Tin tk Tun tk Na tk ";
            }
                
            std::string umlBayan = 
                "grid: 4\n"
                "basefreq: 111.0\n"
                "instrument: bayan\n\n";
            // Alap: Silent (256 cells)
            for (int i = 0; i < 32; ++i) {
                umlBayan += "_ . . . _ . . . ";
            }
            // Jod: Vilambit Teental (128 cells)
            for (int i = 0; i < 8; ++i) {
                umlBayan += "Ghe . . . Ka . . . Ghe . . . Ka . . . ";
            }
            // Jhala: Drut Teental (256 cells)
            for (int i = 0; i < 32; ++i) {
                umlBayan += "Ghe Ghe Ka Ka Ghe Ghe Ka Ka ";
            }
            
            group.sequences.push_back({"Tanpura", new UMLSequence("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Sitar", new UMLSequence("Sitar", 9, umlSitar)});
            group.sequences.push_back({"Dayan", new UMLSequence("Dayan", 0, umlDayan)});
            group.sequences.push_back({"Bayan", new UMLSequence("Bayan", 1, umlBayan)});
            
            group.backgroundTrackWeight = 0.15f;
            duration = 60;
        } else if (selection == 7) {
            group.name = "Indian Folk (Dholak Percussion)";
            
            std::string umlDholak = 
                "grid: 4\n"
                "bpm: 120\n"
                "basefreq: 110.0\n"
                "instrument: dholak\n"
                "freq_right: 165.0\n"
                "\n"
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na _ "
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na _ "
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na _ "
                "Dha _ Ge _ Na _ Ti _ Na _ Ke _ Dhin _ Na _ "
                "Dha _ Na Ti Dha _ Na Ti Na _ Ke Dhin Na _ Ti _ "
                "Dha _ Na Ti Dha _ Na Ti Na _ Ke Dhin Na _ Ti _ "
                "Dha _ Na Ti Dha _ Na Ti Na _ Ke Dhin Na _ Ti _ "
                "Dha _ Na Ti Dha _ Na Ti Na _ Ke Dhin Na _ Ti _ "
                "Dha Na Ge Na Dha Na Ti _ Na Ti Ke Ti Na Ti Dha _ "
                "Dha Na Ge Na Dha Na Ti _ Na Ti Ke Ti Na Ti Dha _ "
                "Dha Na Ge Na Dha Na Ti _ Na Ti Ke Ti Na Ti Dha _ "
                "Dha Na Ge Na Dha Na Ti _ Na Ti Ke Ti Na Ti Dha _";
                
            group.sequences.push_back({"Dholak", new UMLSequence("Dholak", 37, umlDholak)});
            duration = 48;
        } else if (selection == 8) {
            group.name = "Punjabi Folk (Dhol Percussion)";
            
            std::string umlDhol = 
                "grid: 4\n"
                "bpm: 120\n"
                "basefreq: 110.0\n"
                "instrument: dhol\n"
                "freq_right: 165.0\n"
                "\n"
                "Dha _ _ _ _ _ Na _ Na _ _ _ _ _ Na _ "
                "Na _ _ _ _ _ Dha _ Dha _ _ _ _ _ Na _ "
                "Dha _ _ _ _ _ Na _ Na _ _ _ _ _ Na _ "
                "Na _ _ _ _ _ Dha _ Dha _ _ _ _ _ Na _ "
                "Dha _ _ Na Na _ _ Na Na _ _ Dha Dha _ _ Na "
                "Dha _ _ Na Na _ _ Na Na _ _ Dha Dha _ _ Na "
                "Dha _ _ Na Na _ _ Tin Na _ _ Dha Dha _ _ Na "
                "Dha _ _ Na Na _ _ Tin Na _ _ Dha Dha _ _ Na "
                "Dha _ _ Na Dha Dha _ Na Dha _ _ Na Dha Dha _ Na "
                "Dha _ _ Na Dha Dha _ Na Dha _ _ Na Dha Dha _ Na "
                "Dha _ _ Na Dha Dha _ Tin Dha _ _ Na Dha Dha _ Tin "
                "Dha _ _ Na Dha Dha _ Tin Dha _ _ Na Dha Dha _ Tin";

            group.sequences.push_back({"Dhol", new UMLSequence("Dhol", 38, umlDhol)});
            duration = 48;
        } else if (selection == 10) {
            group.name = "Sarod — Raag Yaman (Fast, with Meend Glides)";
            
            std::string umlTanpura = 
                "grid: 4\n"
                "bpm: 80\n"
                "basefreq: 222.0\n"
                "instrument: tanpura\n"
                "notation: Hindustani\n"
                "loop: true\n"
                "\n"
                "5Sa............... _............... "
                "5Sa............... _...............";
            
            // Faster Sarod in Raag Yaman (Ni Re Ga Ma Dha Ni Sa)
            // Structure: Alaap (with glides), Jod, Jhala
            std::string umlSarod = 
                "grid: 4\n"
                "bpm: 80\n"
                "basefreq: 222.0\n"
                "instrument: sarod\n"
                "notation: Hindustani\n"
                "glide: 0.06\n"
                "vibrato_depth: 0.02\n"
                "vibrato_rate: 5.5\n"
                "chikari_freq: 222.0\n"
                // Alaap — slow with long meend glides (^)
                "5Sa..^ 5Sa..^ 8Ni..^ 5Sa..^ \n"
                "8Ni..^ 8Ga..^ 8Re..^ 8Ni..~ \n"
                "8Ga..^ 6Dha..^ 8Ni..^ 6Dha..~ \n"
                "8Re..^ 8Ga..^ 8Re..^ 6Dha..^ \n"
                "9Ni..^ 6Sa*2..^ 9Ni..~ 6Dha..~ \n"
                "8Re..^ 9Ni..^ 6Sa*2..^ 8Ga..^ \n"
                "9Ni..^ 8Re..^ 6Dha..^ 8Ni..^ \n"
                "5Sa..^ 8Re..^ 8Ga..^ 8Re..~ \n"
                // Jod — medium pulse
                "8Ga. 8Re. 5Sa. 8Ni. 9Ni. 5Sa. 8Re. 8Ga. \n"
                "8Re. 8Ga. 6Dha. 8Ni. 6Dha. 8Ni. 8Re. 8Ga. \n"
                "8Ni. 5Sa. 8Re. 8Ga. 9Ni. 6Sa*2. 9Ni. 5Sa. \n"
                "8Ga. 8Re. 6Dha. 8Ni. 8Re. 8Ga. 8Re. 5Sa. \n"
                "6Dha. 8Ni. 8Re. 8Ga. 8Re. 6Dha. 8Ni. 5Sa. \n"
                "8Ni. 5Sa. 8Re. 8Ga. 6Dha. 8Ni. 8Re. 8Ga. \n"
                "9Ni. 6Sa*2. 9Ni. 8Re. 8Ga. 8Re. 5Sa. 8Ni. \n"
                "5Sa. 8Re. 8Ga. 8Re. 6Dha. 8Ni. 5Sa. 8Ga. \n"
                // Jhala — fast with chikari (strike=1 prefix)
                "61Sa 8Ga~ 61Sa 8Ga~ 81Ni 8Ga~ 61Sa 8Ga~ \n"
                "81Re 8Ga~ 81Re 8Ga~ 81Ga 8Re~ 81Ga 8Re~ \n"
                "81Ga 8Ni~ 81Ga 8Ni~ 81Ni 8Re~ 81Ni 8Re~ \n"
                "61Sa 8Ga~ 61Sa 8Ga~ 81Dha 8Ga~ 81Dha 8Re~ \n"
                "81Re 8Ga~ 81Re 8Ga~ 81Ni 8Re~ 81Ni 8Ga~ \n"
                "61Sa 8Ga~ 61Sa 8Ga~ 81Ga 8Re~ 81Ga 8Re~ \n"
                "81Ni 8Dha~ 81Ni 8Dha~ 81Re 8Ga~ 81Re 8Ga~ \n"
                "81Ga 8Ni~ 81Ga 8Ni~ 81Re 8Ga~ 81Re 8Ga~ \n"
                "61Sa 8Ga~ 61Sa 8Ga~ 61Sa 8Ga~ 61Sa 8Ga~ \n"
                "5Sa . . . . . . . \n";
            
            auto buildDayan = [bpm = 80]() -> std::string {
                std::string s = "grid: 4\nbpm: ";
                s += std::to_string(bpm) + "\nbasefreq: 222.0\ninstrument: dayan\n\n";
                std::string alaap = "Na... Tin... Tun... tk... Na... Tin... Na... tk... ";
                std::string med   = "Na. Tin. Tun. tk. Na. Tin. Na. tk. ";
                std::string jhala = "Na Tin Tun tk Na Tin Na tk ";
                for (int i = 0; i < 2; i++) s += alaap;
                for (int i = 0; i < 4; i++) s += med;
                for (int i = 0; i < 4; i++) s += med;
                for (int i = 0; i < 18; i++) s += jhala;
                return s;
            };
            
            auto buildBayan = [bpm = 80]() -> std::string {
                std::string s = "grid: 4\nbpm: ";
                s += std::to_string(bpm) + "\nbasefreq: 111.0\ninstrument: bayan\n\n";
                std::string alaap = "Ghe... _... _... Ka... _... Ka... Ghe... _... ";
                std::string med   = "Ghe. _. _. Ka. _. Ka. Ghe. _. ";
                std::string jhala = "Ghe _ _ Ka _ Ka Ghe _ ";
                for (int i = 0; i < 2; i++) s += alaap;
                for (int i = 0; i < 4; i++) s += med;
                for (int i = 0; i < 4; i++) s += med;
                for (int i = 0; i < 18; i++) s += jhala;
                return s;
            };
            
            group.sequences.push_back({"Tanpura", new UMLSequence("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Sarod", new UMLSequence("Sarod", 44, umlSarod)});
            group.sequences.push_back({"Dayan", new UMLSequence("Dayan", 0, buildDayan())});
            group.sequences.push_back({"Bayan", new UMLSequence("Bayan", 1, buildBayan())});
            
            group.percussionTrackWeight = 1.3f;
            group.backgroundTrackWeight = 0.3f;
            group.melodyTrackWeight = 1.0f;
            duration = 48;
        } else if (selection == 11) {
            group.name = "Carnatic Classical — Raag Hamsadhwani";

            std::string umlViolin =
                "grid: 4\n"
                "bpm: 100\n"
                "basefreq: 444.0\n"
                "instrument: violin\n"
                "notation: Indian\n"
                "\n"
                "// Alaap (Slow, expressive Flautando glides - Strike 0)\n"
                "30Sa.. 50R2.. 70G2.. 50Pa.. \n"
                "60N2.. 80Sa*2.. 60N2.. 40Pa.. \n"
                "50G2.. 40R2.. 30Sa.. _... \n"
                "40Pa.. 60D2.. 70N2.. 80Sa*2.. \n"
                "60R2*2.. 50Sa*2.. 40N2.. 30D2.. \n"
                "40Pa.. 30M2.. 30G2.. _... \n"
                "// Jod (Medium pulse Standard bowing - Strike 1)\n"
                "41Sa. 51R2. 61G2. 71Pa. 81N2. 71Sa*2. 61N2. 51Pa. \n"
                "41G2. 31R2. 21Sa. _......... \n"
                "41Pa. 51D2. 61N2. 71Sa*2. 81R2*2. 71Sa*2. 61N2. 51D2. \n"
                "41Pa. 31M2. 21G2. _......... \n"
                "// Jhala / Drut (Fast Crunch bowing - Strike 2)\n"
                "52Sa 72G2 52Sa 72G2 52R2 72Pa 52R2 72Pa \n"
                "72G2 72N2 72G2 72N2 52Pa 52Sa*2 52Pa 52Sa*2 \n"
                "52Sa*2 72N2 52Sa*2 72N2 52Pa 72G2 52Pa 72G2 \n"
                "52R2 52Sa 52R2 52Sa _... _... \n"
                "52Pa 72N2 52Pa 72N2 52D2 72Sa*2 52D2 72Sa*2 \n"
                "72N2 72R2*2 72N2 72R2*2 52Sa*2 52G2*2 52Sa*2 52G2*2 \n"
                "52G2*2 72R2*2 52G2*2 72R2*2 52Sa*2 72N2 52Sa*2 72N2 \n"
                "52D2 52Pa 52D2 52Pa _... _... \n";



            std::string umlGhatam =
                "grid: 4\n"
                "bpm: 100\n"
                "basefreq: 222.0\n"
                "instrument: ghatam\n"
                "notation: konnakol\n"
                "\n"
                "// Alaap - 48 units\n"
                "5Nam... 3Dhi... 8Gumki... 6Tha... \n"
                "4Nam... 3Dhi... 7Nam... 6Tha... \n"
                "5Nam... 3Dhi... 8Gumki... 6Tha... \n"
                "// Jod - 32 units\n"
                "5Nam. 3Dhi. 8Gumki. 6Tha. 4Nam. 3Dhi. 7Nam. 6Tha. \n"
                "5Nam. 3Dhi. 8Gumki. 6Tha. 4Nam. 3Dhi. 7Nam. 6Tha. \n"
                "// Jhala / Drut - 64 units\n"
                "9Tha 4Dhi 8Thom 6Nam 9Gumki 5Nam 4Dhi 8Tha 9Tha 4Dhi 8Thom 6Nam 9Gumki 5Nam 4Dhi 8Tha \n"
                "9Tha 7Tha 5Dhi 4Dhi 8Thom 6Thom 9Nam 7Nam 9Gumki 7Gumki 6Nam 5Nam 4Dhi 3Dhi 8Tha 6Tha \n"
                "9Tha 4Dhi 8Thom 6Nam 9Gumki 5Nam 4Dhi 8Tha 9Tha 4Dhi 8Thom 6Nam 9Gumki 5Nam 4Dhi 8Tha \n"
                "9Tha 7Tha 5Dhi 4Dhi 8Thom 6Thom 9Nam 7Nam 9Gumki 7Gumki 6Nam 5Nam _... _... \n";

            group.sequences.push_back({"Violin", new UMLSequence("Violin", 18, umlViolin)});
            group.sequences.push_back({"Ghatam", new UMLSequence("Ghatam", 50, umlGhatam)});

            group.percussionTrackWeight = 1.2f;
            group.melodyTrackWeight = 1.0f;
            duration = 32;
        } else if (selection == 12) {
            group.name = "Last of the Mohicans";
            
            auto buildPanflute = []() -> std::string {
                std::string s = "grid: 4\nbpm: 72\nbasefreq: 293.66\ninstrument: panflute\nvibrato: 0.6\nvibrato_rate: 5.5\nvibrato_depth: 0.04\n\n";
                // "The Last of the Mohicans — Promontory" theme, panflute arrangement
                // Section A — Main theme (8 bars)
                s += "5D5... 5D5... 5E5... 5F5... \n";
                s += "5G5... 5G5... 5F5... 5E5... \n";
                s += "5D5... 5C5... 5D5... 5F5... \n";
                s += "5E5..~. 5D5........... \n";
                s += "5D5... 5D5... 5E5... 5F5... \n";
                s += "5G5... 5G5... 5F5... 5E5... \n";
                s += "5D5... 5C5... 5D5... 5A4... \n";
                s += "5D5............... \n";
                // Section B — Secondary theme (8 bars)
                s += "5A4... 5D5... 5F5... 5E5... \n";
                s += "5D5... 5C5... 5D5... 5A4... \n";
                s += "5D5... 5F5... 5G5... 5A5... \n";
                s += "5G5..~. 5F5... 5E5... 5D5... \n";
                s += "5C5... 5D5... 5F5... 5E5... \n";
                s += "5D5... 5C5... 5D5... 5A4... \n";
                s += "5D5... 5F5... 5G5... 5A5... \n";
                s += "5G5... 5F5..~. 5E5... 5D5... \n";
                // Section C — Return to theme + coda (4 bars)
                s += "5D5... 5D5... 5E5... 5F5... \n";
                s += "5G5... 5G5..~. 5F5... 5E5... \n";
                s += "5D5... 5C5... 5D5... 5A4... \n";
                s += "5D5............... \n";
                return s;
            };
            auto buildNAF = []() -> std::string {
                std::string s = "grid: 12\nbpm: 60\nbasefreq: 222.0\ninstrument: nativeamericanflute\nvibrato: 0.5\nvibrato_rate: 5.0\nvibrato_depth: 0.005\n\n";
                // Promentory main theme (guitar tab transcription)
                // Phrase 1: opening statement
                s += "5F4.~.............5E4...5D4...5Ab3....~............5D4...5F4...5E4...5F4.. 7G4....~............... \n";                
                s += "5F4.~.............5E4...5D4...5Ab3....~............5D4...5F4...5E4...5F4.. 7G4....~............... \n";  

                // Phrase 2: descending variation
                s += "5F4....5A4..~..........5G4.....5F4.~........5E4.....5G4.~........... 3F4......4E4...4E4...4E4 ....5F4......... 3D4..~................... \n";
                s += "5F4....5A4..~.........5G4.....5F4.~........5E4.....5G4.~........... 3F4......4E4...4E4...4E4.....5F4.......... 3D4..~.................. \n";
                // "The Kiss" melody — saved for later
                // s += "5A3 5F4 5G4 5A4  5C4 5D4 5A4 5G4 5F4 5A3 \n"; 
                // s += "5A3.5F4.5G4.5A4.  5C4. 5A4. 5G4. 5F4.5A3. \n";
                // s += "5A3..5F4..5G4..5A4..  5C4.. 5A4.. 5G4.. 5F4..5A3.. \n";
                // s += "5A3...5F4...5G4...5A4...  5C4... 5A4... 5G4... 5F4...5A3... \n";
                 return s;
             };
             auto buildVoice = []() -> std::string {
                  std::string s = "grid: 12\nbpm: 60\nbasefreq: 110\ninstrument: voice\nvibrato_rate: 5.5\nvibrato_depth: 0.04\nbreathiness: 0.2\nvowel: 0\n";
                  s += "delay: 30\n\n";
                 // Same opening melody as NAF, delayed to start after NAF finishes
                  s += "5F3.~..........^..5E3..^.5D3..^.5Ab2....~..........^..5D3..^.5F3..^.5E3..^.5F3.. 7G3....~.......>......._ \n";
                  s += "5F3.~.............5E3...5D3...5Ab2....~............5D3...5F3...5E3...5F3.. 7G3....~............... \n";
                  s += "5F3....5A3..~..........5G3.....5F3.~........5E3.....5G3.~........... 3F3......4E3...4E3...4E3 ....5F3......... 3D3..~................... \n";
                  s += "5F3....5A3..~.........5G3.....5F3.~........5E3.....5G3.~........... 3F3......4E3...4E3...4E3.....5F3.......... 3D3..~.................. \n";
                 return s;
             };
             auto buildRainmaker = []() -> std::string {
                std::string s = "grid: 4\nbpm: 72\nbasefreq: 444.0\ninstrument: rainmaker\nloop: true\n\n";
                for (int i = 0; i < 32; i++)
                    s += "8x.. 8x.. 8x.. 8x.. 8x.. 8x.. 8x.. 8x.. \n";
                return s;
            };
            auto buildDhol = []() -> std::string {
                std::string s = "grid: 4\nbpm: 72\nbasefreq: 111.0\ninstrument: dhol\nloop: true\n\n";
                for (int i = 0; i < 32; i++)
                    s += "8x.. 8x.. 8x.. 8x.. \n";
                return s;
            };
            
            //group.sequences.push_back({"Panflute", new UMLSequence("Panflute", 51, buildPanflute())});
            group.sequences.push_back({"NAF", new UMLSequence("NAF", 52, buildNAF())});
            group.sequences.push_back({"Voice", new UMLSequence("Voice", 32, buildVoice())});
            //group.sequences.push_back({"Rainmaker", new UMLSequence("Rainmaker", 19, buildRainmaker())});
            //group.sequences.push_back({"Dhol", new UMLSequence("Dhol", 38, buildDhol())});
            group.percussionTrackWeight = 1.5f;
            group.melodyTrackWeight = 1.8f;
            group.backgroundTrackWeight = 0.5f;
            duration = 68;
        }

        if (!group.sequences.empty()) {
            if (timeoutSec > 0) duration = timeoutSec;
            playSequenceGroup(mixer, orch, group, duration);
        } else {
            std::cout << "Invalid selection. Please try again." << std::endl;
        }

        // If run with command line args, exit after playing once
        if (argc > 1) {
            break;
        }
        
        selection = -1; // Reset for next loop in interactive mode
    }

    mixer.stop();
    std::cout << "--- Runner Complete ---" << std::endl;
    return 0;
}
