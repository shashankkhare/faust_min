/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustTrumpet.cpp
 * Wrapper implementation for the Faust Trumpet DSP.
 */

#include "FaustTrumpet.hpp"
#include "FaustTrumpetDSP.hpp"

FaustTrumpet::FaustTrumpet(float sampleRate) {
    setSampleRate(sampleRate);
    setDSP(new FaustTrumpetDSP());
    startInternalStream(sampleRate);
}

void FaustTrumpet::setVibrato(float rate, float depth) {
    setParam("vibrato_rate", rate);
    setParam("vibrato_depth", depth);
}

void FaustTrumpet::strike(float velocity) {
    setParam("gain", velocity);
    noteOn();
}
