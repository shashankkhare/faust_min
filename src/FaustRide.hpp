#include "FaustCommon.hpp"
#include <vector>

class FaustRide {
public:
    FaustRide(float sampleRate);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    
    // 6-Oscillator FM/Ring-Mod Cluster
    float _phases[6];
    float _freqs[6];
    
    // Envelopes
    float _pingEnv;
    float _washEnv;
    
    // Resonant Band-Pass Filter (Biquad for shimmer)
    float _v1, _v2;
    float _b0, _b1, _b2, _a1, _a2;

    void setFilter(float freq, float Q);
};
