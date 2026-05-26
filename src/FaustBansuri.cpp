/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustBansuri.cpp
 * Wrapper implementation for the Faust Bansuri DSP.
 */

#include "FaustBansuri.hpp"
#include "FaustBansuriDSP.hpp"

FaustBansuri::FaustBansuri(float sampleRate) {
    setSampleRate(sampleRate);
    setDSP(new FaustBansuriDSP());
    startInternalStream(sampleRate);
}

void FaustBansuri::setVibrato(float rate, float depth) {
    // No-op for Bansuri (vibrato is traditionally physical/breath controlled)
}

void FaustBansuri::strike(float velocity) {
    setParam("gain", velocity);
    noteOn();
}
