import("stdfaust.lib");

freq = hslider("freq", 55.0, 20.0, 200.0, 0.1) : si.smoo;
gate = button("gate");
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
gain = hslider("gain", 1.0, 0.0, 1.0, 0.01);

trig = gate > gate';

// Stick/mallet strike excitation
strike_env = en.ar(0.001, 0.05, trig);
strike_noise = no.noise * strike_env * velocity * 0.5;
strike_impulse = os.impulse * velocity;
exc = strike_impulse + strike_noise;

// Dagu (Large Barrel Drum) Modal Frequencies
// A massive wooden body with a thick leather skin.
mode1 = fi.resonbp(freq, 8, 1.0);         // Fundamental boom
mode2 = fi.resonbp(freq * 1.6, 12, 0.6);  // Leather skin stretch
mode3 = fi.resonbp(freq * 2.3, 15, 0.3);  // Resonator body
mode4 = fi.resonbp(freq * 3.8, 10, 0.1);  // High wooden crack from mallet

dagu = exc <: mode1 + mode2 + mode3 + mode4;

// Add some saturation/drive for cinematic punch
punch = dagu : *(1.5) : ma.tanh : *(0.8);

process = punch * gain : min(1.0) : max(-1.0);
