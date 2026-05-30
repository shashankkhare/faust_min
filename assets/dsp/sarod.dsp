import("stdfaust.lib");

freq = hslider("freq", 146.83, 40, 1000, 0.01);
gate = button("gate");
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gain = hslider("gain", 1.0, 0, 1, 0.01);
symp_gain = hslider("symp_gain", 0.3, 0, 1, 0.01);

trig = gate > gate';
exc_env = en.ar(0.001, 0.02, trig);
exc = (os.impulse * 0.4 + no.noise * 0.6) * exc_env * velocity;

del = ma.SR / freq;
linear_fdelay(maxDel, d, x) = (1.0 - frac) * x1 + frac * x2
with {
    int_del = int(d);
    frac = d - int_del;
    x1 = de.delay(maxDel, int_del, x);
    x2 = de.delay(maxDel, int_del + 1, x);
};

// Sarod has a metal fingerboard, giving a very bright and slightly metallic sustain
// without the extreme buzz (jivari) of a sitar.
lp = * (0.995) : + ~ * (0.005);
dispersion = _ <: * (0.2), _' : + : + ~ * (-0.2); // slight stiffness

stringLoop = exc : (+ : linear_fdelay(16384, del - 1.0)) ~ (lp : dispersion : _ * 0.998);

// Sympathetic strings (Taraf)
symp_mode(ratio, x) = x : + ~ feedback
with {
    omega = 2.0 * ma.PI * (freq * ratio) / ma.SR;
    r = pow(0.001, 1.0 / (2.0 * ma.SR)); // 2 second T60
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    feedback(y) = (b1 * y - b2 * y');
};

symp_sum(x) = symp_mode(1.000, x)
            + symp_mode(1.250, x)
            + symp_mode(1.500, x)
            + symp_mode(2.000, x)
            + symp_mode(3.000, x);

process = (stringLoop + symp_sum(stringLoop) * symp_gain) * gain * 0.8 : min(1.0) : max(-1.0);
