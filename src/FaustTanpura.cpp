#include "FaustTanpura.hpp"
#include <cmath>
#include <algorithm>
#include <random>

TanpuraString::TanpuraString() 
    : mSampleRate(44100.0f), mFreq(110.0f), mJivari(0.7f), 
      mWritePtr(0), mLpState(0.0f), mDCState(0.0f), mPrevIn(0.0f), mSeed(42) {
    for(int i=0; i<4; i++) {
        mApX[i] = mApY[i] = 0.0f;
    }
}

void TanpuraString::init(float sampleRate, float freq) {
    mSampleRate = sampleRate;
    mFreq = std::max(20.0f, freq);
    size_t size = (size_t)(sampleRate / 20.0f) + 2;
    mDelayLine.assign(size, 0.0f);
    mFeedback = 0.999f; // Extremely high sustain for the Tanpura drone
}

void TanpuraString::setJivari(float amount) {
    mJivari = std::max(0.0f, std::min(1.0f, amount));
}

void TanpuraString::setDecay(float t60) {
    if (t60 < 0.1f) t60 = 0.1f;
    // Calculate exact feedback for T60
    mFeedback = std::pow(0.001f, 1.0f / (t60 * mFreq));
    // Compensate for filter loss to achieve the 9s+ drone
    mFeedback = std::min(0.9999f, mFeedback * 1.002f); 
}

void TanpuraString::pluck(float velocity) {
    float period = mSampleRate / mFreq;
    int iPeriod = (int)period;
    if (iPeriod > (int)mDelayLine.size()) iPeriod = mDelayLine.size();
    
    // Add excitation noise behind the write pointer (at the read position)
    for (int i = 0; i < iPeriod; i++) {
        int idx = (int)((float)mWritePtr - period + (float)i);
        while (idx < 0) idx += mDelayLine.size();
        idx = idx % mDelayLine.size();
        
        // Fast LCG random for pluck
        mSeed = mSeed * 1103515245 + 12345;
        float noise = (float)(mSeed / 65536 % 32768) / 32768.0f * 2.0f - 1.0f;
        
        mDelayLine[idx] += noise * velocity;
    }
}

float TanpuraString::tick() {
    float period = mSampleRate / mFreq;
    float readPos = (float)mWritePtr - period;
    while (readPos < 0) readPos += (float)mDelayLine.size();
    
    int idx1 = (int)readPos % mDelayLine.size();
    int idx2 = (idx1 + 1) % mDelayLine.size();
    float frac = readPos - (int)readPos;
    float sig = mDelayLine[idx1] * (1.0f - frac) + mDelayLine[idx2] * frac;

    // Jivari Bridge (Soft-String Thread Buzz)
    float jivariReflection = sig;
    if (mJivari > 0.01f) {
        float threshold = 0.2f; 
        if (sig > threshold) {
            float delta = sig - threshold;
            // Very gentle folding for "soft string" character
            jivariReflection = threshold - delta * (0.1f + mJivari * 0.2f); 
        }
    }
    
    // Unity-gain saturation for clean stability
    jivariReflection = std::tanh(jivariReflection);
    
    // String Loop Filter (Transparent Sustain)
    // 0.995 provides near-zero loss for a long, singing drone
    mLpState = jivariReflection * 0.995f + mLpState * 0.005f;
    float feedbackSig = mLpState * mFeedback;

    // Dispersion (String Stiffness)
    float apIn = feedbackSig;
    const float a = 0.45f;
    for (int j = 0; j < 4; j++) {
        float out = a * apIn + mApX[j] - a * mApY[j];
        mApX[j] = apIn;
        mApY[j] = out;
        apIn = out;
    }
    
    // DC Blocker (Sub-Bass preservation)
    float dcBlockOut = apIn - mPrevIn + 0.998f * mDCState;
    mPrevIn = apIn;
    mDCState = dcBlockOut;

    // Hard-Clipping to prevent blow-ups without destroying sustain
    float saturated = dcBlockOut;
    if (saturated > 1.0f) saturated = 1.0f;
    if (saturated < -1.0f) saturated = -1.0f;
    
    mDelayLine[mWritePtr] = saturated;
    mWritePtr = (mWritePtr + 1) % mDelayLine.size();

    return saturated;
}

FaustTanpura::FaustTanpura(float sampleRate) 
    : mSampleRate(sampleRate), mIsPlaying(false), mSampleCounter(0), 
      mDelaySamples(sampleRate * 0.7f), mCurrentString(0) {
    // Default tuning: Pa - Sa - Sa - Sa(low)
    mStrings[0].init(sampleRate, 196.00f); // Pa (G3)
    mStrings[1].init(sampleRate, 261.63f); // Sa (C4)
    mStrings[2].init(sampleRate, 261.63f); // Sa (C4)
    mStrings[3].init(sampleRate, 130.81f); // Low Sa (C3)
}

void FaustTanpura::setParams(float f1, float f2, float f3, float f4, float decay, float delay) {
    mStrings[0].init(mSampleRate, f1);
    mStrings[1].init(mSampleRate, f2);
    mStrings[2].init(mSampleRate, f3);
    mStrings[3].init(mSampleRate, f4);
    
    for(int i=0; i<4; i++) mStrings[i].setDecay(decay);
    mDelaySamples = (int)(delay * mSampleRate);
}

void FaustTanpura::setFrequency(int idx, float freq) {
    if (idx >= 0 && idx < 4) mStrings[idx].init(mSampleRate, freq);
}

void FaustTanpura::pluck(int idx, float velocity) {
    if (idx >= 0 && idx < 4) mStrings[idx].pluck(velocity);
}

void FaustTanpura::setJivari(float amount) {
    for(int i=0; i<4; i++) mStrings[i].setJivari(amount);
}

void FaustTanpura::setPlaying(bool playing) {
    if (playing && !mIsPlaying) {
        mSampleCounter = mDelaySamples; // trigger immediately on next render
        mCurrentString = 0;
    }
    mIsPlaying = playing;
}

void FaustTanpura::render(int numFrames, float* buffer) {
    for (int i = 0; i < numFrames; i++) {
        if (mIsPlaying) {
            if (mSampleCounter >= mDelaySamples) {
                mStrings[mCurrentString].pluck(0.8f);
                mCurrentString = (mCurrentString + 1) % 4;
                mSampleCounter = 0;
            }
            mSampleCounter++;
        }
        
        float out = 0.0f;
        for (int j = 0; j < 4; j++) {
            out += mStrings[j].tick();
        }
        float finalOut = out * 0.8f; // Boosted output mix
        buffer[i] = finalOut / (1.0f + std::abs(finalOut)); // Master bus soft-limiter
    }
}
