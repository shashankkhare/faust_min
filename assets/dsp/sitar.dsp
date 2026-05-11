import("stdfaust.lib");

// Sitar - Physical Model (Documentation)
// Waveguide with Non-linear Jivari Bridge and Sympathetic Strings

// Controls
freq = nentry("freq", 146.83, 40, 1000, 0.01); // D3 is common for Sitar
pluck = button("pluck");
jivari = hslider("jivari", 0.5, 0, 1, 0.01);
sympGain = hslider("symp_gain", 0.3, 0, 1, 0.01);

// Bridge (Jivari) Non-linearity
// Modifies the reflection coefficient based on signal amplitude
jivari_bridge(x) = x * (1.0 - jivari * x * x); // Simple parabolic buzz

// Sympathetic Strings (Modal Bank tuned to C Major for demo)
sympRatios = (1.0, 1.125, 1.25, 1.333, 1.5, 1.666, 1.875, 2.0, 2.25, 2.5, 3.0);
sympDecays = (5.0, 4.8, 4.5, 4.2, 4.0, 3.8, 3.5, 3.0, 2.5, 2.0, 1.5);

sympathetic = pm.modalModel(sympRatios, sympDecays, sympGain);

// Sitar Engine
sitar = pluck : pm.guitar(freq, 0.8) : jivari_bridge : sympathetic;

process = sitar;
