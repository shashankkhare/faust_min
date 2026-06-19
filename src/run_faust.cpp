#include <iostream>
#include "FaustSarodDSP.hpp"

// Dummy UI class to capture parameters
class MapUI : public UI {
public:
    std::map<std::string, FAUSTFLOAT*> zoneMap;
    void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override {
        zoneMap[label] = zone;
        *zone = init;
    }
    // Implement other dummy methods
    void addButton(const char* label, FAUSTFLOAT* zone) override { zoneMap[label] = zone; *zone = 0.0; }
    void addCheckButton(const char* label, FAUSTFLOAT* zone) override { zoneMap[label] = zone; *zone = 0.0; }
    void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override { zoneMap[label] = zone; *zone = init; }
    void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override { zoneMap[label] = zone; *zone = init; }
    void openTabBox(const char* label) override {}
    void openHorizontalBox(const char* label) override {}
    void openVerticalBox(const char* label) override {}
    void closeBox() override {}
    void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override {}
    void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override {}
    void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) override {}
    void declare(FAUSTFLOAT* zone, const char* key, const char* val) override {}
};

int main() {
    mydsp dsp;
    dsp.init(44100);
    MapUI ui;
    dsp.buildUserInterface(&ui);

    // Turn on the gate and trigger
    if (ui.zoneMap.count("gate")) *ui.zoneMap["gate"] = 1.0;
    if (ui.zoneMap.count("velocity")) *ui.zoneMap["velocity"] = 0.8;
    if (ui.zoneMap.count("gain")) *ui.zoneMap["gain"] = 1.0;
    if (ui.zoneMap.count("strike")) *ui.zoneMap["strike"] = 1.0; // Play chikari!

    float out[100];
    float* outputs[1] = { out };

    dsp.compute(100, nullptr, outputs);

    for (int i = 0; i < 100; i++) {
        std::cout << out[i] << std::endl;
        if (std::isnan(out[i])) {
            std::cout << "NaN DETECTED at sample " << i << std::endl;
            return 1;
        }
    }
    return 0;
}
