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

#include "FaustInstrument.hpp"
#include <iostream>

int main() {
    FaustInstrument* inst = new FaustInstrument(17, DSPExecutionType::StaticCompiled, 48000, 1.0f);
    inst->setFrequency(440.0f);
    inst->setVelocity(1.0f);
    inst->setAmplitude(1.0f);
    inst->noteOn(440.0f, 1.0f, -1.0f, 1.0f);
    // let's peek at the event queue or the actual values in MapUI
    // MapUI isn't easily accessible but we can test if it compiles and runs.
    std::cout << "Test completed." << std::endl;
    delete inst;
    return 0;
}
