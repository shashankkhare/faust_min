#include "FaustTanpura.hpp"
#include "FaustTanpuraDSP.hpp"
#include <string>

FaustTanpura::FaustTanpura(float sampleRate) {
    mDSP.reset(new FaustTanpuraDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustTanpura::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustTanpura::setParams(float f1, float f2, float f3, float f4, float decay, float delay) {
    setParam("freq", f1);
    setParam("gain", 0.8f);
}

void FaustTanpura::setFrequency(int stringIdx, float freq) {
    setParam("freq", freq);
}

void FaustTanpura::setJivari(float amount) {
    setParam("jivari", amount);
}

void FaustTanpura::pluck(int stringIdx, float velocity) {
    setParam("gate", 1.0f);
}

void FaustTanpura::setPlaying(bool playing) {
    setParam("gate", playing ? 1.0f : 0.0f);
}

void FaustTanpura::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
}
