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

#ifndef UMPL_PARSER_HPP
#define UMPL_PARSER_HPP

#include <string>
#include <vector>
#include <map>

enum class EventType {
    NoteOn,
    NoteOff,
    ParamChange
};

struct SequenceEvent {
    long sampleOffset;
    EventType type;
    int instrumentId;
    float value;
    long durationSamples;
    bool legato;
};

class UMPLSequence {
public:
    std::string name;
    std::vector<SequenceEvent> events;
    double bpm;
    double baseFreq;
    long totalDurationSamples;

    UMPLSequence() : bpm(120.0), baseFreq(261.63), totalDurationSamples(0) {}
};

class UMPLParser {
public:
    static UMPLSequence parse(const std::string& name, const std::string& input, double sampleRate);

private:
    static double evaluateExpression(const std::string& expr);
    static double getRatio(const std::string& note);
    static const std::map<std::string, double> ratios;
};

#endif // UMPL_PARSER_HPP
