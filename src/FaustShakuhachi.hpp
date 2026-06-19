/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * FaustShakuhachi.hpp
 * Wrapper for the Faust-generated Shakuhachi DSP code.
 */

#ifndef FAUST_SHAKUHACHI_HPP
#define FAUST_SHAKUHACHI_HPP

#include "FaustInstrument.hpp"

class FaustShakuhachi : public FaustInstrument {
public:
    FaustShakuhachi(float sampleRate);
    void setVibrato(float rate, float depth);
    int getID() const override { return 16; }
};

#endif // FAUST_SHAKUHACHI_HPP
