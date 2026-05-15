import("stdfaust.lib");

// --- Dedicated Kick Drum ---
freq = hslider("freq [unit:Hz]", 55, 20, 200, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

// Add your custom things here (e.g., sub-bass boost)
sub_boost = hslider("sub_boost", 0.5, 0, 1, 0.01);

pitch_env = en.ar(0.001, 0.05, gate);
click = no.noise * en.ar(0.001, 0.01, gate) * 0.5 * (0.5 + 0.5 * velocity);

kick_body = os.osc(freq * (1 + 4 * pitch_env)) * en.ar(0.001, 0.3, gate);

process = (kick_body + click) * gain * velocity * (1.0 + 0.2 * velocity);
