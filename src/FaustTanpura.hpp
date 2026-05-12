#ifndef FAUST_TANPURA_HPP
#define FAUST_TANPURA_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustTanpura {
public:
    FaustTanpura(float sampleRate);
    void setParams(float f1, float f2, float f3, float f4, float decay, float delay);
    void setFrequency(int stringIdx, float freq);
    void setJivari(float amount);
    void pluck(int stringIdx, float velocity);
    void setPlaying(bool playing);
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
