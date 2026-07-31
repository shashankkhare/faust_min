/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "violin"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustViolinDSP_H__
#define  __FaustViolinDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustViolinDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec38[2];
	
  public:
	
	int getNumInputsFaustViolinDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustViolinDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustViolinDSPSIG0(int sample_rate) {
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			iVec1[l16] = 0;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iRec38[l17] = 0;
		}
	}
	
	void fillFaustViolinDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec38[0] = ((iVec1[1] + iRec38[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec38[0])));
			iVec1[1] = iVec1[0];
			iRec38[1] = iRec38[0];
		}
	}

};

static FaustViolinDSPSIG0* newFaustViolinDSPSIG0() { return (FaustViolinDSPSIG0*)new FaustViolinDSPSIG0(); }
static void deleteFaustViolinDSPSIG0(FaustViolinDSPSIG0* dsp) { delete dsp; }

static float FaustViolinDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustViolinDSPSIG0[65536];
static float FaustViolinDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustViolinDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustViolinDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int iRec11[2];
	int iVec0[2];
	int fSampleRate;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider1;
	float fConst8;
	float fRec24[2];
	FAUSTFLOAT fHslider2;
	float fRec25[2];
	float fConst10;
	float fConst11;
	float fConst13;
	float fConst14;
	float fRec32[2];
	float fRec33[2];
	int iRec34[2];
	float fRec31[2];
	float fRec30[2];
	float fRec29[2];
	float fRec28[2];
	float fRec27[2];
	float fRec26[2];
	FAUSTFLOAT fButton0;
	FAUSTFLOAT fHslider3;
	float fConst15;
	float fRec35[2];
	FAUSTFLOAT fHslider4;
	float fRec36[2];
	float fConst16;
	float fConst17;
	float fRec37[2];
	FAUSTFLOAT fHslider5;
	float fRec40[2];
	float fRec39[2];
	float fRec21[2];
	FAUSTFLOAT fHslider6;
	float fRec41[2];
	float fRec42[4];
	int IOTA;
	float fRec43[2048];
	float fVec2[2];
	FAUSTFLOAT fHslider7;
	float fRec44[2];
	float fConst19;
	float fConst20;
	float fConst22;
	float fConst23;
	float fRec51[2];
	float fRec52[2];
	float fRec50[2];
	float fRec49[2];
	float fRec48[2];
	float fRec47[2];
	float fRec46[2];
	float fRec45[2];
	float fVec3[2048];
	float fRec18[2048];
	float fRec20[2];
	float fRec17[4];
	float fConst24;
	float fConst25;
	float fConst26;
	float fRec15[3];
	float fConst27;
	int iRec7[2];
	float fRec3[2048];
	float fRec1[2];
	float fRec2[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "violin.dsp");
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
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "violin");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
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
		FaustViolinDSPSIG0* sig0 = newFaustViolinDSPSIG0();
		sig0->instanceInitFaustViolinDSPSIG0(sample_rate);
		sig0->fillFaustViolinDSPSIG0(65536, ftbl0FaustViolinDSPSIG0);
		deleteFaustViolinDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((1570.79639f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.5f) / fConst1) + 1.0f);
		fConst4 = (1.0f / (fConst1 * fConst3));
		fConst5 = (0.00882352982f * fConst0);
		fConst6 = (0.00147058826f * fConst0);
		fConst7 = (44.0999985f / fConst0);
		fConst8 = (1.0f - fConst7);
		float fConst9 = (1.0f / std::tan((6.28318548f / fConst0)));
		fConst10 = (1.0f / (fConst9 + 1.0f));
		fConst11 = (1.0f - fConst9);
		float fConst12 = (12.566371f / fConst0);
		fConst13 = std::sin(fConst12);
		fConst14 = std::cos(fConst12);
		fConst15 = (1.0f / fConst0);
		fConst16 = std::exp((0.0f - (3.33333325f / fConst0)));
		fConst17 = (1.0f - fConst16);
		float fConst18 = (1.0f / std::tan((37.6991119f / fConst0)));
		fConst19 = (1.0f / (fConst18 + 1.0f));
		fConst20 = (1.0f - fConst18);
		float fConst21 = (75.3982239f / fConst0);
		fConst22 = std::sin(fConst21);
		fConst23 = std::cos(fConst21);
		fConst24 = (1.0f / fConst3);
		fConst25 = (((fConst2 + -0.5f) / fConst1) + 1.0f);
		fConst26 = (2.0f * (1.0f - (1.0f / FaustViolinDSP_faustpower2_f(fConst1))));
		fConst27 = (0.0f - fConst4);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(440.0f);
		fHslider1 = FAUSTFLOAT(0.14999999999999999f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(0.012f);
		fHslider5 = FAUSTFLOAT(5.5f);
		fHslider6 = FAUSTFLOAT(0.5f);
		fHslider7 = FAUSTFLOAT(0.40000000000000002f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec11[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec24[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec25[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec32[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec33[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec34[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec31[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec30[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec29[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec28[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec27[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec26[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec35[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec36[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec37[l15] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec40[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec39[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec21[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec41[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 4); l22 = (l22 + 1)) {
			fRec42[l22] = 0.0f;
		}
		IOTA = 0;
		for (int l23 = 0; (l23 < 2048); l23 = (l23 + 1)) {
			fRec43[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fVec2[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec44[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec51[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec52[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec50[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec49[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec48[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec47[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec46[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec45[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2048); l34 = (l34 + 1)) {
			fVec3[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2048); l35 = (l35 + 1)) {
			fRec18[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec20[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 4); l37 = (l37 + 1)) {
			fRec17[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec15[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			iRec7[l39] = 0;
		}
		for (int l40 = 0; (l40 < 2048); l40 = (l40 + 1)) {
			fRec3[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec1[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec2[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec0[l43] = 0.0f;
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
	
	virtual FaustViolinDSP* clone() {
		return new FaustViolinDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("violin");
		ui_interface->addHorizontalSlider("bowPosition", &fHslider1, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("bowPressure", &fHslider7, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("bowVelocity", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("calibration", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-0.100000001f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(440.0f), FAUSTFLOAT(80.0f), FAUSTFLOAT(1400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider4, FAUSTFLOAT(0.0120000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider5, FAUSTFLOAT(5.5f), FAUSTFLOAT(3.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (1.10000002f * std::max<float>(1.0f, std::min<float>(3.0f, std::sqrt(((4.0f * FaustViolinDSP_faustpower2_f(((0.00200000009f * fSlow0) - (500.0f / fSlow0)))) + 1.0f)))));
		float fSlow2 = (fConst7 * float(fHslider1));
		float fSlow3 = (fConst7 * float(fHslider2));
		float fSlow4 = (340.0f / fSlow0);
		float fSlow5 = float(fButton0);
		float fElse0 = (0.150000006f * float(fHslider3));
		float fSlow6 = (int(fSlow5) ? fElse0 : 0.0299999993f);
		int iSlow7 = (std::fabs(fSlow6) < 1.1920929e-07f);
		float fThen2 = std::exp((0.0f - (fConst15 / (iSlow7 ? 1.0f : fSlow6))));
		float fSlow8 = (iSlow7 ? 0.0f : fThen2);
		float fSlow9 = (fSlow5 * (1.0f - fSlow8));
		float fSlow10 = (fConst7 * float(fHslider4));
		float fSlow11 = (fConst17 * fSlow5);
		float fSlow12 = (fConst7 * float(fHslider5));
		float fSlow13 = (fConst7 * float(fHslider6));
		float fSlow14 = (fConst7 * float(fHslider7));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec11[0] = 0;
			iVec0[0] = 1;
			int iRec12 = iRec11[1];
			float fTempFTZ0 = (float(iRec7[1]) - (0.989264667f * ((0.600000024f * fRec17[2]) + (0.200000003f * (fRec17[1] + fRec17[3])))));
			float fRec16 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow2 + (fConst8 * fRec24[1]));
			fRec24[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (1.0f - fRec24[0]);
			float fTempFTZ2 = (fSlow3 + (fConst8 * fRec25[1]));
			fRec25[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((fConst13 * fRec33[1]) + (fConst14 * fRec32[1]));
			fRec32[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp1 = float((1 - iVec0[1]));
			float fTempFTZ4 = ((fTemp1 + (fConst14 * fRec33[1])) - (fConst13 * fRec32[1]));
			fRec33[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			int iTemp2 = ((fRec32[1] <= 0.0f) & (fRec32[0] > 0.0f));
			iRec34[0] = ((1103515245 * iRec34[1]) + 12345);
			float fTemp3 = float(iRec34[0]);
			float fTempFTZ5 = ((fRec31[1] * float((1 - iTemp2))) + (4.65661287e-10f * (fTemp3 * float(iTemp2))));
			fRec31[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (0.0f - (fConst10 * ((fConst11 * fRec30[1]) - (fRec31[0] + fRec31[1]))));
			fRec30[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.0f - (fConst10 * ((fConst11 * fRec29[1]) - (fRec30[0] + fRec30[1]))));
			fRec29[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (0.0f - (fConst10 * ((fConst11 * fRec28[1]) - (fRec29[0] + fRec29[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (0.0f - (fConst10 * ((fConst11 * fRec27[1]) - (fRec28[0] + fRec28[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (0.0f - (fConst10 * ((fConst11 * fRec26[1]) - (fRec27[0] + fRec27[1]))));
			fRec26[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = ((fRec35[1] * fSlow8) + fSlow9);
			fRec35[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp4 = (0.00150000001f * (fRec26[0] * fRec35[0]));
			float fTempFTZ12 = (fSlow10 + (fConst8 * fRec36[1]));
			fRec36[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fSlow11 + (fConst16 * fRec37[1]));
			fRec37[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fSlow12 + (fConst8 * fRec40[1]));
			fRec40[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp5 = (fRec39[1] + (fConst15 * fRec40[0]));
			float fTempFTZ15 = (fTemp5 - std::floor(fTemp5));
			fRec39[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp6 = ((fRec36[0] * fRec37[0]) * ftbl0FaustViolinDSPSIG0[int((65536.0f * fRec39[0]))]);
			float fTemp7 = ((fRec25[0] + (fSlow4 / ((fTemp4 + fTemp6) + 1.0f))) + -0.0799999982f);
			int iTemp8 = int(((fConst6 * (fTemp0 * fTemp7)) + -1.49999499f));
			float fTemp9 = ((fRec25[0] + (fSlow4 / ((fTemp4 + 1.0f) + fTemp6))) + -0.0799999982f);
			float fTemp10 = (fConst6 * (fTemp0 * fTemp9));
			float fTemp11 = (fTemp10 + -1.49999499f);
			float fTemp12 = std::floor(fTemp11);
			float fTemp13 = (fTemp10 + (-1.0f - fTemp12));
			float fTemp14 = (0.0f - fTemp13);
			float fTemp15 = (fTemp10 + (-2.0f - fTemp12));
			float fTemp16 = (0.0f - (0.5f * fTemp15));
			float fTemp17 = (fTemp10 + (-3.0f - fTemp12));
			float fTemp18 = (0.0f - (0.333333343f * fTemp17));
			float fTemp19 = (fTemp10 + (-4.0f - fTemp12));
			float fTemp20 = (0.0f - (0.25f * fTemp19));
			float fTemp21 = (fTemp10 - fTemp12);
			float fTemp22 = (0.0f - fTemp15);
			float fTemp23 = (0.0f - (0.5f * fTemp17));
			float fTemp24 = (0.0f - (0.333333343f * fTemp19));
			float fTemp25 = (0.0f - fTemp17);
			float fTemp26 = (0.0f - (0.5f * fTemp19));
			float fTemp27 = (fTemp13 * fTemp15);
			float fTemp28 = (0.0f - fTemp19);
			float fTemp29 = (fTemp27 * fTemp17);
			float fTempFTZ16 = (((((fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int(iTemp8))))) + 1)) & 2047)] * fTemp14) * fTemp16) * fTemp18) * fTemp20) + (fTemp21 * ((((((fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp8 + 1)))))) + 1)) & 2047)] * fTemp22) * fTemp23) * fTemp24) + (0.5f * (((fTemp13 * fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp8 + 2)))))) + 1)) & 2047)]) * fTemp25) * fTemp26))) + (0.166666672f * ((fTemp27 * fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp8 + 3)))))) + 1)) & 2047)]) * fTemp28))) + (0.0416666679f * (fTemp29 * fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp8 + 4)))))) + 1)) & 2047)])))));
			fRec21[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fSlow13 + (fConst8 * fRec41[1]));
			fRec41[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec1[1];
			fRec42[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (-1.0f * (0.99880147f * ((0.800000012f * fRec42[2]) + (0.100000001f * (fRec42[1] + fRec42[3])))));
			fRec43[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			int iTemp30 = int(((fConst6 * (fRec24[0] * fTemp7)) + -1.49999499f));
			int iTemp31 = int(std::min<float>(fConst5, float(std::max<int>(0, int(iTemp30)))));
			float fTemp32 = (fConst6 * (fRec24[0] * fTemp9));
			float fTemp33 = std::floor((fTemp32 + -1.49999499f));
			float fTemp34 = (fTemp32 + (-1.0f - fTemp33));
			float fTemp35 = (0.0f - fTemp34);
			float fTemp36 = (fTemp32 + (-2.0f - fTemp33));
			float fTemp37 = (0.0f - (0.5f * fTemp36));
			float fTemp38 = (fTemp32 + (-3.0f - fTemp33));
			float fTemp39 = (0.0f - (0.333333343f * fTemp38));
			float fTemp40 = (fTemp32 + (-4.0f - fTemp33));
			float fTemp41 = (0.0f - (0.25f * fTemp40));
			float fTemp42 = (fTemp32 - fTemp33);
			int iTemp43 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp30 + 1))))));
			float fTemp44 = (0.0f - fTemp36);
			float fTemp45 = (0.0f - (0.5f * fTemp38));
			float fTemp46 = (0.0f - (0.333333343f * fTemp40));
			int iTemp47 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp30 + 2))))));
			float fTemp48 = (0.0f - fTemp38);
			float fTemp49 = (0.0f - (0.5f * fTemp40));
			float fTemp50 = (fTemp34 * fTemp36);
			int iTemp51 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp30 + 3))))));
			float fTemp52 = (0.0f - fTemp40);
			float fTemp53 = (fTemp50 * fTemp38);
			int iTemp54 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp30 + 4))))));
			fVec2[0] = (((((fRec43[((IOTA - (iTemp31 + 2)) & 2047)] * fTemp35) * fTemp37) * fTemp39) * fTemp41) + (fTemp42 * ((((((fRec43[((IOTA - (iTemp43 + 2)) & 2047)] * fTemp44) * fTemp45) * fTemp46) + (0.5f * (((fTemp34 * fRec43[((IOTA - (iTemp47 + 2)) & 2047)]) * fTemp48) * fTemp49))) + (0.166666672f * ((fTemp50 * fRec43[((IOTA - (iTemp51 + 2)) & 2047)]) * fTemp52))) + (0.0416666679f * (fTemp53 * fRec43[((IOTA - (iTemp54 + 2)) & 2047)])))));
			float fTemp55 = ((0.200000003f * (fRec35[0] * fRec41[0])) - (fRec21[1] + fVec2[1]));
			float fTempFTZ20 = (fSlow14 + (fConst8 * fRec44[1]));
			fRec44[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = ((fConst22 * fRec52[1]) + (fConst23 * fRec51[1]));
			fRec51[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = ((fTemp1 + (fConst23 * fRec52[1])) - (fConst22 * fRec51[1]));
			fRec52[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			int iTemp56 = ((fRec51[1] <= 0.0f) & (fRec51[0] > 0.0f));
			float fTempFTZ23 = ((fRec50[1] * float((1 - iTemp56))) + (4.65661287e-10f * (fTemp3 * float(iTemp56))));
			fRec50[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (0.0f - (fConst19 * ((fConst20 * fRec49[1]) - (fRec50[0] + fRec50[1]))));
			fRec49[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (0.0f - (fConst19 * ((fConst20 * fRec48[1]) - (fRec49[0] + fRec49[1]))));
			fRec48[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (0.0f - (fConst19 * ((fConst20 * fRec47[1]) - (fRec48[0] + fRec48[1]))));
			fRec47[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (0.0f - (fConst19 * ((fConst20 * fRec46[1]) - (fRec47[0] + fRec47[1]))));
			fRec46[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (0.0f - (fConst19 * ((fConst20 * fRec45[1]) - (fRec46[0] + fRec46[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTemp57 = (fTemp55 * std::min<float>(1.0f, (1.0f / FaustViolinDSP_faustpower4_f((std::fabs((fTemp55 * (5.0f - (4.0f * ((fRec35[0] * fRec44[0]) * ((0.0160000008f * (fRec35[0] * fRec45[0])) + 0.200000003f)))))) + 0.75f)))));
			float fTempFTZ29 = (fRec21[1] + fTemp57);
			float fRec22 = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp58 = (fVec2[1] + fTemp57);
			fVec3[(IOTA & 2047)] = fTemp58;
			int iTemp59 = int(fTemp11);
			float fTempFTZ30 = (((((fTemp14 * fTemp16) * fTemp18) * fTemp20) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int(iTemp59)))))) & 2047)]) + (fTemp21 * ((((((fTemp22 * fTemp23) * fTemp24) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp59 + 1))))))) & 2047)]) + (0.5f * (((fTemp13 * fTemp25) * fTemp26) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp59 + 2))))))) & 2047)]))) + (0.166666672f * ((fTemp27 * fTemp28) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp59 + 3))))))) & 2047)]))) + (0.0416666679f * (fTemp29 * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp59 + 4))))))) & 2047)])))));
			float fRec23 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = fRec22;
			fRec18[(IOTA & 2047)] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (((((fTemp35 * fTemp37) * fTemp39) * fTemp41) * fRec18[((IOTA - (iTemp31 + 1)) & 2047)]) + (fTemp42 * ((((((fTemp44 * fTemp45) * fTemp46) * fRec18[((IOTA - (iTemp43 + 1)) & 2047)]) + (0.5f * (((fTemp34 * fTemp48) * fTemp49) * fRec18[((IOTA - (iTemp47 + 1)) & 2047)]))) + (0.166666672f * ((fTemp50 * fTemp52) * fRec18[((IOTA - (iTemp51 + 1)) & 2047)]))) + (0.0416666679f * (fTemp53 * fRec18[((IOTA - (iTemp54 + 1)) & 2047)])))));
			float fRec19 = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = fRec23;
			fRec20[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = fRec20[1];
			fRec17[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fRec17[1] - (fConst24 * ((fConst25 * fRec15[2]) + (fConst26 * fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = ((fConst4 * fRec15[0]) + (fConst27 * fRec15[2]));
			float fTemp60 = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fRec13 = fTemp60;
			float fRec14 = fTemp60;
			iRec7[0] = iRec12;
			float fTempFTZ37 = fRec16;
			float fRec8 = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec13;
			float fRec9 = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = fRec14;
			float fRec10 = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = fRec8;
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = fRec19;
			float fRec4 = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = fRec9;
			float fRec5 = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = fRec10;
			float fRec6 = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = fRec4;
			fRec1[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = fRec6;
			fRec2[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = ((fRec2[0] + (0.995000005f * fRec0[1])) - fRec2[1]);
			fRec0[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow1 * std::max<float>(-1.0f, std::min<float>(1.0f, fRec0[0]))));
			iRec11[1] = iRec11[0];
			iVec0[1] = iVec0[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			iRec34[1] = iRec34[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec21[1] = fRec21[0];
			fRec41[1] = fRec41[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec42[j0] = fRec42[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			fRec44[1] = fRec44[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec20[1] = fRec20[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec17[j1] = fRec17[(j1 - 1)];
			}
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			iRec7[1] = iRec7[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
