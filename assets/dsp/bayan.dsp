import("stdfaust.lib");

// --- Bayan (Tabla Low Drum) - Ported from C++ Modal Model ---
baseFreq = hslider("freq", 110.0, 40, 400, 0.1);
gain = hslider("gain", 0.9, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");
strike = hslider("strike", 1, 0, 2, 1); 
meend = hslider("meend", 1.0, 0.5, 4.0, 0.01); // Frequency multiplier for "Ghe"

// Frequency Glide (Exponential smoothing for the "Ghe" whoop)
// Time constant matches the 0.005 factor from C++
smoothedMeend = meend : si.smoo;
smoothedFreq = baseFreq * smoothedMeend;

// Articulation Logic (Muted vs Resonant - Sharpened for fast natural response)
t60Scale = (strike < 0.5) * 0.05 + (strike >= 0.5) * 0.4;

// Dynamic Drive LUT (Near-linear for clean bass)
dynamicDrive = 1.05;

// Manual 2-Pole Resonator with Internal Normalization
myResonator(f, t, g, x) = x * (1.0 - r) : + ~ (conv) : * (g)
with {
    T60 = t * t60Scale;
    r = pow(0.001, 1.0/(max(0.001, T60) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    conv(y) = b1 * y - b2 * y';
};

// Impulse Exciter (Restored to linear velocity)
exciter = gate : ba.impulsify * velocity;

bayan = myResonator(smoothedFreq * 1.0, 1.8, 1.0, exciter) +
        myResonator(smoothedFreq * 2.1, 1.0, 0.7, exciter) +
        myResonator(smoothedFreq * 3.2, 0.5, 0.4, exciter);

// Target Peak 0.5: Using normalized internal gain and strong master boost
process = (bayan * dynamicDrive : ma.tanh) * 20.0 * gain * (1.0 + 0.00001 * strike);
