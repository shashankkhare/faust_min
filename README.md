# faust_min

A high-fidelity physical modeling music synthesis plugin and sequencing engine for Flutter, powered by **Faust**.

`faust_min` is a full-fledged, real-time computational acoustics engine based on Faust. Instead of relying on static, lifeless samples, `faust_min` mathematically simulates the physical properties of instruments (string tension, resonance, air pressure, tube length) to generate deeply expressive and highly realistic audio directly on the device. Result is very low memory and CPU footprint.  

## 🌟 Key Features

### 🎸 50+ Physically Modeled Instruments
The engine ships with an extensive, highly optimized library of over 50 real-time physical models, covering a vast array of global instruments:
*   **Western:** Electric/Acoustic Guitars, Pianos, Saxophones, Bass, Flutes, Drum Kits.
*   **Indian Classical & Folk:** Sitar, Sarod, Santoor, Bansuri, Tanpura, Tumbi, Tabla, Dhol, Dholak.
*   **Cinematic Chinese Nature:** Guzheng, Erhu, Dagu, Wind, Thunder, Chougong.
*   **Electronic & Ambient:** Tibetan Singing Bowls, Rainmakers, Synths, Vocal Formant Synthesizers.

### 🎹 Advanced Polyphony & Multithreading
*   **Dynamic Voice Allocation:** Built-in polyphonic support allows multiple notes to ring out simultaneously without cutting each other off. Availabe only for Piano and Guitars at the moment. Plan to add more western and eastern instruments in future. 
*   **Persistent Thread Pool:** Driven by a highly performant `FaustMixer` thread pool that renders heavy DSP algorithms concurrently across multiple CPU cores, avoiding UI thread blocks completely.
*   **Sample-Accurate Timing:** Perfect for high-density, multi-instrument sequencing.

### 🎼 The Universal Music Language (UML) Sequencer
`faust_min` includes a deeply integrated, zero-latency **Sequence Orchestrator** capable of parsing plain-text text files into complex musical arrangements. The sequencer intelligently adapts to different cultural notations:
*   **Western Notation:** Standard `C4`, `D#5`, `Eb` formatting.
*   **Indian Solfège (Sargam):** Fully parses `Sa`, `Re`, `Ga`, `Ma`, `Pa`, `Dha`, `Ni` using complex Shruti frequency ratios.
*   **Percussion Bols/Strokes:** Unpitched parsing of specific strokes like `Dha`, `Ge`, `Dhin` for Tabla or `Kik`, `Snr`, `Hat` for drum kits.

## 🚀 Getting Started

### Installation
Add `faust_min` to your `pubspec.yaml`:
```yaml
dependencies:
  faust_min: ^0.2.0
```

### Initialization
Before creating instruments or sequences, initialize the engine and the audio mixer:

```dart
import 'package:faust_min/faust_min.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  // Extract the bundled DSP assets to app storage and configure the
  // native C++ engines. Unchanged files are skipped on subsequent launches.
  await FaustEngine.init();

  // Configure the mixer with a sample rate (48 kHz) and start the audio device.
  FaustMixer.instance.init(48000);
  FaustMixer.instance.start();

  // ... create instruments / sequences below
}
```

All instruments and sequences must be created with the same sample rate as the mixer (48 kHz).

### Basic Instrument Usage
Generate high-fidelity audio on the fly:
```dart
import 'package:faust_min/faust_min.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await FaustEngine.init();
  FaustMixer.instance.init(48000);

  // Create a new Flute instance (Instrument ID 10, StaticCompiled, 48 kHz)
  final flute = FaustInstrument.create(10, 0, 48000);

  // Play a note (Frequency, Velocity)
  flute.noteOn(freq: 440.0, velocity: 0.8);

  // Apply real-time physical parameter modulations
  flute.setParameter("breath_pressure", 0.9);
  flute.setParameter("vibrato_depth", 0.05);

  // Let it ring, then release
  flute.noteOff();
}
```

### Advanced Multi-Instrument Sequencing
Orchestrate a massive arrangement using the UML Sequencer:

```dart
import 'package:faust_min/faust_min.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await FaustEngine.init();
  FaustMixer.instance.init(48000);
  FaustMixer.instance.start();

  final orchestrator = SequenceOrchestrator();

  // Define a Tumbi sequence using Indian notation and parameter overrides
  String tumbiUML = '''
  grid: 4
  bpm: 120
  instrument: tumbi
  notation: Indian
  basefreq: 659.25
  vibrato_depth: 0.08
  vibrato_rate: 7.0

  5Sa . . 5Re . 5Ga . . 5Re . . 5Sa . . . 
  ''';

  // Define a Dhol sequence using Percussion strokes
  String dholUML = '''
  grid: 4
  bpm: 120
  instrument: dhol

  Dha . . Na Na . . Tin Na . . Dha Dha . . Na
  ''';

  // Load and play flawlessly synchronized
  orchestrator.addSequence("Tumbi", tumbiUML);
  orchestrator.addSequence("Dhol", dholUML);

  orchestrator.play();
}
```

## 🔨 Build Process (Native Engine)

The native engine must be built with **CMake** — there is no other supported build path.

### Prerequisites
*   CMake 3.10+
*   A C++17 compiler (GCC/Clang)
*   Faust compiler (`faust`) on `PATH` — the build auto-compiles every `assets/dsp/*.dsp` file into a generated `Faust<Name>DSP.hpp` header whenever the DSP changes
*   FFTW3 (`libfftw3`) — required only by `test_instruments`

### Configure
Run CMake from the `linux/` directory (the CMake root that includes `src/`), into a build directory:

```bash
cmake -S linux -B build-release -DCMAKE_BUILD_TYPE=Release
```

### Build — always in one shot
Whenever the `faust_min` core is modified (any `.dsp`, any `src/*.cpp`/`*.hpp`, or any `assets/dsp/*.csv`), **all artifacts must be built together in a single invocation** — never build only one artifact:

```bash
cmake --build build-release -j$(nproc)
# or equivalently
make -C build-release -j$(nproc)
```

This is mandatory because every test binary (`test_sequence`, `test_mixer`, `test_instruments`) links against the `faust_min` shared library, and `faust_min` post-build syncs all DSP CSV lookup tables. Building one test in isolation leaves the others linked against a stale core — the whole set (engine + all test binaries) must be rebuilt together so they stay in lockstep. CMake tracks the generated DSP headers automatically, so this is safe and incremental.

### Artifacts
*   `build-release/shared/libfaust_min.so` — the engine (bundled by the Flutter Linux plugin).
*   `build-release/shared/test_instruments`, `test_mixer`, `test_sequence` — test binaries (also reachable via `build-release/`).
*   DSP calibration CSVs are auto-synced to both `assets/dsp/` and `build-release/assets/dsp/` on every build.

### Running tests
Test binaries resolve `libfaust_min.so` via the build dir, so run them from the repo root with `LD_LIBRARY_PATH` set:

```bash
LD_LIBRARY_PATH=build-release/shared ./build-release/test_instruments <id> f=220 v=0.8 s=0 --render
```

## 🏗 Architecture & Stability

Legacy C++ audio libraries often suffer from thread-safety issues, `SIGSEGV` crashes, and timing drift when used in a modern, multithreaded environment like Flutter's Dart Isolates. 

`faust_min` solves this. The underlying DSP code is generated by **Faust (Functional Audio Stream)**, which outputs completely stateless, re-entrant, memory-safe C++ arrays that are fully decoupled from the UI. This ensures **industrial-grade stability** and zero latency for professional audio applications.

## 🚀 Roadmap
- **Enhanced Playing Techniques:** Support for enhanced playing techniques for all instruments.
- **Enhanced Mixer:** Support for chaining (parallel/serial) various DSP elements like echo, bandpass, etc.
- **More wrappers:** Currently only Dart but in future Java, and Python too.    

## 📄 License
This project is licensed under the **MIT License**.
