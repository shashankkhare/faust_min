declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// The Master Reverb Bus
// A lush, massive Zita Stereo Reverb designed for ambient, meditative sleep soundscapes.
// Takes 2 inputs (Left, Right) and outputs 2 reverberated channels (Left, Right).

// Configurable parameters so the C++ Mixer can optionally control the size
decay_time = hslider("decay_time", 8.0, 1.0, 30.0, 0.1); // Mid-frequency decay time (T60m) in seconds
damping_freq = hslider("damping_freq", 6000, 1000, 10000, 10); // High frequency damping
low_rt60 = hslider("low_rt60", 2.0, 0.1, 8.0, 0.1); // Low frequency decay (T60dc) - keep short to avoid mud!

process = _,_ : par(i, 2, fi.highpass(2, 80.0)) : re.zita_rev1_stereo(60.0, 200.0, damping_freq, low_rt60, decay_time, 48000.0);
