import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class SaxPanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const SaxPanel({super.key, required this.onPlay});
  @override
  State<SaxPanel> createState() => _SaxPanelState();
}

class _SaxPanelState extends State<SaxPanel> {
  final FaustSaxInstrument _inst = FaustSaxInstrument();
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
    return BaseInstrumentCard(title: "Tenor Sax", icon: Icons.air, color: Colors.brown, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      ElevatedButton(onPressed: _render, 
        style: ElevatedButton.styleFrom(backgroundColor: Colors.brown),
        child: const Text("Blow Sax")),
    ]);
  }
}
