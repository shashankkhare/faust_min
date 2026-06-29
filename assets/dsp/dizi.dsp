declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Chinese transverse bamboo flute (Dizi) with dimo membrane buzz.
// Core waveguide modeled along bansuri lines (embouchure, jet turbulence, tube).
// The dimo membrane adds a nasal, bright buzzing timbre via asymmetric nonlinear
// waveshaping + bandpass filtering mixed back into the clean output.
//
// Parameters (Controls):
//   - freq
//   - velocity
//   - gate
//   - gain
//   - pressure
//   - mouthPosition
//   - glide
//   - vibrato
//   - breathiness
//   - buzzIntensity  (0-1, blend of dimo buzz vs clean tone)
// =============================================================================
import("stdfaust.lib");

// Dizi range: D4 (293.66 Hz) to Bb6 (1864.66 Hz)
fTarget = hslider("freq", 440.0, 293, 1865, 0.1);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

gain = hslider("gain", 1.0, 0.0, 3.0, 0.01) : si.smoo;

pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;
buzzIntensity  = hslider("buzzIntensity", 0.4, 0.0, 1.0, 0.001) : si.smoo;

glide = hslider("glide", 0.08, 0.0, 1.0, 0.001);

fSmoothed = fTarget : si.smooth(ba.tau2pole(glide));

vibrato = hslider("vibrato", 0.3, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.5;
vibratoDepth = vibrato * 0.02;
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * fSmoothed;
actualFreq = fSmoothed + vibratoLFO;

attackTime = 0.005 + (1.0 - velocity) * 0.1;

pressure = t * pressureTarget : min(1.0) : si.smooth(ba.tau2pole(attackTime));

breathIntensity = hslider("breathiness", 0.2, 0.0, 1.0, 0.01) : si.smoo;

// Breath attack: decaying noise burst
burstRelease = 0.08;
poleRel = ba.tau2pole(burstRelease);
burstScale = 0.5 / (1.0 - poleRel);
tDel = t : mem;
risingEdge = t - tDel : >(0);
gateBurst = risingEdge * burstScale : si.smooth(poleRel);

filteredNoise = no.noise;

actualBreath = breathIntensity + gateBurst;
jetTurbulence = filteredNoise * actualBreath * 1.0;
noisyPressure = pressure + (jetTurbulence * pressure);

releaseEnv = t : si.smooth(ba.tau2pole(0.030));

// =============================================================================
// Core Dizi waveguide (same structure as bansuri — transverse flute)
// =============================================================================
diziModel(tubeLength, mouthPosition, pressure) = pm.endChain(diziChain) : fi.dcblocker
with {
    maxTubeLength = pm.maxLength;
    tubeTuning = 0.27;
    tLength = tubeLength + tubeTuning;
    embouchurePos = 0.27 + (mouthPosition - 0.5) * 0.4;
    tted = tLength * embouchurePos;
    eted = tLength * (1.0 - embouchurePos);

    bambooWallLoss = si.smooth(0.40);

    diziHead = pm.lTermination(*(0.98), pm.basicBlock);
    diziFoot = pm.rTermination(pm.basicBlock, *(0.97) : si.smooth(0.30) : bambooWallLoss);

    diziChain = pm.chain(
        diziHead :
        pm.openTube(maxTubeLength, tted) :
        pm.fluteEmbouchure(pressure) :
        pm.openTube(maxTubeLength, eted) :
        diziFoot :
        pm.out
    );
};

// =============================================================================
// Dimo Membrane Buzz Model
// =============================================================================
//
// The dimo is a thin paper membrane glued over a hole between the embouchure
// and the finger holes. It vibrates asymmetrically with the tube's pressure
// wave, adding a nasal buzzing quality rich in odd/even harmonics.
//
// We model this by:
//   1. Tapping the pressure wave at the embouchure point
//   2. Applying an asymmetric polynomial waveshaper
//   3. Bandpass filtering centered on the dimo resonance (~2.2 kHz)
//   4. Mixing the buzz back with the clean tube output
//
dimoResonance = 2200.0; // Hz — typical dimo resonant peak
dimoQ = 4.0;            // resonance Q factor

// Asymmetric waveshaper — models the membrane flapping against the hole rim
// The asymmetry (bias + different gains for positive vs negative) creates
// the characteristic nasal buzz rich in both even and odd harmonics.
waveshaper(x) = (x * (1.0 + buzzIntensity * 1.5)) +
                (x * abs(x) * buzzIntensity * 2.0) +
                (x * x * x * buzzIntensity * 3.0);

// Extract the pressure signal from the waveguide (post-embouchure, pre-output)
// We drive the dimo model from the main audio signal
dimoDrive = _ : fi.dcblocker;

// Bandpass filter at dimo resonance
dimoBP = fi.bandpass(dimoResonance, dimoQ, 1.0);

// Complete dimo processing chain
dimoProcessor = dimoDrive : waveshaper : dimoBP : *(2.0);

// =============================================================================
// Main signal path
// =============================================================================
flute = diziModel(pm.f2l(actualFreq), mouthPosition, noisyPressure);

// Split: clean tube output + dimo buzzed signal
cleanSignal = flute;
buzzSignal = flute : dimoProcessor;

// Crossfade based on buzzIntensity
buzzMix = buzzIntensity;
output = (cleanSignal * (1.0 - buzzMix)) + (buzzSignal * buzzMix);

// Add breath burst
process = (output + no.pink_noise * gateBurst * 0.2) : *(gain * 1.0);
