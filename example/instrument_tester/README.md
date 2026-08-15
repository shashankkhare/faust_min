# faust_min_instrument_tester

Interactive instrument testing app for the `faust_min` plugin.

Browses all available instruments by category, plays single notes/patterns
through the generic instrument panel, and plays the bundled song assets
(Yaman, Hamsadhwani) plus built-in patterns (Tanpura Drone, Varanasi Dawn,
Dayan/Bayan Strokes, 22 Shrutis Test).

## Running

On startup the app runs `FaustEngine.init()` to extract the bundled DSP
assets, then boots the mixer at 48 kHz:

```dart
await FaustEngine.init();        // extract DSP assets, configure native paths
FaustMixer.instance.init(48000); // configure mixer sample rate
FaustMixer.instance.start();     // start the audio device
```

```bash
flutter pub get
flutter run
```
