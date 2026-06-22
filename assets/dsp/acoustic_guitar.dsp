declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Physically modeled acoustic guitar simulating nylon/steel string vibration using digital waveguide loops, including string damping and plucking position controls.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - gain
//   - pluckPosition
// =============================================================================
import("stdfaust.lib");

mypm = library("physmodels.lib") with { maxLength = 20; };

// Expert Play Range: Acoustic Guitar typical range E2 (82 Hz) to C6 (1046 Hz).
freq = hslider("freq", 196.0, 82, 1046, 0.01);
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gate = button("gate");
gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;

pluckPosition = hslider("pluckPosition", 0.8, 0.01, 0.99, 0.01) : si.smoo;

// String length in meters
stringLength = freq : mypm.f2l;

// We use the steel string acoustic guitar model, passing gate directly
process = mypm.guitar(stringLength, pluckPosition, velocity, gate) : fi.dcblocker : ma.tanh * gain;
