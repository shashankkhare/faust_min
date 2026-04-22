#include "FaustCommon.hpp"
#include <vector>

class FaustBowl {
public:
    FaustBowl(float sampleRate);
    void setFrequency(float freq);
    void strike(float velocity);
    void setRub(float rub);
    void setWaver(float waver);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _baseFreq;
    float _rub;
    float _waver;
    std::vector<Faust::Resonator> _modes;
    float _excitation;

    void updateInternal();
};
