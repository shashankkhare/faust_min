#include "FaustSnare.hpp"
#include <random>

FaustSnare::FaustSnare(float sampleRate) : _sampleRate(sampleRate), _snareEnv(0.0f), _excitation(0.0f) {
    _head.ratio = 1.0f;
    _head.t60 = 0.2f; // Snappy head
    _head.gain = 1.0f;
    _head.init();
    updateInternal();
}

void FaustSnare::strike(float velocity) {
    _excitation = velocity;
    _snareEnv = velocity;
}

void FaustSnare::updateInternal() {
    _head.update(210.0f, _sampleRate); // G3 snare tuning
}

void FaustSnare::render(int numFrames, float* buffer) {
    static std::mt19937 gen(46);
    static std::uniform_real_distribution<float> dis(-1.0, 1.0);

    for (int i = 0; i < numFrames; ++i) {
        float x = _excitation;
        _excitation = 0.0f;

        // Head resonance
        float head = _head.process(x);

        // Snare wires (noise)
        float noise = dis(gen) * _snareEnv;
        _snareEnv *= 0.999f; // Snare decay

        buffer[i] = std::tanh((head + noise) * 1.5f); 
    }
}
