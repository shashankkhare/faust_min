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
#include <atomic>
#include <map>

#include <mutex>
#include "PlatformCompat.hpp"

enum class DSPExecutionType {
    StaticCompiled,  // Static compiled sub-classes e.g., FaustFluteDSP
    InterpretedByte  // Runtime dynamic interpreter_dsp instances
};

class FAUST_API FaustInstrument {
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
    void clearVoices();

    // --- Native Automation Glides ---
    void velocityGlide(float targetVelocity, float durationSeconds);
    void frequencyGlide(float targetFreq, float durationSeconds);
    void gainGlide(float targetGain, float durationSeconds);

    // Public concrete accessors
    float getGain() const;
    float getFrequency() const;
    float getVelocity() const;
    float getDefaultVelocity() const;
    float getAmplitude() const;
    float getDSPGlideParam() const { return mDSPGlideParam; }
    float getDuration() const;
    float getReverbSend() const;
    float getSampleRate() const;
    DSPExecutionType getExecutionType() const;

    /**
     * Play a note.
     *
     * @param freq    Note frequency in Hz. Optional — pass -1.0f for
     *                instruments with built-in pitch (thunder, wind,
     *                clap, percussion, etc.).
     * @param amplitude Output level (required: > 0).
     * @param velocity  Playing velocity. Optional (-1.0f = DSP default).
     * @param strikeVal Strike type / articulation. Optional (-1.0f = DSP default).
     *                For percussion, selects different strokes (open, muted, rim, etc).
     */
    virtual void noteOn(float freq = -1.0f, float velocity = 0.5f, float strikeVal = -1.0f);
    virtual void noteOff(int voiceIndex = -1, float decayTailMs = 0.0f);
    virtual void noteOffTargetFreq(float targetFreq, float decayTailMs = 0.0f);
    void render(int numFrames, float* buffer);

    // Mute support
    void setMuted(bool mute) { mIsMuted.store(mute, std::memory_order_release); }
    bool isMuted() const { return mIsMuted.load(std::memory_order_acquire); }

    // Diagnostics
    void enableDiagnostics(bool enable) { mEnableDiagLogging = enable; }
    void enableDiagnosticLogging(bool enable) { mEnableDiagLogging = enable; }
    void clearDiagnosticLogs() { std::lock_guard<std::recursive_mutex> lock(mDSPLock); mDiagLogs.clear(); }
    void dumpDiagnostics();
    
    struct DiagLog {
        long frame;
        float freq;
        float amp;
        float value3; // used for energy capture
        std::vector<float> rawAudio;
    };
    
    std::vector<float> mGoertzelFreqs;
    void addDiagnosticFreq(float freq) {
        std::lock_guard<std::recursive_mutex> lock(mDSPLock);
        mGoertzelFreqs.push_back(freq);
    }
    void clearDiagnosticFreqs() {
        std::lock_guard<std::recursive_mutex> lock(mDSPLock);
        mGoertzelFreqs.clear();
    }

    std::vector<float> mDiagSamplingTimes = {0.5f, 0.6f, 0.7f};
    void setDiagnosticSamplingTimes(const std::vector<float>& timesSeconds) {
        std::lock_guard<std::recursive_mutex> lock(mDSPLock);
        mDiagSamplingTimes = timesSeconds;
    }
    std::vector<float> getDiagnosticFreqs() {
        std::lock_guard<std::recursive_mutex> lock(mDSPLock);
        return mGoertzelFreqs;
    }

    std::vector<DiagLog> getDiagnosticLogs() { 
        std::lock_guard<std::recursive_mutex> lock(mDSPLock); 
        return mDiagLogs; 
    }

    // Virtual completion callback hook
    virtual void onNoteFinish();

    // Group routing identifier
    virtual int getID() const { return mInstrumentID; }

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
    float getParam(const char* shortName);
    bool getParamBounds(const char* shortName, float& outMin, float& outMax);
    std::string getParametersJSON();

protected:
    std::recursive_mutex mDSPLock; // Dedicated recursive mutex protecting DSP state maps
    
    struct LUTRecord {
        float frequency;
        float velocity;
        float strike;
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
    std::vector<float> mVoiceFreqs; // Tracks the frequency each voice is currently playing
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
    float mDefaultVelocity = 0.5f;
    float mAmplitude;
    float mStrikeVal = -1.0f;
    bool mHasStrikeLUT = false;
    float mDuration;
    float mReverbSend;
    bool mGateOpen;
    std::atomic<bool> mIsMuted{false};

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
    
    // Tracks the current peak amplitude energy of each active voice
    std::vector<float> mVoiceEnergies;

    // Running peak envelope tracker for smooth look-ahead normalization
    float mRunningPeakEnvelope = 0.0f;

    // Fast inline helper to calculate peak block amplitude for voice energy tracking
    inline void updateVoiceEnergyInline(int voiceIndex, const float* sourceBufferL, const float* sourceBufferR, int chunkSize) {
        float peak = 0.0f;
        if (sourceBufferR == nullptr) { // Mono
            for (int i = 0; i < chunkSize; ++i) {
                float val = std::abs(sourceBufferL[i]);
                if (val > peak) peak = val;
            }
        } else { // Stereo
            for (int i = 0; i < chunkSize; ++i) {
                float val = std::max(std::abs(sourceBufferL[i]), std::abs(sourceBufferR[i]));
                if (val > peak) peak = val;
            }
        }
        if (voiceIndex >= 0 && voiceIndex < mVoiceEnergies.size()) {
            mVoiceEnergies[voiceIndex] = peak;
        }
    }

    // Dynamic smoothing peak normalization to prevent digital clipping in polyphony
    void normalizeBuffer(float* buffer, int numFrames);

    std::vector<DiagLog> mDiagLogs;
    std::vector<std::string> mDiagLogsFull;
    bool mEnableDiagLogging = false;

    void* mStreamDevice;

protected:
    void processInternalGlides(int numFrames);
    void startInternalStream(float sampleRate);
    void stopInternalStream();
    void setSampleRate(float sampleRate);  // accessible to subclass constructors
    void loadTargetDSP();                  // accessible to subclass constructors
    void initParams();                     // refactored INI parsing

private:
    std::map<std::string, std::string> mParamAddressCache;
    // No external or subclass-unsafe methods remain here
};

#endif
