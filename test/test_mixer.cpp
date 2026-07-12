/*
 * test_mixer.cpp
 * Envelope interpolation type comparison test.
 * Runs all 3 types (linear, exponential, S-curve) back-to-back and outputs
 * a side-by-side matrix for visual comparison.
 *
 * Build:  cd build-host && cmake ../src && make test_mixer
 * Run:    ./build-host/test_mixer [instrumentID]
 * Default: instrument 54 (harmonium)
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <unistd.h>
#include <atomic>
#include <memory>
#include "../src/FaustMixer.hpp"
#include "../src/InstrumentMapper.hpp"
#include "../src/FaustInstrument.hpp"

struct EnergySnapshot {
    float time;
    float rms;
    float peak;
};

static std::vector<EnergySnapshot> gEnergyLog;
static std::atomic<float> gCurrentTime{0.0f};

static void waveformCallback(float rms, float peak, void* userData) {
    float t = gCurrentTime.load(std::memory_order_relaxed);
    gEnergyLog.push_back({t, rms, peak});
}

static std::vector<float> bucketRMS(const std::vector<EnergySnapshot>& log, float bucketSize, float totalSeconds) {
    int numBuckets = (int)(totalSeconds / bucketSize) + 1;
    std::vector<float> result(numBuckets, 0.0f);
    for (int b = 0; b < numBuckets; b++) {
        float bStart = b * bucketSize;
        float bEnd = bStart + bucketSize;
        float sum = 0;
        int count = 0;
        for (auto& s : log) {
            if (s.time >= bStart && s.time < bEnd) {
                sum += s.rms;
                count++;
            }
        }
        result[b] = (count > 0) ? sum / count : 0.0f;
    }
    return result;
}

static void printBar(float rms, int width) {
    int len = (int)(rms * (float)width);
    if (len > width) len = width;
    for (int i = 0; i < len; i++) printf("#");
}

static void runOneTest(int instrumentID, float duration, const char* label,
                       std::vector<float>& times, std::vector<float>& values,
                       std::vector<uint8_t>& interps,
                       std::vector<float>& outRMS) {
    FaustMixer& mixer = FaustMixer::getInstance();

    mixer.clearAll();
    gEnergyLog.clear();

    mixer.setWaveformCallback(waveformCallback, nullptr);

    auto inst = std::make_shared<FaustInstrument>(
        instrumentID, DSPExecutionType::StaticCompiled,
        InstrumentMapper::DEFAULT_SAMPLE_RATE
    );

    int trackID = mixer.addTrack(1.0f);
    mixer.addInstrumentToTrack(trackID, inst.get());

    mixer.setTrackEnvelope(trackID, times.data(), values.data(), interps.data(), (int)times.size());

    inst->noteOn(440.0f, 0.8f, 0.5f);

    float elapsed = 0.0f;
    float pollInterval = 0.05f;
    while (elapsed < duration + 0.5f) {
        usleep((useconds_t)(pollInterval * 1000000));
        elapsed += pollInterval;
        gCurrentTime.store(elapsed, std::memory_order_relaxed);
    }

    inst->noteOff();
    usleep(200000);

    float bucketSize = 0.5f;
    outRMS = bucketRMS(gEnergyLog, bucketSize, duration);
}

int main(int argc, char* argv[]) {
    int instrumentID = 54;
    if (argc > 1) instrumentID = std::atoi(argv[1]);

    std::string instName = InstrumentMapper::getNameFromID(instrumentID);
    printf("================================================================================\n");
    printf("  ENVELOPE INTERPOLATION TYPE COMPARISON\n");
    printf("  instrument: %d (%s)\n", instrumentID, instName.c_str());
    printf("================================================================================\n");
    printf("  Running 3 tests: LINEAR, EXPONENTIAL (t^2), S-CURVE (smoothstep)\n");
    printf("  Each: 0->1 fade-in over 6 seconds, then hold.\n");
    printf("================================================================================\n\n");
    fflush(stdout);

    FaustMixer& mixer = FaustMixer::getInstance();
    mixer.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);
    mixer.start();
    usleep(200000);

    float duration = 6.0f;
    int bucketSize = 6;  // 0.5s buckets, 12 buckets for 6s
    const char* names[] = { "LINEAR", "EXPONENTIAL (t^2)", "S-CURVE (smoothstep)" };
    uint8_t interpCodes[] = { 0, 1, 2 };
    std::vector<std::vector<float>> allRMS(3);

    for (int t = 0; t < 3; t++) {
        printf("  [%s] running...\n", names[t]);
        fflush(stdout);

        std::vector<float> times   = { 0.0f, duration };
        std::vector<float> values  = { 0.0f, 1.0f };
        std::vector<uint8_t> interps = { interpCodes[t], interpCodes[t] };

        runOneTest(instrumentID, duration, names[t], times, values, interps, allRMS[t]);

        printf("  [%s] done (%zu energy samples)\n", names[t], gEnergyLog.size());
        fflush(stdout);
    }

    mixer.stop();

    // --- Print side-by-side comparison matrix ---
    int numBuckets = (int)(allRMS[0].size());
    float dt = 0.5f;

    printf("\n");
    printf("================================================================================\n");
    printf("  INTERPOLATION COMPARISON  (0 -> 1 fade-in over %.0fs)\n", duration);
    printf("================================================================================\n");
    printf("  time(s)    LINEAR        EXPONENTIAL   S-CURVE       LINEAR   EXP      SCURVE\n");
    printf("  --------   -----------   -----------   -----------   --------------------------\n");

    for (int b = 0; b < numBuckets; b++) {
        float t = b * dt;
        float rL = allRMS[0][b];
        float rE = allRMS[1][b];
        float rS = allRMS[2][b];

        printf("  %5.1f      %9.5f    %9.5f    %9.5f    ", t, rL, rE, rS);
        printBar(rL, 10);
        printf("  ");
        printBar(rE, 10);
        printf("  ");
        printBar(rS, 10);
        printf("\n");
    }

    printf("================================================================================\n");
    printf("\n");
    printf("  EXPECTED CURVES at midpoint t/T = 0.5:\n");
    printf("    LINEAR:       0.500\n");
    printf("    EXPONENTIAL:  0.250  (t^2 — slower start, accelerates)\n");
    printf("    S-CURVE:      0.500  (smoothstep — S-shaped, slow at both ends)\n");
    printf("\n");
    printf("  The RMS values above are audio-level averages per 0.5s bucket.\n");
    printf("  LINEAR should ramp uniformly. EXP should lag behind LINEAR initially.\n");
    printf("  S-CURVE should lag at start AND end (slow-fast-slow).\n");
    printf("================================================================================\n");
    fflush(stdout);

    return 0;
}
