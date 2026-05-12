import("stdfaust.lib");

// --- Physical Model Piano ---
freq = hslider("freq [unit:Hz]", 440, 20, 4000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

// Expressive tone settings
sustain = hslider("sustain", 0.8, 0, 1, 0.01);
stiffness = hslider("stiffness", 0.1, 0, 1, 0.01);
hardness = hslider("hardness", 0.5, 0, 1, 0.01);

// Waveguide layout with lowpass loop modeling hammer strikes
env = en.adsr(0.005, 0.2, sustain, 1.0, gate);
hammer = gate : ba.impulsify : fi.lowpass(1, 2000 + hardness * 6000);

// Basic dispersive decay loop
pianoLoop = pm.stringSegment(4096, pm.f2l(freq)) : fi.lowpass(1, 4000 - stiffness * 1000);

process = (hammer : pianoLoop) * env * gain * 2.0;
