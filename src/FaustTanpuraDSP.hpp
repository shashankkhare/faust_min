/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tanpura"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTanpuraDSP_H__
#define  __FaustTanpuraDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustTanpuraDSPSIG0 {
	
  private:
	
	int iVec5[2];
	int iRec9[2];
	
  public:
	
	int getNumInputsFaustTanpuraDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTanpuraDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTanpuraDSPSIG0(int sample_rate) {
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iVec5[l12] = 0;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			iRec9[l13] = 0;
		}
	}
	
	void fillFaustTanpuraDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec5[0] = 1;
			iRec9[0] = ((iVec5[1] + iRec9[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec9[0])));
			iVec5[1] = iVec5[0];
			iRec9[1] = iRec9[0];
		}
	}

};

static FaustTanpuraDSPSIG0* newFaustTanpuraDSPSIG0() { return (FaustTanpuraDSPSIG0*)new FaustTanpuraDSPSIG0(); }
static void deleteFaustTanpuraDSPSIG0(FaustTanpuraDSPSIG0* dsp) { delete dsp; }

static float FaustTanpuraDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustTanpuraDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTanpuraDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTanpuraDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider1;
	float fConst6;
	FAUSTFLOAT fHslider2;
	float fConst7;
	float fRec3[2];
	float fVec0[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fConst9;
	float fConst10;
	float fConst13;
	int iRec6[2];
	float fConst14;
	float fConst15;
	float fRec5[3];
	float fVec2[2];
	float fRec4[2];
	FAUSTFLOAT fHslider8;
	int iVec3[2];
	int iRec7[2];
	int IOTA;
	float fVec4[8192];
	float fRec2[2048];
	float fConst16;
	float fConst17;
	float fRec8[2];
	float fConst18;
	float fRec10[2];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec1[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec11[3];
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec12[3];
	float fConst38;
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fConst46;
	float fRec13[3];
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fRec14[3];
	float fVec6[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.1");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "tanpura.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("fm.lib/copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tanpura");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("options", "[nvoices:4]");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.1");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		FaustTanpuraDSPSIG0* sig0 = newFaustTanpuraDSPSIG0();
		sig0->instanceInitFaustTanpuraDSPSIG0(sample_rate);
		sig0->fillFaustTanpuraDSPSIG0(65536, ftbl0FaustTanpuraDSPSIG0);
		deleteFaustTanpuraDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((7853.98145f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.285714298f) / fConst1) + 1.0f);
		fConst4 = (0.0500000007f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		fConst6 = (44.0999985f / fConst0);
		fConst7 = (1.0f - fConst6);
		float fConst8 = (1.0f / std::tan((2513.27417f / fConst0)));
		fConst9 = (1.0f / (fConst8 + 1.0f));
		fConst10 = (1.0f - fConst8);
		float fConst11 = std::tan((6283.18555f / fConst0));
		float fConst12 = (1.0f / fConst11);
		fConst13 = (1.0f / (((fConst12 + 1.41421354f) / fConst11) + 1.0f));
		fConst14 = (((fConst12 + -1.41421354f) / fConst11) + 1.0f);
		fConst15 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst11))));
		fConst16 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst17 = (1.0f - fConst16);
		fConst18 = (1.0f / fConst0);
		fConst19 = (1.0f / fConst3);
		fConst20 = (((fConst2 + -0.285714298f) / fConst1) + 1.0f);
		fConst21 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst1))));
		float fConst22 = std::tan((4555.30957f / fConst0));
		float fConst23 = (1.0f / fConst22);
		float fConst24 = (((fConst23 + 0.333333343f) / fConst22) + 1.0f);
		fConst25 = (0.0799999982f / (fConst22 * fConst24));
		fConst26 = (0.0f - fConst25);
		fConst27 = (1.0f / fConst24);
		fConst28 = (((fConst23 + -0.333333343f) / fConst22) + 1.0f);
		fConst29 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst22))));
		float fConst30 = std::tan((2261.94678f / fConst0));
		float fConst31 = (1.0f / fConst30);
		float fConst32 = (((fConst31 + 0.200000003f) / fConst30) + 1.0f);
		float fConst33 = (fConst30 * fConst32);
		fConst34 = (1.0f / fConst33);
		fConst35 = (1.0f / fConst32);
		fConst36 = (((fConst31 + -0.200000003f) / fConst30) + 1.0f);
		fConst37 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst30))));
		fConst38 = (0.0f - (0.150000006f / fConst33));
		float fConst39 = std::tan((785.398193f / fConst0));
		float fConst40 = (1.0f / fConst39);
		float fConst41 = (((fConst40 + 0.333333343f) / fConst39) + 1.0f);
		fConst42 = (0.349999994f / (fConst39 * fConst41));
		fConst43 = (0.0f - fConst42);
		fConst44 = (1.0f / fConst41);
		fConst45 = (((fConst40 + -0.333333343f) / fConst39) + 1.0f);
		fConst46 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst39))));
		float fConst47 = std::tan((329.867218f / fConst0));
		float fConst48 = (1.0f / fConst47);
		float fConst49 = (((fConst48 + 0.333333343f) / fConst47) + 1.0f);
		fConst50 = (0.449999988f / (fConst47 * fConst49));
		fConst51 = (0.0f - fConst50);
		fConst52 = (1.0f / fConst49);
		fConst53 = (((fConst48 + -0.333333343f) / fConst47) + 1.0f);
		fConst54 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst47))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(130.81f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.45000000000000001f);
		fHslider4 = FAUSTFLOAT(24.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(0.029999999999999999f);
		fHslider7 = FAUSTFLOAT(0.80000000000000004f);
		fHslider8 = FAUSTFLOAT(0.12f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec3[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec6[l3] = 0;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iVec3[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec7[l8] = 0;
		}
		IOTA = 0;
		for (int l9 = 0; (l9 < 8192); l9 = (l9 + 1)) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2048); l10 = (l10 + 1)) {
			fRec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec8[l11] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec10[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec1[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec11[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec12[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec13[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec14[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fVec6[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec0[l21] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("calibration", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-100.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("excDur", &fHslider8, FAUSTFLOAT(0.119999997f), FAUSTFLOAT(9.99999975e-05f), FAUSTFLOAT(0.125f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excGain", &fHslider6, FAUSTFLOAT(0.0299999993f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(130.809998f), FAUSTFLOAT(130.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider3, FAUSTFLOAT(0.449999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stringGainVal", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider4, FAUSTFLOAT(24.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(36.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider7, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (45.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fConst6 * float(fHslider2));
		float fSlow3 = float(fHslider3);
		float fSlow4 = ((20.0f * fSlow3) + 1.0f);
		float fSlow5 = (1.0f / fSlow4);
		float fSlow6 = (1.0f / std::max<float>(0.400000006f, (float(fHslider4) * (1.0f - (0.349999994f * fSlow3)))));
		float fSlow7 = float(fButton0);
		float fSlow8 = (((fSlow7 * float(fHslider5)) * float(fHslider6)) * float(fHslider7));
		float fSlow9 = (1.0f / std::max<float>(1.0f, (fConst0 * float(fHslider8))));
		float fSlow10 = (1350.0f * fSlow3);
		float fSlow11 = (fConst18 * fSlow1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow2 + (fConst7 * fRec3[1]));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = std::pow(2.0f, (0.000833333354f * fRec3[0]));
			float fTemp1 = std::max<float>(40.0f, (fSlow1 * fTemp0));
			float fTemp2 = (fConst0 / fTemp1);
			int iTemp3 = int(fTemp2);
			float fTemp4 = float(iTemp3);
			float fTemp5 = (fTemp2 + (4.99999987e-06f - fTemp4));
			int iTemp6 = int(fTemp5);
			float fTemp7 = (fTemp4 + std::floor(fTemp5));
			float fTemp8 = (fTemp2 - fTemp7);
			float fTemp9 = (fTemp2 + (-1.0f - fTemp7));
			float fTemp10 = (fTemp2 + (-2.0f - fTemp7));
			float fTemp11 = ((((fRec2[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp6)) + 1)) & 2047)] * (0.0f - fTemp8)) * (0.0f - (0.5f * fTemp9))) * (0.0f - (0.333333343f * fTemp10))) + ((fTemp2 + (1.0f - fTemp7)) * ((((fRec2[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp6 + 1))) + 1)) & 2047)] * (0.0f - fTemp9)) * (0.0f - (0.5f * fTemp10))) + (0.5f * ((fTemp8 * fRec2[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp6 + 2))) + 1)) & 2047)]) * (0.0f - fTemp10)))) + (0.166666672f * ((fTemp8 * fTemp9) * fRec2[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp6 + 3))) + 1)) & 2047)])))));
			fVec0[0] = fTemp11;
			float fTemp12 = ((0.00200000009f * fTemp11) + (0.998000026f * fVec0[1]));
			float fThen0 = (fSlow5 * float(tanhf(float((fSlow4 * fTemp12)))));
			fVec1[0] = fSlow7;
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fTempFTZ1 = ((4.65661287e-10f * float(iRec6[0])) - (fConst13 * ((fConst14 * fRec5[2]) + (fConst15 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp13 = (fRec5[2] + (fRec5[0] + (2.0f * fRec5[1])));
			fVec2[0] = fTemp13;
			float fTempFTZ2 = (0.0f - (fConst9 * ((fConst10 * fRec4[1]) - (fConst13 * (fTemp13 + fVec2[1])))));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			int iTemp14 = ((fSlow7 - fVec1[1]) > 0.0f);
			iVec3[0] = iTemp14;
			iRec7[0] = ((iTemp14 > iVec3[1]) + ((iTemp14 <= iVec3[1]) * (iRec7[1] + (iRec7[1] > 0))));
			float fTemp15 = (fSlow9 * float(iRec7[0]));
			fVec4[(IOTA & 8191)] = ((((fTemp12 > 0.0f) ? fTemp12 : fThen0) * std::pow(0.00100000005f, (fSlow6 / fTemp1))) + (fSlow8 * (fRec4[0] * std::max<float>(0.0f, std::min<float>(fTemp15, (2.0f - fTemp15))))));
			float fTempFTZ3 = fVec4[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp3 + -1)))) & 8191)];
			fRec2[(IOTA & 2047)] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp16 = std::fabs(fRec2[((IOTA - 0) & 2047)]);
			float fTempFTZ4 = std::max<float>(fTemp16, ((fConst16 * fRec8[1]) + (fConst17 * fTemp16)));
			fRec8[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp17 = (fRec10[1] + (fSlow11 * fTemp0));
			float fTempFTZ5 = (fTemp17 - std::floor(fTemp17));
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp18 = std::max<float>(1.0f, ((fSlow10 * ((fRec8[0] * ftbl0FaustTanpuraDSPSIG0[int((65536.0f * fRec10[0]))]) / fTemp1)) + 4.0f));
			float fTemp19 = (fTemp18 + 4.99999987e-06f);
			int iTemp20 = int(fTemp19);
			float fTemp21 = std::floor(fTemp19);
			float fTemp22 = ((fRec2[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp20))))) & 2047)] * (0.0f - (fTemp18 + (-1.0f - fTemp21)))) + ((fTemp18 - fTemp21) * fRec2[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp20 + 1)))))) & 2047)]));
			float fTempFTZ6 = (fTemp22 - (fConst19 * ((fConst20 * fRec1[2]) + (fConst21 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp23 = (fConst5 * fRec1[2]);
			float fTemp24 = (fConst4 * fRec1[0]);
			float fTempFTZ7 = (fTemp22 - (fConst27 * ((fConst28 * fRec11[2]) + (fConst29 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp25 = (fConst26 * fRec11[2]);
			float fTemp26 = (fConst25 * fRec11[0]);
			float fTempFTZ8 = (fTemp22 - (fConst35 * ((fConst36 * fRec12[2]) + (fConst37 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp27 = (0.150000006f * (fTemp22 + (fConst34 * fRec12[0])));
			float fTemp28 = (fConst38 * fRec12[2]);
			float fTempFTZ9 = (fTemp22 - (fConst44 * ((fConst45 * fRec13[2]) + (fConst46 * fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp29 = (fConst43 * fRec13[2]);
			float fTemp30 = (fConst42 * fRec13[0]);
			float fTempFTZ10 = (fTemp22 - (fConst52 * ((fConst53 * fRec14[2]) + (fConst54 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp31 = (fConst51 * fRec14[2]);
			float fTemp32 = (fConst50 * fRec14[0]);
			fVec6[0] = (fTemp23 + ((fTemp25 + ((fTemp27 + (fTemp28 + (fTemp29 + ((fTemp32 + fTemp31) + fTemp30)))) + fTemp26)) + fTemp24));
			float fTempFTZ11 = ((fTemp23 + (fTemp24 + (fTemp25 + (fTemp26 + (fTemp27 + (fTemp28 + (fTemp29 + (fTemp30 + (fTemp31 + ((0.995000005f * fRec0[1]) + fTemp32)))))))))) - fVec6[1]);
			fRec0[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fRec0[0] / (std::fabs(fRec0[0]) + 1.0f))));
			fRec3[1] = fRec3[0];
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			iRec6[1] = iRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fVec2[1] = fVec2[0];
			fRec4[1] = fRec4[0];
			iVec3[1] = iVec3[0];
			iRec7[1] = iRec7[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fVec6[1] = fVec6[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
