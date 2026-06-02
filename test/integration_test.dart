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
  print("\n=== Faust Native Bridge: Multi-Track Sequence Test ===");

  // 0. Initialize and Start the Mixer (The Heartbeat)
  final mixer = FaustMixer.instance;
  print("[Test] Starting FaustMixer...");
  if (!mixer.start()) {
    print("[Test Error] Failed to start FaustMixer hardware driver.");
    return;
  }
  mixer.masterGain = 0.8;

  // 1. Flute Scale (Instrument ID 10)
  final String fluteSchedule = """
  instrument: flute
  exectype: interpreter
  notation: Indian
  basefreq: 400
  bpm: 60
  grid: 4
  Sa Re Ga Ma Pa Dha Ni Sa
  """;

  // 2. Dayan Rhythmic Pattern (Instrument ID 0)
  final String dayanSchedule = """
notation: Indian
instrument: DY
bpm: 120
grid: 2
basefreq: 300.0
9Na . 8Ti . 9Na . 8Ti . 8Tu . . . 9Na . 8Ti .
""";

  print("[Test] Compiling sequences...");
  final fluteSequence = UMLSequence("FluteScale", 10, fluteSchedule);
  final dayanSequence = UMLSequence("DayanBeat", 0, dayanSchedule);
  
  final orchestrator = SequenceOrchestrator();

  // 3. Register Tracks with Orchestrator (The Brain)
  print("[Test] Adding sequences to Orchestrator...");
  orchestrator.addSequence("Flute", fluteSequence);
  orchestrator.addSequence("Dayan", dayanSequence);

  // 3.1 SUPPLY INSTRUMENTS TO MIXER (The Heartbeat)
  // Strict Separation: Orchestrator manages UML, Mixer manages Audio Nodes.
  print("[Test] Supplying instruments to Mixer...");
  mixer.registerInstrument(fluteSequence.getFaustInstrument(), 0.8);
  mixer.registerInstrument(dayanSequence.getFaustInstrument(), 0.8);

  print("[Test] Starting Multi-Track Playback...");
  // orchestrator.play("Flute");
  orchestrator.play("Dayan");

  print("[Test] Playing for 10 seconds. Listen for the Flute scale and Tabla beat...");
  for (int i = 10; i > 0; i--) {
    print("  $i seconds remaining...");
    await Future.delayed(const Duration(seconds: 1));
  }

  // 4. Cleanup
  print("[Test] Cleaning up...");
  orchestrator.stop();
  mixer.stop(); // Release the hardware
  fluteSequence.dispose();
  dayanSequence.dispose();
  // No orchestrator.dispose() for singleton safety

  print("=== Multi-Track Test Completed ===\n");
}
