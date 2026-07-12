import csv
import sys

instrument = sys.argv[1]
with open(f'assets/dsp/{instrument}.csv') as f:
    rows = list(csv.DictReader(f))

max_gain = max(float(r['gain']) for r in rows)
for r in rows:
    r['gain'] = f"{float(r['gain']) / max_gain:.4f}"

with open(f'assets/dsp/{instrument}.csv', 'w', newline='') as f:
    w = csv.DictWriter(f, fieldnames=rows[0].keys())
    w.writeheader()
    w.writerows(rows)

print(f"Max gain was {max_gain}")
