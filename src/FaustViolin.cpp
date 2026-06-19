/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustViolin.cpp
 * Wrapper implementation for the Faust Violin DSP.
 * Uses pm.violinModel — a bowed string physical model based on
 * Smith/Michon waveguide synthesis with Helmholtz motion at the bow contact point.
 */

#include "FaustViolin.hpp"
#include "FaustViolinDSP.hpp"

FaustViolin::FaustViolin(float sampleRate) {
    setSampleRate(sampleRate);
    setDSP(new FaustViolinDSP());
    startInternalStream(sampleRate);
}

void FaustViolin::setVibrato(float rate, float depth) {
    // No-op: violin vibrato is inherent to the physical model's
    // bow-pressure/velocity dynamics. Future: expose via bowPressure modulation.
}
