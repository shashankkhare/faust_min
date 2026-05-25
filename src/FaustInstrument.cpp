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
 * @file FaustInstrument.cpp
 * @brief Implementation file for FaustInstrument
 * 
 * DESIGN: Base class for all synthesis engines. It provides thread-safe parameter interpolation (Glides) and manages the lifecycle of the underlying Faust DSP instance.
 */

#include "FaustInstrument.hpp"
#include "InstrumentMapper.hpp"
#include "FaustDayanDSP.hpp"
#include "FaustBayanDSP.hpp"
#include "FaustKickDSP.hpp"
#include "FaustSnareDSP.hpp"
#include "FaustHihatDSP.hpp"
#include "FaustTomDSP.hpp"
#include "FaustRideDSP.hpp"
#include "FaustBellDSP.hpp"
#include "FaustBowlDSP.hpp"
#include "FaustSitarDSP.hpp"
#include "FaustFluteDSP.hpp"
#include "FaustTanpuraDSP.hpp"
#include "FaustPianoDSP.hpp"
#include "FaustSaxDSP.hpp"
#include "FaustCowbellDSP.hpp"
#include "FaustTrumpetDSP.hpp"
#include "FaustShakuhachiDSP.hpp"
#include "FaustBansuriDSP.hpp"
#include "FaustViolinDSP.hpp"
#include "FaustRainmakerDSP.hpp"
#include "FaustChurchBellDSP.hpp"
#include "FaustAcoustic_guitarDSP.hpp"
#include "FaustElectric_guitarDSP.hpp"
#include "FaustBassDSP.hpp"
#include "FaustCelloDSP.hpp"
#include "FaustCricketDSP.hpp"
#include "FaustCuckooDSP.hpp"
#include "FaustWaterfallDSP.hpp"
#include "FaustDjembeDSP.hpp"
#include "FaustMarimbaDSP.hpp"
#include "FaustCongaDSP.hpp"
#include "FaustBongoDSP.hpp"
#include "FaustVoiceDSP.hpp"
#include <faust/dsp/interpreter-dsp.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

FaustInstrument::FaustInstrument(int instrumentID, DSPExecutionType execType,
                                 float sampleRate, float gain, float freq, float velocity, float amplitude) 
    : mInstrumentID(instrumentID), mExecType(execType), mSampleRate(sampleRate), mGain(gain),
      mFrequency(freq), mVelocity(velocity), mAmplitude(amplitude), mDuration(-1.0f), mAssignedWeight(1.0f), mReverbSend(0.0f), mGateOpen(false),
      mTargetFrames(0), mElapsedFrames(0), mDecayFramesTarget(0), mDecayElapsedFrames(0),
      mVelGlideActive(false), mVelGlideStart(velocity), mVelGlideTarget(velocity), mVelGlideFramesTotal(0), mVelGlideFramesElapsed(0),
      mFreqGlideActive(false), mFreqGlideStart(freq), mFreqGlideTarget(freq), mFreqGlideFramesTotal(0), mFreqGlideFramesElapsed(0),
      mGainGlideActive(false), mGainGlideStart(gain), mGainGlideTarget(gain), mGainGlideFramesTotal(0), mGainGlideFramesElapsed(0),
      mStreamDevice(nullptr), mDSPFactory(nullptr) {
          
    mRenderBuffer = new float[InstrumentMapper::MAX_FRAMES_PER_BUFFER * 2];
    mEventQueue.reserve(128);

    if (instrumentID != -1) {
        loadTargetDSP();
    }
}

FaustInstrument::~FaustInstrument() {
    stopInternalStream();
    unloadDSP();
    if (mRenderBuffer) delete[] mRenderBuffer;
}

void FaustInstrument::setDSP(dsp* newDSP, DSPExecutionType execType) {
    if (!newDSP) return;
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mExecType = execType;
    mDSP.reset(newDSP);
    mDSP->init(static_cast<int>(mSampleRate));
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
    if (mFrequency >= 0.0f) {
        setFrequency(mFrequency);
    } else {
        if (mUI->getParamZone("freq") != nullptr) {
            mFrequency = mUI->getParamValue("freq");
        } else if (mUI->getParamZone("frequency") != nullptr) {
            mFrequency = mUI->getParamValue("frequency");
        } else {
            mFrequency = 261.63f;
        }
    }
    if (mVelocity >= 0.0f) {
        setVelocity(mVelocity);
    } else {
        if (mUI->getParamZone("velocity") != nullptr) {
            mVelocity = mUI->getParamValue("velocity");
        } else if (mUI->getParamZone("vel") != nullptr) {
            mVelocity = mUI->getParamValue("vel");
        } else {
            mVelocity = 1.0f;
        }
    }
    if (mAmplitude >= 0.0f) {
        setAmplitude(mAmplitude);
    } else {
        mAmplitude = 1.0f;
    }
    if (mGain >= 0.0f) {
        setGain(mGain);
    } else {
        if (mUI->getParamZone("gain") != nullptr) {
            mGain = mUI->getParamValue("gain");
        } else if (mUI->getParamZone("vol") != nullptr) {
            mGain = mUI->getParamValue("vol");
        } else {
            mGain = 1.0f;
        }
    }
}

void FaustInstrument::unloadDSP() {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mUI.reset();
    mDSP.reset();
    if (mExecType == DSPExecutionType::InterpretedByte && mDSPFactory) {
        deleteInterpreterDSPFactory(static_cast<interpreter_dsp_factory*>(mDSPFactory));
        mDSPFactory = nullptr;
    }
}

void FaustInstrument::loadTargetDSP() {
    if (mDSP) return;
    unloadDSP();

    std::string candidateDSPPath = InstrumentMapper::getDSPPathForID(mInstrumentID, "");
    std::string csvPath = candidateDSPPath;
    if (csvPath.length() > 4 && csvPath.substr(csvPath.length() - 4) == ".dsp") {
        csvPath = csvPath.substr(0, csvPath.length() - 4) + ".csv";
    }

    mLUTRecords.clear();
    mLUTActive = false;
    std::ifstream csvFile(csvPath);
    if (csvFile.is_open()) {
        std::string headerLine;
        if (std::getline(csvFile, headerLine)) {
            std::vector<std::string> columns;
            std::stringstream hss(headerLine);
            std::string colName;
            while (std::getline(hss, colName, ',')) {
                while (!colName.empty() && std::isspace(colName.front())) colName.erase(colName.begin());
                while (!colName.empty() && std::isspace(colName.back())) colName.pop_back();
                columns.push_back(colName);
            }

            std::string rLine;
            while (std::getline(csvFile, rLine)) {
                if (rLine.empty() || rLine[0] == '#' || rLine.find("//") == 0) continue;
                std::stringstream rss(rLine);
                std::string cell;
                float rowFreq = 0.0f;
                float rowAmp = 1.0f;
                std::map<std::string, float> paramsMap;
                int cIdx = 0;
                while (std::getline(rss, cell, ',')) {
                    if (cIdx < columns.size()) {
                        try {
                            float val = std::stof(cell);
                            if (columns[cIdx] == "frequency" || columns[cIdx] == "freq" || cIdx == 0) {
                                rowFreq = val;
                            } else if (columns[cIdx] == "amplitude" || columns[cIdx] == "amp" || cIdx == 1) {
                                rowAmp = val;
                            } else {
                                paramsMap[columns[cIdx]] = val;
                            }
                        } catch (...) {}
                    }
                    cIdx++;
                }
                if (rowFreq > 0.0f && !paramsMap.empty()) {
                    mLUTRecords.push_back({rowFreq, rowAmp, paramsMap});
                }
            }
        }
        csvFile.close();
        if (!mLUTRecords.empty()) {
            std::sort(mLUTRecords.begin(), mLUTRecords.end(), [](const LUTRecord& a, const LUTRecord& b) {
                return a.frequency < b.frequency;
            });
            mLUTActive = true;
            printf("[Native] SUCCESS: Auto-constructed %zu LUT records from companion CSV '%s'\n", mLUTRecords.size(), csvPath.c_str());
            fflush(stdout);
        }
    }

    if (mExecType == DSPExecutionType::StaticCompiled) {
        switch (mInstrumentID) {
            case 0:  setDSP(new FaustDayanDSP(), mExecType); break;
            case 1:  setDSP(new FaustBayanDSP(), mExecType); break;
            case 2:  setDSP(new FaustKickDSP(), mExecType); break;
            case 3:  setDSP(new FaustSnareDSP(), mExecType); break;
            case 4:  setDSP(new FaustHihatDSP(), mExecType); break;
            case 5:  setDSP(new FaustTomDSP(), mExecType); break;
            case 6:  setDSP(new FaustRideDSP(), mExecType); break;
            case 7:  setDSP(new FaustBellDSP(), mExecType); break;
            case 8:  setDSP(new FaustBowlDSP(), mExecType); break;
            case 9:  setDSP(new FaustSitarDSP(), mExecType); break;
            case 10: setDSP(new FaustFluteDSP(), mExecType); break;
            case 11: setDSP(new FaustTanpuraDSP(), mExecType); break;
            case 12: setDSP(new FaustPianoDSP(), mExecType); break;
            case 13: setDSP(new FaustSaxDSP(), mExecType); break;
            case 14: setDSP(new FaustCowbellDSP(), mExecType); break;
            case 15: setDSP(new FaustTrumpetDSP(), mExecType); break;
            case 16: setDSP(new FaustShakuhachiDSP(), mExecType); break;
            case 17: setDSP(new FaustBansuriDSP(), mExecType); break;
            case 18: setDSP(new FaustViolinDSP(), mExecType); break;
            case 19: setDSP(new FaustRainmakerDSP(), mExecType); break;
            case 20: setDSP(new FaustChurchBellDSP(), mExecType); break;
            case 21: setDSP(new FaustAcoustic_guitarDSP(), mExecType); break;
            case 22: setDSP(new FaustElectric_guitarDSP(), mExecType); break;
            case 23: setDSP(new FaustBassDSP(), mExecType); break;
            case 24: setDSP(new FaustCelloDSP(), mExecType); break;
            case 25: setDSP(new FaustCricketDSP(), mExecType); break;
            case 26: setDSP(new FaustCuckooDSP(), mExecType); break;
            case 27: setDSP(new FaustWaterfallDSP(), mExecType); break;
            case 28: setDSP(new FaustDjembeDSP(), mExecType); break;
            case 29: setDSP(new FaustMarimbaDSP(), mExecType); break;
            case 30: setDSP(new FaustCongaDSP(), mExecType); break;
            case 31: setDSP(new FaustBongoDSP(), mExecType); break;
            case 32: setDSP(new FaustVoiceDSP(), mExecType); break;
            default: setDSP(new FaustDayanDSP(), mExecType); break;
        }
    } else if (mExecType == DSPExecutionType::InterpretedByte) {
        std::string path = InstrumentMapper::getDSPPathForID(mInstrumentID, "");
        std::ifstream ifs(path);
        if (ifs.is_open()) {
            std::stringstream ss;
            ss << ifs.rdbuf();
            std::string source = ss.str();
            
            std::string err;
            std::string libDir = InstrumentMapper::DEFAULT_LIB_DIR;
            const char* argv[] = { "-I", libDir.c_str() };
            interpreter_dsp_factory* factory = createInterpreterDSPFactoryFromFile(path, 2, argv, err);
            if (factory) {
                dsp* instDSP = factory->createDSPInstance();
                if (instDSP) {
                    printf("[Native] SUCCESS: Faust Bytecode Interpreter successfully compiled DSP file '%s'\n", path.c_str());
                    if (!err.empty()) {
                        printf("[Native] Compiler Warnings: %s\n", err.c_str());
                    }
                    fflush(stdout);
                    mDSPFactory = factory;
                    mDSP.reset(instDSP);
                    mDSP->init(static_cast<int>(mSampleRate));
                    mUI.reset(new MapUI());
                    mDSP->buildUserInterface(mUI.get());
                    if (mFrequency >= 0.0f) {
                        setFrequency(mFrequency);
                    } else {
                        if (mUI->getParamZone("freq") != nullptr) {
                            mFrequency = mUI->getParamValue("freq");
                        } else if (mUI->getParamZone("frequency") != nullptr) {
                            mFrequency = mUI->getParamValue("frequency");
                        } else {
                            mFrequency = 261.63f;
                        }
                    }
                    if (mVelocity >= 0.0f) {
                        setVelocity(mVelocity);
                    } else {
                        if (mUI->getParamZone("velocity") != nullptr) {
                            mVelocity = mUI->getParamValue("velocity");
                        } else if (mUI->getParamZone("vel") != nullptr) {
                            mVelocity = mUI->getParamValue("vel");
                        } else {
                            mVelocity = 1.0f;
                        }
                    }
                    if (mAmplitude >= 0.0f) {
                        setAmplitude(mAmplitude);
                    } else {
                        mAmplitude = 1.0f;
                    }
                    if (mGain >= 0.0f) {
                        setGain(mGain);
                    } else {
                        if (mUI->getParamZone("gain") != nullptr) {
                            mGain = mUI->getParamValue("gain");
                        } else if (mUI->getParamZone("vol") != nullptr) {
                            mGain = mUI->getParamValue("vol");
                        } else {
                            mGain = 1.0f;
                        }
                    }
                } else {
                    std::cerr << "[Native] WARNING: Interpreter factory failed to instantiate DSP (libfaust limitation). Falling back to StaticCompiled mode." << std::endl;
                    deleteInterpreterDSPFactory(factory);
                    mDSPFactory = nullptr;
                    mExecType = DSPExecutionType::StaticCompiled;
                    loadTargetDSP();
                }
            } else {
                std::cerr << "[Native] Faust Compilation failed for ID " << mInstrumentID << ": " << err << std::endl;
                std::cerr << "[Native] Falling back to StaticCompiled mode." << std::endl;
                mExecType = DSPExecutionType::StaticCompiled;
                loadTargetDSP();
            }
        } else {
            std::cerr << "[Native] ERROR: Could not open DSP file path: " << path << std::endl;
        }
    }
}

void FaustInstrument::setSampleRate(float sampleRate) {
    if (mSampleRate == sampleRate && mDSP) return;
    mSampleRate = sampleRate;
    if (mDSP) {
        mDSP->init(static_cast<int>(sampleRate));
        if (mFrequency >= 0.0f) setFrequency(mFrequency);
        if (mVelocity >= 0.0f) setVelocity(mVelocity);
        if (mAmplitude >= 0.0f) setAmplitude(mAmplitude);
        if (mGain >= 0.0f) setGain(mGain);
    }
}

void FaustInstrument::setParamImmediate(const char* shortName, float val) {
    if (!mUI) return;

    std::string key(shortName);
    auto it = mParamAddressCache.find(key);
    if (it != mParamAddressCache.end()) {
        // Cache Hit: Silent in production, but let's keep it minimal for proof
        mUI->setParamValue(it->second, val);
        return;
    }

    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            // printf("[Native Trace] CACHE MISS: Parameter '%s' resolved to '%s'\n", shortName, addr.c_str());
            mParamAddressCache[key] = addr;
            mUI->setParamValue(addr, val);
            break;
        }
    }
    // fflush(stdout);
}

void FaustInstrument::setParam(const char* shortName, float val) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mEventQueue.push_back({shortName, val});
}

void FaustInstrument::setFrequency(float freq) {
    mFrequency = freq;
    setParam("freq", freq);
    applyDynamicLUTParams(freq, mAmplitude);
}

void FaustInstrument::setFrequencyImmediate(float freq) {
    mFrequency = freq;
    setParamImmediate("freq", freq);
    applyDynamicLUTParams(freq, mAmplitude);
}

void FaustInstrument::setGain(float gain) {
    mGain = gain;
    setParam("gain", gain);
}

void FaustInstrument::setGainImmediate(float gain) {
    mGain = gain;
    setParamImmediate("gain", gain);
}

void FaustInstrument::setVelocity(float velocity) {
    mVelocity = velocity;
    setParam("velocity", velocity);
}

void FaustInstrument::setVelocityImmediate(float velocity) {
    mVelocity = velocity;
    setParamImmediate("velocity", velocity);
}

void FaustInstrument::setAmplitude(float amplitude) {
    mAmplitude = amplitude;
    if (!mLUTActive) setParam("gain", amplitude);
    applyDynamicLUTParams(mFrequency, mAmplitude);
}

void FaustInstrument::setAmplitudeImmediate(float amplitude) {
    mAmplitude = amplitude;
    if (!mLUTActive) setParamImmediate("gain", amplitude);
    applyDynamicLUTParams(mFrequency, mAmplitude);
}

void FaustInstrument::setDuration(float seconds) {
    mDuration = seconds;
    mTargetFrames = static_cast<long>(seconds * mSampleRate);
}

void FaustInstrument::setParameter(const char* name, float value) {
    setParam(name, value);
}

float FaustInstrument::getGain() const { return mGain; }
float FaustInstrument::getFrequency() const { return mFrequency; }
float FaustInstrument::getVelocity() const { return mVelocity; }
float FaustInstrument::getAmplitude() const { return mAmplitude; }
float FaustInstrument::getDuration() const { return mDuration; }
float FaustInstrument::getReverbSend() const { return mReverbSend; }
float FaustInstrument::getSampleRate() const { return mSampleRate; }

void FaustInstrument::setReverbSend(float send) { mReverbSend = send; }
DSPExecutionType FaustInstrument::getExecutionType() const { return mExecType; }

void FaustInstrument::velocityGlide(float targetVelocity, float durationSeconds) {
    mVelGlideStart = mVelocity;
    mVelGlideTarget = targetVelocity;
    mVelGlideFramesTotal = static_cast<long>(durationSeconds * mSampleRate);
    mVelGlideFramesElapsed = 0;
    mVelGlideActive = (mVelGlideFramesTotal > 0);
    if (!mVelGlideActive) {
        setVelocity(targetVelocity);
    }
}

void FaustInstrument::frequencyGlide(float targetFreq, float durationSeconds) {
    mFreqGlideStart = mFrequency;
    mFreqGlideTarget = targetFreq;
    mFreqGlideFramesTotal = static_cast<long>(durationSeconds * mSampleRate);
    mFreqGlideFramesElapsed = 0;
    mFreqGlideActive = (mFreqGlideFramesTotal > 0);
    if (!mFreqGlideActive) {
        setFrequency(targetFreq);
    }
}

void FaustInstrument::gainGlide(float targetGain, float durationSeconds) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mGainGlideStart = mGain;
    mGainGlideTarget = targetGain;
    mGainGlideFramesTotal = static_cast<long>(durationSeconds * mSampleRate);
    mGainGlideFramesElapsed = 0;
    mGainGlideActive = (mGainGlideFramesTotal > 0);
    if (!mGainGlideActive) {
        setGain(targetGain);
    }
}

void FaustInstrument::setAssignedWeight(float weight) { mAssignedWeight = weight; }
float FaustInstrument::getAssignedWeight() const { return mAssignedWeight; }

void FaustInstrument::noteOn(float freq, float vel, float strikeVal, float amp) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);

    mGateOpen = true;
    mElapsedFrames = 0;
    mTargetFrames = 0; // Infinite until noteOff
    
    // Disable any active glides when a hard note-on is received
    mVelGlideActive = false;
    mFreqGlideActive = false;
    mGainGlideActive = false;

    if (freq > 0.0f) setFrequency(freq);
    if (vel >= 0.0f) setVelocity(vel);
    if (amp >= 0.0f) setAmplitudeImmediate(amp);
    
    if (strikeVal >= 0.0f) setParam("strike", strikeVal);

    if (mLUTActive) {
        applyDynamicLUTParams(mFrequency, mAmplitude);
    }
    
    setParam("gate", 0.0f);
    setParam("gate", 1.0f);
}

void FaustInstrument::noteOff(float decayTailMs) {
    // Manual authority overrides timeline countdown instantly
    mTargetFrames = 0;
    mGateOpen = false;
    setParam("gate", 0.0f);

    if (decayTailMs > 0.0f) {
        mDecayFramesTarget = static_cast<long>((decayTailMs / 1000.0f) * mSampleRate);
        mDecayElapsedFrames = 0;
    } else {
        mDecayFramesTarget = 0;
        onNoteFinish(); // Immediate event completion if no physical tail expected
    }
}

void FaustInstrument::processInternalGlides(int numFrames) {
    if (mVelGlideActive) {
        mVelGlideFramesElapsed += numFrames;
        if (mVelGlideFramesElapsed >= mVelGlideFramesTotal) {
            mVelGlideActive = false;
            setVelocityImmediate(mVelGlideTarget);
        } else {
            float progress = static_cast<float>(mVelGlideFramesElapsed) / mVelGlideFramesTotal;
            float currentVel = mVelGlideStart + (mVelGlideTarget - mVelGlideStart) * progress;
            setVelocityImmediate(currentVel);
        }
    }

    if (mFreqGlideActive) {
        mFreqGlideFramesElapsed += numFrames;
        if (mFreqGlideFramesElapsed >= mFreqGlideFramesTotal) {
            mFreqGlideActive = false;
            setFrequencyImmediate(mFreqGlideTarget);
        } else {
            float progress = static_cast<float>(mFreqGlideFramesElapsed) / mFreqGlideFramesTotal;
            float currentFreq = mFreqGlideStart + (mFreqGlideTarget - mFreqGlideStart) * progress;
            setFrequencyImmediate(currentFreq);
        }
    }

    if (mGainGlideActive) {
        mGainGlideFramesElapsed += numFrames;
        if (mGainGlideFramesElapsed >= mGainGlideFramesTotal) {
            mGainGlideActive = false;
            setGainImmediate(mGainGlideTarget);
        } else {
            float progress = static_cast<float>(mGainGlideFramesElapsed) / mGainGlideFramesTotal;
            float currentGain = mGainGlideStart + (mGainGlideTarget - mGainGlideStart) * progress;
            setGainImmediate(currentGain);
        }
    }
}

void FaustInstrument::render(int numFrames, float* buffer) {
    if (!mDSP) return;
    processInternalGlides(numFrames);
    
    FAUSTFLOAT* outputs[2] = { mRenderBuffer, mRenderBuffer + numFrames };
    int nOuts = mDSP->getNumOutputs();
    mDSP->compute(numFrames, nullptr, outputs);

    if (nOuts == 1) {
        for (int i = 0; i < numFrames; ++i) {
            float val = mRenderBuffer[i];
            if (mGain != 1.0f) val *= mGain;
            buffer[i * 2] = val;
            buffer[i * 2 + 1] = val;
        }
    } else if (nOuts == 2) {
        for (int i = 0; i < numFrames; ++i) {
            float valL = outputs[0][i];
            float valR = outputs[1][i];
            if (mGain != 1.0f) { valL *= mGain; valR *= mGain; }
            buffer[i * 2] = valL;
            buffer[i * 2 + 1] = valR;
        }
    }
}

void FaustInstrument::onNoteFinish() {
    // completed its duration
}

void FaustInstrument::processRealtimeStream(float* buffer, int numFrames) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    if (!mDSP) {
        std::memset(buffer, 0, sizeof(float) * numFrames);
        return;
    }

    // To prevent parameter updates from dividing the render block into large silent gaps/latency,
    // we use a sub-block size of 1 sample for intermediate events, leaving the
    // remaining frames for the final state.
    int framesPerSubBlock = 1;
    int framesProcessed = 0;

    int nOuts = mDSP->getNumOutputs();
    FAUSTFLOAT* outputs[2] = { mRenderBuffer, mRenderBuffer + numFrames };

    for (const auto& ev : mEventQueue) {
        if (framesPerSubBlock > 0 && (framesProcessed + framesPerSubBlock <= numFrames)) {
            processInternalGlides(framesPerSubBlock);
            mDSP->compute(framesPerSubBlock, nullptr, outputs);
            float* chunkBuffer = buffer + (framesProcessed * 2);

            if (nOuts == 1) {
                for (int i = 0; i < framesPerSubBlock; ++i) {
                    float val = mRenderBuffer[i];
                    if (mGain != 1.0f) val *= mGain;
                    chunkBuffer[i * 2] = val;
                    chunkBuffer[i * 2 + 1] = val;
                }
            } else if (nOuts == 2) {
                for (int i = 0; i < framesPerSubBlock; ++i) {
                    float valL = outputs[0][i];
                    float valR = outputs[1][i];
                    if (mGain != 1.0f) { valL *= mGain; valR *= mGain; }
                    chunkBuffer[i * 2] = valL;
                    chunkBuffer[i * 2 + 1] = valR;
                }
            }

            if (mGateOpen) {
                long prevElapsed = mElapsedFrames;
                mElapsedFrames += framesPerSubBlock;
                if (mTargetFrames > 0 && mElapsedFrames >= mTargetFrames && prevElapsed < mTargetFrames) {
                    onNoteFinish();
                }
            }
            framesProcessed += framesPerSubBlock;
        }
        setParamImmediate(ev.paramName.c_str(), ev.value);
    }

    int remaining = numFrames - framesProcessed;
    if (remaining > 0) {
        processInternalGlides(remaining);
        mDSP->compute(remaining, nullptr, outputs);
        float* chunkBuffer = buffer + (framesProcessed * 2);

        if (nOuts == 1) {
            for (int i = 0; i < remaining; ++i) {
                float val = mRenderBuffer[i];
                if (mGain != 1.0f) val *= mGain;
                chunkBuffer[i * 2] = val;
                chunkBuffer[i * 2 + 1] = val;
            }
        } else if (nOuts == 2) {
            for (int i = 0; i < remaining; ++i) {
                float valL = outputs[0][i];
                float valR = outputs[1][i];
                if (mGain != 1.0f) { valL *= mGain; valR *= mGain; }
                chunkBuffer[i * 2] = valL;
                chunkBuffer[i * 2 + 1] = valR;
            }
        }

        if (mGateOpen) {
            long prevElapsed = mElapsedFrames;
            mElapsedFrames += remaining;
            if (mTargetFrames > 0 && mElapsedFrames >= mTargetFrames && prevElapsed < mTargetFrames) {
                onNoteFinish();
            }
        }
    }

    mEventQueue.clear();
}

void FaustInstrument::startInternalStream(float sampleRate) {
    mSampleRate = sampleRate;
}

void FaustInstrument::stopInternalStream() {
    mIsStreamActive = false;
}

void FaustInstrument::applyDynamicLUTParams(float freq, float amp) {
    if (!mLUTActive || mLUTRecords.empty()) return;

    // Utilize normalized vector proximity distance: d = sqrt( ((f-f1)/(f+f1))^2 + ((a-a1)/(a+a1))^2 )
    // Perform robust Inverse Distance Weighting (IDW) interpolation across all dynamic parameter columns
    std::map<std::string, float> accumulatedParams;
    std::map<std::string, float> totalWeights;

    for (const auto& rec : mLUTRecords) {
        float fDenom = freq + rec.frequency;
        float fNorm = (fDenom > 0.0001f) ? (freq - rec.frequency) / fDenom : 0.0f;

        float aDenom = amp + rec.amplitude;
        float aNorm = (aDenom > 0.0001f) ? (amp - rec.amplitude) / aDenom : 0.0f;

        float dist = std::sqrt(fNorm * fNorm + aNorm * aNorm);

        // If extremely close to a calibrated node, snap directly to its targets to preserve boundary perfection
        if (dist < 0.00001f) {
            for (const auto& pair : rec.targetParams) {
                setParam(pair.first.c_str(), pair.second);
            }
            return;
        }

        float weight = 1.0f / (dist * dist);
        for (const auto& pair : rec.targetParams) {
            accumulatedParams[pair.first] += pair.second * weight;
            totalWeights[pair.first] += weight;
        }
    }

    for (const auto& pair : accumulatedParams) {
        float wSum = totalWeights[pair.first];
        if (wSum > 0.0f) {
            float val = pair.second / wSum;
            setParam(pair.first.c_str(), val);
        }
    }
}
