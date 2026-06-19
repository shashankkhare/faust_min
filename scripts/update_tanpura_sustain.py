import csv

path = 'assets/dsp/tanpura.csv'
rows = []
try:
    with open(path, 'r') as f:
        reader = csv.DictReader(f)
        fieldnames = reader.fieldnames
        for row in reader:
            rows.append(row)
except FileNotFoundError:
    print(f"File not found: {path}")
    exit(1)

def get_sustain(freq):
    # Base: 35.0 at 130.81 (C3)
    # High at lower freq: 55.0 at 65.41 (C2)
    # Drops at higher freq: 20.0 at 392.00 (G4)
    if freq <= 65.41:
        return 55.0
    elif freq <= 130.81:
        ratio = (freq - 65.41) / (130.81 - 65.41)
        return round(55.0 - ratio * (55.0 - 35.0), 2)
    elif freq <= 392.00:
        ratio = (freq - 130.81) / (392.00 - 130.81)
        return round(35.0 - ratio * (35.0 - 20.0), 2)
    else:
        return 20.0

if 'sustain' not in fieldnames:
    fieldnames.append('sustain')

for row in rows:
    freq = float(row['frequency'])
    row['sustain'] = str(get_sustain(freq))

with open(path, 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(rows)

print("Updated sustain column in tanpura.csv based on frequency.")
