declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Large Chinese drum (Da Gu) physically modeled using low-frequency drum head resonance and stick/mallet strike excitations.
// =============================================================================
import("stdfaust.lib");

freq = hslider("freq", 55.0, 20.0, 200.0, 0.1);
gate = button("gate");
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
gain = hslider("gain", 1.0, 0.0, 1.0, 0.01);

// Material Selection: 0 for Oxhide (Heavy, Deep Boom), 1 for Cowhide (Light, Sharp Punch)
skin_type = checkbox("Skin Type: Cowhide (Checked) / Oxhide (Unchecked)");

trig = gate > gate';

// --- FIXED STRIKE EXCITATION (No high-frequency leak) ---
strike_env = en.ar(0.001, 0.02, trig); // Shortened for punchier attack

// Mallet modeling: Real mallets are soft. We low-pass filter the noise at 300Hz 
// to strip away the electronic hiss, leaving only an organic, heavy impact thud.
mallet_noise = no.noise : fi.lowpass(2, 300) * strike_env * velocity * 1.0;
strike_impulse = trig * velocity;
exc = strike_impulse + mallet_noise;

// --- DYNAMIC ACOUSTIC MATERIAL MODELLING ---
decay_mod = ba.if(skin_type, 0.5, 1.3); 

f_offset2 = ba.if(skin_type, 1.59, 1.63);
f_offset3 = ba.if(skin_type, 2.14, 2.30);
f_offset4 = ba.if(skin_type, 3.60, 3.85);

// --- CHANGED TO RESONANT LOW-PASS FOR DEEP ACOUSTIC CAVITY ---
// resonbp lets high-frequencies through from noise. resonlp acts as a natural 
// acoustic muffler, capturing the deep bass resonance of a massive wood barrel.
mode1 = fi.resonlp(freq, 25 * decay_mod, 1.0);                 // Sub-bass fundamental
mode2 = fi.resonlp(freq * f_offset2, 18 * decay_mod, 0.5);   // Leather stretch
mode3 = fi.resonlp(freq * f_offset3, 12 * decay_mod, 0.25);  // Shell resonance
mode4 = fi.resonlp(freq * f_offset4, 6 * decay_mod, 0.1);    // Soft rim/mallet click

dagu = exc <: mode1 + mode2 + mode3 + mode4;

// --- CINEMATIC DRIVE (With high-frequency cleanup) ---
// The saturation was exaggerating the tail noise. We put a low-pass filter 
// after the saturation block to keep the tail dark, muddy, and heavy.
punch = dagu : *(4.0) : ef.cubicnl(0.1, 0.0) : fi.lowpass(2, 800) * 0.6;

process = punch * gain;

