declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Chinese zither (Guzheng) modeled using plucked waveguide strings, string damping, and pluck noise with optional rapid plucking (lunzhi) emulation.
//
// Parameters (Controls):
//   - freq
//   - gate
//   - velocity
//   - gain
//   - damping
//   - pluck_noise
// =============================================================================
import("stdfaust.lib");

// Expert Play Range: Guzheng typical range C2 (65 Hz) to C6 (1046 Hz).
freq = hslider("freq", 440.0, 65, 1046, 0.01);
gate = button("gate");
velocity = hslider("velocity", 0.8, 0, 1, 0.01) : si.smoo;
gain = hslider("gain", 1.0, 0, 5.0, 0.01) : si.smoo;
damping = hslider("damping", 0.995, 0.900, 0.9999, 0.0001) : si.smoo;
pluck_noise = hslider("pluck_noise", 0.5, 0.0, 1.0, 0.01) : si.smoo;

// Tremolo for lunzhi (rapid plucking), we'll add an LFO trigger if gate is held, but Guzheng is often single pluck
// Excitation pulse
trig = gate > gate';
exc = os.impulse * velocity * (1.0 - pluck_noise) + no.noise * velocity * pluck_noise * (trig : env)
with {
    env = en.ar(0.001, 0.02);
};

// Delay line for KS model
del = ma.SR / freq;
linear_fdelay(maxDel, d, x) = (1.0 - frac) * x1 + frac * x2
with {
    int_del = int(d);
    frac = d - int_del;
    x1 = de.delay(maxDel, int_del, x);
    x2 = de.delay(maxDel, int_del + 1, x);
};

// Damping filter (Guzheng has bright attack but long sustain)
lp = * (0.999) : + ~ * (0.001); // Very light damping for long sustain

string = exc : (+ : linear_fdelay(16384, del - 1.0)) ~ (lp : _ * damping);

// Add a slight chorus for the rich resonant body
chorus = _ <: _, de.fdelay(4096, 200 + os.osc(0.5)*100) : + : _ * 0.5;

process = string : chorus : *(gain) : min(1.0) : max(-1.0);
