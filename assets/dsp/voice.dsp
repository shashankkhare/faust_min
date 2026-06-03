declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Formant-based singing voice synthesizer utilizing glottal pulse excitation and a morphable vowel filter bank (aa, ee, ii, oo, uu).
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - gain
//   - gate
//   - vowel
//   - breathiness
//   - vibrato_rate
//   - vibrato_depth
//   - velocity
// =============================================================================
import("stdfaust.lib");

// ============================================================
// Singing Voice Synthesizer — LF Glottal + Formant Bank
// Vowel morphing: 0=aa, 1=ee, 2=ii, 3=oo, 4=uu
// ============================================================

freq     = hslider("freq [unit:Hz]",  220,  50,  2000, 0.1);
gain     = hslider("gain",            0.7,  0.0, 1.0,  0.01);
gate     = button("gate");
vowel    = hslider("vowel",           0.0,  0.0, 4.0,  0.01) : si.smoo;
breathiness = hslider("breathiness", 0.15, 0.0,  1.0,  0.01) : si.smoo;

vibratoRate  = hslider("vibrato_rate",  5.5, 0.0, 12.0, 0.1);
vibratoDepth = hslider("vibrato_depth", 0.012, 0.0, 0.08, 0.001);

// --- Attack envelope (80ms default — breath-onset phrasing) ---
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
attackTime = 0.08 + (1.0 - velocity) * 0.12;
env      = gate * gain : si.smooth(ba.tau2pole(attackTime));
release  = gate : si.smooth(ba.tau2pole(0.06));

// --- Vibrato LFO ---
vib = os.osc(vibratoRate) * vibratoDepth * env;

// --- Pitch jitter (micro-fluctuation for vocal naturalness ~7 cents random) ---
jitter = no.noise * 0.003 * env;

// --- Modulated pitch ---
fMod = freq * (1.0 + vib + jitter);

// --- LF Glottal Source (sawtooth as approximation of Liljencrants-Fant pulse) ---
glottal = os.sawtooth(fMod);

// --- Breathiness layer (band-limited noise centred at fundamental) ---
breath  = no.noise : fi.resonbp(fMod, 1.2, 1.0) * breathiness * env;

// --- Excitation mix ---
excitation = glottal * (1.0 - breathiness * 0.5) + breath;

// ============================================================
// 5-Formant Filter Bank — vowel-interpolated
// Vowel table: [aa, ee, ii, oo, uu] (male voice, Hz)
// F1: [800, 400, 300, 400, 300]
// F2: [1200,1800,2300, 800, 800]
// F3: [2500,2600,3000,2500,2300]
// F4: [3500,3600,3700,3300,3100]
// F5: [4500,4500,4600,4200,4000]
// ============================================================

// Linear interpolation helper between 5 vowel anchor points
// index: 0..4 float
lerp5(v0,v1,v2,v3,v4,t) = ba.if(t < 1.0,
        v0 + (v1-v0)*t,
        ba.if(t < 2.0,
            v1 + (v2-v1)*(t-1.0),
            ba.if(t < 3.0,
                v2 + (v3-v2)*(t-2.0),
                v3 + (v4-v3)*(t-3.0))));

f1 = lerp5(800.0,  400.0,  300.0,  400.0,  300.0,  vowel);
f2 = lerp5(1200.0, 1800.0, 2300.0, 800.0,  800.0,  vowel);
f3 = lerp5(2500.0, 2600.0, 3000.0, 2500.0, 2300.0, vowel);
f4 = lerp5(3500.0, 3600.0, 3700.0, 3300.0, 3100.0, vowel);
f5 = lerp5(4500.0, 4500.0, 4600.0, 4200.0, 4000.0, vowel);

// Formant amplitudes (vowel-specific brightness)
a1 = lerp5(1.00,  0.80, 0.70, 0.90, 0.85, vowel);
a2 = lerp5(0.85,  1.00, 0.95, 0.60, 0.55, vowel);
a3 = lerp5(0.55,  0.70, 0.80, 0.40, 0.35, vowel);
a4 = lerp5(0.30,  0.40, 0.50, 0.25, 0.20, vowel);
a5 = lerp5(0.15,  0.20, 0.25, 0.10, 0.10, vowel);

// BW (bandwidth) controls resonance sharpness per formant
bw1 = 80.0;
bw2 = 90.0;
bw3 = 120.0;
bw4 = 130.0;
bw5 = 160.0;

// Q = F/BW
q1 = f1 / bw1;
q2 = f2 / bw2;
q3 = f3 / bw3;
q4 = f4 / bw4;
q5 = f5 / bw5;

// --- Formant filter bank (parallel resonant bandpass) ---
fbank(x) = fi.resonbp(f1, q1, a1, x)
         + fi.resonbp(f2, q2, a2, x)
         + fi.resonbp(f3, q3, a3, x)
         + fi.resonbp(f4, q4, a4, x)
         + fi.resonbp(f5, q5, a5, x);

// --- Output ---
voiced = excitation : fbank * env * 0.4;

// Duplicate to stereo with slight chorus spread for warmth
chorus = voiced : de.fdelay(4096, 8.5 + os.osc(0.23)*3.0) * 0.35;

process = voiced + chorus, voiced - chorus * 0.5;
