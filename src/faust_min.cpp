#include "faust_min.h"
#include "FaustFlute.hpp"
#include "FaustBowl.hpp"
#include "FaustDayan.hpp"
#include "FaustBayan.hpp"
#include "FaustSitar.hpp"
#include "FaustKick.hpp"
#include "FaustSnare.hpp"
#include "FaustTom.hpp"
#include "FaustHiHat.hpp"
#include "FaustRide.hpp"

extern "C" {

// --- Flute ---
FaustFlute* flute_create(float sampleRate) { return new FaustFlute(sampleRate); }
void flute_destroy(FaustFlute* flute) { delete flute; }
void flute_set_frequency(FaustFlute* flute, float freq) { flute->setFrequency(freq); }
void flute_set_pressure(FaustFlute* flute, float pressure) { flute->setPressure(pressure); }
void flute_set_vibrato(FaustFlute* flute, float rate, float depth) { flute->setVibrato(rate, depth); }
void flute_render(FaustFlute* flute, int numFrames, float* buffer) { flute->render(numFrames, buffer); }

// --- Singing Bowl ---
FaustBowl* bowl_create(float sampleRate) { return new FaustBowl(sampleRate); }
void bowl_destroy(FaustBowl* bowl) { delete bowl; }
void bowl_set_frequency(FaustBowl* bowl, float freq) { bowl->setFrequency(freq); }
void bowl_set_rub(FaustBowl* bowl, float rub) { bowl->setRub(rub); }
void bowl_set_waver(FaustBowl* bowl, float waver) { bowl->setWaver(waver); }
void bowl_strike(FaustBowl* bowl, float velocity) { bowl->strike(velocity); }
void bowl_render(FaustBowl* bowl, int numFrames, float* buffer) { bowl->render(numFrames, buffer); }

// --- Tabla Dayan ---
FaustDayan* dayan_create(float sampleRate) { return new FaustDayan(sampleRate); }
void dayan_destroy(FaustDayan* dayan) { delete dayan; }
void dayan_set_frequency(FaustDayan* dayan, float freq) { dayan->setFrequency(freq); }
void dayan_strike(FaustDayan* dayan, float velocity) { dayan->strike(velocity); }
void dayan_render(FaustDayan* dayan, int numFrames, float* buffer) { dayan->render(numFrames, buffer); }

// --- Tabla Bayan ---
FaustBayan* bayan_create(float sampleRate) { return new FaustBayan(sampleRate); }
void bayan_destroy(FaustBayan* bayan) { delete bayan; }
void bayan_set_frequency(FaustBayan* bayan, float freq) { bayan->setFrequency(freq); }
void bayan_set_meend(FaustBayan* bayan, float multiplier) { bayan->setMeend(multiplier); }
void bayan_strike(FaustBayan* bayan, float velocity) { bayan->strike(velocity); }
void bayan_render(FaustBayan* bayan, int numFrames, float* buffer) { bayan->render(numFrames, buffer); }

// --- Sitar ---
FaustSitar* sitar_create(float sampleRate) { return new FaustSitar(sampleRate); }
void sitar_destroy(FaustSitar* sitar) { delete sitar; }
void sitar_set_frequency(FaustSitar* sitar, float freq) { sitar->setFrequency(freq); }
void sitar_set_jivari(FaustSitar* sitar, float amount) { sitar->setJivari(amount); }
void sitar_set_sympathetic_gain(FaustSitar* sitar, float gain) { sitar->setSympatheticGain(gain); }
void sitar_pluck(FaustSitar* sitar, float velocity) { sitar->pluck(velocity); }
void sitar_render(FaustSitar* sitar, int numFrames, float* buffer) { sitar->render(numFrames, buffer); }

// --- Drum Kit ---
FaustKick* kick_create(float sampleRate) { return new FaustKick(sampleRate); }
void kick_destroy(FaustKick* kick) { delete kick; }
void kick_strike(FaustKick* kick, float velocity) { kick->strike(velocity); }
void kick_render(FaustKick* kick, int numFrames, float* buffer) { kick->render(numFrames, buffer); }

FaustSnare* snare_create(float sampleRate) { return new FaustSnare(sampleRate); }
void snare_destroy(FaustSnare* snare) { delete snare; }
void snare_strike(FaustSnare* snare, float velocity) { snare->strike(velocity); }
void snare_render(FaustSnare* snare, int numFrames, float* buffer) { snare->render(numFrames, buffer); }

FaustTom* tom_create(float sampleRate) { return new FaustTom(sampleRate); }
void tom_destroy(FaustTom* tom) { delete tom; }
void tom_set_frequency(FaustTom* tom, float freq) { tom->setFrequency(freq); }
void tom_strike(FaustTom* tom, float velocity) { tom->strike(velocity); }
void tom_render(FaustTom* tom, int numFrames, float* buffer) { tom->render(numFrames, buffer); }

FaustHiHat* hihat_create(float sampleRate) { return new FaustHiHat(sampleRate); }
void hihat_destroy(FaustHiHat* hihat) { delete hihat; }
void hihat_set_openness(FaustHiHat* hihat, float openness) { hihat->setOpenness(openness); }
void hihat_strike(FaustHiHat* hihat, float velocity) { hihat->strike(velocity); }
void hihat_render(FaustHiHat* hihat, int numFrames, float* buffer) { hihat->render(numFrames, buffer); }

FaustRide* ride_create(float sampleRate) { return new FaustRide(sampleRate); }
void ride_destroy(FaustRide* ride) { delete ride; }
void ride_strike(FaustRide* ride, float velocity) { ride->strike(velocity); }
void ride_render(FaustRide* ride, int numFrames, float* buffer) { ride->render(numFrames, buffer); }

}
