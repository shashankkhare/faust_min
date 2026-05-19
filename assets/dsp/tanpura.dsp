import("stdfaust.lib");

// =====================================================
// TANPURA WITH STABLE FREQUENCY-NORMALIZED JAWARI
// =====================================================

baseFreq = hslider("freq", 130.81, 40, 600, 0.01);

gain = hslider("gain", 0.8, 0, 1, 0.01);

velocity = hslider("velocity", 0.8, 0, 1, 0.01);

gate = button("gate");

// =====================================================
// SEQUENTIAL PLUCKS (same relock pattern as sitar.dsp)
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

stringFreq(i) =
      (i == 0) * (smoothedBaseFreq * 1.5)
    + (i == 1) * (smoothedBaseFreq)
    + (i == 2) * (smoothedBaseFreq)
    + (i == 3) * (smoothedBaseFreq * 0.5);

// =====================================================
// 2D LOOKUP TABLE
// =====================================================

// Columns:
//
// 0 = frequency
// 1 = threshold
// 2 = jivari
// 3 = excDur
// 4 = excGain
// 5 = excLPF
// 6 = dispersion
// 7 = stringGain

cols = 8;
rows = 4;

tableData = waveform {

    // LowSa
    130.81,0.12,0.12,0.0115,0.20,1800,0.10,0.35,

    // Sa
    261.63,0.09,0.09,0.0060,0.28,2600,0.05,0.75,

    // Pa
    392.00,0.07,0.07,0.0040,0.38,3600,0.025,1.00,

    // HighSa
    523.25,0.05,0.05,0.0030,0.45,4500,0.015,0.60
};

// =====================================================
// TABLE ACCESS
// =====================================================

cell(row,col) =
    (tableData, int(row * cols + col)) : rdtable;

// =====================================================
// ROW LOOKUP
// =====================================================

lookupRow(f) =
    (f >= 200.0) * (f < 330.0) * 1.0
    + (f >= 330.0) * (f < 460.0) * 2.0
    + (f >= 460.0) * 3.0;

// =====================================================
// LOOKUPS
// =====================================================

lookupThresh(f)   = cell(lookupRow(f), 1);

lookupJivari(f)   = cell(lookupRow(f), 2);

lookupExcDur(f)   = cell(lookupRow(f), 3);

lookupExcGain(f)  = cell(lookupRow(f), 4);

lookupExcLPF(f)   = cell(lookupRow(f), 5);

lookupDisp(f)     = cell(lookupRow(f), 6);

stringGain(i)     = cell(lookupRow(stringFreq(i)), 7);

// =====================================================
// FIXED FEEDBACK
// =====================================================

// CRITICAL FIX:
// previous formula overdamped loop massively

feedback = 0.99975;

// =====================================================
// EXCITATION (gated by exciteActive)
// =====================================================

pluckExcitation(freqVal, exciteActive) =

    no.noise

    * exciteActive

    * lookupExcGain(freqVal)

    * velocity

    : fi.lowpass(
        1,
        lookupExcLPF(freqVal)
      );

// =====================================================
// FREQUENCY-NORMALIZED JAWARI
// =====================================================

jivariBridge(freqVal, y) =

    (y * 0.9997) + sparkle

with {

    thresh =
        lookupThresh(freqVal);

    jAmt =
        lookupJivari(freqVal);

    env =
        abs(y)
        : si.smooth(0.997);

    excite =
        max(0.0, env - thresh);

    // IMPORTANT:
    // normalize derivative by frequency

    norm =
        sqrt(130.81 / max(130.81, freqVal));

    transient =
        ((y - y') * norm)
        : fi.highpass(1, 2200);

    sparkle =
        transient
        * excite
        * jAmt
        * 0.08;
};

// =====================================================
// STRING MODEL
// =====================================================

jivariString(freqVal, trigSig) =

    pluckExcitation(freqVal, exciteActive)

    :

    + ~

    (
        de.fdelay(
            8192,
            ma.SR / max(20.0, freqVal) - 2.0
        )

        :

        jivariBridge(freqVal)

        :

        fi.allpassnn(
            1,
            lookupDisp(freqVal)
        )

        :

        *(feedback)

        :

        *(exciteActive == 0.0)
    )

with {

    // Rising edge of this string's trigger
    perStringTrig = (trigSig - trigSig') > 0.0;

    // Counter-based pulse (same pattern as sitar.dsp)
    exciteTimer = perStringTrig : trig_pulse
    with {
        trig_pulse(t) = loop ~ _
        with {
            loop(cnt) = ba.if(t > 0.0,
                ba.sec2samp(lookupExcDur(freqVal)),
                max(0.0, cnt - 1.0)
            );
        };
    };
    exciteActive = exciteTimer : >(0.0);
};

// =====================================================
// STRINGS
// =====================================================

s0 =
    jivariString(
        stringFreq(0),
        t0
    ) * stringGain(0);

s1 =
    jivariString(
        stringFreq(1),
        t1
    ) * stringGain(1);

s2 =
    jivariString(
        stringFreq(2),
        t2
    ) * stringGain(2);

s3 =
    jivariString(
        stringFreq(3),
        t3
    ) * stringGain(3);

// =====================================================
// MIX
// =====================================================

mix =
    (
        s0 + s1 + s2 + s3
    )
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
