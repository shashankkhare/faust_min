#include "FaustBell.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

FaustBell::FaustBell(float sampleRate) : _sampleRate(sampleRate), _baseFreq(440.0f), _duration(6.0f), _damping(0.0f), _excitation(0.0f), _strikeEnv(0.0f) {
    struct ModeData { float ratio; float t60; float gain; };
    std::vector<ModeData> data = {
        {0.500f, 8.0f, 0.8f},  {1.000f, 6.0f, 1.0f}, {1.200f, 4.0f, 0.6f},
        {1.500f, 3.5f, 0.5f},  {2.000f, 2.5f, 0.4f}, {2.511f, 1.5f, 0.3f},
        {4.000f, 1.0f, 0.2f}
    };

    for (const auto& d : data) {
        Faust::Resonator m;
        m.ratio = d.ratio;
        m.t60 = d.t60;
        m.gain = d.gain;
        m.init(); 
        _baseT60s.push_back(d.t60);
        _modes.push_back(m);
    }
    updateInternal();
}

void FaustBell::setFrequency(float freq) {
    _baseFreq = freq;
    updateInternal();
}

void FaustBell::setDuration(float seconds) {
    _duration = seconds;
    if (_duration < 0.1f) _duration = 0.1f;
    updateInternal();
}

void FaustBell::setDamping(float damping) {
    _damping = damping;
    updateInternal();
}

void FaustBell::strike(float velocity) {
    _excitation = velocity * 0.15f; 
    _strikeEnv = 1.0f; 
}

void FaustBell::updateInternal() {
    for (size_t i = 0; i < _modes.size(); ++i) {
        float frequencyDamping = std::pow(_modes[i].ratio, -_damping);
        _modes[i].t60 = _duration * (_baseT60s[i] / 6.0f) * frequencyDamping;
        _modes[i].update(_baseFreq, _sampleRate);
    }
}

void FaustBell::render(int numFrames, float* buffer) {
    static std::mt19937 gen(42);
    static std::uniform_real_distribution<float> dis(-1.0, 1.0);
    for (int i = 0; i < numFrames; ++i) {
        float noise = dis(gen);
        float impactNoise = noise * _strikeEnv * 0.02f;
        _strikeEnv *= 0.99f;
        float x = _excitation + impactNoise;
        _excitation = 0.0f;
        float out = 0.0f;
        for (auto& m : _modes) {
            out += m.process(x) * m.gain;
        }
        buffer[i] = out * 0.5f;
    }
}
