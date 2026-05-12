#include "FaustSax.hpp"
#include "FaustSaxDSP.hpp"
#include <string>

FaustSax::FaustSax(float sampleRate) {
    mDSP.reset(new FaustSaxDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustSax::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustSax::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustSax::setVibrato(float rate, float depth) {
    setParam("vibrato_rate", rate);
    setParam("vibrato_depth", depth);
}

void FaustSax::strike(float velocity) {
    setParam("gain", velocity);
    setParam("gate", 1.0f);
}

void FaustSax::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
