import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:typed_data';
import 'dart:math' as math;

import 'dart:ffi';
import 'package:ffi/ffi.dart';
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
      length: 9,
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
              Tab(icon: Icon(Icons.line_weight), text: "Tanpura"),
              Tab(icon: Icon(Icons.grid_view), text: "Drums"),
              Tab(icon: Icon(Icons.notifications), text: "Bell"),
              Tab(icon: Icon(Icons.playlist_play), text: "Patterns"),
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
            TanpuraSection(),
            DrumKitSection(),
            BellSection(),
            SequencerSection(),
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

Uint8List createWavFile(Float32List samples, int sampleRate, {int channels = 1}) {
  final dataSize = samples.length * 2;
  final buffer = ByteData(44 + dataSize);
  buffer.setUint32(0, 0x52494646, Endian.big);
  buffer.setUint32(4, 36 + dataSize, Endian.little);
  buffer.setUint32(8, 0x57415645, Endian.big);
  buffer.setUint32(12, 0x666D7420, Endian.big);
  buffer.setUint32(16, 16, Endian.little);
  buffer.setUint16(20, 1, Endian.little);
  buffer.setUint16(22, channels, Endian.little);
  buffer.setUint32(24, sampleRate, Endian.little);
  buffer.setUint32(28, sampleRate * 2 * channels, Endian.little);
  buffer.setUint16(32, 2 * channels, Endian.little);
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
  double _duration = 6.0;
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
    _inst.setDuration(_duration);
    _inst.setRub(_rub);
    _inst.setWaver(_waver);
    _inst.strike(1.0);

    final pcm = Float32List(44100 * (_duration + 1).toInt());
    _inst.render(pcm);

    final source = await SoLoud.instance.loadMem(
      'bowl_${DateTime.now().microsecondsSinceEpoch}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);

    await Future.delayed(Duration(seconds: _duration.toInt()));
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
          const SizedBox(height: 20),
          Text("Ring Length: ${_duration.toStringAsFixed(1)}s"),
          Slider(
            value: _duration,
            min: 1.0,
            max: 15.0,
            onChanged: (v) => setState(() => _duration = v),
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

class TanpuraSection extends StatefulWidget {
  const TanpuraSection({super.key});
  @override
  State<TanpuraSection> createState() => _TanpuraSectionState();
}

class _TanpuraSectionState extends State<TanpuraSection> {
  late FaustTanpuraInstrument _inst;
  double _f1 = 196.00; // Pa (G3)
  double _f2 = 261.63; // Sa (C4)
  double _f3 = 261.63; // Sa (C4)
  double _f4 = 130.81; // Low Sa (C3)
  double _decay = 6.0;
  double _delay = 0.7;
  double _jivari = 0.85;
  bool _isPlaying = false;

  @override
  void initState() {
    super.initState();
    _inst = FaustTanpuraInstrument();
  }

  @override
  void dispose() {
    _inst.dispose();
    super.dispose();
  }

  void _playContinuousLoop() async {
    if (_isPlaying) return;
    setState(() => _isPlaying = true);
    
    _inst.setParams(_f1, _f2, _f3, _f4, _decay, _delay);
    _inst.setJivari(_jivari);
    _inst.setPlaying(true);

    // We will render 8 seconds of continuous playing
    int totalSamples = 44100 * 8;
    final pcm = Float32List(totalSamples);
    
    // The native Faust engine handles the loop sequencing internally!
    _inst.render(pcm);

    final source = await SoLoud.instance.loadMem(
      'tanpura_loop_${DateTime.now().microsecondsSinceEpoch}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);
    await Future.delayed(const Duration(seconds: 8));
    await SoLoud.instance.disposeSource(source);
    
    _inst.setPlaying(false);
    if (mounted) setState(() => _isPlaying = false);
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(30),
      child: Column(
        children: [
          const Text(
            "Tanpura (Continuous Drone)",
            style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          ),
          const SizedBox(height: 10),
          Expanded(
            child: ListView(
              children: [
                _buildSlider("String 1 Freq", _f1, 98.0, 523.0, (v) => setState(() => _f1 = v)),
                _buildSlider("String 2 Freq", _f2, 98.0, 523.0, (v) => setState(() => _f2 = v)),
                _buildSlider("String 3 Freq", _f3, 98.0, 523.0, (v) => setState(() => _f3 = v)),
                _buildSlider("String 4 Freq", _f4, 98.0, 523.0, (v) => setState(() => _f4 = v)),
                _buildSlider("Decay (t60) sec", _decay, 1.0, 15.0, (v) => setState(() => _decay = v)),
                _buildSlider("Delay (sec)", _delay, 0.2, 2.0, (v) => setState(() => _delay = v)),
                _buildSlider("Jivari (Buzz)", _jivari, 0.0, 1.0, (v) => setState(() => _jivari = v)),
              ],
            ),
          ),
          SizedBox(
            width: double.infinity,
            height: 80,
            child: ElevatedButton.icon(
              onPressed: _isPlaying ? null : _playContinuousLoop,
              icon: const Icon(Icons.loop),
              label: const Text("Play 8s Loop"),
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildSlider(String label, double val, double min, double max, Function(double) onChanged) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text("$label: ${val.toStringAsFixed(2)}"),
        Slider(value: val, min: min, max: max, onChanged: onChanged),
      ],
    );
  }
}
class SequencerSection extends StatefulWidget {
  const SequencerSection({super.key});

  @override
  State<SequencerSection> createState() => _SequencerSectionState();
}

class _SequencerSectionState extends State<SequencerSection> {
  bool _isPlaying = false;
  String _status = "Ready to Mix";
  double _track1Volume = 0.8; // Tabla
  double _track2Volume = 0.8; // Flute
  double _track3Volume = 0.6; // Tanpura
  // Syncopated Classical Tabla Pattern from Slumber App
  // Original: "D n t . G k . n D g n . T . n t"
  // Mapped: D(Dha) N(Na) T(Tin) I(Ge) e(Ke) N(Na) D(Dha) I(Ge) N(Na) I(Tun) N(Na) T(Tin)
  // Classic Teental-style pattern for testing
  final String _tablaSeq = 
      "D.N.T.I.D.N.T.I"
      "D.N.T.I.D.N.T.I"
      "D.N.T.I.D.N.T.I"
      "D.N.T.I.D.N.T.I";
  final String _fluteSeq = "E...........F.......E...F...A...B...G.......D.......C...E...D...";
  final String _tanpuraSeq = "1234123412341234123412341234123412341234123412341234123412341234";

  double _calculateOptimalPressure(double freq) {
    // Dynamic compensation: Higher frequencies require more blowing pressure
    // to oscillate effectively in shorter virtual air columns.
    const double minFreq = 440.0;
    const double maxFreq = 1100.0;
    const double minP = 0.78;
    const double maxP = 0.96;
    
    double t = (freq - minFreq) / (maxFreq - minFreq);
    t = t.clamp(0.0, 1.0);
    return minP + (maxP - minP) * t;
  }

  Future<void> _playPattern() async {
    if (_isPlaying) return;
    setState(() {
      _isPlaying = true;
      _status = "Rendering tracks & mixing...";
    });

    try {
      const double sampleRate = 44100.0;
      const double tempoBpm = 100.0;
      const double durationSec = 10.0;
      final int totalSamples = (durationSec * sampleRate).toInt();

      final double secondsPerBeat = 60.0 / tempoBpm;
      final double secondsPerStep = secondsPerBeat / 4.0;
      final int samplesPerStep = (secondsPerStep * sampleRate).floor();

      final List<FaustEventData> track1Events = []; // Tabla (Dayan 0, Bayan 1)
      final List<FaustEventData> track2Events = []; // Flute (10)
      final List<FaustEventData> track3Events = []; // Tanpura (11)

      // --- Parse Track 1 (Tabla) ---
      final double bayanFreq = 110.0;
      final double dayanFreq = 220.0;
      
      track1Events.add(FaustEventData(sampleOffset: 0, instrumentId: 0, eventType: 1, value: dayanFreq));
      track1Events.add(FaustEventData(sampleOffset: 0, instrumentId: 1, eventType: 1, value: bayanFreq));

      for (int i = 0; i < _tablaSeq.length; i++) {
        int offset = i * samplesPerStep;
        String s = _tablaSeq[i];
        if (s == '.') continue;
        
        if (s == 'D') { 
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 2, paramId: 0, value: 0.0));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 1, value: dayanFreq));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 0, value: 0.9));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 1, eventType: 2, paramId: 0, value: 0.0));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 1, eventType: 2, paramId: 1, value: 1.0));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 1, eventType: 0, value: 1.0));
           track1Events.add(FaustEventData(sampleOffset: offset + 5000, instrumentId: 1, eventType: 2, paramId: 1, value: 1.2));
        } else if (s == 'I') {
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 2, paramId: 0, value: 0.0));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 1, value: dayanFreq * 0.95)); // Tun slightly lower
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 0, value: 0.7));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 1, eventType: 2, paramId: 0, value: 0.0));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 1, eventType: 2, paramId: 1, value: 1.3));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 1, eventType: 0, value: 0.8));
        } else if (s == 'N') {
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 2, paramId: 0, value: 0.0));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 1, value: dayanFreq));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 0, value: 1.0));
        } else if (s == 'T') {
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 2, paramId: 0, value: 0.0));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 1, value: dayanFreq * 0.95));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 0, value: 0.6));
        } else if (s == 'e') {
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 2, paramId: 0, value: 1.0)); // Dayan Muted
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 1, value: dayanFreq));
           track1Events.add(FaustEventData(sampleOffset: offset, instrumentId: 0, eventType: 0, value: 0.7));
        }
      }

      // --- Parse Track 2 (Flute) ---
      bool isBlowing = false;
      for (int i = 0; i < _fluteSeq.length; i++) {
        int offset = i * samplesPerStep;
        String s = _fluteSeq[i];
        
        if (s == '-') {
          if (isBlowing) {
             track2Events.add(FaustEventData(sampleOffset: offset, instrumentId: 10, eventType: 2, paramId: 0, value: 0.0)); // Stop pressure
             isBlowing = false;
          }
        } else if (s != '.') {
          double freq = 523.25;
          if (s == 'B') freq = 493.88; // B4 (Ni)
          if (s == 'C') freq = 523.25; // C5 (Sa)
          if (s == 'D') freq = 587.33; // D5 (Re)
          if (s == 'E') freq = 659.25; // E5 (Ga)
          if (s == 'F') freq = 739.99; // F#5 (Teevra Ma for Yaman)
          if (s == 'G') freq = 783.99; // G5 (Pa)
          if (s == 'A') freq = 880.00; // A5 (Dha)
          if (s == 'c') freq = 1046.50; // C6 (Sa upper)
          
          if (!isBlowing) {
             double p = _calculateOptimalPressure(freq);
             // Tongue the first note of a phrase with dynamic pressure
             track2Events.add(FaustEventData(sampleOffset: offset, instrumentId: 10, eventType: 2, paramId: 0, value: (p + 0.1).clamp(0.0, 1.0))); // Peak Attack
             track2Events.add(FaustEventData(sampleOffset: offset + 1500, instrumentId: 10, eventType: 2, paramId: 0, value: p)); // Dynamic Sustain
             track2Events.add(FaustEventData(sampleOffset: offset + 1500, instrumentId: 10, eventType: 2, paramId: 1, value: 0.03)); // Subtle Vibrato
             isBlowing = true;
          }
          
          track2Events.add(FaustEventData(sampleOffset: offset, instrumentId: 10, eventType: 1, value: freq)); // Slur to new frequency
        }
      }
      track2Events.add(FaustEventData(sampleOffset: totalSamples - 100, instrumentId: 10, eventType: 2, paramId: 0, value: 0.0)); // Ensure stop

      // --- Track 3: Tanpura (Instrument 11) ---
      track3Events.add(FaustEventData(sampleOffset: 0, instrumentId: 11, eventType: 1, paramId: 0, value: 196.00)); // G3
      track3Events.add(FaustEventData(sampleOffset: 0, instrumentId: 11, eventType: 1, paramId: 1, value: 261.63)); // C4
      track3Events.add(FaustEventData(sampleOffset: 0, instrumentId: 11, eventType: 1, paramId: 2, value: 261.63)); // C4
      track3Events.add(FaustEventData(sampleOffset: 0, instrumentId: 11, eventType: 1, paramId: 3, value: 130.81)); // C3
      track3Events.add(FaustEventData(sampleOffset: 0, instrumentId: 11, eventType: 2, paramId: 10, value: 0.85)); // Jivari

      for (int i = 0; i < _tanpuraSeq.length; i++) {
        int offset = i * samplesPerStep;
        String s = _tanpuraSeq[i];
        if (s != '.') {
           int sIdx = int.tryParse(s) ?? 1;
           track3Events.add(FaustEventData(sampleOffset: offset, instrumentId: 11, eventType: 0, value: (sIdx - 1).toDouble()));
        }
      }

      track1Events.sort((a, b) => a.sampleOffset.compareTo(b.sampleOffset));
      track2Events.sort((a, b) => a.sampleOffset.compareTo(b.sampleOffset));
      track3Events.sort((a, b) => a.sampleOffset.compareTo(b.sampleOffset));

      // --- Render Tracks ---
      final Pointer<Float> track1Buf = calloc<Float>(totalSamples);
      final Pointer<Float> track2Buf = calloc<Float>(totalSamples);
      final Pointer<Float> track3Buf = calloc<Float>(totalSamples);
      
      try {
        FaustMin.renderAutomationSequence(
          events: track1Events,
          sampleRate: sampleRate,
          totalSamples: totalSamples,
          outputBuffer: track1Buf,
        );
        
        FaustMin.renderAutomationSequence(
          events: track2Events,
          sampleRate: sampleRate,
          totalSamples: totalSamples,
          outputBuffer: track2Buf,
        );

        FaustMin.renderAutomationSequence(
          events: track3Events,
          sampleRate: sampleRate,
          totalSamples: totalSamples,
          outputBuffer: track3Buf,
        );

        // --- Mix Tracks ---
        List<MixLayer> layers = [
          MixLayer(
            buffer: track1Buf.asTypedList(totalSamples),
            amplitudeScale: _track1Volume,
            pan: -0.2, // Tabla slightly left
          ),
          MixLayer(
            buffer: track2Buf.asTypedList(totalSamples),
            amplitudeScale: _track2Volume * 2.0, // Flute boosted
            pan: 0.2, // Flute slightly right
          ),
          MixLayer(
            buffer: track3Buf.asTypedList(totalSamples),
            amplitudeScale: _track3Volume,
            pan: 0.0, // Tanpura center
          ),
        ];

      final Float32List stereoMaster = Float32List(totalSamples * 2);
      
      FaustAudioDSP.mixSignals(
        layers: layers,
        stereoOutputBuffer: stereoMaster,
      );

      final source = await SoLoud.instance.loadMem(
        'mix_${DateTime.now().microsecondsSinceEpoch}',
        createWavFile(stereoMaster, 44100, channels: 2),
      );
      
      setState(() => _status = "Playing Mix...");
      await SoLoud.instance.play(source);
      await Future.delayed(const Duration(seconds: 10));
      await SoLoud.instance.disposeSource(source);
      
      } finally {
        calloc.free(track1Buf);
        calloc.free(track2Buf);
      }

    } catch (e) {
      setState(() => _status = "Error: $e");
    } finally {
      if (mounted) {
        setState(() {
          _isPlaying = false;
          _status = "Finished";
        });
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(20),
      child: Column(
        children: [
          const Icon(Icons.queue_music, size: 60, color: Colors.blue),
          const SizedBox(height: 10),
          Text("2-Track Sequence Mixer", style: Theme.of(context).textTheme.headlineMedium),
          Text(_status, style: const TextStyle(color: Colors.grey)),
          const SizedBox(height: 20),
          
          Expanded(
            child: SingleChildScrollView(
              child: Column(
                children: [
                  _trackControl("Track 1: Tabla (Dayan + Bayan)", _tablaSeq, _track1Volume, (v) => setState(() => _track1Volume = v)),
                  const Divider(height: 30),
                  _trackControl("Track 2: Flute", _fluteSeq, _track2Volume, (v) => setState(() => _track2Volume = v)),
                  const Divider(height: 30),
                  _trackControl("Track 3: Tanpura", _tanpuraSeq, _track3Volume, (v) => setState(() => _track3Volume = v)),
                ],
              ),
            ),
          ),
          

          SizedBox(
            width: double.infinity,
            height: 60,
            child: ElevatedButton.icon(
              style: ElevatedButton.styleFrom(backgroundColor: Colors.blue.withOpacity(0.3)),
              onPressed: _isPlaying ? null : _playPattern,
              icon: const Icon(Icons.play_arrow),
              label: const Text("Render & Play Mix", style: TextStyle(fontWeight: FontWeight.bold, fontSize: 18)),
            ),
          ),
        ],
      ),
    );
  }

  Widget _trackControl(String title, String seq, double vol, ValueChanged<double> onVolChanged) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(title, style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16, color: Colors.amber)),
        const SizedBox(height: 5),
        Container(
          width: double.infinity,
          padding: const EdgeInsets.all(8),
          decoration: BoxDecoration(color: Colors.black26, borderRadius: BorderRadius.circular(5)),
          child: Text(seq, style: const TextStyle(fontFamily: 'monospace', fontSize: 14, letterSpacing: 2.0)),
        ),
        Row(
          children: [
            const Icon(Icons.volume_up, size: 16),
            Expanded(
              child: Slider(value: vol, min: 0.0, max: 1.0, onChanged: onVolChanged),
            ),
            Text((vol * 10).toStringAsFixed(1)),
          ],
        ),
      ],
    );
  }
}


class BellSection extends StatefulWidget {
  const BellSection({super.key});
  @override
  State<BellSection> createState() => _BellSectionState();
}

class _BellSectionState extends State<BellSection> {
  late FaustBellInstrument _inst;
  double _midi = 67.0; // G4
  double _duration = 6.0;
  bool _isPlaying = false;

  @override
  void initState() {
    super.initState();
    _inst = FaustBellInstrument();
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
    _inst.setDuration(_duration);
    _inst.strike(1.0);
    final pcm = Float32List(44100 * (_duration + 1).toInt());
    _inst.render(pcm);

    final source = await SoLoud.instance.loadMem(
      'bell_${DateTime.now().microsecondsSinceEpoch}',
      createWavFile(pcm, 44100),
    );
    await SoLoud.instance.play(source);
    await Future.delayed(Duration(seconds: _duration.toInt()));
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
            "Meditative Bell",
            style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
          ),
          const SizedBox(height: 20),
          const Icon(Icons.notifications_active, size: 100, color: Colors.amber),
          const SizedBox(height: 20),
          Text(
            "Note: ${getNoteName(_midi)}",
            style: const TextStyle(fontSize: 18),
          ),
          Slider(
            value: _midi,
            min: 48,
            max: 84,
            onChanged: (v) => setState(() => _midi = v),
          ),
          const SizedBox(height: 20),
          Text(
            "Ring Length: ${_duration.toStringAsFixed(1)}s",
            style: const TextStyle(fontSize: 14),
          ),
          Slider(
            value: _duration,
            min: 1.0,
            max: 15.0,
            onChanged: (v) {
              setState(() => _duration = v);
              _inst.setDuration(v);
            },
          ),
          const Spacer(),
          SizedBox(
            width: double.infinity,
            height: 80,
            child: ElevatedButton.icon(
              onPressed: _isPlaying ? null : _strike,
              icon: const Icon(Icons.notifications),
              label: const Text("Strike Bell"),
              style: ElevatedButton.styleFrom(
                backgroundColor: Colors.amber.shade900,
                foregroundColor: Colors.white,
              ),
            ),
          ),
        ],
      ),
    );
  }
}
