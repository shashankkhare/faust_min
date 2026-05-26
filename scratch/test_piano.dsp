import("stdfaust.lib");

freq = hslider("freq [unit:Hz]", 110, 27, 4000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");
brightness = hslider("brightness", 0.7, 0, 1, 0.01);
stiffness = hslider("stiffness", 0.25, 0, 1, 0.01);

hammerEnv = en.ar(0.0001, 0.008, gate : ba.impulsify);
hammerNoise = no.noise * hammerEnv * velocity;
hammer = hammerNoise : fi.lowpass(1, 1500 + velocity * brightness * 8000);

dispersion = fi.allpassnn(1, 0.02 + stiffness * 0.12);
loopLPF = fi.lowpass(1, 6000 - freq * 0.8);

pianoString(f, detune, amp) =
    hammer
    :
    + ~
    (
        de.fdelay(8192, ma.SR / (f * detune))
        : dispersion
        : loopLPF
        : *(0.9996 - f * 0.0000002)
    )
    * amp;

s1 = pianoString(freq, 1.0000, 0.40);
s2 = pianoString(freq, 1.0007, 0.30);
s3 = pianoString(freq, 0.9994, 0.30);

soundboardIn = s1 + s2 + s3;

soundboard =
    soundboardIn
    <:
    (
        fi.resonbp(110, 12, 1.0)
        + fi.resonbp(220, 10, 1.0)
        + fi.resonbp(440, 8, 1.0)
        + fi.resonbp(880, 6, 1.0)
    )
    * 0.25;

mix = soundboardIn + soundboard;
softclip(x) = x / (1.0 + abs(x));
process = mix * gain * 1.5 : softclip;
