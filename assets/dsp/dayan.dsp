declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Composite membrane model with two independent resonator banks:
//   1. Syahi (black loading paste at center) — perfect harmonic series (x1..x5)
//   2. Maidan (white outer annulus) — inharmonic Bessel-derived series
// Each strike type mixes the two banks with per-mode gains and decay times.
//
// Parameters (Controls):
//   - freq
//   - gain
//   - velocity
//   - gate
//   - strike
//
// Strokes:
//   0: Na  — finger on maidan, syahi dominant (70%), fundamental suppressed
//   1: tk  — dead muted click, both banks strongly damped
//   2: Tin — edge (maidan) strike, maidan dominant (70%), 2nd partial emphasized
//   3: Tun — open center (syahi) strike, syahi dominant (95%), all harmonics ring
//
// References:
//   - C.V. Raman (1920) — syahi loading produces near-perfect harmonic series
//   - Fleischer (2003) — laser vibrometry modal measurements of tabla
// =============================================================================
import("stdfaust.lib");

freq = hslider("freq", 293.66, 100, 1000, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");
strike = hslider("strike", 0, 0, 3, 1);

// =====================================================
// Maidan multipliers — Bessel zeros normalized to (0,1)
// (0,1)=2.405, (1,1)=3.832, (2,1)=5.136, (0,2)=5.520, (3,1)=6.380
// =====================================================
maidanMul = (1.0, 1.593, 2.135, 2.295, 2.653);

// =====================================================
// Syahi multipliers — perfect harmonic series
// =====================================================
syahiMul = (1.0, 2.0, 3.0, 4.0, 5.0);

// =====================================================
// Per-strike T60 scalar
// =====================================================
t60Scale = ba.selectn(4, strike,
    0.1,   // 0: Na
    0.01,  // 1: tk
    0.3,   // 2: Tin
    0.5    // 3: Tun
);

// =====================================================
// Syahi bank: per-mode base T60 (seconds)
// =====================================================
st60 = (3.5, 2.8, 2.0, 1.4, 0.9);

// =====================================================
// Maidan bank: per-mode base T60 (seconds)
// Shorter than syahi — more boundary damping at rim
// =====================================================
mt60 = (2.5, 2.0, 1.5, 1.0, 0.6);

// =====================================================
// Syahi bank: per-mode gains per strike
// selectn(modeIndex, strike, Na, tk, Tin, Tun)
// =====================================================
sg1_base = ba.selectn(4, strike, 0.05, 0.30, 0.15, 1.50);
sg2_base = ba.selectn(4, strike, 0.30, 0.15, 1.00, 0.80);
sg3_base = ba.selectn(4, strike, 1.00, 0.05, 0.50, 0.40);
sg4_base = ba.selectn(4, strike, 0.60, 0.02, 0.20, 0.25);
sg5_base = ba.selectn(4, strike, 0.30, 0.01, 0.10, 0.15);

// =====================================================
// Maidan bank: per-mode gains per strike
// =====================================================
mg1_base = ba.selectn(4, strike, 0.05, 0.30, 0.20, 0.20);
mg2_base = ba.selectn(4, strike, 0.30, 0.15, 0.70, 0.10);
mg3_base = ba.selectn(4, strike, 1.00, 0.05, 1.00, 0.05);
mg4_base = ba.selectn(4, strike, 0.60, 0.02, 0.50, 0.02);
mg5_base = ba.selectn(4, strike, 0.30, 0.01, 0.20, 0.01);

// =====================================================
// Mix ratio between banks (syahi fraction)
// =====================================================
syahiMix = ba.selectn(4, strike, 0.70, 0.50, 0.30, 0.95);
maidanMix = 1.0 - syahiMix;

// =====================================================
// Velocity-dependent brightness morphing
// =====================================================
bright = velocity * 0.6;

sg1 = sg1_base * (1.0 - bright * 0.2);
sg2 = sg2_base * (1.0 + bright * 0.1);
sg3 = sg3_base * (1.0 + bright * 0.4);
sg4 = sg4_base * (1.0 + bright * 0.7);
sg5 = sg5_base * (1.0 + bright * 1.0);

mg1 = mg1_base * (1.0 - bright * 0.2);
mg2 = mg2_base * (1.0 + bright * 0.1);
mg3 = mg3_base * (1.0 + bright * 0.4);
mg4 = mg4_base * (1.0 + bright * 0.7);
mg5 = mg5_base * (1.0 + bright * 1.0);

// =====================================================
// Manual 2-Pole Resonator
// =====================================================
myResonator(f, t, g, x) = x * 0.002 : + ~ (conv) : * (g)
with {
    T60 = t * smoothedT60;
    r = pow(0.001, 1.0 / (max(0.001, T60) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    conv(y) = b1 * y - b2 * y';
};

// =====================================================
// Impulse Exciter
// =====================================================
exciter = gate : ba.impulsify * velocity;

// =====================================================
// Direct signal paths (instant updates, no smoothing)
// =====================================================
smoothedFreq = freq;
smoothedT60 = t60Scale;

// Syahi bank sum
syahiOut = myResonator(smoothedFreq * 1.0, 3.5, sg1, exciter) +
           myResonator(smoothedFreq * 2.0, 2.8, sg2, exciter) +
           myResonator(smoothedFreq * 3.0, 2.0, sg3, exciter) +
           myResonator(smoothedFreq * 4.0, 1.4, sg4, exciter) +
           myResonator(smoothedFreq * 5.0, 0.9, sg5, exciter);

// Maidan bank sum
maidanOut = myResonator(smoothedFreq * 1.000, 2.5, mg1, exciter) +
            myResonator(smoothedFreq * 1.593, 2.0, mg2, exciter) +
            myResonator(smoothedFreq * 2.135, 1.5, mg3, exciter) +
            myResonator(smoothedFreq * 2.295, 1.0, mg4, exciter) +
            myResonator(smoothedFreq * 2.653, 0.6, mg5, exciter);

// Mix
dayan = syahiOut * syahiMix + maidanOut * maidanMix;

// Dynamic Drive (per-strike base with velocity boost)
dynamicDrive = ba.selectn(4, strike, 1.3, 2.0, 1.2, 1.0) * (1.0 + velocity * 0.2);

// Final Stage
process = (dayan * dynamicDrive * 24.0 : ma.tanh) * gain;
