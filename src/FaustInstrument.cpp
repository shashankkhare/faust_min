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
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <limits>
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
#include "FaustMridangamDSP.hpp"
#include "FaustGhatamDSP.hpp"
#include "FaustMarimbaDSP.hpp"
#include "FaustCongaDSP.hpp"
#include "FaustBongoDSP.hpp"
#include "FaustVoiceDSP.hpp"
#include "FaustShakerDSP.hpp"
#include "FaustSeawaveDSP.hpp"
#include "FaustChougongDSP.hpp"
#include "FaustLagngaDSP.hpp"
#include "FaustDholakDSP.hpp"
#include "FaustDholDSP.hpp"
#include "FaustTibetanbowlDSP.hpp"
#include "FaustGuzhengDSP.hpp"
#include "FaustErhuDSP.hpp"
#include "FaustWindDSP.hpp"
#include "FaustThunderDSP.hpp"
#include "FaustDaguDSP.hpp"
#include "FaustSarodDSP.hpp"
#include "FaustDiziDSP.hpp"
#include "FaustSantoorDSP.hpp"
#include "FaustTumbiDSP.hpp"
#include "FaustNgachenDSP.hpp"
#include "FaustMridangamDSP.hpp"
#include "FaustGhatamDSP.hpp"
#include "FaustPanfluteDSP.hpp"
#include "FaustNativeamericanfluteDSP.hpp"
#ifndef FAUST_DISABLE_INTERPRETER
#include <faust/dsp/interpreter-dsp.h>
#endif
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

FaustInstrument::FaustInstrument(int instrumentID, DSPExecutionType execType,
                                 float sampleRate, float gain, float freq, float velocity, float amplitude) 
    : mInstrumentID(instrumentID), mExecType(execType), mSampleRate(sampleRate), mGain(gain),
      mFrequency(freq), mVelocity(velocity), mAmplitude(1.0f), mDuration(-1.0f), mReverbSend(0.0f), mGateOpen(false),
      mTargetFrames(0), mElapsedFrames(0), mDecayFramesTarget(0), mDecayElapsedFrames(0),
      mVelGlideActive(false), mVelGlideStart(velocity), mVelGlideTarget(velocity), mVelGlideFramesTotal(0), mVelGlideFramesElapsed(0),
      mFreqGlideActive(false), mFreqGlideStart(freq), mFreqGlideTarget(freq), mFreqGlideFramesTotal(0), mFreqGlideFramesElapsed(0),
      mGainGlideActive(false), mGainGlideStart(gain), mGainGlideTarget(gain), mGainGlideFramesTotal(0), mGainGlideFramesElapsed(0),
      mIsPolyphonic(false), mNumVoices(1), mNextVoice(0), mVoiceScratchBuffer(nullptr),
      mStreamDevice(nullptr), mDSPFactory(nullptr) {
          
    mRenderBuffer = new float[InstrumentMapper::MAX_FRAMES_PER_BUFFER * 2];
    mEventQueue.reserve(128);
    mDiagLogs.reserve(4096);

    if (instrumentID != -1) {
        loadTargetDSP();
    }
}

FaustInstrument::~FaustInstrument() {
    stopInternalStream();
    unloadDSP();
    if (mRenderBuffer) delete[] mRenderBuffer;
    if (mVoiceScratchBuffer) delete[] mVoiceScratchBuffer;
}

void FaustInstrument::setDSP(dsp* newDSP, DSPExecutionType execType) {
    if (!newDSP) return;
    mExecType = execType;
    addVoice(newDSP);
    initializeVoices();
}

void FaustInstrument::addVoice(dsp* newDSP) {
    if (!newDSP) return;
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mVoices.emplace_back(newDSP);
    mVoices.back()->init(static_cast<int>(mSampleRate));
    mVoiceUIs.emplace_back(new MapUI());
    mVoices.back()->buildUserInterface(mVoiceUIs.back().get());
    mVoiceFreqs.push_back(0.0f);
}

void FaustInstrument::initializeVoices() {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    if (mVoices.empty()) return;
    
    if (mFrequency >= 0.0f) {
        setFrequencyImmediate(mFrequency);
    } else {
        if (mVoiceUIs[0]->getParamZone("freq") != nullptr) {
            mFrequency = mVoiceUIs[0]->getParamValue("freq");
        } else if (mVoiceUIs[0]->getParamZone("frequency") != nullptr) {
            mFrequency = mVoiceUIs[0]->getParamValue("frequency");
        } else {
            mFrequency = 261.63f;
        }
    }
    if (mVelocity >= 0.0f) {
        setVelocityImmediate(mVelocity);
    } else {
        if (mVoiceUIs[0]->getParamZone("velocity") != nullptr) {
            mVelocity = mVoiceUIs[0]->getParamValue("velocity");
        } else if (mVoiceUIs[0]->getParamZone("vel") != nullptr) {
            mVelocity = mVoiceUIs[0]->getParamValue("vel");
        } else {
            mVelocity = 1.0f;
        }
    }
    mDefaultVelocity = mVelocity;
    if (mAmplitude >= 0.0f) {
        setAmplitudeImmediate(mAmplitude);
    } else {
        mAmplitude = 1.0f;
    }
    if (mGain >= 0.0f) {
        setGainImmediate(mGain);
    } else {
        if (mVoiceUIs[0]->getParamZone("gain") != nullptr) {
            mGain = mVoiceUIs[0]->getParamValue("gain");
        } else if (mVoiceUIs[0]->getParamZone("vol") != nullptr) {
            mGain = mVoiceUIs[0]->getParamValue("vol");
        } else {
            mGain = 1.0f;
        }
    }

    // Pre-warm the DSP to settle any internal parameter smoothers (like the 80ms glide)
    if (mSampleRate > 0) {
        int numOutputs = mVoices[0]->getNumOutputs();
        if (numOutputs > 0) {
            int settleFrames = static_cast<int>(mSampleRate * 0.1f); // 100ms
            float** dummyOutputs = new float*[numOutputs];
            for (int i = 0; i < numOutputs; i++) {
                dummyOutputs[i] = new float[settleFrames];
            }
            
            for (auto& v : mVoices) {
                v->compute(settleFrames, nullptr, dummyOutputs);
            }
            
            for (int i = 0; i < numOutputs; i++) {
                delete[] dummyOutputs[i];
            }
            delete[] dummyOutputs;
        }
    }
}

void FaustInstrument::unloadDSP() {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mVoiceUIs.clear();
    mVoices.clear();
#ifndef FAUST_DISABLE_INTERPRETER
    if (mExecType == DSPExecutionType::InterpretedByte && mDSPFactory) {
        deleteInterpreterDSPFactory(static_cast<interpreter_dsp_factory*>(mDSPFactory));
        mDSPFactory = nullptr;
    }
#endif
}

void FaustInstrument::loadTargetDSP() {
    // Force StaticCompiled execution mode for complex physical model DSPs that cause libfaust interpreter stack overflows
    if (mExecType == DSPExecutionType::InterpretedByte) {
        if (mInstrumentID >= 0 && mInstrumentID <= 53) {
            mExecType = DSPExecutionType::StaticCompiled;
        }
    }

    if (!mVoices.empty()) return;
    unloadDSP();

    mNumVoices = InstrumentMapper::getPolyphonyVoices(mInstrumentID);
    mIsPolyphonic = (mNumVoices > 1);
    if (mIsPolyphonic && mVoiceScratchBuffer == nullptr) {
        mVoiceScratchBuffer = new float[InstrumentMapper::MAX_FRAMES_PER_BUFFER * 2];
    }

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
                if (colName == "strike") mHasStrikeLUT = true;
            }

            std::string rLine;
            while (std::getline(csvFile, rLine)) {
                if (rLine.empty() || rLine[0] == '#' || rLine.find("//") == 0) continue;
                std::stringstream rss(rLine);
                std::string cell;
                float rowFreq = 0.0f;
                float rowVel = 1.0f;
                float rowStrike = 0.0f;
                std::map<std::string, float> paramsMap;
                int cIdx = 0;
                while (std::getline(rss, cell, ',')) {
                    if (cIdx < columns.size()) {
                        try {
                            float val = std::stof(cell);
                            if (columns[cIdx] == "frequency" || columns[cIdx] == "freq" || cIdx == 0) {
                                rowFreq = val;
                            } else if (columns[cIdx] == "velocity" || columns[cIdx] == "vel" || cIdx == 1) {
                                rowVel = val;
                            } else if (columns[cIdx] == "strike") {
                                rowStrike = val;
                            } else {
                                paramsMap[columns[cIdx]] = val;
                            }
                        } catch (...) {}
                    }
                    cIdx++;
                }
                if (rowFreq > 0.0f && !paramsMap.empty()) {
                    mLUTRecords.push_back({rowFreq, rowVel, rowStrike, paramsMap});
                }
            }
        }
        csvFile.close();
        if (!mLUTRecords.empty()) {
            std::sort(mLUTRecords.begin(), mLUTRecords.end(), [](const LUTRecord& a, const LUTRecord& b) {
                return a.frequency < b.frequency;
            });
            mLUTActive = true;
            printf("[Native] SUCCESS: Auto-constructed %llu LUT records from companion CSV '%s'\n", (unsigned long long)mLUTRecords.size(), csvPath.c_str());
            fflush(stdout);
        }
    }

    if (mExecType == DSPExecutionType::StaticCompiled) {
        for (int v = 0; v < mNumVoices; ++v) {
            switch (mInstrumentID) {
                case 0:  addVoice(new FaustDayanDSP()); break;
                case 1:  addVoice(new FaustBayanDSP()); break;
                case 2:  addVoice(new FaustKickDSP()); break;
                case 3:  addVoice(new FaustSnareDSP()); break;
                case 4:  addVoice(new FaustHihatDSP()); break;
                case 5:  addVoice(new FaustTomDSP()); break;
                case 6:  addVoice(new FaustRideDSP()); break;
                case 7:  addVoice(new FaustBellDSP()); break;
                case 8:  addVoice(new FaustBowlDSP()); break;
                case 9:  addVoice(new FaustSitarDSP()); break;
                case 10: addVoice(new FaustFluteDSP()); break;
                case 11: addVoice(new FaustTanpuraDSP()); break;
                case 12: addVoice(new FaustPianoDSP()); break;
                case 13: addVoice(new FaustSaxDSP()); break;
                case 14: addVoice(new FaustCowbellDSP()); break;
                case 15: addVoice(new FaustTrumpetDSP()); break;
                case 16: addVoice(new FaustShakuhachiDSP()); break;
                case 17: addVoice(new FaustBansuriDSP()); break;
                case 18: addVoice(new FaustViolinDSP()); break;
                case 19: addVoice(new FaustRainmakerDSP()); break;
                case 20: addVoice(new FaustChurchBellDSP()); break;
                case 21: addVoice(new FaustAcoustic_guitarDSP()); break;
                case 22: addVoice(new FaustElectric_guitarDSP()); break;
                case 23: addVoice(new FaustBassDSP()); break;
                case 24: addVoice(new FaustCelloDSP()); break;
                case 25: addVoice(new FaustCricketDSP()); break;
                case 26: addVoice(new FaustCuckooDSP()); break;
                case 27: addVoice(new FaustWaterfallDSP()); break;
                case 28: addVoice(new FaustDjembeDSP()); break;
                case 29: addVoice(new FaustMarimbaDSP()); break;
                case 30: addVoice(new FaustCongaDSP()); break;
                case 31: addVoice(new FaustBongoDSP()); break;
                case 32: addVoice(new FaustVoiceDSP()); break;
                case 33: addVoice(new FaustShakerDSP()); break;
                case 34: addVoice(new FaustSeawaveDSP()); break;
                case 35: addVoice(new FaustChougongDSP()); break;
                case 36: addVoice(new FaustLagngaDSP()); break;
                case 37: addVoice(new FaustDholakDSP()); break;
                case 38: addVoice(new FaustDholDSP()); break;
                case 39: addVoice(new FaustGuzhengDSP()); break;
                case 40: addVoice(new FaustErhuDSP()); break;
                case 41: addVoice(new FaustWindDSP()); break;
                case 42: addVoice(new FaustThunderDSP()); break;
                case 43: addVoice(new FaustDaguDSP()); break;
                case 44: addVoice(new FaustSarodDSP()); break;
                case 45: addVoice(new FaustSantoorDSP()); break;
                case 46: addVoice(new FaustTumbiDSP()); break;
                case 47: addVoice(new FaustTibetanbowlDSP()); break;
                case 48: addVoice(new FaustNgachenDSP()); break;
                case 49: addVoice(new FaustMridangamDSP()); break;
                case 50: addVoice(new FaustGhatamDSP()); break;
                case 51: addVoice(new FaustPanfluteDSP()); break;
                case 52: addVoice(new FaustNativeamericanfluteDSP()); break;
                case 53: addVoice(new FaustDiziDSP()); break;
                default: addVoice(new FaustDayanDSP()); break;
            }
        }
        initializeVoices();
    }
#ifndef FAUST_DISABLE_INTERPRETER
    else if (mExecType == DSPExecutionType::InterpretedByte) {
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
                mDSPFactory = factory;
                bool success = true;
                for (int v = 0; v < mNumVoices; ++v) {
                    dsp* instDSP = factory->createDSPInstance();
                    if (instDSP) {
                        addVoice(instDSP);
                    } else {
                        success = false;
                        break;
                    }
                }
                if (success) {
                    printf("[Native] SUCCESS: Faust Bytecode Interpreter successfully compiled DSP file '%s' with %d voices\n", path.c_str(), mNumVoices);
                    if (!err.empty()) {
                        printf("[Native] Compiler Warnings: %s\n", err.c_str());
                    }
                    fflush(stdout);
                    initializeVoices();
                } else {
                    std::cerr << "[Native] WARNING: Interpreter factory failed to instantiate DSP (libfaust limitation). Falling back to StaticCompiled mode." << std::endl;
                    mVoiceUIs.clear();
                    mVoices.clear();
                    deleteInterpreterDSPFactory(factory);
                    mDSPFactory = nullptr;
                    mExecType = DSPExecutionType::StaticCompiled;
                    loadTargetDSP();
                }
            } else {
                std::cerr << "[Native] Faust Compilation failed for ID " << mInstrumentID << ": " << err << std::endl;
                std::cerr << "[Native] Falling back to StaticCompiled mode." << std::endl;
                mVoiceUIs.clear();
                mVoices.clear();
                mExecType = DSPExecutionType::StaticCompiled;
                loadTargetDSP();
            }
        } else {
            std::cerr << "[Native] ERROR: Could not open DSP file path: " << path << std::endl;
        }
    }
#endif

    initParams();
}

void FaustInstrument::initParams() {
    if (mVoices.empty()) return;

    std::string iniPath = InstrumentMapper::getDSPPathForID(mInstrumentID, "");
    if (iniPath.length() > 4 && iniPath.substr(iniPath.length() - 4) == ".dsp") {
        iniPath = iniPath.substr(0, iniPath.length() - 4) + ".ini";
    }
    std::ifstream iniFile(iniPath);
    if (iniFile.is_open()) {
        std::string line;
        while (std::getline(iniFile, line)) {
            while (!line.empty() && std::isspace(line.front())) line.erase(line.begin());
            if (line.empty() || line[0] == '#' || line[0] == ';' || line.find("//") == 0) continue;
            
            auto pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string valStr = line.substr(pos + 1);
                while (!key.empty() && std::isspace(key.back())) key.pop_back();
                while (!valStr.empty() && std::isspace(valStr.front())) valStr.erase(valStr.begin());
                while (!valStr.empty() && std::isspace(valStr.back())) valStr.pop_back();
                try {
                    float val = std::stof(valStr);
                    setParamImmediate(key.c_str(), val);
                } catch(...) {}
            }
        }
        iniFile.close();
        printf("[Native] Loaded INI parameters from '%s'\n", iniPath.c_str());
        fflush(stdout);
    }
}

void FaustInstrument::setSampleRate(float sampleRate) {
    if (mSampleRate == sampleRate && !mVoices.empty()) return;
    mSampleRate = sampleRate;
    if (!mVoices.empty()) {
        for (auto& v : mVoices) v->init(static_cast<int>(sampleRate));
        if (mFrequency >= 0.0f) setFrequency(mFrequency);
        if (mVelocity >= 0.0f) setVelocity(mVelocity);
        if (mAmplitude >= 0.0f) setAmplitude(mAmplitude);
        if (mGain >= 0.0f) setGain(mGain);
    }
}

void FaustInstrument::setParamImmediate(const char* shortName, float val, int voiceIndex) {
    if (std::string(shortName) == "gain") {
        mGain = val;
        return;
    }
    
    if (mVoiceUIs.empty()) return;

    std::string key(shortName);
    auto it = mParamAddressCache.find(key);
    std::string addr = "";
    if (it != mParamAddressCache.end()) {
        addr = it->second;
    } else {
        for (int i = 0; i < mVoiceUIs[0]->getParamsCount(); i++) {
            std::string tempAddr = mVoiceUIs[0]->getParamAddress(i);
            // Extract the basename of the parameter (after the last '/')
            size_t lastSlash = tempAddr.find_last_of('/');
            std::string baseName = (lastSlash != std::string::npos) ? tempAddr.substr(lastSlash + 1) : tempAddr;
            
    // Check for EXACT match of the basename to avoid substring collisions (e.g. 'freq' matching 'chikari_freq')
            if (baseName == shortName || tempAddr == shortName) {
                mParamAddressCache[key] = tempAddr;
                addr = tempAddr;
                break;
            }
        }
    }

    if (!addr.empty()) {
        if (voiceIndex == -1) {
            for (auto& ui : mVoiceUIs) ui->setParamValue(addr, val);
        } else if (voiceIndex >= 0 && voiceIndex < mVoiceUIs.size()) {
            mVoiceUIs[voiceIndex]->setParamValue(addr, val);
        }
    }
}

void FaustInstrument::setParam(const char* shortName, float val, int voiceIndex) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mEventQueue.push_back({shortName, val, voiceIndex});
}

float FaustInstrument::getParam(const char* shortName) {
    if (mVoiceUIs.empty()) return 0.0f;

    std::string key(shortName);
    auto it = mParamAddressCache.find(key);
    std::string addr = "";
    if (it != mParamAddressCache.end()) {
        addr = it->second;
    } else {
        for (int i = 0; i < mVoiceUIs[0]->getParamsCount(); i++) {
            std::string tempAddr = mVoiceUIs[0]->getParamAddress(i);
            size_t lastSlash = tempAddr.find_last_of('/');
            std::string baseName = (lastSlash != std::string::npos) ? tempAddr.substr(lastSlash + 1) : tempAddr;
            if (baseName == key) {
                addr = tempAddr;
                mParamAddressCache[key] = addr;
                break;
            }
        }
    }
    
    if (addr.empty()) return 0.0f;
    return mVoiceUIs[0]->getParamValue(addr.c_str());
}

bool FaustInstrument::getParamBounds(const char* shortName, float& outMin, float& outMax) {
    if (mVoiceUIs.empty() || !mVoiceUIs[0]) return false;

    std::string key(shortName);
    auto it = mParamAddressCache.find(key);
    std::string addr = "";
    if (it != mParamAddressCache.end()) {
        addr = it->second;
    } else {
        for (int i = 0; i < mVoiceUIs[0]->getParamsCount(); i++) {
            std::string tempAddr = mVoiceUIs[0]->getParamAddress(i);
            size_t lastSlash = tempAddr.find_last_of('/');
            std::string baseName = (lastSlash != std::string::npos) ? tempAddr.substr(lastSlash + 1) : tempAddr;
            if (baseName == key) {
                addr = tempAddr;
                mParamAddressCache[key] = addr;
                break;
            }
        }
    }

    if (addr.empty()) return false;
    FAUSTFLOAT fmin, fmax;
    if (mVoiceUIs[0]->getParamBounds(addr, fmin, fmax)) {
        outMin = fmin;
        outMax = fmax;
        return true;
    }
    return false;
}

std::string FaustInstrument::getParametersJSON() {
    if (mVoiceUIs.empty() || !mVoiceUIs[0]) return "[]";
    
    std::stringstream ss;
    ss << "[";
    bool first = true;
    for (int i = 0; i < mVoiceUIs[0]->getParamsCount(); i++) {
        std::string fullPath = mVoiceUIs[0]->getParamAddress(i);
        size_t lastSlash = fullPath.find_last_of('/');
        std::string baseName = (lastSlash != std::string::npos) ? fullPath.substr(lastSlash + 1) : fullPath;
        
        FAUSTFLOAT fmin = 0, fmax = 1;
        mVoiceUIs[0]->getParamBounds(fullPath.c_str(), fmin, fmax);
        float val = mVoiceUIs[0]->getParamValue(fullPath.c_str());
        
        if (!first) ss << ",";
        ss << "{\"name\":\"" << baseName << "\",";
        ss << "\"address\":\"" << fullPath << "\",";
        ss << "\"min\":" << fmin << ",";
        ss << "\"max\":" << fmax << ",";
        ss << "\"value\":" << val << "}";
        first = false;
    }
    ss << "]";
    return ss.str();
}

void FaustInstrument::setFrequency(float freq) {
    mFrequency = freq;
    setParam("freq", freq, -1);
    applyDynamicLUTParams(freq, mAmplitude, -1);
}

void FaustInstrument::setFrequencyImmediate(float freq) {
    mFrequency = freq;
    setParamImmediate("freq", freq, -1);
    applyDynamicLUTParams(freq, mAmplitude, -1);
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
    if (!mLUTActive) setParam("gain", amplitude, -1);
    applyDynamicLUTParams(mFrequency, mAmplitude, -1);
}

void FaustInstrument::setAmplitudeImmediate(float amplitude) {
    mAmplitude = amplitude;
    if (!mLUTActive) setParamImmediate("gain", amplitude, -1);
    applyDynamicLUTParams(mFrequency, mAmplitude, -1);
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
float FaustInstrument::getDefaultVelocity() const { return mDefaultVelocity; }
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
    } else {
        if (mVoiceUIs[0]->getParamZone("glide") != nullptr) {
            mDSPGlideParam = mVoiceUIs[0]->getParamValue("glide");
        }
        setParamImmediate("glide", 0.0f, -1);
    }
}

void FaustInstrument::gainGlide(float targetGain, float durationSeconds) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    mGainGlideStart = mAmplitude;
    mGainGlideTarget = targetGain;
    mGainGlideFramesTotal = static_cast<long>(durationSeconds * mSampleRate);
    mGainGlideFramesElapsed = 0;
    mGainGlideActive = (mGainGlideFramesTotal > 0);
    if (!mGainGlideActive) {
        mAmplitude = targetGain;
        if (!mLUTActive) setParamImmediate("gain", targetGain, -1);
    }
}

void FaustInstrument::noteOn(float freq, float vel, float strikeVal) {
    if (vel <= 0.0f) return;

    std::lock_guard<std::recursive_mutex> lock(mDSPLock);

    mGateOpen = true;
    mElapsedFrames = 0;
    mTargetFrames = 0;
    mVelGlideActive = false;
    mFreqGlideActive = false;
    mGainGlideActive = false;

    int v = -1;

    // Check if we can reuse a voice already playing this exact frequency
    if (mIsPolyphonic && freq > 0.0f && mNumVoices > 0) {
        for (int i = 0; i < mNumVoices; ++i) {
            if (std::abs(mVoiceFreqs[i] - freq) < 0.1f) {
                v = i;
                break;
            }
        }
    }

    // If no matching voice was found, fall back to round-robin allocation
    if (v == -1) {
        v = mNextVoice;
        if (mNumVoices > 0)
            mNextVoice = (mNextVoice + 1) % mNumVoices;
        else
            v = 0;
    }

    // Stop the voice completely before re-triggering
    noteOff(v);
    // Explicitly zero the immediate gate value as well to clear smoothers instantly
    setParamImmediate("gate", 0.0f, v);

    if (freq > 0.0f) {
        mFrequency = freq;
        mVoiceFreqs[v] = freq; // Track frequency in O(1) array
        setParamImmediate("freq", freq, v);
    }

    if (vel >= 0.0f) {
        mVelocity = vel;
        setParamImmediate("velocity", vel, v);
    }

    if (mLUTActive)
        applyDynamicLUTParams(mFrequency, mVelocity, v);

    mStrikeVal = strikeVal;
    if (strikeVal >= 0.0f)
        setParamImmediate("strike", strikeVal, v);

    setParam("gate", 1.0f, v);
}

void FaustInstrument::noteOffTargetFreq(float targetFreq, float decayTailMs) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    if (mVoices.empty() || !mIsPolyphonic) return;

    for (int i = 0; i < mNumVoices; ++i) {
        if (std::abs(mVoiceFreqs[i] - targetFreq) < 0.1f) {
            noteOff(i, decayTailMs);
        }
    }
}

void FaustInstrument::noteOff(int voiceIndex, float decayTailMs) {
    mTargetFrames = 0;
    if (voiceIndex == -1) {
        mGateOpen = false;
    }
    setParam("gate", 0.0f, voiceIndex);

    if (voiceIndex == -1 && decayTailMs > 0.0f) {
        mDecayFramesTarget = static_cast<long>((decayTailMs / 1000.0f) * mSampleRate);
        mDecayElapsedFrames = 0;
    } else if (voiceIndex == -1) {
        mDecayFramesTarget = 0;
        onNoteFinish();
    }
}

void FaustInstrument::clearVoices() {
    for (int i = 0; i < mNumVoices; ++i) {
        if (mVoices[i]) mVoices[i]->instanceClear();
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
        if (mFreqGlideFramesElapsed == 0 && mEnableDiagLogging) {
            mDiagLogs.push_back({mElapsedFrames, mFreqGlideStart, mAmplitude, 0.0f});
        }
        mFreqGlideFramesElapsed += numFrames;
        if (mFreqGlideFramesElapsed >= mFreqGlideFramesTotal) {
            mFreqGlideActive = false;
            setFrequencyImmediate(mFreqGlideTarget);
            setParamImmediate("glide", mDSPGlideParam, -1);
            if (mEnableDiagLogging) {
                mDiagLogs.push_back({mElapsedFrames + numFrames, mFreqGlideTarget, mAmplitude, mDSPGlideParam});
            }
        } else {
            float progress = static_cast<float>(mFreqGlideFramesElapsed) / mFreqGlideFramesTotal;
            // Apply S-Curve (Cosine Interpolation) for natural human biomechanics
            float s_progress = 0.5f * (1.0f - std::cos(progress * M_PI));
            float currentFreq = mFreqGlideStart + (mFreqGlideTarget - mFreqGlideStart) * s_progress;
            setFrequencyImmediate(currentFreq);
            if (mEnableDiagLogging && (mFreqGlideFramesElapsed % 4096 < numFrames)) {
                mDiagLogs.push_back({mElapsedFrames + numFrames, currentFreq, mAmplitude, 0.0f});
            }
        }
    }

    if (mGainGlideActive) {
        mGainGlideFramesElapsed += numFrames;
        if (mGainGlideFramesElapsed >= mGainGlideFramesTotal) {
            mGainGlideActive = false;
            mAmplitude = mGainGlideTarget;
            if (!mLUTActive) setParamImmediate("gain", mGainGlideTarget, -1);
        } else {
            float progress = static_cast<float>(mGainGlideFramesElapsed) / mGainGlideFramesTotal;
            float currentGain = mGainGlideStart + (mGainGlideTarget - mGainGlideStart) * progress;
            mAmplitude = currentGain;
            if (!mLUTActive) setParamImmediate("gain", currentGain, -1);
        }
    }

    if (mLUTActive)
        applyDynamicLUTParams(mFrequency, mAmplitude, -1);
}

void FaustInstrument::render(int numFrames, float* buffer) {
    if (mVoices.empty()) return;
    processInternalGlides(numFrames);
    
    for (int i = 0; i < numFrames * 2; ++i) buffer[i] = 0.0f;

    int nOuts = mVoices[0]->getNumOutputs();
    float scale = mIsPolyphonic ? (1.0f / (float)mNumVoices) : 1.0f;
    
    int framesProcessed = 0;
    while (framesProcessed < numFrames) {
        int chunkSize = std::min(numFrames - framesProcessed, InstrumentMapper::MAX_FRAMES_PER_BUFFER);
        
        for (int v = 0; v < mNumVoices; ++v) {
            FAUSTFLOAT* outputs[2] = { mRenderBuffer, mRenderBuffer + chunkSize };
            mVoices[v]->compute(chunkSize, nullptr, outputs);
            
            float* chunkDest = buffer + (framesProcessed * 2);
            if (nOuts == 1) {
                for (int i = 0; i < chunkSize; ++i) {
                    float val = mRenderBuffer[i] * scale;
                    if (mGain != 1.0f) val *= mGain;
                    chunkDest[i * 2] += val;
                    chunkDest[i * 2 + 1] += val;
                }
            } else if (nOuts == 2) {
                for (int i = 0; i < chunkSize; ++i) {
                    float valL = outputs[0][i] * scale;
                    float valR = outputs[1][i] * scale;
                    if (mGain != 1.0f) { valL *= mGain; valR *= mGain; }
                    chunkDest[i * 2] += valL;
                    chunkDest[i * 2 + 1] += valR;
                }
            }
        }
        framesProcessed += chunkSize;
    }
}

void FaustInstrument::onNoteFinish() {
    // completed its duration
}

void FaustInstrument::processRealtimeStream(float* buffer, int numFrames) {
    std::lock_guard<std::recursive_mutex> lock(mDSPLock);
    if (mVoices.empty()) {
        std::memset(buffer, 0, sizeof(float) * numFrames * 2);
        return;
    }

    std::memset(buffer, 0, sizeof(float) * numFrames * 2);
    int framesPerSubBlock = 1;
    int framesProcessed = 0;
    int nOuts = mVoices[0]->getNumOutputs();
    float scale = mIsPolyphonic ? (1.0f / (float)mNumVoices) : 1.0f;

    for (const auto& ev : mEventQueue) {
        if (framesPerSubBlock > 0 && (framesProcessed + framesPerSubBlock <= numFrames)) {
            processInternalGlides(framesPerSubBlock);
            
            float* chunkBuffer = buffer + (framesProcessed * 2);
            for (int v = 0; v < mNumVoices; ++v) {
                FAUSTFLOAT* outputs[2] = { mRenderBuffer, mRenderBuffer + framesPerSubBlock };
                mVoices[v]->compute(framesPerSubBlock, nullptr, outputs);

                if (nOuts == 1) {
                    for (int i = 0; i < framesPerSubBlock; ++i) {
                        float val = mRenderBuffer[i] * scale;
                        if (mGain != 1.0f) val *= mGain;
                        chunkBuffer[i * 2] += val;
                        chunkBuffer[i * 2 + 1] += val;
                    }
                } else if (nOuts == 2) {
                    for (int i = 0; i < framesPerSubBlock; ++i) {
                        float valL = outputs[0][i] * scale;
                        float valR = outputs[1][i] * scale;
                        if (mGain != 1.0f) { valL *= mGain; valR *= mGain; }
                        chunkBuffer[i * 2] += valL;
                        chunkBuffer[i * 2 + 1] += valR;
                    }
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
        setParamImmediate(ev.paramName.c_str(), ev.value, ev.voiceIndex);
    }

    int remaining = numFrames - framesProcessed;
    if (remaining > 0) {
        processInternalGlides(remaining);
        
        float* chunkBuffer = buffer + (framesProcessed * 2);
        for (int v = 0; v < mNumVoices; ++v) {
            FAUSTFLOAT* outputs[2] = { mRenderBuffer, mRenderBuffer + remaining };
            mVoices[v]->compute(remaining, nullptr, outputs);

            if (nOuts == 1) {
                for (int i = 0; i < remaining; ++i) {
                    float val = mRenderBuffer[i] * scale;
                    if (mGain != 1.0f) val *= mGain;
                    chunkBuffer[i * 2] += val;
                    chunkBuffer[i * 2 + 1] += val;
                }
            } else if (nOuts == 2) {
                for (int i = 0; i < remaining; ++i) {
                    float valL = outputs[0][i] * scale;
                    float valR = outputs[1][i] * scale;
                    if (mGain != 1.0f) { valL *= mGain; valR *= mGain; }
                    chunkBuffer[i * 2] += valL;
                    chunkBuffer[i * 2 + 1] += valR;
                }
            }
        }

        if (mGateOpen) {
            long prevElapsed = mElapsedFrames;
            mElapsedFrames += remaining;
            
            if (mEnableDiagLogging) {
                for (float t : mDiagSamplingTimes) {
                    long targetFrame = static_cast<long>(t * mSampleRate);
                    if (prevElapsed < targetFrame && mElapsedFrames >= targetFrame) {
                        float sumSq = 0.0f;
                        for (int i = 0; i < remaining; ++i) {
                            float valL = chunkBuffer[i * 2];
                            float valR = chunkBuffer[i * 2 + 1];
                            sumSq += (valL * valL + valR * valR) * 0.5f;
                        }
                        float energy = sumSq / remaining;
                        DiagLog log = {mElapsedFrames, mFrequency, 0.0f, energy, {}};

                        {
                            std::lock_guard<std::recursive_mutex> lock(mDSPLock);
                            if (!mGoertzelFreqs.empty()) {
                                log.rawAudio.assign(chunkBuffer, chunkBuffer + (remaining * 2));
                            }
                            mDiagLogs.push_back(log);
                        }
                    }
                }
            }

            if (mTargetFrames > 0 && mElapsedFrames >= mTargetFrames && prevElapsed < mTargetFrames) {
                onNoteFinish();
            }
        }
    }

    mEventQueue.clear();

    if (mIsMuted.load(std::memory_order_acquire)) {
        std::memset(buffer, 0, sizeof(float) * numFrames * 2);
    }
}

void FaustInstrument::startInternalStream(float sampleRate) {
    mSampleRate = sampleRate;
}

void FaustInstrument::stopInternalStream() {
    mIsStreamActive = false;
}

void FaustInstrument::applyDynamicLUTParams(float freq, float velocity, int voiceIndex) {
    if (!mLUTActive || mLUTRecords.empty()) return;

    constexpr int K = 3;
    struct Neighbor { const LUTRecord* record; float distSq; };
    Neighbor nearest[K] = {};

    for (const auto& rec : mLUTRecords) {
        if (mHasStrikeLUT) {
            // Hard-filter: Only interpolate using rows that match the target strike
            float targetStrike = (mStrikeVal >= 0.0f) ? mStrikeVal : 1.0f; // Default to 1.0 (Standard)
            if (std::abs(rec.strike - targetStrike) > 0.01f) {
                continue; // Skip rows that don't match the strike
            }
        }

        float fDenom = freq + rec.frequency;
        float fNorm = (fDenom > 0.0001f) ? (freq - rec.frequency) / fDenom : 0.0f;
        float aDenom = velocity + rec.velocity;
        float aNorm = (aDenom > 0.0001f) ? (velocity - rec.velocity) / aDenom : 0.0f;
        
        float distSq = fNorm * fNorm + aNorm * aNorm;

            if (distSq < 1e-10f) {
            for (const auto& pair : rec.targetParams)
                setParamImmediate(pair.first.c_str(), pair.second, voiceIndex);
            return;
        }

        if (!nearest[K-1].record || distSq < nearest[K-1].distSq) {
            int idx = K-1;
            for (int i = K-2; i >= 0; --i)
                if (nearest[i].record && distSq >= nearest[i].distSq) { idx = i+1; break; }
                else idx = i;
            for (int i = K-1; i > idx; --i) nearest[i] = nearest[i-1];
            nearest[idx] = {&rec, distSq};
        }
    }

#ifdef DEBUG
    // To prevent flooding the console if the test is fast, we only print if requested. 
    // Usually it's helpful to see it per-note.
    printf("\n[DEBUG LUT] Interpolating for Request: Freq=%.1f, Vel=%.2f, TargetStrike=%.1f\n", freq, velocity, mStrikeVal >= 0.0f ? mStrikeVal : 1.0f);
#endif

    std::map<std::string, float> accumulatedParams, totalWeights;
    for (int i = 0; i < K && nearest[i].record; ++i) {
        float weight = 1.0f / (nearest[i].distSq + 1e-10f);
        
#ifdef DEBUG
        printf("  -> Using Row %d: CSV Freq=%.1f, CSV Amp=%.2f, CSV Strike=%.1f (DistSq=%.6f, Weight=%.2f)\n", 
               i, nearest[i].record->frequency, nearest[i].record->amplitude, nearest[i].record->strike, nearest[i].distSq, weight);
#endif

        for (const auto& pair : nearest[i].record->targetParams) {
            accumulatedParams[pair.first] += pair.second * weight;
            totalWeights[pair.first] += weight;
        }
    }

    for (const auto& pair : accumulatedParams) {
        float wSum = totalWeights[pair.first];
        if (wSum > 0.0f)
            setParamImmediate(pair.first.c_str(), pair.second / wSum, voiceIndex);
    }
}


void FaustInstrument::dumpDiagnostics() {
    if (!mEnableDiagLogging || mDiagLogs.empty()) return;
    printf("\n=== MEMORY-BASED GLIDE DIAGNOSTICS FOR INSTRUMENT %d ===\n", mInstrumentID);
    printf("%-15s %-15s %-15s %-15s\n", "Frames", "C++ Freq", "C++ Amp", "DSP Glide");
    for (const auto& log : mDiagLogs) {
        printf("%-15ld %-15.2f %-15.3f %-15.3f\n", log.frame, log.freq, log.amp, log.value3);
    }
    printf("========================================================\n\n");
    mDiagLogs.clear();
}
