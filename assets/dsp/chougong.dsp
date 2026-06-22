declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Classical Chinese Opera Gong (Chou Gong) using heavily inharmonic modal synthesis and non-linear mallet excitation to simulate pitch bloom and shimmer.
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
// and non-linear mallet excitation to simulate the "bloom" and shimmer.

// Expert Play Range: Chou Gong fundamental typically 80-400 Hz.
freq = hslider("freq [unit:Hz]", 100.0, 80, 400, 0.1);
gain = hslider("gain", 0.6, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

trig = gate > gate';

// Non-linear Pitch Envelope: Tension increases on strike, causing pitch to start slightly high and drop smoothly
pitch_env = en.ar(0.01, 2.0, trig) : si.smooth(0.999); 
dyn_freq = freq * (1.0 + (pitch_env * 0.04)); 

// Mallet Excitation: Safe impulse to prevent biquad blowup
mallet_env = loop_mallet ~ _ with {
    g = exp(-1.0 / (0.020 * ma.SR)); // 20ms burst as requested
    loop_mallet(s) = ba.if(trig, 2.5, s * g); // Safe impact energy
};
// Moderate lowpass cutoff to allow some high-frequency crash without overloading partials
excitation = (no.noise : fi.lowpass(2, dyn_freq * 4.0)) * mallet_env;

// Modal Filters (Inharmonic partials of a flat circular plate)
mode(r, t, g) = excitation : fi.resonbp(dyn_freq * r, q, g) with {
    q = ma.PI * dyn_freq * r * t;
};

// Mode tuning for a large gong (Chou Gong)
// Including DOUBLETS: closely spaced modal pairs that create organic beating/vibrato!
m1a = mode(1.000, 10.0, 4.0); // Boosted back to massive 4.0 for intense initial energy
m1b = mode(1.015, 9.0, 3.5);  

m2a = mode(1.350, 8.0, 0.8);
m2b = mode(1.362, 7.5, 0.7); 

m3a = mode(1.710, 6.5, 0.6);
m3b = mode(1.728, 6.0, 0.5); 

m4a = mode(2.230, 5.0, 0.4);
m4b = mode(2.245, 4.8, 0.4);

m5 = mode(2.810, 3.5, 0.3);
m6 = mode(3.520, 3.0, 0.3);
m7 = mode(4.350, 2.5, 0.2);
m8 = mode(5.420, 2.0, 0.15);
m9 = mode(6.580, 1.5, 0.1);
m10 = mode(8.130, 1.0, 0.1);

// The "Bloom" effect (dynamic high-frequency spread that opens up after strike)
bloom_env = en.ar(0.10, 2.0, trig); // Fast attack (100ms), fast decay (2.0s) for realistic high-freq dissipation
bloom_shimmer = (m6 + m7 + m8 + m9 + m10) * bloom_env * 1.5;

gong_sum = m1a + m1b + m2a + m2b + m3a + m3b + m4a + m4b + m5 + bloom_shimmer;

// Soft clipping via tanh to guarantee the resonators NEVER digitally clip
// Reduced scalar to 0.1 to prevent driving tanh into fuzz/distortion!
process = gong_sum * gain * velocity * 0.1 : ma.tanh;
