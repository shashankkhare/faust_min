#include "../src/FaustSitar.cpp"
#include <iostream>
#include <vector>

int main() {
    FaustSitar sitar(44100.0f);
    sitar.setFrequency(146.83f); // D3
    sitar.pluck(0.8f);

    std::vector<float> buffer(1024);
    sitar.render(1024, buffer.data());

    float sum = 0.0f;
    for (float s : buffer) {
        sum += std::abs(s);
    }

    std::cout << "Sitar Test Render (1024 samples)" << std::endl;
    std::cout << "Average absolute amplitude: " << (sum / 1024.0f) << std::endl;

    if (sum > 0.0f) {
        std::cout << "SUCCESS: Non-zero audio detected." << std::endl;
    } else {
        std::cout << "FAILURE: Silence detected!" << std::endl;
    }

    return (sum > 0.0f) ? 0 : 1;
}
