/* ------------------------------------------------------------
author: "Shashank Khare"
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tibetanBowl"
version: "1.0"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBowlDSP_H__
#define  __FaustBowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustBowlDSPSIG0 {
	
  private:
	
	int iVec15[2];
	int iRec44[2];
	
  public:
	
	int getNumInputsFaustBowlDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustBowlDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustBowlDSPSIG0(int sample_rate) {
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			iVec15[l59] = 0;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			iRec44[l60] = 0;
		}
	}
	
	void fillFaustBowlDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec15[0] = 1;
			iRec44[0] = ((iVec15[1] + iRec44[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec44[0])));
			iVec15[1] = iVec15[0];
			iRec44[1] = iRec44[0];
		}
	}

};

static FaustBowlDSPSIG0* newFaustBowlDSPSIG0() { return (FaustBowlDSPSIG0*)new FaustBowlDSPSIG0(); }
static void deleteFaustBowlDSPSIG0(FaustBowlDSPSIG0* dsp) { delete dsp; }

static float FaustBowlDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustBowlDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}
static float ftbl0FaustBowlDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBowlDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBowlDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fEntry1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fConst5;
	FAUSTFLOAT fHslider2;
	float fVec0[2];
	float fConst6;
	float fRec15[2];
	FAUSTFLOAT fHslider3;
	float fConst7;
	float fConst8;
	float fRec16[2];
	int iRec17[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fConst9;
	float fRec18[2];
	int IOTA;
	float fVec1[8192];
	FAUSTFLOAT fEntry2;
	float fConst10;
	float fConst11;
	float fRec14[3];
	float fRec13[2];
	float fRec0[2];
	float fVec2[8192];
	float fConst12;
	float fConst13;
	float fRec20[3];
	float fRec19[2];
	float fRec1[2];
	float fVec3[8192];
	float fConst14;
	float fConst15;
	float fRec22[3];
	float fRec21[2];
	float fRec2[2];
	float fVec4[8192];
	float fConst16;
	float fConst17;
	float fRec24[3];
	float fRec23[2];
	float fRec3[2];
	float fVec5[4096];
	float fConst18;
	float fConst19;
	float fRec26[3];
	float fRec25[2];
	float fRec4[2];
	float fVec6[4096];
	float fConst20;
	float fConst21;
	float fRec28[3];
	float fRec27[2];
	float fRec5[2];
	float fVec7[2048];
	float fConst22;
	float fConst23;
	float fRec30[3];
	float fRec29[2];
	float fRec6[2];
	float fVec8[2048];
	float fConst24;
	float fConst25;
	float fRec32[3];
	float fRec31[2];
	float fRec7[2];
	float fVec9[1024];
	float fConst26;
	float fConst27;
	float fRec34[3];
	float fRec33[2];
	float fRec8[2];
	float fVec10[1024];
	float fConst28;
	float fRec36[3];
	float fRec35[2];
	float fRec9[2];
	float fVec11[8192];
	float fConst29;
	float fRec38[3];
	float fRec37[2];
	float fRec10[2];
	float fVec12[4096];
	float fConst30;
	float fConst31;
	float fRec40[3];
	float fRec39[2];
	float fRec11[2];
	float fVec13[2048];
	float fConst32;
	float fConst33;
	float fRec42[3];
	float fRec41[2];
	float fRec12[2];
	float fVec14[2];
	FAUSTFLOAT fHslider6;
	float fRec43[2];
	float fConst34;
	FAUSTFLOAT fHslider7;
	float fRec46[2];
	float fRec45[2];
	float fRec52[2];
	float fRec51[2];
	float fRec50[2];
	float fRec49[2];
	float fRec48[2];
	float fRec47[2];
	float fRec58[2];
	float fRec57[2];
	float fRec56[2];
	float fRec55[2];
	float fRec54[2];
	float fRec53[2];
	float fVec16[8192];
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
		m->declare("filename", "bowl.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
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
		FaustBowlDSPSIG0* sig0 = newFaustBowlDSPSIG0();
		sig0->instanceInitFaustBowlDSPSIG0(sample_rate);
		sig0->fillFaustBowlDSPSIG0(65536, ftbl0FaustBowlDSPSIG0);
		deleteFaustBowlDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (100.530968f / fConst0);
		float fConst2 = (1.0f - fConst1);
		fConst3 = FaustBowlDSP_faustpower2_f(fConst2);
		fConst4 = (0.5f * (1.0f - fConst3));
		fConst5 = (44.0999985f / fConst0);
		fConst6 = (1.0f - fConst5);
		fConst7 = (0.5f * fConst0);
		fConst8 = (1.0f / std::max<float>(1.0f, fConst7));
		fConst9 = std::exp((0.0f - (66.6666641f / fConst0)));
		fConst10 = (0.0f - (2.0f * fConst2));
		fConst11 = (6.28318548f / fConst0);
		fConst12 = (1.60000002f * fConst0);
		fConst13 = (3.92699075f / fConst0);
		fConst14 = (2.55999994f * fConst0);
		fConst15 = (2.45436931f / fConst0);
		fConst16 = (0.621118009f * fConst0);
		fConst17 = (10.1159286f / fConst0);
		fConst18 = (0.385787576f * fConst0);
		fConst19 = (16.286644f / fConst0);
		fConst20 = (0.239619613f * fConst0);
		fConst21 = (26.2214985f / fConst0);
		fConst22 = (0.148949161f * fConst0);
		fConst23 = (42.1834221f / fConst0);
		fConst24 = (0.142857149f * fConst0);
		fConst25 = (43.982296f / fConst0);
		fConst26 = (0.0574712642f * fConst0);
		fConst27 = (109.327423f / fConst0);
		fConst28 = (0.0625f * fConst0);
		fConst29 = (12.566371f / fConst0);
		fConst30 = (0.25f * fConst0);
		fConst31 = (25.1327419f / fConst0);
		fConst32 = (0.125f * fConst0);
		fConst33 = (50.2654839f / fConst0);
		fConst34 = (1.0f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fEntry0 = FAUSTFLOAT(0.80000000000000004f);
		fEntry1 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.80000000000000004f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fEntry2 = FAUSTFLOAT(440.0f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(220.0f);
		fHslider8 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec15[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec16[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec17[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec18[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 8192); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec14[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec13[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec0[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 8192); l9 = (l9 + 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec20[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec19[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec1[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 8192); l13 = (l13 + 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec22[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec21[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 8192); l17 = (l17 + 1)) {
			fVec4[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec24[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec23[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec3[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 4096); l21 = (l21 + 1)) {
			fVec5[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec26[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec25[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec4[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 4096); l25 = (l25 + 1)) {
			fVec6[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec28[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec27[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec5[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2048); l29 = (l29 + 1)) {
			fVec7[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec30[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec29[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec6[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2048); l33 = (l33 + 1)) {
			fVec8[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec32[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec31[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec7[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 1024); l37 = (l37 + 1)) {
			fVec9[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec34[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec33[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec8[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 1024); l41 = (l41 + 1)) {
			fVec10[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec36[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec35[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec9[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 8192); l45 = (l45 + 1)) {
			fVec11[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec38[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec37[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec10[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 4096); l49 = (l49 + 1)) {
			fVec12[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec40[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec39[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec11[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2048); l53 = (l53 + 1)) {
			fVec13[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec42[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec41[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec12[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fVec14[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec43[l58] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec46[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec45[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec52[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec51[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec50[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec49[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec48[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec47[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec58[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec57[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec56[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec55[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec54[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec53[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 8192); l75 = (l75 + 1)) {
			fVec16[l75] = 0.0f;
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
	
	virtual FaustBowlDSP* clone() {
		return new FaustBowlDSP();
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
		ui_interface->addHorizontalSlider("Modulation_Frequency", &fHslider7, FAUSTFLOAT(220.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fEntry1, "3", "");
		ui_interface->declare(&fEntry1, "tooltip", "0=theta modulated by signal; 1=averaged signal; 2=squared signal; 3=sine freqMod; 4=sine freq");
		ui_interface->addNumEntry("Modulation_Type", &fEntry1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
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
		ui_interface->addNumEntry("freq", &fEntry2, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(1.0f));
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
		float fSlow2 = (11.0f * ((1.0f - fSlow0) * fSlow1));
		float fSlow3 = float(fEntry1);
		float fSlow4 = float((fSlow3 >= 3.0f));
		float fSlow5 = float(fHslider1);
		float fSlow6 = (0.0769230798f * fSlow5);
		float fSlow7 = float(fHslider2);
		float fSlow8 = (fConst5 * fSlow7);
		float fSlow9 = float(fHslider3);
		float fSlow10 = ((0.200000003f * fSlow9) + 0.0299999993f);
		int iSlow11 = (fSlow7 == 0.0f);
		float fSlow12 = ((0.100000001f * float(fHslider4)) + 0.899999976f);
		float fSlow13 = float(fHslider5);
		float fSlow14 = (10.0f - (9.0f * fSlow9));
		float fSlow15 = (1.0f - fSlow5);
		float fSlow16 = float(fEntry2);
		int iSlow17 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst0 / fSlow16))));
		float fSlow18 = (fConst10 * std::cos((fConst11 * fSlow16)));
		float fSlow19 = (0.5f * fSlow15);
		int iSlow20 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst12 / fSlow16))));
		float fSlow21 = (fConst10 * std::cos((fConst13 * fSlow16)));
		int iSlow22 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst14 / fSlow16))));
		float fSlow23 = (fConst10 * std::cos((fConst15 * fSlow16)));
		float fSlow24 = (2.0f * fSlow15);
		int iSlow25 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst16 / fSlow16))));
		float fSlow26 = (fConst10 * std::cos((fConst17 * fSlow16)));
		int iSlow27 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst18 / fSlow16))));
		float fSlow28 = (fConst10 * std::cos((fConst19 * fSlow16)));
		int iSlow29 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst20 / fSlow16))));
		float fSlow30 = (fConst10 * std::cos((fConst21 * fSlow16)));
		float fSlow31 = (3.0f * fSlow15);
		int iSlow32 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst22 / fSlow16))));
		float fSlow33 = (fConst10 * std::cos((fConst23 * fSlow16)));
		int iSlow34 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst24 / fSlow16))));
		float fSlow35 = (fConst10 * std::cos((fConst25 * fSlow16)));
		float fSlow36 = (4.0f * fSlow15);
		int iSlow37 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst26 / fSlow16))));
		float fSlow38 = (fConst10 * std::cos((fConst27 * fSlow16)));
		int iSlow39 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst28 / fSlow16))));
		float fSlow40 = (fConst10 * std::cos((fConst1 * fSlow16)));
		int iSlow41 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst7 / fSlow16))));
		float fSlow42 = (fConst10 * std::cos((fConst29 * fSlow16)));
		int iSlow43 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst30 / fSlow16))));
		float fSlow44 = (fConst10 * std::cos((fConst31 * fSlow16)));
		int iSlow45 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst32 / fSlow16))));
		float fSlow46 = (fConst10 * std::cos((fConst33 * fSlow16)));
		float fSlow47 = (fConst5 * float(fHslider6));
		float fSlow48 = (fSlow16 * float((fSlow3 == 4.0f)));
		float fSlow49 = float((fSlow3 != 4.0f));
		float fSlow50 = (fConst5 * float(fHslider7));
		float fSlow51 = float((fSlow3 < 3.0f));
		float fSlow52 = (3.14159274f * float((fSlow3 == 0.0f)));
		float fSlow53 = (1.57079637f * float((fSlow3 == 1.0f)));
		float fSlow54 = (3.14159274f * float((fSlow3 == 2.0f)));
		float fSlow55 = (11.0f * (fSlow0 * fSlow1));
		int iSlow56 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst7 * (float(fHslider8) / fSlow16)))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow7;
			float fTempFTZ0 = (fSlow8 + (fConst6 * fRec15[1]));
			fRec15[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow7 + (fRec16[1] * float((fVec0[1] >= fSlow7))));
			fRec16[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec17[0] = (iSlow11 * (iRec17[1] + 1));
			float fTemp0 = (((fSlow10 * std::max<float>(0.0f, (std::min<float>((fConst8 * fRec16[0]), 1.0f) * (1.0f - (fConst8 * float(iRec17[0])))))) - (fSlow12 * ((((((((((((fRec0[1] + fRec1[1]) + fRec2[1]) + fRec3[1]) + fRec4[1]) + fRec5[1]) + fRec6[1]) + fRec7[1]) + fRec8[1]) + fRec9[1]) + fRec10[1]) + fRec11[1]) + fRec12[1]))) - fSlow13);
			float fTemp1 = FaustBowlDSP_faustpower4_f((std::fabs((fSlow14 * fTemp0)) + 0.75f));
			float fTemp2 = (1.0f / fTemp1);
			float fTemp3 = (fSlow6 * ((fRec15[0] * fTemp0) * (float((fTemp2 > 1.0f)) + (float((fTemp2 <= 1.0f)) / fTemp1))));
			float fThen0 = (fConst9 * fRec18[1]);
			float fTempFTZ2 = ((fSlow7 > fVec0[1]) ? fSlow9 : fThen0);
			fRec18[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			fVec1[(IOTA & 8191)] = ((fRec13[1] + fTemp3) + (fSlow15 * fRec18[0]));
			float fTempFTZ3 = ((0.999000013f * fVec1[((IOTA - iSlow17) & 8191)]) - ((fSlow18 * fRec14[1]) + (fConst3 * fRec14[2])));
			fRec14[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fConst4 * (fRec14[0] - fRec14[2]));
			fRec13[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = fRec13[0];
			fRec0[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp4 = (fTemp3 + (fSlow19 * fRec18[0]));
			fVec2[(IOTA & 8191)] = (fRec19[1] + fTemp4);
			float fTempFTZ6 = ((0.999000013f * fVec2[((IOTA - iSlow20) & 8191)]) - ((fSlow21 * fRec20[1]) + (fConst3 * fRec20[2])));
			fRec20[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fConst4 * (fRec20[0] - fRec20[2]));
			fRec19[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = fRec19[0];
			fRec1[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			fVec3[(IOTA & 8191)] = (fTemp4 + fRec21[1]);
			float fTempFTZ9 = ((0.999000013f * fVec3[((IOTA - iSlow22) & 8191)]) - ((fSlow23 * fRec22[1]) + (fConst3 * fRec22[2])));
			fRec22[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fConst4 * (fRec22[0] - fRec22[2]));
			fRec21[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = fRec21[0];
			fRec2[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp5 = (fTemp3 + (fSlow24 * fRec18[0]));
			fVec4[(IOTA & 8191)] = (fRec23[1] + fTemp5);
			float fTempFTZ12 = ((0.999000013f * fVec4[((IOTA - iSlow25) & 8191)]) - ((fSlow26 * fRec24[1]) + (fConst3 * fRec24[2])));
			fRec24[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fConst4 * (fRec24[0] - fRec24[2]));
			fRec23[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = fRec23[0];
			fRec3[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			fVec5[(IOTA & 4095)] = (fTemp5 + fRec25[1]);
			float fTempFTZ15 = ((0.999000013f * fVec5[((IOTA - iSlow27) & 4095)]) - ((fSlow28 * fRec26[1]) + (fConst3 * fRec26[2])));
			fRec26[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fConst4 * (fRec26[0] - fRec26[2]));
			fRec25[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec25[0];
			fRec4[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			fVec6[(IOTA & 4095)] = (fTemp5 + fRec27[1]);
			float fTempFTZ18 = ((0.999000013f * fVec6[((IOTA - iSlow29) & 4095)]) - ((fSlow30 * fRec28[1]) + (fConst3 * fRec28[2])));
			fRec28[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fConst4 * (fRec28[0] - fRec28[2]));
			fRec27[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec27[0];
			fRec5[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp6 = (fTemp3 + (fSlow31 * fRec18[0]));
			fVec7[(IOTA & 2047)] = (fRec29[1] + fTemp6);
			float fTempFTZ21 = ((0.999000013f * fVec7[((IOTA - iSlow32) & 2047)]) - ((fSlow33 * fRec30[1]) + (fConst3 * fRec30[2])));
			fRec30[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fConst4 * (fRec30[0] - fRec30[2]));
			fRec29[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec29[0];
			fRec6[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			fVec8[(IOTA & 2047)] = (fTemp6 + fRec31[1]);
			float fTempFTZ24 = ((0.999000013f * fVec8[((IOTA - iSlow34) & 2047)]) - ((fSlow35 * fRec32[1]) + (fConst3 * fRec32[2])));
			fRec32[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fConst4 * (fRec32[0] - fRec32[2]));
			fRec31[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec31[0];
			fRec7[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			fVec9[(IOTA & 1023)] = (fRec33[1] + (fTemp3 + (fSlow36 * fRec18[0])));
			float fTempFTZ27 = ((0.999000013f * fVec9[((IOTA - iSlow37) & 1023)]) - ((fSlow38 * fRec34[1]) + (fConst3 * fRec34[2])));
			fRec34[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fConst4 * (fRec34[0] - fRec34[2]));
			fRec33[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec33[0];
			fRec8[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			fVec10[(IOTA & 1023)] = (fTemp6 + fRec35[1]);
			float fTempFTZ30 = ((0.999000013f * fVec10[((IOTA - iSlow39) & 1023)]) - ((fSlow40 * fRec36[1]) + (fConst3 * fRec36[2])));
			fRec36[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fConst4 * (fRec36[0] - fRec36[2]));
			fRec35[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec35[0];
			fRec9[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			fVec11[(IOTA & 8191)] = (fTemp4 + fRec37[1]);
			float fTempFTZ33 = ((0.999000013f * fVec11[((IOTA - iSlow41) & 8191)]) - ((fSlow42 * fRec38[1]) + (fConst3 * fRec38[2])));
			fRec38[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fConst4 * (fRec38[0] - fRec38[2]));
			fRec37[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = fRec37[0];
			fRec10[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			fVec12[(IOTA & 4095)] = (fTemp4 + fRec39[1]);
			float fTempFTZ36 = ((0.999000013f * fVec12[((IOTA - iSlow43) & 4095)]) - ((fSlow44 * fRec40[1]) + (fConst3 * fRec40[2])));
			fRec40[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fConst4 * (fRec40[0] - fRec40[2]));
			fRec39[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec39[0];
			fRec11[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			fVec13[(IOTA & 2047)] = (fTemp4 + fRec41[1]);
			float fTempFTZ39 = ((0.999000013f * fVec13[((IOTA - iSlow45) & 2047)]) - ((fSlow46 * fRec42[1]) + (fConst3 * fRec42[2])));
			fRec42[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fConst4 * (fRec42[0] - fRec42[2]));
			fRec41[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = fRec41[0];
			fRec12[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTemp7 = ((((((((((((fRec0[0] + fRec1[0]) + fRec2[0]) + fRec3[0]) + fRec4[0]) + fRec5[0]) + fRec6[0]) + fRec7[0]) + fRec8[0]) + fRec9[0]) + fRec10[0]) + fRec11[0]) + fRec12[0]);
			fVec14[0] = fTemp7;
			float fTempFTZ42 = (fSlow47 + (fConst6 * fRec43[1]));
			fRec43[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = (fSlow50 + (fConst6 * fRec46[1]));
			fRec46[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTemp8 = (fRec45[1] + (fConst34 * (fSlow48 + (fSlow49 * fRec46[0]))));
			float fTempFTZ44 = (fTemp8 - std::floor(fTemp8));
			fRec45[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTemp9 = (3.14159274f * (fRec43[0] * ftbl0FaustBowlDSPSIG0[int((65536.0f * fRec45[0]))]));
			float fTemp10 = std::sin(fTemp9);
			float fTemp11 = std::cos(fTemp9);
			float fTemp12 = ((fTemp7 * fTemp11) - (fTemp10 * fRec47[1]));
			float fTemp13 = ((fTemp11 * fTemp12) - (fTemp10 * fRec48[1]));
			float fTemp14 = ((fTemp11 * fTemp13) - (fTemp10 * fRec49[1]));
			float fTemp15 = ((fTemp11 * fTemp14) - (fTemp10 * fRec50[1]));
			float fTemp16 = ((fTemp11 * fTemp15) - (fTemp10 * fRec51[1]));
			float fTempFTZ45 = ((fTemp11 * fTemp16) - (fTemp10 * fRec52[1]));
			fRec52[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = ((fTemp10 * fTemp16) + (fTemp11 * fRec52[1]));
			fRec51[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = ((fTemp10 * fTemp15) + (fTemp11 * fRec51[1]));
			fRec50[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = ((fTemp10 * fTemp14) + (fTemp11 * fRec50[1]));
			fRec49[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = ((fTemp10 * fTemp13) + (fTemp11 * fRec49[1]));
			fRec48[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = ((fTemp10 * fTemp12) + (fTemp11 * fRec48[1]));
			fRec47[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTemp17 = (fRec43[0] * (((fSlow52 * fTemp7) + (fSlow53 * (fTemp7 + fVec14[1]))) + (fSlow54 * FaustBowlDSP_faustpower2_f(fTemp7))));
			float fTemp18 = std::sin(fTemp17);
			float fTemp19 = std::cos(fTemp17);
			float fTemp20 = ((fTemp7 * fTemp19) - (fTemp18 * fRec53[1]));
			float fTemp21 = ((fTemp19 * fTemp20) - (fTemp18 * fRec54[1]));
			float fTemp22 = ((fTemp19 * fTemp21) - (fTemp18 * fRec55[1]));
			float fTemp23 = ((fTemp19 * fTemp22) - (fTemp18 * fRec56[1]));
			float fTemp24 = ((fTemp19 * fTemp23) - (fTemp18 * fRec57[1]));
			float fTempFTZ51 = ((fTemp19 * fTemp24) - (fTemp18 * fRec58[1]));
			fRec58[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = ((fTemp18 * fTemp24) + (fTemp19 * fRec58[1]));
			fRec57[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = ((fTemp18 * fTemp23) + (fTemp19 * fRec57[1]));
			fRec56[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTempFTZ54 = ((fTemp18 * fTemp22) + (fTemp19 * fRec56[1]));
			fRec55[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fTempFTZ55 = ((fTemp18 * fTemp21) + (fTemp19 * fRec55[1]));
			fRec54[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fTempFTZ56 = ((fTemp18 * fTemp20) + (fTemp19 * fRec54[1]));
			fRec53[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fTemp25 = ((fSlow4 * ((fTemp7 * fTemp10) + (fRec47[1] * fTemp11))) + (fSlow51 * ((fTemp7 * (1.0f - fRec43[0])) + (fRec43[0] * ((fTemp7 * fTemp18) + (fRec53[1] * fTemp19))))));
			fVec16[(IOTA & 8191)] = fTemp25;
			output0[i0] = FAUSTFLOAT((fSlow2 * fTemp25));
			output1[i0] = FAUSTFLOAT((fSlow55 * fVec16[((IOTA - iSlow56) & 8191)]));
			fVec0[1] = fVec0[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			iRec17[1] = iRec17[0];
			fRec18[1] = fRec18[0];
			IOTA = (IOTA + 1);
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec0[1] = fRec0[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec1[1] = fRec1[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec2[1] = fRec2[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec3[1] = fRec3[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec4[1] = fRec4[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec5[1] = fRec5[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec6[1] = fRec6[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec7[1] = fRec7[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec8[1] = fRec8[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec9[1] = fRec9[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec10[1] = fRec10[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec11[1] = fRec11[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec12[1] = fRec12[0];
			fVec14[1] = fVec14[0];
			fRec43[1] = fRec43[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
		}
	}

};

#endif
