declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Indian drone lute (Tanpura) featuring stable, parameter-driven jawari (buzzing bridge) emulation.
// Designed as a single-string physical model to be instantiated polyphonically by the orchestrator.
//
// Parameters (Controls):
//   - freq
//   - gain
//   - velocity
//   - gate
//   - sustain
//   - jivariThreshold
//   - jivari
//   - excDur
//   - excGain
//   - excLPF
//   - dispersion
//   - stringGainVal
// =============================================================================
import("stdfaust.lib");

// =====================================================
// TANPURA WITH STABLE PARAMETER-DRIVEN JAWARI
// =====================================================

// Expert Play Range: Tanpura typical male/female base frequencies 130-300 Hz.
freq = hslider("freq", 130.81, 130, 300, 0.01);
smoothedFreq = freq : si.smoo;

gain = hslider("gain", 0.8, 0, 100, 0.01);

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

t0 = (gate - gate') > 0.0;

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
    * (freq / max(20.0, freqVal))
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
// SINGLE STRING
// =====================================================

s0 = stringLoop(smoothedFreq, t0, sustain) * stringGainVal;

// =====================================================
// MIX
// =====================================================

mix =
    s0
    * 30.0
    * gain
    * 4.5081;

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

