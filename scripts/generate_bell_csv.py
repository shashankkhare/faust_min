import math
import csv
import os

# Bell DSP freq range: 200-800 Hz
FREQ_MIN = 200.0
FREQ_MAX = 800.0

notes = []
# Chromatic notes from C3 upward, filtered to 200-800 Hz
for midi in range(48, 108):
    freq = 440.0 * math.pow(2.0, (midi - 69) / 12.0)
    if FREQ_MIN <= freq <= FREQ_MAX:
        notes.append(round(freq, 2))

velocities = [0.2, 0.4, 0.6, 0.8, 1.0]
new_rows = []

for freq in notes:
    for vel in velocities:
        new_rows.append({'frequency': freq, 'velocity': vel, 'gain': 1.0})

out_path = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'assets', 'dsp', 'bell.csv')
os.makedirs(os.path.dirname(out_path), exist_ok=True)
with open(out_path, 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=['frequency', 'velocity', 'gain'])
    writer.writeheader()
    for row in new_rows:
        writer.writerow(row)

print(f"Generated bell.csv: {len(notes)} freqs x {len(velocities)} velocities = {len(new_rows)} rows")
print(f"  Freq range: {notes[0]}-{notes[-1]} Hz")
