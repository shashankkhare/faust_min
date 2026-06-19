import csv

path = 'assets/dsp/tanpura.csv'
rows = []
with open(path, 'r') as f:
    reader = csv.reader(f)
    header = next(reader)
    for row in reader:
        if not row: continue
        rows.append(row)

if 'gain' not in header:
    header.append('gain')
    for row in rows:
        row.append('1.0')

    with open(path, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(header)
        writer.writerows(rows)
    print("Added gain column to tanpura.csv")
else:
    print("gain column already exists")
