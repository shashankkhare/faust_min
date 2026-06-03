declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Large Tibetan ritual kettledrum (Nga Chen) with a hemispherical pot body and single head, producing a deep, sustained sacred boom.
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - gain
//   - velocity
//   - gate
//   - mallet_softness
// =============================================================================
import("stdfaust.lib");

// --- Nga Chen (Tibetan Kettledrum — Hemispherical Pot Body, Single Head) ---
// A large single-headed drum over a hemispherical metal or clay pot resonator.
// Struck with a thick, heavily-padded curved mallet. Used in pairs in Tibetan ritual.
// The enclosed pot acts as a Helmholtz resonator, strongly boosting the fundamental.
// Sound character: deep, sustained boom — like a deep timpani with long sacred ring.

freq           = hslider("freq [unit:Hz]", 75.0, 40.0, 130.0, 0.1);
gain           = hslider("gain", 1.0, 0.0, 2.0, 0.01);
velocity       = hslider("velocity", 1.0, 0.0, 1.0, 0.01);
gate           = button("gate");
mallet_softness = hslider("mallet_softness", 0.8, 0.0, 1.0, 0.01); // 0=hard, 1=very thick padding

// Direct-Form-II 2-pole resonator
resonator(f, t60, g, x) = x * 0.002 : + ~ routing : *(g)
with {
    r     = pow(0.001, 1.0 / (max(0.001, t60) * ma.SR)) * 0.99999;
    omega = 2.0 * ma.PI * f / ma.SR;
    routing(fb) = 2.0 * r * cos(omega) * fb - r * r * fb';
};

trig = gate : ba.impulsify;

// EXCITATION: Thick padded mallet — very soft, deep, low-frequency bloom onset
// mallet_softness=0.8 → heavy felt padding → very low cutoff
malletCutoff = 450.0 - mallet_softness * 400.0;   // Range: 50–450 Hz
excitation   = trig * velocity * 0.16 * (freq / 75.0)
             : fi.lowpass(4, max(50.0, malletCutoff));

// PITCH ENVELOPE: Almost zero — rigid metal/clay pot constrains the membrane significantly
// Unlike a frame drum, the pot walls prevent the membrane from sagging on impact
pitch_env = en.ar(0.003, 0.025, trig);
dyn_freq  = freq * (1.0 - 0.015 * pitch_env);  // Only 1.5% dip — near-rigid constraint

// MEMBRANE MODES — single circular membrane, standard Bessel function ratios
// Upper modes are strongly damped by the pot walls and padded mallet
mem1 = resonator(dyn_freq * 1.000, 2.60, 1.00, excitation); // T01 — fundamental (pot-boosted, very long)
mem2 = resonator(dyn_freq * 1.593, 0.50, 0.15, excitation); // T11 — attenuated by pot rim damping
mem3 = resonator(dyn_freq * 2.136, 0.22, 0.06, excitation); // T21
mem4 = resonator(dyn_freq * 2.295, 0.14, 0.03, excitation); // T02
mem5 = resonator(dyn_freq * 2.653, 0.07, 0.01, excitation); // T31 — barely audible trace

// HELMHOLTZ POT CAVITY — hemispherical pot resonates at a frequency close to the membrane T01
// The enclosed air volume strongly amplifies the fundamental and sustains it
// Helmholtz resonance frequency ≈ (c/2π) * sqrt(A / (V * L_eff))
// In practice for a large pot this lands ~5-10% below the membrane fundamental
pot_helmholtz = resonator(freq * 0.93, 3.50, 0.70, excitation);  // Deep pot ring — longest decay

// AIR COUPLING SUB-HARMONIC — the large enclosed air volume supports a half-frequency mode
// This gives the characteristic very low "rumble" below the main strike
pot_sub       = resonator(dyn_freq * 0.50, 1.40, 0.22, excitation); // Sub-octave air coupling

drum_mix = mem1 + mem2 + mem3 + mem4 + mem5 + pot_helmholtz + pot_sub;

// Very gentle saturation (soft mallet = low membrane nonlinearity)
// Light highpass to remove DC, gentle lowpass at ~4x fundamental for natural body roll-off
process = (drum_mix * 9.0 : ma.tanh : fi.highpass(1, 18.0) : fi.lowpass(2, freq * 4.5)) * (gain * 6.5);
