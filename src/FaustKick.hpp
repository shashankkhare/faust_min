#include "FaustCommon.hpp"
#include <vector>

class FaustKick {
public:
    FaustKick(float sampleRate);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _currentFreq;
    float _targetFreq;
    Faust::Resonator _body;
    Faust::Resonator _click;
    float _excitation;
    float _lpState;

    void updateInternal();
};
