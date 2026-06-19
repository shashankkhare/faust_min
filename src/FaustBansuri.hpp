/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustBansuri.hpp
 * Wrapper for the Faust-generated Bansuri DSP code.
 */

#ifndef FAUST_BANSURI_HPP
#define FAUST_BANSURI_HPP

#include "FaustInstrument.hpp"

class FaustBansuri : public FaustInstrument {
public:
    FaustBansuri(float sampleRate);
    void setVibrato(float rate, float depth);
    int getID() const override { return 17; }
};

#endif // FAUST_BANSURI_HPP
