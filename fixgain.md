# Gain Fix Procedure

Produces consistent perceived loudness across all frequencies for an instrument.

**⚠️ CRITICAL: Follow these three steps exactly. Do NOT modify DSP code, add limiters, change damping, or deviate from this procedure. Any timbre/behavior issues belong in a separate fix — not here.**

## Steps

### 0. Preparation

Before running the calibration script, ensure the `gain` slider in the instrument's `.dsp` file has a sufficient maximum range (e.g., `100` instead of `1`). If the range is capped at `1`, the script will fail to hit the target energy if it needs to amplify the signal significantly.

Change `gain = hslider("gain", 1.0, 0, 1, 0.01);` to `gain = hslider("gain", 1.0, 0, 100, 0.01);`.

### a. Measure & Fit

Run the calibration script to measure the instrument's energy output at each (frequency, amplitude) pair in its CSV, then adjust the `gain` column so that `amp=1.0` produces energy ≈ 0.3.

```bash
python3 scripts/fix_instrument_gain.py <instrument_name_or_id> [--target <energy>] [--strike <strike_id>]
```
Example: `python3 scripts/fix_instrument_gain.py bayan --strike 1 --target 0.3`

The script requires a Release build of `test_instruments` at `./build-release/test_instruments`.

### b. Normalize CSV Gains

Divide every value in the `gain` column by the maximum gain in that column. This makes the relative frequency/amplitude response flat (max gain in CSV = 1.0) while preserving the per-frequency shape.

```python
import csv

with open('assets/dsp/<instrument>.csv') as f:
    rows = list(csv.DictReader(f))

max_gain = max(float(r['gain']) for r in rows)
for r in rows:
    r['gain'] = f"{float(r['gain']) / max_gain:.4f}"

with open('assets/dsp/<instrument>.csv', 'w', newline='') as f:
    w = csv.DictWriter(f, fieldnames=rows[0].keys())
    w.writeheader()
    w.writerows(rows)

print(f"Max gain was {max_gain}")
```

### c. Apply Max Gain in DSP

Take the `max_gain` from step (b) and multiply it into the hardcoded gain multiplier in the instrument's `.dsp` file.

Look for the output line in the DSP, e.g. in `nativeamericanflute.dsp`:

```
process = flute * gain * 1.0;
```

Change `1.0` → `1.0 * max_gain` (e.g. if `max_gain = 1.5207`):

```
process = flute * gain * 1.5207;
```

Now the DSP supplies the absolute scaling and the CSV only stores the relative frequency correction.

### d. Revert Slider

Now that the internal DSP handles the massive scaling factor, restore the user-facing `gain` slider back to its normal `0` to `1` range.

Change `gain = hslider("gain", 1.0, 0, 100, 0.01);` back to `gain = hslider("gain", 1.0, 0, 1, 0.01);`.
