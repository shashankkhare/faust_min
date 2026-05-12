import 'dart:ffi';
import 'dart:io';
import 'dart:typed_data';
import 'package:ffi/ffi.dart';

import 'package:faust_min/faust_min_bindings_generated.dart';

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

final FaustMinBindings _bindings = FaustMinBindings(_dylib);

// Top-level FFI function pointers for the Orchestrator
final _funcSetWeight = _dylib.lookupFunction<Void Function(Pointer<Utf8>, Float), void Function(Pointer<Utf8>, double)>('orchestrator_set_weight');
final _funcSetParameter = _dylib.lookupFunction<Void Function(Pointer<Utf8>, Pointer<Utf8>, Float), void Function(Pointer<Utf8>, Pointer<Utf8>, double)>('orchestrator_set_parameter');
final _funcRenderMaster = _dylib.lookupFunction<Void Function(Pointer<Float>, Int), void Function(Pointer<Float>, int)>('orchestrator_render_master');
final _funcSetFinishedCallback = _dylib.lookupFunction<Void Function(Pointer<NativeFunction<Void Function(Pointer<Utf8>)>>), void Function(Pointer<NativeFunction<Void Function(Pointer<Utf8>)>>)>('orchestrator_set_finished_callback');

/// Utility to manage a persistent native buffer for audio rendering.
class _NativeAudioBuffer {
  final int size;
  final Pointer<Float> pointer;

  _NativeAudioBuffer(this.size) : pointer = calloc<Float>(size);

  void copyTo(Float32List list) {
    for (int i = 0; i < size; i++) {
      list[i] = pointer[i];
    }
  }

  void copyFrom(Float32List list) {
    for (int i = 0; i < size; i++) {
      pointer[i] = list[i];
    }
  }

  void dispose() {
    calloc.free(pointer);
  }
}

/// Configuration for a single audio track layer in the mixer.
class MixLayer {
  final Float32List buffer;
  final double amplitudeScale; 
  final int fadeInSamples;
  final int fadeOutSamples;
  final int curveType;
  final int offsetSamples; 
  final double pan; 

  MixLayer({
    required this.buffer,
    required this.amplitudeScale,
    this.fadeInSamples = 0,
    this.fadeOutSamples = 0,
    this.curveType = 3,
    this.offsetSamples = 0,
    this.pan = 0.0,
  });
}

/// DSP Utility for fast native post-processing and mixing
class FaustAudioDSP {
  static void mixSignals({
    required List<MixLayer> layers,
    required Float32List stereoOutputBuffer,
    double masterGain = 1.0,
  }) {
    final int numTracks = layers.length;
    if (numTracks == 0) return;
    
    final int numSamples = layers[0].buffer.length;
    final int stereoSamples = numSamples * 2;
    
    final Pointer<Pointer<Float>> trackPointers = calloc<Pointer<Float>>(numTracks);
    final Pointer<Float> amplitudeScales = calloc<Float>(numTracks);
    final Pointer<Int> fadeInSamples = calloc<Int>(numTracks);
    final Pointer<Int> fadeOutSamples = calloc<Int>(numTracks);
    final Pointer<Int> curveTypes = calloc<Int>(numTracks);
    final Pointer<Int> offsetSamples = calloc<Int>(numTracks);
    final Pointer<Float> pans = calloc<Float>(numTracks);
    
    final nativeOutput = _NativeAudioBuffer(stereoSamples);
    final List<_NativeAudioBuffer> nativeTracks = [];
    
    for (int i = 0; i < numTracks; i++) {
      final layer = layers[i];
      final nativeTrack = _NativeAudioBuffer(layer.buffer.length);
      nativeTrack.copyFrom(layer.buffer);
      nativeTracks.add(nativeTrack);
      
      trackPointers[i] = nativeTrack.pointer;
      amplitudeScales[i] = layer.amplitudeScale;
      fadeInSamples[i] = layer.fadeInSamples;
      fadeOutSamples[i] = layer.fadeOutSamples;
      curveTypes[i] = layer.curveType;
      offsetSamples[i] = layer.offsetSamples;
      pans[i] = layer.pan;
    }
    
    try {
      _bindings.mix_raw_signals(
        trackPointers,
        amplitudeScales,
        fadeInSamples,
        fadeOutSamples,
        curveTypes,
        offsetSamples,
        pans,
        numTracks,
        numSamples,
        nativeOutput.pointer,
        masterGain,
      );
      nativeOutput.copyTo(stereoOutputBuffer);
    } finally {
      for (var nt in nativeTracks) {
        nt.dispose();
      }
      nativeOutput.dispose();
      calloc.free(trackPointers);
      calloc.free(amplitudeScales);
      calloc.free(fadeInSamples);
      calloc.free(fadeOutSamples);
      calloc.free(curveTypes);
      calloc.free(offsetSamples);
      calloc.free(pans);
    }
  }
}

abstract class FaustInstrument {
  void dispose();
  void render(Float32List buffer);
}

class FaustFluteInstrument implements FaustInstrument {
  late Pointer<FaustFlute> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustFluteInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.flute_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.flute_set_frequency(_nativeHandle, freq);
  }

  void setPressure(double pressure) {
    if (_isDisposed) return;
    _bindings.flute_set_pressure(_nativeHandle, pressure);
  }

  void setVibrato(double rate, double depth) {
    if (_isDisposed) return;
    _bindings.flute_set_vibrato(_nativeHandle, rate, depth);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.flute_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.flute_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustBowlInstrument implements FaustInstrument {
  late Pointer<FaustBowl> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustBowlInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.bowl_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.bowl_set_frequency(_nativeHandle, freq);
  }

  void setDuration(double seconds) {
    if (_isDisposed) return;
    _bindings.bowl_set_duration(_nativeHandle, seconds);
  }

  void setRub(double rub) {
    if (_isDisposed) return;
    _bindings.bowl_set_rub(_nativeHandle, rub);
  }

  void setWaver(double waver) {
    if (_isDisposed) return;
    _bindings.bowl_set_waver(_nativeHandle, waver);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.bowl_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.bowl_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.bowl_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustBellInstrument implements FaustInstrument {
  late Pointer<FaustBell> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustBellInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.bell_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.bell_set_frequency(_nativeHandle, freq);
  }

  void setDuration(double seconds) {
    if (_isDisposed) return;
    _bindings.bell_set_duration(_nativeHandle, seconds);
  }

  void setDamping(double damping) {
    if (_isDisposed) return;
    _bindings.bell_set_damping(_nativeHandle, damping);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.bell_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.bell_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.bell_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustDayanInstrument implements FaustInstrument {
  late Pointer<FaustDayan> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustDayanInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.dayan_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.dayan_set_frequency(_nativeHandle, freq);
  }

  void setMute(bool muted) {
    if (_isDisposed) return;
    _bindings.dayan_set_mute(_nativeHandle, muted ? 1 : 0);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.dayan_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.dayan_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.dayan_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustBayanInstrument implements FaustInstrument {
  late Pointer<FaustBayan> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustBayanInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.bayan_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.bayan_set_frequency(_nativeHandle, freq);
  }

  void setMeend(double multiplier) {
    if (_isDisposed) return;
    _bindings.bayan_set_meend(_nativeHandle, multiplier);
  }

  void setMute(bool muted) {
    if (_isDisposed) return;
    _bindings.bayan_set_mute(_nativeHandle, muted ? 1 : 0);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.bayan_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.bayan_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.bayan_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustSitarInstrument implements FaustInstrument {
  late Pointer<FaustSitar> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustSitarInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.sitar_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.sitar_set_frequency(_nativeHandle, freq);
  }

  void setJivari(double amount) {
    if (_isDisposed) return;
    _bindings.sitar_set_jivari(_nativeHandle, amount);
  }

  void setSympatheticGain(double gain) {
    if (_isDisposed) return;
    _bindings.sitar_set_sympathetic_gain(_nativeHandle, gain);
  }

  void pluck(double velocity) {
    if (_isDisposed) return;
    _bindings.sitar_pluck(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.sitar_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.sitar_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustTanpuraInstrument implements FaustInstrument {
  late Pointer<FaustTanpura> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustTanpuraInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.tanpura_create(sampleRate);
  }

  void setParams(double f1, double f2, double f3, double f4, double decay, double delay) {
    if (_isDisposed) return;
    _bindings.tanpura_set_params(_nativeHandle, f1, f2, f3, f4, decay, delay);
  }

  void setJivari(double amount) {
    if (_isDisposed) return;
    _bindings.tanpura_set_jivari(_nativeHandle, amount);
  }

  void setPlaying(bool playing) {
    if (_isDisposed) return;
    _bindings.tanpura_set_playing(_nativeHandle, playing ? 1 : 0);
  }

  void pluck(int stringIndex, double velocity) {
    if (_isDisposed) return;
    _bindings.tanpura_pluck(_nativeHandle, stringIndex, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.tanpura_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.tanpura_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustKickInstrument implements FaustInstrument {
  late Pointer<FaustKick> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustKickInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.kick_create(sampleRate);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.kick_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.kick_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.kick_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustSnareInstrument implements FaustInstrument {
  late Pointer<FaustSnare> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustSnareInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.snare_create(sampleRate);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.snare_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.snare_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.snare_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustTomInstrument implements FaustInstrument {
  late Pointer<FaustTom> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustTomInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.tom_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.tom_set_frequency(_nativeHandle, freq);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.tom_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.tom_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.tom_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustHiHatInstrument implements FaustInstrument {
  late Pointer<FaustHiHat> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustHiHatInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.hihat_create(sampleRate);
  }

  void setOpenness(double amount) {
    if (_isDisposed) return;
    _bindings.hihat_set_openness(_nativeHandle, amount);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.hihat_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.hihat_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.hihat_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustRideInstrument implements FaustInstrument {
  late Pointer<FaustRide> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustRideInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.ride_create(sampleRate);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.ride_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.ride_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.ride_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustPianoInstrument implements FaustInstrument {
  late Pointer<FaustPiano> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustPianoInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.piano_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.piano_set_frequency(_nativeHandle, freq);
  }

  void setSustain(double level) {
    if (_isDisposed) return;
    _bindings.piano_set_sustain(_nativeHandle, level);
  }

  void setStiffness(double stiffness) {
    if (_isDisposed) return;
    _bindings.piano_set_stiffness(_nativeHandle, stiffness);
  }

  void strike(double velocity, {double hardness = 0.5}) {
    if (_isDisposed) return;
    _bindings.piano_strike(_nativeHandle, velocity, hardness);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.piano_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.piano_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustSaxInstrument implements FaustInstrument {
  late Pointer<FaustSax> _nativeHandle;
  _NativeAudioBuffer? _renderBuffer;
  bool _isDisposed = false;

  FaustSaxInstrument({double sampleRate = 44100.0}) {
    _nativeHandle = _bindings.sax_create(sampleRate);
  }

  void setFrequency(double freq) {
    if (_isDisposed) return;
    _bindings.sax_set_frequency(_nativeHandle, freq);
  }

  void setVibrato(double rate, double depth) {
    if (_isDisposed) return;
    _bindings.sax_set_vibrato(_nativeHandle, rate, depth);
  }

  void strike(double velocity) {
    if (_isDisposed) return;
    _bindings.sax_strike(_nativeHandle, velocity);
  }

  @override
  void render(Float32List buffer) {
    if (_isDisposed) return;
    if (_renderBuffer == null || _renderBuffer!.size != buffer.length) {
      _renderBuffer?.dispose();
      _renderBuffer = _NativeAudioBuffer(buffer.length);
    }
    _bindings.sax_render(_nativeHandle, buffer.length, _renderBuffer!.pointer);
    _renderBuffer!.copyTo(buffer);
  }

  @override
  void dispose() {
    if (!_isDisposed) {
      _bindings.sax_destroy(_nativeHandle);
      _renderBuffer?.dispose();
      _isDisposed = true;
    }
  }
}

class FaustOrchestrator {
  static bool _isInitialized = false;

  static void init({double sampleRate = 44100.0}) {
    if (_isInitialized) return;
    final func = _dylib.lookupFunction<Void Function(Float), void Function(double)>('orchestrator_init');
    func(sampleRate);
    _isInitialized = true;
  }

  static void setAssetBasePath(String path) {
    final func = _dylib.lookupFunction<Void Function(Pointer<Utf8>), void Function(Pointer<Utf8>)>('orchestrator_set_asset_base_path');
    final ptr = path.toNativeUtf8();
    try {
      func(ptr);
    } finally {
      malloc.free(ptr);
    }
  }

  static void loadSequence(String name, String umlData) {
    final func = _dylib.lookupFunction<Void Function(Pointer<Utf8>, Pointer<Utf8>), void Function(Pointer<Utf8>, Pointer<Utf8>)>('orchestrator_load_sequence');
    final namePtr = name.toNativeUtf8();
    final dataPtr = umlData.toNativeUtf8();
    try {
      func(namePtr, dataPtr);
    } finally {
      malloc.free(namePtr);
      malloc.free(dataPtr);
    }
  }

  static void play(String name) {
    final func = _dylib.lookupFunction<Void Function(Pointer<Utf8>), void Function(Pointer<Utf8>)>('orchestrator_play');
    final namePtr = name.toNativeUtf8();
    try {
      func(namePtr);
    } finally {
      malloc.free(namePtr);
    }
  }

  static void stop() {
    final func = _dylib.lookupFunction<Void Function(), void Function()>('orchestrator_stop');
    func();
  }

  static void pause() {
    final func = _dylib.lookupFunction<Void Function(), void Function()>('orchestrator_pause');
    func();
  }

  static void resume() {
    final func = _dylib.lookupFunction<Void Function(), void Function()>('orchestrator_resume');
    func();
  }

  static void setWeight(String name, double weight) {
    final namePtr = name.toNativeUtf8();
    _funcSetWeight(namePtr.cast(), weight);
    malloc.free(namePtr);
  }

  static void setParameter(String sequenceName, String paramName, double value) {
    final seqNamePtr = sequenceName.toNativeUtf8();
    final paramNamePtr = paramName.toNativeUtf8();
    _funcSetParameter(seqNamePtr.cast(), paramNamePtr.cast(), value);
    malloc.free(seqNamePtr);
    malloc.free(paramNamePtr);
  }

  static void renderMaster(Pointer<Float> buffer, int numFrames) {
    _funcRenderMaster(buffer, numFrames);
  }

  static void renderPCM(String name, Pointer<Float> buffer, int numFrames) {
    final namePtr = name.toNativeUtf8();
    final func = _dylib.lookupFunction<Void Function(Pointer<Utf8>, Pointer<Float>, Int), void Function(Pointer<Utf8>, Pointer<Float>, int)>('orchestrator_render_pcm');
    func(namePtr.cast(), buffer, numFrames);
    malloc.free(namePtr);
  }

  static void setOnFinishedCallback(void Function(String) callback) {
    final nativeCallable = NativeCallable<Void Function(Pointer<Utf8>)>.isolateLocal((Pointer<Utf8> namePtr) {
      callback(namePtr.toDartString());
    });
    _funcSetFinishedCallback(nativeCallable.nativeFunction);
  }
}

class FaustEventData {
  final int sampleOffset;
  final int instrumentId;
  final int eventType; 
  final int paramId;
  final double value;

  FaustEventData({
    required this.sampleOffset,
    required this.instrumentId,
    required this.eventType,
    this.paramId = 0,
    required this.value,
  });
}
