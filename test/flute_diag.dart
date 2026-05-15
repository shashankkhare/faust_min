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
