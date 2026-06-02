declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

// --- Dedicated Meditative Ride Cymbal ---

freq     = hslider("freq [unit:Hz]", 5500, 2000, 10000, 1);
gain     = hslider("gain", 0.5, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);

strike = hslider("strike", 0, 0, 3, 1); 
// 0 = Tip
// 1 = Bow
// 2 = Bell
// 3 = Full wash

gate = button("gate");

// =====================================================
// Trigger
// =====================================================

trig = (gate - gate') > 0;

// =====================================================
// Metallic Oscillator Bank
// =====================================================

sq_osc(f) = (os.osc(f) > 0.0) * 2.0 - 1.0;

// Frequency-scaled modal structure
osc1 = sq_osc(freq * 0.041);
osc2 = sq_osc(freq * 0.056);
osc3 = sq_osc(freq * 0.083);
osc4 = sq_osc(freq * 0.105);
osc5 = sq_osc(freq * 0.167);
osc6 = sq_osc(freq * 0.245);

mix = (osc1 + osc2 + osc3 + osc4 + osc5 + osc6) / 6.0;

// =====================================================
// Ping Envelope
// =====================================================

ping_env = loop_ping ~ _ with {
    g = exp(-1.0 / (0.041 * ma.SR));

    loop_ping(s) = max(s * g, trig);
};

// =====================================================
// Wash Envelope
// =====================================================

wash_env = loop_wash ~ _ with {
    g = exp(-1.0 / (0.104 * ma.SR));

    loop_wash(s) = max(s * g, trig * 0.4);
};

// =====================================================
// Metallic Components
// =====================================================

// Bright shimmer ping
ping_filtered =
    (mix : fi.resonbp(10000, 12, 1.0))
    * ping_env
    * 3.0;

// Strike-dependent wash filtering
wash_cutoff =
    ba.selectn(4, strike,
        4000, // Tip
        2000, // Bow
        5000, // Bell
        20    // Full wash
    ) : si.smoo;

wash_filtered =
    (mix : fi.highpass(2, wash_cutoff))
    * wash_env
    * 0.6;

metallic_mix = ping_filtered + wash_filtered;

// =====================================================
// Noise Sizzle
// =====================================================

// Fast transient burst
noise_env_fast = loop_fast ~ _ with {
    g = exp(-1.0 / (0.04 * ma.SR));

    // Smooth retrigger without discontinuity
    loop_fast(s) = max(s * g, trig * 2.5);
};

// Slow shimmer tail
noise_env_slow = loop_slow ~ _ with {
    g = exp(-1.0 / (0.45 * ma.SR));

    // Smooth retrigger without discontinuity
    loop_slow(s) = max(s * g, trig * 1.0);
};

// Additional smoothing prevents zipper/click artifacts
noise_env =
    (noise_env_fast + noise_env_slow)
    : si.smoo;

// IMPORTANT:
// Filter BEFORE envelope for DSP stability
noise_wash =
    (no.noise : fi.highpass(2, 6000))
    * noise_env
    * 2.0;

// =====================================================
// Strike-dependent balance
// =====================================================

strike_balance =
    ba.selectn(4, strike,
        0.2, // Tip
        0.6, // Bow
        0.1, // Bell
        0.4  // Full wash
    ) : si.smoo;

// =====================================================
// Final Mix
// =====================================================

final_mix =
    metallic_mix
    + noise_wash * strike_balance;

// Soft clipping
process =
    final_mix
    * gain
    * velocity
    * (1.0 + 0.1 * velocity)
    * (1.0 + 0.00000001 * freq)
    : ma.tanh;