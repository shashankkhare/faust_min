#include "UMLParser.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>

const std::map<std::string, double> UMLParser::indianRatios = {
    {"SaLow", 0.5}, {"Sa", 1.0}, 
    {"r1", 256.0/243.0}, {"r2", 16.0/15.0}, {"R1", 10.0/9.0}, {"R2", 9.0/8.0}, {"Re", 9.0/8.0},
    {"g1", 32.0/27.0}, {"g2", 6.0/5.0}, {"G1", 5.0/4.0}, {"G2", 81.0/64.0}, {"Ga", 5.0/4.0},
    {"M1", 4.0/3.0}, {"M2", 27.0/20.0}, {"m1", 45.0/32.0}, {"m2", 64.0/45.0}, {"Ma", 4.0/3.0},
    {"Pa", 1.5},
    {"d1", 128.0/81.0}, {"d2", 8.0/5.0}, {"D1", 5.0/3.0}, {"D2", 27.0/16.0}, {"Dh", 5.0/3.0},
    {"n1", 16.0/9.0}, {"n2", 9.0/5.0}, {"N1", 15.0/8.0}, {"N2", 243.0/128.0}, {"Ni", 15.0/8.0}
};

const std::map<std::string, double> UMLParser::percussionBols = {
    {"Ta", 1.0}, {"Na", 1.0}, // Dayan Rim
    {"Dh", 2.0}, {"Di", 2.0}, // Dayan White/Open
    {"Ge", 3.0}, {"Ka", 4.0}, // Bayan Bass/Closed
    {"Ti", 5.0}, {"Te", 6.0}  // Center/Muted
};

const std::map<std::string, double> UMLParser::westernPitches = {
    {"C4", 261.63}, {"C#", 277.18}, {"Db", 277.18}, {"D4", 293.66}
    // Add more western pitches as needed
};

UMLSequence UMLParser::parse(const std::string& name, const std::string& input, double sampleRate) {
    UMLSequence seq;
    seq.name = name;
    
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
            else if (key == "basefreq") seq.baseFreq = std::stod(val);
            else if (key == "bpm") seq.bpm = std::stod(val);
            else if (key == "grid") grid = std::stoi(val);
            else if (key == "instrument") {
                // Split for params: instrument: FL (pressure=0.8)
                auto p_start = val.find('(');
                if (p_start != std::string::npos) {
                    seq.instrument = val.substr(0, p_start);
                } else {
                    seq.instrument = val;
                }
            }
            else if (key == "0") { if (seq.instrument.empty()) seq.instrument = "DA"; }
            else if (key == "1") { if (seq.instrument.empty()) seq.instrument = "BA"; }
            else if (key == "gain") seq.gain = std::stod(val);
        } else {
            notesSection += line;
        }
    }

    double samplesPerGrid = (60.0 / seq.bpm) * sampleRate / grid;

    // --- Pass 2: Tokenization & Glide Resolution ---
    struct RawToken {
        int velocity;
        std::string note;
        char articulation; // '.', '_', '^'
        long gridOffset;
    };

    std::vector<RawToken> rawTokens;
    long currentGrid = 0;
    
    for (size_t i = 0; i < notesSection.length(); ) {
        char c = notesSection[i];
        if (isspace(c)) { i++; continue; }

        RawToken rt;
        rt.gridOffset = currentGrid;
        rt.velocity = 5; // Default

        if (isdigit(c)) {
            // Velocity prefix
            rt.velocity = c - '0';
            i++;
        }

        // Read note until next articulation (. _ ^) or space
        // We only stop at digits if we haven't started a note yet or if it's a velocity prefix
        // Actually, the simplest rule: read until grid marker or space. 
        // If there's a digit inside, it's part of the note.
        size_t start = i;
        while (i < notesSection.length() && 
               notesSection[i] != '.' && 
               notesSection[i] != '_' && 
               notesSection[i] != '^' && 
               !isspace(notesSection[i])) {
            // Check if this digit is actually a velocity for the NEXT note.
            // In UML, velocity is always followed by a note or grid? 
            // Actually, let's look for the next Note-Velocity pair.
            // For now, let's assume notes don't start with digits unless they are numeric frequencies.
            // If it's a numeric frequency, it will be handled by the numeric check.
            if (isdigit(notesSection[i])) {
                // If the next char is ALSO a digit or a note letter, then this MIGHT be a velocity.
                // But wait, the user said "note is the frequency". 
                // 9200.5 -> 9 is vel, 200.5 is note.
                // If we hit another digit, it might be part of the frequency.
                
                // Let's use a simpler heuristic: notes stop at articulations or spaces.
                // Multiple notes without articulations must be separated by spaces in this parser.
                i++;
            } else {
                i++;
            }
        }
        rt.note = notesSection.substr(start, i - start);
        rt.articulation = 0;

        // If no note was found but we hit an articulation, it's a grid token
        if (rt.note.empty() && i < notesSection.length() && 
            (notesSection[i] == '.' || notesSection[i] == '_' || notesSection[i] == '^')) {
            rt.articulation = notesSection[i];
            i++;
        }
        
        rawTokens.push_back(rt);
        currentGrid++;
    }

    // --- Pass 3: Event Generation with Look-ahead ---
    for (size_t i = 0; i < rawTokens.size(); ++i) {
        const auto& rt = rawTokens[i];
        if (!rt.note.empty()) {
            float freq = (float)getFrequency(rt.note, seq.notation, seq.baseFreq, seq.instrument);
            float vel = (float)rt.velocity / 9.0f;

            UMLEvent ev;
            ev.sampleOffset = (long)(rt.gridOffset * samplesPerGrid);
            ev.frequency = freq;
            ev.velocity = vel;
            ev.type = UMLEventType::NoteOn;
            ev.note = rt.note; // STORE THE ORIGINAL BOL/NOTE NAME
            
            // Look-ahead for duration (dots '.')
            long durationGrids = 1;
            size_t k = i + 1;
            while (k < rawTokens.size() && rawTokens[k].articulation == '.') {
                durationGrids++;
                k++;
            }
            
            // Check for Glide Look-ahead
            size_t j = i + 1;
            while (j < rawTokens.size() && rawTokens[j].articulation == '^') {
                // Found a glide marker
                size_t glideTarget = j + 1;
                while (glideTarget < rawTokens.size() && rawTokens[glideTarget].articulation == '.') glideTarget++;
                
                if (glideTarget < rawTokens.size() && !rawTokens[glideTarget].note.empty()) {
                    // Found target note
                    ev.type = UMLEventType::Glide;
                    ev.targetFrequency = (float)getFrequency(rawTokens[glideTarget].note, seq.notation, seq.baseFreq, seq.instrument);
                    ev.targetVelocity = (float)rawTokens[glideTarget].velocity / 9.0f;
                    ev.durationSamples = (long)((glideTarget - j) * samplesPerGrid);
                }
                break;
            }
            
            seq.events.push_back(ev);
        } else if (rt.articulation == '_') {
            UMLEvent ev;
            ev.sampleOffset = (long)(rt.gridOffset * samplesPerGrid);
            seq.events.push_back(ev);
        }
    }

    seq.totalDurationSamples = (long)(currentGrid * samplesPerGrid);
    return seq;
}

double UMLParser::getFrequency(const std::string& token, const std::string& notation, double baseFreq, const std::string& instrument) {
    // 0. Numeric Check (Direct Frequency)
    try {
        if (!token.empty() && std::isdigit(token[0])) {
            return std::stod(token);
        }
    } catch (...) {}

    // 1. Percussion Check
    if (instrument == "DA" || instrument == "BA" || instrument == "0" || instrument == "1") {
        // For percussion, the bol name itself is used for articulation.
        // We return baseFreq as the default pitch.
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
