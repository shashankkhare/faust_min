#include "FaustCommon.hpp"
#include <vector>

class FaustSitar {
public:
    FaustSitar(float sampleRate);
    void setFrequency(float freq);
    void setJivari(float amount);
    void setSympatheticGain(float gain);
    void pluck(float velocity);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _baseFreq;
    float _jivari;
    float _sympGain;

    // String Waveguide
    std::vector<float> _delayLine;
    int _writePtr;
    float _feedback;
    float _lpState;
    float _dcState;
    float _prevIn;

    // Dispersion All-Pass Cascade (4 stages)
    float _apX[4];
    float _apY[4];

    // Sympathetic Resonators
    std::vector<Faust::Resonator> _sympModes;

    float _dynThreshold;
    float _dynDispersion;
    float _dynStrikeScale;
    float _dynDamping;
    float _dynDC;
    float _dynFold;
    float _dynOutputGain;

    void updateInternal();
};
