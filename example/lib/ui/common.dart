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
import 'dart:math' as math;

class NoteMath {
  static const List<String> westernNotes = [
    'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'
  ];
  
  // Base frequency C1 = 32.70 Hz
  static double getFreq(int halfStepsFromC1) {
    return 32.703 * math.pow(2.0, halfStepsFromC1 / 12.0);
  }

  static String getNoteName(int halfStepsFromC1) {
    int octave = (halfStepsFromC1 / 12).floor() + 1;
    String note = westernNotes[halfStepsFromC1 % 12];
    return "$note$octave";
  }
}

class NoteSlider extends StatelessWidget {
  final int value;
  final ValueChanged<int> onChanged;
  final String label;
  const NoteSlider({super.key, required this.value, required this.onChanged, this.label = "Note"});

  @override
  Widget build(BuildContext context) {
    final freq = NoteMath.getFreq(value);
    return Column(
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Text("$label: ${NoteMath.getNoteName(value)}", 
              style: const TextStyle(color: Colors.amber, fontWeight: FontWeight.bold, fontSize: 16)),
            Text("${freq.toStringAsFixed(2)} Hz", 
              style: TextStyle(color: Colors.amber.withOpacity(0.7), fontSize: 14)),
          ],
        ),
        Slider(
          min: 0, max: 48, divisions: 48, // 4 Octaves from C1
          value: value.toDouble(),
          onChanged: (v) => onChanged(v.toInt()),
        ),
      ],
    );
  }
}

class BaseInstrumentCard extends StatelessWidget {
  final String title; final IconData icon; final Color color; final List<Widget> children;
  const BaseInstrumentCard({super.key, required this.title, required this.icon, required this.color, required this.children});
  @override
  Widget build(BuildContext context) {
    return Card(
      elevation: 12, margin: const EdgeInsets.all(12),
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
      child: Container(
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(16),
          gradient: LinearGradient(colors: [color.withOpacity(0.2), Colors.black12], begin: Alignment.topLeft, end: Alignment.bottomRight),
        ),
        padding: const EdgeInsets.all(20),
        child: Column(children: [
          Row(children: [Icon(icon, color: color, size: 28), const SizedBox(width: 12), Text(title, style: TextStyle(color: color, fontWeight: FontWeight.bold, fontSize: 22))]),
          const Divider(height: 30),
          ...children,
        ]),
      ),
    );
  }
}

Uint8List createWavFile(Float32List samples, int sampleRate, {int channels = 1}) {
  final int byteCount = samples.length * 2;
  final ByteData wav = ByteData(44 + byteCount);
  wav.setUint32(0, 0x52494646, Endian.big); // "RIFF"
  wav.setUint32(4, 36 + byteCount, Endian.little);
  wav.setUint32(8, 0x57415645, Endian.big); // "WAVE"
  wav.setUint32(12, 0x666d7420, Endian.big); // "fmt "
  wav.setUint32(16, 16, Endian.little);
  wav.setUint16(20, 1, Endian.little);
  wav.setUint16(22, channels, Endian.little);
  wav.setUint32(24, sampleRate, Endian.little);
  wav.setUint32(28, sampleRate * channels * 2, Endian.little);
  wav.setUint16(32, channels * 2, Endian.little);
  wav.setUint16(34, 16, Endian.little);
  wav.setUint32(36, 0x64617461, Endian.big); // "data"
  wav.setUint32(40, byteCount, Endian.little);
  for (int i = 0; i < samples.length; i++) {
    wav.setInt16(44 + i * 2, (samples[i].clamp(-1.0, 1.0) * 32767).toInt(), Endian.little);
  }
  return wav.buffer.asUint8List();
}
