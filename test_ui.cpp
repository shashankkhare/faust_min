#include "src/FaustInstrument.hpp"
#include <iostream>
int main() {
    FaustInstrument inst(44, DSPExecutionType::StaticCompiled, 48000.0f);
    inst.setParamImmediate("freq", 440.0f, 0);
    std::cout << "Done test" << std::endl;
    return 0;
}
