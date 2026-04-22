#ifndef FAUST_FLUTE_HPP
#define FAUST_FLUTE_HPP

#include <cmath>
#include <random>
#include <vector>

/**
 * A High-Fidelity Physical Model of a Flute.
 * Based on the Smith/Michon waveguide synthesis logic.
 */
class FaustFlute {
public:
    FaustFlute(float sampleRate);
    ~FaustFlute();

    void setFrequency(float freq);
    void setPressure(float pressure);
    void setVibrato(float rate, float depth);
    
    // Renders float PCM data into the buffer
    void render(int numFrames, float* buffer);

private:
    float mSampleRate;
    float mFreq;
    float mPressure;
    float mVibratoRate;
    float mVibratoDepth;
    float mPhase;

    // Dual-Waveguide components
    std::vector<float> mBoreDelay;
    std::vector<float> mJetDelay;
    int mBoreWriteIdx;
    int mJetWriteIdx;
    
    // Nonlinearities
    std::mt19937 mPRNG;
    std::uniform_real_distribution<float> mDist;
    
    float mFilterState; // One-pole low-pass
    float mDCState;     // DC blocker state
    float mPrevIn;      // DC blocker previous input
    
    // All-pass Fractional Delay state (for perfect C3/C4 phase)
    float mBoreAP_X1, mBoreAP_Y1;
    float mJetAP_X1, mJetAP_Y1;
    
    float tick();
};

#endif // FAUST_FLUTE_HPP
