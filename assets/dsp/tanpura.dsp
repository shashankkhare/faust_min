declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
declare options "[nvoices:4]";

// =============================================================================
// === PRODUCTION CONCERT TANPURA (GLITCH-FREE LAGRANGE ENGINE) ===
// Description: Fixed the undefined symbol by upgrading to de.fdelayltv.
//              Uses robust 3rd-order time-varying Lagrange polynomial
//              interpolation to natively handle dynamic sample-rate pointer modulation.
// =============================================================================
import("stdfaust.lib");

freq = hslider("freq", 130.81, 130, 300, 0.01);
smoothedFreq = freq : si.smoo;

gain = hslider("gain", 0.5, 0, 1.0, 0.01); 
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");

sustain = hslider("sustain", 25.0, 0.1, 45.0, 0.01);
jivariThreshold = hslider("jivariThreshold", 0.015, 0.0, 1.0, 0.0001);

// --- FIXED JIVARI SLIDER (Strictly Normalized 0.0 to 1.0 Range) ---
jivari = hslider("jivari", 0.5, 0.0, 1.0, 0.01);

// Expert Control: Hard-coded pitch glide depth
glideDepth = 3.5; 

excDur = hslider("excDur", 0.0115, 0.0001, 0.1, 0.0001);
excGain = hslider("excGain", 0.40, 0.0, 1.0, 0.01);
excLPF = hslider("excLPF", 2000.0, 100.0, 20000.0, 1.0);
dispersion = hslider("dispersion", 0.07, 0.0, 1.0, 0.0001);
stringGainVal = hslider("stringGainVal", 1.0, 0.0, 2.0, 0.01);

t0 = (gate - gate') > 0.0;
pitchChanged = (freq != freq');

eraseTrigger = t0 + pitchChanged : >(0.0);
antiGlitchLoss = 1.0 - (eraseTrigger : si.smooth(ba.tau2pole(0.008)));

feedback(freqVal, susVal) = exp(-3.0 / (max(20.0, freqVal) * max(0.001, susVal))) * 0.9996;

pluckExcitation(freqVal, exciteActive) =
    no.noise
    * en.ar(excDur, excDur * 0.5, exciteActive)
    * excGain
    * velocity
    * (freq / max(20.0, freqVal));

// =====================================================
// STRING ENGINE WITH POLYNOMIAL LAGRANGE INTERPOLATION
// =====================================================
stringLoop(freqVal, trigSig, susVal) =
    pluckExcitation(freqVal, exciteActive)
    :
    + ~ (waveguideNode)
with {
    basePeriod = ma.SR / max(20.0, freqVal);

    // FIXED: Corrected syntax to de.fdelayltv(Order, MaxDelay, TargetDelay)
    // Using 3rd-order (N=3) polynomial interpolation for bright, precise sheen.
    // Minimum delay boundary raised slightly to guarantee Lagrange filter stability.
    waveguideNode(y) = de.fdelayltv(3, 8192, targetDelay, y)
                     : fi.allpassnn(1, dispersion)
                     : *(feedback(freqVal, susVal))
                     : *(antiGlitchLoss)
    with {
        shorteningAmount = ba.if(y < -jivariThreshold, glideDepth * 0.8, 0.0);
        targetDelay = max(6.0, basePeriod - 2.0 - shorteningAmount); 
    };

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

// =============================================================================
// === THE TWO-SIGNAL SPLIT PIPELINE ===
// =============================================================================
cleanString(x) = x;

bridgeBuzz(x) = x - jivariTerm
with {
    delta = max(0.0, -jivariThreshold - x);
    normX = delta * 3.5;
    
    cubicTerm = (normX * normX * normX) * 0.22;
    quinticTerm = (normX * normX * normX * normX * normX) * 0.10;
    
    jivariTerm = cubicTerm + quinticTerm;
};

// =============================================================================
// === PRODUCTION CONCERT TANPURA GOURD RESONATOR ===
// =============================================================================
gourdResonator(x) = x <: (toombaAir + tabliWood + jawariPresence + soundholeShimmer) :> _
with {
    toombaAir       = fi.resonbp(105.0, 3.0, 0.45);  
    tabliWood      = fi.resonbp(250.0, 3.0, 0.35);  
    jawariPresence = fi.resonbp(720.0, 5.0,  0.15);  
    soundholeShimmer = fi.resonbp(1450.0, 3.0, 0.08);  
};

// =====================================================
// MAIN MIX AND CONSTANT-POWER CROSSFADE PIPELINE
// =====================================================
s0 = stringLoop(smoothedFreq, t0, sustain) * stringGainVal;

buzzedString = (s0 : cleanString * (1.0 - jivari)) + (s0 : bridgeBuzz * jivari);

mix = buzzedString * 14.5 * gain;
softclip(x) = x / (1.0 + abs(x));

process = mix : gourdResonator : fi.dcblocker : softclip;

