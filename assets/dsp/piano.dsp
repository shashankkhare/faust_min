declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// =====================================================
// SIMPLE GRAND PIANO MODEL
// =====================================================

freq = hslider("freq [unit:Hz]", 110, 27, 4000, 0.1);

gain = hslider("gain", 0.5, 0, 1, 0.01);

velocity = hslider("velocity", 0.8, 0, 1, 0.01);

gate = button("gate");

brightness = hslider("brightness", 0.7, 0, 1, 0.01);

stiffness = hslider("stiffness", 0.25, 0, 1, 0.01);

// =====================================================
// HAMMER EXCITATION (freq-dependent sine burst + noise)
// =====================================================

// Rising edge detector
rawTrig = (gate - gate') > 0.0;

// Frequency-dependent hammer duration: at least 2 cycles
hammerDur = max(0.003, 2.0 / freq);

// Counter-based hammer envelope
hammerTimer = rawTrig : hammer_pulse
with {
    hammer_pulse(t) = loop ~ _
    with {
        loop(cnt) = ba.if(t > 0.0, hammerDur * ma.SR, max(0.0, cnt - 1.0));
    };
};
hammerEnv = hammerTimer : >(0.0);

// Sine burst at fundamental frequency (3 full cycles, no truncation click)
hammerProgress = 1.0 - hammerTimer / (hammerDur * ma.SR);
hammerSine = sin(2.0 * ma.PI * freq * hammerProgress * hammerDur);

// Scale gain lower at low frequencies to prevent clipping
hammerGain = sqrt(max(55.0, freq) / 261.0);
hammerTone = hammerSine * hammerEnv * velocity * hammerGain;

// Mix tone + noise for the felt-hammer attack, then band-limit
hammer =
    (hammerTone * 0.7 + no.noise * hammerEnv * velocity * 0.3)
    : fi.lowpass(
        1,
        1500 + velocity * brightness * 8000
    );

// =====================================================
// STIFF STRING DISPERSION
// =====================================================

dispersion =
    fi.allpassnn(
        1,
        0.02 + stiffness * 0.12
    );

// =====================================================
// FREQUENCY-DEPENDENT DAMPING
// =====================================================

loopLPF =
    fi.lowpass(
        1,
        6000 - freq * 0.8
    );

// =====================================================
// STRING MODEL
// =====================================================

pianoString(f, detune) =

    hammer

    :

    + ~

    (
        de.fdelay(
            8192,
            ma.SR / (f * detune)
        )

        :

        dispersion

        :

        loopLPF

        :

        *(gate * max(0.70, 1.0 - 4.6 / max(20.0, f)) + (1.0 - gate) * max(0.50, 1.0 - 17.3 / max(20.0, f)))
    );

// =====================================================
// THREE STRINGS
// =====================================================

s1 =
    pianoString(freq, 1.0000) * 0.40;

s2 =
    pianoString(freq, 1.0003) * 0.30;

s3 =
    pianoString(freq, 0.9997) * 0.30;

// =====================================================
// SOUNDBOARD
// =====================================================

soundboardIn =
    s1 + s2 + s3;

soundboard =

    soundboardIn

    <:

    (
        fi.resonbp(110, 6, 0.8)
        + fi.resonbp(220, 5, 0.8)
        + fi.resonbp(440, 4, 0.8)
        + fi.resonbp(880, 3, 0.8)
    )

    * 0.08;

// =====================================================
// FINAL MIX
// =====================================================

mix =
    soundboardIn
    + soundboard;

// =====================================================
// OUTPUT
// =====================================================

softclip(x) =
    x / (1.0 + abs(x));

process =
    mix
    * gain
    * 1.5
    : softclip;
