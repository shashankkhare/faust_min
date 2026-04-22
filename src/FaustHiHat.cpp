#include "FaustHiHat.hpp"
#include <random>
#include <algorithm>

FaustHiHat::FaustHiHat(float sampleRate) : _sampleRate(sampleRate), _decay(0.999f), _env(0.0f), _filterState(0.0f) {}

void FaustHiHat::strike(float velocity) {
    _env = velocity;
}

void FaustHiHat::setOpenness(float amount) {
    // amount: 0 (closed) to 1 (open)
    // Closed = faster decay, Open = slower decay
    _decay = 0.998f + (amount * 0.0015f);
}

void FaustHiHat::render(int numFrames, float* buffer) {
    static std::mt19937 gen(47);
    static std::uniform_real_distribution<float> dis(-1.0, 1.0);

    for (int i = 0; i < numFrames; ++i) {
        float noise = dis(gen) * _env;
        _env *= _decay;

        // Simple high-pass filter at ~8kHz
        // y[n] = x[n] - x[n-1] + a*y[n-1]
        float filtered = noise - _filterState;
        _filterState = noise;
        
        buffer[i] = filtered * 0.5f;
    }
}
