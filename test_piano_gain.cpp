#include "faust/dsp/dsp.h"
#include "faust/gui/MapUI.h"
#include "faust/gui/meta.h"
#include <iostream>
#include <cmath>
#include <algorithm>

// Include the generated class
#include "piano.h"

int main() {
    mydsp DSP;
    DSP.init(48000);
    MapUI ui;
    DSP.buildUserInterface(&ui);
    
    // Set parameters
    ui.setParamValue("freq", 440.0);
    ui.setParamValue("velocity", 0.8);
    ui.setParamValue("gain", 1.0);
    
    // Create buffers
    int nFrames = 48000;
    float* out[1];
    out[0] = new float[nFrames];
    
    // Trigger gate
    ui.setParamValue("gate", 1.0);
    
    // Process
    DSP.compute(nFrames, nullptr, out);
    
    float max_val = 0.0;
    for(int i=0; i<nFrames; i++) {
        max_val = std::max(max_val, std::abs(out[0][i]));
    }
    
    std::cout << "Max output amplitude: " << max_val << std::endl;
    return 0;
}
