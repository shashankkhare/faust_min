declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Pure physical model of a classical Western flute using a waveguide tube and embouchure air jet loop.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - pressure
//   - mouthPosition
// =============================================================================
import("stdfaust.lib");

// Pure Physical Model Flute (No UI assembly)
f = hslider("freq", 440, 50, 2000, 0.1) : si.smoo;
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

// Multi-Column Dynamic Parameters controlled by Companion CSV Lookup Table
// Mapped directly via Inverse Distance Weighting from (freq, velocity) vectors
pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

// Attack time mapped from velocity (high velocity = 5ms fast attack, low velocity = up to 105ms slow attack)
attackTime = 0.005 + (1.0 - velocity) * 0.1;

// Apply calibrated target pressure directly via trigger gate with dynamic tonguing attack
pressure = t * pressureTarget : min(1.0) : si.smooth(ba.tau2pole(attackTime));

// Fast 30ms release envelope to cleanly silence the physical model decay
releaseEnv = t : si.smooth(ba.tau2pole(0.030));

process = pm.fluteModel(pm.f2l(f), mouthPosition, pressure) : *(releaseEnv) : *(0.5);
