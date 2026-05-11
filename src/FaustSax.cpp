#include "FaustSax.hpp"
#include <random>
#include <algorithm>
#include <cmath>

FaustSax::FaustSax(float sampleRate) 
    : _sampleRate(sampleRate), _freq(220.0f), _breath(0.0f), _vibratoRate(5.5f), _vibratoDepth(0.0f), _vibratoPhase(0.0f), _lpState(0.0f), _dcState(0.0f), _smoothBreath(0.0f), _writePtr(0), _seed(1234) {
    size_t size = (size_t)(sampleRate / 20.0f) + 100;
    _delayLine.assign(size, 0.0f);
}

void FaustSax::setFrequency(float freq) {
    _freq = std::max(40.0f, freq);
}

void FaustSax::strike(float velocity) {
    _breath = velocity;
}

void FaustSax::updateInternal() {
}

void FaustSax::setVibrato(float rate, float depth) {
    _vibratoRate = rate;
    _vibratoDepth = depth;
}

void FaustSax::render(int numFrames, float* buffer) {
    for (int i = 0; i < numFrames; ++i) {
        // Vibrato
        _vibratoPhase += (6.2831853f * _vibratoRate / _sampleRate);
        if (_vibratoPhase > 6.2831853f) _vibratoPhase -= 6.2831853f;
        float vib = std::sin(_vibratoPhase) * _vibratoDepth;
        
        float modulatedFreq = _freq * (1.0f + vib);
        float period = _sampleRate / modulatedFreq;

        float readPos = (float)_writePtr - period;
        while (readPos < 0) readPos += (float)_delayLine.size();
        
        int idx1 = (int)readPos % _delayLine.size();
        int idx2 = (idx1 + 1) % _delayLine.size();
        float frac = readPos - (int)readPos;
        
        // --- Bore Reflection ---
        float delayedSig = _delayLine[idx1] * (1.0f - frac) + _delayLine[idx2] * frac;
        float borePressure = delayedSig * -0.985f; // Stronger bell reflection

        // Turbulence (Noise)
        _seed = _seed * 1103515245 + 12345;
        float noise = (float)(_seed / 65536 % 32768) / 32768.0f * 2.0f - 1.0f;
        
        // Breath Smoothing (Kill the Thud)
        _smoothBreath = _breath * 0.005f + _smoothBreath * 0.995f; 
        
        float mouthPressure = _smoothBreath + 0.005f * noise * _smoothBreath; 
        
        // --- Negative-Resistance Reed Model ---
        float pDelta = mouthPressure - borePressure;
        
        // CRITICAL: The Reed Table must have a NEGATIVE SLOPE to oscillate.
        // H(d) = offset - slope * d
        float reedTable = 0.6f - (0.4f * pDelta); 
        if (reedTable > 1.0f) reedTable = 1.0f;
        if (reedTable < -1.0f) reedTable = -1.0f;
        
        // Waveguide Interaction
        float newBorePressure = borePressure + (pDelta * reedTable);
        
        // Low-pass Filter (Damping)
        _lpState = newBorePressure * 0.6f + _lpState * 0.4f; 
        
        _delayLine[_writePtr] = _lpState;
        _writePtr = (_writePtr + 1) % _delayLine.size();
        
        // --- Output High-Pass (Surgical DC Removal) ---
        // Prevents the "Thud" from reaching the speaker
        _dcState = _lpState * 0.0005f + _dcState * 0.9995f;
        float out = _lpState - _dcState;
        
        // Warm saturation for Jazz tone
        buffer[i] = std::tanh(out * 4.5f);
    }
}
