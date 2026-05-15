/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once
#include <faust/gui/meta.h>
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
