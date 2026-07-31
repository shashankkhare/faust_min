declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");
import("fm.lib");

// Frequency controls
f = hslider("freq", 440, 150, 2000, 0.1) : si.smooth(0.995);

// Calibration slider: Now acts as a precision pitch trim in cents (-1200 to +1200)
cal = hslider("calibration", 0.0, -1200.0, 1200.0, 0.01);

// Performance controls
t = button("gate");
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smooth(0.03);

// Physical UI Sliders
pressure = hslider("pressure", 0.72, 0.0, 1.5, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.15, 0.01, 1.0, 0.001) : si.smoo;
loss           = hslider("loss", 0.02, 0.0, 1.0, 0.001) : si.smoo;

attackTime = 0.05;

// Linear AR envelopes with corner smoothing (S-curve) prevent infinite slope at t=0
// This prevents the dcblocker in the waveguide from generating a spike (click/pluck)
rawEnv = en.ar(attackTime, 0.05, t);
breathEnv = rawEnv : si.smooth(0.995);
releaseEnv = rawEnv : si.smooth(0.995);

mode = 0;

process = fluteModel(f, pressure, breathEnv, mouthPosition, loss, mode, cal) * releaseEnv * gain * 0.0372281;

