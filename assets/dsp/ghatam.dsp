declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN: GHATAM (Terracotta Matka) ===
//
// Description:
// The Ghatam is a traditional Carnatic percussion instrument made of clay (terracotta).
// Acoustically, it functions as a thick, rigid spherical shell with a narrow mouth.
// This creates two distinct physical systems:
// 1. The rigid clay shell: Produces very high-pitched, metallic, inharmonic modes.
// 2. The air cavity (Helmholtz resonator): Produces a deep, pure low-frequency bass.
//
// Parameters (Controls):
//   - freq: Fundamental Helmholtz pitch (usually tuned to the tonic 'Sa')
//   - gain: Master output volume
//   - velocity: Excitation energy and brightness
//   - gate: Triggers the stroke
//   - strike: Selects the articulation/bol (0-4)
// =============================================================================
import("stdfaust.lib");

// Expert Play Range: Ghatam tonal range typically 100-300 Hz depending on size/pitch.
freq = hslider("freq", 130.81, 100, 300, 0.1); // Default C3
gain = hslider("gain", 0.8, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
slap_force = hslider("slap_force", 1, 0, 1, 0.01);
gate = button("gate");
strike = hslider("strike", 0, 0, 4, 1);

// Articulation Logic (Ghatam Strokes)
// 0: Tha (Neck stroke - Balanced mix of shell and cavity)
// 1: Dhi (Body/Center - High-pitched shell ring, muted bass)
// 2: Thom (Belly stroke - Very deep, resonant bass, less shell)
// 3: Nam / Rim (Edge click - Extremely sharp, metallic, zero bass)
// 4: Gumki (Mouth pressed against stomach - Drops Helmholtz pitch by a minor third/fourth)

// Decay scales
t60Shell = ba.selectn(5, strike,
    0.4,   // 0: Tha (Moderate metallic ring)
    0.6,   // 1: Dhi (Long, prominent metallic ring)
    0.2,   // 2: Thom (Muted shell)
    0.8,   // 3: Nam (Maximum sharp metallic ring)
    0.1    // 4: Gumki (Damped shell)
);

t60Cavity = ba.selectn(5, strike,
    0.35,  // 0: Tha (Acoustically calibrated 350ms T60 Helmholtz fundamental)
    0.01,  // 1: Dhi (Muted rim click)
    0.30,  // 2: Thom (Deep 300ms resonant bass fundamental)
    0.005, // 3: Nam (Zero bass)
    0.25   // 4: Gumki (Dynamic pitch bend)
);

// Pitch scaling for the Gumki effect (drops the pitch of the cavity)
cavityFreq = freq * ba.selectn(5, strike, 1.0, 1.0, 1.0, 1.0, 0.8);

// Modal Gains (Shell: inharmonic stiff modes, Cavity: pure fundamental)
// Modes: Cavity, Shell 1, Shell 2, Shell 3, Shell 4
g_cavity = ba.selectn(5, strike, 0.5, 0.05, 0.8, 0.0, 0.8); // Bass pumped up lightly
g_shell1 = ba.selectn(5, strike, 0.8, 1.2, 0.2, 1.5, 0.4); // ~3.4x fundamental
g_shell2 = ba.selectn(5, strike, 0.6, 1.0, 0.1, 1.2, 0.2); // ~5.1x fundamental
g_shell3 = ba.selectn(5, strike, 0.5, 0.8, 0.0, 1.0, 0.1); // ~6.8x fundamental
g_shell4 = ba.selectn(5, strike, 0.3, 0.6, 0.0, 0.8, 0.0); // ~8.6x fundamental

// Brightness based on slap_force (how hard the drum is struck)
bright = slap_force;
s1 = g_shell1 * (0.8 + bright * 0.4);
s2 = g_shell2 * (0.6 + bright * 0.6);
s3 = g_shell3 * (0.4 + bright * 0.8);
s4 = g_shell4 * (0.3 + bright * 0.8);
c_gain = g_cavity * (1.2 - bright * 0.2); // Harder strikes excite more shell, less cavity proportionally

// Resonator logic
myResonator(f, t, g, x) = x * 0.002 : + ~ (conv) : * (g)
with {
    r = pow(0.001, 1.0/(max(0.001, t) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    conv(y) = b1 * y - b2 * y';
};

// Exciter: A clay pot requires a sharp transient to ring its high-frequency modes.
// We use slap_force for the core energy, and we simulate a "slower attack" (fleshy hand)
// by low-pass filtering the impulse based on velocity.
// The shell modes are around 700Hz-2000Hz. To mute them, the cutoff must drop to ~300Hz at low velocity!
lp_freq = freq + (pow(velocity, 2.0) * 10000.0); // Non-linear cutoff scaling
exciter = gate : ba.impulsify : fi.lowpass(2, lp_freq) * slap_force;

// The Ghatam shell has very high, inharmonic modes (thick rigid body)
shell = myResonator(freq * 3.42, t60Shell, s1, exciter) +
        myResonator(freq * 5.14, t60Shell, s2, exciter) +
        myResonator(freq * 6.81, t60Shell, s3, exciter) +
        myResonator(freq * 8.65, t60Shell * 0.8, s4, exciter);

// The cavity is a pure Helmholtz resonator
cavity = myResonator(cavityFreq, t60Cavity, c_gain, exciter);

process = (shell + cavity) * 15.0 : ma.tanh * gain;
