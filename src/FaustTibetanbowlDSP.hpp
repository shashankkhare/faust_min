/* ------------------------------------------------------------
author: "Shashank Khare"
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tibetanBowl"
version: "1.0"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTibetanbowlDSP_H__
#define  __FaustTibetanbowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustTibetanbowlDSPSIG0 {
	
  private:
	
	int iVec14[2];
	int iRec41[2];
	
  public:
	
	int getNumInputsFaustTibetanbowlDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTibetanbowlDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTibetanbowlDSPSIG0(int sample_rate) {
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			iVec14[l55] = 0;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			iRec41[l56] = 0;
		}
	}
	
	void fillFaustTibetanbowlDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec14[0] = 1;
			iRec41[0] = ((iVec14[1] + iRec41[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec41[0])));
			iVec14[1] = iVec14[0];
			iRec41[1] = iRec41[0];
		}
	}

};

static FaustTibetanbowlDSPSIG0* newFaustTibetanbowlDSPSIG0() { return (FaustTibetanbowlDSPSIG0*)new FaustTibetanbowlDSPSIG0(); }
static void deleteFaustTibetanbowlDSPSIG0(FaustTibetanbowlDSPSIG0* dsp) { delete dsp; }

static float FaustTibetanbowlDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}
static float ftbl0FaustTibetanbowlDSPSIG0[65536];
static float FaustTibetanbowlDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTibetanbowlDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTibetanbowlDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fVec0[2];
	float fConst2;
	float fRec14[2];
	FAUSTFLOAT fHslider3;
	float fConst3;
	float fConst4;
	float fRec15[2];
	int iRec16[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fConst5;
	float fRec17[2];
	int IOTA;
	float fVec1[2048];
	FAUSTFLOAT fEntry2;
	float fConst6;
	float fRec13[3];
	float fRec12[2];
	float fRec0[2];
	float fVec2[1024];
	float fConst7;
	float fConst8;
	float fRec19[3];
	float fRec18[2];
	float fRec1[2];
	float fVec3[512];
	float fConst9;
	float fConst10;
	float fRec21[3];
	float fRec20[2];
	float fRec2[2];
	float fVec4[512];
	float fConst11;
	float fConst12;
	float fRec23[3];
	float fRec22[2];
	float fRec3[2];
	float fVec5[256];
	float fConst13;
	float fConst14;
	float fRec25[3];
	float fRec24[2];
	float fRec4[2];
	float fVec6[256];
	float fConst15;
	float fConst16;
	float fRec27[3];
	float fRec26[2];
	float fRec5[2];
	float fVec7[128];
	float fConst17;
	float fConst18;
	float fRec29[3];
	float fRec28[2];
	float fRec6[2];
	float fVec8[128];
	float fConst19;
	float fConst20;
	float fRec31[3];
	float fRec30[2];
	float fRec7[2];
	float fVec9[128];
	float fConst21;
	float fConst22;
	float fRec33[3];
	float fRec32[2];
	float fRec8[2];
	float fVec10[64];
	float fConst23;
	float fConst24;
	float fRec35[3];
	float fRec34[2];
	float fRec9[2];
	float fVec11[64];
	float fConst25;
	float fConst26;
	float fRec37[3];
	float fRec36[2];
	float fRec10[2];
	float fVec12[64];
	float fConst27;
	float fConst28;
	float fRec39[3];
	float fRec38[2];
	float fRec11[2];
	float fVec13[2];
	FAUSTFLOAT fHslider6;
	float fRec40[2];
	float fConst29;
	FAUSTFLOAT fHslider7;
	float fRec43[2];
	float fRec42[2];
	float fRec49[2];
	float fRec48[2];
	float fRec47[2];
	float fRec46[2];
	float fRec45[2];
	float fRec44[2];
	float fRec55[2];
	float fRec54[2];
	float fRec53[2];
	float fRec52[2];
	float fRec51[2];
	float fRec50[2];
	float fVec15[1024];
	FAUSTFLOAT fHslider8;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Shashank Khare");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "Banded Waveguide Tibetan Bowl");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "tibetanbowl.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("instruments.lib/author", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("instruments.lib/copyright", "Romain Michon");
		m->declare("instruments.lib/licence", "STK-4.3");
		m->declare("instruments.lib/name", "Faust-STK Tools Library");
		m->declare("instruments.lib/version", "1.0");
		m->declare("licence", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tibetanBowl");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.1");
		m->declare("version", "1.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		FaustTibetanbowlDSPSIG0* sig0 = newFaustTibetanbowlDSPSIG0();
		sig0->instanceInitFaustTibetanbowlDSPSIG0(sample_rate);
		sig0->fillFaustTibetanbowlDSPSIG0(65536, ftbl0FaustTibetanbowlDSPSIG0);
		deleteFaustTibetanbowlDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (0.5f * fConst0);
		fConst4 = (1.0f / std::max<float>(1.0f, fConst3));
		fConst5 = std::exp((0.0f - (66.6666641f / fConst0)));
		fConst6 = (6.28318548f / fConst0);
		fConst7 = (0.370370358f * fConst0);
		fConst8 = (16.9645996f / fConst0);
		fConst9 = (0.208333328f * fConst0);
		fConst10 = (30.1592903f / fConst0);
		fConst11 = (0.13333334f * fConst0);
		fConst12 = (47.1238899f / fConst0);
		fConst13 = (0.094339624f * fConst0);
		fConst14 = (66.6017609f / fConst0);
		fConst15 = (0.0704225376f * fConst0);
		fConst16 = (89.2212296f / fConst0);
		fConst17 = (0.0549450554f * fConst0);
		fConst18 = (114.353973f / fConst0);
		fConst19 = (0.0440528616f * fConst0);
		fConst20 = (142.628311f / fConst0);
		fConst21 = (0.0361010842f * fConst0);
		fConst22 = (174.044235f / fConst0);
		fConst23 = (0.0301204827f * fConst0);
		fConst24 = (208.601746f / fConst0);
		fConst25 = (0.025510205f * fConst0);
		fConst26 = (246.300858f / fConst0);
		fConst27 = (0.0218818374f * fConst0);
		fConst28 = (287.141571f / fConst0);
		fConst29 = (1.0f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fEntry0 = FAUSTFLOAT(0.80000000000000004f);
		fEntry1 = FAUSTFLOAT(100.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.80000000000000004f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fEntry2 = FAUSTFLOAT(400.0f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(220.0f);
		fHslider8 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec14[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec15[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec16[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec17[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 2048); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec13[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec12[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec0[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 1024); l9 = (l9 + 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec19[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec18[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec1[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 512); l13 = (l13 + 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec21[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec20[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 512); l17 = (l17 + 1)) {
			fVec4[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec23[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec22[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec3[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 256); l21 = (l21 + 1)) {
			fVec5[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec25[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec24[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec4[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 256); l25 = (l25 + 1)) {
			fVec6[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec27[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec26[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec5[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 128); l29 = (l29 + 1)) {
			fVec7[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec29[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec28[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec6[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 128); l33 = (l33 + 1)) {
			fVec8[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec31[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec30[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec7[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 128); l37 = (l37 + 1)) {
			fVec9[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec33[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec32[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec8[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 64); l41 = (l41 + 1)) {
			fVec10[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec35[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec34[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec9[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 64); l45 = (l45 + 1)) {
			fVec11[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec37[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec36[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec10[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 64); l49 = (l49 + 1)) {
			fVec12[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec39[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec38[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec11[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fVec13[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec40[l54] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec43[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec42[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec49[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec48[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec47[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec46[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec45[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec44[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec55[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec54[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec53[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec52[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec51[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec50[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 1024); l71 = (l71 + 1)) {
			fVec15[l71] = 0.0f;
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
	
	virtual FaustTibetanbowlDSP* clone() {
		return new FaustTibetanbowlDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tibetanBowl");
		ui_interface->openHorizontalBox("Physical_and_Nonlinearity");
		ui_interface->openVerticalBox("Nonlinear_Filter_Parameters");
		ui_interface->declare(&fHslider7, "3", "");
		ui_interface->declare(&fHslider7, "tooltip", "Sine modulation frequency (works if Modulation Type=3)");
		ui_interface->declare(&fHslider7, "unit", "Hz");
		ui_interface->addHorizontalSlider("Modulation_Frequency", &fHslider7, FAUSTFLOAT(220.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fEntry1, "3", "");
		ui_interface->declare(&fEntry1, "tooltip", "0=theta modulated by signal; 1=averaged signal; 2=squared signal; 3=sine freqMod; 4=sine freq");
		ui_interface->addNumEntry("Modulation_Type", &fEntry1, FAUSTFLOAT(100.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "3", "");
		ui_interface->declare(&fHslider6, "tooltip", "Nonlinearity factor (0 to 1)");
		ui_interface->addHorizontalSlider("Nonlinearity", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Physical_Parameters");
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "tooltip", "A value between 0 and 1");
		ui_interface->addHorizontalSlider("Base_Gain", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "tooltip", "A value between 0 and 1");
		ui_interface->addHorizontalSlider("Integration_Constant", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Spat");
		ui_interface->addHorizontalSlider("pan angle", &fHslider0, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("spatial width", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->addNumEntry("freq", &fEntry2, FAUSTFLOAT(400.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(1.0f));
		ui_interface->addNumEntry("gain", &fEntry0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gate", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fEntry0);
		float fSlow2 = (3.53325009f * ((1.0f - fSlow0) * fSlow1));
		float fSlow3 = float(fEntry1);
		float fSlow4 = float((fSlow3 >= 3.0f));
		float fSlow5 = float(fHslider1);
		float fSlow6 = (0.0833333358f * fSlow5);
		float fSlow7 = float(fHslider2);
		float fSlow8 = (fConst1 * fSlow7);
		float fSlow9 = float(fHslider3);
		float fSlow10 = ((0.200000003f * fSlow9) + 0.0299999993f);
		int iSlow11 = (fSlow7 == 0.0f);
		float fSlow12 = ((0.100000001f * float(fHslider4)) + 0.899999976f);
		float fSlow13 = float(fHslider5);
		float fSlow14 = (10.0f - (9.0f * fSlow9));
		float fSlow15 = (1.0f - fSlow5);
		float fSlow16 = (24.0f * fSlow15);
		float fSlow17 = float(fEntry2);
		int iSlow18 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst0 / fSlow17))));
		float fSlow19 = (0.0f - (1.96000004f * std::cos((fConst6 * fSlow17))));
		float fSlow20 = (19.2000008f * fSlow15);
		int iSlow21 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst7 / fSlow17))));
		float fSlow22 = (0.0f - (1.96000004f * std::cos((fConst8 * fSlow17))));
		float fSlow23 = (14.3999996f * fSlow15);
		int iSlow24 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst9 / fSlow17))));
		float fSlow25 = (0.0f - (1.96000004f * std::cos((fConst10 * fSlow17))));
		int iSlow26 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst11 / fSlow17))));
		float fSlow27 = (0.0f - (1.96000004f * std::cos((fConst12 * fSlow17))));
		int iSlow28 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst13 / fSlow17))));
		float fSlow29 = (0.0f - (1.96000004f * std::cos((fConst14 * fSlow17))));
		int iSlow30 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst15 / fSlow17))));
		float fSlow31 = (0.0f - (1.96000004f * std::cos((fConst16 * fSlow17))));
		int iSlow32 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst17 / fSlow17))));
		float fSlow33 = (0.0f - (1.96000004f * std::cos((fConst18 * fSlow17))));
		int iSlow34 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst19 / fSlow17))));
		float fSlow35 = (0.0f - (1.96000004f * std::cos((fConst20 * fSlow17))));
		float fSlow36 = (9.60000038f * fSlow15);
		int iSlow37 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst21 / fSlow17))));
		float fSlow38 = (0.0f - (1.96000004f * std::cos((fConst22 * fSlow17))));
		int iSlow39 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst23 / fSlow17))));
		float fSlow40 = (0.0f - (1.96000004f * std::cos((fConst24 * fSlow17))));
		int iSlow41 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst25 / fSlow17))));
		float fSlow42 = (0.0f - (1.96000004f * std::cos((fConst26 * fSlow17))));
		int iSlow43 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst27 / fSlow17))));
		float fSlow44 = (0.0f - (1.96000004f * std::cos((fConst28 * fSlow17))));
		float fSlow45 = (fConst1 * float(fHslider6));
		float fSlow46 = (fSlow17 * float((fSlow3 == 4.0f)));
		float fSlow47 = float((fSlow3 != 4.0f));
		float fSlow48 = (fConst1 * float(fHslider7));
		float fSlow49 = float((fSlow3 < 3.0f));
		float fSlow50 = (3.14159274f * float((fSlow3 == 0.0f)));
		float fSlow51 = (1.57079637f * float((fSlow3 == 1.0f)));
		float fSlow52 = (3.14159274f * float((fSlow3 == 2.0f)));
		float fSlow53 = (3.53325009f * (fSlow0 * fSlow1));
		int iSlow54 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst3 * (float(fHslider8) / fSlow17)))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow7;
			float fTempFTZ0 = (fSlow8 + (fConst2 * fRec14[1]));
			fRec14[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow7 + (fRec15[1] * float((fVec0[1] >= fSlow7))));
			fRec15[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec16[0] = (iSlow11 * (iRec16[1] + 1));
			float fTemp0 = (((fSlow10 * std::max<float>(0.0f, (std::min<float>((fConst4 * fRec15[0]), 1.0f) * (1.0f - (fConst4 * float(iRec16[0])))))) - (fSlow12 * (((((((((((fRec0[1] + fRec1[1]) + fRec2[1]) + fRec3[1]) + fRec4[1]) + fRec5[1]) + fRec6[1]) + fRec7[1]) + fRec8[1]) + fRec9[1]) + fRec10[1]) + fRec11[1]))) - fSlow13);
			float fTemp1 = FaustTibetanbowlDSP_faustpower4_f((std::fabs((fSlow14 * fTemp0)) + 0.75f));
			float fTemp2 = (1.0f / fTemp1);
			float fTemp3 = (fSlow6 * ((fRec14[0] * fTemp0) * (float((fTemp2 > 1.0f)) + (float((fTemp2 <= 1.0f)) / fTemp1))));
			float fThen0 = (fConst5 * fRec17[1]);
			float fTempFTZ2 = ((fSlow7 > fVec0[1]) ? fSlow9 : fThen0);
			fRec17[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp4 = (fSlow16 * fRec17[0]);
			fVec1[(IOTA & 2047)] = ((fRec12[1] + fTemp3) + fTemp4);
			float fTempFTZ3 = ((0.998000026f * fVec1[((IOTA - iSlow18) & 2047)]) - ((fSlow19 * fRec13[1]) + (0.960399985f * fRec13[2])));
			fRec13[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (0.0197999999f * (fRec13[0] - fRec13[2]));
			fRec12[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = fRec12[0];
			fRec0[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp5 = (fTemp3 + (fSlow20 * fRec17[0]));
			fVec2[(IOTA & 1023)] = (fRec18[1] + fTemp5);
			float fTempFTZ6 = ((0.998000026f * fVec2[((IOTA - iSlow21) & 1023)]) - ((fSlow22 * fRec19[1]) + (0.960399985f * fRec19[2])));
			fRec19[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.0197999999f * (fRec19[0] - fRec19[2]));
			fRec18[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = fRec18[0];
			fRec1[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp6 = (fTemp3 + (fSlow23 * fRec17[0]));
			fVec3[(IOTA & 511)] = (fRec20[1] + fTemp6);
			float fTempFTZ9 = ((0.998000026f * fVec3[((IOTA - iSlow24) & 511)]) - ((fSlow25 * fRec21[1]) + (0.960399985f * fRec21[2])));
			fRec21[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (0.0197999999f * (fRec21[0] - fRec21[2]));
			fRec20[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = fRec20[0];
			fRec2[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			fVec4[(IOTA & 511)] = (fTemp6 + fRec22[1]);
			float fTempFTZ12 = ((0.998000026f * fVec4[((IOTA - iSlow26) & 511)]) - ((fSlow27 * fRec23[1]) + (0.960399985f * fRec23[2])));
			fRec23[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (0.0197999999f * (fRec23[0] - fRec23[2]));
			fRec22[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = fRec22[0];
			fRec3[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			fVec5[(IOTA & 255)] = (fTemp5 + fRec24[1]);
			float fTempFTZ15 = ((0.998000026f * fVec5[((IOTA - iSlow28) & 255)]) - ((fSlow29 * fRec25[1]) + (0.960399985f * fRec25[2])));
			fRec25[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (0.0197999999f * (fRec25[0] - fRec25[2]));
			fRec24[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec24[0];
			fRec4[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			fVec6[(IOTA & 255)] = (fTemp5 + fRec26[1]);
			float fTempFTZ18 = ((0.998000026f * fVec6[((IOTA - iSlow30) & 255)]) - ((fSlow31 * fRec27[1]) + (0.960399985f * fRec27[2])));
			fRec27[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (0.0197999999f * (fRec27[0] - fRec27[2]));
			fRec26[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec26[0];
			fRec5[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp7 = (fTemp3 + fTemp4);
			fVec7[(IOTA & 127)] = (fRec28[1] + fTemp7);
			float fTempFTZ21 = ((0.998000026f * fVec7[((IOTA - iSlow32) & 127)]) - ((fSlow33 * fRec29[1]) + (0.960399985f * fRec29[2])));
			fRec29[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (0.0197999999f * (fRec29[0] - fRec29[2]));
			fRec28[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec28[0];
			fRec6[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			fVec8[(IOTA & 127)] = (fTemp7 + fRec30[1]);
			float fTempFTZ24 = ((0.998000026f * fVec8[((IOTA - iSlow34) & 127)]) - ((fSlow35 * fRec31[1]) + (0.960399985f * fRec31[2])));
			fRec31[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (0.0197999999f * (fRec31[0] - fRec31[2]));
			fRec30[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec30[0];
			fRec7[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTemp8 = (fTemp3 + (fSlow36 * fRec17[0]));
			fVec9[(IOTA & 127)] = (fRec32[1] + fTemp8);
			float fTempFTZ27 = ((0.998000026f * fVec9[((IOTA - iSlow37) & 127)]) - ((fSlow38 * fRec33[1]) + (0.960399985f * fRec33[2])));
			fRec33[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (0.0197999999f * (fRec33[0] - fRec33[2]));
			fRec32[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec32[0];
			fRec8[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			fVec10[(IOTA & 63)] = (fTemp8 + fRec34[1]);
			float fTempFTZ30 = ((0.998000026f * fVec10[((IOTA - iSlow39) & 63)]) - ((fSlow40 * fRec35[1]) + (0.960399985f * fRec35[2])));
			fRec35[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (0.0197999999f * (fRec35[0] - fRec35[2]));
			fRec34[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec34[0];
			fRec9[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			fVec11[(IOTA & 63)] = (fTemp5 + fRec36[1]);
			float fTempFTZ33 = ((0.998000026f * fVec11[((IOTA - iSlow41) & 63)]) - ((fSlow42 * fRec37[1]) + (0.960399985f * fRec37[2])));
			fRec37[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (0.0197999999f * (fRec37[0] - fRec37[2]));
			fRec36[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = fRec36[0];
			fRec10[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			fVec12[(IOTA & 63)] = (fTemp5 + fRec38[1]);
			float fTempFTZ36 = ((0.998000026f * fVec12[((IOTA - iSlow43) & 63)]) - ((fSlow44 * fRec39[1]) + (0.960399985f * fRec39[2])));
			fRec39[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (0.0197999999f * (fRec39[0] - fRec39[2]));
			fRec38[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec38[0];
			fRec11[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTemp9 = (((((((((((fRec0[0] + fRec1[0]) + fRec2[0]) + fRec3[0]) + fRec4[0]) + fRec5[0]) + fRec6[0]) + fRec7[0]) + fRec8[0]) + fRec9[0]) + fRec10[0]) + fRec11[0]);
			fVec13[0] = fTemp9;
			float fTempFTZ39 = (fSlow45 + (fConst2 * fRec40[1]));
			fRec40[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fSlow48 + (fConst2 * fRec43[1]));
			fRec43[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTemp10 = (fRec42[1] + (fConst29 * (fSlow46 + (fSlow47 * fRec43[0]))));
			float fTempFTZ41 = (fTemp10 - std::floor(fTemp10));
			fRec42[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTemp11 = (3.14159274f * (fRec40[0] * ftbl0FaustTibetanbowlDSPSIG0[int((65536.0f * fRec42[0]))]));
			float fTemp12 = std::sin(fTemp11);
			float fTemp13 = std::cos(fTemp11);
			float fTemp14 = ((fTemp9 * fTemp13) - (fTemp12 * fRec44[1]));
			float fTemp15 = ((fTemp13 * fTemp14) - (fTemp12 * fRec45[1]));
			float fTemp16 = ((fTemp13 * fTemp15) - (fTemp12 * fRec46[1]));
			float fTemp17 = ((fTemp13 * fTemp16) - (fTemp12 * fRec47[1]));
			float fTemp18 = ((fTemp13 * fTemp17) - (fTemp12 * fRec48[1]));
			float fTempFTZ42 = ((fTemp13 * fTemp18) - (fTemp12 * fRec49[1]));
			fRec49[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = ((fTemp12 * fTemp18) + (fTemp13 * fRec49[1]));
			fRec48[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = ((fTemp12 * fTemp17) + (fTemp13 * fRec48[1]));
			fRec47[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = ((fTemp12 * fTemp16) + (fTemp13 * fRec47[1]));
			fRec46[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = ((fTemp12 * fTemp15) + (fTemp13 * fRec46[1]));
			fRec45[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = ((fTemp12 * fTemp14) + (fTemp13 * fRec45[1]));
			fRec44[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTemp19 = (fRec40[0] * (((fSlow50 * fTemp9) + (fSlow51 * (fTemp9 + fVec13[1]))) + (fSlow52 * FaustTibetanbowlDSP_faustpower2_f(fTemp9))));
			float fTemp20 = std::sin(fTemp19);
			float fTemp21 = std::cos(fTemp19);
			float fTemp22 = ((fTemp9 * fTemp21) - (fTemp20 * fRec50[1]));
			float fTemp23 = ((fTemp21 * fTemp22) - (fTemp20 * fRec51[1]));
			float fTemp24 = ((fTemp21 * fTemp23) - (fTemp20 * fRec52[1]));
			float fTemp25 = ((fTemp21 * fTemp24) - (fTemp20 * fRec53[1]));
			float fTemp26 = ((fTemp21 * fTemp25) - (fTemp20 * fRec54[1]));
			float fTempFTZ48 = ((fTemp21 * fTemp26) - (fTemp20 * fRec55[1]));
			fRec55[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = ((fTemp20 * fTemp26) + (fTemp21 * fRec55[1]));
			fRec54[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = ((fTemp20 * fTemp25) + (fTemp21 * fRec54[1]));
			fRec53[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTempFTZ51 = ((fTemp20 * fTemp24) + (fTemp21 * fRec53[1]));
			fRec52[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = ((fTemp20 * fTemp23) + (fTemp21 * fRec52[1]));
			fRec51[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = ((fTemp20 * fTemp22) + (fTemp21 * fRec51[1]));
			fRec50[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTemp27 = ((fSlow4 * ((fTemp9 * fTemp12) + (fRec44[1] * fTemp13))) + (fSlow49 * ((fTemp9 * (1.0f - fRec40[0])) + (fRec40[0] * ((fTemp9 * fTemp20) + (fRec50[1] * fTemp21))))));
			fVec15[(IOTA & 1023)] = fTemp27;
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow2 * fTemp27)))));
			output1[i0] = FAUSTFLOAT(float(tanhf(float((fSlow53 * fVec15[((IOTA - iSlow54) & 1023)])))));
			fVec0[1] = fVec0[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			iRec16[1] = iRec16[0];
			fRec17[1] = fRec17[0];
			IOTA = (IOTA + 1);
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec0[1] = fRec0[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec1[1] = fRec1[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec2[1] = fRec2[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec3[1] = fRec3[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec4[1] = fRec4[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec5[1] = fRec5[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec6[1] = fRec6[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec7[1] = fRec7[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec8[1] = fRec8[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec9[1] = fRec9[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec10[1] = fRec10[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec11[1] = fRec11[0];
			fVec13[1] = fVec13[0];
			fRec40[1] = fRec40[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
		}
	}

};

#endif
