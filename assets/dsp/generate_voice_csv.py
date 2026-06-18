import csv
import os

# Base phoneme targets
# f1_freq, f2_freq, f3_freq, f4_freq, f5_freq, f1_amp, f2_amp, f3_amp, f4_amp, f5_amp, chest, glottal, nasal, f1_bw, f2_bw, f3_bw, f4_bw, f5_bw
targets = {
    "aa": [800.0, 1200.0, 2500.0, 3500.0, 4500.0, 1.00, 0.85, 0.55, 0.30, 0.15, 0.5, 0.5, 0.0, 80.0, 90.0, 120.0, 130.0, 160.0],
    "ee": [400.0, 1800.0, 2600.0, 3600.0, 4500.0, 0.80, 1.00, 0.70, 0.40, 0.20, 0.5, 0.5, 0.0, 80.0, 90.0, 120.0, 130.0, 160.0],
    "ii": [300.0, 2300.0, 3000.0, 3700.0, 4600.0, 0.70, 0.95, 0.80, 0.50, 0.25, 0.5, 0.5, 0.0, 80.0, 90.0, 120.0, 130.0, 160.0],
    "oo": [400.0, 800.0,  2500.0, 3300.0, 4200.0, 0.90, 0.60, 0.40, 0.25, 0.10, 0.5, 0.5, 0.0, 80.0, 90.0, 120.0, 130.0, 160.0],
    "uu": [300.0, 800.0,  2300.0, 3100.0, 4000.0, 0.85, 0.55, 0.35, 0.20, 0.10, 0.5, 0.5, 0.0, 80.0, 90.0, 120.0, 130.0, 160.0]
}

columns = [
    "source_phoneme", "target_phoneme",
    "f1_freq", "f2_freq", "f3_freq", "f4_freq", "f5_freq",
    "f1_amp", "f2_amp", "f3_amp", "f4_amp", "f5_amp",
    "chest", "glottal", "nasal",
    "f1_bw", "f2_bw", "f3_bw", "f4_bw", "f5_bw",
    "bez_p1x", "bez_p1y", "bez_p2x", "bez_p2y"
]

out_file = os.path.join(os.path.dirname(__file__), "voice.csv")

with open(out_file, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(columns)
    
    # 1. Steady State Rows (target_phoneme = NONE)
    # No bezier curve points needed
    for src, vals in targets.items():
        row = [src, "NONE"] + vals + [0.0, 0.0, 0.0, 0.0]
        writer.writerow(row)
        
    # 2. Transition Rows (N x N)
    for src, src_vals in targets.items():
        for tgt, tgt_vals in targets.items():
            if src == tgt: continue
            
            # Default bezier for a normal transition is an ease-in-out S-curve
            p1x, p1y = 0.33, 0.0
            p2x, p2y = 0.66, 1.0
            
            row = [src, tgt] + tgt_vals + [p1x, p1y, p2x, p2y]
            writer.writerow(row)

print(f"Generated {out_file}")
