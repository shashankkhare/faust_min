#include "FaustDayan.hpp"
#include <vector>
#include <cmath>
#include <algorithm>

FaustDayan::FaustDayan(float sampleRate) : _sampleRate(sampleRate), _baseFreq(293.66f), _excitation(0.0f), _muted(false) {
    struct ModeData { float ratio; float t60; float gain; };
    std::vector<ModeData> data = {
        {1.0f, 3.5f, 1.0f},
        {1.5f, 2.8f, 0.8f},
        {2.0f, 2.0f, 0.6f},
        {2.5f, 1.4f, 0.4f},
        {3.0f, 0.9f, 0.2f}
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

void FaustDayan::setFrequency(float freq) {
    _baseFreq = freq;
    updateInternal();
}

void FaustDayan::setMute(bool muted) {
    _muted = muted;
    struct ModeData { float t60; };
    std::vector<ModeData> baseT60 = { {3.5f}, {2.8f}, {2.0f}, {1.4f}, {0.9f} };
    float scale = _muted ? 0.05f : 1.0f;
    for (size_t i = 0; i < _modes.size() && i < baseT60.size(); ++i) {
        _modes[i].t60 = baseT60[i].t60 * scale;
    }
    updateInternal();
}

void FaustDayan::strike(float velocity) {
    _excitation = velocity * 0.15f;
}

void FaustDayan::updateInternal() {
    for (auto& m : _modes) {
        m.update(_baseFreq, _sampleRate);
    }
}

void FaustDayan::render(int numFrames, float* buffer) {
    for (int i = 0; i < numFrames; ++i) {
        float x = _excitation;
        _excitation = 0.0f;
        float out = 0.0f;
        for (auto& m : _modes) {
            out += m.process(x) * m.gain;
        }
        buffer[i] = std::tanh(out * 10.0f) * 0.8f;
    }
}
