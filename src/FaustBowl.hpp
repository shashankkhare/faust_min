#ifndef FAUST_BOWL_HPP
#define FAUST_BOWL_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustBowl {
public:
    FaustBowl(float sampleRate);
    void setFrequency(float freq);
    void setDuration(float seconds);
    void strike(float velocity);
    void setRub(float rub);
    void setWaver(float waver);
    void render(int numFrames, float* buffer);
    void dispose() {}

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
