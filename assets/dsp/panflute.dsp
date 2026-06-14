declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");

fTarget = hslider("freq", 440, 50, 2000, 0.1);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");
gain = hslider("gain", 1.0, 0.0, 3.0, 0.01) : si.smoo;

pressureTarget = hslider("pressure", 0.65, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;
breathiness = hslider("breathiness", 0.3, 0.0, 1.0, 0.01) : si.smoo;

glide = hslider("glide", 0.06, 0.0, 1.0, 0.001);
fSmoothed = fTarget : si.smooth(ba.tau2pole(glide));

vibrato = hslider("vibrato", 0.5, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = hslider("vibrato_rate", 5.5, 0.0, 10.0, 0.1);
vibratoDepth = hslider("vibrato_depth", 0.03, 0.0, 0.05, 0.001);
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * fSmoothed;
actualFreq = fSmoothed + vibratoLFO * vibrato;

attackTime = 0.003 + (1.0 - velocity) * 0.015;
pressure = t * pressureTarget : min(1.0) : si.smooth(ba.tau2pole(attackTime));

breathNoise = no.pink_noise * breathiness * pressure * 0.3;

panfluteSound = pm.fluteModel(pm.f2l(actualFreq), mouthPosition, pressure + breathNoise);

releaseEnv = t : si.smooth(ba.tau2pole(0.04));

process = panfluteSound : *(releaseEnv) : *(gain * 2.0);
