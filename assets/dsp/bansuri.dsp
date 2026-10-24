declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Fully calibrated, stable Classical Indian bamboo flute (Bansuri).
// =============================================================================
import("stdfaust.lib");
import("fm.lib");

// Expert Play Range: Bansuri range aligned with flute LUT (150 Hz to 2000 Hz) with frequency smoothing.
fTarget = hslider("freq", 440.0, 150, 2000, 0.1) : si.smooth(0.995);
cal = hslider("calibration", 0.0, -1200.0, 1200.0, 0.01);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

// fixgain.md step 6: 0.1575 * max_gain 1.5427 = 0.2429753 (absolute scaling).
// Step 7: gain slider restored to 0-1 with smoothing.
gain = hslider("gain", 1.0, 0.0, 1.0, 0.01) : si.smooth(0.03);
loss = hslider("loss", 0.02, 0.0, 1.0, 0.001) : si.smoo;
pressure = hslider("pressure", 0.72, 0.0, 1.5, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.15, 0.01, 1.0, 0.001) : si.smoo;

vibratoDepth = hslider("vibrato_depth", 0.0, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.0; 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * 0.015 * fTarget;
actualFreq = fTarget + vibratoLFO;

attackTime = 0.05;

// Gate-hold ASR envelopes with smooth corners prevent infinite slope at t=0.
rawEnv = en.asr(attackTime, 1.0, 0.05, t);
breathEnv = rawEnv : si.smooth(0.995);
releaseEnv = rawEnv : si.smooth(0.995);

breathIntensity = hslider("breathiness", 0.15, 0.0, 1.0, 0.01) : si.smoo;

// Path B: External air bypass — soft bamboo wind blended subtly under the tone.
externalAir = no.pink_noise
              : fi.highpass(2, 250.0)
              : fi.lowpass(2, 3200.0)
              : *(breathIntensity * 0.35 * breathEnv);

// Shares the calibrated waveguide and embouchure geometry with flute.dsp.
flute = fluteModel(actualFreq, pressure, breathEnv, mouthPosition, loss, cal, 0.0, 0.45);

// Final mix matrix
process = (flute + externalAir) 
          : *(releaseEnv) 
          : fi.lowpass(2, 5000.0) 
          : *(gain * 0.2429753); 

