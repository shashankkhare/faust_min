declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;
size = hslider("size", 0.5, 0, 1, 0.01) : si.smoo; // 0 = gentle trickle with long gaps, 1 = roaring falls
gate = button("gate");

// 1. Organic Surge Generator (combining prime-ratio LFOs to avoid repeating patterns)
lfo1 = os.osc(0.043) * 0.5 + 0.5; // ~23s cycle
lfo2 = os.osc(0.071) * 0.5 + 0.5; // ~14s cycle
lfo3 = os.osc(0.113) * 0.5 + 0.5; // ~9s cycle
surge = (lfo1 * 0.5 + lfo2 * 0.35 + lfo3 * 0.15);

// 2. Dynamic Thresholding to create gaps
// At size=0 (gentle trickle), thresh is 0.6 -> surge must exceed 0.6, leaving long silent gaps.
// At size=1 (roaring falls), thresh is 0.2 -> surge is almost always active, continuous flow.
thresh = 0.60 - (size * 0.40);
env = max(0.0, surge - thresh) / (1.0 - thresh + 0.001);
waterEnv = pow(env, 2.5) : si.smoo; // Exponential curve for natural swell/decay shape

// 3. Slow spectral color modulation (filters shift slowly over time)
cutoffMod = os.osc(0.052) * 0.2 + 1.0; // +/- 20% variation at 19s cycle
rumbleCutoff = max(40.0, (80.0 + size * 220.0) * cutoffMod);
bodyCutoff = max(300.0, (1000.0 + size * 1500.0) * cutoffMod);

// 4. Multi-band Noise Generation
// Low rumble (50–300 Hz)
rumble = no.noise : fi.lowpass(3, rumbleCutoff) * (0.05 + size * 0.7);

// Main cascading body (200–2500 Hz)
body = no.noise : fi.lowpass(2, bodyCutoff) : fi.highpass(2, 200.0) * 0.6;

// High mist/spray (3000 Hz+)
spray = no.noise : fi.highpass(3, 3000.0) : fi.lowpass(1, 12000.0) * (0.15 + (1.0 - size) * 0.25);

// 5. Combine bands and apply the dynamic surge envelope
rawMix = (rumble + body + spray) * waterEnv;

// 6. Gate and Master Gain
running = gate > 0.0;
process = rawMix : fi.dcblocker * ba.if(running, 1.0, 0.0) * gain;
