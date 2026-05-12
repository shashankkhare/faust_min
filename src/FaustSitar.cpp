#include "FaustSitar.hpp"
#include "FaustSitarDSP.hpp"
#include <string>

FaustSitar::FaustSitar(float sampleRate) {
    mDSP.reset(new FaustSitarDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustSitar::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustSitar::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustSitar::setJivari(float amount) {
    setParam("jivari", amount);
}

void FaustSitar::setSympatheticGain(float gain) {
    setParam("symp_gain", gain);
}

void FaustSitar::pluck(float velocity) {
    setParam("pluck", 1.0f);
}

void FaustSitar::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("pluck", 0.0f);
}
