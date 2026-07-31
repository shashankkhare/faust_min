declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Fretless sarod with goatskin membrane, teak wood bowl, chikari
//              drone strings, sympathetic taraf, and asymmetric tanh jawari.
//              All strings use the unified sitar_string waveguide from fm.lib.
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - gate
//   - velocity
//   - gain
//   - symp_gain
//   - strike
//   - chikari_freq1
//   - chikari_freq2
//   - chikari_gain
//   - jawari
//   - vibrato [style:check]
//   - vibrato_depth
//   - vibrato_rate
// =============================================================================

import("stdfaust.lib");
import("fm.lib");

// Expert Play Range: Sarod typical range C3 (~130 Hz) to A5 (~880 Hz).
freq = hslider("freq", 146.83, 90, 900, 0.01);
cal = hslider("calibration", 0.0, -100.0, 100.0, 0.01) : si.smoo;
gate = button("gate");
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gain = hslider("gain", 1.0, 0, 1, 0.01);
symp_gain = hslider("symp_gain", 0.05, 0, 1, 0.01); 
strike = hslider("strike", 0, 0, 2, 1);

chikari_freq1 = hslider("chikari_freq1", 130, 130, 900, 0.01);
chikari_freq2 = hslider("chikari_freq2", 166.5, 130, 900, 0.01);
chikari_gain = hslider("chikari_gain", 0.1, 0, 1, 0.01);

jawari = hslider("jawari", 0.25, 0, 1.0, 0.001);

vibrato = hslider("vibrato [style:check]", 0, 0, 1, 1);
vibrato_depth = hslider("vibrato_depth", 0.01, 0, 0.5, 0.001);
vibrato_rate = hslider("vibrato_rate", 6.5, 1, 10, 0.1);

gate_rel = 0.010 - velocity * 0.008;
trig = gate > gate';

// Short pluck transient for the excitation noise
gate_held_pluck = trig : pulse_timer > 0
with {
    pulse_timer(t) = loop ~ _
    with { loop(s) = ba.if(t, 150, max(0.0, s - 1.0)); };
};
pluck_env = en.ar(0.003, 0.015, gate_held_pluck);
pick_noise = no.noise : fi.bandpass(2, 100.0, 5000.0);
base_exc = pick_noise * 1.0 * pluck_env * velocity;

is_chikari = strike > 0.5;
melody_exc = base_exc * (1 - is_chikari);

chikari_trig = (is_chikari > is_chikari') | (trig & is_chikari);
chikari_pluck_gate = chikari_trig : chikari_pt > 0
with {
    chikari_pt(t) = loop ~ _
    with { loop(s) = ba.if(t, 150, max(0.0, s - 1.0)); };
};
chikari_pluck_env = en.ar(0.003, 0.015, chikari_pluck_gate);
chikari_trig_exc = (no.noise : fi.bandpass(2, 150.0, 12000.0)) * 0.05 * chikari_pluck_env * velocity;

smooth_reset(c, t, x) = loop ~ _
with {
    loop(y1) = ba.if(t, x, x * (1 - c) + y1 * c);
};

// Melody string parameters with Kampa Vibrato Applied to Pitch
melody_freq = (freq * (1 - is_chikari)) : + ~ *(is_chikari);
smooth_melody_freq = melody_freq : smooth_reset(0.999, trig);

kampa_lfo = os.osc(vibrato_rate) * vibrato_depth * gate * vibrato;
modulated_freq = smooth_melody_freq * (1.0 + kampa_lfo);

normFreq = (smooth_melody_freq - 80.0) / (800.0 - 80.0) : min(1.0) : max(0.0);

// CALIBRATED DECAY: Reduced max sustain from 4.0s down to 2.2s for tighter decay
dynSustain = 4.0 - normFreq * 1.7; 

melody_gate = max(gate, is_chikari) : si.smoo;

// sitar_string imported from fm.lib (read-only)
stringLoop = sitar_string(modulated_freq, dynSustain, jawari, 1.0, melody_gate, melody_exc, cal);

// 4 Chikari strings using sitar_string (detuned pairs for chorus)
chikariLoop = ( sitar_string(chikari_freq1 - 1.0, 1.5, jawari * 0.5, 1.0, chikari_trig, chikari_trig_exc, 0)
              + sitar_string(chikari_freq1 + 1.0, 1.5, jawari * 0.5, 1.0, chikari_trig, chikari_trig_exc, 0)
              + sitar_string(chikari_freq2 - 1.0, 1.5, jawari * 0.5, 1.0, chikari_trig, chikari_trig_exc, 0)
              + sitar_string(chikari_freq2 + 1.0, 1.5, jawari * 0.5, 1.0, chikari_trig, chikari_trig_exc, 0)
              ) * chikari_gain * 0.25;

// Main mechanical wire summation striking the skin
wire_sum = stringLoop + chikariLoop;

membrane_saturate(x) = ma.tanh(x * 2.0) / 2.0;
skin_vibration = wire_sum : membrane_saturate;

// Sympathetic strings (Taraf) using sitar_string
symp_exc = skin_vibration * gate : fi.lowpass(2, 12000.0);
symp_trigger = gate : si.smoo;

symp_strings_ks = ( sitar_string(max(freq, 40.0), 4.0, 0.05, symp_gain, symp_trigger, symp_exc, cal)
                  + sitar_string(max(freq * 1.5, 40.0), 4.0, 0.05, symp_gain, symp_trigger, symp_exc, cal)
                  + sitar_string(max(freq * 2.0, 40.0), 4.0, 0.05, symp_gain, symp_trigger, symp_exc, cal)
                  ) * 0.15;

summed = skin_vibration + symp_strings_ks;

// Goatskin membrane modes — tuned to real sarod FFT (Freesound #9610)
// Passthrough reduced to 0.15 (body_filter now carries the dry signal via its own passthrough).
// Low-freq resonances (150 Hz) scaled down: real data shows only 4.9% energy below 200 Hz.
// High-freq resonances (1200/1800/2600/3500 Hz) boosted: these are the wire/metal brightness
// that separates sarod from rubab. Lowpass raised 10 kHz → 14 kHz to let them through.
membrane_filter(x) =
    (  (x * 0.15)
     + (x : fi.resonbp(150.0,   3.0, 0.25))  // low-band, measured 4.9% — kept subtle
     + (x : fi.resonbp(236.7,   3.0, 0.25))
     + (x : fi.resonbp(240.2,   3.0, 0.25))
     + (x : fi.resonbp(315.4,   3.0, 0.25))
     + (x : fi.resonbp(320.7,   3.0, 0.25))
     + (x : fi.resonbp(342.3,   3.0, 0.25))
     + (x : fi.resonbp(386.4,   3.0, 0.25))
     + (x : fi.resonbp(402.7,   3.0, 0.25))
     + (x : fi.resonbp(423.0,   1.5, 0.15))
     + (x : fi.resonbp(438.7,   1.5, 0.15))
     + (x : fi.resonbp(465.3,   1.5, 0.15))
     + (x : fi.resonbp(477.4,   1.5, 0.15))
     + (x : fi.resonbp(498.4,   1.5, 0.15))
     + (x : fi.resonbp(522.9,   1.5, 0.15))
     + (x : fi.resonbp(535.9,   1.5, 0.15))
     + (x : fi.resonbp(544.2,   1.5, 0.15))
     + (x : fi.resonbp(553.6,   1.5, 0.12))
     + (x : fi.resonbp(573.3,   1.5, 0.12))
     + (x : fi.resonbp(606.6,   2.0, 0.15))
     + (x : fi.resonbp(610.3,   2.0, 0.12))
     + (x : fi.resonbp(850.0,   1.5, 0.15))
     + (x : fi.resonbp(1200.0,  2.5, 0.40))  // boosted: strong peak measured at 1150-1240 Hz
     + (x : fi.resonbp(1800.0,  2.5, 0.65))  // boosted: key string brightness
     + (x : fi.resonbp(2600.0,  2.5, 0.60))  // wire/metal presence
     + (x : fi.resonbp(3500.0,  2.5, 0.55))  // upper string harmonic shimmer
    ) : fi.lowpass(2, 14000.0);

// Wooden body bowl resonator — fixed based on real sarod FFT measurement.
// Added (x * 0.35) passthrough so membrane's 1800/2600/3500 Hz content survives.
// Reduced 180 Hz: real data shows only 4.9% energy in 50-200 Hz band.
// Added 1050/1200/1800 Hz peaks: strong clusters measured at 1025 Hz, 1150-1240 Hz.
body_filter(x) =
    (  (x * 0.35)                               // passthrough — carries membrane high-freqs
     + (x : fi.resonbp(180.0,  2.5,  1.45))    // reduced from 1.00 — low band not dominant
     + (x : fi.resonbp(320.0,  1.5,  0.60))    // tamed: was Q2.5/gain1.90, caused 349Hz resonance
     + (x : fi.resonbp(550.0,  2.0,  0.50))    // tamed: was Q4.0/gain1.30, caused 440/523Hz resonance
     + (x : fi.resonbp(950.0,  3.5,  0.85))    // kept
     + (x : fi.resonbp(1050.0, 3.5,  0.90))    // NEW — strong peak measured at 1025 Hz
     + (x : fi.resonbp(1200.0, 3.0,  0.80))    // NEW — cluster measured at 1150-1240 Hz
     + (x : fi.resonbp(1800.0, 3.0,  0.55))    // NEW — lets membrane 1800 Hz pass into body
    );

softclip(x) = ba.if(abs(x) < 0.9, x, 0.9 * ma.tanh(x / 0.9));

// Signal path: string → membrane (skin resonance) → body (wooden bowl) → output
// membrane_filter was previously dead code — now correctly wired into chain.
process = summed : membrane_filter : body_filter : *(gain * 2.4995) : softclip <: _,_;

