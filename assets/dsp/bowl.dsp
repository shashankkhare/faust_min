import("stdfaust.lib");

freq = hslider("freq [unit:Hz]", 220, 100, 1000, 0.01);
strike = button("strike");
rub = hslider("rub", 0, 0, 1, 0.01);

// Strike excitation plus continuous rub friction noise
exc = (strike : ba.impulsify) + (no.noise * rub * 0.01);

// Parallel bandpass filter bank modeling singing bowl doublets
mode(r, t, g) = fi.resonbp(freq * r, 50.0, g);

bowl = exc <: (
    mode(1.0, 6.0, 1.0) + mode(1.002, 5.8, 1.0) +
    mode(2.78, 4.0, 0.6) + mode(2.785, 3.8, 0.6) +
    mode(5.21, 2.5, 0.4) + mode(5.215, 2.3, 0.4)
) : _ * 0.5;

process = bowl;
