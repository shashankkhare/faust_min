import("stdfaust.lib");

// --- Bayan (Tabla Low Drum) - Ported from C++ Modal Model ---
baseFreq = hslider("freq", 110.0, 40, 400, 0.1);
gain = hslider("gain", 0.9, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");
strike = hslider("strike", 1, 0, 3, 1); 
meend = hslider("meend", 1.0, 0.5, 4.0, 0.01); // Frequency multiplier for "Ghe"

// Frequency Glide (Exponential smoothing for the "Ghe" whoop)
// Time constant matches the 0.005 factor from C++
smoothedMeend = meend : si.smoo;
smoothedFreq = baseFreq * smoothedMeend;

// Articulation Logic (0: Ka/Closed, 1: Ghe/Open, 2: Ghi/Open, 3: Ke/Closed)
t60Scale = ba.selectn(4, strike, 0.05, 0.4, 0.4, 0.05);

// Dynamic Drive LUT (Near-linear for clean bass)
dynamicDrive = 1.05;

// Manual 2-Pole Resonator using fixed energy input scaling to prevent transient spikes
myResonator(f, t, g, x) = x * 0.002 : + ~ (conv) : * (g)
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

// Spectral Balance with Velocity Morphing
bright = velocity * 0.5;
bg1_base = ba.selectn(4, strike, 1.0, 1.0, 1.0, 1.0);
bg2_base = ba.selectn(4, strike, 0.5, 0.7, 0.7, 0.5);
bg3_base = ba.selectn(4, strike, 0.2, 0.4, 0.4, 0.2);

bg1 = bg1_base * (1.0 - bright * 0.1);
bg2 = bg2_base * (1.0 + bright * 0.3);
bg3 = bg3_base * (1.0 + bright * 0.6);

bayan = myResonator(smoothedFreq * 1.0, 1.8, bg1, exciter) +
        myResonator(smoothedFreq * 2.1, 1.0, bg2, exciter) +
        myResonator(smoothedFreq * 3.2, 0.5, bg3, exciter);

// Target Peak 0.5: Using normalized internal gain and strong master boost
process = (bayan * dynamicDrive : ma.tanh) * 20.0 * gain;
