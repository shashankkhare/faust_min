#include "FaustPiano.hpp"
#include "FaustPianoDSP.hpp"
#include <string>

FaustPiano::FaustPiano(float sampleRate) {
    mDSP.reset(new FaustPianoDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustPiano::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustPiano::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustPiano::setSustain(float sustain) {
    setParam("sustain", sustain);
}

void FaustPiano::setStiffness(float stiffness) {
    setParam("stiffness", stiffness);
}

void FaustPiano::strike(float velocity, float hardness) {
    setParam("gain", velocity);
    setParam("hardness", hardness);
    setParam("gate", 1.0f);
}

void FaustPiano::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
