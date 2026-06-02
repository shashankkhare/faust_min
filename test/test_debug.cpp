/*
 * Copyright (c) 2026 Shashank Khare
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
