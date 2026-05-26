/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustTrumpet.hpp
 * Wrapper for the Faust-generated Trumpet DSP code.
 */

#ifndef FAUST_TRUMPET_HPP
#define FAUST_TRUMPET_HPP

#include "FaustInstrument.hpp"

class FaustTrumpet : public FaustInstrument {
public:
    FaustTrumpet(float sampleRate);
    void strike(float velocity);
    void setVibrato(float rate, float depth);
    int getID() const override { return 15; }
};

#endif // FAUST_TRUMPET_HPP
