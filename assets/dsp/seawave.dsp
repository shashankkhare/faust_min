import("stdfaust.lib");

gain = hslider("gain", 0.5, 0, 1, 0.01);
intensity = hslider("velocity", 0.5, 0, 1, 0.01) : si.smoo;
gate = button("gate");

// 2.0s release hides the Dart pattern-looping gaps!
gate_switch = gate : si.smooth(ba.tau2pole(2.0)); 

// 1. ASYMMETRIC MASTER ENVELOPE
rand_drift = (os.osc(0.013) * 0.5 + os.osc(0.021) * 0.5) * 0.02;
ph = os.phasor(1.0, 0.08 + rand_drift); // Phase counter from 0.0 to 1.0

// Warp the phase so the peak happens at 85% of the cycle!
// This makes the wave swell slowly, but die out very quickly (along with the crash)
peak_pos = 0.85; 
ph_warped = select2(ph >= peak_pos, 
                    (ph / peak_pos) * 0.5, 
                    0.5 + ((ph - peak_pos) / (1.0 - peak_pos)) * 0.5);

// Perfectly smooth mathematical wave: Silence -> Slow Swell -> Peak -> Fast Die-out
waveEnv = (1.0 - cos(ph_warped * 2 * ma.PI)) * 0.5;

// 2. FLAWLESS PEAK DETECTION
// Fires EXACTLY once when the phase crosses the peak position
peak_trigger = (ph >= peak_pos) & (mem(ph) < peak_pos);

// Crisp 0.8-second decaying foam burst triggered precisely at the crest
crash_raw_env = peak_trigger : + ~ *(ba.tau2pole(0.8));
crash_env = crash_raw_env : si.smooth(ba.tau2pole(0.05));

// 3. TEXTURE LFOs & SYNTHESIS
lfo1 = os.osc(0.137) * 0.5 + 0.5;
lfo2 = os.osc(0.191) * 0.5 + 0.5;
texture_sweep = (lfo1 * 0.6 + lfo2 * 0.4);

// Dynamic filters for organic swirling
sweep = texture_sweep * 0.5 + 0.8;
body  = no.pink_noise : fi.lowpass(2, (100.0 + intensity * 200.0) * sweep) * 0.85;

body_gain  = 1.0 - (crash_env * 0.55);
body_clean = body * body_gain;

crash_noise = no.pink_noise : fi.highpass(2, 600.0 + (texture_sweep * 200.0));
crash = crash_noise * crash_env * (0.4 + intensity * 0.3) * 0.25;

mix = (body_clean + crash) * waveEnv;

process = mix : fi.dcblocker : *(gate_switch) : *(gain * 20.0) : ma.tanh;
