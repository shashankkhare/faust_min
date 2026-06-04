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
    this->instrumentID = instID != -1 ? instID : parsed.instrumentID;
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
