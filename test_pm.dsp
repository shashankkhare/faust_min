import("stdfaust.lib");
nModes = 11;
velocityInput = (0.5 + _*0.9) , par(i,nModes-1, (_*0.9)) :> _;
process = velocityInput;
