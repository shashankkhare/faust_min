import("stdfaust.lib");

// --- Authentic Tibetan Singing Bowl (Physical Model) ---
// Based on Modal Synthesis with detuned Doublets for slow beating and physical realism.
// Explicit parallel biquad resonator channels guarantee 100% cross-version Faust compilation stability.

// Controls
freq = hslider("freq [unit:Hz]", 220, 100, 1000, 0.01);
gain = hslider("gain", 0.6, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");
rub = hslider("rub", 0, 0, 1, 0.01);

trig = gate > gate';

// Mallet Excitation: Soft-felt mallet contact burst (15ms)
mallet_env = loop_mallet ~ _ with {
    g = exp(-1.0 / (0.015 * ma.SR));
    loop_mallet(s) = ba.if(trig, 4.5, s * g);
};
excitation_strike = (no.noise : fi.lowpass(1, freq * 1.5)) * mallet_env;

// Rub Excitation: Continuous friction noise band-pass filtered around fundamental
excitation_rub = (no.noise * rub * 0.04) : fi.bandpass(2, freq * 1.0, 2.0);

excitation = excitation_strike + excitation_rub;

// Parallel resonant doublet filters (Singing Bowl modal doublets)
// Maps the decay time parameter 't' to the correct Q-factor: Q = PI * f * t
mode(r, t, g) = excitation : fi.resonbp(freq * r, q, g) with {
    q = ma.PI * freq * r * t;
};

// Doublet pairs create the beautiful, organic acoustic beating and "wah-wah" sweep
m1 = mode(1.000, 7.0, 1.0);
m2 = mode(1.002, 6.8, 1.0);  // Fundamental doublet
m3 = mode(2.780, 4.5, 0.5);
m4 = mode(2.785, 4.3, 0.5);  // Mid partial doublet
m5 = mode(5.210, 2.8, 0.25);
m6 = mode(5.215, 2.6, 0.25); // High partial doublet
m7 = mode(8.400, 1.2, 0.1);
m8 = mode(8.410, 1.0, 0.1);  // High shimmer doublet

// Low-frequency warm body resonance
body = excitation : fi.lowpass(2, freq * 1.2) * 0.15;

// Output summation with highly linear scaling (no saturation/clipping)
bowl = (m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + body) * 0.85;

// Completely linear output scaling to preserve pure sinusoidal ring
process = bowl * gain * velocity;
