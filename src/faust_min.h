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

#ifndef FAUST_MIN_H
#define FAUST_MIN_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
#define DART_EXPORT __declspec(dllexport)
#else
#define DART_EXPORT __attribute__((visibility("default")))
#endif

// Opaque types
typedef struct FaustFlute FaustFlute;
typedef struct FaustBowl FaustBowl;
typedef struct FaustDayan FaustDayan;
typedef struct FaustBayan FaustBayan;
typedef struct FaustSitar FaustSitar;
typedef struct FaustBell FaustBell;
typedef struct FaustTanpura FaustTanpura;
typedef struct FaustPiano FaustPiano;
typedef struct FaustSax FaustSax;
typedef struct FaustTrumpet FaustTrumpet;
typedef struct FaustCowbell FaustCowbell;
typedef struct FaustShakuhachi FaustShakuhachi;
typedef struct FaustBansuri FaustBansuri;

// --- High-Res Automation Event ---
typedef struct {
    int sampleOffset;
    int instrumentId;
    int eventType;  // 0 = Strike, 1 = SetFreq, 2 = SetParam
    int paramId;    // Context-dependent (e.g. 0 = Mute, 1 = Damping)
    float value;    // Exact value (Velocity, Hz, or generic float)
} FaustEvent;

// --- Flute ---
DART_EXPORT FaustFlute* flute_create(float sampleRate);
DART_EXPORT void flute_destroy(FaustFlute* flute);
DART_EXPORT void flute_set_frequency(FaustFlute* flute, float freq);
DART_EXPORT void flute_set_pressure(FaustFlute* flute, float pressure);
DART_EXPORT void flute_set_vibrato(FaustFlute* flute, float rate, float depth);
DART_EXPORT void flute_set_duration(FaustFlute* flute, float seconds);
DART_EXPORT void flute_note_on(FaustFlute* flute, float freq, float velocity);
DART_EXPORT void flute_note_off(FaustFlute* flute);
DART_EXPORT void flute_render(FaustFlute* flute, int numFrames, float* buffer);

// --- Singing Bowl ---
DART_EXPORT FaustBowl* bowl_create(float sampleRate);
DART_EXPORT void bowl_destroy(FaustBowl* bowl);
DART_EXPORT void bowl_set_frequency(FaustBowl* bowl, float freq);
DART_EXPORT void bowl_set_duration(FaustBowl* bowl, float seconds);
DART_EXPORT void bowl_set_rub(FaustBowl* bowl, float rub);
DART_EXPORT void bowl_set_waver(FaustBowl* bowl, float waver);
DART_EXPORT void bowl_note_on(FaustBowl* bowl, float freq, float velocity);
DART_EXPORT void bowl_note_off(FaustBowl* bowl);
DART_EXPORT void bowl_render(FaustBowl* bowl, int numFrames, float* buffer);

// --- Tabla Dayan ---
DART_EXPORT FaustDayan* dayan_create(float sampleRate);
DART_EXPORT void dayan_destroy(FaustDayan* dayan);
DART_EXPORT void dayan_set_frequency(FaustDayan* dayan, float freq);
DART_EXPORT void dayan_set_mute(FaustDayan* dayan, int muted);
DART_EXPORT void dayan_note_on(FaustDayan* dayan, float freq, float velocity);
DART_EXPORT void dayan_note_off(FaustDayan* dayan);
DART_EXPORT void dayan_render(FaustDayan* dayan, int numFrames, float* buffer);

// --- Tabla Bayan ---
DART_EXPORT FaustBayan* bayan_create(float sampleRate);
DART_EXPORT void bayan_destroy(FaustBayan* bayan);
DART_EXPORT void bayan_set_frequency(FaustBayan* bayan, float freq);
DART_EXPORT void bayan_set_meend(FaustBayan* bayan, float multiplier);
DART_EXPORT void bayan_set_mute(FaustBayan* bayan, int muted);
DART_EXPORT void bayan_note_on(FaustBayan* bayan, float freq, float velocity);
DART_EXPORT void bayan_note_off(FaustBayan* bayan);
DART_EXPORT void bayan_render(FaustBayan* bayan, int numFrames, float* buffer);

// --- Sitar ---
DART_EXPORT FaustSitar* sitar_create(float sampleRate);
DART_EXPORT void sitar_destroy(FaustSitar* sitar);
DART_EXPORT void sitar_set_frequency(FaustSitar* sitar, float freq);
DART_EXPORT void sitar_set_jivari(FaustSitar* sitar, float amount);
DART_EXPORT void sitar_set_sympathetic_gain(FaustSitar* sitar, float gain);
DART_EXPORT void sitar_pluck(FaustSitar* sitar, float velocity);
DART_EXPORT void sitar_note_on(FaustSitar* sitar, float freq, float velocity);
DART_EXPORT void sitar_note_off(FaustSitar* sitar);
DART_EXPORT void sitar_render(FaustSitar* sitar, int numFrames, float* buffer);

// --- Tanpura ---
DART_EXPORT FaustTanpura* tanpura_create(float sampleRate);
DART_EXPORT void tanpura_destroy(FaustTanpura* tanpura);
DART_EXPORT void tanpura_set_params(FaustTanpura* tanpura, float f1, float f2, float f3, float f4, float decay, float delay);
DART_EXPORT void tanpura_set_jivari(FaustTanpura* tanpura, float amount);
DART_EXPORT void tanpura_set_playing(FaustTanpura* tanpura, int playing);
DART_EXPORT void tanpura_note_on(FaustTanpura* tanpura, float freq, float velocity);
DART_EXPORT void tanpura_note_off(FaustTanpura* tanpura);
DART_EXPORT void tanpura_render(FaustTanpura* tanpura, int numFrames, float* buffer);

// --- Bell ---
DART_EXPORT FaustBell* bell_create(float sampleRate);
DART_EXPORT void bell_destroy(FaustBell* bell);
DART_EXPORT void bell_set_frequency(FaustBell* bell, float freq);
DART_EXPORT void bell_set_ring_time(FaustBell* bell, float seconds);
DART_EXPORT void bell_set_damping(FaustBell* bell, float damping);
DART_EXPORT void bell_note_on(FaustBell* bell, float freq, float velocity);
DART_EXPORT void bell_note_off(FaustBell* bell);
DART_EXPORT void bell_render(FaustBell* bell, int numFrames, float* buffer);

// --- Drum Kit ---
typedef struct FaustKick FaustKick;
typedef struct FaustSnare FaustSnare;
typedef struct FaustTom FaustTom;
typedef struct FaustHiHat FaustHiHat;
typedef struct FaustRide FaustRide;

DART_EXPORT FaustKick* kick_create(float sampleRate);
DART_EXPORT void kick_destroy(FaustKick* kick);
DART_EXPORT void kick_render(FaustKick* kick, int numFrames, float* buffer);

DART_EXPORT FaustSnare* snare_create(float sampleRate);
DART_EXPORT void snare_destroy(FaustSnare* snare);
DART_EXPORT void snare_render(FaustSnare* snare, int numFrames, float* buffer);

DART_EXPORT FaustTom* tom_create(float sampleRate);
DART_EXPORT void tom_destroy(FaustTom* tom);
DART_EXPORT void tom_set_frequency(FaustTom* tom, float freq);
DART_EXPORT void tom_render(FaustTom* tom, int numFrames, float* buffer);

DART_EXPORT FaustHiHat* hihat_create(float sampleRate);
DART_EXPORT void hihat_destroy(FaustHiHat* hihat);
DART_EXPORT void hihat_set_openness(FaustHiHat* hihat, float openness);
DART_EXPORT void hihat_render(FaustHiHat* hihat, int numFrames, float* buffer);

DART_EXPORT FaustRide* ride_create(float sampleRate);
DART_EXPORT void ride_destroy(FaustRide* ride);
DART_EXPORT void ride_render(FaustRide* ride, int numFrames, float* buffer);

// --- Cowbell ---
DART_EXPORT FaustCowbell* cowbell_create(float sampleRate);
DART_EXPORT void cowbell_destroy(FaustCowbell* cowbell);
DART_EXPORT void cowbell_render(FaustCowbell* cowbell, int numFrames, float* buffer);

// --- Piano ---
DART_EXPORT FaustPiano* piano_create(float sampleRate);
DART_EXPORT void piano_destroy(FaustPiano* piano);
DART_EXPORT void piano_set_frequency(FaustPiano* piano, float freq);
DART_EXPORT void piano_set_sustain(FaustPiano* piano, float level);
DART_EXPORT void piano_set_stiffness(FaustPiano* piano, float stiffness);
DART_EXPORT void piano_note_on(FaustPiano* piano, float freq, float velocity);
DART_EXPORT void piano_note_off(FaustPiano* piano);
DART_EXPORT void piano_render(FaustPiano* piano, int numFrames, float* buffer);

// --- Saxophone ---
DART_EXPORT FaustSax* sax_create(float sampleRate);
DART_EXPORT void sax_destroy(FaustSax* sax);
DART_EXPORT void sax_set_frequency(FaustSax* sax, float freq);
DART_EXPORT void sax_set_vibrato(FaustSax* sax, float rate, float depth);
DART_EXPORT void sax_note_on(FaustSax* sax, float freq, float velocity);
DART_EXPORT void sax_note_off(FaustSax* sax);
DART_EXPORT void sax_render(FaustSax* sax, int numFrames, float* buffer);

// --- Trumpet ---
DART_EXPORT FaustTrumpet* trumpet_create(float sampleRate);
DART_EXPORT void trumpet_destroy(FaustTrumpet* trumpet);
DART_EXPORT void trumpet_set_frequency(FaustTrumpet* trumpet, float freq);
DART_EXPORT void trumpet_set_vibrato(FaustTrumpet* trumpet, float rate, float depth);
DART_EXPORT void trumpet_note_on(FaustTrumpet* trumpet, float freq, float velocity);
DART_EXPORT void trumpet_note_off(FaustTrumpet* trumpet);
DART_EXPORT void trumpet_render(FaustTrumpet* trumpet, int numFrames, float* buffer);

// --- Shakuhachi ---
DART_EXPORT FaustShakuhachi* shakuhachi_create(float sampleRate);
DART_EXPORT void shakuhachi_destroy(FaustShakuhachi* shakuhachi);
DART_EXPORT void shakuhachi_set_frequency(FaustShakuhachi* shakuhachi, float freq);
DART_EXPORT void shakuhachi_set_vibrato(FaustShakuhachi* shakuhachi, float rate, float depth);
DART_EXPORT void shakuhachi_note_on(FaustShakuhachi* shakuhachi, float freq, float velocity);
DART_EXPORT void shakuhachi_note_off(FaustShakuhachi* shakuhachi);
DART_EXPORT void shakuhachi_render(FaustShakuhachi* shakuhachi, int numFrames, float* buffer);

// --- Bansuri ---
DART_EXPORT FaustBansuri* bansuri_create(float sampleRate);
DART_EXPORT void bansuri_destroy(FaustBansuri* bansuri);
DART_EXPORT void bansuri_set_frequency(FaustBansuri* bansuri, float freq);
DART_EXPORT void bansuri_set_vibrato(FaustBansuri* bansuri, float rate, float depth);
DART_EXPORT void bansuri_note_on(FaustBansuri* bansuri, float freq, float velocity);
DART_EXPORT void bansuri_note_off(FaustBansuri* bansuri);
DART_EXPORT void bansuri_render(FaustBansuri* bansuri, int numFrames, float* buffer);

// --- Audio Mixer & DSP ---
DART_EXPORT /**
 * High-Fidelity Stereo Mixer Algorithm:
 * 
 * 1. Track Normalization: Each input track is pre-scanned to find its peak amplitude.
 *    The track is then scaled so its peak reaches 1.0. This ensures that the 
 *    'amplitudeScale' parameters act as absolute proportional weights regardless 
 *    of the instrument's raw output level.
 * 
 * 2. Proportional Scaling: The normalized signal is multiplied by (amplitudeScale * balanceMultiplier).
 *    balanceMultiplier ensures the sum of all weights does not exceed 1.0, preventing initial clipping.
 * 
 * 3. Enveloping: Quadratic fades are applied at the start (offset) and end of each track.
 * 
 * 4. Linear Panning: The signal is distributed into Left/Right channels based on the pan value (-1 to 1).
 * 
 * 5. Master Peak Protection: After all tracks are accumulated, the final stereo mix is scanned.
 *    If the combined signal exceeds 1.0, a global master scale is applied to prevent digital clipping.
 */
void mix_raw_signals(
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

DART_EXPORT void normalize_signal(float* signal, int numSamples, float targetPeak);

DART_EXPORT void render_sequenced_audio(
    int* offsets,
    int* instrumentIds,
    float* velocities,
    float* params,
    int numTriggers,
    float baseFreq,
    float sampleRate,
    int totalSamples,
    float* outputBuffer
);

DART_EXPORT void render_automation_sequence(
    FaustEvent* events,
    int numEvents,
    float sampleRate,
    int totalSamples,
    float* outputBuffer
);

// --- Forward Object Definitions ---
typedef struct SequenceOrchestrator SequenceOrchestrator;
typedef struct UMLSequence UMLSequence;
typedef struct FaustInstrument FaustInstrument;
typedef struct FaustMixer FaustMixer;

// Tick callback type: called from audio thread with playhead position
typedef void (*TickCallback)(long tick, int noteIndex, const char* seqName, void* userData);

// --- Real-time Sequence Orchestrator Object Exposure ---
DART_EXPORT SequenceOrchestrator* orchestrator_create();
DART_EXPORT void orchestrator_destroy(SequenceOrchestrator* orch);
DART_EXPORT void orchestrator_register_tick_callback(SequenceOrchestrator* orch, TickCallback cb, void* userData);

DART_EXPORT void orchestrator_set_asset_base_path(SequenceOrchestrator* orch, const char* path);
DART_EXPORT int orchestrator_add_sequence(SequenceOrchestrator* orch, const char* name, UMLSequence* seq);
DART_EXPORT void orchestrator_play(SequenceOrchestrator* orch, const char* name);
DART_EXPORT void orchestrator_stop(SequenceOrchestrator* orch);
DART_EXPORT void orchestrator_pause(SequenceOrchestrator* orch);
DART_EXPORT void orchestrator_resume(SequenceOrchestrator* orch);
DART_EXPORT void orchestrator_set_weight(SequenceOrchestrator* orch, const char* name, float weight);
DART_EXPORT void orchestrator_set_parameter(SequenceOrchestrator* orch, const char* name, const char* param, float value);
DART_EXPORT const char* orchestrator_poll_finished(SequenceOrchestrator* orch);
DART_EXPORT int orchestrator_load_song(SequenceOrchestrator* orch, const char* directory);
DART_EXPORT void orchestrator_unload_song(SequenceOrchestrator* orch, const char* directory);
DART_EXPORT void orchestrator_play_song(SequenceOrchestrator* orch, const char* directory);
DART_EXPORT void orchestrator_stop_song(SequenceOrchestrator* orch, const char* directory);

// --- FaustMixer Singleton Endpoints ---
DART_EXPORT FaustMixer* mixer_get_instance();
DART_EXPORT int mixer_start(FaustMixer* mixer);
DART_EXPORT void mixer_stop(FaustMixer* mixer);
DART_EXPORT void mixer_clear_all(FaustMixer* mixer);
DART_EXPORT float mixer_get_sample_rate(FaustMixer* mixer);
DART_EXPORT void mixer_set_master_gain(FaustMixer* mixer, float gain);
DART_EXPORT void mixer_register_waveform_callback(FaustMixer* mixer, void (*cb)(float rms, float peak, void* userData), void* userData);


// --- UMLSequence and FaustInstrument Flat Endpoints ---
DART_EXPORT const char* instrument_mapper_get_name(int id);
DART_EXPORT int instrument_mapper_get_id(const char* name);
DART_EXPORT int instrument_mapper_is_percussion(int id);
DART_EXPORT int instrument_mapper_get_polyphony(int id);
DART_EXPORT const char* instrument_mapper_get_class(int id);
DART_EXPORT const char* instrument_mapper_get_origin(int id);
DART_EXPORT int instrument_mapper_get_available(int* outArray, int maxElements);

DART_EXPORT UMLSequence* sequence_create(const char* name, int instID, const char* umlDataString);
DART_EXPORT void sequence_destroy(UMLSequence* seq);
DART_EXPORT FaustInstrument* sequence_get_instrument(UMLSequence* seq);
DART_EXPORT FaustInstrument* instrument_create(int instrumentID, int execType, float sampleRate);
DART_EXPORT void instrument_destroy(FaustInstrument* inst);
DART_EXPORT float instrument_get_sample_rate(FaustInstrument* inst);
DART_EXPORT void instrument_set_parameter(FaustInstrument* inst, const char* name, float value);
DART_EXPORT const char* instrument_get_parameters_json(FaustInstrument* inst);
DART_EXPORT void instrument_free_json(const char* jsonPtr);
/**
 * Play a note.
 *
 * freq: frequency in Hz. Pass -1 for instruments with built-in pitch
 *       (thunder, wind, clap, percussion).
 * amplitude: output level (required > 0).
 * velocity: playing velocity (-1 = DSP default).
 * strike: articulation / stroke type (-1 = DSP default).
 *         For percussion: selects different strokes (open, muted, rim, etc).
 */
DART_EXPORT void instrument_note_on(FaustInstrument* inst, float freq, float velocity, float strike);
DART_EXPORT void instrument_note_off(FaustInstrument* inst);
DART_EXPORT void instrument_render(FaustInstrument* inst, float* buffer, int numFrames);
DART_EXPORT double sequence_get_bpm(UMLSequence* seq);
DART_EXPORT int sequence_get_grid(UMLSequence* seq);
DART_EXPORT double sequence_get_basefreq(UMLSequence* seq);
DART_EXPORT void sequence_set_basefreq(UMLSequence* seq, double freq);

DART_EXPORT void sequence_add_note(UMLSequence* seq, float pitch, float velocity, float startBeat, float durationBeats, float strikeVal = 0.0f);
DART_EXPORT void sequence_remove_note(UMLSequence* seq, float pitch, float startBeat);
DART_EXPORT void sequence_clear_notes(UMLSequence* seq);
DART_EXPORT int sequence_get_notes(UMLSequence* seq, float fromBeat, float toBeat, float* outBuffer, int maxNotes, char* outNames);

#ifdef __cplusplus
}
#endif

#endif // FAUST_MIN_H
