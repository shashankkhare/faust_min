#pragma once
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Faust {
    struct Resonator {
        float ratio;   // mode ratio
        float t60;     // decay time
        float gain;    // mode gain
        float b1, b2;  // coefficients
        float y1, y2;  // state
        
        void init() {
            y1 = y2 = 0.0f;
        }

        void update(float baseFreq, float sampleRate) {
            float freq = baseFreq * ratio;
            float r = std::pow(0.001f, 1.0f / (t60 * sampleRate));
            b1 = 2.0f * r * std::cos(2.0f * M_PI * freq / sampleRate);
            b2 = -r * r;
        }
        
        inline float process(float in) {
            float out = in + b1 * y1 + b2 * y2;
            y2 = y1;
            y1 = out;
            return out - y2; // High-pass for clarity
        }
    };
}
