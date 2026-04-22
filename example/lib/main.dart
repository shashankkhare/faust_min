import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:typed_data';
import 'dart:math' as math;

import 'package:faust_min/faust_min.dart';
import 'package:flutter_soloud/flutter_soloud.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await SoLoud.instance.init();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData.dark(useMaterial3: true).copyWith(
        colorScheme: ColorScheme.fromSeed(
          seedColor: Colors.blue,
          brightness: Brightness.dark,
        ),
      ),
      home: const FaustExampleHome(),
    );
  }
}

class FaustExampleHome extends StatefulWidget {
  const FaustExampleHome({super.key});

  @override
  State<FaustExampleHome> createState() => _FaustExampleHomeState();
}

class _FaustExampleHomeState extends State<FaustExampleHome> {
  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 6,
      child: Scaffold(
        appBar: AppBar(
          title: const Text('Faust Classical Suite'),
          bottom: const TabBar(
            isScrollable: true,
            tabs: [
              Tab(icon: Icon(Icons.air), text: "Flute"),
              Tab(icon: Icon(Icons.blur_circular), text: "Bowl"),
              Tab(icon: Icon(Icons.circle), text: "Dayan"),
              Tab(icon: Icon(Icons.lens), text: "Bayan"),
              Tab(icon: Icon(Icons.music_note), text: "Sitar"),
              Tab(icon: Icon(Icons.grid_view), text: "Drums"),
            ],
          ),
        ),
        body: const TabBarView(
          children: [
            FluteSection(),
            BowlSection(),
            DayanSection(),
            BayanSection(),
            SitarSection(),
            DrumKitSection(),
          ],
        ),
      ),
    );
  }
}

// ... helper code ...

class DrumKitSection extends StatefulWidget {
  const DrumKitSection({super.key});
  @override
  State<DrumKitSection> createState() => _DrumKitSectionState();
}

class _DrumKitSectionState extends State<DrumKitSection> {
  late FaustKickInstrument _kick;
  late FaustSnareInstrument _snare;
  late FaustTomInstrument _tom;
  late FaustHiHatInstrument _hat;
  late FaustRideInstrument _ride;

  double _tomFreq = 120.0;
  double _hatOpenness = 0.2;

  @override
  void initState() {
    super.initState();
    _kick = FaustKickInstrument();
    _snare = FaustSnareInstrument();
    _tom = FaustTomInstrument();
    _hat = FaustHiHatInstrument();
    _ride = FaustRideInstrument();
  }

  @override
  void dispose() {
    _kick.dispose();
    _snare.dispose();
    _tom.dispose();
    _hat.dispose();
    _ride.dispose();
    super.dispose();
  }

  void _trigger(FaustInstrument inst, String name) async {
    final pcm = Float32List(11025); // 0.25 seconds
    if (inst is FaustHiHatInstrument) inst.setOpenness(_hatOpenness);
    if (inst is FaustTomInstrument) inst.setFrequency(_tomFreq);

    // Type-specific strike
    if (inst is FaustKickInstrument) inst.strike(1.0);
    if (inst is FaustSnareInstrument) inst.strike(1.0);
    if (inst is FaustTomInstrument) inst.strike(1.0);
    if (inst is FaustHiHatInstrument) inst.strike(0.8);
    if (inst is FaustRideInstrument) inst.strike(0.8);

    inst.render(pcm);
    final source = await SoLoud.instance.loadMem(
      '${name}_${DateTime.now().microsecondsSinceEpoch}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);
    await Future.delayed(const Duration(milliseconds: 250));
    await SoLoud.instance.disposeSource(source);
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(15),
      child: Column(
        children: [
          Expanded(
            child: GridView.count(
              crossAxisCount: 3, // 3 columns for better fit
              mainAxisSpacing: 8,
              crossAxisSpacing: 8,
              childAspectRatio: 1.2, // Make pads slightly wider/shorter
              children: [
                _pad("KICK", Colors.deepOrange, () => _trigger(_kick, "kick")),
                _pad("SNARE", Colors.blueGrey, () => _trigger(_snare, "snare")),
                _pad("TOM", Colors.blue, () => _trigger(_tom, "tom")),
                _pad(
                  "HI-HAT",
                  Colors.yellow.shade800,
                  () => _trigger(_hat, "hat"),
                ),
                _pad("RIDE", Colors.teal, () => _trigger(_ride, "ride")),
              ],
            ),
          ),
          const Divider(),
          Text(
            "Tom Tuning: ${_tomFreq.toStringAsFixed(0)} Hz",
            style: const TextStyle(fontSize: 12),
          ),
          Slider(
            value: _tomFreq,
            min: 60,
            max: 400,
            onChanged: (v) => setState(() => _tomFreq = v),
          ),
          Text(
            "Hi-Hat Openness: ${_hatOpenness.toStringAsFixed(2)}",
            style: const TextStyle(fontSize: 12),
          ),
          Slider(
            value: _hatOpenness,
            min: 0,
            max: 1.0,
            onChanged: (v) => setState(() => _hatOpenness = v),
          ),
        ],
      ),
    );
  }

  Widget _pad(String label, Color color, VoidCallback onTap) {
    return InkWell(
      onTap: onTap,
      child: Container(
        decoration: BoxDecoration(
          color: color.withOpacity(0.3),
          borderRadius: BorderRadius.circular(15),
          border: Border.all(color: color, width: 2),
        ),
        child: Center(
          child: Text(
            label,
            style: TextStyle(
              color: color,
              fontWeight: FontWeight.bold,
              fontSize: 18,
            ),
          ),
        ),
      ),
    );
  }
}

// --- Common Helpers ---

double midiToFreq(double midi) {
  return 440.0 * math.pow(2.0, (midi - 69.0) / 12.0);
}

String getNoteName(double midi) {
  const names = [
    "C",
    "C#",
    "D",
    "D#",
    "E",
    "F",
    "F#",
    "G",
    "G#",
    "A",
    "A#",
    "B",
  ];
  int imidi = midi.round();
  int octave = (imidi / 12).floor() - 1;
  return "${names[imidi % 12]}$octave";
}

Uint8List createWavFile(Float32List samples, int sampleRate) {
  final numSamples = samples.length;
  final dataSize = numSamples * 2;
  final buffer = ByteData(44 + dataSize);
  buffer.setUint32(0, 0x52494646, Endian.big);
  buffer.setUint32(4, 36 + dataSize, Endian.little);
  buffer.setUint32(8, 0x57415645, Endian.big);
  buffer.setUint32(12, 0x666D7420, Endian.big);
  buffer.setUint32(16, 16, Endian.little);
  buffer.setUint16(20, 1, Endian.little);
  buffer.setUint16(22, 1, Endian.little);
  buffer.setUint32(24, sampleRate, Endian.little);
  buffer.setUint32(28, sampleRate * 2, Endian.little);
  buffer.setUint16(32, 2, Endian.little);
  buffer.setUint16(34, 16, Endian.little);
  buffer.setUint32(36, 0x64617461, Endian.big);
  buffer.setUint32(40, dataSize, Endian.little);
  var offset = 44;
  for (var sample in samples) {
    final intSample = (sample * 32767).clamp(-32768, 32767).toInt();
    buffer.setInt16(offset, intSample, Endian.little);
    offset += 2;
  }
  return buffer.buffer.asUint8List();
}

// --- Sections ---

class FluteSection extends StatefulWidget {
  const FluteSection({super.key});
  @override
  State<FluteSection> createState() => _FluteSectionState();
}

class _FluteSectionState extends State<FluteSection> {
  late FaustFluteInstrument _inst;
  double _midi = 60.0;
  double _pressure = 0.8;
  bool _isPlaying = false;

  @override
  void initState() {
    super.initState();
    _inst = FaustFluteInstrument();
  }

  @override
  void dispose() {
    _inst.dispose();
    super.dispose();
  }

  void _play() async {
    if (_isPlaying) return;
    setState(() => _isPlaying = true);
    _inst.setFrequency(midiToFreq(_midi));
    _inst.setPressure(_pressure);
    final pcm = Float32List(22050);
    _inst.render(pcm);
    final source = await SoLoud.instance.loadMem(
      'flute_${DateTime.now()}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);
    await Future.delayed(const Duration(milliseconds: 600));
    await SoLoud.instance.disposeSource(source);
    if (mounted) setState(() => _isPlaying = false);
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(30),
      child: Column(
        children: [
          Text(
            "Note: ${getNoteName(_midi)}",
            style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          ),
          Slider(
            value: _midi,
            min: 36,
            max: 84,
            onChanged: (v) => setState(() => _midi = v),
          ),
          Text("Pressure: ${_pressure.toStringAsFixed(2)}"),
          Slider(
            value: _pressure,
            min: 0,
            max: 1.2,
            onChanged: (v) => setState(() => _pressure = v),
          ),
          const Spacer(),
          SizedBox(
            width: double.infinity,
            height: 80,
            child: ElevatedButton.icon(
              onPressed: _isPlaying ? null : _play,
              icon: const Icon(Icons.air),
              label: const Text("Blow Flute"),
            ),
          ),
        ],
      ),
    );
  }
}

class BowlSection extends StatefulWidget {
  const BowlSection({super.key});
  @override
  State<BowlSection> createState() => _BowlSectionState();
}

class _BowlSectionState extends State<BowlSection> {
  late FaustBowlInstrument _inst;
  double _midi = 48.0;
  double _rub = 0.0;
  double _waver = 0.002;
  bool _isPlaying = false;

  @override
  void initState() {
    super.initState();
    _inst = FaustBowlInstrument();
  }

  @override
  void dispose() {
    _inst.dispose();
    super.dispose();
  }

  void _strike() async {
    if (_isPlaying) return;
    setState(() => _isPlaying = true);
    _inst.setFrequency(midiToFreq(_midi));
    _inst.setRub(_rub);
    _inst.setWaver(_waver);
    _inst.strike(0.8);

    final pcm = Float32List(44100 * 5);
    _inst.render(pcm);

    final source = await SoLoud.instance.loadMem(
      'bowl_${DateTime.now().microsecondsSinceEpoch}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);

    await Future.delayed(const Duration(seconds: 5));
    await SoLoud.instance.disposeSource(source);
    if (mounted) setState(() => _isPlaying = false);
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(30),
      child: Column(
        children: [
          Text(
            "Note: ${getNoteName(_midi)}",
            style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          ),
          Slider(
            value: _midi,
            min: 36,
            max: 72,
            onChanged: (v) => setState(() => _midi = v),
          ),
          const SizedBox(height: 20),
          Text("Sustain (Rub) Intensity: ${_rub.toStringAsFixed(2)}"),
          Slider(
            value: _rub,
            min: 0,
            max: 1.0,
            onChanged: (v) {
              setState(() => _rub = v);
              _inst.setRub(v);
            },
          ),
          const SizedBox(height: 20),
          Text("Waver (Beating): ${(_waver * 100).toStringAsFixed(2)}%"),
          Slider(
            value: _waver,
            min: 0.0,
            max: 0.02,
            onChanged: (v) {
              setState(() => _waver = v);
              _inst.setWaver(v);
            },
          ),
          const Spacer(),
          SizedBox(
            width: double.infinity,
            height: 80,
            child: ElevatedButton.icon(
              onPressed: _isPlaying ? null : _strike,
              icon: const Icon(Icons.gavel),
              label: const Text("Strike & Sustain"),
            ),
          ),
        ],
      ),
    );
  }
}

class DayanSection extends StatefulWidget {
  const DayanSection({super.key});
  @override
  State<DayanSection> createState() => _DayanSectionState();
}

class _DayanSectionState extends State<DayanSection> {
  late FaustDayanInstrument _inst;
  double _midi = 62.0; // D
  bool _isPlaying = false;

  @override
  void initState() {
    super.initState();
    _inst = FaustDayanInstrument();
  }

  @override
  void dispose() {
    _inst.dispose();
    super.dispose();
  }

  void _strike() async {
    if (_isPlaying) return;
    setState(() => _isPlaying = true);
    _inst.setFrequency(midiToFreq(_midi));
    _inst.strike(0.9);
    final pcm = Float32List(22050);
    _inst.render(pcm);
    final source = await SoLoud.instance.loadMem(
      'dayan_${DateTime.now()}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);
    await Future.delayed(const Duration(milliseconds: 500));
    await SoLoud.instance.disposeSource(source);
    if (mounted) setState(() => _isPlaying = false);
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(30),
      child: Column(
        children: [
          Text(
            "Note: ${getNoteName(_midi)}",
            style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          ),
          Slider(
            value: _midi,
            min: 48,
            max: 72,
            onChanged: (v) => setState(() => _midi = v),
          ),
          const Spacer(),
          SizedBox(
            width: double.infinity,
            height: 80,
            child: ElevatedButton.icon(
              onPressed: _isPlaying ? null : _strike,
              icon: const Icon(Icons.circle),
              label: const Text("Strike Dayan"),
            ),
          ),
        ],
      ),
    );
  }
}

class BayanSection extends StatefulWidget {
  const BayanSection({super.key});
  @override
  State<BayanSection> createState() => _BayanSectionState();
}

class _BayanSectionState extends State<BayanSection> {
  late FaustBayanInstrument _inst;
  double _meend = 1.0;
  bool _isPlaying = false;

  @override
  void initState() {
    super.initState();
    _inst = FaustBayanInstrument();
  }

  @override
  void dispose() {
    _inst.dispose();
    super.dispose();
  }

  void _strike() async {
    if (_isPlaying) return;
    setState(() => _isPlaying = true);
    _inst.setFrequency(110.0);
    _inst.setMeend(_meend);
    _inst.strike(1.0);
    final pcm = Float32List(44100);
    _inst.render(pcm);
    final source = await SoLoud.instance.loadMem(
      'bayan_${DateTime.now()}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);
    await Future.delayed(const Duration(milliseconds: 1000));
    await SoLoud.instance.disposeSource(source);
    if (mounted) setState(() => _isPlaying = false);
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(30),
      child: Column(
        children: [
          const Text(
            "Bayan (Bass Drum)",
            style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          ),
          const SizedBox(height: 40),
          Text("Meend (Slide): ${_meend.toStringAsFixed(2)}x"),
          Slider(
            value: _meend,
            min: 1.0,
            max: 2.5,
            onChanged: (v) => setState(() {
              _meend = v;
              _inst.setMeend(v);
            }),
          ),
          const Spacer(),
          SizedBox(
            width: double.infinity,
            height: 80,
            child: ElevatedButton.icon(
              onPressed: _isPlaying ? null : _strike,
              icon: const Icon(Icons.lens),
              label: const Text("Strike Bayan"),
            ),
          ),
        ],
      ),
    );
  }
}

class SitarSection extends StatefulWidget {
  const SitarSection({super.key});
  @override
  State<SitarSection> createState() => _SitarSectionState();
}

class _SitarSectionState extends State<SitarSection> {
  late FaustSitarInstrument _inst;
  double _midi = 50.0; // D3
  double _jivari = 0.5;
  bool _isPlaying = false;

  @override
  void initState() {
    super.initState();
    _inst = FaustSitarInstrument();
  }

  @override
  void dispose() {
    _inst.dispose();
    super.dispose();
  }

  void _pluck() async {
    if (_isPlaying) return;
    setState(() => _isPlaying = true);
    _inst.setFrequency(midiToFreq(_midi));
    _inst.setJivari(_jivari);
    _inst.pluck(0.8);
    final pcm = Float32List(44100 * 2);
    _inst.render(pcm);

    // Debug: Check if PCM has sound
    double maxAmp = 0;
    for (var s in pcm) {
      if (s.abs() > maxAmp) maxAmp = s.abs();
    }
    debugPrint('Sitar Render - Max Amplitude: $maxAmp');

    final source = await SoLoud.instance.loadMem(
      'sitar_${DateTime.now().microsecondsSinceEpoch}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);
    await Future.delayed(const Duration(seconds: 2));
    await SoLoud.instance.disposeSource(source);
    if (mounted) setState(() => _isPlaying = false);
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(30),
      child: Column(
        children: [
          Text(
            "Note: ${getNoteName(_midi)}",
            style: const TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          ),
          Slider(
            value: _midi,
            min: 36,
            max: 72,
            onChanged: (v) => setState(() => _midi = v),
          ),
          Text("Jivari (Buzz): ${_jivari.toStringAsFixed(2)}"),
          Slider(
            value: _jivari,
            min: 0,
            max: 1,
            onChanged: (v) => setState(() => _jivari = v),
          ),
          const Spacer(),
          SizedBox(
            width: double.infinity,
            height: 80,
            child: ElevatedButton.icon(
              onPressed: _isPlaying ? null : _pluck,
              icon: const Icon(Icons.music_note),
              label: const Text("Pluck Sitar"),
            ),
          ),
        ],
      ),
    );
  }
}
