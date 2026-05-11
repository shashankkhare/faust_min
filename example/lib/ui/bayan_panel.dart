import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class BayanPanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const BayanPanel({super.key, required this.onPlay});
  @override
  State<BayanPanel> createState() => _BayanPanelState();
}

class _BayanPanelState extends State<BayanPanel> {
  final FaustBayanInstrument _inst = FaustBayanInstrument();
  int _noteIndex = 24; // C3 (Lower than Dayan)
  double _meend = 1.0;

  void _strike() {
    _inst.setFrequency(NoteMath.getFreq(_noteIndex));
    _inst.setMeend(_meend);
    _inst.strike(0.8);
    final pcm = Float32List(44100 * 2);
    _inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Bayan (Bass)", icon: Icons.circle, color: Colors.blueGrey, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      Text("Meend (Slide): ${_meend.toStringAsFixed(2)}", style: const TextStyle(color: Colors.white70)),
      Slider(value: _meend, min: 1.0, max: 2.0, onChanged: (v) => setState(() => _meend = v)),
      ElevatedButton(onPressed: _strike, 
        style: ElevatedButton.styleFrom(backgroundColor: Colors.blueGrey),
        child: const Text("Strike Bayan")),
    ]);
  }
}
