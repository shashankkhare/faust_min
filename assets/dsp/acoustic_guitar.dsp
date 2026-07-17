declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");
pm = library("physmodels.lib");

// --- GLOBAL CONTROLS ---
freq          = hslider("freq [unit:Hz]", 196.0, 82, 1046, 0.01); 
velocity      = hslider("velocity", 0.5, 0, 1, 0.01);
gate          = button("gate");
pluckPosition = hslider("pluckPosition", 0.8, 0.01, 0.99, 0.01) : si.smoo;
gain          = hslider("gain", 1.0, 0, 1, 0.01);

// String Selection: 0 = Steel String, 1 = Nylon String, 2 = Heavy Bass String
stringType    = hslider("stringType [style:knob]", 0, 0, 2, 1) : int;

// --- ACOUSTIC CHAMBER / CABINET ACCENTS ---
// Body resonances that track the fundamental for harmonic enhancement
guitarBody(sel) = _ <: (airResonance, woodPlates) :> fi.dcblocker
with {
    // Air resonance at fundamental (body air cavity)
    airFreq = freq;
    airQ    = select2(sel > 0, 15.0, select2(sel > 1, 10.0, 20.0));    
    airGain = select2(sel > 0, 1.2, select2(sel > 1, 1.5, 2.0));       
    airResonance = fi.resonbp(airFreq, airQ, airGain);

    // Wood plate modes at harmonic frequencies
    woodPlates = _ <: (mode1, mode2, mode3) :> /(3.0)
    with {
        f1 = freq * 2.0;
        f2 = freq * 3.0;
        f3 = freq * 4.0;
        mode1 = fi.resonbp(f1, 12.0, 1.0); 
        mode2 = fi.resonbp(f2, 10.0, 0.8); 
        mode3 = fi.resonbp(f3, 8.0, 0.6); 
    };
};

// --- ROUTING ENGINE ---
stringLength  = freq : pm.f2l;
strikeTrigger = gate : ba.impulsify;

// pm.pluckString outputs ~0.1 peak; waveguide chain absorbs most of it.
// Boost velocity into the model so the waveguide operates at a healthy level.
excBoost = 2;

steelModel = pm.guitar(stringLength, pluckPosition, velocity * excBoost, strikeTrigger)
             : fi.highshelf(1, 3.0, 3000.0);

nylonModel = pm.nylonGuitar(stringLength, pluckPosition, velocity * excBoost, strikeTrigger)
             : fi.lowpass(1, 2200.0);

bassModel  = pm.guitar(stringLength, pluckPosition, velocity * excBoost, strikeTrigger)
             : fi.lowpass(2, 750.0);

stringSelector = select2(stringType == 0, select2(stringType == 1, bassModel, nylonModel), steelModel);

process = stringSelector
        : guitarBody(stringType)
        : ma.tanh
        : *(gain * 14.125);

