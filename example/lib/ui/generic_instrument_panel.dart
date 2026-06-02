/*
 * Copyright (c) 2026 Shashank Khare
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

import 'package:flutter/material.dart';
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'common.dart';

class ParamDef {
  final String name;
  final String label;
  final double min;
  final double max;
  final double defaultValue;

  const ParamDef({
    required this.name,
    required this.label,
    this.min = 0,
    this.max = 1,
    this.defaultValue = 0.5,
  });
}

class InstrumentDef {
  final int id;
  final String name;
  final IconData icon;
  final Color color;
  final String category;
  final List<ParamDef> params;

  const InstrumentDef({
    required this.id,
    required this.name,
    required this.icon,
    required this.color,
    required this.category,
    this.params = const [],
  });
}

class GenericInstrumentPanel extends StatefulWidget {
  final InstrumentDef def;
  final Function(Uint8List) onPlay;
  const GenericInstrumentPanel({super.key, required this.def, required this.onPlay});
  @override
  State<GenericInstrumentPanel> createState() => _GenericInstrumentPanelState();
}

class _GenericInstrumentPanelState extends State<GenericInstrumentPanel> {
  late final FaustInstrument _inst;
  int _noteIndex = 36;
  double _velocity = 0.8;
  double _gain = 0.8;
  final Map<String, double> _paramValues = {};

  @override
  void initState() {
    super.initState();
    _inst = FaustInstrument.create(widget.def.id, 0, 44100);
    for (final p in widget.def.params) {
      _paramValues[p.name] = p.defaultValue;
    }
  }

  @override
  void dispose() {
    _inst.dispose();
    super.dispose();
  }

  void _noteOn() {
    final freq = NoteMath.getFreq(_noteIndex);
    _inst.noteOn(freq: freq, velocity: _velocity);
    _inst.setParameter("gain", _gain);
    for (final p in widget.def.params) {
      _inst.setParameter(p.name, _paramValues[p.name] ?? p.defaultValue);
    }
    final pcm = Float32List(44100 * 2);
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
    return BaseInstrumentCard(
      title: widget.def.name,
      icon: widget.def.icon,
      color: widget.def.color,
      children: [
        NoteSlider(value: _noteIndex, onChanged: (v) => setState(() => _noteIndex = v)),
        const SizedBox(height: 8),
        _ParamSlider(label: "Velocity", value: _velocity, onChanged: (v) => _velocity = v),
        _ParamSlider(label: "Gain", value: _gain, onChanged: (v) => _gain = v),
        for (final p in widget.def.params)
          _ParamSlider(
            label: p.label,
            value: _paramValues[p.name] ?? p.defaultValue,
            min: p.min,
            max: p.max,
            onChanged: (v) => _paramValues[p.name] = v,
          ),
        const SizedBox(height: 10),
        Row(mainAxisAlignment: MainAxisAlignment.center, children: [
          ElevatedButton(onPressed: _noteOn,
            style: ElevatedButton.styleFrom(backgroundColor: widget.def.color),
            child: const Text("Note On")),
          const SizedBox(width: 10),
          ElevatedButton(onPressed: _noteOff,
            style: ElevatedButton.styleFrom(backgroundColor: Colors.redAccent),
            child: const Text("Note Off")),
        ]),
      ],
    );
  }
}

class _ParamSlider extends StatelessWidget {
  final String label;
  final double value;
  final double min;
  final double max;
  final ValueChanged<double> onChanged;
  const _ParamSlider({required this.label, required this.value, required this.onChanged, this.min = 0, this.max = 1});

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 2),
      child: Row(children: [
        SizedBox(width: 100, child: Text(label, style: const TextStyle(color: Colors.white70, fontSize: 13))),
        Expanded(child: Slider(value: value.clamp(min, max), min: min, max: max, onChanged: onChanged)),
        SizedBox(width: 50, child: Text(value.toStringAsFixed(3), style: const TextStyle(color: Colors.white60, fontSize: 11))),
      ]),
    );
  }
}

// --- All 49 instrument definitions ---

const List<InstrumentDef> allInstruments = [
  // Tabla
  InstrumentDef(id: 0, name: "Dayan", icon: Icons.dark_mode, color: Color(0xFFE91E63), category: "Tabla"),
  InstrumentDef(id: 1, name: "Bayan", icon: Icons.dark_mode, color: Color(0xFF9C27B0), category: "Tabla",
    params: [ParamDef(name: "meend", label: "Meend", min: 0.5, max: 4.0, defaultValue: 1.2)]),

  // Drums
  InstrumentDef(id: 2, name: "Kick", icon: Icons.album, color: Color(0xFFF44336), category: "Drums",
    params: [ParamDef(name: "sub_boost", label: "Sub Boost", defaultValue: 0.5)]),
  InstrumentDef(id: 3, name: "Snare", icon: Icons.album, color: Color(0xFFFF5722), category: "Drums",
    params: [ParamDef(name: "wire_rattle", label: "Rattle", defaultValue: 0.5)]),
  InstrumentDef(id: 4, name: "HiHat", icon: Icons.album, color: Color(0xFFFF9800), category: "Drums"),
  InstrumentDef(id: 5, name: "Tom", icon: Icons.album, color: Color(0xFFFFC107), category: "Drums",
    params: [ParamDef(name: "decay_time", label: "Decay", min: 0.1, max: 2.0, defaultValue: 0.5)]),
  InstrumentDef(id: 6, name: "Ride", icon: Icons.album, color: Color(0xFFFFEB3B), category: "Drums"),
  InstrumentDef(id: 28, name: "Djembe", icon: Icons.sports_kabaddi, color: Color(0xFF8BC34A), category: "Drums",
    params: [ParamDef(name: "position", label: "Position", defaultValue: 0.5)]),
  InstrumentDef(id: 30, name: "Conga", icon: Icons.sports_kabaddi, color: Color(0xFF4CAF50), category: "Drums",
    params: [ParamDef(name: "position", label: "Position", max: 2, defaultValue: 0)]),
  InstrumentDef(id: 31, name: "Bongo", icon: Icons.sports_kabaddi, color: Color(0xFF009688), category: "Drums",
    params: [ParamDef(name: "position", label: "Position", max: 2, defaultValue: 0)]),
  InstrumentDef(id: 35, name: "Chougong", icon: Icons.sports_kabaddi, color: Color(0xFF00BCD4), category: "Drums"),
  InstrumentDef(id: 36, name: "Lagnga", icon: Icons.sports_kabaddi, color: Color(0xFF03A9F4), category: "Drums",
    params: [ParamDef(name: "mallet_softness", label: "Softness", defaultValue: 0.3)]),
  InstrumentDef(id: 37, name: "Dholak", icon: Icons.sports_kabaddi, color: Color(0xFF2196F3), category: "Drums",
    params: [ParamDef(name: "decay_scale", label: "Decay", min: 0.1, max: 4.0, defaultValue: 1.0)]),
  InstrumentDef(id: 38, name: "Dhol", icon: Icons.sports_kabaddi, color: Color(0xFF3F51B5), category: "Drums",
    params: [ParamDef(name: "decay_scale", label: "Decay", min: 0.1, max: 4.0, defaultValue: 1.0)]),
  InstrumentDef(id: 43, name: "Dagu", icon: Icons.sports_kabaddi, color: Color(0xFF673AB7), category: "Drums"),

  // Bells & Percussion
  InstrumentDef(id: 7, name: "Bell", icon: Icons.notifications, color: Color(0xFF795548), category: "Bell",
    params: [ParamDef(name: "ring_time", label: "Ring", min: 0.5, max: 10.0, defaultValue: 2.0)]),
  InstrumentDef(id: 8, name: "Bowl", icon: Icons.soup_kitchen, color: Color(0xFF00BCD4), category: "Bell"),
  InstrumentDef(id: 14, name: "Cowbell", icon: Icons.notifications, color: Color(0xFFCDDC39), category: "Bell",
    params: [ParamDef(name: "clang_intensity", label: "Clang", defaultValue: 0.5)]),
  InstrumentDef(id: 20, name: "Church Bell", icon: Icons.church, color: Color(0xFFFFC107), category: "Bell"),
  InstrumentDef(id: 29, name: "Marimba", icon: Icons.music_note, color: Color(0xFF8D6E63), category: "Bell",
    params: [ParamDef(name: "position", label: "Position", max: 4, defaultValue: 2.0)]),
  InstrumentDef(id: 47, name: "Tibetan Bowl", icon: Icons.soup_kitchen, color: Color(0xFF26C6DA), category: "Bell"),
  InstrumentDef(id: 48, name: "Ngachen", icon: Icons.notifications, color: Color(0xFF80DEEA), category: "Bell",
    params: [ParamDef(name: "mallet_softness", label: "Softness", defaultValue: 0.8)]),

  // Wind
  InstrumentDef(id: 10, name: "Flute", icon: Icons.music_note, color: Color(0xFFE91E63), category: "Wind",
    params: [ParamDef(name: "pressure", label: "Pressure", defaultValue: 0.8)]),
  InstrumentDef(id: 13, name: "Sax", icon: Icons.music_note, color: Color(0xFFFF9800), category: "Wind",
    params: [ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 0, max: 10, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.1, defaultValue: 0.015)]),
  InstrumentDef(id: 15, name: "Trumpet", icon: Icons.music_note, color: Color(0xFFFF5722), category: "Wind",
    params: [ParamDef(name: "vibrato_rate", label: "Vib Rate", max: 10, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.1, defaultValue: 0.015)]),
  InstrumentDef(id: 16, name: "Shakuhachi", icon: Icons.music_note, color: Color(0xFF795548), category: "Wind",
    params: [ParamDef(name: "pressure", label: "Pressure", defaultValue: 0.8),
             ParamDef(name: "breath_noise", label: "Breath", defaultValue: 0.1)]),
  InstrumentDef(id: 17, name: "Bansuri", icon: Icons.music_note, color: Color(0xFF8D6E63), category: "Wind",
    params: [ParamDef(name: "pressure", label: "Pressure", defaultValue: 0.8),
             ParamDef(name: "breathiness", label: "Breathiness", defaultValue: 0.2)]),
  InstrumentDef(id: 41, name: "Wind", icon: Icons.air, color: Color(0xFFB0BEC5), category: "Wind"),

  // Strings
  InstrumentDef(id: 9, name: "Sitar", icon: Icons.room, color: Color(0xFF9C27B0), category: "Strings",
    params: [ParamDef(name: "jivari", label: "Jivari", defaultValue: 0.5),
             ParamDef(name: "symp_gain", label: "Symp", defaultValue: 0.2)]),
  InstrumentDef(id: 11, name: "Tanpura", icon: Icons.all_inclusive, color: Color(0xFF795548), category: "Strings"),
  InstrumentDef(id: 18, name: "Violin", icon: Icons.music_note, color: Color(0xFF4CAF50), category: "Strings",
    params: [ParamDef(name: "bowPressure", label: "Bow Press", defaultValue: 0.4),
             ParamDef(name: "bowVelocity", label: "Bow Vel", defaultValue: 0.05),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 8, defaultValue: 5.5),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.05, defaultValue: 0.012)]),
  InstrumentDef(id: 21, name: "Acoustic Guitar", icon: Icons.music_note, color: Color(0xFF8BC34A), category: "Strings",
    params: [ParamDef(name: "pluckPosition", label: "Pluck Pos", min: 0.01, max: 0.99, defaultValue: 0.8)]),
  InstrumentDef(id: 22, name: "Electric Guitar", icon: Icons.music_note, color: Color(0xFFCDDC39), category: "Strings",
    params: [ParamDef(name: "pluckPosition", label: "Pluck Pos", min: 0.01, max: 0.99, defaultValue: 0.8),
             ParamDef(name: "drive", label: "Drive", defaultValue: 0.5),
             ParamDef(name: "sustain", label: "Sustain", defaultValue: 0.5)]),
  InstrumentDef(id: 23, name: "Bass", icon: Icons.music_note, color: Color(0xFF03A9F4), category: "Strings",
    params: [ParamDef(name: "mute", label: "Mute", defaultValue: 0.95),
             ParamDef(name: "tone", label: "Tone", min: 100, max: 5000, defaultValue: 600)]),
  InstrumentDef(id: 24, name: "Cello", icon: Icons.music_note, color: Color(0xFF2196F3), category: "Strings",
    params: [ParamDef(name: "bowPressure", label: "Bow Press", defaultValue: 0.4),
             ParamDef(name: "bowVelocity", label: "Bow Vel", defaultValue: 0.1),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 8, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.03, defaultValue: 0.008)]),
  InstrumentDef(id: 39, name: "Guzheng", icon: Icons.music_note, color: Color(0xFF009688), category: "Strings",
    params: [ParamDef(name: "damping", label: "Damping", min: 0.9, max: 0.9999, defaultValue: 0.995),
             ParamDef(name: "pluck_noise", label: "Pluck Noise", defaultValue: 0.5)]),
  InstrumentDef(id: 40, name: "Erhu", icon: Icons.music_note, color: Color(0xFFE91E63), category: "Strings",
    params: [ParamDef(name: "bowPressure", label: "Bow Press", defaultValue: 0.6),
             ParamDef(name: "bowVelocity", label: "Bow Vel", defaultValue: 0.3),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 8, defaultValue: 6.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.05, defaultValue: 0.02)]),
  InstrumentDef(id: 44, name: "Sarod", icon: Icons.music_note, color: Color(0xFF673AB7), category: "Strings",
    params: [ParamDef(name: "symp_gain", label: "Symp", defaultValue: 0.3)]),
  InstrumentDef(id: 45, name: "Santoor", icon: Icons.music_note, color: Color(0xFF3F51B5), category: "Strings"),
  InstrumentDef(id: 46, name: "Tumbi", icon: Icons.music_note, color: Color(0xFF7C4DFF), category: "Strings",
    params: [ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 10, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.05, defaultValue: 0.003)]),

  // Keys
  InstrumentDef(id: 12, name: "Piano", icon: Icons.piano, color: Color(0xFF212121), category: "Keys",
    params: [ParamDef(name: "brightness", label: "Brightness", defaultValue: 0.7),
             ParamDef(name: "stiffness", label: "Stiffness", defaultValue: 0.25)]),

  // Synth & FX
  InstrumentDef(id: 19, name: "Rainmaker", icon: Icons.water_drop, color: Color(0xFF00BCD4), category: "FX",
    params: [ParamDef(name: "Instrument_Material", label: "Material", defaultValue: 0),
             ParamDef(name: "Tilt_Speed_Hz", label: "Tilt Speed", min: 0.01, max: 1, defaultValue: 0.05)]),
  InstrumentDef(id: 25, name: "Cricket", icon: Icons.bug_report, color: Color(0xFF4CAF50), category: "FX",
    params: [ParamDef(name: "rate", label: "Rate", min: 1, max: 8, defaultValue: 3.0)]),
  InstrumentDef(id: 26, name: "Cuckoo", icon: Icons.forest, color: Color(0xFF795548), category: "FX",
    params: [ParamDef(name: "type", label: "Type", max: 2, defaultValue: 0)]),
  InstrumentDef(id: 27, name: "Waterfall", icon: Icons.water, color: Color(0xFF2196F3), category: "FX",
    params: [ParamDef(name: "size", label: "Size", defaultValue: 0.5)]),
  InstrumentDef(id: 32, name: "Voice", icon: Icons.mic, color: Color(0xFFE91E63), category: "FX",
    params: [ParamDef(name: "vowel", label: "Vowel", max: 4, defaultValue: 0),
             ParamDef(name: "breathiness", label: "Breathiness", defaultValue: 0.15),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", max: 12, defaultValue: 5.5),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.08, defaultValue: 0.012)]),
  InstrumentDef(id: 33, name: "Shaker", icon: Icons.blur_on, color: Color(0xFF9E9E9E), category: "FX",
    params: [ParamDef(name: "decay", label: "Decay", min: 0.01, max: 0.5, defaultValue: 0.06)]),
  InstrumentDef(id: 34, name: "Seawave", icon: Icons.waves, color: Color(0xFF03A9F4), category: "FX",
    params: [ParamDef(name: "intensity", label: "Intensity", defaultValue: 0.5)]),
  InstrumentDef(id: 42, name: "Thunder", icon: Icons.thunderstorm, color: Color(0xFF263238), category: "FX"),
];
