declare copyright "Copyright (c) 2026 Shashank Khare, MIT License";

// =============================================================================
// === PHYSICAL MODEL DESIGN ===
// Description: Chinese zither (Guzheng) physically modeled with steel-core
//              waveguide strings (pm.guitar), paulownia soundboard resonances,
//              180 Hz Helmholtz body cavity, and 8-voice polyphonic ringing.
//
// Parameters (Controls):
//   - freq
//   - gate
//   - velocity
//   - pluckPosition
//   - strike (0=Tuo/Pi plectrum, 1=Mo/Tiao soft, 2=Gou/Da heavy, 3=Fan Yin harmonics)
//   - vibrato_rate
//   - vibrato_depth
//   - gain
//   - calibration
// =============================================================================
import("stdfaust.lib");
pm = library("physmodels.lib");

// --- GLOBAL CONTROLS ---
freq          = hslider("freq [unit:Hz]", 261.63, 65, 1046, 0.01);
velocity      = hslider("velocity", 0.8, 0, 1, 0.01);
gate          = button("gate");
// Authentic Guzheng pluck position is near the front bridge (0.88 - 0.94; 1.0 is bridge)
pluckPosition = hslider("pluckPosition", 0.91, 0.01, 0.99, 0.01) : si.smoo;
gain          = hslider("gain", 1.0, 0, 1, 0.01);

// Strike Articulations:
// 0 = Tuo / Pi (托/劈 - Standard Crisp Plectrum Snap)
// 1 = Mo / Tiao (抹/挑 - Soft Glancing Fingertip Pluck)
// 2 = Gou / Da (勾/打 - Heavy Deep Accented Pluck)
// 3 = Fan Yin (泛音 - Harmonics / Flageolet Chime)
strike        = hslider("strike", 0.0, 0.0, 3.0, 1.0);

isStandard    = (strike == 0.0);
isSoft        = (strike == 1.0);
isHeavy       = (strike == 2.0);
isHarmonic    = (strike == 3.0);

// Expressive left-hand pressing vibrato / chanyin (颤音)
// High depth by default (4-5% pitch modulation) for signature Guzheng character
// Harmonics have lighter vibrato
vibrato_rate  = hslider("vibrato_rate", 5.2, 1.0, 10.0, 0.1) : si.smoo;
vibrato_depth = hslider("vibrato_depth", 0.045, 0.0, 0.12, 0.001) : si.smoo;

// Pitch calibration (cents)
calibration   = hslider("calibration", 0, -100, 100, 0.01);
cfreq         = freq * (2.0 ^ (calibration / 1200.0));

// Quick onset vibrato (blooms ~80ms after pluck as left hand presses behind bridge)
vibDepthEff   = ba.if(isHarmonic, vibrato_depth * 0.35, vibrato_depth);
vibEnv        = gate : si.smooth(ba.tau2pole(0.08));
vibratoLFO    = os.osc(vibrato_rate) * vibDepthEff * vibEnv * cfreq;
playFreq      = max(20.0, cfreq + vibratoLFO);

// Dynamic physical articulation adjustments:
effectiveFreq = ba.if(isHarmonic, playFreq * 2.0, playFreq);
effectivePos  = ba.if(isSoft, 0.82, ba.if(isHeavy, 0.88, ba.if(isHarmonic, 0.50, pluckPosition)));
hpCutoff      = ba.if(isSoft, 120.0, ba.if(isHeavy, 160.0, ba.if(isHarmonic, 600.0, 220.0)));
lpCutoff      = ba.if(isSoft, 3800.0, ba.if(isHeavy, 7500.0, ba.if(isHarmonic, 12000.0, 8500.0)));
sharpness     = ba.if(isSoft, 0.28, ba.if(isHeavy, 0.60, ba.if(isHarmonic, 0.35, 0.45)));
velScale      = ba.if(isSoft, 0.11, ba.if(isHeavy, 0.18, ba.if(isHarmonic, 0.12, 0.14)));

// --- PAULOWNIA SOUNDBOARD & BODY RESONANCE ---
guzhengBody = _ <: (airResonance, bodyCavity, woodPlates) :> fi.dcblocker
with {
    // Dynamic air resonance tracking note fundamental
    airFreq = freq;
    airQ = 8.0;
    airGain = 0.5;
    airResonance = fi.resonbp(airFreq, airQ, airGain);

    // Fixed 180 Hz Helmholtz air cavity mode (1.6m hollow body sound holes)
    bodyCavity = fi.resonbp(180.0, 5.0, 0.35);

    // Paulownia arched soundboard modes
    woodPlates = _ <: (mode1, mode2, mode3) :> /(3.0)
    with {
        f1 = min(18000.0, freq * 2.0);
        f2 = min(18000.0, freq * 3.0);
        mode1 = fi.resonbp(f1, 10.0, 0.8);
        mode2 = fi.resonbp(f2, 8.0, 0.6);
        mode3 = fi.resonbp(580.0, 6.0, 0.5); // Fixed soundboard formant
    };
};

// --- ROUTING ENGINE ---
stringLength = effectiveFreq : pm.f2l;

// Plectrum strike trigger (yijia nail click + string displacement)
strikeTrigger = pm.strikeModel(hpCutoff, lpCutoff, sharpness, 1.0, gate);

// All Guzheng strings modeled with steel-core waveguide (pm.guitar)
// Bright acoustic zither presence with bridge high-end shimmer
stringModel = pm.guitar(stringLength, effectivePos, velocity * velScale, strikeTrigger)
            : fi.highshelf(1, 2.8, 2800.0);

process = stringModel
        : guzhengBody
        : *(gain * 360.0) : ma.tanh;
