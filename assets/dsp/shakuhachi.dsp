declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Traditional Japanese bamboo flute (Shakuhachi) modeled using a waveguide tube, mouth embouchure position, and breath turbulence.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - pressure
//   - mouthPosition
//   - breath_noise
// =============================================================================
import("stdfaust.lib");

// Shakuhachi physical modeling waveguide with breath turbulence
f = hslider("freq", 440, 50, 2000, 0.1) : si.smoo;
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

// Mapped parameters via inverse distance weighting from companion CSV lookup table
pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;
breathNoiseTarget = hslider("breath_noise", 0.1, 0.0, 1.0, 0.001) : si.smoo;

// Generate breath turbulence noise
noise = no.noise * breathNoiseTarget;

// Attack time mapped from velocity (high velocity = 5ms fast attack, low velocity = up to 105ms slow attack)
attackTime = 0.005 + (1.0 - velocity) * 0.1;

// Combine target pressure and noise turbulence under the trigger gate with dynamic tonguing attack
pressure = t * (pressureTarget + noise) : min(1.0) : si.smooth(ba.tau2pole(attackTime));

// Fast 30ms release envelope to cleanly silence the physical model decay
releaseEnv = t : si.smooth(ba.tau2pole(0.030));

process = pm.fluteModel(pm.f2l(f), mouthPosition, pressure) : *(releaseEnv) : *(0.5);
