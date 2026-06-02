declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// --- Physical Modeling Conga Drum ---
// Documented Parameters:
// - freq: Fundamental pitch frequency of the drumhead (Hz).
// - gain: Overall output volume/amplitude scaling.
// - velocity: Strike velocity (maps to internal excitation gain).
// - gate: Note trigger (1-sample impulse generated on rising edge).
// - position: Strike position on the membrane (0 = Center, 1 = Mid-skin, 2 = Edge/Rim).
// - strike: Strike articulation (0 = Open Tone, 1 = Slap Tone, 2 = Muffled/Touch).

// UI Controls (Discrete sliders)
freq = hslider("freq", 150.0, 80, 400, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01) : si.smoo;
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");
position = hslider("position", 0, 0, 2, 1);
strike = hslider("strike", 0, 0, 2, 1); 

// Generate trigger pulse from gate rising edge
trig = (gate > 0) & (gate' <= 0);

// Map discrete inputs to physical parameters
strikePos = ba.selectn(3, int(position), 0.1, 0.5, 0.9);
sharpness = ba.selectn(3, int(strike), 0.25, 0.65, 1.3);
decayScale = ba.selectn(3, int(strike), 1.0, 0.6, 0.15);

// Excitation using standard library's physical strike model
excitation = pm.strike(strikePos, sharpness, velocity, trig);

// Conga Model with Bessel membrane ratios
congaModel(f, ds) = _ <: par(i, nModes, pm.modeFilter(modeFreqs(i), modeT60s(i), modeGains(i))) :> /(nModes)
with {
    nModes = 6;
    // Physical Bessel ratios for circular membrane modes
    modeFreqs(i) = f * ba.selectn(6, i, 1.00, 1.59, 2.14, 2.30, 2.65, 2.92);
    
    // Decay times scale down for higher modes
    baseT60 = 0.5 * ds;
    modeT60s(i) = baseT60 * ba.selectn(6, i, 1.0, 0.7, 0.5, 0.4, 0.3, 0.2);
    
    // Mode gains (natural quadratic roll-off)
    modeGains(i) = 1.0 / ((i + 1) * (i + 1));
};

// Route excitation through the membrane model
drumOutput = excitation : congaModel(freq, decayScale);

// Conga has a thick leather head, so we lowpass slightly to keep it warm and woody (no high-Q bandpass cavity)
process = (drumOutput : fi.lowpass(2, freq * 4.0)) : ma.tanh * 1.5 * gain;
