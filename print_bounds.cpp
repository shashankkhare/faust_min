#include <iostream>
#include <memory>
#include "src/FaustInstrument.hpp"
#include "src/InstrumentMapper.hpp"
int main() {
    auto inst = std::make_shared<FaustInstrument>(11, DSPExecutionType::InterpretedByte, 48000);
    float fmin, fmax;
    if (inst->getParamBounds("freq", fmin, fmax)) {
        std::cout << "fmin: " << fmin << ", fmax: " << fmax << std::endl;
    } else {
        std::cout << "No freq param" << std::endl;
    }
}
