/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "erhu"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustErhuDSP_H__
#define  __FaustErhuDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustErhuDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec32[2];
	
  public:
	
	int getNumInputsFaustErhuDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustErhuDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustErhuDSPSIG0(int sample_rate) {
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iVec1[l14] = 0;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			iRec32[l15] = 0;
		}
	}
	
	void fillFaustErhuDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec32[0] = ((iVec1[1] + iRec32[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec32[0])));
			iVec1[1] = iVec1[0];
			iRec32[1] = iRec32[0];
		}
	}

};

static FaustErhuDSPSIG0* newFaustErhuDSPSIG0() { return (FaustErhuDSPSIG0*)new FaustErhuDSPSIG0(); }
static void deleteFaustErhuDSPSIG0(FaustErhuDSPSIG0* dsp) { delete dsp; }

static float FaustErhuDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustErhuDSPSIG0[65536];
static float FaustErhuDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustErhuDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustErhuDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst4;
	float fConst5;
	float fConst9;
	float fConst11;
	int iRec8[2];
	int iVec0[2];
	float fConst12;
	float fConst13;
	FAUSTFLOAT fHslider1;
	float fConst14;
	FAUSTFLOAT fHslider2;
	float fConst15;
	float fRec20[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst17;
	float fConst18;
	float fConst20;
	float fConst21;
	float fRec27[2];
	float fRec28[2];
	int iRec29[2];
	float fRec26[2];
	float fRec25[2];
	float fRec24[2];
	float fRec23[2];
	float fRec22[2];
	float fRec21[2];
	FAUSTFLOAT fHslider5;
	float fRec30[2];
	float fConst22;
	float fConst23;
	FAUSTFLOAT fButton0;
	float fRec31[2];
	float fConst24;
	FAUSTFLOAT fHslider6;
	float fRec34[2];
	float fRec33[2];
	float fRec17[2];
	FAUSTFLOAT fHslider7;
	float fRec35[2];
	float fRec36[2];
	float fRec37[4];
	int IOTA;
	float fRec38[2048];
	float fVec2[2];
	FAUSTFLOAT fHslider8;
	float fRec39[2];
	float fConst25;
	float fConst26;
	float fRec40[2];
	float fConst27;
	float fConst28;
	float fRec41[2];
	float fConst30;
	float fConst31;
	float fConst33;
	float fConst34;
	float fRec48[2];
	float fRec49[2];
	float fRec47[2];
	float fRec46[2];
	float fRec45[2];
	float fRec44[2];
	float fRec43[2];
	float fRec42[2];
	float fVec3[2048];
	float fRec14[2048];
	float fRec16[2];
	float fRec13[4];
	float fRec4[2048];
	float fRec2[2];
	float fConst37;
	float fConst39;
	FAUSTFLOAT fHslider9;
	float fRec51[2];
	float fConst40;
	float fConst41;
	float fRec50[3];
	float fConst42;
	float fConst43;
	float fConst44;
	float fRec1[3];
	float fConst45;
	float fConst46;
	float fConst47;
	float fConst48;
	float fConst49;
	float fRec0[3];
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fRec52[3];
	float fConst61;
	float fConst62;
	float fConst63;
	float fConst64;
	float fConst65;
	float fRec53[3];
	float fConst66;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "erhu.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "erhu");
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
		FaustErhuDSPSIG0* sig0 = newFaustErhuDSPSIG0();
		sig0->instanceInitFaustErhuDSPSIG0(sample_rate);
		sig0->fillFaustErhuDSPSIG0(65536, ftbl0FaustErhuDSPSIG0);
		deleteFaustErhuDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((8796.45898f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.200000003f) / fConst1) + 1.0f);
		fConst4 = (0.25f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		float fConst6 = std::tan((376.991119f / fConst0));
		float fConst7 = (1.0f / fConst6);
		float fConst8 = (((fConst7 + 1.41421354f) / fConst6) + 1.0f);
		fConst9 = (1.0f / fConst8);
		float fConst10 = FaustErhuDSP_faustpower2_f(fConst6);
		fConst11 = (1.0f / fConst10);
		fConst12 = (0.00882352982f * fConst0);
		fConst13 = (0.00147058826f * fConst0);
		fConst14 = (44.0999985f / fConst0);
		fConst15 = (1.0f - fConst14);
		float fConst16 = (1.0f / std::tan((6.28318548f / fConst0)));
		fConst17 = (1.0f / (fConst16 + 1.0f));
		fConst18 = (1.0f - fConst16);
		float fConst19 = (12.566371f / fConst0);
		fConst20 = std::sin(fConst19);
		fConst21 = std::cos(fConst19);
		fConst22 = std::exp((0.0f - (2.85714293f / fConst0)));
		fConst23 = (1.0f - fConst22);
		fConst24 = (1.0f / fConst0);
		fConst25 = std::exp((0.0f - (66.6666641f / fConst0)));
		fConst26 = (1.0f - fConst25);
		fConst27 = std::exp((0.0f - (25.0f / fConst0)));
		fConst28 = (1.0f - fConst27);
		float fConst29 = (1.0f / std::tan((37.6991119f / fConst0)));
		fConst30 = (1.0f / (fConst29 + 1.0f));
		fConst31 = (1.0f - fConst29);
		float fConst32 = (75.3982239f / fConst0);
		fConst33 = std::sin(fConst32);
		fConst34 = std::cos(fConst32);
		float fConst35 = std::tan((7853.98145f / fConst0));
		float fConst36 = (1.0f / fConst35);
		fConst37 = (1.0f / (((fConst36 + 1.41421354f) / fConst35) + 1.0f));
		float fConst38 = FaustErhuDSP_faustpower2_f(fConst35);
		fConst39 = (1.0f / fConst38);
		fConst40 = (((fConst36 + -1.41421354f) / fConst35) + 1.0f);
		fConst41 = (2.0f * (1.0f - fConst39));
		fConst42 = (0.0f - (2.0f / fConst38));
		fConst43 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst44 = (2.0f * (1.0f - fConst11));
		fConst45 = (0.0f - (2.0f / fConst10));
		fConst46 = (0.200000003f / FaustErhuDSP_faustpower2_f(fConst8));
		fConst47 = (1.0f / fConst3);
		fConst48 = (((fConst2 + -0.200000003f) / fConst1) + 1.0f);
		fConst49 = (2.0f * (1.0f - (1.0f / FaustErhuDSP_faustpower2_f(fConst1))));
		float fConst50 = std::tan((4869.46875f / fConst0));
		float fConst51 = (1.0f / fConst50);
		float fConst52 = (((fConst51 + 0.333333343f) / fConst50) + 1.0f);
		fConst53 = (0.400000006f / (fConst50 * fConst52));
		fConst54 = (0.0f - fConst53);
		fConst55 = (1.0f / fConst52);
		fConst56 = (((fConst51 + -0.333333343f) / fConst50) + 1.0f);
		fConst57 = (2.0f * (1.0f - (1.0f / FaustErhuDSP_faustpower2_f(fConst50))));
		float fConst58 = std::tan((2984.51294f / fConst0));
		float fConst59 = (1.0f / fConst58);
		float fConst60 = (((fConst59 + 0.25f) / fConst58) + 1.0f);
		fConst61 = (0.600000024f / (fConst58 * fConst60));
		fConst62 = (0.0f - fConst61);
		fConst63 = (1.0f / fConst60);
		fConst64 = (((fConst59 + -0.25f) / fConst58) + 1.0f);
		fConst65 = (2.0f * (1.0f - (1.0f / FaustErhuDSP_faustpower2_f(fConst58))));
		fConst66 = (0.75f / fConst8);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.71999999999999997f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(440.0f);
		fHslider5 = FAUSTFLOAT(0.02f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(6.0f);
		fHslider7 = FAUSTFLOAT(0.5f);
		fHslider8 = FAUSTFLOAT(0.5f);
		fHslider9 = FAUSTFLOAT(0.02f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec8[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec20[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec27[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec28[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec29[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec26[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec25[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec24[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec23[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec22[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec21[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec30[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec31[l13] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec34[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec33[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec17[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec35[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec36[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 4); l21 = (l21 + 1)) {
			fRec37[l21] = 0.0f;
		}
		IOTA = 0;
		for (int l22 = 0; (l22 < 2048); l22 = (l22 + 1)) {
			fRec38[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fVec2[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec39[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec40[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec41[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec48[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec49[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec47[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec46[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec45[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec44[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec43[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec42[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2048); l35 = (l35 + 1)) {
			fVec3[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2048); l36 = (l36 + 1)) {
			fRec14[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec16[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 4); l38 = (l38 + 1)) {
			fRec13[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2048); l39 = (l39 + 1)) {
			fRec4[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec2[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec51[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec50[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec1[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec0[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec52[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec53[l46] = 0.0f;
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
	
	virtual FaustErhuDSP* clone() {
		return new FaustErhuDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("erhu");
		ui_interface->addHorizontalSlider("bowPosition", &fHslider2, FAUSTFLOAT(0.720000029f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("bowPressure", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("bowVelocity", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("calibration", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-0.100000001f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(440.0f), FAUSTFLOAT(290.0f), FAUSTFLOAT(1400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("noiseLvl", &fHslider9, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider5, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider6, FAUSTFLOAT(6.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (1.25999999f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		int iSlow2 = (fSlow1 == 2.0f);
		int iSlow3 = (fSlow1 == 3.0f);
		float fSlow4 = (fConst14 * float(fHslider2));
		float fSlow5 = float(fHslider3);
		float fSlow6 = (340.0f / float(fHslider4));
		float fSlow7 = (fConst14 * float(fHslider5));
		float fSlow8 = float(fButton0);
		float fSlow9 = (fConst23 * fSlow8);
		float fSlow10 = (fConst14 * float(fHslider6));
		int iSlow11 = (fSlow1 == 4.0f);
		int iSlow12 = iSlow11;
		int iSlow13 = (fSlow1 == 1.0f);
		int iSlow14 = iSlow13;
		float fSlow15 = (fConst14 * float(fHslider7));
		int iSlow16 = (iSlow13 | iSlow11);
		float fThen7 = (iSlow2 ? 0.0799999982f : 0.0350000001f);
		float fThen8 = (iSlow16 ? 0.0250000004f : 0.0450000018f);
		float fElse8 = (iSlow16 ? 0.00999999978f : fThen7);
		float fSlow17 = (int(fSlow8) ? fElse8 : fThen8);
		int iSlow18 = (std::fabs(fSlow17) < 1.1920929e-07f);
		float fThen10 = std::exp((0.0f - (fConst24 / (iSlow18 ? 1.0f : fSlow17))));
		float fSlow19 = (iSlow18 ? 0.0f : fThen10);
		float fSlow20 = (fSlow8 * (1.0f - fSlow19));
		float fSlow21 = (fConst14 * float(fHslider8));
		float fSlow22 = (fConst26 * fSlow8);
		float fSlow23 = (fConst28 * fSlow8);
		float fSlow24 = (fConst14 * float(fHslider9));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec8[0] = 0;
			iVec0[0] = 1;
			float fTempFTZ0 = (float(iRec8[1]) - (0.989264667f * ((0.600000024f * fRec13[2]) + (0.200000003f * (fRec13[1] + fRec13[3])))));
			float fRec12 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow4 + (fConst15 * fRec20[1]));
			fRec20[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fThen1 = (iSlow3 ? 0.879999995f : fRec20[0]);
			float fTemp0 = (iSlow2 ? 0.5f : fThen1);
			float fTemp1 = (1.0f - fTemp0);
			float fTempFTZ2 = ((fConst20 * fRec28[1]) + (fConst21 * fRec27[1]));
			fRec27[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp2 = float((1 - iVec0[1]));
			float fTempFTZ3 = ((fTemp2 + (fConst21 * fRec28[1])) - (fConst20 * fRec27[1]));
			fRec28[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			int iTemp3 = ((fRec27[1] <= 0.0f) & (fRec27[0] > 0.0f));
			iRec29[0] = ((1103515245 * iRec29[1]) + 12345);
			float fTemp4 = float(iRec29[0]);
			float fTempFTZ4 = ((fRec26[1] * float((1 - iTemp3))) + (4.65661287e-10f * (fTemp4 * float(iTemp3))));
			fRec26[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (0.0f - (fConst17 * ((fConst18 * fRec25[1]) - (fRec26[0] + fRec26[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (0.0f - (fConst17 * ((fConst18 * fRec24[1]) - (fRec25[0] + fRec25[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.0f - (fConst17 * ((fConst18 * fRec23[1]) - (fRec24[0] + fRec24[1]))));
			fRec23[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (0.0f - (fConst17 * ((fConst18 * fRec22[1]) - (fRec23[0] + fRec23[1]))));
			fRec22[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (0.0f - (fConst17 * ((fConst18 * fRec21[1]) - (fRec22[0] + fRec22[1]))));
			fRec21[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp5 = (0.00200000009f * fRec21[0]);
			float fTempFTZ10 = (fSlow7 + (fConst15 * fRec30[1]));
			fRec30[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fSlow9 + (fConst22 * fRec31[1]));
			fRec31[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fSlow10 + (fConst15 * fRec34[1]));
			fRec34[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp6 = (fRec33[1] + (fConst24 * fRec34[0]));
			float fTempFTZ13 = (fTemp6 - std::floor(fTemp6));
			fRec33[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp7 = ((fRec30[0] * fRec31[0]) * ftbl0FaustErhuDSPSIG0[int((65536.0f * fRec33[0]))]);
			float fTemp8 = (fSlow5 + ((fSlow6 / ((fTemp5 + fTemp7) + 1.0f)) + -0.0799999982f));
			int iTemp9 = int(((fConst13 * (fTemp1 * fTemp8)) + -1.49999499f));
			float fTemp10 = (fSlow5 + ((fSlow6 / ((fTemp5 + 1.0f) + fTemp7)) + -0.0799999982f));
			float fTemp11 = (fConst13 * (fTemp1 * fTemp10));
			float fTemp12 = (fTemp11 + -1.49999499f);
			float fTemp13 = std::floor(fTemp12);
			float fTemp14 = (fTemp11 + (-1.0f - fTemp13));
			float fTemp15 = (0.0f - fTemp14);
			float fTemp16 = (fTemp11 + (-2.0f - fTemp13));
			float fTemp17 = (0.0f - (0.5f * fTemp16));
			float fTemp18 = (fTemp11 + (-3.0f - fTemp13));
			float fTemp19 = (0.0f - (0.333333343f * fTemp18));
			float fTemp20 = (fTemp11 + (-4.0f - fTemp13));
			float fTemp21 = (0.0f - (0.25f * fTemp20));
			float fTemp22 = (fTemp11 - fTemp13);
			float fTemp23 = (0.0f - fTemp16);
			float fTemp24 = (0.0f - (0.5f * fTemp18));
			float fTemp25 = (0.0f - (0.333333343f * fTemp20));
			float fTemp26 = (0.0f - fTemp18);
			float fTemp27 = (0.0f - (0.5f * fTemp20));
			float fTemp28 = (fTemp14 * fTemp16);
			float fTemp29 = (0.0f - fTemp20);
			float fTemp30 = (fTemp28 * fTemp18);
			float fTempFTZ14 = (((((fRec4[((IOTA - (int(std::min<float>(fConst12, float(std::max<int>(0, int(iTemp9))))) + 1)) & 2047)] * fTemp15) * fTemp17) * fTemp19) * fTemp21) + (fTemp22 * ((((((fRec4[((IOTA - (int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp9 + 1)))))) + 1)) & 2047)] * fTemp23) * fTemp24) * fTemp25) + (0.5f * (((fTemp14 * fRec4[((IOTA - (int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp9 + 2)))))) + 1)) & 2047)]) * fTemp26) * fTemp27))) + (0.166666672f * ((fTemp28 * fRec4[((IOTA - (int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp9 + 3)))))) + 1)) & 2047)]) * fTemp29))) + (0.0416666679f * (fTemp30 * fRec4[((IOTA - (int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp9 + 4)))))) + 1)) & 2047)])))));
			fRec17[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fSlow15 + (fConst15 * fRec35[1]));
			fRec35[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fThen3 = (iSlow14 ? 0.600000024f : fRec35[0]);
			float fThen4 = (iSlow12 ? 0.550000012f : fThen3);
			float fTempFTZ16 = ((fRec36[1] * fSlow19) + fSlow20);
			fRec36[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec2[1];
			fRec37[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (-1.0f * (0.99880147f * ((0.800000012f * fRec37[2]) + (0.100000001f * (fRec37[1] + fRec37[3])))));
			fRec38[(IOTA & 2047)] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			int iTemp31 = int(((fConst13 * (fTemp0 * fTemp8)) + -1.49999499f));
			int iTemp32 = int(std::min<float>(fConst12, float(std::max<int>(0, int(iTemp31)))));
			float fTemp33 = (fConst13 * (fTemp0 * fTemp10));
			float fTemp34 = std::floor((fTemp33 + -1.49999499f));
			float fTemp35 = (fTemp33 + (-1.0f - fTemp34));
			float fTemp36 = (0.0f - fTemp35);
			float fTemp37 = (fTemp33 + (-2.0f - fTemp34));
			float fTemp38 = (0.0f - (0.5f * fTemp37));
			float fTemp39 = (fTemp33 + (-3.0f - fTemp34));
			float fTemp40 = (0.0f - (0.333333343f * fTemp39));
			float fTemp41 = (fTemp33 + (-4.0f - fTemp34));
			float fTemp42 = (0.0f - (0.25f * fTemp41));
			float fTemp43 = (fTemp33 - fTemp34);
			int iTemp44 = int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp31 + 1))))));
			float fTemp45 = (0.0f - fTemp37);
			float fTemp46 = (0.0f - (0.5f * fTemp39));
			float fTemp47 = (0.0f - (0.333333343f * fTemp41));
			int iTemp48 = int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp31 + 2))))));
			float fTemp49 = (0.0f - fTemp39);
			float fTemp50 = (0.0f - (0.5f * fTemp41));
			float fTemp51 = (fTemp35 * fTemp37);
			int iTemp52 = int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp31 + 3))))));
			float fTemp53 = (0.0f - fTemp41);
			float fTemp54 = (fTemp51 * fTemp39);
			int iTemp55 = int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp31 + 4))))));
			fVec2[0] = (((((fRec38[((IOTA - (iTemp32 + 2)) & 2047)] * fTemp36) * fTemp38) * fTemp40) * fTemp42) + (fTemp43 * ((((((fRec38[((IOTA - (iTemp44 + 2)) & 2047)] * fTemp45) * fTemp46) * fTemp47) + (0.5f * (((fTemp35 * fRec38[((IOTA - (iTemp48 + 2)) & 2047)]) * fTemp49) * fTemp50))) + (0.166666672f * ((fTemp51 * fRec38[((IOTA - (iTemp52 + 2)) & 2047)]) * fTemp53))) + (0.0416666679f * (fTemp54 * fRec38[((IOTA - (iTemp55 + 2)) & 2047)])))));
			float fTemp56 = (((iSlow2 ? 0.400000006f : fThen4) * fRec36[0]) - (fRec17[1] + fVec2[1]));
			float fTempFTZ19 = (fSlow21 + (fConst15 * fRec39[1]));
			fRec39[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fThen12 = (iSlow14 ? 0.600000024f : fRec39[0]);
			float fThen13 = (iSlow3 ? 0.699999988f : fThen12);
			float fTempFTZ20 = (fSlow22 + (fConst25 * fRec40[1]));
			fRec40[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fSlow23 + (fConst27 * fRec41[1]));
			fRec41[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fElse14 = (0.200000003f * (fRec40[0] * (1.0f - fRec41[0])));
			float fTemp57 = ((iSlow2 ? 0.349999994f : fThen13) + (iSlow16 ? fElse14 : 0.0f));
			float fTempFTZ22 = ((fConst33 * fRec49[1]) + (fConst34 * fRec48[1]));
			fRec48[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = ((fTemp2 + (fConst34 * fRec49[1])) - (fConst33 * fRec48[1]));
			fRec49[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			int iTemp58 = ((fRec48[1] <= 0.0f) & (fRec48[0] > 0.0f));
			float fTempFTZ24 = ((fRec47[1] * float((1 - iTemp58))) + (4.65661287e-10f * (fTemp4 * float(iTemp58))));
			fRec47[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (0.0f - (fConst30 * ((fConst31 * fRec46[1]) - (fRec47[0] + fRec47[1]))));
			fRec46[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (0.0f - (fConst30 * ((fConst31 * fRec45[1]) - (fRec46[0] + fRec46[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (0.0f - (fConst30 * ((fConst31 * fRec44[1]) - (fRec45[0] + fRec45[1]))));
			fRec44[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (0.0f - (fConst30 * ((fConst31 * fRec43[1]) - (fRec44[0] + fRec44[1]))));
			fRec43[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (0.0f - (fConst30 * ((fConst31 * fRec42[1]) - (fRec43[0] + fRec43[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp59 = (fTemp56 * std::min<float>(1.0f, (1.0f / FaustErhuDSP_faustpower4_f((std::fabs((fTemp56 * (5.0f - (4.0f * (fRec36[0] * (fTemp57 + (0.0399999991f * ((fRec36[0] * fRec42[0]) * fTemp57)))))))) + 0.75f)))));
			float fTempFTZ30 = (fRec17[1] + fTemp59);
			float fRec18 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTemp60 = (fVec2[1] + fTemp59);
			fVec3[(IOTA & 2047)] = fTemp60;
			int iTemp61 = int(fTemp12);
			float fTempFTZ31 = (((((fTemp15 * fTemp17) * fTemp19) * fTemp21) * fVec3[((IOTA - int(std::min<float>(fConst12, float(std::max<int>(0, int(iTemp61)))))) & 2047)]) + (fTemp22 * ((((((fTemp23 * fTemp24) * fTemp25) * fVec3[((IOTA - int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp61 + 1))))))) & 2047)]) + (0.5f * (((fTemp14 * fTemp26) * fTemp27) * fVec3[((IOTA - int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp61 + 2))))))) & 2047)]))) + (0.166666672f * ((fTemp28 * fTemp29) * fVec3[((IOTA - int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp61 + 3))))))) & 2047)]))) + (0.0416666679f * (fTemp30 * fVec3[((IOTA - int(std::min<float>(fConst12, float(std::max<int>(0, int((iTemp61 + 4))))))) & 2047)])))));
			float fRec19 = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec18;
			fRec14[(IOTA & 2047)] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (((((fTemp36 * fTemp38) * fTemp40) * fTemp42) * fRec14[((IOTA - (iTemp32 + 1)) & 2047)]) + (fTemp43 * ((((((fTemp45 * fTemp46) * fTemp47) * fRec14[((IOTA - (iTemp44 + 1)) & 2047)]) + (0.5f * (((fTemp35 * fTemp49) * fTemp50) * fRec14[((IOTA - (iTemp48 + 1)) & 2047)]))) + (0.166666672f * ((fTemp51 * fTemp53) * fRec14[((IOTA - (iTemp52 + 1)) & 2047)]))) + (0.0416666679f * (fTemp54 * fRec14[((IOTA - (iTemp55 + 1)) & 2047)])))));
			float fRec15 = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = fRec19;
			fRec16[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = fRec16[1];
			fRec13[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = fRec12;
			float fRec9 = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = fRec13[0];
			float fTemp62 = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fRec10 = fTemp62;
			float fRec11 = fTemp62;
			float fTempFTZ38 = fRec9;
			fRec4[(IOTA & 2047)] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = fRec15;
			float fRec5 = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = fRec10;
			float fRec6 = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = fRec11;
			float fRec7 = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = fRec5;
			fRec2[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = fRec7;
			float fRec3 = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = (fSlow24 + (fConst15 * fRec51[1]));
			fRec51[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = ((4.65661287e-10f * ((fRec36[0] * fRec51[0]) * fTemp4)) - (fConst37 * ((fConst40 * fRec50[2]) + (fConst41 * fRec50[1]))));
			fRec50[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = ((fRec3 + (fConst37 * (((fConst39 * fRec50[0]) + (fConst42 * fRec50[1])) + (fConst39 * fRec50[2])))) - (fConst9 * ((fConst43 * fRec1[2]) + (fConst44 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTemp63 = (((fConst11 * fRec1[0]) + (fConst45 * fRec1[1])) + (fConst11 * fRec1[2]));
			float fTemp64 = (fTemp63 * (1.0f - (fConst46 * FaustErhuDSP_faustpower2_f(fTemp63))));
			float fTemp65 = (fConst9 * fTemp64);
			float fTempFTZ47 = (fTemp65 - (fConst47 * ((fConst48 * fRec0[2]) + (fConst49 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = (fTemp65 - (fConst55 * ((fConst56 * fRec52[2]) + (fConst57 * fRec52[1]))));
			fRec52[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = (fTemp65 - (fConst63 * ((fConst64 * fRec53[2]) + (fConst65 * fRec53[1]))));
			fRec53[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * ((fConst5 * fRec0[2]) + ((fConst4 * fRec0[0]) + ((fConst54 * fRec52[2]) + ((fConst53 * fRec52[0]) + ((fConst62 * fRec53[2]) + ((fConst61 * fRec53[0]) + (fConst66 * fTemp64))))))))))));
			iRec8[1] = iRec8[0];
			iVec0[1] = iVec0[0];
			fRec20[1] = fRec20[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			iRec29[1] = iRec29[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec17[1] = fRec17[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec37[j0] = fRec37[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec48[1] = fRec48[0];
			fRec49[1] = fRec49[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec16[1] = fRec16[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec13[j1] = fRec13[(j1 - 1)];
			}
			fRec2[1] = fRec2[0];
			fRec51[1] = fRec51[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
		}
	}

};

#endif
