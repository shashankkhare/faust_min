import 'faust_sequencer.dart';

/// Compiles a high-level pattern specification into a playable [FaustSequencer].
///
/// [FaustPatternLanguage] accepts a `Map<String, dynamic>` spec with tempo,
/// grid, and tracks. Each track maps an instrument name to a string of
/// space-separated steps: note names (e.g. `C4`, `Sa`), rhythmic strikes (`X`, `x`),
/// continuations (`.`), legato ties (`-`), and parameter overrides (`(p=1)`).
class FaustPatternLanguage {
  static const Map<String, int> _instrumentMap = {
    'dayan': 0, 'bayan': 1, 'kick': 2, 'snare': 3,
    'hihat': 4, 'tom': 5, 'ride': 6, 'bell': 7,
    'bowl': 8, 'sitar': 9, 'flute': 10, 'tanpura': 11,
    'piano': 12, 'sax': 13,
  };

  static const Map<String, double> _noteMap = {
    'C3': 130.81, 'C#3': 138.59, 'D3': 146.83, 'Eb3': 155.56, 'E3': 164.81, 'F3': 174.61, 'F#3': 185.00, 'G3': 196.00, 'Ab3': 207.65, 'A3': 220.00, 'Bb3': 233.08, 'B3': 246.94,
    'C4': 261.63, 'C#4': 277.18, 'D4': 293.66, 'Eb4': 311.13, 'E4': 329.63, 'F4': 349.23, 'F#4': 369.99, 'G4': 392.00, 'Ab4': 415.30, 'A4': 440.00, 'Bb4': 466.16, 'B4': 493.88,
    'C5': 523.25, 'C#5': 554.37, 'D5': 587.33, 'Eb5': 622.25, 'E5': 659.25, 'F5': 698.46, 'F#5': 739.99, 'G5': 783.99, 'Ab5': 830.61, 'A5': 880.00, 'Bb5': 932.33, 'B5': 987.77,
    'Pa': 392.00, 'Sa': 523.25, 'Re': 587.33, 'Ga': 659.25, 'Ma': 698.46, 'Ni': 987.77,
  };

  static FaustSequencer compile(Map<String, dynamic> spec) {
    final double tempo = (spec['tempo'] ?? 120.0).toDouble();
    final double grid = (spec['grid'] ?? 4.0).toDouble(); // Steps per beat
    final Map<String, String> tracks = spec['tracks'] as Map<String, String>;
    
    final sequencer = FaustSequencer(tempoBpm: tempo);
    final double stepDuration = 1.0 / grid;

    tracks.forEach((instName, patternStr) {
      final int? instId = _instrumentMap[instName.toLowerCase()];
      if (instId == null) return;

      final List<String> steps = patternStr.trim().split(RegExp(r'\s+'));
      
      for (int i = 0; i < steps.length; i++) {
        final String step = steps[i];
        final double currentBeat = i * stepDuration;

        if (step == '.') continue;

        if (step == 'X' || step == 'x') {
          // Rhythmic Strike
          sequencer.addNote(
            instrumentId: instId,
            pitch: 0,
            beat: currentBeat,
            duration: stepDuration * 0.9,
            velocity: (step == 'X') ? 0.8 : 0.3,
          );
        } else if (_noteMap.containsKey(step)) {
          // Melodic Note
          bool isLegato = false;
          if (i + 1 < steps.length && steps[i + 1] == '-') {
            isLegato = true;
          }

          sequencer.addNote(
            instrumentId: instId,
            pitch: _noteMap[step]!,
            beat: currentBeat,
            duration: stepDuration * (isLegato ? 1.0 : 0.85),
            velocity: 0.8,
            legato: isLegato,
          );
        } else if (step.startsWith('(')) {
          // Parameter notation like (p=1)
          if (step.contains('p=')) {
             final pVal = int.tryParse(step.replaceAll(RegExp(r'[()p=]'), '')) ?? 0;
             sequencer.addNote(
               instrumentId: instId,
               pitch: 0,
               beat: currentBeat,
               duration: stepDuration,
               velocity: 0.8,
               paramId: pVal,
             );
          }
        }
      }
    });

    return sequencer;
  }
}
