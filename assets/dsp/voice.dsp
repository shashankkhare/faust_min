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
vowel       = hslider("vowel",       0.0,  0.0, 4.0,  0.01) : si.smoo;
breathiness = hslider("breathiness", 0.15, 0.0, 1.0,  0.01) : si.smoo;
chest       = hslider("chest",       0.5,  0.0, 1.0,  0.01) : si.smoo;
glottal     = hslider("glottal",     0.5,  0.0, 1.0,  0.01) : si.smoo;
nasal       = hslider("nasal",       0.0,  0.0, 1.0,  0.01) : si.smoo;

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

// ============================================================
// 5-Formant PAF Generator — Vowel-interpolated
// Vowel table: [aa, ee, ii, oo, uu] (male voice, Hz)
// ============================================================

// Linear interpolation helper between 5 vowel anchor points
lerp5(v0,v1,v2,v3,v4,t) = ba.if(t < 1.0,
        v0 + (v1-v0)*t,
        ba.if(t < 2.0,
            v1 + (v2-v1)*(t-1.0),
            ba.if(t < 3.0,
                v2 + (v3-v2)*(t-2.0),
                v3 + (v4-v3)*(t-3.0))));

f1_base = lerp5(800.0,  400.0,  300.0,  400.0,  300.0,  vowel);
f2_base = lerp5(1200.0, 1800.0, 2300.0, 800.0,  800.0,  vowel);
f3_base = lerp5(2500.0, 2600.0, 3000.0, 2500.0, 2300.0, vowel);
f4_base = lerp5(3500.0, 3600.0, 3700.0, 3300.0, 3100.0, vowel);
f5_base = lerp5(4500.0, 4500.0, 4600.0, 4200.0, 4000.0, vowel);

// Formant Tracking (forces formants above the fundamental)
f1 = max(f1_base, fMod) : si.smoo;
f2 = max(f2_base, f1 + 200.0) : si.smoo;
f3 = max(f3_base, f2 + 200.0) : si.smoo;
f4 = max(f4_base, f3 + 200.0) : si.smoo;
f5 = max(f5_base, f4 + 200.0) : si.smoo;

// Formant amplitudes (vowel-specific brightness)
a1_base = lerp5(1.00,  0.80, 0.70, 0.90, 0.85, vowel);
a2_base = lerp5(0.85,  1.00, 0.95, 0.60, 0.55, vowel);
a3_base = lerp5(0.55,  0.70, 0.80, 0.40, 0.35, vowel);
a4_base = lerp5(0.30,  0.40, 0.50, 0.25, 0.20, vowel);
a5_base = lerp5(0.15,  0.20, 0.25, 0.10, 0.10, vowel);

// Applied Vocal Traits (Chest, Glottal, Nasal)
f1_mod = max(fMod, f1 * (1.0 - (chest - 0.5) * 0.15)); // Deeper F1 for chest
a1 = a1_base * (0.5 + chest) * (1.0 - nasal * 0.4);    // Boost F1 for chest, dip for nasal
a2 = a2_base * (0.5 + chest * 0.5);                    // Slight boost to F2 for chest

a3 = a3_base * (glottal * 2.0);                        // High formants scale with glottal harshness
a4 = a4_base * (glottal * 2.0);
a5 = a5_base * (glottal * 2.0);

f_nasal = 1500.0;
bw_nasal = 150.0;
a_nasal = nasal * 0.6; // Nasal formant peak

// BW (bandwidth) per formant - Glottal narrows bandwidth slightly for more buzzy, sharper peaks
bw_mod = 1.0 - (glottal - 0.5) * 0.3;
bw1 = 80.0;
bw2 = 90.0;
bw3 = 120.0 * bw_mod;
bw4 = 130.0 * bw_mod;
bw5 = 160.0 * bw_mod;

// --- Phase-Aligned Formant (PAF) Core ---
// Master phase locked to fundamental pitch
phi = os.phasor(1.0, fMod);

paf(f0, fc, bw) = pulse * carrier * norm
with {
    c = fc / max(1.0, f0);
    k = floor(c);
    d = c - k;
    
    // Twin-cosine crossfaded carrier
    phase_k  = 2.0 * ma.PI * k * phi;
    phase_k1 = 2.0 * ma.PI * (k + 1.0) * phi;
    carrier  = (1.0 - d) * cos(phase_k) + d * cos(phase_k1);
    
    // Modulator pulse width (proportional to bandwidth)
    bw_ratio = bw / max(1.0, f0);
    M = bw_ratio * bw_ratio * 0.5;
    pulse_arg = max(-80.0, M * (cos(2.0 * ma.PI * phi) - 1.0));
    pulse = exp(pulse_arg);
    
    norm = sqrt(M + 1.0);
};

// --- Generate 5 Formants + Nasal ---
formants = paf(fMod, f1_mod, bw1) * a1
         + paf(fMod, f2, bw2) * a2
         + paf(fMod, f3, bw3) * a3
         + paf(fMod, f4, bw4) * a4
         + paf(fMod, f5, bw5) * a5
         + paf(fMod, f_nasal, bw_nasal) * a_nasal;

// --- Breathiness layer ---
// We add high-passed noise shaped by the formants for realism
breath_noise = no.noise : fi.resonbp(fMod, 1.2, 1.0) * breathiness * env;

// --- Output ---
voiced = (formants * (1.0 - breathiness * 0.5) + breath_noise) * env * 0.25;

// Duplicate to stereo with slight chorus spread for warmth
chorus = voiced : de.fdelay(4096, 8.5 + os.osc(0.23)*3.0) * 0.35;

process = voiced + chorus, voiced - chorus * 0.5;
