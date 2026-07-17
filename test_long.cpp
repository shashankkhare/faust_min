#include "FaustInstrument.hpp"
#include "FaustMixer.hpp"
#include <iostream>
#include <unistd.h>
int main() {
    FaustMixer& mixer = FaustMixer::getInstance();
    mixer.init(48000);
    mixer.start();
    auto inst = std::make_shared<FaustInstrument>(47, DSPExecutionType::StaticCompiled, 48000.0f);
    int track = mixer.addTrack(50.0f);
    mixer.addInstrumentToTrack(track, inst.get());
    inst->enableDiagnosticLogging(true);
    inst->noteOn(400.0, 1.0, 1.0);
    for(int i=0; i<10; i++) {
        usleep(1000000);
        auto logs = inst->getDiagnosticLogs();
        if(!logs.empty()) {
            std::cout << "Sec " << i << " RMS: " << logs.back().rmsEnvelope << std::endl;
        }
    }
    mixer.removeTrack(track);
    return 0;
}
