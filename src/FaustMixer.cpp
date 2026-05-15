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

/**
 * @file FaustMixer.cpp
 * @brief Implementation file for FaustMixer
 * 
 * DESIGN: Acts as the 'Sink' in the Controller-Sink model. It manages a persistent thread pool to render multiple Faust instruments in parallel. It is hardware-agnostic and provides a generic callback hook for timeline synchronization.
 */

#include "FaustMixer.hpp"
#include <iostream>

#ifdef __ANDROID__
#include <oboe/Oboe.h>
class MixerOboeCallback : public oboe::AudioStreamDataCallback {
public:
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream* audioStream, void* audioData, int32_t numFrames) override {
        FaustMixer::hardwareCallback(audioData, (int)numFrames, audioStream->getUserData());
        return oboe::DataCallbackResult::Continue;
    }
};
#else
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
void mixerMaCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    FaustMixer::hardwareCallback(pOutput, (int)frameCount, pDevice->pUserData);
}
#endif

FaustMixer& FaustMixer::getInstance() {
    static FaustMixer instance;
    return instance;
}

FaustMixer::FaustMixer() 
#if defined(__ANDROID__) || defined(__linux__)
    : mSampleRate(48000.0f), 
#else
    : mSampleRate(44100.0f),
#endif
      mStreamDevice(nullptr), mIsStreamActive(false),
      mMasterSampleTime(0), mMasterGain(1.0f), mScratchBuffer(nullptr), mMaxFrames(0),
      mIsHardwareStarted(false) {}

FaustMixer::~FaustMixer() {
    stop();
    close();
    if (mScratchBuffer) delete[] mScratchBuffer;
    for (int i = 0; i < InstrumentMapper::MAX_INSTRUMENTS; i++) {
        if (mInstrumentBuffers[i]) delete[] mInstrumentBuffers[i];
        mInstrumentBuffers[i] = nullptr;
    }
}

void FaustMixer::init(float sampleRate) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mSampleRate = sampleRate;

    // Pre-allocate thread pool intermediate buffers
    for (int i = 0; i < InstrumentMapper::MAX_INSTRUMENTS; i++) {
        if (!mInstrumentBuffers[i]) {
            mInstrumentBuffers[i] = new float[InstrumentMapper::MAX_FRAMES_PER_BUFFER];
        }
    }

    if (!mWorkerRunning.load()) {
        int hwCores = static_cast<int>(std::thread::hardware_concurrency());
        mWorkerCount = std::max(4, hwCores - 2);
        startWorkers();
        printf("[Native] FaustMixer persistent thread pool fully armed: %d workers\n", mWorkerCount);
        fflush(stdout);
    }
}

bool FaustMixer::start() {
    std::unique_lock<std::mutex> lock(mRegistryMutex);
    
    // Ensure internal buffers are allocated (lazy init)
    if (!mInstrumentBuffers[0]) {
        float rate = mSampleRate;
        lock.unlock(); // Release lock to call init which takes it
        init(rate);
        lock.lock();
    }

    if (mIsHardwareStarted) return true;

#ifdef __ANDROID__
    oboe::AudioStreamBuilder builder;
    static MixerOboeCallback cb;
    builder.setDirection(oboe::Direction::Output)
           .setPerformanceMode(oboe::PerformanceMode::LowLatency)
           .setSharingMode(oboe::SharingMode::Shared)
           .setFormat(oboe::AudioFormat::Float)
           .setChannelCount(oboe::ChannelCount::Stereo)
           .setSampleRate((int32_t)mSampleRate)
           .setUserData(this)
           .setDataCallback(&cb);
    oboe::AudioStream* stream = nullptr;
    if (builder.openStream((std::shared_ptr<oboe::AudioStream>&)stream) == oboe::Result::OK) {
        stream->requestStart();
        mStreamDevice = stream;
        mIsStreamActive = true;
        mIsHardwareStarted = true;
    }
#else
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format = ma_format_f32;
    config.playback.channels = 2;
    config.sampleRate = (ma_uint32)mSampleRate;
    config.dataCallback = mixerMaCallback;
    config.pUserData = this;

    ma_device* device = new ma_device();
    ma_result res = ma_device_init(NULL, &config, device);
    if (res == MA_SUCCESS) {
        mStreamDevice = device;
        mIsStreamActive = true;
        mIsHardwareStarted = true;
        
        // Release lock before starting hardware to avoid deadlock with the first callback
        lock.unlock(); 
        
        if (ma_device_start(device) == MA_SUCCESS) {
            printf("[Native Trace] miniaudio hardware device started successfully. SR=%d\n", config.sampleRate);
        } else {
            printf("[Native Trace] ERROR: Failed to start miniaudio device.\n");
            // Hardware failed to start, but we marked it as started—cleanup would be needed here in production
        }
    } else {
        delete device;
        printf("[Native Trace] ERROR: Failed to init miniaudio (ma_result=%d). Entering Headless Mode.\n", res);
        mIsHardwareStarted = true; // Fallback to headless for testing
    }
#endif
    fflush(stdout);
    return mIsHardwareStarted;
}

void FaustMixer::stop() {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mIsHardwareStarted || !mStreamDevice) return;

#ifdef __ANDROID__
    oboe::AudioStream* stream = static_cast<oboe::AudioStream*>(mStreamDevice);
    stream->requestStop();
    stream->close();
#else
    ma_device* device = static_cast<ma_device*>(mStreamDevice);
    ma_device_stop(device);
    ma_device_uninit(device);
    delete device;
#endif
    mStreamDevice = nullptr;
    mIsStreamActive = false;
    mIsHardwareStarted = false;
}

void FaustMixer::setPreRenderCallback(PreRenderCallback callback, void* userData) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mPreRenderCallback = callback;
    mPreRenderUserData = userData;
    printf("[Native Trace] CALLBACK REGISTERED: Ptr=%p | UserData=%p\n", (void*)callback, userData);
    fflush(stdout);
}

void FaustMixer::close() {
    stopWorkers();
}

void FaustMixer::startWorkers() {
    mWorkerRunning.store(true, std::memory_order_release);
    mWorkerThreads.resize(mWorkerCount);
    for (int i = 0; i < mWorkerCount; i++) {
        mWorkerGeneration[i] = 0;
        mWorkerThreads[i] = std::thread(&FaustMixer::workerLoop, this, i);
    }
}

void FaustMixer::stopWorkers() {
    mWorkerRunning.store(false, std::memory_order_release);
    mDispatchGeneration.fetch_add(1, std::memory_order_release);
    for (auto& t : mWorkerThreads) {
        if (t.joinable()) t.join();
    }
    mWorkerThreads.clear();
}

/**
 * @brief Persistent worker thread loop.
 */
void FaustMixer::workerLoop(int workerID) {
    int idleSpins = 0;
    while (mWorkerRunning.load(std::memory_order_acquire)) {
        uint64_t gen = mDispatchGeneration.load(std::memory_order_acquire);
        if (gen == mWorkerGeneration[workerID]) {
            if (++idleSpins > 1000) {
                std::this_thread::sleep_for(std::chrono::microseconds(10));
            } else {
                std::this_thread::yield();
            }
            continue;
        }
        idleSpins = 0;
        mWorkerGeneration[workerID] = gen;

        int total = mWorkCount.load(std::memory_order_acquire);
        int idx;
        while ((idx = mWorkHead.fetch_add(1, std::memory_order_acq_rel)) < total) {
            WorkItem& item = mWorkQueue[idx];
            if (!item.valid) { mPendingTasks.fetch_sub(1, std::memory_order_release); continue; }
            
            float* buf = mInstrumentBuffers[item.bufferSlot];
            std::fill(buf, buf + item.numFrames, 0.0f);
            
            if (item.inst) {
                item.inst->processRealtimeStream(buf, item.numFrames);
            }
            mPendingTasks.fetch_sub(1, std::memory_order_release);
        }
    }
}

void FaustMixer::registerInstrument(FaustInstrument* inst, float assignedWeight) {
    if (!inst) return;
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    auto it = std::find(mRegisteredInstruments.begin(), mRegisteredInstruments.end(), inst);
    if (it == mRegisteredInstruments.end()) {
        mRegisteredInstruments.push_back(inst);
        int id = inst->getID();
        inst->setAssignedWeight(assignedWeight);
        mAssignedWeights[id] = assignedWeight;
        mDynamicWeights[id] = assignedWeight;
    }
}

void FaustMixer::unregisterInstrument(FaustInstrument* inst) {
    if (!inst) return;
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    auto it = std::find(mRegisteredInstruments.begin(), mRegisteredInstruments.end(), inst);
    if (it != mRegisteredInstruments.end()) {
        mRegisteredInstruments.erase(it);
    }
}

void FaustMixer::fadeIn(int id, float durationSeconds) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mDynamicWeights[id] = 0.0f;
    float assignedCap = mAssignedWeights.count(id) ? mAssignedWeights[id] : 1.0f;
    auto& sweep = mWeightSweeps[id];
    sweep.isActive = true;
    sweep.startWeight = 0.0f;
    sweep.targetWeight = assignedCap;
    sweep.startSample = mMasterSampleTime;
    sweep.durationSamples = static_cast<long>(durationSeconds * mSampleRate);
}

void FaustMixer::fadeOut(int id, float durationSeconds) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    float curW = mDynamicWeights.count(id) ? mDynamicWeights[id] : 0.0f;
    auto& sweep = mWeightSweeps[id];
    sweep.isActive = true;
    sweep.startWeight = curW;
    sweep.targetWeight = 0.0f;
    sweep.startSample = mMasterSampleTime;
    sweep.durationSamples = static_cast<long>(durationSeconds * mSampleRate);
}

void FaustMixer::setInstrumentWeight(int id, float dynamicWeight) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    float assignedCap = mAssignedWeights.count(id) ? mAssignedWeights[id] : 1.0f;
    mDynamicWeights[id] = std::min(dynamicWeight, assignedCap);
    mWeightSweeps[id].isActive = false;
}

float FaustMixer::getInstrumentWeight(int id) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    return mDynamicWeights.count(id) ? mDynamicWeights[id] : 0.0f;
}

void FaustMixer::masterFadeIn(float durationSeconds) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mMasterGain = 0.0f;
    mMasterSweep.isActive = true;
    mMasterSweep.startGain = 0.0f;
    mMasterSweep.targetGain = 1.0f;
    mMasterSweep.startSample = mMasterSampleTime;
    mMasterSweep.durationSamples = static_cast<long>(durationSeconds * mSampleRate);
}

void FaustMixer::masterFadeOut(float durationSeconds) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mMasterSweep.isActive = true;
    mMasterSweep.startGain = mMasterGain;
    mMasterSweep.targetGain = 0.0f;
    mMasterSweep.startSample = mMasterSampleTime;
    mMasterSweep.durationSamples = static_cast<long>(durationSeconds * mSampleRate);
}

void FaustMixer::setMasterGain(float gain) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mMasterGain = gain;
    mMasterSweep.isActive = false;
}

void FaustMixer::mixRawSignals(
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
) {
    int totalStereoSamples = numSamples * 2;
    std::fill(outputBuffer, outputBuffer + totalStereoSamples, 0.0f);
    
    float totalWeight = 0.0f;
    for (int t = 0; t < numTracks; t++) {
        totalWeight += amplitudeScales[t];
    }
    float balanceMultiplier = (totalWeight > 1.0f) ? (1.0f / totalWeight) : 1.0f;

    for (int t = 0; t < numTracks; t++) {
        float* track = inputBuffers[t];
        if (!track) continue;
        int offset = offsetSamples[t];
        
        float maxAmp = 0.0f;
        for (int i = offset; i < numSamples; i++) {
            float absVal = std::abs(track[i]);
            if (absVal > maxAmp) maxAmp = absVal;
        }
        if (maxAmp == 0.0f) continue;
        
        float effectiveWeight = (amplitudeScales[t] * balanceMultiplier) / maxAmp;
        int fIn = fadeInSamples[t];
        int fOut = fadeOutSamples[t];
        int curve = curveTypes[t];
        int fadeOutStart = (numSamples > fOut) ? (numSamples - fOut) : 0;
        float pan = pans[t];
        float leftGain = pan < 0.0f ? 1.0f : 1.0f - pan;
        float rightGain = pan > 0.0f ? 1.0f : 1.0f + pan;

        for (int i = offset; i < numSamples; i++) {
            float val = track[i] * effectiveWeight;
            float envelope = 1.0f;
            if (i < offset + fIn && fIn > 0) {
                float k = (float)(i - offset) / fIn;
                envelope = k * k;
            } else if (i >= fadeOutStart && fOut > 0) {
                float k = 1.0f - ((float)(i - fadeOutStart) / fOut);
                if (k < 0.0f) k = 0.0f;
                if (curve == 4) envelope = k * k * k * k;
                else if (curve == 2) envelope = k * k;
                else envelope = k * k * k;
            }
            float finalVal = val * envelope;
            outputBuffer[i * 2] += finalVal * leftGain;
            outputBuffer[i * 2 + 1] += finalVal * rightGain;
        }
    }

    float globalMax = 0.0f;
    for (int i = 0; i < totalStereoSamples; i++) {
        float absVal = std::abs(outputBuffer[i]);
        if (absVal > globalMax) globalMax = absVal;
    }
    float finalScale = masterGain;
    if (globalMax > 1.0f) {
        finalScale *= (1.0f / globalMax);
    }
    if (finalScale != 1.0f) {
        for (int i = 0; i < totalStereoSamples; i++) outputBuffer[i] *= finalScale;
    }
}

inline void FaustMixer::processMasterSweep(long currentS) {
    if (mMasterSweep.isActive) {
        float progress = (float)(currentS - mMasterSweep.startSample) / mMasterSweep.durationSamples;
        if (progress >= 1.0f) { progress = 1.0f; mMasterSweep.isActive = false; }
        mMasterGain = mMasterSweep.startGain + (mMasterSweep.targetGain - mMasterSweep.startGain) * progress;
    }
}

inline void FaustMixer::processChannelSweeps(long currentS) {
    for (auto& pair : mWeightSweeps) {
        int id = pair.first;
        auto& sweep = pair.second;
        if (sweep.isActive) {
            float progress = (float)(currentS - sweep.startSample) / sweep.durationSamples;
            if (progress >= 1.0f) { progress = 1.0f; sweep.isActive = false; }
            float curW = sweep.startWeight + (sweep.targetWeight - sweep.startWeight) * progress;
            float assignedCap = mAssignedWeights.count(id) ? mAssignedWeights[id] : 1.0f;
            mDynamicWeights[id] = std::min(curW, assignedCap);
        }
    }
}

inline float FaustMixer::computeAutoRecalibrationMultiplier(const std::vector<FaustInstrument*>& activeList) {
    float totalDynamicWeight = 0.0f;
    for (auto* inst : activeList) {
        int id = inst->getID();
        totalDynamicWeight += mDynamicWeights.count(id) ? mDynamicWeights[id] : 0.0f;
    }
    return (totalDynamicWeight > 0.0f) ? (1.0f / totalDynamicWeight) : 1.0f;
}

inline void FaustMixer::accumulateInstrumentChannels(float* stereoOutput, int numFrames, float balanceMultiplier, const std::vector<FaustInstrument*>& activeList) {
    if (numFrames > mMaxFrames) {
        if (mScratchBuffer) delete[] mScratchBuffer;
        mMaxFrames = numFrames;
        mScratchBuffer = new float[mMaxFrames * 2];
    }

    // Dispatch all registered instruments to the thread pool for parallel rendering
    int workCount = 0;

    for (auto* inst : activeList) {
        if (workCount >= InstrumentMapper::MAX_INSTRUMENTS) break;
        mWorkQueue[workCount] = WorkItem(inst, workCount, numFrames, true);
        workCount++;
    }

    if (workCount > 0) {
        mWorkHead.store(0, std::memory_order_release);
        mWorkCount.store(workCount, std::memory_order_release);
        mPendingTasks.store(workCount, std::memory_order_release);
        mDispatchGeneration.fetch_add(1, std::memory_order_release);

        // Current thread helps too
        int total = workCount;
        int idx;
        while ((idx = mWorkHead.fetch_add(1, std::memory_order_acq_rel)) < total) {
            WorkItem& item = mWorkQueue[idx];
            if (item.valid && item.inst) {
                float* buf = mInstrumentBuffers[item.bufferSlot];
                std::fill(buf, buf + numFrames, 0.0f);
                item.inst->processRealtimeStream(buf, numFrames);
                mPendingTasks.fetch_sub(1, std::memory_order_release);
            }
        }

        // Spin barrier
        int spins = 0;
        while (mPendingTasks.load(std::memory_order_acquire) > 0) {
            if (++spins > 1000000) { spins = 0; }
            std::this_thread::yield();
        }
    }

    // Accumulate results into stereoOutput
    float peakMix = 0.0f;
    for (int slot = 0; slot < workCount; slot++) {
        FaustInstrument* inst = activeList[slot];
        int id = inst->getID();
        float effectiveWeight = (mDynamicWeights.count(id) ? mDynamicWeights[id] : 0.0f) * balanceMultiplier;
        float* sourceBuffer = mInstrumentBuffers[slot];

        float instPeak = 0.0f;
        for (int i = 0; i < numFrames; ++i) {
            float scaledSample = sourceBuffer[i] * effectiveWeight;
            float absVal = std::abs(scaledSample);
            if (absVal > instPeak) instPeak = absVal;
            
            stereoOutput[i * 2] += scaledSample;
            stereoOutput[i * 2 + 1] += scaledSample;
            
            float mixAbs = std::abs(stereoOutput[i * 2]);
            if (mixAbs > peakMix) peakMix = mixAbs;
        }
    }
}

inline void FaustMixer::applyMasterLimiter(float* buffer, int totalSamples) {
    float maxAmp = 0.0f;
    for (int i = 0; i < totalSamples; i++) {
        float a = std::abs(buffer[i]);
        if (a > maxAmp) maxAmp = a;
    }
    if (maxAmp > 0.95f) {
        float scale = 0.95f / maxAmp;
        for (int i = 0; i < totalSamples; i++) buffer[i] *= scale;
    }
}

inline void FaustMixer::applyMasterGainAndLimiter(float* stereoOutput, int numFrames) {
    if (mMasterGain != 1.0f) {
        for (int i = 0; i < numFrames * 2; ++i) stereoOutput[i] *= mMasterGain;
    }
    
    applyMasterLimiter(stereoOutput, numFrames * 2);
}

void FaustMixer::onAudioReady(float* stereoOutput, int numFrames) {
    if (!stereoOutput || numFrames <= 0) return;

    std::memset(stereoOutput, 0, sizeof(float) * numFrames * 2);

    int framesProcessed = 0;
    while (framesProcessed < numFrames) {
        int framesRemaining = numFrames - framesProcessed;
        int framesThisSubBlock = framesRemaining;

        // 1. Query Orchestrator for event boundaries
        if (mPreRenderCallback) {
            // We use the callback to find the next event offset within the remaining frames
            // In our system, the callback now handles both event dispatching and boundary detection.
            // For now, we'll keep it simple: the orchestrator will return the safe frames to render.
            // (Architecture note: we'll refine this interface further)
        }

        // 2. Perform the actual sub-block accumulation
        float* subOutput = stereoOutput + (framesProcessed * 2);
        
        std::lock_guard<std::mutex> lock(mRegistryMutex);
        std::vector<FaustInstrument*> activeList = mRegisteredInstruments;

        long currentS = mMasterSampleTime;
        processMasterSweep(currentS);
        processChannelSweeps(currentS);

        float balanceMultiplier = computeAutoRecalibrationMultiplier(activeList);
        accumulateInstrumentChannels(subOutput, framesThisSubBlock, balanceMultiplier, activeList);

        // 3. Tick the timeline
        if (mPreRenderCallback) {
            mPreRenderCallback(framesThisSubBlock, mPreRenderUserData);
        }

        mMasterSampleTime += framesThisSubBlock;
        framesProcessed += framesThisSubBlock;
    }

    applyMasterGainAndLimiter(stereoOutput, numFrames);
}
