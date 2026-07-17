declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN: BAYAN ===
// Description: The bass drum of the Indian Tabla pair (Bayan), modeled via a 
//              hybrid physical waveguide and modal architecture.
//
//               [Exciter (Noise)]
//                      |
//           +----------------+----------------+
//           |                                 |
// [Twin Detuned Waveguides]             [Maidan Bank]
//           |                                 |
//           +----------------+----------------+
//                            | (Dynamic Membrane Mix)
//                            v
//                   [Bowl Resonator]
//                            |
//             Output = Membrane Mix + Bowl Resonance
//
//
// 1. The Syahi Path (Twin Waveguide Mode Splitting):
//    The heavy tuning paste (Syahi) is mounted off-center (eccentric). This breaks 
//    circular symmetry and splits the degenerate modes. This is modeled using Twin 
//    Detuned Waveguides that beat against each other, yielding a near-harmonic, 
//    wavering bass tone (e.g., 1.0x, 2.0x alongside 1.02x, 2.04x).
//
// 2. The Maidan Path (Inharmonic Goatskin Modes):
//    Striking the open, bare goatskin creates inharmonic Bessel modes alongside the 
//    Syahi's pitch. This is modeled with a parallel bank of Biquad resonators 
//    tuned to mathematically pure Bessel roots (1.59x, 2.13x, 2.29x, 2.65x).
//
// 3. Stroke-Based Dynamic Coupling:
//    - Open Strokes (Ghe): 50% Syahi / 50% Maidan. Long T60 decay.
//    - Closed Strokes (Ka): 20% Syahi / 80% Maidan. Syahi is pinned down by hand, 
//      causing the energy to route through the heavily-damped goatskin ("thap").
//
// 4. Copper Bowl Resonator (Helmholtz Physics):
//    Uses `physics.lib` to mathematically calculate the Helmholtz resonance of the 
//    metallic body dynamically based on the radius of the opening and internal volume.
//
// 5. Meend (Pitch Glide & Skin Damping):
//    The pitch glide dynamically shrinks the fractional delay lengths, while the 
//    `meend_env` simultaneously chokes the Maidan skin up to 85% to simulate the 
//    wrist physically pressing into and muffling the bare goatskin.
//
// Parameters:
//   - freq
//   - gain
//   - velocity
//   - gate
//   - strike
// =============================================================================
import("stdfaust.lib");
import("physics.lib");

// Expert Play Range: Tabla Bayan (Left hand) bass modulation typically 50-200 Hz.
freq     = hslider("freq",     110.0, 50, 200, 0.1);
gain     = hslider("gain",     0.8,   0,  1,   0.01);
velocity = hslider("velocity", 1.0,   0,  1,   0.01);
gate     = button("gate");
strike   = hslider("strike",   0,     0,  4,   1);
meend_inc_freq = hslider("meend_inc_freq", 2.0, 0.0, 12.0, 0.01); // Semitones to bend up
eccentricity = hslider("eccentricity", 1.02, 1.0, 1.05, 0.001); // Syahi Mode Splitting Ratio
bowl_radius  = hslider("bowl_radius", 0.12, 0.05, 0.20, 0.01);  // Meters
bowl_volume  = hslider("bowl_volume", 0.01, 0.005, 0.05, 0.001); // Cubic Meters

// --- Bayan Strokes ---
// 0: Ghe — Open Maidan/Bass
// 1: Ka  — Closed Syahi
// 2: Tit — Silent/ghost stroke
// 3: Ghi — Half-open Maidan
// 4: Ke  — Closed Syahi edge

int_strike = int(strike + 0.5);
is_open = (int_strike == 0) | (int_strike == 3);
is_closed = (int_strike == 1) | (int_strike == 2) | (int_strike == 4);

// =====================================================
// Exciter
// =====================================================
att = ba.if(is_open, 0.002, 0.001);
rel = ba.if(is_open, 0.02,  0.010);
env = en.ar(att, rel, gate);
exciter_noise = no.noise * env * velocity;

exciter_open = exciter_noise : fi.lowpass(2, 600.0) * 1.5;
exciter_closed = exciter_noise : fi.highpass(2, 200.0) : fi.lowpass(2, 3000.0) * 1.5;
exciter = ba.if(is_open, exciter_open, exciter_closed);

// =====================================================
// Internal Auto-Meend & Pitch Control
// =====================================================
smoothedFreq = freq : si.smoo;

// The wrist presses in over ~80ms after a Ghe strike
meend_env = en.ar(0.08, 0.3, gate) * ba.if(int_strike == 0, 1.0, 0.0);

// Pitch bends upward by 'meend_inc_freq' semitones (scaled by velocity)
meend_target_mult = pow(2.0, meend_inc_freq / 12.0);
meend_multiplier = 1.0 + (meend_env * (meend_target_mult - 1.0) * velocity);
active_freq = smoothedFreq * meend_multiplier;

// =====================================================
// Twin Detuned Waveguide (Eccentric Syahi Mode Splitting)
// =====================================================
// Two parallel waveguides slightly detuned to simulate the 
// mode splitting caused by the off-center Syahi mass.
target_delay_A = ma.SR / active_freq;
target_delay_B = ma.SR / (active_freq * eccentricity);

// =====================================================
// Physical Boundary Reflection Coefficients (rho)
// =====================================================
// The energy preserved each time the wave hits the edge of the drumhead.
// High frequencies hit the boundary more often per second, naturally decaying faster.

// Open Ghe: Boundary is free. The heavy Syahi preserves energy efficiently.
// A rho of ~0.97 at 65 Hz naturally yields exactly a 1.5-second T60.
rho_open = 0.93 + (velocity * 0.04); 

// Half-muted Ghi: Hand rests lightly on skin, absorbing more energy per reflection.
// A rho of ~0.92 at 65 Hz yields a ~0.8-second T60.
rho_ghi = 0.88 + (velocity * 0.04);

// Closed Ka: Hand pressed hard against Syahi, massive immediate absorption.
// A rho of 0.83 yields a ~0.5s T60, ensuring it doesn't choke out before the 100ms snapshot.
rho_closed = 0.83;
rho_tit = 0.70; // Massive immediate absorption for ghost stroke
rho_ke = 0.85;  // Slightly more ring than Ka for Ke edge snap

fb_gain = ba.selectn(5, int_strike, rho_open, rho_closed, rho_tit, rho_ghi, rho_ke);

// Maintain higher cutoff to prevent unnatural high-frequency choking
damping_cutoff = ba.if(is_open, 2000.0, 800.0) + (velocity * 1500.0);
damping_filter = fi.lowpass(1, damping_cutoff);

wgA = exciter : (+ : de.fdelay(4096, target_delay_A)) ~ (damping_filter : *(fb_gain));
wgB = exciter : (+ : de.fdelay(4096, target_delay_B)) ~ (damping_filter : *(fb_gain));

syahi_waveguide = (wgA + wgB) * 0.5;

// =====================================================
// Maidan Resonators (Inharmonic Goatskin Bessel Modes)
// =====================================================
// Bessel ratios approx: 1.59, 2.13, 2.29, 2.65
myResonator(f, t, g, x) = x * 0.002 : + ~ (conv) : * (g)
with {
    r = pow(0.001, 1.0 / (max(0.001, t) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    conv(y) = b1 * y - b2 * y';
};

// Maidan is always active, but coupling mix changes based on stroke
maidan_g1 = 0.8;
maidan_g2 = 0.5;
maidan_g3 = 0.3;
maidan_g4 = 0.2;

// Dynamic Damping (T60 decay time)
// Open strokes ring out (0.15 to 0.4s depending on velocity/pitch). 
// Closed strokes (Ka/Ke) choke the Maidan in 0.03s.
mt_open = 0.15 + (velocity * 0.25) + (((200.0 - active_freq)/150.0) * 0.15);
mt_base = ba.selectn(5, int_strike, mt_open, 0.03, 0.01, mt_open * 0.7, 0.05);

// The wrist pressing into the drum heavily dampens the bare goatskin.
maidan_damping = 1.0 - (meend_env * 0.85); // Kills up to 85% of ringing at peak pressure
mt = mt_base * maidan_damping;

maidan_bank = myResonator(active_freq * 1.593, mt * 0.8, maidan_g1, exciter) +
              myResonator(active_freq * 2.135, mt * 0.6, maidan_g2, exciter) +
              myResonator(active_freq * 2.295, mt * 0.5, maidan_g3, exciter) +
              myResonator(active_freq * 2.653, mt * 0.4, maidan_g4, exciter);

// =====================================================
// Dynamic Membrane Coupling
// =====================================================
// 0: Ghe (50% Syahi, 50% Maidan)
// 1: Ka (20% Syahi, 80% Maidan - heavy damped thap)
// 2: Tit (5% Syahi, 20% Maidan - very faint muted tap)
// 3: Ghi (40% Syahi, 60% Maidan)
// 4: Ke (10% Syahi, 90% Maidan)
syahi_mix = ba.selectn(5, int_strike, 0.5, 0.2, 0.05, 0.4, 0.1);
maidan_mix = ba.selectn(5, int_strike, 0.5, 0.8, 0.20, 0.6, 0.9);

// The entire vibrating membrane (Syahi + Maidan) displaces air into the bowl cavity.
membrane_mix = (syahi_waveguide * syahi_mix) + (maidan_bank * maidan_mix);
bowl_freq = helmholtz_freq(bowl_radius, bowl_volume);
bowl_resonance = membrane_mix : fi.resonbp(bowl_freq, 2.0, 1.5) : fi.lowpass(2, 300.0);

// =====================================================
// Final Mix & Output
// =====================================================
// We hear direct radiation from the skin + radiation out of the bowl
bayan_raw = membrane_mix + (bowl_resonance * 0.9);

dynamicDrive = ba.selectn(5, int_strike, 1.2, 1.5, 0.5, 1.0, 1.6);
process = (bayan_raw * dynamicDrive * 4.0 : ma.tanh) * gain * 3.8869;
