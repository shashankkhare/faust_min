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

#ifndef UML_PARSER_HPP
#define UML_PARSER_HPP

#include <string>
#include <vector>
#include <map>

enum class UMLEventType {
    NoteOn,
    NoteOff,
    Glide
};

struct UMLEvent {
    long sampleOffset = 0;
    UMLEventType type = UMLEventType::NoteOn;
    float frequency = 0.0f;
    float velocity = 0.0f;
    float strikeVal = -1.0f;   // -1.0 implies no explicit strike value
    float vowelVal  = -1.0f;   // -1.0 = not a voice event; 0=aa 1=ee 2=ii 3=oo 4=uu
    std::string note = "";
    long durationSamples = 0;  // For glides
    float targetFrequency = 0.0f;  // For glides
    float targetVelocity  = 0.0f;  // For glides
    float targetStrikeVal = -1.0f; // For glides if needed
};

#include <memory>
#include "FaustInstrument.hpp"

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

    std::shared_ptr<FaustInstrument> mInstrument;

    UMLSequence() : instrumentID(-1), bpm(120.0), grid(4), baseFreq(261.63), gain(1.0), totalDurationSamples(0), notation("Indian"), execType("static") {}

    UMLSequence(const std::string& seqName, int instID, const std::string& umlDataString, double defaultBaseFreq = 261.63);

    FaustInstrument* getFaustInstrument() {
        return mInstrument.get();
    }
    
    ~UMLSequence();
};

class UMLParser {
public:
    enum class TokenType { NoteWithControl, ContinuityDot, StopRest };
    struct TokenItem {
        TokenType type;
        std::string rawStr;
        long gridIndex;
        int controlParam; // Octave/Velocity prefix modifier
        std::string noteName;
        bool hasGlide;
    };

    static UMLSequence parse(const std::string& name, const std::string& input, double sampleRate, double defaultBaseFreq = 261.63);

private:
    static double getFrequency(const std::string& token, const std::string& notation, double baseFreq, const std::string& instrument);
    static void handlePercussionToken(const std::string& tokenNoteName, float velocityScalar, long sampleOffset, long durationSamples, 
                                     double baseFreq, const std::string& instrument, std::vector<UMLEvent>& outEvents);
    static void handlePitchedToken(const TokenItem& ti, float velocityScalar, long sampleOffset, long durationSamples, 
                                   const std::string& notation, double baseFreq, const std::string& instrument,
                                   double samplesPerGrid, size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray, std::vector<UMLEvent>& outEvents);
    static void handleVoiceToken(const TokenItem& ti, float velocityScalar, long sampleOffset, long durationSamples,
                                 const std::string& notation, double baseFreq,
                                 double samplesPerGrid, size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray, std::vector<UMLEvent>& outEvents);

    static const std::map<std::string, double> indianRatios;
    static const std::map<std::string, double> westernPitches;
    static const std::map<std::string, double> percussionBols;
    // Vowel syllable table: aa/ee/ii/oo/uu → continuous 0–4 index for formant morphing
    static const std::map<std::string, double> vowelValues;
    // Extended bayan-specific bols (Dha, Ge, Dhin, Tit, etc.)
    static const std::map<std::string, double> bayanBols;
    // African drum stroke names → strikeVal for djembe (ID 28), conga (ID 30), bongo (ID 31)
    static const std::map<std::string, double> africanDrumBols;
};

#endif // UML_PARSER_HPP
