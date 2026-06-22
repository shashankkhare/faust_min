declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Traditional Indian folk barrel drum (Dholak) modeled with coupled dual-frequency skin resonances.
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - freq_right [unit:Hz]
//   - strike
//   - gain
//   - velocity
//   - gate
//   - decay_scale
// =============================================================================
import("stdfaust.lib");

// --- Indian Dholak Physical Model (Multiphonic/Dual-Freq) ---

// Expert Play Range: Dholak bass/treble fundamental typically 70-300 Hz.
freq = hslider("freq [unit:Hz]", 98.0, 70, 300, 0.1);      // Left Head (Bayan/Bass)
// Expert Play Range: Dholak bass/treble fundamental typically 70-300 Hz.
freq_right = hslider("freq_right [unit:Hz]", 277.2, 70, 300, 0.1);   // Right Head (Dayan/Treble)
strike = hslider("strike", 0, 0, 4, 1);                       // 0=Bayan open, 1=Bayan closed, 2=Dayan open, 3=Dayan closed, 4=Composite Dha
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
trigBayan = trig * ((strike == 0) + (strike == 1) + (strike == 4) > 0);
trigDayan = trig * ((strike == 2) + (strike == 3) + (strike == 4) > 0);

bayanDecay = decayScaleSlider * ba.if(strike == 1, 0.3, 1.0);
dayanDecay = decayScaleSlider * ba.if(strike == 3, 0.25, 1.0);

// Excitation mallet: Bayan is soft (110 Hz lowpass), Dayan is sharp (800 Hz lowpass)
excitationBayan = trigBayan * velocity * 0.35 : fi.lowpass(4, 110.0);
excitationDayan = trigDayan * velocity * 0.35 : fi.lowpass(4, 800.0);

// 1. Bayan (Bass) - Includes hand heel pitch sliding
bayan_pitch_env = en.ar(0.01, 0.25, trigBayan);
bayan_freq = freq * (1.0 + 0.25 * bayan_pitch_env * velocity);
bayan_mode1 = resonator(bayan_freq * 1.0, 0.90 * bayanDecay, 1.00, excitationBayan);
bayan_mode2 = resonator(bayan_freq * 1.8, 0.50 * bayanDecay, 0.50, excitationBayan);
bayan_mode3 = resonator(bayan_freq * 2.3, 0.25 * bayanDecay, 0.20, excitationBayan);
bayan_body = bayan_mode1 + bayan_mode2 + bayan_mode3;

// 2. Dayan (Treble) - Bright, high-pitched, inharmonic membrane ring
dayan_mode1 = resonator(freq_right * 1.00, 0.35 * dayanDecay, 1.00, excitationDayan);
dayan_mode2 = resonator(freq_right * 1.59, 0.18 * dayanDecay, 0.55, excitationDayan);
dayan_mode3 = resonator(freq_right * 2.14, 0.08 * dayanDecay, 0.25, excitationDayan);
dayan_mode4 = resonator(freq_right * 2.30, 0.04 * dayanDecay, 0.10, excitationDayan);
dayan_body = dayan_mode1 + dayan_mode2 + dayan_mode3 + dayan_mode4;

// Output: Summed response of active heads
drum_body = bayan_body * 0.95 + dayan_body * 1.15;

// Process: Waveshaping and 1st-order low-pass (cutoff at 1200 Hz to let Dayan ring through)
process = (drum_body * 16.0 : ma.tanh : fi.lowpass(1, 1200.0)) * (gain * 1.25);
