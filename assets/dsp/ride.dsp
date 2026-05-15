import("stdfaust.lib");

// --- Dedicated Meditative Ride Cymbal ---
freq = hslider("freq [unit:Hz]", 350, 100, 1000, 1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
strike = hslider("strike", 0, 0, 3, 1); 
gate = button("gate");

// Complex wash/ping using FM pairs and multi-mode cluster
// Velocity increases wash vs ping balance
wash = no.noise : fi.bandpass(2, 1000, 8000) * en.ar(0.001, 1.5, gate) * (0.2 + 0.8 * velocity);
ping = os.osc(freq) * en.ar(0.001, 0.2, gate) + os.osc(freq * 2.42) * en.ar(0.001, 0.1, gate);

// 0: Tip (more ping), 1: Bow (more wash), 2: Bell (high ping)
strike_balance = ba.selectn(4, strike, 0.2, 0.6, 0.1, 0.3);

process = (ping + wash * strike_balance) * gain * velocity * (1.0 + 0.1 * velocity);
