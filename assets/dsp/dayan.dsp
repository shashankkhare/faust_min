import("stdfaust.lib");

// --- Dayan (Tabla High Drum) - Ported from C++ Modal Model ---
freq = hslider("freq", 293.66, 100, 1000, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");
strike = hslider("strike", 0, 0, 2, 1); 

// Articulation Logic (Decay & Spectral Balance)
// strike 0: Na Snap
// strike 0.1: tk Dead Click
// strike 1: Tin (Edge Resonant)
// strike 2: Tun (Open Center)

// Base decay scale (Sharpened for very fast natural response)
t60Scale = (strike < 0.05) * 0.1 + // Na Snap
           ((strike >= 0.05) * (strike < 0.5)) * 0.01 + // tk Dead Click
           ((strike >= 0.5) * (strike < 1.5)) * 0.3 + // Tin
           (strike >= 1.5) * 0.5; // Tun

actualT60 = t60Scale;

// Spectral Balance LUT
// g1-g5: mode gains
// strike 0: Na (Bright Edge Snap)
// strike 0.1: tk (Dull Center Thud)
g1 = (strike < 0.05) * 1.0 + ((strike >= 0.05) * (strike < 0.5)) * 0.5 + ((strike >= 0.5) * (strike < 1.5)) * 1.5 + (strike >= 1.5) * 1.5;
g2 = (strike < 0.05) * 0.8 + ((strike >= 0.05) * (strike < 0.5)) * 1.0 + ((strike >= 0.5) * (strike < 1.5)) * 1.2 + (strike >= 1.5) * 0.8;
g3 = (strike < 0.05) * 0.6 + ((strike >= 0.05) * (strike < 0.5)) * 0.5 + ((strike >= 0.5) * (strike < 1.5)) * 0.8 + (strike >= 1.5) * 0.4;
g4 = (strike < 0.05) * 1.0 + ((strike >= 0.05) * (strike < 0.5)) * 0.1 + ((strike >= 0.5) * (strike < 1.5)) * 0.4 + (strike >= 1.5) * 0.1;
g5 = (strike < 0.05) * 1.0 + ((strike >= 0.05) * (strike < 0.5)) * 0.05 + ((strike >= 0.5) * (strike < 1.5)) * 0.2 + (strike >= 1.5) * 0.05;

// Dynamic Drive LUT (Near-linear for clean sound)
dynamicDrive = 1.1;

// Manual 2-Pole Resonator with Internal Normalization
myResonator(f, t, g, x) = x * (1.0 - r) : + ~ (conv) : * (g)
with {
    T60 = t * actualT60;
    r = pow(0.001, 1.0/(max(0.001, T60) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    conv(y) = b1 * y - b2 * y';
};

// Impulse Exciter (Scaled by physical velocity)
exciter = gate : ba.impulsify * velocity;

dayan = myResonator(freq * 1.0, 3.5, g1, exciter) +
        myResonator(freq * 1.5, 2.8, g2, exciter) +
        myResonator(freq * 2.0, 2.0, g3, exciter) +
        myResonator(freq * 2.5, 1.4, g4, exciter) +
        myResonator(freq * 3.0, 0.9, g5, exciter);

// Target Peak 0.5: Using normalized internal gain and strong master boost
process = (dayan * dynamicDrive : ma.tanh) * 24.0 * gain * (1.0 + 0.00001 * strike);
