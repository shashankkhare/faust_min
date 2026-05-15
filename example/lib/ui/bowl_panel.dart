import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class BowlPanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const BowlPanel({super.key, required this.onPlay});
  @override
  State<BowlPanel> createState() => _BowlPanelState();
}

class _BowlPanelState extends State<BowlPanel> {
  final FaustBowlInstrument _inst = FaustBowlInstrument();
  int _noteIndex = 36; // C4

  void _noteOn() {
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
    return BaseInstrumentCard(title: "Singing Bowl", icon: Icons.soup_kitchen, color: Colors.cyan, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      Row(mainAxisAlignment: MainAxisAlignment.center, children: [
        ElevatedButton(onPressed: _noteOn, 
          style: ElevatedButton.styleFrom(backgroundColor: Colors.cyan),
          child: const Text("Note On")),
        const SizedBox(width: 10),
        ElevatedButton(onPressed: _noteOff, 
          style: ElevatedButton.styleFrom(backgroundColor: Colors.redAccent),
          child: const Text("Note Off")),
      ]),
    ]);
  }
}
