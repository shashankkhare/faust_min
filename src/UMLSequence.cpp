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
    double samplesPerBeat = (60.0 / bpm) * InstrumentMapper::DEFAULT_SAMPLE_RATE;
    for (const auto& ev : this->events) {
        if (ev.type == UMLEventType::NoteOn) {
            float midiPitch = ev.frequency > 0.0f ? 69.0f + 12.0f * log2f(ev.frequency / 440.0f) : 0.0f;
            float start = static_cast<float>(ev.sampleOffset / samplesPerBeat);
            float dur = static_cast<float>(ev.durationSamples / samplesPerBeat);
            rawNotes.push_back({midiPitch, ev.velocity, start, dur, ev.strikeVal});
        }
    }
    this->gain = parsed.gain;
    this->totalDurationSamples = parsed.totalDurationSamples;
    this->notation = parsed.notation;
    this->execType = parsed.execType;
    this->umlData = umlDataString;
    this->loop = parsed.loop;

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

int UMLSequence::getNotes(float fromBeat, float toBeat, float* outBuffer, int maxNotes) {
    int count = 0;
    for (const auto& note : rawNotes) {
        if (note.startBeat >= fromBeat && note.startBeat <= toBeat) {
            if (count < maxNotes) {
                int idx = count * 5;
                outBuffer[idx] = note.pitch;
                outBuffer[idx+1] = note.velocity;
                outBuffer[idx+2] = note.startBeat;
                outBuffer[idx+3] = note.durationBeats;
                outBuffer[idx+4] = note.strikeVal;
                count++;
            }
        }
    }
    return count;
}

void UMLSequence::regenerateEventsIfNeeded() {
    if (!isDirty) return;
    
    // Simplistic full regeneration of the event timeline from rawNotes
    events.clear();
    double samplesPerBeat = (60.0 / bpm) * InstrumentMapper::DEFAULT_SAMPLE_RATE;
    
    for (const auto& raw : rawNotes) {
        UMLEvent onEv;
        onEv.sampleOffset = static_cast<long>(raw.startBeat * samplesPerBeat);
        onEv.type = UMLEventType::NoteOn;
        onEv.frequency = raw.pitch;
        onEv.velocity = raw.velocity;
        onEv.durationSamples = static_cast<long>(raw.durationBeats * samplesPerBeat);
        events.push_back(onEv);
        
        UMLEvent offEv;
        offEv.sampleOffset = onEv.sampleOffset + onEv.durationSamples;
        offEv.type = UMLEventType::NoteOff;
        offEv.frequency = raw.pitch;
        events.push_back(offEv);
    }
    
    // Re-sort the event timeline
    std::sort(events.begin(), events.end(), [](const UMLEvent& a, const UMLEvent& b) {
        return a.sampleOffset < b.sampleOffset;
    });
    
    if (!events.empty()) {
        totalDurationSamples = events.back().sampleOffset;
    }
    
    isDirty = false;
}
