/*
 * Copyright (c) 2026 Shashank Khare (Rebuild Trigger)
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
 * @file faust_min.cpp
 * @brief Implementation file for faust_min
 * 
 * DESIGN: Universal FFI Bridge. It exposes the engine's high-level functionality to the Dart layer through a flat C-style API, enabling cross-platform mobile integration.
 */

#include "faust_min.h"
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <chrono>
#include <mutex>
#include <unordered_map>
#include <memory>

#ifdef __ANDROID__
#include <android/log.h>
#define FM_LOG_TAG "FaustMin"
#define FM_LOGI(...) __android_log_print(ANDROID_LOG_INFO,  FM_LOG_TAG, __VA_ARGS__)
#define FM_LOGW(...) __android_log_print(ANDROID_LOG_WARN,  FM_LOG_TAG, __VA_ARGS__)
#define FM_LOGE(...) __android_log_print(ANDROID_LOG_ERROR, FM_LOG_TAG, __VA_ARGS__)
#define FM_LOG_ALWAYS(...) __android_log_print(ANDROID_LOG_INFO, FM_LOG_TAG, __VA_ARGS__)
#else
#define FM_LOGI(...) printf(__VA_ARGS__); fflush(stdout)
#define FM_LOGW(...) printf(__VA_ARGS__); fflush(stdout)
#define FM_LOGE(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)
#define FM_LOG_ALWAYS(...) printf(__VA_ARGS__); fflush(stdout)
#endif

#define TLOG(msg) do { \
    auto __now = std::chrono::steady_clock::now(); \
    auto __us = std::chrono::duration_cast<std::chrono::microseconds>(__now.time_since_epoch()).count(); \
    FM_LOG_ALWAYS("[TIMESTAMP %ld] %s", __us, msg); \
} while(0)
#include "FaustFlute.hpp"
#include "FaustBowl.hpp"
#include "FaustDayan.hpp"
#include "FaustBayan.hpp"
#include "FaustSitar.hpp"
#include "FaustKick.hpp"
#include "FaustSnare.hpp"
#include "FaustMixer.hpp"
#include "SequenceOrchestrator.hpp"
#include "FaustTom.hpp"
#include "FaustHiHat.hpp"
#include "FaustRide.hpp"
#include "FaustCowbell.hpp"
#include "FaustBell.hpp"
#include "FaustTanpura.hpp"
#include "FaustPiano.hpp"
#include "FaustSax.hpp"
#include "FaustTrumpet.hpp"
#include "FaustShakuhachi.hpp"
#include "FaustBansuri.hpp"
#include "FaustViolin.hpp"
#include "FaustViolin.hpp"
#include "SequenceOrchestrator.hpp"
#include "InstrumentMapper.hpp"

static struct FaustMinInit {
    FaustMinInit() {
        printf("FaustMin: Native Library Loaded Successfully\n");
        fflush(stdout);
    }
} g_faustMinInit;

// ---------------------------------------------------------------------------
// UMLSequence ownership bridge.
//
// Dart cannot hold a std::shared_ptr, so the FFI passes raw addresses only.
// This registry stores Dart's reference to every sequence it creates; the
// object is freed when the last reference (registry + orchestrator borrows)
// is released. sequence_create() -> make_shared + store, sequence_destroy()
// -> erase. The registry itself never constructs or deletes objects.
// ---------------------------------------------------------------------------
static std::mutex gSequenceRegistryMutex;
static std::unordered_map<UMLSequence*, std::shared_ptr<UMLSequence>> gSequenceRegistry;

extern "C" {

// --- High-Level Orchestrator Endpoints (The Controller) ---

DART_EXPORT SequenceOrchestrator* orchestrator_get_instance() {
    auto& orch = SequenceOrchestrator::getInstance();
    // Connect the Brain to the Heartbeat via the FFI bridge (Decoupled).
    // setPreRenderCallback overwrites the single slot, so this is idempotent.
    FaustMixer::getInstance().setPreRenderCallback(SequenceOrchestrator::staticPreRender, &orch);
    return &orch;
}

[[deprecated("Use orchestrator_get_instance()")]]
DART_EXPORT SequenceOrchestrator* orchestrator_create() {
    return orchestrator_get_instance();
}



DART_EXPORT int orchestrator_add_sequence(SequenceOrchestrator* orch, const char* name, UMLSequence* seq) {
    if (!orch || !name || !seq) return -3;
    std::lock_guard<std::mutex> lock(gSequenceRegistryMutex);
    auto it = gSequenceRegistry.find(seq);
    if (it == gSequenceRegistry.end()) {
        printf("[Native Error] orchestrator_add_sequence: sequence %p is not tracked in the registry\n", (void*)seq);
        fflush(stdout);
        return -4;
    }
    return orch->addSequence(name, it->second);
}

DART_EXPORT void orchestrator_play(SequenceOrchestrator* orch, const char* name) {
    if (orch && name) {
        TLOG("orchestrator_play() called - queuing sequence");
        orch->play(name);
        TLOG("orchestrator_play() returned - sequence queued");
    }
}

DART_EXPORT void orchestrator_play_sequences(SequenceOrchestrator* orch, const char** names, int count) {
    if (orch && names && count > 0) {
        std::vector<std::string> vec;
        for (int i = 0; i < count; ++i) {
            if (names[i]) vec.push_back(names[i]);
        }
        orch->playSequences(vec);
    }
}

[[deprecated("Use orchestrator_clear_sequences() / orchestrator_stop()")]]
DART_EXPORT void orchestrator_destroy(SequenceOrchestrator* orchestrator) {
    if (orchestrator) {
        orchestrator->stop();
        orchestrator->clearSequences();
    }
}

DART_EXPORT void orchestrator_clear_sequence(SequenceOrchestrator* orch, const char* name) {
    if (orch && name) orch->clearSequence(name);
}

DART_EXPORT void orchestrator_clear_sequences(SequenceOrchestrator* orch) {
    if (orch) orch->clearSequences();
}

DART_EXPORT void orchestrator_stop(SequenceOrchestrator* orch) {
    if (orch) orch->stop();
}

DART_EXPORT void orchestrator_pause(SequenceOrchestrator* orch) {
    if (orch) orch->pause();
}

DART_EXPORT void orchestrator_resume(SequenceOrchestrator* orch) {
    if (orch) orch->resume();
}

DART_EXPORT void orchestrator_seek(SequenceOrchestrator* orch, long sampleOffset) {
    if (orch) orch->seek(sampleOffset);
}

DART_EXPORT void orchestrator_set_song_looping(SequenceOrchestrator* orch, int loop) {
    if (orch) orch->setSongLooping(loop != 0);
}

DART_EXPORT void orchestrator_set_weight(SequenceOrchestrator* orch, const char* name, float weight) {
    if (orch && name) orch->setWeight(std::string(name), weight);
}

DART_EXPORT void orchestrator_mute_sequence(SequenceOrchestrator* orch, const char* name, int mute) {
    if (orch && name) orch->muteSequence(name, mute != 0);
}

DART_EXPORT void orchestrator_set_parameter(SequenceOrchestrator* orch, const char* name, const char* param, float value) {
    if (orch && name && param) orch->setParameter(name, param, value);
}



DART_EXPORT void orchestrator_register_tick_callback(SequenceOrchestrator* orch, SequenceOrchestrator::TickCallback cb, void* userData) {
    if (orch) orch->setTickCallback(cb, userData);
}

DART_EXPORT const char* orchestrator_poll_finished(SequenceOrchestrator* orch) {
    return orch ? orch->pollFinished() : nullptr;
}

DART_EXPORT int orchestrator_load_song(SequenceOrchestrator* orch, const char* directory) {
    return (orch && directory) ? orch->loadSong(std::string(directory)) : -1;
}

DART_EXPORT void orchestrator_unload_song(SequenceOrchestrator* orch, const char* directory) {
    if (orch && directory) orch->unloadSong(std::string(directory));
}

DART_EXPORT void orchestrator_play_song(SequenceOrchestrator* orch, const char* directory) {
    if (orch && directory) orch->playSong(std::string(directory));
}

DART_EXPORT void orchestrator_stop_song(SequenceOrchestrator* orch, const char* directory) {
    if (orch && directory) orch->stopSong(std::string(directory));
}

// --- Shared Asset Base Path (owned by FaustEngine) ---

static std::string gAssetBasePath = "";

DART_EXPORT void faust_min_set_asset_base_path(const char* path) {
    if (path) gAssetBasePath = path;
}

DART_EXPORT const char* faust_min_get_asset_base_path() {
    return gAssetBasePath.c_str();
}

// --- FaustMixer Singleton Endpoints ---

DART_EXPORT FaustMixer* mixer_get_instance() {
    return &FaustMixer::getInstance();
}

DART_EXPORT void mixer_init(FaustMixer* mixer, float sampleRate) {
    FM_LOGI("mixer_init: mixer=%p SR=%.0f", (void*)mixer, sampleRate);
    if (mixer) mixer->init(sampleRate);
}

DART_EXPORT int mixer_start(FaustMixer* mixer) {
    if (!mixer) return -1;
    bool ok = mixer->start();
    FM_LOGI("mixer_start called, result=%d", ok ? 1 : -1);
    return ok ? 1 : -1;
}

/**
 * @brief Asynchronously starts the FaustMixer audio hardware.
 * 
 * This function spawns a background C++ thread to execute the potentially 
 * blocking initialization of the hardware audio driver (e.g., waking up a suspended 
 * PulseAudio sink). Once the hardware driver is fully started, the provided callback 
 * is fired on the background thread.
 * 
 * @param mixer A pointer to the FaustMixer singleton instance.
 * @param onComplete A function pointer (callback) executed when initialization finishes.
 */
DART_EXPORT void mixer_start_async(FaustMixer* mixer, void (*onComplete)()) {
    if (!mixer) return;
    TLOG("mixer_start_async ENTER - spawning start thread");
    std::thread([mixer, onComplete]() {
        mixer->start();
        TLOG("mixer->start() RETURNED - calling onComplete()");
        if (onComplete) {
            onComplete();
            TLOG("onComplete() DONE - device reported as ready");
        }
    }).detach();
}

// --- InstrumentMapper FFI ---
DART_EXPORT const char* instrument_mapper_get_name(int id) {
    static std::string static_name;
    static_name = InstrumentMapper::getNameFromID(id);
    return static_name.c_str();
}

DART_EXPORT int instrument_mapper_get_id(const char* name) {
    if (!name) return -1;
    return InstrumentMapper::getIDFromName(std::string(name));
}

DART_EXPORT int instrument_mapper_is_percussion(int id) {
    return InstrumentMapper::isPercussionID(id) ? 1 : 0;
}

DART_EXPORT int instrument_mapper_get_polyphony(int id) {
    return InstrumentMapper::getPolyphonyVoices(id);
}

DART_EXPORT const char* instrument_mapper_get_class(int id) {
    static std::string static_class;
    static_class = InstrumentMapper::getInstrumentClass(id);
    return static_class.c_str();
}

DART_EXPORT const char* instrument_mapper_get_origin(int id) {
    static std::string static_origin;
    static_origin = InstrumentMapper::getInstrumentOrigin(id);
    return static_origin.c_str();
}

DART_EXPORT int instrument_mapper_get_available(int* outArray, int maxElements) {
    if (!outArray || maxElements <= 0) return 0;
    // Known valid IDs up to 52, excluding duplicates/aliases.
    int valid_ids[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
    int count = sizeof(valid_ids) / sizeof(valid_ids[0]);
    int written = std::min(count, maxElements);
    for (int i = 0; i < written; ++i) {
        outArray[i] = valid_ids[i];
    }
    return written;
}

// --- Audio Mixer & DSP ---
DART_EXPORT void mixer_stop(FaustMixer* mixer) {
    if (mixer) mixer->stop();
}

DART_EXPORT void mixer_clear_all(FaustMixer* mixer) {
    if (mixer) mixer->clearAll();
}

DART_EXPORT float mixer_get_sample_rate(FaustMixer* mixer) {
    return mixer ? mixer->getMasterSampleRate() : 0.0f;
}

DART_EXPORT void mixer_set_master_gain(FaustMixer* mixer, float gain) {
    if (mixer) mixer->setMasterGain(gain);
}

DART_EXPORT void mixer_register_waveform_callback(FaustMixer* mixer, WaveformCallback cb, void* userData) {
    if (mixer) mixer->setWaveformCallback(cb, userData);
}

DART_EXPORT void mixer_set_instrument_weight(FaustMixer* mixer, FaustInstrument* inst, float weight) {
    if (mixer && inst) mixer->setInstrumentWeight(inst, weight);
}

DART_EXPORT int mixer_register_instrument(FaustMixer* mixer, FaustInstrument* inst, float weight) {
    if (!mixer || !inst) return 0;
    if (fabsf(mixer->getMasterSampleRate() - inst->getSampleRate()) > 0.5f) {
        fprintf(stderr, "[FaustMixer] ERROR: Sample rate mismatch — mixer SR=%.0f, instrument SR=%.0f. Rejecting registration.\n",
                mixer->getMasterSampleRate(), inst->getSampleRate());
        return 0;
    }
    int trackID = mixer->addTrack(weight);
    mixer->addInstrumentToTrack(trackID, inst, 1.0f);
    return trackID;
}

DART_EXPORT void mixer_unregister_instrument(FaustMixer* mixer, FaustInstrument* inst) {
    (void)mixer; (void)inst;
}

// --- FaustMixer Track & Breakpoint Envelope ---

DART_EXPORT int mixer_add_track(FaustMixer* mixer, float initialWeight) {
    FM_LOGI("mixer_add_track: mixer=%p weight=%.3f", (void*)mixer, initialWeight);
    return mixer ? mixer->addTrack(initialWeight) : 0;
}

DART_EXPORT void mixer_remove_track(FaustMixer* mixer, int trackID) {
    if (mixer) mixer->removeTrack(trackID);
}

DART_EXPORT void mixer_set_track_envelope(FaustMixer* mixer, int trackID, float* times, float* values, uint8_t* interpTypes, int numPoints) {
    FM_LOGI("mixer_set_track_envelope: mixer=%p track=%d points=%d", (void*)mixer, trackID, numPoints);
    if (mixer) mixer->setTrackEnvelope(trackID, times, values, interpTypes, numPoints);
}

DART_EXPORT void mixer_set_track_weight(FaustMixer* mixer, int trackID, float weight) {
    if (mixer) mixer->setTrackWeight(trackID, weight);
}

DART_EXPORT void mixer_set_weight_mode(FaustMixer* mixer, int mode) {
    if (mixer) mixer->setWeightMode(mode);
}

DART_EXPORT float mixer_get_track_weight(FaustMixer* mixer, int trackID) {
    return mixer ? mixer->getTrackWeight(trackID) : 0.0f;
}

DART_EXPORT void mixer_mute_track(FaustMixer* mixer, int trackID) {
    if (mixer) mixer->muteTrack(trackID);
}

DART_EXPORT void mixer_unmute_track(FaustMixer* mixer, int trackID) {
    if (mixer) mixer->unmuteTrack(trackID);
}

DART_EXPORT void mixer_set_track_reverb(FaustMixer* mixer, int trackID, float send) {
    if (mixer) mixer->setTrackReverbSend(trackID, send);
}

DART_EXPORT void mixer_set_track_echo(FaustMixer* mixer, int trackID, float send, float feedback, float delaySec) {
    if (mixer) mixer->setTrackEcho(trackID, send, feedback, delaySec);
}

DART_EXPORT void mixer_set_track_eq(FaustMixer* mixer, int trackID, float bassDb, float trebleDb) {
    if (mixer) mixer->setTrackEQ(trackID, bassDb, trebleDb);
}

DART_EXPORT void mixer_set_track_mid(FaustMixer* mixer, int trackID, float midDb, float midFreq, float midQ) {
    if (mixer) mixer->setTrackMid(trackID, midDb, midFreq, midQ);
}

DART_EXPORT void mixer_set_track_bypass_eq(FaustMixer* mixer, int trackID, float bypass) {
    if (mixer) mixer->setTrackBypassEQ(trackID, bypass > 0.5f);
}

DART_EXPORT void mixer_set_track_bypass_echo(FaustMixer* mixer, int trackID, float bypass) {
    if (mixer) mixer->setTrackBypassEcho(trackID, bypass > 0.5f);
}

DART_EXPORT void mixer_set_fx_return(FaustMixer* mixer, float weight) {
    if (mixer) mixer->setFXReturnWeight(weight);
}

DART_EXPORT void mixer_add_instrument_to_track(FaustMixer* mixer, int trackID, FaustInstrument* inst, float instWeight) {
    FM_LOGI("mixer_add_inst_to_track: mixer=%p track=%d inst=%p weight=%.3f", (void*)mixer, trackID, (void*)inst, instWeight);
    if (mixer && inst) mixer->addInstrumentToTrack(trackID, inst, instWeight);
}

DART_EXPORT void mixer_remove_instrument_from_track(FaustMixer* mixer, int trackID, FaustInstrument* inst) {
    if (mixer && inst) mixer->removeInstrumentFromTrack(trackID, inst);
}

DART_EXPORT void mixer_master_fade_in(FaustMixer* mixer, float durationSeconds) {
    if (mixer) mixer->masterFadeIn(durationSeconds);
}

DART_EXPORT void mixer_master_fade_out(FaustMixer* mixer, float durationSeconds) {
    if (mixer) mixer->masterFadeOut(durationSeconds);
}

// --- UMLSequence Flat Endpoints ---

DART_EXPORT UMLSequence* sequence_create(const char* name, int instID, const char* umlDataString) {
    if (!name || !umlDataString) return nullptr;
    auto seq = std::make_shared<UMLSequence>(name, instID, umlDataString);
    std::lock_guard<std::mutex> lock(gSequenceRegistryMutex);
    gSequenceRegistry[seq.get()] = seq;
    return seq.get();
}

DART_EXPORT void sequence_destroy(UMLSequence* seq) {
    if (!seq) return;
    std::lock_guard<std::mutex> lock(gSequenceRegistryMutex);
    gSequenceRegistry.erase(seq);
}

DART_EXPORT double sequence_get_bpm(UMLSequence* seq) {
    return seq ? seq->bpm : 120.0;
}

DART_EXPORT void sequence_set_bpm(UMLSequence* seq, double bpm) {
    if (seq) {
        seq->setBpm(bpm);
        seq->isDirty = true;
    }
}

DART_EXPORT const char* sequence_get_uml_data(UMLSequence* seq) {
    return seq ? seq->umlData.c_str() : "";
}

DART_EXPORT int sequence_get_grid(UMLSequence* seq) {
    return seq ? seq->grid : 4;
}

DART_EXPORT int sequence_get_measure(UMLSequence* seq) {
    int m = seq ? seq->measure : 0;
    return m > 0 ? m : 4;
}

DART_EXPORT double sequence_get_basefreq(UMLSequence* seq) {
    return seq ? seq->baseFreq : 261.63;
}

DART_EXPORT void sequence_set_basefreq(UMLSequence* seq, double freq) {
    if (seq) seq->setBaseFrequency(freq);
}

DART_EXPORT void sequence_prepare(UMLSequence* seq) {
    if (seq) seq->prepare();
}

DART_EXPORT int sequence_is_dirty(UMLSequence* seq) {
    return (seq && seq->isDirty) ? 1 : 0;
}

DART_EXPORT void sequence_add_note(UMLSequence* seq, float pitch, float velocity, float startBeat, float durationBeats, const char* noteName, float strikeVal) {
    if (seq) seq->addNote(pitch, velocity, startBeat, durationBeats, noteName ? noteName : ".", strikeVal);
}

DART_EXPORT void sequence_remove_note(UMLSequence* seq, float pitch, float startBeat) {
    if (seq) seq->removeNote(pitch, startBeat);
}

DART_EXPORT void sequence_clear_notes(UMLSequence* seq) {
    if (seq) seq->clearNotes();
}

DART_EXPORT int sequence_get_notes(UMLSequence* seq, float fromBeat, float toBeat, float* outBuffer, int maxNotes, char* outNames) {
    if (seq) return seq->getNotes(fromBeat, toBeat, outBuffer, maxNotes, outNames);
    return 0;
}

DART_EXPORT FaustInstrument* sequence_get_instrument(UMLSequence* seq) {
    return seq ? seq->getFaustInstrument() : nullptr;
}

// --- Individual Instrument Endpoints (For UI Auditioning/Direct Control) ---

DART_EXPORT void instrument_set_parameter(FaustInstrument* inst, const char* name, float value) {
    if (inst && name) inst->setParameter(name, value);
}

DART_EXPORT const char* instrument_get_parameters_json(FaustInstrument* inst) {
    if (!inst) return nullptr;
    std::string jsonStr = inst->getParametersJSON();
    char* cstr = new char[jsonStr.length() + 1];
    strcpy(cstr, jsonStr.c_str());
    return cstr;
}

DART_EXPORT void instrument_free_json(const char* jsonPtr) {
    if (jsonPtr) delete[] jsonPtr;
}

DART_EXPORT void instrument_note_on(FaustInstrument* inst, float freq, float velocity, float strike) {
    if (inst) inst->noteOn(freq, velocity, strike);
}

DART_EXPORT void instrument_note_off(FaustInstrument* inst) {
    if (inst) inst->noteOff();
}

DART_EXPORT void instrument_render(FaustInstrument* inst, float* buffer, int numFrames) {
    if (inst && buffer) inst->render(numFrames, buffer);
}

DART_EXPORT FaustInstrument* instrument_create(int instrumentID, int execType, float sampleRate) {
    return new FaustInstrument(instrumentID, static_cast<DSPExecutionType>(execType), sampleRate);
}

DART_EXPORT void instrument_destroy(FaustInstrument* inst) {
    if (inst) delete inst;
}

DART_EXPORT float instrument_get_sample_rate(FaustInstrument* inst) {
    if (inst) return inst->getSampleRate();
    return 48000.0f;
}

// --- Manual Factory Endpoints (Optional bypass for specialized UI) ---

DART_EXPORT FaustFlute* flute_create(float sampleRate) { return new FaustFlute(sampleRate); }
DART_EXPORT void flute_destroy(FaustFlute* i) { delete i; }

DART_EXPORT FaustBowl* bowl_create(float sampleRate) { return new FaustBowl(sampleRate); }
DART_EXPORT void bowl_destroy(FaustBowl* i) { delete i; }

DART_EXPORT FaustDayan* dayan_create(float sampleRate) { return new FaustDayan(sampleRate); }
DART_EXPORT void dayan_destroy(FaustDayan* i) { delete i; }

DART_EXPORT FaustBayan* bayan_create(float sampleRate) { return new FaustBayan(sampleRate); }
DART_EXPORT void bayan_destroy(FaustBayan* i) { delete i; }

DART_EXPORT FaustSitar* sitar_create(float sampleRate) { return new FaustSitar(sampleRate); }
DART_EXPORT void sitar_destroy(FaustSitar* i) { delete i; }

DART_EXPORT FaustTanpura* tanpura_create(float sampleRate) { return new FaustTanpura(sampleRate); }
DART_EXPORT void tanpura_destroy(FaustTanpura* i) { delete i; }

DART_EXPORT FaustBell* bell_create(float sampleRate) { return new FaustBell(sampleRate); }
DART_EXPORT void bell_destroy(FaustBell* i) { delete i; }

DART_EXPORT FaustKick* kick_create(float sampleRate) { return new FaustKick(sampleRate); }
DART_EXPORT void kick_destroy(FaustKick* i) { delete i; }

DART_EXPORT FaustSnare* snare_create(float sampleRate) { return new FaustSnare(sampleRate); }
DART_EXPORT void snare_destroy(FaustSnare* i) { delete i; }

DART_EXPORT FaustTom* tom_create(float sampleRate) { return new FaustTom(sampleRate); }
DART_EXPORT void tom_destroy(FaustTom* i) { delete i; }

DART_EXPORT FaustHiHat* hihat_create(float sampleRate) { return new FaustHiHat(sampleRate); }
DART_EXPORT void hihat_destroy(FaustHiHat* i) { delete i; }

DART_EXPORT FaustRide* ride_create(float sampleRate) { return new FaustRide(sampleRate); }
DART_EXPORT void ride_destroy(FaustRide* i) { delete i; }

DART_EXPORT FaustCowbell* cowbell_create(float sampleRate) { return new FaustCowbell(sampleRate); }
DART_EXPORT void cowbell_destroy(FaustCowbell* i) { delete i; }

DART_EXPORT FaustPiano* piano_create(float sampleRate) { return new FaustPiano(sampleRate); }
DART_EXPORT void piano_destroy(FaustPiano* i) { delete i; }

DART_EXPORT FaustSax* sax_create(float sampleRate) { return new FaustSax(sampleRate); }
DART_EXPORT void sax_destroy(FaustSax* i) { delete i; }

DART_EXPORT FaustTrumpet* trumpet_create(float sampleRate) { return new FaustTrumpet(sampleRate); }
DART_EXPORT void trumpet_destroy(FaustTrumpet* i) { delete i; }

DART_EXPORT FaustShakuhachi* shakuhachi_create(float sampleRate) { return new FaustShakuhachi(sampleRate); }
DART_EXPORT void shakuhachi_destroy(FaustShakuhachi* i) { delete i; }

DART_EXPORT FaustBansuri* bansuri_create(float sampleRate) { return new FaustBansuri(sampleRate); }
DART_EXPORT void bansuri_destroy(FaustBansuri* i) { delete i; }

DART_EXPORT FaustViolin* violin_create(float sampleRate) { return new FaustViolin(sampleRate); }
DART_EXPORT void violin_destroy(FaustViolin* i) { delete i; }




DART_EXPORT bool mixer_get_track_mute(FaustMixer* mixer, int trackID) {
    return mixer ? mixer->isTrackMuted(trackID) : true;
}

DART_EXPORT void mixer_unmute_tracks(FaustMixer* mixer, const int* trackIDs, int count) {
    if (mixer && trackIDs && count > 0) {
        mixer->unmuteTracks(trackIDs, count);
    }
}

} // extern "C"
