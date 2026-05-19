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

const std::map<std::string, double> UMLParser::westernPitches = {
    {"C4", 261.63}, {"C#", 277.18}, {"Db", 277.18}, {"D4", 293.66}
    // Add more western pitches as needed
};

UMLSequence UMLParser::parse(const std::string& name, const std::string& input, double sampleRate, double defaultBaseFreq) {
    UMLSequence seq;
    seq.name = name;
    seq.baseFreq = defaultBaseFreq;
    
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

            if (InstrumentMapper::isPercussionID(mappedInstID)) {
                handlePercussionToken(ti.noteName, vel, sampleOffset, calculatedDurationSamples, seq.baseFreq, seq.instrument, seq.events);
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

void UMLParser::handlePercussionToken(const std::string& tokenNoteName, float velocityScalar, long sampleOffset, long durationSamples, double baseFreq, const std::string& instrument, std::vector<UMLEvent>& outEvents) {
    // Percussion instances utilize unpitched triggering mechanics where note string defines stroke style.
    // The frequency is inherited from the sequence base frequency.
    UMLEvent ev; 
    ev.sampleOffset = sampleOffset;
    ev.frequency = static_cast<float>(baseFreq);
    ev.velocity = velocityScalar;
    ev.type = UMLEventType::NoteOn;
    ev.note = tokenNoteName;
    ev.durationSamples = durationSamples;

    // Pre-calculate strikeVal based on instrument and note
    int instID = InstrumentMapper::getIDFromName(instrument);
    if (instID == 0) { // Dayan
        if (tokenNoteName == "Na" || tokenNoteName == "Ta" || tokenNoteName == "na" || tokenNoteName == "ta") ev.strikeVal = 0.0f;
        else if (tokenNoteName == "tk") ev.strikeVal = 1.0f;
        else if (tokenNoteName == "Tin" || tokenNoteName == "Ti" || tokenNoteName == "tin" || tokenNoteName == "ti") ev.strikeVal = 2.0f;
        else if (tokenNoteName == "Tun" || tokenNoteName == "Tu" || tokenNoteName == "tun" || tokenNoteName == "tu") ev.strikeVal = 3.0f;
    } else if (instID == 1) { // Bayan
        if (tokenNoteName == "Ka" || tokenNoteName == "ka") ev.strikeVal = 0.0f;
        else if (tokenNoteName == "Ghe" || tokenNoteName == "ghe") ev.strikeVal = 1.0f;
        else if (tokenNoteName == "Ghi" || tokenNoteName == "ghi") ev.strikeVal = 2.0f;
        else if (tokenNoteName == "Ke" || tokenNoteName == "ke") ev.strikeVal = 3.0f;
    } else if (percussionBols.count(tokenNoteName)) {
        ev.strikeVal = static_cast<float>(percussionBols.at(tokenNoteName));
    }

    outEvents.push_back(ev);
}

void UMLParser::handlePitchedToken(const TokenItem& ti, float velocityScalar, long sampleOffset, long durationSamples, 
                                   const std::string& notation, double baseFreq, const std::string& instrument,
                                   double samplesPerGrid, size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray, std::vector<UMLEvent>& outEvents) {
    float freq = static_cast<float>(getFrequency(ti.noteName, notation, baseFreq, instrument));
    
    UMLEvent noteEv;
    noteEv.sampleOffset = sampleOffset;
    noteEv.frequency = freq;
    noteEv.velocity = velocityScalar;
    noteEv.type = UMLEventType::NoteOn;
    noteEv.note = ti.noteName;
    noteEv.durationSamples = durationSamples;
    outEvents.push_back(noteEv);

    // Execute automated glides targeting next standalone operational pitch boundary
    if (ti.hasGlide) {
        size_t targetIdx = nextTokenIndex;
        while (targetIdx < tokenItemsArray.size() && (tokenItemsArray[targetIdx].type == TokenType::ContinuityDot || tokenItemsArray[targetIdx].type == TokenType::StopRest)) {
            targetIdx++;
        }
        if (targetIdx < tokenItemsArray.size() && tokenItemsArray[targetIdx].type == TokenType::NoteWithControl) {
            float tFreq = (float)getFrequency(tokenItemsArray[targetIdx].noteName, notation, baseFreq, instrument);
            float tVel = (float)tokenItemsArray[targetIdx].controlParam / 9.0f;
            
            // Enforce lookahead constraint: glide triggers ONLY if target frequency or velocity differs
            if (std::abs(tFreq - freq) > 0.01f || std::abs(tVel - velocityScalar) > 0.01f) {
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
    }
    return baseFreq;
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
