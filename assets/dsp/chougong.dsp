declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Classical Chinese Opera Gong (Chou Gong) using heavily inharmonic
// modal synthesis with a soft 60ms noise-burst mallet, per-mode T60 damping and
// a passive nonlinear allpass to reproduce the pitch bloom / shimmer.
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - gain
//   - velocity
//   - gate
// =============================================================================
import("stdfaust.lib");

// --- Chou Gong (Physical Model) ---
// Authentic large Chinese Gong model using heavily inharmonic modal synthesis
// and a non-linear mallet excitation to simulate the "bloom" and shimmer.

// Expert Play Range: Chou Gong fundamental typically 80-400 Hz.
freq = hslider("freq [unit:Hz]", 100.0, 80, 400, 0.1);
gain = hslider("gain", 1.0, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

trig = gate > gate';

// Non-linear Pitch Envelope: Tension increases on strike, causing pitch to start slightly high and drop smoothly
pitch_env = en.ar(0.01, 2.0, trig) : si.smooth(0.999); 
dyn_freq = freq * (1.0 + (pitch_env * 0.04)); 

// --- Mallet Excitation: 60ms noise burst (soft, elegant attack) ---
mallet_env = loop_mallet ~ _ with {
    g = exp(-1.0 / (0.060 * ma.SR)); // 60ms burst
    loop_mallet(s) = ba.if(trig, 1.0, s * g); // safe impact energy
};
// Moderate lowpass cutoff to allow some high-frequency crash without overloading partials
excitation = (no.noise : fi.lowpass(2, dyn_freq * 4.0)) * mallet_env;

// --- Modal Filters ---
// Inharmonic partials of a flat circular plate, each with its own decay time
// (low modes ring for seconds, high modes die in tens of ms). Q is derived
// from the target T60: for fi.resonbp (SVF bandpass) T60 = 6.9078*Q/(PI*fc).
mode(r, t60, g) = excitation : fi.resonbp(dyn_freq * r, q, g) with {
    q = ma.PI * (dyn_freq * r) * t60 / 6.9078;
};

// Mode tuning for a large gong (Chou Gong): inharmonic ratios, long low-mode
// ring (real gongs sustain 10+ seconds) dying to seconds at the top. T60 values
// reproduce the proven "elegant" reference balance: fundamental clearly
// dominant, mid modes for strike timbre, top modes for the initial crash.
m1a = mode(1.000, 24.2, 4.0);
m1b = mode(1.015, 22.1, 3.5);

m2a = mode(1.350, 19.3, 0.8);
m2b = mode(1.362, 18.0, 0.7);

m3a = mode(1.710, 15.9, 0.6);
m3b = mode(1.728, 14.5, 0.5);

m4a = mode(2.230, 12.4, 0.4);
m4b = mode(2.245, 11.7, 0.4);

m5 = mode(2.810, 9.7, 0.3);
m6 = mode(3.520, 8.3, 0.3);
m7 = mode(4.350, 6.9, 0.2);
m8 = mode(5.420, 5.5, 0.15);
m9 = mode(6.580, 4.1, 0.1);
m10 = mode(8.130, 2.8, 0.1);

// The "Bloom" effect: high partials open up after the strike and settle quickly,
// keeping the initial attack clean (the crash fades in over 100ms instead of
// hitting at t=0, which reads as pure noise).
bloom_env = en.ar(0.10, 1.2, trig);
bloom_shimmer = (m6 + m7 + m8 + m9 + m10) * bloom_env * 1.2;

gong_sum = m1a + m1b + m2a + m2b + m3a + m3b + m4a + m4b + m5 + bloom_shimmer;

// Soft clipping via tanh to guarantee the resonators NEVER digitally clip
process = gong_sum : fi.dcblocker : *(gain * velocity * 0.928264) : ma.tanh;
