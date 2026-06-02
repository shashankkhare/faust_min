declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
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

// Linearly map velocity to attack time up to 150ms
attackTime  = velocity * 0.150; 
releaseTime = 0.030; // Snappy 30ms release to clear fast note transitions

// Dynamic Envelope targeting the bow activation path
bowEnv = t : si.smooth(ba.tau2pole(ba.if(t, attackTime, releaseTime)));

// Apply envelope modulation directly to physics engine drives
bowVelocity = bowVelocityTarget * bowEnv;
bowPressure = bowPressureTarget * bowEnv;

// --- Faust pm.violinBody Compensation Filter ---
bodyCompGain = max(1.0, min(3.0,
    sqrt(1.0 + 4.0 * ((f / 500.0) - (500.0 / f)) * ((f / 500.0) - (500.0 / f)))
));

// --- Pitch Humanization ---
drift = no.lfnoise(2.0) * 0.0015 * f;
vibEnv = t : si.smooth(ba.tau2pole(0.3)); 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * vibEnv * f;

humanizedFreq = f + drift + vibratoLFO;

// --- Physical Processing Engine Execution ---
process = pm.violinModel(pm.f2l(humanizedFreq), bowPressure, bowVelocity, bowPosition)
          : *(bodyCompGain)
          : *(0.6);

