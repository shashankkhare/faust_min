import("stdfaust.lib");

freq = hslider("freq [unit:Hz]", 440, 20, 4000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");

sustain = hslider("sustain", 0.8, 0, 1, 0.01);
stiffness = hslider("stiffness", 0.1, 0, 1, 0.01);
hardness = hslider("hardness", 0.5, 0, 1, 0.01);

// Harder hammer response based on velocity
env = en.adsr(0.001, 0.1, sustain, 1.0, gate);
hammer = (gate : ba.impulsify) : fi.lowpass(1, 2000 + (hardness * velocity) * 8000) * velocity;

del = ma.SR / freq;
pianoLoop = hammer : + ~ (de.fdelay(4096, del) : fi.lowpass(1, 4000 - stiffness * 1000) : _ * 0.99);

process = pianoLoop * env * gain * 30.0;
