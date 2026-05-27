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
 * @file UMLParser.cpp
 * @brief Implementation file for UMLParser
 * 
 * DESIGN: A lightweight parser for the Unified Musical Language (UML). It converts string-based musical notation into a deterministic event timeline for the orchestrator.
 */

#include "UMLParser.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <regex>
#include <fstream>
#include "InstrumentMapper.hpp"

const std::map<std::string, double> UMLParser::indianRatios = {
    {"SaLow", 0.5}, {"Sa", 1.0}, 
    {"r1", 256.0/243.0}, {"r2", 16.0/15.0}, {"R1", 10.0/9.0}, {"R2", 9.0/8.0}, {"Re", 9.0/8.0},
    {"g1", 32.0/27.0}, {"g2", 6.0/5.0}, {"G1", 5.0/4.0}, {"G2", 81.0/64.0}, {"Ga", 5.0/4.0},
    {"M1", 4.0/3.0}, {"M2", 27.0/20.0}, {"m1", 45.0/32.0}, {"m2", 64.0/45.0}, {"Ma", 4.0/3.0},
    {"Pa", 1.5},
    {"d1", 128.0/81.0}, {"d2", 8.0/5.0}, {"D1", 5.0/3.0}, {"D2", 27.0/16.0}, {"Dh", 5.0/3.0}, {"Dha", 5.0/3.0},
    {"n1", 16.0/9.0}, {"n2", 9.0/5.0}, {"N1", 15.0/8.0}, {"N2", 243.0/128.0}, {"Ni", 15.0/8.0}
};

const std::map<std::string, double> UMLParser::percussionBols = {
    {"Na", 0.0}, {"Ta", 0.0}, 
    {"tk", 1.0}, {"Ka", 1.0}, 
    {"Ti", 2.0}, {"Tin", 2.0},
    {"Tu", 3.0}, {"Tun", 3.0}
};

// Vowel syllables → continuous formant-morph index (0=aa, 1=ee, 2=ii, 3=oo, 4=uu)
const std::map<std::string, double> UMLParser::vowelValues = {
    {"aa", 0.0}, {"AA", 0.0}, {"Aa", 0.0}, {"a",  0.0},
    {"ee", 1.0}, {"EE", 1.0}, {"Ee", 1.0}, {"e",  1.0},
    {"ii", 2.0}, {"II", 2.0}, {"Ii", 2.0}, {"i",  2.0},
    {"oo", 3.0}, {"OO", 3.0}, {"Oo", 3.0}, {"o",  3.0},
    {"uu", 4.0}, {"UU", 4.0}, {"Uu", 4.0}, {"u",  4.0}
};

// Bayan-specific tabla bols → strike index (0..3)
const std::map<std::string, double> UMLParser::bayanBols = {
    // Open resonant strokes
    {"Ge",  0.0}, {"ge",  0.0}, {"Ghe", 0.0}, {"ghe", 0.0},
    // Deep bass press
    {"Dha", 1.0}, {"dha", 1.0},
    // Half-muffled
    {"Dhin",2.0}, {"dhin",2.0},
    // Edge stroke
    {"Ka",  3.0}, {"ka",  3.0}, {"Ke",  3.0}, {"ke",  3.0},
    // Muted centre
    {"Ghi", 1.0}, {"ghi", 1.0},
    // Silent/dummy stroke
    {"Tit", 0.0}, {"tit", 0.0}
};

// African hand drum stroke names → strikeVal
// Djembe (ID 28): strike 0.0=soft/bass, 1.0=sharp/slap (continuous 0–1)
// Conga (ID 30) / Bongo (ID 31): strike 0=Open Tone, 1=Slap, 2=Muted
const std::map<std::string, double> UMLParser::africanDrumBols = {
    // --- Open/Bass strokes (strike = 0) ---
    {"Ba",   0.0}, {"ba",   0.0},  // Bass  — full palm centre hit
    {"Gu",   0.0}, {"gu",   0.0},  // Gu    — djembe deep bass (W African)
    {"Don",  0.0}, {"don",  0.0},  // Don   — dun dun open bass
    {"To",   0.0}, {"to",   0.0},  // Tone  — open finger tone (conga/bongo)
    // --- Mid / Tone strokes (strike = 1) ---
    {"Sl",   1.0}, {"sl",   1.0},  // Slap  — sharp edge slap
    {"Go",   1.0}, {"go",   1.0},  // Go    — djembe open tone (W African)
    {"Pa",   1.0},                  // Pa    — djembe mid open tone
    // --- Muted / Edge strokes (strike = 2) ---
    {"Mu",   2.0}, {"mu",   2.0},  // Mute  — muffled/touch stroke
    {"De",   2.0}, {"de",   2.0},  // De    — djembe muted/stopped tone
    {"Tap",  2.0}, {"tap",  2.0},  // Tap   — light finger tap
    // --- Ghost / Silent strokes ---
    {"Gh",   0.0}, {"gh",   0.0}   // Ghost — near-silent brush
};

const std::map<std::string, double> UMLParser::westernPitches = {
    {"C4", 261.63}, {"C#", 277.18}, {"Db", 277.18}, {"D4", 293.66}
    // Add more western pitches as needed
};

UMLSequence UMLParser::parse(const std::string& name, const std::string& input, double sampleRate, double defaultBaseFreq) {
    UMLSequence seq;
    seq.name = name;
    seq.baseFreq = -1.0;
    
    std::stringstream ss(input);
    std::string line;
    std::string notesSection;
    int grid = 4;
    // --- Pass 1: Header Parsing ---
    while (std::getline(ss, line)) {
        if (line.empty()) continue;
        if (line.find("//") == 0) continue; // Comment

        if (line.find(':') != std::string::npos) {
            auto pos = line.find(':');
            std::string key = line.substr(0, pos);
            std::string val = line.substr(pos + 1);
            
            // Trim
            key.erase(0, key.find_first_not_of(" \t\r\n"));
            key.erase(key.find_last_not_of(" \t\r\n") + 1);
            val.erase(0, val.find_first_not_of(" \t\r\n"));
            val.erase(val.find_last_not_of(" \t\r\n") + 1);

            if (key == "notation") seq.notation = val;
            else if (key == "exectype" || key == "execType" || key == "exec_type") seq.execType = val;
            else if (key == "basefreq") seq.baseFreq = std::stod(val);
            else if (key == "bpm") seq.bpm = std::stod(val);
            else if (key == "grid") grid = std::stoi(val);
            else if (key == "instrument") {
                seq.instrument = val;
            }
            else if (key == "parameters") {
                std::stringstream pss(val);
                std::string pPair;
                while (std::getline(pss, pPair, ',')) {
                    auto eq = pPair.find('=');
                    if (eq != std::string::npos) {
                        std::string pKey = pPair.substr(0, eq);
                        std::string pVal = pPair.substr(eq + 1);
                        pKey.erase(0, pKey.find_first_not_of(" \t\r\n"));
                        pKey.erase(pKey.find_last_not_of(" \t\r\n") + 1);
                        seq.initialParams[pKey] = std::stod(pVal);
                    }
                }
            }
            else if (key == "gain") seq.gain = std::stod(val);
            else if (key == "instrumentID" || key == "instrumentid" || key == "ID" || key == "id") {
                seq.instrumentID = std::stoi(val);
            }
            else if (!key.empty() && std::all_of(key.begin(), key.end(), ::isdigit)) {
                seq.instrumentID = std::stoi(key);
                if (seq.instrument.empty()) {
                    seq.instrument = val;
                }
            }
        } else {
            notesSection += line;
        }
    }

    // Bidirectional translation mapping cross-synchronization via Universal Service
    if (seq.instrumentID != -1 && seq.instrument.empty()) {
        seq.instrument = InstrumentMapper::getNameFromID(seq.instrumentID);
    } else if (seq.instrumentID == -1 && !seq.instrument.empty()) {
        seq.instrumentID = InstrumentMapper::getIDFromName(seq.instrument);
        if (seq.instrumentID == -1) {
            printf("[Native Error] UMLParser: Failed to resolve instrument name '%s'\n", seq.instrument.c_str());
            fflush(stdout);
        }
    } else if (seq.instrumentID == -1 && seq.instrument.empty()) {
        seq.instrumentID = 10; // Flute fallback if missing headers
        seq.instrument = "flute";
    }

    double samplesPerGrid = (60.0 / seq.bpm) * sampleRate / grid;

    // --- Pass 2: Tokenization via Standardized Regex Classifier ---
    std::vector<TokenItem> tokenItems;
    long currentGridIndex = 0;

    // Regex parsing layout:
    // Group 1 matches standalone dots (.) -> ContinuityDot
    // Group 2 matches standalone underscores (_) -> StopRest
    // Group 3 matches general notes starting with optional digits/chars ending with optional glide marker (^) -> NoteWithControl
    std::regex tokenRegex(R"((\.)|(\_)|([^\s\.\_]+))");
    auto words_begin = std::sregex_iterator(notesSection.begin(), notesSection.end(), tokenRegex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        TokenItem ti;
        ti.gridIndex = currentGridIndex;
        ti.controlParam = 5; // Default middle-register/velocity scalar
        ti.hasGlide = false;

        if (match[1].matched) {
            ti.type = TokenType::ContinuityDot;
            ti.rawStr = ".";
        } else if (match[2].matched) {
            ti.type = TokenType::StopRest;
            ti.rawStr = "_";
        } else if (match[3].matched) {
            ti.type = TokenType::NoteWithControl;
            std::string rem = match[3].str();
            ti.rawStr = rem;

            // Extract embedded single-digit control prefix modifier securely
            if (rem.length() > 1 && std::isdigit(rem[0]) && !std::isdigit(rem[1])) {
                ti.controlParam = rem[0] - '0';
                rem = rem.substr(1);
            }
            if (!rem.empty() && rem.back() == '^') {
                ti.hasGlide = true;
                rem.pop_back();
            }
            ti.noteName = rem;
        }
        tokenItems.push_back(ti);
        currentGridIndex++;
    }

    // --- Pass 3: Event Generation with Standardized Multi-Grid Sustains ---
    for (size_t i = 0; i < tokenItems.size(); ++i) {
        const auto& ti = tokenItems[i];
        if (ti.type == TokenType::NoteWithControl) {
            float vel = (float)ti.controlParam / 9.0f;

            // Calculate exact continuous sustain duration across trailing ContinuityDot tokens
            long durationGrids = 1;
            size_t k = i + 1;
            while (k < tokenItems.size() && tokenItems[k].type == TokenType::ContinuityDot) {
                durationGrids++;
                k++;
            }
            long calculatedDurationSamples = (long)(durationGrids * samplesPerGrid);
            long sampleOffset = (long)(ti.gridIndex * samplesPerGrid);

            int mappedInstID = seq.instrumentID;
            if (mappedInstID == -1 && !seq.instrument.empty()) {
                mappedInstID = InstrumentMapper::getIDFromName(seq.instrument);
            }

            bool hasExplicitPrefix = (ti.rawStr != ti.noteName);
            if (InstrumentMapper::isPercussionID(mappedInstID)) {
                handlePercussionToken(ti.noteName, vel, sampleOffset, calculatedDurationSamples, seq.baseFreq, seq.instrument, seq.events);
            } else if (mappedInstID == 32) { // Voice — vowel-driven token
                handleVoiceToken(ti, vel, sampleOffset, calculatedDurationSamples, seq.notation, seq.baseFreq, samplesPerGrid, k, tokenItems, seq.events);
            } else {
                handlePitchedToken(ti, vel, sampleOffset, calculatedDurationSamples, seq.notation, seq.baseFreq, seq.instrument, samplesPerGrid, k, tokenItems, seq.events);
            }
        } else if (ti.type == TokenType::StopRest) {
            UMLEvent restEv;
            restEv.sampleOffset = (long)(ti.gridIndex * samplesPerGrid);
            restEv.type = UMLEventType::NoteOff;
            seq.events.push_back(restEv);
        }
    }

    seq.grid = grid;
    seq.totalDurationSamples = (long)(currentGridIndex * samplesPerGrid);

    // Parsed events dump complete
    return seq;
}

void UMLParser::handlePercussionToken(const std::string& tokenNoteName, float amplitudeScalar, long sampleOffset, long durationSamples, double baseFreq, const std::string& instrument, std::vector<UMLEvent>& outEvents) {
    // Percussion instances utilize unpitched triggering mechanics where note string defines stroke style.
    // The frequency is inherited from the sequence base frequency.
    UMLEvent ev; 
    ev.sampleOffset = sampleOffset;
    ev.frequency = static_cast<float>(baseFreq);
    ev.velocity = -1.0f;  // not in UML yet — use DSP default
    ev.amplitude = amplitudeScalar;
    ev.type = UMLEventType::NoteOn;
    ev.note = tokenNoteName;
    ev.durationSamples = durationSamples;

    // Pre-calculate strikeVal based on instrument and note
    int instID = InstrumentMapper::getIDFromName(instrument);
    if (instID == 0) { // Dayan — classical tabla bols
        if (tokenNoteName == "Na" || tokenNoteName == "Ta" || tokenNoteName == "na" || tokenNoteName == "ta") ev.strikeVal = 0.0f;
        else if (tokenNoteName == "tk") ev.strikeVal = 1.0f;
        else if (tokenNoteName == "Tin" || tokenNoteName == "Ti" || tokenNoteName == "tin" || tokenNoteName == "ti") ev.strikeVal = 2.0f;
        else if (tokenNoteName == "Tun" || tokenNoteName == "Tu" || tokenNoteName == "tun" || tokenNoteName == "tu") ev.strikeVal = 3.0f;
        // Compound bols that have a dayan component (use Na/Ta strike)
        else if (tokenNoteName == "Dha" || tokenNoteName == "dha") ev.strikeVal = 0.0f; // Dayan open ring
        else if (tokenNoteName == "Dhin" || tokenNoteName == "dhin") ev.strikeVal = 2.0f; // Dayan Tin-style
        else if (tokenNoteName == "Tit" || tokenNoteName == "tit") ev.strikeVal = 1.0f;
    } else if (instID == 1) { // Bayan — extended bol set
        if (bayanBols.count(tokenNoteName)) {
            ev.strikeVal = static_cast<float>(bayanBols.at(tokenNoteName));
        } else {
            // Legacy fallback for older bol spellings
            if (tokenNoteName == "Ka" || tokenNoteName == "ka") ev.strikeVal = 0.0f;
            else if (tokenNoteName == "Ghe" || tokenNoteName == "ghe") ev.strikeVal = 1.0f;
            else if (tokenNoteName == "Ghi" || tokenNoteName == "ghi") ev.strikeVal = 2.0f;
            else if (tokenNoteName == "Ke" || tokenNoteName == "ke") ev.strikeVal = 3.0f;
        }
    } else if (instID == 28 || instID == 30 || instID == 31) { // Djembe / Conga / Bongo — African stroke names
        if (africanDrumBols.count(tokenNoteName)) {
            ev.strikeVal = static_cast<float>(africanDrumBols.at(tokenNoteName));
        } else if (percussionBols.count(tokenNoteName)) {
            // Fallback: allow generic tabla tokens to still work
            ev.strikeVal = static_cast<float>(percussionBols.at(tokenNoteName));
        }
    } else if (instID == 37) { // Dholak
        float bassF = 98.0f;
        if (baseFreq > 0.0 && std::abs(baseFreq - 261.63) > 0.01) {
            bassF = static_cast<float>(baseFreq);
        }
        ev.frequency = bassF;

        bool isOpenBass = (tokenNoteName == "Ge" || tokenNoteName == "ge" || tokenNoteName == "Ghe" || tokenNoteName == "ghe" || tokenNoteName == "bass");
        bool isClosedBass = (tokenNoteName == "Ke" || tokenNoteName == "ke" || tokenNoteName == "Ka" || tokenNoteName == "ka");
        bool isOpenTreble = (tokenNoteName == "Na" || tokenNoteName == "na" || tokenNoteName == "Ta" || tokenNoteName == "ta" || tokenNoteName == "treble");
        bool isClosedTreble = (tokenNoteName == "Tin" || tokenNoteName == "tin" || tokenNoteName == "Ti" || tokenNoteName == "ti" ||
                               tokenNoteName == "Tun" || tokenNoteName == "tun" || tokenNoteName == "Tu" || tokenNoteName == "tu");
        bool isComposite = (tokenNoteName == "Dha" || tokenNoteName == "dha" || tokenNoteName == "Dhin" || tokenNoteName == "dhin");

        if (isComposite) {
            ev.strikeVal = 4.0f;
        } else if (isOpenBass) {
            ev.strikeVal = 0.0f;
        } else if (isClosedBass) {
            ev.strikeVal = 1.0f;
        } else if (isOpenTreble) {
            ev.strikeVal = 2.0f;
        } else if (isClosedTreble) {
            ev.strikeVal = 3.0f;
        } else {
            ev.strikeVal = 0.0f;
        }
    } else if (instID == 38) { // Dhol
        float bassF = 65.4f;
        if (baseFreq > 0.0 && std::abs(baseFreq - 261.63) > 0.01) {
            bassF = static_cast<float>(baseFreq);
        }
        ev.frequency = bassF;

        bool isOpenBass = (tokenNoteName == "Ge" || tokenNoteName == "ge" || tokenNoteName == "Ghe" || tokenNoteName == "ghe" || tokenNoteName == "Dagga" || tokenNoteName == "dagga" || tokenNoteName == "bass");
        bool isClosedBass = (tokenNoteName == "Ke" || tokenNoteName == "ke" || tokenNoteName == "Ka" || tokenNoteName == "ka");
        bool isOpenTreble = (tokenNoteName == "Na" || tokenNoteName == "na" || tokenNoteName == "Ta" || tokenNoteName == "ta" || tokenNoteName == "Tilli" || tokenNoteName == "tilli" || tokenNoteName == "treble");
        bool isClosedTreble = (tokenNoteName == "Tin" || tokenNoteName == "tin" || tokenNoteName == "Ti" || tokenNoteName == "ti");
        bool isComposite = (tokenNoteName == "Dha" || tokenNoteName == "dha" || tokenNoteName == "Dhin" || tokenNoteName == "dhin");

        if (isComposite) {
            ev.strikeVal = 4.0f;
        } else if (isOpenBass) {
            ev.strikeVal = 0.0f;
        } else if (isClosedBass) {
            ev.strikeVal = 1.0f;
        } else if (isOpenTreble) {
            ev.strikeVal = 2.0f;
        } else if (isClosedTreble) {
            ev.strikeVal = 3.0f;
        } else {
            ev.strikeVal = 0.0f;
        }
    } else if (percussionBols.count(tokenNoteName)) {
        ev.strikeVal = static_cast<float>(percussionBols.at(tokenNoteName));
    }

    outEvents.push_back(ev);
}

void UMLParser::handlePitchedToken(const TokenItem& ti, float amplitudeScalar, long sampleOffset, long durationSamples, 
                                   const std::string& notation, double baseFreq, const std::string& instrument,
                                   double samplesPerGrid, size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray, std::vector<UMLEvent>& outEvents) {
    
    std::vector<std::string> notes;
    std::stringstream ss(ti.noteName);
    std::string item;
    while (std::getline(ss, item, '|')) {
        notes.push_back(item);
    }

    if (notes.empty()) return;

    for (const auto& noteStr : notes) {
        float freq = static_cast<float>(getFrequency(noteStr, notation, baseFreq, instrument));
        
        UMLEvent noteEv;
        noteEv.sampleOffset = sampleOffset;
        noteEv.frequency = freq;
        noteEv.velocity = -1.0f;
        noteEv.amplitude = amplitudeScalar;
        noteEv.type = UMLEventType::NoteOn;
        noteEv.note = noteStr;
        noteEv.durationSamples = durationSamples;
        outEvents.push_back(noteEv);
    }

    // Execute automated glides targeting next standalone operational pitch boundary
    if (ti.hasGlide) {
        size_t targetIdx = nextTokenIndex;
        while (targetIdx < tokenItemsArray.size() && (tokenItemsArray[targetIdx].type == TokenType::ContinuityDot || tokenItemsArray[targetIdx].type == TokenType::StopRest)) {
            targetIdx++;
        }
        if (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type == TokenType::NoteWithControl) {
            std::string tNote = tokenItemsArray[targetIdx].noteName;
            size_t slashPos = tNote.find('/');
            if (slashPos != std::string::npos) tNote = tNote.substr(0, slashPos);
            
            float tFreq = (float)getFrequency(tNote, notation, baseFreq, instrument);
            float tVel = (float)tokenItemsArray[targetIdx].controlParam / 9.0f;
            
            float freq0 = static_cast<float>(getFrequency(notes[0], notation, baseFreq, instrument));
            
            // Enforce lookahead constraint: glide triggers ONLY if target frequency or velocity differs
            if (std::abs(tFreq - freq0) > 0.01f || std::abs(tVel - amplitudeScalar) > 0.01f) {
                UMLEvent glideEv;
                glideEv.sampleOffset = sampleOffset;
                glideEv.type = UMLEventType::Glide;
                glideEv.targetFrequency = tFreq;
                glideEv.targetVelocity = tVel;
                glideEv.durationSamples = durationSamples;
                outEvents.push_back(glideEv);
            }
        }
    }
}

static double parseWesternPitch(const std::string& token) {
    if (token.empty()) return 0.0;
    
    size_t i = 0;
    char note = token[i++];
    note = std::toupper(note);
    if (note < 'A' || note > 'G') return 0.0;
    
    int offset = 0;
    switch (note) {
        case 'C': offset = 0; break;
        case 'D': offset = 2; break;
        case 'E': offset = 4; break;
        case 'F': offset = 5; break;
        case 'G': offset = 7; break;
        case 'A': offset = 9; break;
        case 'B': offset = 11; break;
    }
    
    if (i < token.length() && (token[i] == '#' || token[i] == 's')) {
        offset += 1;
        i++;
    } else if (i < token.length() && (token[i] == 'b' || token[i] == 'f')) {
        offset -= 1;
        i++;
    }
    
    int octave = 4; // default octave
    if (i < token.length() && std::isdigit(token[i])) {
        octave = token[i] - '0';
    }
    
    int midi = (octave + 1) * 12 + offset;
    return 440.0 * std::pow(2.0, (midi - 69) / 12.0);
}

double UMLParser::getFrequency(const std::string& token, const std::string& notation, double baseFreq, const std::string& instrument) {
    // 0. Numeric Check (Direct Frequency)
    try {
        if (!token.empty() && std::isdigit(token[0])) {
            return std::stod(token);
        }
    } catch (...) {}

    // 1. Universal Percussion Check via Translation Mapper (IDs 0 to 6 are non-pitched drums)
    int instID = InstrumentMapper::getIDFromName(instrument);
    if (instID >= 0 && instID <= 6) {
        // For percussion, the bol/stroke name itself controls articulation mappings.
        // We return baseFreq directly as a static unpitched target.
        return baseFreq;
    }

    // 2. Melodic Check
    if (notation == "Indian") {
        if (indianRatios.count(token)) return baseFreq * indianRatios.at(token);
    } else {
        if (westernPitches.count(token)) return westernPitches.at(token);
        double parsed = parseWesternPitch(token);
        if (parsed > 0.0) return parsed;
    }
    return baseFreq;
}


void UMLParser::handleVoiceToken(const TokenItem& ti, float amplitudeScalar, long sampleOffset, long durationSamples,
                                 const std::string& notation, double baseFreq,
                                 double samplesPerGrid, size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray, std::vector<UMLEvent>& outEvents) {
    // tokenNoteName is the raw string from the UML token (e.g., "6Sa")
    // For voice, we need to extract vowel formant scale from numerical prefix
    const std::string& token = ti.noteName;

    UMLEvent ev;
    ev.sampleOffset   = sampleOffset;
    ev.velocity       = -1.0f;
    ev.amplitude      = amplitudeScalar;
    ev.type           = UMLEventType::NoteOn;
    ev.note           = token;
    ev.durationSamples = durationSamples;
    ev.strikeVal      = -1.0f; // Voice has no strike

    // Check if the token is a vowel syllable
    if (vowelValues.count(token)) {
        // Vowel token: emit the formant-morph value; pitch stays at base
        ev.vowelVal  = static_cast<float>(vowelValues.at(token));
        ev.frequency = static_cast<float>(baseFreq);
    } else {
        // Treat as a pitched note (Indian solfège or direct Hz) with no vowel override
        ev.frequency = static_cast<float>(getFrequency(token, notation, baseFreq, "voice"));
        ev.vowelVal  = -1.0f; // No vowel change — orchestrator keeps existing vowel
    }

    outEvents.push_back(ev);

    // Glide support: if the token ends with '^', emit a Glide event towards the next token
    if (ti.hasGlide) {
        size_t targetIdx = nextTokenIndex;
        while (targetIdx < tokenItemsArray.size() &&
               (tokenItemsArray[targetIdx].type == TokenType::ContinuityDot ||
                tokenItemsArray[targetIdx].type == TokenType::StopRest)) {
            targetIdx++;
        }
        if (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type == TokenType::NoteWithControl) {
            const std::string& nextTok = tokenItemsArray[targetIdx].noteName;
            float tFreq = ev.frequency;
            if (!vowelValues.count(nextTok)) {
                tFreq = static_cast<float>(getFrequency(nextTok, notation, baseFreq, "voice"));
            }
            float tVel = static_cast<float>(tokenItemsArray[targetIdx].controlParam) / 9.0f;
            if (std::abs(tFreq - ev.frequency) > 0.01f || std::abs(tVel - amplitudeScalar) > 0.01f) {
                UMLEvent glideEv;
                glideEv.sampleOffset     = sampleOffset;
                glideEv.type             = UMLEventType::Glide;
                glideEv.targetFrequency  = tFreq;
                glideEv.targetVelocity   = tVel;
                glideEv.durationSamples  = durationSamples;
                outEvents.push_back(glideEv);
            }
        }
    }
}

UMLSequence::UMLSequence(const std::string& seqName, int instID, const std::string& umlDataString, double defaultBaseFreq) {
    UMLSequence parsed = UMLParser::parse(seqName, umlDataString, InstrumentMapper::DEFAULT_SAMPLE_RATE, defaultBaseFreq);
    this->name = parsed.name;
    this->instrument = parsed.instrument;
    this->instrumentID = instID != -1 ? instID : parsed.instrumentID;
    this->initialParams = parsed.initialParams;
    this->events = parsed.events;
    this->bpm = parsed.bpm;
    this->grid = parsed.grid;
    this->baseFreq = parsed.baseFreq;
    this->gain = parsed.gain;
    this->totalDurationSamples = parsed.totalDurationSamples;
    this->notation = parsed.notation;
    this->execType = parsed.execType;
    this->umlData = umlDataString;

    int targetID = this->instrumentID;
    if (targetID == -1 && !this->instrument.empty()) {
        targetID = InstrumentMapper::getIDFromName(this->instrument);
    }
    if (targetID != -1) {
        DSPExecutionType mode = (this->execType == "interpreter" || this->execType == "interpreted") 
                              ? DSPExecutionType::InterpretedByte 
                              : DSPExecutionType::StaticCompiled;
        this->mInstrument = std::make_shared<FaustInstrument>(targetID, mode, InstrumentMapper::DEFAULT_SAMPLE_RATE);
        for (const auto& pair : this->initialParams) {
            this->mInstrument->setParameter(pair.first.c_str(), pair.second);
        }
    } else {
        printf("[Native] WARNING: UMLSequence created with invalid instrument ID mapping.\n");
        fflush(stdout);
    }
}

UMLSequence::~UMLSequence() {
    // Note: FaustMixer unregistration must be handled by the caller/owner
    // to strictly preserve zero-coupling architecture.
}
