#include "FaustSitar.hpp"
#include <random>
#include <algorithm>

 FaustSitar::FaustSitar(float sampleRate) 
    : _sampleRate(sampleRate), _baseFreq(146.83f), _jivari(0.5f), _sympGain(0.3f), _writePtr(0), _lpState(0.0f), _dcState(0.0f), _prevIn(0.0f) {
    
    for (int i = 0; i < 4; i++) {
        _apX[i] = _apY[i] = 0.0f;
    }
    
    // Sympathetic mode ratios 
    std::vector<float> ratios = {1.0f, 1.125f, 1.25f, 1.333f, 1.5f, 1.666f, 1.875f, 2.0f, 2.25f, 2.5f, 3.0f};
    for (float r : ratios) {
        Faust::Resonator m;
        m.ratio = r;
        m.t60 = 6.0f;
        m.gain = 1.0f;
        m.init();
        _sympModes.push_back(m);
    }

    _delayLine.assign(16384, 0.0f);
    updateInternal();
}

void FaustSitar::setFrequency(float freq) {
    _baseFreq = std::max(20.0f, freq);
    updateInternal();
}

void FaustSitar::setJivari(float amount) {
    _jivari = std::max(0.0f, std::min(1.0f, amount));
}

void FaustSitar::setSympatheticGain(float gain) {
    _sympGain = gain;
}

void FaustSitar::pluck(float velocity) {
    // Reset seed for perfect consistency as requested
    static std::mt19937 gen;
    gen.seed(45); 
    static std::uniform_real_distribution<float> dis(-1.0, 1.0);
    
    // Total clear to avoid old artifacts
    std::fill(_delayLine.begin(), _delayLine.end(), 0.0f);
    
    // Clear sympathetic resonance buildup
    for (auto& m : _sympModes) {
        m.init();
    }
    
    float period = _sampleRate / _baseFreq;
    int iPeriod = (int)period;
    if (iPeriod > (int)_delayLine.size()) iPeriod = _delayLine.size();

    // Fill the buffer with excitation noise
    // But we start the noise at index 0
    for (int i = 0; i < iPeriod; i++) {
        _delayLine[i] = dis(gen) * velocity;
    }
    
    // Start writing at the end of the noise burst
    _writePtr = iPeriod % _delayLine.size();
}

void FaustSitar::updateInternal() {
    _feedback = 0.997f; // High sustain for bloom
    for (auto& m : _sympModes) {
        m.update(_baseFreq, _sampleRate);
    }
}

void FaustSitar::render(int numFrames, float* buffer) {
    float period = _sampleRate / _baseFreq;
    if (period < 2.0f) period = 2.0f;

    for (int i = 0; i < numFrames; i++) {
        // 1. Read Pointer is exactly one period behind Write Pointer
        float readPos = (float)_writePtr - period;
        while (readPos < 0) readPos += (float)_delayLine.size();
        
        int idx1 = (int)readPos % _delayLine.size();
        int idx2 = (idx1 + 1) % _delayLine.size();
        float frac = readPos - (int)readPos;
        
        float sig = _delayLine[idx1] * (1.0f - frac) + _delayLine[idx2] * frac;

        // 2. Jivari Bridge - Unilateral Nonlinearity (The Buzz)
        // A real bridge only obstructs the string on ONE side.
        // We simulate this by "baking" the string displacement against a curved boundary.
        float jivariReflection = sig;
        if (_jivari > 0.01f) {
            float threshold = 1.0f - (_jivari * 0.7f); // How close the string is to bridge
            if (sig > threshold) {
                // Wave-wrapping: the string "bounces" back from the bridge
                float delta = sig - threshold;
                jivariReflection = threshold - delta * (0.5f + _jivari * 0.4f); 
            }
        }

        // Safety Clip to Michon safety zone [-1.5, 1.5]
        if (jivariReflection > 1.5f) jivariReflection = 1.5f;
        if (jivariReflection < -1.5f) jivariReflection = -1.5f;

        // 3. String Loop Filter (Damping)
        // High-shelf like damping to keep buzz in check
        _lpState = jivariReflection * 0.4f + _lpState * 0.6f;
        float feedbackSig = _lpState * _feedback;

        // 4. Dispersion (The Growl)
        // Cascade of all-pass filters to simulate string stiffness
        float apIn = feedbackSig;
        const float a = 0.5f; // Dispersion coefficient
        for (int j = 0; j < 4; j++) {
            float out = a * apIn + _apX[j] - a * _apY[j];
            _apX[j] = apIn;
            _apY[j] = out;
            apIn = out;
        }
        float dispSig = apIn;

        // 5. DC Blocker
        float dcBlockOut = dispSig - _prevIn + 0.995f * _dcState;
        _prevIn = dispSig;
        _dcState = dcBlockOut;

        // Smooth Soft-Clipping (S-Curve) to prevent blow-ups
        float saturated = dcBlockOut / (1.0f + std::abs(dcBlockOut));
        
        // 4. Update Delay Line
        _delayLine[_writePtr] = saturated;
        _writePtr = (_writePtr + 1) % _delayLine.size();

        // 5. Sympathetic Strings
        float symp = 0.0f;
        if (_sympGain > 0.01f) {
            for (auto& m : _sympModes) {
                symp += m.process(sig);
            }
        }

        // Final Mix (Normalized and safe)
        // Use a slightly smaller gain to be extra safe
        float finalOut = (sig + symp * _sympGain) * 0.12f; 
        buffer[i] = finalOut / (1.0f + std::abs(finalOut)); // Final smooth safety
    }
}
