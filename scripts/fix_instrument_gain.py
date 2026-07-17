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
ENV = {**os.environ, "LD_LIBRARY_PATH": os.path.join(WORK_DIR, "build-release", "shared")}

TARGET_E_AT_AMP1 = 0.3
TARGET_TOLERANCE = 0.10  # ±10%
STRIKE = "0"
RENDER_MODE = True

NAMES = {0:'dayan',1:'bayan',2:'kick',3:'snare',4:'hihat',5:'tom',6:'ride',
         7:'bell',8:'bowl',9:'sitar',10:'flute',11:'tanpura',12:'piano',13:'sax',
         14:'cowbell',15:'trumpet',16:'shakuhachi',17:'bansuri',18:'violin',
         19:'rainmaker',20:'churchbell',21:'acousticguitar',22:'electricguitar',
         23:'bass',24:'cello',25:'cricket',26:'cuckoo',27:'waterfall',28:'djembe',
         29:'marimba',30:'conga',31:'bongo',32:'voice',33:'shaker',34:'seawave',
         35:'chougong',36:'lagnga',37:'dholak',38:'dhol',39:'guzheng',40:'erhu',
         41:'wind',42:'thunder',43:'dagu',44:'sarod',45:'santoor',46:'tumbi',
         47:'tibetanbowl',48:'ngachen',49:'mridangam',50:'ghatam',51:'panflute',
         52:'nativeamericanflute',53:'dizi',54:'harmonium'}
NAME_TO_ID = {v: k for k, v in NAMES.items()}

def resolve_id(name_or_id):
    """Resolve an instrument name or numeric ID to (id, name)."""
    try:
        id_val = int(name_or_id)
        name = NAMES.get(id_val, name_or_id)
        return id_val, name
    except ValueError:
        name_lower = name_or_id.lower()
        if name_lower in NAME_TO_ID:
            return NAME_TO_ID[name_lower], name_lower
        print(f"ERROR: unknown instrument '{name_or_id}'")
        sys.exit(1)

def csv_path(instrument_name):
    name_lower = instrument_name.lower()
    # Try flat name (electricguitar.csv)
    direct = os.path.join(CSV_DIR, f"{name_lower}.csv")
    if os.path.exists(direct):
        return direct
    # Try scanning DSP directory: the DSP filename (e.g. electric_guitar.dsp) determines the CSV name.
    # InstrumentMapper maps ID -> electric_guitar.dsp, and LUT derives electric_guitar.csv from that.
    # If a matching underscored file exists, use it.
    import glob as gglob
    for f in gglob.glob(os.path.join(CSV_DIR, "*.csv")):
        # Match name_lower case-insensitively, ignoring underscores & hyphens
        base = os.path.splitext(os.path.basename(f))[0]
        name_clean = name_lower.replace('_', '').replace('-', '')
        base_clean = base.replace('_', '').replace('-', '')
        if name_clean == base_clean:
            return f
    return direct

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
    cmd = [TEST_BINARY, str(instrument_id), f"f={freq}", f"v={amp}", f"s={STRIKE}"]
    if RENDER_MODE:
        cmd.append("--render")
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15, cwd=WORK_DIR, env=ENV)
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

def set_gain(row, gain_col, value, path, header, rows, columns):
    row[gain_col] = value
    write_csv(path, header, rows, columns)

def binary_search_gain(instrument_id, freq, amp, target_energy, initial_gain,
                       path, header, rows, columns, gain_col, row):
    GAIN_MIN, GAIN_MAX = 0.01, 100.0
    PROBE_LIMIT = 15
    BS_ITERS = 4

    lo = target_energy * (1.0 - TARGET_TOLERANCE)
    hi = target_energy * (1.0 + TARGET_TOLERANCE)

    g = max(GAIN_MIN, min(GAIN_MAX, initial_gain))
    set_gain(row, gain_col, g, path, header, rows, columns)
    e = measure(instrument_id, freq, amp)
    if e is None:
        print(f"    amp={amp:.1f}: FAILED measurement at gain={g:.4f}")
        return g, False

    if lo <= e <= hi:
        print(f"    amp={amp:.1f}: gain={g:.4f} E={e:.6f}  OK (initial)")
        return g, True

    if e < lo:
        print(f"    amp={amp:.1f}: gain={g:.4f} E={e:.6f} < target, probing up...")
        g_lo, e_lo = g, e
        g_hi, e_hi = g, e
        for step in range(PROBE_LIMIT):
            g_hi = min(g_hi * 2, GAIN_MAX)
            set_gain(row, gain_col, g_hi, path, header, rows, columns)
            e_hi = measure(instrument_id, freq, amp)
            if e_hi is None:
                print(f"    amp={amp:.1f}: FAILED at probe step {step}")
                return g_hi, False
            print(f"    amp={amp:.1f}: probe gain={g_hi:.4f} E={e_hi:.6f}")
            if e_hi >= lo:
                break
        else:
            if e_hi < lo:
                print(f"    amp={amp:.1f}: ERROR cannot reach target even at max gain")
                return g_hi, False
    else:
        print(f"    amp={amp:.1f}: gain={g:.4f} E={e:.6f} > target, probing down...")
        g_hi, e_hi = g, e
        g_lo, e_lo = g, e
        for step in range(PROBE_LIMIT):
            g_lo = max(g_lo / 2, GAIN_MIN)
            set_gain(row, gain_col, g_lo, path, header, rows, columns)
            e_lo = measure(instrument_id, freq, amp)
            if e_lo is None:
                print(f"    amp={amp:.1f}: FAILED at probe step {step}")
                return g_lo, False
            print(f"    amp={amp:.1f}: probe gain={g_lo:.4f} E={e_lo:.6f}")
            if e_lo <= hi:
                break
        else:
            if e_lo > hi:
                print(f"    amp={amp:.1f}: ERROR cannot reach target even at min gain")
                return g_lo, False

    print(f"    amp={amp:.1f}: binary search [{g_lo:.4f}, {g_hi:.4f}]")
    for step in range(BS_ITERS):
        g_mid = (g_lo + g_hi) / 2.0
        set_gain(row, gain_col, g_mid, path, header, rows, columns)
        e_mid = measure(instrument_id, freq, amp)
        if e_mid is None:
            print(f"    amp={amp:.1f}: FAILED at BS step {step}")
            return g_mid, False

        print(f"    amp={amp:.1f}: BS[{step}] gain={g_mid:.4f} E={e_mid:.6f}")

        if lo <= e_mid <= hi:
            return g_mid, True

        if e_mid < lo:
            g_lo = g_mid
        else:
            g_hi = g_mid

    g_final = (g_lo + g_hi) / 2.0
    set_gain(row, gain_col, g_final, path, header, rows, columns)
    e_final = measure(instrument_id, freq, amp)
    if e_final is None:
        print(f"    amp={amp:.1f}: FAILED final verification")
        return g_final, False
    print(f"    amp={amp:.1f}: final gain={g_final:.4f} E={e_final:.6f}")
    if lo <= e_final <= hi:
        return g_final, True
    return g_final, False

def main():
    global TARGET_E_AT_AMP1, STRIKE, RENDER_MODE
    
    parser = argparse.ArgumentParser(description="Linearize energy output across CSV amplitude levels.")
    parser.add_argument("instrument", help="Instrument name or ID")
    parser.add_argument("--target", type=float, default=0.3, help="Target energy at amp=1.0 (default 0.3)")
    parser.add_argument("--strike", type=str, default="0", help="Strike type to use for testing (default 0)")
    parser.add_argument("--render", action="store_true", default=True, help="Use fast render mode (no audio output, default True)")
    parser.add_argument("--no-render", action="store_true", help="Use real-time audio mode (audible output)")
    
    args = parser.parse_args()
    TARGET_E_AT_AMP1 = args.target
    STRIKE = args.strike
    RENDER_MODE = not args.no_render

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
    amp_col = col_name(['velocity', 'vel'])
    gain_col = col_name(['gain'])

    print(f"Using columns: freq='{freq_col}', amp='{amp_col}', gain='{gain_col}'")

    freqs = sorted(set(r[freq_col] for r in rows))
    print(f"Unique frequencies: {len(freqs)}")

    total_changes = 0
    skipped_freqs = []

    for freq in freqs:
        freq_rows = [r for r in rows if abs(r[freq_col] - freq) < 0.01]
        freq_rows.sort(key=lambda r: r[amp_col])

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

        old_g = ref_row[gain_col]
        g_found, ok = binary_search_gain(
            instrument_id, freq, 1.0, TARGET_E_AT_AMP1,
            old_g, path, header, rows, columns, gain_col, ref_row)
        e_check = measure(instrument_id, freq, 1.0)
        low = TARGET_E_AT_AMP1 * (1.0 - TARGET_TOLERANCE)
        high = TARGET_E_AT_AMP1 * (1.0 + TARGET_TOLERANCE)
        if e_check is not None:
            print(f"    amp=1.0: gain {old_g:.4f} -> {g_found:.4f}  E={e_check:.6f}  target=[{low:.6f}, {high:.6f}]", end="")
        if not ok:
            print(f"  WARNING: amp=1.0 could not reach target, skipping freq")
            skipped_freqs.append(freq)
            continue
        print("  OK")
        if abs(g_found - old_g) > 0.0001:
            total_changes += 1

        e_ref = measure(instrument_id, freq, 1.0)
        if e_ref is None:
            continue
        sqrt_e_ref = math.sqrt(e_ref)

        print(f"    {amp_col:>5} {'OldGain':>8} {'NewGain':>8} {'Energy':>12} {'Sqrt(E)':>12} {'TargetSqrt':>12}")
        for r in freq_rows:
            a = r[amp_col]
            if abs(a - 1.0) < 0.01:
                continue

            target_sqrt = sqrt_e_ref * a
            target_e = target_sqrt ** 2
            old_g = r[gain_col]
            g_found, ok = binary_search_gain(
                instrument_id, freq, a, target_e,
                old_g, path, header, rows, columns, gain_col, r)
            e_check = measure(instrument_id, freq, a)
            sqrt_e = math.sqrt(e_check) if e_check else 0
            if e_check is not None:
                print(f"    {a:5.1f} {old_g:8.4f} {g_found:8.4f} {e_check:12.6f} {sqrt_e:12.6f} {target_sqrt:12.6f}", end="")
            if not ok:
                print(f"  WARNING: amp={a} could not reach target, skipping")
                skipped_freqs.append(freq)
                continue
            print("  OK")
            if abs(g_found - old_g) > 0.0001:
                total_changes += 1

    if total_changes > 0:
        write_csv(path, header, rows, columns)
        print(f"\n  Total gain changes: {total_changes}")
        print(f"  CSV updated: {path}")
    else:
        print(f"\n  No changes needed")

if __name__ == "__main__":
    main()
