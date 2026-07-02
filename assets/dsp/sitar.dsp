declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// --- Control Interfaces ---
freq = hslider("freq [unit:Hz]", 138.6, 130, 900, 0.01); 
gate = button("gate");
gain = hslider("gain", 0.3, 0, 1, 0.01);
velocity = hslider("velocity", 0.6, 0, 1, 0.01);

// ROUTING CONTROL: 0 = Main String, 1 = Chikari String, 2 = Heavy Mizrab Accent
strike = hslider("strike [style:knob]", 0, 0, 2, 1); 

jivari = hslider("jivari [style:knob]", 0.30, 0, 1, 0.001); 
symp_gain = hslider("symp_gain", 0.5, 0, 1, 0.01); 

// Chikari Base Slider (Default C#4 matching classical tuning)
chikari_base = hslider("chikari_base [unit:Hz]", 277.2, 130, 900, 0.01);

sustain_knob = hslider("sustain [unit:s]", 5.0, 0.5, 12.0, 0.1);
symp_drift_hz = hslider("symp_drift [unit:Hz]", 1.2, 0, 5, 0.01);

// --- Edge-Triggered Plucks ---
trig = gate > gate';

// STRIKE LOGIC FLAGS
is_melody  = strike == 0;
is_chikari = strike == 1;
is_mizrab  = strike == 2; 

pluck_env = en.ar(0.001, 0.008, trig); 
pick_noise = no.noise : fi.lowpass(2, 6000.0) : fi.highpass(2, 60.0);

melody_exc = pick_noise * pluck_env * velocity * ba.if(is_mizrab, 0.65, 0.40) * (is_melody + is_mizrab);

chikari_trig = is_chikari > is_chikari';
chikari_pluck_env = en.ar(0.001, 0.008, chikari_trig);
chikari_exc = (no.noise : fi.lowpass(2, 600.0)) * chikari_pluck_env * velocity * 0.35;

// --- Main Melody String ---
del = ma.SR / freq;
int_del = int(del);
frac_del = del - int_del;

effective_sustain = max(0.4, sustain_knob * (1.0 - jivari * 0.35));
feedback_gain = pow(0.001, del / (effective_sustain * ma.SR));
wire_loss_filter(x) = x * 0.002 + x' * 0.998; 

raw_string = melody_exc : (+ : de.delay(16384, int_del)) ~ loop_processor
with {
    loop_processor(x) = x : de.fdelay1a(1024, frac_del) : wire_loss_filter : * (feedback_gain);
};

// --- EXTERNAL AUDIO-RATE JIVARI ENGINE ---
string_envelope(x) = abs(x) : fi.lowpass(1, 10.0);
compressed_env(wire) = sqrt(string_envelope(wire)); 

mod_depth = (300.0 / freq) * jivari * ba.if(is_mizrab, 1.3, 1.0) * 3.5 * (compressed_env(raw_string) * 2.0);
external_modulator = os.osc(freq) * mod_depth;

melodyLoop(wire) = de.fdelayltv(1, 1024, max(1.0, 4.0 + external_modulator), wire);
melody_output = raw_string : melodyLoop;

// --- Chikari Drone Strings (VERIFIED 2x / 3x Layout) ---
chikari_freq1 = chikari_base * 2.0; 
chikari_freq2 = chikari_base * 3.0;

chikari_del1 = ma.SR / chikari_freq1;
chikari_del2 = ma.SR / chikari_freq2;

chikari_fb1 = pow(0.001, chikari_del1 / (1.6 * ma.SR));
chikari_fb2 = pow(0.001, chikari_del2 / (1.6 * ma.SR));

chikari_string(d, fb) = chikari_exc : (+ : de.delay(16384, id)) ~ (de.fdelay1a(1024, fd) : wire_loss_filter : * (fb))
with {
    id = int(d);
    fd = d - id;
};

// FIXED: Volume safely divided by 2.0 (* 0.5) to keep the strings balanced and clip-free
chikariLoop = (chikari_string(chikari_del1, chikari_fb1) + chikari_string(chikari_del2, chikari_fb2)) * 0.5;

played_strings = melody_output + chikariLoop;

// --- EXPLICIT 3-STRING SYMPATHETIC TARAF CHANNELS ---
symp_fb = 0.9984; 
symp_exc = played_strings * 0.35; 

symp_string(multiplier, hz_offset) = symp_exc : (+ : de.delay(16384, s_int)) ~ (de.fdelay1a(1024, s_frac) : wire_loss_filter : * (symp_fb))
with {
    t_freq = max((freq * multiplier) + (hz_offset * symp_drift_hz), 40.0);
    s_total = ma.SR / t_freq;
    s_int = int(s_total);
    s_frac = s_total - s_int;
};

symp_strings_ks = ( symp_string(1.5,  0.6)  
                  + symp_string(2.0, -0.4)  
                  + symp_string(3.0,  0.5)  
                  ) * symp_gain;

// --- Gourd Resonator Acoustic Body Filter ---
body_filter(x) =
    (  (x * 0.25) 
     + (x : fi.resonbp(250.0,  5.0, 0.4)) 
     + (x : fi.resonbp(450.0,  4.0, 0.5)) 
     + (x : fi.resonbp(900.0,  3.5, 0.8))  
     + (x : fi.resonbp(1400.0, 3.0, 0.7)) 
     + (x : fi.resonbp(2200.0, 2.5, 0.7)) 
     + (x : fi.resonbp(3600.0, 2.0, 0.4)) 
    );

all_strings_mix = played_strings + symp_strings_ks;
core = all_strings_mix : fi.dcblocker : body_filter;

gourd_saturation(x) = x - (x * x * x * 0.06);

process = core : gourd_saturation : * (gain * 7.5);

