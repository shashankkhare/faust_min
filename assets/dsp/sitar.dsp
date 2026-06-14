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

symp_trig = trig + chikari_trig;
symp_max_frames = int(3.0 * ma.SR);
symp_timer_raw = symp_trig : timer(symp_max_frames);
symp_elapsed = (symp_max_frames - symp_timer_raw) / ma.SR;
symp_env(mu, sigma, lam) = lam * (1.0 - exp(-4.0 * symp_elapsed / max(mu, 0.001))) * exp(-sigma * max(0.0, symp_elapsed - mu));
symp_base = ba.if(is_chikari, chikari_freq, freq);
symp_string(ratio, detune, mu, sigma, lam) = os.osc(symp_base * ratio * detune) * symp_env(mu, sigma, lam);
symp_strings = symp_string(1.500, 1.000, 0.15, 1.2, 0.08)
             + symp_string(1.500, 0.998, 0.15, 1.2, 0.08)
             + symp_string(2.000, 1.000, 0.10, 1.8, 0.10)
             + symp_string(2.000, 0.998, 0.10, 1.8, 0.10)
             + symp_string(3.000, 1.000, 0.20, 1.0, 0.06)
             + symp_string(3.000, 0.998, 0.20, 1.0, 0.06)
             + symp_string(4.000, 1.000, 0.12, 0.8, 0.05)
             + symp_string(4.000, 0.998, 0.12, 0.8, 0.05);

summed = (melodyLoop + chikariLoop + symp_strings * symp_gain) : dcblock : body_filter;
process = (summed) * gain * 23.0;
