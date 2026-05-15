import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class BellPanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const BellPanel({super.key, required this.onPlay});
  @override
  State<BellPanel> createState() => _BellPanelState();
}

class _BellPanelState extends State<BellPanel> {
  final FaustBellInstrument _inst = FaustBellInstrument();
  int _noteIndex = 45; // A4 (Standard tuning check)
  double _ringTime = 2.0; // Resonator decay tail in seconds

  void _noteOn() {
    _inst.setRingTime(_ringTime);
    _inst.noteOn(freq: NoteMath.getFreq(_noteIndex), velocity: 0.8);
    final pcm = Float32List(44100 * 3);
    _inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  void _noteOff() {
    _inst.noteOff();
    final pcm = Float32List(44100 * 2);
    _inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Meditative Bell", icon: Icons.notifications_active, color: Colors.amber, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      Text("Physical Ring Time: ${_ringTime.toStringAsFixed(2)}s", style: const TextStyle(color: Colors.white70)),
      Slider(value: _ringTime, min: 0.5, max: 10.0, onChanged: (v) => setState(() => _ringTime = v)),
      const SizedBox(height: 10),
      Row(mainAxisAlignment: MainAxisAlignment.center, children: [
        ElevatedButton(onPressed: _noteOn, 
          style: ElevatedButton.styleFrom(backgroundColor: Colors.amber),
          child: const Text("Note On")),
        const SizedBox(width: 10),
        ElevatedButton(onPressed: _noteOff, 
          style: ElevatedButton.styleFrom(backgroundColor: Colors.redAccent),
          child: const Text("Note Off")),
      ]),
    ]);
  }
}
