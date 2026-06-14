#include "src/FaustInstrument.hpp"
#include <iostream>
class TestFaustInstrument : public FaustInstrument {
public:
    TestFaustInstrument(int id, DSPExecutionType type, float sr) : FaustInstrument(id, type, sr) {}
    void printParams() {
        std::cout << "Voice count: " << mVoiceUIs.size() << std::endl;
        if (!mVoiceUIs.empty()) {
            std::cout << "Params count: " << mVoiceUIs[0]->getParamsCount() << std::endl;
            for (int i = 0; i < mVoiceUIs[0]->getParamsCount(); i++) {
                std::cout << "Param " << i << ": " << mVoiceUIs[0]->getParamAddress(i) << std::endl;
            }
        }
    }
};
int main() {
    TestFaustInstrument inst(44, DSPExecutionType::StaticCompiled, 48000.0f);
    inst.printParams();
    return 0;
}
