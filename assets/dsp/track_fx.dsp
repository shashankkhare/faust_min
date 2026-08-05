declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
declare name "track_fx";

// =============================================================================
// === PER-TRACK INSERT FX ===
// Stereo 3-band EQ (bass shelf / parametric mid / treble shelf) followed by a
// feedback echo. Instantiated once per MixerTrack, inserted post-AGC in the
// accumulation loop. Params are automatable through MapUI like instruments.
// =============================================================================
import("stdfaust.lib");

// --- Bypass Switches ---
bypass_eq   = checkbox("bypass_eq");
bypass_echo = checkbox("bypass_echo");

// --- Echo ---
echo_mix      = hslider("echo_mix", 0, 0, 1, 0.01);
echo_feedback = hslider("echo_feedback", 0.3, 0, 0.95, 0.01);
echo_time     = hslider("echo_time", 0.25, 0.02, 1.0, 0.01);

// --- 3-Band EQ ---
bass_db   = hslider("bass_db", 0, -18, 18, 0.5);
mid_db    = hslider("mid_db", 0, -18, 18, 0.5);
mid_freq  = hslider("mid_freq", 1000, 20, 20000, 1);
mid_q     = hslider("mid_q", 1.0, 0.1, 18, 0.1);
treble_db = hslider("treble_db", 0, -18, 18, 0.5);

// --- 3-band EQ chain (per channel) ---
// low_shelf(gain_dB, fc), peak_eq(gain_dB, fc, bandwidth_Hz), high_shelf(gain_dB, fc)
eqBand(x) = x : fi.low_shelf(bass_db, 250.0)
              : fi.peak_eq(mid_db, mid_freq, mid_freq / mid_q)
              : fi.high_shelf(treble_db, 2500.0);

// --- Feedback echo (per channel) ---
maxEchoSeconds = 1.0;
echoCore(x) = x + echo_mix * wet
with {
    n   = int(maxEchoSeconds * ma.SR);
    d   = int(echo_time * ma.SR);
    wet = x : + ~ (de.delay(n, d) * echo_feedback);
};

// --- Bypassed Stages ---
eq_stage = ba.bypass1(bypass_eq, eqBand);
echo_stage = ba.bypass1(bypass_echo, echoCore);

process = _ , _ : (eq_stage, eq_stage) : (echo_stage, echo_stage);
