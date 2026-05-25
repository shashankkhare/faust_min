import("stdfaust.lib");

// --- Bayan (Tabla Bass Drum) - Full Bol Model ---
// strike 0: Ka  — Closed/muted, short thud, no glide
// strike 1: Ghe — Open bass, long ring, pitch glide (meend) upward
// strike 2: Ghi — Half-open, medium ring, slight glide
// strike 3: Ke  — Closed edge hit, sharp attack, no glide

baseFreq = hslider("freq",     110.0, 40, 400, 0.1);
gain     = hslider("gain",     0.9,   0,  1,   0.01);
velocity = hslider("velocity", 1.0,   0,  1,   0.01);
gate     = button("gate");
strike   = hslider("strike",   1,     0,  3,   1);
meend    = hslider("meend",    1.0,   0.5, 4.0, 0.01);

// =====================================================
// Meend (Pitch Glide) — Only active for Ghe (1) and Ghi (2)
// Ka (0) and Ke (3) are closed/muted — no pitch glide
// =====================================================
meendActive = (strike > 0.5) * (strike < 2.5);
meendTarget = ba.if(meendActive, meend, 1.0);
smoothedMeend = meendTarget : si.smoo;
smoothedFreq = baseFreq * smoothedMeend;

// =====================================================
// Decay Scale per Bol
// Ka/Ke: very short (closed mute), Ghe: long, Ghi: medium
// =====================================================
t60Scale = ba.selectn(4, strike,
    0.03,   // 0: Ka  — sharp closed thud
    0.55,   // 1: Ghe — long open ring
    0.25,   // 2: Ghi — medium half-open ring
    0.03    // 3: Ke  — short edge thud
);

// =====================================================
// Per-Bol Spectral Gains (4 resonator modes)
// Ka/Ke: dominant fundamental only, dead upper modes
// Ghe:   rich fundamental, moderate harmonics
// Ghi:   moderate fundamental, brighter harmonics
// =====================================================
bg1_base = ba.selectn(4, strike, 1.5, 1.5, 1.2, 1.5);  // Fundamental
bg2_base = ba.selectn(4, strike, 0.3, 0.8, 0.9, 0.3);  // 2nd partial
bg3_base = ba.selectn(4, strike, 0.1, 0.5, 0.7, 0.1);  // 3rd partial
bg4_base = ba.selectn(4, strike, 0.0, 0.3, 0.5, 0.0);  // 4th partial

// Velocity-dependent brightness morphing
bright = velocity * 0.5;
bg1 = bg1_base * (1.0 - bright * 0.1);
bg2 = bg2_base * (1.0 + bright * 0.2);
bg3 = bg3_base * (1.0 + bright * 0.5);
bg4 = bg4_base * (1.0 + bright * 0.8);

// =====================================================
// Dynamic Drive — Ghe is heavier, Ka/Ke lighter
// =====================================================
dynamicDrive = ba.selectn(4, strike, 0.9, 1.1, 1.0, 0.9);

// =====================================================
// Manual 2-Pole Resonator (unchanged core)
// =====================================================
myResonator(f, t, g, x) = x * 0.002 : + ~ (conv) : *(g)
with {
    T60   = t * t60Scale;
    r     = pow(0.001, 1.0 / (max(0.001, T60) * ma.SR));
    omega = 2.0 * ma.PI * f / ma.SR;
    b1    = 2.0 * r * cos(omega);
    b2    = r * r;
    conv(y) = b1 * y - b2 * y';
};

// =====================================================
// Exciter
// =====================================================
exciter = gate : ba.impulsify * velocity;

// =====================================================
// 4-Mode Modal Sum (was 3, now 4 to match dayan depth)
// =====================================================
bayan = myResonator(smoothedFreq * 1.00, 1.8, bg1, exciter) +
        myResonator(smoothedFreq * 2.10, 1.2, bg2, exciter) +
        myResonator(smoothedFreq * 3.20, 0.8, bg3, exciter) +
        myResonator(smoothedFreq * 4.50, 0.5, bg4, exciter);

// =====================================================
// Output — tanh saturation for natural head compression
// =====================================================
process = (bayan * dynamicDrive * 20.0 : ma.tanh) * gain;
