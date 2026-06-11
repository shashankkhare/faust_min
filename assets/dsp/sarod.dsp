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
symp_gain = hslider("symp_gain", 0.3, 0, 1, 0.01);
strike = hslider("strike", 0, 0, 2, 1);
chikari_freq = hslider("chikari_freq", 440.0, 40, 2000, 0.01);
j_h = hslider("jawari_hardness", 0.05, 0, 0.5, 0.001);

// Melody excitation trigger
trig = gate > gate';

// Gate holds for the full note duration (based on dynSustain)
// dynSustain varies from 4s (low notes) to 0.8s (high notes)
gate_dur = int((0.12 + dynSustain * 0.8) * ma.SR);
gate_held = trig : pulse_timer > 0
with {
    pulse_timer(t) = loop ~ _
    with { loop(s) = ba.if(t, gate_dur, max(0.0, s - 1.0)); };
};

// Paper-based ADSR envelope: attack=0.0018s, decay=0.1088s, sustain=0.3532, release=0.3s
note_env = en.adsr(0.0018, 0.1088, 0.3532, 0.3, gate_held);

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
pick_noise = no.noise : fi.bandpass(2, 300.0, 800.0);

// Base wooden pluck excitation — short transient only!
base_exc = pick_noise * 0.2 * pluck_env * velocity;

// Explicit mathematical routing
is_chikari = strike > 0.5;

// Melody: suppress when chikari strike — let the string coast
melody_exc = base_exc * (1 - is_chikari);

// Chikari: independent trigger on rising edge of strike (no gate needed)
chikari_trig = is_chikari > is_chikari';
chikari_pluck_gate = chikari_trig : chikari_pt > 0
with {
    chikari_pt(t) = loop ~ _
    with { loop(s) = ba.if(t, 150, max(0.0, s - 1.0)); };
};
chikari_pluck_env = en.ar(0.003, 0.015, chikari_pluck_gate);
chikari_trig_exc = (no.noise : fi.bandpass(2, 300.0, 800.0)) * 0.2 * chikari_pluck_env * velocity;

// Melody string parameters
normFreq = (freq - 80.0) / (800.0 - 80.0) : min(1.0) : max(0.0);
dynSustain = 4.0 - normFreq * 3.2; // 4.0s sustain for low notes, 0.8s for high notes
feedback_gain = pow(0.001, 1.0 / (dynSustain * freq));

lp = * (0.1) : + ~ * (0.9);

del = ma.SR / freq;

linear_fdelay(maxDel, d, x) = (1.0 - frac) * x1 + frac * x2
with {
    int_del = int(d);
    frac = d - int_del;
    x1 = de.delay(maxDel, int_del, x);
    x2 = de.delay(maxDel, int_del + 1, x);
};

// Fretless steel fingerboard collision model (asymmetric soft clipping)
fingerboard(x) = ba.if(abs(x) > 0.04, sign(x) * (0.04 + (abs(x) - 0.04) * 0.15), x)
with {
    sign(y) = ba.if(y > 0.0, 1.0, -1.0);
};

dispersion = _ <: * (0.2), _' : + : + ~ * (-0.2); // slight stiffness

// Jawari (bridge) nonlinearity: asymmetric cubic — positive excursions catch the bridge edge
// producing the characteristic nasal buzzing/singing tone
jawari(x) = x * (1.0 + j_h * max(0.0, x) * max(0.0, x));

stringLoop = melody_exc : (+ : linear_fdelay(16384, del - 1.0)) ~ (jawari : lp : dispersion : fingerboard : _ * feedback_gain);

// Goatskin membrane modes in parallel (20 non-degenerate eigenmodes from Manaswi et al. 2013)
membrane_filter(x) = 
    (  (x : fi.resonbp(150.0,   12.0, 0.5))
     + (x : fi.resonbp(236.7,   12.0, 0.5))
     + (x : fi.resonbp(240.2,   12.0, 0.5))
     + (x : fi.resonbp(315.4,   12.0, 0.5))
     + (x : fi.resonbp(320.7,   12.0, 0.5))
     + (x : fi.resonbp(342.3,   12.0, 0.5))
     + (x : fi.resonbp(386.4,   12.0, 0.5))
     + (x : fi.resonbp(402.7,   12.0, 0.03))
     + (x : fi.resonbp(423.0,   12.0, 0.03))
     + (x : fi.resonbp(438.7,   12.0, 0.03))
     + (x : fi.resonbp(465.3,   12.0, 0.03))
     + (x : fi.resonbp(477.4,   12.0, 0.03))
     + (x : fi.resonbp(498.4,   12.0, 0.03))
     + (x : fi.resonbp(522.9,   12.0, 0.5))
     + (x : fi.resonbp(535.9,   12.0, 0.5))
     + (x : fi.resonbp(544.2,   12.0, 0.5))
     + (x : fi.resonbp(553.6,   12.0, 0.5))
     + (x : fi.resonbp(573.3,   12.0, 0.5))
     + (x : fi.resonbp(606.6,   12.0, 0.5))
     + (x : fi.resonbp(610.3,   12.0, 0.5))
    ) : fi.lowpass(2, 4200.0);

// Wooden body bowl modes in parallel
body_filter(x) = 
    (  (x : fi.resonbp(180.0,  8.0, 1.0))
     + (x : fi.resonbp(320.0,  8.0, 0.3))
     + (x : fi.resonbp(550.0,  8.0, 0.3))
     + (x : fi.resonbp(900.0,  8.0, 0.3))
     + (x : fi.resonbp(1600.0, 5.0, 1.0))
     + (x : fi.resonbp(2800.0, 5.0, 1.0))
    );

// Nonlinear saturation emulating goatskin compression
membrane_saturate(x) = ma.tanh(x * 2.0) / 2.0;

// Sympathetic strings (Taraf) with detuned pairs for beating (per paper)
// Each sympathetic string is an independent sine oscillator with an EMG-inspired envelope:
//   rise to peak in μ seconds, then exponential decay at rate σ.
// 4 detuned pairs (fundamental, 3rd, octave, 12th) for audible beating.

// Sympathetic timer: fires on trig, counts down from max_frames to 0
symp_max_frames = int(3.5 * ma.SR);
symp_timer(t) = loop ~ _
with { loop(s) = ba.if(t, symp_max_frames, max(0.0, s - 1.0)); };

symp_trig = trig + chikari_trig;
symp_timer_raw = symp_trig : symp_timer;
symp_hold = symp_timer_raw > 0;
symp_elapsed = (symp_max_frames - symp_timer_raw) / ma.SR;

// EMG-inspired envelope: rise to peak over mu seconds, then exponential decay at rate sigma
// lam = peak amplitude
symp_env(mu, sigma, lam) = lam * (1.0 - exp(-4.0 * symp_elapsed / max(mu, 0.001))) * exp(-sigma * max(0.0, symp_elapsed - mu));

// Sympathetic base frequency follows trigger source: chikari_freq on chikari stroke, freq on melody
symp_base = ba.if(is_chikari, chikari_freq, freq);

// Each sympathetic string = sine oscillator × EMG envelope
symp_string(ratio, detune, mu, sigma, lam) = os.osc(symp_base * ratio * detune) * symp_env(mu, sigma, lam);

// 4 detuned pairs with EMG params (mu=time-to-peak, sigma=decay-rate, lam=peak-amp)
// Lower strings: slower attack, longer ring. Higher strings: faster attack, shorter ring.
symp_strings = symp_string(1.000, 1.000, 0.12, 1.5, 0.05)
             + symp_string(1.000, 0.998, 0.12, 1.5, 0.05)
             + symp_string(1.500, 1.000, 0.15, 1.2, 0.03)
             + symp_string(1.500, 0.998, 0.15, 1.2, 0.03)
             + symp_string(2.000, 1.000, 0.10, 1.8, 0.04)
             + symp_string(2.000, 0.998, 0.10, 1.8, 0.04)
             + symp_string(3.000, 1.000, 0.20, 1.0, 0.02)
             + symp_string(3.000, 0.998, 0.20, 1.0, 0.02);

// 4 Chikari strings: 2×Sa, 2×Pa — all Karplus-Strong delay lines with independent sustain
chikari_string(del, fb, exc) = exc : (+ : linear_fdelay(16384, del - 1.0)) ~ (*(0.95) : + ~ *(0.05) : _ * fb);

chikari_sa_del = ma.SR / chikari_freq;
chikari_sa_fb = pow(0.001, 1.0 / (2.5 * chikari_freq));
chikari_pa_del = ma.SR / (chikari_freq * 1.5);
chikari_pa_fb = pow(0.001, 1.0 / (2.5 * chikari_freq * 1.5));

chikari_amp = chikari_trig_exc * 0.25;
chikariLoop = chikari_string(chikari_sa_del, chikari_sa_fb, chikari_amp)
            + chikari_string(chikari_sa_del, chikari_sa_fb, chikari_amp)
            + chikari_string(chikari_pa_del, chikari_pa_fb, chikari_amp)
            + chikari_string(chikari_pa_del, chikari_pa_fb, chikari_amp);

// Series coupling: melody + chikari + sympathetic strings drive the membrane, then body
// All three pass through the goatskin saturate → membrane modes → body modes
summed = stringLoop + chikariLoop + symp_strings * symp_gain;
core = summed : membrane_saturate : membrane_filter : body_filter;

process = core * gain * 3.5 : ma.tanh;
