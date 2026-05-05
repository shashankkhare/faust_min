#include "FaustCommon.hpp"
#include <vector>

class FaustDayan {
public:
    FaustDayan(float sampleRate);
    void setFrequency(float freq);
    void setMute(bool muted);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _baseFreq;
    std::vector<Faust::Resonator> _modes;
    float _excitation;
    bool _muted;

    void updateInternal();
};
