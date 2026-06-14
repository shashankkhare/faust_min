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

#ifndef UML_SEQUENCE_HPP
#define UML_SEQUENCE_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "FaustInstrument.hpp"

enum class UMLEventType {
    NoteOn,
    NoteOff,
    Glide,
    VibratoOn
};

struct UMLEvent {
    long sampleOffset = 0;
    UMLEventType type = UMLEventType::NoteOn;
    float frequency = 0.0f;
    float velocity = -1.0f;  // -1.0 = not set (use DSP default)
    float amplitude = -1.0f; // -1.0 = not set (use DSP default)
    float strikeVal = 0.0f;   // Default to 0.0f (normal strike)
    float vowelVal  = -1.0f;   // -1.0 = not a voice event; 0=aa 1=ee 2=ii 3=oo 4=uu
    std::string note = "";
    long durationSamples = 0;  // For glides
    float targetFrequency = 0.0f;  // For glides
    float targetVelocity  = 0.0f;  // For glides
    float targetAmplitude = -1.0f; // For glides
    float targetStrikeVal = -1.0f; // For glides if needed
};

class UMLSequence {
public:
    std::string name;
    std::string instrument;
    int instrumentID;
    std::map<std::string, float> initialParams;
    std::vector<UMLEvent> events;
    double bpm;
    int grid;
    double baseFreq;
    double gain;
    long totalDurationSamples;
    std::string notation;
    std::string execType;
    std::string umlData;
    bool loop = false;

    std::shared_ptr<FaustInstrument> mInstrument;

    UMLSequence() : instrumentID(-1), bpm(120.0), grid(4), baseFreq(261.63), gain(1.0), totalDurationSamples(0), notation("Indian"), execType("static") {}

    UMLSequence(const std::string& seqName, int instID, const std::string& umlDataString, double defaultBaseFreq = 261.63);

    FaustInstrument* getFaustInstrument() {
        return mInstrument.get();
    }
    
    void setBaseFrequency(double newBaseFreq);
    void setBpm(double newBpm);

    ~UMLSequence();
};

#endif // UML_SEQUENCE_HPP
