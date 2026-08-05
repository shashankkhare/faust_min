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

// Renders a short note then measures the RMS tail AFTER note-off.
// fxMode: 0=dry, 1=echo+EQ, 2=reverb only, 3=all FX.
static double measureTailRMS(int instrumentID, int fxMode) {
    FaustMixer& mixer = FaustMixer::getInstance();
    mixer.clearAll();
    gEnergyLog.clear();

    auto inst = std::make_shared<FaustInstrument>(
        instrumentID, DSPExecutionType::StaticCompiled,
        InstrumentMapper::DEFAULT_SAMPLE_RATE
    );

    int trackID = mixer.addTrack(1.0f);
    mixer.addInstrumentToTrack(trackID, inst.get());

    if (fxMode == 1 || fxMode == 3) {
        mixer.setTrackEcho(trackID, 0.8f, 0.5f, 0.15f);
        mixer.setTrackEQ(trackID, 2.0f, -2.0f);
        mixer.setTrackMid(trackID, 3.0f, 1000.0f, 1.0f);
    }
    if (fxMode == 2 || fxMode == 3) {
        mixer.setTrackReverbSend(trackID, 0.5f);
    }

    inst->noteOn(440.0f, 0.8f, 0.5f);
    usleep(800000);
    inst->noteOff();
    gEnergyLog.clear(); // count only the decay tail after note-off
    usleep(1200000);

    double sum = 0.0;
    for (auto& s : gEnergyLog) sum += s.rms;
    return sum;
}

static void runFXSmokeTest(int instrumentID) {
    printf("================================================================================\n");
    printf("  PER-TRACK FX SMOKE TEST (reverb send, echo, bass/treble EQ)\n");
    printf("  instrument: %d\n", instrumentID);
    printf("================================================================================\n\n");
    fflush(stdout);

    double dryTail = measureTailRMS(instrumentID, 0);
    double echoTail = measureTailRMS(instrumentID, 1);
    double reverbTail = measureTailRMS(instrumentID, 2);
    double allTail = measureTailRMS(instrumentID, 3);

    printf("  dry tail RMS sum      : %.4f\n", dryTail);
    printf("  echo+EQ tail RMS sum  : %.4f\n", echoTail);
    printf("  reverb tail RMS sum   : %.4f\n", reverbTail);
    printf("  all-FX tail RMS sum   : %.4f\n", allTail);
    printf("  ratios vs dry         : echo %.2fx | reverb %.2fx | all %.2fx\n",
           (dryTail > 1e-6f) ? echoTail / dryTail : 0.0,
           (dryTail > 1e-6f) ? reverbTail / dryTail : 0.0,
           (dryTail > 1e-6f) ? allTail / dryTail : 0.0);
    fflush(stdout);

    if (allTail > dryTail * 1.3f) {
        printf("  [PASS] per-track FX extend the track tail.\n\n");
    } else {
        printf("  [CHECK] all-FX tail ratio below 1.3x - inspect manually.\n\n");
    }
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

    runFXSmokeTest(instrumentID);

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
