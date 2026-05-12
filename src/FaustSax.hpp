#ifndef FAUST_SAX_HPP
#define FAUST_SAX_HPP

#include <memory>
#include <faust/gui/MapUI.h>
#include <faust/dsp/dsp.h>
#include <faust/gui/meta.h>

class FaustSax {
public:
    FaustSax(float sampleRate);
    void strike(float velocity);
    void setFrequency(float freq);
    void setVibrato(float rate, float depth);
    void render(int numFrames, float* buffer);

private:
    std::unique_ptr<dsp> mDSP;
    std::unique_ptr<MapUI> mUI;
    void setParam(const char* shortName, float val);
};

#endif
