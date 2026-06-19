import math
import csv

# Read original tanpura.csv
orig_data = []
try:
    with open('assets/dsp/tanpura.csv', 'r') as f:
        reader = csv.DictReader(f)
        for row in reader:
            try:
                orig_data.append({
                    'frequency': float(row['frequency']),
                    'amplitude': float(row['amplitude']),
                    'sustain': float(row.get('sustain0', 8.0)),
                    'jivariThreshold': float(row.get('jivariThreshold', 0.09)),
                    'jivari': float(row.get('jivari', 0.4)),
                    'excDur': float(row.get('excDur', 1.0)),
                    'excGain': float(row.get('excGain', 0.5)),
                    'excLPF': float(row.get('excLPF', 2000.0)),
                    'dispersion': float(row.get('dispersion', 0.1)),
                    'stringGainVal': float(row.get('stringGainVal0', 0.5)),
                    'gain': float(row.get('gain', 1.0))
                })
            except ValueError:
                pass
except FileNotFoundError:
    print("tanpura.csv not found, proceeding with defaults.")

def interpolate(freq, amp, data, field, default_val):
    if not data: return default_val
    pts = [d for d in data if abs(d['amplitude'] - amp) < 0.01]
    if not pts:
        return default_val
    pts.sort(key=lambda x: x['frequency'])
    if freq <= pts[0]['frequency']: return pts[0][field]
    if freq >= pts[-1]['frequency']: return pts[-1][field]
    for i in range(len(pts) - 1):
        if pts[i]['frequency'] <= freq <= pts[i+1]['frequency']:
            f1, f2 = pts[i]['frequency'], pts[i+1]['frequency']
            v1, v2 = pts[i][field], pts[i+1][field]
            ratio = (freq - f1) / (f2 - f1)
            v = v1 + ratio * (v2 - v1)
            return round(v, 4)
    return default_val

def interpolate_2d(freq, amp, data, field, default_val):
    if not data: return default_val
    available_amps = sorted(list(set(d['amplitude'] for d in data)))
    if not available_amps: return default_val
    freq_interp_vals = []
    for a in available_amps:
        val = interpolate(freq, a, data, field, default_val)
        freq_interp_vals.append({'amplitude': a, 'value': val})
    if amp <= available_amps[0]: return freq_interp_vals[0]['value']
    if amp >= available_amps[-1]: return freq_interp_vals[-1]['value']
    for i in range(len(available_amps) - 1):
        if available_amps[i] <= amp <= available_amps[i+1]:
            a1, a2 = available_amps[i], available_amps[i+1]
            v1, v2 = freq_interp_vals[i]['value'], freq_interp_vals[i+1]['value']
            ratio = (amp - a1) / (a2 - a1)
            v = v1 + ratio * (v2 - v1)
            return round(v, 4)
    return default_val

# Generate notes from C2 to G4 (36 to 67)
notes = []
for midi in range(36, 68):
    freq = 440.0 * math.pow(2.0, (midi - 69) / 12.0)
    notes.append(round(freq, 2))

amplitudes = [0.2, 0.4, 0.6, 0.8, 1.0]
new_rows = []

fields = ['sustain', 'jivariThreshold', 'jivari', 'excDur', 'excGain', 'excLPF', 'dispersion', 'stringGainVal', 'gain']
defaults = {'sustain': 8.0, 'jivariThreshold': 0.09, 'jivari': 0.4, 'excDur': 1.0, 'excGain': 0.5, 'excLPF': 2000.0, 'dispersion': 0.1, 'stringGainVal': 0.5, 'gain': 1.0}

for freq in notes:
    for amp in amplitudes:
        row = {'frequency': freq, 'amplitude': amp}
        for f in fields:
            row[f] = interpolate_2d(freq, amp, orig_data, f, defaults[f])
        
        # Override gain to 1.0 for calibration
        row['gain'] = 1.0
        new_rows.append(row)

with open('assets/dsp/tanpura.csv', 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=['frequency', 'amplitude'] + fields)
    writer.writeheader()
    for row in new_rows:
        writer.writerow(row)

print("Generated tanpura.csv with C2-G4 range.")
