import 'package:flutter/material.dart';
import 'package:faust_min/faust_min.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  FaustMixer.instance.init(48000);
  FaustMixer.instance.start();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'faust_min examples',
      theme: ThemeData.dark().copyWith(
        colorScheme: const ColorScheme.dark(primary: Colors.amber),
      ),
      home: const ExamplesHome(),
    );
  }
}

class ExamplesHome extends StatefulWidget {
  const ExamplesHome({super.key});

  @override
  State<ExamplesHome> createState() => _ExamplesHomeState();
}

class _ExamplesHomeState extends State<ExamplesHome> {
  String _status = "Ready";
  SequenceOrchestrator? _orchestratorSession;
  final List<UMLSequence> _activeSequences = [];

  void _stopAll() {
    _orchestratorSession?.dispose();
    _orchestratorSession = null;
    FaustMixer.instance.clearAll();
    for (final seq in _activeSequences) {
      seq.dispose();
    }
    _activeSequences.clear();
    setState(() => _status = "Stopped & Released Native Instances");
  }

  Future<void> _playDemo(String demo) async {
    _stopAll();
    setState(() => _status = "Streaming $demo...");
    _orchestratorSession = SequenceOrchestrator();

    final orchestrator = _orchestratorSession!;
    if (demo == "Sequence 1: Sitar → Sarod") {
      await _playSitarSarod(orchestrator);
    } else if (demo == "Vivaldi Spring Ensemble") {
      await _playVivaldi(orchestrator);
    }
    setState(() => _status = "Playing $demo");
  }

  void _register(UMLSequence seq) {
    _activeSequences.add(seq);
    FaustMixer.instance.registerInstrument(seq.getFaustInstrument(), 1.0);
  }

  Future<void> _playSitarSarod(SequenceOrchestrator orch) async {
    const sitar = """
grid: 4
bpm: 60
basefreq: 222.0
instrument: sitar
notation: Hindustani
vibrato_depth: 0.008
vibrato_rate: 5.0
chikari_freq: 222.0

6Ni . 6Re . 6Ga . 6Re . 6Ga . 6ma . 6Ga . 6Re .
6Ni . 6Re . 6Ga . 6ma . 6Dha . 6Ni . 6Sa*2 . 6Re*2 .
6Sa*2 6Ni 6Dha 6Pa 6ma 6Ga 6Re 6Sa
6Ni 6Re 6Ga 6ma 6Pa 6Dha 6Ni 6Sa*2
6Sa*2 6Ni 6Dha 6Pa 6ma 6Ga 6Re 6Sa
6Ga 6Re 6Sa 6Ni 6Dha 6Pa 6ma 6Ga
6Ga 61Sa*2 6Re 61Sa*2 6Ga 61Sa*2 6ma 61Sa*2
6Pa 61Sa*2 6Dha 61Sa*2 6Ni 61Sa*2 6Sa*2 61Sa*2
6Sa*2 61Sa*2 6Ni 61Sa*2 6Dha 61Sa*2 6Pa 61Sa*2
6ma 61Sa*2 6Ga 61Sa*2 6Re 61Sa*2 6Sa 61Sa*2
""";

    const sarod = """
grid: 4
bpm: 60
basefreq: 222.0
instrument: sarod
notation: Hindustani
vibrato_depth: 0.02
vibrato_rate: 5.5
chikari_freq: 222.0

5Sa..^ 5Sa..^ 8Ni..^ 5Sa..^
8Ni..^ 8Ga..^ 8Re..^ 8Ni..~
8Ga..^ 6Dha..^ 8Ni..^ 6Dha..~
8Re..^ 8Ga..^ 8Re..^ 6Dha..^
9Ni..^ 6Sa*2..^ 9Ni..~ 6Dha..~
8Re..^ 9Ni..^ 6Sa*2..^ 8Ga..^
9Ni..^ 8Re..^ 6Dha..^ 8Ni..^
5Sa..^ 8Re..^ 8Ga..^ 8Re..~
61Sa 8Ga~ 61Sa 8Ga~ 81Ni 8Ga~ 61Sa 8Ga~
81Ni 8Ga~ 81Ga 8Re~ 81Re 8Ga~ 81Ni 8Ga~
81Ga 8Re~ 61Dha 8Ni~ 81Ni 8Ga~ 61Dha 8Ni~
81Re 8Ga~ 81Ga 8Re~ 81Re 8Ga~ 61Dha 8Ni~
5Sa . . . . . . .
""";

    final String dayan = _tablaDayan();
    final String bayan = _tablaBayan();

    final sitarSeq = UMLSequence("sitar_seq", 9, sitar);
    orch.addSequence("sitar_seq", sitarSeq);
    orch.play("sitar_seq");
    _register(sitarSeq);

    final sarodSeq = UMLSequence("sarod_seq", 44, sarod);
    orch.addSequence("sarod_seq", sarodSeq);
    orch.play("sarod_seq");
    _register(sarodSeq);

    final dayanSeq = UMLSequence("dayan_seq", 0, dayan);
    orch.addSequence("dayan_seq", dayanSeq);
    orch.play("dayan_seq");
    _register(dayanSeq);

    final bayanSeq = UMLSequence("bayan_seq", 1, bayan);
    orch.addSequence("bayan_seq", bayanSeq);
    orch.play("bayan_seq");
    _register(bayanSeq);
  }

  String _tablaDayan() {
    final b = StringBuffer("grid: 4\nbpm: 60\nbasefreq: 222.0\ninstrument: dayan\n\n");
    const alaap = "Na... Tin... Tun... tk... Na... Tin... Na... tk... ";
    const med = "Na. Tin. Tun. tk. Na. Tin. Na. tk. ";
    const jhala = "Na Tin Tun tk Na Tin Na tk ";
    for (var i = 0; i < 2; i++) {
      b.write(alaap);
    }
    for (var i = 0; i < 4; i++) {
      b.write(med);
    }
    for (var i = 0; i < 8; i++) {
      b.write(jhala);
    }
    return b.toString();
  }

  String _tablaBayan() {
    final b = StringBuffer("grid: 4\nbpm: 60\nbasefreq: 55.0\ninstrument: bayan\n\n");
    const alaap = "Ghe... _... _... Ka... _... Ka... Ghe... _... ";
    const med = "Ghe. _. _. Ka. _. Ka. Ghe. _. ";
    const jhala = "Ghe _ _ Ka _ Ka Ghe _ ";
    for (var i = 0; i < 2; i++) {
      b.write(alaap);
    }
    for (var i = 0; i < 4; i++) {
      b.write(med);
    }
    for (var i = 0; i < 8; i++) {
      b.write(jhala);
    }
    return b.toString();
  }

  Future<void> _playVivaldi(SequenceOrchestrator orch) async {
    const violinM = """
grid: 4
bpm: 100
instrument: violin
notation: Western
loop: false

5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4...
5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4...
6B4. 6C#5. 6B4. 6A4. 5G#4. 4F#4. 3E4 2E4 1E4 0E4
""";

    const bass = """
grid: 4
bpm: 100
instrument: cello
notation: Western
loop: false

5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2...
5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2...
5E2. 5A1. 5E2. 5B1. 5E2. 5B1. 5E2...
5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2...
5E2. 5E2. 5E2. 5E2. 5B1. 5B1. 5E2...
5E2. 5A1. 5E2. 5B1. 5E2. 5B1. 5E2...
""";

    const flute = """
grid: 4
bpm: 100
instrument: flute
notation: Western
loop: false

5E5. 5G#5. 5G#5. 5G#5. 5F#5. 5E5. 6B5...
5E5. 5G#5. 5G#5. 5G#5. 5F#5. 5E5. 6B5...
6B5. 6C#6. 6B5. 6A5. 5G#5. 4F#5. 3E5 2E5 1E5 0E5
""";

    const timpani = """
grid: 4
bpm: 100
instrument: tom
notation: Western
loop: false

5E2... 5E2... 5E2... 5E2... 5B1... 5B1... 5E2...
5E2... 5E2... 5E2... 5E2... 5B1... 5B1... 5E2...
5E2... 5A1... 5E2... 5B1... 5E2... 5B1... 5E2...
""";

    const piano = """
delay: 48
grid: 4
bpm: 100
instrument: piano
notation: Western
loop: false

5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4...
5E4. 5G#4. 5G#4. 5G#4. 5F#4. 5E4. 6B4...
6B4. 6C#5. 6B4. 6A4. 6G#4. 6F#4. 6E4...
""";

    String withHumanization(String uml, int instanceNum) {
      final delay = (instanceNum - 1) * 0.015;
      final vibRate = 4.5 + (instanceNum * 0.15);
      return "delay: $delay\nvibrato_rate: $vibRate\nvibrato_depth: 0.03\n$uml";
    }

    void add(String name, int instrumentId, String uml) {
      final seq = UMLSequence(name, instrumentId, uml);
      orch.addSequence(name, seq);
      orch.play(name);
      _register(seq);
    }

    for (var i = 1; i <= 5; i++) {
      add("ViolinM$i", 18, withHumanization(violinM, i));
    }
    for (var i = 1; i <= 4; i++) {
      add("Cello$i", 24, withHumanization(bass, i));
    }
    for (var i = 1; i <= 3; i++) {
      add("Flute$i", 10, withHumanization(flute, i));
    }
    for (var i = 1; i <= 2; i++) {
      add("Timpani$i", 5, withHumanization(timpani, i));
    }
    for (var i = 1; i <= 2; i++) {
      add("Piano$i", 12, withHumanization(piano, i));
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        title: const Text("FAUST_MIN EXAMPLES"),
        actions: [
          Padding(
            padding: const EdgeInsets.only(right: 12),
            child: Center(
              child: Text(
                _status,
                style: const TextStyle(color: Colors.amber, fontSize: 11),
              ),
            ),
          ),
        ],
      ),
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topCenter,
            end: Alignment.bottomCenter,
            colors: [Colors.black, Colors.grey[900]!],
          ),
        ),
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            const Text(
              "Playback examples using the native UML sequencer and mixer.",
              style: TextStyle(color: Colors.white70),
            ),
            const SizedBox(height: 16),
            _demoCard(
              "Sequence 1: Sitar → Sarod",
              "Same Sa-Re-Ga-Pa melody — sitar first, then sarod layered "
                  "with chikari drone strings.",
              () => _playDemo("Sequence 1: Sitar → Sarod"),
            ),
            const SizedBox(height: 12),
            _demoCard(
              "Vivaldi Spring Ensemble",
              "16-instrument ensemble — violins, cellos, flutes, timpani and "
                  "piano playing 'La Primavera' (Spring) from Vivaldi.",
              () => _playDemo("Vivaldi Spring Ensemble"),
            ),
            const SizedBox(height: 16),
            OutlinedButton.icon(
              onPressed: _stopAll,
              icon: const Icon(Icons.stop, color: Colors.red),
              label: const Text("STOP ALL",
                  style: TextStyle(color: Colors.red)),
            ),
          ],
        ),
      ),
    );
  }

  Widget _demoCard(String title, String subtitle, VoidCallback onPressed) {
    return Card(
      color: Colors.grey[900],
      child: ListTile(
        title: Text(title,
            style: const TextStyle(color: Colors.amber, fontSize: 16)),
        subtitle: Text(subtitle, style: const TextStyle(color: Colors.white70)),
        trailing: const Icon(Icons.play_circle, color: Colors.amber, size: 32),
        onTap: onPressed,
      ),
    );
  }
}
