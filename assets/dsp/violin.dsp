import("stdfaust.lib");

// Violin physical model using pm.violinModel (Romain Michon / Faust stdlib)
// violinModel(stringLength, bowPressure, bowVelocity, bowPosition)
//   - stringLength : computed from freq via pm.f2l (length in meters)
//   - bowPressure  : how hard the bow presses the string (0-1), higher = raspier tone
//   - bowVelocity  : how fast the bow moves (0-1), acts as the drive/volume
//   - bowPosition  : where along the string the bow contacts (0-1, ~0.15 = sul tasto)

f = hslider("freq", 440, 80, 1400, 0.1) : si.smoo;
t = button("gate");

// Expressive pitch controls
vibratoRate = hslider("vibrato_rate", 5.5, 3.0, 8.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.012, 0.0, 0.05, 0.001) : si.smoo; // 1.2% depth

// Multi-Column Dynamic Parameters controlled by Companion CSV Lookup Table
// Mapped directly via Inverse Distance Weighting from (freq, velocity) vectors
bowPressureTarget = hslider("bowPressure", 0.4,  0.0, 1.0, 0.001) : si.smoo;
bowVelocityTarget = hslider("bowVelocity", 0.05, 0.0, 1.0, 0.001) : si.smoo;
bowPosition       = hslider("bowPosition", 0.15, 0.0, 1.0, 0.001) : si.smoo;

// Gate-driven bow velocity (bow stops when gate is off)
bowVelocity = t * bowVelocityTarget : si.smooth(0.999);
bowPressure = t * bowPressureTarget : si.smooth(0.999);

// Fast 30ms release envelope to cleanly silence the bow sound on noteOff
releaseEnv = t : si.smooth(ba.tau2pole(0.030));

// pm.violinBody uses fi.resonbp(500, 2, 1) — a fixed bandpass at 500 Hz.
// This causes natural rolloff above 500 Hz (at 659 Hz: ~-3.5dB, at 880 Hz: ~-7dB).
// We compute the exact inverse of that bandpass response and apply it as a gain boost
// to restore flat volume across the full violin range (clamped to 3x max).
bodyCompGain = max(1.0, min(3.0,
    sqrt(1.0 + 4.0 * ((f / 500.0) - (500.0 / f)) * ((f / 500.0) - (500.0 / f)))
));

// --- Professional Pitch Humanization ---
// 1. Organic Drift: Very slow 2Hz random noise simulating finger micro-movements (~0.15% pitch dev)
drift = no.lfnoise(2.0) * 0.0015 * f;

// 2. Delayed Vibrato: A slow 0.3s ramp-up that begins when the note is held, simulating
// the player attacking the note flat, then rolling into the vibrato.
vibEnv = t : si.smooth(ba.tau2pole(0.3)); 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * vibEnv * f;

humanizedFreq = f + drift + vibratoLFO;

process = pm.violinModel(pm.f2l(humanizedFreq), bowPressure, bowVelocity, bowPosition)
          : *(releaseEnv)
          : *(bodyCompGain)
          : *(0.6);
