#include <cmath>
#include <algorithm>
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
#include "FaustBell.hpp"
#include "FaustTanpura.hpp"

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
void bowl_set_duration(FaustBowl* bowl, float seconds) { bowl->setDuration(seconds); }
void bowl_set_rub(FaustBowl* bowl, float rub) { bowl->setRub(rub); }
void bowl_set_waver(FaustBowl* bowl, float waver) { bowl->setWaver(waver); }
void bowl_strike(FaustBowl* bowl, float velocity) { bowl->strike(velocity); }
void bowl_render(FaustBowl* bowl, int numFrames, float* buffer) { bowl->render(numFrames, buffer); }

// --- Tabla Dayan ---
FaustDayan* dayan_create(float sampleRate) { return new FaustDayan(sampleRate); }
void dayan_destroy(FaustDayan* dayan) { delete dayan; }
void dayan_set_frequency(FaustDayan* dayan, float freq) { dayan->setFrequency(freq); }
void dayan_set_mute(FaustDayan* dayan, int muted) { dayan->setMute(muted != 0); }
void dayan_strike(FaustDayan* dayan, float velocity) { dayan->strike(velocity); }
void dayan_render(FaustDayan* dayan, int numFrames, float* buffer) { dayan->render(numFrames, buffer); }

// --- Tabla Bayan ---
FaustBayan* bayan_create(float sampleRate) { return new FaustBayan(sampleRate); }
void bayan_destroy(FaustBayan* bayan) { delete bayan; }
void bayan_set_frequency(FaustBayan* bayan, float freq) { bayan->setFrequency(freq); }
void bayan_set_meend(FaustBayan* bayan, float multiplier) { bayan->setMeend(multiplier); }
void bayan_set_mute(FaustBayan* bayan, int muted) { bayan->setMute(muted != 0); }
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

// --- Tanpura ---
FaustTanpura* tanpura_create(float sampleRate) { return new FaustTanpura(sampleRate); }
void tanpura_destroy(FaustTanpura* tanpura) { if (tanpura) delete tanpura; }
void tanpura_set_params(FaustTanpura* tanpura, float f1, float f2, float f3, float f4, float decay, float delay) {
    if (tanpura) tanpura->setParams(f1, f2, f3, f4, decay, delay);
}
void tanpura_set_jivari(FaustTanpura* tanpura, float amount) {
    if (tanpura) tanpura->setJivari(amount);
}
void tanpura_set_playing(FaustTanpura* tanpura, int playing) {
    if (tanpura) tanpura->setPlaying(playing != 0);
}
void tanpura_render(FaustTanpura* tanpura, int numFrames, float* buffer) {
    if (tanpura) tanpura->render(numFrames, buffer);
}


// --- Bell ---
FaustBell* bell_create(float sampleRate) { return new FaustBell(sampleRate); }
void bell_destroy(FaustBell* bell) { delete bell; }
void bell_set_frequency(FaustBell* bell, float freq) { bell->setFrequency(freq); }
void bell_set_duration(FaustBell* bell, float seconds) { bell->setDuration(seconds); }
void bell_set_damping(FaustBell* bell, float damping) { bell->setDamping(damping); }
void bell_strike(FaustBell* bell, float velocity) { bell->strike(velocity); }
void bell_render(FaustBell* bell, int numFrames, float* buffer) { bell->render(numFrames, buffer); }

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

// --- Audio Mixer & DSP ---

void normalize_signal(float* signal, int numSamples, float targetPeak);
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
) {
    // 1. Clear stereo output buffer (size is numSamples * 2)
    int totalStereoSamples = numSamples * 2;
    for (int i = 0; i < totalStereoSamples; i++) {
        outputBuffer[i] = 0.0f;
    }
    
    // 2. Auto-balance weights (amplitudeScales) so they don't exceed 1.0
    float totalWeight = 0.0f;
    for (int t = 0; t < numTracks; t++) {
        totalWeight += amplitudeScales[t];
    }
    float balanceMultiplier = 1.0f;
    if (totalWeight > 1.0f) {
        balanceMultiplier = 1.0f / totalWeight;
    }
    
    // 3. Process each track
    for (int t = 0; t < numTracks; t++) {
        float* track = inputBuffers[t];
        if (track == nullptr) continue;
        
        int offset = offsetSamples[t];
        
        // Find peak to normalize this specific track (starting from offset)
        float maxAmp = 0.0f;
        for (int i = offset; i < numSamples; i++) {
            float absVal = std::abs(track[i]);
            if (absVal > maxAmp) maxAmp = absVal;
        }
        
        if (maxAmp == 0.0f) continue;
        
        // Use normalized weight: (amplitudeScale * balanceMultiplier) / maxAmp
        float effectiveWeight = (amplitudeScales[t] * balanceMultiplier) / maxAmp;
        
        int fIn = fadeInSamples[t];
        int fOut = fadeOutSamples[t];
        int curve = curveTypes[t];
        int fadeOutStart = (numSamples > fOut) ? (numSamples - fOut) : 0;
        
        // Linear Panning logic (-1.0 to 1.0)
        float pan = pans[t];
        float leftGain = pan < 0.0f ? 1.0f : 1.0f - pan;
        float rightGain = pan > 0.0f ? 1.0f : 1.0f + pan;
        
        // Single pass per track: Scale, Fade, Pan, and Accumulate into Stereo Output
        for (int i = 0; i < numSamples; i++) {
            if (i < offset) continue; // Skip warmup silence
            
            float val = track[i] * effectiveWeight;
            float envelope = 1.0f;
            
            // Fade In (starts at offset)
            if (i < offset + fIn && fIn > 0) {
                float k = (float)(i - offset) / (float)fIn;
                envelope = k * k; // Quadratic fade in
            } 
            // Fade Out
            else if (i >= fadeOutStart && fOut > 0) {
                float k = 1.0f - ((float)(i - fadeOutStart) / (float)fOut);
                if (k < 0.0f) k = 0.0f;
                if (curve == 4) envelope = k * k * k * k; // Quartic
                else if (curve == 2) envelope = k * k;    // Quadratic
                else envelope = k * k * k;                // Cubic (default)
            }
            
            float finalVal = val * envelope;
            
            // Interleaved Stereo Accumulation
            outputBuffer[i * 2] += finalVal * leftGain;       // Left Channel
            outputBuffer[i * 2 + 1] += finalVal * rightGain;  // Right Channel
        }
    }
    
    // 4. Master Peak Protection (Normalize only if clipping)
    float globalMax = 0.0f;
    for (int i = 0; i < totalStereoSamples; i++) {
        float absVal = std::abs(outputBuffer[i]);
        if (absVal > globalMax) globalMax = absVal;
    }

    float finalScale = masterGain;
    if (globalMax > 1.0f) {
        finalScale *= (1.0f / globalMax);
    }

    if (finalScale != 1.0f) {
        for (int i = 0; i < totalStereoSamples; i++) {
            outputBuffer[i] *= finalScale;
        }
    }
}

void normalize_signal(float* signal, int numSamples, float targetPeak) {
    if (numSamples <= 0 || targetPeak <= 0.0f) return;
    
    float maxAmp = 0.0f;
    for (int i = 0; i < numSamples; i++) {
        float absVal = std::abs(signal[i]);
        if (absVal > maxAmp) maxAmp = absVal;
    }
    
    if (maxAmp > 0.0f) {
        float scale = targetPeak / maxAmp;
        for (int i = 0; i < numSamples; i++) {
            signal[i] *= scale;
        }
    }
}

void render_sequenced_audio(
    int* offsets,
    int* instrumentIds,
    float* velocities,
    float* params,
    int numTriggers,
    float baseFreq,
    float sampleRate,
    int totalSamples,
    float* outputBuffer
) {
    if (totalSamples <= 0 || sampleRate <= 0) return;
    std::fill(outputBuffer, outputBuffer + totalSamples, 0.0f);

    // Track which instruments are actually present in this sequence
    bool useDayan = false, useBayan = false, useKick = false, useSnare = false;
    bool useHiHat = false, useTom = false, useRide = false, useBell = false, useBowl = false;
    for (int i = 0; i < numTriggers; i++) {
        switch (instrumentIds[i]) {
            case 0: useDayan = true; break;
            case 1: useBayan = true; break;
            case 2: useKick = true; break;
            case 3: useSnare = true; break;
            case 4: useHiHat = true; break;
            case 5: useTom = true; break;
            case 6: useRide = true; break;
            case 7: useBell = true; break;
            case 8: useBowl = true; break;
        }
    }

    // Initialize ONLY needed instruments
    FaustDayan* dayan = useDayan ? new FaustDayan(sampleRate) : nullptr;
    FaustBayan* bayan = useBayan ? new FaustBayan(sampleRate) : nullptr;
    FaustKick* kick = useKick ? new FaustKick(sampleRate) : nullptr;
    FaustSnare* snare = useSnare ? new FaustSnare(sampleRate) : nullptr;
    FaustHiHat* hihat = useHiHat ? new FaustHiHat(sampleRate) : nullptr;
    FaustTom* tom = useTom ? new FaustTom(sampleRate) : nullptr;
    FaustRide* ride = useRide ? new FaustRide(sampleRate) : nullptr;
    FaustBell* bell = useBell ? new FaustBell(sampleRate) : nullptr;
    FaustBowl* bowl = useBowl ? new FaustBowl(sampleRate) : nullptr;

    if (dayan) dayan->setFrequency(baseFreq);
    if (bayan) bayan->setFrequency(baseFreq);
    if (bell) bell->setFrequency(baseFreq);
    if (bowl) bowl->setFrequency(baseFreq);

    int currentSample = 0;
    int triggerIdx = 0;
    float* temp = new float[4096]; // Reuse a reasonably sized block
    int tempSize = 4096;

    while (currentSample < totalSamples) {
        while (triggerIdx < numTriggers && offsets[triggerIdx] <= currentSample) {
            int instId = instrumentIds[triggerIdx];
            float vel = velocities[triggerIdx];
            float p = params[triggerIdx];

            if (instId == 0 && dayan) { dayan->setMute(p > 0.5f); dayan->strike(vel); }
            else if (instId == 1 && bayan) { 
                bayan->setMute(p > 0.5f && p < 1.0f); // Fix: Mute only if specifically 1.0, not for meend > 1.0
                if (p >= 1.0f) bayan->setMeend(p); 
                bayan->strike(vel); 
            }
            else if (instId == 2 && kick) kick->strike(vel);
            else if (instId == 3 && snare) snare->strike(vel);
            else if (instId == 4 && hihat) hihat->strike(vel);
            else if (instId == 5 && tom) tom->strike(vel);
            else if (instId == 6 && ride) ride->strike(vel);
            else if (instId == 7 && bell) {
                if (p > 20.0f) bell->setFrequency(p); // Optional: param as frequency override
                bell->strike(vel);
            }
            else if (instId == 8 && bowl) {
                if (p > 20.0f) bowl->setFrequency(p);
                bowl->strike(vel);
            }
            triggerIdx++;
        }

        int nextTrigger = (triggerIdx < numTriggers) ? offsets[triggerIdx] : totalSamples;
        int chunkLen = nextTrigger - currentSample;
        if (chunkLen <= 0) chunkLen = 1;
        if (currentSample + chunkLen > totalSamples) chunkLen = totalSamples - currentSample;

        if (chunkLen > 0) {
            if (chunkLen > tempSize) {
                delete[] temp;
                temp = new float[chunkLen];
                tempSize = chunkLen;
            }
            
            // Render and accumulate ONLY active instruments
            if (dayan) { dayan->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (bayan) { bayan->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (kick) { kick->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (snare) { snare->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (hihat) { hihat->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (tom) { tom->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (ride) { ride->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (bell) { bell->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (bowl) { bowl->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
        }
        currentSample += chunkLen;
    }

    delete[] temp;
    if (dayan) delete dayan; if (bayan) delete bayan;
    if (kick) delete kick; if (snare) delete snare; if (hihat) delete hihat; if (tom) delete tom; if (ride) delete ride;
    if (bell) delete bell; if (bowl) delete bowl;

    // Normalization
    float maxAmp = 0.0f;
    for (int i = 0; i < totalSamples; i++) {
        float a = std::abs(outputBuffer[i]);
        if (a > maxAmp) maxAmp = a;
    }
    if (maxAmp > 0.0f) {
        float scale = 1.0f / maxAmp;
        for (int i = 0; i < totalSamples; i++) outputBuffer[i] *= scale;
    }
}

void render_automation_sequence(
    FaustEvent* events,
    int numEvents,
    float sampleRate,
    int totalSamples,
    float* outputBuffer
) {
    if (totalSamples <= 0 || sampleRate <= 0) return;
    std::fill(outputBuffer, outputBuffer + totalSamples, 0.0f);

    // Track which instruments are present
    bool useDayan = false, useBayan = false, useKick = false, useSnare = false;
    bool useHiHat = false, useTom = false, useRide = false, useBell = false, useBowl = false;
    bool useSitar = false, useFlute = false, useTanpura = false;
    for (int i = 0; i < numEvents; i++) {
        switch (events[i].instrumentId) {
            case 0: useDayan = true; break;
            case 1: useBayan = true; break;
            case 2: useKick = true; break;
            case 3: useSnare = true; break;
            case 4: useHiHat = true; break;
            case 5: useTom = true; break;
            case 6: useRide = true; break;
            case 7: useBell = true; break;
            case 8: useBowl = true; break;
            case 9: useSitar = true; break;
            case 10: useFlute = true; break;
            case 11: useTanpura = true; break;
        }
    }

    FaustDayan* dayan = useDayan ? new FaustDayan(sampleRate) : nullptr;
    FaustBayan* bayan = useBayan ? new FaustBayan(sampleRate) : nullptr;
    FaustKick* kick = useKick ? new FaustKick(sampleRate) : nullptr;
    FaustSnare* snare = useSnare ? new FaustSnare(sampleRate) : nullptr;
    FaustHiHat* hihat = useHiHat ? new FaustHiHat(sampleRate) : nullptr;
    FaustTom* tom = useTom ? new FaustTom(sampleRate) : nullptr;
    FaustRide* ride = useRide ? new FaustRide(sampleRate) : nullptr;
    FaustBell* bell = useBell ? new FaustBell(sampleRate) : nullptr;
    FaustBowl* bowl = useBowl ? new FaustBowl(sampleRate) : nullptr;
    FaustSitar* sitar = useSitar ? new FaustSitar(sampleRate) : nullptr;
    FaustFlute* flute = useFlute ? new FaustFlute(sampleRate) : nullptr;
    FaustTanpura* tanpura = useTanpura ? new FaustTanpura(sampleRate) : nullptr;

    int currentSample = 0;
    int eventIdx = 0;
    float* temp = new float[4096];
    int tempSize = 4096;

    while (currentSample < totalSamples) {
        while (eventIdx < numEvents && events[eventIdx].sampleOffset <= currentSample) {
            FaustEvent& ev = events[eventIdx];
            int instId = ev.instrumentId;
            float val = ev.value;
            
            if (ev.eventType == 0) { // Strike
                if (instId == 0 && dayan) dayan->strike(val);
                else if (instId == 1 && bayan) bayan->strike(val);
                else if (instId == 2 && kick) kick->strike(val);
                else if (instId == 3 && snare) snare->strike(val);
                else if (instId == 4 && hihat) hihat->strike(val);
                else if (instId == 5 && tom) tom->strike(val);
                else if (instId == 6 && ride) ride->strike(val);
                else if (instId == 7 && bell) bell->strike(val);
                else if (instId == 8 && bowl) bowl->strike(val);
                else if (instId == 9 && sitar) sitar->pluck(val);
                else if (instId == 11 && tanpura) {
                    // Tanpura strike uses val as string index (0-3)
                    int sIdx = (int)val;
                    tanpura->pluck(sIdx, 0.8f); 
                }
            } 
            else if (ev.eventType == 1) { // SetFreq
                if (instId == 0 && dayan) dayan->setFrequency(val);
                else if (instId == 1 && bayan) bayan->setFrequency(val);
                else if (instId == 5 && tom) tom->setFrequency(val);
                else if (instId == 7 && bell) bell->setFrequency(val);
                else if (instId == 8 && bowl) bowl->setFrequency(val);
                else if (instId == 9 && sitar) sitar->setFrequency(val);
                else if (instId == 10 && flute) flute->setFrequency(val);
                else if (instId == 11 && tanpura) {
                    // For Tanpura, we use paramId as string index in SetFreq too?
                    // Let's use a convention: if eventType 1 and paramId is 0-3
                    tanpura->setFrequency(ev.paramId, val);
                }
            }
            else if (ev.eventType == 2) { // SetParam
                if (instId == 0 && dayan) {
                    if (ev.paramId == 0) dayan->setMute(val > 0.5f);
                } else if (instId == 1 && bayan) {
                    if (ev.paramId == 0) bayan->setMute(val > 0.5f);
                    else if (ev.paramId == 1) bayan->setMeend(val);
                } else if (instId == 4 && hihat) {
                    if (ev.paramId == 0) hihat->setOpenness(val);
                } else if (instId == 7 && bell) {
                    if (ev.paramId == 0) bell->setDamping(val);
                } else if (instId == 8 && bowl) {
                    if (ev.paramId == 0) bowl->setRub(val);
                    else if (ev.paramId == 1) bowl->setWaver(val);
                } else if (instId == 9 && sitar) {
                    if (ev.paramId == 0) sitar->setJivari(val);
                } else if (instId == 10 && flute) {
                    if (ev.paramId == 0) flute->setPressure(val);
                    else if (ev.paramId == 1) flute->setVibrato(5.5f, val);
                } else if (instId == 11 && tanpura) {
                    if (ev.paramId == 10) tanpura->setJivari(val); // Global Jivari
                }
            }
            eventIdx++;
        }

        int nextEventOffset = (eventIdx < numEvents) ? events[eventIdx].sampleOffset : totalSamples;
        int chunkLen = nextEventOffset - currentSample;
        if (chunkLen <= 0) chunkLen = 1;
        if (currentSample + chunkLen > totalSamples) chunkLen = totalSamples - currentSample;

        if (chunkLen > 0) {
            if (chunkLen > tempSize) {
                delete[] temp;
                temp = new float[chunkLen];
                tempSize = chunkLen;
            }
            
            if (dayan) { dayan->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (bayan) { bayan->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (kick) { kick->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (snare) { snare->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (hihat) { hihat->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (tom) { tom->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (ride) { ride->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (bell) { bell->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (bowl) { bowl->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (sitar) { sitar->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (flute) { flute->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
            if (tanpura) { tanpura->render(chunkLen, temp); for(int i=0; i<chunkLen; i++) outputBuffer[currentSample + i] += temp[i]; }
        }
        currentSample += chunkLen;
    }

    delete[] temp;
    if (dayan) delete dayan; if (bayan) delete bayan;
    if (kick) delete kick; if (snare) delete snare; if (hihat) delete hihat; if (tom) delete tom; if (ride) delete ride;
    if (bell) delete bell; if (bowl) delete bowl;
    if (sitar) delete sitar; if (flute) delete flute;
    if (tanpura) delete tanpura;

    // Normalization
    float maxAmp = 0.0f;
    for (int i = 0; i < totalSamples; i++) {
        float a = std::abs(outputBuffer[i]);
        if (a > maxAmp) maxAmp = a;
    }
    if (maxAmp > 0.0f) {
        float scale = 1.0f / maxAmp;
        for (int i = 0; i < totalSamples; i++) outputBuffer[i] *= scale;
    }
}

}
