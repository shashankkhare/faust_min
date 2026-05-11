import("stdfaust.lib");

// --- AI-Ready Physical Modeling Flute ---
// Based on STK (Synthesis Tool Kit) principles but optimized for AI control

// 1. Parameters (Exposed for AI/Orchestrator)
freq = hslider("freq [unit:Hz]", 440, 20, 2000, 0.01) : si.polySmooth(0.999, 1e-3, 44100);
gain = hslider("gain", 0.5, 0, 1, 0.01) : si.polySmooth(0.999, 1e-3, 44100);
gate = button("gate");

// AI Specific Parameters (to be driven by Magenta CSV)
pressure = hslider("ai_pressure", 0.8, 0, 1, 0.01) : si.polySmooth(0.999, 1e-3, 44100);
vibrato_rate = hslider("ai_vibrato_rate", 5.0, 0, 15, 0.1);
vibrato_depth = hslider("ai_vibrato_depth", 0.0, 0, 1, 0.01);
breath_noise = hslider("ai_breath_noise", 0.01, 0, 1, 0.01);

// 2. Synthesis Logic
// Simple Waveguide Loop
vibrato = os.osc(vibrato_rate) * vibrato_depth * (freq/100.0);
actual_freq = freq + vibrato;

// Excitation (Pressure + Noise)
excitation = (pressure + no.noise * breath_noise) * gate;

// Resonator (Delay line based on frequency)
delay_len = ma.SR / actual_freq;
flute_loop = excitation : pm.fdelay(1024, delay_len) : ef.cubic_distortion(0.5);

// Output
process = flute_loop * gain * gate : fi.lowpass(1, 5000) : *(0.5);
