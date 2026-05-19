import("stdfaust.lib");

// =====================================================
// Warm Meditative Tanpura
// =====================================================

baseFreq = hslider("freq", 130.81, 40, 400, 0.01);

freq1 =
    hslider("freq1", 0, 0, 1000, 0.01);

gain =
    hslider("gain", 0.7, 0, 1, 0.01);

velocity =
    hslider("velocity", 0.7, 0, 1, 0.01);

jivari =
    hslider("jivari", 0.35, 0, 1, 0.01);

gate =
    button("gate");

// =====================================================
// Trigger
// =====================================================

trig = gate : ba.impulsify;

// =====================================================
// String timing
// =====================================================

t0 = trig;

t1 = trig @ ba.sec2samp(0.45);

t2 = trig @ ba.sec2samp(0.90);

t3 = trig @ ba.sec2samp(1.35);

// =====================================================
// Tuning
// =====================================================

f0 = baseFreq : si.smoo;

f1 =
    ba.if(freq1 > 0.0,
        freq1,
        baseFreq * 1.5)
    : si.smoo;

// Sa Pa Sa Sa
stringFreq(i) =
      (i == 0) * f0
    + (i == 1) * f1
    + (i == 2) * (f0 * 2.0)
    + (i == 3) * (f0 * 2.0);

// =====================================================
// Gentle Pluck Excitation
// =====================================================

exc_counter(t) = loop ~ _
with {
    loop(s) =
        ba.if(t > 0.0,
            ba.sec2samp(0.012),
            max(0.0, s - 1.0));
};

// Softer filtered pluck
pluck(t) =
    (
        no.noise
        : fi.lowpass(1, 1800)
    )
    * (exc_counter(t) > 0.0)
    * 0.12
    * velocity;

// =====================================================
// Soft Jivari
// =====================================================

// Dynamic damping instead of clipping
soft_jivari(x) =
    x * (
        1.0
        - jivari
        * smooth(x)
        * 0.12
    )
with {
    smooth(y) =
        abs(y) / (1.0 + abs(y));
};

// =====================================================
// Warm String Loop
// =====================================================

tanpuraString(freq, trigSig) =
    pluck(trigSig)
    :
    + ~ (
        de.delay(
            8192,
            ma.SR / max(20.0, freq) - 2.0
        )
        : soft_jivari
        : fi.lowpass(1, 1600)
        : fi.dcblocker
        : *(0.9988)
    );

// =====================================================
// 4 Strings
// =====================================================

s0 = tanpuraString(stringFreq(0), t0);

s1 = tanpuraString(stringFreq(1), t1);

s2 = tanpuraString(stringFreq(2), t2);

s3 = tanpuraString(stringFreq(3), t3);

// =====================================================
// Air Resonance
// =====================================================

air =
    (
        no.noise
        : fi.highpass(1, 5000)
    )
    * 0.0015;

// =====================================================
// Final Drone
// =====================================================

mix =
    (
        s0 + s1 + s2 + s3
    ) * 0.22;

process =
    (mix + air)
    * gain;