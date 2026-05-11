import("stdfaust.lib");

// --- Dedicated Singing Bowl ---
freq = hslider("freq [unit:Hz]", 220, 50, 1000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

// Add your custom things here (e.g., rub intensity for sustained singing)
rub = hslider("rub_intensity", 0.0, 0, 1, 0.01);

modal(f, d, t) = os.osc(f) * en.ar(0.01, d, t);

// Modal modes for a rich metallic bowl
bowl = modal(freq, 6.0, gate) + 
       modal(freq * 2.81, 4.5, gate) * 0.4 + 
       modal(freq * 5.22, 3.0, gate) * 0.2 +
       (no.noise : fi.lowpass(1, freq * 2) * rub); // Friction noise

process = bowl * gain;
