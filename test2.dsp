import("stdfaust.lib");
process = os.pulsetrain(440, 0.5) * 2.0 : ma.tanh;
