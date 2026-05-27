import("stdfaust.lib");

// --- Punjabi Dhol (Bhangra Drum) Physical Model (Multiphonic/Dual-Freq) ---

freq = hslider("freq [unit:Hz]", 110.0, 40.0, 600.0, 0.1);      // Left Head (Dagga/Bass)
freq1 = hslider("freq1 [unit:Hz]", 660.0, 100.0, 1200.0, 0.1);  // Right Head (Tilli/Treble)
strike = hslider("strike", 0, 0, 4, 1);                       // 0=Dagga open, 1=Dagga closed, 2=Tilli open, 3=Tilli closed, 4=Composite Dha
gain = hslider("gain", 1.0, 0.0, 2.0, 0.01);
velocity = hslider("velocity", 1.0, 0.0, 1.0, 0.01);
gate = button("gate");

decayScaleSlider = hslider("decay_scale", 1.0, 0.1, 4.0, 0.05);

// Robust 2-Pole Resonator function (Direct Form II style)
resonator(f, t60, g, x) = x * 0.002 : + ~ (routing) : *(g)
with {
    T60 = max(0.001, t60);
    r = pow(0.001, 1.0 / (T60 * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    routing(fb) = b1 * fb - b2 * fb';
};

// Gate and excitation routing based on strike code
trig = gate : ba.impulsify;
trigDagga = trig * ((strike == 0) + (strike == 1) + (strike == 4) > 0);
trigTilli = trig * ((strike == 2) + (strike == 3) + (strike == 4) > 0);

daggaDecay = decayScaleSlider * ba.if(strike == 1, 0.25, 1.0);
tilliDecay = decayScaleSlider * ba.if(strike == 3, 0.15, 1.0);

// Noise generator for stick scrapes and transients
noise = no.noise;

// Dagga (Bass stick) excitation: deep impulse + low-passed noise burst for thick skin contact
dagga_noise_env = en.ar(0.002, 0.015, trigDagga);
dagga_noise = noise * dagga_noise_env * velocity * 0.12 : fi.lowpass(2, 200.0);
excitationDagga = (trigDagga * velocity * 0.35 + dagga_noise) : fi.lowpass(4, 180.0);

// Tilli (Treble stick) excitation: clean, extremely sharp impulse for clean wood-to-membrane strike (no noisy fuzz)
excitationTilli = trigTilli * velocity * 0.65;

// 1. Dagga (Bass stick) - Heavy, resonant, low-frequency boom with pitch envelope
dagga_pitch_env = en.ar(0.004, 0.18, trigDagga);
dagga_freq = freq * (1.0 + 0.28 * dagga_pitch_env * velocity);
dagga_mode1 = resonator(dagga_freq * 1.0, 1.40 * daggaDecay, 1.00, excitationDagga);
dagga_mode2 = resonator(dagga_freq * 1.6, 0.50 * daggaDecay, 0.35, excitationDagga);
dagga_mode3 = resonator(dagga_freq * 2.2, 0.15 * daggaDecay, 0.15, excitationDagga);
dagga_body = dagga_mode1 + dagga_mode2 + dagga_mode3;

// 2. Tilli (Treble stick) - Sharp, cutting snap, rapid decay, inharmonic Bessel modes (extremely tight & thin)
// Strike positions: strike == 2 (Open, struck near center), strike == 3 (Edge/Rim, dampens fundamental)
tilli_m1_g = ba.if(strike == 3, 0.15, 1.00);
tilli_m2_g = ba.if(strike == 3, 0.80, 0.75);
tilli_m3_g = ba.if(strike == 3, 1.00, 0.50);
tilli_m4_g = ba.if(strike == 3, 0.60, 0.25);

tilli_mode1 = resonator(freq1 * 1.00, 0.12 * tilliDecay, tilli_m1_g, excitationTilli);
tilli_mode2 = resonator(freq1 * 1.59, 0.06 * tilliDecay, tilli_m2_g, excitationTilli);
tilli_mode3 = resonator(freq1 * 2.14, 0.03 * tilliDecay, tilli_m3_g, excitationTilli);
tilli_mode4 = resonator(freq1 * 2.65, 0.01 * tilliDecay, tilli_m4_g, excitationTilli);
tilli_body = tilli_mode1 + tilli_mode2 + tilli_mode3 + tilli_mode4;

// Output: Summed response of active heads (Tilli has higher relative gain to cut through)
drum_body = dagga_body * 1.0 + tilli_body * 2.8;

// Process: Nonlinear saturation waveshaping and low-pass filtering to bring out warm chest punch
process = (drum_body * 18.0 : ma.tanh : fi.lowpass(1, 2000.0)) * (gain * 0.95);
