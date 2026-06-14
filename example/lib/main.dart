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

import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'package:flutter_soloud/flutter_soloud.dart';

import 'ui/generic_instrument_panel.dart';

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
  bool _isPlayingPattern = false;
  String? _selectedCategory;
  InstrumentDef? _activeInstrument;

  @override
  void initState() {
    super.initState();
    _activeInstrument = allInstruments[0];
    Future.delayed(const Duration(seconds: 1), () {
      _playPattern("Tanpura Drone");
    });
  }

  final List<String> _patterns = ["Song: Yaman", "Song: Hamsadhwani", "Tanpura Drone", "Varanasi Dawn", "Dayan Strokes", "Bayan Strokes", "22 Shrutis Test"];

  SequenceOrchestrator? _orchestratorSession;
  final List<UMLSequence> _activeSequences = [];

  List<String> get _categories => allInstruments.map((i) => i.category).toSet().toList()..sort();

  List<InstrumentDef> get _filteredInstruments {
    if (_selectedCategory == null) return allInstruments;
    return allInstruments.where((i) => i.category == _selectedCategory).toList();
  }

  Future<void> _playPattern(String genre) async {
    setState(() {
      _isPlayingPattern = true;
      _status = "Streaming $genre...";
    });

    try {
      _stopAll();
      _orchestratorSession = SequenceOrchestrator();

      if (genre == "Song: Yaman") {
        FaustMixer.instance.clearAll();
        _orchestratorSession!.loadSong("/home/shashankkhare/AndroidStudioProjects/faust_min/assets/songs/yaman");
        _orchestratorSession!.playSong("/home/shashankkhare/AndroidStudioProjects/faust_min/assets/songs/yaman");
      } else if (genre == "Song: Hamsadhwani") {
        FaustMixer.instance.clearAll();
        _orchestratorSession!.loadSong("/home/shashankkhare/AndroidStudioProjects/faust_min/assets/songs/hamsadhwani");
        _orchestratorSession!.playSong("/home/shashankkhare/AndroidStudioProjects/faust_min/assets/songs/hamsadhwani");
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
      } else if (genre == "22 Shrutis Test") {
        final List<String> shrutis = [
          "Sa", "r1", "r2", "R1", "R2", "g1", "g2", "G1", "G2", "M1", "M2",
          "m1", "m2", "Pa", "d1", "d2", "D1", "D2", "n1", "n2", "N1", "N2"
        ];
        String notes = "";
        for (String s in shrutis) notes += "9$s.. ";

        final String uml = "notation: Indian\ninstrument: FL\nbpm: 120\ngrid: 4\nbasefreq: 200.0\n\n$notes";
        final seq = UMLSequence("shruti_test", 10, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("shruti_test", seq);
        _orchestratorSession!.play("shruti_test");
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
        }
      } else if (genre == "Dayan Strokes") {
        final String uml = "notation: Indian\ninstrument: DA\nbpm: 120\ngrid: 4\nbasefreq: 150.0\n\n9Na. 9Na. 9Tin. 9Tin. 9Tun. 9Tun. 9tk. 9tk. 9Na. 9Tin. 9Tun. .S..";
        final seq = UMLSequence("dayan_test", 0, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("dayan_test", seq);
        _orchestratorSession!.play("dayan_test");
      } else if (genre == "Bayan Strokes") {
        final String uml = "notation: Indian\ninstrument: BA\nbpm: 120\ngrid: 4\nbasefreq: 110.0\n\n9Ghe. 9Ghe. 9Ka. 9Ka. 9Ghe. 9Ghe. 9Ka. 9Ka. 9Ghe. .S..";
        final seq = UMLSequence("bayan_test", 1, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("bayan_test", seq);
        _orchestratorSession!.play("bayan_test");
      } else {
        final String uml = "notation: Indian\ninstrument: FL\nbpm: 120\ngrid: 4\nbasefreq: 440.0\n\n9Sa. 9Re. 9Ga. 9Ma. 9Pa. 9Dh. 9Ni. 9Sa^ .S..";
        final seq = UMLSequence("rt_scale", 10, uml);
        _activeSequences.add(seq);
        _orchestratorSession!.addSequence("rt_scale", seq);
        _orchestratorSession!.play("rt_scale");
      }
    } catch (e) {
      debugPrint("Playback Error: $e");
    } finally {
      if (mounted) setState(() { _isPlayingPattern = false; });
    }
  }

  void _stopAll() {
    _orchestratorSession?.dispose();
    _orchestratorSession = null;
    for (final seq in _activeSequences) {
      seq.dispose();
    }
    _activeSequences.clear();
    setState(() => _status = "Stopped & Released Native Instances");
  }

  void _onPlayData(Uint8List wav) async {
    final name = _activeInstrument?.name ?? 'inst';
    debugPrint("Rendered WAV audio buffer successfully: ${wav.length} bytes");
    try {
      final source = await SoLoud.instance.loadMem(
        '${name}_${DateTime.now().microsecondsSinceEpoch}',
        wav,
      );
      await SoLoud.instance.play(source);
      // Let it play; don't block or dispose immediately
    } catch (e) {
      debugPrint("Playback error: $e");
    }
    if (mounted) {
      setState(() {
        _status = "Playing ${wav.length} bytes for $name";
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    final categories = _categories;
    final filtered = _filteredInstruments;

    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        title: const Text("UMPL UNIVERSAL STUDIO"),
        bottom: PreferredSize(
          preferredSize: const Size.fromHeight(120),
          child: Column(
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
                          onSelected: (_) => setState(() => _selectedCategory = cat),
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
                  children: filtered.map((inst) => Padding(
                    padding: const EdgeInsets.symmetric(horizontal: 3),
                    child: ChoiceChip(
                      label: Text(inst.name, style: const TextStyle(fontSize: 11)),
                      selected: _activeInstrument?.id == inst.id,
                      selectedColor: inst.color.withOpacity(0.4),
                      onSelected: (_) => setState(() => _activeInstrument = inst),
                    ),
                  )).toList(),
                ),
              ),
              SingleChildScrollView(
                scrollDirection: Axis.horizontal,
                padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 2),
                child: Row(
                  children: _patterns.map((pt) => Padding(
                    padding: const EdgeInsets.symmetric(horizontal: 5),
                    child: ActionChip(
                      label: Text("Play $pt", style: const TextStyle(color: Colors.amber)),
                    onPressed: () => _playPattern(pt),
                  ),
                )).toList() + [
                  Padding(
                    padding: const EdgeInsets.symmetric(horizontal: 5),
                    child: ActionChip(
                      label: const Text("STOP ALL", style: TextStyle(color: Colors.red)),
                      onPressed: _stopAll,
                    ),
                  )
                ],
              ),
              ),
            ],
          ),
        ),
      ),
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topCenter, end: Alignment.bottomCenter,
            colors: [Colors.black, Colors.grey[900]!],
          ),
        ),
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.all(10.0),
              child: Text("Studio Status: $_status", style: const TextStyle(color: Colors.amber, fontSize: 12)),
            ),
            Expanded(
              child: Center(
                child: _activeInstrument != null
                  ? GenericInstrumentPanel(def: _activeInstrument!, onPlay: _onPlayData)
                  : const Text("Select an instrument"),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
