declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Plucked wire-string sitar with dual-mode chikari drone, sympathetic
//              taraf strings, gourd body resonator, and adjustable bridge jawari.
//              Uses asymmetric tanh jawari in a waveguide feedback loop.
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - gate
//   - gain
//   - velocity
//   - strike [style:knob]   — 0=melody, 1=chikari, 2=mizrab accent
//   - jivari [style:knob]
//   - symp_gain
//   - chikari_freq [unit:Hz]
//   - sustain [unit:s]
//   - symp_drift [unit:Hz]
//   - vibrato [style:check]
//   - vibrato_depth
//   - vibrato_rate
// =============================================================================
import("stdfaust.lib");
import("fm.lib");
freq = hslider("freq [unit:Hz]", 138.6, 130, 2400, 0.01); 
cal = hslider("calibration", 0.0, -100.0, 100.0, 0.01) : si.smoo;
gate = button("gate");
gain = hslider("gain", 0.3, 0, 100, 0.01); 
velocity = hslider("velocity", 0.6, 0, 1, 0.01);

// ROUTING CONTROL: 0 = Main String, 1 = Chikari String, 2 = Heavy Mizrab Accent
strike = hslider("strike [style:knob]", 0, 0, 2, 1); 

jivari = hslider("jivari [style:knob]", 0.0, 0, 1, 0.001); 
symp_gain = hslider("symp_gain", 0.0, 0, 1, 0.01); 

// Chikari Base Slider (Default C#4 matching classical tuning)
chikari_freq = hslider("chikari_freq [unit:Hz]", 111.0, 55, 900, 0.01);

sustain_knob = hslider("sustain [unit:s]", 7.5, 0.5, 30.0, 0.1);
symp_drift_hz = hslider("symp_drift [unit:Hz]", 1.2, 0, 5, 0.01);

// --- Vibrato Controls ---
vibrato = hslider("vibrato [style:check]", 0, 0, 1, 1);
vibrato_depth = hslider("vibrato_depth", 0.01, 0, 0.5, 0.001);
vibrato_rate = hslider("vibrato_rate", 4.0, 1, 10, 0.1);

vibrato_signal = os.osc(vibrato_rate) * vibrato_depth * vibrato;
melody_freq = freq * (1.0 + vibrato_signal);

// --- Edge-Triggered Master Pluck ---
trig = gate > gate';

// FIXED MASTER EXCITATION: Replaced dual independent blocks with one single unified physical pluck engine.
// Both melody and chikari strings now share the exact same raw transient tracking window synchronously.
pluck_env = en.ar(0.004, 0.15, trig); 
pick_noise = no.noise; //WHITE-TEST
master_exc_signal = pick_noise * pluck_env * velocity;

is_melody  = strike == 0;
is_chikari = strike == 1;
is_mizrab  = strike == 2; 

// LATCHED CHIKARI TRIGGER: Fired immediately on edge trigger and latches for a short window,
// ensuring the string loop has time to receive the full pluck excitation even if the global gate goes off.
chikari_trig = (is_chikari > is_chikari') | (trig & is_chikari);
chikari_pluck_gate = chikari_trig : chikari_pt > 0
with {
    chikari_pt(t) = loop ~ _
    with { loop(s) = ba.if(t, 150, max(0.0, s - 1.0)); };
};
chikari_pluck_env = en.ar(0.001, 0.008, chikari_pluck_gate);
chikari_exc_signal = pick_noise * chikari_pluck_env * velocity;

// sitar_string defined in fm.lib (read-only)

// --- INSTANCE 1: Main Melody String ---
mizrab_scale = ba.if(is_mizrab, 1.4, 1.0);
exc_gain = hslider("exc_gain", 0.0125, 0.0, 2.0, 0.01);
melody_gain = ba.if(is_mizrab, 0.65, 0.40) * exc_gain;
// Pulls energy directly from the master excitation source
melody_output = sitar_string(melody_freq, sustain_knob, jivari * mizrab_scale, melody_gain, (is_melody + is_mizrab), master_exc_signal, cal);

// --- INSTANCE 2 & 3: Chikari Drone Strings ---
    chikari_freq1 = chikari_freq * 2.0; 
    chikari_freq2 = chikari_freq * 3.0;

// FIXED LOGIC: Chikari instances are now driven directly by the latched trigger excitation channel.
// Setting 'strike = 1' and clicking 'gate' will now cleanly fire and sustain the drone overtones naturally.
chikariLoop = ( sitar_string(chikari_freq1, 1.8, jivari * 0.7, 0.35, chikari_trig, chikari_exc_signal, 0)
              + sitar_string(chikari_freq2, 1.8, jivari * 0.7, 0.35, chikari_trig, chikari_exc_signal, 0)
              ) * 0.5;

played_strings = melody_output + chikariLoop;

// --- INSTANCE 4, 5 & 6: Sympathetic Taraf Strings ---
symp_trigger = pluck_env : si.smoo;

symp_string(multiplier, hz_offset) = sitar_string(t_freq, sustain_knob * 1.5, jivari * 0.45, 0.35, symp_trigger, played_strings, cal)
with {     t_freq = max((freq * multiplier) + (hz_offset * symp_drift_hz), 40.0); };

symp_strings_ks = ( symp_string(1.5,  0.6)  
                  + symp_string(2.0, -0.4)  
                  + symp_string(3.0,  0.5)  
                  ) * symp_gain;

// --- Gourd Resonator Acoustic Body Filter ---
// Modes from measured sitar modal analysis (OMA/EMA, SAGE 10775463211042196):
// - Helmholtz Air Resonance (Tumba gourd): ~110 Hz (primary gourd cavity)
// - Tabli lateral bending (EMA): 144 Hz
// - Main resonator bulging cluster (OMA): 283/294/316 Hz  -> boosts tonic 2nd harmonic
// - 3rd-harmonic bulging mode (OMA): 560 Hz
// - Upper bulging + coupling modes (OMA): 746, 833, 938/975 Hz
// The sitar body radiates almost entirely below ~1 kHz; brightness is carried by
// the string/jawari and pluck excitation, not by body modes.
body_filter(x) =
    (  (x * 0.30)                                 // dry passthrough
     + (x : fi.resonbp(110.0,  4.5, 1.00))       // Tumba gourd Helmholtz air resonance
     + (x : fi.resonbp(144.0,  4.5, 0.70))       // Tabli lateral bending mode (EMA 144 Hz)
     + (x : fi.resonbp(300.0,  4.5, 1.30))       // Main bulging cluster 283/294/316 Hz (OMA) — body voice
     + (x : fi.resonbp(430.0,  4.5, 0.85))       // Bridge mode — fills the 330–440 Hz fundamental gap
     + (x : fi.resonbp(560.0,  4.5, 0.38))       // 3rd-harmonic bulging mode (OMA 560 Hz)
     + (x : fi.resonbp(745.0,  4.5, 0.28))       // Upper resonator bulging (OMA 746 Hz)
     + (x : fi.resonbp(833.0,  4.5, 0.24))       // Coupling mode (OMA 833 Hz)
     + (x : fi.resonbp(940.0,  4.5, 0.20))       // Coupling mode cluster (OMA 938/975 Hz)
    );

all_strings_mix = played_strings + symp_strings_ks;
core = all_strings_mix : fi.dcblocker;

gourd_saturation(x) = x - (x * x * x * 0.06);

process = core : gourd_saturation : * (gain * 134.4375);

