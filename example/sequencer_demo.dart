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

import 'dart:ffi';
import 'dart:math' as math;
import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';
import 'package:ffi/ffi.dart';

/// A pure Dart usage guide for the Native MIDI-style Sequencer.
/// This demonstrates how to build complex, sample-accurate rhythms.
void main() {
  const double sampleRate = 44100.0;
  const double tempoBpm = 120.0;
  const double durationSec = 4.0; // 2 bars at 120 BPM
  final int totalSamples = (durationSec * sampleRate).toInt();

  // --- 1. Define Patterns ---
  // Uppercase = Accent (v=1.0), Lowercase = Soft (v=0.6), '.' = Rest
  const String tablaPattern = "D . n t G . k . D n t . G k . .";
  const String rockPattern =  "K . H . S . H . K K H . S . H R";
  const String bellPattern =  ". . . . . . . . . . . . . . . B";

  final List<FaustTriggerData> triggers = [];

  final double secondsPerBeat = 60.0 / tempoBpm;
  final double secondsPerStep = secondsPerBeat / 4.0; // 16th notes
  final int samplesPerStep = (secondsPerStep * sampleRate).floor();

  // --- 2. Compose Tabla Sequence (Kit IDs 0 & 1) ---
  for (int i = 0; i < tablaPattern.length; i++) {
    int offset = i * samplesPerStep;
    String stroke = tablaPattern[i];
    if (stroke == ' ' || stroke == '.') continue;

    double vel = (stroke == stroke.toUpperCase()) ? 1.0 : 0.6;
    String type = stroke.toLowerCase();

    switch (type) {
      case 'd': // Dhin (Combo)
        triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 0, velocity: vel * 0.8, param: 0.0));
        triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 1, velocity: vel, param: 1.1)); // Open + Slight Meend
        break;
      case 'n': // Na (Open)
        triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 0, velocity: vel, param: 0.0));
        break;
      case 't': // Ta (Mute)
        triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 0, velocity: vel, param: 1.0));
        break;
      case 'g': // Ge (Open Bass)
        triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 1, velocity: vel, param: 1.2)); // Meend slide
        break;
      case 'k': // Ka (Mute Bass)
        triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 1, velocity: vel, param: 1.0));
        break;
    }
  }

  // --- 3. Compose Rock Groove (Kit IDs 2-6) ---
  // We can layer this on top of the Tabla!
  for (int i = 0; i < rockPattern.length; i++) {
    int offset = i * samplesPerStep;
    String stroke = rockPattern[i];
    if (stroke == ' ' || stroke == '.') continue;

    double vel = (stroke == stroke.toUpperCase()) ? 1.0 : 0.5;
    String type = stroke.toLowerCase();

    switch (type) {
      case 'k': triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 2, velocity: vel)); break; // Kick
      case 's': triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 3, velocity: vel)); break; // Snare
      case 'h': triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 4, velocity: vel, param: 0.2)); break; // HiHat (partially open)
      case 'r': triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 6, velocity: vel)); break; // Ride
    }
  }

  // --- 4. Compose Bell Accents (Kit ID 7) ---
  for (int i = 0; i < bellPattern.length; i++) {
    int offset = i * samplesPerStep;
    String stroke = bellPattern[i];
    if (stroke == ' ' || stroke == '.') continue;

    double vel = (stroke == stroke.toUpperCase()) ? 1.0 : 0.5;
    if (stroke.toLowerCase() == 'b') {
      // Use param as frequency override (e.g. 880Hz for a high chime)
      triggers.add(FaustTriggerData(sampleOffset: offset, instrumentId: 7, velocity: vel, param: 880.0));
    }
  }

  // --- 5. Subnotes Example (Micro-timing) ---
  // Let's add a rapid 32nd-note snare roll at the end of the second bar
  int lastBarStart = 12 * samplesPerStep;
  for (int i = 0; i < 4; i++) {
    int microOffset = lastBarStart + (i * (samplesPerStep ~/ 2));
    triggers.add(FaustTriggerData(sampleOffset: microOffset, instrumentId: 3, velocity: 0.4 + (i * 0.1)));
  }

  // --- 6. Render via Native Engine ---
  final Pointer<Float> outputBuffer = malloc<Float>(totalSamples);
  
  try {
    print("Generating ${triggers.length} triggers over ${durationSec}s...");
    
    FaustMin.renderSequencedAudio(
      triggers: triggers,
      baseFreq: 140.0, // Base tuning for Tabla Dayan
      sampleRate: sampleRate,
      totalSamples: totalSamples,
      outputBuffer: outputBuffer,
    );

    // Convert to Dart list for playback or saving
    final Float32List audioData = outputBuffer.asTypedList(totalSamples);
    
    double peak = 0.0;
    for (var s in audioData) {
      if (s.abs() > peak) peak = s.abs();
    }
    
    print("Success! Generated sequence with peak amplitude: ${peak.toStringAsFixed(2)}");
    print("The audio is now ready in native memory at address: ${outputBuffer.address}");

  } finally {
    malloc.free(outputBuffer);
  }
}
