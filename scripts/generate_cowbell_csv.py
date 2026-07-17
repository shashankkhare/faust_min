import math
import csv
import os

notes = []
semitones = [0, 2, 4, 5, 7, 9, 11]
for oct in range(2, 6):
    for s in semitones:
        midi = 12 * (oct + 1) + s
        freq = 440.0 * math.pow(2.0, (midi - 69) / 12.0)
        notes.append(round(freq, 2))

velocities = [0.2, 0.4, 0.6, 0.8, 1.0]
new_rows = []

for freq in notes:
    for vel in velocities:
        new_rows.append({'frequency': freq, 'velocity': vel, 'gain': 1.0})

out_path = 'assets/dsp/cowbell.csv'
os.makedirs(os.path.dirname(out_path), exist_ok=True)
with open(out_path, 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=['frequency', 'velocity', 'gain'])
    writer.writeheader()
    for row in new_rows:
        writer.writerow(row)

print("Generated cowbell.csv")
