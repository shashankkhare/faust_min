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

// Three detuned strings per note for rich acoustic chorus
string(f, detune) = loop
with {
    f_detuned = f * detune;
    del_len = ma.SR / f_detuned;
    loop = hammer : + ~ (de.fdelay(4096, del_len) : fi.lowpass(1, 4000 - stiffness * 1000) : _ * 0.99);
};

pianoStrings = string(freq, 1.0) * 0.4 + string(freq, 1.0006) * 0.3 + string(freq, 0.9994) * 0.3;

// Soundboard sympathetic resonance
soundboard = pianoStrings : + ~ (de.delay(1024, 256) : fi.lowpass(1, 1200) : * (0.25));

process = (pianoStrings + soundboard * 0.3) * env * gain * 30.0;
