declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// =======================================================================================
// LAG NGA PHYSICAL MODEL (TWO-SIDED CLOSED BARREL DRUM)
// =======================================================================================
//
// ACOUSTIC RANGE SUMMARY:
// - Optimal Range: 120.0 Hz to 400.0 Hz (D2 to G4).
// - Lower Bound (120 Hz): Deep bass register. Long resonator delay lines may cause slow
//   buildup at the very lowest pitches; use a basefreq of 180+ Hz for best attack punch.
// - Higher Bound (400 Hz): Tight, high-pitched skin tension register typical of smaller
//   Lag Nga frames struck with a thin wooden stick.
//
// PHYSICAL ACOUSTICS:
// - Two-Headed Coupling: The two tensioned membranes couple through the enclosed air column
//   inside the barrel. This produces a characteristic SYMMETRIC + ANTISYMMETRIC mode pair
//   at the fundamental: the symmetric mode (both heads in-phase) sits at 1.00x, and the
//   antisymmetric mode (heads out-of-phase, raised by air stiffness) sits at ~1.035x.
//   This slight split is the defining acoustic character of closed two-headed drums.
// - Bessel Membrane Modes: The standard circular membrane Bessel function ratios are used
//   for higher modes: T01=1.00, T11=1.593, T21=2.136, T02=2.295.
// - Barrel Air Column: The enclosed air between the two heads resonates at approximately
//   0.80x the membrane fundamental, adding a characteristic woody sub-body coupling.
// - Hard Curved Stick: The wooden mallet excitation is modeled as a bandpass impulse
//   (80 Hz highpass, 700–2800 Hz lowpass) giving a sharp, bright attack transient.
// - Short Decay: As a tight, closed drum, T60 is 0.22s for the fundamental and
//   much shorter for overtones — reflecting the high internal air damping of the barrel.
//
// CONTROL PARAMETERS:
// - freq:            Target pitch in Hz. Controls membrane fundamental frequency.
// - gain:            Output level multiplier (0.0–2.0).
// - velocity:        Strike force (0.0–1.0). Scales excitation amplitude linearly.
// - gate:            Triggers a new strike on each 0→1 transition.
// - mallet_softness: Stick hardness (0.0=hard wood, 1.0=padded). Controls excitation
//                    lowpass cutoff (2800 Hz hard → 700 Hz soft). Affects attack brightness.
// =======================================================================================

freq            = hslider("freq [unit:Hz]", 220.0, 120.0, 400.0, 0.1);
gain            = hslider("gain", 1.0, 0.0, 2.0, 0.01);
velocity        = hslider("velocity", 1.0, 0.0, 1.0, 0.01);
gate            = button("gate");
mallet_softness = hslider("mallet_softness", 0.3, 0.0, 1.0, 0.01); // 0=hard wood, 1=padded

// Use Faust's highly stable physical modeling mode filter (avoids denormal distortion at tail end)
resonator(f, t60, g, x) = x : pm.modeFilter(f, t60, g);

trig = gate : ba.impulsify;

// EXCITATION: Hard curved wooden stick — sharp transient with high-frequency presence
// Highpass at 80 Hz removes DC thump. Lowpass cutoff ranges from 700 Hz (soft) to 2800 Hz (hard).
stickCutoff = 2800.0 - mallet_softness * 2100.0;
excitation  = trig * velocity * 0.18 * (freq / 220.0)
            : fi.highpass(1, 150.0)
            : fi.lowpass(2, max(400.0, stickCutoff));

// PITCH ENVELOPE: Tighter membrane means a faster, smaller pitch dip (2% drop)
pitch_env = en.ar(0.001, 0.008, trig);
dyn_freq  = freq * (1.0 - 0.02 * pitch_env);

// SYMMETRIC MODES — both heads moving in-phase (standard Bessel circular membrane ratios)
// Tighter tension means shorter decay times, but extended significantly for proper ring
sym1 = resonator(dyn_freq * 1.000, 0.85, 1.00, excitation); // T01 — primary fundamental
sym2 = resonator(dyn_freq * 1.593, 0.45, 0.32, excitation); // T11 — second Bessel mode
sym3 = resonator(dyn_freq * 2.136, 0.25, 0.12, excitation); // T21 — third Bessel mode
sym4 = resonator(dyn_freq * 2.295, 0.18, 0.07, excitation); // T02 — breathing mode

// ANTISYMMETRIC MODES — heads moving out-of-phase
// In a short, shallow hand drum (Lag Nga), the very small air volume acts as a highly stiff air spring.
// This pushes the antisymmetric mode significantly higher than the symmetric mode (e.g. +18%).
// This large split creates the tight, "clonky" bite of a shallow drum.
ant1 = resonator(dyn_freq * 1.180, 0.60, 0.60, excitation); // Antisymmetric T01 (strongly raised by stiff air cavity)
ant2 = resonator(dyn_freq * 1.720, 0.22, 0.18, excitation); // Antisymmetric T11

// SHALLOW DRUM BODY (AIR CAVITY)
// A short drum has a very high cavity resonance frequency (c / 2*L is high).
// It acts as a high-frequency woody "clonk" rather than a deep sub-bass rumble.
body = resonator(dyn_freq * 3.80, 0.30, 0.25, excitation);

drum_mix = sym1 + sym2 + sym3 + sym4 + ant1 + ant2 + body;

// Soft tanh saturation models membrane nonlinearity on hard strike.
// Lowpass extended to 8x fundamental so it doesn't muffle the bright wooden stick attack.
// Using softer drive (5.0 instead of 10.0) to prevent overdrive/clipping at the tail end.
process = (drum_mix * 2.0 : ma.tanh : fi.lowpass(1, freq * 8.0)) * (gain * 6.0);
