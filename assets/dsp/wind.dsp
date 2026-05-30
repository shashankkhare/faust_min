import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

env = gate : si.smooth(ba.tau2pole(1.0)); // Very slow fade in/out

// Modulate the cutoff of a bandpass filter with slow LFOs
lfo1 = os.lf_triangle(0.2) * 400 + 600; // Sweeps 200 - 1000
lfo2 = os.lf_triangle(0.05) * 800 + 1000; // Sweeps 200 - 1800

cutoff = lfo1 + lfo2;

wind = no.noise : fi.resonbp(cutoff, 2, 1) : fi.lowpass(2, cutoff * 1.2);

process = (wind * env * 1.5 : min(1.0) : max(-1.0)) * gain;
