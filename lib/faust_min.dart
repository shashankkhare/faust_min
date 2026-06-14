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
import 'dart:io';
import 'dart:typed_data';
import 'package:ffi/ffi.dart';

const String _libName = 'faust_min';

final DynamicLibrary _dylib = () {
  if (Platform.isMacOS || Platform.isIOS) {
    return DynamicLibrary.open('$_libName.framework/$_libName');
  }
  if (Platform.isAndroid || Platform.isLinux) {
    return DynamicLibrary.open('lib$_libName.so');
  }
  if (Platform.isWindows) {
    return DynamicLibrary.open('$_libName.dll');
  }
  throw UnsupportedError('Unknown platform: ${Platform.operatingSystem}');
}();

// --- Internal FFI Opaque Pointer Structures ---
final class NativeInstrumentOpaque extends Opaque {}
final class NativeSequenceOpaque extends Opaque {}
final class NativeMixerOpaque extends Opaque {}
final class NativeOrchestratorOpaque extends Opaque {}

// --- FaustMixer Typedefs ---
typedef _c_mixer_get_instance = Pointer<NativeMixerOpaque> Function();
typedef _dart_mixer_get_instance = Pointer<NativeMixerOpaque> Function();

typedef _c_mixer_init = Void Function(Pointer<NativeMixerOpaque> mixer, Float sampleRate);
typedef _dart_mixer_init = void Function(Pointer<NativeMixerOpaque> mixer, double sampleRate);

typedef _c_mixer_start = Int32 Function(Pointer<NativeMixerOpaque> mixer);
typedef _dart_mixer_start = int Function(Pointer<NativeMixerOpaque> mixer);

typedef _c_mixer_stop = Void Function(Pointer<NativeMixerOpaque> mixer);
typedef _dart_mixer_stop = void Function(Pointer<NativeMixerOpaque> mixer);

typedef _c_mixer_clear_all = Void Function(Pointer<NativeMixerOpaque> mixer);
typedef _dart_mixer_clear_all = void Function(Pointer<NativeMixerOpaque> mixer);

typedef _c_mixer_get_sr = Float Function(Pointer<NativeMixerOpaque> mixer);
typedef _dart_mixer_get_sr = double Function(Pointer<NativeMixerOpaque> mixer);

typedef _c_mixer_set_gain = Void Function(Pointer<NativeMixerOpaque> mixer, Float gain);
typedef _dart_mixer_set_gain = void Function(Pointer<NativeMixerOpaque> mixer, double gain);

typedef _c_mixer_set_inst_weight = Void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, Float weight);
typedef _dart_mixer_set_inst_weight = void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, double weight);

typedef _c_mixer_register_inst = Int32 Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, Float weight);
typedef _dart_mixer_register_inst = int Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, double weight);

typedef _c_mixer_unregister_inst = Void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst);
typedef _dart_mixer_unregister_inst = void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst);


// --- Flat API Bindings Signatures ---
typedef _c_sequence_create = Pointer<NativeSequenceOpaque> Function(Pointer<Utf8>, Int32, Pointer<Utf8>);
typedef _dart_sequence_create = Pointer<NativeSequenceOpaque> Function(Pointer<Utf8>, int, Pointer<Utf8>);

typedef _c_sequence_destroy = Void Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_destroy = void Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_get_bpm = Double Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_bpm = double Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_get_grid = Int32 Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_grid = int Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_get_basefreq = Double Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_basefreq = double Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_set_basefreq = Void Function(Pointer<NativeSequenceOpaque>, Double);
typedef _dart_sequence_set_basefreq = void Function(Pointer<NativeSequenceOpaque>, double);

typedef _c_sequence_get_instrument = Pointer<NativeInstrumentOpaque> Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_instrument = Pointer<NativeInstrumentOpaque> Function(Pointer<NativeSequenceOpaque>);

typedef _c_inst_create = Pointer<NativeInstrumentOpaque> Function(Int32, Int32, Float);
typedef _dart_inst_create = Pointer<NativeInstrumentOpaque> Function(int, int, double);

typedef _c_inst_destroy = Void Function(Pointer<NativeInstrumentOpaque>);
typedef _dart_inst_destroy = void Function(Pointer<NativeInstrumentOpaque>);

typedef _c_inst_set_param = Void Function(Pointer<NativeInstrumentOpaque>, Pointer<Utf8>, Float);
typedef _dart_inst_set_param = void Function(Pointer<NativeInstrumentOpaque>, Pointer<Utf8>, double);

typedef _c_inst_note_on = Void Function(Pointer<NativeInstrumentOpaque>, Float, Float, Float);
typedef _dart_inst_note_on = void Function(Pointer<NativeInstrumentOpaque>, double, double, double);

typedef _c_inst_note_off = Void Function(Pointer<NativeInstrumentOpaque>);
typedef _dart_inst_note_off = void Function(Pointer<NativeInstrumentOpaque>);

typedef _c_inst_render = Void Function(Pointer<NativeInstrumentOpaque>, Pointer<Float>, Int32);
typedef _dart_inst_render = void Function(Pointer<NativeInstrumentOpaque>, Pointer<Float>, int);

typedef _c_inst_get_sample_rate = Float Function(Pointer<NativeInstrumentOpaque>);
typedef _dart_inst_get_sample_rate = double Function(Pointer<NativeInstrumentOpaque>);

typedef _c_orch_create = Pointer<NativeOrchestratorOpaque> Function();
typedef _dart_orch_create = Pointer<NativeOrchestratorOpaque> Function();

typedef _c_orch_destroy = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_destroy = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_add_seq = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<NativeSequenceOpaque>);
typedef _dart_orch_add_seq = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<NativeSequenceOpaque>);

typedef _c_orch_play = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_play = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);



typedef _c_orch_stop = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_stop = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_pause = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_pause = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_resume = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_resume = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_mute_track = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Int32);
typedef _dart_orch_mute_track = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, int);

typedef _c_orch_set_param = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<Utf8>, Float);
typedef _dart_orch_set_param = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<Utf8>, double);

typedef _c_orch_set_weight = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Float);
typedef _dart_orch_set_weight = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, double);

typedef _c_orch_poll_finished = Pointer<Utf8> Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_poll_finished = Pointer<Utf8> Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_load_song = Int32 Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_load_song = int Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_unload_song = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_unload_song = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_play_song = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_play_song = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_stop_song = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_stop_song = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

// --- Classes ---

/// A physically modeled instrument instance backed by a real-time Faust DSP engine.
///
/// [FaustInstrument] wraps a native C++ instrument heap object accessed via FFI.
/// Each instrument encapsulates a complete physical model (e.g., flute, sitar, tabla)
/// with parameters for frequency, velocity, articulation, and real-time modulation.
///
/// Instruments are rendered by [FaustMixer] and can be sequenced via [UMLSequence]
/// and [SequenceOrchestrator]. Multiple voices are allocated dynamically by the
/// native engine for polyphonic playback.
///
/// {@tool dartpad}
/// ```dart
/// final flute = FaustInstrument(10, DSPExecutionType.StaticCompiled, 48000);
/// flute.noteOn(freq: 440.0, velocity: 0.8);
/// // ... let it ring ...
/// flute.noteOff();
/// ```
/// {@end-tool}
class FaustInstrument {
  final Pointer<NativeInstrumentOpaque> _handle;
  final bool _owned;
  bool _isDisposed = false;

  static late final _funcCreate = _dylib.lookupFunction<_c_inst_create, _dart_inst_create>('instrument_create');
  static late final _funcDestroy = _dylib.lookupFunction<_c_inst_destroy, _dart_inst_destroy>('instrument_destroy');
  static late final _funcSetParam = _dylib.lookupFunction<_c_inst_set_param, _dart_inst_set_param>('instrument_set_parameter');
  static late final _funcNoteOn = _dylib.lookupFunction<_c_inst_note_on, _dart_inst_note_on>('instrument_note_on');
  static late final _funcNoteOff = _dylib.lookupFunction<_c_inst_note_off, _dart_inst_note_off>('instrument_note_off');
  static late final _funcRender = _dylib.lookupFunction<_c_inst_render, _dart_inst_render>('instrument_render');
  static late final _funcGetSampleRate = _dylib.lookupFunction<_c_inst_get_sample_rate, _dart_inst_get_sample_rate>('instrument_get_sample_rate');

  /// Wraps an existing native instrument pointer.
  ///
  /// [handle] must be a valid pointer from the native layer.
  /// When [_owned] is true the pointer is freed on [dispose].
  FaustInstrument(this._handle, [this._owned = false]);

  /// Creates a [FaustInstrument] from an existing native pointer (not owned).
  ///
  /// The caller retains ownership — [dispose] will NOT free the native handle.
  factory FaustInstrument.fromNative(Pointer<NativeInstrumentOpaque> handle) => FaustInstrument(handle);

  /// Create a new instrument instance by ID.
  ///
  /// [instrumentID] is the instrument type (0-48).
  /// [execType] is 0 for StaticCompiled, 1 for InterpretedByte.
  factory FaustInstrument.create(int instrumentID, int execType, double sampleRate) {
    final handle = _funcCreate(instrumentID, execType, sampleRate);
    return FaustInstrument(handle, true);
  }

  /// Set a named parameter on the native DSP instrument.
  ///
  /// Common parameters: `freq`, `velocity`, `strike`, `gain`, `vibrato_rate`,
  /// `vibrato_depth`, `mallet_softness`, etc.
  void setParameter(String name, double value) {
    if (_isDisposed || _handle == nullptr) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcSetParam(_handle, namePtr.cast(), value);
    } finally {
      malloc.free(namePtr);
    }
  }

  /// Trigger a note-on event.
  ///
  /// [freq] — frequency in Hz (-1 uses the DSP default).
  /// [velocity] — amplitude 0.0–1.0 (-1 uses the DSP default).
  /// [strike] — percussion articulation index (-1 uses the DSP default).
  void noteOn({double freq = -1.0, double velocity = -1.0, double strike = -1.0}) {
    if (_isDisposed || _handle == nullptr) return;
    _funcNoteOn(_handle, freq, velocity, strike);
  }

  /// Release the current note (note-off).
  void noteOff() {
    if (_isDisposed) return;
    _funcNoteOff(_handle);
  }

  /// The sample rate this instrument was created with.
  double get sampleRate => _isDisposed ? 0.0 : _funcGetSampleRate(_handle);

  /// Render the next block of audio samples into [buffer].
  ///
  /// [buffer] must be a pre-allocated [Float32List] of the desired frame count.
  void render(Float32List buffer) {
    if (_isDisposed || _handle == nullptr) return;
    final ptr = malloc<Float>(buffer.length);
    try {
      _funcRender(_handle, ptr, buffer.length);
      final view = ptr.asTypedList(buffer.length);
      buffer.setAll(0, view);
    } finally {
      malloc.free(ptr);
    }
  }

  void dispose() {
    if (_isDisposed) return;
    _isDisposed = true;
    if (_owned && _handle != nullptr) {
      _funcDestroy(_handle);
    }
  }

  /// The native FFI pointer backing this instrument.
  Pointer<NativeInstrumentOpaque> get nativePointer => _handle;
}

/// A parsed UML (Universal Music Language) sequence backed by a native timeline object.
///
/// [UMLSequence] parses a plain-text musical notation string (supporting Western,
/// Indian Sargam, and percussion strokes) into a sample-accurate event timeline.
/// The parsed sequence is stored in the native C++ engine for zero-latency playback.
///
/// Create a sequence, hand it to [SequenceOrchestrator.addSequence], and play.
/// Call [dispose] when done to free native memory.
class UMLSequence {
  late final Pointer<NativeSequenceOpaque> _handle;
  bool _isDisposed = false;

  static late final _funcCreate = _dylib.lookupFunction<_c_sequence_create, _dart_sequence_create>('sequence_create');
  static late final _funcDestroy = _dylib.lookupFunction<_c_sequence_destroy, _dart_sequence_destroy>('sequence_destroy');

  /// Parse a UML notation string into a native sequence timeline.
  ///
  /// [name] — unique identifier for the sequence.
  /// [instrumentID] — target instrument (0–48).
  /// [umlDataString] — the UML notation text.
  UMLSequence(String name, int instrumentID, String umlDataString) {
    final namePtr = name.toNativeUtf8();
    final dataPtr = umlDataString.toNativeUtf8();
    try {
      _handle = _funcCreate(namePtr.cast(), instrumentID, dataPtr.cast());
    } finally {
      malloc.free(namePtr);
      malloc.free(dataPtr);
    }
  }

  static late final _funcGetBpm = _dylib.lookupFunction<_c_sequence_get_bpm, _dart_sequence_get_bpm>('sequence_get_bpm');
  static late final _funcGetGrid = _dylib.lookupFunction<_c_sequence_get_grid, _dart_sequence_get_grid>('sequence_get_grid');
  static late final _funcGetInst = _dylib.lookupFunction<_c_sequence_get_instrument, _dart_sequence_get_instrument>('sequence_get_instrument');
  static late final _funcGetBasefreq = _dylib.lookupFunction<_c_sequence_get_basefreq, _dart_sequence_get_basefreq>('sequence_get_basefreq');
  static late final _funcSetBasefreq = _dylib.lookupFunction<_c_sequence_set_basefreq, _dart_sequence_set_basefreq>('sequence_set_basefreq');

  /// The parsed BPM (beats per minute). Defaults to 120.0.
  double get bpm => _isDisposed ? 120.0 : _funcGetBpm(_handle);
  /// The grid subdivision (cells per beat). Defaults to 4.
  int get grid => _isDisposed ? 4 : _funcGetGrid(_handle);
  /// The base frequency (fundamental pitch anchor) in Hz.
  double get basefreq => _isDisposed ? 261.63 : _funcGetBasefreq(_handle);
  /// Set the base frequency. Affects all note frequencies computed relative to this anchor.
  set basefreq(double freq) { if (!_isDisposed) _funcSetBasefreq(_handle, freq); }

  /// Get the [FaustInstrument] this sequence was created for.
  FaustInstrument getFaustInstrument() {
    if (_isDisposed) throw StateError("UMLSequence is disposed");
    final instHandle = _funcGetInst(_handle);
    return FaustInstrument.fromNative(instHandle);
  }

  /// Free the native sequence and its event timeline.
  void dispose() {
    if (!_isDisposed && _handle != nullptr) {
      _funcDestroy(_handle);
      _isDisposed = true;
    }
  }

  /// The native FFI pointer backing this sequence.
  Pointer<NativeSequenceOpaque> get nativePointer => _handle;
}

/// Standalone multi-instance session orchestration controller driving continuous native callbacks.
///
/// [SequenceOrchestrator] manages a collection of named [UMLSequence] instances,
/// providing play, stop, pause, resume, mute, and real-time parameter control
/// over the native hardware audio device. It drives the audio callback chain
/// through [FaustMixer] with sample-accurate event scheduling.
///
/// Must be disposed with [dispose] when no longer needed.
class SequenceOrchestrator {
  late final Pointer<NativeOrchestratorOpaque> _handle;
  bool _isDisposed = false;

  static late final _funcCreate = _dylib.lookupFunction<_c_orch_create, _dart_orch_create>('orchestrator_create');
  static late final _funcDestroy = _dylib.lookupFunction<_c_orch_destroy, _dart_orch_destroy>('orchestrator_destroy');
  static late final _funcAddSeq = _dylib.lookupFunction<_c_orch_add_seq, _dart_orch_add_seq>('orchestrator_add_sequence');
  static late final _funcPlay = _dylib.lookupFunction<_c_orch_play, _dart_orch_play>('orchestrator_play');

  static late final _funcStop = _dylib.lookupFunction<_c_orch_stop, _dart_orch_stop>('orchestrator_stop');
  static late final _funcPause = _dylib.lookupFunction<_c_orch_pause, _dart_orch_pause>('orchestrator_pause');
  static late final _funcResume = _dylib.lookupFunction<_c_orch_resume, _dart_orch_resume>('orchestrator_resume');
  static late final _funcMuteTrack = _dylib.lookupFunction<_c_orch_mute_track, _dart_orch_mute_track>('orchestrator_mute_track');
  static late final _funcSetWeight = _dylib.lookupFunction<_c_orch_set_weight, _dart_orch_set_weight>('orchestrator_set_weight');
  static late final _funcSetParam = _dylib.lookupFunction<_c_orch_set_param, _dart_orch_set_param>('orchestrator_set_parameter');

  static late final _funcPollFinished = _dylib.lookupFunction<_c_orch_poll_finished, _dart_orch_poll_finished>('orchestrator_poll_finished');
  static late final _funcLoadSong = _dylib.lookupFunction<_c_orch_load_song, _dart_orch_load_song>('orchestrator_load_song');
  static late final _funcUnloadSong = _dylib.lookupFunction<_c_orch_unload_song, _dart_orch_unload_song>('orchestrator_unload_song');
  static late final _funcPlaySong = _dylib.lookupFunction<_c_orch_play_song, _dart_orch_play_song>('orchestrator_play_song');
  static late final _funcStopSong = _dylib.lookupFunction<_c_orch_stop_song, _dart_orch_stop_song>('orchestrator_stop_song');

  /// Create an orchestrator instance. Call [dispose] when done.
  SequenceOrchestrator() {
    _handle = _funcCreate();
  }

  /// Register a parsed [UMLSequence] by name for playback.
  void addSequence(String name, UMLSequence sequence) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcAddSeq(_handle, namePtr.cast(), sequence.nativePointer);
    } finally {
      malloc.free(namePtr);
    }
  }

  /// Load a song from a directory
  int loadSong(String directory) {
    if (_isDisposed) return -1;
    final dirPtr = directory.toNativeUtf8();
    try {
      return _funcLoadSong(_handle, dirPtr.cast());
    } finally {
      malloc.free(dirPtr);
    }
  }

  /// Unload a song by directory
  void unloadSong(String directory) {
    if (_isDisposed) return;
    final dirPtr = directory.toNativeUtf8();
    try {
      _funcUnloadSong(_handle, dirPtr.cast());
    } finally {
      malloc.free(dirPtr);
    }
  }

  /// Play a loaded song by directory name
  void playSong(String directory) {
    if (_isDisposed) return;
    final dirPtr = directory.toNativeUtf8();
    try {
      _funcPlaySong(_handle, dirPtr.cast());
    } finally {
      malloc.free(dirPtr);
    }
  }

  /// Stop a loaded song by directory name
  void stopSong(String directory) {
    if (_isDisposed) return;
    final dirPtr = directory.toNativeUtf8();
    try {
      _funcStopSong(_handle, dirPtr.cast());
    } finally {
      malloc.free(dirPtr);
    }
  }

  /// Start playback of a registered sequence.
  void play(String name) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcPlay(_handle, namePtr.cast());
    } finally {
      malloc.free(namePtr);
    }
  }

  /// Stop all playback.
  void stop() => _isDisposed ? null : _funcStop(_handle);
  /// Pause all playback (suspends the audio device).
  void pause() => _isDisposed ? null : _funcPause(_handle);
  /// Resume from pause.
  void resume() => _isDisposed ? null : _funcResume(_handle);

  /// Mute or unmute a sequence by name.
  void muteTrack(String name, {bool mute = true}) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcMuteTrack(_handle, namePtr.cast(), mute ? 1 : 0);
    } finally {
      malloc.free(namePtr);
    }
  }

  /// Set the mixer weight (volume) for a sequence.
  void setWeight(String name, double weight) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcSetWeight(_handle, namePtr.cast(), weight);
    } finally {
      malloc.free(namePtr);
    }
  }

  /// Send a real-time parameter change to a sequence's instrument.
  ///
  /// [name] — sequence identifier.
  /// [param] — DSP parameter name (e.g. `vibrato_rate`, `bow_pressure`).
  /// [value] — new parameter value.
  void setParameter(String name, String param, double value) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    final paramPtr = param.toNativeUtf8();
    try {
      _funcSetParam(_handle, namePtr.cast(), paramPtr.cast(), value);
    } finally {
      malloc.free(namePtr);
      malloc.free(paramPtr);
    }
  }

  /// Poll the orchestrator for finished sequence names.
  ///
  /// Returns the name of the first completed sequence, or null if none finished.
  String? pollFinished() {
    if (_isDisposed) return null;
    final ptr = _funcPollFinished(_handle);
    if (ptr == nullptr) return null;
    return ptr.toDartString();
  }

  /// Free the orchestrator and stop all playback.
  void dispose() {
    if (!_isDisposed && _handle != nullptr) {
      _funcDestroy(_handle);
      _isDisposed = true;
    }
  }

  /// The native FFI pointer backing this orchestrator.
  Pointer<NativeOrchestratorOpaque> get nativePointer => _handle;
}

/// Singleton access to the global Faust audio mixer and hardware driver.
///
/// [FaustMixer] is the central audio hub. It manages:
/// - Hardware device initialization and lifecycle
/// - Sample-rate configuration
/// - Master gain control
/// - Instrument registration and per-instrument volume weighting
/// - The persistent thread pool for concurrent DSP rendering
///
/// Access via [FaustMixer.instance]. Must be initialized with [init] before use.
class FaustMixer {
  /// The global singleton mixer instance.
  static final FaustMixer instance = FaustMixer._internal();
  late final Pointer<NativeMixerOpaque> _handle;

  static late final _funcGetInstance = _dylib.lookupFunction<_c_mixer_get_instance, _dart_mixer_get_instance>('mixer_get_instance');
  static late final _funcInit = _dylib.lookupFunction<_c_mixer_init, _dart_mixer_init>('mixer_init');
  static late final _funcStart = _dylib.lookupFunction<_c_mixer_start, _dart_mixer_start>('mixer_start');
  static late final _funcStop = _dylib.lookupFunction<_c_mixer_stop, _dart_mixer_stop>('mixer_stop');
  static late final _funcClearAll = _dylib.lookupFunction<_c_mixer_clear_all, _dart_mixer_clear_all>('mixer_clear_all');
  static late final _funcGetSR = _dylib.lookupFunction<_c_mixer_get_sr, _dart_mixer_get_sr>('mixer_get_sample_rate');
  static late final _funcSetGain = _dylib.lookupFunction<_c_mixer_set_gain, _dart_mixer_set_gain>('mixer_set_master_gain');
  static late final _funcSetInstWeight = _dylib.lookupFunction<_c_mixer_set_inst_weight, _dart_mixer_set_inst_weight>('mixer_set_instrument_weight');
  static late final _funcRegisterInst = _dylib.lookupFunction<_c_mixer_register_inst, _dart_mixer_register_inst>('mixer_register_instrument');
  static late final _funcUnregisterInst = _dylib.lookupFunction<_c_mixer_unregister_inst, _dart_mixer_unregister_inst>('mixer_unregister_instrument');

  FaustMixer._internal() {
    _handle = _funcGetInstance();
  }

  /// Initialize the mixer with a specific sample rate.
  void init(double sampleRate) => _funcInit(_handle, sampleRate);

  /// Start the hardware audio device.
  bool start() => _funcStart(_handle) != 0;

  /// Stop the hardware audio device.
  void stop() => _funcStop(_handle);

  /// Instantly wipe out all instruments and tracks from the mixer.
  void clearAll() => _funcClearAll(_handle);

  /// Get the hardware sample rate.
  double get sampleRate => _funcGetSR(_handle);

  /// Set the master bus gain (0.0 to 1.0+).
  set masterGain(double gain) => _funcSetGain(_handle, gain);

  /// Set the volume weight for a specific instrument.
  void setInstrumentWeight(FaustInstrument inst, double weight) {
    _funcSetInstWeight(_handle, inst.nativePointer, weight);
  }

  /// Register an instrument with the mixer.
  ///
  /// Throws [ArgumentError] if the instrument's sample rate does not match the mixer's.
  void registerInstrument(FaustInstrument inst, double weight) {
    final result = _funcRegisterInst(_handle, inst.nativePointer, weight);
    if (result == 0) {
      throw ArgumentError(
        'Sample rate mismatch: mixer SR=${sampleRate.toStringAsFixed(0)}, '
        'instrument SR=${inst.sampleRate.toStringAsFixed(0)}. '
        'Create the instrument with the mixer\'s sample rate.'
      );
    }
  }

  /// Unregister an instrument from the mixer.
  void unregisterInstrument(FaustInstrument inst) {
    _funcUnregisterInst(_handle, inst.nativePointer);
  }
}
