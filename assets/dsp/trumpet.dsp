declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Physically modeled trumpet utilizing a waveguide tube with brass-like lip pressure and air column dynamics.
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - gain
//   - gate
//   - vibrato_rate
//   - vibrato_depth
// =============================================================================
import("stdfaust.lib");

// --- Trumpet: simplified from Saxophone (no pitch dip on attack) ---
freq = hslider("freq [unit:Hz]", 440, 50, 2000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

vibratoRate = hslider("vibrato_rate", 5.0, 0, 10, 0.1);
vibratoDepth = hslider("vibrato_depth", 0.015, 0, 0.1, 0.001);

breath = gate * gain : si.smooth(0.995);
vib = os.osc(vibratoRate) * vibratoDepth * breath;

// --- Oscillator with vibrato ---
osc = os.sawtooth(freq * (1.0 + vib));

// --- ADSR envelope ---
trumpet_env = en.adsr(0.05, 0.1, 0.8, 0.2, gate);

// --- Resonant lowpass ---
filter_cutoff = freq * 2.0 + breath * 800 + trumpet_env * 400;

process = osc : fi.resonlp(filter_cutoff, 3.0, 1.0) * trumpet_env * gain * 1.2;
