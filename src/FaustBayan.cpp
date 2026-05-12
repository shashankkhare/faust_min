#include "FaustBayan.hpp"
#include "FaustBayanDSP.hpp"
#include <string>

FaustBayan::FaustBayan(float sampleRate) {
    mDSP.reset(new FaustBayanDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustBayan::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustBayan::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustBayan::setMeend(float multiplier) {
    setParam("meend", multiplier);
}

void FaustBayan::setMute(bool muted) {
    setParam("strike", muted ? 0.0f : 1.0f);
}

void FaustBayan::strike(float velocity) {
    setParam("velocity", velocity);
    setParam("gate", 1.0f);
}

void FaustBayan::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
