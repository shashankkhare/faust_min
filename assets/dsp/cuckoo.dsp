declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Generates realistic cuckoo bird calls using dual-pitch LFO frequency shifting and organic envelope shaping.
//
// Parameters (Controls):
//   - gain
//   - freq
//   - gate
//   - type
// =============================================================================
import("stdfaust.lib");

// --- INTERFACE CONTROLS ---
gain  = hslider("gain",  0.5, 0, 1, 0.01) : si.smoo;
freq  = hslider("freq",  587.33, 200, 2000, 0.01) : si.smoo; // base frequency
gate  = button("gate");
type  = hslider("type", 0, 0, 2, 1); // 0 = Asian Cuckoo, 1 = Western Cuckoo, 2 = Indian Cuckoo

// --- TIME ACCUMULATOR ---
trig = gate > gate';
sample_count = loop ~ _
with {
    loop(c) = ba.if(trig, 1, ba.if(gate > 0, c + 1, 0));
};
time_sec = sample_count / ma.SR;

// --- WESTERN CUCKOO (2 Notes: Descending Minor Third) ---
w_e1 = max(0.0, sin((time_sec - 0.0) / 0.3 * ma.PI)) * ((time_sec >= 0.0) * (time_sec < 0.3));
w_e2 = max(0.0, sin((time_sec - 0.4) / 0.3 * ma.PI)) * ((time_sec >= 0.4) * (time_sec < 0.7));
west_envelope = w_e1 + w_e2;

west_pitch = ba.if(time_sec < 0.35, freq, freq * 0.8409) : si.smoo; // Smooth glide between notes

// Fundamental tone
west_pure = os.osc(west_pitch);
// Warm wood throat resonance
west_sound = (west_pure + os.osc(west_pitch * 2.0) * 0.12 + os.osc(west_pitch * 3.0) * 0.04) * 0.85 * west_envelope;

// --- ASIAN CUCKOO (4 Notes: Standard D5 -> F5 -> D5 -> Bb4 sequence, played faster) ---
// Note 1: D5 (freq) [0.0 - 0.3]s
// Note 2: F5 (freq * 1.1892) [0.32 - 0.62]s  -- Fast transition (0.02s gap)
// Note 3: D5 (freq) [0.8 - 1.1]s             -- Normal breath gap (0.18s gap)
// Note 4: Bb4 (freq * 0.7937) [1.12 - 1.57]s  -- Fast transition (0.02s gap)
a_e1 = max(0.0, sin((time_sec - 0.0) / 0.3 * ma.PI)) * ((time_sec >= 0.0) * (time_sec < 0.3));
a_e2 = max(0.0, sin((time_sec - 0.32) / 0.3 * ma.PI)) * ((time_sec >= 0.32) * (time_sec < 0.62));
a_e3 = max(0.0, sin((time_sec - 0.8) / 0.3 * ma.PI)) * ((time_sec >= 0.8) * (time_sec < 1.1));
a_e4 = max(0.0, sin((time_sec - 1.12) / 0.45 * ma.PI)) * ((time_sec >= 1.12) * (time_sec < 1.57));
asian_envelope = a_e1 * 0.65 + a_e2 * 0.75 + a_e3 * 0.65 + a_e4 * 1.0;

// Sinusoidal pitch rise and fall (rises 8% at the peak in the middle, then falls back)
p1 = freq * (1.0 + 0.08 * sin((time_sec - 0.0) / 0.3 * ma.PI));
p2 = freq * 1.1892 * (1.0 + 0.08 * sin((time_sec - 0.32) / 0.3 * ma.PI));
p3 = freq * (1.0 + 0.08 * sin((time_sec - 0.76) / 0.3 * ma.PI));
p4 = freq * 0.7937 * (1.0 + 0.08 * sin((time_sec - 1.12) / 0.45 * ma.PI));

// Switch pitch instantly between notes (during silence) to prevent siren sound
asian_target_pitch = ba.if(time_sec < 0.31, p1,
                     ba.if(time_sec < 0.71, p2,
                     ba.if(time_sec < 1.11, p3, p4)));

// Portamento filter for smooth note glides using standard si.smoo (which has a ~25ms exponential response time)
asian_pitch = asian_target_pitch : si.smoo;

// Fundamental tone
asian_pure = os.osc(asian_pitch);
// Warm wood throat resonance
asian_sound = (asian_pure + os.osc(asian_pitch * 2.0) * 0.12 + os.osc(asian_pitch * 3.0) * 0.04) * 0.85 * asian_envelope;

// --- INDIAN CUCKOO (4 Notes: D5 -> F#5 -> F#5 -> D5 sequence, modeled from 5s-7s video track) ---
// Measured Freqs from video track: Note 1 (~1301 Hz), Note 2 (~1443 Hz), Note 3 (~1427 Hz), Note 4 (~1485 -> 1165 Hz)
// Note 1: 1301 Hz (freq) [0.0 - 0.3]s
// Note 2: 1443 Hz (freq * 1.109) [0.32 - 0.62]s  -- Fast transition (0.02s gap)
// Note 3: 1427 Hz (freq * 1.096) [0.8 - 1.1]s     -- Normal breath gap (0.18s gap)
// Note 4: 1485->1165 Hz (freq * 1.142 falling to freq * 0.896) [1.12 - 1.57]s -- Fast transition (0.02s gap)
i_e1 = max(0.0, sin((time_sec - 0.0) / 0.3 * ma.PI)) * ((time_sec >= 0.0) * (time_sec < 0.3));
i_e2 = max(0.0, sin((time_sec - 0.32) / 0.3 * ma.PI)) * ((time_sec >= 0.32) * (time_sec < 0.62));
i_e3 = max(0.0, sin((time_sec - 0.8) / 0.3 * ma.PI)) * ((time_sec >= 0.8) * (time_sec < 1.1));
i_e4 = max(0.0, sin((time_sec - 1.12) / 0.45 * ma.PI)) * ((time_sec >= 1.12) * (time_sec < 1.57));
indian_envelope = i_e1 * 0.65 + i_e2 * 0.75 + i_e3 * 0.65 + i_e4 * 1.0;

// Pitch trajectory matching the exact frequency changes
ip1 = freq * (1.0 - 0.017 * (time_sec / 0.3)); // Note 1: falls slightly from 1301 to 1278 Hz
ip2 = freq * 1.109 * (1.0 + 0.05 * sin((time_sec - 0.32) / 0.3 * ma.PI)); // Note 2: rises to 1443 Hz peak
ip3 = freq * 1.096 * (1.0 + 0.047 * sin((time_sec - 0.8) / 0.3 * ma.PI)); // Note 3: dips and rises to 1494 Hz peak
// Note 4: starts at 1485 Hz (freq * 1.142) and slides/falls down to 1165 Hz (freq * 0.896)
ip4 = freq * (1.142 - (1.142 - 0.896) * ((time_sec - 1.12) / 0.45)); 

// Switch pitch continuously through the target pitch line
indian_target_pitch = ba.if(time_sec < 0.31, ip1,
                      ba.if(time_sec < 0.71, ip2,
                      ba.if(time_sec < 1.11, ip3, ip4)));

// Portamento filter for smooth note glides using standard si.smoo
indian_pitch = indian_target_pitch : si.smoo;

// Fundamental tone
indian_pure = os.osc(indian_pitch);
// Warm wood throat resonance
indian_sound = (indian_pure + os.osc(indian_pitch * 2.0) * 0.12 + os.osc(indian_pitch * 3.0) * 0.04) * 0.85 * indian_envelope;

// --- MAIN ROUTING ---
process = select3(int(type), asian_sound, west_sound, indian_sound) * gain;
