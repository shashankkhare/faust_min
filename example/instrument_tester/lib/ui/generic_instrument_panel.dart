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
  final List<ParamDef> params;

  const InstrumentDef({
    required this.id,
    required this.name,
    required this.icon,
    required this.color,
    this.params = const [],
  });

  String get category => InstrumentMapper.getClass(id);
}

class GenericInstrumentPanel extends StatefulWidget {
  final InstrumentDef def;
  const GenericInstrumentPanel({super.key, required this.def});
  @override
  State<GenericInstrumentPanel> createState() => _GenericInstrumentPanelState();
}

class _GenericInstrumentPanelState extends State<GenericInstrumentPanel> {
  late final FaustInstrument _inst;
  int _noteIndex = 36;
  double _velocity = 0;
  double _strike = 0;
  double _strikeMin = 0;
  double _strikeMax = 1;
  final Map<String, double> _paramValues = {};
  bool _registered = false;
  int _trackId = 0;

  @override
  void initState() {
    super.initState();
    _inst = FaustInstrument.create(widget.def.id, 0, FaustMixer.instance.sampleRate);
    for (final p in widget.def.params) {
      _paramValues[p.name] = p.defaultValue;
    }
    try {
      final params = _inst.getParameters();
      for (final p in params) {
        final name = p['name'] as String;
        final pMin = (p['min'] as num).toDouble();
        final pMax = (p['max'] as num).toDouble();
        final pVal = (p['value'] as num).toDouble();
        if (name == 'strike') {
          _strikeMin = pMin;
          _strikeMax = pMax;
          _strike = pVal;
        } else if (name == 'velocity') {
          _velocity = pVal;
        } else if (_paramValues.containsKey(name)) {
          _paramValues[name] = pVal;
        }
      }
    } catch (_) {}
  }

  @override
  void dispose() {
    _inst.noteOff();
    if (_registered) {
      FaustMixer.instance.removeTrack(_trackId);
      _registered = false;
    }
    _inst.dispose();
    super.dispose();
  }

  void _noteOn() {
    final freq = NoteMath.getFreq(_noteIndex);
    _inst.noteOn(freq: freq, velocity: _velocity, strike: _strike);
    for (final p in widget.def.params) {
      _inst.setParameter(p.name, _paramValues[p.name] ?? p.defaultValue);
    }
    if (!_registered) {
      _trackId = FaustMixer.instance.registerInstrument(_inst, 1.0);
      _registered = true;
    }
  }

  void _noteOff() {
    _inst.noteOff();
  }

  @override
  Widget build(BuildContext context) {
    return BaseInstrumentCard(
      title: widget.def.name,
      icon: widget.def.icon,
      color: widget.def.color,
      children: [
        _FreqDropdown(
            noteIndex: _noteIndex,
            onChanged: (v) => setState(() => _noteIndex = v)),
        const SizedBox(height: 8),
        _ParamSlider(
            label: "Velocity",
            value: _velocity,
            onChanged: (v) => setState(() => _velocity = v)),
        _ParamSlider(
            label: "Strike", value: _strike, min: _strikeMin, max: _strikeMax, onChanged: (v) => setState(() => _strike = v)),
        for (final p in widget.def.params)
          _ParamSlider(
            label: p.label,
            value: _paramValues[p.name] ?? p.defaultValue,
            min: p.min,
            max: p.max,
            onChanged: (v) => setState(() => _paramValues[p.name] = v),
          ),
        const SizedBox(height: 10),
        Row(mainAxisAlignment: MainAxisAlignment.center, children: [
          ElevatedButton(
              onPressed: _noteOn,
              style: ElevatedButton.styleFrom(
                  backgroundColor: widget.def.color),
              child: const Text("Note On")),
          const SizedBox(width: 10),
          ElevatedButton(
              onPressed: _noteOff,
              style:
                  ElevatedButton.styleFrom(backgroundColor: Colors.redAccent),
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
  const _ParamSlider(
      {required this.label,
      required this.value,
      required this.onChanged,
      this.min = 0,
      this.max = 1});

  @override
  Widget build(BuildContext context) {
    final displayVal = value.clamp(min, max);
    final decimals = max > 1 ? 0 : 2;
    final valStr = displayVal.toStringAsFixed(decimals);
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 2),
      child: Row(children: [
        SizedBox(
            width: 100,
            child: Text(this.label,
                style:
                    const TextStyle(color: Colors.white70, fontSize: 13))),
        Expanded(
            child: SliderTheme(
              data: SliderTheme.of(context).copyWith(
                valueIndicatorShape: const PaddleSliderValueIndicatorShape(),
                valueIndicatorColor: Colors.amber,
                valueIndicatorTextStyle: const TextStyle(color: Colors.black, fontWeight: FontWeight.bold, fontSize: 12),
                showValueIndicator: ShowValueIndicator.always,
              ),
              child: Slider(
                  value: displayVal,
                  min: min,
                  max: max,
                  label: valStr,
                  onChanged: onChanged),
            )),
        SizedBox(
            width: 50,
            child: Text(max > 1 ? max.toStringAsFixed(0) : max.toStringAsFixed(1),
                textAlign: TextAlign.right,
                style:
                    const TextStyle(color: Colors.white60, fontSize: 11))),
      ]),
    );
  }
}

class _FreqDropdown extends StatelessWidget {
  final int noteIndex;
  final ValueChanged<int> onChanged;
  const _FreqDropdown({required this.noteIndex, required this.onChanged});

  @override
  Widget build(BuildContext context) {
    final entries = List<int>.generate(49, (i) => i);
    return Row(
      children: [
        const SizedBox(
            width: 100,
            child: Text("Note",
                style: TextStyle(color: Colors.white70, fontSize: 13))),
        Expanded(
          child: DropdownButton<int>(
            isExpanded: true,
            value: noteIndex,
            dropdownColor: const Color(0xFF1E1E2E),
            style: const TextStyle(color: Colors.amber, fontSize: 15),
            items: entries
                .map((i) => DropdownMenuItem(
                      value: i,
                      child: Text(
                          "${NoteMath.getNoteName(i)}  (${NoteMath.getFreq(i).toStringAsFixed(1)} Hz)"),
                    ))
                .toList(),
            onChanged: (v) {
              if (v != null) onChanged(v);
            },
          ),
        ),
      ],
    );
  }
}

// --- All instrument definitions ---

const List<InstrumentDef> allInstruments = [
  InstrumentDef(id: 0, name: "Dayan", icon: Icons.dark_mode, color: Color(0xFFE91E63)),
  InstrumentDef(id: 1, name: "Bayan", icon: Icons.dark_mode, color: Color(0xFF9C27B0),
    params: [ParamDef(name: "meend", label: "Meend", min: 0.5, max: 4.0, defaultValue: 1.2)]),
  InstrumentDef(id: 2, name: "Kick", icon: Icons.album, color: Color(0xFFF44336),
    params: [ParamDef(name: "sub_boost", label: "Sub Boost", defaultValue: 0.5)]),
  InstrumentDef(id: 3, name: "Snare", icon: Icons.album, color: Color(0xFFFF5722),
    params: [ParamDef(name: "wire_rattle", label: "Rattle", defaultValue: 0.5)]),
  InstrumentDef(id: 4, name: "HiHat", icon: Icons.album, color: Color(0xFFFF9800)),
  InstrumentDef(id: 5, name: "Tom", icon: Icons.album, color: Color(0xFFFFC107),
    params: [ParamDef(name: "decay_time", label: "Decay", min: 0.1, max: 2.0, defaultValue: 0.5)]),
  InstrumentDef(id: 6, name: "Ride", icon: Icons.album, color: Color(0xFFFFEB3B)),
  InstrumentDef(id: 7, name: "Bell", icon: Icons.notifications, color: Color(0xFF795548),
    params: [ParamDef(name: "ring_time", label: "Ring", min: 0.5, max: 10.0, defaultValue: 2.0)]),
  InstrumentDef(id: 8, name: "Bowl", icon: Icons.soup_kitchen, color: Color(0xFF00BCD4)),
  InstrumentDef(id: 9, name: "Sitar", icon: Icons.room, color: Color(0xFF9C27B0),
    params: [ParamDef(name: "jivari", label: "Jivari", defaultValue: 0.5),
             ParamDef(name: "symp_gain", label: "Symp", defaultValue: 0.2)]),
  InstrumentDef(id: 10, name: "Flute", icon: Icons.music_note, color: Color(0xFFE91E63),
    params: [ParamDef(name: "pressure", label: "Pressure", defaultValue: 0.8)]),
  InstrumentDef(id: 11, name: "Tanpura", icon: Icons.all_inclusive, color: Color(0xFF795548)),
  InstrumentDef(id: 12, name: "Piano", icon: Icons.piano, color: Color(0xFF212121),
    params: [ParamDef(name: "brightness", label: "Brightness", defaultValue: 0.7),
             ParamDef(name: "stiffness", label: "Stiffness", defaultValue: 0.25)]),
  InstrumentDef(id: 13, name: "Sax", icon: Icons.music_note, color: Color(0xFFFF9800),
    params: [ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 0, max: 10, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.1, defaultValue: 0.015)]),
  InstrumentDef(id: 14, name: "Cowbell", icon: Icons.notifications, color: Color(0xFFCDDC39),
    params: [ParamDef(name: "clang_intensity", label: "Clang", defaultValue: 0.5)]),
  InstrumentDef(id: 15, name: "Trumpet", icon: Icons.music_note, color: Color(0xFFFF5722),
    params: [ParamDef(name: "vibrato_rate", label: "Vib Rate", max: 10, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.1, defaultValue: 0.015)]),
  InstrumentDef(id: 16, name: "Shakuhachi", icon: Icons.music_note, color: Color(0xFF795548),
    params: [ParamDef(name: "pressure", label: "Pressure", defaultValue: 0.8),
             ParamDef(name: "breath_noise", label: "Breath", defaultValue: 0.1)]),
  InstrumentDef(id: 17, name: "Bansuri", icon: Icons.music_note, color: Color(0xFF8D6E63),
    params: [ParamDef(name: "pressure", label: "Pressure", defaultValue: 0.8),
             ParamDef(name: "breathiness", label: "Breathiness", defaultValue: 0.2)]),
  InstrumentDef(id: 18, name: "Violin", icon: Icons.music_note, color: Color(0xFF4CAF50),
    params: [ParamDef(name: "bowPressure", label: "Bow Press", defaultValue: 0.4),
             ParamDef(name: "bowVelocity", label: "Bow Vel", defaultValue: 0.05),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 8, defaultValue: 5.5),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.05, defaultValue: 0.012)]),
  InstrumentDef(id: 19, name: "Rainmaker", icon: Icons.water_drop, color: Color(0xFF00BCD4),
    params: [ParamDef(name: "Instrument_Material", label: "Material", defaultValue: 0),
             ParamDef(name: "Tilt_Speed_Hz", label: "Tilt Speed", min: 0.01, max: 1, defaultValue: 0.05)]),
  InstrumentDef(id: 20, name: "Church Bell", icon: Icons.church, color: Color(0xFFFFC107)),
  InstrumentDef(id: 21, name: "Acoustic Guitar", icon: Icons.music_note, color: Color(0xFF8BC34A),
    params: [ParamDef(name: "pluckPosition", label: "Pluck Pos", min: 0.01, max: 0.99, defaultValue: 0.8)]),
  InstrumentDef(id: 22, name: "Electric Guitar", icon: Icons.music_note, color: Color(0xFFCDDC39),
    params: [ParamDef(name: "pluckPosition", label: "Pluck Pos", min: 0.01, max: 0.99, defaultValue: 0.8),
             ParamDef(name: "drive", label: "Drive", defaultValue: 0.5),
             ParamDef(name: "sustain", label: "Sustain", defaultValue: 0.5)]),
  InstrumentDef(id: 23, name: "Bass", icon: Icons.music_note, color: Color(0xFF03A9F4),
    params: [ParamDef(name: "mute", label: "Mute", defaultValue: 0.95),
             ParamDef(name: "tone", label: "Tone", min: 100, max: 5000, defaultValue: 600)]),
  InstrumentDef(id: 24, name: "Cello", icon: Icons.music_note, color: Color(0xFF2196F3),
    params: [ParamDef(name: "bowPressure", label: "Bow Press", defaultValue: 0.4),
             ParamDef(name: "bowVelocity", label: "Bow Vel", defaultValue: 0.1),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 8, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.03, defaultValue: 0.008)]),
  InstrumentDef(id: 25, name: "Cricket", icon: Icons.bug_report, color: Color(0xFF4CAF50),
    params: [ParamDef(name: "rate", label: "Rate", min: 1, max: 8, defaultValue: 3.0)]),
  InstrumentDef(id: 26, name: "Cuckoo", icon: Icons.forest, color: Color(0xFF795548),
    params: [ParamDef(name: "type", label: "Type", max: 2, defaultValue: 0)]),
  InstrumentDef(id: 27, name: "Waterfall", icon: Icons.water, color: Color(0xFF2196F3),
    params: [ParamDef(name: "size", label: "Size", defaultValue: 0.5)]),
  InstrumentDef(id: 28, name: "Djembe", icon: Icons.sports_kabaddi, color: Color(0xFF8BC34A),
    params: [ParamDef(name: "position", label: "Position", defaultValue: 0.5)]),
  InstrumentDef(id: 29, name: "Marimba", icon: Icons.music_note, color: Color(0xFF8D6E63),
    params: [ParamDef(name: "position", label: "Position", max: 4, defaultValue: 2.0)]),
  InstrumentDef(id: 30, name: "Conga", icon: Icons.sports_kabaddi, color: Color(0xFF4CAF50),
    params: [ParamDef(name: "position", label: "Position", max: 2, defaultValue: 0)]),
  InstrumentDef(id: 31, name: "Bongo", icon: Icons.sports_kabaddi, color: Color(0xFF009688),
    params: [ParamDef(name: "position", label: "Position", max: 2, defaultValue: 0)]),
  InstrumentDef(id: 32, name: "Voice", icon: Icons.mic, color: Color(0xFFE91E63),
    params: [ParamDef(name: "vowel", label: "Vowel", max: 4, defaultValue: 0),
             ParamDef(name: "breathiness", label: "Breathiness", defaultValue: 0.15),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", max: 12, defaultValue: 5.5),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.08, defaultValue: 0.012)]),
  InstrumentDef(id: 33, name: "Shaker", icon: Icons.blur_on, color: Color(0xFF9E9E9E),
    params: [ParamDef(name: "decay", label: "Decay", min: 0.01, max: 0.5, defaultValue: 0.06)]),
  InstrumentDef(id: 34, name: "Seawave", icon: Icons.waves, color: Color(0xFF03A9F4),
    params: [ParamDef(name: "intensity", label: "Intensity", defaultValue: 0.5)]),
  InstrumentDef(id: 35, name: "Chougong", icon: Icons.sports_kabaddi, color: Color(0xFF00BCD4)),
  InstrumentDef(id: 36, name: "Lagnga", icon: Icons.sports_kabaddi, color: Color(0xFF03A9F4),
    params: [ParamDef(name: "mallet_softness", label: "Softness", defaultValue: 0.3)]),
  InstrumentDef(id: 37, name: "Dholak", icon: Icons.sports_kabaddi, color: Color(0xFF2196F3),
    params: [ParamDef(name: "decay_scale", label: "Decay", min: 0.1, max: 4.0, defaultValue: 1.0)]),
  InstrumentDef(id: 38, name: "Dhol", icon: Icons.sports_kabaddi, color: Color(0xFF3F51B5),
    params: [ParamDef(name: "decay_scale", label: "Decay", min: 0.1, max: 4.0, defaultValue: 1.0)]),
  InstrumentDef(id: 39, name: "Guzheng", icon: Icons.music_note, color: Color(0xFF009688),
    params: [ParamDef(name: "damping", label: "Damping", min: 0.9, max: 0.9999, defaultValue: 0.995),
             ParamDef(name: "pluck_noise", label: "Pluck Noise", defaultValue: 0.5)]),
  InstrumentDef(id: 40, name: "Erhu", icon: Icons.music_note, color: Color(0xFFE91E63),
    params: [ParamDef(name: "bowPressure", label: "Bow Press", defaultValue: 0.6),
             ParamDef(name: "bowVelocity", label: "Bow Vel", defaultValue: 0.3),
             ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 8, defaultValue: 6.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.05, defaultValue: 0.02)]),
  InstrumentDef(id: 41, name: "Wind", icon: Icons.air, color: Color(0xFFB0BEC5)),
  InstrumentDef(id: 42, name: "Thunder", icon: Icons.thunderstorm, color: Color(0xFF263238)),
  InstrumentDef(id: 43, name: "Dagu", icon: Icons.sports_kabaddi, color: Color(0xFF673AB7)),
  InstrumentDef(id: 44, name: "Sarod", icon: Icons.music_note, color: Color(0xFF673AB7),
    params: [ParamDef(name: "symp_gain", label: "Symp", defaultValue: 0.3)]),
  InstrumentDef(id: 45, name: "Santoor", icon: Icons.music_note, color: Color(0xFF3F51B5)),
  InstrumentDef(id: 46, name: "Tumbi", icon: Icons.music_note, color: Color(0xFF7C4DFF),
    params: [ParamDef(name: "vibrato_rate", label: "Vib Rate", min: 3, max: 10, defaultValue: 5.0),
             ParamDef(name: "vibrato_depth", label: "Vib Depth", max: 0.05, defaultValue: 0.003)]),
  InstrumentDef(id: 47, name: "Tibetan Bowl", icon: Icons.soup_kitchen, color: Color(0xFF26C6DA)),
  InstrumentDef(id: 48, name: "Ngachen", icon: Icons.notifications, color: Color(0xFF80DEEA),
    params: [ParamDef(name: "mallet_softness", label: "Softness", defaultValue: 0.8)]),
  InstrumentDef(id: 49, name: "Mridangam", icon: Icons.sports_kabaddi, color: Color(0xFFB71C1C)),
  InstrumentDef(id: 50, name: "Ghatam", icon: Icons.sports_kabaddi, color: Color(0xFFD84315)),
];
