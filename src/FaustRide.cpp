#include "FaustRide.hpp"
#include <cmath>
#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

FaustRide::FaustRide(float sampleRate) : _sampleRate(sampleRate), _pingEnv(0.0f), _washEnv(0.0f), _v1(0.0f), _v2(0.0f) {
    // 6 inharmonic frequencies for metallic clang
    _freqs[0] = 230.0f;
    _freqs[1] = 310.0f;
    _freqs[2] = 455.0f;
    _freqs[3] = 580.0f;
    _freqs[4] = 920.0f;
    _freqs[5] = 1350.0f;

    for (int i = 0; i < 6; i++) _phases[i] = 0.0f;

    // Set a sharp, shimmering band-pass filter at 10kHz
    setFilter(10000.0f, 12.0f);
}

void FaustRide::setFilter(float freq, float Q) {
    float omega = 2.0f * M_PI * freq / _sampleRate;
    float sn = std::sin(omega);
    float cs = std::cos(omega);
    float alpha = sn / (2.0f * Q);

    float a0 = 1.0f + alpha;
    _b0 = alpha / a0;
    _b1 = 0 / a0;
    _b2 = -alpha / a0;
    _a1 = -2.0f * cs / a0;
    _a2 = (1.0f - alpha) / a0;
}

void FaustRide::strike(float velocity) {
    _pingEnv = velocity;
    _washEnv = velocity * 0.4f;
}

void FaustRide::render(int numFrames, float* buffer) {
    for (int i = 0; i < numFrames; i++) {
        float mix = 0.0f;
        for (int j = 0; j < 6; j++) {
            // Square wave oscillators
            float val = (_phases[j] < 0.5f) ? 1.0f : -1.0f;
            mix += val;

            _phases[j] += _freqs[j] / _sampleRate;
            if (_phases[j] >= 1.0f) _phases[j] -= 1.0f;
        }

        // Apply Wash (lower-frequency ringing)
        float wash = mix * _washEnv;
        _washEnv *= 0.9998f;

        // Apply Shimmer (Higher Band-Pass)
        float pingIn = mix * _pingEnv;
        _pingEnv *= 0.9995f;

        // Biquad Band-Pass
        float out = _b0 * pingIn + _v1;
        _v1 = _b1 * pingIn - _a1 * out + _v2;
        _v2 = _b2 * pingIn - _a2 * out;

        // Final mix (Ping + subtle Wash)
        buffer[i] = (out * 0.8f + wash * 0.2f) * 0.5f;
    }
}
