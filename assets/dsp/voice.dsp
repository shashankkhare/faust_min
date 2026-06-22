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

// Expert Play Range: Human voice (Bass to Soprano) broadly spans E2 (82 Hz) to C6 (1046 Hz).
freq     = hslider("freq [unit:Hz]",  220.0, 82, 1046, 0.1);
gain     = hslider("gain",            0.7,  0.0, 1.0,  0.01);
gate     = button("gate");

breathiness = hslider("breathiness", 0.15, 0.0, 1.0,  0.01) : si.smoo;
chest       = hslider("chest",       0.5,  0.0, 1.0,  0.01) : si.smoo;
glottal     = hslider("glottal",     0.5,  0.0, 1.0,  0.01) : si.smoo;
nasal       = hslider("nasal",       0.0,  0.0, 1.0,  0.01) : si.smoo;

vibratoRate  = hslider("vibrato_rate",  5.5, 0.0, 12.0, 0.1);
vibratoDepth = hslider("vibrato_depth", 0.012, 0.0, 0.08, 0.001);
frication    = hslider("frication",   0.0, 0.0, 1.0, 0.01) : si.smoo;

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

f1_base = hslider("f1_freq", 800.0,  200.0, 5000.0, 1.0) : si.smoo;
f2_base = hslider("f2_freq", 1200.0, 200.0, 5000.0, 1.0) : si.smoo;
f3_base = hslider("f3_freq", 2500.0, 200.0, 5000.0, 1.0) : si.smoo;
f4_base = hslider("f4_freq", 3500.0, 200.0, 5000.0, 1.0) : si.smoo;
f5_base = hslider("f5_freq", 4500.0, 200.0, 5000.0, 1.0) : si.smoo;

// Formants stay fixed at their phonemic (vocal tract) positions independent of pitch.
// The PAF algorithm handles fc < f0 correctly — do NOT force formants above fMod
// or you get a chain-reaction octave-jump (violin/falsetto artifact at high pitches).
f1 = f1_base : si.smoo;
f2 = f2_base : si.smoo;
f3 = f3_base : si.smoo;
f4 = f4_base : si.smoo;
f5 = f5_base : si.smoo;

// Formant amplitudes (vowel-specific brightness)
a1_base = hslider("f1_amp", 1.0, 0.0, 1.0, 0.01) : si.smoo;
a2_base = hslider("f2_amp", 0.8, 0.0, 1.0, 0.01) : si.smoo;
a3_base = hslider("f3_amp", 0.6, 0.0, 1.0, 0.01) : si.smoo;
a4_base = hslider("f4_amp", 0.4, 0.0, 1.0, 0.01) : si.smoo;
a5_base = hslider("f5_amp", 0.2, 0.0, 1.0, 0.01) : si.smoo;

// Applied Vocal Traits (Chest, Glottal, Nasal)
f1_mod = f1 * (1.0 - (chest - 0.5) * 0.15); // Chest resonance lowers F1 slightly
a1 = a1_base * (0.5 + chest) * (1.0 - nasal * 0.4);    // Boost F1 for chest, dip for nasal
a2 = a2_base * (0.5 + chest * 0.5);                    // Slight boost to F2 for chest

a3 = a3_base * (glottal * 2.0);                        // High formants scale with glottal harshness
a4 = a4_base * (glottal * 2.0);
a5 = a5_base * (glottal * 2.0);

f_nasal = hslider("nasal_freq", 1500.0, 500.0, 3000.0, 1.0) : si.smoo;
bw_nasal = 150.0;
a_nasal = nasal * 0.6; // Nasal formant peak

// BW (bandwidth) per formant - Glottal narrows bandwidth slightly for more buzzy, sharper peaks
bw_mod = 1.0 - (glottal - 0.5) * 0.3;
bw1 = hslider("f1_bw", 80.0, 10.0, 500.0, 1.0) * bw_mod : si.smoo;
bw2 = hslider("f2_bw", 90.0, 10.0, 500.0, 1.0) * bw_mod : si.smoo;
bw3 = hslider("f3_bw", 120.0, 10.0, 500.0, 1.0) * bw_mod : si.smoo;
bw4 = hslider("f4_bw", 130.0, 10.0, 500.0, 1.0) * bw_mod : si.smoo;
bw5 = hslider("f5_bw", 160.0, 10.0, 500.0, 1.0) * bw_mod : si.smoo;

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

// --- Noise Excitation layer (Breath + Consonants) ---
// Pink noise has a natural -3dB/oct roll-off matching human breath airflow.
// We pass it through a parallel bank of formant resonators to shape it
// exactly like the vocal tract shapes the glottal pulse.
n_src = no.pink_noise * (breathiness + frication) * env;

// Convert PAF bandwidths to Q factors for the BPFs
q1 = f1_mod / max(1.0, bw1);
q2 = f2 / max(1.0, bw2);
q3 = f3 / max(1.0, bw3);
q4 = f4 / max(1.0, bw4);
q5 = f5 / max(1.0, bw5);
q_n= f_nasal / max(1.0, bw_nasal);

f_noise = n_src : fi.resonbp(f1_mod, q1, 1.0) * a1
        + n_src : fi.resonbp(f2, q2, 1.0) * a2
        + n_src : fi.resonbp(f3, q3, 1.0) * a3
        + n_src : fi.resonbp(f4, q4, 1.0) * a4
        + n_src : fi.resonbp(f5, q5, 1.0) * a5
        + n_src : fi.resonbp(f_nasal, q_n, 1.0) * a_nasal;

// --- Output Mix ---
// If frication is high (consonant), we duck the voiced component
voice_mix = 1.0 - (frication * 0.8) - (breathiness * 0.5);
voiced = (formants * voice_mix + f_noise) * env * 0.25;

// Duplicate to stereo with slight chorus spread for warmth
chorus = voiced : de.fdelay(4096, 8.5 + os.osc(0.23)*3.0) * 0.35;

process = voiced + chorus, voiced - chorus * 0.5;
