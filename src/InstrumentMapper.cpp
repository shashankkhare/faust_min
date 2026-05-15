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
 * @file InstrumentMapper.cpp
 * @brief Implementation file for InstrumentMapper
 * 
 * DESIGN: Factory utility that maps UML instrument identifiers to concrete C++ classes. It ensures that the orchestrator can instantiate instruments without direct coupling.
 */

#include "InstrumentMapper.hpp"
#include <algorithm>

constexpr float InstrumentMapper::DEFAULT_SAMPLE_RATE;
constexpr int InstrumentMapper::MAX_INSTRUMENTS;
constexpr int InstrumentMapper::MAX_FRAMES_PER_BUFFER;

std::string InstrumentMapper::getNameFromID(int id) {
    switch (id) {
        case 0:  return "DA";
        case 1:  return "BA";
        case 2:  return "kick";
        case 3:  return "snare";
        case 4:  return "hihat";
        case 5:  return "tom";
        case 6:  return "ride";
        case 7:  return "BE";
        case 8:  return "BO";
        case 9:  return "SI";
        case 10: return "FL";
        case 11: return "TA";
        case 12: return "PI";
        case 13: return "SX";
        case 14: return "CB";
        default: return "DA";
    }
}

int InstrumentMapper::getIDFromName(const std::string& name) {
    if (name.empty()) return -1;
    
    // Support direct numeric string checks
    if (std::all_of(name.begin(), name.end(), ::isdigit)) {
        return std::stoi(name);
    }

    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    if (lowerName == "da" || lowerName == "dy" || lowerName == "dayan") return 0;
    if (lowerName == "ba" || lowerName == "bayan") return 1;
    if (lowerName == "kick") return 2;
    if (lowerName == "snare") return 3;
    if (lowerName == "hihat") return 4;
    if (lowerName == "tom") return 5;
    if (lowerName == "ride") return 6;
    if (lowerName == "be" || lowerName == "bell") return 7;
    if (lowerName == "bo" || lowerName == "bowl") return 8;
    if (lowerName == "si" || lowerName == "sitar") return 9;
    if (lowerName == "fl" || lowerName == "flute") return 10;
    if (lowerName == "ta" || lowerName == "tanpura") return 11;
    if (lowerName == "pi" || lowerName == "piano") return 12;
    if (lowerName == "sx" || lowerName == "sax") return 13;
    if (lowerName == "cb" || lowerName == "cowbell") return 14;

    return -1;
}

bool InstrumentMapper::isPercussionID(int id) {
    // Drum nodes map sequentially from 0 (Dayan) through 6 (Ride)
    return (id >= 0 && id <= 6);
}

std::string InstrumentMapper::getDSPPathForID(int id, const std::string& assetBasePath) {
    std::string base = assetBasePath.empty() ? DEFAULT_DSP_DIR : (assetBasePath + "/dsp/");
    switch (id) {
        case 0:  return base + "dayan.dsp";
        case 1:  return base + "bayan.dsp";
        case 2:  return base + "kick.dsp";
        case 3:  return base + "snare.dsp";
        case 4:  return base + "hihat.dsp";
        case 5:  return base + "tom.dsp";
        case 6:  return base + "ride.dsp";
        case 7:  return base + "bell.dsp";
        case 8:  return base + "bowl.dsp";
        case 9:  return base + "sitar.dsp";
        case 10: return base + "flute.dsp";
        case 11: return base + "tanpura.dsp";
        case 12: return base + "piano.dsp";
        case 13: return base + "sax.dsp";
        case 14: return base + "cowbell.dsp";
        default: return base + "dayan.dsp";
    }
}
