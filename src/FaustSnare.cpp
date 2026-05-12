#include "FaustSnare.hpp"
#include "FaustSnareDSP.hpp"
#include <string>

FaustSnare::FaustSnare(float sampleRate) {
    mDSP.reset(new FaustSnareDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustSnare::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustSnare::strike(float velocity) {
    setParam("gain", velocity);
    setParam("gate", 1.0f);
}

void FaustSnare::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
