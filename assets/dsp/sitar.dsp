declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
// Reference: http://issta.ie/wp-content/uploads/The-Physical-Modelling-of-a-Sitar.pdf
import("stdfaust.lib");

freq = hslider("freq [unit:Hz]", 222.0, 40, 1000, 0.01);
gate = button("gate");
gain = hslider("gain", 0.3, 0, 1, 0.01);
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
strike = hslider("strike", 0, 0, 2, 1);
jivari = hslider("jivari", 0.1, 0, 0.5, 0.001);
symp_gain = hslider("symp_gain", 0.15, 0, 1, 0.01);
chikari_freq = hslider("chikari_freq [unit:Hz]", 440.0, 40, 2000, 0.01);

trig = (gate - gate') > 0;
is_chikari = strike > 0.5;
sustain = 8.0;
feedback_gain = pow(0.001, 1.0 / (sustain * ma.SR));
pluck_amp = 0.2;

timer(maxf, t) = loop~_ with { loop(s) = ba.if(t, maxf, max(0.0, s - 1.0)); };

gate_held_pluck = trig : timer(150) > 0;
pluck_env = en.ar(0.003, 0.015, gate_held_pluck);

pick_noise = no.noise : fi.bandpass(2, 200.0, 1200.0);
melody_exc = pick_noise * 1.0 * pluck_env * velocity * pluck_amp * (1 - is_chikari);

chikari_trig = is_chikari > is_chikari';
chikari_gate = chikari_trig : timer(150) > 0;
chikari_pluck_env = en.ar(0.003, 0.015, chikari_gate);
chikari_exc = (no.noise : fi.bandpass(2, 300.0, 800.0)) * 0.2 * chikari_pluck_env * velocity * 0.25;

del = ma.SR / freq;

dcblock(x) = x - x' + 0.999 * x'';
bridge_contact(x) = max(0, x * 5.0);
jivari_mod = jivari * 600.0;
dynamic_delay(x) = de.fdelay(16384, max(2.0, del - jivari_mod * bridge_contact(x)), x);

melodyLoop = melody_exc : (+ : dynamic_delay) ~ (_ * feedback_gain);

chikari_del = ma.SR / chikari_freq;
chikari_pa_del = ma.SR / (chikari_freq * 1.5);
chikari_fb = pow(0.001, 1.0 / (2.5 * chikari_freq));
chikari_pa_fb = pow(0.001, 1.0 / (2.5 * chikari_freq * 1.5));
chikari_string(d, fb) = chikari_exc : (+ : de.fdelay(16384, d - 1.0)) ~ (*(0.95) : +~*(0.05) : _ * fb);
chikariLoop = chikari_string(chikari_del, chikari_fb) + chikari_string(chikari_del, chikari_fb)
            + chikari_string(chikari_pa_del, chikari_pa_fb) + chikari_string(chikari_pa_del, chikari_pa_fb);

body_filter(x) =
    (  (x * 0.6)
     + (x : fi.resonbp(150.0,  3.0, 1.0))
     + (x : fi.resonbp(250.0,  3.0, 0.5))
     + (x : fi.resonbp(350.0,  3.0, 0.8))
     + (x : fi.resonbp(550.0,  3.0, 0.5))
     + (x : fi.resonbp(750.0,  3.0, 0.6))
     + (x : fi.resonbp(1100.0, 3.0, 0.8))
     + (x : fi.resonbp(1600.0, 3.0, 0.6))
     + (x : fi.resonbp(2200.0, 3.0, 0.8))
     + (x : fi.resonbp(3500.0, 3.0, 0.5))
     + (x : fi.resonbp(5000.0, 2.0, 0.3))
    );

// Sympathetic strings (Taraf) — 3 body-driven KS delay lines
// Excited by body resonance, gated so they only receive energy during note-on.
// Feedback keeps them ringing naturally after gate→0.
// Ratios: 1:1 (unison), 3:2 (fifth), 2:1 (octave)
symp_fb = 0.997;
symp_del1 = ma.SR / max(freq, 40.0);
symp_del2 = ma.SR / max(freq * 1.5, 40.0);
symp_del3 = ma.SR / max(freq * 2.0, 40.0);

summed = (melodyLoop + chikariLoop) * gate;
core = summed : dcblock : body_filter;

symp_exc = core * gate;
symp_ks1 = symp_exc : (+ : de.fdelay(16384, symp_del1 - 1.0)) ~ _ * symp_fb;
symp_ks2 = symp_exc : (+ : de.fdelay(16384, symp_del2 - 1.0)) ~ _ * symp_fb;
symp_ks3 = symp_exc : (+ : de.fdelay(16384, symp_del3 - 1.0)) ~ _ * symp_fb;
symp_strings_ks = (symp_ks1 + symp_ks2 + symp_ks3) / 3;

process = (core + symp_strings_ks * symp_gain) * gain * 23.0;
