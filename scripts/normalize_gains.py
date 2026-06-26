import csv
import sys
import os

def normalize(csv_file):
    rows = []
    max_gain = 0.0
    with open(csv_file, 'r') as f:
        reader = csv.reader(f)
        header = next(reader)
        for row in reader:
            if not row or len(row) < 4: continue
            gain = float(row[3])
            if gain > max_gain:
                max_gain = gain
            rows.append(row)
            
    # normalize
    for row in rows:
        gain = float(row[3])
        row[3] = f"{gain / max_gain:.4f}"
        
    with open(csv_file, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(header)
        writer.writerows(rows)
        
    print(f"{os.path.basename(csv_file)} max_gain: {max_gain:.4f}")

normalize('assets/dsp/bayan.csv')
normalize('assets/dsp/dayan.csv')
