#!/usr/bin/env python3
import csv
import os

path = 'assets/dsp/harmonium.csv'
with open(path) as f:
    rows = list(csv.DictReader(f))

max_gain = max(float(r['gain']) for r in rows)
for r in rows:
    r['gain'] = f"{float(r['gain']) / max_gain:.4f}"

with open(path, 'w', newline='') as f:
    w = csv.DictWriter(f, fieldnames=rows[0].keys())
    w.writeheader()
    w.writerows(rows)

print(f"Max gain was {max_gain}")
