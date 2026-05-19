import("stdfaust.lib");

// --- Subtractive Synth Saxophone ---
freq = hslider("freq [unit:Hz]", 440, 50, 2000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

// Expressive controls
vibratoRate = hslider("vibrato_rate", 5.0, 0, 10, 0.1);
vibratoDepth = hslider("vibrato_depth", 0.015, 0, 0.1, 0.001);

breath = gate * gain : si.smooth(0.995);
vib = os.osc(vibratoRate) * vibratoDepth * breath;

// A sawtooth through a dynamic lowpass filter strongly mimics a reed instrument (Sax)
sax_env = en.adsr(0.05, 0.1, 0.8, 0.2, gate);
filter_cutoff = freq * 1.5 + breath * 3500;
process = os.sawtooth(freq * (1.0 + vib)) : fi.lowpass(2, filter_cutoff) * sax_env * gain * 0.5;
