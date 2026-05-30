declare name "tibetanBowl";
declare description "Banded Waveguide Modeld Tibetan Bowl";
declare author "Romain Michon";
declare copyright "Romain Michon (rmichon@ccrma.stanford.edu)";
declare version "1.0";
declare licence "STK-4.3"; // Synthesis Tool Kit 4.3 (MIT style license);
declare description "This instrument uses banded waveguide. For more information, see Essl, G. and Cook, P. Banded Waveguides: Towards Physical Modelling of Bar Percussion Instruments, Proceedings of the 1999 International Computer Music Conference.";

import("instruments.lib");

//==================== GUI SPECIFICATION ================

freq = nentry("freq",440,20,20000,1);
gain = nentry("gain",0.8,0,1,0.01); 
velocity = hslider("velocity", 0.8, 0, 1, 0.01);
gate = hslider("gate", 0, 0, 1, 1);

strikeVal = hslider("strike", 1, 0, 1, 1);
integrationConstant = hslider("h:Physical_and_Nonlinearity/v:Physical_Parameters/Integration_Constant
[2][tooltip:A value between 0 and 1]",0,0,1,0.01);
baseGain = hslider("h:Physical_and_Nonlinearity/v:Physical_Parameters/Base_Gain
[2][tooltip:A value between 0 and 1]",1,0,1,0.01);
bowPressure = hslider("h:Physical_and_Nonlinearity/v:Physical_Parameters/Bow_Pressure
[2][tooltip:Bow pressure on the instrument (Value between 0 and 1)]",0.2,0,1,0.01);
bowPosition = hslider("h:Physical_and_Nonlinearity/v:Physical_Parameters/Bow_Position
[2][tooltip:Bow position on the instrument (Value between 0 and 1)]",0,0,1,0.01);

typeModulation = nentry("h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Modulation_Type 
[3][tooltip: 0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal;
2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
4=theta is modulated by a sine wave of frequency freq;]",0,0,4,1);
nonLinearity = hslider("h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Nonlinearity 
[3][tooltip:Nonlinearity factor (value between 0 and 1)]",0,0,1,0.01);
frequencyMod = hslider("h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Modulation_Frequency 
[3][unit:Hz][tooltip:Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)]",220,20,1000,0.1);
nonLinAttack = hslider("h:Physical_and_Nonlinearity/v:Nonlinear_Filter_Parameters/Nonlinearity_Attack
[3][unit:s][Attack duration of the nonlinearity]",0.1,0,2,0.01);



//==================== SIGNAL PROCESSING ================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6; 

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib 
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),1,freq,
typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

// --- Custom Golden Ratio + Octave Physics Engine ---
nModes = 11;
my_modes(x) = ba.take(x+1, (1.0, 0.625, 0.390625, 1.61, 2.5921, 4.173281, 7.0, 15.4, 2.0, 4.0, 8.0));
// Additive synthesis amplitudes don't work for physical models because high-frequency delay lines instantly absorb energy.
// We must aggressively overdrive the high-frequency excitations to get a "metallic hit" ping.
my_excitation(x) = ba.take(x+1, (1.0, 0.5, 0.5, 2.0, 2.0, 2.0, 3.0, 4.0, 0.5, 0.5, 0.5));

//bow table parameters
tableOffset = 0;
// Use velocity to dictate bow pressure so it 'bites' the string/bowl and forces a sound!
tableSlope = 10 - (9*velocity);

delayLengthBase = ma.SR/freq;

//delay lengths in number of samples
delayLength(x) = delayLengthBase/my_modes(x);

//delay lines
delayLine(x) = de.delay(4096,delayLength(x));

//Filter bank: bandpass filters (declared in instruments.lib)
radius = 1 - ma.PI*32/ma.SR;
bandPassFilter(x) = bandPass(freq*my_modes(x),radius);

//Delay lines feedback for bow table lookup control
baseGainApp = 0.8999999999999999 + (0.1*baseGain);
velocityInputApp = integrationConstant;
velocityInput = velocityInputApp + _*baseGainApp,par(i,(nModes-1),(_*baseGainApp)) :> _;

//Bow velocity is controlled by an ADSR envelope
maxVelocity = 0.03 + 0.2 * velocity;
bowVelocity = maxVelocity*en.adsr(0.5,0.005,1,0.5,gate);

//stereoizer is declared in instruments.lib and implement a stereo spacialisation in function of 
//the frequency period in number of samples 
stereo = stereoizer(delayLengthBase);

//----------------------- Algorithm implementation ----------------------------

//Bow table lookup (bow is declared in instruments.lib)
bowing = (bowVelocity - velocityInput <: *(bow(tableOffset,tableSlope)) : /(nModes)) * (gate : si.smoo);

// Trigger logic
trig = gate > gate';

// Mallet Excitation: Soft-felt mallet contact burst
mallet_env = loop_mallet ~ _ with {
    g = exp(-1.0 / (0.015 * ma.SR));
    loop_mallet(s) = ba.if(trig, velocity, s * g);
};

//One resonance
// Using globalDamping so modes resonate properly.
// my_excitation governs how hard the mallet hits each mode.
globalDamping = 0.9999; // Increased damping so it rings clearly!
resonance(x) = + : + (mallet_env * strikeVal * my_excitation(x)) : delayLine(x) : *(globalDamping) : bandPassFilter(x);

process =
		//Bowed Excitation (only active when strikeVal == 0)
		(bowing*((strikeVal-1)*-1) <:
		//nModes resonances with nModes feedbacks for bow table look-up 
		par(i,nModes,(resonance(i)~_)))~par(i,nModes,_) :> _ : 
		//Signal Scaling and stereo
		NLFM : stereo : *(gain * 5.0), *(gain * 5.0);

