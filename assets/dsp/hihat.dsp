declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Resonant metal Hi-Hat cymbal using high-pass filtered noise bands and closed/open strike decay times.
//
// Parameters (Controls):
//   - gain
//   - velocity
//   - strike
//   - gate
// =============================================================================
import("stdfaust.lib");

// --- Dedicated HiHat Cymbal ---
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
strike = hslider("strike", 0, 0, 3, 1); 
gate = button("gate");

// 0: Closed, 1: Open, 2: Pedal
openness_strike = ba.selectn(4, strike, 0.1, 0.6, 0.05, 0.1);
decay = 0.05 + openness_strike * 0.4;
env = en.ar(0.001, decay, gate);

// Highpass filtered metallic noise cluster
// Velocity increases brightness
hat = no.noise : fi.highpass(2, 6000 + 2000 * velocity) * env * 6.0;

process = hat * gain * velocity * (1.0 + 0.1 * velocity);
