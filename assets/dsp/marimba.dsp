declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Wooden bar mallet instrument (Marimba) modeled using waveguide bars coupled to resonator tubes with strike hardness and position controls.
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

// --- Physical Modeling Marimba ---
// Documented Parameters:
// - freq: Fundamental pitch frequency of the wood bar and resonator tube (Hz).
// - gain: Overall output volume/amplitude scaling.
// - velocity: Strike velocity (maps to internal excitation gain).
// - gate: Note trigger (1-sample impulse generated on rising edge).
// - position: Strike position along the bar (0 to 4, representing nodes to center/edges).
// - strike: Strike sharpness (0 = soft felt mallet, 1 = hard plastic/wood mallet).
//           Internally modulates both excitation filter cutoff and mallet sharpness.

// UI Controls
freq = hslider("freq", 220, 50, 1500, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01) : si.smoo;
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");
position = hslider("position", 2.0, 0, 4, 0.01) : si.smoo;
strike = hslider("strike", 0.5, 0, 1, 0.01) : si.smoo;

// Generate trigger pulse from gate rising edge
trig = (gate > 0) & (gate' <= 0);

// Dynamic mapping of strike parameter to internal physical parameters
strikeCutoff = 1000.0 + strike * 15000.0;
strikeSharpness = 0.1 + strike * 0.9;

// Use the physical modeling library's marimba model
process = pm.marimba(freq, position, strikeCutoff, strikeSharpness, velocity, trig) * gain;
