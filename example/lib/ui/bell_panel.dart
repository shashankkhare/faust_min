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

  void _strike() {
    _inst.setFrequency(NoteMath.getFreq(_noteIndex));
    _inst.strike(0.8);
    final pcm = Float32List(44100 * 6);
    _inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Meditative Bell", icon: Icons.notifications_active, color: Colors.amber, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      ElevatedButton(onPressed: _strike, 
        style: ElevatedButton.styleFrom(backgroundColor: Colors.amber),
        child: const Text("Strike Bell")),
    ]);
  }
}
