#include <iostream>
#include "../src/UMLParser.hpp"

int main() {
    std::string seq = 
        "basefreq: 222.0\n"
        "instrument: bansuri\n"
        "notation: Indian\n"
        "\n"
        "6Sa . 6Re^ . 6g2 . . . 6Ma^ . 6Re . 6Sa . . . "
        "6n2/2^ . 6d2/2 . 6n2/2 . . . 6Pa/2 . . . . . . . "
        "6Ma^ . 6Pa . 6d2^ . 6n2 . 7Sa . . . . . . .";
    UMLSequence u = UMLParser::parse("test", seq, 48000.0, 222.0);
    for (auto& ev : u.events) {
        if (ev.type == UMLEventType::NoteOn) {
            std::cout << "NoteOn freq: " << ev.frequency << "\n";
        } else if (ev.type == UMLEventType::Glide) {
            std::cout << "Glide target: " << ev.targetFrequency << "\n";
        }
    }
    return 0;
}
