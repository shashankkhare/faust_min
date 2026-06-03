declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";
declare name "tibetanBowl";
declare description "Banded Waveguide Tibetan Bowl";
declare author "Shashank Khare";
declare licence "MIT";
declare version "1.0";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Advanced banded waveguide model of a Tibetan singing bowl supporting both mallet strikes and continuous stick bowing.
//
// Parameters (Controls):
//   - freq
//   - gain
//   - velocity
//   - gate
//   - strike
//   - h:Physical_and_Nonlinearity/v:Physical_Parameters/Integration_Constant [2][tooltip:A value between 0 and 1]
//   - h:Physical_and_Nonlinearity/v:Physical_Parameters/Base_Gain [2][tooltip:A value between 0 and 1]
//   - h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Modulation_Type [3][tooltip:0=theta modulated by signal; 1=averaged signal; 2=squared signal; 3=sine freqMod; 4=sine freq]
//   - h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Nonlinearity [3][tooltip:Nonlinearity factor (0 to 1)]
//   - h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Modulation_Frequency [3][unit:Hz][tooltip:Sine modulation frequency (works if Modulation Type=3)]
// =============================================================================
import("instruments.lib");

freq = nentry("freq",440,20,20000,1);
gain = nentry("gain",0.8,0,1,0.01);
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = hslider("gate", 0, 0, 1, 1);

strikeVal = hslider("strike", 1, 0, 1, 1);
integrationConstant = hslider("h:Physical_and_Nonlinearity/v:Physical_Parameters/Integration_Constant
[2][tooltip:A value between 0 and 1]",0,0,1,0.01);
baseGain = hslider("h:Physical_and_Nonlinearity/v:Physical_Parameters/Base_Gain
[2][tooltip:A value between 0 and 1]",1,0,1,0.01);

typeModulation = nentry("h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Modulation_Type
[3][tooltip:0=theta modulated by signal; 1=averaged signal; 2=squared signal; 3=sine freqMod; 4=sine freq]",0,0,4,1);
nonLinearity = hslider("h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Nonlinearity
[3][tooltip:Nonlinearity factor (0 to 1)]",0,0,1,0.01);
frequencyMod = hslider("h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Modulation_Frequency
[3][unit:Hz][tooltip:Sine modulation frequency (works if Modulation Type=3)]",220,20,1000,0.1);

nlfOrder = 6;
NLFM = nonLinearModulator((nonLinearity : si.smoo),1,freq,
    typeModulation,(frequencyMod : si.smoo),nlfOrder);

nModes = 12;
my_modes(x) = ba.take(x+1, (1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0));
my_excitation(x) = ba.take(x+1, (1.0, 0.8, 0.6, 0.6, 0.8, 0.8, 1.0, 1.0, 0.4, 0.4, 0.8, 0.8));

tableOffset = 0;
tableSlope = 10 - (9*velocity);

delayLengthBase = ma.SR/freq;
delayLength(x) = delayLengthBase/my_modes(x);
delayLine(x) = de.delay(4096,delayLength(x));

radius = 1 - ma.PI*32/ma.SR;
bandPassFilter(x) = bandPass(freq*my_modes(x),radius);

baseGainApp = 0.8999999999999999 + (0.1*baseGain);
velocityInputApp = integrationConstant;
velocityInput = velocityInputApp + _*baseGainApp,par(i,(nModes-1),(_*baseGainApp)) :> _;

maxVelocity = 0.03 + 0.2 * velocity;
bowVelocity = maxVelocity*en.adsr(0.5,0.005,1,0.5,gate);

stereo = stereoizer(delayLengthBase);

bowing = (bowVelocity - velocityInput <: *(bow(tableOffset,tableSlope)) : /(nModes)) * (gate : si.smoo);

trig = gate > gate';

mallet_env = loop_mallet ~ _ with {
    g = exp(-1.0 / (0.015 * ma.SR));
    loop_mallet(s) = ba.if(trig, velocity, s * g);
};

globalDamping = 0.9995;
resonance(x) = + : + (mallet_env * strikeVal * my_excitation(x)) : delayLine(x) : *(globalDamping) : bandPassFilter(x);

process =
    (bowing*((strikeVal-1)*-1) <:
    par(i,nModes,(resonance(i)~_)))~par(i,nModes,_) :> _ :
    NLFM : stereo : instrReverb : *(gain * 2.5), *(gain * 2.5);
