#include "FaustSitar.hpp"
#include <random>
#include <algorithm>

 FaustSitar::FaustSitar(float sampleRate) 
    : _sampleRate(sampleRate), _baseFreq(146.83f), _jivari(0.5f), _sympGain(0.20f), _writePtr(0), _lpState(0.0f), _dcState(0.0f), _prevIn(0.0f), _seed(54) {
    
    for (int i = 0; i < 4; i++) {
        _apX[i] = _apY[i] = 0.0f;
    }
    
    // Sympathetic mode ratios 
    std::vector<float> ratios = {1.0f, 1.125f, 1.25f, 1.333f, 1.5f, 1.666f, 1.875f, 2.0f, 2.25f, 2.5f, 3.0f};
    for (float r : ratios) {
        Faust::Resonator m;
        m.ratio = r;
        m.t60 = 1.0f; // Default to long decay, will be scaled in update
        m.gain = 1.0f;
        m.init();
        m.update(146.83f, _sampleRate); 
        _sympModes.push_back(m);
    }

    _delayLine.assign(16384, 0.0f);
    updateInternal();
}

void FaustSitar::setFrequency(float freq) {
    _baseFreq = std::max(20.0f, freq);
    // Re-tune sympathetic strings to match the new key
    for (auto& m : _sympModes) {
        m.update(_baseFreq, _sampleRate);
    }
    updateInternal();
}

void FaustSitar::setJivari(float amount) {
    _jivari = std::max(0.0f, std::min(1.0f, amount));
}

void FaustSitar::setSympatheticGain(float gain) {
    _sympGain = gain;
}

void FaustSitar::pluck(float velocity) {
    float period = _sampleRate / _baseFreq;
    // Micro-strike (24 samples) to kill "trumpety" low-frequency energy
    int exciteLen = std::min(24, (int)period);
    
    for (int i = 0; i < exciteLen; i++) {
        int idx = (_writePtr - exciteLen + i + (int)_delayLine.size()) % _delayLine.size();
        float phase = (float)i / exciteLen;
        float pulse = std::sin(2.0f * M_PI * phase);
        
        // Fast LCG random for pluck noise
        _seed = _seed * 1103515245 + 12345;
        float noise = (float)(_seed / 65536 % 32768) / 32768.0f * 2.0f - 1.0f;
        
        // High intensity (0.9f) to force bridge interaction
        _delayLine[idx] = (pulse * 0.5f + noise * 0.5f) * velocity * _dynStrikeScale;
    }
}

void FaustSitar::updateInternal() {
    float period = _sampleRate / _baseFreq;
    
    // 2. Multi-Band Physics Mapping (Extended to 80Hz for E2 support)
    float normFreq = (_baseFreq - 80.0f) / (600.0f - 80.0f); // Map E2-D5 to 0-1
    normFreq = std::max(0.0f, std::min(1.0f, normFreq));

    // 1. Dynamic Sustain (T60 Scaling): Long (6s) for bass, shorter (3s) for treble
    float dynSustain = 6.0f - (normFreq * 3.0f);
    _feedback = std::pow(0.001f, 1.0f / (dynSustain * _sampleRate / period));
    
    // Jivari Threshold: Kept very low (0.08 - 0.12) so even tiny vibrations hit the bridge
    _dynThreshold = 0.08f + (normFreq * 0.04f);
    
    _dynDispersion = 0.35f - (normFreq * 0.20f);
    
    // Strike Intensity: Normalized to prevent F#3 volume spikes
    _dynStrikeScale = 0.25f - (normFreq * 0.05f);
    
    // 3. Dynamic Taraf Decay
    float dynTarafT60 = 1.2f - (normFreq * 0.6f);
    for (auto& m : _sympModes) { m.t60 = dynTarafT60; }

    // 4. Full-Band Parameters
    _dynDamping = 0.97f + (normFreq * 0.01f); // Capped at ~0.98 for natural decay
    _dynDC = 0.985f + (normFreq * 0.01f);
    _dynFold = 0.85f - (normFreq * 0.25f);
    _dynOutputGain = 1.0f + (normFreq * 1.5f); 
}

void FaustSitar::render(int numFrames, float* buffer) {
    float period = _sampleRate / _baseFreq;
    if (period < 2.0f) period = 2.0f;

    for (int i = 0; i < numFrames; i++) {
        float readPos = (float)_writePtr - period;
        while (readPos < 0) readPos += (float)_delayLine.size();
        
        int idx1 = (int)readPos % _delayLine.size();
        int idx2 = (idx1 + 1) % _delayLine.size();
        float frac = readPos - (int)readPos;
        
        float sig = _delayLine[idx1] * (1.0f - frac) + _delayLine[idx2] * frac;

        // 2. Jivari Bridge - Dynamic Wave-Folding
        float jivariReflection = sig;
        if (_jivari > 0.01f) {
            float threshold = _dynThreshold; 
            if (sig > threshold) {
                float delta = sig - threshold;
                jivariReflection = threshold - delta * (_dynFold + _jivari * _dynFold); 
            }
        }

        // Multi-Band Stability: Hard clip for sustain and "zing"
        if (jivariReflection > 1.2f) jivariReflection = 1.2f;
        if (jivariReflection < -1.2f) jivariReflection = -1.2f;

        // 3. String Loop Filter (Dynamic Damping)
        _lpState = jivariReflection * _dynDamping + _lpState * (1.0f - _dynDamping);
        float feedbackSig = _lpState * _feedback;

        // 4. Dynamic Dispersion (The Growl)
        float apIn = feedbackSig;
        const float a = _dynDispersion; 
        for (int j = 0; j < 4; j++) {
            float out = a * apIn + _apX[j] - a * _apY[j];
            _apX[j] = apIn;
            _apY[j] = out;
            apIn = out;
        }
        float dispSig = apIn;

        // 5. Dynamic DC Blocker
        float dcBlockOut = dispSig - _prevIn + _dynDC * _dcState;
        _prevIn = dispSig;
        _dcState = dcBlockOut;

        float saturated = dcBlockOut;
        if (saturated > 1.0f) saturated = 1.0f;
        if (saturated < -1.0f) saturated = -1.0f;
        
        _delayLine[_writePtr] = saturated;
        _writePtr = (_writePtr + 1) % _delayLine.size();

        // 6. Sympathetic Resonance (The Aura)
        float symp = 0.0f;
        for (auto& m : _sympModes) {
            symp += m.process(saturated);
        }

        float mixed = (saturated + symp * _sympGain);
        buffer[i] = std::tanh(mixed * _dynOutputGain);
    }
}
