import("stdfaust.lib");

// --- Dedicated Tom Drum ---
freq = hslider("freq [unit:Hz]", 110, 50, 300, 0.1);
gain = hslider("gain", 0.7, 0, 1, 0.01);
gate = button("gate");

decay = hslider("decay_time", 0.5, 0.1, 2.0, 0.01);

tom_body = os.osc(freq * (1 + 2 * en.ar(0.001, 0.03, gate))) * en.ar(0.001, decay, gate);

process = tom_body * gain;
