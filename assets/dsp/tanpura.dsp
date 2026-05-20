import("stdfaust.lib");

// =====================================================
// TANPURA WITH STABLE PARAMETER-DRIVEN JAWARI
// =====================================================

baseFreq = hslider("freq", 130.81, 40, 600, 0.01);
firstFreq = hslider("freq1", 196.22, 40, 600, 0.01);

gain = hslider("gain", 0.8, 0, 1, 0.01);

velocity = hslider("velocity", 0.8, 0, 1, 0.01);

gate = button("gate");

// Parameter Sliders (Mappable via companion CSV)
sustain = hslider("sustain", 35.0, 0.1, 1000.0, 0.01);
jivariThreshold = hslider("jivariThreshold", 0.015, 0.0, 1.0, 0.0001);
jivari = hslider("jivari", 0.55, 0.0, 10.0, 0.01);
excDur = hslider("excDur", 0.0115, 0.0001, 1.0, 0.0001);
excGain = hslider("excGain", 0.40, 0.0, 10.0, 0.01);
excLPF = hslider("excLPF", 2000.0, 100.0, 20000.0, 1.0);
dispersion = hslider("dispersion", 0.07, 0.0, 1.0, 0.0001);
stringGainVal = hslider("stringGainVal", 1.0, 0.0, 2.0, 0.01);

// =====================================================
// SEQUENTIAL PLUCKS
// =====================================================

// Rising edge detector (1-sample impulse per note-on)
rawTrig = (gate - gate') > 0.0;

// Each string gets the raw trigger with staggered delays
t0 = rawTrig;
t1 = rawTrig @ ba.sec2samp(0.5);
t2 = rawTrig @ ba.sec2samp(1.0);
t3 = rawTrig @ ba.sec2samp(1.5);

// =====================================================
// STRING TUNING
// =====================================================

// Pa Sa Sa LowSa

smoothedBaseFreq = baseFreq : si.smoo;
smoothedFirstFreq = firstFreq : si.smoo;

stringFreq(i) =
      (i == 0) * (smoothedFirstFreq)
    + (i == 1) * (smoothedBaseFreq)
    + (i == 2) * (smoothedBaseFreq)
    + (i == 3) * (smoothedBaseFreq * 0.5);

// =====================================================
// LOOP FEEDBACK COEFFICIENT FROM SUSTAIN (T60 DECAY)
// =====================================================

feedback(freqVal) = exp(-3.0 / (max(0.1, sustain) * freqVal));

// =====================================================
// EXCITATION (gated by exciteActive)
// =====================================================

pluckExcitation(freqVal, exciteActive) =
    no.noise
    * exciteActive
    * excGain
    * velocity
    : fi.lowpass(1, excLPF);

// =====================================================
// FREQUENCY-NORMALIZED JAWARI
// =====================================================

jivariBridge(freqVal, y) =
    y * (0.9997 - excite * 0.8) + sparkle
with {
    thresh = jivariThreshold;
    jAmt = jivari;
    env = abs(y) : si.smooth(0.997);
    excite = max(0.0, env - thresh) : min(0.5);
    transient = (y - y') : fi.highpass(1, 2200);
    sparkle = transient * excite * jAmt;
};

// =====================================================
// STRING MODEL
// =====================================================

jivariString(freqVal, trigSig) =
    pluckExcitation(freqVal, exciteActive)
    :
    + ~
    (
        de.fdelay(8192, ma.SR / max(20.0, freqVal) - 2.0)
        : jivariBridge(freqVal)
        : fi.allpassnn(1, dispersion)
        : *(feedback(freqVal))
        : min(0.99) : max(-0.99)
        : *(1.0 - perStringTrig)
    )
with {
    // Rising edge of this string's trigger
    perStringTrig = (trigSig - trigSig') > 0.0;

    // Counter-based pulse
    exciteTimer = perStringTrig : trig_pulse
    with {
        trig_pulse(t) = loop ~ _
        with {
            loop(cnt) = ba.if(t > 0.0,
                ba.sec2samp(excDur),
                max(0.0, cnt - 1.0)
            );
        };
    };
    exciteActive = exciteTimer : >(0.0);
};

// =====================================================
// STRINGS
// =====================================================

s0 = jivariString(stringFreq(0), t0) * stringGainVal;
s1 = jivariString(stringFreq(1), t1) * stringGainVal;
s2 = jivariString(stringFreq(2), t2) * stringGainVal;
s3 = jivariString(stringFreq(3), t3) * stringGainVal;

// =====================================================
// MIX
// =====================================================

mix =
    (
        s0 + s1 + s2 + s3
    )
    * 0.25
    * gain;

// =====================================================
// SOFT LIMITER
// =====================================================

softclip(x) =
    x / (1.0 + abs(x));

// =====================================================
// OUTPUT
// =====================================================

process =
    mix
    : fi.dcblocker
    : softclip;
