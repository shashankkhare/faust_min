declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// --- Dedicated Cowbell ---
freq = hslider("freq [unit:Hz]", 560, 200, 1000, 1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

// Add your custom things here (e.g., clang amount)
clang = hslider("clang_intensity", 0.5, 0, 1, 0.01);

// Two detuned pulses for that classic metallic interference
// Velocity increases higher frequency clang
pulse1 = os.square(freq);
pulse2 = os.square(freq * 1.48); // Classic cowbell detune ratio

cowbell = (pulse1 + pulse2) * en.ar(0.001, 0.3, gate) : fi.highpass(2, 500 + 200 * velocity);

process = cowbell * gain * velocity * (1.0 + clang + 0.3 * velocity);
