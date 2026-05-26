import("stdfaust.lib");

mypm = library("physmodels.lib") with { maxLength = 20; };

freq = hslider("freq", 196.0, 50, 2000, 0.01);
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gate = button("gate");
gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;

pluckPosition = hslider("pluckPosition", 0.8, 0.01, 0.99, 0.01) : si.smoo;
mute = hslider("mute", 1.0, 0.0, 1.0, 0.01) : si.smoo; // 1 for no mute, 0 for instant mute

// String length in meters
stringLength = freq : mypm.f2l;

// We use the steel string electric guitar model, passing gate directly
process = mypm.elecGuitar(stringLength, pluckPosition, mute, velocity, gate) : fi.dcblocker : ma.tanh * gain;
