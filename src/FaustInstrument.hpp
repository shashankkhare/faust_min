#ifndef FAUST_INSTRUMENT_HPP
#define FAUST_INSTRUMENT_HPP

#include <memory>
#include <string>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

enum class DSPExecutionType {
    StaticCompiled,  // Static compiled sub-classes e.g., FaustFluteDSP
    InterpretedByte  // Runtime dynamic interpreter_dsp instances
};

class __attribute__((visibility("default"))) FaustInstrument {
public:
    FaustInstrument(int instrumentID = -1, DSPExecutionType execType = DSPExecutionType::StaticCompiled,
                    float sampleRate = 44100.0f, float gain = 1.0f, float freq = 440.0f, float velocity = 0.8f);
    virtual ~FaustInstrument();

    // Concrete core setup parameters
    void setSampleRate(float sampleRate);
    void setDSP(dsp* newDSP, DSPExecutionType execType = DSPExecutionType::StaticCompiled);
    void unloadDSP();
    void loadTargetDSP(int instrumentID, DSPExecutionType execType);

    // Concrete parameter tracking controls
    void setGain(float gain);
    void setFrequency(float freq);
    void setVelocity(float velocity);
    void setDuration(float seconds);
    void setParameter(const char* name, float value);

    // --- Native Automation Glides ---
    void velocityGlide(float targetVelocity, float durationSeconds);
    void frequencyGlide(float targetFreq, float durationSeconds);

    // Public concrete accessors
    float getGain() const;
    float getFrequency() const;
    float getVelocity() const;
    float getDuration() const;
    float getSampleRate() const;
    DSPExecutionType getExecutionType() const;

    void noteOn(float freq = -1.0f, float velocity = -1.0f);
    void noteOff(float decayTailMs = 0.0f);
    void render(int numFrames, float* buffer);

    // Virtual completion callback hook
    virtual void onNoteFinish();

    // Group routing identifier
    virtual int getID() const { return -1; }

    // Weight scaling properties
    void setAssignedWeight(float weight);
    float getAssignedWeight() const;

    // Real-time audio streaming driver execution loop
    void processRealtimeStream(float* buffer, int numFrames);

protected:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    DSPExecutionType mExecType;
    void* mDSPFactory;

    bool mIsStreamActive;
    float mSampleRate;
    float mGain;
    float mFrequency;
    float mVelocity;
    float mDuration;
    float mAssignedWeight;

    // Internal sample-accurate timeline counters
    long mTargetFrames;
    long mElapsedFrames;
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

    void* mStreamDevice;

    void setParam(const char* shortName, float val);
    void processInternalGlides(int numFrames);
    void startInternalStream(float sampleRate);
    void stopInternalStream();
};

#endif
