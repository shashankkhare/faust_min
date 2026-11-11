import csv
import sys

if len(sys.argv) < 2:
    print("Usage: python3 normalize.py <instrument>")
    sys.exit(1)

instrument = sys.argv[1]
filepath = f'assets/dsp/{instrument}.csv'

with open(filepath) as f:
    rows = list(csv.DictReader(f))

max_gain = max(float(r['gain']) for r in rows)
for r in rows:
    r['gain'] = f"{float(r['gain']) / max_gain:.4f}"

with open(filepath, 'w', newline='') as f:
    w = csv.DictWriter(f, fieldnames=rows[0].keys())
    w.writeheader()
    w.writerows(rows)

print(f"Max gain was {max_gain}")
