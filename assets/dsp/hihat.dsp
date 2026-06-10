declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// 8-mode inharmonic modal bank + per-strike excitation
//
// strike: 0 = closed-hat (ch), 1 = open-hat (oh), 2 = foot-chick (fc)
// size: cymbal diameter in inches (12-16), scales modal frequencies
// =============================================================================
import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
strike = hslider("strike", 0, 0, 2, 1);
size = hslider("size", 14, 12, 16, 1);
gate = button("gate");

freq_scale = 14.0 / size;

// Inharmonic mode frequencies at 14" reference
f1 = 80.0 * freq_scale;   bw1 = f1 / 40.0;  a1 = 0.8;
f2 = 180.0 * freq_scale;  bw2 = f2 / 50.0;  a2 = 0.6;
f3 = 350.0 * freq_scale;  bw3 = f3 / 60.0;  a3 = 0.5;
f4 = 600.0 * freq_scale;  bw4 = f4 / 60.0;  a4 = 0.4;
f5 = 900.0 * freq_scale;  bw5 = f5 / 50.0;  a5 = 0.3;
f6 = 1300.0 * freq_scale; bw6 = f6 / 40.0;  a6 = 0.2;
f7 = 1800.0 * freq_scale; bw7 = f7 / 30.0;  a7 = 0.1;
f8 = 2400.0 * freq_scale; bw8 = f8 / 20.0;  a8 = 0.05;

// Per-strike parameters
// openness determines body decay (ch=short, oh=long, fc=short)
openness = ba.selectn(3, strike, 0.15, 0.85, 0.05);
decay = 0.5 + openness * 2.0;

// Noise coloring per strike
// ch=moderate HPF for bright wash, oh=full spectrum, fc=low thump
noise_hpf = ba.selectn(3, strike, 2000.0, 50.0, 50.0);
// noise level per strike (drives both modal excitation and direct wash)
noise_amp = ba.selectn(3, strike, 0.3, 0.6, 0.8);
// stick impulse amplitude per strike (fc = 0)
impulse_amp = ba.selectn(3, strike, 1.0, 1.0, 0.0);
// lowpass for fc thump
thump_lp = ba.selectn(3, strike, 20000.0, 20000.0, 400.0);
// Direct wash level (not through modal bank — gives sustained rattle)
wash_level = ba.selectn(3, strike, 0.08, 0.3, 0.0);

// Rising edge trigger only (no click on gate-off)
trig = max(0.0, gate - gate' @ 1);
impulse = trig * impulse_amp;

// Noise for contact/wash rattle
raw_noise = no.noise * noise_amp;
noise_env = en.asr(0.001, 1.0, 0.02, gate);
// HP + LP cascade for modal excitation
noise_colored = raw_noise : fi.highpass(2, noise_hpf) : fi.lowpass(2, thump_lp);

// Direct noise wash (sustained rattle without modal filtering)
wash_noise = raw_noise : fi.highpass(2, 3000);
wash = wash_noise * noise_env * wash_level;

// Combined excitation for modal bank: impulse + colored noise
exc = impulse + noise_colored * noise_env * 0.5;

// Modal bank: sum of 8 resonant bandpass filters
modes = _ <: (fi.resonbp(f1, bw1, a1),
             fi.resonbp(f2, bw2, a2),
             fi.resonbp(f3, bw3, a3),
             fi.resonbp(f4, bw4, a4),
             fi.resonbp(f5, bw5, a5),
             fi.resonbp(f6, bw6, a6),
             fi.resonbp(f7, bw7, a7),
             fi.resonbp(f8, bw8, a8)) :> _;

// Output envelope for overall decay shaping
env = en.asr(0.001, 1.0, decay, gate);
process = ((exc : modes) + wash) * env * gain * velocity * 6.0;

