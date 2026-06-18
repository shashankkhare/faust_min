import csv

# X-SAMPA Phonetical targets
# Format: symbol: [f1, f2, f3, f4, f5, a1, a2, a3, a4, a5]
phonemes = {
    # Vowels
    'A': [800.0, 1200.0, 2500.0, 3500.0, 4500.0, 1.0, 0.85, 0.55, 0.3, 0.15],
    'E': [400.0, 1800.0, 2600.0, 3600.0, 4500.0, 0.8, 1.0, 0.7, 0.4, 0.2],
    'I': [300.0, 2300.0, 3000.0, 3700.0, 4600.0, 0.7, 0.95, 0.8, 0.5, 0.25],
    'O': [400.0, 800.0, 2500.0, 3300.0, 4200.0, 0.9, 0.6, 0.4, 0.25, 0.1],
    'U': [300.0, 800.0, 2300.0, 3100.0, 4000.0, 0.85, 0.55, 0.35, 0.2, 0.1],
    
    # Basic consonant approximations (voiced nasal/plosive placeholders for now)
    'm': [250.0, 1200.0, 2200.0, 3200.0, 4200.0, 1.0, 0.3, 0.1, 0.05, 0.05],
    'n': [250.0, 1500.0, 2500.0, 3500.0, 4500.0, 1.0, 0.4, 0.15, 0.05, 0.05],
    'p': [300.0, 1000.0, 2000.0, 3000.0, 4000.0, 0.1, 0.1, 0.1, 0.1, 0.1],
    't': [300.0, 1500.0, 2500.0, 3500.0, 4500.0, 0.1, 0.1, 0.1, 0.1, 0.1],
    'k': [300.0, 2000.0, 3000.0, 4000.0, 5000.0, 0.1, 0.1, 0.1, 0.1, 0.1],
    's': [4000.0, 4500.0, 5000.0, 6000.0, 7000.0, 0.0, 0.0, 0.5, 0.8, 1.0],
    'S': [2500.0, 3000.0, 4000.0, 5000.0, 6000.0, 0.0, 0.2, 0.8, 1.0, 0.8]
}

# Constant values
chest = 0.5
glottal = 0.5
nasal = 0.0
bw = [80.0, 90.0, 120.0, 130.0, 160.0]

header = [
    'source_phoneme', 'target_phoneme',
    'f1_freq', 'f2_freq', 'f3_freq', 'f4_freq', 'f5_freq',
    'f1_amp', 'f2_amp', 'f3_amp', 'f4_amp', 'f5_amp',
    'chest', 'glottal', 'nasal',
    'f1_bw', 'f2_bw', 'f3_bw', 'f4_bw', 'f5_bw',
    'bez_p1x', 'bez_p1y', 'bez_p2x', 'bez_p2y'
]

with open('assets/dsp/voice.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(header)
    
    # 1. Base sounds (no transition, target='NONE')
    for p, params in phonemes.items():
        row = [p, 'NONE']
        row.extend(params[:5]) # Formant frequencies
        row.extend(params[5:]) # Formant amplitudes
        row.extend([chest, glottal, nasal])
        row.extend(bw)
        row.extend([0.0, 0.0, 0.0, 0.0]) # Linear fallback for non-transitions
        writer.writerow(row)
        
    # 2. Vowel-to-Vowel Transitions (smooth S-curve glide)
    vowels = ['A', 'E', 'I', 'O', 'U']
    for p1 in vowels:
        for p2 in vowels:
            if p1 != p2:
                # Evolve towards p2 targets using Bezier
                # We store the *target* frequencies in the transition row
                params = phonemes[p2]
                row = [p1, p2]
                row.extend(params[:5])
                row.extend(params[5:])
                row.extend([chest, glottal, nasal])
                row.extend(bw)
                row.extend([0.33, 0.0, 0.66, 1.0]) # Smooth S-Curve Bezier
                writer.writerow(row)

    # 3. Transitions to/from Consonants (Fast glide)
    for p1 in phonemes.keys():
        for p2 in phonemes.keys():
            if p1 != p2 and not (p1 in vowels and p2 in vowels):
                params = phonemes[p2]
                row = [p1, p2]
                row.extend(params[:5])
                row.extend(params[5:])
                
                # If nasal, boost nasal
                c_nasal = 0.8 if p2 in ['m', 'n'] else 0.0
                
                row.extend([chest, glottal, c_nasal])
                row.extend(bw)
                row.extend([0.1, 0.0, 0.2, 1.0]) # Fast attack Bezier
                writer.writerow(row)

print("Generated assets/dsp/voice.csv with X-SAMPA transitions.")
