#include "FaustDayan.hpp"
#include "FaustDayanDSP.hpp"
#include <string>

FaustDayan::FaustDayan(float sampleRate) {
    mDSP.reset(new FaustDayanDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustDayan::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustDayan::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustDayan::setMute(bool muted) {
    setParam("strike", muted ? 0.1f : 1.0f);
}

void FaustDayan::strike(float velocity) {
    setParam("velocity", velocity);
    setParam("gate", 1.0f);
}

void FaustDayan::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
