import 'dart:typed_data';
import 'package:faust_min/faust_min.dart';

void main() {
  var sitar = FaustSitarInstrument();
  sitar.setFrequency(220.0);
  sitar.pluck(0.8);
  var buf = Float32List(100);
  sitar.render(buf);
  for (int i=0; i<10; i++) print(buf[i]);
  sitar.dispose();
}
