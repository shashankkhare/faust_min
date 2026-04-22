#include "FaustCommon.hpp"
#include <vector>

class FaustTom {
public:
    FaustTom(float sampleRate);
    void setFrequency(float freq);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _freq;
    Faust::Resonator _mode1;
    Faust::Resonator _mode2;
    float _excitation;

    void updateInternal();
};
