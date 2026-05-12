#include "FaustBell.hpp"
#include "FaustBellDSP.hpp"
#include <string>

FaustBell::FaustBell(float sampleRate) {
    mDSP.reset(new FaustBellDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

void FaustBell::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustBell::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustBell::setDuration(float seconds) {
    setParam("ring_time", seconds);
}

void FaustBell::setDamping(float damping) {
    // Unmapped static control path
}

void FaustBell::strike(float velocity) {
    setParam("gain", velocity);
    setParam("gate", 1.0f);
}

void FaustBell::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
    setParam("gate", 0.0f);
}
