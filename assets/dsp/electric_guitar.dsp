declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

// =============================================================================
// === ELECTRIC GUITAR PHYSICAL MODEL (Steel Waveguide + Magnetic Pickup + Tube Amp) ===
// Fixes pm.elecGuitar's fixed per-reflection 0.64 loss (which killed >300 Hz in <15ms
// and forced 1600x pregain fuzz that sounded like an organ).
// Uses frequency-calibrated T60 loop loss, gate-linked finger damping on noteOff ('_'),
// magnetic pickup position comb filtering, and warm asymmetric tube amp + 12" cabinet.
// =============================================================================

// Expert Play Range: Electric Guitar typical range E2 (82 Hz) to C6 (1046 Hz).
freq          = hslider("freq", 196.0, 82, 1046, 0.01);
velocity      = hslider("velocity", 0.5, 0, 1, 0.01);
gate          = button("gate");
gain          = hslider("gain", 1.0, 0, 1, 0.01);
calibration   = hslider("calibration", 0, -100, 100, 0.01);
cfreq         = freq * (2.0 ^ (calibration / 1200.0));

pluckPosition = hslider("pluckPosition", 0.78, 0.05, 0.95, 0.01);
mute          = hslider("mute", 1.0, 0.0, 1.0, 0.01);

// Clean/warm jazz-blues defaults; raising drive/sustain yields classic rock crunch
drive         = hslider("drive", 0.18, 0, 1, 0.01);
sustain       = hslider("sustain", 0.35, 0, 1, 0.01);

// --- 1. Counter-based pick excitation (Rule 23: reliable retrigger) ---
rawTrig = (gate - gate') > 0.0;
pickSamples = max(8.0, min(192.0, ma.SR * 1.2 / cfreq));

pickTimer = rawTrig : pulse_counter
with {
    pulse_counter(t) = loop ~ _
    with {
        loop(cnt) = ba.if(t > 0.0, pickSamples, max(0.0, cnt - 1.0));
    };
};

pickActive   = pickTimer > 0.0;
pickProgress = 1.0 - (pickTimer / pickSamples);
pickPluck    = sin(ma.PI * pickProgress) * pickActive;
pickScrape   = no.noise * sin(ma.PI * pickProgress) * pickActive * (0.25 + 0.35 * velocity);
excitation   = (pickPluck * 0.75 + pickScrape) * velocity
             : fi.lowpass(1, 1400.0 + velocity * 5500.0);

// --- 2. Steel string waveguide with constant-T60 sustain & gate finger-muting ---
targetT60 = ba.if(gate > 0.0, 1.6 + sustain * 2.8, 0.035) : si.smooth(ba.tau2pole(0.006));
loopGain  = pow(0.001, 1.0 / max(1.0, cfreq * targetT60)) * (0.2 + 0.8 * mute);

dispersion = fi.allpassnn(1, 0.05 * max(0.0, 1.0 - cfreq / 2200.0));
stringLPF  = fi.lowpass(1, min(14000.0, 3200.0 + cfreq * 7.0));
delayLen   = max(2.0, (ma.SR / cfreq) - 2.50);

steelString(detune) = excitation : + ~ (
    de.fdelay(4096, delayLen * detune)
    : dispersion
    : stringLPF
    : *(loopGain)
);

// Slight dual-unison chorus richness + magnetic pickup spatial comb filter
rawString   = steelString(1.0) * 0.75 + steelString(1.0006) * 0.25;
pickupDelay = max(1.5, (ma.SR / cfreq) * (1.0 - pluckPosition));
pickupSig   = (rawString - 0.75 * de.fdelay(1024, pickupDelay, rawString));

// --- 3. Warm asymmetric tube preamp + 12" speaker cabinet + click-free gate ---
ampGate = en.asr(0.001, 1.0, 0.04, gate);
pregain = 1.0 + drive * 2.5;
cabinet = fi.highpass(2, 85.0) : fi.peak_eq_cq(2.0, 1100.0, 1.1) : fi.lowpass(2, 3800.0);

process = pickupSig
        : fi.dcblocker
        : *(pregain)
        : ef.cubicnl(drive * 0.45, 0.06)
        : fi.dcblocker
        : cabinet
        : *(ampGate * gain * 10.8)
        : ma.tanh;
