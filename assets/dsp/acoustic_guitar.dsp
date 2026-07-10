declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

import("stdfaust.lib");
pm = library("physmodels.lib");

// --- GLOBAL CONTROLS ---
freq          = hslider("freq", 196.0, 40, 1046, 0.01); 
velocity      = hslider("velocity", 0.5, 0, 1, 0.01);
gate          = button("gate");
pluckPosition = hslider("pluckPosition", 0.8, 0.01, 0.99, 0.01) : si.smoo;
gain          = hslider("gain", 1.0, 0, 1, 0.01) : si.smoo;

// String Selection: 0 = Steel String, 1 = Nylon String, 2 = Heavy Bass String
stringType    = hslider("stringType [style:knob]", 0, 0, 2, 1) : int;

// --- ACOUSTIC CHAMBER / CABINET ACCENTS ---
guitarBody(sel) = _ <: (airResonance, woodPlates) :> fi.dcblocker
with {
    airFreq = select2(sel > 0, 100.0, select2(sel > 1, 85.0, 52.0));   
    airQ    = select2(sel > 0, 25.0, select2(sel > 1, 12.0, 38.0));    
    airGain = select2(sel > 0, 0.4, select2(sel > 1, 0.8, 1.4));       
    airResonance = fi.resonbp(airFreq, airQ, airGain);

    woodPlates = _ <: (mode1, mode2, mode3) :> /(3.0)
    with {
        f1 = select2(sel > 0, 190.0, select2(sel > 1, 160.0, 105.0));
        f2 = select2(sel > 0, 220.0, select2(sel > 1, 195.0, 138.0));
        f3 = select2(sel > 0, 410.0, select2(sel > 1, 320.0, 210.0));
        mode1 = fi.resonbp(f1, 15.0, 0.5); 
        mode2 = fi.resonbp(f2, 18.0, 0.4); 
        mode3 = fi.resonbp(f3, 12.0, 0.3); 
    };
};

// --- ROUTING ENGINE ---
stringLength  = freq : pm.f2l;
strikeTrigger = gate : ba.impulsify; 

// CRITICAL FIX: Explicitly alter the frequency profile of each model stream
steelModel = pm.guitar(stringLength, pluckPosition, velocity, strikeTrigger) 
             : fi.highshelf(1, 3.0, 3000.0); // Boost metallic "ping" attack

nylonModel = pm.nylonGuitar(stringLength, pluckPosition, velocity, strikeTrigger) 
             : fi.lowpass(1, 2200.0); // Strip away bright frequencies for warm nylon thud

bassModel  = pm.guitar(stringLength, pluckPosition, velocity, strikeTrigger) 
             : fi.lowpass(2, 750.0); // Extreme high cut for sub-focused thick copper wrap

// Using the verified, corrected logical routing statement
stringSelector = select2(stringType == 0, select2(stringType == 1, bassModel, nylonModel), steelModel);

process = stringSelector
        : guitarBody(stringType)
        : ma.tanh 
        : *(gain * 10000.0);

