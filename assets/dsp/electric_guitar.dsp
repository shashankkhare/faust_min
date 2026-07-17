declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

mypm = library("physmodels.lib") with { maxLength = 20; };

// Expert Play Range: Electric Guitar typical range E2 (82 Hz) to C6 (1046 Hz).
freq = hslider("freq", 196.0, 82, 1046, 0.01);
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gate = button("gate");
gain = hslider("gain", 1.0, 0, 1, 0.01);

pluckPosition = hslider("pluckPosition", 0.5, 0.01, 0.99, 0.01);
mute = hslider("mute", 1.0, 0.0, 1.0, 0.01);

// Distortion and sustain controls
drive = hslider("drive", 0.7, 0, 1, 0.01);
sustain = hslider("sustain", 0.8, 0, 1, 0.01);
pregain = 1.0 + sustain * 19.0;

stringLength = freq : mypm.f2l;

// Boost excitation — elecGuitar model outputs very quiet signal
excBoost = 100;

cabinet = fi.lowpass(2, 4000);

process = mypm.elecGuitar(stringLength, pluckPosition, mute, velocity * excBoost, gate)
        : fi.dcblocker 
        : *(pregain) 
        : ef.cubicnl(drive, 0) 
        : ma.tanh 
        : cabinet 
        : *(gain * 1.33);
