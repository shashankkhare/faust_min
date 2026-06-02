declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
import("stdfaust.lib");

mypm = library("physmodels.lib") with { maxLength = 20; };

freq = hslider("freq", 130.81, 40, 1000, 0.1) : si.smoo;
velocity = hslider("velocity", 0.5, 0, 1, 0.01);
gate = button("gate");
gain = hslider("gain", 0.5, 0, 1, 0.01) : si.smoo;

bowPressureTarget = hslider("bowPressure", 0.4, 0.0, 1.0, 0.001) : si.smoo;
bowVelocityTarget = hslider("bowVelocity", 0.1, 0.0, 1.0, 0.001) : si.smoo;
bowPosition = hslider("bowPosition", 0.15, 0.0, 1.0, 0.001) : si.smoo;

vibratoRate = hslider("vibrato_rate", 5.0, 3.0, 8.0, 0.1) : si.smoo;
vibratoDepth = hslider("vibrato_depth", 0.008, 0.0, 0.03, 0.001) : si.smoo;

bowVelocity = gate * bowVelocityTarget : si.smooth(0.999);
bowPressure = gate * bowPressureTarget : si.smooth(0.999);
releaseEnv = gate : si.smooth(ba.tau2pole(0.030));

// Deep woody body resonance filter tuned for cello
celloBody = reflectance, transmittance, _
with {
    transmittance = fi.resonbp(150, 1.5, 1.0);
    reflectance = _;
};

celloModel(stringLength, bowPressure, bowVelocity, bowPosition) = mypm.endChain(modelChain)
with {
    stringTuning = 0.08;
    stringL = max(0.01, stringLength - stringTuning);
    modelChain = mypm.chain(
        mypm.violinNuts :
        mypm.violinBowedString(stringL, bowPressure, bowVelocity, bowPosition) :
        mypm.violinBridge :
        celloBody :
        mypm.out
    );
};

// Humanized delayed vibrato
drift = no.lfnoise(1.5) * 0.001 * freq;
vibEnv = gate : si.smooth(ba.tau2pole(0.3));
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * vibEnv * freq;
humanizedFreq = freq + drift + vibratoLFO;

stringLength = humanizedFreq : mypm.f2l;

process = celloModel(stringLength, bowPressure, bowVelocity, bowPosition)
          : *(releaseEnv)
          : fi.dcblocker
          : ma.tanh * gain;
