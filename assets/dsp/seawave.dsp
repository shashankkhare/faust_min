declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01);
intensity = hslider("velocity", 0.5, 0, 1, 0.01) : si.smoo;
gate = button("gate");

// --- ADSR ENVELOPE ---
attack   = hslider("attack", 2.0, 0.01, 10.0, 0.01);
decay    = hslider("decay",  2.0, 0.01, 10.0, 0.01);
sustain  = hslider("sustain", 0.8, 0.0, 1.0, 0.01);
release  = hslider("release", 2.0, 0.01, 10.0, 0.01);
envelope = en.adsr(attack, decay, sustain, release, gate);

// Multi-oscillator wave envelope
lfo1 = os.osc(0.031) * 0.5 + 0.5;
lfo2 = os.osc(0.053) * 0.5 + 0.5;
lfo3 = os.osc(0.079) * 0.5 + 0.5;
lfo4 = os.osc(0.109) * 0.5 + 0.5;

waveRaw = lfo1 * 0.3 + lfo2 * 0.3 + lfo3 * 0.25 + lfo4 * 0.15;

thresh = 0.55 - (intensity * 0.40);
crest = max(0.0, waveRaw - thresh) / (1.0 - thresh + 0.001);
waveEnv = pow(crest, 2.0);

// Crash burst — only fires on actual rise
prev = mem(waveEnv);
rise = max(0.0, waveEnv - prev);
crash = no.noise : fi.highpass(2, 800.0) * rise * (0.5 + intensity * 0.5);

// Slow spectral sweep
sweep = os.osc(0.043) * 0.25 + 1.0;

// Filtered wave body
body = no.noise : fi.lowpass(2, (80.0 + intensity * 160.0) * sweep) * 0.8;

// Combine
mix = (body + crash) * waveEnv;

process = mix : fi.dcblocker : *(envelope) : *(gain * 15) : ma.tanh;
