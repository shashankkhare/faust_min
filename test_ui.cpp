#include <iostream>
#include "src/FaustInstrument.hpp"
#include "src/InstrumentMapper.hpp"
#include "src/FaustMixer.hpp"

int main() {
    FaustMixer& mixer = FaustMixer::getInstance();
    mixer.init(48000);
    
    auto inst = std::make_shared<FaustInstrument>(44, DSPExecutionType::InterpretedByte, 48000);
    
    std::cout << "--- Param Addresses for Sarod ---" << std::endl;
    // We can't access mVoiceUIs directly because it's private. 
    // We can just call setParamImmediate with a dummy name and it will cache.
    // Actually, we can just compile and run this. But better:
    
    return 0;
}
