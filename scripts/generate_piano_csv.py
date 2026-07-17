import math
import csv
import os

FREQ_MIN = 55.0
FREQ_MAX = 2000.0

notes = []
for midi in range(24, 96):
    freq = 440.0 * math.pow(2.0, (midi - 69) / 12.0)
    if FREQ_MIN <= freq <= FREQ_MAX:
        notes.append(round(freq, 2))

velocities = [0.2, 0.4, 0.6, 0.8, 1.0]
new_rows = []

for freq in notes:
    for vel in velocities:
        new_rows.append({'frequency': freq, 'velocity': vel, 'gain': 1.0})

out_path = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'assets', 'dsp', 'piano.csv')
with open(out_path, 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=['frequency', 'velocity', 'gain'])
    writer.writeheader()
    for row in new_rows:
        writer.writerow(row)

print(f"Generated piano.csv: {len(notes)} freqs x {len(velocities)} velocities = {len(new_rows)} rows")
print(f"  Freq range: {notes[0]}-{notes[-1]} Hz")
