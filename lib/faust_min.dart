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

import 'dart:convert';
import 'dart:ffi';
import 'dart:io';
import 'dart:async';
import 'dart:typed_data';
import 'package:ffi/ffi.dart';
import 'package:flutter/services.dart';
import 'package:path_provider/path_provider.dart';

const String _libName = 'faust_min';

final DynamicLibrary _dylib = () {
  if (Platform.isIOS) {
    return DynamicLibrary.process();
  }
  if (Platform.isMacOS) {
    try {
      return DynamicLibrary.open('$_libName.framework/$_libName');
    } catch (_) {
      return DynamicLibrary.process();
    }
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

typedef VoidFunctionNative = Void Function();
typedef _c_mixer_start_async = Void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeFunction<VoidFunctionNative>> callback);
typedef _dart_mixer_start_async = void Function(Pointer<NativeMixerOpaque> mixer, Pointer<NativeFunction<VoidFunctionNative>> callback);

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

typedef _c_mixer_add_track = Int32 Function(Pointer<NativeMixerOpaque> mixer, Float initialWeight);
typedef _dart_mixer_add_track = int Function(Pointer<NativeMixerOpaque> mixer, double initialWeight);

typedef _c_mixer_remove_track = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID);
typedef _dart_mixer_remove_track = void Function(Pointer<NativeMixerOpaque> mixer, int trackID);

typedef _c_mixer_add_inst_to_track = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Pointer<NativeInstrumentOpaque> inst, Float instWeight);
typedef _dart_mixer_add_inst_to_track = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, Pointer<NativeInstrumentOpaque> inst, double instWeight);

typedef _c_mixer_remove_inst_from_track = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Pointer<NativeInstrumentOpaque> inst);
typedef _dart_mixer_remove_inst_from_track = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, Pointer<NativeInstrumentOpaque> inst);

typedef _c_mixer_set_track_envelope = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Pointer<Float> times, Pointer<Float> values, Pointer<Uint8> interpTypes, Int32 numPoints);
typedef _dart_mixer_set_track_envelope = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, Pointer<Float> times, Pointer<Float> values, Pointer<Uint8> interpTypes, int numPoints);

typedef _c_mixer_set_track_weight = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Float weight);
typedef _dart_mixer_set_track_weight = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, double weight);
typedef _c_mixer_set_weight_mode = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 mode);
typedef _dart_mixer_set_weight_mode = void Function(Pointer<NativeMixerOpaque> mixer, int mode);

typedef _c_mixer_get_track_weight = Float Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID);
typedef _dart_mixer_get_track_weight = double Function(Pointer<NativeMixerOpaque> mixer, int trackID);

typedef _c_mixer_get_track_mute = Int32 Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID);
typedef _dart_mixer_get_track_mute = int Function(Pointer<NativeMixerOpaque> mixer, int trackID);
typedef _c_mixer_mute_track = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID);
typedef _dart_mixer_mute_track = void Function(Pointer<NativeMixerOpaque> mixer, int trackID);

typedef _c_mixer_unmute_tracks = Void Function(Pointer<NativeMixerOpaque> mixer, Pointer<Int32> trackIDs, Int32 count);
typedef _dart_mixer_unmute_tracks = void Function(Pointer<NativeMixerOpaque> mixer, Pointer<Int32> trackIDs, int count);
typedef _c_mixer_unmute_track = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID);
typedef _dart_mixer_unmute_track = void Function(Pointer<NativeMixerOpaque> mixer, int trackID);

typedef _c_mixer_set_track_reverb = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Float send);
typedef _dart_mixer_set_track_reverb = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, double send);

typedef _c_mixer_set_track_echo = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Float send, Float feedback, Float delaySec);
typedef _dart_mixer_set_track_echo = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, double send, double feedback, double delaySec);

typedef _c_mixer_set_track_eq = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Float bassDb, Float trebleDb);
typedef _dart_mixer_set_track_eq = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, double bassDb, double trebleDb);

typedef _c_mixer_set_track_mid = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Float midDb, Float midFreq, Float midQ);
typedef _dart_mixer_set_track_mid = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, double midDb, double midFreq, double midQ);

typedef _c_mixer_set_track_bypass_eq = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Float bypass);
typedef _dart_mixer_set_track_bypass_eq = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, double bypass);

typedef _c_mixer_set_track_bypass_echo = Void Function(Pointer<NativeMixerOpaque> mixer, Int32 trackID, Float bypass);
typedef _dart_mixer_set_track_bypass_echo = void Function(Pointer<NativeMixerOpaque> mixer, int trackID, double bypass);

typedef _c_mixer_set_fx_return = Void Function(Pointer<NativeMixerOpaque> mixer, Float weight);
typedef _dart_mixer_set_fx_return = void Function(Pointer<NativeMixerOpaque> mixer, double weight);

typedef _c_mixer_master_fade_in = Void Function(Pointer<NativeMixerOpaque> mixer, Float durationSeconds);
typedef _dart_mixer_master_fade_in = void Function(Pointer<NativeMixerOpaque> mixer, double durationSeconds);

typedef _c_mixer_master_fade_out = Void Function(Pointer<NativeMixerOpaque> mixer, Float durationSeconds);
typedef _dart_mixer_master_fade_out = void Function(Pointer<NativeMixerOpaque> mixer, double durationSeconds);


// --- Flat API Bindings Signatures ---
typedef _c_sequence_create = Pointer<NativeSequenceOpaque> Function(Pointer<Utf8>, Int32, Pointer<Utf8>);
typedef _dart_sequence_create = Pointer<NativeSequenceOpaque> Function(Pointer<Utf8>, int, Pointer<Utf8>);

typedef _c_sequence_destroy = Void Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_destroy = void Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_get_bpm = Double Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_bpm = double Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_set_bpm = Void Function(Pointer<NativeSequenceOpaque>, Double);
typedef _dart_sequence_set_bpm = void Function(Pointer<NativeSequenceOpaque>, double);

typedef _c_sequence_get_uml_data = Pointer<Utf8> Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_uml_data = Pointer<Utf8> Function(Pointer<NativeSequenceOpaque>);
typedef _c_sequence_is_dirty = Int32 Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_is_dirty = int Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_get_grid = Int32 Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_grid = int Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_get_measure = Int32 Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_measure = int Function(Pointer<NativeSequenceOpaque>);
typedef _c_sequence_get_basefreq = Double Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_get_basefreq = double Function(Pointer<NativeSequenceOpaque>);
typedef _c_sequence_set_basefreq = Void Function(Pointer<NativeSequenceOpaque>, Double);
typedef _dart_sequence_set_basefreq = void Function(Pointer<NativeSequenceOpaque>, double);

typedef _c_sequence_prepare = Void Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_prepare = void Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_add_note = Void Function(Pointer<NativeSequenceOpaque>, Float, Float, Float, Float, Pointer<Utf8>, Float);
typedef _dart_sequence_add_note = void Function(Pointer<NativeSequenceOpaque>, double, double, double, double, Pointer<Utf8>, double);

typedef _c_sequence_remove_note = Void Function(Pointer<NativeSequenceOpaque>, Float, Float);
typedef _dart_sequence_remove_note = void Function(Pointer<NativeSequenceOpaque>, double, double);

typedef _c_sequence_clear_notes = Void Function(Pointer<NativeSequenceOpaque>);
typedef _dart_sequence_clear_notes = void Function(Pointer<NativeSequenceOpaque>);

typedef _c_sequence_get_notes = Int32 Function(Pointer<NativeSequenceOpaque>, Float, Float, Pointer<Float>, Int32, Pointer<Uint8>);
typedef _dart_sequence_get_notes = int Function(Pointer<NativeSequenceOpaque>, double, double, Pointer<Float>, int, Pointer<Uint8>);

// Orchestrator FFI (Opaque structure: orchestrator)
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

typedef _c_inst_get_params_json = Pointer<Utf8> Function(Pointer<NativeInstrumentOpaque>);
typedef _dart_inst_get_params_json = Pointer<Utf8> Function(Pointer<NativeInstrumentOpaque>);

typedef _c_inst_free_json = Void Function(Pointer<Utf8>);
typedef _dart_inst_free_json = void Function(Pointer<Utf8>);

typedef _c_inst_render = Void Function(Pointer<NativeInstrumentOpaque>, Pointer<Float>, Int32);
typedef _dart_inst_render = void Function(Pointer<NativeInstrumentOpaque>, Pointer<Float>, int);

typedef _c_inst_get_sample_rate = Float Function(Pointer<NativeInstrumentOpaque>);
typedef _dart_inst_get_sample_rate = double Function(Pointer<NativeInstrumentOpaque>);

typedef _c_orch_get_instance = Pointer<NativeOrchestratorOpaque> Function();
typedef _dart_orch_get_instance = Pointer<NativeOrchestratorOpaque> Function();

typedef _c_orch_destroy = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_destroy = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_add_seq = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<NativeSequenceOpaque>);
typedef _dart_orch_add_seq = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<NativeSequenceOpaque>);

typedef _c_orch_clear_sequence = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_clear_sequence = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_clear_sequences = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_clear_sequences = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_play = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_play = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_play_sequences = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Pointer<Utf8>>, Int32);
typedef _dart_orch_play_sequences = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Pointer<Utf8>>, int);



typedef _c_orch_stop = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_stop = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_pause = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_pause = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_resume = Void Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_resume = void Function(Pointer<NativeOrchestratorOpaque>);

typedef _c_orch_seek = Void Function(Pointer<NativeOrchestratorOpaque>, Int64);
typedef _dart_orch_seek = void Function(Pointer<NativeOrchestratorOpaque>, int);

typedef _c_orch_set_song_looping = Void Function(Pointer<NativeOrchestratorOpaque>, Int32);
typedef _dart_orch_set_song_looping = void Function(Pointer<NativeOrchestratorOpaque>, int);

typedef _c_orch_mute_sequence = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Int32);
typedef _dart_orch_mute_sequence = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, int);

typedef _c_orch_set_param = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<Utf8>, Float);
typedef _dart_orch_set_param = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Pointer<Utf8>, double);

typedef _c_orch_set_weight = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, Float);
typedef _dart_orch_set_weight = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>, double);

typedef _c_orch_poll_finished = Pointer<Utf8> Function(Pointer<NativeOrchestratorOpaque>);
typedef _dart_orch_poll_finished = Pointer<Utf8> Function(Pointer<NativeOrchestratorOpaque>);

// TickCallback: void(long tick, int noteIndex, const char* seqName, void* userData)
typedef _c_orch_register_tick_callback = Void Function(
    Pointer<NativeOrchestratorOpaque>, Pointer<NativeFunction<TickCallbackNative>>, Pointer<Void>);
typedef _dart_orch_register_tick_callback = void Function(
    Pointer<NativeOrchestratorOpaque>, Pointer<NativeFunction<TickCallbackNative>>, Pointer<Void>);

typedef _c_orch_load_song = Int32 Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_load_song = int Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_unload_song = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_unload_song = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_play_song = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_play_song = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_orch_stop_song = Void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);
typedef _dart_orch_stop_song = void Function(Pointer<NativeOrchestratorOpaque>, Pointer<Utf8>);

typedef _c_engine_set_asset_base_path = Void Function(Pointer<Utf8>);
typedef _dart_engine_set_asset_base_path = void Function(Pointer<Utf8>);

typedef _c_engine_get_asset_base_path = Pointer<Utf8> Function();
typedef _dart_engine_get_asset_base_path = Pointer<Utf8> Function();

typedef _c_mapper_get_name = Pointer<Utf8> Function(Int32);
typedef _dart_mapper_get_name = Pointer<Utf8> Function(int);

typedef _c_mapper_get_id = Int32 Function(Pointer<Utf8>);
typedef _dart_mapper_get_id = int Function(Pointer<Utf8>);

typedef _c_mapper_is_percussion = Int32 Function(Int32);
typedef _dart_mapper_is_percussion = int Function(int);


typedef _c_mapper_get_polyphony = Int32 Function(Int32);
typedef _dart_mapper_get_polyphony = int Function(int);

typedef _c_mapper_get_class = Pointer<Utf8> Function(Int32);
typedef _dart_mapper_get_class = Pointer<Utf8> Function(int);

typedef _c_mapper_get_origin = Pointer<Utf8> Function(Int32);
typedef _dart_mapper_get_origin = Pointer<Utf8> Function(int);

typedef _c_mapper_get_available = Int32 Function(Pointer<Int32>, Int32);
typedef _dart_mapper_get_available = int Function(Pointer<Int32>, int);

// Callback typedefs for native tick and waveform callbacks
typedef TickCallbackNative = Void Function(Int64, Int32, Pointer<Utf8>, Pointer<Void>);
typedef TickCallbackDart = void Function(int, int, Pointer<Utf8>, Pointer<Void>);

typedef WaveformCallbackNative = Void Function(Float, Float, Pointer<Void>);
typedef WaveformCallbackDart = void Function(double, double, Pointer<Void>);

typedef _c_mixer_register_waveform_callback = Void Function(
    Pointer<NativeMixerOpaque>,
    Pointer<NativeFunction<WaveformCallbackNative>>,
    Pointer<Void>,
);
typedef _dart_mixer_register_waveform_callback = void Function(
    Pointer<NativeMixerOpaque>,
    Pointer<NativeFunction<WaveformCallbackNative>>,
    Pointer<Void>,
);

// --- Classes ---

/// Static registry / metadata lookup for the built-in instrument library.
///
/// [InstrumentMapper] exposes read-only metadata about every physical model
/// the engine ships with — its numeric ID, display name, polyphony, and
/// classification. Use it to enumerate available instruments
/// ([getAvailableInstruments]) and to look up details by ID or name.
abstract final class InstrumentMapper {
  /// Whether the instrument with the given [id] is unpitched/percussive.
  static bool isPercussion(int id) {
    return _funcIsPercussion(id) == 1;
  }

  /// Whether the instrument with the given [id] is melodic (pitched).
  ///
  /// Equivalent to `!isPercussion(id)`. Useful for routing tracks to a
  /// melodic vs. percussion section.
  static bool isMelody(int id) {
    return !isPercussion(id);
  }

  /// The number of simultaneous voices the instrument [id] supports.
  ///
  /// Instruments with polyphony > 1 (e.g. piano, guitars) can ring out
  /// multiple notes at once without cutting each other off. Returns `0`
  /// for unknown IDs.
  static int getPolyphony(int id) {
    return _funcGetPolyphony(id);
  }

  /// The instrument class/category for [id] (e.g. `aerophone`,
  /// `chordophone`, `membranophone`, `idiophone`). Returns `'Unknown'`
  /// for unknown IDs.
  static String getClass(int id) {
    final ptr = _funcGetClass(id);
    if (ptr == nullptr) return 'Unknown';
    return ptr.cast<Utf8>().toDartString();
  }

  /// The geographic/cultural origin of instrument [id].
  ///
  /// Returns `'Unknown'` for unknown IDs.
  static String getOrigin(int id) {
    final ptr = _funcGetOrigin(id);
    if (ptr == nullptr) return 'Unknown';
    return ptr.cast<Utf8>().toDartString();
  }

  /// The display name of instrument [id] (e.g. `'Flute'`, `'Sitar'`).
  static String getName(int id) {
    final ptr = _funcGetName(id);
    if (ptr == nullptr) return '';
    return ptr.cast<Utf8>().toDartString();
  }

  /// The list of all instrument IDs available in this build.
  ///
  /// Use together with [getName] / [getClass] to build instrument pickers.
  static List<int> getAvailableInstruments() {
    final outArray = calloc<Int32>(256);
    final count = _funcGetAvailable(outArray, 256);
    final result = <int>[];
    for (var i = 0; i < count; i++) {
      result.add(outArray[i]);
    }
    calloc.free(outArray);
    return result;
  }

  /// Resolve an instrument's numeric ID from its [name].
  ///
  /// Returns `-1` if the name does not match any registered instrument.
  static int getId(String name) {
    final ptr = name.toNativeUtf8();
    try {
      return _funcGetId(ptr.cast());
    } finally {
      malloc.free(ptr);
    }
  }

  static late final _funcIsPercussion = _dylib.lookupFunction<_c_mapper_is_percussion, _dart_mapper_is_percussion>('instrument_mapper_is_percussion');
  static late final _funcGetId = _dylib.lookupFunction<_c_mapper_get_id, _dart_mapper_get_id>('instrument_mapper_get_id');
  static late final _funcGetName = _dylib.lookupFunction<_c_mapper_get_name, _dart_mapper_get_name>('instrument_mapper_get_name');
  static late final _funcGetPolyphony = _dylib.lookupFunction<_c_mapper_get_polyphony, _dart_mapper_get_polyphony>('instrument_mapper_get_polyphony');
  static late final _funcGetClass = _dylib.lookupFunction<_c_mapper_get_class, _dart_mapper_get_class>('instrument_mapper_get_class');
  static late final _funcGetOrigin = _dylib.lookupFunction<_c_mapper_get_origin, _dart_mapper_get_origin>('instrument_mapper_get_origin');
  static late final _funcGetAvailable = _dylib.lookupFunction<_c_mapper_get_available, _dart_mapper_get_available>('instrument_mapper_get_available');
}

/// A physically modeled instrument instance backed by a real-time Faust DSP engine.
///
/// Each [FaustInstrument] encapsulates a complete physical model (e.g. flute,
/// sitar, tabla) with parameters for frequency, velocity, articulation, and
/// real-time modulation. It wraps a native C++ instrument heap object accessed
/// via FFI.
///
/// Create instances with [FaustInstrument.create], attach them to the mixer
/// with [FaustMixer.registerInstrument], and sequence them with [UMLSequence]
/// / [SequenceOrchestrator]. Multiple voices are allocated dynamically by the
/// native engine for polyphonic playback.
///
/// ```dart
/// final flute = FaustInstrument.create(10);       // sampleRate auto-matches mixer
/// flute.noteOn(freq: 440.0, velocity: 0.8);
/// // ... let it ring ...
/// flute.noteOff();
/// flute.dispose();                                 // free the native heap object
/// ```
class FaustInstrument {
  final Pointer<NativeInstrumentOpaque> _handle;
  final bool _owned;
  bool _isDisposed = false;

  static late final _funcCreate = _dylib.lookupFunction<_c_inst_create, _dart_inst_create>('instrument_create');
  static late final _funcDestroy = _dylib.lookupFunction<_c_inst_destroy, _dart_inst_destroy>('instrument_destroy');
  static late final _funcSetParam = _dylib.lookupFunction<_c_inst_set_param, _dart_inst_set_param>('instrument_set_parameter');
  static late final _funcNoteOn = _dylib.lookupFunction<_c_inst_note_on, _dart_inst_note_on>('instrument_note_on');
  static late final _funcNoteOff = _dylib.lookupFunction<_c_inst_note_off, _dart_inst_note_off>('instrument_note_off');
  static late final _funcGetParamsJson = _dylib.lookupFunction<_c_inst_get_params_json, _dart_inst_get_params_json>('instrument_get_parameters_json');
  static late final _funcFreeJson = _dylib.lookupFunction<_c_inst_free_json, _dart_inst_free_json>('instrument_free_json');
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
  factory FaustInstrument.create(int instrumentID, int execType, [double? sampleRate]) {
    final sr = sampleRate ?? FaustMixer.instance.sampleRate;
    final handle = _funcCreate(instrumentID, execType, sr);
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

  /// Get a list of all active DSP parameters for this instrument.
  List<Map<String, dynamic>> getParameters() {
    if (_isDisposed || _handle == nullptr) return [];
    final ptr = _funcGetParamsJson(_handle);
    if (ptr == nullptr) return [];
    try {
      final jsonStr = ptr.toDartString();
      final decoded = jsonDecode(jsonStr);
      if (decoded is List) {
        return List<Map<String, dynamic>>.from(decoded);
      }
    } finally {
      _funcFreeJson(ptr);
    }
    return [];
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

  /// Renders a WAV file byte array in memory for the given duration.
  /// Used for pre-rendering test buffers for SoLoud playback.
  Future<Uint8List> renderWavBytes(double durationSeconds, double freq, double vel) async {
    final sr = sampleRate;
    if (sr <= 0) return Uint8List(0);
    
    final numFrames = (durationSeconds * sr).toInt();
    final numChannels = 2; // interleaved stereo
    final bufferSize = numFrames * numChannels;
    
    final floatBuffer = calloc<Float>(bufferSize);
    
    // Trigger note on
    noteOn(freq: freq, velocity: vel);
    
    // Render the entire sustained buffer
    _funcRender(_handle, floatBuffer, numFrames);
    
    // Construct WAV byte array (32-bit float PCM)
    final byteData = ByteData(44 + bufferSize * 4);
    
    // RIFF chunk
    byteData.setUint8(0, 0x52); // R
    byteData.setUint8(1, 0x49); // I
    byteData.setUint8(2, 0x46); // F
    byteData.setUint8(3, 0x46); // F
    byteData.setUint32(4, 36 + bufferSize * 4, Endian.little); // chunk size
    byteData.setUint8(8, 0x57); // W
    byteData.setUint8(9, 0x41); // A
    byteData.setUint8(10, 0x56); // V
    byteData.setUint8(11, 0x45); // E
    
    // fmt chunk
    byteData.setUint8(12, 0x66); // f
    byteData.setUint8(13, 0x6D); // m
    byteData.setUint8(14, 0x74); // t
    byteData.setUint8(15, 0x20); // ' '
    byteData.setUint32(16, 16, Endian.little); // Subchunk1Size
    byteData.setUint16(20, 3, Endian.little); // AudioFormat (3 = IEEE float)
    byteData.setUint16(22, numChannels, Endian.little); // NumChannels
    byteData.setUint32(24, sr.toInt(), Endian.little); // SampleRate
    byteData.setUint32(28, sr.toInt() * numChannels * 4, Endian.little); // ByteRate
    byteData.setUint16(32, numChannels * 4, Endian.little); // BlockAlign
    byteData.setUint16(34, 32, Endian.little); // BitsPerSample
    
    // data chunk
    byteData.setUint8(36, 0x64); // d
    byteData.setUint8(37, 0x61); // a
    byteData.setUint8(38, 0x74); // t
    byteData.setUint8(39, 0x61); // a
    byteData.setUint32(40, bufferSize * 4, Endian.little); // Subchunk2Size
    
    // Copy floats directly into ByteData payload
    var offset = 44;
    for (var i = 0; i < bufferSize; i++) {
      byteData.setFloat32(offset, floatBuffer[i], Endian.little);
      offset += 4;
    }
    
    calloc.free(floatBuffer);
    return byteData.buffer.asUint8List();
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

class UMLRawNote {
  final double pitch;
  final double velocity;
  final double startBeat;
  final double durationBeats;
  final double strikeVal;
  final String noteName;
  final bool hasStop;
  final bool hasGlide;
  final bool hasVibrato;
  final bool hasVelGlide;

  UMLRawNote({
    required this.pitch,
    required this.velocity,
    required this.startBeat,
    required this.durationBeats,
    this.strikeVal = 0.0,
    this.noteName = '',
    this.hasStop = false,
    this.hasGlide = false,
    this.hasVibrato = false,
    this.hasVelGlide = false,
  });
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
  final int instrumentId;
  final String name;

  static late final _funcCreate = _dylib.lookupFunction<_c_sequence_create, _dart_sequence_create>('sequence_create');
  static late final _funcDestroy = _dylib.lookupFunction<_c_sequence_destroy, _dart_sequence_destroy>('sequence_destroy');

  /// Parse a UML notation string into a native sequence timeline.
  ///
  /// [name] — unique identifier for the sequence.
  /// [instrumentID] — target instrument (0–48).
  /// [umlDataString] — the UML notation text.
  UMLSequence(this.name, this.instrumentId, String umlDataString) {
    final namePtr = name.toNativeUtf8();
    final dataPtr = umlDataString.toNativeUtf8();
    try {
      _handle = _funcCreate(namePtr.cast(), instrumentId, dataPtr.cast());
    } finally {
      malloc.free(namePtr);
      malloc.free(dataPtr);
    }
  }

  static late final _funcGetBpm = _dylib.lookupFunction<_c_sequence_get_bpm, _dart_sequence_get_bpm>('sequence_get_bpm');
  static late final _funcSetBpm = _dylib.lookupFunction<_c_sequence_set_bpm, _dart_sequence_set_bpm>('sequence_set_bpm');
  static late final _funcGetUmlData = _dylib.lookupFunction<_c_sequence_get_uml_data, _dart_sequence_get_uml_data>('sequence_get_uml_data');
  static late final _funcGetGrid = _dylib.lookupFunction<_c_sequence_get_grid, _dart_sequence_get_grid>('sequence_get_grid');
  static late final _funcGetMeasure = _dylib.lookupFunction<_c_sequence_get_measure, _dart_sequence_get_measure>('sequence_get_measure');
  static late final _funcGetInst = _dylib.lookupFunction<_c_sequence_get_instrument, _dart_sequence_get_instrument>('sequence_get_instrument');
  static late final _funcGetBasefreq = _dylib.lookupFunction<_c_sequence_get_basefreq, _dart_sequence_get_basefreq>('sequence_get_basefreq');
  static late final _funcSetBasefreq = _dylib.lookupFunction<_c_sequence_set_basefreq, _dart_sequence_set_basefreq>('sequence_set_basefreq');

  static late final _funcAddNote = _dylib.lookupFunction<_c_sequence_add_note, _dart_sequence_add_note>('sequence_add_note');
  static late final _funcRemoveNote = _dylib.lookupFunction<_c_sequence_remove_note, _dart_sequence_remove_note>('sequence_remove_note');
  static late final _funcClearNotes = _dylib.lookupFunction<_c_sequence_clear_notes, _dart_sequence_clear_notes>('sequence_clear_notes');
  static late final _funcGetNotes = _dylib.lookupFunction<_c_sequence_get_notes, _dart_sequence_get_notes>('sequence_get_notes');
  static late final _funcPrepare = _dylib.lookupFunction<_c_sequence_prepare, _dart_sequence_prepare>('sequence_prepare');
  static late final _funcIsDirty = _dylib.lookupFunction<_c_sequence_is_dirty, _dart_sequence_is_dirty>('sequence_is_dirty');

  /// Whether the sequence has unsaved modifications.
  bool get isDirty => _isDisposed ? false : _funcIsDirty(_handle) != 0;

  /// The parsed BPM (beats per minute). Defaults to 120.0.
  double get bpm => _isDisposed ? 120.0 : _funcGetBpm(_handle);
  /// Set the BPM. Scales internal event times.
  set bpm(double value) { if (!_isDisposed) _funcSetBpm(_handle, value); }

  /// The serialized UML sequence representation.
  String get umlData => _isDisposed ? "" : _funcGetUmlData(_handle).toDartString();

  /// The grid subdivision (cells per beat). Defaults to 4.
  int get grid => _isDisposed ? 4 : _funcGetGrid(_handle);
  /// The number of beats per measure. Defaults to 4.
  int get measure => _isDisposed ? 4 : _funcGetMeasure(_handle);
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

  void prepare() {
    if (!_isDisposed) _funcPrepare(_handle);
  }

  void addNote(double pitch, double velocity, double startBeat, double durationBeats, String noteName, {double strikeVal = 0.0}) {
    if (!_isDisposed) {
      final namePtr = noteName.toNativeUtf8();
      try {
        _funcAddNote(_handle, pitch, velocity, startBeat, durationBeats, namePtr, strikeVal);
      } finally {
        malloc.free(namePtr);
      }
    }
  }

  void removeNote(double pitch, double startBeat) {
    if (!_isDisposed) _funcRemoveNote(_handle, pitch, startBeat);
  }

  void clearNotes() {
    if (!_isDisposed) _funcClearNotes(_handle);
  }

  List<UMLRawNote> getNotes(double fromBeat, double toBeat, {int maxNotes = 128}) {
    if (_isDisposed) return [];
    final Pointer<Float> buffer = malloc.allocate<Float>(maxNotes * 9 * sizeOf<Float>());
    final int nameBufSize = maxNotes * 64;
    final Pointer<Uint8> nameBuf = malloc.allocate<Uint8>(nameBufSize);
    try {
      final int count = _funcGetNotes(_handle, fromBeat, toBeat, buffer, maxNotes, nameBuf);
      List<UMLRawNote> result = [];
      int nameOffset = 0;
      for (int i = 0; i < count; i++) {
        int idx = i * 9;
        final name = nameBuf.elementAt(nameOffset).cast<Utf8>().toDartString();
        nameOffset += name.length + 1;
        result.add(UMLRawNote(
          pitch: buffer[idx],
          velocity: buffer[idx + 1],
          startBeat: buffer[idx + 2],
          durationBeats: buffer[idx + 3],
          strikeVal: buffer[idx + 4],
          hasStop: buffer[idx + 5] > 0.5,
          hasGlide: buffer[idx + 6] > 0.5,
          hasVibrato: buffer[idx + 7] > 0.5,
          hasVelGlide: buffer[idx + 8] > 0.5,
          noteName: name,
        ));
      }
      return result;
    } finally {
      malloc.free(buffer);
      malloc.free(nameBuf);
    }
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

  static late final _funcGetInstance = _dylib.lookupFunction<_c_orch_get_instance, _dart_orch_get_instance>('orchestrator_get_instance');
  static late final _funcDestroy = _dylib.lookupFunction<_c_orch_destroy, _dart_orch_destroy>('orchestrator_destroy');
  static late final _funcAddSeq = _dylib.lookupFunction<_c_orch_add_seq, _dart_orch_add_seq>('orchestrator_add_sequence');
  static late final _funcClearSequence = _dylib.lookupFunction<_c_orch_clear_sequence, _dart_orch_clear_sequence>('orchestrator_clear_sequence');
  static late final _funcClearSequences = _dylib.lookupFunction<_c_orch_clear_sequences, _dart_orch_clear_sequences>('orchestrator_clear_sequences');
  static late final _funcPlay = _dylib.lookupFunction<_c_orch_play, _dart_orch_play>('orchestrator_play');
  static late final _funcPlaySequences = _dylib.lookupFunction<_c_orch_play_sequences, _dart_orch_play_sequences>('orchestrator_play_sequences');

  static late final _funcStop = _dylib.lookupFunction<_c_orch_stop, _dart_orch_stop>('orchestrator_stop');
  static late final _funcPause = _dylib.lookupFunction<_c_orch_pause, _dart_orch_pause>('orchestrator_pause');
  static late final _funcResume = _dylib.lookupFunction<_c_orch_resume, _dart_orch_resume>('orchestrator_resume');
  static late final _funcSeek = _dylib.lookupFunction<_c_orch_seek, _dart_orch_seek>('orchestrator_seek');
  static late final _funcSetSongLooping = _dylib.lookupFunction<_c_orch_set_song_looping, _dart_orch_set_song_looping>('orchestrator_set_song_looping');
  static late final _funcMuteSequence = _dylib.lookupFunction<_c_orch_mute_sequence, _dart_orch_mute_sequence>('orchestrator_mute_sequence');
  static late final _funcSetWeight = _dylib.lookupFunction<_c_orch_set_weight, _dart_orch_set_weight>('orchestrator_set_weight');
  static late final _funcSetParam = _dylib.lookupFunction<_c_orch_set_param, _dart_orch_set_param>('orchestrator_set_parameter');

  static late final _funcRegisterTickCb = _dylib.lookupFunction<_c_orch_register_tick_callback, _dart_orch_register_tick_callback>('orchestrator_register_tick_callback');
  static late final _funcPollFinished = _dylib.lookupFunction<_c_orch_poll_finished, _dart_orch_poll_finished>('orchestrator_poll_finished');
  static late final _funcLoadSong = _dylib.lookupFunction<_c_orch_load_song, _dart_orch_load_song>('orchestrator_load_song');
  static late final _funcUnloadSong = _dylib.lookupFunction<_c_orch_unload_song, _dart_orch_unload_song>('orchestrator_unload_song');
  static late final _funcPlaySong = _dylib.lookupFunction<_c_orch_play_song, _dart_orch_play_song>('orchestrator_play_song');
  static late final _funcStopSong = _dylib.lookupFunction<_c_orch_stop_song, _dart_orch_stop_song>('orchestrator_stop_song');

  /// Access the global singleton orchestrator. Prefer [FaustEngine.getOrchestrator].
  ///
  /// The native orchestrator is a process-wide singleton; every call returns
  /// the same instance. There is no per-session create/destroy lifecycle.
  factory SequenceOrchestrator() {
    _instance ??= SequenceOrchestrator._();
    return _instance!;
  }

  static SequenceOrchestrator? _instance;

  SequenceOrchestrator._() {
    _handle = _funcGetInstance();
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

  /// Stop a single sequence and drop the orchestrator's reference to it.
  ///
  /// The sequence object itself stays alive as long as Dart still owns it
  /// (and is freed by reference count when the last owner disposes it).
  void clearSequence(String name) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcClearSequence(_handle, namePtr.cast());
    } finally {
      malloc.free(namePtr);
    }
  }

  /// Stop all playback and drop every sequence reference held by the
  /// orchestrator.
  void clearSequences() {
    if (_isDisposed) return;
    _funcClearSequences(_handle);
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

  /// Trigger playback for a registered sequence by name.
  void play(String name) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcPlay(_handle, namePtr.cast());
    } finally {
      malloc.free(namePtr);
    }
  }

  /// Trigger playback for a list of registered sequences in a single batch FFI call.
  /// This prevents the audio thread from running between play triggers, which could
  /// cause first-note skipping on subsequent tracks due to clock misalignment.
  void playSequences(List<String> names) {
    if (_isDisposed || names.isEmpty) return;
    final Pointer<Pointer<Utf8>> pointerArray = malloc<Pointer<Utf8>>(names.length);
    final List<Pointer<Utf8>> allocatedPointers = [];
    try {
      for (int i = 0; i < names.length; i++) {
        final ptr = names[i].toNativeUtf8();
        pointerArray[i] = ptr;
        allocatedPointers.add(ptr);
      }
      _funcPlaySequences(_handle, pointerArray, names.length);
    } finally {
      for (final ptr in allocatedPointers) {
        malloc.free(ptr);
      }
      malloc.free(pointerArray);
    }
  }

  /// Stop all playback.
  void stop() => _isDisposed ? null : _funcStop(_handle);
  /// Pause all playback (suspends the audio device).
  void pause() => _isDisposed ? null : _funcPause(_handle);
  /// Resume from pause.
  void resume() => _isDisposed ? null : _funcResume(_handle);

  /// Seek to a global sample offset.
  void seek(int sampleOffset) => _isDisposed ? null : _funcSeek(_handle, sampleOffset);

  /// Enable or disable global song looping.
  void setSongLooping(bool loop) => _isDisposed ? null : _funcSetSongLooping(_handle, loop ? 1 : 0);

  /// Mute or unmute a sequence by name.
  void muteSequence(String name, {bool mute = true}) {
    if (_isDisposed) return;
    final namePtr = name.toNativeUtf8();
    try {
      _funcMuteSequence(_handle, namePtr.cast(), mute ? 1 : 0);
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

  /// Register a tick callback that fires on every audio block with playhead state.
  void registerTickCallback(Pointer<NativeFunction<TickCallbackNative>> callback, Pointer<Void> userData) {
    _funcRegisterTickCb(_handle, callback, userData);
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

  /// @Deprecated: The orchestrator is a process-wide singleton; it is never
  /// created or destroyed per-session. Use [stop]/[clearSequences] to release
  /// playback state instead. Retained for backward compatibility only.
  @Deprecated('Use clearSequences()/stop() — the orchestrator is a singleton')
  void dispose() {
    if (!_isDisposed && _handle != nullptr) {
      _funcDestroy(_handle);
      _isDisposed = true;
    }
  }

  /// The native FFI pointer backing this orchestrator.
  Pointer<NativeOrchestratorOpaque> get nativePointer => _handle;
}

/// Singleton real-time audio mixer and hardware driver.
///
/// [FaustMixer] is the central audio hub that owns the hardware output device
/// and a persistent worker thread pool for concurrent DSP rendering. It manages
/// three core concerns:
///
/// 1. **Track lifecycle** — instruments are attached to numbered tracks via
///    [registerInstrument] (convenience, auto-creates a track) or the explicit
///    [addTrack] / [addInstrumentToTrack] pair. Muting a track
///    ([muteTrack]) skips its DSP entirely (0% CPU while silenced).
///
/// 2. **Per-track effects** — each track carries its own Faust FX chain:
///    [setTrackReverbSend], [setTrackEcho], [setTrackEQ] / [setTrackMid],
///    with per-effect bypass switches ([setTrackBypassEQ], [setTrackBypassEcho]).
///
/// 3. **Weight system** — two modes controlled by [setWeightMode]:
///    - *STATIC* (0): weights are fixed to the value passed at registration
///      time. Ideal during setup / initialisation.
///    - *DYNAMIC* (1): weights can be updated at any time via
///      [setTrackWeight] and are auto-normalised so the sum of all active
///      track weights stays at 1.0, preventing master-bus clipping when
///      tracks are added or removed on the fly. Use this mode for live
///      mixing or automation.
///
/// Typical startup sequence:
/// ```dart
/// final mixer = FaustMixer.instance;
/// mixer.init(48000);
/// mixer.setWeightMode(0);            // STATIC during setup
/// final t1 = mixer.registerInstrument(flute, 0.8);
/// final t2 = mixer.registerInstrument(sitar, 0.6);
/// mixer.start();
/// mixer.setWeightMode(1);            // switch to DYNAMIC for live control
/// mixer.setTrackWeight(t1, 0.5);     // real-time adjustment
/// ```
///
/// Access via [FaustMixer.instance]. Call [init] once, then [start] to open
/// the hardware audio device.
class FaustMixer {
  /// The global singleton mixer instance.
  static final FaustMixer instance = FaustMixer._internal();
  late final Pointer<NativeMixerOpaque> _handle;

  static late final _funcGetInstance = _dylib.lookupFunction<_c_mixer_get_instance, _dart_mixer_get_instance>('mixer_get_instance');
  static late final _funcInit = _dylib.lookupFunction<_c_mixer_init, _dart_mixer_init>('mixer_init');
  static late final _funcStart = _dylib.lookupFunction<_c_mixer_start, _dart_mixer_start>('mixer_start');
  static late final _funcStartAsync = _dylib.lookupFunction<_c_mixer_start_async, _dart_mixer_start_async>('mixer_start_async');
  static late final _funcStop = _dylib.lookupFunction<_c_mixer_stop, _dart_mixer_stop>('mixer_stop');
  static late final _funcClearAll = _dylib.lookupFunction<_c_mixer_clear_all, _dart_mixer_clear_all>('mixer_clear_all');
  static late final _funcGetSR = _dylib.lookupFunction<_c_mixer_get_sr, _dart_mixer_get_sr>('mixer_get_sample_rate');
  static late final _funcSetGain = _dylib.lookupFunction<_c_mixer_set_gain, _dart_mixer_set_gain>('mixer_set_master_gain');
  static late final _funcSetInstWeight = _dylib.lookupFunction<_c_mixer_set_inst_weight, _dart_mixer_set_inst_weight>('mixer_set_instrument_weight');
  static late final _funcRegisterWaveformCb = _dylib.lookupFunction<_c_mixer_register_waveform_callback, _dart_mixer_register_waveform_callback>('mixer_register_waveform_callback');
  static late final _funcRegisterInst = _dylib.lookupFunction<_c_mixer_register_inst, _dart_mixer_register_inst>('mixer_register_instrument');
  static late final _funcUnregisterInst = _dylib.lookupFunction<_c_mixer_unregister_inst, _dart_mixer_unregister_inst>('mixer_unregister_instrument');
  static late final _funcAddTrack = _dylib.lookupFunction<_c_mixer_add_track, _dart_mixer_add_track>('mixer_add_track');
  static late final _funcRemoveTrack = _dylib.lookupFunction<_c_mixer_remove_track, _dart_mixer_remove_track>('mixer_remove_track');
  static late final _funcAddInstToTrack = _dylib.lookupFunction<_c_mixer_add_inst_to_track, _dart_mixer_add_inst_to_track>('mixer_add_instrument_to_track');
  static late final _funcRemoveInstFromTrack = _dylib.lookupFunction<_c_mixer_remove_inst_from_track, _dart_mixer_remove_inst_from_track>('mixer_remove_instrument_from_track');
  static late final _funcSetTrackEnvelope = _dylib.lookupFunction<_c_mixer_set_track_envelope, _dart_mixer_set_track_envelope>('mixer_set_track_envelope');
  static final _funcSetTrackWeight = _dylib.lookupFunction<_c_mixer_set_track_weight, _dart_mixer_set_track_weight>('mixer_set_track_weight');
  static final _funcSetWeightMode = _dylib.lookupFunction<_c_mixer_set_weight_mode, _dart_mixer_set_weight_mode>('mixer_set_weight_mode');
  static final _funcGetTrackWeight = _dylib.lookupFunction<_c_mixer_get_track_weight, _dart_mixer_get_track_weight>('mixer_get_track_weight');
  static final _funcGetTrackMute = _dylib.lookupFunction<_c_mixer_get_track_mute, _dart_mixer_get_track_mute>('mixer_get_track_mute');
  static final _funcMuteTrack = _dylib.lookupFunction<_c_mixer_mute_track, _dart_mixer_mute_track>('mixer_mute_track');
  static final _funcUnmuteTracks = _dylib.lookupFunction<_c_mixer_unmute_tracks, _dart_mixer_unmute_tracks>('mixer_unmute_tracks');
  static final _funcUnmuteTrack = _dylib.lookupFunction<_c_mixer_unmute_track, _dart_mixer_unmute_track>('mixer_unmute_track');
  static final _funcSetTrackReverb = _dylib.lookupFunction<_c_mixer_set_track_reverb, _dart_mixer_set_track_reverb>('mixer_set_track_reverb');
  static final _funcSetTrackEcho = _dylib.lookupFunction<_c_mixer_set_track_echo, _dart_mixer_set_track_echo>('mixer_set_track_echo');
  static final _funcSetTrackEQ = _dylib.lookupFunction<_c_mixer_set_track_eq, _dart_mixer_set_track_eq>('mixer_set_track_eq');
  static final _funcSetTrackMid = _dylib.lookupFunction<_c_mixer_set_track_mid, _dart_mixer_set_track_mid>('mixer_set_track_mid');
  static final _funcSetTrackBypassEQ = _dylib.lookupFunction<_c_mixer_set_track_bypass_eq, _dart_mixer_set_track_bypass_eq>('mixer_set_track_bypass_eq');
  static final _funcSetTrackBypassEcho = _dylib.lookupFunction<_c_mixer_set_track_bypass_echo, _dart_mixer_set_track_bypass_echo>('mixer_set_track_bypass_echo');
  static final _funcSetFXReturn = _dylib.lookupFunction<_c_mixer_set_fx_return, _dart_mixer_set_fx_return>('mixer_set_fx_return');
  static final _funcMasterFadeIn = _dylib.lookupFunction<_c_mixer_master_fade_in, _dart_mixer_master_fade_in>('mixer_master_fade_in');
  static final _funcMasterFadeOut = _dylib.lookupFunction<_c_mixer_master_fade_out, _dart_mixer_master_fade_out>('mixer_master_fade_out');

  FaustMixer._internal() {
    _handle = _funcGetInstance();
  }

  /// Initialise the mixer at the given hardware sample rate.
  ///
  /// Must be called exactly once before [start]. Creates the internal
  /// thread pool and pre-allocates all intermediate render buffers.
  /// The sample rate is fixed for the lifetime of the process — all
  /// instruments and sequences must match this rate.
  void init(double sampleRate) => _funcInit(_handle, sampleRate);

  /// Open the hardware audio device and begin rendering.
  ///
  /// Returns `true` if the device was opened successfully. Calling
  /// [start] more than once is a safe no-op.
  bool start() => _funcStart(_handle) != 0;

  /// Asynchronously open the hardware audio device without blocking the UI.
  ///
  /// Resolves when the hardware callback has fired for the first time.
  /// Prefer this over [start] on platforms where the audio driver may
  /// take several hundred milliseconds to wake from a suspended state
  /// (e.g. PulseAudio on Linux, CoreAudio on macOS after sleep).
  Future<void> startAsync() async {
    final completer = Completer<void>();
    final callable = NativeCallable<VoidFunctionNative>.listener(() {
      completer.complete();
    });
    _funcStartAsync(_handle, callable.nativeFunction);
    await completer.future;
    callable.close();
  }

  /// Stop the hardware audio device and drain the worker pool.
  ///
  /// All in-flight render work is completed before the device is closed.
  /// The mixer can be restarted with [start] without calling [init] again.
  void stop() => _funcStop(_handle);

  /// Remove every track, instrument and FX chain from the mixer.
  ///
  /// Useful when switching song/scene. The hardware device is left open;
  /// call [stop] to release it.
  void clearAll() => _funcClearAll(_handle);

  /// The hardware sample rate passed to [init].
  ///
  /// Returns `0.0` if [init] has not been called yet.
  double get sampleRate => _funcGetSR(_handle);

  NativeCallable<WaveformCallbackNative>? _waveformCallable;
  void Function(double rms, double peak)? _onWaveform;

  /// Callback invoked on every rendered audio block with the block's RMS
  /// and peak level of the final stereo mix.
  ///
  /// Set this to receive level updates, or to `null` to disable monitoring.
  /// This is a high-frequency callback (fires once per audio buffer, e.g.
  /// ~48 Hz at 1024 frames / 48 kHz) — keep the handler cheap and avoid
  /// heavy work or blocking. It runs on the audio thread, so use it for
  /// level meters / visualizers, not for DSP or UI work.
  ///
  /// The first callback argument is the RMS value, the second the peak.
  void Function(double rms, double peak)? get onWaveform => _onWaveform;
  set onWaveform(void Function(double rms, double peak)? cb) {
    _onWaveform = cb;
    _waveformCallable?.close();
    _waveformCallable = null;
    if (cb != null) {
      _waveformCallable = NativeCallable<WaveformCallbackNative>.listener(
        (double rms, double peak, Pointer<Void> _) => cb(rms, peak),
      );
      _funcRegisterWaveformCb(_handle, _waveformCallable!.nativeFunction, nullptr);
    } else {
      _funcRegisterWaveformCb(_handle, nullptr, nullptr);
    }
  }

  /// Low-level variant of [onWaveform] taking raw FFI pointers.
  ///
  /// Most users should prefer [onWaveform], which manages the native
  /// callable lifetime automatically. If you use this directly, keep the
  /// returned [NativeCallable] alive and close it with
  /// [clearWaveformCallback] when done.
  @Deprecated('Use the onWaveform setter, which manages the native callable for you')
  void registerWaveformCallback(Pointer<NativeFunction<WaveformCallbackNative>> callback, Pointer<Void> userData) {
    _funcRegisterWaveformCb(_handle, callback, userData);
  }

  /// Drop the current waveform callback and free its native callable.
  void clearWaveformCallback() {
    onWaveform = null;
  }

  double _masterGain = 1.0;

  /// The current master bus gain.
  ///
  /// Defaults to `1.0`. Values above `1.0` are permitted but will push the
  /// output into the master limiter (soft-clip) sooner.
  double get masterGain => _masterGain;

  /// Set the master bus gain.
  ///
  /// [gain] is applied after all tracks and FX are summed, immediately
  /// before the master limiter. This is the global output volume.
  ///
  /// Prefer [setTrackWeight] for per-track balancing; use [masterGain] only
  /// for the final output level that should touch every track equally.
  set masterGain(double gain) {
    _masterGain = gain;
    _funcSetGain(_handle, gain);
  }

  /// Set the volume weight of a registered instrument inside its mixer track.
  void setInstrumentWeight(FaustInstrument inst, double weight) {
    _funcSetInstWeight(_handle, inst.nativePointer, weight);
  }

  /// Register an instrument with the mixer, returning its track ID.
  ///
  /// [weight] is the initial track weight (0.0–1.0). The returned ID is used
  /// by all subsequent per-track operations ([muteTrack], [setTrackWeight],
  /// FX setters, etc.).
  ///
  /// Throws [ArgumentError] if the instrument's sample rate does not match
  /// the mixer's, which would corrupt the timing of the shared DSP pipeline.
  ///
  /// Note: registering an instrument is equivalent to [addTrack] +
  /// [addInstrumentToTrack] in a single call.
  int registerInstrument(FaustInstrument inst, double weight) {
    final result = _funcRegisterInst(_handle, inst.nativePointer, weight);
    if (result == 0) {
      throw ArgumentError(
        'Sample rate mismatch: mixer SR=${sampleRate.toStringAsFixed(0)}, '
        'instrument SR=${inst.sampleRate.toStringAsFixed(0)}. '
        'Create the instrument with the mixer\'s sample rate.'
      );
    }
    return result;
  }

  /// Unregister an instrument, removing it and its track from the mixer.
  void unregisterInstrument(FaustInstrument inst) {
    _funcUnregisterInst(_handle, inst.nativePointer);
  }

  /// Create an empty mixer track and return its track ID.
  ///
  /// [initialWeight] (0.0–1.0) is the starting weight used by the weight
  /// system. Attach instruments with [addInstrumentToTrack]. In DYNAMIC
  /// mode this weight is re-normalised automatically.
  int addTrack(double initialWeight) => _funcAddTrack(_handle, initialWeight);

  /// Remove a track and everything attached to it from the mixer.
  void removeTrack(int trackID) => _funcRemoveTrack(_handle, trackID);

  /// Attach an already-created instrument to an existing track.
  ///
  /// Requires a track created with [addTrack]. For the common single-track
  /// case, prefer [registerInstrument] which creates the track for you.
  void addInstrumentToTrack(int trackID, FaustInstrument inst, double instWeight) =>
      _funcAddInstToTrack(_handle, trackID, inst.nativePointer, instWeight);

  /// Detach an instrument from a track.
  void removeInstrumentFromTrack(int trackID, FaustInstrument inst) =>
      _funcRemoveInstFromTrack(_handle, trackID, inst.nativePointer);

  /// Set a per-track breakpoint envelope (post-weight gain multiplier).
  ///
  /// The envelope plays once over [times] seconds from the moment it is set,
  /// interpolating through [values] using the per-segment [interpTypes]:
  /// `0` = linear, `1` = exponential, `2` = S-curve. Envelope points ride on
  /// top of (multiply) the track weight.
  ///
  /// [times] and [values] must be the same length; [interpTypes] is one entry
  /// per segment (length `values.length - 1`), or a single scalar applied to
  /// all segments. Pass empty lists to clear the envelope.
  void setTrackEnvelope(int trackID, List<double> times, List<double> values, List<int> interpTypes) {
    final n = times.length;
    final tPtr = calloc<Float>(n);
    final vPtr = calloc<Float>(n);
    final iPtr = calloc<Uint8>(n);
    for (int j = 0; j < n; j++) {
      tPtr[j] = times[j];
      vPtr[j] = values[j];
      iPtr[j] = interpTypes[j];
    }
    _funcSetTrackEnvelope(_handle, trackID, tPtr, vPtr, iPtr, n);
    calloc.free(tPtr);
    calloc.free(vPtr);
    calloc.free(iPtr);
  }

  /// Immediately set a track's weight.
  ///
  /// In DYNAMIC mode (see [setWeightMode]) the other active tracks are
  /// re-normalised so the total sum of weights equals 1.0, keeping the
  /// master bus free of clipping. [weight] is clamped to 0.0–1.0.
  ///
  /// In STATIC mode this has no effect — weights are fixed to the value
  /// given at registration/add-track time.
  void setTrackWeight(int trackID, double weight) =>
      _funcSetTrackWeight(_handle, trackID, weight);

  /// Select the mixer weight mode.
  ///
  /// **Recommended workflow:**
  /// 1. Call `setWeightMode(0)` (STATIC) before registering tracks so each
  ///    track keeps the exact [weight] you pass to [addTrack] or
  ///    [registerInstrument].
  /// 2. Register all tracks.
  /// 3. Once the mix is set up, call `setWeightMode(1)` (DYNAMIC) so weights
  ///    can be adjusted in real time with [setTrackWeight].
  ///
  /// [mode]: `0` = STATIC_WEIGHTS (fixed at registration), `1` = DYNAMIC_WEIGHTS
  /// (auto-normalised, real-time adjustable).
  void setWeightMode(int mode) =>
      _funcSetWeightMode(_handle, mode);

  /// Query the current weight of a track.
  ///
  /// Returns the effective weight; in DYNAMIC mode this is the normalised
  /// value (each track's share of the active sum).
  double getTrackWeight(int trackID) =>
      _funcGetTrackWeight(_handle, trackID);

  /// Whether the track is currently muted.
  bool getTrackMute(int trackID) => _funcGetTrackMute(_handle, trackID) != 0;

  /// Mute a track, skipping its DSP rendering entirely (0% CPU).
  ///
  /// A muted track makes no sound. Unmute with [unmuteTrack] or
  /// [unmuteTracks].
  void muteTrack(int trackID) =>
      _funcMuteTrack(_handle, trackID);

  /// Unmute several tracks atomically.
  ///
  /// Unmuting via a single call prevents the audio thread from rendering a
  /// partial mix between individual unmutes, giving sample-tight sync when
  /// bringing a whole group back in on a downbeat.
  void unmuteTracks(List<int> trackIDs) {
    final pointer = calloc<Int32>(trackIDs.length);
    for (int i = 0; i < trackIDs.length; i++) {
      pointer[i] = trackIDs[i];
    }
    _funcUnmuteTracks(_handle, pointer, trackIDs.length);
    calloc.free(pointer);
  }

  /// Unmute a single track.
  void unmuteTrack(int trackID) =>
      _funcUnmuteTrack(_handle, trackID);

  /// Set this track's send level into the shared master reverb bus.
  ///
  /// [send] (0.0..1.0) is the wet amount. Sends from every track are summed
  /// and returned through the master bus scaled by [fxReturnWeight]. A send
  /// of `0.0` routes nothing to the reverb.
  void setTrackReverbSend(int trackID, double send) =>
      _funcSetTrackReverb(_handle, trackID, send);

  /// Configure this track's echo (delay) effect.
  ///
  /// - [send]: wet mix level (0.0 = dry, 1.0 = full echo).
  /// - [feedback]: regeneration of the delayed signal (0.0..0.95). Higher
  ///   values repeat the echo longer and can build toward runaway feedback.
  /// - [delaySec]: echo delay time in seconds (default 0.25).
  void setTrackEcho(int trackID, double send, {double feedback = 0.3, double delaySec = 0.25}) =>
      _funcSetTrackEcho(_handle, trackID, send, feedback, delaySec);

  /// Set this track's bass/treble shelving EQ gains in dB.
  ///
  /// [bassDb] and [trebleDb] are shelf gains (−18..+18 dB, `0` disables).
  /// Bass shelf sits at 250 Hz, treble shelf at 2500 Hz. Use [setTrackMid]
  /// for a parametric mid band, and [setTrackBypassEQ] to toggle the whole
  /// EQ stage on/off.
  void setTrackEQ(int trackID, double bassDb, double trebleDb) =>
      _funcSetTrackEQ(_handle, trackID, bassDb, trebleDb);

  /// Set this track's parametric mid (peaking) band.
  ///
  /// - [midDb]: gain in dB at the center frequency (−18..+18).
  /// - [midFreq]: center frequency in Hz (20..20000, default 1000).
  /// - [midQ]: bandwidth (0.1..18, default 1.0). Higher Q = narrower band.
  void setTrackMid(int trackID, double midDb, {double midFreq = 1000.0, double midQ = 1.0}) =>
      _funcSetTrackMid(_handle, trackID, midDb, midFreq, midQ);

  /// Bypass or re-engage this track's EQ stage.
  ///
  /// When [bypass] is `true` the EQ is skipped and the dry signal passes
  /// through unchanged. Pass `false` to re-engage.
  void setTrackBypassEQ(int trackID, {bool bypass = true}) =>
      _funcSetTrackBypassEQ(_handle, trackID, bypass ? 1.0 : 0.0);

  /// Bypass or re-engage this track's echo stage.
  ///
  /// When [bypass] is `true` the echo is skipped. Pass `false` to re-engage.
  void setTrackBypassEcho(int trackID, {bool bypass = true}) =>
      _funcSetTrackBypassEcho(_handle, trackID, bypass ? 1.0 : 0.0);

  /// Set the master FX (reverb) return weight (0.0..1.0).
  ///
  /// Scales the summed wet reverb signal added back into the master bus.
  /// A value of `0.0` silences the global reverb entirely.
  set fxReturnWeight(double weight) => _funcSetFXReturn(_handle, weight);

  /// Fade the master bus from 0 to 1.0 over [durationSeconds].
  ///
  /// A typical startup ramp to avoid an opening click. Interrupted by
  /// [masterFadeOut] or a direct [masterGain] write.
  void masterFadeIn(double durationSeconds) =>
      _funcMasterFadeIn(_handle, durationSeconds);

  /// Fade the master bus from its current gain to 0 over [durationSeconds].
  ///
  /// Use before [stop] for a click-free shutdown. Interrupted by
  /// [masterFadeIn] or a direct [masterGain] write.
  void masterFadeOut(double durationSeconds) =>
      _funcMasterFadeOut(_handle, durationSeconds);
}

/// Global asset manager and initializer for the Faust synthesis engine.
///
/// [init] must be called once before creating any instruments or sequences.
/// It copies the bundled DSP/CSV assets from the package into app storage and
/// tells the native engine where to find them. On subsequent launches it
/// skips files whose size and mtime already match, so it is near-instant.
///
/// [getOrchestrator] and [getMixer] are the canonical entry points for the
/// process-wide [SequenceOrchestrator] and [FaustMixer] singletons.
class FaustEngine {
  static late final _funcSetAssetBasePath =
      _dylib.lookupFunction<_c_engine_set_asset_base_path, _dart_engine_set_asset_base_path>(
          'faust_min_set_asset_base_path');
  static late final _funcGetAssetBasePath =
      _dylib.lookupFunction<_c_engine_get_asset_base_path, _dart_engine_get_asset_base_path>(
          'faust_min_get_asset_base_path');

  static bool _initialized = false;
  static SequenceOrchestrator? _orchestrator;

  /// The global singleton [SequenceOrchestrator].
  ///
  /// The native orchestrator is a process-wide singleton shared by every
  /// caller; no per-session create/destroy lifecycle exists.
  static SequenceOrchestrator getOrchestrator() =>
      _orchestrator ??= SequenceOrchestrator();

  /// The global singleton [FaustMixer].
  static FaustMixer getMixer() => FaustMixer.instance;

  /// Returns the native asset base path (directory where DSP/CSV assets were
  /// extracted by [init]). Empty until [init] completes.
  static String getAssetBasePath() {
    final ptr = _funcGetAssetBasePath();
    if (ptr == nullptr) return '';
    return ptr.toDartString();
  }

  /// Copies all instrument CSV tables and DSP assets from Flutter package assets
  /// to local app storage and configures native C++ engines with the extracted directory path.
  ///
  /// Unchanged files are skipped: an existing target is reused when its size and
  /// modification time match the on-disk source asset, or (when the source cannot
  /// be stat'd, e.g. packaged builds) when its content is byte-identical.
  static Future<void> init() async {
    if (_initialized) return;
    try {
      final dir = await getApplicationSupportDirectory();
      final dspDir = Directory('${dir.path}/dsp');
      if (!dspDir.existsSync()) {
        dspDir.createSync(recursive: true);
      }

      final manifest = await AssetManifest.loadFromAssetBundle(rootBundle);
      final dspAssets = manifest.listAssets().where((key) => key.contains('assets/dsp/'));

      for (final assetKey in dspAssets) {
        final fileName = assetKey.split('/').last;
        final targetFile = File('${dspDir.path}/$fileName');
        try {
          final byteData = await rootBundle.load(assetKey);
          final bytes = byteData.buffer.asUint8List(byteData.offsetInBytes, byteData.lengthInBytes);
          final sourceStat = _statSourceAsset(assetKey, fileName);
          if (_isUpToDate(targetFile, bytes, sourceStat)) continue;
          await targetFile.writeAsBytes(bytes, flush: true);
          if (sourceStat != null) {
            targetFile.setLastModifiedSync(sourceStat.modified);
          }
        } catch (_) {}
      }

      final nativePath = dir.path.toNativeUtf8();
      try {
        _funcSetAssetBasePath(nativePath.cast());
      } finally {
        malloc.free(nativePath);
      }

      _initialized = true;
    } catch (_) {}
  }

  /// Best-effort stat of the on-disk source asset (available during source/dev
  /// runs from the plugin repo). Returns `null` when the asset is only reachable
  /// through the asset bundle (packaged builds).
  static FileStat? _statSourceAsset(String assetKey, String fileName) {
    final candidates = <String>[
      assetKey.startsWith('packages/')
          ? assetKey.substring(assetKey.indexOf('/') + 1)
          : assetKey,
      'assets/dsp/$fileName',
    ];
    for (final candidate in candidates) {
      try {
        final stat = File(candidate).statSync();
        if (stat.type != FileSystemEntityType.notFound) return stat;
      } catch (_) {}
    }
    return null;
  }

  static bool _isUpToDate(File targetFile, Uint8List bytes, FileStat? sourceStat) {
    if (!targetFile.existsSync()) return false;
    if (targetFile.lengthSync() != bytes.length) return false;
    if (sourceStat != null) {
      return targetFile.lastModifiedSync() == sourceStat.modified;
    }
    return _bytesEqual(targetFile.readAsBytesSync(), bytes);
  }

  static bool _bytesEqual(List<int> a, List<int> b) {
    if (a.length != b.length) return false;
    for (var i = 0; i < a.length; i++) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
}

