#include <iostream>
#include "src/UMLParser.hpp"
int main() {
    std::string uml = "grid: 4\nbpm: 60\ninstrument: tanpura\n\n4C4|E4|G4 . . C4_ \n";
    UMLSequence seq = UMLParser::parse("Tanpura", uml, 48000, 261.63);
    for (const auto& ev : seq.events) {
        if (ev.type == UMLEventType::NoteOn) {
            std::cout << "NoteOn: " << ev.note << " Freq: " << ev.frequency << " Offset: " << ev.sampleOffset << "\n";
        } else if (ev.type == UMLEventType::NoteOff) {
            std::cout << "NoteOff TargetFreq: " << ev.frequency << " Offset: " << ev.sampleOffset << "\n";
        }
    }
    return 0;
}
