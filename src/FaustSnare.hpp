#include "FaustCommon.hpp"
#include <vector>

class FaustSnare {
public:
    FaustSnare(float sampleRate);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    Faust::Resonator _head;
    float _snareEnv;
    float _excitation;

    void updateInternal();
};
