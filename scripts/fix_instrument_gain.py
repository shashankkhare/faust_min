#!/usr/bin/env python3
"""
fix_instrument_gain.py — Linearize energy output across CSV amplitude levels.

For each frequency in an instrument's CSV:
  1. Adjust amp=1.0 gain so energy = 0.3 (±10%)
  2. Scale lower amp gains so sqrt(energy) ∝ amp (energy ∝ amp²)

Usage: python3 scripts/fix_instrument_gain.py <instrument_name_or_id>
Example: python3 scripts/fix_instrument_gain.py sarod
"""

import subprocess, sys, os, math, re, argparse

CSV_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "assets", "dsp")
TEST_BINARY = "./build-release/test_instruments"
WORK_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

TARGET_E_AT_AMP1 = 0.3
TARGET_TOLERANCE = 0.10  # ±10%
STRIKE = "0"

def resolve_id(name_or_id):
    """Resolve an instrument name or numeric ID to (id, name)."""
    try:
        id_val = int(name_or_id)
        # Numeric ID — find name by scanning available instruments output
        cmd = [TEST_BINARY, "--get-id", "none"]
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=5, cwd=WORK_DIR, input="-1\n")
        for line in r.stdout.split('\n'):
            m = re.search(r'ID\s+(\d+)\s*:\s*(\S+)', line)
            if m and int(m.group(1)) == id_val:
                name = m.group(2)
                return id_val, name
        print(f"ERROR: no instrument found for ID {id_val}")
        sys.exit(1)
    except ValueError:
        # String name — resolve ID via test binary
        name = name_or_id
        cmd = [TEST_BINARY, "--get-id", name]
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=5, cwd=WORK_DIR, input="-1\n")
        for line in result.stdout.split('\n'):
            m = re.search(r'ID\s+(\d+)\s*:\s*(\S+)', line)
            if m and m.group(2).lower() == name.lower():
                return int(m.group(1)), m.group(2)
        print(f"ERROR: unknown instrument '{name}'")
        sys.exit(1)

def csv_path(instrument_name):
    return os.path.join(CSV_DIR, f"{instrument_name.lower()}.csv")

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
    cmd = [TEST_BINARY, str(instrument_id), f"f={freq}", f"a={amp}", f"s={STRIKE}"]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15, cwd=WORK_DIR)
        for line in reversed(result.stdout.strip().split('\n')):
            parts = line.split(' , ')
            for part in parts:
                m = re.search(r'(?:\{)?\s*([\d.]+)\s*,\s*([\d.eE+-]+)', part)
                if m:
                    f_val = float(m.group(1))
                    if abs(f_val - freq) < 0.1:
                        return float(m.group(2))
        return None
    except subprocess.TimeoutExpired:
        return None

def main():
    global TARGET_E_AT_AMP1, STRIKE
    
    parser = argparse.ArgumentParser(description="Linearize energy output across CSV amplitude levels.")
    parser.add_argument("instrument", help="Instrument name or ID")
    parser.add_argument("--target", type=float, default=0.3, help="Target energy at amp=1.0 (default 0.3)")
    parser.add_argument("--strike", type=str, default="0", help="Strike type to use for testing (default 0)")
    
    args = parser.parse_args()
    TARGET_E_AT_AMP1 = args.target
    STRIKE = args.strike

    if not os.path.exists(TEST_BINARY):
        print(f"ERROR: {TEST_BINARY} not found. Run build first.")
        sys.exit(1)

    instrument_id, instrument_name = resolve_id(args.instrument)
    path = csv_path(instrument_name)

    print(f"Instrument: {instrument_name} (ID {instrument_id})")
    print(f"Reading: {path}")
    print(f"Target Energy: {TARGET_E_AT_AMP1}, Strike: {STRIKE}")
    header, rows, columns = read_csv(path)
    print(f"Loaded {len(rows)} rows, columns: {columns}")

    # Map column names (accept common variants)
    def col_name(candidates):
        for c in candidates:
            if c in columns:
                return c
        return candidates[0]

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

        ref_row = None
        for r in freq_rows:
            if abs(r[amp_col] - 1.0) < 0.01:
                ref_row = r
                break
        if ref_row is None:
            continue

        for r in freq_rows:
            if abs(r[amp_col] - 0.9) < 0.01:
                r[amp_col] = 0.8
                print(f"  {freq:.2f} Hz: fixed amp 0.9 -> 0.8")

        print(f"\n  --- {freq:.2f} Hz ---")

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
                new_g = round(ref_row[gain_col] * math.sqrt(TARGET_E_AT_AMP1 / e) if e > 0 else ref_row[gain_col], 4)
                new_g = max(0.01, min(50.0, new_g))
                print(f"  adjust gain {ref_row[gain_col]:.4f} -> {new_g:.4f}")
                ref_row[gain_col] = new_g
                write_csv(path, header, rows, columns)
                total_changes += 1
        else:
            print(f"    amp=1.0 still out of range after 3 iterations, continuing anyway")

        e_ref = measure(instrument_id, freq, 1.0)
        if e_ref is None:
            continue
        sqrt_e_ref = math.sqrt(e_ref)

        print(f"    {amp_col:>5} {'OldGain':>8} {'Energy':>12} {'Sqrt(E)':>12} {'TargetSqrt':>12} {'NewGain':>8}")
        for r in freq_rows:
            a = r[amp_col]
            if abs(a - 1.0) < 0.01:
                continue

            for iteration in range(3):
                e = measure(instrument_id, freq, a)
                if e is None:
                    break

                sqrt_e = math.sqrt(e)
                target_sqrt = sqrt_e_ref * a
                
                target_e = target_sqrt ** 2
                low = target_e * (1.0 - TARGET_TOLERANCE)
                high = target_e * (1.0 + TARGET_TOLERANCE)
                
                old_g = r[gain_col]
                
                if low <= e <= high:
                    print(f"    {a:5.1f} {old_g:8.4f} {e:12.6f} {sqrt_e:12.6f} {target_sqrt:12.6f} {'OK':>8}")
                    break
                
                new_g = round(old_g * target_sqrt / sqrt_e, 4) if sqrt_e > 0 else old_g
                new_g = max(0.01, min(50.0, new_g))
                
                print(f"    {a:5.1f} {old_g:8.4f} {e:12.6f} {sqrt_e:12.6f} {target_sqrt:12.6f} {new_g:8.4f}")
                
                if abs(new_g - r[gain_col]) > 0.0001:
                    r[gain_col] = new_g
                    write_csv(path, header, rows, columns)
                    total_changes += 1
                else:
                    break

    if total_changes > 0:
        write_csv(path, header, rows, columns)
        print(f"\n  Total gain changes: {total_changes}")
        print(f"  CSV updated: {path}")
    else:
        print(f"\n  No changes needed")

if __name__ == "__main__":
    main()
