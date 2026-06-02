declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// =====================================================
// Realistic Tibetan Singing Bowl (Physical Model)
// =====================================================

freq = hslider("freq", 110, 60, 1000, 0.1) : si.smoo;
velocity = hslider("velocity", 0.8, 0, 1, 0.01) : si.smoo;

// Strike: 0 = Mallet Click, 1 = Continuous Rub
strike = hslider("strike", 0, 0, 1, 1);
gate = button("gate");

gain = hslider("gain", 0.6, 0, 1, 0.01) : si.smoo;

// =====================================================
// Physical Model based on pm.modeFilter
// =====================================================
tibetanBowl(f, vel, strk, trig) = excitation : _ <: par(i, nModes, pm.modeFilter(modeFreqs(i), modeT60s(i), modeGains(i))) :> /(nModes)
with {
    nModes = 4;
    
    // Inharmonic modal frequencies of a typical singing bowl
    modeFreqs(0) = f;
    modeFreqs(1) = f * 2.8;
    modeFreqs(2) = f * 5.4;
    modeFreqs(3) = f * 8.9;
    
    // Long, metallic decay times
    modeT60s(0) = 15.0;
    modeT60s(1) = 8.0;
    modeT60s(2) = 4.0;
    modeT60s(3) = 2.0;

    // Amplitude weighting
    modeGains(0) = 1.0;
    modeGains(1) = 0.5;
    modeGains(2) = 0.2;
    modeGains(3) = 0.1;

    // 1. Metallic Click (Strike = 0)
    // A sharp impulse filtered to mimic a wooden/padded mallet strike.
    impulse = (trig > 0) & (trig' <= 0); // 1 sample impulse on trigger rising edge
    click_exc = impulse : fi.lowpass(2, 4000) * vel * 8.0;
    
    // 2. Continuous Rub (Strike = 1)
    // Stick-slip friction simulated with bandpass-filtered noise enveloped by the trigger.
    rub_env = trig : si.smooth(ba.tau2pole(0.1)); // 100ms attack/release for friction buildup
    rub_exc = no.noise : fi.resonbp(f, 2.0, 1.0) * rub_env * vel * 0.15;

    // Dynamic Excitation Router
    excitation = (click_exc * (1 - strk)) + (rub_exc * strk);
};

process = tibetanBowl(freq, velocity, strike, gate) * gain;