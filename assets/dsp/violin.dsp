declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Standard acoustic violin physically modeled with bowed string waveguides,
//              4-peak acoustic wood body filter, and 5 strike playing styles.
//
// Parameters (Controls):
//   - freq
//   - gate
//   - vibrato_rate
//   - vibrato_depth
//   - bowPressure
//   - bowVelocity
//   - bowPosition
//   - velocity
//   - strike
//   - calibration
// =============================================================================
import("stdfaust.lib");

// ============================================================
// Violin physical model using pm.violinModel (Romain Michon / Faust stdlib)
// ============================================================

f = hslider("freq", 440, 80, 1400, 0.1);
t = button("gate");

// Expressive pitch controls
vibratoRate = hslider("vibrato_rate", 5.5, 3.0, 8.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.012, 0.0, 0.05, 0.001) : si.smoo;

// Independent Physical Bowing Controls (Instantaneous response via si.smoo)
bowPressureTarget = hslider("bowPressure", 0.45, 0.0, 1.0, 0.001) : si.smoo;
bowVelocityTarget = hslider("bowVelocity", 0.50, 0.0, 1.0, 0.001) : si.smoo;
bowPositionTarget = hslider("bowPosition", 0.15, 0.0, 1.0, 0.001) : si.smoo;

// Strike Playing Styles (0 = Détaché/Legato, 1 = Staccato, 2 = Sul Tasto, 3 = Sul Ponticello, 4 = Spiccato)
strike = hslider("strike", 0.0, 0.0, 4.0, 1.0);

// Dynamic Articulation Mapping based on Strike Style
isStaccato      = (strike == 1.0);
isSulTasto      = (strike == 2.0);
isSulPonticello = (strike == 3.0);
isSpiccato      = (strike == 4.0);

// Attack and Release Times according to playing style
attackTime  = ba.if(isStaccato | isSpiccato, 0.010, ba.if(isSulTasto, 0.080, 0.035));
releaseTime = ba.if(isStaccato | isSpiccato, 0.025, 0.045);

// Dynamic Envelope targeting the bow activation path
bowEnv = t : si.smooth(ba.tau2pole(ba.if(t, attackTime, releaseTime)));

// Initial friction catch transient (bite) for Staccato / Spiccato strokes
catchBite = (t : si.smooth(ba.tau2pole(0.015))) * (1.0 - (t : si.smooth(ba.tau2pole(0.040))));
catchBoost = ba.if(isStaccato | isSpiccato, catchBite * 0.35, 0.0);

// Effective Bow Parameters per Style
effBowPress = ba.if(isSulTasto, 0.22, ba.if(isSulPonticello, 0.65, ba.if(isStaccato, 0.55, bowPressureTarget))) + catchBoost;
effBowVel   = ba.if(isSulTasto, 0.60, ba.if(isSpiccato, 0.40, ba.if(isStaccato, 0.70, bowVelocityTarget)));
effBowPos   = ba.if(isSulTasto, 0.28, ba.if(isSulPonticello, 0.04, bowPositionTarget));

// Apply envelope modulation directly to physics engine drives
bowVelocity = (effBowVel / 5.0) * bowEnv;

// Humanize bow pressure with micro-fluctuations (simulating rosin grip/slip and hand tremor)
microPressure = no.lfnoise(12.0) * 0.06 * (effBowPress / 5.0) * bowEnv;
bowPressure = ((effBowPress / 5.0) + microPressure) * bowEnv;
bowPosition = effBowPos : si.smoo;

// Calibration: frequency-dependent string length offset to correct pitch drift
calibration = hslider("calibration", 0.0, -0.1, 0.1, 0.001) : si.smoo;

// --- Pitch Humanization ---
drift = no.lfnoise(2.0) * 0.0012 * f * bowEnv;
vibEnv = t : si.smooth(ba.tau2pole(0.15)); 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * vibEnv * f;

humanizedFreq = f + drift + vibratoLFO;

// --- 4-Peak Acoustic Violin Wood Body Resonances ---
// Real violin body modal resonances:
// 1. A0 Air Mode (~275 Hz, Q=4.0, +6 dB) — Deep acoustic body warmth
// 2. B1- Lower Wood Mode (~440 Hz, Q=5.0, +8 dB) — Low plate resonance
// 3. B1+ Upper Wood Mode (~550 Hz, Q=5.0, +9 dB) — Main wood plate resonance
// 4. Bridge & Soundboard Formant (~2800 Hz, Q=2.5, +5 dB) — Sweet acoustic sheen
violinBody = fi.peak_eq(6.0, 275.0, 275.0 / 4.0)
           : fi.peak_eq(8.0, 440.0, 440.0 / 5.0)
           : fi.peak_eq(9.0, 550.0, 550.0 / 5.0)
           : fi.peak_eq(5.0, 2800.0, 2800.0 / 2.5);

// --- Physical Processing Engine Execution ---
process = pm.violinModel(pm.f2l(humanizedFreq) + calibration, bowPressure, bowVelocity, bowPosition)
          : fi.dcblocker
          : max(-1.0, min(1.0))
          : violinBody
          : *(0.45);
