declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Traditional large resonant church bell modeled using subtractive/modal synthesis to simulate massive metal resonance.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - gain
// =============================================================================
import("stdfaust.lib");

// Expert Play Range: Church bell fundamental typically 100-1000 Hz.
freq = hslider("freq", 200.0, 100, 1000, 0.1); // No si.smoo on freq to avoid biquad pops on note changes
velocity = hslider("velocity", 0.8, 0, 1, 0.01); // No smoothing to preserve instant strike dynamics
gate = button("gate");
gain = hslider("gain", 0.6, 0, 100, 0.01) : si.smoo;

// Generate trigger pulse from gate rising edge
trig = (gate > 0) & (gate' <= 0);

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

// A transposable Church Bell using physical modal synthesis
churchBell(f, vel, t) = excitation : _ <: par(i, 7, safe_modeFilter(modeFreqs(i), modeT60s(i), modeGains(i))) :> /(7)
with {
    // Correct transposable churchbell ratios (pitched relative to Hum f * 1.0)
    modeFreqs(0) = f * 1.00;   // Hum
    modeFreqs(1) = f * 2.00;   // Prime
    modeFreqs(2) = f * 2.40;   // Tierce (Minor Third)
    modeFreqs(3) = f * 3.00;   // Quint (Fifth)
    modeFreqs(4) = f * 4.00;   // Nominal
    modeFreqs(5) = f * 6.00;   // Superquint
    modeFreqs(6) = f * 8.00;   // Octave Nominal

    // Decay times (T60 in seconds)
    // Capped to max 10.0 to prevent endless ringing and numeric overflow
    modeT60s(0) = 10.0;
    modeT60s(1) = 8.0;
    modeT60s(2) = 6.0;
    modeT60s(3) = 4.0;
    modeT60s(4) = 3.0;
    modeT60s(5) = 2.0;
    modeT60s(6) = 1.0;

    // Amplitude weights
    modeGains(0) = 0.9;
    modeGains(1) = 1.0;
    modeGains(2) = 0.8;
    modeGains(3) = 0.6;
    modeGains(4) = 1.0;
    modeGains(5) = 0.4;
    modeGains(6) = 0.2;

    // Excitation: 1-sample impulse scaled by velocity.
    // Lowpass at 350 Hz simulates a soft, heavy clapper and avoids high frequency "click/rock" transients.
    // Scaled by 1.2 to keep the resonators' initial output below the hard clipping threshold.
    excitation = t : fi.lowpass(2, 350) * vel * 1.2;
};

// Sum of 7 modes scaled down, filtered, soft-clipped, and multiplied by gain.
process = churchBell(freq, velocity, trig) : fi.dcblocker : ma.tanh * gain;
