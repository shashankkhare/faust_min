import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class DrumPanel extends StatefulWidget {
  final String name;
  final FaustInstrument inst;
  final Function(Uint8List) onPlay;
  const DrumPanel({super.key, required this.name, required this.inst, required this.onPlay});
  @override
  State<DrumPanel> createState() => _DrumPanelState();
}

class _DrumPanelState extends State<DrumPanel> {
  void _noteOn() {
    widget.inst.noteOn(velocity: 0.8);
    final pcm = Float32List(44100 * 1);
    widget.inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: widget.name, icon: Icons.album, color: Colors.redAccent, children: [
      ElevatedButton(onPressed: _noteOn, child: Text("Strike ${widget.name}")),
    ]);
  }
}
