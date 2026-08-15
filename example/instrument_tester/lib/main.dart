/*
 * Copyright (c) 2026 Shashank Khare
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

import 'dart:io';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:path_provider/path_provider.dart';
import 'package:faust_min/faust_min.dart';

import 'ui/generic_instrument_panel.dart';

const Map<String, String> _songAssets = {
  'yaman': 'assets/songs/yaman/yaman.usq',
  'hamsadhwani': 'assets/songs/hamsadhwani/hamsadhwani.usq',
};

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await FaustEngine.init();
  FaustMixer.instance.init(48000);
  FaustMixer.instance.start();
  await _copySongAssets();
  runApp(const MyApp());
}

Future<void> _copySongAssets() async {
  final appDir = await getApplicationDocumentsDirectory();
  for (final entry in _songAssets.entries) {
    final songDir = Directory('${appDir.path}/${entry.key}');
    if (!await songDir.exists()) {
      await songDir.create(recursive: true);
    }
    final destFile = File('${songDir.path}/${entry.key}.usq');
    if (!await destFile.exists()) {
      final data = await rootBundle.load(entry.value);
      await destFile.writeAsBytes(
        data.buffer.asUint8List(data.offsetInBytes, data.lengthInBytes),
      );
    }
  }
}

class _SongSequenceInfo {
  final String name;
  final int instrumentId;
  final String umlData;
  _SongSequenceInfo(this.name, this.instrumentId, this.umlData);
}

Future<List<_SongSequenceInfo>> _parseSongUsq(String filePath) async {
  final content = await File(filePath).readAsString();
  final sections = <_SongSequenceInfo>[];
  final filename = Platform.pathSeparator +
      Uri.file(filePath).pathSegments.last.replaceAll('.usq', '');

  final lines = content.split('\n');
  String currentBlock = '';
  bool inNotes = false;
  int subIdx = 0;

  for (final line in lines) {
    final trimmed = line.trim();
    final isParam = trimmed.isNotEmpty && !trimmed.startsWith('//') && trimmed.contains(':');

    if (isParam && inNotes) {
      final info = _extractSequenceFromBlock(currentBlock, filename, subIdx);
      if (info != null) sections.add(info);
      subIdx++;
      currentBlock = '';
      inNotes = false;
    }

    if (!isParam && trimmed.isNotEmpty) {
      inNotes = true;
    }

    currentBlock += line + '\n';
  }

  if (currentBlock.trim().isNotEmpty) {
    final info = _extractSequenceFromBlock(currentBlock, filename, subIdx);
    if (info != null) sections.add(info);
  }

  return sections;
}

_SongSequenceInfo? _extractSequenceFromBlock(String block, String filename, int subIdx) {
  String instrument = '';
  for (final line in block.split('\n')) {
    final t = line.trim().toLowerCase();
    if (t.startsWith('instrument:') || t.startsWith('instrument=')) {
      instrument = line.trim().split(RegExp(r'[:=]'))[1].trim();
      break;
    }
  }
  if (instrument.isEmpty) return null;

  final id = InstrumentMapper.getId(instrument);
  if (id < 0) {
    debugPrint("Unknown instrument '$instrument', skipping");
    return null;
  }

  final name = '${filename}_$subIdx';
  return _SongSequenceInfo(name, id, block);
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'UMPL Universal Studio',
      theme: ThemeData.dark().copyWith(
        primaryColor: Colors.amber,
      ),
      home: const FaustInstrumentsHome(),
    );
  }
}

class FaustInstrumentsHome extends StatefulWidget {
  const FaustInstrumentsHome({super.key});
  @override
  State<FaustInstrumentsHome> createState() => _FaustInstrumentsHomeState();
}

class _FaustInstrumentsHomeState extends State<FaustInstrumentsHome> {
  String _status = "Ready";
  int _selectedTab = 0;

  InstrumentDef? _activeInstrument;
  String? _selectedCategory;

  SequenceOrchestrator? _orchestratorSession;
  final List<UMLSequence> _activeSequences = [];

  List<String> get _categories =>
      allInstruments.map((i) => i.category).toSet().toList()..sort();

  List<InstrumentDef> get _filteredInstruments {
    if (_selectedCategory == null) return allInstruments;
    return allInstruments.where((i) => i.category == _selectedCategory).toList();
  }

  @override
  void initState() {
    super.initState();
    _activeInstrument = allInstruments[0];
  }

  final List<String> _patterns = [
    "Song: Yaman",
    "Song: Hamsadhwani",
    "Tanpura Drone",
    "Varanasi Dawn",
    "Dayan Strokes",
    "Bayan Strokes",
    "22 Shrutis Test",
  ];

  Future<void> _playPattern(String genre) async {
    setState(() {
      _status = "Streaming $genre...";
    });

    try {
      _stopAll();
      _orchestratorSession = SequenceOrchestrator();

      final appDir = await getApplicationDocumentsDirectory();

      if (genre == "Song: Yaman" || genre == "Song: Hamsadhwani") {
        FaustMixer.instance.clearAll();
        final songName = genre == "Song: Yaman" ? "yaman" : "hamsadhwani";
        final songDir = '${appDir.path}/$songName';
        final usqFile = '$songDir/$songName.usq';

        final sections = await _parseSongUsq(usqFile);
        for (final s in sections) {
          final seq = UMLSequence(s.name, s.instrumentId, s.umlData);
          _activeSequences.add(seq);
          _orchestratorSession!.addSequence(s.name, seq);
          _orchestratorSession!.play(s.name);
          FaustMixer.instance.registerInstrument(seq.getFaustInstrument(), 1.0);
        }
      } else if (genre == "Tanpura Drone") {
        final String uml = """
notation: Indian
instrument: TA
bpm: 60
grid: 4
basefreq: 130.81

9Sa....................................................................................................
""";
        final seq = UMLSequence("tanpura_solo", 11, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("tanpura_solo", seq);
        _orchestratorSession!.play("tanpura_solo");
        final inst = seq.getFaustInstrument();
        inst.setParameter("decay", 8.0);
        FaustMixer.instance.registerInstrument(inst, 1.0);
      } else if (genre == "22 Shrutis Test") {
        final List<String> shrutis = [
          "Sa", "r1", "r2", "R1", "R2", "g1", "g2", "G1", "G2", "M1", "M2",
          "m1", "m2", "Pa", "d1", "d2", "D1", "D2", "n1", "n2", "N1", "N2"
        ];
        String notes = "";
        for (String s in shrutis) {
          notes += "9$s.. ";
        }

        final String uml =
            "notation: Indian\ninstrument: FL\nbpm: 120\ngrid: 4\nbasefreq: 200.0\n\n$notes";
        final seq = UMLSequence("shruti_test", 10, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("shruti_test", seq);
        _orchestratorSession!.play("shruti_test");
        FaustMixer.instance.registerInstrument(seq.getFaustInstrument(), 1.0);
      } else if (genre == "Varanasi Dawn") {
        final List<String> umplTracks = [
          'baseFreq: 261.63\nbpm: 100\ninstrument: DA\n9Sa.......9(Pa/2).......9Sa.......9(Pa/2).......\n9Sa...9Sa...9Sa.9Sa...9Sa...9Sa.9Sa...',
          'baseFreq: 130.81\nbpm: 100\ninstrument: TA\n9Sa^ .S.. .S.. .S..',
          'baseFreq: 523.25\nbpm: 100\ninstrument: FL\n9Sa.9r1^9R2.9G1.9M1.9(2*Pa).....9(2*Ma)^9(2*Pa).9G2.9R1.9Sa....'
        ];
        final List<int> instIDs = [0, 11, 10];
        for (int i = 0; i < umplTracks.length; i++) {
          final name = "vd_track_$i";
          final seq = UMLSequence(name, instIDs[i], umplTracks[i]);
          _activeSequences.add(seq);
          _orchestratorSession!.addSequence(name, seq);
          _orchestratorSession!.play(name);
          FaustMixer.instance.registerInstrument(seq.getFaustInstrument(), 1.0);
        }
      } else if (genre == "Dayan Strokes") {
        final String uml =
            "notation: Indian\ninstrument: DA\nbpm: 120\ngrid: 4\nbasefreq: 150.0\n\n9Na. 9Na. 9Tin. 9Tin. 9Tun. 9Tun. 9tk. 9tk. 9Na. 9Tin. 9Tun. .S..";
        final seq = UMLSequence("dayan_test", 0, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("dayan_test", seq);
        _orchestratorSession!.play("dayan_test");
        FaustMixer.instance.registerInstrument(seq.getFaustInstrument(), 1.0);
      } else if (genre == "Bayan Strokes") {
        final String uml =
            "notation: Indian\ninstrument: BA\nbpm: 120\ngrid: 4\nbasefreq: 110.0\n\n9Ghe. 9Ghe. 9Ka. 9Ka. 9Ghe. 9Ghe. 9Ka. 9Ka. 9Ghe. .S..";
        final seq = UMLSequence("bayan_test", 1, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("bayan_test", seq);
        _orchestratorSession!.play("bayan_test");
        FaustMixer.instance.registerInstrument(seq.getFaustInstrument(), 1.0);
      } else {
        final String uml =
            "notation: Indian\ninstrument: FL\nbpm: 120\ngrid: 4\nbasefreq: 440.0\n\n9Sa. 9Re. 9Ga. 9Ma. 9Pa. 9Dh. 9Ni. 9Sa^ .S..";
        final seq = UMLSequence("rt_scale", 10, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("rt_scale", seq);
        _orchestratorSession!.play("rt_scale");
        FaustMixer.instance.registerInstrument(seq.getFaustInstrument(), 1.0);
      }
    } catch (e) {
      debugPrint("Playback Error: $e");
    } finally {
      if (mounted) setState(() {});
    }
  }

  void _stopAll() {
    for (final seq in _activeSequences) {
      try {
        FaustMixer.instance.unregisterInstrument(seq.getFaustInstrument());
      } catch (_) {}
      seq.dispose();
    }
    _activeSequences.clear();
    _orchestratorSession?.dispose();
    _orchestratorSession = null;
    setState(() => _status = "Stopped & Released Native Instances");
  }

  Widget _buildInstrumentsTab() {
    final categories = _categories;
    final filtered = _filteredInstruments;

    return Column(
      children: [
        SizedBox(
          height: 40,
          child: ListView(
            scrollDirection: Axis.horizontal,
            padding: const EdgeInsets.symmetric(horizontal: 10),
            children: [
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 4),
                child: ChoiceChip(
                  label: const Text("All", style: TextStyle(fontSize: 12)),
                  selected: _selectedCategory == null,
                  onSelected: (_) => setState(() => _selectedCategory = null),
                ),
              ),
              for (final cat in categories)
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 4),
                  child: ChoiceChip(
                    label: Text(cat, style: const TextStyle(fontSize: 12)),
                    selected: _selectedCategory == cat,
                    onSelected: (_) =>
                        setState(() => _selectedCategory = cat),
                  ),
                ),
            ],
          ),
        ),
        SizedBox(
          height: 40,
          child: ListView(
            scrollDirection: Axis.horizontal,
            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 2),
            children: filtered
                .map((inst) => Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 3),
                      child: ChoiceChip(
                        label: Text(inst.name,
                            style: const TextStyle(fontSize: 11)),
                        selected: _activeInstrument?.id == inst.id,
                        selectedColor: inst.color.withValues(alpha: 0.4),
                        onSelected: (_) =>
                            setState(() => _activeInstrument = inst),
                      ),
                    ))
                .toList(),
          ),
        ),
        const Divider(height: 1),
        Expanded(
          child: Center(
            child: _activeInstrument != null
                ? GenericInstrumentPanel(
                    key: ValueKey(_activeInstrument!.id),
                    def: _activeInstrument!,
                  )
                : const Text("Select an instrument"),
          ),
        ),
      ],
    );
  }

  Widget _buildSongsTab() {
    return Column(
      children: [
        const SizedBox(height: 12),
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 16),
          child: Align(
            alignment: Alignment.centerLeft,
            child: Text(
              "Songs & Patterns",
              style: TextStyle(
                  color: Colors.amber[700],
                  fontSize: 16,
                  fontWeight: FontWeight.bold),
            ),
          ),
        ),
        const SizedBox(height: 8),
        Expanded(
          child: ListView(
            padding: const EdgeInsets.symmetric(horizontal: 12),
            children: [
              for (final pt in _patterns)
                Padding(
                  padding: const EdgeInsets.symmetric(vertical: 4),
                  child: SizedBox(
                    width: double.infinity,
                    child: ActionChip(
                      label: Text("Play $pt",
                          style: const TextStyle(color: Colors.amber)),
                      onPressed: () => _playPattern(pt),
                    ),
                  ),
                ),
              Padding(
                padding: const EdgeInsets.symmetric(vertical: 4),
                child: SizedBox(
                  width: double.infinity,
                  child: ActionChip(
                    label: const Text("STOP ALL",
                        style: TextStyle(color: Colors.red)),
                    onPressed: _stopAll,
                  ),
                ),
              ),
            ],
          ),
        ),
      ],
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        title: const Text("UMPL UNIVERSAL STUDIO"),
        actions: [
          Padding(
            padding: const EdgeInsets.only(right: 12),
            child: Center(
              child: Text(_status,
                  style: const TextStyle(color: Colors.amber, fontSize: 11)),
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
        child: _selectedTab == 0 ? _buildInstrumentsTab() : _buildSongsTab(),
      ),
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _selectedTab,
        onTap: (i) => setState(() => _selectedTab = i),
        backgroundColor: Colors.grey[900],
        selectedItemColor: Colors.amber,
        unselectedItemColor: Colors.grey,
        items: const [
          BottomNavigationBarItem(
            icon: Icon(Icons.piano),
            label: "Instruments",
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.music_note),
            label: "Songs",
          ),
        ],
      ),
    );
  }
}
