#include "FaustKick.hpp"
#include <cmath>

FaustKick::FaustKick(float sampleRate) : _sampleRate(sampleRate), _currentFreq(150.0f), _targetFreq(60.0f), _excitation(0.0f) {
    _body.ratio = 1.0f;
    _body.t60 = 0.5f; // Fast decay for kick
    _body.gain = 1.0f;
    _body.init();

    _click.ratio = 28.0f; // High frequency click (ratio to base)
    _click.t60 = 0.02f;   // Ultra-fast decay
    _click.gain = 0.4f;
    _click.init();

    updateInternal();
}

void FaustKick::strike(float velocity) {
    _excitation = velocity;
    _currentFreq = 150.0f; // Start high for the "click/thump"
}

void FaustKick::updateInternal() {
    _body.update(_currentFreq, _sampleRate);
    _click.update(_currentFreq, _sampleRate);
}

void FaustKick::render(int numFrames, float* buffer) {
    for (int i = 0; i < numFrames; ++i) {
        // Pitch sweep: Glide towards the target frequency
        if (_currentFreq > _targetFreq) {
            _currentFreq *= 0.9992f; // Geometric decay of frequency
            if (_currentFreq < _targetFreq) _currentFreq = _targetFreq;
            updateInternal();
        }

        float x = _excitation;
        _excitation = 0.0f;

        float body = _body.process(x);
        float click = _click.process(x);
        
        // Add subtle saturation (tanh) to the kick body for warmth
        buffer[i] = std::tanh(body * 1.2f + click);
    }
}
