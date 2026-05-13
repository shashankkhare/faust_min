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
#include <faust/dsp/interpreter-dsp.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

FaustInstrument::FaustInstrument(int instrumentID, DSPExecutionType execType,
                                 float sampleRate, float gain, float freq, float velocity) 
    : mIsStreamActive(false), mSampleRate(sampleRate), mGain(gain),
      mFrequency(freq), mVelocity(velocity), mDuration(1.0f), mAssignedWeight(1.0f),
      mTargetFrames(0), mElapsedFrames(0), 
      mDecayFramesTarget(0), mDecayElapsedFrames(0),
      mVelGlideActive(false), mVelGlideStart(velocity), mVelGlideTarget(velocity), mVelGlideFramesTotal(0), mVelGlideFramesElapsed(0),
      mFreqGlideActive(false), mFreqGlideStart(freq), mFreqGlideTarget(freq), mFreqGlideFramesTotal(0), mFreqGlideFramesElapsed(0),
      mStreamDevice(nullptr), mExecType(execType), mDSPFactory(nullptr) {
    if (instrumentID != -1) {
        loadTargetDSP(instrumentID, execType);
    }
}

FaustInstrument::~FaustInstrument() {
    stopInternalStream();
    unloadDSP();
}

void FaustInstrument::setDSP(dsp* newDSP, DSPExecutionType execType) {
    if (!newDSP) return;
    mExecType = execType;
    mDSP.reset(newDSP);
    mDSP->init(static_cast<int>(mSampleRate));
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustInstrument::unloadDSP() {
    mUI.reset();
    mDSP.reset();
    if (mExecType == DSPExecutionType::InterpretedByte && mDSPFactory) {
        deleteInterpreterDSPFactory(static_cast<interpreter_dsp_factory*>(mDSPFactory));
        mDSPFactory = nullptr;
    }
    mExecType = DSPExecutionType::StaticCompiled;
}

void FaustInstrument::loadTargetDSP(int instrumentID, DSPExecutionType execType) {
    unloadDSP();
    mExecType = execType;

    if (execType == DSPExecutionType::StaticCompiled) {
        switch (instrumentID) {
            case 0:  setDSP(new FaustDayanDSP(), execType); break;
            case 1:  setDSP(new FaustBayanDSP(), execType); break;
            case 2:  setDSP(new FaustKickDSP(), execType); break;
            case 3:  setDSP(new FaustSnareDSP(), execType); break;
            case 4:  setDSP(new FaustHihatDSP(), execType); break;
            case 5:  setDSP(new FaustTomDSP(), execType); break;
            case 6:  setDSP(new FaustRideDSP(), execType); break;
            case 7:  setDSP(new FaustBellDSP(), execType); break;
            case 8:  setDSP(new FaustBowlDSP(), execType); break;
            case 9:  setDSP(new FaustSitarDSP(), execType); break;
            case 10: setDSP(new FaustFluteDSP(), execType); break;
            case 11: setDSP(new FaustTanpuraDSP(), execType); break;
            case 12: setDSP(new FaustPianoDSP(), execType); break;
            case 13: setDSP(new FaustSaxDSP(), execType); break;
            default: setDSP(new FaustDayanDSP(), execType); break;
        }
    } else if (execType == DSPExecutionType::InterpretedByte) {
        std::string path = InstrumentMapper::getDSPPathForID(instrumentID, "");
        std::ifstream ifs(path);
        if (ifs.is_open()) {
            std::stringstream ss;
            ss << ifs.rdbuf();
            std::string source = ss.str();
            
            std::string err;
            interpreter_dsp_factory* factory = createInterpreterDSPFactoryFromString("AutoInst", source, 0, nullptr, err);
            if (factory) {
                mDSPFactory = factory;
                setDSP(factory->createDSPInstance(), execType);
            } else {
                std::cerr << "[Native] Faust Compilation failed for ID " << instrumentID << ": " << err << std::endl;
            }
        } else {
            std::cerr << "[Native] ERROR: Could not open DSP file path: " << path << std::endl;
        }
    }
}

void FaustInstrument::setSampleRate(float sampleRate) {
    mSampleRate = sampleRate;
    if (mDSP) mDSP->init(static_cast<int>(sampleRate));
}

void FaustInstrument::setParam(const char* shortName, float val) {
    if (!mUI) return;
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustInstrument::setFrequency(float freq) {
    mFrequency = freq;
    setParam("freq", freq);
}

void FaustInstrument::setGain(float gain) {
    mGain = gain;
    setParam("gain", gain);
}

void FaustInstrument::setVelocity(float velocity) {
    mVelocity = velocity;
    setParam("velocity", velocity);
}

void FaustInstrument::setDuration(float seconds) {
    mDuration = seconds;
}

void FaustInstrument::setParameter(const char* name, float value) {
    setParam(name, value);
}

float FaustInstrument::getGain() const { return mGain; }
float FaustInstrument::getFrequency() const { return mFrequency; }
float FaustInstrument::getVelocity() const { return mVelocity; }
float FaustInstrument::getDuration() const { return mDuration; }
float FaustInstrument::getSampleRate() const { return mSampleRate; }
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

void FaustInstrument::setAssignedWeight(float weight) { mAssignedWeight = weight; }
float FaustInstrument::getAssignedWeight() const { return mAssignedWeight; }

void FaustInstrument::noteOn(float freq, float velocity) {
    if (freq > 0.0f) setFrequency(freq);
    if (velocity >= 0.0f) setVelocity(velocity);
    
    // Arm sample-accurate duration safety countdown
    mTargetFrames = static_cast<long>(mDuration * mSampleRate);
    mElapsedFrames = 0;

    setParam("gate", 1.0f);
    setParam("strike", 1.0f);
    setParam("pluck", 1.0f);
}

void FaustInstrument::noteOff(float decayTailMs) {
    // Manual authority overrides timeline countdown instantly
    mTargetFrames = 0;
    setParam("gate", 0.0f);
    setParam("strike", 0.0f);
    setParam("pluck", 0.0f);

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
            setVelocity(mVelGlideTarget);
        } else {
            float progress = static_cast<float>(mVelGlideFramesElapsed) / mVelGlideFramesTotal;
            float currentVel = mVelGlideStart + (mVelGlideTarget - mVelGlideStart) * progress;
            setVelocity(currentVel);
        }
    }

    if (mFreqGlideActive) {
        mFreqGlideFramesElapsed += numFrames;
        if (mFreqGlideFramesElapsed >= mFreqGlideFramesTotal) {
            mFreqGlideActive = false;
            setFrequency(mFreqGlideTarget);
        } else {
            float progress = static_cast<float>(mFreqGlideFramesElapsed) / mFreqGlideFramesTotal;
            float currentFreq = mFreqGlideStart + (mFreqGlideTarget - mFreqGlideStart) * progress;
            setFrequency(currentFreq);
        }
    }
}

void FaustInstrument::render(int numFrames, float* buffer) {
    if (!mDSP) return;
    processInternalGlides(numFrames);
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    // Auto-clear impulse gates universally
    setParam("strike", 0.0f);
    setParam("pluck", 0.0f);
}

void FaustInstrument::onNoteFinish() {
    // Overrideable hook behavior when a note completes
}

void FaustInstrument::processRealtimeStream(float* buffer, int numFrames) {
    if (!mDSP) {
        std::memset(buffer, 0, sizeof(float) * numFrames * 2);
        return;
    }

    processInternalGlides(numFrames);

    // Deterministic duration safety timeout check inside real-time continuous thread
    if (mTargetFrames > 0) {
        mElapsedFrames += numFrames;
        if (mElapsedFrames >= mTargetFrames) {
            noteOff(); // Executes sample-accurate cutoff cleanly
        }
    }

    // Sample-accurate post-release decay tail completion tracking
    if (mDecayFramesTarget > 0) {
        mDecayElapsedFrames += numFrames;
        if (mDecayElapsedFrames >= mDecayFramesTarget) {
            mDecayFramesTarget = 0; // Cutoff tail threshold complete
            onNoteFinish();
        }
    }

    static float* monoBuf = nullptr;
    static int maxFrames = 0;
    if (numFrames > maxFrames) {
        if (monoBuf) delete[] monoBuf;
        maxFrames = numFrames;
        monoBuf = new float[maxFrames];
    }
    FAUSTFLOAT* outputs[1] = { monoBuf };
    mDSP->compute(numFrames, nullptr, outputs);
    for (int i = 0; i < numFrames; i++) {
        buffer[i * 2] = monoBuf[i];
        buffer[i * 2 + 1] = monoBuf[i];
    }
}

void FaustInstrument::startInternalStream(float sampleRate) {
    mSampleRate = sampleRate;
}

void FaustInstrument::stopInternalStream() {
    mIsStreamActive = false;
}
