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
 * @file SequenceOrchestrator.cpp
 * @brief Implementation file for SequenceOrchestrator
 * 
 * DESIGN: Acts as the 'Controller' in the Controller-Sink model. It manages the musical timeline (UML) and schedules events. It is synchronized with the hardware interrupt via the FaustMixer's pre-render callback.
 */

#include "SequenceOrchestrator.hpp"
#include "UMLParser.hpp"
#include "InstrumentMapper.hpp"
#include "FaustMixer.hpp"

#include <faust/dsp/dsp.h>
#include <faust/dsp/interpreter-dsp.h>
#include <faust/gui/MapUI.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <chrono>
#include <unistd.h>
#include <sys/stat.h>

#define DEBUG_ORCHESTRATOR 1

SequenceOrchestrator::SequenceOrchestrator() {}

SequenceOrchestrator::~SequenceOrchestrator() {
    stop();
    {
        std::lock_guard<std::mutex> lock(mStateMutex);
        mActiveSequences.clear();
    }
    // Release snapshot — shared_ptr ref count handles safe cleanup
    std::atomic_store(&mRenderSnapshot, std::shared_ptr<SnapshotVec>(nullptr));
}


void SequenceOrchestrator::rebuildSnapshot() {
    // Must be called under mStateMutex from main thread only.
    auto next = std::make_shared<SnapshotVec>();
    next->reserve(mActiveSequences.size());
    for (auto& pair : mActiveSequences) {
        next->push_back(pair.second);
    }
    std::atomic_store(&mRenderSnapshot, next);
}

void SequenceOrchestrator::setAssetBasePath(const std::string& path) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    mAssetBasePath = path;
    printf("[Native] Asset Base Path set to: %s\n", path.c_str());
    fflush(stdout);
}

int SequenceOrchestrator::addSequence(const std::string& name, UMLSequence* sequence) {
    if (!sequence || sequence->instrumentID == -1) {
        printf("[Native Error] Failed to add sequence '%s': Invalid Instrument ID\n", name.c_str());
        fflush(stdout);
        return -1;
    }

    std::lock_guard<std::mutex> lock(mStateMutex);

    if (mActiveSequences.count(name)) {
        printf("[Native Error] Failed to add sequence '%s': Name already exists\n", name.c_str());
        fflush(stdout);
        return -2;
    }

    printf("[Native] Adding Sequence Object: %s (InstID: %d)\n", name.c_str(), sequence->instrumentID);
    fflush(stdout);
    
    auto seqWrapper = std::make_shared<ActiveSequence>();
    seqWrapper->sequenceObj = sequence;
    seqWrapper->currentSample = 0;
    seqWrapper->nextEventIndex = 0;
    seqWrapper->isPlaying = false;
    
    mActiveSequences[name] = seqWrapper;
    
    // Ensure audio engine is armed and running (lazy init)
    // REMOVED: Hardware control should be explicit via FaustMixer class.
    
    // Registration with FaustMixer is now handled explicitly by the caller (Bridge/Dart)
    // to maintain strict decoupling between Orchestration and Rendering.
    
    rebuildSnapshot();
    return 0;
}

void SequenceOrchestrator::play(const std::string& name) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name)) {
        printf("[Native] Starting Playback: %s\n", name.c_str());
        fflush(stdout);
        mActiveSequences[name]->isPlaying.store(true);
        mActiveSequences[name]->currentSample = 0;
        mActiveSequences[name]->nextEventIndex = 0;
        rebuildSnapshot();
    } else {
        printf("[Native] ERROR: Sequence not found: %s\n", name.c_str());
        fflush(stdout);
    }
}

void SequenceOrchestrator::stop() {
    std::lock_guard<std::mutex> lock(mStateMutex);
    for (auto& pair : mActiveSequences) {
        pair.second->isPlaying = false;
    }
}

void SequenceOrchestrator::pause() { mIsPaused = true; }
void SequenceOrchestrator::resume() { mIsPaused = false; }

void SequenceOrchestrator::muteTrack(const std::string& name, bool mute) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name)) {
        mActiveSequences[name]->isMuted.store(mute);
        rebuildSnapshot();
        printf("[Native] Track '%s' mute state set to: %s\n", name.c_str(), mute ? "true" : "false");
        fflush(stdout);
    }
}

void SequenceOrchestrator::setParameter(const std::string& name, const std::string& param, float value) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name) && mActiveSequences[name]->sequenceObj) {
        auto inst = mActiveSequences[name]->sequenceObj->getFaustInstrument();
        if (inst) inst->setParameter(param.c_str(), value);
    }
}

void SequenceOrchestrator::setWeight(const std::string& name, float weight) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name)) {
        auto inst = mActiveSequences[name]->sequenceObj->getFaustInstrument();
        if (inst) {
            FaustMixer::getInstance().setInstrumentWeight(inst->getID(), weight);
        }
    }
}



void SequenceOrchestrator::updateTimeline(int numFrames) {
    if (mIsPaused.load(std::memory_order_relaxed)) return;
    
    auto snapshot = getRenderSnapshot();
    if (!snapshot || snapshot->empty()) return;


    for (auto& seqWrapper : *snapshot) {
        if (!seqWrapper->isPlaying.load(std::memory_order_relaxed) || seqWrapper->isMuted.load(std::memory_order_relaxed)) continue;
        
        UMLSequence* seq = seqWrapper->sequenceObj;
        FaustInstrument* inst = seq->getFaustInstrument();
        if (!inst) continue;

        auto& events = seq->events;

        // Evaluate all events that fall within this block's sample range
        while (seqWrapper->isPlaying && seqWrapper->nextEventIndex < events.size()) {
            auto& ev = events[seqWrapper->nextEventIndex];
            
            // If the event happens within this block (or happened in the past due to a skip)
            if (ev.sampleOffset <= seqWrapper->currentSample + numFrames) {
                if (ev.type == UMLEventType::NoteOn) {
                    printf("[Native Trace] TRIGGER: Seq='%s' | EvIdx=%zu | Offset=%ld\n", 
                           seqWrapper->sequenceObj->name.c_str(), seqWrapper->nextEventIndex, ev.sampleOffset);
                    fflush(stdout);
                    updateDSPParams(seqWrapper, ev.frequency, ev.velocity, ev.strikeVal, ev.note);
                    if (inst) inst->noteOn(ev.frequency, ev.velocity, ev.strikeVal);
                } else if (ev.type == UMLEventType::NoteOff) {
                    printf("[Native Trace] TRIGGER (OFF): Seq='%s' | EvIdx=%zu | Offset=%ld\n", 
                           seqWrapper->sequenceObj->name.c_str(), seqWrapper->nextEventIndex, ev.sampleOffset);
                    fflush(stdout);
                    if (inst) inst->noteOff();
                } else if (ev.type == UMLEventType::Glide) {
                    float durSec = static_cast<float>(ev.durationSamples) / FaustMixer::getInstance().getSampleRate();
                    if (inst) {
                        inst->frequencyGlide(ev.targetFrequency, durSec);
                        inst->velocityGlide(ev.targetVelocity, durSec);
                    }
                }
                seqWrapper->nextEventIndex++;
            } else {
                // Event is further in the future, stop for this block
                break;
            }
        }

        seqWrapper->currentSample += numFrames;

        if (seqWrapper->currentSample >= seq->totalDurationSamples) {
            seqWrapper->isPlaying.store(false, std::memory_order_release);
            notifyFinished(seq->name);
        }
    }
}

void SequenceOrchestrator::processBuffer(std::shared_ptr<ActiveSequence> seqWrapper, float* output, int numFrames) {
    // This is now a legacy stub if anyone still calls it directly
}

void SequenceOrchestrator::updateDSPParams(std::shared_ptr<ActiveSequence> seqWrapper, float freq, float vel, float strikeVal, const std::string& note) {
    if (!seqWrapper || !seqWrapper->sequenceObj) return;
    auto inst = seqWrapper->sequenceObj->getFaustInstrument();
    if (!inst) return;

    if (freq > 0.0f) inst->setParam("freq", freq);
    if (vel >= 0.0f) inst->setParam("velocity", vel);
    if (strikeVal >= 0.0f) inst->setParam("strike", strikeVal);
}
