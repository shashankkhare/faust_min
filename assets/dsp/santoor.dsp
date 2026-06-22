declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Indian hammered dulcimer (Santoor) simulating multiple strings struck with light wooden mallets (mezrab).
//
// Parameters (Controls):
//   - freq
//   - gate
//   - velocity
//   - gain
// =============================================================================
import("stdfaust.lib");

// Expert Play Range: Santoor typical range C3 (130 Hz) to C6 (1046 Hz).
freq = hslider("freq", 440.0, 130, 1046, 0.01);
gate = button("gate");
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gain = hslider("gain", 1.0, 0, 1, 0.01);

trig = gate > gate';

// Struck with a small wooden mallet
exc = os.impulse * velocity * 0.8 + no.noise * en.ar(0.001, 0.01, trig) * velocity * 0.2;

// Fractional delay
linear_fdelay(maxDel, d, x) = (1.0 - frac) * x1 + frac * x2
with {
    int_del = int(d);
    frac = d - int_del;
    x1 = de.delay(maxDel, int_del, x);
    x2 = de.delay(maxDel, int_del + 1, x);
};

// Santoor strings are struck in courses of 3, slightly detuned.
santoor_string(f, detune) = exc : (+ : linear_fdelay(4096, del - 1.0)) ~ (lp : _ * 0.999)
with {
    actual_freq = f * detune;
    del = ma.SR / actual_freq;
    lp = * (0.95) : + ~ * (0.05); // Brighter than guitar, less damped
};

// 3 strings per note
s1 = santoor_string(freq, 1.000);
s2 = santoor_string(freq, 1.002);
s3 = santoor_string(freq, 0.998);

process = (s1 + s2 + s3) * gain * 0.5 : min(1.0) : max(-1.0);
