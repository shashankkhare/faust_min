/*
 * test_mixer.cpp
 * Validates mixer envelope system: setTrackEnvelope, processEnvelopes, post-weight fadeGain.
 *
 * Builds: add to src/CMakeLists.txt → add_faust_test(test_mixer "../test/test_mixer.cpp")
 * Run:     ./build-host/test_mixer [instrumentID] [seconds]
 * Default: instrument 10 (Flute), 10 seconds
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

// --- Energy capture from waveform callback ---
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

// --- Print energy table ---
static void printEnergyTable(float totalSeconds) {
    float bucketSize = 0.2f;  // 200ms buckets
    int numBuckets = (int)(totalSeconds / bucketSize) + 1;

    std::cout << "\n";
    std::cout << "=====================================================================\n";
    std::cout << "  ENVELOPE ENERGY PROGRESSION (200ms buckets)\n";
    std::cout << "  time(s)     RMS         peak        bar\n";
    std::cout << "=====================================================================\n";

    for (int b = 0; b < numBuckets; b++) {
        float bucketStart = b * bucketSize;
        float bucketEnd = bucketStart + bucketSize;
        float sumRms = 0, maxPeak = 0;
        int count = 0;

        for (auto& s : gEnergyLog) {
            if (s.time >= bucketStart && s.time < bucketEnd) {
                sumRms += s.rms;
                if (s.peak > maxPeak) maxPeak = s.peak;
                count++;
            }
        }

        float avgRms = (count > 0) ? sumRms / count : 0.0f;
        int barLen = (int)(avgRms * 60.0f);
        if (barLen > 60) barLen = 60;

        printf("  %5.1f      %.6f    %.6f    ", bucketStart, avgRms, maxPeak);
        for (int i = 0; i < barLen; i++) printf("#");
        printf("\n");
    }
    std::cout << "=====================================================================\n";
    std::cout.flush();
}

int main(int argc, char* argv[]) {
    int instrumentID = 10;  // Flute — good sustained tone
    float totalSeconds = 10.0f;

    if (argc > 1) instrumentID = std::atoi(argv[1]);
    if (argc > 2) totalSeconds = std::atof(argv[2]);

    std::string instName = InstrumentMapper::getNameFromID(instrumentID);
    printf("[TEST] instrument=%d (%s) duration=%.1fs\n", instrumentID, instName.c_str(), totalSeconds);
    fflush(stdout);

    // --- Init mixer ---
    FaustMixer& mixer = FaustMixer::getInstance();
    mixer.init(InstrumentMapper::DEFAULT_SAMPLE_RATE);

    // --- Waveform callback for energy capture ---
    mixer.setWaveformCallback(waveformCallback, nullptr);

    if (!mixer.start()) {
        std::cerr << "[TEST] FAIL: mixer.start() returned false. Is ALSA available?" << std::endl;
        return 1;
    }
    printf("[TEST] mixer started, sr=%.0f\n", mixer.getSampleRate());
    fflush(stdout);

    usleep(200000);  // let hardware settle

    // --- Create instrument and register on track ---
    auto inst = std::make_shared<FaustInstrument>(
        instrumentID, DSPExecutionType::StaticCompiled,
        InstrumentMapper::DEFAULT_SAMPLE_RATE
    );

    int trackID = mixer.addTrack(1.0f);
    mixer.addInstrumentToTrack(trackID, inst.get());
    printf("[TEST] track %d created, instrument registered\n", trackID);
    fflush(stdout);

    // --- Flute needs pressure and vibrato to produce sound ---
    inst->setParamImmediate("pressure", 0.40f);
    inst->setParamImmediate("vibrato", 0.05f);

    // --- Set envelope: fade in 2s, hold 6s, fade out 2s ---
    //
    //   0s        2s         8s         10s
    //   |  fadein  |   hold   | fadeout  |
    //   0 --------> 1 --------> 1 ------> 0
    //
    std::vector<float> times = { 0.0f, 2.0f, 8.0f, totalSeconds };
    std::vector<float> values = { 0.0f, 1.0f, 1.0f, 0.0f };
    std::vector<uint8_t> interps = { 1, 0, 0, 0 };  // exp fade-in, linear hold, linear fade-out

    mixer.setTrackEnvelope(trackID, times.data(), values.data(), interps.data(), (int)times.size());

    printf("[TEST] envelope set: %d points\n", (int)times.size());
    for (int i = 0; i < (int)times.size(); i++) {
        printf("  pt[%d] t=%.1f v=%.1f interp=%d\n", i, times[i], values[i], interps[i]);
    }
    fflush(stdout);

    // --- Trigger note ---
    inst->noteOn(440.0f, 0.8f, 0.5f);
    printf("[TEST] noteOn(440, 0.8, 0.5) fired\n");
    fflush(stdout);

    // --- Wait and track time ---
    float elapsed = 0.0f;
    float pollInterval = 0.05f;  // 50ms poll
    while (elapsed < totalSeconds + 0.5f) {
        usleep((useconds_t)(pollInterval * 1000000));
        elapsed += pollInterval;
        gCurrentTime.store(elapsed, std::memory_order_relaxed);
    }

    // --- Release and wait for tail ---
    inst->noteOff();
    usleep(500000);

    mixer.stop();

    // --- Print results ---
    printEnergyTable(totalSeconds);

    printf("\n[TEST] total energy samples captured: %zu\n", gEnergyLog.size());
    printf("[TEST] done.\n");
    return 0;
}
