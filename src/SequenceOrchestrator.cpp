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

#include <faust/dsp/dsp.h>
#ifndef FAUST_DISABLE_INTERPRETER
#include <faust/dsp/interpreter-dsp.h>
#endif
#include <faust/gui/MapUI.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <chrono>
#ifndef _WIN32
#include <unistd.h>
#include <sys/stat.h>
#endif
#include <dirent.h>

#define DEBUG_ORCHESTRATOR 0

// Extremely fast, stateless deterministic hash to generate jitter for a given event index and instrument
inline long getDeterministicJitter(size_t eventIndex, int instID) {
    uint32_t hash = static_cast<uint32_t>(eventIndex ^ (instID << 8));
    hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
    hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
    hash = (hash >> 16) ^ hash;
    return static_cast<long>(hash % 961) - 480; // +/- 10ms at 48kHz
}

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

int SequenceOrchestrator::loadSong(const std::string& songDirectory) {
    std::string fullDir = mAssetBasePath + "/" + songDirectory;
    DIR* dir = opendir(fullDir.c_str());
    if (!dir) {
        // Attempt as absolute path if relative fails
        dir = opendir(songDirectory.c_str());
        if (!dir) {
            printf("[Orchestrator] Failed to open song directory: %s\n", fullDir.c_str());
            return -1;
        }
        fullDir = songDirectory;
    }

    std::vector<std::string> loadedSeqNames;
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;
        if (filename.length() > 4 && filename.substr(filename.length() - 4) == ".usq") {
            std::string filepath = fullDir + "/" + filename;
            std::ifstream infile(filepath);
            if (!infile.is_open()) continue;

            std::string line;
            std::string currentSeqBlock = "";
            bool inNotes = false;
            int subSeqIdx = 0;

            while (std::getline(infile, line)) {
                bool isParam = false;
                std::string trimmed = line;
                trimmed.erase(0, trimmed.find_first_not_of(" \t\r\n"));
                if (!trimmed.empty() && trimmed.find("//") != 0) {
                    if (trimmed.find(':') != std::string::npos) {
                        isParam = true;
                    } else {
                        inNotes = true;
                    }
                }

                if (isParam && inNotes) {
                    std::string seqName = songDirectory + "_" + filename + "_" + std::to_string(subSeqIdx++);
                    UMLSequence* seq = new UMLSequence(seqName, -1, currentSeqBlock);
                    if (addSequence(seqName, seq) == 0) {
                        loadedSeqNames.push_back(seqName);
                    } else {
                        delete seq;
                    }
                    currentSeqBlock = "";
                    inNotes = false;
                }
                currentSeqBlock += line + "\n";
            }
            if (!currentSeqBlock.empty()) {
                std::string seqName = songDirectory + "_" + filename + "_" + std::to_string(subSeqIdx++);
                UMLSequence* seq = new UMLSequence(seqName, -1, currentSeqBlock);
                if (addSequence(seqName, seq) == 0) {
                    loadedSeqNames.push_back(seqName);
                } else {
                    delete seq;
                }
            }
        }
    }
    closedir(dir);

    std::lock_guard<std::mutex> lock(mStateMutex);
    mSongRegistry[songDirectory] = loadedSeqNames;
    return loadedSeqNames.size();
}

void SequenceOrchestrator::unloadSong(const std::string& songDirectory) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mSongRegistry.count(songDirectory)) {
        for (const auto& seqName : mSongRegistry[songDirectory]) {
            mActiveSequences.erase(seqName);
            // also remove from pending play if it's there
            mPendingPlay.erase(std::remove(mPendingPlay.begin(), mPendingPlay.end(), seqName), mPendingPlay.end());
        }
        mSongRegistry.erase(songDirectory);
    }
    rebuildSnapshot();
}

void SequenceOrchestrator::playSong(const std::string& songDirectory) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mSongRegistry.count(songDirectory)) {
        for (const auto& seqName : mSongRegistry[songDirectory]) {
            if (mActiveSequences.count(seqName)) {
                if (std::find(mPendingPlay.begin(), mPendingPlay.end(), seqName) == mPendingPlay.end()) {
                    mPendingPlay.push_back(seqName);
                }
            }
        }
    }
}

void SequenceOrchestrator::stopSong(const std::string& songDirectory) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mSongRegistry.count(songDirectory)) {
        for (const auto& seqName : mSongRegistry[songDirectory]) {
            mPendingPlay.erase(std::remove(mPendingPlay.begin(), mPendingPlay.end(), seqName), mPendingPlay.end());
            if (mActiveSequences.count(seqName)) {
                mActiveSequences[seqName]->state = SequenceState::STOPPED;
                mActiveSequences[seqName]->playbackSampleIndex = 0;
            }
        }
    }
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
        
        auto seqWrapper = mActiveSequences[name];
        if (seqWrapper && seqWrapper->sequenceObj) {
            auto inst = seqWrapper->sequenceObj->getFaustInstrument();
            if (inst) {
                // Initialize the instrument frequency immediately to the first note's frequency
                // to prevent high-pitched slides from the default 440Hz when starting.
                for (const auto& ev : seqWrapper->sequenceObj->events) {
                    if (ev.type == UMLEventType::NoteOn && ev.frequency > 0.0f) {
                        inst->setFrequencyImmediate(ev.frequency);
                        break;
                    }
                }
            }
        }

        mPendingPlay.push_back(name);
        rebuildSnapshot();
    } else {
        printf("[Native] ERROR: Sequence not found: %s\n", name.c_str());
        fflush(stdout);
    }
}

void SequenceOrchestrator::clearSequences() {
    stop();
    {
        std::lock_guard<std::mutex> lock(mStateMutex);
        mActiveSequences.clear();
        rebuildSnapshot();
    }
    printf("[Native] Sequence Orchestrator cleared.\n");
    fflush(stdout);
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
        if (param == "bpm") {
            mActiveSequences[name]->sequenceObj->setBpm(value);
        } else if (param == "basefreq") {
            mActiveSequences[name]->sequenceObj->setBaseFrequency(value);
        } else {
            auto inst = mActiveSequences[name]->sequenceObj->getFaustInstrument();
            if (inst) inst->setParameter(param.c_str(), value);
        }
    }
}

void SequenceOrchestrator::updateTimeline(int numFrames) {
    if (mIsPaused.load(std::memory_order_relaxed)) return;

    // Check if any sequence is currently playing before adding new ones
    bool anyPlaying = false;
    auto snapshot = getRenderSnapshot();
    if (snapshot) {
        for (auto& seqWrapper : *snapshot) {
            if (seqWrapper->isPlaying.load(std::memory_order_acquire)) {
                anyPlaying = true;
                break;
            }
        }
    }

    if (!anyPlaying) {
        mMasterSampleCount = 0;
    }

    // 1. Process any pending play requests first
    std::vector<std::shared_ptr<ActiveSequence>> toStart;
    {
        std::lock_guard<std::mutex> lock(mStateMutex);
        if (!mPendingPlay.empty()) {
            for (const auto& name : mPendingPlay) {
                if (mActiveSequences.count(name)) {
                    toStart.push_back(mActiveSequences[name]);
                }
            }
            mPendingPlay.clear();
            rebuildSnapshot();
        }
    }

    for (auto& seqWrapper : toStart) {
        seqWrapper->isPlaying.store(true, std::memory_order_release);
        if (mMasterSampleCount == 0) {
            seqWrapper->currentSample = 0;
            seqWrapper->nextEventIndex = 0;
        } else {
            seqWrapper->currentSample = mMasterSampleCount % seqWrapper->sequenceObj->totalDurationSamples;
            seqWrapper->nextEventIndex = 0;
            auto& events = seqWrapper->sequenceObj->events;
            while (seqWrapper->nextEventIndex < events.size() && 
                   events[seqWrapper->nextEventIndex].sampleOffset < seqWrapper->currentSample) {
                seqWrapper->nextEventIndex++;
            }
        }
    }
    
    // Reload snapshot to include the newly started sequences
    snapshot = getRenderSnapshot();
    if (!snapshot || snapshot->empty()) return;

    for (auto& seqWrapper : *snapshot) {
        if (!seqWrapper->isPlaying.load(std::memory_order_acquire)) {
            continue;
        }

        UMLSequence* seq = seqWrapper->sequenceObj;
        if (!seq || seq->totalDurationSamples <= 0) continue;

        long framesRemaining = numFrames;

        if (seqWrapper->isMuted.load(std::memory_order_relaxed)) {
            while (framesRemaining > 0) {
                long samplesToNextWrap = seq->totalDurationSamples - seqWrapper->currentSample;
                if (samplesToNextWrap <= 0) {
                    seqWrapper->currentSample = 0;
                    seqWrapper->nextEventIndex = 0;
                    samplesToNextWrap = seq->totalDurationSamples;
                }
                long framesToProcess = std::min(framesRemaining, samplesToNextWrap);
                seqWrapper->currentSample += framesToProcess;
                framesRemaining -= framesToProcess;

                if (seqWrapper->currentSample >= seq->totalDurationSamples) {
                    if (seq->loop || mLooping.load(std::memory_order_relaxed)) {
                        seqWrapper->currentSample = 0;
                        seqWrapper->nextEventIndex = 0;
                    } else {
                        seqWrapper->isPlaying.store(false, std::memory_order_release);
                        notifyFinished(seq->name);
                        break;
                    }
                }
            }
            continue;
        }
        
        FaustInstrument* inst = seq->getFaustInstrument();
        if (!inst) continue;

        auto& events = seq->events;

        while (framesRemaining > 0) {
            long samplesToNextWrap = seq->totalDurationSamples - seqWrapper->currentSample;
            if (samplesToNextWrap <= 0) {
                seqWrapper->currentSample = 0;
                seqWrapper->nextEventIndex = 0;
                samplesToNextWrap = seq->totalDurationSamples;
            }
            long framesToProcess = std::min(framesRemaining, samplesToNextWrap);

            // Evaluate all events that fall within this sub-block's sample range
            while (seqWrapper->isPlaying && seqWrapper->nextEventIndex < events.size()) {
                auto& ev = events[seqWrapper->nextEventIndex];
                
                long effectiveOffset = ev.sampleOffset;
                if (mHumanize.load(std::memory_order_relaxed)) {
                    effectiveOffset += getDeterministicJitter(seqWrapper->nextEventIndex, seqWrapper->sequenceObj->instrumentID);
                }
                
                if (effectiveOffset <= seqWrapper->currentSample + framesToProcess) {
                    if (ev.type == UMLEventType::NoteOn) {
                        int instID = seqWrapper->sequenceObj->instrumentID;
                        if (instID == 32) {
                            updateDSPParamsVoice(seqWrapper, ev.frequency, ev.velocity, ev.vowelVal);
                        } else {
                            updateDSPParams(seqWrapper, ev.frequency, ev.velocity, ev.strikeVal, ev.note);
                        }
                        if (inst) {
                            float durationSec = static_cast<float>(ev.durationSamples) / inst->getSampleRate();
                            
                            float baseVelocity = inst->getDefaultVelocity();
                            if (seqWrapper->sequenceObj->initialParams.count("velocity")) {
                                baseVelocity = seqWrapper->sequenceObj->initialParams["velocity"];
                            }
                            
                            float dynamicVelocity;
                            if (ev.velocity >= 0.0f) {
                                dynamicVelocity = ev.velocity;
                            } else if (seqWrapper->sequenceObj->initialParams.count("velocity")) {
                                dynamicVelocity = baseVelocity;
                            } else {
                                float r = std::min(durationSec / 0.5f, 1.0f);
                                dynamicVelocity = baseVelocity + (1.0f - baseVelocity) * (1.0f - r);
                            }
                            
                            float baseGlide = inst->getDSPGlideParam();
                            if (seqWrapper->sequenceObj->initialParams.count("glide")) {
                                baseGlide = seqWrapper->sequenceObj->initialParams["glide"];
                            }

                            float tenPercentTime = durationSec * 0.10f;
                            float dynamicGlide = baseGlide;
                            if (dynamicGlide > tenPercentTime) {
                                dynamicGlide = tenPercentTime;
                            }

                            inst->setParamImmediate("glide", dynamicGlide, -1);
                            inst->setParamImmediate("vibrato", 0.0f);
                            inst->setParamImmediate("vibrato_depth", 0.0f);
                            inst->setParamImmediate("vibrato_rate", 0.0f);
                            if (seqWrapper->sequenceObj->initialParams.count("chikari_freq")) {
                                inst->setParamImmediate("chikari_freq", seqWrapper->sequenceObj->initialParams["chikari_freq"], -1);
                            }
                            if (seqWrapper->sequenceObj->initialParams.count("freq_right")) {
                                inst->setParamImmediate("freq_right", seqWrapper->sequenceObj->initialParams["freq_right"], -1);
                            } else if (seqWrapper->sequenceObj->baseFreq > 0) {
                                inst->setParamImmediate("freq_right", seqWrapper->sequenceObj->baseFreq * 1.5f, -1);
                            }
                            inst->noteOn(ev.frequency, dynamicVelocity, ev.strikeVal, ev.amplitude);
                        }
                    } else if (ev.type == UMLEventType::NoteOff) {
                        if (inst) inst->noteOff();
                    } else if (ev.type == UMLEventType::FreqGlide) {
                        if (inst) {
                            float durSec = static_cast<float>(ev.durationSamples) / inst->getSampleRate();
                            if (ev.targetFrequency > 0.0f) inst->frequencyGlide(ev.targetFrequency, durSec);
                        }
                    } else if (ev.type == UMLEventType::AmpGlide) {
                        if (inst) {
                            float durSec = static_cast<float>(ev.durationSamples) / inst->getSampleRate();
                            if (ev.targetAmplitude >= 0.0f) inst->gainGlide(ev.targetAmplitude, durSec);
                        }
                    } else if (ev.type == UMLEventType::VibratoOn) {
                        if (inst) {
                            float vMaster = 0.6f;
                            float vDepth = 0.03f;
                            float vRate = 5.5f;
                            if (seqWrapper->sequenceObj->initialParams.count("vibrato")) {
                                vMaster = seqWrapper->sequenceObj->initialParams["vibrato"];
                            }
                            if (seqWrapper->sequenceObj->initialParams.count("vibrato_depth")) {
                                vDepth = seqWrapper->sequenceObj->initialParams["vibrato_depth"];
                            }
                            if (seqWrapper->sequenceObj->initialParams.count("vibrato_rate")) {
                                vRate = seqWrapper->sequenceObj->initialParams["vibrato_rate"];
                            }
                            inst->setParam("vibrato", vMaster);
                            inst->setParam("vibrato_depth", vDepth);
                            inst->setParam("vibrato_rate", vRate);
                        }
                    }
                    seqWrapper->nextEventIndex++;
                } else {
                    break;
                }
            }

            seqWrapper->currentSample += framesToProcess;
            framesRemaining -= framesToProcess;

            if (seqWrapper->currentSample >= seq->totalDurationSamples) {
                if (seq->loop || mLooping.load(std::memory_order_relaxed)) {
                    seqWrapper->currentSample = 0;
                    seqWrapper->nextEventIndex = 0;
                } else {
                    seqWrapper->isPlaying.store(false, std::memory_order_release);
                    notifyFinished(seq->name);
                    break;
                }
            }
        }
    }
    mMasterSampleCount += numFrames;
}

void SequenceOrchestrator::processBuffer(std::shared_ptr<ActiveSequence> seqWrapper, float* output, int numFrames) {
    // This is now a legacy stub if anyone still calls it directly
}

void SequenceOrchestrator::updateDSPParams(std::shared_ptr<ActiveSequence> seqWrapper, float freq, float vel, float strikeVal, const std::string& note) {
    if (!seqWrapper || !seqWrapper->sequenceObj) return;
    auto inst = seqWrapper->sequenceObj->getFaustInstrument();
    if (!inst) return;
    // freq, velocity, and strikeVal are handled per-voice inside FaustInstrument::noteOn
}

void SequenceOrchestrator::updateDSPParamsVoice(std::shared_ptr<ActiveSequence> seqWrapper, float freq, float vel, float vowelVal) {
    if (!seqWrapper || !seqWrapper->sequenceObj) return;
    auto inst = seqWrapper->sequenceObj->getFaustInstrument();
    if (!inst) return;

    if (vowelVal >= 0.0f) inst->setParam("vowel",  vowelVal);
}

void SequenceOrchestrator::enableDiagnostics(bool enable) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    for (auto& pair : mActiveSequences) {
        if (pair.second && pair.second->sequenceObj) {
            auto inst = pair.second->sequenceObj->getFaustInstrument();
            if (inst) inst->enableDiagnostics(enable);
        }
    }
}

void SequenceOrchestrator::dumpInstrumentDiagnostics() {
    std::lock_guard<std::mutex> lock(mStateMutex);
    for (auto& pair : mActiveSequences) {
        if (pair.second && pair.second->sequenceObj) {
            auto inst = pair.second->sequenceObj->getFaustInstrument();
            if (inst) inst->dumpDiagnostics();
        }
    }
}
