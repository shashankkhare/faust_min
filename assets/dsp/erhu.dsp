declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Chinese two-stringed bowed instrument (Erhu) physically modeled with bow pressure, velocity, noise level, and vibrato.
//
// Parameters (Controls):
//   - freq
//   - gate
//   - gain
//   - vibrato_rate
//   - vibrato_depth
//   - bowPressure
//   - bowVelocity
//   - bowPosition
//   - noiseLvl
// =============================================================================
import("stdfaust.lib");

freq = hslider("freq", 440, 80, 1400, 0.1) : si.smoo;
gate = button("gate");
gain = hslider("gain", 1.0, 0.0, 1.0, 0.01) : si.smoo;

vibratoRate = hslider("vibrato_rate", 6.0, 3.0, 8.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.02, 0.0, 0.05, 0.001) : si.smoo; 

bowPressure = hslider("bowPressure", 0.6, 0.0, 1.0, 0.01) : si.smoo;
bowVelocity = hslider("bowVelocity", 0.3, 0.0, 1.0, 0.01) : si.smoo;
bowPosition = hslider("bowPosition", 0.15, 0.0, 1.0, 0.01) : si.smoo;
noiseLvl = hslider("noiseLvl", 0.02, 0.0, 1.0, 0.01) : si.smoo;

releaseEnv = gate : si.smooth(ba.tau2pole(0.05));

// Humanization
drift = no.lfnoise(2.0) * 0.002 * freq;
vibEnv = gate : si.smooth(ba.tau2pole(0.2)); 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * vibEnv * freq;
humanizedFreq = freq + drift + vibratoLFO;

// Custom raw bowed string (bypasses pm.violinModel's built-in wooden body)
erhuModel(stringLength, bowPress, bowVel, bowPos) = 
    pm.endChain(pm.chain(
        pm.violinNuts :
        pm.violinBowedString(stringLength - 0.08, bowPress, bowVel, bowPos) :
        pm.violinBridge :
        pm.out
    ));

raw_string = erhuModel(pm.f2l(humanizedFreq), bowPressure * gate, bowVelocity * gate, bowPosition);

// Add rosin/bow scrape noise for realism (removes flute-like purity)
bow_noise = no.noise * gate * noiseLvl : fi.highpass(2, 2500);

// 1. Small Octagonal Box Acoustics:
// A tiny box physically cannot radiate low frequencies like a violin's large wooden back.
hp_filter = fi.highpass(3, 600); // Drastically cut low-end warmth

// 2. Python Skin Membrane Resonances:
// The bridge rests directly on a stretched python skin, acting like a tiny drum/banjo.
// This creates very sharp, nasal mid-frequency formants.
skin_mode1 = fi.resonbp(950, 4, 1.0);  // Primary drumhead mode
skin_mode2 = fi.resonbp(1550, 3, 0.6); // Secondary mode
skin_mode3 = fi.resonbp(2800, 5, 0.4); // High piercing "crying" mode

// 3. Nonlinear Membrane Buzz:
// The stretched skin compresses under heavy bow pressure, creating a slight gritty buzz.
buzz(x) = x * (1.0 - 0.3 * x * x); // Subtle cubic distortion

// Assemble the Erhu body
erhu_body(x) = x : hp_filter : buzz <: (skin_mode1 + skin_mode2 + skin_mode3 + (_ * 0.15)) : _ * 0.8;

// Mix raw string back in with formants for a fuller sound
src = raw_string + bow_noise;
body_out = erhu_body(src);

// Proper ADSR envelope to give notes shape instead of a continuous drone
env = en.adsr(0.1, 0.2, 0.8, 0.3, gate);

process = body_out * env * gain * 0.6 : min(1.0) : max(-1.0);
