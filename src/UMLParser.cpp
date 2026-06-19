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

const std::map<std::string, double> UMLParser::shruti22Ratios = {
    // 22 Shrutis — full microtonal system of Hindustani classical music
    // Each shruti has its S{n} numeric alias, standard swara name, and common aliases
    {"S1", 1.0}, {"Sa", 1.0}, {"SaLow", 0.5},
    {"S2", 256.0/243.0}, {"r1", 256.0/243.0},
    {"S3", 16.0/15.0},  {"r2", 16.0/15.0},  {"re", 16.0/15.0},
    {"S4", 10.0/9.0},   {"R1", 10.0/9.0},
    {"S5", 9.0/8.0},    {"R2", 9.0/8.0},    {"Re", 9.0/8.0},
    {"S6", 32.0/27.0},  {"g1", 32.0/27.0},
    {"S7", 6.0/5.0},    {"g2", 6.0/5.0},    {"ga", 6.0/5.0},
    {"S8", 5.0/4.0},    {"G1", 5.0/4.0},    {"Ga", 5.0/4.0},
    {"S9", 81.0/64.0},  {"G2", 81.0/64.0},
    {"S10", 4.0/3.0},   {"M1", 4.0/3.0},    {"Ma", 4.0/3.0},
    {"S11", 27.0/20.0}, {"M2", 27.0/20.0},
    {"S12", 45.0/32.0}, {"m1", 45.0/32.0},
    {"S13", 64.0/45.0}, {"m2", 64.0/45.0},
    {"S14", 3.0/2.0},   {"Pa", 3.0/2.0},
    {"S15", 128.0/81.0},{"d1", 128.0/81.0},
    {"S16", 8.0/5.0},   {"d2", 8.0/5.0},    {"dha", 8.0/5.0},
    {"S17", 5.0/3.0},   {"D1", 5.0/3.0},    {"Dha", 5.0/3.0}, {"Dh", 5.0/3.0},
    {"S18", 27.0/16.0}, {"D2", 27.0/16.0},
    {"S19", 16.0/9.0},  {"n1", 16.0/9.0},
    {"S20", 9.0/5.0},   {"n2", 9.0/5.0},    {"ni", 9.0/5.0},
    {"S21", 15.0/8.0},  {"N1", 15.0/8.0},   {"Ni", 15.0/8.0},
    {"S22", 243.0/128.0},{"N2", 243.0/128.0}
};

const std::map<std::string, double> UMLParser::hindustaniRatios = {
    // 12-note Sargam (Hindustani classical) — Sa Re Ga Ma Pa Dha Ni
    {"SaLow", 0.5}, {"Sa", 1.0},
    {"re", 16.0/15.0}, {"Re", 9.0/8.0},
    {"ga", 6.0/5.0},  {"Ga", 5.0/4.0},
    {"Ma", 4.0/3.0},  {"m", 45.0/32.0}, {"ma", 45.0/32.0},
    {"Pa", 3.0/2.0},
    {"dha", 8.0/5.0}, {"Dha", 5.0/3.0}, {"Dh", 5.0/3.0},
    {"ni", 9.0/5.0},  {"Ni", 15.0/8.0}
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

/**
 * Main UML sequence parsing pipeline.
 * Converts raw UML string sequences into a sample-accurate vector of UMLEvents.
 *
 * 1. Pass 1 (Metadata Extraction): Pulls out header keys (e.g., bpm:, notation:, grid:) and extracts the raw `notesSection`.
 * 2. Pass 2 (Tokenization): Uses a regex to tokenize notes, continuity dots, and rests into `TokenItem` structs, inherently tracking grid boundaries. Operators like ^ and ~ are parsed as flags belonging to a specific grid token.
 * 3. Pass 3 (Event Assembly): Scans sequences linearly, rolling up ContinuityDots to calculate total note durations and resolving precise sample offsets for triggers, yielding the final event collection.
 */
UMLSequence UMLParser::parse(const std::string& name, const std::string& input, double sampleRate, double defaultBaseFreq) {
    UMLSequence seq;
    seq.name = name;
    seq.baseFreq = -1.0;
    seq.notation.clear();
    
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
            else if (key == "loop") {
                std::string lowerVal = val;
                std::transform(lowerVal.begin(), lowerVal.end(), lowerVal.begin(), ::tolower);
                seq.loop = (lowerVal == "true" || lowerVal == "1" || lowerVal == "yes");
            }
            else if (key == "delay") {
                seq.delaySec = std::stod(val);
            }
            else if (key == "measure") {
                seq.measure = std::stoi(val);
            }
            else if (key == "instrumentID" || key == "instrumentid" || key == "ID" || key == "id") {
                seq.instrumentID = std::stoi(val);
            }
            else if (!key.empty() && std::all_of(key.begin(), key.end(), ::isdigit)) {
                seq.instrumentID = std::stoi(key);
                if (seq.instrument.empty()) {
                    seq.instrument = val;
                }
            }
            else {
                seq.initialParams[key] = std::stod(val);
            }
        } else {
            notesSection += line + "\n";
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
    // Group 1 matches standalone dots with optional operators (\.[\^\~>]*) -> ContinuityDot
    // Group 2 matches standalone underscores (_) -> StopRest
    // Group 3 matches general notes starting with optional digits/chars ending with optional operators -> NoteWithControl
    std::regex tokenRegex(R"((\.[\^\~>]*)|(\_)|([\^\~>])|([^\s\.\_]+))");
    auto words_begin = std::sregex_iterator(notesSection.begin(), notesSection.end(), tokenRegex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        TokenItem ti;
        ti.gridIndex = currentGridIndex;
        ti.controlParam = 5; // Default middle-register/velocity scalar
        ti.strikeVal = 0.0f;
        ti.hasGlideOp = false;
        ti.hasAmpGlideOp = false;
        ti.hasVibratoOp = false;

        if (match[1].matched) {
            ti.type = TokenType::ContinuityDot;
            std::string rem = match[1].str();
            ti.rawStr = rem;
            if (rem.find('^') != std::string::npos) ti.hasGlideOp = true;
            if (rem.find('>') != std::string::npos) ti.hasAmpGlideOp = true;
            if (rem.find('~') != std::string::npos) ti.hasVibratoOp = true;
        } else if (match[2].matched) {
            ti.type = TokenType::StopRest;
            ti.rawStr = "_";
        } else if (match[4].matched) {
            ti.type = TokenType::NoteWithControl;
            std::string rem = match[4].str();
            ti.rawStr = rem;

            if (rem.find('^') != std::string::npos) {
                ti.hasGlideOp = true;
                rem.erase(std::remove(rem.begin(), rem.end(), '^'), rem.end());
            }
            if (rem.find('>') != std::string::npos) {
                ti.hasAmpGlideOp = true;
                rem.erase(std::remove(rem.begin(), rem.end(), '>'), rem.end());
            }
            if (rem.find('~') != std::string::npos) {
                ti.hasVibratoOp = true;
                rem.erase(std::remove(rem.begin(), rem.end(), '~'), rem.end());
            }

            // Composite note — comma-separated sub-notes, each with its own prefix
            if (rem.find(',') != std::string::npos) {
                ti.hasCompositeNotes = true;
                ti.noteName = rem;
                goto done_parsing;
            }

            // Extract embedded control/strike prefix modifier
            if (rem.length() > 2 && std::isdigit(rem[0]) && std::isdigit(rem[1]) && !std::isdigit(rem[2])) {
                ti.controlParam = rem[0] - '0';
                ti.strikeVal = static_cast<float>(rem[1] - '0');
                rem = rem.substr(2);
            } else if (rem.length() > 1 && std::isdigit(rem[0]) && !std::isdigit(rem[1])) {
                ti.controlParam = rem[0] - '0';
                rem = rem.substr(1);
            } else if (rem.length() > 0 && std::isdigit(rem[0]) && rem.find_first_not_of("0123456789.") == std::string::npos) {
                // Direct Hz numeric token, keep whole
            } else if (rem.length() > 0 && std::isdigit(rem[0])) {
                // Fallback: check if we have one or two digits
                if (rem.length() > 1 && std::isdigit(rem[1])) {
                    ti.controlParam = rem[0] - '0';
                    ti.strikeVal = static_cast<float>(rem[1] - '0');
                    rem = rem.substr(2);
                } else {
                    ti.controlParam = rem[0] - '0';
                    rem = rem.substr(1);
                }
            }
            ti.noteName = rem;
        done_parsing:;
        } else if (match[3].matched) {
            // Standalone operator (^ or ~ with space before/after) — still occupies a grid cell
            ti.type = TokenType::ContinuityDot;
            ti.rawStr = match[3].str();
            if (match[3].str() == "~") ti.hasVibratoOp = true;
            if (match[3].str() == "^") ti.hasGlideOp = true;
            if (match[3].str() == ">") ti.hasAmpGlideOp = true;
        }
        tokenItems.push_back(ti);
        currentGridIndex++;
    }

    // --- Pass 2.5: Mark Glide Targets ---
    for (size_t i = 0; i < tokenItems.size(); ++i) {
        if (tokenItems[i].hasGlideOp) {
            size_t targetIdx = i + 1;
            while (targetIdx < tokenItems.size() && tokenItems[targetIdx].type != TokenType::NoteWithControl) {
                targetIdx++;
            }
            if (targetIdx < tokenItems.size()) {
                tokenItems[targetIdx].isGlideTarget = true;
            }
        }
    }

    // --- Pass 3: Event Generation & Timing ---
    for (size_t i = 0; i < tokenItems.size(); ++i) {
        const auto& ti = tokenItems[i];
        
        if (ti.type == TokenType::NoteWithControl) {
            long durGrids = 1;
            std::vector<std::pair<OpType, long>> triggers;
            
            if (ti.hasGlideOp) triggers.push_back({OpType::Glide, 0});
            if (ti.hasAmpGlideOp) triggers.push_back({OpType::AmpGlide, 0});
            if (ti.hasVibratoOp) triggers.push_back({OpType::Vibrato, 0});

            size_t j = i + 1;
            while (j < tokenItems.size() && tokenItems[j].type == TokenType::ContinuityDot) {
                if (tokenItems[j].hasGlideOp) {
                    triggers.push_back({OpType::Glide, durGrids});
                }
                if (tokenItems[j].hasAmpGlideOp) {
                    triggers.push_back({OpType::AmpGlide, durGrids});
                }
                if (tokenItems[j].hasVibratoOp) {
                    triggers.push_back({OpType::Vibrato, durGrids});
                }
                durGrids++;
                j++;
            }
            long durationSamples = (long)(durGrids * samplesPerGrid);
            long sampleOffset = (long)(ti.gridIndex * samplesPerGrid);
            float amplitudeScalar = (float)ti.controlParam / 9.0f;

            if (seq.notation == "XSAMPA" || seq.notation == "xsampa" || seq.notation == "Xsampa") {
                handleXSampaToken(ti, sampleOffset, durationSamples, j, tokenItems, seq.events, sampleRate);
            } else if (ti.hasCompositeNotes) {
                handleCompositeNote(ti, sampleOffset, durationSamples, seq.notation, seq.baseFreq, seq.instrument, j, tokenItems, samplesPerGrid, sampleRate, seq.events);
            } else if (InstrumentMapper::isPercussionID(seq.instrumentID)) {
                handlePercussionToken(ti.noteName, amplitudeScalar, sampleOffset, durationSamples, seq.notation, seq.baseFreq, seq.instrument, seq.events, ti.strikeVal);
            } else {
                handlePitchedToken(ti, amplitudeScalar, sampleOffset, durationSamples, seq.notation, seq.baseFreq, seq.instrument, samplesPerGrid, sampleRate, j, tokenItems, triggers, seq.events);
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

    // Apply delay offset: shift all events and total duration
    if (seq.delaySec > 0.0) {
        long delaySamples = (long)(seq.delaySec * sampleRate);
        for (auto& ev : seq.events) {
            ev.sampleOffset += delaySamples;
        }
        seq.totalDurationSamples += delaySamples;
    }

    // Parsed events dump complete
    return seq;
}

void UMLParser::handlePercussionToken(const std::string& tokenNoteName, float amplitudeScalar, long sampleOffset, long durationSamples, const std::string& notation, double baseFreq, const std::string& instrument, std::vector<UMLEvent>& outEvents, float strikeValFromPrefix) {
    UMLEvent ev; 
    ev.sampleOffset = sampleOffset;
    ev.frequency = static_cast<float>(baseFreq);
    ev.velocity = -1.0f;
    ev.amplitude = amplitudeScalar;
    ev.type = UMLEventType::NoteOn;
    ev.note = tokenNoteName;
    ev.durationSamples = durationSamples;

    int instID = InstrumentMapper::getIDFromName(instrument);
    if (instID == 0) {
        if (tokenNoteName == "Na" || tokenNoteName == "Ta" || tokenNoteName == "na" || tokenNoteName == "ta") ev.strikeVal = 0.0f;
        else if (tokenNoteName == "tk") ev.strikeVal = 1.0f;
        else if (tokenNoteName == "Tin" || tokenNoteName == "Ti" || tokenNoteName == "tin" || tokenNoteName == "ti") ev.strikeVal = 2.0f;
        else if (tokenNoteName == "Tun" || tokenNoteName == "Tu" || tokenNoteName == "tun" || tokenNoteName == "tu") ev.strikeVal = 3.0f;
        else if (tokenNoteName == "Dha" || tokenNoteName == "dha") ev.strikeVal = 0.0f;
        else if (tokenNoteName == "Dhin" || tokenNoteName == "dhin") ev.strikeVal = 2.0f;
        else if (tokenNoteName == "Tit" || tokenNoteName == "tit") ev.strikeVal = 1.0f;
    } else if (instID == 1) {
        if (bayanBols.count(tokenNoteName)) {
            ev.strikeVal = static_cast<float>(bayanBols.at(tokenNoteName));
        } else {
            if (tokenNoteName == "Ka" || tokenNoteName == "ka") ev.strikeVal = 0.0f;
            else if (tokenNoteName == "Ghe" || tokenNoteName == "ghe") ev.strikeVal = 1.0f;
            else if (tokenNoteName == "Ghi" || tokenNoteName == "ghi") ev.strikeVal = 2.0f;
            else if (tokenNoteName == "Ke" || tokenNoteName == "ke") ev.strikeVal = 3.0f;
        }
    } else if (instID == 28 || instID == 30 || instID == 31) {
        if (africanDrumBols.count(tokenNoteName)) {
            ev.strikeVal = static_cast<float>(africanDrumBols.at(tokenNoteName));
        } else if (percussionBols.count(tokenNoteName)) {
            ev.strikeVal = static_cast<float>(percussionBols.at(tokenNoteName));
        }
    } else if (instID == 37) {
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

        if (isComposite) ev.strikeVal = 4.0f;
        else if (isOpenBass) ev.strikeVal = 0.0f;
        else if (isClosedBass) ev.strikeVal = 1.0f;
        else if (isOpenTreble) ev.strikeVal = 2.0f;
        else if (isClosedTreble) ev.strikeVal = 3.0f;
        else ev.strikeVal = 0.0f;
    } else if (instID == 38) {
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

        if (isComposite) ev.strikeVal = 4.0f;
        else if (isOpenBass) ev.strikeVal = 0.0f;
        else if (isClosedBass) ev.strikeVal = 1.0f;
        else if (isOpenTreble) ev.strikeVal = 2.0f;
        else if (isClosedTreble) ev.strikeVal = 3.0f;
        else ev.strikeVal = 0.0f;
    } else if (instID == 49 || instID == 50) {
        ev.frequency = static_cast<float>(baseFreq);
        std::string lowerNote = tokenNoteName;
        std::transform(lowerNote.begin(), lowerNote.end(), lowerNote.begin(), ::tolower);
        
        if (notation == "konnakol" || notation == "Konnakol") {
            if (instID == 49) { // Mridangam
                if (lowerNote == "tha") ev.strikeVal = 0.0f;
                else if (lowerNote == "thom") ev.strikeVal = 1.0f;
                else if (lowerNote == "chapu") ev.strikeVal = 2.0f;
                else if (lowerNote == "nam") ev.strikeVal = 3.0f;
                else if (lowerNote == "dhi") ev.strikeVal = 4.0f;
                else if (lowerNote == "ta") ev.strikeVal = 5.0f;
                else ev.strikeVal = 2.0f; // default to chapu
            } else if (instID == 50) { // Ghatam
                if (lowerNote == "tha") ev.strikeVal = 0.0f;
                else if (lowerNote == "dhi") ev.strikeVal = 1.0f;
                else if (lowerNote == "thom") ev.strikeVal = 2.0f;
                else if (lowerNote == "nam") ev.strikeVal = 3.0f;
                else if (lowerNote == "gumki") ev.strikeVal = 4.0f;
                else ev.strikeVal = 0.0f; // default to tha
            }
        } else {
            // fallback x/X<strike>
            if (!lowerNote.empty() && lowerNote[0] == 'x') {
                if (lowerNote.length() > 1) {
                    try {
                        ev.strikeVal = static_cast<float>(std::stoi(lowerNote.substr(1)));
                    } catch (...) {
                        ev.strikeVal = 0.0f;
                    }
                } else {
                    ev.strikeVal = 0.0f;
                }
            } else {
                ev.strikeVal = 0.0f;
            }
        }
    } else if (instID == 47 || instID == 8 || instID == 7) {
        ev.frequency = static_cast<float>(baseFreq);
        
        if (!tokenNoteName.empty() && (tokenNoteName[0] == 'X' || tokenNoteName[0] == 'x')) {
            // Format: [Amplitude][StrikeVal]X — strikeVal from prefix, no suffix on X
            // 0=mallet (default), 1=rub/bow. Direct passthrough to DSP.
            ev.strikeVal = (strikeValFromPrefix >= 0.0f) ? strikeValFromPrefix : 0.0f;
        } else if (tokenNoteName == "s" || tokenNoteName == "S" || tokenNoteName == "strike" || tokenNoteName == "Strike") {
            ev.strikeVal = 0.0f; // mallet
        } else if (tokenNoteName == "r" || tokenNoteName == "R" || tokenNoteName == "rub" || tokenNoteName == "Rub") {
            ev.strikeVal = 1.0f; // rub
        } else {
            ev.strikeVal = 0.0f; // default mallet
        }
    } else if (percussionBols.count(tokenNoteName)) {
        ev.strikeVal = static_cast<float>(percussionBols.at(tokenNoteName));
    }

    outEvents.push_back(ev);
}

void UMLParser::handlePitchedToken(const TokenItem& ti, float amplitudeScalar, long sampleOffset, long durationSamples, 
                                   const std::string& notation, double baseFreq, const std::string& instrument,
                                   double samplesPerGrid, double sampleRate, size_t nextTokenIndex, 
                                   const std::vector<TokenItem>& tokenItemsArray, 
                                   const std::vector<std::pair<OpType, long>>& triggers, std::vector<UMLEvent>& outEvents) {
    
    std::vector<std::string> notes;
    std::stringstream ss(ti.noteName);
    std::string item;
    while (std::getline(ss, item, '|')) {
        notes.push_back(item);
    }

    if (notes.empty()) return;

    for (const auto& noteStr : notes) {
        float freq = static_cast<float>(getFrequency(noteStr, notation, baseFreq, instrument));
        
        if (!ti.isGlideTarget) {
            UMLEvent noteEv;
            noteEv.sampleOffset = sampleOffset;
            noteEv.frequency = freq;
            noteEv.velocity = -1.0f; // Reserved for later use per user
            noteEv.amplitude = amplitudeScalar;
            noteEv.strikeVal = ti.strikeVal;
            noteEv.type = UMLEventType::NoteOn;
            noteEv.note = noteStr;
            noteEv.durationSamples = durationSamples;
            outEvents.push_back(noteEv);
        }
    }

    bool hasGlide = false;
    for (const auto& trigger : triggers) {
        long triggerOffset = sampleOffset + (long)(trigger.second * samplesPerGrid);
        
        if (trigger.first == OpType::Vibrato) {
            UMLEvent vibEv;
            vibEv.sampleOffset = triggerOffset;
            vibEv.type = UMLEventType::VibratoOn;
            outEvents.push_back(vibEv);
        } else if (trigger.first == OpType::Glide) {
            hasGlide = true;
            size_t targetIdx = nextTokenIndex;
            while (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type != TokenType::NoteWithControl) {
                targetIdx++;
            }
            if (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type == TokenType::NoteWithControl) {
                std::string tNote = tokenItemsArray[targetIdx].noteName;
                float tFreq = (float)getFrequency(tNote, notation, baseFreq, instrument);
                float tVel = (float)tokenItemsArray[targetIdx].controlParam / 9.0f;
                
                // FreqGlide: ramp pitch to next note
                {
                    UMLEvent fg;
                    fg.sampleOffset = triggerOffset;
                    fg.type = UMLEventType::FreqGlide;
                    fg.targetFrequency = tFreq;
                    fg.durationSamples = (sampleOffset + durationSamples) - triggerOffset;
                    outEvents.push_back(fg);
                }
                // AmpGlide: ramp amplitude to next note
                {
                    UMLEvent ag;
                    ag.sampleOffset = triggerOffset;
                    ag.type = UMLEventType::AmpGlide;
                    ag.targetAmplitude = tVel;
                    ag.durationSamples = (sampleOffset + durationSamples) - triggerOffset;
                    outEvents.push_back(ag);
                }
            }
        } else if (trigger.first == OpType::AmpGlide) {
            hasGlide = true;
            size_t targetIdx = nextTokenIndex;
            while (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type != TokenType::NoteWithControl) {
                targetIdx++;
            }
            if (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type == TokenType::NoteWithControl) {
                float tVel = (float)tokenItemsArray[targetIdx].controlParam / 9.0f;
                
                UMLEvent ag;
                ag.sampleOffset = triggerOffset;
                ag.type = UMLEventType::AmpGlide;
                ag.targetAmplitude = tVel;
                ag.durationSamples = (sampleOffset + durationSamples) - triggerOffset;
                outEvents.push_back(ag);
            }
        }
    }

    // If no glide is present, schedule a NoteOff event.
    // Fire early if next token is another note for smooth release decay before noteOn.
    if (!hasGlide) {
        bool nextIsNote = (nextTokenIndex < tokenItemsArray.size() && 
                           tokenItemsArray[nextTokenIndex].type == TokenType::NoteWithControl);
        long lookAhead = 0;
        if (nextIsNote) {
            long maxLA = (long)(0.03 * sampleRate);
            long minLA = (long)(0.002 * sampleRate);
            long propLA = durationSamples / 10;
            lookAhead = std::max(std::min(propLA, maxLA), minLA);
        }
        long offOffset = sampleOffset + durationSamples - lookAhead;
        if (offOffset <= sampleOffset) offOffset = sampleOffset + 1;
        UMLEvent offEv;
        offEv.sampleOffset = offOffset;
        offEv.type = UMLEventType::NoteOff;
        outEvents.push_back(offEv);
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
        i++;
    }
    
    // If any characters remain unparsed, the token is invalid
    if (i < token.length()) return 0.0;
    
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
        return baseFreq;
    }

    // 2. Parse optional *N or /N octave multiplier/divider suffix
    // e.g. "Sa*2" = Sa one octave up, "n2/2" = Komal Ni one octave down
    std::string baseToken = token;
    double octaveScale = 1.0;
    size_t starPos = token.rfind('*');
    size_t slashPos = token.rfind('/');
    if (starPos != std::string::npos && starPos > 0) {
        std::string scalePart = token.substr(starPos + 1);
        try {
            double s = std::stod(scalePart);
            if (s > 0.0) { octaveScale = s; baseToken = token.substr(0, starPos); }
        } catch (...) {}
    } else if (slashPos != std::string::npos && slashPos > 0) {
        std::string scalePart = token.substr(slashPos + 1);
        try {
            double s = std::stod(scalePart);
            if (s > 0.0) { octaveScale = 1.0 / s; baseToken = token.substr(0, slashPos); }
        } catch (...) {}
    }

    // 3. Melodic Check on base token
    if (notation == "22Shruti" || notation == "22shruti" || notation == "Indian" || notation == "indian") {
        if (shruti22Ratios.count(baseToken)) return baseFreq * shruti22Ratios.at(baseToken) * octaveScale;
    } else if (notation == "Hindustani" || notation == "hindustani" || notation == "Sargam" || notation == "sargam") {
        if (hindustaniRatios.count(baseToken)) return baseFreq * hindustaniRatios.at(baseToken) * octaveScale;
        if (shruti22Ratios.count(baseToken)) return baseFreq * shruti22Ratios.at(baseToken) * octaveScale;
    } else {
        if (westernPitches.count(baseToken)) return westernPitches.at(baseToken) * octaveScale;
        double parsed = parseWesternPitch(baseToken);
        if (parsed > 0.0) return parsed * octaveScale;
    }
    return baseFreq * octaveScale;
}



void UMLParser::handleXSampaToken(const TokenItem& ti, long sampleOffset, long durationSamples, size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray, std::vector<UMLEvent>& outEvents, double sampleRate) {
    UMLEvent ev;
    ev.sampleOffset   = sampleOffset;
    ev.type           = UMLEventType::PhonemeOn;
    ev.note           = ti.noteName;
    ev.durationSamples = durationSamples;
    outEvents.push_back(ev);

    size_t targetIdx = nextTokenIndex;
    while (targetIdx < tokenItemsArray.size() &&
           (tokenItemsArray[targetIdx].type == TokenType::ContinuityDot ||
            tokenItemsArray[targetIdx].type == TokenType::StopRest)) {
        targetIdx++;
    }

    if (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type == TokenType::NoteWithControl) {
        const std::string& nextTok = tokenItemsArray[targetIdx].noteName;
        
        UMLEvent pg;
        pg.type = UMLEventType::PhonemeGlide;
        pg.targetNote = nextTok;

        if (ti.hasGlideOp) {
            // Explicit glide: span the entire bridge
            pg.sampleOffset = sampleOffset; 
            pg.durationSamples = durationSamples;
        } else {
            // Implicit boundary: 100ms glide at the end of the note
            long glideLen = static_cast<long>(0.100 * sampleRate); // 100ms
            if (glideLen > durationSamples) glideLen = durationSamples;
            
            pg.sampleOffset = sampleOffset + durationSamples - glideLen;
            pg.durationSamples = glideLen;
        }
        outEvents.push_back(pg);
    }
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

    // Glide support: if the token ends with '^', emit explicit glide events
    if (ti.hasGlideOp) {
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
            
            // Emit Freq and Amp glides
            if (std::abs(tFreq - ev.frequency) > 0.01f || std::abs(tVel - amplitudeScalar) > 0.01f) {
                UMLEvent fg;
                fg.sampleOffset     = sampleOffset;
                fg.type             = UMLEventType::FreqGlide;
                fg.targetFrequency  = tFreq;
                fg.durationSamples  = durationSamples;
                outEvents.push_back(fg);

                UMLEvent ag;
                ag.sampleOffset     = sampleOffset;
                ag.type             = UMLEventType::AmpGlide;
                ag.targetAmplitude  = tVel;
                ag.durationSamples  = durationSamples;
                outEvents.push_back(ag);
            }

            // It's an explicit ^ transition.
            UMLEvent pg;
            pg.sampleOffset = sampleOffset; // starts at the boundary or end of dots
            pg.type = UMLEventType::PhonemeGlide;
            pg.targetNote = nextTok;
            pg.durationSamples = durationSamples; // duration of the dot(s) holding the ^
            outEvents.push_back(pg);
        }
    } else {
        // Automatic boundary smoothing (100ms Biological limit)
        // Check if the NEXT token immediately follows (no dots between) and is a NoteWithControl
        if (nextTokenIndex < tokenItemsArray.size() && tokenItemsArray[nextTokenIndex].type == TokenType::NoteWithControl) {
            const std::string& nextTok = tokenItemsArray[nextTokenIndex].noteName;
            // Biological Anticipation Limit: 100ms
            long autoGlideSamples100ms = 4410; // Assume 44.1kHz for now
            long pgOffset = sampleOffset + durationSamples - autoGlideSamples100ms;
            if (pgOffset < sampleOffset) pgOffset = sampleOffset; // limit to current note start

            UMLEvent pg;
            pg.sampleOffset = pgOffset;
            pg.type = UMLEventType::PhonemeGlide;
            pg.targetNote = nextTok;
            pg.durationSamples = autoGlideSamples100ms;
            outEvents.push_back(pg);
        }
    }
    // Amp-only glide: if the token has '>', emit AmpGlide event
    if (ti.hasAmpGlideOp) {
        size_t targetIdx = nextTokenIndex;
        while (targetIdx < tokenItemsArray.size() &&
               (tokenItemsArray[targetIdx].type == TokenType::ContinuityDot ||
                tokenItemsArray[targetIdx].type == TokenType::StopRest)) {
            targetIdx++;
        }
        if (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type == TokenType::NoteWithControl) {
            float tVel = static_cast<float>(tokenItemsArray[targetIdx].controlParam) / 9.0f;
            if (std::abs(tVel - amplitudeScalar) > 0.01f) {
                UMLEvent ag;
                ag.sampleOffset     = sampleOffset;
                ag.type             = UMLEventType::AmpGlide;
                ag.targetAmplitude  = tVel;
                ag.durationSamples  = durationSamples;
                outEvents.push_back(ag);
            }
        }
    }
}

void UMLParser::handleCompositeNote(const TokenItem& ti, long sampleOffset, long durationSamples,
                                    const std::string& notation, double baseFreq, const std::string& instrument,
                                    size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray,
                                    double samplesPerGrid, double sampleRate, std::vector<UMLEvent>& outEvents) {
    std::vector<std::string> subNotes;
    std::stringstream ss(ti.noteName);
    std::string item;
    while (std::getline(ss, item, ',')) {
        subNotes.push_back(item);
    }
    if (subNotes.empty()) return;

    for (const auto& subNote : subNotes) {
        std::string rem = subNote;
        int subControl = 5;
        float subStrike = 0.0f;

        if (rem.length() > 2 && std::isdigit(rem[0]) && std::isdigit(rem[1]) && !std::isdigit(rem[2])) {
            subControl = rem[0] - '0';
            subStrike = static_cast<float>(rem[1] - '0');
            rem = rem.substr(2);
        } else if (rem.length() > 1 && std::isdigit(rem[0]) && !std::isdigit(rem[1])) {
            subControl = rem[0] - '0';
            rem = rem.substr(1);
        }

        float freq = static_cast<float>(getFrequency(rem, notation, baseFreq, instrument));
        float amp = static_cast<float>(subControl) / 9.0f;

        UMLEvent noteEv;
        noteEv.sampleOffset = sampleOffset;
        noteEv.frequency = freq;
        noteEv.velocity = -1.0f;
        noteEv.amplitude = amp;
        noteEv.strikeVal = subStrike;
        noteEv.type = UMLEventType::NoteOn;
        noteEv.note = subNote;
        noteEv.durationSamples = durationSamples;
        outEvents.push_back(noteEv);
    }

    bool nextIsNote = (nextTokenIndex < tokenItemsArray.size() &&
                       tokenItemsArray[nextTokenIndex].type == TokenType::NoteWithControl);
    long lookAhead = 0;
    if (nextIsNote) {
        long maxLA = (long)(0.03 * sampleRate);
        long minLA = (long)(0.002 * sampleRate);
        long propLA = durationSamples / 10;
        lookAhead = std::max(std::min(propLA, maxLA), minLA);
    }
    long offOffset = sampleOffset + durationSamples - lookAhead;
    if (offOffset <= sampleOffset) offOffset = sampleOffset + 1;
    UMLEvent offEv;
    offEv.sampleOffset = offOffset;
    offEv.type = UMLEventType::NoteOff;
    outEvents.push_back(offEv);
}
