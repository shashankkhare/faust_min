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

#include "UMLSequence.hpp"

class UMLParser {
public:
    enum class TokenType { NoteWithControl, ContinuityDot, StopRest };
    enum class OpType { Glide, AmpGlide, Vibrato };
    struct TokenItem {
        TokenType type;
        std::string rawStr;
        long gridIndex;
        int controlParam; // Octave/Velocity prefix modifier
        float strikeVal = 0.0f; // Strike type prefix modifier (default 0.0f)
        std::string noteName;
        bool hasGlideOp;
        bool hasAmpGlideOp = false;
        bool hasVibratoOp;
        bool isGlideTarget = false;
        bool hasCompositeNotes = false;
    };

    static UMLSequence parse(const std::string& name, const std::string& input, double sampleRate, double defaultBaseFreq = 261.63);

private:
    static void parseHeader(std::stringstream& ss, UMLSequence& seq, int& grid, std::string& notesSection);
    static double getFrequency(const std::string& token, const std::string& notation, double baseFreq, const std::string& instrument);
    static void handlePercussionToken(const std::string& tokenNoteName, float amplitudeScalar, long sampleOffset, long durationSamples, 
                                     const std::string& notation, double baseFreq, const std::string& instrument, std::vector<UMLEvent>& outEvents,
                                     float strikeValFromPrefix = -1.0f);
    static void handlePitchedToken(const TokenItem& ti, float amplitudeScalar, long sampleOffset, long durationSamples, 
                                   const std::string& notation, double baseFreq, const std::string& instrument,
                                   double samplesPerGrid, double sampleRate, size_t nextTokenIndex, 
                                   const std::vector<TokenItem>& tokenItemsArray,
                                   const std::vector<std::pair<OpType, long>>& triggers, std::vector<UMLEvent>& outEvents);
    static void handleVoiceToken(const TokenItem& ti, float amplitudeScalar, long sampleOffset, long durationSamples,
                                 const std::string& notation, double baseFreq,
                                 double samplesPerGrid, size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray, std::vector<UMLEvent>& outEvents);
    static void handleCompositeNote(const TokenItem& ti, long sampleOffset, long durationSamples,
                                    const std::string& notation, double baseFreq, const std::string& instrument,
                                    size_t nextTokenIndex, const std::vector<TokenItem>& tokenItemsArray,
                                    double samplesPerGrid, double sampleRate, std::vector<UMLEvent>& outEvents);

    static const std::map<std::string, double> shruti22Ratios;
    static const std::map<std::string, double> hindustaniRatios;
    static const std::map<std::string, double> gongcheRatios;
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
