import("stdfaust.lib");

// Tabla Bayan - Physical Model (Documentation)
// Deep modal resonance with pitch slide (meend)

// Controls
baseFreq = nentry("freq", 110, 40, 400, 0.01);
meend = hslider("meend", 1.0, 1.0, 2.5, 0.01); // Slide multiplier
strike = button("strike");

freq = baseFreq * meend : si.smoo; // Smooth pitch transition

// Mode ratios for a deep skin membrane
ratios = (1.0, 2.1, 3.2);
decays = (1.5, 0.8, 0.4);

// Excitation
excitation = strike : ba.impulsify;

// Modal Bank
bayan = excitation : pm.modalModel(ratios, decays, 1.0) : _ * 0.6;

process = bayan;
