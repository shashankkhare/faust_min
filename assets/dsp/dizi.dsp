declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Chinese transverse bamboo flute (Dizi) with dimo membrane buzz.
// Uses the calibrated precision flute waveguide (fm.lib) for perfect pitch tracking,
// coupled with the dimo paper membrane nonlinear waveshaper and resonator.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - gain
//   - pressure
//   - mouthPosition
//   - loss
//   - calibration
//   - vibrato
//   - breathiness
//   - buzzIntensity  (0-1, blend of dimo buzz vs clean tone)
//   - buzzFrequency  (dimo membrane resonant frequency, default 2200 Hz)
// =============================================================================
import("stdfaust.lib");
import("fm.lib");

// Dizi range: D4 (293.66 Hz) to Bb6 (1864.66 Hz)
fTarget = hslider("freq", 440.0, 290, 2000, 0.1) : si.smooth(0.995);
cal = hslider("calibration", 0.0, -1200.0, 1200.0, 0.01);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

gain = hslider("gain", 1.0, 0.0, 3.0, 0.01) : si.smoo;

pressure = hslider("pressure", 0.75, 0.0, 1.5, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.15, 0.01, 1.0, 0.001) : si.smoo;
loss = hslider("loss", 0.02, 0.0, 1.0, 0.001) : si.smoo;

buzzIntensity  = hslider("buzzIntensity", 0.35, 0.0, 1.0, 0.001) : si.smoo;
buzzFrequency  = hslider("buzzFrequency", 2200.0, 800.0, 4000.0, 10.0) : si.smoo;

vibrato = hslider("vibrato", 0.0, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.5;
vibratoDepth = vibrato * 0.015;
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * fTarget;
actualFreq = fTarget + vibratoLFO;

attackTime = 0.035;

rawEnv = en.asr(attackTime, 1.0, 0.05, t);
breathEnv = rawEnv : si.smooth(0.995);
releaseEnv = rawEnv : si.smooth(0.995);

breathIntensity = hslider("breathiness", 0.08, 0.0, 1.0, 0.01) : si.smoo;

externalAir = no.pink_noise
              : fi.highpass(2, 400.0)
              : fi.lowpass(2, 3500.0)
              : *(breathIntensity * 0.25 * breathEnv);

// Calibrated waveguide core (exact acoustic period tracking from fm.lib)
fluteCore = fluteModel(actualFreq, pressure, breathEnv, mouthPosition, loss, cal, 0.0, 0.45);

// =============================================================================
// Dimo Membrane Buzz Model
// =============================================================================
// The dimo is a thin membrane of reed tissue glued over a hole between the
// embouchure and the finger holes.
dimoQ = 4.0;
waveshaper(x) = (x * (1.0 + buzzIntensity * 1.5)) +
                (x * abs(x) * buzzIntensity * 2.0) +
                (x * x * x * buzzIntensity * 3.0);

dimoDrive = fi.dcblocker;
dimoBP = fi.resonbp(buzzFrequency, dimoQ, 1.0);
dimoProcessor = dimoDrive : waveshaper : dimoBP : *(2.0);

buzzSignal = fluteCore : dimoProcessor;
cleanSignal = fluteCore;

buzzMix = buzzIntensity;
output = (cleanSignal * (1.0 - buzzMix)) + (buzzSignal * buzzMix) + externalAir;

process = output * releaseEnv * gain * 0.242;
