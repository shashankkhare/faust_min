#ifndef FAUST_FLUTE_HPP
#define FAUST_FLUTE_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustFlute {
public:
    FaustFlute(float sampleRate);
    ~FaustFlute();

    void setFrequency(float freq);
    void setPressure(float pressure);
    void setVibrato(float rate, float depth);
    void reset();
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
