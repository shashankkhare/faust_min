import math
import csv

# Read original bayan.csv
orig_data = []
with open('assets/dsp/bayan.csv', 'r') as f:
    reader = csv.DictReader(f)
    for row in reader:
        try:
            orig_data.append({
                'frequency': float(row['frequency']),
                'amplitude': float(row['amplitude']),
                'velocity': float(row['velocity']),
                'gain': float(row['gain'])
            })
        except ValueError:
            pass

def interpolate(freq, amp, data, field):
    # Very simple 1D interpolation along frequency for a given amplitude
    pts = [d for d in data if abs(d['amplitude'] - amp) < 0.01]
    if not pts:
        return 0.5 # Default

    # Sort by frequency
    pts.sort(key=lambda x: x['frequency'])

    if freq <= pts[0]['frequency']:
        return pts[0][field]
    if freq >= pts[-1]['frequency']:
        return pts[-1][field]

    for i in range(len(pts) - 1):
        if pts[i]['frequency'] <= freq <= pts[i+1]['frequency']:
            f1, f2 = pts[i]['frequency'], pts[i+1]['frequency']
            v1, v2 = pts[i][field], pts[i+1][field]

            ratio = (freq - f1) / (f2 - f1)
            v = v1 + ratio * (v2 - v1)
            return round(v, 4)

    return 0.5

# Define frequencies for all semitones from C2 to C3
notes = []
for midi in range(36, 49): # C2 (36) to C3 (48)
    freq = 440.0 * math.pow(2.0, (midi - 69) / 12.0)
    notes.append(round(freq, 2))

# We need rows for amplitudes 0.0, 0.2, 0.4, 0.5, 0.6, 0.8, 1.0 to preserve the old ones + add new ones,
# or we can just use the standard 0.2, 0.4, 0.6, 0.8, 1.0 but interpolate velocity.
# Let's use 0.2, 0.4, 0.6, 0.8, 1.0
amplitudes = [0.2, 0.4, 0.6, 0.8, 1.0]

new_rows = []
for freq in notes:
    for amp in amplitudes:
        # Interpolate across the 3 original amplitudes (0.0, 0.5, 1.0) for this frequency?
        # Wait, the original csv only has 0.0, 0.5, 1.0. If we just ask for amp=0.2, `interpolate` won't find it!
        # Because pts = [d for d in data if abs(d['amplitude'] - amp) < 0.01] will be empty.
        # We need a 2D interpolation, or simply interpolate frequency first, then amplitude.
        pass

# 2D interpolation
def interpolate_2d(freq, amp, data, field):
    # First, for each available amplitude in the original data, interpolate frequency
    available_amps = sorted(list(set(d['amplitude'] for d in data)))
    freq_interp_vals = []
    for a in available_amps:
        val = interpolate(freq, a, data, field)
        freq_interp_vals.append({'amplitude': a, 'value': val})
    
    # Now interpolate across amplitude
    if amp <= available_amps[0]:
        return freq_interp_vals[0]['value']
    if amp >= available_amps[-1]:
        return freq_interp_vals[-1]['value']
        
    for i in range(len(available_amps) - 1):
        if available_amps[i] <= amp <= available_amps[i+1]:
            a1, a2 = available_amps[i], available_amps[i+1]
            v1, v2 = freq_interp_vals[i]['value'], freq_interp_vals[i+1]['value']
            ratio = (amp - a1) / (a2 - a1)
            v = v1 + ratio * (v2 - v1)
            return round(v, 4)
    return 0.5

for freq in notes:
    for amp in amplitudes:
        v = interpolate_2d(freq, amp, orig_data, 'velocity')
        g = interpolate_2d(freq, amp, orig_data, 'gain')
        new_rows.append({'frequency': freq, 'amplitude': amp, 'velocity': v, 'gain': g})

# Write to bayan.csv
with open('assets/dsp/bayan.csv', 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=['frequency', 'amplitude', 'velocity', 'gain'])
    writer.writeheader()
    for row in new_rows:
        writer.writerow(row)

print("Generated bayan.csv with C2-C3 range and preserved parameters.")
