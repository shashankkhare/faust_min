declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Fully calibrated, stable Classical Indian bamboo flute (Bansuri).
// =============================================================================
import("stdfaust.lib");

// Expert Play Range: Bansuri typical range A3 (220 Hz) to C6 (1046 Hz).
fTarget = hslider("freq", 440.0, 220, 1046, 0.1);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

gain = hslider("gain", 1.0, 0.0, 3.0, 0.01) : si.smoo;

// --- CRITICAL FIX 1: Raised default pressure target to jump-start the loop solver ---
pressureTarget = hslider("pressure", 0.88, 0.2, 1.5, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

glide = hslider("glide", 0.08, 0.0, 1.0, 0.001);
fSmoothed = fTarget : si.smooth(ba.tau2pole(glide));

vibrato = hslider("vibrato", 0.2, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.0; 
vibratoDepth = vibrato * 0.015;
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * fSmoothed;
actualFreq = fSmoothed + vibratoLFO;

attackTime = 0.005 + (1.0 - velocity) * 0.1;
pressure = t * pressureTarget : min(1.5) : si.smooth(ba.tau2pole(attackTime));

breathIntensity = hslider("breathiness", 0.35, 0.0, 1.0, 0.01) : si.smoo;

burstRelease = 0.06;
poleRel = ba.tau2pole(burstRelease);
burstScale = 0.5 / (1.0 - poleRel);
tDel = t : mem;
risingEdge = t - tDel : >(0);
gateBurst = risingEdge * burstScale : si.smooth(poleRel);

actualBreath = breathIntensity + gateBurst;

// Path A: Stable turbulence injector into the tube
jetTurbulence = no.pink_noise * actualBreath * 0.05; 
noisyPressure = pressure + (jetTurbulence * pressure);

// Path B: External air bypass for clearly audible breathiness
externalAir = no.pink_noise * actualBreath * 0.25 * t;

releaseEnv = t : si.smooth(ba.tau2pole(0.04));

bansuriModel(tubeLength, mouthPos, pres) = pm.endChain(bansuriChain) : fi.dcblocker
with {
    maxTubeLength = pm.maxLength;
    // --- CRITICAL FIX 2: Corrected the length scale for proper low-frequency tracking ---
    tubeTuning = 0.05; 
    tLength = tubeLength + tubeTuning; 
    embouchurePos = 0.2 + mouthPos * 0.1; // Narrowed boundary window to maintain stability
    tted = tLength * embouchurePos; 
    eted = tLength * (1.0 - embouchurePos); 
    
    // Smooth first-order lowpass modeling the non-reflective fiber structure
    bambooWallLoss = fi.lowpass(1, 4500.0);
    
    gateAbsorb = t : si.smooth(ba.tau2pole(0.02));
    bansuriHead = pm.lTermination(*((gateAbsorb * 0.99)), pm.basicBlock);
    bansuriFoot = pm.rTermination(pm.basicBlock, *((gateAbsorb * 0.97)) : bambooWallLoss);
    
    bansuriChain = pm.chain(
        bansuriHead : 
        pm.openTube(maxTubeLength, tted) : 
        pm.fluteEmbouchure(pres) : 
        pm.openTube(maxTubeLength, eted) : 
        bansuriFoot : 
        pm.out
    );
};

// Map length from our corrected actualFreq tracking variable
flute = bansuriModel(pm.f2l(actualFreq), mouthPosition, noisyPressure);

// Final mix matrix
process = (flute + externalAir) 
          : *(releaseEnv) 
          : fi.lowpass(2, 5000.0) 
          : *(gain * 1.44);

