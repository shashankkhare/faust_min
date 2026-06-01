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
