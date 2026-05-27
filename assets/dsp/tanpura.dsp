import("stdfaust.lib");

// =====================================================
// TANPURA WITH STABLE PARAMETER-DRIVEN JAWARI
// =====================================================

baseFreq = hslider("freq", 130.81, 40, 600, 0.01);
firstFreq = hslider("freq1", 0.0, 0.0, 1000.0, 0.01);

gain = hslider("gain", 0.8, 0, 1, 0.01);

velocity = hslider("velocity", 0.8, 0, 1, 0.01);

gate = button("gate");

// Parameter Sliders (Mappable via companion CSV)
sustain0 = hslider("sustain0", 55.0, 0.1, 1000.0, 0.01);
sustain1 = hslider("sustain1", 35.0, 0.1, 1000.0, 0.01);
sustain2 = hslider("sustain2", 35.0, 0.1, 1000.0, 0.01);
sustain3 = hslider("sustain3", 20.0, 0.1, 1000.0, 0.01);
jivariThreshold = hslider("jivariThreshold", 0.015, 0.0, 1.0, 0.0001);
jivari = hslider("jivari", 0.55, 0.0, 10.0, 0.01);
excDur = hslider("excDur", 0.0115, 0.0001, 1.0, 0.0001);
excGain = hslider("excGain", 0.40, 0.0, 10.0, 0.01);
excLPF = hslider("excLPF", 2000.0, 100.0, 20000.0, 1.0);
dispersion = hslider("dispersion", 0.07, 0.0, 1.0, 0.0001);
stringGainVal0 = hslider("stringGainVal0", 1.0, 0.0, 2.0, 0.01);
stringGainVal1 = hslider("stringGainVal1", 1.0, 0.0, 2.0, 0.01);
stringGainVal2 = hslider("stringGainVal2", 1.0, 0.0, 2.0, 0.01);
stringGainVal3 = hslider("stringGainVal3", 1.0, 0.0, 2.0, 0.01);

// =====================================================
// SEQUENTIAL PLUCKS
// =====================================================

// Internal delay timer controls the gate of each string from the global gate
gate0 = gate;
gate1 = gate @ ba.sec2samp(0.5);
gate2 = gate @ ba.sec2samp(1.0);
gate3 = gate @ ba.sec2samp(1.5);

t0 = (gate0 - gate0') > 0.0;
t1 = (gate1 - gate1') > 0.0;
t2 = (gate2 - gate2') > 0.0;
t3 = (gate3 - gate3') > 0.0;

// =====================================================
// STRING TUNING
// =====================================================

// Pa Sa Sa LowSa

smoothedBaseFreq = baseFreq;
smoothedFirstFreq = ba.if(firstFreq > 0.0, firstFreq, baseFreq * 1.5);

stringFreq(i) =
      (i == 0) * (smoothedFirstFreq)
    + (i == 1) * (smoothedBaseFreq)
    + (i == 2) * (smoothedBaseFreq)
    + (i == 3) * (smoothedBaseFreq * 0.5);

// =====================================================
// LOOP FEEDBACK COEFFICIENT FROM SUSTAIN (T60 DECAY)
// =====================================================

feedback(freqVal, susVal) = exp(-3.0 / (max(0.001, susVal) * ma.SR));

// =====================================================
// EXCITATION (gated by exciteActive)
// =====================================================

pluckExcitation(freqVal, exciteActive) =
    no.noise
    * en.ar(excDur, excDur * 0.5, exciteActive)
    * excGain
    * velocity
    * (baseFreq / max(20.0, freqVal))
    * 0.3
    : fi.lowpass(2, freqVal * 3.0);


// =====================================================
// STRING MODEL WITH JAWARI AT BRIDGE TERMINATION
// =====================================================

// Jawari bridge reflection (matches sitar's fold-over approach)
bridgeReflection(y) = ba.if(y > jivariThreshold, jivariThreshold - delta * (dispersion + jivari * dispersion), y) : min(1.2) : max(-1.2)
with {
    delta = y - jivariThreshold;
};

stringLoop(freqVal, trigSig, susVal) =
    pluckExcitation(freqVal, exciteActive)
    :
    + ~
    (
        de.fdelay(8192, ma.SR / max(20.0, freqVal) - 2.0)
        : fi.allpassnn(1, dispersion)
        : bridgeReflection
        : *(feedback(freqVal, susVal))
        : *(1.0 - perStringTrig)
    )
with {
    perStringTrig = (trigSig - trigSig') > 0.0;
    exciteTimer = perStringTrig : trig_pulse
    with {
        trig_pulse(t) = loop ~ _
        with {
            loop(cnt) = ba.if(t > 0.0, ba.sec2samp(excDur), max(0.0, cnt - 1.0));
        };
    };
    exciteActive = exciteTimer : >(0.0);
};

// =====================================================
// STRINGS
// =====================================================

s0 = stringLoop(stringFreq(0), t0, sustain0) * stringGainVal0;
s1 = stringLoop(stringFreq(1), t1, sustain1) * stringGainVal1;
s2 = stringLoop(stringFreq(2), t2, sustain2) * stringGainVal2;
s3 = stringLoop(stringFreq(3), t3, sustain3) * stringGainVal3;

// =====================================================
// MIX
// =====================================================

mix =
    (
        s0 + s1 + s2 + s3
    )
    * 0.25
    * 30.0
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
