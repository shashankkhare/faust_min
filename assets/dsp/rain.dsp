import("stdfaust.lib");

// =============================================================================
// SIMPLE RAIN GENERATOR
// We intentionally omit the standard 'gain' slider. 
// Instead, 'velocity' acts as the sole master volume (gain) control for this 
// instrument, directly responding to the sequence note intensities.
// =============================================================================

velocity = hslider("velocity", 0.5, 0, 1, 0.01) : si.smoo;

// We explicitly tie gain to velocity internally
gain = velocity;

gate = button("gate");

// 2.0s smooth fade to prevent looping gaps
gate_switch = gate : si.smooth(ba.tau2pole(2.0)); 

// Pink noise perfectly mimics the organic frequency spectrum of falling water.
// Velocity dynamically controls the filter, so higher velocity = heavier/brighter rain.
cutoff = 300.0 + (velocity * 1200.0);
rain_base = no.pink_noise : fi.lowpass(2, cutoff);

// A subtle, slow volume swell simulates organic sheets of rain moving in the wind
swell = (os.osc(0.12) * 0.15) + 0.85;

// Master mix uses the internally linked gain
process = rain_base * swell * gate_switch * gain * 4.0;
