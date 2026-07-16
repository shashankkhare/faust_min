declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

// =====================================================
// GLOBAL CONTROLS
// =====================================================

// Full acoustic piano range: A0 (27.5 Hz) to C8 (4186 Hz)
freq       = hslider("freq [unit:Hz]", 110.0, 27.5, 4186, 0.1);
gain       = hslider("gain", 0.5, 0, 1, 0.01);
velocity   = hslider("velocity", 0.8, 0, 1, 0.01);
gate       = button("gate");

// SUSTAIN PEDAL: 0 = Off (Normal Damping), 1 = On (Strings Ring Out)
sustain    = hslider("sustainPedal [style:knob]", 0, 0, 1, 1) : int;

brightness = hslider("brightness", 0.7, 0, 1, 0.01);
stiffness  = hslider("stiffness", 0.25, 0, 1, 0.01);

// =====================================================
// HAMMER EXCITATION (Sine burst + noise transient)
// =====================================================
rawTrig = (gate - gate') > 0.0;
hammerDur = max(0.003, 2.0 / freq);

hammerTimer = rawTrig : hammer_pulse
with {
    hammer_pulse(t) = loop ~ _
    with {
        loop(cnt) = ba.if(t > 0.0, hammerDur * ma.SR, max(0.0, cnt - 1.0));
    };
};
hammerEnv = hammerTimer : >(0.0);

hammerProgress = 1.0 - hammerTimer / (hammerDur * ma.SR);
hammerSine = sin(2.0 * ma.PI * freq * hammerProgress * hammerDur);

hammerGain = sqrt(max(55.0, freq) / 261.0);
hammerTone = hammerSine * hammerEnv * velocity * hammerGain;

hammer = (hammerTone * 0.7 + no.noise * hammerEnv * velocity * 0.3)
       : fi.lowpass(1, 1500 + velocity * brightness * 8000);

// =====================================================
// STIFF STRING DISPERSION & COUPLING
// =====================================================
dispersion = fi.allpassnn(1, 0.02 + stiffness * 0.12);
loopLPF    = fi.lowpass(1, 6000 - freq * 0.8);

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
    // If key is held OR sustain pedal is pressed, string loops freely
    isSustained = (gate > 0.0) | (sustain > 0);

    heldDecay    = max(0.985, 1.0 - 1.2 / max(20.0, f)); 
    releaseDecay = max(0.850, 1.0 - 15.3 / max(20.0, f));

    decayLoss    = select2(isSustained, releaseDecay, heldDecay);
};

// =====================================================
// THREE STRING UNISON TRIPLETS
// =====================================================
s1 = pianoString(freq, 1.0000) * 0.40;
s2 = pianoString(freq, 1.0003) * 0.30;
s3 = pianoString(freq, 0.9997) * 0.30;

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

process = mix * gain * 75.0 : softclip;

