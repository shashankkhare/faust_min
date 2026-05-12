#include "FaustFlute.hpp"
#include "FaustFluteDSP.hpp"
#include <string>

FaustFlute::FaustFlute(float sampleRate) {
    mDSP.reset(new FaustFluteDSP());
    mDSP->init((int)sampleRate);
    mUI.reset(new MapUI());
    mDSP->buildUserInterface(mUI.get());
}

FaustFlute::~FaustFlute() {}

void FaustFlute::setParam(const char* shortName, float val) {
    for (int i = 0; i < mUI->getParamsCount(); i++) {
        std::string addr = mUI->getParamAddress(i);
        if (addr.find(shortName) != std::string::npos) {
            mUI->setParamValue(addr, val);
            break;
        }
    }
}

void FaustFlute::setFrequency(float freq) {
    setParam("freq", freq);
}

void FaustFlute::setPressure(float pressure) {
    setParam("gain", pressure);
    setParam("gate", pressure > 0.01f ? 1.0f : 0.0f);
}

void FaustFlute::setVibrato(float rate, float depth) {
    // Unsupported/no-op in pure flute.dsp
}

void FaustFlute::reset() {
    // Handled natively by dsp execution states
}

void FaustFlute::render(int numFrames, float* buffer) {
    FAUSTFLOAT* outputs[1] = { buffer };
    mDSP->compute(numFrames, nullptr, outputs);
}
