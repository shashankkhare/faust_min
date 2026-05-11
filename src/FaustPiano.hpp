#ifndef FAUST_PIANO_HPP
#define FAUST_PIANO_HPP

#include <vector>

class PianoString {
public:
    PianoString();
    void init(float sampleRate);
    void strike(float freq, float velocity, float hardness, float stiffness, float sustain);
    float render();
    bool isActive() const;

private:
    float _sampleRate;
    float _freq;
    float _velocity;
    float _excitation;
    float _hammerLP;
    float _sustain;
    float _stiffness;
    std::vector<float> _delayLine;
    int _writePtr;
    
    // State for all-pass filters (stiffness)
    float _apX[4], _apY[4];
    float _lpState;
    float _dcState;
};

class FaustPiano {
public:
    FaustPiano(float sampleRate);
    void setFrequency(float freq);
    void setSustain(float sustain);
    void setStiffness(float stiffness);
    void strike(float velocity, float hardness = 0.5f);
    void render(int numFrames, float* buffer);

private:
    float _sampleRate;
    float _currentFreq;
    float _globalSustain;
    float _globalStiffness;
    int _nextVoice;
    PianoString _strings[16];
};

#endif // FAUST_PIANO_HPP
