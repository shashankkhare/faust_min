import("stdfaust.lib");

freq = hslider("freq [unit:Hz]", 146.83, 40, 1000, 0.01);
pluck = button("pluck");
jivari = hslider("jivari", 0.5, 0, 1, 0.01);
symp_gain = hslider("symp_gain", 0.3, 0, 1, 0.01);

// Standard Karplus-Strong string excitation
exc = (no.noise * en.ar(0.001, 0.05, pluck));
del = ma.SR / freq;

// Feedback loop with lowpass damping and parabolic jivari clipping
bridge(x) = x * (1.0 - jivari * x * x);
stringLoop = exc : + ~ (de.fdelay(4096, del) : fi.lowpass(1, 4000) : bridge : _ * 0.99);

process = stringLoop * 0.5;
