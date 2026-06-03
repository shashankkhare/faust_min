declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Plucked string waveguide model of an electric guitar combined with distortion drive and sustain modeling.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - gain
//   - pluckPosition
//   - mute
//   - drive
//   - sustain
// =============================================================================
import("stdfaust.lib");

mypm = library("physmodels.lib") with { maxLength = 20; };

freq = hslider("freq", 196.0, 50, 2000, 0.01);
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gate = button("gate");
gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;

pluckPosition = hslider("pluckPosition", 0.8, 0.01, 0.99, 0.01) : si.smoo;
mute = hslider("mute", 1.0, 0.0, 1.0, 0.01) : si.smoo; // 1 for no mute, 0 for instant mute

// Distortion and sustain controls
drive = hslider("drive", 0.5, 0, 1, 0.01) : si.smoo;
sustain = hslider("sustain", 0.5, 0, 1, 0.01) : si.smoo;
pregain = 1.0 + sustain * 19.0;

// String length in meters
stringLength = freq : mypm.f2l;

// Cabinet simulator using a 2nd order lowpass filter to eliminate high-frequency fizz and simulate real speakers
cabinet = fi.lowpass(2, 4000);

process = mypm.elecGuitar(stringLength, pluckPosition, mute, velocity, gate)
        : fi.dcblocker 
        : *(pregain) 
        : ef.cubicnl(drive, 0) 
        : ma.tanh 
        : cabinet 
        : *(gain * 2.5);
