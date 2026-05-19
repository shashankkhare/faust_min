import("stdfaust.lib");

// =====================================================
// Realistic Tibetan Singing Bowl
// =====================================================

freq = hslider("freq [unit:Hz]", 110, 60, 400, 0.1);

gain = hslider("gain", 0.6, 0, 1, 0.01);

// Strike
gate = button("gate");

// Rim rubbing sustain
rub = hslider("rub_intensity", 0.0, 0, 1, 0.01);

// =====================================================
// Trigger
// =====================================================

trig = (gate - gate') > 0;

// =====================================================
// Soft Excitation Impulse
// =====================================================

exc_env = exc ~ _ with {
    g = exp(-1.0 / (0.008 * ma.SR));

    exc(s) = min(1.0, s * g + trig);
};

// Soft mallet excitation
excitation =
    no.noise
    * exc_env
    * 0.25;

// =====================================================
// Bowl Resonant Modes
// =====================================================

// Real bowls are dominated by resonances,
// not direct oscillators.

mode(f, q, amp) =
    excitation
    : fi.resonbp(f, q, 1.0)
    * amp;

// Fundamental
m1 = mode(freq * 1.00, 40, 1.0);

// Inharmonic bowl modes
m2 = mode(freq * 2.32, 55, 0.45);

m3 = mode(freq * 3.95, 70, 0.22);

m4 = mode(freq * 5.43, 90, 0.10);

// Gentle low resonance/body
body =
    excitation
    : fi.lowpass(2, freq * 1.2)
    * 0.15;

// =====================================================
// Friction Singing
// =====================================================

// Soft filtered friction
friction =
    no.noise
    : fi.bandpass(2, freq * 1.8, 2.0)
    * rub;

// Feed friction into bowl resonance
rubbed =
    friction
    : fi.resonbp(freq, 60, 1.0)
    * 0.25;

// =====================================================
// Air
// =====================================================

air =
    (no.noise : fi.highpass(1, 8000))
    * exc_env
    * 0.002;

// =====================================================
// Final Bowl
// =====================================================

bowl =
    m1 + m2 + m3 + m4
    + body
    + rubbed
    + air;

// Gentle output limiting only
process =
    bowl
    * gain
    : *(0.8);