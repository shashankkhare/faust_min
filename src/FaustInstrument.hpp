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

#ifndef FAUST_INSTRUMENT_HPP
#define FAUST_INSTRUMENT_HPP

#include "InstrumentMapper.hpp"
#include <memory>
#include <string>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>
#include <vector>
#include <map>

#include <mutex>

enum class DSPExecutionType {
    StaticCompiled,  // Static compiled sub-classes e.g., FaustFluteDSP
    InterpretedByte  // Runtime dynamic interpreter_dsp instances
};

class __attribute__((visibility("default"))) FaustInstrument {
public:
    FaustInstrument(int instrumentID = -1, DSPExecutionType execType = DSPExecutionType::StaticCompiled,
                    float sampleRate = InstrumentMapper::DEFAULT_SAMPLE_RATE, float gain = -1.0f, float freq = -1.0f, float velocity = -1.0f, float amplitude = 1.0f);
    virtual ~FaustInstrument();
    void setDSP(dsp* newDSP, DSPExecutionType execType = DSPExecutionType::StaticCompiled);
    void addVoice(dsp* newDSP);
    void initializeVoices();
    void unloadDSP();


    // Concrete parameter tracking controls
    void setGain(float gain);
    void setGainImmediate(float gain);
    void setFrequency(float freq);
    void setFrequencyImmediate(float freq);
    void setVelocity(float velocity);
    void setVelocityImmediate(float velocity);
    virtual void setAmplitude(float amplitude);
    virtual void setAmplitudeImmediate(float amplitude);
    void setDuration(float seconds);
    void setReverbSend(float send);
    void setParameter(const char* name, float value);

    // --- Native Automation Glides ---
    void velocityGlide(float targetVelocity, float durationSeconds);
    void frequencyGlide(float targetFreq, float durationSeconds);
    void gainGlide(float targetGain, float durationSeconds);

    // Public concrete accessors
    float getGain() const;
    float getFrequency() const;
    float getVelocity() const;
    float getAmplitude() const;
    float getDSPGlideParam() const { return mDSPGlideParam; }
    float getDuration() const;
    float getReverbSend() const;
    float getSampleRate() const;
    DSPExecutionType getExecutionType() const;

    virtual void noteOn(float freq = -1.0f, float velocity = -1.0f, float strikeVal = -1.0f, float amplitude = -1.0f);
    virtual void noteOff(float decayTailMs = 0.0f);
    void render(int numFrames, float* buffer);

    // Diagnostics
    void enableDiagnostics(bool enable) { mEnableDiagLogging = enable; }
    void dumpDiagnostics();

    // Virtual completion callback hook
    virtual void onNoteFinish();

    // Group routing identifier
    virtual int getID() const { return mInstrumentID; }

    // Weight scaling properties
    void setAssignedWeight(float weight);
    float getAssignedWeight() const;

    // Real-time audio streaming driver execution loop
    void processRealtimeStream(float* buffer, int numFrames);

    /**
     * @brief Queues a parameter change for sub-block processing.
     * 
     * This method ensures that the parameter change is 'seen' by the DSP by dividing 
     * the next audio block into sub-blocks. Each queued event triggers a separate 
     * compute cycle. Use this for all real-time triggers (e.g., gate hits).
     */
    void setParam(const char* shortName, float val, int voiceIndex = -1);
    void setParamImmediate(const char* shortName, float val, int voiceIndex = -1);

protected:
    std::recursive_mutex mDSPLock; // Dedicated recursive mutex protecting DSP state maps
    
    struct LUTRecord {
        float frequency;
        float amplitude;
        std::map<std::string, float> targetParams;
    };
    std::vector<LUTRecord> mLUTRecords;
    bool mLUTActive = false;

    struct TimedEvent {
        std::string paramName;
        float value;
        int voiceIndex;
    };
    std::vector<TimedEvent> mEventQueue;

    void applyDynamicLUTParams(float freq, float amp, int voiceIndex);

    std::vector<std::unique_ptr<dsp>> mVoices;
    std::vector<std::unique_ptr<MapUI>> mVoiceUIs;
    bool mIsPolyphonic;
    int mNumVoices;
    int mNextVoice;
    float* mVoiceScratchBuffer;
    
    DSPExecutionType mExecType;
    void* mDSPFactory;
    int mInstrumentID;

    bool mIsStreamActive;
    float mSampleRate;
    float mGain;
    float mFrequency;
    float mVelocity;
    float mAmplitude;
    float mDuration;
    float mAssignedWeight;
    float mReverbSend;
    bool mGateOpen;

    // Internal sample-accurate timeline counters
    long mTargetFrames;
    long mElapsedFrames;
    
    float* mRenderBuffer;
    long mDecayFramesTarget;
    long mDecayElapsedFrames;

    // --- Glide Interpolation State Trackers ---
    bool mVelGlideActive;
    float mVelGlideStart;
    float mVelGlideTarget;
    long mVelGlideFramesTotal;
    long mVelGlideFramesElapsed;

    bool mFreqGlideActive;
    float mFreqGlideStart;
    float mFreqGlideTarget;
    long mFreqGlideFramesTotal;
    long mFreqGlideFramesElapsed;

    bool mGainGlideActive;
    float mGainGlideStart;
    float mGainGlideTarget;
    long mGainGlideFramesTotal;
    long mGainGlideFramesElapsed;

    float mDSPGlideParam = 0.05f; // Store original portamento
    
    struct DiagLog {
        long frame;
        float freq;
        float amp;
        float glide;
    };
    std::vector<DiagLog> mDiagLogs;
    bool mEnableDiagLogging = false;

    void* mStreamDevice;

protected:
    void processInternalGlides(int numFrames);
    void startInternalStream(float sampleRate);
    void stopInternalStream();
    void setSampleRate(float sampleRate);  // accessible to subclass constructors
    void loadTargetDSP();                  // accessible to subclass constructors

private:
    std::map<std::string, std::string> mParamAddressCache;
    // No external or subclass-unsafe methods remain here
};

#endif
