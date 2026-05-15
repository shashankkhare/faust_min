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
  double _duration = 1.0; // Auto-release timeout in seconds

  void _noteOn() {
    _inst.setDuration(_duration);
    _inst.noteOn(freq: NoteMath.getFreq(_noteIndex), velocity: _pressure);
  }

  void _noteOff() {
    _inst.noteOff();
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: "Flute Lab", icon: Icons.waves, color: Colors.teal, children: [
      NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
      const SizedBox(height: 10),
      Text("Pressure: ${_pressure.toStringAsFixed(2)}", style: const TextStyle(color: Colors.white70)),
      Slider(value: _pressure, onChanged: (v) => setState(() => _pressure = v)),
      Text("Duration Safety Limit: ${_duration.toStringAsFixed(2)}s", style: const TextStyle(color: Colors.amber)),
      Slider(value: _duration, min: 0.1, max: 5.0, onChanged: (v) => setState(() => _duration = v)),
      const SizedBox(height: 10),
      Row(mainAxisAlignment: MainAxisAlignment.center, children: [
        ElevatedButton(onPressed: _noteOn, 
          style: ElevatedButton.styleFrom(backgroundColor: Colors.teal),
          child: const Text("Note On")),
        const SizedBox(width: 10),
        ElevatedButton(onPressed: _noteOff, 
          style: ElevatedButton.styleFrom(backgroundColor: Colors.redAccent),
          child: const Text("Note Off")),
      ]),
    ]);
  }
}
