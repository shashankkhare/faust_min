import 'dart:ffi';
import 'dart:io';
import 'dart:typed_data';
import 'package:ffi/ffi.dart';

// Minimal bindings for the test
class FaustBowlBindings {
  final DynamicLibrary dylib;
  late Pointer<Void> Function(double) bowl_create;
  late void Function(Pointer<Void>, double) bowl_set_frequency;
  late void Function(Pointer<Void>, double) bowl_set_duration;
  late void Function(Pointer<Void>, double) bowl_strike;
  late void Function(Pointer<Void>, int, Pointer<Float>) bowl_render;
  late void Function(Pointer<Void>) bowl_destroy;

  FaustBowlBindings(String path) : dylib = DynamicLibrary.open(path) {
    bowl_create = dylib.lookupFunction<Pointer<Void> Function(Float), Pointer<Void> Function(double)>('bowl_create');
    bowl_set_frequency = dylib.lookupFunction<Void Function(Pointer<Void>, Float), void Function(Pointer<Void>, double)>('bowl_set_frequency');
    bowl_set_duration = dylib.lookupFunction<Void Function(Pointer<Void>, Float), void Function(Pointer<Void>, double)>('bowl_set_duration');
    bowl_strike = dylib.lookupFunction<Void Function(Pointer<Void>, Float), void Function(Pointer<Void>, double)>('bowl_strike');
    bowl_render = dylib.lookupFunction<Void Function(Pointer<Void>, Int32, Pointer<Float>), void Function(Pointer<Void>, int, Pointer<Float>)>('bowl_render');
    bowl_destroy = dylib.lookupFunction<Void Function(Pointer<Void>), void Function(Pointer<Void>)>('bowl_destroy');
  }
}

void main() {
  final libPath = '/home/shashankkhare/AndroidStudioProjects/faust_min/libfaust_min.so';
  final bindings = FaustBowlBindings(libPath);

  final bowl = bindings.bowl_create(44100.0);
  bindings.bowl_set_frequency(bowl, 220.0);
  bindings.bowl_set_duration(bowl, 3.0); // User requested 3 seconds
  bindings.bowl_strike(bowl, 1.0);

  const sampleRate = 44100;
  const duration = 3;
  const numSamples = sampleRate * duration;
  
  final pcm = calloc<Float>(numSamples);
  bindings.bowl_render(bowl, numSamples, pcm);

  final file = File('bowl_3s.raw');
  final bytes = pcm.asTypedList(numSamples).buffer.asUint8List();
  file.writeAsBytesSync(bytes);

  bindings.bowl_destroy(bowl);
  calloc.free(pcm);
  print('Generated bowl_3s.raw (${numSamples} samples)');
}
