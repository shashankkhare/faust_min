#include "FaustKick.hpp"
#include <cmath>

FaustKick::FaustKick(float sampleRate) 
    : _sampleRate(sampleRate), _currentFreq(150.0f), _targetFreq(60.0f), _excitation(0.0f), _lpState(0.0f) {
    _body.ratio = 1.0f;
    _body.t60 = 0.4f; 
    _body.gain = 1.0f;
    _body.init();

    _click.ratio = 1.0f; 
    _click.t60 = 0.01f;   // Ultra-tight beater hit
    _click.gain = 0.3f;
    _click.init();
    _click.update(3000.0f, _sampleRate); // Fixed beater frequency (Acoustic)

    updateInternal();
}

void FaustKick::strike(float velocity) {
    _excitation = velocity;
    _currentFreq = 150.0f; // Start high for the "click/thump"
}

void FaustKick::updateInternal() {
    _body.update(_currentFreq, _sampleRate);
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
        
        // Final Mix with Low-Pass for warmth (Rock/Jazz feel)
        float mixed = body * 1.2f + click;
        _lpState = mixed * 0.4f + _lpState * 0.6f;
        
        buffer[i] = std::tanh(_lpState);
    }
}
