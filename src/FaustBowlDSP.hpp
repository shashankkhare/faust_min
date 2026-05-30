/* ------------------------------------------------------------
author: "Romain Michon"
copyright: "Romain Michon (rmichon@ccrma.stanford.edu)"
name: "tibetanBowl"
version: "1.0"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustBowlDSP_H__
#define  __FaustBowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

class FaustBowlDSPSIG0 {
	
  private:
	
	int iVec13[2];
	int iRec38[2];
	
  public:
	
	int getNumInputsFaustBowlDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustBowlDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustBowlDSPSIG0(int sample_rate) {
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			iVec13[l51] = 0;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			iRec38[l52] = 0;
		}
	}
	
	void fillFaustBowlDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec13[0] = 1;
			iRec38[0] = ((iVec13[1] + iRec38[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec38[0])));
			iVec13[1] = iVec13[0];
			iRec38[1] = iRec38[0];
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
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider1;
	float fConst4;
	FAUSTFLOAT fHslider2;
	float fVec0[2];
	float fConst5;
	float fRec13[2];
	FAUSTFLOAT fHslider3;
	float fConst6;
	float fConst7;
	float fRec14[2];
	int iRec15[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fConst8;
	float fRec16[2];
	int IOTA;
	float fVec1[8192];
	FAUSTFLOAT fEntry2;
	float fConst9;
	float fConst10;
	float fRec12[3];
	float fRec11[2];
	float fRec0[2];
	float fVec2[8192];
	float fConst11;
	float fConst12;
	float fRec18[3];
	float fRec17[2];
	float fRec1[2];
	float fVec3[8192];
	float fConst13;
	float fConst14;
	float fRec20[3];
	float fRec19[2];
	float fRec2[2];
	float fVec4[8192];
	float fConst15;
	float fConst16;
	float fRec22[3];
	float fRec21[2];
	float fRec3[2];
	float fVec5[4096];
	float fConst17;
	float fConst18;
	float fRec24[3];
	float fRec23[2];
	float fRec4[2];
	float fVec6[4096];
	float fConst19;
	float fConst20;
	float fRec26[3];
	float fRec25[2];
	float fRec5[2];
	float fVec7[2048];
	float fConst21;
	float fConst22;
	float fRec28[3];
	float fRec27[2];
	float fRec6[2];
	float fVec8[1024];
	float fConst23;
	float fConst24;
	float fRec30[3];
	float fRec29[2];
	float fRec7[2];
	float fVec9[8192];
	float fConst25;
	float fRec32[3];
	float fRec31[2];
	float fRec8[2];
	float fVec10[4096];
	float fConst26;
	float fConst27;
	float fRec34[3];
	float fRec33[2];
	float fRec9[2];
	float fVec11[2048];
	float fConst28;
	float fConst29;
	float fRec36[3];
	float fRec35[2];
	float fRec10[2];
	float fVec12[2];
	FAUSTFLOAT fHslider6;
	float fRec37[2];
	float fConst30;
	FAUSTFLOAT fHslider7;
	float fRec40[2];
	float fRec39[2];
	float fRec46[2];
	float fRec45[2];
	float fRec44[2];
	float fRec43[2];
	float fRec42[2];
	float fRec41[2];
	float fRec52[2];
	float fRec51[2];
	float fRec50[2];
	float fRec49[2];
	float fRec48[2];
	float fRec47[2];
	float fVec14[8192];
	FAUSTFLOAT fHslider8;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Romain Michon");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "Banded Waveguide Modeld Tibetan Bowl");
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
		m->declare("licence", "STK-4.3");
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
		float fConst1 = (1.0f - (100.530968f / fConst0));
		fConst2 = FaustBowlDSP_faustpower2_f(fConst1);
		fConst3 = (0.5f * (1.0f - fConst2));
		fConst4 = (44.0999985f / fConst0);
		fConst5 = (1.0f - fConst4);
		fConst6 = (0.5f * fConst0);
		fConst7 = (1.0f / std::max<float>(1.0f, fConst6));
		fConst8 = std::exp((0.0f - (66.6666641f / fConst0)));
		fConst9 = (0.0f - (2.0f * fConst1));
		fConst10 = (6.28318548f / fConst0);
		fConst11 = (1.60000002f * fConst0);
		fConst12 = (3.92699075f / fConst0);
		fConst13 = (2.55999994f * fConst0);
		fConst14 = (2.45436931f / fConst0);
		fConst15 = (0.621118009f * fConst0);
		fConst16 = (10.1159286f / fConst0);
		fConst17 = (0.385787576f * fConst0);
		fConst18 = (16.286644f / fConst0);
		fConst19 = (0.239619613f * fConst0);
		fConst20 = (26.2214985f / fConst0);
		fConst21 = (0.142857149f * fConst0);
		fConst22 = (43.982296f / fConst0);
		fConst23 = (0.0649350658f * fConst0);
		fConst24 = (96.761055f / fConst0);
		fConst25 = (12.566371f / fConst0);
		fConst26 = (0.25f * fConst0);
		fConst27 = (25.1327419f / fConst0);
		fConst28 = (0.125f * fConst0);
		fConst29 = (50.2654839f / fConst0);
		fConst30 = (1.0f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fEntry0 = FAUSTFLOAT(0.80000000000000004f);
		fEntry1 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
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
			fRec13[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec14[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec15[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec16[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 8192); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec12[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec11[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec0[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 8192); l9 = (l9 + 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec18[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec17[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec1[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 8192); l13 = (l13 + 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec20[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec19[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 8192); l17 = (l17 + 1)) {
			fVec4[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec22[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec21[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec3[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 4096); l21 = (l21 + 1)) {
			fVec5[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec24[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec23[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec4[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 4096); l25 = (l25 + 1)) {
			fVec6[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec26[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec25[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec5[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2048); l29 = (l29 + 1)) {
			fVec7[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec28[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec27[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec6[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 1024); l33 = (l33 + 1)) {
			fVec8[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec30[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec29[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec7[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 8192); l37 = (l37 + 1)) {
			fVec9[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec32[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec31[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec8[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 4096); l41 = (l41 + 1)) {
			fVec10[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec34[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec33[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec9[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2048); l45 = (l45 + 1)) {
			fVec11[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec36[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec35[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec10[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fVec12[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec37[l50] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec40[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec39[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec46[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec45[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec44[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec43[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec42[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec41[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec52[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec51[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec50[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec49[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec48[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec47[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 8192); l67 = (l67 + 1)) {
			fVec14[l67] = 0.0f;
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
		ui_interface->declare(&fHslider7, "tooltip", "Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)");
		ui_interface->declare(&fHslider7, "unit", "Hz");
		ui_interface->addHorizontalSlider("Modulation_Frequency", &fHslider7, FAUSTFLOAT(220.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fEntry1, "3", "");
		ui_interface->declare(&fEntry1, "tooltip", "0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal; 2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod; 4=theta is modulated by a sine wave of frequency freq;");
		ui_interface->addNumEntry("Modulation_Type", &fEntry1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "3", "");
		ui_interface->declare(&fHslider6, "tooltip", "Nonlinearity factor (value between 0 and 1)");
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
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fEntry0);
		float fSlow2 = (5.0f * ((1.0f - fSlow0) * fSlow1));
		float fSlow3 = float(fEntry1);
		float fSlow4 = float((fSlow3 >= 3.0f));
		float fSlow5 = float(fHslider1);
		float fSlow6 = (0.0909090936f * (0.0f - (fSlow5 + -1.0f)));
		float fSlow7 = float(fHslider2);
		float fSlow8 = (fConst4 * fSlow7);
		float fSlow9 = float(fHslider3);
		float fSlow10 = ((0.200000003f * fSlow9) + 0.0299999993f);
		int iSlow11 = (fSlow7 == 0.0f);
		float fSlow12 = ((0.100000001f * float(fHslider4)) + 0.899999976f);
		float fSlow13 = float(fHslider5);
		float fSlow14 = (10.0f - (9.0f * fSlow9));
		float fSlow15 = float(fEntry2);
		int iSlow16 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst0 / fSlow15))));
		float fSlow17 = (fConst9 * std::cos((fConst10 * fSlow15)));
		float fSlow18 = (0.5f * fSlow5);
		int iSlow19 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst11 / fSlow15))));
		float fSlow20 = (fConst9 * std::cos((fConst12 * fSlow15)));
		int iSlow21 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst13 / fSlow15))));
		float fSlow22 = (fConst9 * std::cos((fConst14 * fSlow15)));
		float fSlow23 = (2.0f * fSlow5);
		int iSlow24 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst15 / fSlow15))));
		float fSlow25 = (fConst9 * std::cos((fConst16 * fSlow15)));
		int iSlow26 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst17 / fSlow15))));
		float fSlow27 = (fConst9 * std::cos((fConst18 * fSlow15)));
		int iSlow28 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst19 / fSlow15))));
		float fSlow29 = (fConst9 * std::cos((fConst20 * fSlow15)));
		float fSlow30 = (3.0f * fSlow5);
		int iSlow31 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst21 / fSlow15))));
		float fSlow32 = (fConst9 * std::cos((fConst22 * fSlow15)));
		float fSlow33 = (4.0f * fSlow5);
		int iSlow34 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst23 / fSlow15))));
		float fSlow35 = (fConst9 * std::cos((fConst24 * fSlow15)));
		int iSlow36 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst6 / fSlow15))));
		float fSlow37 = (fConst9 * std::cos((fConst25 * fSlow15)));
		int iSlow38 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst26 / fSlow15))));
		float fSlow39 = (fConst9 * std::cos((fConst27 * fSlow15)));
		int iSlow40 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst28 / fSlow15))));
		float fSlow41 = (fConst9 * std::cos((fConst29 * fSlow15)));
		float fSlow42 = (fConst4 * float(fHslider6));
		float fSlow43 = (fSlow15 * float((fSlow3 == 4.0f)));
		float fSlow44 = float((fSlow3 != 4.0f));
		float fSlow45 = (fConst4 * float(fHslider7));
		float fSlow46 = float((fSlow3 < 3.0f));
		float fSlow47 = (3.14159274f * float((fSlow3 == 0.0f)));
		float fSlow48 = (1.57079637f * float((fSlow3 == 1.0f)));
		float fSlow49 = (3.14159274f * float((fSlow3 == 2.0f)));
		float fSlow50 = (5.0f * (fSlow0 * fSlow1));
		int iSlow51 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst6 * (float(fHslider8) / fSlow15)))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow7;
			fRec13[0] = (fSlow8 + (fConst5 * fRec13[1]));
			fRec14[0] = (fSlow7 + (fRec14[1] * float((fVec0[1] >= fSlow7))));
			iRec15[0] = (iSlow11 * (iRec15[1] + 1));
			float fTemp0 = (((fSlow10 * std::max<float>(0.0f, (std::min<float>((fConst7 * fRec14[0]), 1.0f) * (1.0f - (fConst7 * float(iRec15[0])))))) - (fSlow12 * ((((((((((fRec0[1] + fRec1[1]) + fRec2[1]) + fRec3[1]) + fRec4[1]) + fRec5[1]) + fRec6[1]) + fRec7[1]) + fRec8[1]) + fRec9[1]) + fRec10[1]))) - fSlow13);
			float fTemp1 = FaustBowlDSP_faustpower4_f((std::fabs((fSlow14 * fTemp0)) + 0.75f));
			float fTemp2 = (1.0f / fTemp1);
			float fTemp3 = (fSlow6 * ((fRec13[0] * fTemp0) * (float((fTemp2 > 1.0f)) + (float((fTemp2 <= 1.0f)) / fTemp1))));
			float fThen0 = (fConst8 * fRec16[1]);
			fRec16[0] = ((fSlow7 > fVec0[1]) ? fSlow9 : fThen0);
			fVec1[(IOTA & 8191)] = ((fRec11[1] + fTemp3) + (fSlow5 * fRec16[0]));
			fRec12[0] = ((0.999899983f * fVec1[((IOTA - iSlow16) & 8191)]) - ((fSlow17 * fRec12[1]) + (fConst2 * fRec12[2])));
			fRec11[0] = (fConst3 * (fRec12[0] - fRec12[2]));
			fRec0[0] = fRec11[0];
			float fTemp4 = (fTemp3 + (fSlow18 * fRec16[0]));
			fVec2[(IOTA & 8191)] = (fRec17[1] + fTemp4);
			fRec18[0] = ((0.999899983f * fVec2[((IOTA - iSlow19) & 8191)]) - ((fSlow20 * fRec18[1]) + (fConst2 * fRec18[2])));
			fRec17[0] = (fConst3 * (fRec18[0] - fRec18[2]));
			fRec1[0] = fRec17[0];
			fVec3[(IOTA & 8191)] = (fTemp4 + fRec19[1]);
			fRec20[0] = ((0.999899983f * fVec3[((IOTA - iSlow21) & 8191)]) - ((fSlow22 * fRec20[1]) + (fConst2 * fRec20[2])));
			fRec19[0] = (fConst3 * (fRec20[0] - fRec20[2]));
			fRec2[0] = fRec19[0];
			float fTemp5 = (fTemp3 + (fSlow23 * fRec16[0]));
			fVec4[(IOTA & 8191)] = (fRec21[1] + fTemp5);
			fRec22[0] = ((0.999899983f * fVec4[((IOTA - iSlow24) & 8191)]) - ((fSlow25 * fRec22[1]) + (fConst2 * fRec22[2])));
			fRec21[0] = (fConst3 * (fRec22[0] - fRec22[2]));
			fRec3[0] = fRec21[0];
			fVec5[(IOTA & 4095)] = (fTemp5 + fRec23[1]);
			fRec24[0] = ((0.999899983f * fVec5[((IOTA - iSlow26) & 4095)]) - ((fSlow27 * fRec24[1]) + (fConst2 * fRec24[2])));
			fRec23[0] = (fConst3 * (fRec24[0] - fRec24[2]));
			fRec4[0] = fRec23[0];
			fVec6[(IOTA & 4095)] = (fTemp5 + fRec25[1]);
			fRec26[0] = ((0.999899983f * fVec6[((IOTA - iSlow28) & 4095)]) - ((fSlow29 * fRec26[1]) + (fConst2 * fRec26[2])));
			fRec25[0] = (fConst3 * (fRec26[0] - fRec26[2]));
			fRec5[0] = fRec25[0];
			fVec7[(IOTA & 2047)] = (fRec27[1] + (fTemp3 + (fSlow30 * fRec16[0])));
			fRec28[0] = ((0.999899983f * fVec7[((IOTA - iSlow31) & 2047)]) - ((fSlow32 * fRec28[1]) + (fConst2 * fRec28[2])));
			fRec27[0] = (fConst3 * (fRec28[0] - fRec28[2]));
			fRec6[0] = fRec27[0];
			fVec8[(IOTA & 1023)] = (fRec29[1] + (fTemp3 + (fSlow33 * fRec16[0])));
			fRec30[0] = ((0.999899983f * fVec8[((IOTA - iSlow34) & 1023)]) - ((fSlow35 * fRec30[1]) + (fConst2 * fRec30[2])));
			fRec29[0] = (fConst3 * (fRec30[0] - fRec30[2]));
			fRec7[0] = fRec29[0];
			fVec9[(IOTA & 8191)] = (fTemp4 + fRec31[1]);
			fRec32[0] = ((0.999899983f * fVec9[((IOTA - iSlow36) & 8191)]) - ((fSlow37 * fRec32[1]) + (fConst2 * fRec32[2])));
			fRec31[0] = (fConst3 * (fRec32[0] - fRec32[2]));
			fRec8[0] = fRec31[0];
			fVec10[(IOTA & 4095)] = (fTemp4 + fRec33[1]);
			fRec34[0] = ((0.999899983f * fVec10[((IOTA - iSlow38) & 4095)]) - ((fSlow39 * fRec34[1]) + (fConst2 * fRec34[2])));
			fRec33[0] = (fConst3 * (fRec34[0] - fRec34[2]));
			fRec9[0] = fRec33[0];
			fVec11[(IOTA & 2047)] = (fTemp4 + fRec35[1]);
			fRec36[0] = ((0.999899983f * fVec11[((IOTA - iSlow40) & 2047)]) - ((fSlow41 * fRec36[1]) + (fConst2 * fRec36[2])));
			fRec35[0] = (fConst3 * (fRec36[0] - fRec36[2]));
			fRec10[0] = fRec35[0];
			float fTemp6 = ((((((((((fRec0[0] + fRec1[0]) + fRec2[0]) + fRec3[0]) + fRec4[0]) + fRec5[0]) + fRec6[0]) + fRec7[0]) + fRec8[0]) + fRec9[0]) + fRec10[0]);
			fVec12[0] = fTemp6;
			fRec37[0] = (fSlow42 + (fConst5 * fRec37[1]));
			fRec40[0] = (fSlow45 + (fConst5 * fRec40[1]));
			float fTemp7 = (fRec39[1] + (fConst30 * (fSlow43 + (fSlow44 * fRec40[0]))));
			fRec39[0] = (fTemp7 - std::floor(fTemp7));
			float fTemp8 = (3.14159274f * (fRec37[0] * ftbl0FaustBowlDSPSIG0[int((65536.0f * fRec39[0]))]));
			float fTemp9 = std::sin(fTemp8);
			float fTemp10 = std::cos(fTemp8);
			float fTemp11 = ((fTemp6 * fTemp10) - (fTemp9 * fRec41[1]));
			float fTemp12 = ((fTemp10 * fTemp11) - (fTemp9 * fRec42[1]));
			float fTemp13 = ((fTemp10 * fTemp12) - (fTemp9 * fRec43[1]));
			float fTemp14 = ((fTemp10 * fTemp13) - (fTemp9 * fRec44[1]));
			float fTemp15 = ((fTemp10 * fTemp14) - (fTemp9 * fRec45[1]));
			fRec46[0] = ((fTemp10 * fTemp15) - (fTemp9 * fRec46[1]));
			fRec45[0] = ((fTemp9 * fTemp15) + (fTemp10 * fRec46[1]));
			fRec44[0] = ((fTemp9 * fTemp14) + (fTemp10 * fRec45[1]));
			fRec43[0] = ((fTemp9 * fTemp13) + (fTemp10 * fRec44[1]));
			fRec42[0] = ((fTemp9 * fTemp12) + (fTemp10 * fRec43[1]));
			fRec41[0] = ((fTemp9 * fTemp11) + (fTemp10 * fRec42[1]));
			float fTemp16 = (fRec37[0] * (((fSlow47 * fTemp6) + (fSlow48 * (fTemp6 + fVec12[1]))) + (fSlow49 * FaustBowlDSP_faustpower2_f(fTemp6))));
			float fTemp17 = std::sin(fTemp16);
			float fTemp18 = std::cos(fTemp16);
			float fTemp19 = ((fTemp6 * fTemp18) - (fTemp17 * fRec47[1]));
			float fTemp20 = ((fTemp18 * fTemp19) - (fTemp17 * fRec48[1]));
			float fTemp21 = ((fTemp18 * fTemp20) - (fTemp17 * fRec49[1]));
			float fTemp22 = ((fTemp18 * fTemp21) - (fTemp17 * fRec50[1]));
			float fTemp23 = ((fTemp18 * fTemp22) - (fTemp17 * fRec51[1]));
			fRec52[0] = ((fTemp18 * fTemp23) - (fTemp17 * fRec52[1]));
			fRec51[0] = ((fTemp17 * fTemp23) + (fTemp18 * fRec52[1]));
			fRec50[0] = ((fTemp17 * fTemp22) + (fTemp18 * fRec51[1]));
			fRec49[0] = ((fTemp17 * fTemp21) + (fTemp18 * fRec50[1]));
			fRec48[0] = ((fTemp17 * fTemp20) + (fTemp18 * fRec49[1]));
			fRec47[0] = ((fTemp17 * fTemp19) + (fTemp18 * fRec48[1]));
			float fTemp24 = ((fSlow4 * ((fTemp6 * fTemp9) + (fRec41[1] * fTemp10))) + (fSlow46 * ((fTemp6 * (1.0f - fRec37[0])) + (fRec37[0] * ((fTemp6 * fTemp17) + (fRec47[1] * fTemp18))))));
			fVec14[(IOTA & 8191)] = fTemp24;
			output0[i0] = FAUSTFLOAT((fSlow2 * fTemp24));
			output1[i0] = FAUSTFLOAT((fSlow50 * fVec14[((IOTA - iSlow51) & 8191)]));
			fVec0[1] = fVec0[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			iRec15[1] = iRec15[0];
			fRec16[1] = fRec16[0];
			IOTA = (IOTA + 1);
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec0[1] = fRec0[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec1[1] = fRec1[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec2[1] = fRec2[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec3[1] = fRec3[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec4[1] = fRec4[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec5[1] = fRec5[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec6[1] = fRec6[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec7[1] = fRec7[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec8[1] = fRec8[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec9[1] = fRec9[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec10[1] = fRec10[0];
			fVec12[1] = fVec12[0];
			fRec37[1] = fRec37[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
		}
	}

};

#endif
