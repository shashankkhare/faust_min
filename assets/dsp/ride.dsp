import("stdfaust.lib");

// --- Dedicated Meditative Ride Cymbal ---
freq = hslider("freq [unit:Hz]", 350, 100, 1000, 1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

// Complex wash/ping using FM pairs and multi-mode cluster
wash = no.noise : fi.bandpass(2, 1000, 8000) * en.ar(0.001, 1.5, gate);
ping = os.osc(freq) * en.ar(0.001, 0.2, gate) + os.osc(freq * 2.42) * en.ar(0.001, 0.1, gate);

process = (ping + wash * 0.4) * gain;
