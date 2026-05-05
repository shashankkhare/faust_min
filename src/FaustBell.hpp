#ifndef FAUST_BELL_HPP
#define FAUST_BELL_HPP

#include <vector>
#include "FaustCommon.hpp"

class FaustBell {
public:
    FaustBell(float sampleRate);
    void setFrequency(float freq);
    void setDuration(float seconds);
    void setDamping(float damping);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    void updateInternal();
    float _sampleRate;
    float _baseFreq;
    float _duration;
    float _damping;
    float _excitation;
    float _strikeEnv;
    std::vector<float> _baseT60s;
    std::vector<Faust::Resonator> _modes;
};

#endif
