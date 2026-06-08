declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN: MRIDANGAM ===
//
// Description:
// The Mridangam is a South Indian double-sided drum. The right head (Valanthalai)
// is concentrically loaded with a heavy black paste (sihai/karanai). As established
// in mathematical and acoustic studies, this concentric loading forces the drum
// to vibrate with perfectly harmonic overtone ratios, giving it a strong sense of pitch.
// 
// Reference:
// Sathej, G., and R. Adhikari. "The eigenspectra of Indian musical drums." 
// arXiv preprint arXiv:0809.1320 (2008). 
// The paper demonstrates that the first five axisymmetric and non-axisymmetric 
// modes of the concentrically loaded membrane yield integer frequency ratios:
// 1.0, 2.0, 3.0, 4.0, and 5.0.
//
// Model Architecture:
// This DSP implements a 5-mode parallel 2-pole resonator bank tuned exactly to
// these harmonic integers. A 'strike' parameter maps 6 traditional strokes (bols/sollukattus)
// to varying modal excitation gains, decay times, and pitch offsets.
//
// Parameters (Controls):
//   - freq: Fundamental pitch (or first overtone pitch, depending on stroke)
//   - gain: Master output volume
//   - velocity: Excitation energy and brightness
//   - gate: Triggers the stroke
//   - strike: Selects the articulation/bol (0-5)
// =============================================================================
import("stdfaust.lib");

freq = hslider("freq", 146.83, 40, 1000, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");
strike = hslider("strike", 2, 0, 5, 1);

// Articulation Logic (Mridangam Strokes / Sollukattus)
// 0: Tha (Open Bass - Left Head/Toppi)
// 1: Thom (Closed Bass - Left Head/Toppi)
// 2: Chapu (Open Treble Harmonic - Right Head/Valanthalai)
// 3: Nam (Treble Edge - Right Head/Valanthalai)
// 4: Dhi (Treble Center Mute - Right Head/Valanthalai)
// 5: Ta (Treble Edge Click - Right Head/Valanthalai)

// Decay Scale per stroke
t60Scale = ba.selectn(6, strike,
    0.6,   // 0: Tha (Long bass ring)
    0.05,  // 1: Thom (Short bass thud)
    0.7,   // 2: Chapu (Beautiful, long harmonic ring)
    0.4,   // 3: Nam (Bright edge ring)
    0.1,   // 4: Dhi (Muted center)
    0.03   // 5: Ta (Sharp click)
);

// Frequency scaling per stroke
// The left head (Toppi) is generally tuned an octave below the right head's perceived pitch.
freqScale = ba.selectn(6, strike,
    0.5,   // 0: Tha (Octave down for bass)
    0.5,   // 1: Thom (Octave down for bass)
    1.0,   // 2: Chapu (Base pitch)
    1.2,   // 3: Nam (Edge strikes often excite higher modes predominantly)
    1.0,   // 4: Dhi (Base pitch)
    1.5    // 5: Ta (High click)
);

actualFreq = freq * freqScale;

// Base modal gains (Modeling 5 perfectly harmonic modes)
// Chapu (2) excites all 5 modes strongly. 
// Bass strokes (0, 1) predominantly excite the fundamental.
// Edge strokes (3, 5) excite higher modes.
g1_base = ba.selectn(6, strike, 1.5, 1.2, 0.5, 0.2, 1.0, 0.1); // Mode 1: 1.0
g2_base = ba.selectn(6, strike, 0.8, 0.4, 1.0, 0.5, 0.8, 0.2); // Mode 2: 2.0 (Often perceived pitch)
g3_base = ba.selectn(6, strike, 0.3, 0.1, 0.8, 0.8, 0.4, 0.3); // Mode 3: 3.0
g4_base = ba.selectn(6, strike, 0.1, 0.0, 0.6, 1.0, 0.2, 0.5); // Mode 4: 4.0
g5_base = ba.selectn(6, strike, 0.0, 0.0, 0.4, 0.8, 0.1, 0.8); // Mode 5: 5.0

// Velocity morphing (higher velocity = brighter strike)
bright = velocity * 0.5;
g1 = g1_base * (1.0 - bright * 0.2);
g2 = g2_base * (1.0 + bright * 0.1);
g3 = g3_base * (1.0 + bright * 0.3);
g4 = g4_base * (1.0 + bright * 0.6);
g5 = g5_base * (1.0 + bright * 0.8);

// Dynamic Drive
dynamicDrive = 1.0 + (velocity * 0.3);

// 2-Pole Resonator Implementation
myResonator(f, t, g, x) = x * 0.002 : + ~ (conv) : * (g)
with {
    T60 = t * t60Scale;
    r = pow(0.001, 1.0/(max(0.001, T60) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    conv(y) = b1 * y - b2 * y';
};

// Gate-driven impulsive exciter
exciter = gate : ba.impulsify * velocity;

// Perfectly harmonic modal sum (1.0, 2.0, 3.0, 4.0, 5.0) per the reference paper
mridangam = myResonator(actualFreq * 1.0, 3.5, g1, exciter) +
            myResonator(actualFreq * 2.0, 2.8, g2, exciter) +
            myResonator(actualFreq * 3.0, 2.0, g3, exciter) +
            myResonator(actualFreq * 4.0, 1.4, g4, exciter) +
            myResonator(actualFreq * 5.0, 0.9, g5, exciter);

// Output stage with soft clipping
process = (mridangam * dynamicDrive * 20.0 : ma.tanh) * gain;
