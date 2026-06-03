declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Generates highly realistic insect/cricket chirping sounds using high-frequency pulse amplitude modulation.
//
// Parameters (Controls):
//   - gain
//   - rate
//   - freq
//   - gate
// =============================================================================
import("stdfaust.lib");

gain  = hslider("gain",  0.5,  0,    1,    0.01) : si.smoo;
rate  = hslider("rate",  3.0,  1.0,  8.0,  0.1);        // chirp rate (chirps/sec)
freq  = hslider("freq",  4500, 3000, 6000, 1.0)  : si.smoo; // cricket carrier frequency
gate  = button("gate");

// 1. Chirp phasor (0 to 1)
chirpPhase = os.phasor(1, rate);

// 2. Determine active chirp zone (first 40% of the period)
chirpActive = chirpPhase < 0.4;
localPhase  = chirpPhase / 0.4;

// 3. Within the active zone, create 4 distinct pulses (wing rubs)
numPulses = 4;
pulseIndex = localPhase * numPulses;
pulseFrac  = pulseIndex - int(pulseIndex);

// Each pulse is shaped with a half-sine envelope lasting 70% of the pulse slot
pulseOn    = pulseFrac < 0.7;
pulseEnv   = ba.if(pulseOn, sin(pulseFrac / 0.7 * ma.PI), 0.0);

// 4. Overall chirp shape (swells and decays across the 4 pulses)
chirpEnv   = sin(localPhase * ma.PI);

// 5. Combine envelopes
totalEnv   = ba.if(chirpActive, pulseEnv * chirpEnv, 0.0);

// 6. Carrier: Pure sine wave (cricket wings act as resonators producing clean sine tones)
//    We add a tiny bit of second harmonic for a slight metallic/crystalline edge.
carrier    = os.osc(freq) * 0.90 + os.osc(freq * 2.0) * 0.10;

// 7. Gate and gain control
running    = gate > 0.0;
process    = carrier * totalEnv * ba.if(running, 1.0, 0.0) * gain;
