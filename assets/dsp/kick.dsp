declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Electronic/acoustic kick drum generator utilizing a fast pitch envelope sweep and sub-bass reinforcement.
//
// Parameters (Controls):
//   - freq [unit:Hz]
//   - gain
//   - velocity
//   - gate
//   - sub_boost
// =============================================================================
import("stdfaust.lib");

// --- Dedicated Kick Drum ---
// Expert Play Range: Standard Kick Drum fundamental typically 40-100 Hz.
freq = hslider("freq [unit:Hz]", 100.0, 40, 100, 0.1);
gain = hslider("gain", 0.8, 0, 1, 0.01);
velocity = hslider("velocity", 1, 0, 1, 0.01);
gate = button("gate");

// Add your custom things here (e.g., sub-bass boost)
sub_boost = hslider("sub_boost", 0.5, 0, 1, 0.01);

pitch_env = en.adsr(0.001, 0.03, 0.0, 0.01, gate);
click = no.noise * en.adsr(0.001, 0.005, 0.0, 0.01, gate) * 0.1 * (0.5 + 0.5 * velocity);

kick_body = os.osc(freq * (1 + 0.5 * pitch_env)) * en.adsr(0.001, 0.5, 0.0, 0.1, gate);

process = (kick_body + click) * gain * velocity * (1.0 + 0.2 * velocity);
