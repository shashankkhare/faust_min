#!/usr/bin/env python3
"""
pitchcorrect.py — Measure and correct pitch drift in instrument CSV LUTs.

For each unique frequency in an instrument's CSV:
  1. Runs the test binary with --render --scan to measure Goertzel at f ± 5%
  2. Finds the peak offset (drift %)
  3. Computes a calibration correction value
  4. Adds an interactive review step, then writes the calibration column to CSV
  5. Verifies the fix by re-running the scan

Usage: python3 scripts/pitchcorrect.py <instrument_name_or_id>
Example: python3 scripts/pitchcorrect.py violin
"""

import subprocess, sys, os, math, re, argparse

CSV_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "assets", "dsp")
TEST_BINARY = "./build-release/test_instruments"
WORK_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ENV = {**os.environ, "LD_LIBRARY_PATH": os.path.join(WORK_DIR, "build-release", "shared")}

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

STRING_TUNING = 0.08
SPEED_OF_SOUND = 340.0


def resolve_id(name_or_id):
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
    direct = os.path.join(CSV_DIR, f"{name_lower}.csv")
    if os.path.exists(direct):
        return direct
    import glob as gglob
    for f in gglob.glob(os.path.join(CSV_DIR, "*.csv")):
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


def measure_scan(instrument_id, freq):
    cmd = [TEST_BINARY, str(instrument_id), f"f={freq}", "v=0.5", "--render", "--scan"]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30, cwd=WORK_DIR, env=ENV)
        for line in result.stdout.split('\n'):
            line = line.strip()
            if line.startswith('SCAN'):
                parts = line.split()
                if len(parts) >= 12:
                    values = [float(p) for p in parts[1:]]
                    if len(values) >= 11:
                        return values[:11]
        return None
    except subprocess.TimeoutExpired:
        return None


def find_peak_offset(values):
    max_idx = max(range(len(values)), key=lambda i: values[i])
    return max_idx - 5


def compute_calibration_physical(freq, peak_offset_pct):
    f2l_minus_tuning = SPEED_OF_SOUND / freq - STRING_TUNING
    return -peak_offset_pct / 100.0 * f2l_minus_tuning


def compute_calibration_cents(freq, peak_offset_pct):
    return round(-peak_offset_pct * 10.0, 2)


def main():
    parser = argparse.ArgumentParser(description="Measure and correct pitch drift in CSV LUTs.")
    parser.add_argument("instrument", help="Instrument name or ID")
    parser.add_argument("--column", default="calibration",
                        help="Column name for correction values (default: calibration)")
    parser.add_argument("--model", choices=['physical', 'cents'], default='physical',
                        help="Correction model: physical (string length offset) or cents (default: physical)")
    parser.add_argument("--yes", "-y", action="store_true",
                        help="Skip interactive prompts")
    parser.add_argument("--skip-verify", action="store_true",
                        help="Skip verification step")

    args = parser.parse_args()

    if not os.path.exists(TEST_BINARY):
        print(f"ERROR: {TEST_BINARY} not found. Run build first.")
        sys.exit(1)

    instrument_id, instrument_name = resolve_id(args.instrument)
    path = csv_path(instrument_name)

    print(f"Instrument: {instrument_name} (ID {instrument_id})")
    print(f"Reading: {path}")

    header, rows, columns = read_csv(path)
    print(f"Loaded {len(rows)} rows, columns: {columns}")

    freq_col = 'frequency' if 'frequency' in columns else 'freq'
    freqs = sorted(set(r[freq_col] for r in rows))
    print(f"Unique frequencies: {len(freqs)}")

    cal_col = args.column

    if cal_col not in columns:
        columns.append(cal_col)
        header = ','.join(columns)
        for r in rows:
            r[cal_col] = 0.0
        print(f"Added column '{cal_col}'")
    else:
        for r in rows:
            r[cal_col] = 0.0
        print(f"Zeroed column '{cal_col}' for baseline measurement")
    write_csv(path, header, rows, columns)

    results = {}

    print(f"\n{'─' * 60}")
    print("PHASE 1: Measuring drift (baseline, calibration=0)")
    print(f"{'─' * 60}")

    for freq in freqs:
        sys.stdout.write(f"  {freq:>7.1f} Hz: ")
        sys.stdout.flush()

        values = measure_scan(instrument_id, freq)
        if values is None:
            print("FAILED (no scan data)")
            continue

        peak_offset = find_peak_offset(values)

        if args.model == 'physical':
            cal = compute_calibration_physical(freq, peak_offset)
        else:
            cal = compute_calibration_cents(freq, peak_offset)

        results[freq] = {'offset': peak_offset, 'calibration': cal, 'scan': values}

        drift_str = f"{peak_offset:+d}%"
        try:
            cents = round(peak_offset * 10.0, 1)
            drift_str += f" ({cents:+} cents)"
            peak_val = max(values)
            print(f"drift={drift_str:>12}  cal={cal:+.6f}  peak={peak_val:.6f}")
        except:
            print(f"drift={drift_str:>12}  cal={cal:+.6f}")

    print(f"\n{'─' * 60}")
    print("Proposed calibration values:")
    print(f"{'─' * 60}")
    print(f"  {'Freq (Hz)':>9}  {'Drift':>6}  {'Calibration':>12}")
    for freq in sorted(results.keys()):
        r = results[freq]
        print(f"  {freq:>9.1f}  {r['offset']:+5d}%  {r['calibration']:+12.6f}")

    if not args.yes:
        try:
            resp = input(f"\nApply these {len(results)} calibration values to '{path}'? [Y/n] ")
            if resp.strip().lower() not in ('', 'y', 'yes'):
                print("Aborted.")
                return
        except EOFError:
            pass

    print(f"\nApplying calibration values...")
    for freq in sorted(results.keys()):
        r = results[freq]
        freq_rows = [row for row in rows if abs(row[freq_col] - freq) < 0.01]
        for row in freq_rows:
            row[cal_col] = round(r['calibration'], 6)

    write_csv(path, header, rows, columns)
    print(f"Updated: {path}")

    if args.skip_verify:
        print("\nDone.")
        return

    print(f"\n{'─' * 60}")
    print("PHASE 2: Verification (with calibration applied)")
    print(f"{'─' * 60}")

    all_pass = True
    for freq in sorted(results.keys()):
        sys.stdout.write(f"  {freq:>7.1f} Hz: ")
        sys.stdout.flush()

        values = measure_scan(instrument_id, freq)
        if values is None:
            print("FAILED (no scan data)")
            all_pass = False
            continue

        peak_offset = find_peak_offset(values)
        results[freq]['verify_offset'] = peak_offset

        pass_fail = "PASS" if abs(peak_offset) <= 1 else "FAIL"
        if pass_fail != "PASS":
            all_pass = False

        cents = round(peak_offset * 10.0, 1)
        print(f"drift={peak_offset:+d}% ({cents:+} cents)  [{pass_fail}]")

    print(f"\n{'─' * 60}")
    if all_pass:
        print("RESULT: All frequencies within ±1% tolerance.")
    else:
        bad = [f for f, r in results.items() if 'verify_offset' in r and abs(r['verify_offset']) > 1]
        print(f"RESULT: {len(bad)} frequencies still exceed ±1% tolerance:")
        for f in bad:
            r = results[f]
            print(f"  {f:.1f} Hz: verify_offset={r['verify_offset']:+d}%")

    print(f"\nSummary:")
    for freq in sorted(results.keys()):
        r = results[freq]
        pre = r['offset']
        post = r.get('verify_offset', '?')
        status = "OK" if (isinstance(post, int) and abs(post) <= 1) else "?"
        print(f"  {freq:>7.1f} Hz: {pre:+3d}% -> {post:+3d}%  cal={r['calibration']:.6f}  [{status}]")


if __name__ == "__main__":
    main()
