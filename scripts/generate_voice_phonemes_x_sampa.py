import csv

# =========================================================
# X-SAMPA Phoneme Database — Acoustically Correct Formants
# Sources: Peterson & Barney (1952), Hillenbrand et al. (1995)
# Bladon & Fant (1978) — Male voice average values
# =========================================================
#
# Each phoneme: [f1, f2, f3, f4, f5, a1, a2, a3, a4, a5, chest, glottal, nasal, frication]
# Formant freqs in Hz, amps 0-1, chest/glottal/nasal/frication 0-1

phonemes = {

    # ---- VOWELS ----
    'i':   [270,  2290, 3010, 3700, 4500,  0.6,  1.0,  0.7,  0.4,  0.2,  0.4, 0.7, 0.0, 0.0],  # ee (see)
    'I':   [390,  1990, 2550, 3700, 4500,  0.7,  0.9,  0.6,  0.35, 0.18, 0.5, 0.6, 0.0, 0.0],  # I  (bit)
    'e':   [400,  2000, 2550, 3600, 4500,  0.75, 0.95, 0.65, 0.38, 0.19, 0.5, 0.6, 0.0, 0.0],  # e  (French é)
    'E':   [530,  1840, 2480, 3600, 4500,  0.85, 0.9,  0.6,  0.35, 0.18, 0.5, 0.5, 0.0, 0.0],  # E  (bed)
    '{':   [660,  1720, 2410, 3500, 4400,  0.9,  0.85, 0.55, 0.3,  0.15, 0.5, 0.5, 0.0, 0.0],  # ae (cat)
    '@':   [500,  1500, 2500, 3500, 4500,  0.8,  0.7,  0.5,  0.3,  0.15, 0.5, 0.5, 0.0, 0.0],  # @  (schwa, Abbott)
    'a':   [800,  1200, 2500, 3500, 4500,  1.0,  0.8,  0.55, 0.3,  0.15, 0.5, 0.5, 0.0, 0.0],  # a  (short open central)
    'A':   [800,  1100, 2400, 3400, 4400,  1.0,  0.85, 0.55, 0.3,  0.15, 0.5, 0.5, 0.0, 0.0],  # A  (father)
    'O':   [570,  840,  2410, 3300, 4200,  0.9,  0.6,  0.4,  0.25, 0.1,  0.5, 0.5, 0.0, 0.0],  # O  (law)
    'U':   [440,  1020, 2240, 3100, 4000,  0.85, 0.55, 0.35, 0.2,  0.1,  0.5, 0.5, 0.0, 0.0],  # U  (book)
    'u':   [300,  870,  2240, 3100, 4000,  0.75, 0.5,  0.3,  0.18, 0.09, 0.4, 0.6, 0.0, 0.0],  # u  (soon)

    # ---- NASALS ----
    'm':   [250,  900,  2200, 3200, 4200,  0.9,  0.25, 0.1,  0.05, 0.05, 0.3, 0.5, 0.9, 0.0],  # m (bilabial nasal)
    'n':   [250,  1100, 2500, 3500, 4500,  0.9,  0.3,  0.15, 0.05, 0.05, 0.3, 0.5, 0.9, 0.0],  # n (alveolar nasal)
    'N':   [250,  800,  2300, 3300, 4300,  0.9,  0.2,  0.1,  0.05, 0.05, 0.3, 0.5, 0.95,0.0], # N (velar nasal, "ng")

    # ---- APPROXIMANTS / LIQUIDS ----
    'r':   [400,  1050, 1550, 3400, 4300,  0.8,  0.6,  0.4,  0.2,  0.1,  0.4, 0.5, 0.0, 0.0],  # r (very low F3 = key)
    'l':   [360,  1100, 2800, 3400, 4300,  0.8,  0.6,  0.5,  0.2,  0.1,  0.4, 0.5, 0.0, 0.0],  # l (lateral)
    'j':   [300,  2200, 2900, 3600, 4500,  0.6,  0.9,  0.7,  0.35, 0.18, 0.4, 0.6, 0.0, 0.0],  # j (palatal approx, "y")
    'w':   [300,  700,  2200, 3100, 4000,  0.7,  0.5,  0.3,  0.15, 0.08, 0.4, 0.5, 0.0, 0.0],  # w (labial-velar approx)

    # ---- VOICED PLOSIVES (burst — brief, low voiced energy) ----
    'b':   [250,  700,  2200, 3200, 4200,  0.2,  0.15, 0.1,  0.05, 0.05, 0.3, 0.4, 0.0, 0.1],  # b
    'd':   [250,  1700, 2600, 3500, 4500,  0.2,  0.3,  0.2,  0.1,  0.05, 0.3, 0.4, 0.0, 0.1],  # d
    'g':   [250,  2000, 2800, 3500, 4500,  0.3,  0.4,  0.2,  0.1,  0.05, 0.3, 0.4, 0.0, 0.1],  # g

    # ---- UNVOICED PLOSIVES (silent closure — near zero energy) ----
    'p':   [200,  800,  2000, 3000, 4000,  0.05, 0.05, 0.05, 0.05, 0.05, 0.2, 0.1, 0.0, 0.8],  # p
    't':   [200,  1400, 2400, 3400, 4400,  0.05, 0.05, 0.05, 0.05, 0.05, 0.2, 0.1, 0.0, 0.8],  # t
    'k':   [200,  2000, 2800, 3800, 4800,  0.05, 0.05, 0.05, 0.05, 0.05, 0.2, 0.1, 0.0, 0.8],  # k

    # ---- FRICATIVES ----
    's':   [3000, 4000, 5000, 6000, 7000,  0.0,  0.0,  0.4,  0.7,  1.0,  0.1, 0.1, 0.0, 1.0],  # s (alveolar)
    'S':   [2000, 3000, 4000, 5000, 6000,  0.0,  0.1,  0.6,  0.9,  0.8,  0.1, 0.1, 0.0, 1.0],  # S (postalveolar, "sh")
    'z':   [2800, 3800, 4800, 5800, 6800,  0.05, 0.05, 0.35, 0.65, 0.9,  0.1, 0.2, 0.0, 0.8],  # z (voiced "s")
    'v':   [300,  1100, 2200, 3200, 4200,  0.1,  0.15, 0.1,  0.08, 0.05, 0.2, 0.3, 0.0, 0.6],  # v
    'f':   [3000, 4000, 5000, 6000, 7000,  0.0,  0.0,  0.3,  0.6,  0.9,  0.1, 0.1, 0.0, 0.9],  # f
    'h':   [400,  1200, 2400, 3400, 4400,  0.15, 0.15, 0.15, 0.1,  0.1,  0.2, 0.2, 0.0, 0.9],  # h (glottal)

    # ---- ASPIRATED (Indian languages — voiced with breathy onset) ----
    'd_h': [250,  1700, 2600, 3500, 4500,  0.35, 0.3,  0.2,  0.1,  0.05, 0.3, 0.6, 0.0, 0.6],  # dh (ध)
    'b_h': [250,  700,  2200, 3200, 4200,  0.3,  0.2,  0.15, 0.08, 0.05, 0.3, 0.6, 0.0, 0.6],  # bh (भ)
    'g_h': [250,  2000, 2800, 3500, 4500,  0.35, 0.4,  0.25, 0.12, 0.05, 0.3, 0.6, 0.0, 0.6],  # gh (घ)
    'p_h': [200,  800,  2000, 3000, 4000,  0.15, 0.1,  0.1,  0.05, 0.05, 0.2, 0.4, 0.0, 0.9],  # ph (फ)
    'k_h': [200,  2000, 2800, 3800, 4800,  0.15, 0.1,  0.1,  0.05, 0.05, 0.2, 0.4, 0.0, 0.9],  # kh (ख)
    't_h': [200,  1400, 2400, 3400, 4400,  0.1,  0.08, 0.08, 0.05, 0.05, 0.2, 0.4, 0.0, 0.9],  # th (थ)

    # ---- RETROFLEX (Indian languages — tongue curled back) ----
    'd\\': [250,  1500, 2300, 3400, 4400,  0.2,  0.3,  0.2,  0.1,  0.05, 0.3, 0.4, 0.0, 0.1],  # d\ (ड)
    't\\': [200,  1500, 2300, 3300, 4300,  0.05, 0.05, 0.05, 0.05, 0.05, 0.2, 0.1, 0.0, 0.8],  # t\ (ट)
    'n\\': [250,  1000, 2300, 3300, 4300,  0.9,  0.28, 0.12, 0.05, 0.05, 0.3, 0.5, 0.85,0.0], # n\ (retroflex n, ण)
    'r\\': [350,  1000, 1400, 3300, 4200,  0.8,  0.55, 0.35, 0.18, 0.09, 0.4, 0.5, 0.0, 0.0],  # r\ (retroflex r, ड़)
}

# ---- Phoneme Classes ----
VOWELS          = {'i','I','e','E','{','@','a','A','O','U','u'}
NASALS          = {'m','n','N','n\\'}
APPROXIMANTS    = {'r','l','j','w','r\\'}
VOICED_PLOSIVES = {'b','d','g'}
UNVOICED_PLOSIVES = {'p','t','k'}
FRICATIVES      = {'s','S','z','v','f','h'}
ASPIRATED       = {'d_h','b_h','g_h','p_h','k_h','t_h'}
RETROFLEX       = {'d\\','t\\','r\\','n\\'}
SONORANT        = NASALS | APPROXIMANTS

bw_default = [80.0, 90.0, 120.0, 130.0, 160.0]

header = [
    'source_phoneme', 'target_phoneme',
    'f1_freq', 'f2_freq', 'f3_freq', 'f4_freq', 'f5_freq',
    'f1_amp', 'f2_amp', 'f3_amp', 'f4_amp', 'f5_amp',
    'chest', 'glottal', 'nasal', 'frication',
    'f1_bw', 'f2_bw', 'f3_bw', 'f4_bw', 'f5_bw',
    'bez_p1x', 'bez_p1y', 'bez_p2x', 'bez_p2y'
]

def get_bezier(src, tgt):
    """Phoneme-class-aware Bézier curve selection."""
    sv = src in VOWELS
    tv = tgt in VOWELS
    sn = src in SONORANT
    tn = tgt in SONORANT

    if sv and tv:
        return [0.33, 0.0, 0.66, 1.0]     # Vowel→Vowel: smooth S-curve
    elif sn and tv:
        return [0.2,  0.0, 0.5,  1.0]     # Sonorant→Vowel: medium smooth
    elif sv and tn:
        return [0.5,  1.0, 0.8,  0.0]     # Vowel→Sonorant: medium smooth
    elif src in (VOICED_PLOSIVES | UNVOICED_PLOSIVES) and tv:
        return [0.05, 0.0, 0.15, 1.0]     # Plosive→Vowel: very fast attack
    elif sv and tgt in (VOICED_PLOSIVES | UNVOICED_PLOSIVES):
        return [0.85, 1.0, 0.95, 0.0]     # Vowel→Plosive: fast closure
    elif src in ASPIRATED and tv:
        return [0.1,  0.0, 0.25, 1.0]     # Aspirated→Vowel: aspirate then voice
    elif src in FRICATIVES and tv:
        return [0.1,  0.0, 0.3,  1.0]     # Fricative→Vowel: slight delay
    elif sv and tgt in FRICATIVES:
        return [0.7,  1.0, 0.9,  0.0]     # Vowel→Fricative: anticipatory
    elif src in RETROFLEX and tv:
        return [0.08, 0.0, 0.2,  1.0]     # Retroflex→Vowel: sharp release
    else:
        return [0.2,  0.0, 0.4,  1.0]     # Default

with open('assets/dsp/voice.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(header)

    total_transitions = 0
    for src, src_params in phonemes.items():
        # Base state (no transition)
        row = [src, 'NONE']
        row.extend(src_params[:5])
        row.extend(src_params[5:10])
        row.extend([src_params[10], src_params[11], src_params[12], src_params[13]])
        row.extend(bw_default)
        row.extend([0.0, 0.0, 0.0, 0.0])
        writer.writerow(row)

        # NxN transitions
        for tgt, tgt_params in phonemes.items():
            if src == tgt:
                continue
            row = [src, tgt]
            row.extend(tgt_params[:5])
            row.extend(tgt_params[5:10])
            row.extend([tgt_params[10], tgt_params[11], tgt_params[12], tgt_params[13]])
            row.extend(bw_default)
            row.extend(get_bezier(src, tgt))
            writer.writerow(row)
            total_transitions += 1

n = len(phonemes)
print(f"Generated assets/dsp/voice.csv")
print(f"  Phonemes : {n}")
print(f"  Transitions: {total_transitions}  ({n}x{n} - {n} self = {n*n - n})")
print(f"  Total rows : {n + total_transitions}")
