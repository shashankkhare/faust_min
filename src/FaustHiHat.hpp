#ifndef FAUST_HIHAT_HPP
#define FAUST_HIHAT_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustHiHat {
public:
    FaustHiHat(float sampleRate);
    void strike(float velocity);
    void setOpenness(float amount);
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
