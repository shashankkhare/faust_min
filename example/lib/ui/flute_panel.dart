import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class FlutePanel extends StatefulWidget {
  final Function(Uint8List) onPlay;
  const FlutePanel({super.key, required this.onPlay});
  @override
  State<FlutePanel> createState() => _FlutePanelState();
}

class _FlutePanelState extends State<FlutePanel> {
  final FaustFluteInstrument _inst = FaustFluteInstrument();
  int _noteIndex = 36; // Default to C4 (440Hz is A4=45, C4 is 36)
  double _pressure = 0.8;

  void _render() {
    _inst.setFrequency(NoteMath.getFreq(_noteIndex));
    _inst.setPressure(_pressure);
    final pcm = Float32List(44100 * 3);
    _inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Flute Lab", icon: Icons.waves, color: Colors.teal, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      Text("Pressure: ${_pressure.toStringAsFixed(2)}", style: const TextStyle(color: Colors.white70)),
      Slider(value: _pressure, onChanged: (v) => setState(() => _pressure = v)),
      ElevatedButton(onPressed: _render, 
        style: ElevatedButton.styleFrom(backgroundColor: Colors.teal),
        child: const Text("Blow Note")),
    ]);
  }
}
