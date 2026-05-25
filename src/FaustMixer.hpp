/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FAUST_MIXER_HPP
#define FAUST_MIXER_HPP

#include <vector>
#include <map>
#include <mutex>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <memory>
#include "FaustInstrument.hpp"
#include "FaustMasterReverbDSP.hpp"

/**
 * @class FaustMixer
 * @brief Centralized audio engine dispatcher and mixer.
 * 
 * The FaustMixer is a singleton responsible for:
 * 1. Owning the hardware audio driver (miniaudio/Oboe).
 * 2. Managing a persistent thread pool for parallel DSP rendering.
 * 3. Orchestrating the "Centralized Mixer" model where the audio thread 
 *    triggers rendering of active nodes via a generic PreRenderCallback.
 * 4. Applying master-bus gain, sweeps, and a safety peak limiter.
 */
class __attribute__((visibility("default"))) FaustMixer {
public:
    static FaustMixer& getInstance();

    // Setup & Hardware Driver Ownership
    void init(float sampleRate);
    bool start();
    void stop();
    void close();
    float getSampleRate() const { return mSampleRate; }
    bool isHardwareStarted() const { return mIsHardwareStarted; }

    // Standalone Node Registration
    void registerInstrument(FaustInstrument* inst, float assignedWeight);
    void unregisterInstrument(FaustInstrument* inst);

    // Explicit DJ Fader Automation API (Real-time Sweeps)
    void fadeIn(FaustInstrument* inst, float durationSeconds);
    void fadeOut(FaustInstrument* inst, float durationSeconds);
    void setInstrumentWeight(FaustInstrument* inst, float dynamicWeight);
    float getInstrumentWeight(FaustInstrument* inst);

    // Global Master-Bus Automation
    void masterFadeIn(float durationSeconds);
    void masterFadeOut(float durationSeconds);
    void setMasterGain(float gain);
    float getMasterGain() const { return mMasterGain; }

    // Multi-Track Offline Signal Mixing API
    static void mixRawSignals(
        float** inputBuffers,
        float* amplitudeScales,
        int* fadeInSamples,
        int* fadeOutSamples,
        int* curveTypes,
        int* offsetSamples,
        float* pans,
        int numTracks,
        int numSamples,
        float* outputBuffer,
        float masterGain
    );

    // Generic callback triggered before every block accumulation.
    // Returns the number of frames that can safely be rendered before the next event.
    typedef int (*PreRenderCallback)(int numFrames, void* userData);
    void setPreRenderCallback(PreRenderCallback cb, void* userData);

    /**
     * @brief Static hardware callback wrapper for miniaudio/oboe.
     */
    static void hardwareCallback(void* pOutput, int frameCount, void* pUserData) {
        if (pUserData) {
            static_cast<FaustMixer*>(pUserData)->onAudioReady(static_cast<float*>(pOutput), frameCount);
        }
    }

private:
    FaustMixer();
    ~FaustMixer();
    FaustMixer(const FaustMixer&) = delete;
    FaustMixer& operator=(const FaustMixer&) = delete;

    // Real-Time Audio Interrupt Accumulator Endpoint
    void onAudioReady(float* stereoOutput, int numFrames);

    float mSampleRate;
    void* mStreamDevice;
    bool mIsStreamActive;
    long mMasterSampleTime;
    float mMasterGain;
    float mLimiterGain;

    std::vector<FaustInstrument*> mRegisteredInstruments;
    std::map<FaustInstrument*, float> mDynamicWeights;

    struct WeightSweep {
        bool isActive = false;
        float startWeight = 1.0f;
        float targetWeight = 1.0f;
        long startSample = 0;
        long durationSamples = 0;
    };
    std::map<FaustInstrument*, WeightSweep> mWeightSweeps;

    struct MasterSweep {
        bool isActive = false;
        float startGain = 1.0f;
        float targetGain = 1.0f;
        long startSample = 0;
        long durationSamples = 0;
    } mMasterSweep;

    std::mutex mRegistryMutex;
    float* mScratchBuffer;
    int mMaxFrames;

    // --- Master Reverb Bus ---
    std::unique_ptr<FaustMasterReverbDSP> mMasterReverbDSP;
    float* mReverbInL;
    float* mReverbInR;
    float* mReverbOutL;
    float* mReverbOutR;

    // --- Persistent Thread Pool ---
    int mWorkerCount = 4;
    std::vector<std::thread> mWorkerThreads;
    std::atomic<bool> mWorkerRunning{false};

    struct WorkItem {
        FaustInstrument* inst;
        int bufferSlot;
        int numFrames;
        bool valid = false;

        WorkItem() : inst(nullptr), bufferSlot(0), numFrames(0), valid(false) {}
        WorkItem(FaustInstrument* i, int slot, int frames, bool v) 
            : inst(i), bufferSlot(slot), numFrames(frames), valid(v) {}
    };
    WorkItem mWorkQueue[InstrumentMapper::MAX_INSTRUMENTS];
    std::atomic<int> mWorkHead{0};
    std::atomic<int> mWorkCount{0};
    std::atomic<int> mPendingTasks{0};
    std::atomic<uint64_t> mDispatchGeneration{0};
    uint64_t mWorkerGeneration[InstrumentMapper::MAX_INSTRUMENTS] = {};

    void startWorkers();
    void stopWorkers();
    void workerLoop(int workerID);

    // Per-instrument pre-allocated scratch buffer arrays for thread pool extraction
    float* mInstrumentBuffers[InstrumentMapper::MAX_INSTRUMENTS] = {};


    // Modular Inline Helpers for Control-Rate Block Interrupt Handling
    inline void processMasterSweep(long currentS);
    inline void processChannelSweeps(long currentS);
    inline float computeAutoRecalibrationMultiplier(const std::vector<FaustInstrument*>& activeList);
    inline void accumulateInstrumentChannels(float* stereoOutput, int numFrames, float balanceMultiplier, const std::vector<FaustInstrument*>& activeList);
    inline void applyMasterGainAndLimiter(float* stereoOutput, int numFrames);
    inline void applyMasterLimiter(float* buffer, int totalSamples);

    bool mIsHardwareStarted = false;
    PreRenderCallback mPreRenderCallback = nullptr;
    void* mPreRenderUserData = nullptr;
};

#endif // FAUST_MIXER_HPP
