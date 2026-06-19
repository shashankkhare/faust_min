import math
import csv

# Define frequencies for C Major scale (C2 to C5)
notes = []
semitones = [0, 2, 4, 5, 7, 9, 11]
for oct in range(2, 6):
    for s in semitones:
        midi = 12 * (oct + 1) + s
        freq = 440.0 * math.pow(2.0, (midi - 69) / 12.0)
        notes.append(round(freq, 2))

# Read original sarod.csv
orig_data = []
with open('assets/dsp/sarod.csv', 'r') as f:
    reader = csv.DictReader(f)
    for row in reader:
        try:
            orig_data.append({
                'frequency': float(row['frequency']),
                'amplitude': float(row['amplitude']),
                'gain': float(row['gain'])
            })
        except ValueError:
            pass

def interpolate(freq, amp, data):
    # Very simple 1D interpolation along frequency for a given amplitude
    pts = [d for d in data if abs(d['amplitude'] - amp) < 0.01]
    if not pts:
        return 0.5 # Default gain

    # Sort by frequency
    pts.sort(key=lambda x: x['frequency'])

    if freq <= pts[0]['frequency']:
        return pts[0]['gain']
    if freq >= pts[-1]['frequency']:
        return pts[-1]['gain']

    for i in range(len(pts) - 1):
        if pts[i]['frequency'] <= freq <= pts[i+1]['frequency']:
            f1, f2 = pts[i]['frequency'], pts[i+1]['frequency']
            g1, g2 = pts[i]['gain'], pts[i+1]['gain']

            ratio = (freq - f1) / (f2 - f1)
            g = g1 + ratio * (g2 - g1)
            return round(g, 3)

    return 0.5

# Generate new rows
new_rows = []
amplitudes = [0.1, 0.5, 1.0]

for freq in notes:
    for amp in amplitudes:
        g = interpolate(freq, amp, orig_data)
        new_rows.append({'frequency': freq, 'amplitude': amp, 'gain': g})

# Write back
with open('assets/dsp/sarod.csv', 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=['frequency', 'amplitude', 'gain'])
    writer.writeheader()
    for row in new_rows:
        writer.writerow(row)

print("Generated sarod.csv with C2-C5 scales.")
