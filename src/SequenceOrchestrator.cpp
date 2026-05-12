#include "SequenceOrchestrator.hpp"
#include <faust/dsp/dsp.h>
#include <faust/dsp/interpreter-dsp.h>
#include <faust/gui/MapUI.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <chrono>

#ifndef __ANDROID__
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

// Bridge function for miniaudio to call the orchestrator's onAudioReady
void maDataCallback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    SequenceOrchestrator* orchestrator = (SequenceOrchestrator*)pDevice->pUserData;
    orchestrator->onAudioReady(nullptr, pOutput, frameCount);
}
#endif

#define DEBUG_ORCHESTRATOR 1

SequenceOrchestrator& SequenceOrchestrator::getInstance() {
    static SequenceOrchestrator instance;
    return instance;
}

SequenceOrchestrator::SequenceOrchestrator() : mSampleRate(44100.0f), mIsPaused(false), mScratchBuffer(nullptr), mRenderScratchBuffer(nullptr), mMaxRenderFrames(0) {}

SequenceOrchestrator::~SequenceOrchestrator() {
    stop();
    {
        std::lock_guard<std::mutex> lock(mStateMutex);
        mActiveSequences.clear(); // ~ActiveSequence() handles dsp and ui cleanup automatically
    }
    if (mStream) mStream->close();
    if (mScratchBuffer) delete[] mScratchBuffer;
    if (mRenderScratchBuffer) delete[] mRenderScratchBuffer;
}

void SequenceOrchestrator::init(float sampleRate) {
    if (mScratchBuffer && mSampleRate == sampleRate) return; // Already initialized
    mSampleRate = sampleRate;
    
    if (mScratchBuffer) delete[] mScratchBuffer;
    mMaxFramesPerBuffer = 2048; 
    mScratchBuffer = new float[mMaxFramesPerBuffer];

#ifdef __ANDROID__
    if (mStream) return;
    oboe::AudioStreamBuilder builder;
    builder.setDirection(oboe::Direction::Output)
           .setPerformanceMode(oboe::PerformanceMode::LowLatency)
           .setSharingMode(oboe::SharingMode::Exclusive)
           .setFormat(oboe::AudioFormat::Float)
           .setChannelCount(oboe::ChannelCount::Mono)
           .setSampleRate((int32_t)sampleRate)
           .setDataCallback(this);
    
    builder.openStream(mStream);
    if (mStream) mStream->requestStart();
#else
    printf("[Native] SequenceOrchestrator: Initializing miniaudio for Desktop/iOS...\n");
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format = ma_format_f32;
    config.playback.channels = 1;
    config.sampleRate = (ma_uint32)sampleRate;
    config.dataCallback = maDataCallback;
    config.pUserData = this;

    static ma_device device; 
    static bool deviceInitialized = false;
    if (!deviceInitialized) {
        if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
            printf("[Native] ERROR: Failed to initialize miniaudio device.\n");
        } else {
            ma_device_start(&device);
            deviceInitialized = true;
            printf("[Native] miniaudio: Device started successfully at %f Hz.\n", sampleRate);
        }
    }
    fflush(stdout);
#endif
}

void SequenceOrchestrator::setAssetBasePath(const std::string& path) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    mAssetBasePath = path;
    printf("[Native] Asset Base Path set to: %s\n", path.c_str());
    fflush(stdout);
}

#include <unistd.h>
#include <sys/stat.h>

std::string readFileContent(const std::string& path) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("[Native] Current Working Directory: %s\n", cwd);
    }
    
    struct stat buffer;
    if (stat(path.c_str(), &buffer) == 0) {
        printf("[Native] File 'stat' SUCCESS: %s (Size: %lld)\n", path.c_str(), (long long)buffer.st_size);
    } else {
        printf("[Native] File 'stat' FAILED: %s\n", path.c_str());
    }
    fflush(stdout);

    std::ifstream file(path);
    if (!file.is_open()) {
        printf("[Native] ERROR: Failed to open file stream: %s\n", path.c_str());
        fflush(stdout);
        return "";
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

void SequenceOrchestrator::loadSequence(const std::string& name, const std::string& umlData) {
    printf("[Native] Loading Sequence: %s\n", name.c_str());
    fflush(stdout);
    
    // Parse UML and compile Faust factory bytecode OUTSIDE the audio thread lock
    auto data = UMLParser::parse(name, umlData, mSampleRate);
    printf("[Native] Parsed %lu events for %s. Instrument: %s\n", data.events.size(), name.c_str(), data.instrument.c_str());
    fflush(stdout);
    
    auto seq = std::make_shared<ActiveSequence>();
    seq->data = data;
    seq->ui = new MapUI(); 
    seq->dsp = createDSP(seq, data.instrument);
    seq->currentSample = 0;
    seq->weight = 1.0f;
    seq->inGlide = false;
    seq->pendingGateOn = false;
    
    // Lock briefly only to insert the fully constructed sequence into the active map
    std::lock_guard<std::mutex> lock(mStateMutex);
    mActiveSequences[name] = seq;
}

void SequenceOrchestrator::play(const std::string& name) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name)) {
        printf("[Native] Starting Playback: %s\n", name.c_str());
        fflush(stdout);
        mActiveSequences[name]->isPlaying = true;
        mActiveSequences[name]->currentSample = 0;
#ifdef __ANDROID__
        if (mStream) mStream->requestStart();
#endif
    } else {
        printf("[Native] ERROR: Sequence not found: %s\n", name.c_str());
        fflush(stdout);
    }
}

void SequenceOrchestrator::stop() {
    std::lock_guard<std::mutex> lock(mStateMutex);
    for (auto& [name, seq] : mActiveSequences) {
        seq->isPlaying = false;
    }
#ifdef __ANDROID__
    if (mStream) mStream->requestStop();
#endif
}

void SequenceOrchestrator::pause() { mIsPaused = true; }
void SequenceOrchestrator::resume() { mIsPaused = false; }

void SequenceOrchestrator::setWeight(const std::string& name, float weight) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name)) {
        mActiveSequences[name]->weight = weight;
    }
}

void SequenceOrchestrator::setParameter(const std::string& name, const std::string& param, float value) {
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name) && mActiveSequences[name]->ui) {
        mActiveSequences[name]->ui->setParamValue(param, value);
    }
}

void SequenceOrchestrator::setOnFinishedCallback(OnSequenceFinished callback) {
    mOnFinishedCallback = callback;
}

void SequenceOrchestrator::renderToBuffer(const std::string& name, float* buffer, int numFrames) {
    auto start = std::chrono::high_resolution_clock::now();
    std::lock_guard<std::mutex> lock(mStateMutex);
    if (mActiveSequences.count(name)) {
        std::fill(buffer, buffer + numFrames, 0.0f);
        processBuffer(mActiveSequences[name], buffer, numFrames);
        
        // --- Normalization ---
        float maxAmp = 0.0f;
        for (int i = 0; i < numFrames; i++) {
            float a = std::abs(buffer[i]);
            if (a > maxAmp) maxAmp = a;
        }
        if (maxAmp > 0.0f) {
            float scale = 0.95f / maxAmp;
            for (int i = 0; i < numFrames; i++) buffer[i] *= scale;
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        printf("[Native] renderToBuffer: '%s' (%d frames) took %lld ms. Peak: %f\n", 
               name.c_str(), numFrames, (long long)duration, maxAmp);
        fflush(stdout);
    }
}

void SequenceOrchestrator::renderMaster(float* buffer, int numFrames) {
    auto start = std::chrono::high_resolution_clock::now();
    std::lock_guard<std::mutex> lock(mStateMutex);
    std::fill(buffer, buffer + numFrames, 0.0f);
    
    if (numFrames > mMaxRenderFrames) {
        if (mRenderScratchBuffer) delete[] mRenderScratchBuffer;
        mMaxRenderFrames = numFrames;
        mRenderScratchBuffer = new float[mMaxRenderFrames];
    }

    for (auto& [name, seq] : mActiveSequences) {
        if (!seq->isPlaying) continue;
        
        std::fill(mRenderScratchBuffer, mRenderScratchBuffer + numFrames, 0.0f);
        processBuffer(seq, mRenderScratchBuffer, numFrames);
        
        for (int i = 0; i < numFrames; i++) {
            buffer[i] += mRenderScratchBuffer[i] * seq->weight;
        }
    }

    // --- Peak Normalization ---
    float maxAmp = 0.0f;
    for (int i = 0; i < numFrames; i++) {
        float absVal = std::abs(buffer[i]);
        if (absVal > maxAmp) maxAmp = absVal;
    }
    if (maxAmp > 0.0f) {
        float scale = 0.95f / maxAmp;
        for (int i = 0; i < numFrames; i++) buffer[i] *= scale;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    printf("[Native] renderMaster: (%d frames) took %lld ms. Peak: %f\n", 
           numFrames, (long long)duration, maxAmp);
    fflush(stdout);
}

oboe::DataCallbackResult SequenceOrchestrator::onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) {
    float* output = static_cast<float*>(audioData);
    std::fill(output, output + numFrames, 0.0f);

    if (mIsPaused) return oboe::DataCallbackResult::Continue;

    std::lock_guard<std::mutex> lock(mStateMutex);
    
    // Ensure scratch buffer is large enough
    if (numFrames > mMaxFramesPerBuffer) {
        if (mScratchBuffer) delete[] mScratchBuffer;
        mMaxFramesPerBuffer = numFrames;
        mScratchBuffer = new float[mMaxFramesPerBuffer];
    }

    for (auto& [name, seq] : mActiveSequences) {
        if (!seq->isPlaying) continue;

        std::fill(mScratchBuffer, mScratchBuffer + numFrames, 0.0f);
        processBuffer(seq, mScratchBuffer, numFrames);

        // Weighted Summation
        for (int i = 0; i < numFrames; ++i) {
            output[i] += mScratchBuffer[i] * seq->weight;
        }
    }

    return oboe::DataCallbackResult::Continue;
}

void SequenceOrchestrator::processBuffer(std::shared_ptr<ActiveSequence> seq, float* output, int numFrames) {
    long startS = seq->currentSample;
    int framesProcessed = 0;

    while (framesProcessed < numFrames) {
        long currentS = startS + framesProcessed;

        // 0. Handle Pending Gate-On (Smart Reset) - Done at start of chunk
        // to ensure the DSP saw the gate=0 from the previous sub-block.
        if (seq->pendingGateOn) {
            for (int p = 0; p < seq->ui->getParamsCount(); p++) {
                std::string addr = seq->ui->getParamAddress(p);
                if (addr.find("gate") != std::string::npos) {
                    seq->ui->setParamValue(addr, 1.0f);
                    break;
                }
            }
            seq->pendingGateOn = false;
        }

        // 1. Process all events scheduled at currentS
        for (auto it = seq->data.events.begin(); it != seq->data.events.end(); ) {
            if (it->sampleOffset <= currentS) {
                if (it->sampleOffset == currentS) {
                    if (it->type == UMLEventType::NoteOn) {
                        printf("[Native] NoteOn: %f Hz, Vel: %f, Bol: %s at sample %ld\n", it->frequency, it->velocity, it->note.c_str(), currentS);
                        fflush(stdout);
                        updateDSPParams(seq, it->frequency, it->velocity, it->note);
                        seq->inGlide = false;
                    } else if (it->type == UMLEventType::NoteOff) {
                        printf("[Native] NoteOff at sample %ld\n", currentS);
                        fflush(stdout);
                        updateDSPParams(seq, 0, 0, ""); 
                        seq->inGlide = false;
                    } else if (it->type == UMLEventType::Glide) {
                        seq->inGlide = true;
                        seq->glideStartSample = currentS;
                        seq->glideDuration = it->durationSamples;
                        seq->glideStartFreq = it->frequency;
                        seq->glideEndFreq = it->targetFrequency;
                        seq->glideStartVel = it->velocity;
                        seq->glideEndVel = it->targetVelocity;
                    }
                }
                it = seq->data.events.erase(it);
            } else {
                break;
            }
        }

        // 2. Determine contiguous chunk size to render in one native pass
        int framesToNextEvent = numFrames - framesProcessed;
        if (!seq->data.events.empty()) {
            long nextEventS = seq->data.events.front().sampleOffset;
            if (nextEventS > currentS) {
                framesToNextEvent = std::min(framesToNextEvent, (int)(nextEventS - currentS));
            }
        }

        int chunkSize = framesToNextEvent;
        // If gate reset is pending, render precisely 1 frame to emit the zero-gate edge
        if (seq->pendingGateOn && chunkSize > 0) {
            chunkSize = 1;
        }

        // Sub-block division during glides to keep parameter sweeps smooth
        if (seq->inGlide && chunkSize > 16) {
            chunkSize = 16;
        }

        // Glide parameter update
        if (seq->inGlide) {
            float progress = (float)(currentS - seq->glideStartSample) / seq->glideDuration;
            progress = std::min(1.0f, std::max(0.0f, progress));
            float f = seq->glideStartFreq + (seq->glideEndFreq - seq->glideStartFreq) * progress;
            float v = seq->glideStartVel + (seq->glideEndVel - seq->glideStartVel) * progress;
            updateDSPParams(seq, f, v);
            if (progress >= 1.0f) seq->inGlide = false;
        }

        // 3. Render multi-sample chunk
        if (seq->dsp && chunkSize > 0) {
            int numOuts = seq->dsp->getNumOutputs();
            if (numOuts > 0) {
                float* outputs[1] = { &output[framesProcessed] };
                seq->dsp->compute(chunkSize, nullptr, outputs);
            }
        }

        framesProcessed += chunkSize;

        // 4. End of Sequence Check
        if (startS + framesProcessed >= seq->data.totalDurationSamples) {
            seq->isPlaying = false;
            if (mOnFinishedCallback) {
                mOnFinishedCallback(seq->data.name.c_str());
            }
            break;
        }
    }

    seq->currentSample += framesProcessed;
}

void SequenceOrchestrator::updateDSPParams(std::shared_ptr<ActiveSequence> seq, float freq, float vel, const std::string& note) {
    if (!seq->ui) return;

    auto setFuzzyParam = [&](const std::string& key, float value) {
        for (int i = 0; i < seq->ui->getParamsCount(); i++) {
            std::string addr = seq->ui->getParamAddress(i);
            auto it = std::search(addr.begin(), addr.end(), key.begin(), key.end(),
                                [](char a, char b) { return std::tolower(a) == std::tolower(b); });
            if (it != addr.end()) {
                seq->ui->setParamValue(addr, value);
                return true;
            }
        }
        return false;
    };

    std::string inst = seq->data.instrument;

    // --- Percussion Bol Mapping ---
    if (!note.empty()) {
        if (inst == "DA" || inst == "0") {
            // Dayan Bols
            float strikeVal = -1.0f; 
            if (note == "Na" || note == "Ta" || note == "na" || note == "ta") {
                strikeVal = 0.0f; // Na Snap
            } else if (note == "tk") {
                strikeVal = 0.1f; // tk Dead Click
            } else if (note == "Tu" || note == "Tun" || note == "tu" || note == "tun") {
                strikeVal = 2.0f; // Tun Open
            } else if (note == "Ti" || note == "Tin" || note == "ti" || note == "tin" || note == "Te" || note == "te") strikeVal = 1.0f;
            
            if (strikeVal >= 0.0f) {
                printf("[Native] Setting Strike for %s: %f\n", note.c_str(), strikeVal);
                setFuzzyParam("strike", strikeVal);
            } else if (vel > 0) {
                float s = 0.0f;
                if (vel > 0.66f) s = 2.0f;
                else if (vel > 0.33f) s = 1.0f;
                setFuzzyParam("strike", s);
            }
        } else if (inst == "BA" || inst == "1") {
            // Bayan Bols
            float strikeVal = 1.0f; // Default Ghe
            float meendVal = 1.0f;
            if (note == "Ghe" || note == "Ghi" || note == "ghe" || note == "ghi") {
                strikeVal = 1.0f;
                meendVal = 1.6f; // Deeper glide for Ghe
            } else if (note == "Ka" || note == "Ke" || note == "ka" || note == "ke") {
                strikeVal = 0.0f;
            }
            
            printf("[Native] Setting Bayan Strike for %s: %f (Meend: %f)\n", note.c_str(), strikeVal, meendVal);
            setFuzzyParam("strike", strikeVal);
            setFuzzyParam("meend", meendVal);
        }
    }

    if (freq > 0) {
        if (!setFuzzyParam("freq", freq)) {
            setFuzzyParam("tubeLength", freq);
        }
    }
    
    if (vel > 0) {
        // Sample-accurate gate reset: ONLY if not in a glide
        if (!seq->inGlide) {
            setFuzzyParam("gate", 0.0f);
            // The next render cycle will set it to 1.0
            seq->pendingGateOn = true; 
        }
        
        if (!setFuzzyParam("velocity", vel)) {
            if (!setFuzzyParam("gain", vel)) {
                setFuzzyParam("pressure", vel);
            }
        } else {
            setFuzzyParam("gain", 1.0f);
        }
        
        if (!seq->pendingGateOn) {
            setFuzzyParam("gate", 1.0f);
        }
    } else {
        setFuzzyParam("gate", 0.0f);
        setFuzzyParam("pressure", 0.0f);
    }
}

interpreter_dsp* SequenceOrchestrator::createDSP(std::shared_ptr<ActiveSequence> seq, const std::string& instrumentName) {
    std::string path = getDSPPath(instrumentName);
    std::string source = readFileContent(path);
    if (source.empty()) {
        printf("[Native] ERROR: Could not read DSP file: %s\n", path.c_str());
        fflush(stdout);
        return nullptr;
    }

    // Cache-busting: add a unique comment and use a unique factory name to force re-compilation
    std::string timestamp = std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
    source = "// " + timestamp + "\n" + source;
    std::string factoryName = "FaustInst_" + timestamp;

    std::string error;
    std::string libPath = mAssetBasePath.empty() ? "./assets/libraries/" : (mAssetBasePath + "/libraries/");
    const char* argv[] = { "-I", libPath.c_str() };
    interpreter_dsp_factory* factory = createInterpreterDSPFactoryFromString(factoryName.c_str(), source, 2, argv, error);
    if (!factory) {
        printf("[Native] ERROR: Faust Compilation failed for %s: %s\n", instrumentName.c_str(), error.c_str());
        fflush(stdout);
        return nullptr;
    }

    interpreter_dsp* dsp = factory->createDSPInstance();
    dsp->init(mSampleRate);
    
    // Build UI for MapUI
    if (seq->ui) {
        dsp->buildUserInterface(seq->ui);
        printf("[Native] Available Parameters for %s:\n", instrumentName.c_str());
        for (int i = 0; i < seq->ui->getParamsCount(); i++) {
            printf("  - %s\n", seq->ui->getParamAddress(i).c_str());
        }
        fflush(stdout);
    }
    
    // Clean up the factory AST memory footprint permanently after instance instantiation
    deleteInterpreterDSPFactory(factory);
    
    return dsp;
}

std::string SequenceOrchestrator::getDSPPath(const std::string& instrumentName) {
    std::string base = mAssetBasePath.empty() ? "./assets/dsp/" : (mAssetBasePath + "/dsp/");
    if (instrumentName.empty()) return base + "flute.dsp"; // Default fallback
    if (instrumentName == "FL" || instrumentName == "10") return base + "flute.dsp";
    if (instrumentName == "DA" || instrumentName == "0") return base + "dayan.dsp";
    if (instrumentName == "BA" || instrumentName == "1") return base + "bayan.dsp";
    if (instrumentName == "SI" || instrumentName == "9") return base + "sitar.dsp";
    if (instrumentName == "TA" || instrumentName == "11") return base + "tanpura.dsp";
    if (instrumentName == "PI" || instrumentName == "12") return base + "piano.dsp";
    if (instrumentName == "SX" || instrumentName == "13") return base + "sax.dsp";
    return base + instrumentName + ".dsp";
}
