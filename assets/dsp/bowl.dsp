declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
declare name "tibetanBowlMono";
declare description "Banded Waveguide Tibetan Bowl (Mono - Correct Physical Velocity Mapping)";
declare author "Shashank Khare";
declare licence "MIT";
declare version "2.4";

import("stdfaust.lib");

// --- UI Controls ---
freq     = nentry("freq", 220.0, 100, 1000, 0.1);
gain     = nentry("gain", 0.8, 0, 2, 0.01);
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate     = button("gate"); 

// --- Modal Properties ---
my_modes(x)      = ba.take(x+1, (1.0, 0.625, 0.390625, 1.61, 2.5921, 4.173281, 6.7137, 7.0, 17.40, 16.0, 2.0, 4.0, 8.0));
my_excitation(x) = ba.take(x+1, (1.0, 0.5, 0.5, 2.0, 2.0, 2.0, 3.0, 3.0, 4.0, 3.0, 0.5, 0.5, 0.5));

// --- Delay Line Engine ---
delayLine(x) = de.delay(8192, ma.SR / (freq * my_modes(x)));

// --- Safe Modal Bandpass Filters ---
safe_modeFilter(f, r) = fi.tf2(b0, 0, -b0, a1, a2)
with {
    w = 2.0 * ma.PI * f / ma.SR;
    r_safe = min(0.998, r); 
    b0 = 1.0 - r_safe;
    a1 = -2.0 * r_safe * cos(w);
    a2 = r_safe * r_safe;
};
bandPassFilter(x) = safe_modeFilter(freq * my_modes(x), 0.995);

// =====================================================
// FIXED EXCITATION ENGINE (VELOCITY AT THE INPUT)
// =====================================================
trig = (gate > gate') : ba.impulsify; 

// CORITICAL FIX: Velocity scales the raw shockwave here.
// Harder hits generate a wider, heavier initial acoustic wavefront.
mallet_strike = trig : fi.resonbp(150.0, 1.5, 20.0) : *(velocity) : fi.dcblocker;

globalDamping  = 0.996; 
excitationGain = 1.5; 

// =====================================================
// INDEPENDENT WAVEGUIDE ENGINE
// =====================================================
waveguide_mode(id) = loop_core
with {
    mallet_exc = mallet_strike * my_excitation(id) * excitationGain;    
    loop_core = (mallet_exc + _) ~ (delayLine(id) : *(globalDamping) : bandPassFilter(id));
};

// Mix down all 13 modes cleanly
bowl_system = par(i, 13, waveguide_mode(i)) :> _;

// =====================================================
// EXECUTION PIPELINE (PURE GAIN SCALING)
// =====================================================
// Velocity is completely removed from this track. 
process = bowl_system 
        : fi.dcblocker
        : *(gain)*5.0
        : ma.tanh;

