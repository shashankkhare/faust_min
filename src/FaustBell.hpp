#ifndef FAUST_BELL_HPP
#define FAUST_BELL_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustBell {
public:
    FaustBell(float sampleRate);
    void setFrequency(float freq);
    void setDuration(float seconds);
    void setDamping(float damping);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
