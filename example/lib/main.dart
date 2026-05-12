import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:typed_data';
import 'dart:ffi' hide Size;
import 'package:ffi/ffi.dart';
import 'package:faust_min/faust_min.dart';
import 'package:faust_min/umpl_parser.dart';
import 'package:flutter_soloud/flutter_soloud.dart';

import 'ui/common.dart';
import 'ui/flute_panel.dart';
import 'ui/dayan_panel.dart';
import 'ui/bayan_panel.dart';
import 'ui/sitar_panel.dart';
import 'ui/tanpura_panel.dart';
import 'ui/piano_panel.dart';
import 'ui/sax_panel.dart';
import 'ui/bell_panel.dart';
import 'ui/bowl_panel.dart';
import 'ui/drum_panel.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  // Removed SoLoud initialization to prevent ALSA soundcard lock contention
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
  String _activeView = "Flute";
  
  @override
  void initState() {
    super.initState();
    // Auto-trigger solo Tanpura Drone for physics verification
    Future.delayed(const Duration(seconds: 1), () {
      _playPattern("Tanpura Drone");
    });
  }

  final List<String> _instruments = [
    "Flute", "Dayan", "Bayan", "Sitar", "Tanpura", 
    "Piano", "Sax", "Bell", "Bowl",
    "Kick", "Snare", "Tom", "HiHat", "Ride"
  ];
  
  final List<String> _patterns = ["Tanpura Drone", "Varanasi Dawn", "Dayan Strokes", "Bayan Strokes", "22 Shrutis Test"];

  Future<void> _playPattern(String genre) async {
    setState(() { 
      _isPlayingPattern = true; 
      _status = "Streaming $genre..."; 
    });
    
    try {
      FaustOrchestrator.stop(); // Stop any existing sequence first
      FaustOrchestrator.init();
      FaustOrchestrator.setAssetBasePath("../assets");
      
      if (genre == "Tanpura Drone") {
        // Single strike with 100 dots (25s) to allow for 8s natural decay
        final String uml = """
notation: Indian
instrument: TA
bpm: 60
grid: 4
basefreq: 130.81

9Sa....................................................................................................
""";
        FaustOrchestrator.loadSequence("tanpura_solo", uml);
        FaustOrchestrator.play("tanpura_solo");
        Future.delayed(const Duration(seconds: 30));
      } else if (genre == "22 Shrutis Test") {
        final List<String> shrutis = [
          "Sa", "r1", "r2", "R1", "R2", "g1", "g2", "G1", "G2", "M1", "M2", 
          "m1", "m2", "Pa", "d1", "d2", "D1", "D2", "n1", "n2", "N1", "N2"
        ];
        String notes = "";
        for (String s in shrutis) notes += "9$s.. ";
        
        final String uml = "notation: Indian\ninstrument: FL\nbpm: 120\ngrid: 4\nbasefreq: 200.0\n\n$notes";
        FaustOrchestrator.loadSequence("shruti_test", uml);
        FaustOrchestrator.play("shruti_test");
        await Future.delayed(Duration(seconds: shrutis.length));
      } else if (genre == "Varanasi Dawn") {
        final List<String> umplTracks = [
          'baseFreq: 261.63\nbpm: 100\ninstrument: DA\n9Sa.......9(Pa/2).......9Sa.......9(Pa/2).......\n9Sa...9Sa...9Sa.9Sa...9Sa...9Sa.9Sa...',
          'baseFreq: 130.81\nbpm: 100\ninstrument: TA\n9Sa^ .S.. .S.. .S..', 
          'baseFreq: 523.25\nbpm: 100\ninstrument: FL\n9Sa.9r1^9R2.9G1.9M1.9(2*Pa).....9(2*Ma)^9(2*Pa).9G2.9R1.9Sa....'
        ];
        for (int i = 0; i < umplTracks.length; i++) {
          final name = "vd_track_$i";
          FaustOrchestrator.loadSequence(name, umplTracks[i]);
          FaustOrchestrator.play(name);
        }
        Future.delayed(const Duration(seconds: 30));
      } else if (genre == "Dayan Strokes") {
        // Authentic Bols: Na, Tin, Tun, tk
        final String uml = "notation: Indian\ninstrument: DA\nbpm: 120\ngrid: 4\nbasefreq: 150.0\n\n9Na. 9Na. 9Tin. 9Tin. 9Tun. 9Tun. 9tk. 9tk. 9Na. 9Tin. 9Tun. .S..";
        FaustOrchestrator.loadSequence("dayan_test", uml);
        FaustOrchestrator.play("dayan_test");
        
        // Auto-trigger Bayan after Dayan
        Future.delayed(const Duration(seconds: 12), () {
          if (mounted) _playPattern("Bayan Strokes");
        });
        
        await Future.delayed(const Duration(seconds: 10));
      } else if (genre == "Bayan Strokes") {
        // Authentic Bols: Ghe, Ka
        final String uml = "notation: Indian\ninstrument: BA\nbpm: 120\ngrid: 4\nbasefreq: 110.0\n\n9Ghe. 9Ghe. 9Ka. 9Ka. 9Ghe. 9Ghe. 9Ka. 9Ka. 9Ghe. .S..";
        FaustOrchestrator.loadSequence("bayan_test", uml);
        FaustOrchestrator.play("bayan_test");
        await Future.delayed(const Duration(seconds: 10));
      } else {
        // Simple Real-Time Scale
        final String uml = "notation: Indian\ninstrument: FL\nbpm: 120\ngrid: 4\nbasefreq: 440.0\n\n9Sa. 9Re. 9Ga. 9Ma. 9Pa. 9Dh. 9Ni. 9Sa^ .S..";
        FaustOrchestrator.loadSequence("rt_scale", uml);
        FaustOrchestrator.play("rt_scale");
      }
    } catch (e) {
      debugPrint("Playback Error: $e");
    } finally {
      if (mounted) setState(() { _isPlayingPattern = false; });
    }
  }

  Future<void> _playRealTimeTest() async => _playPattern("Real-Time");

  void _stopAll() {
    FaustOrchestrator.stop();
    setState(() => _status = "Stopped");
  }

  void _onPlayData(Uint8List wav) async {
    final source = await SoLoud.instance.loadMem('os_${DateTime.now().microsecondsSinceEpoch}', wav);
    await SoLoud.instance.play(source);
    await Future.delayed(const Duration(seconds: 4));
    await SoLoud.instance.disposeSource(source);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        title: const Text("UMPL UNIVERSAL STUDIO"),
        bottom: PreferredSize(
          preferredSize: const Size.fromHeight(100),
          child: Column(
            children: [
              SingleChildScrollView(
                scrollDirection: Axis.horizontal,
                padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 5),
                child: Row(
                  children: _instruments.map((inst) => Padding(
                    padding: const EdgeInsets.symmetric(horizontal: 5),
                    child: ChoiceChip(
                      label: Text(inst),
                      selected: _activeView == inst,
                      onSelected: (val) { if (val) setState(() => _activeView = inst); },
                    ),
                  )).toList(),
                ),
              ),
              SingleChildScrollView(
                scrollDirection: Axis.horizontal,
                padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 5),
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
                child: _buildActiveView(),
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildActiveView() {
    switch (_activeView) {
      case "Flute": return FlutePanel(onPlay: _onPlayData);
      case "Dayan": return DayanPanel(onPlay: _onPlayData);
      case "Bayan": return BayanPanel(onPlay: _onPlayData);
      case "Sitar": return SitarPanel(onPlay: _onPlayData);
      case "Tanpura": return TanpuraPanel(onPlay: _onPlayData);
      case "Piano": return PianoPanel(onPlay: _onPlayData);
      case "Sax": return SaxPanel(onPlay: _onPlayData);
      case "Bell": return BellPanel(onPlay: _onPlayData);
      case "Bowl": return BowlPanel(onPlay: _onPlayData);
      case "Kick": return DrumPanel(name: "Kick", inst: FaustKickInstrument(), onPlay: _onPlayData);
      case "Snare": return DrumPanel(name: "Snare", inst: FaustSnareInstrument(), onPlay: _onPlayData);
      case "Tom": return DrumPanel(name: "Tom", inst: FaustTomInstrument(), onPlay: _onPlayData);
      case "HiHat": return DrumPanel(name: "HiHat", inst: FaustHiHatInstrument(), onPlay: _onPlayData);
      case "Ride": return DrumPanel(name: "Ride", inst: FaustRideInstrument(), onPlay: _onPlayData);
      default: return const Text("Select an instrument from the header");
    }
  }
}
