import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class TanpuraPanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const TanpuraPanel({super.key, required this.onPlay});
  @override
  State<TanpuraPanel> createState() => _TanpuraPanelState();
}

class _TanpuraPanelState extends State<TanpuraPanel> {
  final FaustTanpuraInstrument _inst = FaustTanpuraInstrument();
  int _noteIndex = 24; // C3
  bool _isPlaying = false;

  void _toggle() {
    setState(() => _isPlaying = !_isPlaying);
    double base = NoteMath.getFreq(_noteIndex);
    _inst.setParams(
      base,       // String 1 (Sa)
      base * 1.5, // String 2 (Pa)
      base * 1.5, // String 3 (Pa)
      base * 0.5, // String 4 (Lower Sa)
      0.98,       // Decay
      2.0         // Delay
    );
    _inst.setPlaying(_isPlaying);
    
    if (_isPlaying) {
      final pcm = Float32List(44100 * 10);
      _inst.render(pcm);
      widget.onPlay(createWavFile(pcm, 44100));
    }
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Tanpura Drone", icon: Icons.all_inclusive, color: Colors.brown, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      ElevatedButton(onPressed: _toggle, 
        style: ElevatedButton.styleFrom(backgroundColor: Colors.brown),
        child: Text(_isPlaying ? "Stop Drone" : "Start Drone")),
    ]);
  }
}
