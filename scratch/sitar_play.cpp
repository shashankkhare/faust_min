#include "../src/FaustMixer.hpp"
#include "../src/FaustInstrument.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char** argv) {
    double freq = 392.0;
    float amp = 0.9;
    if (argc > 1) freq = std::atof(argv[1]);
    if (argc > 2) amp = std::atof(argv[2]);

    FaustMixer mixer(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.start();
    usleep(500000);

    auto inst = std::make_shared<FaustInstrument>(9, DSPExecutionType::InterpretedByte, InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.registerInstrument(inst.get(), 0.8f);
    usleep(500000);

    std::cout << "Playing sitar: freq=" << freq << " Hz  amp=" << amp << std::endl;
    inst->noteOn(freq, amp);
    usleep(3000000);
    inst->noteOff();
    usleep(1500000);

    mixer.unregisterInstrument(inst.get());
    usleep(500000);
    mixer.stop();
    return 0;
}
