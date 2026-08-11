declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

// =====================================================
// GLOBAL CONTROLS
// =====================================================

// Full acoustic piano range: A0 (27.5 Hz) to C8 (4186 Hz)
freq       = hslider("freq [unit:Hz]", 110.0, 27.5, 4186, 0.1);
gain       = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;
velocity   = hslider("velocity", 0.8, 0, 1, 0.01);
gate       = button("gate");
calibration = hslider("calibration", 0, -100, 100, 0.01);
cfreq = freq * (2.0 ^ (calibration / 1200.0));

// SUSTAIN PEDAL: 0 = Off (Normal Damping), 1 = On (Strings Ring Out)
sustain    = hslider("sustainPedal [style:knob]", 0, 0, 1, 1) : int;

// STRIKE: 0 = Staccato (dampers on), 1 = Sustain (dampers lifted, like grand piano)
strike     = hslider("strike", 0, 0, 1, 0.01);

brightness = hslider("brightness", 0.7, 0, 1, 0.01);
stiffness  = hslider("stiffness", 0.25, 0, 1, 0.01);

// =====================================================
// HAMMER EXCITATION (Sine burst + noise transient)
// =====================================================
rawTrig = (gate - gate') > 0.0;
hammerDur = max(0.003, 2.0 / cfreq);

hammerTimer = rawTrig : hammer_pulse
with {
    hammer_pulse(t) = loop ~ _
    with {
        loop(cnt) = ba.if(t > 0.0, hammerDur * ma.SR, max(0.0, cnt - 1.0));
    };
};
hammerEnv = hammerTimer : >(0.0);

hammerProgress = 1.0 - hammerTimer / (hammerDur * ma.SR);
hammerSine = sin(2.0 * ma.PI * cfreq * hammerProgress * hammerDur);

// FIXED: Scaled back to realistic physical excitation levels. 
// 4000.0 was blowing up the waveguide recursive accumulator.
hammerGain = 1.0;
hammerTone = hammerSine * hammerEnv * velocity * hammerGain;

hammer = (hammerTone * 0.7 + no.noise * hammerEnv * velocity * 0.3)
       : fi.lowpass(1, 1500 + velocity * brightness * 8000);

// =====================================================
// STIFF STRING DISPERSION & COUPLING
// =====================================================
dispersion = fi.allpassnn(1, (0.02 + stiffness * 0.12) * max(0.0, 1.0 - (cfreq / 2500.0)));
loopLPF    = fi.lowpass(1, 16000.0);

// =====================================================
// STRING ENGINE WITH SUSTAIN MAPPING
// =====================================================
pianoString(f, detune) = hammer : + ~ (
    de.fdelay(8192, ma.SR / (f * detune))
    : dispersion
    : loopLPF
    : *(decayLoss)
)
with {
    isSustained = (gate > 0.0) | (strike > 0.0);

    heldDecay    = max(0.985, 1.0 - 1.0 / max(20.0, f));
    releaseDecay = max(0.50, 1.0 - 17.3 / max(20.0, f));

    decayLoss    = select2(isSustained, releaseDecay, heldDecay);
};

// =====================================================
// THREE STRING UNISON TRIPLETS
// =====================================================
s1 = pianoString(cfreq, 1.0000) * 0.40;
s2 = pianoString(cfreq, 1.0003) * 0.30;
s3 = pianoString(cfreq, 0.9997) * 0.30;

soundboardIn = s1 + s2 + s3;

// =====================================================
// SOUNDBOARD MAPPING (FIXED ROUTING SYNTAX)
// =====================================================
soundboard = soundboardIn <: (
    fi.resonbp(110, 6, 0.8), 
    fi.resonbp(220, 5, 0.8), 
    fi.resonbp(440, 4, 0.8), 
    fi.resonbp(880, 3, 0.8)
) :> *(0.08); 

// =====================================================
// OUTPUT PROCESSOR
// =====================================================
mix = soundboardIn + soundboard;

softclip(x) = x / (1.0 + abs(x));

// FIXED: Multiply by gain on the outside of softclip so slider changes 
// volume rather than forcing saturation shape dynamics.
process = mix : fi.dcblocker : *(gain * 2050) : ma.tanh;

