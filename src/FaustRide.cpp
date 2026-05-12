#include "FaustRide.hpp"
#include "FaustRideDSP.hpp"
#include <string>

FaustRide::FaustRide(float sampleRate) {
    mDSP.reset(new FaustRideDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustRide::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustRide::strike(float velocity) {
    setParam("gain", velocity);
    setParam("gate", 1.0f);
}

void FaustRide::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
