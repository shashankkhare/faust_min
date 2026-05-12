#ifndef FAUST_BAYAN_HPP
#define FAUST_BAYAN_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustBayan {
public:
    FaustBayan(float sampleRate);
    void setFrequency(float freq);
    void setMeend(float multiplier);
    void setMute(bool muted);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
