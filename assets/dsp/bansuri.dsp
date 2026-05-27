import("stdfaust.lib");

// Bansuri physical model with dynamic meend glide
fTarget = hslider("freq", 440, 50, 2000, 0.1);
velocity = hslider("velocity", 0.8, 0.0, 1.0, 0.01);
t = button("gate");

// Mapped parameters via inverse distance weighting from companion CSV lookup table
pressureTarget = hslider("pressure", 0.8, 0.0, 1.0, 0.001) : si.smoo;
mouthPosition  = hslider("mouthPosition", 0.5, 0.0, 1.0, 0.001) : si.smoo;

// Glide time in seconds (default 80ms for natural meend transitions)
glide = hslider("glide", 0.08, 0.0, 1.0, 0.001);

// Smooth target frequency to generate continuous pitch slides
fSmoothed = fTarget : si.smooth(ba.tau2pole(glide));

// Vibrato LFO: humanized pitch modulation (default 5.5Hz rate, max 2% frequency deviation)
vibrato = hslider("vibrato", 0.3, 0.0, 1.0, 0.01) : si.smoo;
vibratoRate = 5.5;
vibratoDepth = vibrato * 0.02;
vibratoLFO = os.osc(vibratoRate) * vibratoDepth * fSmoothed;
actualFreq = fSmoothed + vibratoLFO;

// Attack time mapped from velocity (high velocity = 5ms fast attack, low velocity = up to 105ms slow attack)
attackTime = 0.005 + (1.0 - velocity) * 0.1;

// Apply calibrated target pressure directly via trigger gate with dynamic tonguing attack
pressure = t * pressureTarget : min(1.0) : si.smooth(ba.tau2pole(attackTime));

// Fast 30ms release envelope to cleanly silence the physical model decay
releaseEnv = t : si.smooth(ba.tau2pole(0.030));

process = pm.fluteModel(pm.f2l(actualFreq), mouthPosition, pressure) : *(releaseEnv) : *(0.5);

