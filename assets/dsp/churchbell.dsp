declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

freq = hslider("freq", 200.0, 100, 1000, 0.1);
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");
gain = hslider("gain", 0.6, 0, 1, 0.01);

trig = gate : ba.impulsify;

// Use standard, safe resonbp filter
// Q = t60 * freq / 2.2 calculates the correct Q for the desired T60 decay
modeFilter(f, t60, g) = fi.resonbp(f, max(1.0, t60 * f / 2.2), g);

churchBell(f, vel) = excitation : _ <: par(i, 7, modeFilter(modeFreqs(i), modeT60s(i), modeGains(i))) :> /(7)
with {
    // True inharmonic church bell ratios
    modeFreqs(0) = f * 0.50;
    modeFreqs(1) = f * 1.00;
    modeFreqs(2) = f * 1.19;
    modeFreqs(3) = f * 1.56;
    modeFreqs(4) = f * 2.00;
    modeFreqs(5) = f * 2.51;
    modeFreqs(6) = f * 3.00;

    modeT60s(0) = 12.5;
    modeT60s(1) = 10.0;
    modeT60s(2) = 7.5;
    modeT60s(3) = 5.0;
    modeT60s(4) = 3.75;
    modeT60s(5) = 2.5;
    modeT60s(6) = 1.25;

    modeGains(0) = 1.0;
    modeGains(1) = 1.0;
    modeGains(2) = 0.8;
    modeGains(3) = 0.6;
    modeGains(4) = 1.0;
    modeGains(5) = 0.4;
    modeGains(6) = 0.2;

    // Simple impulsive click for excitation (much safer than counting samples)
    // A 1-pole lowpass gently mimics the metal-on-metal thud without looping bugs.
    strike = trig * vel * 50.0; // Scaled up to perfectly ring the normalized resonbp
    excitation = strike : fi.lowpass(1, 1500.0);
};

process = churchBell(freq, velocity) : fi.dcblocker : *(gain * 12.25) : ma.tanh;
