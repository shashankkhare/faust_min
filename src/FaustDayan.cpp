#include "FaustDayan.hpp"

FaustDayan::FaustDayan(float sampleRate) : _sampleRate(sampleRate), _baseFreq(293.66f), _excitation(0.0f) {
    // Tuned harmonic modes for Dayan (Sa, Pa, Sa...)
    struct ModeData { float ratio; float t60; float gain; };
    std::vector<ModeData> data = {
        {1.0f, 3.5f, 1.0f}, // Sa
        {1.5f, 2.8f, 0.8f}, // Pa
        {2.0f, 2.0f, 0.6f}, // Sa+1
        {2.5f, 1.4f, 0.4f}, // Ga/Pa
        {3.0f, 0.9f, 0.2f}  // Sa+2
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
        buffer[i] = out * 0.4f;
    }
}
