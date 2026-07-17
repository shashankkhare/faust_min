declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Acoustic coupled dual-membrane (double-sided plastic sheet) 
//              kick drum model utilizing modal resonators and internal air coupling.
// =============================================================================
import("stdfaust.lib");

// --- CONTROLS ---
freq        = hslider("freq [unit:Hz]", 55.0, 40, 100, 0.1);
gain        = hslider("gain", 0.8, 0, 1, 0.01) : si.smoo;
velocity    = hslider("velocity", 0.8, 0, 1, 0.01);
gate        = button("gate");

// Head tension decoupling: controls the tuning difference between front and back sheets
headTuning  = hslider("headTuning", 1.2, 1.0, 1.5, 0.01) : si.smoo;
// Sub-bass air compression factor inside the shell cavity
sub_boost   = hslider("sub_boost", 0.5, 0, 1, 0.01) : si.smoo;

// =====================================================
// EXCITATION: Beater impact on plastic batter head
// =====================================================
rawTrig = (gate - gate') > 0.0;

// High-speed exponential pitch envelope mimicking plastic sheet tension decay
pitchDrop = s ~ _
with {
    s(y) = ba.if(rawTrig, 1.0, y * 0.996); // Ultra-fast exponential decay
};

// Felt beater strike: a quick noise spike paired with a heavy low impulse click
beaterStrike = (no.noise * env * 0.2) + (os.osc(freq * 3.0) * env * 0.8)
with {
    env = ba.if(rawTrig, 1.0, _ * 0.99) ~ _ : max(0.0); // 3ms strike transient
};

// =====================================================
// DUAL-HEAD PHYSICAL MEMBRANE MODES
// =====================================================
dualHeadModel = _ <: (batterHead, resonantHead) :> _;

// Dynamic pitch drop applied to the fundamental tuning
instFreq = freq * (1.0 + pitchDrop * 1.8);

// 1. Batter Head (The plastic sheet you hit - high damping, snappy overtones)
// FIXED: Explicit split and merge syntax mapped safely outside local blocks
batterHead = _ <: (b_mode1, b_mode2,b_mode3) :> _
with {
    b_mode1 = fi.resonbp(instFreq, 12.0, 0.6);        // Fundamental (1.0)
    b_mode2 = fi.resonbp(instFreq * 1.59, 8.0, 0.3); // First circular mode (1.59)
    b_mode3 = fi.resonbp(instFreq * 2.14, 15.0, 0.2); // Upper asymmetrical mode (2.14)
};

// 2. Resonant Head (The front plastic sheet - low damping, deep boom)
// FIXED: Combined spatial scaling inside a mathematically sound signal path
resonantHead = _ <: (r_mode1, r_mode2, r_mode3) :> *(sub_boost * 1.5)
with {
    r_freq  = instFreq * headTuning;
    r_mode1 = fi.resonbp(r_freq, 35.0, 0.7);        // Highly resonant fundamental
    r_mode2 = fi.resonbp(r_freq * 1.59, 8.0, 0.3); // First circular mode (1.59)
    r_mode3 = fi.resonbp(r_freq * 2.14, 15.0, 0.2); // Upper asymmetrical mode (2.14)
};

// =====================================================
// COUPLING ENGINE & CLEANUP
// =====================================================
process = beaterStrike * velocity
        : dualHeadModel 
        : fi.dcblocker
        : ma.tanh 
        * gain * 37.5;

