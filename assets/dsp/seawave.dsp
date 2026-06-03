declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Ambient generator simulating rolling ocean waves using multi-oscillator pink/white noise filtering and slow LFO sweeps.
//
// Parameters (Controls):
//   - gain
//   - intensity
//   - gate
// =============================================================================
import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;
intensity = hslider("intensity", 0.5, 0, 1, 0.01) : si.smoo;
gate = button("gate");

// Multi-oscillator wave envelope — incommensurate ratios avoid repetition
lfo1 = os.osc(0.031) * 0.5 + 0.5;
lfo2 = os.osc(0.053) * 0.5 + 0.5;
lfo3 = os.osc(0.079) * 0.5 + 0.5;
lfo4 = os.osc(0.109) * 0.5 + 0.5;

waveRaw = lfo1 * 0.3 + lfo2 * 0.3 + lfo3 * 0.25 + lfo4 * 0.15;

// Wave crest threshold — higher intensity = more frequent/wetter waves
thresh = 0.55 - (intensity * 0.40);
crest = max(0.0, waveRaw - thresh) / (1.0 - thresh + 0.001);
waveEnv = pow(crest, 2.0);

// Crash burst at wave peak — a short noise spike when the envelope rises fast
prev = mem(waveEnv);
rise = max(0.0, waveEnv - prev);
crash = no.noise : fi.highpass(3, 2000.0) * (rise * 8.0) * (0.1 + intensity * 0.5);

// Slow spectral sweep for evolving colour
sweep = os.osc(0.043) * 0.25 + 1.0;

// Multi-band noise
rumble = no.noise : fi.lowpass(2, (30.0 + intensity * 120.0) * sweep) * (0.2 + intensity * 0.6);
swash = no.noise : fi.bandpass(3, (400.0 + intensity * 1600.0) * sweep, 0.6) * 0.5;
spray = no.noise : fi.highpass(3, 4000.0) * (0.05 + intensity * 0.2);

// Combine
mix = (rumble + swash + spray) * waveEnv + crash * waveEnv;

running = gate > 0.0;
process = mix : fi.dcblocker * ba.if(running, 1.0, 0.0) * gain;
