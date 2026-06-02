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

/// Parses the Universal Music Pattern Language (UMPL) into a [FaustSequencer].
///
/// UMPL extends basic Shruti notation with per-instrument base frequency and
/// gain overrides, inline mathematical expressions for microtonal ratios, and
/// meend glide articulation. Format:
///
/// ```
/// basefreq: 444.0
/// bpm: 120
/// grid: 8
/// 1: 444.0 (gain=0.8)
/// 2: 222.0
///
/// 1Sa . 1Re . 2Pa . . .
/// ```
class UmplParser {
  static const Map<String, double> _ratios = {
    'Sa': 1.0, 'r1': 256.0/243.0, 'r2': 16.0/15.0, 'R1': 10.0/9.0, 'R2': 9.0/8.0,
    'g1': 32.0/27.0, 'g2': 6.0/5.0, 'G1': 5.0/4.0, 'G2': 81.0/64.0,
    'M1': 4.0/3.0, 'M2': 27.0/20.0, 'm1': 45.0/32.0, 'm2': 64.0/45.0,
    'Pa': 1.5, 'd1': 128.0/81.0, 'd2': 8.0/5.0, 'D1': 5.0/3.0, 'D2': 27.0/16.0,
    'n1': 16.0/9.0, 'n2': 9.0/5.0, 'N1': 15.0/8.0, 'N2': 243.0/128.0,
  };

  static FaustSequencer parse(String input) {
    final lines = input.trim().split('\n');
    double baseFreq = 261.63;
    double bpm = 120.0;
    int grid = 4;
    String rawPattern = "";
    final Map<int, double> instrumentBaseFreqs = {};
    final Map<int, double> instrumentGains = {};

    for (var line in lines) {
      if (line.contains(':')) {
        final parts = line.split(':');
        final key = parts[0].trim().toLowerCase();
        final valSection = parts[1].trim();
        
        final int? instId = int.tryParse(key);
        if (instId != null) {
          // Parse "Freq (gain=X)"
          final freqMatch = RegExp(r'^([\d.]+)(?:\s*\(gain=([\d.]+)\))?').firstMatch(valSection);
          if (freqMatch != null) {
            instrumentBaseFreqs[instId] = double.tryParse(freqMatch.group(1)!) ?? 0.0;
            if (freqMatch.group(2) != null) {
              instrumentGains[instId] = double.tryParse(freqMatch.group(2)!) ?? 1.0;
            }
          }
        } else if (key == 'basefreq') {
          baseFreq = double.tryParse(valSection) ?? baseFreq;
        } else if (key == 'bpm') {
          bpm = double.tryParse(valSection) ?? bpm;
        } else if (key == 'grid') {
          grid = int.tryParse(valSection) ?? grid;
        }
      } else {
        rawPattern += line.trim();
      }
    }

    instrumentBaseFreqs.putIfAbsent(1, () => baseFreq / 2.0);
    instrumentBaseFreqs.putIfAbsent(0, () => baseFreq);

    final sequencer = FaustSequencer(tempoBpm: bpm);
    final double stepDur = 1.0 / grid;
    final tokenRegex = RegExp(r'(\d+)(?:\(([^)]+)\)|([a-zA-Z12]+))|([._^])');
    final matches = tokenRegex.allMatches(rawPattern).toList();
    final Map<int, double> lastFreq = {};

    for (int i = 0; i < matches.length; i++) {
      final match = matches[i];
      final double currentBeat = i * stepDur;

      if (match.group(4) != null) continue;

      final int instId = int.parse(match.group(1)!);
      final String expr = (match.group(2) ?? match.group(3) ?? "Sa");
      final double instBase = instrumentBaseFreqs[instId] ?? baseFreq;
      final double instGain = instrumentGains[instId] ?? 1.0;
      
      double ratio = _evaluateExpression(expr);
      final double freq = instBase * ratio;
      
      double duration = stepDur;
      int lookAhead = i + 1;
      while (lookAhead < matches.length && matches[lookAhead].group(4) == '.') {
        duration += stepDur;
        lookAhead++;
      }

      if (i > 0 && matches[i-1].group(4) == '^' && lastFreq.containsKey(instId)) {
         _generateMeend(sequencer, instId, lastFreq[instId]!, freq, currentBeat - stepDur, stepDur, instGain);
      }

      sequencer.addNote(
        instrumentId: instId, pitch: freq, beat: currentBeat,
        duration: duration * 0.95, velocity: 0.8 * instGain,
        legato: lookAhead < matches.length && matches[lookAhead].group(4) == '^',
      );
      lastFreq[instId] = freq;
    }
    return sequencer;
  }

  static double _evaluateExpression(String expr) {
    if (_ratios.containsKey(expr)) return _ratios[expr]!;
    String processed = expr;
    _ratios.forEach((key, val) => processed = processed.replaceAll(key, val.toString()));
    try { return _evalMath(processed); } catch (e) { return 1.0; }
  }

  static double _evalMath(String expression) {
    final opMatch = RegExp(r'([\d.]+)\s*([\+\-\*\/])\s*([\d.]+)').firstMatch(expression);
    if (opMatch != null) {
      double a = double.parse(opMatch.group(1)!);
      String op = opMatch.group(2)!;
      double b = double.parse(opMatch.group(3)!);
      if (op == '+') return a + b;
      if (op == '-') return a - b;
      if (op == '*') return a * b;
      if (op == '/') return a / b;
    }
    return double.tryParse(expression) ?? 1.0;
  }

  static void _generateMeend(FaustSequencer seq, int instId, double from, double to, double startBeat, double durationBeat, double gain) {
    const int steps = 10;
    for (int i = 1; i <= steps; i++) {
      double t = i / steps;
      seq.addNote(
        instrumentId: instId, pitch: from + (to - from) * t,
        beat: startBeat + (durationBeat * t), duration: (durationBeat / steps) * 2.0,
        velocity: 0.8 * gain, legato: true,
      );
    }
  }
}
