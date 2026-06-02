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
        case 15: return "TR";
        case 16: return "SH";
        case 17: return "BN";
        case 18: return "VI";
        case 19: return "RM";
        case 20: return "CH";
        case 21: return "AG";
        case 22: return "EG";
        case 23: return "BS";
        case 24: return "CE";
        case 25: return "CR";
        case 26: return "CU";
        case 27: return "WF";
        case 28: return "DJ";
        case 29: return "MA";
        case 30: return "CG";
        case 31: return "BG";
        case 32: return "VO";
        case 33: return "SK";
        case 34: return "SW";
        case 35: return "CG"; // Chou Gong
        case 36: return "LN"; // Lag Nga
        case 37: return "DK"; // Dholak
        case 38: return "DH"; // Dhol
        case 48: return "NC"; // Ngachen
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
    if (lowerName == "tr" || lowerName == "trumpet") return 15;
    if (lowerName == "sh" || lowerName == "shakuhachi") return 16;
    if (lowerName == "bn" || lowerName == "bansuri") return 17;
    if (lowerName == "vi" || lowerName == "violin") return 18;
    if (lowerName == "rm" || lowerName == "rainmaker") return 19;
    if (lowerName == "ch" || lowerName == "churchbell") return 20;
    if (lowerName == "ag" || lowerName == "acousticguitar" || lowerName == "acoustic_guitar") return 21;
    if (lowerName == "eg" || lowerName == "electricguitar" || lowerName == "electric_guitar") return 22;
    if (lowerName == "bs" || lowerName == "bass" || lowerName == "bassguitar" || lowerName == "bass_guitar") return 23;
    if (lowerName == "ce" || lowerName == "cello") return 24;
    if (lowerName == "cr" || lowerName == "cricket") return 25;
    if (lowerName == "cu" || lowerName == "cuckoo") return 26;
    if (lowerName == "wf" || lowerName == "waterfall") return 27;
    if (lowerName == "dj" || lowerName == "djembe") return 28;
    if (lowerName == "ma" || lowerName == "marimba") return 29;
    if (lowerName == "cg" || lowerName == "conga") return 30;
    if (lowerName == "bg" || lowerName == "bongo" || lowerName == "bonga") return 31;
    if (lowerName == "vo" || lowerName == "voice" || lowerName == "vocals" || lowerName == "singing") return 32;
    if (lowerName == "sk" || lowerName == "shaker") return 33;
    if (lowerName == "sw" || lowerName == "seawave" || lowerName == "wave" || lowerName == "ocean") return 34;
    if (lowerName == "chougong" || lowerName == "chou_gong" || lowerName == "gong") return 35;
    if (lowerName == "ln" || lowerName == "lagnga" || lowerName == "lag_nga" || lowerName == "lag nga") return 36;
    if (lowerName == "dk" || lowerName == "dholak") return 37;
    if (lowerName == "dh" || lowerName == "dhol") return 38;
    if (lowerName == "tb" || lowerName == "tibetanbowl" || lowerName == "tibetan_bowl") return 47;
    if (lowerName == "nc" || lowerName == "ngachen" || lowerName == "nga_chen" || lowerName == "nga chen") return 48;

    return -1;
}

bool InstrumentMapper::isPercussionID(int id) {
    return isMembraneophone(id) || isIdiophone(id);
}

bool InstrumentMapper::isMembraneophone(int id) {
    return id == 0 || id == 1 || id == 2 || id == 3 || id == 5
        || id == 28 || id == 30 || id == 31 || id == 36 || id == 37
        || id == 38 || id == 48;
}

bool InstrumentMapper::isIdiophone(int id) {
    return id == 4 || id == 6 || id == 7 || id == 8 || id == 14
        || id == 20 || id == 29 || id == 33 || id == 35 || id == 47;
}

int InstrumentMapper::getPolyphonyVoices(int id) {
    switch (id) {
        case 12: return 6; // Piano
        case 21: return 6; // Acoustic Guitar
        case 22: return 6; // Electric Guitar
        case 23: return 4; // Bass
        default: return 1; // Monophonic by default
    }
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
        case 15: return base + "trumpet.dsp";
        case 16: return base + "shakuhachi.dsp";
        case 17: return base + "bansuri.dsp";
        case 18: return base + "violin.dsp";
        case 19: return base + "rainmaker.dsp";
        case 20: return base + "churchbell.dsp";
        case 21: return base + "acoustic_guitar.dsp";
        case 22: return base + "electric_guitar.dsp";
        case 23: return base + "bass.dsp";
        case 24: return base + "cello.dsp";
        case 25: return base + "cricket.dsp";
        case 26: return base + "cuckoo.dsp";
        case 27: return base + "waterfall.dsp";
        case 28: return base + "djembe.dsp";
        case 29: return base + "marimba.dsp";
        case 30: return base + "conga.dsp";
        case 31: return base + "bongo.dsp";
        case 32: return base + "voice.dsp";
        case 33: return base + "shaker.dsp";
        case 34: return base + "seawave.dsp";
        case 35: return base + "chougong.dsp";
        case 36: return base + "lagnga.dsp";
        case 37: return base + "dholak.dsp";
        case 38: return base + "dhol.dsp";
        case 47: return base + "tibetanbowl.dsp";
        case 48: return base + "ngachen.dsp";
        default: return base + "dayan.dsp";
    }
}
