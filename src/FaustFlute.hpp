#ifndef FAUST_FLUTE_HPP
#define FAUST_FLUTE_HPP

#include <cmath>
#include <vector>
#include <random>

class FaustFlute {
public:
    FaustFlute(float sampleRate);
    ~FaustFlute();

    void setFrequency(float freq);
    void setPressure(float pressure);
    void setVibrato(float rate, float depth);
    void reset();
    void render(int numFrames, float* buffer);

private:
    /**
     * @brief Core synthesis engine for a single sample.
     * Based on the STK (Synthesis Tool Kit) Digital Waveguide Flute model.
     * 
     * Algorithm Overview:
     * 1. Excitation: Breath pressure + noise + vibrato.
     * 2. Jet Delay: Simulates the time air takes to travel from lips to the flute edge.
     * 3. Non-linearity: A cubic polynomial (x - x^3) simulates the "switching" 
     *    behavior of the air jet across the flute's embouchure hole.
     * 4. Bore Delay: Simulates the resonance of the flute's cylindrical tube.
     * 5. Feedback: A double-loop system where the jet and bore interact to 
     *    sustain oscillation.
     */
    float tick(float currentPressure);

    float mSampleRate;
    float mFreq;
    float mPressure;
    float mVibratoRate;
    float mVibratoDepth;
    float mPhase;

    // Waveguide State (Double Delay Loop)
    // The "Jet" delay represents the embouchure path, while "Bore" is the tube resonance.
    std::vector<float> mBoreDelay;
    std::vector<float> mJetDelay; // Embouchure Delay
    size_t mWriteIdxB;
    size_t mWriteIdxJ;
    
    float mFilterState; // Reflection filter (lowpass damping)
    float mDCState;     // DC blocker state
    float mBoreOut;     // Feedback signal from end of bore
    
    // All-pass fractional delay states (for future pitch precision)
    float mBoreAP_X1, mBoreAP_Y1;
    float mJetAP_X1, mJetAP_Y1;

    std::mt19937 mPRNG;
    std::uniform_real_distribution<float> mDist;
};

#endif // FAUST_FLUTE_HPP
