# Gain Fix Procedure

Produces consistent perceived loudness across all frequencies for an instrument.

**⚠️ CRITICAL: Follow these three steps exactly. Do NOT modify DSP code, add limiters, change damping, or deviate from this procedure. Any timbre/behavior issues belong in a separate fix — not here.**

## Steps

### 1. Check DSP Stability

**⚠️ STEP 1 IS VERY CRITICAL ⚠️**

Before proceeding, ensure the DSP is stable and produces decent energy levels natively.
- Delete the instrument's CSV file from `assets/dsp/`.
- Run `test_instruments` to test the instrument at 160Hz to verify decent energy levels.
- Verify that the fundamental energy is large compared to overtones.
- If energy is too low or too high, refer to [`checkdsp.md`](checkdsp.md) to diagnose the issue.
- If no errors are flagged after following `checkdsp.md`, proceed to step 2.

### 2. Create or Reuse CSV

- If the CSV file already exists for this instrument, **keep it**. Skip directly to step 3.
- If no CSV exists, create a blank CSV by running the `create_<instrument>_csv.py` script (if available for the instrument).
- This will generate rows for different frequencies (in the instrument's playable range), velocity, and strike values (if applicable).
- The playable range is defined by the `freq` slider bounds in the `.dsp` file (e.g. `hslider("freq", 196.0, 82, 1046, 0.01)` means 82–1046 Hz).
- If no script exists, manually create the CSV with 7–12 frequencies covering the playable range, velocities [0.1, 0.2, 0.4, 0.6, 0.8, 1.0], and all gains=1.0.
- Note that output parameters will be different for different instruments.

### 3. Preparation

Before running the calibration script, ensure the `gain` slider in the instrument's `.dsp` file has a sufficient maximum range (e.g., `100` instead of `1`). If the range is capped at `1`, the script will fail to hit the target energy if it needs to amplify the signal significantly.

Change `gain = hslider("gain", 1.0, 0, 1, 0.01);` to `gain = hslider("gain", 1.0, 0, 100, 0.01);`.

### 4. Measure & Fit

Run the calibration script to measure the instrument's energy output at each (frequency, amplitude) pair in its CSV, then adjust the `gain` column so that `amp=1.0` produces energy ≈ 0.3.

```bash
python3 scripts/fix_instrument_gain.py <instrument_name_or_id> [--target <energy>] [--strike <strike_id>]
```
Example: `python3 scripts/fix_instrument_gain.py bayan --strike 1 --target 0.3`

The script requires a Release build of `test_instruments` at `./build-release/test_instruments`.

### 5. Normalize CSV Gains

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

### 6. Apply Max Gain in DSP

Take the `max_gain` from step 5 and multiply it into the hardcoded gain multiplier in the instrument's `.dsp` file.

Look for the output line in the DSP, e.g. in `nativeamericanflute.dsp`:

```
process = flute * gain * 1.0;
```

Change `1.0` → `1.0 * max_gain` (e.g. if `max_gain = 1.5207`):

```
process = flute * gain * 1.5207;
```

Now the DSP supplies the absolute scaling and the CSV only stores the relative frequency correction.

### 7. Revert Slider

Now that the internal DSP handles the massive scaling factor, restore the user-facing `gain` slider back to its normal `0` to `1` range.

Change `gain = hslider("gain", 1.0, 0, 100, 0.01);` back to `gain = hslider("gain", 1.0, 0, 1, 0.01);`.

### 8. Verify

Rebuild the shared library and test binary, then spot-check a few frequencies to confirm energy is within the target range.

```bash
cd build-release && make -j$(nproc)
LD_LIBRARY_PATH=shared ./test_instruments <instrument_id> f=<freq> v=1.0
```

- The output `{ freq, energy, sqrt(energy) }` should show `energy` close to `0.3` (target).
- Check at least 3 frequencies: low, mid, and high end of the instrument's range.
- If energy is consistently off, re-check that step 6 multiplier matches the `max_gain` from step 5.
