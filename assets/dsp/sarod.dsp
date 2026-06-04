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

// Melody excitation trigger
trig = gate > gate';

// Hold the gate for 150 samples (~3ms) to allow en.ar to reach full attack
gate_held = trig : pulse_timer > 0
with {
    pulse_timer(t) = loop ~ _
    with { loop(s) = ba.if(t, 150, max(0.0, s - 1.0)); };
};

// Original AR envelope, now properly opening on every note
exc_env = en.ar(0.003, 0.015, gate_held);

// Simulate the hard wooden pick transient (replaces os.impulse so it fires on every note)
pick_impulse = ba.impulsify(trig);

// Wooden plectrum scratch noise
pick_noise = no.noise : fi.bandpass(2, 800.0, 1600.0);

// Melody string excitation: sharp wooden click + scratchy noise, but less prominent
melody_exc = (pick_impulse * 0.1 + pick_noise * 0.4) * exc_env * velocity * 2.0;

// Melody string parameters
normFreq = (freq - 80.0) / (800.0 - 80.0) : min(1.0) : max(0.0);
dynSustain = 4.0 - normFreq * 3.2; // 4.0s sustain for low notes, 0.8s for high notes
feedback_gain = pow(0.001, 1.0 / (dynSustain * freq));

dynDamping = 0.985 + normFreq * 0.005; // 0.015 damping at low freqs, 0.01 at high freqs
lp = * (dynDamping) : + ~ * (1.0 - dynDamping);

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

stringLoop = melody_exc : (+ : linear_fdelay(16384, del - 1.0)) ~ (lp : dispersion : fingerboard : _ * feedback_gain);

// Goatskin membrane modes in parallel + nonlinear saturation
membrane_filter(x) = 
    (  (x : fi.resonbp(150.0,  10.0, 1.0))
     + (x : fi.resonbp(238.5,  10.0, 1.0))
     + (x : fi.resonbp(321.0,  15.0, 1.0))
     + (x : fi.resonbp(397.5,  5.0, 1.0))
     + (x : fi.resonbp(438.0,  5.0, 1.0))
     + (x : fi.resonbp(550.0,  15.0, 1.0))
    ) : fi.lowpass(2, 4200.0);

// Wooden body bowl modes in parallel
body_filter(x) = 
    (  (x : fi.resonbp(180.0,  10.0, 1.0))
     + (x : fi.resonbp(320.0,  15.0, 1.0))
     + (x : fi.resonbp(550.0,  15.0, 1.0))
     + (x : fi.resonbp(900.0,  10.0, 1.0))
     + (x : fi.resonbp(1600.0, 5.0, 1.0))
     + (x : fi.resonbp(2800.0, 5.0, 1.0))
    );

// Nonlinear saturation emulating goatskin compression
membrane_saturate(x) = ma.tanh(x * 2.0) / 2.0;

// Sympathetic strings (Taraf) with tighter decay
symp_mode(ratio, x) = (x : + ~ feedback) * (1.0 - r)
with {
    omega = 2.0 * ma.PI * (freq * ratio) / ma.SR;
    r = pow(0.001, 1.0 / (1.2 * ma.SR)); // 1.2 second T60
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    feedback(y) = (b1 * y - b2 * y');
};

symp_sum(x) = symp_mode(1.000, x)
            + symp_mode(1.500, x)
            + symp_mode(2.000, x)
            + symp_mode(3.000, x);

// Series coupling: string + sympathetic strings both drive the membrane, then body
summed = stringLoop + symp_sum(stringLoop) * symp_gain * 2.0;
core = summed : membrane_saturate : membrane_filter : body_filter;

process = core * gain * 3.5 : ma.tanh;
