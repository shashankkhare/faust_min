declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Fully calibrated, stable Classical Indian bamboo flute (Bansuri).
// =============================================================================
import("stdfaust.lib");

// Expert Play Range: Bansuri typical range A3 (220 Hz) to C6 (1046 Hz).
fTarget = hslider("freq", 440.0, 160, 1046, 0.1);
cal = hslider("calibration", 0.0, -1200.0, 1200.0, 0.01);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

gain = hslider("gain", 1.0, 0.0, 1.0, 0.01) : si.smooth(0.03);
wall_loss = hslider("wallLoss", 0.9, 0.0, 1.0, 0.01) : si.smoo;
// --- CRITICAL FIX 1: Raised default pressure target to jump-start the loop solver ---
pressureTarget = hslider("pressure", 0.88, 0.2, 1.5, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

vibratoDepth = hslider("vibrato_depth", 0.2, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.0; 
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * 0.015 * fTarget;
actualFreq = fTarget + vibratoLFO;

attackTime = 0.005 + (1.0 - velocity) * 0.1;
pressure = t * pressureTarget : min(1.5) : si.smooth(ba.tau2pole(attackTime));

breathIntensity = hslider("breathiness", 0.3, 0.0, 1.0, 0.01) : si.smoo;

burstRelease = 0.12;
poleRel = ba.tau2pole(burstRelease);
burstScale = 0.5 / (1.0 - poleRel);
tDel = t : mem;
risingEdge = t - tDel : >(0);
gateBurst = risingEdge * burstScale : si.smooth(poleRel);

actualBreath = breathIntensity + gateBurst;

// Path A: Stable turbulence injector into the tube
jetTurbulence = no.pink_noise * actualBreath * 0.05; 
noisyPressure = pressure + (jetTurbulence * pressure);

// Path B: External air bypass — soft wind, not hiss.
// Highpass removes muddy low rumble, lowpass removes harsh top hiss;
// the result is smooth broadband breath blended under the tone.
externalAir = no.pink_noise
              : fi.highpass(2, 250.0)
              : fi.lowpass(2, 3200.0)
              : *(actualBreath * 12.0 * t);

releaseEnv = t : si.smooth(ba.tau2pole(0.04));

bansuriModel(freq, mouthPos, pres) = output
with {
    // 1. BASE TARGET PERIOD (in samples)
    target_period = ma.SR / max(40.0, freq);

    // 2. Half-wave acoustic bore with fixed filter group-delay offset (~2.5 samples)
    bore_del = (target_period * 0.5) - 2.5;

    // 3. JET PRE-DELAY (embouchure position controls jet length)
    jet_del = (target_period * 0.5) * max(0.02, 0.2 + mouthPos * 0.3);

    // Isolate integer and fractional parts for the main bore tracking
    int_bore = int(bore_del);
    frac_bore = bore_del - int_bore;

    // Bamboo wall loss: dark first-order lowpass
    // loss: 0 = bright/open, 1 = dark/woody (more absorption)

    wall_cutoff = 8500.0 - (wall_loss * 6500.0);
    g_wall = 0.990 - (wall_loss * 0.04);

    // Excitation: breath + pink-noise turbulence (bansuri breathy character)
    // Noise is injected THROUGH the bore so the tube colors it (natural breath),
    // peaking at the attack onset where a real bansuri "phhh" lives.
    dynamic_noise_gain = 0.60 + (pow(mouthPos, 2.0) * 0.20) + (gateBurst * 1.2);
    breath_drive = pres;
    noise = no.pink_noise : fi.highpass(2, max(40.0, freq * 0.6));
    noise_injection = noise * breath_drive * dynamic_noise_gain;
    excitation = breath_drive + noise_injection;

    // Physical interaction loop at the labium split point
    flute_loop(bore_reflection) = net_pressure
    with {
        delayed_jet = excitation - bore_reflection : de.delay(16384, int(jet_del));

        // Self-recovering smooth clipper keeps the loop from freezing in a dead zone
        clipped_jet = max(-1.1, min(1.1, delayed_jet));
        jet_wave = clipped_jet - (pow(clipped_jet, 3.0) * 0.3333);

        // Micro-stimulus restarts the engine if it ever breaks down
        recovery_stimulus = excitation * 0.0001;

        net_pressure = jet_wave - bore_reflection + recovery_stimulus;
    };

    // Main acoustic body loop containing precise fractional reflections
    raw_wave = flute_loop ~ (
        de.delay(16384, int_bore)
        : de.fdelay1a(1024, frac_bore)
        : fi.dcblocker
        : fi.lowpass(1, wall_cutoff)
        : *(g_wall)
    );

    output = raw_wave;
};

// Precision calibration engine: negative cal lengthens the period (lower pitch)
calibratedFreq = actualFreq * pow(2.0, cal / 1200.0);
flute = bansuriModel(calibratedFreq, mouthPosition, noisyPressure);

// Final mix matrix
process = (flute + externalAir) 
          : *(releaseEnv) 
          : fi.lowpass(2, 5000.0) 
          : *(gain * 0.1575);

