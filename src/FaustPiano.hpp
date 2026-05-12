#ifndef FAUST_PIANO_HPP
#define FAUST_PIANO_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustPiano {
public:
    FaustPiano(float sampleRate);
    void setFrequency(float freq);
    void setSustain(float sustain);
    void setStiffness(float stiffness);
    void strike(float velocity, float hardness = 0.5f);
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
