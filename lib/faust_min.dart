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
class NativeOrchestratorOpaque extends Opaque {}

// --- FaustMixer Typedefs ---
typedef _c_mixer_get_instance = Pointer<NativeMixerOpaque> Function();
typedef _dart_mixer_get_instance = Pointer<NativeMixerOpaque> Function();

typedef _c_mixer_init = Void Function(Pointer<NativeMixerOpaque> mixer, Float sampleRate);
typedef _dart_mixer_init = void Function(Pointer<NativeMixerOpaque> mixer, double sampleRate);

typedef _c_mixer_start = Int32 Function(Pointer<NativeMixerOpaque> mixer);
typedef _dart_mixer_start = int Function(Pointer<NativeMixerOpaque> mixer);

typedef _c_mixer_stop = Void Function(Pointer<NativeMixerOpaque> mixer);
typedef _dart_mixer_stop = void Function(Pointer<NativeMixerOpaque> mixer);

typedef _c_mixer_get_sr = Float Function(Pointer<NativeMixerOpaque> mixer);
typedef _dart_mixer_get_sr = double Function(Pointer<NativeMixerOpaque> mixer);

typedef _c_mixer_set_gain = Void Function(Pointer<NativeMixerOpaque> mixer, Float gain);
typedef _dart_mixer_set_gain = void Function(Pointer<NativeMixerOpaque> mixer, double gain);

typedef _c_mixer_set_inst_weight = Void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, Float weight);
typedef _dart_mixer_set_inst_weight = void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, double weight);

typedef _c_mixer_register_inst = Void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, Float weight);
typedef _dart_mixer_register_inst = void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeInstrumentOpaque> inst, double weight);

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

typedef _c_inst_set_param = Void Function(Pointer<NativeInstrumentOpaque>, Pointer<Utf8>, Float);
typedef _dart_inst_set_param = void Function(Pointer<NativeInstrumentOpaque>, Pointer<Utf8>, double);

typedef _c_inst_note_on = Void Function(Pointer<NativeInstrumentOpaque>, Float, Float, Float);
typedef _dart_inst_note_on = void Function(Pointer<NativeInstrumentOpaque>, double, double, double);

typedef _c_inst_note_off = Void Function(Pointer<NativeInstrumentOpaque>);
typedef _dart_inst_note_off = void Function(Pointer<NativeInstrumentOpaque>);

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

typedef _c_orch_set_weight = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Float);
typedef _dart_orch_set_weight = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, double);

typedef _c_orch_set_param = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<Utf8>, Float);
typedef _dart_orch_set_param = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<Utf8>, double);

typedef _c_orch_render_master = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Float>, Int32);
typedef _dart_orch_render_master = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Float>, int);

typedef _c_orch_poll_finished = Pointer<Utf8> Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_poll_finished = Pointer<Utf8> Function(Pointer<NativeOrchestratorOpaque>);

// --- Classes ---

/// Concrete dynamic representation wrapping opaque instrument heap pointers over FFI.
class FaustInstrument {
  final Pointer<NativeInstrumentOpaque> _handle;
  bool _isDisposed = false;

  static late final _funcSetParam = _dylib.lookupFunction<_c_inst_set_param, _dart_inst_set_param>('instrument_set_parameter');
  static late final _funcNoteOn = _dylib.lookupFunction<_c_inst_note_on, _dart_inst_note_on>('instrument_note_on');
  static late final _funcNoteOff = _dylib.lookupFunction<_c_inst_note_off, _dart_inst_note_off>('instrument_note_off');

  FaustInstrument._(this._handle);

  void setParameter(String name, double value) {
    if (_isDisposed || _handle == nullptr) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcSetParam(_handle, namePtr.cast(), value);
    } finally {
      malloc.free(namePtr);
    }
  }

  void noteOn({double freq = -1.0, double velocity = -1.0, double strike = -1.0}) {
    if (_isDisposed || _handle == nullptr) return;
    _funcNoteOn(_handle, freq, velocity, strike);
  }

  void noteOff() {
    if (_isDisposed || _handle == nullptr) return;
    _funcNoteOff(_handle);
  }

  void dispose() {
    _isDisposed = true;
  }

  Pointer<NativeInstrumentOpaque> get nativePointer => _handle;
}

/// Self-contained object-oriented schedule timeline model natively parsing UML patterns.
class UMLSequence {
  late final Pointer<NativeSequenceOpaque> _handle;
  bool _isDisposed = false;

  static late final _funcCreate = _dylib.lookupFunction<_c_sequence_create, _dart_sequence_create>('sequence_create');
  static late final _funcDestroy = _dylib.lookupFunction<_c_sequence_destroy, _dart_sequence_destroy>('sequence_destroy');

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

  double get bpm => _isDisposed ? 120.0 : _funcGetBpm(_handle);
  int get grid => _isDisposed ? 4 : _funcGetGrid(_handle);

  void dispose() {
    if (!_isDisposed && _handle != nullptr) {
      _funcDestroy(_handle);
      _isDisposed = true;
    }
  }

  Pointer<NativeSequenceOpaque> get nativePointer => _handle;
}

/// Standalone multi-instance session orchestration controller driving continuous native callbacks.
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
  SequenceOrchestrator() {
    _handle = _funcCreate();
  }

  void addSequence(String name, UMLSequence sequence) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcAddSeq(_handle, namePtr.cast(), sequence.nativePointer);
    } finally {
      malloc.free(namePtr);
    }
  }

  void play(String name) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcPlay(_handle, namePtr.cast());
    } finally {
      malloc.free(namePtr);
    }
  }

  void stop() => _isDisposed ? null : _funcStop(_handle);
  void pause() => _isDisposed ? null : _funcPause(_handle);
  void resume() => _isDisposed ? null : _funcResume(_handle);

  void muteTrack(String name, {bool mute = true}) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcMuteTrack(_handle, namePtr.cast(), mute ? 1 : 0);
    } finally {
      malloc.free(namePtr);
    }
  }

  void setWeight(String name, double weight) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcSetWeight(_handle, namePtr.cast(), weight);
    } finally {
      malloc.free(namePtr);
    }
  }

  void setParameter(String trackName, String paramName, double value) {
    if (_isDisposed) return;
    final trackPtr = trackName.toNativeUtf8();
    final paramPtr = paramName.toNativeUtf8();
    try {
      _funcSetParam(_handle, trackPtr.cast(), paramPtr.cast(), value);
    } finally {
      malloc.free(trackPtr);
      malloc.free(paramPtr);
    }
  }



  String? pollFinished() {
    if (_isDisposed) return null;
    final ptr = _funcPollFinished(_handle);
    if (ptr == nullptr) return null;
    return ptr.toDartString();
  }

  void dispose() {
    if (!_isDisposed && _handle != nullptr) {
      _funcDestroy(_handle);
      _isDisposed = true;
    }
  }

  Pointer<NativeOrchestratorOpaque> get nativePointer => _handle;
}

/// Singleton access to the global Faust audio mixer and hardware driver.
class FaustMixer {
  static final FaustMixer instance = FaustMixer._internal();
  late final Pointer<NativeMixerOpaque> _handle;

  static late final _funcGetInstance = _dylib.lookupFunction<_c_mixer_get_instance, _dart_mixer_get_instance>('mixer_get_instance');
  static late final _funcInit = _dylib.lookupFunction<_c_mixer_init, _dart_mixer_init>('mixer_init');
  static late final _funcStart = _dylib.lookupFunction<_c_mixer_start, _dart_mixer_start>('mixer_start');
  static late final _funcStop = _dylib.lookupFunction<_c_mixer_stop, _dart_mixer_stop>('mixer_stop');
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

  /// Get the hardware sample rate.
  double get sampleRate => _funcGetSR(_handle);

  /// Set the master bus gain (0.0 to 1.0+).
  set masterGain(double gain) => _funcSetGain(_handle, gain);

  /// Set the volume weight for a specific instrument.
  void setInstrumentWeight(FaustInstrument inst, double weight) {
    _funcSetInstWeight(_handle, inst.nativePointer, weight);
  }

  /// Register an instrument with the mixer.
  void registerInstrument(FaustInstrument inst, double weight) {
    _funcRegisterInst(_handle, inst.nativePointer, weight);
  }

  /// Unregister an instrument from the mixer.
  void unregisterInstrument(FaustInstrument inst) {
    _funcUnregisterInst(_handle, inst.nativePointer);
  }
}
