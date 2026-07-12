#!/usr/bin/env python3
import csv
import math

with open('assets/dsp/harmonium.csv', 'w', newline='') as f:
    w = csv.writer(f)
    w.writerow(['frequency', 'velocity', 'gain', 'strike'])
    for midi_note in range(36, 97, 6): # Every half octave
        freq = 440.0 * (2.0 ** ((midi_note - 69) / 12.0))
        for vel in [0.1, 0.4, 0.7, 1.0]:
            w.writerow([f"{freq:.2f}", f"{vel:.1f}", "1.0", "0"])
print("Generated assets/dsp/harmonium.csv")
