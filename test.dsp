import("stdfaust.lib");
process = os.pulsetrain(440, 0.5) : ma.tanh( * (2.0));
