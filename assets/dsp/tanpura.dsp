declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
declare options "[nvoices:4]";

// =============================================================================
// === PRODUCTION CONCERT TANPURA (UNIFIED SITAR_STRING ENGINE) ===
// Description: Refactored to utilize the robust sitar_string physical model
//              from fm.lib, preserving standard controls.
// =============================================================================
import("stdfaust.lib");
import("fm.lib");

freq = hslider("freq", 130.81, 130, 300, 0.01);
smoothedFreq = freq : si.smoo;

gain = hslider("gain", 0.5, 0, 1.0, 0.01); 
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = button("gate");

sustain = hslider("sustain", 14.0, 4.0, 24.0, 0.01);
jivari = hslider("jivari", 0.75, 0.0, 1.0, 0.01);

excDur = hslider("excDur", 0.0115, 0.0001, 0.1, 0.0001);
excGain = hslider("excGain", 0.40, 0.0, 1.0, 0.01);
stringGainVal = hslider("stringGainVal", 1.0, 0.0, 2.0, 0.01);

t0 = (gate - gate') > 0.0;
pluck_env = en.ar(excDur, excDur * 0.5, t0);
pick_noise = no.noise : fi.lowpass(2, 6000.0);
master_exc_signal = pick_noise * pluck_env * velocity;

// --- Gourd Resonator Acoustic Body Filter ---
gourdResonator(x) = x <: (toombaAir + tabliWood + jawariPresence + soundholeShimmer) :> _
with {
    toombaAir        = fi.resonbp(105.0, 3.0, 0.45);  
    tabliWood        = fi.resonbp(250.0, 3.0, 0.35);  
    jawariPresence   = fi.resonbp(720.0, 5.0,  0.15);  
    soundholeShimmer = fi.resonbp(1450.0, 3.0, 0.08);  
};

// --- Main String Instance using fm.lib sitar_string ---
string_output = sitar_string(smoothedFreq, sustain, jivari, excGain * stringGainVal, gate, master_exc_signal);

mix = string_output * 14.5 * gain;
softclip(x) = x / (1.0 + abs(x));

process = mix : gourdResonator : fi.dcblocker : softclip;
