declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Dramatic environmental thunder simulation using low-frequency saturated rumble filters.
//
// Parameters (Controls):
//   - gain
//   - gate
// =============================================================================
import("stdfaust.lib");

gain = hslider("gain", 1.0, 0, 1, 0.01);
gate = button("gate");

// 1. Saturated Rumble (Adding harmonics makes the low-end audible on small speakers)
rumble_env = en.ar(0.01, 4.5, gate);
rumble_raw = no.pink_noise : fi.lowpass(2, 200);
rumble_sat = ma.tanh(rumble_raw * 25.0); // True soft clipping for warm thunderous harmonics
rumble = rumble_sat * rumble_env * 0.8;

// 2. Mid "Roar" (The rolling, tearing sound of thunder)
roar_env = en.ar(0.1, 3.5, gate);
roar = no.pink_noise : fi.resonbp(400, 2.0, 1.0) * roar_env * 0.6;

// 3. Initial High-Frequency Crack
crack_env = en.ar(0.001, 0.6, gate);
crack = no.noise : fi.highpass(2, 800) * crack_env * 1.5;

src = rumble + roar + crack;

// Rolling delay effect to simulate echoes through clouds
// 24000 samples = 500ms delay for massive rolling thunder scale
echoes = src : + ~ (de.delay(96000, 24000) * 0.5 : fi.lowpass(1, 400));

// Massive cavernous reverb for the boom
thunder = (src + echoes * 0.7) <: re.zita_rev1_stereo :> +;

process = (ma.tanh(thunder * 0.8)) * gain;
