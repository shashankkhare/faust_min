/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustViolin.hpp
 * Wrapper for the Faust-generated Violin DSP code.
 * Uses pm.violinModel (bowed string physical model) from physmodels.lib.
 */

#ifndef FAUST_VIOLIN_HPP
#define FAUST_VIOLIN_HPP

#include "FaustInstrument.hpp"

class FaustViolin : public FaustInstrument {
public:
    FaustViolin(float sampleRate);
    void strike(float velocity);
    void setVibrato(float rate, float depth);
    int getID() const override { return 18; }
};

#endif // FAUST_VIOLIN_HPP
