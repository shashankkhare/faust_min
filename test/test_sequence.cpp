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
    std::vector<std::pair<std::string, std::shared_ptr<UMLSequence>>> sequences;
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
    mixer.setTrackReverbSend(percussionTrack, 0.5f);

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
                          << " | Amp: " << ev.velocity;
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
            } else if (ev.type == UMLEventType::PhonemeOn) {
                double durMs = ev.durationSamples * 1000.0 / InstrumentMapper::DEFAULT_SAMPLE_RATE;
                std::cout << "  Event " << eIdx << ": Phoneme: " << ev.note
                          << " | Dur: " << durMs << "ms"
                          << " | SampleOffset: " << ev.sampleOffset << std::endl;
            } else if (ev.type == UMLEventType::PhonemeGlide) {
                double durMs = ev.durationSamples * 1000.0 / InstrumentMapper::DEFAULT_SAMPLE_RATE;
                std::cout << "  Event " << eIdx << ": Glide: " << ev.targetNote
                          << " | Dur: " << durMs << "ms"
                          << " | SampleOffset: " << ev.sampleOffset << std::endl;
            }
        }
        
        int id = seqPair.second->instrumentID;
        int targetTrack = melodyTrack;
        // Background (ambient/drone/accompaniment/harmony/bass)
        if (id == 11 || id == 19 || id == 27 || id == 34 || id == 41 || id == 42 ||
            (id == 54 && group.name == "Sarod & Harmonium — Raag Yaman") ||
            seqPair.first.find("Cello") != std::string::npos ||
            seqPair.first.find("ViolinH") != std::string::npos) {
            targetTrack = backgroundTrack;
        // All percussion (membrane + idiophone: bowl, bells, shaker, ghatam, ride, hihat, ...) → percussion bus
        } else if (InstrumentMapper::isPercussionID(id)) {
            targetTrack = percussionTrack;
        // Melody stays on melodyTrack (default)
        }
        
        float instWeight = 1.0f;
        if (seqPair.first.find("Cello") != std::string::npos) {
            instWeight = 2.0f; // Boost cellos
        } else if (seqPair.first.find("ViolinH") != std::string::npos) {
            instWeight = 0.6f; // Push harmony violins slightly back
        } else if (seqPair.first.find("Timpani") != std::string::npos) {
            instWeight = 0.3f; // Greatly reduce timpani to prevent speaker cracking
        } else if (id == 21) {
            instWeight = 1.5f; // Boost acoustic guitar
        }

        if (seqPair.second->getFaustInstrument()) {
            mixer.addInstrumentToTrack(targetTrack, seqPair.second->getFaustInstrument(), instWeight);
        }
    }

    orch.linkExtensions();

    // Looping disabled for sequence 12 (single playthrough)

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

    // Sequences are reference-counted: they self-free when the orchestrator's
    // last reference is dropped. No manual delete.
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

#ifdef DEBUG_MIXER
    // --- Tick callback demo: rate-limited console output ---
    static int gTickCounter = 0;
    orch.setTickCallback([](long tick, int noteIndex, const char* seqName, void*) {
        gTickCounter++;
        if ((gTickCounter % 128) == 0) {
            int sec = static_cast<int>(tick / 48000);
            int ms = static_cast<int>((tick % 48000) * 1000 / 48000);
            printf("[TICK] seq=%s  tick=%ld (%d.%03ds)  noteIdx=%d\n", seqName, tick, sec, ms, noteIndex);
            fflush(stdout);
        }
    }, nullptr);
    std::cout << "[TickCallback] Registered tick callback with rate-limited (~128-block) console output\n";

    // --- Waveform callback demo: RMS/peak of master output ---
    static int gWaveformCounter = 0;
    mixer.setWaveformCallback([](float rms, float peak, void*) {
        gWaveformCounter++;
        if ((gWaveformCounter % 256) == 0) {
            printf("[WAVEFORM] rms=%.4f  peak=%.4f\n", rms, peak);
            fflush(stdout);
        }
    }, nullptr);
    std::cout << "[WaveformCallback] Registered waveform callback with rate-limited (~256-block) console output\n";
#endif

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
            std::cout << "  1. Indian Classical — Darbari Kanada (Bansuri, Tanpura, Tabla) [12 semitone]" << std::endl;
            std::cout << "  2. Jazz Ensemble (Piano, Sax, Bass, Drums)" << std::endl;
            std::cout << "  3. Rock Band (Electric Guitar, Bass, Drums)" << std::endl;
            std::cout << "  4. Tibetan Bowl with Rain + LagNga (Bowl, Rainmaker, LagNga)" << std::endl;
            std::cout << "  5. Acoustic Hotel California (Acoustic Guitar, 3 Congas, Bass, Drums)" << std::endl;
            std::cout << "  6. Sitar — Raag Yaman + Tabla" << std::endl;
            std::cout << "  7. North Indian Folk (Dholak Percussion)" << std::endl;
            std::cout << "  8. Punjabi Folk (Bhangra beats)" << std::endl;
            std::cout << "  9. Exit" << std::endl;
            std::cout << " 10. Sarod & Harmonium — Raag Yaman" << std::endl;
            std::cout << " 11. Carnatic Classical — Raag Hamsadhwani (Violin, Mridangam, Ghatam)" << std::endl;
            std::cout << " 12. Last of the Mohicans — Promontory & Elk Hunt (Panflute, NAF, Rainmaker, Dhol)" << std::endl;
            std::cout << " 13. Vivaldi Spring Ensemble (20 Instruments Load Test)" << std::endl;
            std::cout << ">>> Enter selection (1-13): ";
            if (!(std::cin >> selection)) {
                break;
            }
        }

        if (selection == 9) {
            break;
        }

        SequenceGroup group;
        int duration = -1; // default duration 15s

        if (selection == 1) {
            group.name = "Indian Classical — Raag Darbari Kanada (Bansuri, Tanpura, Tabla) [12 semitone]";
            
            std::string umlTanpura = 
                "grid: 4\n"
                "bpm: 70\n"
                "basefreq: 111.0\n"
                "instrument: tanpura\n"
                "notation: Hindustani\n"
                "loop: true\n"
                "\n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n";
            
            // Raag Darbari Kanada — late-night, majestic, deep
            // Arohana: Sa Re ga ma Pa dha ni Sa*
            // Vadi: Re, Samvadi: Pa
            // Structure: Alaap (slow, meend, rests) → Jod (medium) → Jhala (fast chikari)
            std::string umlBansuri = 
                "grid: 4\n"
                "bpm: 70\n"
                "basefreq: 444.0\n"
                "instrument: flute\n"
                "notation: Hindustani\n"
                "vibrato_depth: 0.02\n"
                "vibrato_rate: 5.5\n"
                // --- Alaap (64 cells) — slow, spacious, meend between notes, vibrato on ending ---
                "5Sa..~ . . . . . \n"                     // Sa rings 3 cells with vibrato, 5 cells decay
                "5Sa.^ 8re..~ . . . \n"                   // Sa→meend, re rings with vibrato, decay
                "8re.^ 8ga..~ . . . \n"                   // re→meend, ga rings with vibrato, decay
                "8ga..~ . . . . . \n"                     // ga rings with vibrato, then decay
                "3Ma . 8ga.^ 8re.~ . . \n"                // Ma, meend, re rings with vibrato, decay
                "8re.^ 5Sa..~ . . . \n"                   // re→Sa meend, Sa rings with vibrato, decay
                "8ni . 6dha~ . . . . . \n"                // ni, dha rings with vibrato, then decay
                "6dha.^ 5Sa..~ . . . \n"                   // dha→Sa meend, Sa rings, 3 natural decay
                // --- Jod (128 cells) — medium pulse, vibrato only on ending note ---
                "8re . 8ga . 8re . 5Sa~ . \n"
                "8re . 8ga . 3Ma . 6Pa~ . \n"
                "6dha . 8ni . 6dha . 6Pa~ . \n"
                "3Ma . 8ga . 8re . 5Sa~ . \n"
                "8ni . 6dha . 6Pa . 3Ma~ . \n"
                "8ga . 3Ma . 6dha . 8ni~ . \n"
                "8re . 8ga . 8re . 5Sa~ . \n"
                "6Pa . 3Ma . 8ga . 8re~ . \n"
                "8re . 8ga . 6dha . 8ni~ . \n"
                "6dha . 6Pa . 3Ma . 8ga~ . \n"
                "8re . 8ga . 8re . 5Sa~ . \n"
                "8ni . 6dha . 6Pa . 3Ma~ . \n"
                "8ga . 3Ma . 6Pa . 3Ma~ . \n"
                "8ga . 8re . 5Sa . 8re~ . \n"
                "8ga . 3Ma . 6dha . 6Pa~ . \n"
                "8re . 8ga . 8re . 5Sa~ . \n"
                // --- Jhala (144 cells) — fast chikari, vibrato only on last melody of each line ---
                "61% 8ga 61% 8ga 61% 8re 61% 8ga~ \n"
                "61% 8re 61% 8re 61% 8Sa 61% 8re~ \n"
                "61% 8Sa 61% 8Sa 61% 8ni 61% 8Sa~ \n"
                "61% 8ni 61% 8ni 61% 8dha 61% 8ni~ \n"
                "81re 8ga 81re 8ga 81ni 8dha 81ni 6Pa~ \n"
                "81re 8ga 81re 5Sa 81re 8ga 81re 3Ma~ \n"
                "81ga 8re 81ga 8re 81ga 5Sa 81ga 8re~ \n"
                "61Sa 8ga 61Sa 8ni 61Sa 8dha 61Sa 6Pa~ \n"
                "81re 8ga 81ni 8dha 81re 8ga 81ni 6Pa~ \n"
                "61Sa 8ga 61Sa 8re 61Sa 8ga 61Sa 5Sa~ \n"
                "81ni 8dha 81ni 6Pa 81ni 3Ma 81ni 8ga~ \n"
                "81re 8ga 81re 8ni 81re 8dha 81re 6Pa~ \n"
                "61Sa 8ga 61Sa 5Sa 61Sa 8ga 61Sa 5Sa~ \n"
                "81re 8ga 81re 8ni 81ni 8dha 81ni 6Pa~ \n"
                "61Sa 8ga 61Sa 8re 61Sa 8ga 61Sa 8re~ \n"
                "81ga 8re 81ga 5Sa 81ga 8re 81ga 5Sa~ \n"
                "61Sa 8ga 61Sa 8re 61Sa 8ga 61Sa 8re~ \n"
                "61Sa 8ga 61Sa 8re 61Sa 5Sa 61Sa 5Sa~ \n"
                "5Sa~ . . . . . . . \n";
            
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
                s += std::to_string(bpm) + "\nbasefreq: 55.0\ninstrument: bayan\n\n";
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

            group.sequences.push_back({"Tanpura", std::make_shared<UMLSequence>("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Bansuri", std::make_shared<UMLSequence>("Flute", 10, umlBansuri)});
            group.sequences.push_back({"Dayan", std::make_shared<UMLSequence>("Dayan", 0, umlDayan)});
            group.sequences.push_back({"Bayan", std::make_shared<UMLSequence>("Bayan", 1, umlBayan)});
            
            group.percussionTrackWeight = 0.0f;
            group.melodyTrackWeight = 1.4f;
            group.backgroundTrackWeight = 0.8f;
            duration = -1;
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

            group.sequences.push_back({"JazzPiano", std::make_shared<UMLSequence>("JazzPiano", 12, umlPiano)});
            group.sequences.push_back({"JazzSax", std::make_shared<UMLSequence>("JazzSax", 13, umlSax)});
            group.sequences.push_back({"JazzBass", std::make_shared<UMLSequence>("JazzBass", 23, umlBass)});
            group.sequences.push_back({"JazzKick", std::make_shared<UMLSequence>("JazzKick", 2, umlKick)});
            group.sequences.push_back({"JazzSnare", std::make_shared<UMLSequence>("JazzSnare", 3, umlSnare)});
            group.sequences.push_back({"JazzRide", std::make_shared<UMLSequence>("JazzRide", 6, umlRide)});
            
            duration = -1;

        } else if (selection == 3) {
            group.name = "Hotel California — Acoustic (Guitar, Bass, Drums)";

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
                // Measures 1-4: Bm, F#, A, E
                "B1............... F#1............... A1............... E1............... "
                // Measures 5-8: G, D, Em, F#
                "G1............... D2............... E1............... F#1............... "
                // Repeat
                "B1............... F#1............... A1............... E1............... "
                "G1............... D2............... E1............... F#1...............";

            std::string umlKick = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: kick\n"
                "\n"
                // Measures 1-4: Simple 4-on-the-floor (4 slots each)
                "8x... 8x... 8x... 8x... "
                "8x... 8x... 8x... 8x... "
                "8x... 8x... 8x... 8x... "
                "8x... 8x... 8x... 8x... "
                // Measures 5-8: Syncopated groove (2+6+8=16)
                "8x. 8x..... 8x....... "
                "8x. 8x..... 8x....... "
                "8x. 8x..... 8x....... "
                "8x. 8x..... 8x....... "
                // Measures 9-12: Double-time feel (8x2=16)
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                // Measures 13-16: Breakdown (8+8=16)
                "8x....... 8x....... "
                "8x....... 8x....... "
                "8x....... 8x... 8x... "
                "8x... 8x... 8x... 8x... ";
                
            std::string umlSnare = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: snare\n"
                "\n"
                // Measures 1-4: Standard backbeat (4+4+4+4=16)
                ".... 8x... .... 8x... "
                ".... 8x... .... 8x... "
                ".... 8x... .... 8x... "
                ".... 8x... .... 8x... "
                // Measures 5-8: Ghost notes + accents (8x2=16)
                ".. 8x. 8x. .. 8x. .. 8x. 8x. "
                ".. 8x. 8x. .. 8x. .. 8x. 8x. "
                ".. 8x. 8x. .. 8x. .. 8x. 8x. "
                ".. 8x. 8x. .. 8x. .. 8x. 8x. "
                // Measures 9-12: Driving backbeat (4+2+6+4=16)
                ".... 8x. 8x..... 8x... "
                ".... 8x. 8x..... 8x... "
                ".... 8x. 8x..... 8x... "
                ".... 8x. 8x..... 8x... "
                // Measures 13-16: Fill ending
                ".... 8x... .... 8x... "
                ".... 8x... .... 8x... "
                ".... 8x... 8x....... "
                ".. 8x. .. 8x. .. 8x. .. 8x. ";
                
            std::string umlHihat = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: hihat\n"
                "\n"
                // Measures 1-4: Sparse intro
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x....... "
                // Measures 5-8: Steady groove
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x. "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x....... "
                // Measures 9-12: Open hi-hat accents
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x 8x "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x 8x "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x 8x "
                "8x. 8x. 8x. 8x. 8x. 8x. 8x. 8x 8x "
                // Measures 13-16: Outro build
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x 8x "
                "8x 8x 8x 8x 8x 8x 8x 8x 8x....... ";

            group.sequences.push_back({"AcousticGuitar", std::make_shared<UMLSequence>("AcousticGuitar", 21, umlAGuitar)});
            group.sequences.push_back({"RockBGuitar", std::make_shared<UMLSequence>("RockBGuitar", 23, umlBGuitar)});
            group.sequences.push_back({"RockKick", std::make_shared<UMLSequence>("RockKick", 2, umlKick)});
            group.sequences.push_back({"RockSnare", std::make_shared<UMLSequence>("RockSnare", 3, umlSnare)});
            group.sequences.push_back({"RockHihat", std::make_shared<UMLSequence>("RockHihat", 4, umlHihat)});

            duration = -1;

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
                "basefreq: 55.0\n"
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

            group.percussionTrackWeight = 1.0f;
            group.backgroundTrackWeight = 0.3f;
            group.melodyTrackWeight = 1.0f;

            group.sequences.push_back({"AmbientRain", std::make_shared<UMLSequence>("AmbientRain", 19, umlRainmaker)});
            group.sequences.push_back({"AmbientBowl", std::make_shared<UMLSequence>("AmbientBowl", 8, umlBowl)});
            group.sequences.push_back({"LagNgaHigh", std::make_shared<UMLSequence>("LagNgaHigh", 36, umlLagngaHigh)});
            group.sequences.push_back({"LagNgaLow", std::make_shared<UMLSequence>("LagNgaLow", 36, umlLagngaLow)});
            group.sequences.push_back({"Bowl222", std::make_shared<UMLSequence>("Bowl222", 8, umlBowl222)});
            group.sequences.push_back({"Bowl444", std::make_shared<UMLSequence>("Bowl444", 8, umlBowl444)});

        } else if (selection == 5) {
            group.name = "Hotel California — Piano, Bass, 3 Congas, Shaker";

            // Piano (ID 12): arpeggiated chord voicings
            std::string umlPiano = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: piano\n"
                "notation: Western\n"
                "\n"
                // Measures 1-4 (Bm, F#, A, E)
                "5B3. 5F#4 6B4 6B3 5F#4 6B4. 6F#5... 5D5... "
                "5F#3. 5F#4 6A#4. 5C#5. 6A#4 5F#5....... "
                "6A3. 6E4 6A4. 5C#5. 5A4 5A5... 6C#5... "
                "6B3. 5E4 5G#4. 5B3 6E3 5B3 6E5....... "
                // Measures 5-8 (G, D, Em, F#)
                "6G3. 6B3 6G4. 5B4. 6G3 5C#5... 5D5... "
                ". . 6A3 6D4. 5F#4.. 6F#4... 6D4... "
                ". . 6B3 5G3. 5B3 6A3. 5B3... 5G3... "
                "6F#3. 6F#4 6A#4. 5C#5. 6A#4 6F#5....... "
                // Repeat Measures 1-4
                "5B3. 5F#4 6B4 6B3 5F#4 6B4. 6F#5... 5D5... "
                "5F#3. 5F#4 6A#4. 5C#5. 6A#4 5F#5....... "
                "6A3. 6E4 6A4. 5C#5. 5A4 5A5... 6C#5... "
                "6B3. 5E4 5G#4. 5B3 6E3 5B3 6E5....... "
                // Repeat Measures 5-8
                "6G3. 6B3 6G4. 5B4. 6G3 5C#5... 5D5... "
                ". . 6A3 6D4. 5F#4.. 6F#4... 6D4... "
                ". . 6B3 5G3. 5B3 6A3. 5B3... 5G3... "
                "6F#3. 6F#4 6A#4. 5C#5. 6A#4 6F#5.......";

            std::string umlBass = 
                "grid: 4\n"
                "bpm: 60\n"
                "instrument: bassguitar\n"
                "notation: Western\n"
                "\n"
                "B1............... F#1............... A1............... E1............... "
                "G1............... D2............... E1............... F#1............... "
                "B1............... F#1............... A1............... E1............... "
                "G1............... D2............... E1............... F#1...............";

            // Low Conga (Tumba, 130Hz): groove + fast changeover roll at end of each measure
            // Pattern: hit on 1, offbeat of 2, offbeat of 3, then 4-note roll (to-to-mu-to) on beat 4
            std::string umlCongaLow = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 130.0\n"
                "instrument: conga\n"
                "\n"
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to "
                "to . . .  . . to .  . . to .  to to mu to";

            // Mid Conga (Segundo, 175Hz): interlocking hits + changeover fill (slap-based)
            std::string umlCongaMid = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 175.0\n"
                "instrument: conga\n"
                "\n"
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to "
                ". to . .  to . . .  . to . .  sl to to to";

            // High Conga (Quinto, 225Hz): sparse slaps + fast changeover roll
            std::string umlCongaHigh = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 225.0\n"
                "instrument: conga\n"
                "\n"
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl "
                ". . . .  sl . . .  . . . .  sl sl to sl";

            std::string umlShaker = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 3000.0\n"
                "instrument: shaker\n"
                "\n"
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh . "
                "8sh . 8sh .  8sh . 8sh .  8sh . 8sh .  8sh . 8sh .";

            group.sequences.push_back({"Piano", std::make_shared<UMLSequence>("Piano", 12, umlPiano)});
            group.sequences.push_back({"Bass", std::make_shared<UMLSequence>("Bass", 23, umlBass)});
            group.sequences.push_back({"CongaLow", std::make_shared<UMLSequence>("CongaLow", 30, umlCongaLow)});
            group.sequences.push_back({"CongaMid", std::make_shared<UMLSequence>("CongaMid", 30, umlCongaMid)});
            group.sequences.push_back({"CongaHigh", std::make_shared<UMLSequence>("CongaHigh", 30, umlCongaHigh)});
            group.sequences.push_back({"Shaker", std::make_shared<UMLSequence>("Shaker", 33, umlShaker)});

            duration = -1;

        } else if (selection == 6) {
            group.name = "Sitar — Raag Yaman (Madhya Laya)";
            
            std::string umlTanpura = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 111.0\n"
                "instrument: tanpura\n"
                "notation: Hindustani\n"
                "loop: true\n\n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... ";
                
            std::string umlSitar = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 222.0\n"
                "instrument: sitar\n"
                "notation: Hindustani\n"
                "vibrato: 0.5\n"
                "vibrato_depth: 0.008\n"
                "vibrato_rate: 5.0\n"
                "chikari_freq: 222.0\n\n";
            // Sthayi (32 cells) — Yaman arohana in lower octave, vadi Ga, samvadi Ni
            umlSitar += "6Ni . 6Re . 6Ga . 6Re . 6Ga . 6ma . 6Ga . 6Re . ";
            umlSitar += "6Ni . 6Re . 6Ga . 6ma . 6Dha . 6Ni . 6Sa*2 . 6Re*2 . ";
            // Antara (96 cells) — upper octave with teevra ma, proper Yaman chalan
            for (int i = 0; i < 3; ++i) {
                umlSitar += "6Sa*2 6Ni 6Dha 6Pa 6ma 6Ga 6Re 6Sa ";
                umlSitar += "6Ni 6Re 6Ga 6ma 6Pa 6Dha 6Ni 6Sa*2 ";
                umlSitar += "6Sa*2 6Ni 6Dha 6Pa 6ma 6Ga 6Re 6Sa ";
                umlSitar += "6Ga 6Re 6Sa 6Ni 6Dha 6Pa 6ma 6Ga ";
            }
            // Jhala (96 cells) — chikari with Yaman melody
            for (int i = 0; i < 3; ++i) {
                umlSitar += "6Ga 61Sa*2 6Re 61Sa*2 6Ga 61Sa*2 6ma 61Sa*2 ";
                umlSitar += "6Pa 61Sa*2 6Dha 61Sa*2 6Ni 61Sa*2 6Sa*2 61Sa*2 ";
                umlSitar += "6Sa*2 61Sa*2 6Ni 61Sa*2 6Dha 61Sa*2 6Pa 61Sa*2 ";
                umlSitar += "6ma 61Sa*2 6Ga 61Sa*2 6Re 61Sa*2 6Sa 61Sa*2 ";
            }
            // Tihai (24 cells)
            umlSitar += "6Sa*2 61Sa*2 6Dha 61Sa*2 6Ni 61Sa*2 . . . ";
            umlSitar += "6Sa*2 61Sa*2 6Dha 61Sa*2 6Ni 61Sa*2 . . . ";
            umlSitar += "6Sa*2 61Sa*2 6Dha 61Sa*2 6Ni 61Sa*2 . . . ";
            // Rest (8 cells)
            umlSitar += "_ . . . _ . . . ";
                
            std::string umlDayan = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 222.0\n"
                "instrument: dayan\n\n";
            // Sthayi: Silent (32 cells)
            for (int i = 0; i < 4; ++i) {
                umlDayan += "_ . . . _ . . . ";
            }
            // Antara: Teen Taal (96 cells = 1.5 cycles)
            for (int i = 0; i < 6; ++i) {
                umlDayan += "Na . . . Tin . . . Tun . . . tk . . . ";
            }
            // Jhala: Drut Teen Taal (96 cells)
            for (int i = 0; i < 12; ++i) {
                umlDayan += "Na tk Tin tk Tun tk Na tk ";
            }
            // Tihai + rest (32 cells)
            for (int i = 0; i < 4; ++i) {
                umlDayan += "Na . . . _ . . . ";
            }
                
            std::string umlBayan = 
                "grid: 4\n"
                "bpm: 60\n"
                "basefreq: 111.0\n"
                "instrument: bayan\n\n";
            // Sthayi: Silent (32 cells)
            for (int i = 0; i < 4; ++i) {
                umlBayan += "_ . . . _ . . . ";
            }
            // Antara: slow (96 cells)
            for (int i = 0; i < 6; ++i) {
                umlBayan += "Ghe . . . Ka . . . Ghe . . . Ka . . . ";
            }
            // Jhala: Drut (96 cells)
            for (int i = 0; i < 12; ++i) {
                umlBayan += "Ghe Ghe Ka Ka Ghe Ghe Ka Ka ";
            }
            // Tihai + rest (32 cells)
            for (int i = 0; i < 4; ++i) {
                umlBayan += "Ghe . . . _ . . . ";
            }
            
            group.sequences.push_back({"Tanpura", std::make_shared<UMLSequence>("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Sitar", std::make_shared<UMLSequence>("Sitar", 9, umlSitar)});
            group.sequences.push_back({"Dayan", std::make_shared<UMLSequence>("Dayan", 0, umlDayan)});
            group.sequences.push_back({"Bayan", std::make_shared<UMLSequence>("Bayan", 1, umlBayan)});
            
            group.backgroundTrackWeight = 0.8f;
            duration = -1;
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
                
            group.sequences.push_back({"Dholak", std::make_shared<UMLSequence>("Dholak", 37, umlDholak)});
            duration = -1;
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

            group.sequences.push_back({"Dhol", std::make_shared<UMLSequence>("Dhol", 38, umlDhol)});
            duration = -1;
        } else if (selection == 10) {
            group.name = "Sarod & Harmonium — Raag Yaman";
            
            std::string umlTanpura = 
                "grid: 4\n"
                "bpm: 80\n"
                "basefreq: 222.0\n"
                "instrument: tanpura\n"
                "notation: Hindustani\n"
                "loop: true\n"
                "\n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... \n"
                "5Pa....... 5Sa....... 5Sa....... 5Sa*2....... ";
            
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
                "\n"
                "5Sa..^ 5Sa..^ 8Ni..^ 5Sa..^ \n"
                "8Ni..^ 8Ga..^ 8Re..^ 8Ni..~ \n"
                "8Ga..^ 6Dha..^ 8Ni..^ 6Dha..~ \n"
                "8Re..^ 8Ga..^ 8Re..^ 6Dha..^ \n"
                "9Ni..^ 6Sa*2..^ 9Ni..~ 6Dha..~ \n"
                "8Re..^ 9Ni..^ 6Sa*2..^ 8Ga..^ \n"
                "9Ni..^ 8Re..^ 6Dha..^ 8Ni..^ \n"
                "5Sa..^ 8Re..^ 8Ga..^ 8Re..~ \n"
                "\n"
                "8Ga. 8Re. 5Sa. 8Ni. 9Ni. 5Sa. 8Re. 8Ga. \n"
                "8Re. 8Ga. 6Dha. 8Ni. 6Dha. 8Ni. 8Re. 8Ga. \n"
                "8Ni. 5Sa. 8Re. 8Ga. 9Ni. 6Sa*2. 9Ni. 5Sa. \n"
                "8Ga. 8Re. 6Dha. 8Ni. 8Re. 8Ga. 8Re. 5Sa. \n"
                "6Dha. 8Ni. 8Re. 8Ga. 8Re. 6Dha. 8Ni. 5Sa. \n"
                "\n"
                "61Sa 8Ga~ 61Sa 8Ga~ 81Ni 8Ga~ 61Sa 8Ga~ \n"
                "81Ni 8Ga~ 81Ga 8Re~ 81Re 8Ga~ 81Ni 8Ga~ \n"
                "81Ga 8Re~ 61Dha 8Ni~ 81Ni 8Ga~ 61Dha 8Ni~ \n"
                "81Re 8Ga~ 81Ga 8Re~ 81Re 8Ga~ 61Dha 8Ni~ \n"
                "91Ni 6Sa*2~ 61Sa*2 9Ni~ 91Ni 6Sa*2~ 61Dha 8Ni~ \n"
                "81Re 8Ga~ 91Ni 6Sa*2~ 61Sa*2 9Ni~ 81Ga 8Re~ \n"
                "91Ni 6Sa*2~ 81Re 8Ga~ 61Dha 8Ni~ 81Ni 8Ga~ \n"
                "51Sa 8Re~ 81Re 8Ga~ 81Ga 8Re~ 81Re 8Ga~ \n"
                "5Sa . . . . . . . \n";
                
            std::string umlHarmonium = 
                "grid: 4\n"
                "bpm: 80\n"
                "basefreq: 222.0\n"
                "instrument: harmonium\n"
                "notation: Hindustani\n"
                "\n"
                "5Sa,5Ga,5Pa..._ 5Re,5M2,5Dha..._ 5Ga,5Pa,5Ni..._ 5Re,5M2,5Dha..._\n"
                "5Sa,5Ga,5Pa..._ 5Re,5M2,5Dha..._ 5Ga,5Pa,5Ni..._ 5Re,5M2,5Dha..._\n"
                "5Sa,5Ga,5Pa..._ 5Re,5M2,5Dha..._ 5Ga,5Pa,5Ni..._ 5Re,5M2,5Dha..._\n"
                "5Sa,5Ga,5Pa..._ 5Re,5M2,5Dha..._ 5Ga,5Pa,5Ni..._ 5Re,5M2,5Dha..._\n";

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
                s += std::to_string(bpm) + "\nbasefreq: 55.0\ninstrument: bayan\n\n";
                std::string alaap = "Ghe... _... _... Ka... _... Ka... Ghe... _... ";
                std::string med   = "Ghe. _. _. Ka. _. Ka. Ghe. _. ";
                std::string jhala = "Ghe _ _ Ka _ Ka Ghe _ ";
                for (int i = 0; i < 2; i++) s += alaap;
                for (int i = 0; i < 4; i++) s += med;
                for (int i = 0; i < 4; i++) s += med;
                for (int i = 0; i < 18; i++) s += jhala;
                return s;
            };

            group.sequences.push_back({"Tanpura", std::make_shared<UMLSequence>("Tanpura", 11, umlTanpura)});
            group.sequences.push_back({"Sarod", std::make_shared<UMLSequence>("Sarod", 44, umlSarod)});
            group.sequences.push_back({"Harmonium", std::make_shared<UMLSequence>("Harmonium", 54, umlHarmonium)});
            group.sequences.push_back({"Dayan", std::make_shared<UMLSequence>("Dayan", 0, buildDayan())});
            group.sequences.push_back({"Bayan", std::make_shared<UMLSequence>("Bayan", 1, buildBayan())});
            
            group.percussionTrackWeight = 0.7f;
            group.melodyTrackWeight = 1.0f;
            group.backgroundTrackWeight = 0.7f;
            duration = -1;
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

            group.sequences.push_back({"Violin", std::make_shared<UMLSequence>("Violin", 18, umlViolin)});
            group.sequences.push_back({"Ghatam", std::make_shared<UMLSequence>("Ghatam", 50, umlGhatam)});

            group.percussionTrackWeight = 1.2f;
            group.melodyTrackWeight = 1.0f;
            duration = -1;
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
                  std::string s = "grid: 12\nbpm: 60\nbasefreq: 220\ninstrument: voice\nnotation: Western\nvibrato_rate: 5.5\nvibrato_depth: 0.04\nbreathiness: 0.2\n";
                  s += "delay: 30\n\n";
                  // Promontory theme — follows NAF melody one octave down (tenor range)
                  s += "5F3.~..........^..5E3..^.5D3..^.5Ab2....~..........^..5D3..^.5F3..^.5E3..^.5F3.. 5G3....~.......>......._ \n";
                  s += "5F3.~.............5E3...5D3...5Ab2....~............5D3...5F3...5E3...5F3.. 5G3....~............... \n";
                  s += "5F3....5A3..~..........5G3.....5F3.~........5E3.....5G3.~........... 3F3......4E3...4E3...4E3 ....5F3......... 3D3..~................... \n";
                  s += "5F3....5A3..~.........5G3.....5F3.~........5E3.....5G3.~........... 3F3......4E3...4E3...4E3.....5F3.......... 3D3..~.................. \n";
                 return s;
             };
             auto buildVoiceExt = []() -> std::string {
                  std::string s = "grid: 12\nbpm: 60\nbasefreq: 110\ninstrument: voice\nnotation: xsampa\n";
                  s += "delay: 30\n\n";
                  s += "5A.............^..5E...^.5I...^.5O................^..5U...^.5A...^.5E...^.5I... 7O.............>......._ \n";
                  s += "5A................5E....5I....5O..................5U....5A....5E....5I... 7O..................... \n";
                  s += "5A.....5E..............5I......5O...........5U......5A.............. 3E.......4I....4O....4U .....5A......... 3E........................ \n";
                  s += "5A.....5E.............5I......5O...........5U......5A.............. 3E.......4I....4O....4U......5A.......... 3E....................... \n";
                 return s;
             };
             
             //group.sequences.push_back({"Panflute", std::make_shared<UMLSequence>("Panflute", 51, buildPanflute())});
             group.sequences.push_back({"NAF", std::make_shared<UMLSequence>("NAF", 52, buildNAF())});
            group.sequences.push_back({"Voice", std::make_shared<UMLSequence>("Voice", 32, buildVoice())});
            group.sequences.push_back({"Voice_ext", std::make_shared<UMLSequence>("Voice_ext", 32, buildVoiceExt())});
            group.percussionTrackWeight = 1.5f;
            group.melodyTrackWeight = 1.8f;
            group.backgroundTrackWeight = 0.5f;
            duration = -1;
        } else if (selection == 13) {
            group.name = "Vivaldi Spring Ensemble (20 Instruments Load Test)";
            
            std::string umlViolinM = 
                "grid: 4\nbpm: 100\ninstrument: violin\nnotation: Western\nloop: false\n\n"
                "5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4... "
                "5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4... "
                "6B4. 6C#5. 6B4. 6A4. 5G#4. 4F#4. 3E4 2E4 1E4 0E4";
                
            std::string umlViolinH = 
                "grid: 4\nbpm: 100\ninstrument: violin\nnotation: Western\nloop: false\n\n"
                "5C#4. 5E4. 5E4. 5E4. 5D#4. 5C#4. 6G#4... "
                "5C#4. 5E4. 5E4. 5E4. 5D#4. 5C#4. 6G#4... "
                "6G#4. 6A4. 6G#4. 6F#4. 5E4. 4D#4. 3C#4 2C#4 1C#4 0C#4";

            std::string umlBass = 
                "grid: 4\nbpm: 100\ninstrument: cello\nnotation: Western\nloop: false\n\n"
                "5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2... "
                "5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2... "
                "5E2. 5A1. 5E2. 5B1. 5E2. 5B1. 5E2... "
                "5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2... "
                "5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2... "
                "5E2. 5A1. 5E2. 5B1. 5E2. 5B1. 5E2...";

            std::string umlFlute = 
                "grid: 4\nbpm: 100\ninstrument: flute\nnotation: Western\nloop: false\n\n"
                "5E5. 5G#5. 5G#5. 5G#5. 5F#5. 5E5. 6B5... "
                "5E5. 5G#5. 5G#5. 5G#5. 5F#5. 5E5. 6B5... "
                "6B5. 6C#6. 6B5. 6A5. 5G#5. 4F#5. 3E5 2E5 1E5 0E5";
                
            std::string umlTimpani = 
                "grid: 4\nbpm: 100\ninstrument: tom\nnotation: Western\nloop: false\n\n"
                "5E2... 5E2... 5E2... 5E2... 5B1... 5B1... 5E2... "
                "5E2... 5E2... 5E2... 5E2... 5B1... 5B1... 5E2... "
                "5E2... 5A1... 5E2... 5B1... 5E2... 5B1... 5E2... ";

            std::string umlTrumpet = 
                "grid: 4\nbpm: 100\ninstrument: trumpet\nnotation: Western\nloop: false\n\n"
                "5E4... 5E4... 5E4... 5E4... 5B3... 5B3... 5E4... "
                "5E4... 5E4... 5E4... 5E4... 5B3... 5B3... 5E4... "
                "5E4... 5A3... 5E4... 5B3... 5E4... 5B3... 5E4... ";

            std::string umlPiano = 
                "delay: 48\ngrid: 4\nbpm: 100\ninstrument: piano\nnotation: Western\nloop: false\n\n"
                "5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4... "
                "5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4... "
                "6B4. 6C#5. 6B4. 6A4. 6G#4. 6F#4. 6E4... ";

            auto buildUml = [](const std::string& baseUml, int instanceNum) {
                float delay = (instanceNum - 1) * 0.015f; // 15ms stagger to humanize/chorus
                float vibRate = 4.5f + (instanceNum * 0.15f); // slightly different vibrato rates
                return "delay: " + std::to_string(delay) + "\n" +
                       "vibrato_rate: " + std::to_string(vibRate) + "\n" +
                       "vibrato_depth: 0.03\n" + baseUml;
            };

            // 20 instruments total
            for(int i=1; i<=1; i++) group.sequences.push_back({"ViolinM"+std::to_string(i), std::make_shared<UMLSequence>("ViolinM"+std::to_string(i), 18, buildUml(umlViolinM, i))});
            for(int i=2; i<=5; i++) group.sequences.push_back({"ViolinM"+std::to_string(i), std::make_shared<UMLSequence>("ViolinM"+std::to_string(i), 18, buildUml(umlViolinM, i))});
            
            // --- HARMONY COMMENTED OUT (violin too loud) ---
            // for(int i=1; i<=4; i++) group.sequences.push_back({"ViolinH"+std::to_string(i), std::make_shared<UMLSequence>("ViolinH"+std::to_string(i), 18, buildUml(umlViolinH, i))});
            for(int i=1; i<=4; i++) group.sequences.push_back({"Cello"+std::to_string(i), std::make_shared<UMLSequence>("Cello"+std::to_string(i), 24, buildUml(umlBass, i))});
            for(int i=1; i<=3; i++) group.sequences.push_back({"Flute"+std::to_string(i), std::make_shared<UMLSequence>("Flute"+std::to_string(i), 10, buildUml(umlFlute, i))});
            for(int i=1; i<=2; i++) group.sequences.push_back({"Timpani"+std::to_string(i), std::make_shared<UMLSequence>("Timpani"+std::to_string(i), 5, buildUml(umlTimpani, i))});
            // for(int i=1; i<=2; i++) group.sequences.push_back({"Trumpet"+std::to_string(i), std::make_shared<UMLSequence>("Trumpet"+std::to_string(i), 15, buildUml(umlTrumpet, i))});
            for(int i=1; i<=2; i++) group.sequences.push_back({"Piano"+std::to_string(i), std::make_shared<UMLSequence>("Piano"+std::to_string(i), 12, buildUml(umlPiano, i))});

            group.melodyTrackWeight = 1.0f;
            group.percussionTrackWeight = 0.10f;
            group.backgroundTrackWeight = 0.45f;
        } else {
            std::cout << "Invalid selection. Please try again." << std::endl;
        }

        if (selection >= 1 && selection <= 13 && selection != 9) {
            if (timeoutSec > 0) duration = timeoutSec;
            playSequenceGroup(mixer, orch, group, duration);
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
