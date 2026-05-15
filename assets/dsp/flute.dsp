import("stdfaust.lib");

// Pure Physical Model Flute (No UI assembly)
f = hslider("freq", 440, 50, 2000, 0.1) : si.smoo;
t = button("gate");

// Multi-Column Dynamic Parameters controlled by Companion CSV Lookup Table
// Mapped directly via Inverse Distance Weighting from (freq, velocity) vectors
pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

// Apply calibrated target pressure directly via trigger gate
pressure = t * pressureTarget : min(1.0) : si.smooth(0.999);
process = pm.fluteModel(pm.f2l(f), mouthPosition, pressure) : *(0.5);
