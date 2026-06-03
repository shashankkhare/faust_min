declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: The treble drum of the Indian Tabla pair (Dayan), simulating standard classical strokes (Na, Ta, Tin, Tun, Dha, Dhin) using multi-mode resonant models.
//
// Parameters (Controls):
//   - freq
//   - gain
//   - velocity
//   - gate
//   - strike
// =============================================================================
import("stdfaust.lib");

// --- Dayan (Tabla High Drum) - Ported from C++ Modal Model ---
freq = hslider("freq", 293.66, 100, 1000, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");
strike = hslider("strike", 0, 0, 3, 1); 

// Articulation Logic (Decay & Spectral Balance)
// strike 0: Na Snap
// strike 1: tk Dead Click
// strike 2: Tin (Edge Resonant)
// strike 3: Tun (Open Center)

// Base decay scale (Sharpened for very fast natural response)
t60Scale = (strike < 0.5) * 0.1 + // Na Snap
           ((strike >= 0.5) * (strike < 1.5)) * 0.01 + // tk Dead Click
           ((strike >= 1.5) * (strike < 2.5)) * 0.3 + // Tin
           (strike >= 2.5) * 0.5; // Tun

actualT60 = t60Scale;

// Velocity-dependent Spectral Morphing
// Higher velocity increases the energy of high-frequency modes
bright = velocity * 0.6;

// Base modal gains for each strike type (0:Na, 1:tk, 2:Tin, 3:Tun)
g1_base = ba.selectn(4, strike, 1.0, 0.5, 1.5, 1.5);
g2_base = ba.selectn(4, strike, 0.8, 1.0, 1.2, 0.8);
g3_base = ba.selectn(4, strike, 0.6, 0.5, 0.8, 0.4);
g4_base = ba.selectn(4, strike, 1.0, 0.1, 0.4, 0.1);
g5_base = ba.selectn(4, strike, 1.0, 0.05, 0.2, 0.05);

g1 = g1_base * (1.0 - bright * 0.2);
g2 = g2_base * (1.0 + bright * 0.1);
g3 = g3_base * (1.0 + bright * 0.4);
g4 = g4_base * (1.0 + bright * 0.7);
g5 = g5_base * (1.0 + bright * 1.0);

// Ensure instantaneous frequency updates without sliding/whooping artifacts
smoothedFreq = freq;
smoothedT60 = actualT60;
sg1 = g1;
sg2 = g2;
sg3 = g3;
sg4 = g4;
sg5 = g5;

// Dynamic Drive LUT (Increases non-linearity with velocity)
dynamicDrive = 1.0 + (velocity * 0.2);

// Manual 2-Pole Resonator using fixed energy input scaling to prevent transient spikes
myResonator(f, t, g, x) = x * 0.002 : + ~ (conv) : * (g)
with {
    T60 = t * smoothedT60;
    r = pow(0.001, 1.0/(max(0.001, T60) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    conv(y) = b1 * y - b2 * y';
};

// Impulse Exciter (Scaled by physical velocity)
exciter = gate : ba.impulsify * velocity;

// Modal Sum
dayan = myResonator(smoothedFreq * 1.0, 3.5, sg1, exciter) +
        myResonator(smoothedFreq * 1.5, 2.8, sg2, exciter) +
        myResonator(smoothedFreq * 2.0, 2.0, sg3, exciter) +
        myResonator(smoothedFreq * 2.5, 1.4, sg4, exciter) +
        myResonator(smoothedFreq * 3.0, 0.9, sg5, exciter);

// Final Stage
process = (dayan * dynamicDrive * 24.0 : ma.tanh) * gain;
