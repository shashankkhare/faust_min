declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: West African Djembe drum physically modeled with center/edge position-based resonance and strike mallet sharpness.
//
// Parameters (Controls):
//   - freq
//   - gain
//   - velocity
//   - gate
//   - position
//   - strike
// =============================================================================
import("stdfaust.lib");

// --- Physical Modeling Djembe Drum ---
// Documented Parameters:
// - freq: Fundamental frequency of the drum membrane (Hz).
// - gain: Overall output volume/amplitude scaling.
// - velocity: Strike velocity (maps to internal excitation gain).
// - gate: Note trigger (1-sample impulse generated on rising edge).
// - position: Strike position on the membrane (0 = center/low-bass, 1 = edge/high-ring).
// - strike: Strike sharpness (0 = dull/soft mallet, 1 = sharp/finger slap).

// UI Controls
// Expert Play Range: Djembe bass/tone fundamental typically 80-300 Hz.
freq = hslider("freq", 110.0, 80, 300, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01) : si.smoo;
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");
position = hslider("position", 0.5, 0, 1, 0.01) : si.smoo;
strike = hslider("strike", 0.5, 0, 1, 0.01) : si.smoo;

// Generate trigger pulse from gate rising edge
trig = (gate > 0) & (gate' <= 0);

// Use the physical modeling library's djembe model
process = pm.djembe(freq, position, strike, velocity, trig) * gain;
