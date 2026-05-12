#ifndef SEQUENCE_ORCHESTRATOR_HPP
#define SEQUENCE_ORCHESTRATOR_HPP

#include <cstdint>

#ifdef __ANDROID__
#include <oboe/Oboe.h>
#define OBOE_OVERRIDE override
#else
#define OBOE_OVERRIDE
#include "miniaudio.h"
namespace oboe {
    enum class DataCallbackResult { Continue };
    class AudioStream {
    public:
        virtual void close() {}
        virtual void requestStart() {}
        virtual void requestStop() {}
    };
    class AudioStreamDataCallback {
    public:
        virtual ~AudioStreamDataCallback() {}
        virtual DataCallbackResult onAudioReady(AudioStream *audioStream, void *audioData, int32_t numFrames) {
            return DataCallbackResult::Continue;
        }
    };
}
#endif

#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>
#include <memory>
#include "UMLParser.hpp"
#include "CSVModelLoader.hpp"

// Faust SDK includes
#include <faust/dsp/interpreter-dsp.h>
#include <faust/gui/MapUI.h>

struct ActiveSequence {
    UMLSequence data;
    interpreter_dsp* dsp; 
    MapUI* ui; // MapUI to control the DSP parameters
    long currentSample;
    float weight;
    bool isPlaying;
    
    // For Glide interpolation
    bool inGlide;
    long glideStartSample;
    long glideDuration;
    float glideStartFreq;
    float glideEndFreq;
    float glideStartVel;
    float glideEndVel;
    bool pendingGateOn;

    ActiveSequence() : dsp(nullptr), ui(nullptr), currentSample(0), weight(1.0f), isPlaying(false),
                       inGlide(false), glideStartSample(0), glideDuration(0), glideStartFreq(0),
                       glideEndFreq(0), glideStartVel(0), glideEndVel(0), pendingGateOn(false) {}

    ~ActiveSequence() {
        if (dsp) { delete dsp; dsp = nullptr; }
        if (ui) { delete ui; ui = nullptr; }
    }
};

class SequenceOrchestrator : public oboe::AudioStreamDataCallback {
public:
    static SequenceOrchestrator& getInstance();

    typedef void (*OnSequenceFinished)(const char* name);
    void setOnFinishedCallback(OnSequenceFinished callback);

    void init(float sampleRate);
    void setAssetBasePath(const std::string& path);
    void loadSequence(const std::string& name, const std::string& umlData);
    void play(const std::string& name);
    void stop();
    void pause();
    void resume();
    void setWeight(const std::string& name, float weight);
    void setParameter(const std::string& name, const std::string& param, float value);

    // Static PCM Rendering
    void renderToBuffer(const std::string& name, float* buffer, int numFrames);
    void renderMaster(float* buffer, int numFrames);

    // Oboe Callback
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) OBOE_OVERRIDE;

private:
    SequenceOrchestrator();
    ~SequenceOrchestrator();
    SequenceOrchestrator(const SequenceOrchestrator&) = delete;
    SequenceOrchestrator& operator=(const SequenceOrchestrator&) = delete;

    float mSampleRate;
    std::string mAssetBasePath;
    std::shared_ptr<oboe::AudioStream> mStream;
    OnSequenceFinished mOnFinishedCallback = nullptr; 
    
    std::map<std::string, std::shared_ptr<ActiveSequence>> mActiveSequences;
    std::mutex mStateMutex;
    std::atomic<bool> mIsPaused;
    
    float* mScratchBuffer = nullptr;
    int32_t mMaxFramesPerBuffer = 1024;

    float* mRenderScratchBuffer = nullptr;
    int32_t mMaxRenderFrames = 0;

    void processBuffer(std::shared_ptr<ActiveSequence> seq, float* output, int numFrames);
    void updateDSPParams(std::shared_ptr<ActiveSequence> seq, float freq, float vel, const std::string& note = "");
    interpreter_dsp* createDSP(std::shared_ptr<ActiveSequence> seq, const std::string& instrumentName);
    
    std::string getDSPPath(const std::string& instrumentName);
};

#endif // SEQUENCE_ORCHESTRATOR_HPP
