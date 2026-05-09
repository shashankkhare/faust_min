#ifndef FAUST_TANPURA_HPP
#define FAUST_TANPURA_HPP

#include "FaustCommon.hpp"
#include <vector>

class TanpuraString {
public:
    TanpuraString();
    void init(float sampleRate, float freq);
    void setJivari(float amount);
    void setDecay(float t60);
    void pluck(float velocity);
    float tick();

private:
    float mSampleRate;
    float mFreq;
    float mJivari;
    float mFeedback;
    
    std::vector<float> mDelayLine;
    int mWritePtr;
    float mLpState;
    float mDCState;
    float mPrevIn;
    
    // Dispersion
    float mApX[4];
    float mApY[4];
};

class FaustTanpura {
public:
    FaustTanpura(float sampleRate);
    void setParams(float f1, float f2, float f3, float f4, float decay, float delay);
    void setFrequency(int stringIdx, float freq);
    void setJivari(float amount);
    void pluck(int stringIdx, float velocity);
    void setPlaying(bool playing);
    void render(int numFrames, float* buffer);

private:
    float mSampleRate;
    TanpuraString mStrings[4];
    
    bool mIsPlaying;
    int mSampleCounter;
    int mDelaySamples;
    int mCurrentString;
};

#endif
