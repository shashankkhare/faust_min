declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Physical model of a Tibetan singing bowl struck with a mallet, emphasizing complex inharmonic modes and metal resonance.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - strike
//   - gate
//   - gain
// =============================================================================
import("stdfaust.lib");

// =====================================================
// Realistic Tibetan Singing Bowl (Physical Model)
// =====================================================

freq = hslider("freq", 110, 60, 1000, 0.1) : si.smoo;
velocity = hslider("velocity", 0.8, 0, 1, 0.01) : si.smoo;

// Strike: 0 = Mallet Click, 1 = Continuous Rub
strike = hslider("strike", 0, 0, 1, 1);
gate = button("gate");

gain = hslider("gain", 0.6, 0, 100, 0.01) : si.smoo;

// =====================================================
// Safe bounded mode filter to prevent 32-bit float limit cycle explosions
safe_modeFilter(freq,t60,gain) = fi.tf2(b0,b1,b2,a1,a2)*gain
with {
    b0 = 1; b1 = 0; b2 = -1;
    w = 2*ma.PI*freq/ma.SR;
    r_target = pow(0.001,1/float(t60*ma.SR));
    r = min(0.999, r_target); // HARD CAP ON RADIUS (prevents r=1.0 in 32-bit floats)
    a1 = -2*r*cos(w);
    a2 = r^2;
};

// Physical Model based on safe_modeFilter
tibetanBowl(f, vel, strk, trig) = excitation : _ <: par(i, nModes, safe_modeFilter(modeFreqs(i), modeT60s(i), modeGains(i))) :> /(nModes)
with {
    nModes = 4;
    
    // Inharmonic modal frequencies of a typical singing bowl
    modeFreqs(0) = f;
    modeFreqs(1) = f * 2.8;
    modeFreqs(2) = f * 5.4;
    modeFreqs(3) = f * 8.9;
    
    // Long, metallic decay times
    // Capped to safe limits for 32-bit precision
    modeT60s(0) = 10.0;
    modeT60s(1) = 6.0;
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
