#include "FaustBowl.hpp"
#include "FaustCommon.hpp"
#include <vector>
#include <random>

FaustBowl::FaustBowl(float sampleRate) : _sampleRate(sampleRate), _baseFreq(220.0f), _rub(0.0f), _waver(0.002f), _excitation(0.0f) {
    // Mode data for a high-quality Tibetan bowl
    struct ModeData { float ratio; float t60; float gain; };
    std::vector<ModeData> data = {
        {1.000f, 6.0f, 1.0f},  {1.002f, 5.8f, 1.0f}, // Beating fundamental
        {2.780f, 4.0f, 0.6f},  {2.785f, 3.8f, 0.6f}, // Mode 2
        {5.210f, 2.5f, 0.4f},  {5.215f, 2.3f, 0.4f}, // Mode 3
        {8.400f, 1.5f, 0.2f},  {8.410f, 1.4f, 0.2f}  // Mode 4
    };

    for (const auto& d : data) {
        Faust::Resonator m;
        m.ratio = d.ratio;
        m.t60 = d.t60;
        m.gain = d.gain;
        m.y1 = m.y2 = 0.0f;
        _modes.push_back(m);
    }
    updateInternal();
}

void FaustBowl::setFrequency(float freq) {
    _baseFreq = freq;
    updateInternal();
}

void FaustBowl::strike(float velocity) {
    _excitation = velocity * 0.1f; // Impulse energy
}

void FaustBowl::setRub(float rub) {
    _rub = rub;
}

void FaustBowl::setWaver(float waver) {
    _waver = waver;
    updateInternal();
}

void FaustBowl::updateInternal() {
    // We update the second mode of each doublet based on _waver
    std::vector<float> baseRatios = {1.0f, 2.78f, 5.21f, 8.4f};
    int modeIdx = 0;
    for (float baseRatio : baseRatios) {
        _modes[modeIdx].ratio = baseRatio;
        _modes[modeIdx].update(_baseFreq, _sampleRate);
        
        _modes[modeIdx + 1].ratio = baseRatio * (1.0f + _waver);
        _modes[modeIdx + 1].update(_baseFreq, _sampleRate);
        
        modeIdx += 2;
    }
}

void FaustBowl::render(int numFrames, float* buffer) {
    static std::mt19937 gen(42);
    static std::uniform_real_distribution<float> dis(-1.0, 1.0);

    for (int i = 0; i < numFrames; ++i) {
        // Excitation = Impulse (one-off strike) + 
        // Sustain (Rubbing friction noise with low-pass to simulate mallet contact)
        float noise = dis(gen);
        float rubExcitation = noise * _rub * 0.002f;
        
        float x = _excitation + rubExcitation;
        _excitation = 0.0f; // Consume one-off strike energy

        float out = 0.0f;
        for (auto& m : _modes) {
            out += m.process(x) * m.gain;
        }
        
        buffer[i] = out * 0.5f;
    }
}
