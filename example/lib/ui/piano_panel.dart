import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class PianoPanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const PianoPanel({super.key, required this.onPlay});
  @override
  State<PianoPanel> createState() => _PianoPanelState();
}

class _PianoPanelState extends State<PianoPanel> {
  final FaustPianoInstrument _inst = FaustPianoInstrument();
  int _noteIndex = 36; // C4

  void _render() {
    _inst.setFrequency(NoteMath.getFreq(_noteIndex));
    _inst.strike(0.8);
    final pcm = Float32List(44100 * 4);
    _inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Grand Piano", icon: Icons.piano, color: Colors.indigo, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      ElevatedButton(onPressed: _render, 
        style: ElevatedButton.styleFrom(backgroundColor: Colors.indigo),
        child: const Text("Strike Piano")),
    ]);
  }
}
