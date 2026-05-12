#include "FaustHiHat.hpp"
#include "FaustHihatDSP.hpp"
#include <string>

FaustHiHat::FaustHiHat(float sampleRate) {
    mDSP.reset(new FaustHihatDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustHiHat::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustHiHat::strike(float velocity) {
    setParam("gain", velocity);
    setParam("gate", 1.0f);
}

void FaustHiHat::setOpenness(float amount) {
    setParam("openness", amount);
}

void FaustHiHat::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
