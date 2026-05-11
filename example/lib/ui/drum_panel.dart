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
  void _strike() {
    if (widget.inst is FaustKickInstrument) (widget.inst as FaustKickInstrument).strike(0.8);
    else if (widget.inst is FaustSnareInstrument) (widget.inst as FaustSnareInstrument).strike(0.8);
    else if (widget.inst is FaustTomInstrument) (widget.inst as FaustTomInstrument).strike(0.8);
    else if (widget.inst is FaustHiHatInstrument) (widget.inst as FaustHiHatInstrument).strike(0.8);
    else if (widget.inst is FaustRideInstrument) (widget.inst as FaustRideInstrument).strike(0.8);
    
    final pcm = Float32List(44100 * 1);
    widget.inst.render(pcm);
    widget.onPlay(createWavFile(pcm, 44100));
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(title: widget.name, icon: Icons.album, color: Colors.redAccent, children: [
      ElevatedButton(onPressed: _strike, child: Text("Strike ${widget.name}")),
    ]);
  }
}
