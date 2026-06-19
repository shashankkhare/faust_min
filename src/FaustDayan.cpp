/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file FaustDayan.cpp
 * @brief Implementation file for FaustDayan
 * 
 * DESIGN: Physical modeling synthesis instrument wrapper. It encapsulates the Faust-generated C++ DSP logic and exposes high-level expressive controls like frequency, velocity, and articulation.
 */

#include "FaustDayan.hpp"
#include "FaustDayanDSP.hpp"

FaustDayan::FaustDayan(float sampleRate) {
    setSampleRate(sampleRate);
    setDSP(new FaustDayanDSP());
    startInternalStream(sampleRate);
}

void FaustDayan::setMute(bool muted) {
    setParam("strike", muted ? 1.0f : 0.0f); // 1.0 = tk (muted), 0.0 = Na (open)
}
