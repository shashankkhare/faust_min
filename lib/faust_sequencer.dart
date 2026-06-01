import 'dart:math';

/// A helper class to simplify musical sequencing for Faust Physical Models.
///
/// [FaustSequencer] provides a high-level API for building note sequences
/// in terms of beats, durations, velocities, and legato articulation.
/// It handles beat-to-sample mapping and automatic articulation
/// (legato/staccato) for multi-instrument event management.
///
/// Use [addNote] to enqueue notes, then [buildEvents] to produce
/// sample-accurate [FaustEventData] ready for the native bridge.
class FaustSequencer {
  final double sampleRate;
  final double tempoBpm;
  final List<FaustNote> _notes = [];

  FaustSequencer({
    this.sampleRate = 44100.0,
    this.tempoBpm = 120.0,
  });

  /// Adds a note to the sequence.
  /// [beat] is the starting beat (0-indexed).
  /// [duration] is the length in beats (e.g., 1.0 for a quarter note).
  /// [velocity] is the strike strength or breath pressure (0.0 to 1.0).
  /// [legato] if true, the breath won't stop before the next note if it overlaps.
  void addNote({
    required int instrumentId,
    required double pitch,
    required double beat,
    double duration = 0.9,
    double velocity = 0.8,
    bool legato = false,
    int paramId = 0,
  }) {
    _notes.add(FaustNote(
      instrumentId: instrumentId,
      pitch: pitch,
      beat: beat,
      duration: duration,
      velocity: velocity,
      legato: legato,
      paramId: paramId,
    ));
  }

  /// Clears all notes from the sequencer.
  void clear() {
    _notes.clear();
  }

  /// Renders the sequence into a list of [FaustEventData] ready for the native bridge.
  /// [autoDecayMs] is the micro-gap between staccato notes to ensure clean re-strikes.
  List<FaustEventData> buildEvents({double autoDecayMs = 10.0}) {
    final List<FaustEventData> events = <FaustEventData>[];
    final double samplesPerBeat = (60.0 / tempoBpm) * sampleRate;
    final int autoDecaySamples = (autoDecayMs * sampleRate / 1000.0).toInt();

    // Group notes by instrument to handle overlaps/slurs
    final Map<int, List<FaustNote>> instrumentTracks = {};
    for (var note in _notes) {
      instrumentTracks.putIfAbsent(note.instrumentId, () => []).add(note);
    }

    for (var entry in instrumentTracks.entries) {
      final int instId = entry.key;
      final List<FaustNote> trackNotes = entry.value;
      trackNotes.sort((a, b) => a.beat.compareTo(b.beat));

      for (int i = 0; i < trackNotes.length; i++) {
        final note = trackNotes[i];
        final int startSample = (note.beat * samplesPerBeat).toInt();
        final int durationSamples = (note.duration * samplesPerBeat).toInt();
        final int endSample = startSample + durationSamples;

        // 1. Set Frequency
        events.add(FaustEventData(
          sampleOffset: startSample,
          instrumentId: instId,
          eventType: 1, // SetFreq
          value: note.pitch,
        ));

        // 2. Start Note (Strike/Breath)
        events.add(FaustEventData(
          sampleOffset: startSample,
          instrumentId: instId,
          eventType: 0, // Strike
          value: note.velocity,
          paramId: note.paramId,
        ));

        // 3. Handle Note Off or Slur
        bool isSlurred = false;
        if (i < trackNotes.length - 1) {
          final nextNote = trackNotes[i + 1];
          final int nextStart = (nextNote.beat * samplesPerBeat).toInt();
          
          // If the next note starts exactly at or before our end, and it's legato
          if (nextStart <= endSample && (note.legato || nextNote.legato)) {
            isSlurred = true;
          }
        }

        if (!isSlurred) {
          // Normal note: Insert a micro-decay before the end to ensure separation
          final int stopSample = max(startSample + 100, endSample - autoDecaySamples);
          events.add(FaustEventData(
            sampleOffset: stopSample,
            instrumentId: instId,
            eventType: 0, // Stop Breath/Strike
            value: 0.0,
          ));
        }
      }
    }

    events.sort((FaustEventData a, FaustEventData b) => a.sampleOffset.compareTo(b.sampleOffset));
    return events;
  }
}

/// A sample-accurate event record for passing to the native sequencer bridge.
///
/// [sampleOffset] is the position in samples from the start of playback.
/// [instrumentId] selects which instrument the event targets.
/// [eventType] 0=strike/stop, 1=set frequency.
/// [value] is the primary parameter (pitch, velocity).
/// [paramId] is an optional extended parameter selector.
class FaustEventData {
  final int sampleOffset;
  final int instrumentId;
  final int eventType;
  final double value;
  final int paramId;

  FaustEventData({
    required this.sampleOffset,
    required this.instrumentId,
    required this.eventType,
    required this.value,
    this.paramId = 0,
  });
}

/// A single note event within a [FaustSequencer] sequence.
///
/// Contains the instrument ID, pitch, timing, velocity, articulation flag,
/// and an optional parameter ID for extended control.
class FaustNote {
  final int instrumentId;
  final double pitch;
  final double beat;
  final double duration;
  final double velocity;
  final bool legato;
  final int paramId;

  FaustNote({
    required this.instrumentId,
    required this.pitch,
    required this.beat,
    required this.duration,
    required this.velocity,
    required this.legato,
    this.paramId = 0,
  });
}
