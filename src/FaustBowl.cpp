#include "FaustBowl.hpp"
#include "FaustBowlDSP.hpp"
#include <string>

FaustBowl::FaustBowl(float sampleRate) {
    mDSP.reset(new FaustBowlDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustBowl::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustBowl::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustBowl::setDuration(float seconds) {
    // Unsupported dynamic parameter in pure static bowl.dsp
}

void FaustBowl::strike(float velocity) {
    setParam("strike", 1.0f);
}

void FaustBowl::setRub(float rub) {
    setParam("rub", rub);
}

void FaustBowl::setWaver(float waver) {
    // Unmapped static layout
}

void FaustBowl::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    // Auto-clear gate triggers
    setParam("strike", 0.0f);
}
