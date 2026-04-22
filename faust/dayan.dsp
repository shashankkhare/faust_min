import("stdfaust.lib");

// Tabla Dayan - Physical Model (Documentation)
// Based on Syahi-tuned Modal Synthesis

// Harmonically tuned ratios for that signature "tunn" ring
ratios = (1.0, 1.5, 2.0, 2.5, 3.0);
decays = (3.0, 2.5, 1.8, 1.2, 0.8); // High Q modes

// Controls
freq = nentry("freq", 293.66, 100, 1000, 0.01); // D4 is common for Dayan
strike = button("strike");

// Excitation
excitation = strike : ba.impulsify;

// Modal Bank
dayan = excitation : pm.modalModel(ratios, decays, 1.0) : _ * 0.4;

process = dayan;
