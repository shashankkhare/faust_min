#include <iostream>
#include <vector>
#include <string>
#include "../src/SequenceOrchestrator.hpp"
#include "../src/UMLParser.hpp"

int main() {
    std::cout << "--- SequenceOrchestrator Test ---" << std::endl;

    // 1. Initialize Orchestrator
    auto& orch = SequenceOrchestrator::getInstance();
    orch.init(44100.0f);

    // 2. Prepare Sample UML (Flute Melody)
    // 9Sa plays Sa at max velocity for 2 grids
    // ^ indicates glide to R1 over the next 2 grids
    // 5R1 arrival and sustain
    // _ stop
    std::string uml = 
        "notation: Indian\n"
        "instrument: FL\n"
        "bpm: 120\n"
        "grid: 4\n"
        "basefreq: 440.0\n"
        "\n"
        "9Sa..^..5R1.._...";

    // 3. Load Sequence
    std::cout << "Loading Sequence: 'morning_flute'..." << std::endl;
    orch.loadSequence("morning_flute", uml);

    // 4. Render to Buffer (Simulating Playback)
    // 120bpm, grid 4 -> 8 samples/beat? No.
    // 44100 / (120/60 * 4) = 44100 / 8 = 5512.5 samples per grid.
    // Total grids = 12 tokens. Total samples ~ 66,150.
    int numFrames = 70000;
    std::vector<float> buffer(numFrames, 0.0f);

    std::cout << "Rendering Sequence..." << std::endl;
    orch.play("morning_flute");
    
    // In our test, we manually call renderToBuffer or simulate the callback
    // For this standalone test, we'll use a mock compute loop
    orch.renderToBuffer("morning_flute", buffer.data(), numFrames);

    // 5. Verification
    bool soundDetected = false;
    for (int i = 0; i < numFrames; i++) {
        if (std::abs(buffer[i]) > 0.001f) {
            soundDetected = true;
            break;
        }
    }

    if (soundDetected) {
        std::cout << "SUCCESS: Audio data generated in buffer." << std::endl;
    } else {
        std::cout << "FAILURE: Buffer is silent." << std::endl;
    }

    return 0;
}
