# Publishing faust_min — Cross-Platform Release Checklist

## 1. Pre-Release

**CRITICAL: All builds must use `-DCMAKE_BUILD_TYPE=Release` (or `RelWithDebInfo`).**
Debug builds (`-g`, no `-O`) produce unoptimized DSP code that can consume 5–10× more CPU and will fail performance requirements on mobile devices. Never ship a Debug build.

```bash
# Bump version in pubspec.yaml — major features → +0.1 (e.g. 0.4.0 → 0.5.0), minor changes → +0.01 (e.g. 0.4.0 → 0.4.1)
# Update CHANGELOG.md with new entries
# Ensure debug logging is OFF in all source files:
grep -rn "DEBUG_" src/ | grep -v "#define DEBUG_"
# (DEBUG_ORCHESTRATOR etc. should be #define'd to 0 for release)

# Run memory & CPU sanity check:
bash scripts/verify.sh
# Exits non-zero if peak RSS exceeds 512MB, crashes, or build fails.
```

## 2. Regenerate DSP Headers

```bash
# Rebuild all Faust .dsp -> .hpp on the host so generated headers are up to date
mkdir -p build-host && cd build-host
cmake ../src -DCMAKE_BUILD_TYPE=Release
make compile_faust_dsps
cd ..
```

Commit any changed DSP headers.

## 3. Linux — Native Build & Test

```bash
mkdir -p build-linux && cd build-linux
cmake ../src -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
# Quick sanity (tests require audio device):
./test_instruments 2>&1 | head -20
cd ..
```

## 4. Windows — MinGW Cross-Compile (from Linux)

```bash
# Ensure the MinGW toolchain is installed:
# sudo apt install g++-mingw-w64-x86-64

mkdir -p build-mingw && cd build-mingw
cmake ../src -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain-mingw64.cmake \
  -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
# Output: build-mingw/libfaust_min.dll, build-mingw/libfaust_min.dll.a
cd ..
```

**Note:** This builds a `FAUST_DISABLE_INTERPRETER` build (no libfaust for Windows).
The resulting DLL goes into `windows/` Flutter bundling (handled by the Flutter build system).

## 5. Android — NDK Native Compile Verification

```bash
# Verify the native code compiles with the Android NDK.
# This doesn't produce an APK — the Flutter host app does that at build time.

cd example/android
flutter build apk --debug
cd ../..
```

The CMake `ANDROID` path sets `FAUST_DISABLE_INTERPRETER` and links oboe
(vendored at `deps/oboe/`). The Android Gradle plugin picks up
`CMakeLists.txt` from `src/` automatically (as configured in
`android/build.gradle:43`).

A direct NDK build (without Gradle) can also verify compilation:
```bash
cmake -S src -B build-android \
  -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK/build/cmake/android.toolchain.cmake" \
  -DANDROID_ABI=arm64-v8a \
  -DANDROID_PLATFORM=android-24 \
  -DCMAKE_BUILD_TYPE=Release
cmake --build build-android
```

## 6. iOS — Podspec Validation

```bash
# From the plugin root:
cd ios
pod lib lint faust_min.podspec --allow-warnings
cd ..
```

This validates the podspec syntax and header paths. The `.mm` forwarder in
`ios/Classes/faust_min.mm` includes `../../src/faust_min.cpp`.

## 7. macOS — Podspec Validation

```bash
cd macos
pod lib lint faust_min.podspec --allow-warnings
cd ..
```

Same structure as iOS but with `FlutterMacOS` dependency and no
`FAUST_DISABLE_INTERPRETER` (macOS supports the interpreter).

## 8. dart pub publish

```bash
# Dry-run first:
dart pub publish --dry-run

# Fix any warnings (missing files, invalid paths, etc.)
# The package must pass analysis_options.yaml lint rules.

# Publish:
dart pub publish
```

## 9. GitHub Release

```bash
# Tag the version:
VERSION=$(grep 'version:' pubspec.yaml | awk '{print $2}')
git tag -a "v$VERSION" -m "faust_min v$VERSION"
git push origin "v$VERSION"

# Create the release (opens editor for release notes):
gh release create "v$VERSION" \
  --title "faust_min v$VERSION" \
  --notes "See CHANGELOG.md for details."

# Or manually at https://github.com/shashankkhare/faust_min/releases/new
```

## 10. Post-Release

```bash
# Verify the package is live:
dart pub global list | grep faust_min
# Or check: https://pub.dev/packages/faust_min
```

---

## Platform Notes

| Platform | Build Method | Interpreter? | Notes |
|----------|-------------|-------------|-------|
| Linux    | Native CMake | Yes (if libfaust installed) | Tests run natively |
| Windows  | MinGW cross (from Linux) | No (libfaust not available) | DLL output |
| Android  | NDK via CMake | No | Uses Oboe backend |
| iOS      | CocoaPods | No (Apple blocks JIT) | `.mm` forwarder |
| macOS    | CocoaPods | Yes | `.mm` forwarder |

## Troubleshooting

- **High CPU usage in development**: Debug builds (`-DCMAKE_BUILD_TYPE=Debug`) compile with `-g` and zero optimization. DSP-heavy sequences can consume 5–10× more CPU than Release builds (`-O3`). Always benchmark and deploy with `Release`.
- **`faust/dsp/interpreter-dsp.h` not found**: Means `FAUST_DISABLE_INTERPRETER`
  is not defined. Set it in CMake or podspec.
- **`_mm_pause()` undefined**: You're on non-x86 without `CPU_PAUSE()` coverage.
  Add an intrinsic for your arch in `FaustMixer.cpp`.
- **PE32+ DLL but can't link in MSVC**: The MinGW DLL exports C symbols via
  `DART_EXPORT` (declspec). For pure MSVC consumption, rebuild with MSVC toolchain.
