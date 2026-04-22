import("stdfaust.lib");

// Tibetan Singing Bowl - Physical Model (Documentation)
// Based on Modal Synthesis with Mode Doublets for Beating

// Mode Ratios (Classic handmade bowl)
// Fundamental, Doublet1, Doublet2, Doublet3...
ratios = (1.0, 1.002, 2.78, 2.785, 5.21, 5.215, 8.4, 8.41);
decays = (4.0, 3.9, 2.5, 2.4, 1.5, 1.4, 0.8, 0.7); // T60 in seconds

// Controls
freq = nentry("freq", 220, 100, 1000, 0.01);
strike = button("strike");
rub = hslider("rub", 0, 0, 1, 0.01);

// Excitation
// Strike: Short pulse
excitation_strike = strike : ba.impulsify;
// Rub: Friction noise filtered to excite fundamental
excitation_rub = no.noise * rub : fi.lowpass(1, freq*1.2) : fi.highpass(1, freq*0.8);

excitation = (excitation_strike + excitation_rub) * 0.5;

// Modal Bank Implementation
bowl = excitation : pm.modalModel(ratios, decays, 1.0) : _ * 0.5;

process = bowl;
