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

#ifndef SEQUENCE_ORCHESTRATOR_HPP
#define SEQUENCE_ORCHESTRATOR_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>
#include <memory>
#include <functional>
#include <cstring>
#include "UMLParser.hpp"
#include "CSVModelLoader.hpp"
#include "InstrumentMapper.hpp"

// Faust SDK includes
#ifndef FAUST_DISABLE_INTERPRETER
#include <faust/dsp/interpreter-dsp.h>
#endif
#include <faust/gui/MapUI.h>

enum class SequenceState { PLAYING, STOPPED, PAUSED };

struct ActiveSequence {
    UMLSequence* sequenceObj;
    long currentSample;           // written only by driving worker thread — no race
    size_t nextEventIndex;        // written only by driving worker thread — no race
    std::atomic<bool> isPlaying{false};
    std::atomic<bool> isMuted{false};
    SequenceState state = SequenceState::PLAYING;
    size_t playbackSampleIndex = 0;

    // Phoneme interpolation state
    std::string currentPhoneme = "aa";
    std::string targetPhoneme = "NONE";
    long phonemeGlideSamples = 0;
    long phonemeGlideSamplesElapsed = 0;
    std::map<std::string, float> startParams; // Parameters at the start of the glide
    VoiceTransition currentTransition;
    bool inPhonemeGlide = false;

    ActiveSequence() : sequenceObj(nullptr), currentSample(0), nextEventIndex(0) {}
    ~ActiveSequence() {}
    // Non-copyable — atomics cannot be copied
    ActiveSequence(const ActiveSequence&) = delete;
    ActiveSequence& operator=(const ActiveSequence&) = delete;
};

/**
 * @class SequenceOrchestrator
 * @brief High-level manager for UML-based musical sequences and their active playback state.
 * 
 * The SequenceOrchestrator is responsible for:
 * 1. Loading and parsing UML sequence definitions.
 * 2. Managing the lifecycle of "Active Sequences" (play, pause, stop).
 * 3. Providing a thread-safe snapshot of active sequences to the FaustMixer for rendering.
 * 4. Handling track-level metadata like volume weights and parameter overrides.
 * 
 * DESIGN NOTE: This class does NOT perform audio rendering. It delegates all signal 
 * generation and block processing to the FaustMixer.
 */
class SequenceOrchestrator {
public:
    /**
     * @brief Singleton Accessor
     */
    static SequenceOrchestrator& getInstance() {
        static SequenceOrchestrator instance;
        return instance;
    }

private:
    SequenceOrchestrator();
    ~SequenceOrchestrator();
public:

    void setAssetBasePath(const std::string& path);

    /**
     * @brief Load all .usq files from a directory and parse their sequences.
     */
    int loadSong(const std::string& songDirectory);

    /**
     * @brief Unload all sequences associated with a specific song directory.
     */
    void unloadSong(const std::string& songDirectory);

    /**
     * @brief Start playback of all sequences associated with a specific song directory.
     */
    void playSong(const std::string& songDirectory);

    /**
     * @brief Stop playback of all sequences associated with a specific song directory.
     */
    void stopSong(const std::string& songDirectory);

    /**
     * @brief Register a new sequence definition into the orchestrator.
     * @param name Unique identifier for the sequence track.
     * @param sequence Parsed UML sequence object.
     */
    int addSequence(const std::string& name, UMLSequence* sequence);
    void linkExtensions();

    /**
     * @brief Trigger playback for a registered sequence.
     */
    void play(const std::string& name);

    /**
     * @brief Dump memory-based diagnostic logs from all active instruments.
     */
    void dumpInstrumentDiagnostics();

    void enableDiagnostics(bool enable);

    /**
     * @brief Remove all sequences from the active orchestrator pool.
     */
    void clearSequences();

    /**
     * @brief Stop all active playback immediately.
     */
    void stop();

    /**
     * @brief Pause the global playback timeline.
     */
    void pause();

    /**
     * @brief Resume global playback.
     */
    void resume();

    /**
     * @brief Toggle the global Humanize property (adds random micro-timing jitter).
     */
    void setHumanize(bool state) { mHumanize.store(state, std::memory_order_relaxed); }
    bool isHumanized() const { return mHumanize.load(std::memory_order_relaxed); }

    /**
     * @brief Mute or unmute a specific track.
     */
    void muteTrack(const std::string& name, bool mute = true);

    /**
     * @brief Manually override a DSP parameter for a specific track.
     */
    void setParameter(const std::string& name, const std::string& param, float value);








    /**
     * @brief Poll for finished sequence notifications (for Dart FFI).
     * @return The name of the sequence that just finished, or nullptr.
     */
    const char* pollFinished() {
        if (mPendingFinish.exchange(false, std::memory_order_acq_rel)) return mFinishedName;
        return nullptr;
    }

    /**
     * @brief Signal from the mixer that a sequence has completed its timeline.
     */
    void notifyFinished(const std::string& name) {
        std::strncpy(mFinishedName, name.c_str(), 127);
        mFinishedName[127] = '\0';
        mPendingFinish.store(true, std::memory_order_release);
    }

    /**
     * @brief Returns a thread-safe snapshot of active sequences for the mixer.
     */
    std::shared_ptr<std::vector<std::shared_ptr<ActiveSequence>>> getRenderSnapshot() {
        return std::atomic_load(&mRenderSnapshot);
    }

    /**
     * @brief Checks if the global timeline is paused.
     */
    bool isPaused() const { return mIsPaused.load(std::memory_order_relaxed); }

    /**
     * @brief Render a block of audio for a specific sequence. 
     */
    void processBuffer(std::shared_ptr<ActiveSequence> seq, float* output, int numFrames);

    /**
     * @brief Static bridge for the mixer's pre-render callback.
     */
    static int staticPreRender(int numFrames, void* userData) {
        if (userData) {
            auto* orch = static_cast<SequenceOrchestrator*>(userData);
            orch->updateTimeline(numFrames);
            return numFrames;
        }
        return 0;
    }

private:
    void updateTimeline(int numFrames);
    void updateDSPParams(std::shared_ptr<ActiveSequence> seqWrapper, float freq, float vel, float strikeVal, const std::string& note);
    void updateDSPParamsVoice(std::shared_ptr<ActiveSequence> seqWrapper, float freq, float vel, float vowelVal);
    SequenceOrchestrator(const SequenceOrchestrator&) = delete;
    SequenceOrchestrator& operator=(const SequenceOrchestrator&) = delete;

    std::string mAssetBasePath;

    std::map<std::string, std::shared_ptr<ActiveSequence>> mActiveSequences;
    std::vector<std::string> mPendingExtensions;
    std::map<std::string, std::vector<std::string>> mSongRegistry;
    std::vector<std::string> mPendingPlay;
    std::mutex mStateMutex;
    long mMasterSampleCount = 0;
    std::atomic<bool> mIsPaused{false};
    std::atomic<bool> mHumanize{true};

    std::atomic<bool> mDiagEnabled{false};

    using SnapshotVec = std::vector<std::shared_ptr<ActiveSequence>>;
    std::shared_ptr<SnapshotVec> mRenderSnapshot; 
    void rebuildSnapshot(); 

    std::atomic<bool> mPendingFinish{false};
    char mFinishedName[128] = {};

    std::map<std::pair<std::string, std::string>, VoiceTransition> mVoiceMatrix;
    float cubicBezier(float t, float p0, float p1, float p2, float p3);
    void processPhonemeGlide(std::shared_ptr<ActiveSequence> seqWrapper, int framesToProcess);
};

#endif // SEQUENCE_ORCHESTRATOR_HPP
