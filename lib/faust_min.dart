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
  final double amplitudeScale; // Defines mix weight relative to other tracks
  final int fadeInSamples;
  final int fadeOutSamples;
  final int curveType;
  final int offsetSamples; // Number of silence samples at the start of the buffer
  final double pan; // -1.0 (Left) to 1.0 (Right). 0.0 is Center.

  MixLayer({
    required this.buffer,
    required this.amplitudeScale,
    this.fadeInSamples = 0,
    this.fadeOutSamples = 0,
    this.curveType = 3, // 2=quadratic, 3=cubic, 4=quartic
    this.offsetSamples = 0,
    this.pan = 0.0,
  });
}

/// DSP Utility for fast native post-processing and mixing
class FaustAudioDSP {
  /// Unifies all track normalization, fades, panning, and mixing into a single high-speed native pass.
  /// Note: The `outputBuffer` must be sized at exactly `(buffer.length * 2)` to accommodate stereo interleaving.
  static void mixSignals({
    required List<MixLayer> layers,
    required Float32List stereoOutputBuffer,
    double masterGain = 1.0,
  }) {
    final int numTracks = layers.length;
    if (numTracks == 0) return;
    
    // numSamples is the length of ONE mono track (e.g. the first layer's buffer)
    final int numSamples = layers[0].buffer.length;
    final int stereoSamples = numSamples * 2;
    
    if (stereoOutputBuffer.length < stereoSamples) {
      throw Exception("FaustAudioDSP: stereoOutputBuffer must be exactly 2x the size of the input tracks.");
    }
    
    // Allocate config arrays for C++
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
      // Run single unified stereo pass natively
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
      
      // Copy stereo interleaved output back to Dart
      nativeOutput.copyTo(stereoOutputBuffer);
    } finally {
      // Guaranteed Cleanup of native allocations to prevent memory leaks
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

/// Base class for all Faust-based instruments.
abstract class FaustInstrument {
  void dispose();
  void render(Float32List buffer);
}

/// A High-Fidelity physical modeling synthesizer of a Flute.
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
    _bindings.flute_render(
      _nativeHandle,
      buffer.length,
      _renderBuffer!.pointer,
    );
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

/// A High-Fidelity physical modeling synthesizer of a Tibetan Singing Bowl.
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

/// A High-Fidelity physical modeling synthesizer of a Meditative Bell.
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

/// A High-Fidelity physical modeling synthesizer of a Tabla Dayan (Treble).
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
    _bindings.dayan_render(
      _nativeHandle,
      buffer.length,
      _renderBuffer!.pointer,
    );
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

/// A High-Fidelity physical modeling synthesizer of a Tabla Bayan (Bass).
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
    _bindings.bayan_render(
      _nativeHandle,
      buffer.length,
      _renderBuffer!.pointer,
    );
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

/// A High-Fidelity physical modeling synthesizer of a Sitar.
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
    _bindings.sitar_render(
      _nativeHandle,
      buffer.length,
      _renderBuffer!.pointer,
    );
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

/// A High-Fidelity physical modeling synthesizer of a Kick Drum.
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

/// A High-Fidelity physical modeling synthesizer of a Snare Drum.
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
    _bindings.snare_render(
      _nativeHandle,
      buffer.length,
      _renderBuffer!.pointer,
    );
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

/// A Tunable High-Fidelity physical modeling Tom Drum.
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

/// A High-Fidelity physical modeling Hi-Hat with Open/Closed control.
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
    _bindings.hihat_render(
      _nativeHandle,
      buffer.length,
      _renderBuffer!.pointer,
    );
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

/// A High-Fidelity physical modeling Ride Cymbal.
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

class FaustMin {
  static void normalizeSignal(Pointer<Float> buffer, int numSamples, double targetPeak) {
    _bindings.normalize_signal(buffer, numSamples, targetPeak);
  }

  static void renderSequencedAudio({
    required List<FaustTriggerData> triggers,
    required double baseFreq,
    required double sampleRate,
    required int totalSamples,
    required Pointer<Float> outputBuffer,
  }) {
    if (triggers.isEmpty) {
        _bindings.normalize_signal(outputBuffer, totalSamples, 0.0); // Clear
        return;
    }

    final offsets = malloc<Int>(triggers.length);
    final ids = malloc<Int>(triggers.length);
    final vels = malloc<Float>(triggers.length);
    final params = malloc<Float>(triggers.length);

    for (int i = 0; i < triggers.length; i++) {
      offsets[i] = triggers[i].sampleOffset;
      ids[i] = triggers[i].instrumentId;
      vels[i] = triggers[i].velocity;
      params[i] = triggers[i].param;
    }

    try {
      _bindings.render_sequenced_audio(
        offsets,
        ids,
        vels,
        params,
        triggers.length,
        baseFreq,
        sampleRate,
        totalSamples,
        outputBuffer,
      );
    } finally {
      malloc.free(offsets);
      malloc.free(ids);
      malloc.free(vels);
      malloc.free(params);
    }
  }
}

class FaustTriggerData {
  final int sampleOffset;
  final int instrumentId;
  final double velocity;
  final double param;

  FaustTriggerData({
    required this.sampleOffset,
    required this.instrumentId,
    required this.velocity,
    this.param = 0.0,
  });
}
