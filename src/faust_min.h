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

// --- Flute ---
DART_EXPORT FaustFlute* flute_create(float sampleRate);
DART_EXPORT void flute_destroy(FaustFlute* flute);
DART_EXPORT void flute_set_frequency(FaustFlute* flute, float freq);
DART_EXPORT void flute_set_pressure(FaustFlute* flute, float pressure);
DART_EXPORT void flute_set_vibrato(FaustFlute* flute, float rate, float depth);
DART_EXPORT void flute_render(FaustFlute* flute, int numFrames, float* buffer);

// --- Singing Bowl ---
DART_EXPORT FaustBowl* bowl_create(float sampleRate);
DART_EXPORT void bowl_destroy(FaustBowl* bowl);
DART_EXPORT void bowl_set_frequency(FaustBowl* bowl, float freq);
DART_EXPORT void bowl_set_duration(FaustBowl* bowl, float seconds);
DART_EXPORT void bowl_set_rub(FaustBowl* bowl, float rub);
DART_EXPORT void bowl_set_waver(FaustBowl* bowl, float waver);
DART_EXPORT void bowl_strike(FaustBowl* bowl, float velocity);
DART_EXPORT void bowl_render(FaustBowl* bowl, int numFrames, float* buffer);

// --- Tabla Dayan ---
DART_EXPORT FaustDayan* dayan_create(float sampleRate);
DART_EXPORT void dayan_destroy(FaustDayan* dayan);
DART_EXPORT void dayan_set_frequency(FaustDayan* dayan, float freq);
DART_EXPORT void dayan_set_mute(FaustDayan* dayan, int muted);
DART_EXPORT void dayan_strike(FaustDayan* dayan, float velocity);
DART_EXPORT void dayan_render(FaustDayan* dayan, int numFrames, float* buffer);

// --- Tabla Bayan ---
DART_EXPORT FaustBayan* bayan_create(float sampleRate);
DART_EXPORT void bayan_destroy(FaustBayan* bayan);
DART_EXPORT void bayan_set_frequency(FaustBayan* bayan, float freq);
DART_EXPORT void bayan_set_meend(FaustBayan* bayan, float multiplier);
DART_EXPORT void bayan_set_mute(FaustBayan* bayan, int muted);
DART_EXPORT void bayan_strike(FaustBayan* bayan, float velocity);
DART_EXPORT void bayan_render(FaustBayan* bayan, int numFrames, float* buffer);

// --- Sitar ---
DART_EXPORT FaustSitar* sitar_create(float sampleRate);
DART_EXPORT void sitar_destroy(FaustSitar* sitar);
DART_EXPORT void sitar_set_frequency(FaustSitar* sitar, float freq);
DART_EXPORT void sitar_set_jivari(FaustSitar* sitar, float amount);
DART_EXPORT void sitar_set_sympathetic_gain(FaustSitar* sitar, float gain);
DART_EXPORT void sitar_pluck(FaustSitar* sitar, float velocity);
DART_EXPORT void sitar_render(FaustSitar* sitar, int numFrames, float* buffer);

// --- Bell ---
DART_EXPORT FaustBell* bell_create(float sampleRate);
DART_EXPORT void bell_destroy(FaustBell* bell);
DART_EXPORT void bell_set_frequency(FaustBell* bell, float freq);
DART_EXPORT void bell_set_duration(FaustBell* bell, float seconds);
DART_EXPORT void bell_set_damping(FaustBell* bell, float damping);
DART_EXPORT void bell_strike(FaustBell* bell, float velocity);
DART_EXPORT void bell_render(FaustBell* bell, int numFrames, float* buffer);

// --- Drum Kit ---
typedef struct FaustKick FaustKick;
typedef struct FaustSnare FaustSnare;
typedef struct FaustTom FaustTom;
typedef struct FaustHiHat FaustHiHat;
typedef struct FaustRide FaustRide;

DART_EXPORT FaustKick* kick_create(float sampleRate);
DART_EXPORT void kick_destroy(FaustKick* kick);
DART_EXPORT void kick_strike(FaustKick* kick, float velocity);
DART_EXPORT void kick_render(FaustKick* kick, int numFrames, float* buffer);

DART_EXPORT FaustSnare* snare_create(float sampleRate);
DART_EXPORT void snare_destroy(FaustSnare* snare);
DART_EXPORT void snare_strike(FaustSnare* snare, float velocity);
DART_EXPORT void snare_render(FaustSnare* snare, int numFrames, float* buffer);

DART_EXPORT FaustTom* tom_create(float sampleRate);
DART_EXPORT void tom_destroy(FaustTom* tom);
DART_EXPORT void tom_set_frequency(FaustTom* tom, float freq);
DART_EXPORT void tom_strike(FaustTom* tom, float velocity);
DART_EXPORT void tom_render(FaustTom* tom, int numFrames, float* buffer);

DART_EXPORT FaustHiHat* hihat_create(float sampleRate);
DART_EXPORT void hihat_destroy(FaustHiHat* hihat);
DART_EXPORT void hihat_set_openness(FaustHiHat* hihat, float openness);
DART_EXPORT void hihat_strike(FaustHiHat* hihat, float velocity);
DART_EXPORT void hihat_render(FaustHiHat* hihat, int numFrames, float* buffer);

DART_EXPORT FaustRide* ride_create(float sampleRate);
DART_EXPORT void ride_destroy(FaustRide* ride);
DART_EXPORT void ride_strike(FaustRide* ride, float velocity);
DART_EXPORT void ride_render(FaustRide* ride, int numFrames, float* buffer);

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

#ifdef __cplusplus
}
#endif

#endif // FAUST_MIN_H
