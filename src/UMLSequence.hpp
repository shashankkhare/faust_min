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
    PhonemeOn,
    FreqGlide,
    VelGlide,
    VibratoOn,
    PhonemeGlide
};

struct UMLEvent {
    long sampleOffset = 0;
    UMLEventType type = UMLEventType::NoteOn;
    float frequency = 0.0f;
    float velocity = -1.0f;  // -1.0 = not set (use DSP default)
    float strikeVal = 0.0f;   // Default to 0.0f (normal strike)
    float vowelVal  = -1.0f;   // -1.0 = not a voice event; 0=aa 1=ee 2=ii 3=oo 4=uu
    float noteNameCode = 0.0f; // 0=pitch-based, 1=X, 2=Na, 3=Tin, 4=Tun, 5=tk, 6=Ghe, 7=Ka
    std::string note = "";
    long durationSamples = 0;  // For glides
    float targetFrequency = 0.0f;  // For glides
    float targetVelocity  = -1.0f;  // For glides
    float targetStrikeVal = -1.0f; // For glides if needed
    std::string targetNote = "";   // For phoneme glides
};

struct UMLRawNote {
    float pitch;
    float velocity;
    float startBeat;
    float durationBeats;
    float strikeVal = 0.0f;
    bool hasStop = false;
    bool hasGlide = false;
    bool hasVibrato = false;
    bool hasVelGlide = false;
};

class UMLSequence {
public:
    std::string name;
    std::map<std::string, double> initialParams;
    std::string notation = "scientific";
    std::string execType = "static";
    std::string linkedTrack = ""; // Cross-link to share DSP instance

    std::vector<UMLEvent> events;
    double bpm;
    int grid;
    double baseFreq;
    double gain;
    long totalDurationSamples;
    std::string instrument;
    int instrumentID;
    std::string umlData;
    bool loop = false;
    double delaySec = 0.0; // delay before first note, in seconds
    int measure = 0; // display-only: number of beats per measure (e.g., 4 for 4/4)

    std::vector<UMLRawNote> rawNotes;
    std::vector<std::string> noteNames;
    bool isDirty = false;

    std::shared_ptr<FaustInstrument> mInstrument;

    UMLSequence() : instrumentID(-1), bpm(120.0), grid(4), baseFreq(261.63), gain(1.0), totalDurationSamples(0), notation("Indian"), execType("static"), isDirty(false) {}

    UMLSequence(const std::string& seqName, int instID, const std::string& umlDataString, double defaultBaseFreq = 261.63);

    void setBpm(double bpm);
    long getTotalDurationSamples() const { return totalDurationSamples; }

    void addNote(float pitch, float velocity, float startBeat, float durationBeats, float strikeVal = 0.0f);
    void removeNote(float pitch, float startBeat);
    void clearNotes();
    int getNotes(float fromBeat, float toBeat, float* outBuffer, int maxNotes, char* outNames = nullptr);
    void prepare();

    void setFaustInstrument(std::shared_ptr<FaustInstrument> inst) {
        mInstrument = inst;
    }
    FaustInstrument* getFaustInstrument() {
        return mInstrument.get();
    }
    std::shared_ptr<FaustInstrument> getFaustInstrumentShared() {
        return mInstrument;
    }
    
    void setBaseFrequency(double newBaseFreq);

    ~UMLSequence();
};

#endif // UML_SEQUENCE_HPP
