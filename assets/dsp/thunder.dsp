declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

gain = hslider("gain", 1.0, 0, 1, 0.01);
gate = button("gate");

// 1. Saturated Rumble (Adding harmonics makes the low-end audible on small speakers)
rumble_env = en.ar(0.01, 3.5, gate);
rumble_raw = no.noise : fi.lowpass(2, 350);
rumble_sat = rumble_raw * 15.0 : min(1.0) : max(-1.0); // Soft clipping generates harmonics
rumble = rumble_sat * rumble_env * 0.6;

// 2. Mid "Roar" (The rolling, tearing sound of thunder)
roar_env = en.ar(0.1, 2.5, gate);
roar = no.noise : fi.resonbp(600, 1.5, 1.0) * roar_env * 0.5;

// 3. Initial High-Frequency Crack
crack_env = en.ar(0.001, 0.4, gate);
crack = no.noise : fi.highpass(2, 1200) * crack_env * 1.5;

src = rumble + roar + crack;

// Rolling delay effect to simulate echoes through clouds
echoes = src : + ~ (de.delay(48000, 8000) * 0.6 : fi.lowpass(1, 800));

// Massive cavernous reverb for the boom
thunder = (src + echoes * 0.5) <: re.zita_rev1_stereo :> +;

process = (thunder * 0.8 : min(1.0) : max(-1.0)) * gain;
