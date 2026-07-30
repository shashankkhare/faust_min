declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Organic ambient soundscape generator simulating a rain stick or Tibetan metal rainmaker with bamboo or metal selector and tilt speed.
//
// Parameters (Controls):
//   - Instrument_Material
//   - Tilt_Speed_Hz
//   - freq
//   - gate
// =============================================================================
import("stdfaust.lib");

// --- 0. ENVELOPE ---
gate = button("gate");
attack   = hslider("attack", 5.0, 0.01, 10.0, 0.01);
decay    = hslider("decay",  8.0, 0.01, 10.0, 0.01);
sustain  = hslider("sustain", 0.6, 0.0, 1.0, 0.01);
release  = hslider("release", 1.0, 0.01, 10.0, 0.01);
envelope = en.adsr(attack, decay, sustain, release, gate);

// --- 1. USER CONTROL INTERFACE ---
// Material Selector: 0 = Organic Bamboo, 1 = Tibetan Metal
material_select = hslider("Instrument_Material", 1, 0, 1, 1);

// Tilt Speed: How fast it rocks back and forth (e.g. 0.05 Hz = 20 seconds per tilt)
tilt_speed = hslider("Tilt_Speed_Hz", 0.1, 0.01, 1, 0.01);
gain = hslider("gain", 1.0, 0, 1, 0.01);


// --- 2. AUTOMATED TILT GENERATOR ---
// Generates a smooth, continuous gravity wave for the sliding beads
tilt_energy = abs(os.osc(tilt_speed)) : si.smooth(0.999);


// --- 3. DYNAMIC PHYSICS ENGINE ---
// If selector is 0, use Bamboo settings (150 seeds, 220Hz warm resonance)
// If selector is 1, use Metal settings (45 beads, 880Hz bright crystalline resonance)
// Use the standard 'freq' slider so the sequencer can control the pitch/size of the tube!
freq = ba.if(material_select == 0, 220, 800): si.smoo;

bead_count = ba.if(material_select == 0, 150, 45);

// Custom Rainmaker Physics:
// White noise simulates thousands of tiny bead impacts.
// We amplitude-modulate it with the tilt_energy to simulate the sliding rush of beads.
// Then we pass it through a resonant bandpass filter tuned to 'freq' to simulate the hollow tube!
bead_noise = no.noise * tilt_energy * (bead_count / 150.0);
rainmaker_source = bead_noise : fi.resonbp(freq, 2.0, 1.0);


// --- 4. TIBETAN AMBIENT REVERB (THE CLOUD) ---
// If Metal is selected, we make the reverb slightly brighter (6000Hz damp)
// If Bamboo is selected, we absorb high frequencies (3000Hz damp) for an earthy tone
reverb_damp = ba.if(material_select == 0, 3000, 6000);

// 12.0 second decay creates an endless, continuous wash of soothing rain sound
// Gate envelope applied before reverb so reverb tail rings out naturally
gated_rain = rainmaker_source * envelope;
process = gated_rain * gain * 5.0 : fi.dcblocker : ma.tanh;
