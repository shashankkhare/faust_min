## 0.5.4

* **UML parser regex crash fix**: The tokenizer regex used `\~`, `\_`, `\>` escapes that LLVM libc++ (`std::regex`) rejects — this crashed **any** UML sequence parse (song load, inline `addSequence`, etc.) on Android and iOS. Escapes removed; parsing behavior unchanged.

## 0.5.3

* **FaustEngine.init() Skip-Logic**: Now skips re-extracting DSP assets when the target file's size and mtime already match the bundled source asset (byte-identical fallback), making init near-instant on repeat launches.
* **Init in Examples & Tests**: `FaustEngine.init()` added to example apps and Flutter tests, and documented in READMEs.
* **Native Track Muting**: `muteTrack`/`unmuteTrack`/`isTrackMuted` mixer APIs.
* **ChurchBell Fix**: Reduced hum subharmonic gain (modeGains(0) 1.0→0.4) so the prime/fundamental dominates pitch; fixed header capitalization so the generated DSP is `FaustChurchbellDSP.hpp` (case-sensitive iOS build).

## 0.5.2

* **Frequency Calibration for All Instruments**: Per-instrument pitch calibration tables (bansuri, sitar, sarod, tanpura) with cents-model correction and `pitchcorrect.py` automation for pitch drift.
* **Volume Calibration for All Instruments**: Gain calibration to target levels across instruments, including bansuri gain calibration to 0.5 target and piano/sitar DSP gain tuning.
* **Instrument Fixes**: Fixed pitch drift (violin, flute), improved bansuri breath attack, tanpura DSP updates, snare hiss parameter, and general DSP physical-model refinements across all instruments.

## 0.5.1

* **Packaging fix**: Include vendored `deps/oboe` in published package for Android builds.

## 0.5.0

*   **50+ Calibrated Instruments**: All instruments tuned and calibrated across multiple frequencies with measured energy (RMS, peak, Goertzel) per-instrument measurement windows.
*   **Kick Drum Gain Recalibrated**: 37.5→15 multiplier, E=0.32 P=0.84 target.
*   **Tibetan Percussion Balance**: Chougong, LagNga, Ngachen gain tuning for balanced energy levels.
*   **InstrumentMapper Measurement Tables**: Per-instrument `getMeasureStart()`/`getMeasureDuration()` for accurate energy measurement windows.
*   **Goertzel Energy in test_instruments**: `--render` mode now reports Goertzel energy at fundamental frequency.
*   **UML Sequencer & Mixer Updates**: Envelope support for track volume control.
*   **cmake OBJECT_DEPENDS Fix**: `FaustInstrument.cpp` depends on all generated hpp headers for correct rebuild propagation.
*   **computeRMS Stereo Fix**: Corrected stereo energy division (numFrames*2).

## 0.4.0

*   **Ghatam Instrument** (ID 50): Clay pot percussion with rich midrange resonance.
*   **Mridangam Instrument** (ID 49): South Indian double-headed drum physical model.
*   **Dayan DSP Redesign**: Dual-bank composite membrane model — Syahi (perfect harmonic 1×–5×) + Maidan (Bessel inharmonic 1.000, 1.593, 2.135, 2.295, 2.653), with per-stroke mix ratios.
*   **Violin Physical Model**: Safety clamps removed for clean gate-off, gain multiplier 1.1, strike=2 bowVelocity 0.15 for ≥392 Hz.
*   **FAUST_DISABLE_INTERPRETER**: New build macro; iOS (only) cannot use interpreter mode. Android guarded similarly. All other platforms support both StaticCompiled and InterpretedByte.
*   **Vendored FAUST Headers**: Architecture headers copied to `src/faust_arch/` for portable builds without FAUST SDK.
*   **iOS/macOS Forwarders**: Renamed from `.c` to `.mm` for Objective-C++ compilation; includes path fixed.
*   **CMake Portability**: `libfaust` linked via `find_library` instead of hardcoded path; system libfaust found automatically; test binaries use vendored headers.
*   **Podspec Metadata**: Proper homepage, author, description; iOS definines `FAUST_DISABLE_INTERPRETER`.
*   **Case-Sensitive HPP Fix**: Removed duplicate `FaustChurchbellDSP.hpp` / `FaustMaster_reverbDSP.hpp` conflicting with `FaustChurchBellDSP.hpp` / `FaustMasterReverbDSP.hpp`.
*   **analysis_options.yaml**: Added to root for pub.dev compliance.

## 0.3.1

*   **Tibetan Bowl Instrument**: Added `tibetanbowl` physical model (ID 47), assigned to idiophone → melody track.
*   **Dual LagNga Rhythm**: Interleaved 111 Hz and 222 Hz LagNga oscillators at BPM=60 for ~1 hit/second.
*   **UML Cell Count Fix**: Standalone `~`/`^` operators now create ContinuityDot tokens at current gridIndex, fixing inter-instrument desync.
*   **Instrument Classification**: Added `isMembraneophone()` / `isIdiophone()` for track routing instead of flat percussion flag.
*   **Mixer Weight Fix**: `setInstrumentWeight()` now properly updates `TrackInstrument::instrumentWeight` in mixer track registry.
*   **Amplitude Glide Rename**: `velocityGlide` → `amplitudeGlide` (correct naming for amplitude parameter).
*   **Base Frequency API**: Exposed `sequence_get_basefreq` / `sequence_set_basefreq` in Dart FFI.
*   **Dead Code Removal**: Removed unused `mAssignedWeight` from FaustInstrument.
*   **Dartdoc Coverage**: Added documentation comments to all public constructors, methods, and getters.

## 0.3.0

*   **Bansuri Breath Attack**: Added post-waveguide pink noise burst with rising-edge detection and 80ms decaying envelope for realistic breath attacks at note start.
*   **Bansuri Glide Fix**: Resolved pitch glitches during meend transitions using K=3 Inverse Distance Weighting (IDW) LUT blending and DSP `glide` parameter synchronization.
*   **Chak Click Fix**: Implemented early noteOff (30ms lookahead) in UMLParser to prevent residual waveguide energy from causing pop artifacts on fast note transitions.
*   **Memory Leak Fixes**: All test files now properly deallocate heap-allocated `UMLSequence` and `FaustInstrument` objects. Verified clean across all test suites with ASan.
*   **DSP Stability**: Added `si.smoo` smoothing to bansuri gain parameter to prevent zipper noise during parameter updates.
*   **Native Sequencer**: Sample-accurate native C++ engine for layered audio patterns — refined timing and reduced drift.
*   **Improved Strike Realism**: Enhanced noise-burst contact simulation for percussive instruments (Bell, Bowl, Dayan, Bayan).

## 0.2.0

*   Added **FaustBell**: High-fidelity physical modeling synthesis of a tuned meditative bell.
*   Added **FaustBowl**: High-fidelity Tibetan Singing Bowl with strike and sustain (rubbing) physics.
*   Added **Native Audio Sequencer**: Sample-accurate native C++ engine for layered audio patterns.
*   Implemented **Duration-based decay**: Precisely control ring length in seconds for Bell and Bowl.
*   Improved **Strike Realism**: Added noise-burst contact simulation for percussive instruments.
*   Expanded native bindings to include all percussion and melodic instruments (Dayan, Bayan, Kick, Snare, HiHat, Tom, Ride, Sitar).

## 0.1.0

* Initial release.
* High-fidelity Faust Flute physical model.
* Raw PCM data rendering interface via FFI.
* Support for Android, iOS, Linux, MacOS, and Windows.
* MIT License.
