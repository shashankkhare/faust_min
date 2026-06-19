declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Fretless Indian classical string instrument (Sarod) with a metal fingerboard,
// producing bright metallic sustain and sympathetic string resonance.
// The sarod features a unique acoustic system where the bridge rests on a tensioned
// goatskin membrane stretched over a carved teak wood bowl (tumba).
//
// The physical model routes the raw string excitation (dispersion + collision)
// through a series coupling of both resonators: the output of the string
// passes through saturate (nonlinear tanh to emulate skin compression),
// then the membrane bandpass bank (goatskin modes), then the body
// bandpass bank (teak bowl modes). No part of the raw string signal
// bypasses the resonators — every bit of sound passes through both
// the membrane and the body, just like a real sarod.
//
// Parameters (Controls):
//   - freq        — melody note frequency
//   - gate        — trigger (momentary)
//   - velocity    — 0..1
//   - gain        — master volume 0..1
//   - symp_gain   — sympathetic string level 0..1
import("stdfaust.lib");

freq = hslider("freq", 146.83, 40, 1000, 0.01);
gate = button("gate");
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gain = hslider("gain", 1.0, 0, 1, 0.01);
symp_gain = hslider("symp_gain", 0, 0, 1, 0.01);
strike = hslider("strike", 0, 0, 2, 1);
chikari_freq1 = hslider("chikari_freq1", 111.0, 40, 2000, 0.01);
chikari_freq2 = hslider("chikari_freq2", 166.5, 40, 2000, 0.01);
chikari_gain = hslider("chikari_gain", 0.0, 0, 1, 0.01);
j_h = hslider("jawari_hardness", 0.05, 0, 0.5, 0.001);

// Velocity-dependent release time (2ms at vel=0, 10ms at vel=1)
gate_rel = 0.002 + velocity * 0.008;

// Melody excitation trigger
trig = gate > gate';

// Short pluck transient for the excitation noise — gate held for attack to complete
gate_held_pluck = trig : pulse_timer > 0
with {
    pulse_timer(t) = loop ~ _
    with { loop(s) = ba.if(t, 150, max(0.0, s - 1.0)); };
};
pluck_env = en.ar(0.003, 0.015, gate_held_pluck);

// Simulate the hard wooden pick transient (replaces os.impulse so it fires on every note)
pick_impulse = ba.impulsify(trig);

// Wooden plectrum scratch noise
pick_noise = no.noise : fi.bandpass(2, 100.0, 1200.0);

// Base wooden pluck excitation — short transient only!
base_exc = pick_noise * 0.18 * pluck_env * velocity;

// Explicit mathematical routing
is_chikari = strike > 0.5;

// Melody: suppress when chikari strike — let the string coast
melody_exc = base_exc * (1 - is_chikari);

// Chikari: triggers on strike transition OR gate press while in chikari mode
chikari_trig = (is_chikari > is_chikari') | (trig & is_chikari);
chikari_pluck_gate = chikari_trig : chikari_pt > 0
with {
    chikari_pt(t) = loop ~ _
    with { loop(s) = ba.if(t, 150, max(0.0, s - 1.0)); };
};
chikari_pluck_env = en.ar(0.003, 0.015, chikari_pluck_gate);
chikari_trig_exc = (no.noise : fi.bandpass(2, 80.0, 400.0)) * 0.2 * chikari_pluck_env * velocity;

smooth_reset(c, t, x) = loop ~ _
with {
    loop(y1) = ba.if(t, x, x * (1 - c) + y1 * c);
};

// Melody string parameters
melody_freq = (freq * (1 - is_chikari)) : + ~ *(is_chikari);
smooth_melody_freq = melody_freq : smooth_reset(0.999, trig);
normFreq = (smooth_melody_freq - 80.0) / (800.0 - 80.0) : min(1.0) : max(0.0);
dynSustain = 4.0 - normFreq * 3.2; // 4.0s sustain for low notes, 0.8s for high notes
feedback_gain = pow(0.001, 1.0 / (dynSustain * smooth_melody_freq));

del = ma.SR / smooth_melody_freq;

// Fretless steel fingerboard collision model (asymmetric soft clipping)
fingerboard(x) = ba.if(abs(x) > 0.8, sign(x) * (0.8 + (abs(x) - 0.8) * 0.15), x)
with {
    sign(y) = ba.if(y > 0.0, 1.0, -1.0);
};

dispersion = _ <: * (0.2), _' : + : + ~ * (-0.2); // slight stiffness

bridge_contact(x) = max(0, x * 5.0);
jivari_mod = j_h * 600.0;
dynamic_delay(x) = de.fdelay(16384, max(2.0, del - jivari_mod * bridge_contact(x)), x);

melody_gate = max(gate, is_chikari) : si.smoo;
chikari_gate = max(gate, 1 - is_chikari) : si.smoo;

stringLoop = melody_exc : (+ : dynamic_delay) ~ (dispersion : fingerboard : _ * feedback_gain * melody_gate);

// Goatskin membrane modes in parallel (20 non-degenerate eigenmodes from Manaswi et al. 2013)
membrane_filter(x) = 
    (  (x * 0.5)
     + (x : fi.resonbp(150.0,   4.0, 0.50))
     + (x : fi.resonbp(236.7,   4.0, 0.25))
     + (x : fi.resonbp(240.2,   4.0, 0.25))
     + (x : fi.resonbp(315.4,   4.0, 0.45))
     + (x : fi.resonbp(320.7,   4.0, 0.45))
     + (x : fi.resonbp(342.3,   4.0, 0.40))
     + (x : fi.resonbp(386.4,   4.0, 0.35))
     + (x : fi.resonbp(402.7,   4.0, 0.35))
     + (x : fi.resonbp(423.0,   4.0, 0.30))
     + (x : fi.resonbp(438.7,   4.0, 0.30))
     + (x : fi.resonbp(465.3,   4.0, 0.25))
     + (x : fi.resonbp(477.4,   4.0, 0.25))
     + (x : fi.resonbp(498.4,   4.0, 0.20))
     + (x : fi.resonbp(522.9,   4.0, 0.20))
     + (x : fi.resonbp(535.9,   4.0, 0.15))
     + (x : fi.resonbp(544.2,   4.0, 0.15))
     + (x : fi.resonbp(553.6,   4.0, 0.12))
     + (x : fi.resonbp(573.3,   4.0, 0.10))
     + (x : fi.resonbp(606.6,   4.0, 0.08))
     + (x : fi.resonbp(610.3,   4.0, 0.08))
    ) : fi.lowpass(2, 4200.0);

// Wooden body bowl modes in parallel
body_filter(x) = 
    (  (x * 0.5)
     + (x : fi.resonbp(180.0,  4.32, 1.0))
     + (x : fi.resonbp(320.0,  4.32, 0.3))
     + (x : fi.resonbp(550.0,  4.32, 0.3))
     + (x : fi.resonbp(900.0,  4.32, 0.3))
     + (x : fi.resonbp(1600.0, 2.7, 1.0))
     + (x : fi.resonbp(2800.0, 2.7, 1.0))
    );

// Nonlinear saturation emulating goatskin compression
membrane_saturate(x) = ma.tanh(x * 2.0) / 2.0;

// Sympathetic strings (Taraf) — 3 KS delay lines driven by body resonance
// Excited by the membrane/body output, gated so they only receive energy during note-on.
// Feedback keeps them ringing naturally after gate→0.
// Ratios: 1:1 (unison), 3:2 (fifth), 2:1 (octave)
symp_fb = 0.997;
symp_del1 = ma.SR / max(freq, 40.0);
symp_del2 = ma.SR / max(freq * 1.5, 40.0);
symp_del3 = ma.SR / max(freq * 2.0, 40.0);
symp_exc = core * gate;
symp_ks1 = symp_exc : (+ : de.fdelay(16384, symp_del1 - 1.0)) ~ _ * symp_fb;
symp_ks2 = symp_exc : (+ : de.fdelay(16384, symp_del2 - 1.0)) ~ _ * symp_fb;
symp_ks3 = symp_exc : (+ : de.fdelay(16384, symp_del3 - 1.0)) ~ _ * symp_fb;
symp_strings_ks = (symp_ks1 + symp_ks2 + symp_ks3) / 3;

// 4 Chikari strings: detuned pairs (±1 Hz) for each chikari frequency
chikari_string(del, fb, exc) = exc : (+ : de.fdelay(16384, del - 1.0)) ~ (*(0.95) : + ~ *(0.05) : _ * fb * chikari_gate);

chikari_1a_del = ma.SR / (chikari_freq1 - 1.0);
chikari_1a_fb = pow(0.001, 1.0 / (2.5 * (chikari_freq1 - 1.0)));
chikari_1b_del = ma.SR / (chikari_freq1 + 1.0);
chikari_1b_fb = pow(0.001, 1.0 / (2.5 * (chikari_freq1 + 1.0)));
chikari_2a_del = ma.SR / (chikari_freq2 - 1.0);
chikari_2a_fb = pow(0.001, 1.0 / (2.5 * (chikari_freq2 - 1.0)));
chikari_2b_del = ma.SR / (chikari_freq2 + 1.0);
chikari_2b_fb = pow(0.001, 1.0 / (2.5 * (chikari_freq2 + 1.0)));

chikari_amp = chikari_trig_exc * chikari_gain;
chikariLoop = chikari_string(chikari_1a_del, chikari_1a_fb, chikari_amp)
            + chikari_string(chikari_1b_del, chikari_1b_fb, chikari_amp)
            + chikari_string(chikari_2a_del, chikari_2a_fb, chikari_amp)
            + chikari_string(chikari_2b_del, chikari_2b_fb, chikari_amp);

// Series coupling: melody + chikari drive the membrane, then body
// Sympathetic strings driven by body resonance, mixed after core
summed = stringLoop + chikariLoop;
core = summed : membrane_saturate : membrane_filter : body_filter;

// Body-driven sympathetic KS strings (defined after core, mixed before final gain)
process = (core + symp_strings_ks * symp_gain) * gain * 4.8475;
