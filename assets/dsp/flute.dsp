declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");
import("fm.lib");

// Frequency controls
f = hslider("freq", 440, 150, 2000, 0.1);

// Calibration slider: Now acts as a precision pitch trim in cents (-1200 to +1200)
cal = hslider("calibration", 0.0, -1200.0, 1200.0, 0.01);

// Performance controls
t = button("gate");
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);

// Physical UI Sliders
pressure = hslider("pressure", 0.72, 0.0, 1.5, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.15, 0.01, 1.0, 0.001) : si.smoo;
loss           = hslider("loss", 0.02, 0.0, 1.0, 0.001) : si.smoo;

// Velocity shapes the attackTime wrapper
attackTime = 0.01 + (1.0 - velocity) * 0.09; 

// Pure gate envelope
breathEnv = t : si.smooth(ba.tau2pole(attackTime));
releaseEnv = t : si.smooth(ba.tau2pole(0.03));

mode = 0;

process = fluteModel(f, pressure, breathEnv, mouthPosition, loss, mode, cal) * releaseEnv * gain * 0.0496375;

