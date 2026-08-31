#ifndef FAUST_MIXER_HPP
#define FAUST_MIXER_HPP

#include "MixerTrack.hpp"
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <memory>
#include "FaustMasterReverbDSP.hpp"

// Typedefs for Dart callbacks
typedef int (*PreRenderCallback)(int numFrames, void* userData);
typedef void (*WaveformCallback)(float rms, float peak, void* userData);

class FaustMixer {
public:

    enum class MixerWeightMode {
        STATIC_WEIGHTS,
        DYNAMIC_WEIGHTS
    };
    MixerWeightMode mWeightMode = MixerWeightMode::DYNAMIC_WEIGHTS;

public:
    static FaustMixer& getInstance() {
        static FaustMixer instance;
        return instance;
    }

    void init(float sampleRate);
    bool start();
    void stop();
    void close();
    
    int addTrack(float initialWeight = 1.0f);
    void removeTrack(int trackID);
    void clearAll();

    void addInstrumentToTrack(int trackID, FaustInstrument* inst, float instWeight = 1.0f);
    void removeInstrumentFromTrack(int trackID, FaustInstrument* inst);
    void setInstrumentWeight(int trackID, FaustInstrument* inst, float weight);

    // Record & Play API
    bool setTrackPlaybackFile(int trackID, const char* wavPath);
    void clearTrackPlaybackFile(int trackID);
    void recordTracks(const char* baseDir);
    void stopRecordingAllTracks();
    void playRecordedTracks(const char* baseDir);
    void resetTrackPlayback();
    void purgeAllTracks(const char* baseDir);

    void setInstrumentWeight(FaustInstrument* inst, float weight);
    void setTrackWeight(int trackID, float dynamicWeight);
    void setWeightMode(int mode);
    float getTrackWeight(int trackID);
    void muteTrack(int trackID);
    void unmuteTrack(int trackID);
    void unmuteTracks(const int* trackIDs, int count);
    bool isTrackMuted(int trackID);
    void setTrackReverbSend(int trackID, float send);
    void setTrackEcho(int trackID, float send, float feedback, float delaySec);
    void setTrackEQ(int trackID, float bassDb, float trebleDb);
    void setTrackMid(int trackID, float midDb, float midFreq, float midQ);
    void setTrackBypassEQ(int trackID, bool bypass);
    void setTrackBypassEcho(int trackID, bool bypass);
    void setFXReturnWeight(float weight);
    void masterFadeIn(float durationSeconds);
    void masterFadeOut(float durationSeconds);
    void mixRawSignals(int numTracks, const int* trackIDs, const float* trackGains, const float* const* channelInL, const float* const* channelInR, float* stereoOut, int numFrames);
    void setTrackEnvelope(int trackID, const float* times, const float* values, const uint8_t* interpTypes, int numPoints);

    void setTrackMuted(int trackID, bool muted);
    void triggerMasterSweep(float targetGain, float durationSec);
    
    void setMasterGain(float gain);
    float getMasterSampleRate() const;
    void setPreRenderCallback(PreRenderCallback cb, void* userData);
    void setWaveformCallback(WaveformCallback cb, void* userData);

private:
    FaustMixer();
    ~FaustMixer();
    FaustMixer(const FaustMixer&) = delete;
    FaustMixer& operator=(const FaustMixer&) = delete;

    void onAudioReady(float* stereoOutput, int numFrames);

    // Hardware callback
    public:
    static void hardwareCallback(void* pOutput, int frameCount, void* pUserData) {
        if (pUserData) {
            static_cast<FaustMixer*>(pUserData)->onAudioReady(static_cast<float*>(pOutput), frameCount);
        }
    }

    float mSampleRate = 0.0f;
    void* mStreamDevice = nullptr;
    bool mIsStreamActive = false;
    long mMasterSampleTime = 0;
    float mMasterGain = 1.0f;
    float mLimiterGain = 1.0f;
    float mFXReturnWeight = 1.0f;

    std::map<int, std::shared_ptr<MixerTrack>> mTracks;
    int mNextTrackID = 1;
    std::recursive_mutex mRegistryMutex;
    
    float* mScratchBuffer = nullptr;
    int mMaxFrames = 0;

    std::unique_ptr<FaustMasterReverbDSP> mMasterReverbDSP;
    float* mReverbInL = nullptr;
    float* mReverbInR = nullptr;
    float* mReverbOutL = nullptr;
    float* mReverbOutR = nullptr;

    // --- Worker Pool ---
    struct WorkItem {
        FaustInstrument* inst;
        int bufferSlot;
        int numFrames;
        bool valid = false;
        WorkItem() : inst(nullptr), bufferSlot(0), numFrames(0), valid(false) {}
        WorkItem(FaustInstrument* i, int slot, int frames, bool v) 
            : inst(i), bufferSlot(slot), numFrames(frames), valid(v) {}
    };

    int mWorkerCount = 4;
    std::vector<std::thread> mWorkerThreads;
    std::atomic<bool> mWorkerRunning{false};
    std::mutex mWorkMutex;
    std::condition_variable mWorkCV;
    std::condition_variable mMainCV;
    uint64_t mDispatchEpoch{0};
    
    // Hardcoded max size to avoid dynamic allocation during audio loop
    static constexpr int MAX_INSTRUMENTS = 128;
    WorkItem mWorkQueue[MAX_INSTRUMENTS];
    std::atomic<int> mWorkHead{0};
    std::atomic<int> mWorkCount{0};
    std::atomic<int> mPendingTasks{0};

    float* mInstrumentBuffers[MAX_INSTRUMENTS] = {};

    void startWorkers();
    void stopWorkers();
    void workerLoop(int workerID);

    // --- I/O Thread ---
    std::thread mIOThread;
    std::atomic<bool> mIORunning{false};
    void ioThreadLoop();

    // Clean modular helpers
    inline void enqueueInstrumentTrack(void* source, int numFrames, int& workCount, std::vector<int>& slotToTrackMap);
    inline void accumulateInstrumentWorkerResults(void* source, int trackID, int numFrames, int workCount, const std::vector<int>& slotToTrackMap);
    inline void accumulateFileTrack(void* source, float* renderBuf, int numFrames);
    inline void accumulateMemoryTrack(void* source, float* renderBuf, int numFrames);
    
    inline void accumulateAllChannels(float* stereoOutput, int numFrames, float balanceMultiplier);
    
    void processMasterSweep(long currentS);
    void processEnvelopes(long currentS);
    void recalculateWeights();
    float computeAutoRecalibrationMultiplier();
    void applyMasterGainAndLimiter(float* stereoOutput, int numFrames);
    void applyMasterLimiter(float* buffer, int totalSamples);

    struct MasterSweep {
        bool isActive = false;
        float startGain = 1.0f;
        float targetGain = 1.0f;
        long startSample = 0;
        long durationSamples = 0;
    } mMasterSweep;

    bool mIsHardwareStarted = false;
    PreRenderCallback mPreRenderCallback = nullptr;
    void* mPreRenderUserData = nullptr;
    WaveformCallback mWaveformCallback = nullptr;
    void* mWaveformUserData = nullptr;
    std::atomic<bool> mFirstCallbackFired{false};
};

#endif // FAUST_MIXER_HPP
