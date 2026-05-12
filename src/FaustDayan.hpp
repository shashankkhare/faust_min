#ifndef FAUST_DAYAN_HPP
#define FAUST_DAYAN_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustDayan {
public:
    FaustDayan(float sampleRate);
    void setFrequency(float freq);
    void setMute(bool muted);
    void strike(float velocity);
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
