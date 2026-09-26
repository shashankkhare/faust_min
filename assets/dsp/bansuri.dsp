declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Fully calibrated, stable Classical Indian bamboo flute (Bansuri).
// =============================================================================
import("stdfaust.lib");
import("fm.lib");

// Expert Play Range: Bansuri typical range A3 (220 Hz) to C6 (1046 Hz).
fTarget = hslider("freq", 440.0, 160, 1046, 0.1);
cal = hslider("calibration", 0.0, -1200.0, 1200.0, 0.01);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

// fixgain.md step 6: 0.1575 * max_gain 1.5427 = 0.2429753 (absolute scaling).
// Step 7: gain slider restored to 0-1 with smoothing.
gain = hslider("gain", 1.0, 0.0, 1.0, 0.01) : si.smooth(0.03);
wall_loss = hslider("wallLoss", 0.9, 0.0, 1.0, 0.01) : si.smoo;
// --- CRITICAL FIX 1: Raised default pressure target to jump-start the loop solver ---
pressureTarget = hslider("pressure", 0.88, 0.2, 1.5, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

vibratoDepth = hslider("vibrato_depth", 0.2, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.0; 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * 0.015 * fTarget;
actualFreq = fTarget + vibratoLFO;

attackTime = 0.005 + (1.0 - velocity) * 0.1;
pressure = t * pressureTarget : min(1.5) : si.smooth(ba.tau2pole(attackTime));

breathIntensity = hslider("breathiness", 0.3, 0.0, 1.0, 0.01) : si.smoo;

burstRelease = 0.12;
poleRel = ba.tau2pole(burstRelease);
burstScale = 0.5 / (1.0 - poleRel);
tDel = t : mem;
risingEdge = t - tDel : >(0);
gateBurst = risingEdge * burstScale : si.smooth(poleRel);

actualBreath = breathIntensity + gateBurst;

// Path A: Stable turbulence injector into the tube
jetTurbulence = no.pink_noise * actualBreath * 0.05; 
noisyPressure = pressure + (jetTurbulence * pressure);

// Path B: External air bypass — soft wind, not hiss.
// Highpass removes muddy low rumble, lowpass removes harsh top hiss;
// the result is smooth broadband breath blended under the tone.
externalAir = no.pink_noise
              : fi.highpass(2, 250.0)
              : fi.lowpass(2, 3200.0)
              : *(actualBreath * 12.0 * t);

releaseEnv = t : si.smooth(ba.tau2pole(0.04));

// The waveguide is shared with flute.dsp through fm.lib's fluteModel, which carries
// the single-tap / bounded-valve loop fix that removed the low-register mode lock.
// Bansuri keeps its own embouchure split (0.2 + mouthPosition*0.3) and its wallLoss
// character; pressure shaping, the turbulence injector and the external air path
// above/below are unchanged. fm.lib applies the same pitch trim internally, so the
// separate calibratedFreq stage is no longer needed.
flute = fluteModel(actualFreq, noisyPressure, 1.0, mouthPosition, wall_loss, cal, 0.2, 0.3);

// Final mix matrix
process = (flute + externalAir) 
          : *(releaseEnv) 
          : fi.lowpass(2, 5000.0) 
          : *(gain * 0.2429753); 

