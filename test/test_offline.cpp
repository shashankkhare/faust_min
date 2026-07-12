#include "SequenceOrchestrator.hpp"
#include "FaustMixer.hpp"
#include "UMLSequence.hpp"
#include <iostream>
#include <cmath>

int main() {
    FaustMixer mixer;
    SequenceOrchestrator orch;
    
    SequenceGroup group;
    group.name = "Tibetan Bowl with Rain + LagNga";

    std::string umlRainmaker = "grid: 1\ninstrument: rainmaker\nloop: true\n\n9x..............................9x.";
    std::string umlBowl = "grid: 1\nbpm: 60\nbasefreq: 55.0\ninstrument: bowl\nloop: true\n\n80X...................";
    std::string umlLagngaHigh = "grid: 2\nbpm: 60\nbasefreq: 222.0\ninstrument: lagnga\nmallet_softness: 0.6\nloop: true\n\n7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. ";
    std::string umlLagngaLow = "grid: 2\nbpm: 60\nbasefreq: 111.0\ninstrument: lagnga\nmallet_softness: 0.6\nloop: true\n\n_. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. _. 7X1. ";
    std::string umlBowl222 = "grid: 1\nbpm: 60\nbasefreq: 222.0\ninstrument: bowl\nloop: true\n\n....80X................";
    std::string umlBowl444 = "grid: 1\nbpm: 60\nbasefreq: 444.0\ninstrument: bowl\nloop: true\n\n........80X............";

    group.sequences.push_back({"AmbientRain", new UMLSequence("AmbientRain", 3, umlRainmaker)});
    group.sequences.push_back({"AmbientBowl", new UMLSequence("AmbientBowl", 2, umlBowl)});
    group.sequences.push_back({"LagNgaHigh", new UMLSequence("LagNgaHigh", 1, umlLagngaHigh)});
    group.sequences.push_back({"LagNgaLow", new UMLSequence("LagNgaLow", 1, umlLagngaLow)});
    group.sequences.push_back({"Bowl222", new UMLSequence("Bowl222", 2, umlBowl222)});
    group.sequences.push_back({"Bowl444", new UMLSequence("Bowl444", 2, umlBowl444)});

    for (const auto& seqPair : group.sequences) {
        mixer.addTrack(seqPair.first, seqPair.second->instrumentID, seqPair.second->volume);
        orch.addSequence(seqPair.second);
        orch.playSequence(seqPair.first);
    }
    
    float buffer[1024];
    
    std::cout << "Starting offline render loop..." << std::endl;
    for (int loop = 0; loop < 50; ++loop) {
        for (long frame = 0; frame < 1008000; frame += 512) {
            orch.updateTimeline(512);
            mixer.processBlock(buffer, 512);
            for (int i = 0; i < 512 * 2; ++i) {
                if (std::isnan(buffer[i])) {
                    std::cout << "NaN detected at loop " << loop << " frame " << frame << "!" << std::endl;
                    return 1;
                }
            }
        }
        std::cout << "Completed loop " << loop << std::endl;
    }
    std::cout << "No NaN detected!" << std::endl;
    return 0;
}
