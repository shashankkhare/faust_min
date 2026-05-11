#include "FaustPiano.hpp"
#include <cmath>
#include <algorithm>

// --- PianoString Implementation ---

PianoString::PianoString() : _sampleRate(44100.0f), _freq(220.0f), _velocity(0.0f), _excitation(0.0f), _hammerLP(0.0f), _sustain(0.999f), _stiffness(0.05f), _writePtr(0), _lpState(0.0f), _dcState(0.0f) {
    for(int i=0; i<4; i++) { _apX[i] = _apY[i] = 0.0f; }
}

void PianoString::init(float sampleRate) {
    _sampleRate = sampleRate;
    _delayLine.assign((size_t)(sampleRate / 20.0f) + 10, 0.0f);
}

bool PianoString::isActive() const {
    return _velocity > 0.0001f || std::abs(_lpState) > 0.00001f;
}

void PianoString::strike(float freq, float velocity, float hardness, float stiffness, float sustain) {
    _freq = freq;
    _velocity = velocity;
    _stiffness = stiffness;
    _sustain = sustain;
    
    // Clear old state to prevent clicks/pops
    std::fill(_delayLine.begin(), _delayLine.end(), 0.0f);
    for(int i=0; i<4; i++) { _apX[i] = 0.0f; }
    _lpState = 0.0f;
    _dcState = 0.0f;

    _excitation = velocity * (0.1f + 0.2f * hardness);
}

float PianoString::render() {
    if (!isActive() && _excitation < 0.0001f) return 0.0f;
    if (_delayLine.size() == 0) init(_sampleRate);

    float period = _sampleRate / _freq;
    float readPos = (float)_writePtr - period;
    while (readPos < 0) readPos += (float)_delayLine.size();
    
    int idx1 = (int)readPos % _delayLine.size();
    int idx2 = (idx1 + 1) % _delayLine.size();
    float frac = readPos - (int)readPos;
    float delayed = _delayLine[idx1] * (1.0f - frac) + _delayLine[idx2] * frac;

    // Hammer Strike
    float hammer = 0.0f;
    if (_excitation > 0.0001f) {
        hammer = _excitation;
        _excitation *= 0.98f; 
    }
    
    float val = delayed + hammer;
    
    // Stiffness AP
    float a = _stiffness * 0.4f;
    for(int i=0; i<4; i++) {
        float x = val;
        val = a * x + _apX[i];
        _apX[i] = x - a * val;
    }

    _lpState = val * 0.6f + _lpState * 0.4f;
    float out = _lpState * _sustain;
    
    _dcState = out * 0.005f + _dcState * 0.995f;
    float blocked = out - _dcState;

    _delayLine[_writePtr] = blocked;
    _writePtr = (_writePtr + 1) % _delayLine.size();

    return blocked;
}

// --- FaustPiano Implementation ---

FaustPiano::FaustPiano(float sampleRate) 
    : _sampleRate(sampleRate), _currentFreq(261.63f), _globalSustain(0.9997f), _globalStiffness(0.05f), _nextVoice(0) {
    for(int i=0; i<16; i++) {
        _strings[i].init(sampleRate);
    }
}

void FaustPiano::setFrequency(float freq) {
    _currentFreq = freq;
}

void FaustPiano::setSustain(float sustain) {
    _globalSustain = std::min(0.9999f, std::max(0.9f, sustain));
}

void FaustPiano::setStiffness(float stiffness) {
    _globalStiffness = std::min(0.9f, std::max(0.001f, stiffness));
}

void FaustPiano::strike(float velocity, float hardness) {
    int voiceToUse = -1;
    for(int i=0; i<16; i++) {
        if (!_strings[i].isActive()) {
            voiceToUse = i;
            break;
        }
    }
    if (voiceToUse == -1) {
        voiceToUse = _nextVoice;
        _nextVoice = (_nextVoice + 1) % 16;
    }
    _strings[voiceToUse].strike(_currentFreq, velocity, hardness, _globalStiffness, _globalSustain);
}

void FaustPiano::render(int numFrames, float* buffer) {
    std::fill(buffer, buffer + numFrames, 0.0f);
    for (int v = 0; v < 16; v++) {
        for (int i = 0; i < numFrames; i++) {
            buffer[i] += _strings[v].render();
        }
    }
    for (int i = 0; i < numFrames; i++) {
        buffer[i] = std::tanh(buffer[i] * 1.5f);
    }
}
