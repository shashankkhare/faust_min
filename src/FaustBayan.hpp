#include "FaustCommon.hpp"
#include <vector>

class FaustBayan {
public:
    FaustBayan(float sampleRate);
    void setFrequency(float freq);
    void setMeend(float multiplier);
    void setMute(bool muted);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _baseFreq;
    float _meend;
    float _currentFreq;
    std::vector<Faust::Resonator> _modes;
    float _excitation;
    bool _muted;

    void updateInternal();
};
