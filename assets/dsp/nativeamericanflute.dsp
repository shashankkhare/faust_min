declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

fTarget = hslider("freq", 440, 50, 2000, 0.1);
velocity = hslider("velocity", 0.5, 0.0, 1.0, 0.01);
t = button("gate");
gain = hslider("gain", 1.0, 0.0, 3.0, 0.01) : si.smoo;

pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;
breathiness = hslider("breathiness", 0.2, 0.0, 1.0, 0.01) : si.smoo;

glide = hslider("glide", 0.08, 0.0, 1.0, 0.001);
fSmoothed = fTarget : si.smooth(ba.tau2pole(glide));

vibrato = hslider("vibrato", 0.6, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.5;
vibratoDepth = vibrato * 0.04;
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * fSmoothed;
actualFreq = fSmoothed + vibratoLFO;

attackTime = 0.002 + (1.0 - velocity) * 0.056;
pressure = t * pressureTarget : min(1.0) : si.smooth(ba.tau2pole(attackTime));

// Breath attack: decaying noise burst
burstRelease = 0.08;
poleRel = ba.tau2pole(burstRelease);
burstScale = 0.5 / (1.0 - poleRel);
tDel = t : mem;
risingEdge = t - tDel : >(0);
gateBurst = risingEdge * burstScale : si.smooth(poleRel);

jetTurbulence = no.pink_noise * (breathiness + gateBurst) * 1.0;
directBreath = no.pink_noise * breathiness * 0.06;
noisyPressure = pressure + (jetTurbulence * pressure) + directBreath;

releaseTime = 0.002 + (1.0 - velocity) * 0.056;
releaseEnv = t : si.smooth(ba.tau2pole(releaseTime));

nafModel(tubeLength, mouthPos, pres) = pm.endChain(nafChain) : fi.dcblocker
with {
    maxTubeLength = pm.maxLength;
    tubeTuning = 0.27;
    tLength = tubeLength + tubeTuning;
    sacPos = 0.15 + mouthPos * 0.25;
    sacLen = tLength * sacPos;
    boreLen = tLength * (1.0 - sacPos);

    wallLoss = si.smooth(0.40);

    nafHead = pm.lTermination(*(0.98), pm.basicBlock);
    nafFoot = pm.rTermination(pm.basicBlock, *(0.97) : si.smooth(0.30) : wallLoss);

    nafChain = pm.chain(
        nafHead :
        pm.openTube(maxTubeLength, sacLen) :
        pm.fluteEmbouchure(pres) :
        pm.openTube(maxTubeLength, boreLen) :
        nafFoot :
        pm.out
    );
};

flute = nafModel(pm.f2l(actualFreq), mouthPosition, noisyPressure);
process = (flute + no.pink_noise * gateBurst * 0.2) : *(releaseEnv) : *(gain * 0.14);
