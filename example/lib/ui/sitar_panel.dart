import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class SitarPanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const SitarPanel({super.key, required this.onPlay});
  @override
  State<SitarPanel> createState() => _SitarPanelState();
}

class _SitarPanelState extends State<SitarPanel> {
  final FaustSitarInstrument _inst = FaustSitarInstrument();
  int _noteIndex = 36; // C4
  double _jivari = 0.5;

  void _render() {
    _inst.setFrequency(NoteMath.getFreq(_noteIndex));
    _inst.setJivari(_jivari);
    _inst.pluck(0.8);
    final pcm = Float32List(44100 * 4);
    _inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Sitar Lab", icon: Icons.music_note, color: Colors.deepPurple, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      Text("Jivari Buzz: ${_jivari.toStringAsFixed(2)}", style: const TextStyle(color: Colors.white70)),
      Slider(value: _jivari, onChanged: (v) => setState(() => _jivari = v)),
      ElevatedButton(onPressed: _render, 
        style: ElevatedButton.styleFrom(backgroundColor: Colors.deepPurple),
        child: const Text("Pluck Sitar")),
    ]);
  }
}
