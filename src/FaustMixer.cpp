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
#include <faust/gui/MapUI.h>
#include <iostream>
#include <chrono>

#include "FaustLog.hpp"

#define TLOG(msg) do { \
    auto __now = std::chrono::steady_clock::now(); \
    auto __us = std::chrono::duration_cast<std::chrono::microseconds>(__now.time_since_epoch()).count(); \
    FM_LOG_ALWAYS("[TIMESTAMP %ld] %s\n", __us, msg); \
} while(0)

#define DEBUG_MIXER 0

// --- Cross-platform audio worker thread priority elevation ---
// Called once at the start of each worker thread before entering the loop.
//
// Android : SCHED_FIFO real-time scheduler (same as Oboe callback thread),
//           set one notch below the hardware callback so it can still
//           preempt our workers if needed.
// iOS/macOS: QOS_CLASS_USER_INTERACTIVE — safe on App Store, no entitlements
//           required. AudioWorkgroup (iOS 16+/macOS 12+) is the future
//           upgrade path for deadline-aware co-scheduling.
// Linux   : SCHED_FIFO — same as Android path, desktop only.
// Platform-specific includes for thread priority APIs
#if defined(__APPLE__)
#include <pthread.h>  // pthread_set_qos_class_self_np
#endif
#if defined(__linux__) || defined(__ANDROID__)
#include <pthread.h>
#include <sched.h>    // SCHED_FIFO, sched_get_priority_max
#include <sys/resource.h>
#include <unistd.h>
#endif
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>  // SetThreadPriority
#endif

// --- Cross-platform audio worker thread priority elevation ---
static void elevateWorkerThreadPriority() {
#if defined(__ANDROID__)
    // Elevate Android process priority to THREAD_PRIORITY_URGENT_AUDIO (-19)
    setpriority(PRIO_PROCESS, gettid(), -19);
    FM_LOGI("[Worker] Priority set to THREAD_PRIORITY_URGENT_AUDIO (-19)");

    struct sched_param sp;
    sp.sched_priority = sched_get_priority_max(SCHED_FIFO) - 1;
    if (pthread_setschedparam(pthread_self(), SCHED_FIFO, &sp) == 0) {
        FM_LOGI("[Worker] SCHED_FIFO real-time elevation succeeded");
    }
#elif defined(__APPLE__)
    pthread_set_qos_class_self_np(QOS_CLASS_USER_INTERACTIVE, 0);
#elif defined(__linux__)
    struct sched_param sp;
    sp.sched_priority = sched_get_priority_max(SCHED_FIFO) - 1;
    pthread_setschedparam(pthread_self(), SCHED_FIFO, &sp);
#elif defined(_WIN32) || defined(_WIN64)
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
#endif
}

#if 0 // USE MINIAUDIO FOR ANDROID
#include <oboe/Oboe.h>
class MixerOboeCallback : public oboe::AudioStreamDataCallback {
public:
    void* mUserData = nullptr;
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream* audioStream, void* audioData, int32_t numFrames) override {
        FaustMixer::hardwareCallback(audioData, (int)numFrames, mUserData);
        return oboe::DataCallbackResult::Continue;
    }
};
#else
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
void mixerMaCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    static bool printed = false;
    if (!printed) {
        printf("[Native Trace] miniaudio callback frameCount: %u\n", frameCount);
        fflush(stdout);
        printed = true;
    }
    FaustMixer::hardwareCallback(pOutput, (int)frameCount, pDevice->pUserData);
}

void mixerMaStopCallback(ma_device* pDevice) {
    printf("[ERROR] miniaudio DEVICE STOPPED!\n");
    fflush(stdout);
}
#endif

FaustMixer& FaustMixer::getInstance() {
    static FaustMixer instance;
    return instance;
}

FaustMixer::FaustMixer() 
    : mSampleRate(48000.0f), 
      mStreamDevice(nullptr), mIsStreamActive(false),
      mMasterSampleTime(0), mMasterGain(0.95f), mLimiterGain(1.0f), mFXReturnWeight(1.0f), mScratchBuffer(nullptr), mMaxFrames(0),
      mReverbInL(nullptr), mReverbInR(nullptr), mReverbOutL(nullptr), mReverbOutR(nullptr),
      mIsHardwareStarted(false) {}

FaustMixer::~FaustMixer() {
    stop();
    close();
    if (mScratchBuffer) delete[] mScratchBuffer;
    if (mReverbInL) delete[] mReverbInL;
    if (mReverbInR) delete[] mReverbInR;
    if (mReverbOutL) delete[] mReverbOutL;
    if (mReverbOutR) delete[] mReverbOutR;
    for (int i = 0; i < InstrumentMapper::MAX_INSTRUMENTS; i++) {
        if (mInstrumentBuffers[i]) delete[] mInstrumentBuffers[i];
        mInstrumentBuffers[i] = nullptr;
    }
}

void FaustMixer::init(float sampleRate) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mIsHardwareStarted) return;
    mSampleRate = sampleRate;

    // Pre-allocate thread pool intermediate buffers (Interleaved Stereo)
    for (int i = 0; i < InstrumentMapper::MAX_INSTRUMENTS; i++) {
        if (!mInstrumentBuffers[i]) {
            mInstrumentBuffers[i] = new float[InstrumentMapper::MAX_FRAMES_PER_BUFFER * 2];
        }
    }

    if (!mMasterReverbDSP) {
        mMasterReverbDSP.reset(new FaustMasterReverbDSP());
        mMasterReverbDSP->init(static_cast<int>(mSampleRate));
    }

    // Tracks created before init() had no sample rate yet; arm their FX DSP now.
    for (auto& pair : mTracks) {
        auto& track = pair.second;
        if (!track.fxDSP) {
            track.fxDSP.reset(new FaustTrackFxDSP());
            track.fxDSP->init(static_cast<int>(mSampleRate));
            track.fxUI.reset(new MapUI());
            track.fxDSP->buildUserInterface(track.fxUI.get());
        }
    }

    if (!mWorkerRunning.load()) {
        int hwCores = static_cast<int>(std::thread::hardware_concurrency());
        mWorkerCount = std::max(4, hwCores - 2);
        startWorkers();
        FM_LOGI("[Mixer] persistent thread pool fully armed: %d workers", mWorkerCount);
    }

#if 0 // USE MINIAUDIO FOR ANDROID
    oboe::AudioStreamBuilder builder;
    static MixerOboeCallback cb;
    cb.mUserData = this;
    oboe::AudioStreamBuilder* b = &builder;
    b->setDirection(oboe::Direction::Output)
     ->setPerformanceMode(oboe::PerformanceMode::None)
     ->setUsage(oboe::Usage::Media)
     ->setFormat(oboe::AudioFormat::Float)
     ->setChannelCount(oboe::ChannelCount::Stereo)
     ->setChannelConversionAllowed(true)
     ->setSampleRate((int32_t)mSampleRate)
     ->setSampleRateConversionQuality(oboe::SampleRateConversionQuality::Medium)
     ->setAudioApi(oboe::AudioApi::AAudio)
     ->setBufferCapacityInFrames(8192)
     ->setDataCallback(&cb);
    oboe::AudioStream* stream = nullptr;
    if (builder.openStream(&stream) == oboe::Result::OK) {
        mStreamDevice = stream;
        mIsHardwareStarted = true;
        FM_LOGI("[Mixer] Oboe stream opened OK, SR=%d", (int)mSampleRate);
    } else {
        FM_LOGE("[Mixer] Oboe stream FAILED to open");
    }
#else
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format = ma_format_f32;
    config.playback.channels = 2;
    config.sampleRate = (ma_uint32)mSampleRate;
    config.periodSizeInFrames = 2048;
    config.periods = 4;
    config.performanceProfile = ma_performance_profile_conservative;
    config.dataCallback = mixerMaCallback;
    config.stopCallback = mixerMaStopCallback;
    config.pUserData = this;

    ma_device* device = new ma_device();
    ma_result res = ma_device_init(NULL, &config, device);
    if (res == MA_SUCCESS) {
        mStreamDevice = device;
        mIsHardwareStarted = true;
        printf("[Native Trace] miniaudio hardware device initialized successfully. SR=%d\n", config.sampleRate);
    } else {
        delete device;
        printf("[Native Trace] ERROR: Failed to init miniaudio (ma_result=%d). Entering Headless Mode.\n", res);
        mIsHardwareStarted = true; // Fallback to headless
    }
#endif
    fflush(stdout);
}

bool FaustMixer::start() {
    std::unique_lock<std::mutex> lock(mRegistryMutex);
    
    // Fallback lazy initialization if not already done
    if (!mIsHardwareStarted) {
        float rate = mSampleRate;
        lock.unlock();
        init(rate);
        lock.lock();
    }

    if (!mStreamDevice) {
        return false;
    }

    if (!mIsStreamActive) {
        mIsStreamActive = true;
        lock.unlock(); // Unlock before starting hardware to avoid deadlock with the callback thread!
#if 0 // USE MINIAUDIO FOR ANDROID
        oboe::AudioStream* stream = static_cast<oboe::AudioStream*>(mStreamDevice);
        auto result = stream->requestStart();
        FM_LOGI("[Mixer] requestStart result=%d", static_cast<int>(result));
#else
        ma_device* device = static_cast<ma_device*>(mStreamDevice);
        ma_device_start(device);
#endif
    }
    return true;
}

void FaustMixer::stop() {
    stopWorkers();

    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mIsHardwareStarted || !mStreamDevice) return;

#if 0 // USE MINIAUDIO FOR ANDROID
    oboe::AudioStream* stream = static_cast<oboe::AudioStream*>(mStreamDevice);
    if (mIsStreamActive) {
        stream->requestPause();
    }
    stream->close();
#else
    ma_device* device = static_cast<ma_device*>(mStreamDevice);
    if (mIsStreamActive) {
        ma_device_stop(device);
    }
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

void FaustMixer::setWaveformCallback(WaveformCallback callback, void* userData) {
    mWaveformCallback = callback;
    mWaveformUserData = userData;
}

void FaustMixer::close() {
    stop();
    stopWorkers();
    
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mStreamDevice) {
#if 0 // USE MINIAUDIO FOR ANDROID
        oboe::AudioStream* stream = static_cast<oboe::AudioStream*>(mStreamDevice);
        stream->close();
#else
        ma_device* device = static_cast<ma_device*>(mStreamDevice);
        ma_device_uninit(device);
        delete device;
#endif
        mStreamDevice = nullptr;
    }
    mIsHardwareStarted = false;
}

void FaustMixer::startWorkers() {
    mWorkerRunning.store(true, std::memory_order_release);
    mWorkerThreads.resize(mWorkerCount);
    for (int i = 0; i < mWorkerCount; i++) {

        mWorkerThreads[i] = std::thread(&FaustMixer::workerLoop, this, i);
    }
}

void FaustMixer::stopWorkers() {
    {
        std::lock_guard<std::mutex> lk(mWorkMutex);
        mWorkerRunning.store(false, std::memory_order_release);
        mDispatchEpoch++; // bump so workers wake and see mWorkerRunning==false
    }
    mWorkCV.notify_all();
    for (auto& t : mWorkerThreads) {
        if (t.joinable()) t.join();
    }
    mWorkerThreads.clear();
}

/**
 * @brief Persistent worker thread loop.
 * 
 * Workers sleep on mWorkCV (0% CPU idle). The main audio thread wakes them
 * by bumping mDispatchEpoch and calling mWorkCV.notify_all(). When all work
 * is done the last worker signals mMainCV to unblock the audio callback.
 */
void FaustMixer::workerLoop(int workerID) {
    // Elevate this thread to audio-class priority on all supported platforms.
    // This minimises OS scheduler preemption from other apps during audio blocks.
    elevateWorkerThreadPriority();

    uint64_t myEpoch = 0;
    static std::atomic<int> workDispatchCount{0};
    while (true) {
        // --- Sleep on condition variable until a new dispatch epoch arrives ---
        {
            std::unique_lock<std::mutex> lk(mWorkMutex);
            mWorkCV.wait(lk, [&] {
                return mDispatchEpoch != myEpoch || !mWorkerRunning.load(std::memory_order_relaxed);
            });
            if (!mWorkerRunning.load(std::memory_order_relaxed)) break;
            myEpoch = mDispatchEpoch;
        }

        // --- Steal and process work items ---
        int total = mWorkCount.load(std::memory_order_acquire);
        int idx;
        while ((idx = mWorkHead.fetch_add(1, std::memory_order_acq_rel)) < total) {
            WorkItem& item = mWorkQueue[idx];
            if (!item.valid) { mPendingTasks.fetch_sub(1, std::memory_order_release); continue; }

            float* buf = mInstrumentBuffers[item.bufferSlot];
            std::fill(buf, buf + item.numFrames * 2, 0.0f);

            if (item.inst) {
                item.inst->processRealtimeStream(buf, item.numFrames);
            }
            mPendingTasks.fetch_sub(1, std::memory_order_release);
        }

        // --- If we finished the last task, wake the main audio thread ---
        {
            std::lock_guard<std::mutex> lk(mWorkMutex);
            if (mPendingTasks.load(std::memory_order_acquire) <= 0) {
                mMainCV.notify_one();
            }
        }
    }
}

int FaustMixer::addTrack(float initialWeight) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    int id = mNextTrackID++;
    mTracks[id] = { id, initialWeight, initialWeight, {} };
    auto& track = mTracks[id];
    if (mSampleRate > 0.0f) {
        track.fxDSP.reset(new FaustTrackFxDSP());
        track.fxDSP->init(static_cast<int>(mSampleRate));
        track.fxUI.reset(new MapUI());
        track.fxDSP->buildUserInterface(track.fxUI.get());
    }
    recalculateWeights();
    FM_LOGI("[Mixer] Added Track ID: %d with Weight: %.2f", id, initialWeight);
    return id;
}

void FaustMixer::removeTrack(int trackID) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mTracks.erase(trackID);
    recalculateWeights();
    FM_LOGI("[Mixer] Removed Track ID: %d", trackID);
}

void FaustMixer::addInstrumentToTrack(int trackID, FaustInstrument* inst, float instWeight) {
    if (!inst) return;
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mTracks.count(trackID)) {
        mTracks[trackID].instruments.push_back({inst, instWeight, 1.0f});
        recalculateWeights();
        FM_LOGI("[Mixer] Added Instrument ptr: %p to Track ID: %d with Weight: %.2f", (void*)inst, trackID, instWeight);
    }
}

void FaustMixer::removeInstrumentFromTrack(int trackID, FaustInstrument* inst) {
    if (!inst) return;
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mTracks.count(trackID)) {
        auto& insts = mTracks[trackID].instruments;
        insts.erase(std::remove_if(insts.begin(), insts.end(),
            [inst](const TrackInstrument& ti) { return ti.instrument == inst; }), insts.end());
        recalculateWeights();
    }
}

void FaustMixer::clearAll() {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mTracks.clear();
    mNextTrackID = 1;
}

void FaustMixer::setTrackEnvelope(int trackID, const float* times, const float* values, const uint8_t* interpTypes, int numPoints) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mTracks.count(trackID)) return;
    auto& track = mTracks[trackID];
    track.envelopeStartSample = mMasterSampleTime;
    auto& env = track.envelope;
    env.clear();
    env.reserve(numPoints);
    for (int i = 0; i < numPoints; i++) {
        env.push_back({ times[i], values[i], interpTypes[i] });
    }
    mTracks[trackID].fadeGain = env.empty() ? 1.0f : env[0].value;
}

void FaustMixer::processEnvelopes(long currentS) {
    for (auto& pair : mTracks) {
        auto& track = pair.second;
        auto& env = track.envelope;
        if (env.empty()) { track.fadeGain = 1.0f; continue; }

        float timeSec = (float)(currentS - track.envelopeStartSample) / mSampleRate;

        if ((int)env.size() == 1) { track.fadeGain = env[0].value; continue; }

        if (timeSec <= env[0].timeSec) {
            track.fadeGain = env[0].value;
            continue;
        }

        if (timeSec >= env.back().timeSec) {
            track.fadeGain = env.back().value;
            continue;
        }

        for (int j = 0; j < (int)env.size() - 1; j++) {
            const auto& p0 = env[j];
            const auto& p1 = env[j + 1];
            if (timeSec >= p0.timeSec && timeSec < p1.timeSec) {
                float span = p1.timeSec - p0.timeSec;
                float t = (span > 0.0f) ? (timeSec - p0.timeSec) / span : 0.0f;
                float v0 = p0.value;
                float v1 = p1.value;
                switch (p0.interpType) {
                    case INTERP_EXPONENTIAL: t = t * t; break;
                    case INTERP_S_CURVE: t = t * t * (3.0f - 2.0f * t); break;
                    default: break; // LINEAR
                }
                track.fadeGain = v0 + (v1 - v0) * t;
                break;
            }
        }
    }
}

void FaustMixer::setInstrumentWeight(FaustInstrument* inst, float weight) {
    if (!inst) return;
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    for (auto& [id, track] : mTracks) {
        for (auto& ti : track.instruments) {
            if (ti.instrument == inst) {
                ti.instrumentWeight = weight;
            }
        }
    }
    recalculateWeights();
}

void FaustMixer::setTrackWeight(int trackID, float dynamicWeight) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mTracks.count(trackID)) {
        mTracks[trackID].dynamicWeight = dynamicWeight;
        recalculateWeights();
    }
}

float FaustMixer::getTrackWeight(int trackID) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    return mTracks.count(trackID) ? mTracks[trackID].dynamicWeight : 0.0f;
}

void FaustMixer::muteTrack(int trackID) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mTracks.count(trackID)) {
        mTracks[trackID].muted = true;
    }
}

void FaustMixer::unmuteTrack(int trackID) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mTracks.count(trackID)) {
        mTracks[trackID].muted = false;
    }
}

bool FaustMixer::isTrackMuted(int trackID) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    return mTracks.count(trackID) ? mTracks[trackID].muted : false;
}

void FaustMixer::setTrackReverbSend(int trackID, float send) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (mTracks.count(trackID)) {
        mTracks[trackID].reverbSend = std::max(0.0f, std::min(1.0f, send));
    }
}

void FaustMixer::setTrackEcho(int trackID, float send, float feedback, float delaySec) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mTracks.count(trackID)) return;
    auto& track = mTracks[trackID];
    if (!track.fxUI) return;
    track.fxUI->setParamValue("echo_mix", std::max(0.0f, std::min(1.0f, send)));
    track.fxUI->setParamValue("echo_feedback", std::max(0.0f, std::min(0.95f, feedback)));
    track.fxUI->setParamValue("echo_time", std::max(0.01f, std::min(1.0f, delaySec)));
}

void FaustMixer::setTrackEQ(int trackID, float bassDb, float trebleDb) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mTracks.count(trackID)) return;
    auto& track = mTracks[trackID];
    if (!track.fxUI) return;
    track.fxUI->setParamValue("bass_db", std::max(-18.0f, std::min(18.0f, bassDb)));
    track.fxUI->setParamValue("treble_db", std::max(-18.0f, std::min(18.0f, trebleDb)));
}

void FaustMixer::setTrackMid(int trackID, float midDb, float midFreq, float midQ) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mTracks.count(trackID)) return;
    auto& track = mTracks[trackID];
    if (!track.fxUI) return;
    track.fxUI->setParamValue("mid_db", std::max(-18.0f, std::min(18.0f, midDb)));
    track.fxUI->setParamValue("mid_freq", std::max(20.0f, std::min(20000.0f, midFreq)));
    track.fxUI->setParamValue("mid_q", std::max(0.1f, std::min(18.0f, midQ)));
}

void FaustMixer::setTrackBypassEQ(int trackID, bool bypass) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mTracks.count(trackID)) return;
    auto& track = mTracks[trackID];
    if (track.fxUI) track.fxUI->setParamValue("bypass_eq", bypass ? 1.0f : 0.0f);
}

void FaustMixer::setTrackBypassEcho(int trackID, bool bypass) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    if (!mTracks.count(trackID)) return;
    auto& track = mTracks[trackID];
    if (track.fxUI) track.fxUI->setParamValue("bypass_echo", bypass ? 1.0f : 0.0f);
}

void FaustMixer::setFXReturnWeight(float weight) {
    std::lock_guard<std::mutex> lock(mRegistryMutex);
    mFXReturnWeight = weight;
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
            float absValL = std::abs(track[i * 2]);
            float absValR = std::abs(track[i * 2 + 1]);
            float peak = (absValL > absValR) ? absValL : absValR;
            if (peak > maxAmp) maxAmp = peak;
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
            float valL = track[i * 2] * effectiveWeight;
            float valR = track[i * 2 + 1] * effectiveWeight;
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
            outputBuffer[i * 2] += valL * envelope * leftGain;
            outputBuffer[i * 2 + 1] += valR * envelope * rightGain;
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

    static float testPhase = 0.0f;
    for (int i = 0; i < totalStereoSamples; i += 2) {
        testPhase += 2.0f * 3.14159265f * 1000.0f / 48000.0f;
        if (testPhase > 2.0f * 3.14159265f) testPhase -= 2.0f * 3.14159265f;
        float tone = sinf(testPhase) * 0.001f;
        outputBuffer[i] += tone;
        outputBuffer[i+1] += tone;
    }
}

inline void FaustMixer::processMasterSweep(long currentS) {
    if (mMasterSweep.isActive) {
        float progress = (float)(currentS - mMasterSweep.startSample) / mMasterSweep.durationSamples;
        if (progress >= 1.0f) { progress = 1.0f; mMasterSweep.isActive = false; }
        mMasterGain = mMasterSweep.startGain + (mMasterSweep.targetGain - mMasterSweep.startGain) * progress;
    }
}

void FaustMixer::recalculateWeights() {
    float totalTrackWeight = 0.0f;
    for (auto& pair : mTracks) {
        totalTrackWeight += pair.second.dynamicWeight;
    }
    float trackMultiplier = 1.0f;
    if (mWeightMode == MixerWeightMode::DYNAMIC_WEIGHTS) {
        trackMultiplier = (totalTrackWeight > 0.0f) ? (1.0f / totalTrackWeight) : 1.0f;
    }

    for (auto& pair : mTracks) {
        float normalizedTrackWeight = pair.second.dynamicWeight * trackMultiplier;
        
        for (auto& tInst : pair.second.instruments) {
            // Ignored instrument weight entirely as requested. Raw summation hits the AGC!
            tInst.effectiveWeight = normalizedTrackWeight;
        }
    }
}

inline float FaustMixer::computeAutoRecalibrationMultiplier() {
    float totalDynamicWeight = 0.0f;
    for (auto& pair : mTracks) {
        totalDynamicWeight += pair.second.dynamicWeight;
    }
    return (totalDynamicWeight > 0.0f) ? (1.0f / totalDynamicWeight) : 1.0f;
}

inline void FaustMixer::accumulateInstrumentChannels(float* stereoOutput, int numFrames, float balanceMultiplier) {
    if (numFrames > mMaxFrames) {
        if (mScratchBuffer) delete[] mScratchBuffer;
        if (mReverbInL) delete[] mReverbInL;
        if (mReverbInR) delete[] mReverbInR;
        if (mReverbOutL) delete[] mReverbOutL;
        if (mReverbOutR) delete[] mReverbOutR;
        
        mMaxFrames = numFrames;
        mScratchBuffer = new float[mMaxFrames * 2];
        mReverbInL = new float[mMaxFrames];
        mReverbInR = new float[mMaxFrames];
        mReverbOutL = new float[mMaxFrames];
        mReverbOutR = new float[mMaxFrames];
    }

    // Dispatch all registered instruments to the thread pool for parallel rendering
    int workCount = 0;
    std::vector<FaustInstrument*> activeList;
    std::vector<int> instrumentToTrackMap;
    std::vector<float> activeWeights;
    std::vector<float> activeFadeGains;

    for (auto& pair : mTracks) {
        if (pair.second.muted) continue;
        for (auto& tInst : pair.second.instruments) {
            if (workCount >= InstrumentMapper::MAX_INSTRUMENTS) break;
            activeList.push_back(tInst.instrument);
            instrumentToTrackMap.push_back(pair.first);
            activeWeights.push_back(tInst.effectiveWeight);
            activeFadeGains.push_back(pair.second.fadeGain);
            mWorkQueue[workCount] = WorkItem(tInst.instrument, workCount, numFrames, true);
            workCount++;
        }
    }

    if (workCount > 0) {
        // --- Dispatch work to the sleeping worker threads ---
        {
            std::lock_guard<std::mutex> lk(mWorkMutex);
            mWorkHead.store(0, std::memory_order_release);
            mWorkCount.store(workCount, std::memory_order_release);
            mPendingTasks.store(workCount, std::memory_order_release);
            mDispatchEpoch++;
        }
        mWorkCV.notify_all(); // Wake all sleeping workers

        // --- Current (audio) thread also steals work items ---
        int total = workCount;
        int idx;
        while ((idx = mWorkHead.fetch_add(1, std::memory_order_acq_rel)) < total) {
            WorkItem& item = mWorkQueue[idx];
            if (!item.valid) { mPendingTasks.fetch_sub(1, std::memory_order_release); continue; }
            if (item.inst) {
                float* buf = mInstrumentBuffers[item.bufferSlot];
                std::fill(buf, buf + (numFrames * 2), 0.0f);
                item.inst->processRealtimeStream(buf, numFrames);
            }
            mPendingTasks.fetch_sub(1, std::memory_order_release);
        }

        // --- Sleep until all workers are done (0% CPU idle vs old spin-barrier) ---
        if (mPendingTasks.load(std::memory_order_acquire) > 0) {
            std::unique_lock<std::mutex> lk(mWorkMutex);
            mMainCV.wait(lk, [&] { return mPendingTasks.load(std::memory_order_acquire) <= 0; });
        }
    }

    // Clear Master Reverb Bus
    if (mMasterReverbDSP) {
        std::fill(mReverbInL, mReverbInL + numFrames, 0.0f);
        std::fill(mReverbInR, mReverbInR + numFrames, 0.0f);
    }
    bool hasReverb = false;

    // Accumulate results into stereoOutput using Per-Track AGC
    float peakMix = 0.0f;
    for (auto& pair : mTracks) {
        int trackID = pair.first;
        MixerTrack& track = pair.second;

        if (track.fxDSP) {
            if (static_cast<int>(track.fxInL.size()) < numFrames) {
                track.fxInL.resize(numFrames);
                track.fxInR.resize(numFrames);
                track.fxOutL.resize(numFrames);
                track.fxOutR.resize(numFrames);
            }
        }
        
        for (int i = 0; i < numFrames; ++i) {
            float summedL = 0.0f;
            float summedR = 0.0f;
            float revSendL = 0.0f;
            float revSendR = 0.0f;
            float normalizedTrackWeight = 1.0f; // Track weight to apply AFTER AGC
            
            // 1. Raw sum all instruments assigned to this track
            for (int slot = 0; slot < workCount; slot++) {
                if (instrumentToTrackMap[slot] == trackID) {
                    float* sourceBuffer = mInstrumentBuffers[slot];
                    
                    // If the track has a master reverb send, we will apply it POST-FX later.
                    // Otherwise, we apply the instrument's specific send PRE-FX here.
                    float revSend = (track.reverbSend > 0.0f) ? 0.0f : activeList[slot]->getReverbSend();
                    if (revSend > 0.0f) hasReverb = true;
                    
                    // Note: activeWeights[slot] stores normalizedTrackWeight
                    normalizedTrackWeight = activeWeights[slot]; 
                    
                    // Raw instruments (NO weights applied yet)
                    float rawL = sourceBuffer[i * 2];
                    float rawR = sourceBuffer[i * 2 + 1];
                    
                    summedL += rawL;
                    summedR += rawR;
                    
                    if (revSend > 0.0f) {
                        revSendL += rawL * revSend;
                        revSendR += rawR * revSend;
                    }
                }
            }
            
            // 2. Apply Per-Track AGC to limit raw sum to 1.0
            float currentPeak = std::max(std::abs(summedL), std::abs(summedR));
            if (currentPeak > track.agcEnvelope) {
                track.agcEnvelope = track.agcAttack * currentPeak + (1.0f - track.agcAttack) * track.agcEnvelope;
            } else {
                track.agcEnvelope = track.agcRelease * track.agcEnvelope + (1.0f - track.agcRelease) * currentPeak;
            }
            float agcMultiplier = 1.0f / std::max(1.0f, track.agcEnvelope);
            
            // 3. Apply the actual Track Weight AND Fade Gain to the final AGC output
            float trackFade = track.fadeGain;
            float finalMultiplier = agcMultiplier * normalizedTrackWeight * trackFade;
            
            float finalL = summedL * finalMultiplier;
            float finalR = summedR * finalMultiplier;

            // 4. Route the post-AGC track signal into the per-track insert FX DSP
            //    (echo + 3-band EQ). The DSP passes dry through when params are 0.
            if (track.fxDSP) {
                track.fxInL[i] = finalL;
                track.fxInR[i] = finalR;
            } else {
                stereoOutput[i * 2] += finalL;
                stereoOutput[i * 2 + 1] += finalR;
                
                // POST-FX REVERB SEND (Fallback if no fxDSP)
                if (track.reverbSend > 0.0f) {
                    mReverbInL[i] += finalL * track.reverbSend;
                    mReverbInR[i] += finalR * track.reverbSend;
                    hasReverb = true;
                }
            }
            
            if (hasReverb) {
                mReverbInL[i] += revSendL * finalMultiplier;
                mReverbInR[i] += revSendR * finalMultiplier;
            }
            
            float mixPeak = std::max(std::abs(stereoOutput[i * 2]), std::abs(stereoOutput[i * 2 + 1]));
            if (mixPeak > peakMix) peakMix = mixPeak;
        }

        // 5. Run the per-track insert FX DSP (echo + 3-band EQ) over the block.
        if (track.fxDSP) {
            FAUSTFLOAT* fxIns[2]  = { track.fxInL.data(), track.fxInR.data() };
            FAUSTFLOAT* fxOuts[2] = { track.fxOutL.data(), track.fxOutR.data() };
            track.fxDSP->compute(numFrames, fxIns, fxOuts);
            for (int i = 0; i < numFrames; ++i) {
                float outL = fxOuts[0][i];
                float outR = fxOuts[1][i];
                stereoOutput[i * 2] += outL;
                stereoOutput[i * 2 + 1] += outR;
                
                // POST-FX REVERB SEND
                if (track.reverbSend > 0.0f) {
                    mReverbInL[i] += outL * track.reverbSend;
                    mReverbInR[i] += outR * track.reverbSend;
                    hasReverb = true;
                }
                
                float mixPeak = std::max(std::abs(stereoOutput[i * 2]), std::abs(stereoOutput[i * 2 + 1]));
                if (mixPeak > peakMix) peakMix = mixPeak;
            }
        }
    }

    // Process and merge Master Reverb Bus
    if (mMasterReverbDSP && hasReverb) {
        FAUSTFLOAT* revIns[2] = { mReverbInL, mReverbInR };
        FAUSTFLOAT* revOuts[2] = { mReverbOutL, mReverbOutR };
        mMasterReverbDSP->compute(numFrames, revIns, revOuts);
        
        for (int i = 0; i < numFrames; ++i) {
            stereoOutput[i * 2] += mReverbOutL[i] * mFXReturnWeight;
            stereoOutput[i * 2 + 1] += mReverbOutR[i] * mFXReturnWeight;
            
            float mixAbsL = std::abs(stereoOutput[i * 2]);
            float mixAbsR = std::abs(stereoOutput[i * 2 + 1]);
            float mixPeak = std::max(mixAbsL, mixAbsR);
            if (mixPeak > peakMix) peakMix = mixPeak;
        }
    }
}

inline void FaustMixer::applyMasterLimiter(float* buffer, int totalSamples) {
    for (int i = 0; i < totalSamples; ++i) {
        // Smooth mathematical soft-clipper to prevent digital clipping
        // and eliminate low-frequency envelope modulation distortion (crackling).
        buffer[i] = std::tanh(buffer[i]);
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

    if (!mFirstCallbackFired.exchange(true)) {
        FM_LOGI("[Mixer] FIRST onAudioReady() CALLBACK FIRED - audio pipeline is live, frames=%d", numFrames);
    }

#if DEBUG_MIXER
    static int audioCbCount = 0;
    if (++audioCbCount % 1000 == 0) {
        printf("[DEBUG_MIXER] onAudioReady #%d alive\n", audioCbCount);
        fflush(stdout);
    }
#endif

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

        // Tick the timeline first so that events are applied immediately before rendering
        if (mPreRenderCallback) {
            mPreRenderCallback(framesThisSubBlock, mPreRenderUserData);
        }

        processMasterSweep(mMasterSampleTime);
        processEnvelopes(mMasterSampleTime);

        float balanceMultiplier = computeAutoRecalibrationMultiplier();
        accumulateInstrumentChannels(subOutput, framesThisSubBlock, balanceMultiplier);

        mMasterSampleTime += framesThisSubBlock;
        framesProcessed += framesThisSubBlock;
    }

    applyMasterGainAndLimiter(stereoOutput, numFrames);



    // Fire waveform callback with RMS and peak of final output
    if (mWaveformCallback) {
        float sumSq = 0.0f;
        float peakVal = 0.0f;
        for (int i = 0; i < numFrames * 2; i++) {
            float s = stereoOutput[i];
            sumSq += s * s;
            float absS = fabsf(s);
            if (absS > peakVal) peakVal = absS;
        }
        float rms = sqrtf(sumSq / (numFrames * 2));
        mWaveformCallback(rms, peakVal, mWaveformUserData);
    }
}
