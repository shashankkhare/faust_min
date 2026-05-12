import("stdfaust.lib");

// --- Physical Model Saxophone ---
freq = hslider("freq [unit:Hz]", 440, 50, 2000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

// Expressive physical controls
vibratoRate = hslider("vibrato_rate", 5.0, 0, 10, 0.1);
vibratoDepth = hslider("vibrato_depth", 0.02, 0, 0.1, 0.001);

// Waveguide with reed stiffness table modeling
breath = gate * gain : si.smooth(0.995);
vib = os.osc(vibratoRate) * vibratoDepth;

// Faust standard physical model macro
process = pm.brassModel(pm.f2l(freq * (1.0 + vib)), 0.6, breath, 0.5) * 0.5;
