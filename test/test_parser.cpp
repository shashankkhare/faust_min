#include <iostream>
#include <vector>
#include <string>

#include "../src/UMLParser.hpp"

// We can just define a stub of FaustInstrument
class FaustInstrument {
public:
    FaustInstrument(int, int, float, float, float, float, float) {}
    void setParameter(const char*, float) {}
    void noteOn(double, float, float, float) {}
    void noteOff() {}
    void render(float*, int) {}
};

