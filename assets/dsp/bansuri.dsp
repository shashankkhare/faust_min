declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

fTarget = hslider("freq", 440, 50, 2000, 0.1);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

gain = hslider("gain", 1.0, 0.0, 3.0, 0.01) : si.smoo;

pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

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

// Breath burst added post-waveguide (waveguide cannot produce audible attack at note start)
bansuriModel(tubeLength, mouthPosition, pressure) = pm.endChain(bansuriChain) : fi.dcblocker
with {
    maxTubeLength = pm.maxLength;
    tubeTuning = 0.27;
    tLength = tubeLength + tubeTuning; 
    embouchurePos = 0.27 + (mouthPosition - 0.5) * 0.4; 
    tted = tLength * embouchurePos; 
    eted = tLength * (1.0 - embouchurePos); 
    
    bambooWallLoss = si.smooth(0.40);
    
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

flute = bansuriModel(pm.f2l(actualFreq), mouthPosition, noisyPressure);
process = (flute + no.pink_noise * gateBurst * 0.2) : *(gain * 1.0);
