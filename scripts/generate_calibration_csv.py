#!/usr/bin/env python3
"""Generate calibration CSV for an instrument with standard note set and amplitudes."""

import math, csv, sys, os

# Hindustani equivalent: Sa Re Ga Ma Pa Dha Ni = 0, 2, 4, 5, 7, 9, 11 semitones
NOTES = [0, 2, 4, 5, 7, 9, 11]
NOTE_NAMES = ['Sa', 'Re', 'Ga', 'Ma', 'Pa', 'Dha', 'Ni']

def freq_from_semitone(semitone):
    return round(440.0 * math.pow(2.0, (semitone - 69) / 12.0), 2)

# Define octave ranges (in MIDI semitones, A4 = 69)
RANGES = {
    'sarod':   {'start': 48, 'end': 83},   # C3 (48) to C6 (83) = 3 octaves
    'sitar':   {'start': 48, 'end': 83},   # C3 (48) to C6 (83) = 3 octaves
    'bowl':    {'start': 48, 'end': 67},   # C3 (48) to G4 (67) = 2 octaves
}

AMPLITUDES = [0.2, 0.4, 0.6, 0.8, 1.0]

def generate_freqs(name):
    if name not in RANGES:
        print(f"Unknown instrument: {name}")
        sys.exit(1)
    r = RANGES[name]
    # Find first C (MIDI note 0 mod 12) at or above start
    first_c = ((r['start'] + 11) // 12) * 12
    freqs = []
    for oct_off in range(4):
        base = first_c + oct_off * 12
        if base > r['end']:
            break
        for s in NOTES:
            midi = base + s
            if r['start'] <= midi <= r['end']:
                freqs.append(freq_from_semitone(midi))
    return freqs

def read_old_csv(path):
    data = []
    try:
        with open(path) as f:
            reader = csv.DictReader(f)
            for row in reader:
                entry = {}
                for k, v in row.items():
                    try:
                        entry[k.strip()] = float(v)
                    except:
                        entry[k.strip()] = v
                data.append(entry)
    except FileNotFoundError:
        pass
    return data

def interpolate_extra(freq, amp, old_data, extra_cols):
    """Interpolate extra column values from old CSV for given (freq, amp)."""
    result = {}
    for col in extra_cols:
        # Find nearest old row by (freq, amp) distance
        best_val = 0.0
        best_dist = float('inf')
        for row in old_data:
            if col not in row:
                continue
            f_old = float(row.get('frequency', 0))
            a_old = float(row.get('amplitude', 0))
            f_norm = (freq - f_old) / (freq + f_old + 1e-6)
            a_norm = (amp - a_old) / (amp + a_old + 1e-6)
            dist = f_norm * f_norm + a_norm * a_norm
            if dist < best_dist:
                best_dist = dist
                best_val = float(row[col])
        result[col] = round(best_val, 4)
    return result

def generate_csv(name, csv_path):
    freqs = generate_freqs(name)
    old_data = read_old_csv(csv_path)
    
    # Determine extra columns from old CSV header
    extra_cols = []
    if old_data:
        all_cols = list(old_data[0].keys())
        exclude = {'frequency', 'freq', 'amplitude', 'amp', 'gain'}
        extra_cols = [c for c in all_cols if c not in exclude]
    
    base_cols = ['frequency', 'amplitude', 'gain']
    all_cols = base_cols + extra_cols
    
    rows = []
    for freq in freqs:
        for amp in AMPLITUDES:
            row = {'frequency': freq, 'amplitude': amp, 'gain': 0.5}
            if extra_cols and old_data:
                extra = interpolate_extra(freq, amp, old_data, extra_cols)
                row.update(extra)
            elif extra_cols:
                for c in extra_cols:
                    row[c] = 0.0
            rows.append(row)
    
    with open(csv_path, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=all_cols)
        writer.writeheader()
        for row in rows:
            writer.writerow(row)
    
    print(f"Generated {csv_path}: {len(freqs)} freqs x {len(AMPLITUDES)} amps = {len(rows)} rows")
    if extra_cols:
        print(f"  Extra columns preserved: {extra_cols}")
    
    return len(rows)

if __name__ == '__main__':
    csv_dir = sys.argv[1] if len(sys.argv) > 1 else 'assets/dsp'
    total = 0
    for name in ['sarod', 'sitar', 'bowl']:
        path = os.path.join(csv_dir, f'{name}.csv')
        n = generate_csv(name, path)
        total += n
    print(f"\nTotal: {total} rows across 3 instruments")
