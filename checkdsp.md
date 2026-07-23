# DSP Basic Checklist

## 1. Output Multiplier

- `process = ... * (gain * <multiplier>)`
- If multiplier is too large, energy will be too high even at gain=0.01
- If multiplier is too small, energy will be too low even at gain=100

## 2. Excitation

- Does the model receive `velocity` in its input?
- e.g. `pm.guitar(..., velocity * excBoost, ...)` — if excBoost is 0 or missing, output will be silent
- For `elecGuitar`: `mute` parameter — if `mute=0`, output is muted. Default should be `mute=1.0`

## 3. Control Smoothing

- `si.smoo` on `gain` causes slow settling — remove during calibration
- `si.smoo` on `freq` or `pluckPosition` is fine

## 4. Check Raw Energy

```bash
# Run at a mid frequency with v=1.0
build-release/test_instruments <id> f=200 v=1 s=0 --render
```

- Energy should be in a reasonable range (~0.01 to ~2.0)
- If near 0: excitation problem (missing mute, missing velocity boost)
- If way above 2.0: output multiplier too high
- **Peak must NOT exceed [-1.0, 1.0]** — every instrument must clip/limit output to this range. If peak > 1.0 or < -1.0, the DSP is broken.
