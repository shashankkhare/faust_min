import("stdfaust.lib");
mypm = library("physmodels.lib") with { maxLength = 20; };
process = mypm.guitar(10, 0.8, 0.5, 0);
