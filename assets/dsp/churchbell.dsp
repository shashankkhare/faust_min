import("stdfaust.lib");

freq = hslider("freq", 200, 50, 1000, 0.1); // No si.smoo on freq to avoid biquad pops on note changes
velocity = hslider("velocity", 0.8, 0, 1, 0.01); // No smoothing to preserve instant strike dynamics
gate = button("gate");
gain = hslider("gain", 0.6, 0, 1, 0.01) : si.smoo;

// Generate trigger pulse from gate rising edge
trig = (gate > 0) & (gate' <= 0);

// A transposable Church Bell using physical modal synthesis
churchBell(f, vel, t) = excitation : _ <: par(i, 7, pm.modeFilter(modeFreqs(i), modeT60s(i), modeGains(i))) :> /(7)
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
    modeT60s(0) = 25.0;
    modeT60s(1) = 20.0;
    modeT60s(2) = 15.0;
    modeT60s(3) = 10.0;
    modeT60s(4) = 5.0;
    modeT60s(5) = 2.5;
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
