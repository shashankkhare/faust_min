declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Physical modeling of hand shakers/cabasa using a particle collision model with variable decay and resonance.
//
// Parameters (Controls):
//   - freq
//   - gain
//   - velocity
//   - gate
//   - decay
// =============================================================================
import("stdfaust.lib");

// --- Physical Modeling Shaker / Cabasa ---
// Documented Parameters:
// - freq: Resonance peak center frequency (Hz)
// - gain: Overall output volume/amplitude scaling
// - velocity: Strike velocity (controls peak volume)
// - gate: Note trigger (1-sample impulse generated on rising edge)
// - decay: Decay time of the shaker hit (seconds)

freq = hslider("freq", 3000.0, 500, 12000, 1) : si.smoo;
gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;
velocity = hslider("velocity", 0.5, 0, 1, 0.01) : si.smoo;
gate = button("gate");
decay = hslider("decay", 0.06, 0.01, 0.5, 0.01) : si.smoo;

// Generate trigger pulse from gate rising edge
trig = (gate > 0) & (gate' <= 0);

// Exponential decay envelope for the shaker hit (fast 1ms attack)
env = en.ar(0.001, decay, trig);

// Shaker noise source (white noise) scaled by velocity
noise_source = no.noise * env * velocity;

// Bandpass filter to shape the shaker sound (metallic/crisp)
// Q factor = 1.2 gives a balanced, airy but resonant shaker/cabasa sound
shaker_filtered = noise_source : fi.resonbp(freq, 1.2, 1.0);

// Highpass filter at 1200Hz to remove low-end rumble and keep it crisp
process = (shaker_filtered : fi.highpass(2, 1200.0)) * gain;
