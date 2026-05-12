import("stdfaust.lib");

// --- Dedicated HiHat Cymbal ---
gain = hslider("gain", 0.5, 0, 1, 0.01);
openness = hslider("openness", 0.2, 0, 1, 0.01);
gate = button("gate");

// Scalable short/long release based on openness parameter
decay = 0.05 + openness * 0.4;
env = en.ar(0.001, decay, gate);

// Highpass filtered metallic noise cluster
hat = no.noise : fi.highpass(2, 6000) * env;

process = hat * gain;
