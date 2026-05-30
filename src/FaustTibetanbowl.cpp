#include "FaustTibetanbowl.hpp"
#include "FaustTibetanbowlDSP.hpp"

FaustTibetanbowl::FaustTibetanbowl(float sampleRate) {
    setSampleRate(sampleRate);
    setDSP(new FaustTibetanbowlDSP());
    startInternalStream(sampleRate);
}

void FaustTibetanbowl::strike(float velocity) {
    noteOn(-1.0f, velocity);
}
