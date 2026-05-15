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
 * @file UMPLParser.cpp
 * @brief Implementation file for UMPLParser
 * 
 * DESIGN: Physical modeling synthesis instrument wrapper. It encapsulates the Faust-generated C++ DSP logic and exposes high-level expressive controls like frequency, velocity, and articulation.
 */

#include "UMPLParser.hpp"
#include <sstream>
#include <regex>
#include <iostream>
#include <cmath>

const std::map<std::string, double> UMPLParser::ratios = {
    {"Sa", 1.0}, {"r1", 256.0/243.0}, {"r2", 16.0/15.0}, {"R1", 10.0/9.0}, {"R2", 9.0/8.0},
    {"g1", 32.0/27.0}, {"g2", 6.0/5.0}, {"G1", 5.0/4.0}, {"G2", 81.0/64.0},
    {"M1", 4.0/3.0}, {"M2", 27.0/20.0}, {"m1", 45.0/32.0}, {"m2", 64.0/45.0},
    {"Pa", 1.5}, {"d1", 128.0/81.0}, {"d2", 8.0/5.0}, {"D1", 5.0/3.0}, {"D2", 27.0/16.0},
    {"n1", 16.0/9.0}, {"n2", 9.0/5.0}, {"N1", 15.0/8.0}, {"N2", 243.0/128.0}
};

UMPLSequence UMPLParser::parse(const std::string& name, const std::string& input, double sampleRate) {
    UMPLSequence seq;
    seq.name = name;
    
    std::stringstream ss(input);
    std::string line;
    std::string rawPattern;
    int grid = 4;
    std::map<int, double> instBaseFreqs;
    std::map<int, double> instGains;

    while (std::getline(ss, line)) {
        if (line.find(':') != std::string::npos) {
            auto pos = line.find(':');
            std::string key = line.substr(0, pos);
            std::string val = line.substr(pos + 1);
            
            // Trim
            key.erase(0, key.find_first_not_of(" \t\r\n"));
            key.erase(key.find_last_not_of(" \t\r\n") + 1);
            val.erase(0, val.find_first_not_of(" \t\r\n"));
            val.erase(val.find_last_not_of(" \t\r\n") + 1);

            if (key == "basefreq") seq.baseFreq = std::stod(val);
            else if (key == "bpm") seq.bpm = std::stod(val);
            else if (key == "grid") grid = std::stoi(val);
            else {
                try {
                    int instId = std::stoi(key);
                    // Parse freq and gain
                    std::regex freqRegex(R"(^([\d.]+)(?:\s*\(gain=([\d.]+)\))?)");
                    std::smatch match;
                    if (std::regex_search(val, match, freqRegex)) {
                        instBaseFreqs[instId] = std::stod(match[1]);
                        if (match.size() > 2 && match[2].matched) {
                            instGains[instId] = std::stod(match[2]);
                        }
                    }
                } catch (...) {}
            }
        } else {
            rawPattern += line;
        }
    }

    if (instBaseFreqs.find(0) == instBaseFreqs.end()) instBaseFreqs[0] = seq.baseFreq;
    if (instBaseFreqs.find(1) == instBaseFreqs.end()) instBaseFreqs[1] = seq.baseFreq / 2.0;

    double samplesPerBeat = (60.0 / seq.bpm) * sampleRate;
    double samplesPerGrid = samplesPerBeat / grid;

    std::regex tokenRegex(R"((\d+)(?:\(([^)]+)\)|([a-zA-Z12]+))|([._^]))");
    auto tokens_begin = std::sregex_iterator(rawPattern.begin(), rawPattern.end(), tokenRegex);
    auto tokens_end = std::sregex_iterator();

    std::vector<std::smatch> tokens;
    for (std::sregex_iterator i = tokens_begin; i != tokens_end; ++i) {
        tokens.push_back(*i);
    }

    long currentSample = 0;
    std::map<int, double> lastFreq;

    for (size_t i = 0; i < tokens.size(); ++i) {
        const auto& match = tokens[i];
        if (match[4].matched) {
             currentSample += samplesPerGrid;
             continue;
        }

        int instId = std::stoi(match[1]);
        std::string expr = match[2].matched ? match[2].str() : match[3].str();
        double instBase = instBaseFreqs.count(instId) ? instBaseFreqs[instId] : seq.baseFreq;
        double instGain = instGains.count(instId) ? instGains[instId] : 1.0;

        double ratio = evaluateExpression(expr);
        float freq = (float)(instBase * ratio);

        long durationSamples = (long)samplesPerGrid;
        size_t lookAhead = i + 1;
        while (lookAhead < tokens.size() && tokens[lookAhead][4].matched && tokens[lookAhead][4].str() == ".") {
            durationSamples += (long)samplesPerGrid;
            lookAhead++;
        }

        bool isLegato = (lookAhead < tokens.size() && tokens[lookAhead][4].matched && tokens[lookAhead][4].str() == "^");

        // Handle Meend (Glide)
        if (i > 0 && tokens[i-1][4].matched && tokens[i-1][4].str() == "^" && lastFreq.count(instId)) {
            // Simplify: add a meend event or series of events
            // For now, just add the NoteOn with a glide flag or similar
        }

        SequenceEvent ev;
        ev.sampleOffset = currentSample;
        ev.type = EventType::NoteOn;
        ev.instrumentId = instId;
        ev.value = freq;
        ev.durationSamples = (long)(durationSamples * 0.95);
        ev.legato = isLegato;
        seq.events.push_back(ev);

        // Add a NoteOff event
        SequenceEvent off;
        off.sampleOffset = currentSample + ev.durationSamples;
        off.type = EventType::NoteOff;
        off.instrumentId = instId;
        off.value = 0;
        off.durationSamples = 0;
        off.legato = false;
        seq.events.push_back(off);

        lastFreq[instId] = freq;
        currentSample += samplesPerGrid;
    }

    seq.totalDurationSamples = currentSample;
    return seq;
}

double UMPLParser::evaluateExpression(const std::string& expr) {
    if (ratios.count(expr)) return ratios.at(expr);
    // Simple math eval placeholder
    try { return std::stod(expr); } catch (...) { return 1.0; }
}
