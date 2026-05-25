import("stdfaust.lib");

// --- Saxophone: sawtooth + resonant body + pitch dip + vibrato ---
freq = hslider("freq [unit:Hz]", 440, 50, 2000, 0.1);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

vibratoRate = hslider("vibrato_rate", 5.0, 0, 10, 0.1);
vibratoDepth = hslider("vibrato_depth", 0.015, 0, 0.1, 0.001);

breath = gate * gain : si.smooth(0.995);
vib = os.osc(vibratoRate) * vibratoDepth * breath;

// --- Attack pitch dip (~40 cents, recovers over 60ms) ---
rawTrig = (gate - gate') > 0.0;
dipLen = 0.06 * ma.SR;
dipTimer = rawTrig : dipEnv with {
    dipEnv(t) = loop ~ _ with {
        loop(cnt) = ba.if(t > 0.0, dipLen, max(0.0, cnt - 1.0));
    };
};
dipAmt = dipTimer / dipLen;
sweep = dipAmt * 0.025;

// --- Oscillator with vibrato + pitch dip ---
osc = os.sawtooth(freq * (1.0 + vib - sweep));

// --- ADSR envelope (slower attack for reed) ---
sax_env = en.adsr(0.05, 0.1, 0.8, 0.2, gate);

// --- Resonant lowpass — warmth + reediness ---
filter_cutoff = freq * 2.0 + breath * 800 + sax_env * 400;

process = osc : fi.resonlp(filter_cutoff, 3.0, 1.0) * sax_env * gain * 1.2;
