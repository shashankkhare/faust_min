#include "FaustKick.hpp"
#include "FaustKickDSP.hpp"
#include <string>

FaustKick::FaustKick(float sampleRate) {
    mDSP.reset(new FaustKickDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustKick::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustKick::strike(float velocity) {
    setParam("gain", velocity);
    setParam("gate", 1.0f);
}

void FaustKick::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
