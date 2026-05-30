import("stdfaust.lib");

// --- Corrected Lag Nga (Tibetan Frame Drum Physical Model) ---
// Models a small, tight, double-headed frame drum
// Struck with a hard wooden mallet.

freq = hslider("freq [unit:Hz]", 111.0, 85.0, 200.0, 0.1);
gain = hslider("gain", 1.0, 0.0, 2.0, 0.01);
velocity = hslider("velocity", 1.0, 0.0, 1.0, 0.01);
gate = button("gate");

// Expressive controls for a tight, wooden mallet strike
decayScale = hslider("decay_scale", 0.8, 0.1, 4.0, 0.05); // Shorter decay for a tight drum
malletSoftness = hslider("mallet_softness", 1200.0, 400.0, 3000.0, 1.0); // High cutoff for sharp wooden attack

// Robust 2-Pole Resonator function (Direct Form II style) - scaled by 0.002 to prevent internal overload
resonator(f, t60, g, x) = x * 0.002 : + ~ (routing) : *(g)
with {
    T60 = max(0.001, t60 * decayScale);
    r = pow(0.001, 1.0 / (T60 * ma.SR)) * 0.999995;
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    // Mathematically clean feedback routing structure
    routing(fb) = b1 * fb - b2 * fb';
};

// EXCITATION: Clean, noise-free mallet pressure pulse modeled by low-passing a single impulse.
// This eliminates all random noise phase jitter (which causes cracking/distortion).
trig = gate : ba.impulsify;
excitation = trig * velocity * 0.15 * (freq / 85.0) : fi.lowpass(4, malletSoftness);

// PITCH ENVELOPE FIX: Triggered by trig instead of gate to prevent noteOff glitching the active decay tail
pitch_env = en.ar(0.005, 0.025, trig); 
dyn_freq = freq * (1.0 - 0.08 * pitch_env); // Drops pitch by 8% initially, blooming back up to root

// MEMBRANE FREQUENCY MODES (Strictly tuned for large, air-coupled Tibetan ritual frames)
// Amplified lower fundamentals and heavily attenuated high overtones.
mode1a = resonator(dyn_freq * 1.00, 1.40, 1.00, excitation);  // Primary low-end bloom
mode1b = resonator(dyn_freq * 1.18, 1.10, 0.65, excitation);  // Air-cavity coupled resonance
mode2a = resonator(dyn_freq * 1.59, 0.35, 0.20, excitation);  // Muffled secondary mode
mode2b = resonator(dyn_freq * 1.63, 0.28, 0.15, excitation);  // Minor structural asymmetry tension split
mode3  = resonator(dyn_freq * 2.14, 0.10, 0.05, excitation);  // Drastically quieted upper mode
mode4  = resonator(dyn_freq * 2.30, 0.05, 0.02, excitation);  // Tiny trace of edge skin vibration

drum_body = mode1a + mode1b + mode2a + mode2b + mode3 + mode4;

// MIX FIX: Saturate first (skin dynamics), 1st-order lowpass second (body absorption, zero overshoot), and apply 0.85 headroom
process = (drum_body * 12.0 : ma.tanh : fi.lowpass(1, 220.0)) * (gain * 6.0);
