#include "FaustBowl.hpp"
#include "FaustCommon.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

FaustBowl::FaustBowl(float sampleRate) : _sampleRate(sampleRate), _baseFreq(220.0f), _duration(6.0f), _rub(0.0f), _waver(0.002f), _excitation(0.0f), _strikeEnv(0.0f) {
    struct ModeData { float ratio; float t60; float gain; };
    std::vector<ModeData> data = {
        {1.000f, 6.0f, 1.0f},  {1.002f, 5.8f, 1.0f},
        {2.780f, 4.0f, 0.6f},  {2.785f, 3.8f, 0.6f},
        {5.210f, 2.5f, 0.4f},  {5.215f, 2.3f, 0.4f},
        {8.400f, 1.5f, 0.2f},  {8.410f, 1.4f, 0.2f}
    };

    for (const auto& d : data) {
        Faust::Resonator m;
        m.ratio = d.ratio;
        m.t60 = d.t60;
        m.gain = d.gain;
        m.init(); // Fixed: Standardized initialization
        _baseT60s.push_back(d.t60);
        _modes.push_back(m);
    }
    updateInternal();
}

void FaustBowl::setFrequency(float freq) {
    _baseFreq = freq;
    updateInternal();
}

void FaustBowl::setDuration(float seconds) {
    _duration = seconds;
    if (_duration < 0.1f) _duration = 0.1f;
    updateInternal();
}

void FaustBowl::strike(float velocity) {
    _excitation = velocity * 0.15f; 
    _strikeEnv = 1.0f; 
}

void FaustBowl::setRub(float rub) {
    _rub = rub;
}

void FaustBowl::setWaver(float waver) {
    _waver = waver;
    updateInternal();
}

void FaustBowl::updateInternal() {
    std::vector<float> baseRatios = {1.0f, 2.78f, 5.21f, 8.4f};
    int modeIdx = 0;
    for (float baseRatio : baseRatios) {
        _modes[modeIdx].ratio = baseRatio;
        _modes[modeIdx].t60 = (_baseT60s[modeIdx] / 6.0f) * _duration;
        _modes[modeIdx].update(_baseFreq, _sampleRate);
        
        _modes[modeIdx + 1].ratio = baseRatio * (1.0f + _waver);
        _modes[modeIdx + 1].t60 = (_baseT60s[modeIdx + 1] / 6.0f) * _duration;
        _modes[modeIdx + 1].update(_baseFreq, _sampleRate);
        
        modeIdx += 2;
    }
}

void FaustBowl::render(int numFrames, float* buffer) {
    static std::mt19937 gen(42);
    static std::uniform_real_distribution<float> dis(-1.0, 1.0);
    for (int i = 0; i < numFrames; ++i) {
        float noise = dis(gen);
        float contactNoise = noise * _strikeEnv * 0.01f;
        _strikeEnv *= 0.995f;
        float rubExcitation = noise * _rub * 0.002f;
        float x = _excitation + rubExcitation + contactNoise;
        _excitation = 0.0f;
        float out = 0.0f;
        for (auto& m : _modes) {
            out += m.process(x) * m.gain;
        }
        buffer[i] = out * 0.6f;
    }
}
