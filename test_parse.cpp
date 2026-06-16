#include <iostream>
#include "src/UMLParser.hpp"
int main() {
    std::string umlNAF = "grid: 12\nbpm: 60\nbasefreq: 222.0\ninstrument: nativeamericanflute\nparameters: vibrato=0.5, vibrato_rate=5.0, vibrato_depth=0.035\n\n5F4....5A4..~.........5G4.....5F4.~........5E4.....5G4.~........... 3F4......4E4...4E4...4E4...5E4.5F4.... 5D4.~................... \n";
    UMLSequence seq = UMLParser::parse("NAF", umlNAF, 48000, 222.0);
    for (const auto& ev : seq.events) {
        if (ev.type == UMLEventType::NoteOn) {
            std::cout << "NoteOn: " << ev.note << " Freq: " << ev.frequency << " Vel: " << ev.velocity << " Amp: " << ev.amplitude << " Offset: " << ev.sampleOffset << "\n";
        } else if (ev.type == UMLEventType::NoteOff) {
            std::cout << "NoteOff Offset: " << ev.sampleOffset << "\n";
        } else if (ev.type == UMLEventType::VibratoOn) {
            std::cout << "VibratoOn Offset: " << ev.sampleOffset << "\n";
        }
    }
    return 0;
}
