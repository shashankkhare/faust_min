#pragma once
#include <cmath>
#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Faust {
    struct Resonator {
        float ratio;   
        float t60;     
        float gain;    
        float a0, b1, b2; 
        float z1, z2;     
        
        void init() {
            z1 = z2 = 0.0f;
        }

        void update(float baseFreq, float sampleRate) {
            float freq = baseFreq * ratio;
            float omega = 2.0f * (float)M_PI * freq / sampleRate;
            float r = std::pow(0.001f, 1.0f / (std::max(0.001f, t60) * sampleRate));
            
            b1 = 2.0f * r * std::cos(omega);
            b2 = r * r;
            a0 = 1.0f; // Standardized for Impulse input. Sustained instruments (Flute) override this.
        }
        
        inline float process(float in) {
            float out = a0 * in + b1 * z1 - b2 * z2;
            z2 = z1;
            z1 = out;
            return out;
        }
    };
}
