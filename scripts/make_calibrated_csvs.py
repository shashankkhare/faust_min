import csv
import shutil

# 1. Copy flute.csv directly to bansuri.csv
shutil.copyfile("assets/dsp/flute.csv", "assets/dsp/bansuri.csv")
print("Copied flute.csv to assets/dsp/bansuri.csv")

# 2. Read flute.csv and write to shakuhachi.csv with breath_noise added
with open("assets/dsp/flute.csv", "r") as f_in:
    reader = csv.reader(f_in)
    header = next(reader)
    
    new_header = header + ["breath_noise"]
    rows = []
    
    for row in reader:
        if not row:
            continue
        vel = float(row[1])
        # Add breath_noise based on velocity
        if vel <= 0.2:
            breath_noise = 0.02
        elif vel <= 0.6:
            breath_noise = 0.05
        else:
            breath_noise = 0.08
            
        new_row = row + [f"{breath_noise:.2f}"]
        rows.append(new_row)

with open("assets/dsp/shakuhachi.csv", "w", newline="") as f_out:
    writer = csv.writer(f_out)
    writer.writerow(new_header)
    writer.writerows(rows)
print("Generated assets/dsp/shakuhachi.csv with breath_noise")
