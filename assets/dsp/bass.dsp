declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Physically modeled electric bass guitar with adjustable tone, muting, and clean plucked string waveguide excitation.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - gain
//   - mute
//   - tone
// =============================================================================
import("stdfaust.lib");

freq     = hslider("freq",     55.0, 20,  500,  0.01);
velocity = hslider("velocity", 0.6,  0,   1,    0.01);
gate     = button("gate");
gain     = hslider("gain",     0.5,  0,   1,    0.01); // no si.smoo: applied immediately at noteOn
mute     = hslider("mute",     0.95, 0.0, 1.0,  0.01) : si.smoo;
tone     = hslider("tone",     600,  100, 5000, 1.0)  : si.smoo;

// 1. Rising edge trigger
trig = gate > gate';

// 2. Short noise burst excitation — 10ms seeds the delay line with broadband noise
//    Noise doesn't accumulate at resonance (unlike a resonant sine), so it stays clean
pulseDur = 0.010 * ma.SR; // 10ms
pulseCnt = loop ~ _
with {
    loop(cnt) = ba.if(trig, pulseDur, max(0.0, cnt - 1.0));
};
pulseEnv = pulseCnt > 0.0;

// Excitation: LP-filtered noise (only inject frequencies that will survive in the loop)
// Explicit parens around the filter to avoid Faust serial-composition precedence issues
excitation = (no.noise : fi.lowpass(1, max(freq * 3.0, 400.0))) * velocity * 8.0 * pulseEnv;

// 3. String parameters
delaySamples = ma.SR / freq;
decaySecs    = 0.15 + (8.0 - 0.15) * mute;
R            = pow(0.001, 1.0 / (decaySecs * freq));
gateDamp     = ba.if(gate > 0.0, 1.0, 0.82); // finger mute on release

// Symmetric 2-point average: linear phase — zero harmonic beating at tail
dampFilter(x) = (x + x') * 0.5;

// 4. KS feedback loop
stringLoop = excitation : (+ : de.fdelay(8192, delaySamples)) ~ (dampFilter : *(R * gateDamp));

// 5. Output: gain scales drive into tanh (low gain = linear, high gain = warm saturation)
process = stringLoop * gain : fi.lowpass(2, tone) : fi.dcblocker : ma.tanh;
