import("stdfaust.lib");

// --- Tanpura Physical Model (Optimized One-Shot) ---
baseFreq = hslider("freq", 130.81, 20, 1000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
jivari = hslider("jivari", 0.7, 0, 1, 0.01); 
gate = button("gate");

// One-Shot Burst Logic
trig = gate : ba.impulsify;
t0 = trig;
t1 = trig @ 8820;  // 0.2s
t2 = trig @ 17640; // 0.4s
t3 = trig @ 26460; // 0.6s

// Fleshy Pluck Excitation
pluckExcitation(t) = no.noise * en.ar(0.001, 0.01, t) : fi.lowpass(1, 400);

// Traditional Tuning
stringFreq(i) = baseFreq * ((i == 0) * 1.5 + (i == 1) * 1.0 + (i == 2) * 1.0 + (i == 3) * 0.5);

// Optimized Jivari String Waveguide
jivariString(f, x) = pluckExcitation(x) : + ~ (de.delay(2048, ma.SR/f-2) : jivariBridge : dispersion : *(0.997) : fi.dcblocker)
with {
    // Jivari bridge: Optimized soft-folding
    jivariBridge(y) = y - (y > 0.4) * (y - 0.4) * (0.2 + jivari * 0.3) : ma.tanh;
    
    // Dispersion: Simplified to single-stage allpass for CPU efficiency
    dispersion = fi.allpassnn(1, (0.45)); 
};

// Parallel processing of 4 strings
process = (jivariString(stringFreq(0), t0) +
           jivariString(stringFreq(1), t1) +
           jivariString(stringFreq(2), t2) +
           jivariString(stringFreq(3), t3)) 
           * gain * velocity * 0.25;
