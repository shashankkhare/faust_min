#include "FaustBayan.hpp"

FaustBayan::FaustBayan(float sampleRate) : _sampleRate(sampleRate), _baseFreq(110.0f), _meend(1.0f), _currentFreq(110.0f), _excitation(0.0f), _muted(false) {
    struct ModeData { float ratio; float t60; float gain; };
    std::vector<ModeData> data = {
        {1.0f, 1.8f, 1.0f},
        {2.1f, 1.0f, 0.7f},
        {3.2f, 0.5f, 0.4f}
    };

    for (const auto& d : data) {
        Faust::Resonator m;
        m.ratio = d.ratio;
        m.t60 = d.t60;
        m.gain = d.gain;
        m.init();
        _modes.push_back(m);
    }
    updateInternal();
}

void FaustBayan::setFrequency(float freq) {
    _baseFreq = freq;
    updateInternal();
}

void FaustBayan::setMeend(float multiplier) {
    _meend = multiplier;
}

void FaustBayan::setMute(bool muted) {
    _muted = muted;
    struct ModeData { float t60; };
    std::vector<ModeData> baseT60 = {
        {1.8f}, {1.0f}, {0.5f}
    };
    
    float scale = _muted ? 0.1f : 1.0f; // Damping for "Ka"
    for (size_t i = 0; i < _modes.size() && i < baseT60.size(); ++i) {
        _modes[i].t60 = baseT60[i].t60 * scale;
    }
    updateInternal();
}

void FaustBayan::strike(float velocity) {
    _excitation = velocity * 0.2f;
}

void FaustBayan::updateInternal() {
    for (auto& m : _modes) {
        m.update(_currentFreq, _sampleRate);
    }
}

void FaustBayan::render(int numFrames, float* buffer) {
    float targetFreq = _baseFreq * _meend;
    
    for (int i = 0; i < numFrames; ++i) {
        // Smooth frequency slide (meend)
        if (std::abs(_currentFreq - targetFreq) > 0.01f) {
            _currentFreq += (targetFreq - _currentFreq) * 0.005f; // Exponential smoothing
            updateInternal();
        }

        float x = _excitation;
        _excitation = 0.0f;

        float out = 0.0f;
        for (auto& m : _modes) {
            out += m.process(x) * m.gain;
        }
        buffer[i] = out * 0.6f;
    }
}
