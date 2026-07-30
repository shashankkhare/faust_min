declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Standard acoustic violin physically modeled with bowed string waveguides, adjustable bow pressure, velocity, and position.
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
//   - calibration
// =============================================================================
import("stdfaust.lib");

// ============================================================
// Violin physical model using pm.violinModel (Romain Michon / Faust stdlib)
// ============================================================

f = hslider("freq", 440, 80, 1400, 0.1) : si.smoo;
t = button("gate");

// Expressive pitch controls
vibratoRate = hslider("vibrato_rate", 5.5, 3.0, 8.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.012, 0.0, 0.05, 0.001) : si.smoo;

// Independent Physical Bowing Controls (Instantaneous response via si.smoo)
bowPressureTarget = hslider("bowPressure", 0.4,  0.0, 1.0, 0.001) : si.smoo;
bowVelocityTarget = hslider("bowVelocity", 0.5,  0.0, 1.0, 0.001) : si.smoo;
bowPosition       = hslider("bowPosition", 0.15, 0.0, 1.0, 0.001) : si.smoo;

// --- Velocity Controlled Articulation ---
// velocity slider acts as note articulation style (Default: 0.5 = 75ms attack)
velocity = hslider("velocity", 0.5, 0.0, 1.0, 0.01);

// Calibration: frequency-dependent string length offset to correct pitch drift
// (set automatically by CSV LUT; 0 = no correction)
calibration = hslider("calibration", 0.0, -0.1, 0.1, 0.001) : si.smoo;

// Linearly map velocity to attack time up to 150ms
attackTime  = velocity * 0.150; 
releaseTime = 0.030; // Snappy 30ms release to clear fast note transitions

// Dynamic Envelope targeting the bow activation path
bowEnv = t : si.smooth(ba.tau2pole(ba.if(t, attackTime, releaseTime)));

// Apply envelope modulation directly to physics engine drives
bowVelocity = (bowVelocityTarget / 5.0) * bowEnv;

// Humanize bow pressure with micro-fluctuations (simulating rosin grip/slip and hand tremor).
// IMPORTANT: microPressure is multiplied by bowEnv here (not just in bowPressure below) so that
// the random lf-noise source is SILENT during the attack phase and only fades in as the bow
// settles. Without this, no.lfnoise(12.0) is always running and enters at a random phase on
// each new note, causing audible pressure wobble at note onset — especially on Strike 0 (150ms
// slow attack) when played in a fast sequencer context.
microPressure = no.lfnoise(12.0) * 0.08 * (bowPressureTarget / 5.0) * bowEnv;
bowPressure = ((bowPressureTarget / 5.0) + microPressure) * bowEnv;

// --- Faust pm.violinBody Compensation Filter ---
bodyCompGain = max(1.0, min(3.0,
    sqrt(1.0 + 4.0 * ((f / 500.0) - (500.0 / f)) * ((f / 500.0) - (500.0 / f)))
));

// --- Pitch Humanization ---
// IMPORTANT: drift is gated through bowEnv so random pitch deviation is ZERO during attack
// and only grows in once the bow is fully engaged. Without this gate, no.lfnoise(2.0) runs
// continuously at a random phase between notes and causes audible pitch instability at the
// very start of each new note — clearly audible as a "wobble" on slow-attack Strike 0 notes
// in the sequencer. vibratoLFO is already safely gated by vibEnv which ramps from gate.
drift = no.lfnoise(2.0) * 0.0015 * f * bowEnv;
vibEnv = t : si.smooth(ba.tau2pole(0.3)); 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * vibEnv * f;

humanizedFreq = f + drift + vibratoLFO;

// --- Physical Processing Engine Execution ---
// DC blocker (fi.dcblocker) removes any DC offset accumulated in the waveguide feedback
// loop which can build up during model instability. Hard clip at ±1.0 prevents any
// momentary instability from corrupting the audio output stream.
process = pm.violinModel(pm.f2l(humanizedFreq) + calibration, bowPressure, bowVelocity, bowPosition)
          : fi.dcblocker
          : max(-1.0, min(1.0))
          : *(bodyCompGain)
          : *(1.1);
