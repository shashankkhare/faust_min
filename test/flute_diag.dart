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

import 'dart:async';
import 'package:faust_min/faust_min.dart';

void main() async {
  print("\n=== Faust Flute Diagnostic Integration Test ===");

  // 1. Prepare Valid UML Schedule String
  // Using lower basefreq (300Hz) and lower velocity (6) to avoid overblowing
  final String umlScheduleString = """
notation: Indian
instrument: FL
exectype: compiled
bpm: 80
grid: 1
basefreq: 300.0
6Sa . 6Re . 6Ga . 6Ma . 6Pa . 6Dha . 6Ni . 6Sa^ .
""";

  print("[Test] Compiling Flute timeline schedule...");

  // 2. Instantiate persistent timeline object model
  final umlSequence = UMLSequence("FluteScale", 10, umlScheduleString);
  print("[Test] SUCCESS: UMLSequence initialized.");

  // 3. Create Orchestrator
  final orchestrator = SequenceOrchestrator();
  print("[Test] SUCCESS: SequenceOrchestrator allocated.");

  // 4. Register sequence
  orchestrator.addSequence("FluteTrack", umlSequence);
  print("[Test] Registered 'FluteTrack'.");

  // 5. Trigger Playback
  print("[Test] Starting Playback...");
  orchestrator.play("FluteTrack");
  
  print("[Test] Playing for 8 seconds. Please verify melodic transitions...");
  for (int i = 8; i > 0; i--) {
      print("  $i seconds remaining...");
      await Future.delayed(const Duration(seconds: 1));
  }

  // 6. Cleanup
  print("[Test] Cleaning up...");
  orchestrator.stop();
  umlSequence.dispose();
  orchestrator.dispose();

  print("=== Diagnostic Verification Completed ===\n");
}
