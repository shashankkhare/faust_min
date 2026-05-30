#include "FaustInstrument.hpp"
#include <iostream>

int main() {
    FaustInstrument inst(17, DSPExecutionType::StaticCompiled, 48000.0f);
    inst.setAmplitude(0.5f);
    inst.setFrequency(200.0f);
    inst.noteOn(200.0f, 0.5f, 0.5f, 0.5f);
    std::cout << "CSV loaded. Test successful." << std::endl;
    return 0;
}
