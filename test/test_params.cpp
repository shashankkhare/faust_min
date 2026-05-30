#include "FaustBansuriDSP.hpp"
#include <faust/gui/MapUI.h>
#include <iostream>

int main() {
    FaustBansuriDSP dsp;
    MapUI ui;
    dsp.buildUserInterface(&ui);
    std::cout << "Number of parameters: " << ui.getParamsCount() << std::endl;
    for (int i = 0; i < ui.getParamsCount(); i++) {
        std::cout << "Param " << i << ": " << ui.getParamAddress(i) << std::endl;
    }
    return 0;
}
