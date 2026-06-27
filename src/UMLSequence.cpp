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

#include "UMLSequence.hpp"
#include "UMLParser.hpp"
#include "InstrumentMapper.hpp"
#include <cstdio>
#include <cmath>
#include <cstring>

UMLSequence::UMLSequence(const std::string& seqName, int instID, const std::string& umlDataString, double defaultBaseFreq) {
    UMLSequence parsed = UMLParser::parse(seqName, umlDataString, InstrumentMapper::DEFAULT_SAMPLE_RATE, defaultBaseFreq);
    this->name = parsed.name;
    this->instrument = parsed.instrument;
    this->instrumentID = parsed.instrumentID != -1 ? parsed.instrumentID : instID;
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
    this->loop = parsed.loop;
    this->measure = parsed.measure;
    this->rawNotes = parsed.rawNotes;
    this->noteNames = parsed.noteNames;

    int targetID = this->instrumentID;
    if (targetID == -1 && !this->instrument.empty()) {
        targetID = InstrumentMapper::getIDFromName(this->instrument);
    }
    if (targetID != -1) {
        DSPExecutionType mode = (this->execType == "interpreter" || this->execType == "interpreted") 
                              ? DSPExecutionType::InterpretedByte 
                              : DSPExecutionType::StaticCompiled;
        this->mInstrument = std::make_shared<FaustInstrument>(targetID, mode, InstrumentMapper::DEFAULT_SAMPLE_RATE);
        if (this->baseFreq > 0.0) {
            this->mInstrument->setParameter("basefreq", this->baseFreq);
        }
        for (const auto& pair : this->initialParams) {
            this->mInstrument->setParameter(pair.first.c_str(), pair.second);
        }
    } else {
        printf("[Native] WARNING: UMLSequence created with invalid instrument ID mapping.\n");
        fflush(stdout);
    }
}

void UMLSequence::setBaseFrequency(double newBaseFreq) {
    if (baseFreq <= 0.0) return;
    double ratio = newBaseFreq / baseFreq;
    baseFreq = newBaseFreq;

    // For percussion instruments (like Dholak/Dhol/Tabla) basefreq is a direct DSP tuning property
    if (instrumentID == 37 || instrumentID == 38 || instrumentID == 1 || instrumentID == 0) {
        if (mInstrument) {
            mInstrument->setParameter("freq", static_cast<float>(newBaseFreq));
            mInstrument->setParameter("basefreq", static_cast<float>(newBaseFreq));
        }
    } else {
        // For melodic instruments, recalculate all pre-parsed note frequencies
        for (auto& ev : events) {
            if (ev.frequency > 0.0f) {
                ev.frequency *= static_cast<float>(ratio);
            }
        }
    }
}

void UMLSequence::setBpm(double newBpm) {
    if (bpm <= 0.0) return;
    double ratio = bpm / newBpm;
    for (auto& ev : events) {
        ev.sampleOffset = static_cast<long>(ev.sampleOffset * ratio);
        ev.durationSamples = static_cast<long>(ev.durationSamples * ratio);
    }
    totalDurationSamples = static_cast<long>(totalDurationSamples * ratio);
    bpm = newBpm;
}

UMLSequence::~UMLSequence() {
    // Note: FaustMixer unregistration must be handled by the caller/owner
    // to strictly preserve zero-coupling architecture.
}

void UMLSequence::addNote(float pitch, float velocity, float startBeat, float durationBeats, float strikeVal) {
    rawNotes.push_back({pitch, velocity, startBeat, durationBeats, strikeVal});
    isDirty = true;
}

void UMLSequence::removeNote(float pitch, float startBeat) {
    for (auto it = rawNotes.begin(); it != rawNotes.end(); ++it) {
        if (std::abs(it->pitch - pitch) < 0.01f && std::abs(it->startBeat - startBeat) < 0.01f) {
            rawNotes.erase(it);
            isDirty = true;
            break;
        }
    }
}

void UMLSequence::clearNotes() {
    rawNotes.clear();
    isDirty = true;
}

int UMLSequence::getNotes(float fromBeat, float toBeat, float* outBuffer, int maxNotes, char* outNames) {
    int count = 0;
    int nameOffset = 0;
    for (size_t i = 0; i < rawNotes.size() && count < maxNotes; ++i) {
        const auto& note = rawNotes[i];
        if (note.startBeat >= fromBeat && note.startBeat <= toBeat) {
            int idx = count * 6;
            outBuffer[idx] = note.pitch;
            outBuffer[idx+1] = note.velocity;
            outBuffer[idx+2] = note.startBeat;
            outBuffer[idx+3] = note.durationBeats;
            outBuffer[idx+4] = note.strikeVal;
            outBuffer[idx+5] = note.hasStop ? 1.0f : 0.0f;
            if (outNames && i < noteNames.size()) {
                const char* name = noteNames[i].c_str();
                int len = static_cast<int>(strlen(name)) + 1;
                memcpy(outNames + nameOffset, name, len);
                nameOffset += len;
            } else if (outNames) {
                outNames[nameOffset] = '\0';
                nameOffset++;
            }
            count++;
        }
    }
    return count;
}

void UMLSequence::prepare() {
    if (!isDirty) return;

    std::string serialized = "";
    
    serialized += "bpm: " + std::to_string(bpm) + "\n";
    serialized += "grid: " + std::to_string(grid) + "\n";
    serialized += "notation: " + notation + "\n";
    serialized += "instrument: " + instrument + "\n";
    serialized += "instrumentID: " + std::to_string(instrumentID) + "\n";
    serialized += "measure: " + std::to_string(measure) + "\n";
    serialized += "loop: " + std::string(loop ? "true" : "false") + "\n";
    serialized += "gain: " + std::to_string(gain) + "\n";
    serialized += "delay: " + std::to_string(delaySec) + "\n";
    
    if (!initialParams.empty()) {
        serialized += "parameters: ";
        bool first = true;
        for (const auto& pair : initialParams) {
            if (!first) serialized += ",";
            serialized += pair.first + "=" + std::to_string(pair.second);
            first = false;
        }
        serialized += "\n";
    }
    
    serialized += "\n";

    float maxBeat = 0.0f;
    for (const auto& note : rawNotes) {
        if (note.startBeat + note.durationBeats > maxBeat) {
            maxBeat = note.startBeat + note.durationBeats;
        }
    }
    
    int totalGrids = static_cast<int>(std::round(maxBeat * grid));
    std::map<int, size_t> gridToNote;
    for (size_t i = 0; i < rawNotes.size(); ++i) {
        int idx = static_cast<int>(std::round(rawNotes[i].startBeat * grid));
        gridToNote[idx] = i;
    }

    for (int g = 0; g < totalGrids; ++g) {
        if (g > 0) serialized += " ";
        if (gridToNote.count(g)) {
            size_t idx = gridToNote[g];
            const auto& raw = rawNotes[idx];
            std::string token = "";
            
            int controlParam = static_cast<int>(std::round(raw.velocity * 9.0f));
            if (raw.strikeVal > 0.0f) {
                token += std::to_string(controlParam) + std::to_string(static_cast<int>(raw.strikeVal));
            } else if (controlParam != 5) {
                token += std::to_string(controlParam);
            }
            
            token += (idx < noteNames.size()) ? noteNames[idx] : ".";
            
            if (raw.hasGlide) token += "^";
            if (raw.hasVibrato) token += "~";
            if (raw.hasVelGlide) token += ">";
            if (raw.hasStop) token += "_";
            
            serialized += token;
        } else {
            serialized += ".";
        }
    }

    UMLSequence parsed = UMLParser::parse(name, serialized, InstrumentMapper::DEFAULT_SAMPLE_RATE, baseFreq);
    
    this->events = parsed.events;
    this->totalDurationSamples = parsed.totalDurationSamples;
    
    isDirty = false;
}
