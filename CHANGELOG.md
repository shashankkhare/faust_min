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
