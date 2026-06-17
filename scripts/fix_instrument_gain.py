#!/usr/bin/env python3
"""
fix_instrument_gain.py — Linearize energy output across CSV amplitude levels.

For each frequency in an instrument's CSV:
  1. Adjust amp=1.0 gain so energy = 0.3 (±10%)
  2. Scale lower amp gains so sqrt(energy) ∝ amp (energy ∝ amp²)

Usage: python3 scripts/fix_instrument_gain.py <instrument_id>
Example: python3 scripts/fix_instrument_gain.py 8
"""

import subprocess, sys, os, math, re

CSV_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "assets", "dsp")
TEST_BINARY = "./build-release/test_instruments"
WORK_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

INSTRUMENT_NAMES = {8: "bowl", 52: "nativeamericanflute"}

TARGET_E_AT_AMP1 = 0.3
TARGET_TOLERANCE = 0.10  # ±10%

def csv_path(instrument_id):
    name = INSTRUMENT_NAMES.get(instrument_id)
    if not name:
        print(f"Unknown instrument ID: {instrument_id}")
        sys.exit(1)
    return os.path.join(CSV_DIR, f"{name}.csv")

def read_csv(path):
    with open(path) as f:
        header = f.readline().strip()
        columns = [c.strip() for c in header.split(',')]
        rows = []
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = [x.strip() for x in line.split(',')]
            row = {}
            for i, col in enumerate(columns):
                if i < len(parts):
                    try:
                        row[col] = float(parts[i])
                    except:
                        row[col] = parts[i]
                else:
                    row[col] = 0.0 if col != 'strike' else 0.0
            rows.append(row)
    return header, rows, columns

def write_csv(path, header, rows, columns):
    with open(path, 'w') as f:
        f.write(header + '\n')
        for r in rows:
            f.write(','.join(str(r.get(c, '')) for c in columns) + '\n')

def measure(instrument_id, freq, amp):
    cmd = [TEST_BINARY, str(instrument_id), f"f={freq}", f"a={amp}"]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15, cwd=WORK_DIR)
        for line in reversed(result.stdout.strip().split('\n')):
            m = re.match(r'^([\d.]+)\s*,\s*([\d.eE+-]+)$', line.strip())
            if m:
                return float(m.group(2))
        return None
    except subprocess.TimeoutExpired:
        return None

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 scripts/fix_instrument_gain.py <instrument_id>")
        sys.exit(1)

    instrument_id = int(sys.argv[1])
    path = csv_path(instrument_id)

    print(f"Reading: {path}")
    header, rows, columns = read_csv(path)
    print(f"Loaded {len(rows)} rows, columns: {columns}")

    if not os.path.exists(TEST_BINARY):
        print(f"ERROR: {TEST_BINARY} not found. Run build first.")
        sys.exit(1)

    # Map column names (accept common variants)
    def col_name(candidates):
        for c in candidates:
            if c in columns:
                return c
        return candidates[0]  # fallback

    freq_col = col_name(['frequency', 'freq'])
    amp_col = col_name(['amplitude', 'amp'])
    gain_col = col_name(['gain'])

    print(f"Using columns: freq='{freq_col}', amp='{amp_col}', gain='{gain_col}'")

    freqs = sorted(set(r[freq_col] for r in rows))
    print(f"Unique frequencies: {len(freqs)}")

    total_changes = 0

    for freq in freqs:
        freq_rows = [r for r in rows if abs(r[freq_col] - freq) < 0.01]
        freq_rows.sort(key=lambda r: r[amp_col])

        if len(freq_rows) < 2:
            continue

        # Find the amp=1.0 row (reference)
        ref_row = None
        for r in freq_rows:
            if abs(r[amp_col] - 1.0) < 0.01:
                ref_row = r
                break
        if ref_row is None:
            continue

        # Fix amp=0.9 -> 0.8 anomalies
        for r in freq_rows:
            if abs(r[amp_col] - 0.9) < 0.01:
                r[amp_col] = 0.8
                print(f"  {freq:.2f} Hz: fixed amp 0.9 -> 0.8")

        print(f"\n  --- {freq:.2f} Hz ---")

        # === Step 1: Fix amp=1.0 gain to hit target energy ===
        for iteration in range(3):
            e = measure(instrument_id, freq, 1.0)
            if e is None:
                print(f"    FAILED measurement at amp=1.0, skipping freq")
                break

            low = TARGET_E_AT_AMP1 * (1.0 - TARGET_TOLERANCE)
            high = TARGET_E_AT_AMP1 * (1.0 + TARGET_TOLERANCE)
            print(f"    amp=1.0: E={e:.6f}  target=[{low:.6f}, {high:.6f}]", end="")

            if low <= e <= high:
                print("  OK")
                break
            else:
                new_g = round(ref_row[gain_col] * math.sqrt(TARGET_E_AT_AMP1 / e), 4)
                new_g = max(0.01, min(50.0, new_g))
                print(f"  adjust gain {ref_row[gain_col]:.4f} -> {new_g:.4f}")
                ref_row[gain_col] = new_g
                write_csv(path, header, rows, columns)
                total_changes += 1
        else:
            print(f"    amp=1.0 still out of range after 3 iterations, continuing anyway")

        # Re-measure amp=1.0 with final gain for reference
        e_ref = measure(instrument_id, freq, 1.0)
        if e_ref is None:
            continue
        sqrt_e_ref = math.sqrt(e_ref)

        # === Step 2: Fix lower amp gains ===
        print(f"    {amp_col:>5} {'OldGain':>8} {'Energy':>12} {'Sqrt(E)':>12} {'TargetSqrt':>12} {'NewGain':>8}")
        for r in freq_rows:
            a = r[amp_col]
            if abs(a - 1.0) < 0.01:
                continue  # already fixed

            e = measure(instrument_id, freq, a)
            if e is None:
                continue

            sqrt_e = math.sqrt(e)
            target_sqrt = sqrt_e_ref * a  # proportional to amp
            old_g = r[gain_col]
            new_g = round(old_g * target_sqrt / sqrt_e, 4) if sqrt_e > 0 else old_g
            new_g = max(0.01, min(50.0, new_g))
            print(f"    {a:5.1f} {old_g:8.4f} {e:12.6f} {sqrt_e:12.6f} {target_sqrt:12.6f} {new_g:8.4f}")

            if abs(new_g - r[gain_col]) > 0.0001:
                r[gain_col] = new_g
                total_changes += 1

    if total_changes > 0:
        write_csv(path, header, rows, columns)
        print(f"\n  Total gain changes: {total_changes}")
        print(f"  CSV updated: {path}")
    else:
        print(f"\n  No changes needed")

if __name__ == "__main__":
    main()
