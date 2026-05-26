/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustShakuhachi.cpp
 * Wrapper implementation for the Faust Shakuhachi DSP.
 */

#include "FaustShakuhachi.hpp"
#include "FaustShakuhachiDSP.hpp"

FaustShakuhachi::FaustShakuhachi(float sampleRate) {
    setSampleRate(sampleRate);
    setDSP(new FaustShakuhachiDSP());
    startInternalStream(sampleRate);
}

void FaustShakuhachi::setVibrato(float rate, float depth) {
    // No-op for Shakuhachi
}

void FaustShakuhachi::strike(float velocity) {
    setParam("gain", velocity);
    noteOn();
}
