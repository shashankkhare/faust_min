#include "src/FaustInstrument.hpp"
#include <iostream>
#include <fstream>
#include <vector>

class TestFaustInstrument : public FaustInstrument {
public:
    TestFaustInstrument(int id, DSPExecutionType type, float sr) : FaustInstrument(id, type, sr) {
        mRenderBuffer = new float[8192 * 2];
    }
    ~TestFaustInstrument() { delete[] mRenderBuffer; }
};

int main() {
    TestFaustInstrument inst(44, DSPExecutionType::StaticCompiled, 48000.0f);
    
    // Play Melody ONLY
    inst.noteOn(222.0f, 1.0f, 0.0f, 1.0f);
    
    std::ofstream out("sarod_dump.csv");
    std::vector<float> buffer(1024 * 2, 0.0f);
    
    for (int block = 0; block < (48000 * 2) / 1024; ++block) {
        inst.processRealtimeStream(buffer.data(), 1024);
        for (int i = 0; i < 1024 * 2; ++i) {
            out << buffer[i] << "\n";
        }
    }
    out.close();
    
    std::cout << "Dumped 2 seconds of Sarod audio to sarod_dump.csv" << std::endl;
    return 0;
}
