declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// --- Dedicated Snare Drum ---
freq = hslider("freq [unit:Hz]", 180, 100, 400, 1);
gain = hslider("gain", 0.6, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

// Add your custom things here (e.g., snare wire rattle)
rattle = hslider("wire_rattle", 0.5, 0, 1, 0.01);

shell_tone = os.osc(freq) * en.ar(0.001, 0.1, gate);
wires = no.noise : fi.bandpass(1, 2000, 6000) * en.ar(0.001, 0.2 * (1 + rattle), gate) * (0.3 + 0.7 * velocity);

process = (shell_tone + wires) * gain * velocity * (1.0 + 0.2 * velocity);
