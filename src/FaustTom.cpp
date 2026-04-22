#include "FaustTom.hpp"

FaustTom::FaustTom(float sampleRate) : _sampleRate(sampleRate), _freq(100.0f), _excitation(0.0f) {
    _mode1.ratio = 1.0f;
    _mode1.t60 = 0.6f;
    _mode1.gain = 1.0f;
    _mode1.init();

    _mode2.ratio = 1.6f; // Harmonic 2 of the drum head
    _mode2.t60 = 0.4f;
    _mode2.gain = 0.6f;
    _mode2.init();

    updateInternal();
}

void FaustTom::setFrequency(float freq) {
    _freq = freq;
    updateInternal();
}

void FaustTom::strike(float velocity) {
    _excitation = velocity;
}

void FaustTom::updateInternal() {
    _mode1.update(_freq, _sampleRate);
    _mode2.update(_freq, _sampleRate);
}

void FaustTom::render(int numFrames, float* buffer) {
    for (int i = 0; i < numFrames; ++i) {
        float x = _excitation;
        _excitation = 0.0f;
        buffer[i] = _mode1.process(x) + _mode2.process(x);
    }
}
