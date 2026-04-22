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
DART_EXPORT void bowl_set_rub(FaustBowl* bowl, float rub);
DART_EXPORT void bowl_set_waver(FaustBowl* bowl, float waver);
DART_EXPORT void bowl_strike(FaustBowl* bowl, float velocity);
DART_EXPORT void bowl_render(FaustBowl* bowl, int numFrames, float* buffer);

// --- Tabla Dayan ---
DART_EXPORT FaustDayan* dayan_create(float sampleRate);
DART_EXPORT void dayan_destroy(FaustDayan* dayan);
DART_EXPORT void dayan_set_frequency(FaustDayan* dayan, float freq);
DART_EXPORT void dayan_strike(FaustDayan* dayan, float velocity);
DART_EXPORT void dayan_render(FaustDayan* dayan, int numFrames, float* buffer);

// --- Tabla Bayan ---
DART_EXPORT FaustBayan* bayan_create(float sampleRate);
DART_EXPORT void bayan_destroy(FaustBayan* bayan);
DART_EXPORT void bayan_set_frequency(FaustBayan* bayan, float freq);
DART_EXPORT void bayan_set_meend(FaustBayan* bayan, float multiplier);
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

#ifdef __cplusplus
}
#endif

#endif // FAUST_MIN_H
