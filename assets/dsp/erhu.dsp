declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Chinese two-stringed bowed instrument (Erhu) physically modeled with
//              bow pressure, velocity, noise level, vibrato, pitch humanization,
//              and 5 strike playing styles (0=Détaché, 1=Staccato, 2=Sul Tasto,
//              3=Sul Ponticello, 4=Spiccato) with python-skin resonator body.
//
// Parameters (Controls):
//   - freq
//   - gate
//   - vibrato_rate
//   - vibrato_depth
//   - bowPressure
//   - bowVelocity
//   - bowPosition
//   - strike
//   - noiseLvl
//   - calibration
//   - gain
// =============================================================================
import("stdfaust.lib");

freq = hslider("freq", 440, 290, 1400, 0.1);
gate = button("gate");

// Expressive pitch controls
vibratoRate = hslider("vibrato_rate", 6.0, 3.0, 8.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.02, 0.0, 0.05, 0.001) : si.smoo; 

// Independent Physical Bowing Controls (0.72 is near the bridge where fundamental speaks clearly)
bowPressureTarget = hslider("bowPressure", 0.50, 0.0, 1.0, 0.01) : si.smoo;
bowVelocityTarget = hslider("bowVelocity", 0.50, 0.0, 1.0, 0.01) : si.smoo;
bowPositionTarget = hslider("bowPosition", 0.72, 0.0, 1.0, 0.01) : si.smoo;
noiseLvl = hslider("noiseLvl", 0.02, 0.0, 1.0, 0.01) : si.smoo;

// Strike Playing Styles (0 = Détaché/Legato, 1 = Staccato, 2 = Sul Tasto, 3 = Sul Ponticello, 4 = Spiccato)
strike = hslider("strike", 0.0, 0.0, 4.0, 1.0);

isStaccato      = (strike == 1.0);
isSulTasto      = (strike == 2.0);
isSulPonticello = (strike == 3.0);
isSpiccato      = (strike == 4.0);

// Attack and Release Times according to playing style
attackTime  = ba.if(isStaccato | isSpiccato, 0.010, ba.if(isSulTasto, 0.080, 0.035));
releaseTime = ba.if(isStaccato | isSpiccato, 0.025, 0.045);

// Dynamic Envelope targeting the bow activation path
bowEnv = gate : si.smooth(ba.tau2pole(ba.if(gate, attackTime, releaseTime)));

// Initial friction catch transient (bite) for Staccato / Spiccato strokes
catchBite = (gate : si.smooth(ba.tau2pole(0.015))) * (1.0 - (gate : si.smooth(ba.tau2pole(0.040))));
catchBoost = ba.if(isStaccato | isSpiccato, catchBite * 0.20, 0.0);

// Effective Bow Parameters per Style
effBowPress = ba.if(isSulTasto, 0.35, ba.if(isSulPonticello, 0.70, ba.if(isStaccato, 0.60, bowPressureTarget))) + catchBoost;
effBowVel   = ba.if(isSulTasto, 0.40, ba.if(isSpiccato, 0.55, ba.if(isStaccato, 0.60, bowVelocityTarget)));
effBowPos   = ba.if(isSulTasto, 0.50, ba.if(isSulPonticello, 0.88, bowPositionTarget));

// Apply envelope modulation directly to physics engine drives (full physical scale)
bowVelocity = effBowVel * bowEnv;

// Humanize bow pressure with micro-fluctuations (simulating rosin grip/slip and hand tremor)
microPressure = no.lfnoise(12.0) * 0.04 * effBowPress * bowEnv;
bowPressure = (effBowPress + microPressure) * bowEnv;
bowPosition = effBowPos;

// Calibration: frequency-dependent string length offset to correct pitch drift
calibration = hslider("calibration", 0.0, -0.1, 0.1, 0.001);

// Per-frequency gain slider
gain = hslider("gain", 1.0, 0, 1, 0.01);

// Humanization: subtle organic pitch drift & delayed vibrato bloom
drift = no.lfnoise(2.0) * 0.002 * freq;
vibEnv = gate : si.smooth(ba.tau2pole(0.35)); 
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

raw_string = erhuModel(pm.f2l(humanizedFreq) + calibration, bowPressure, bowVelocity, bowPosition);

// Add rosin/bow scrape noise for realism (removes flute-like purity)
bow_noise = no.noise * bowEnv * noiseLvl : fi.highpass(2, 2500);

// 1. Small Octagonal Box Acoustics: preserve D4 fundamental (293 Hz)
hp_filter = fi.highpass(2, 120);

// 2. Python Skin Membrane Resonances:
skin_mode1 = fi.resonbp(950, 4, 0.6);  // Primary drumhead mode
skin_mode2 = fi.resonbp(1550, 3, 0.4); // Secondary mode
skin_mode3 = fi.resonbp(2800, 5, 0.25); // High piercing "crying" mode

// 3. Nonlinear Membrane Buzz:
buzz(x) = x * (1.0 - 0.2 * x * x); // Subtle cubic distortion

// Assemble the Erhu body with strong direct string fundamental
erhu_body(x) = x : hp_filter : buzz <: (skin_mode1 + skin_mode2 + skin_mode3 + (_ * 0.75)) : _ * 0.7;

// Mix raw string back in with formants for a fuller sound
src = raw_string + bow_noise;
body_out = erhu_body(src);

process = body_out * (gain * 1.8) : ma.tanh;
