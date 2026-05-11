#pragma once
#include "FaustCommon.hpp"
#include <vector>

class FaustSax {
public:
    FaustSax(float sampleRate);
    void strike(float velocity); // "Strike" here triggers the breath
    void setFrequency(float freq);
    void setVibrato(float rate, float depth);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _freq;
    float _breath;
    float _vibratoRate;
    float _vibratoDepth;
    float _vibratoPhase;
    float _lpState;
    float _dcState;
    float _smoothBreath;
    
    std::vector<float> _delayLine;
    int _writePtr;
    unsigned int _seed;
    
    void updateInternal();
};
