import("stdfaust.lib");

// --- Dedicated Meditative Bell ---
freq = hslider("freq [unit:Hz]", 440, 200, 2000, 1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

// Bell specific: Long ring time
ring_time = hslider("ring_time", 2.0, 0.5, 10.0, 0.1);

modal(f, d, t) = os.osc(f) * en.ar(0.001, d, t);

bell = modal(freq, ring_time, gate) + 
       modal(freq * 2.001, ring_time * 0.7, gate) * 0.6 + 
       modal(freq * 3.502, ring_time * 0.5, gate) * 0.4 +
       modal(freq * 4.903, ring_time * 0.3, gate) * 0.2;

process = bell * gain;
