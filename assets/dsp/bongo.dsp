declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Physical modeling of a pair of Bongos (Macho and Hembra) with strike position on the membrane (center, edge) and strike type (open, slap, muted).
//
// Parameters (Controls):
//   - freq
//   - gain
//   - velocity
//   - gate
//   - position
//   - strike
// =============================================================================
import("stdfaust.lib");

// --- Physical Modeling Bongo Drum ---
// Documented Parameters:
// - freq: Fundamental pitch frequency of the bongo head (Hz). Typically: Macho (300-500Hz), Hembra (180-300Hz).
// - gain: Overall output volume/amplitude scaling.
// - velocity: Strike velocity (maps to internal excitation gain).
// - gate: Note trigger (1-sample impulse generated on rising edge).
// - position: Strike position on the membrane (0 = Center, 1 = Mid-skin, 2 = Edge/Slap).
// - strike: Strike articulation (0 = Open/Resonant Pop, 1 = Rim Slap, 2 = Muted/Tapped Rim).

// UI Controls (Discrete sliders)
freq = hslider("freq", 300.0, 150, 600, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01) : si.smoo;
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");
position = hslider("position", 0, 0, 2, 1);
strike = hslider("strike", 0, 0, 2, 1);

// Generate trigger pulse from gate rising edge
trig = (gate > 0) & (gate' <= 0);

// Map discrete inputs to physical parameters (bongos have sharper, higher transients)
strikePos = ba.selectn(3, int(position), 0.15, 0.55, 0.95);
sharpness = ba.selectn(3, int(strike), 0.45, 0.95, 1.8);
decayScale = ba.selectn(3, int(strike), 1.0, 0.4, 0.1);

// Excitation using standard library's physical strike model
excitation = pm.strike(strikePos, sharpness, velocity, trig);

// Bongo Model with high-tension Bessel membrane ratios
bongoModel(f, ds) = _ <: par(i, nModes, pm.modeFilter(modeFreqs(i), modeT60s(i), modeGains(i))) :> /(nModes)
with {
    nModes = 6;
    // Bessel ratios for small high-tension bongo heads
    modeFreqs(i) = f * ba.selectn(6, i, 1.00, 1.62, 2.20, 2.76, 3.10, 3.40);
    
    // Bongos are shallower and have very short decays
    baseT60 = 0.2 * ds;
    modeT60s(i) = baseT60 * ba.selectn(6, i, 1.0, 0.6, 0.4, 0.3, 0.2, 0.1);
    
    modeGains(i) = 1.0 / ((i + 1) * (i + 1));
};

// Route excitation through bongo model
drumOutput = excitation : bongoModel(freq, decayScale);

// Apply dry decay envelope to match the fast pop of bongo heads (no high-Q bandpass cavity)
envDecay = ba.selectn(3, int(strike), 0.18, 0.08, 0.02);
env = en.ar(0.001, envDecay, trig);

process = drumOutput * env * 4.0 * gain;
