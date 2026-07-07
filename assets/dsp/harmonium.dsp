declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
declare options "[nvoices:6]";

// =============================================================================
// === PHYSICAL HARMONIUM MODEL ===
// Description: Hand-pumped free-reed organ.
//              - Bellows reservoir pressure simulation (inflow / leakage / key-drainage).
//              - Note velocity scales individual key valve apertures.
//              - Multi-reed octave blending stops (Bass, Male, Female).
//              - Wooden case and keybed bandpass resonators.
// =============================================================================

import("stdfaust.lib");

freq = hslider("freq", 440.0, 50, 2000, 0.01);
gate = button("gate");
velocity = hslider("velocity", 0.7, 0, 1, 0.01);
gain = hslider("gain", 0.6, 0, 1, 0.01);

// Global Bellows pressure parameters
pressure = hslider("pressure", 0.8, 0, 1.0, 0.01); // Global hand-pumping target pressure
bellows_growl = hslider("bellows_growl", 0.25, 0, 1.0, 0.01);
reed_octaves = hslider("reed_octaves", 1.0, 0.0, 2.0, 0.1); // Blend between: 0 = Male, 1 = Male+Female, 2 = Bass+Male+Female

// --- Bellows Reservoir Dynamic Simulation ---
// Inflow from hand pumping (LFO-driven bellows strokes to simulate time-varying reservoir replenishment)
pump_lfo = (os.osc(0.6) + 1.0) * 0.5; // slow bellows squeeze cycle (0.6 Hz)
target_inflow = pressure * pump_lfo;

// --- Key Valve Modulation ---
// Harmonium keys return slowly when released because of mechanical valve pad drag and spring returns.
// We model this by smoothing the gate with asymmetric attack (fast ramp-up) and release (slow ramp-down) times.
key_envelope = gate : envelope_follower(attack_sec, release_sec)
with {
    attack_sec = 0.02; // fast attack (20ms) when pushing key down
    release_sec = 0.20; // slow mechanical release (200ms) when key rises back up
    
    envelope_follower(a, r) = loop ~ _
    with {
        c_att = exp(-1.0 / (a * ma.SR));
        c_rel = exp(-1.0 / (r * ma.SR));
        loop(feed, in) = in * (1.0 - c) + feed * c
        with {
            c = ba.if(in > feed, c_att, c_rel);
        };
    };
};

valve_aperture = key_envelope * velocity;
active_drainage = valve_aperture * 0.08;

// Leaky integrator reservoir model (accumulates pump inflow, leaks naturally, and drains quickly when playing keys)
reservoir_pressure = target_inflow : + ~ (*(0.9997 - active_drainage) : max(0.0) : min(1.0));

// Air reaching the reed depends on key aperture (velocity) and current windchest pressure
effective_pressure = reservoir_pressure * valve_aperture;

// --- Free Reed Excitation Engine ---
// Modulate reed frequencies with slight pressure-induced GROWL instability
pressure_freq_detune = (effective_pressure * bellows_growl * 0.012) * (os.osc(6.5) * 0.3 + 0.7);
detuned_freq = freq * (1.0 + pressure_freq_detune);

// Free reeds generate rich odd and even harmonics due to asymmetric airflow.
// We model this using a bandlimited pulse train waveshaped with tanh.
reed_osc(f, pres) = os.pulsetrain(f, duty_width) * (1.5 + pres * 3.5) : ma.tanh
with {
    duty_width = 0.35 + pres * 0.15; // Duty width widens under pressure
};

// Stops (Octave Coupling):
// - Male (f): Fundamental reed stop
// - Female (2*f): Octave above
// - Bass (0.5*f): Octave below
male_reed   = reed_osc(detuned_freq, effective_pressure);
female_reed = reed_osc(detuned_freq * 2.0, effective_pressure * 0.6) * (reed_octaves : min(1.0));
bass_reed   = reed_osc(detuned_freq * 0.5, effective_pressure * 0.8) * (reed_octaves - 1.0 : max(0.0));

raw_reeds_mix = (male_reed * 0.6 + female_reed * 0.45 + bass_reed * 0.5) * effective_pressure;

// --- Wooden Body Box Resonator Filter ---
// Simulates the acoustic coloring of the bellows box, wood casing, and key frame.
wooden_box_filter(x) =
    (  (x * 0.18)                               // Dry sound leak through slats
     + (x : fi.resonbp(135.0,  3.0, 0.40))      // Box air Helmholtz resonance
     + (x : fi.resonbp(340.0,  4.0, 0.55))      // Keybed wood resonance
     + (x : fi.resonbp(680.0,  3.5, 0.50))      // Outer wooden case mode
     + (x : fi.resonbp(1250.0, 2.5, 0.35))      // Key grid resonance
    );

process = raw_reeds_mix : wooden_box_filter : * (gain * 1.5) : ma.tanh;
