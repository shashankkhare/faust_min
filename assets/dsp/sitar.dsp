import("stdfaust.lib");

freq = hslider("freq [unit:Hz]", 146.83, 40, 1000, 0.01);
gate = button("gate");
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
jivari = hslider("jivari", 0.5, 0, 1, 0.01);
symp_gain = hslider("symp_gain", 0.2, 0, 1, 0.01);

// =====================================================
// Dynamic parameter mapping (Matches original C++ updateInternal)
// =====================================================
normFreq = (freq - 80.0) / (600.0 - 80.0) : min(1.0) : max(0.0);
dynSustain = 9.0 - normFreq * 3.0;
feedback = pow(0.001, 1.0 / (dynSustain * freq));
dynThreshold = 0.08 + normFreq * 0.04;
dynDispersion = 0.35 - normFreq * 0.20;
dynStrikeScale = 0.25 - normFreq * 0.05;
dynDamping = 0.97 + normFreq * 0.01;
dynDC = 0.985 + normFreq * 0.01;
dynFold = 0.85 - normFreq * 0.25;
dynOutputGain = 1.0 + normFreq * 1.5;
dynTarafT60 = 1.2 - normFreq * 0.6;

// =====================================================
// Trigger & 24-sample Micro-Strike Excitation
// =====================================================
trig = (gate - gate') > 0;
excite_counter = trig : pulse_timer
with {
    pulse_timer(t) = loop ~ _
    with {
        loop(s) = ba.if(t, 24, max(0.0, s - 1.0));
    };
};
excite_active = excite_counter > 0;
excite_phase = (24.0 - excite_counter) / 24.0;
pulse = sin(2.0 * ma.PI * excite_phase);
exc = (pulse * 0.5 + no.noise * 0.5) * velocity * dynStrikeScale * excite_active;

// =====================================================
// Delay Line
// =====================================================
del = ma.SR / freq;
linear_fdelay(maxDel, d, x) = (1.0 - frac) * x1 + frac * x2
with {
    int_del = int(d);
    frac = d - int_del;
    x1 = de.delay(maxDel, int_del, x);
    x2 = de.delay(maxDel, int_del + 1, x);
};

// =====================================================
// Loop Filters & Bridge
// =====================================================
jivari_bridge(sig) = ba.if(sig > dynThreshold, dynThreshold - delta * (dynFold + jivari * dynFold), sig) : min(1.2) : max(-1.2)
with {
    delta = sig - dynThreshold;
};

// Loop low-pass damping
lp = * (dynDamping) : + ~ * (1.0 - dynDamping);

// Dispersion cascade (4 stages)
ap_stage = (_ <: * (a), _' : +) : + ~ * (-a) with { a = dynDispersion; };
dispersion = ap_stage : ap_stage : ap_stage : ap_stage;

// DC blocker
dcblock = (_ <: _, _' : -) : + ~ * (dynDC);

// Safety clipper
saturated(x) = x : min(1.0) : max(-1.0);

// Waveguide Loop
stringLoop = exc : (+ : linear_fdelay(16384, del - 1.0)) ~ (jivari_bridge : lp : _ * feedback : dispersion : dcblock : saturated : _ * (excite_active == 0));

// =====================================================
// Sympathetic Strings
// =====================================================
symp_mode(ratio, x) = x : + ~ feedback
with {
    omega = 2.0 * ma.PI * (freq * ratio) / ma.SR;
    r = pow(0.001, 1.0 / (dynTarafT60 * ma.SR));
    b1 = 2.0 * r * cos(omega);
    b2 = r * r;
    feedback(y) = (b1 * y - b2 * y') * (excite_active == 0);
};

symp_sum(x) = symp_mode(1.000, x)
            + symp_mode(1.125, x)
            + symp_mode(1.250, x)
            + symp_mode(1.333, x)
            + symp_mode(1.500, x)
            + symp_mode(1.666, x)
            + symp_mode(1.875, x)
            + symp_mode(2.000, x)
            + symp_mode(2.250, x)
            + symp_mode(2.500, x)
            + symp_mode(3.000, x);

symp_out(x) = x + symp_sum(x) * symp_gain;

// =====================================================
// Final Process
// =====================================================
process = symp_out(stringLoop) * gain * dynOutputGain : ma.tanh;