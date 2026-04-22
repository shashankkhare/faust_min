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

  void dispose() {
    calloc.free(pointer);
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
