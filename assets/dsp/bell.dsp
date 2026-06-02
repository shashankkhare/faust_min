declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// --- Dedicated Meditative Bell ---
freq = hslider("freq [unit:Hz]", 440, 200, 2000, 1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

// Bell specific: Long ring time
ring_time = hslider("ring_time", 2.0, 0.5, 10.0, 0.1);

// Velocity-dependent modal scaling (Harder strike = brighter bell)
bright = velocity * 0.7;

modal(f, d, t, g) = os.osc(f) * en.ar(0.001, d, t) * g;

bell = modal(freq, ring_time, gate, 1.0) + 
       modal(freq * 2.001, ring_time * 0.7, gate, 0.6 + bright * 0.2) + 
       modal(freq * 3.502, ring_time * 0.5, gate, 0.4 + bright * 0.4) +
       modal(freq * 4.903, ring_time * 0.3, gate, 0.2 + bright * 0.6);

process = bell * gain * velocity;
