#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "FaustMixer.hpp"
#include "InstrumentMapper.hpp"
#include "UMLSequence.hpp"
#include "UMLParser.hpp"
#include "SequenceOrchestrator.hpp"

static bool gStopPlayback = false;

int main() {
    std::cout << "--- Bansuri Glide Diagnostic Runner ---" << std::endl;

    SequenceOrchestrator& orch = SequenceOrchestrator::getInstance();
    FaustMixer& mixer = FaustMixer::getInstance();
    
    mixer.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.setPreRenderCallback(SequenceOrchestrator::staticPreRender, &orch);
    mixer.start(); 

    int melodyTrack = mixer.addTrack(1.0f);

    std::string umlBansuri = 
        "grid: 4\n"
        "bpm: 120\n"
        "basefreq: 444.0\n"
        "instrument: bansuri\n"
        "notation: 22Shruti\n"
        "vibrato: 0.0\n"
        "glide: 0.05\n"
        "4Sa . . . .^ . . . 4Re . . . . . . . \n"
        "4Re . . . .^ . . . 4Sa . . . . . . . \n"
        "4Sa . . . .^ . . . 4Re . . . . . . . \n"
        "4Re . . . .^ . . . 4Sa . . . . . . . \n";

    UMLSequence* seqBansuri = new UMLSequence("Bansuri", 17, umlBansuri);
    
    if (seqBansuri) {
        orch.addSequence("Bansuri Glide Test", seqBansuri);
        
        std::cout << "[Diagnostic] Parsed NoteOn events:" << std::endl;
        for (size_t eIdx = 0; eIdx < seqBansuri->events.size(); ++eIdx) {
            const auto& ev = seqBansuri->events[eIdx];
            if (ev.type == UMLEventType::NoteOn) {
                std::cout << "  Event " << eIdx << ": NoteOn: " << ev.note 
                          << " | Freq: " << ev.frequency << " Hz" 
                          << " | Amp: " << ev.amplitude 
                          << " | SampleOffset: " << ev.sampleOffset << std::endl;
            } else if (ev.type == UMLEventType::Glide) {
                std::cout << "  Event " << eIdx << ": Glide -> Freq: " << ev.targetFrequency 
                          << " | DurSamples: " << ev.durationSamples 
                          << " | SampleOffset: " << ev.sampleOffset << std::endl;
            } else if (ev.type == UMLEventType::NoteOff) {
                std::cout << "  Event " << eIdx << ": NoteOff | SampleOffset: " << ev.sampleOffset << std::endl;
            }
        }

        auto bansuriInst = seqBansuri->getFaustInstrument();
        if (bansuriInst) {
            mixer.addInstrumentToTrack(melodyTrack, bansuriInst, 1.0f);
        }
        
        orch.enableDiagnostics(true);
        orch.play("Bansuri Glide Test");
        std::cout << "[Native] Playing Sequence. Waiting 12 seconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(12));
        orch.stop();
        orch.dumpInstrumentDiagnostics();
    }

    mixer.stop();
    std::cout << "--- Runner Complete ---" << std::endl;
    return 0;
}
