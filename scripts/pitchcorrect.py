#!/usr/bin/env python3
"""
pitchcorrect.py — Measure and correct pitch drift for instrument DSPs.

For each unique frequency in an instrument's dedicated "<dsp>_calibration.csv":
  1. Runs the test binary with --render --scan to measure the FFT-estimated pitch
  2. Computes the residual drift %  (measured - target) / target * 100
  3. Writes freq_nudge = (target - measured) / target * 100 into the
     "freq_nudge" column (an additional column; the existing "calibration"
     cents column is left untouched)
  4. Asks for interactive review, then writes the column
  5. Verifies by re-running the scan (±1% tolerance)

The nudge is applied automatically by the engine during noteOn (applyFreqNudge)
on top of the cents calibration (applyCalibration).

Usage: python3 scripts/pitchcorrect.py <instrument_name_or_id>
Example: python3 scripts/pitchcorrect.py sarod
"""

import subprocess, sys, os, math, argparse

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

# Instruments with a calibration model that supports freq_nudge correction.
MODEL_MAP = {
    0:  'dayan',   # dayan
    1:  'bayan',   # bayan
    2:  'kick',    # kick
    3:  'snare',   # snare
    5:  'tom',     # tom
    7:  'bell',    # bell
    8:  'bowl',    # bowl
    9:  'sitar',   # sitar
    10: 'flute',   # flute
    12: 'piano',   # piano
    18: 'violin',  # violin
    23: 'bass',    # bass
    24: 'cello',   # cello
    35: 'chougong',# chougong
    36: 'lagnga',  # lagnga
    37: 'dholak',  # dholak
    38: 'dhol',    # dhol
     21: 'acousticguitar',# acoustic guitar
     43: 'dagu',    # dagu
     44: 'sarod',   # sarod
    48: 'ngachen', # ngachen
    49: 'mridangam',# mridangam
    50: 'ghatam',  # ghatam
}


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


def calibration_csv_path(instrument_name):
    """Return the dedicated '<dsp>_calibration.csv' path (case/underscore tolerant)."""
    import glob as gglob
    name_lower = instrument_name.lower()
    direct = os.path.join(CSV_DIR, f"{name_lower}_calibration.csv")
    if os.path.exists(direct):
        return direct
    for f in gglob.glob(os.path.join(CSV_DIR, "*_calibration.csv")):
        base = os.path.splitext(os.path.basename(f))[0].replace("_calibration", "")
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
                    except ValueError:
                        row[col] = parts[i]
                else:
                    row[col] = 0.0
            rows.append(row)
    return header, rows, columns


def fmt(val):
    """Format a float the way the CSV already stores it (no trailing zeros)."""
    if isinstance(val, str):
        return val
    if abs(val) < 1e-12:
        return "0" if val >= 0.0 else "-0"
    return format(val, 'g')


def write_csv(path, header, rows, columns):
    with open(path, 'w') as f:
        f.write(header + '\n')
        for r in rows:
            cells = []
            for c in columns:
                v = r.get(c, '')
                if c == 'freq_nudge' and isinstance(v, (int, float)):
                    cells.append(f"{v:.6f}")
                else:
                    cells.append(str(fmt(v)) if v != '' else '')
            f.write(','.join(cells) + '\n')


def measure_pitch(instrument_id, freq):
    """Render one note and return the FFT-estimated pitch (Hz), or None."""
    cmd = [TEST_BINARY, str(instrument_id), f"f={freq}", "v=0.5", "--render", "--scan"]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=60, cwd=WORK_DIR, env=ENV)
        for line in result.stdout.split('\n'):
            s = line.strip().rstrip(',').strip()
            if s.startswith('SCAN'):
                for token in s.split()[1:]:
                    try:
                        v = float(token)
                        if v > 0.0:
                            return v
                    except ValueError:
                        continue
        return None
    except subprocess.TimeoutExpired:
        return None


def main():
    parser = argparse.ArgumentParser(description="Measure and correct pitch drift (freq_nudge) in _calibration.csv.")
    parser.add_argument("instrument", help="Instrument name or ID")
    parser.add_argument("--column", default="freq_nudge",
                        help="Column to write nudge values into (default: freq_nudge)")
    parser.add_argument("--yes", "-y", action="store_true",
                        help="Skip interactive prompts")
    parser.add_argument("--skip-verify", action="store_true",
                        help="Skip verification step")
    parser.add_argument("--tolerance", type=float, default=1.0,
                        help="Verification tolerance in %% drift (default: 1.0, use 0.1 for pitched percussion)")

    args = parser.parse_args()

    if not os.path.exists(TEST_BINARY):
        print(f"ERROR: {TEST_BINARY} not found. Run build first.")
        sys.exit(1)

    instrument_id, instrument_name = resolve_id(args.instrument)
    if instrument_id not in MODEL_MAP:
        print(f"ERROR: '{instrument_name}' (ID {instrument_id}) has no calibration model defined.")
        print("Add an entry to MODEL_MAP in this script before running pitch correction.")
        sys.exit(1)

    path = calibration_csv_path(instrument_name)
    print(f"Instrument: {instrument_name} (ID {instrument_id})")
    print(f"Reading: {path}")

    header, rows, columns = read_csv(path)
    print(f"Loaded {len(rows)} rows, columns: {columns}")

    if 'frequency' not in columns and 'freq' not in columns:
        print(f"ERROR: no frequency column in {path}")
        sys.exit(1)
    freq_col = 'frequency' if 'frequency' in columns else 'freq'
    freqs = sorted(set(r[freq_col] for r in rows if r[freq_col] > 0.0))
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
    print("PHASE 1: Measuring drift (baseline, freq_nudge=0)")
    print(f"{'─' * 60}")

    for freq in freqs:
        sys.stdout.write(f"  {freq:>7.2f} Hz: ")
        sys.stdout.flush()

        measured = measure_pitch(instrument_id, freq)
        if measured is None:
            print("FAILED (no scan data)")
            continue

        drift_pct = (measured - freq) / freq * 100.0
        nudge = (freq - measured) / freq * 100.0
        results[freq] = {'measured': measured, 'drift_pct': drift_pct, 'nudge': nudge}
        print(f"measured={measured:8.2f} Hz  drift={drift_pct:+6.2f}%  nudge={nudge:+6.3f}%")

    if not results:
        print("No measurements succeeded. Aborting.")
        sys.exit(1)

    print(f"\n{'─' * 60}")
    print("Proposed freq_nudge values:")
    print(f"{'─' * 60}")
    print(f"  {'Freq (Hz)':>9}  {'Drift %':>8}  {'freq_nudge':>10}")
    for freq in sorted(results.keys()):
        r = results[freq]
        print(f"  {freq:>9.2f}  {r['drift_pct']:+7.2f}  {r['nudge']:+9.3f}")

    if not args.yes:
        try:
            resp = input(f"\nApply these {len(results)} freq_nudge values to '{path}'? [Y/n] ")
            if resp.strip().lower() not in ('', 'y', 'yes'):
                print("Aborted.")
                return
        except EOFError:
            pass

    print("\nApplying freq_nudge values...")
    for freq in sorted(results.keys()):
        r = results[freq]
        for row in rows:
            if abs(row[freq_col] - freq) < 0.01:
                row[cal_col] = round(r['nudge'], 6)

    write_csv(path, header, rows, columns)
    print(f"Updated: {path}")

    if args.skip_verify:
        print("\nDone.")
        return

    print(f"\n{'─' * 60}")
    print("PHASE 2: Verification (with freq_nudge applied)")
    print(f"{'─' * 60}")

    all_pass = True
    for freq in sorted(results.keys()):
        sys.stdout.write(f"  {freq:>7.2f} Hz: ")
        sys.stdout.flush()

        measured = measure_pitch(instrument_id, freq)
        if measured is None:
            print("FAILED (no scan data)")
            all_pass = False
            results[freq]['verify_measured'] = None
            continue

        drift_pct = (measured - freq) / freq * 100.0
        results[freq]['verify_measured'] = measured
        pass_fail = "PASS" if abs(drift_pct) <= args.tolerance else "FAIL"
        if pass_fail != "PASS":
            all_pass = False
        print(f"measured={measured:8.2f} Hz  drift={drift_pct:+6.2f}%  [{pass_fail}]")

    print(f"\n{'─' * 60}")
    if all_pass:
        print(f"RESULT: All frequencies within ±{args.tolerance}% tolerance.")
    else:
        bad = [f for f, r in results.items()
               if r.get('verify_measured') is None or abs((r['verify_measured'] - f) / f * 100.0) > args.tolerance]
        print(f"RESULT: {len(bad)} frequencies still exceed ±{args.tolerance}% tolerance:")
        for f in bad:
            r = results[f]
            vm = r.get('verify_measured')
            drift = '?' if vm is None else f"{((vm - f) / f * 100.0):+.2f}%"
            print(f"  {f:.2f} Hz: verify_drift={drift}")

    print("\nSummary (before -> after):")
    for freq in sorted(results.keys()):
        r = results[freq]
        pre = r['drift_pct']
        vm = r.get('verify_measured')
        post = '?' if vm is None else f"{(vm - freq) / freq * 100.0:+.2f}%"
        status = "OK" if (vm is not None and abs((vm - freq) / freq * 100.0) <= args.tolerance) else "?"
        print(f"  {freq:>7.2f} Hz: {pre:+6.2f}% -> {post:>7}  nudge={r['nudge']:+8.3f}  [{status}]")


if __name__ == "__main__":
    main()
