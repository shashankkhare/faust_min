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

import 'faust_sequencer.dart';

/// Parses Indian 22-Shruti notation into a playable [FaustSequencer] sequence.
///
/// Supports header directives (`basefreq`, `bpm`, `grid`) followed by
/// note blocks in the format `<octave><shruti>` (e.g., `4Sa`, `5Re`).
/// Handles automatic duration via dot-continuation, meend glides via `^`,
/// and applies 22-Shruti just-intonation ratios for microtonal accuracy.
class FaustShrutiParser {
  // 22-Shruti Ratios (Standard 5-limit / Just Intonation based)
  static const Map<String, double> _ratios = {
    'Sa': 1.0,
    'r1': 256.0 / 243.0,   // Komal Re (Lower)
    'r2': 16.0 / 15.0,     // Komal Re (Higher)
    'R1': 10.0 / 9.0,      // Shuddha Re (Lower)
    'R2': 9.0 / 8.0,       // Shuddha Re (Higher)
    'g1': 32.0 / 27.0,     // Komal Ga (Lower)
    'g2': 6.0 / 5.0,       // Komal Ga (Higher)
    'G1': 5.0 / 4.0,       // Shuddha Ga (Lower)
    'G2': 81.0 / 64.0,     // Shuddha Ga (Higher)
    'M1': 4.0 / 3.0,       // Shuddha Ma (Lower)
    'M2': 27.0 / 20.0,     // Shuddha Ma (Higher)
    'm1': 45.0 / 32.0,     // Tivra Ma (Lower)
    'm2': 64.0 / 45.0,     // Tivra Ma (Higher)
    'Pa': 1.5,             // Pancham (Perfect Fifth)
    'd1': 128.0 / 81.0,    // Komal Dha (Lower)
    'd2': 8.0 / 5.0,       // Komal Dha (Higher)
    'D1': 5.0 / 3.0,       // Shuddha Dha (Lower)
    'D2': 27.0 / 16.0,     // Shuddha Dha (Higher)
    'n1': 16.0 / 9.0,      // Komal Ni (Lower)
    'n2': 9.0 / 5.0,       // Komal Ni (Higher)
    'N1': 15.0 / 8.0,      // Shuddha Ni (Lower)
    'N2': 243.0 / 128.0,   // Shuddha Ni (Higher)
  };

  static FaustSequencer parse(String input) {
    final lines = input.trim().split('\n');
    double baseFreq = 261.63; // Default C4
    double bpm = 120.0;
    int grid = 4;
    String patternStr = "";

    // Parse Header
    for (var line in lines) {
      if (line.contains(':')) {
        final parts = line.split(':');
        final key = parts[0].trim().toLowerCase();
        final val = parts[1].trim();
        if (key == 'basefreq') baseFreq = double.tryParse(val) ?? baseFreq;
        if (key == 'bpm') bpm = double.tryParse(val) ?? bpm;
        if (key == 'grid') grid = int.tryParse(val) ?? grid;
      } else if (line.trim().isNotEmpty) {
        patternStr += " ${line.trim()}";
      }
    }

    final sequencer = FaustSequencer(tempoBpm: bpm);
    final double stepDuration = 1.0 / grid;
    final List<String> blocks = patternStr.trim().split(RegExp(r'\s+'));

    // State tracking for each instrument
    final Map<int, double> lastFreq = {};

    for (int i = 0; i < blocks.length; i++) {
      final String block = blocks[i];
      final double currentBeat = i * stepDuration;

      if (block == '.') {
        // Continuity: Handled by extending duration in the addNote call later or just skipping
        continue;
      } else if (block == '^') {
        // Meend: Look ahead for target note
        continue; 
      } else if (block == ' ') {
        // Stop is implicit if no note is played, but we can send a 0-velocity event
        continue;
      }

      // Try to parse InstrumentID + Shruti (e.g., 12Sa, 1Pa)
      final match = RegExp(r'^(\d+)([a-zA-Z12]+)$').firstMatch(block);
      if (match != null) {
        final int instId = int.parse(match.group(1)!);
        String shruti = match.group(2)!;
        
        // Correct Pa if lowercase pa was used
        if (shruti == "pa") shruti = "Pa";
        if (shruti == "sa") shruti = "Sa";

        if (_ratios.containsKey(shruti)) {
          final double freq = baseFreq * _ratios[shruti]!;
          
          // Determine duration by looking ahead for '.'
          double duration = stepDuration;
          int lookAhead = i + 1;
          while (lookAhead < blocks.length && blocks[lookAhead] == '.') {
            duration += stepDuration;
            lookAhead++;
          }

          // Check if previous block was Meend '^'
          if (i > 0 && blocks[i-1] == '^' && lastFreq.containsKey(instId)) {
             // Generate a sweep from lastFreq[instId] to freq
             _generateMeend(sequencer, instId, lastFreq[instId]!, freq, currentBeat - stepDuration, stepDuration);
          }

          sequencer.addNote(
            instrumentId: instId,
            pitch: freq,
            beat: currentBeat,
            duration: duration * 0.95,
            velocity: 0.8,
            legato: lookAhead < blocks.length && blocks[lookAhead] == '^',
          );

          lastFreq[instId] = freq;
        }
      }
    }

    return sequencer;
  }

  static void _generateMeend(FaustSequencer seq, int instId, double from, double to, double startBeat, double durationBeat) {
    // Generate 10 small frequency steps for a smooth sweep
    const int steps = 10;
    for (int i = 1; i <= steps; i++) {
      double t = i / steps;
      double freq = from + (to - from) * t;
      seq.addNote(
        instrumentId: instId,
        pitch: freq,
        beat: startBeat + (durationBeat * t),
        duration: (durationBeat / steps) * 2.0,
        velocity: 0.8,
        legato: true,
      );
    }
  }
}
