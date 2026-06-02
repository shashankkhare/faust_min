declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// --- Dedicated Tom Drum ---
freq = hslider("freq [unit:Hz]", 110, 50, 300, 0.1);
gain = hslider("gain", 0.7, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

decay = hslider("decay_time", 0.5, 0.1, 2.0, 0.01);

// Velocity increases pitch envelope depth and click
pitch_env = en.ar(0.001, 0.03, gate) * (1.0 + 1.0 * velocity);
click = no.noise * en.ar(0.001, 0.01, gate) * 0.1 * velocity;

tom_body = os.osc(freq * (1 + 0.3 * pitch_env)) * en.ar(0.001, decay, gate);

process = (tom_body + click) * gain * velocity * (1.0 + 0.2 * velocity);
