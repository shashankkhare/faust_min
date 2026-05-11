import("stdfaust.lib");

// Pure Physical Model Flute (No UI assembly)
f = hslider("freq", 440, 50, 2000, 0.1) : si.smoo;
g = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;
t = button("gate");

// pm.fluteModel(tubeLength, mouthPosition, pressure)
// Use a smoother to simulate breath pressure ramp (slow attack)
pressure = t * g : si.smooth(0.999);
process = pm.fluteModel(pm.f2l(f), 0.5, pressure) : *(0.5);
