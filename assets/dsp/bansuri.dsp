import("stdfaust.lib");

// =======================================================================================
// BANSURI PHYSICAL MODEL (BAMBOO FLUTE)
// =======================================================================================
//
// ACOUSTIC RANGE SUMMARY:
// - Optimal Range: 220.0 Hz (A3) to 1200.0 Hz (D6).
// - Lower Bound (A3 - 220Hz): Deepest natural bass bansuri register. Frequencies below 200Hz 
//   suffer from sluggish feedback buildup (delayed start) due to long waveguide delay lines.
// - Higher Bound (1200Hz+): High-frequency register. Requires boosted excitation pressure
//   (mapped via companion LUT CSV) to sustain stable waveguide oscillations.
//
// PHYSICAL ACOUSTICS:
// - Bamboo Wall Loss: Simulates porous wood viscothermal damping using a lowpass feedback filter 
//   (si.smooth(0.40)) to warm up the tone and eliminate metallic high-frequency buzz.
// - Wood Absorption: Employs reduced reflection coefficients at terminations (Head = 0.91, 
//   Foot = 0.92) to match woody radiation impedance.
// - Embouchure Exciter: Incorporates jet turbulence (noise injection) to model raw breathiness.
//
// CONTROL PARAMETERS:
// - freq: Target pitch in Hz (supports microtonal glides / meend).
// - velocity: Key strike velocity (0.0 to 1.0) mapping to attack transient sharpness.
// - gate: Triggers note on/off with 30ms release envelope.
// - glide: Meend transition time in seconds.
// - vibrato: Humanized pitch modulation amount.
// - breathiness: Embouchure air turbulence intensity.
// =======================================================================================

fTarget = hslider("freq", 440, 50, 2000, 0.1);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

// Output gain (controlled by LUT CSV per amplitude/frequency)
gain = hslider("gain", 1.0, 0.0, 3.0, 0.01);

// Mapped parameters via inverse distance weighting from companion CSV lookup table
pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

// Glide time in seconds (default 80ms for natural meend transitions)
glide = hslider("glide", 0.08, 0.0, 1.0, 0.001);

// Smooth target frequency to generate continuous pitch slides
fSmoothed = fTarget : si.smooth(ba.tau2pole(glide));

// Vibrato LFO: humanized pitch modulation (default 5.5Hz rate, max 2% frequency deviation)
vibrato = hslider("vibrato", 0.3, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.5;
vibratoDepth = vibrato * 0.02;
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * fSmoothed;
actualFreq = fSmoothed + vibratoLFO;

// Attack time mapped from velocity (high velocity = 5ms fast attack, low velocity = up to 105ms slow attack)
attackTime = 0.005 + (1.0 - velocity) * 0.1;

// Apply calibrated target pressure directly via trigger gate with dynamic tonguing attack
pressure = t * pressureTarget : min(1.0) : si.smooth(ba.tau2pole(attackTime));

// Additional breath turbulence (noise) to inject at the embouchure
breathIntensity = hslider("breathiness", 0.2, 0.0, 1.0, 0.01) : si.smoo;

// Filtered jet noise simulating human breath (lowpass-filtered to remove high hiss)
filteredNoise = no.noise : fi.lowpass(2, 1800);

// The air jet turbulence is physically added to the blowing pressure.
// Mapped with 0.06 multiplier so breathiness blends organically.
jetTurbulence = filteredNoise * breathIntensity * 1.0;
noisyPressure = pressure + (jetTurbulence * pressure);

// Fast 30ms release envelope to cleanly silence the physical model decay
releaseEnv = t : si.smooth(ba.tau2pole(0.030));

// Custom Bansuri Model simulating bamboo acoustics (wood/bamboo viscothermal damping)
bansuriModel(tubeLength, mouthPosition, pressure) = pm.endChain(bansuriChain) : fi.dcblocker
with {
    maxTubeLength = pm.maxLength;
    tubeTuning = 0.27; // empirical tuning offset
    tLength = tubeLength + tubeTuning; 
    embouchurePos = 0.27 + (mouthPosition - 0.5) * 0.4; 
    tted = tLength * embouchurePos; 
    eted = tLength * (1.0 - embouchurePos); 
    
    // Viscothermal wall losses in bamboo (gentle lowpass damping)
    bambooWallLoss = si.smooth(0.40);
    
    // Calibrated bamboo boundary reflection coefficients
    bansuriHead = pm.lTermination(*(0.98), pm.basicBlock);
    bansuriFoot = pm.rTermination(pm.basicBlock, *(0.97) : si.smooth(0.30) : bambooWallLoss);
    
    bansuriChain = pm.chain(
        bansuriHead : 
        pm.openTube(maxTubeLength, tted) : 
        pm.fluteEmbouchure(pressure) : 
        pm.openTube(maxTubeLength, eted) : 
        bansuriFoot : 
        pm.out
    );
};

// The turbulent pressure excites the waveguide model directly
flute = bansuriModel(pm.f2l(actualFreq), mouthPosition, noisyPressure);

process = flute : *(releaseEnv) : *(gain * 1.0);
