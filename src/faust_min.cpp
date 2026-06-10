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
 * @file faust_min.cpp
 * @brief Implementation file for faust_min
 * 
 * DESIGN: Universal FFI Bridge. It exposes the engine's high-level functionality to the Dart layer through a flat C-style API, enabling cross-platform mobile integration.
 */

#include "faust_min.h"
#include <cmath>
#include <algorithm>
#include <cstdio>
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
#include "SequenceOrchestrator.hpp"

static struct FaustMinInit {
    FaustMinInit() {
        printf("FaustMin: Native Library Loaded Successfully\n");
        fflush(stdout);
    }
} g_faustMinInit;

extern "C" {

// --- High-Level Orchestrator Endpoints (The Controller) ---

DART_EXPORT SequenceOrchestrator* orchestrator_create() {
    auto& orch = SequenceOrchestrator::getInstance();
    // Connect the Brain to the Heartbeat via the FFI bridge (Decoupled)
    FaustMixer::getInstance().setPreRenderCallback(SequenceOrchestrator::staticPreRender, &orch);
    return &orch;
}



DART_EXPORT int orchestrator_add_sequence(SequenceOrchestrator* orch, const char* name, UMLSequence* seq) {
    if (orch && name && seq) {
        return orch->addSequence(name, seq);
    }
    return -3;
}

DART_EXPORT void orchestrator_play(SequenceOrchestrator* orch, const char* name) {
    if (orch && name) orch->play(name);
}

DART_EXPORT void orchestrator_destroy(SequenceOrchestrator* orchestrator) {
    if (orchestrator) {
        orchestrator->stop();
        // Do NOT delete the singleton!
    }
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

DART_EXPORT void orchestrator_mute_track(SequenceOrchestrator* orch, const char* name, int mute) {
    if (orch && name) orch->muteTrack(name, mute != 0);
}

DART_EXPORT void orchestrator_set_parameter(SequenceOrchestrator* orch, const char* name, const char* param, float value) {
    if (orch && name && param) orch->setParameter(name, param, value);
}



DART_EXPORT const char* orchestrator_poll_finished(SequenceOrchestrator* orch) {
    return orch ? orch->pollFinished() : nullptr;
}

// --- FaustMixer Singleton Endpoints ---

DART_EXPORT FaustMixer* mixer_get_instance() {
    return &FaustMixer::getInstance();
}

DART_EXPORT void mixer_init(FaustMixer* mixer, float sampleRate) {
    if (mixer) mixer->init(sampleRate);
}

DART_EXPORT int mixer_start(FaustMixer* mixer) {
    return (mixer && mixer->start()) ? 1 : 0;
}

DART_EXPORT void mixer_stop(FaustMixer* mixer) {
    if (mixer) mixer->stop();
}

DART_EXPORT float mixer_get_sample_rate(FaustMixer* mixer) {
    return mixer ? mixer->getSampleRate() : 0.0f;
}

DART_EXPORT void mixer_set_master_gain(FaustMixer* mixer, float gain) {
    if (mixer) mixer->setMasterGain(gain);
}

DART_EXPORT void mixer_set_instrument_weight(FaustMixer* mixer, FaustInstrument* inst, float weight) {
    if (mixer && inst) mixer->setInstrumentWeight(inst, weight);
}

DART_EXPORT int mixer_register_instrument(FaustMixer* mixer, FaustInstrument* inst, float weight) {
    if (!mixer || !inst) return 0;
    if (fabsf(mixer->getSampleRate() - inst->getSampleRate()) > 0.5f) {
        fprintf(stderr, "[FaustMixer] ERROR: Sample rate mismatch — mixer SR=%.0f, instrument SR=%.0f. Rejecting registration.\n",
                mixer->getSampleRate(), inst->getSampleRate());
        return 0;
    }
    int trackID = mixer->addTrack(weight);
    mixer->addInstrumentToTrack(trackID, inst);
    return 1;
}

DART_EXPORT void mixer_unregister_instrument(FaustMixer* mixer, FaustInstrument* inst) {
    // Note: Since we don't track the ID here, we might need a reverse lookup in the future.
    // For now, removing an instrument from all tracks isn't explicitly supported in this single call.
}

// --- UMLSequence Flat Endpoints ---

DART_EXPORT UMLSequence* sequence_create(const char* name, int instID, const char* umlDataString) {
    if (!name || !umlDataString) return nullptr;
    return new UMLSequence(name, instID, umlDataString);
}

DART_EXPORT void sequence_destroy(UMLSequence* seq) {
    if (seq) delete seq;
}

DART_EXPORT double sequence_get_bpm(UMLSequence* seq) {
    return seq ? seq->bpm : 120.0;
}

DART_EXPORT int sequence_get_grid(UMLSequence* seq) {
    return seq ? seq->grid : 4;
}

DART_EXPORT double sequence_get_basefreq(UMLSequence* seq) {
    return seq ? seq->baseFreq : 261.63;
}

DART_EXPORT void sequence_set_basefreq(UMLSequence* seq, double freq) {
    if (seq) seq->baseFreq = freq;
}

DART_EXPORT FaustInstrument* sequence_get_instrument(UMLSequence* seq) {
    return seq ? seq->getFaustInstrument() : nullptr;
}

// --- Individual Instrument Endpoints (For UI Auditioning/Direct Control) ---

DART_EXPORT void instrument_set_parameter(FaustInstrument* inst, const char* name, float value) {
    if (inst && name) inst->setParameter(name, value);
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
    delete inst;
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

} // extern "C"
