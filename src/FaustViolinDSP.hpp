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
	int iRec44[2];
	
  public:
	
	int getNumInputsFaustViolinDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustViolinDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustViolinDSPSIG0(int sample_rate) {
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iVec1[l18] = 0;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			iRec44[l19] = 0;
		}
	}
	
	void fillFaustViolinDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec44[0] = ((iVec1[1] + iRec44[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec44[0])));
			iVec1[1] = iVec1[0];
			iRec44[1] = iRec44[0];
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
	
	int fSampleRate;
	float fConst6;
	FAUSTFLOAT fHslider0;
	int iVec0[2];
	float fRec0[2];
	float fConst7;
	float fConst13;
	float fConst14;
	float fConst19;
	float fConst20;
	float fConst25;
	float fConst26;
	int iRec16[2];
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec30[2];
	float fRec29[2];
	FAUSTFLOAT fHslider3;
	float fRec31[2];
	FAUSTFLOAT fHslider4;
	float fConst36;
	float fConst37;
	float fConst39;
	float fConst40;
	float fRec38[2];
	float fRec39[2];
	int iRec40[2];
	float fRec37[2];
	float fRec36[2];
	float fRec35[2];
	float fRec34[2];
	float fRec33[2];
	float fRec32[2];
	FAUSTFLOAT fButton0;
	float fConst41;
	float fRec41[2];
	FAUSTFLOAT fHslider5;
	float fRec42[2];
	float fConst42;
	float fConst43;
	float fRec43[2];
	FAUSTFLOAT fHslider6;
	float fRec46[2];
	float fRec45[2];
	float fRec26[2];
	FAUSTFLOAT fHslider7;
	float fRec47[2];
	float fRec48[4];
	int IOTA;
	float fRec49[2048];
	float fVec2[2];
	FAUSTFLOAT fHslider8;
	float fRec50[2];
	float fConst44;
	float fConst45;
	float fRec51[2];
	float fConst46;
	float fConst47;
	float fRec52[2];
	float fConst49;
	float fConst50;
	float fConst52;
	float fConst53;
	float fRec59[2];
	float fRec60[2];
	float fRec58[2];
	float fRec57[2];
	float fRec56[2];
	float fRec55[2];
	float fRec54[2];
	float fRec53[2];
	float fVec3[2048];
	float fRec23[2048];
	float fRec25[2];
	float fRec22[4];
	float fConst54;
	float fConst55;
	float fConst56;
	float fRec20[3];
	float fConst57;
	int iRec12[2];
	float fRec8[2048];
	float fRec6[2];
	float fRec7[2];
	float fRec5[2];
	float fConst58;
	float fRec4[3];
	float fConst60;
	float fConst61;
	float fConst62;
	float fRec3[3];
	float fConst64;
	float fConst65;
	float fConst66;
	float fRec2[3];
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fRec1[3];
	float fConst73;
	float fConst74;
	
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
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "MIT-style STK-4.3 license");
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
		float fConst1 = std::tan((8796.45898f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (fConst0 * std::sin((17592.918f / fConst0)));
		float fConst4 = (3518.58374f / fConst3);
		float fConst5 = (((fConst2 + fConst4) / fConst1) + 1.0f);
		fConst6 = (10.9125004f / fConst5);
		fConst7 = (2.0f * (1.0f - (1.0f / FaustViolinDSP_faustpower2_f(fConst1))));
		float fConst8 = (1727.87598f / fConst0);
		float fConst9 = std::tan(fConst8);
		float fConst10 = (1.0f / fConst9);
		float fConst11 = (fConst0 * std::sin((3455.75195f / fConst0)));
		float fConst12 = (345.575195f / fConst11);
		fConst13 = (1.0f / (((fConst10 + fConst12) / fConst9) + 1.0f));
		fConst14 = (2.0f * (1.0f - (1.0f / FaustViolinDSP_faustpower2_f(fConst9))));
		float fConst15 = std::tan((1382.30078f / fConst0));
		float fConst16 = (1.0f / fConst15);
		float fConst17 = (fConst0 * std::sin((2764.60156f / fConst0)));
		float fConst18 = (276.460144f / fConst17);
		fConst19 = (1.0f / (((fConst16 + fConst18) / fConst15) + 1.0f));
		fConst20 = (2.0f * (1.0f - (1.0f / FaustViolinDSP_faustpower2_f(fConst15))));
		float fConst21 = std::tan((863.937988f / fConst0));
		float fConst22 = (1.0f / fConst21);
		float fConst23 = (fConst0 * std::sin(fConst8));
		float fConst24 = (215.984497f / fConst23);
		fConst25 = (1.0f / (((fConst22 + fConst24) / fConst21) + 1.0f));
		fConst26 = (2.0f * (1.0f - (1.0f / FaustViolinDSP_faustpower2_f(fConst21))));
		float fConst27 = std::tan((1570.79639f / fConst0));
		float fConst28 = (1.0f / fConst27);
		float fConst29 = (((fConst28 + 0.5f) / fConst27) + 1.0f);
		fConst30 = (1.0f / (fConst27 * fConst29));
		fConst31 = (0.00882352982f * fConst0);
		fConst32 = (0.00147058826f * fConst0);
		fConst33 = (44.0999985f / fConst0);
		fConst34 = (1.0f - fConst33);
		float fConst35 = (1.0f / std::tan((6.28318548f / fConst0)));
		fConst36 = (1.0f / (fConst35 + 1.0f));
		fConst37 = (1.0f - fConst35);
		float fConst38 = (12.566371f / fConst0);
		fConst39 = std::sin(fConst38);
		fConst40 = std::cos(fConst38);
		fConst41 = (1.0f / fConst0);
		fConst42 = std::exp((0.0f - (6.66666651f / fConst0)));
		fConst43 = (1.0f - fConst42);
		fConst44 = std::exp((0.0f - (66.6666641f / fConst0)));
		fConst45 = (1.0f - fConst44);
		fConst46 = std::exp((0.0f - (25.0f / fConst0)));
		fConst47 = (1.0f - fConst46);
		float fConst48 = (1.0f / std::tan((37.6991119f / fConst0)));
		fConst49 = (1.0f / (fConst48 + 1.0f));
		fConst50 = (1.0f - fConst48);
		float fConst51 = (75.3982239f / fConst0);
		fConst52 = std::sin(fConst51);
		fConst53 = std::cos(fConst51);
		fConst54 = (1.0f / fConst29);
		fConst55 = (((fConst28 + -0.5f) / fConst27) + 1.0f);
		fConst56 = (2.0f * (1.0f - (1.0f / FaustViolinDSP_faustpower2_f(fConst27))));
		fConst57 = (0.0f - fConst30);
		fConst58 = (((fConst22 - fConst24) / fConst21) + 1.0f);
		float fConst59 = (430.945709f / fConst23);
		fConst60 = (((fConst22 + fConst59) / fConst21) + 1.0f);
		fConst61 = (((fConst22 - fConst59) / fConst21) + 1.0f);
		fConst62 = (((fConst16 - fConst18) / fConst15) + 1.0f);
		float fConst63 = (694.436523f / fConst17);
		fConst64 = (((fConst16 + fConst63) / fConst15) + 1.0f);
		fConst65 = (((fConst16 - fConst63) / fConst15) + 1.0f);
		fConst66 = (((fConst10 - fConst12) / fConst9) + 1.0f);
		float fConst67 = (973.963196f / fConst11);
		fConst68 = (((fConst10 + fConst67) / fConst9) + 1.0f);
		fConst69 = (((fConst10 - fConst67) / fConst9) + 1.0f);
		fConst70 = (1.0f / fConst5);
		fConst71 = (((fConst2 - fConst4) / fConst1) + 1.0f);
		float fConst72 = (6257.0249f / fConst3);
		fConst73 = (((fConst2 + fConst72) / fConst1) + 1.0f);
		fConst74 = (((fConst2 - fConst72) / fConst1) + 1.0f);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.14999999999999999f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(440.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.012f);
		fHslider6 = FAUSTFLOAT(5.5f);
		fHslider7 = FAUSTFLOAT(0.5f);
		fHslider8 = FAUSTFLOAT(0.45000000000000001f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec16[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec30[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec29[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec31[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec38[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec39[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec40[l8] = 0;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec37[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec36[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec35[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec34[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec33[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec32[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec41[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec42[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec43[l17] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec46[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec45[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec26[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec47[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 4); l24 = (l24 + 1)) {
			fRec48[l24] = 0.0f;
		}
		IOTA = 0;
		for (int l25 = 0; (l25 < 2048); l25 = (l25 + 1)) {
			fRec49[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fVec2[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec50[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec51[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec52[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec59[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec60[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec58[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec57[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec56[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec55[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec54[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec53[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2048); l38 = (l38 + 1)) {
			fVec3[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2048); l39 = (l39 + 1)) {
			fRec23[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec25[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 4); l41 = (l41 + 1)) {
			fRec22[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec20[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			iRec12[l43] = 0;
		}
		for (int l44 = 0; (l44 < 2048); l44 = (l44 + 1)) {
			fRec8[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec6[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec7[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec5[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec4[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec3[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec2[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec1[l51] = 0.0f;
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
		ui_interface->addHorizontalSlider("bowPosition", &fHslider2, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("bowPressure", &fHslider8, FAUSTFLOAT(0.449999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("bowVelocity", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("calibration", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-0.100000001f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(440.0f), FAUSTFLOAT(80.0f), FAUSTFLOAT(1400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider5, FAUSTFLOAT(0.0120000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider6, FAUSTFLOAT(5.5f), FAUSTFLOAT(3.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.970000029f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		int iSlow2 = (fSlow1 == 2.0f);
		int iSlow3 = (fSlow1 == 3.0f);
		float fSlow4 = (fConst33 * float(fHslider2));
		float fSlow5 = (fConst33 * float(fHslider3));
		float fSlow6 = (340.0f / float(fHslider4));
		float fSlow7 = float(fButton0);
		int iSlow8 = (fSlow1 == 1.0f);
		int iSlow9 = (fSlow1 == 4.0f);
		int iSlow10 = (iSlow8 | iSlow9);
		float fThen4 = (iSlow2 ? 0.0799999982f : 0.0350000001f);
		float fThen5 = (iSlow10 ? 0.0250000004f : 0.0450000018f);
		float fElse5 = (iSlow10 ? 0.00999999978f : fThen4);
		float fSlow11 = (int(fSlow7) ? fElse5 : fThen5);
		int iSlow12 = (std::fabs(fSlow11) < 1.1920929e-07f);
		float fThen7 = std::exp((0.0f - (fConst41 / (iSlow12 ? 1.0f : fSlow11))));
		float fSlow13 = (iSlow12 ? 0.0f : fThen7);
		float fSlow14 = (fSlow7 * (1.0f - fSlow13));
		float fSlow15 = (fConst33 * float(fHslider5));
		float fSlow16 = (fConst43 * fSlow7);
		float fSlow17 = (fConst33 * float(fHslider6));
		int iSlow18 = iSlow9;
		int iSlow19 = iSlow8;
		float fSlow20 = (fConst33 * float(fHslider7));
		float fSlow21 = (fConst33 * float(fHslider8));
		float fSlow22 = (fConst45 * fSlow7);
		float fSlow23 = (fConst47 * fSlow7);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			float fTempFTZ0 = (fSlow0 + (0.0299999993f * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec16[0] = 0;
			int iRec17 = iRec16[1];
			float fTempFTZ1 = (float(iRec12[1]) - (0.989264667f * ((0.600000024f * fRec22[2]) + (0.200000003f * (fRec22[1] + fRec22[3])))));
			float fRec21 = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow4 + (fConst34 * fRec30[1]));
			fRec30[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fThen1 = (iSlow3 ? 0.0399999991f : fRec30[0]);
			float fTempFTZ3 = ((fConst34 * fRec29[1]) + (fConst33 * (iSlow2 ? 0.280000001f : fThen1)));
			fRec29[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp0 = (1.0f - fRec29[0]);
			float fTempFTZ4 = (fSlow5 + (fConst34 * fRec31[1]));
			fRec31[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((fConst39 * fRec39[1]) + (fConst40 * fRec38[1]));
			fRec38[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp1 = float((1 - iVec0[1]));
			float fTempFTZ6 = ((fTemp1 + (fConst40 * fRec39[1])) - (fConst39 * fRec38[1]));
			fRec39[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			int iTemp2 = ((fRec38[1] <= 0.0f) & (fRec38[0] > 0.0f));
			iRec40[0] = ((1103515245 * iRec40[1]) + 12345);
			float fTemp3 = float(iRec40[0]);
			float fTempFTZ7 = ((fRec37[1] * float((1 - iTemp2))) + (4.65661287e-10f * (fTemp3 * float(iTemp2))));
			fRec37[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (0.0f - (fConst36 * ((fConst37 * fRec36[1]) - (fRec37[0] + fRec37[1]))));
			fRec36[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (0.0f - (fConst36 * ((fConst37 * fRec35[1]) - (fRec36[0] + fRec36[1]))));
			fRec35[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (0.0f - (fConst36 * ((fConst37 * fRec34[1]) - (fRec35[0] + fRec35[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (0.0f - (fConst36 * ((fConst37 * fRec33[1]) - (fRec34[0] + fRec34[1]))));
			fRec33[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (0.0f - (fConst36 * ((fConst37 * fRec32[1]) - (fRec33[0] + fRec33[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = ((fRec41[1] * fSlow13) + fSlow14);
			fRec41[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp4 = (0.00120000006f * (fRec32[0] * fRec41[0]));
			float fTempFTZ14 = (fSlow15 + (fConst34 * fRec42[1]));
			fRec42[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fSlow16 + (fConst42 * fRec43[1]));
			fRec43[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fSlow17 + (fConst34 * fRec46[1]));
			fRec46[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp5 = (fRec45[1] + (fConst41 * fRec46[0]));
			float fTempFTZ17 = (fTemp5 - std::floor(fTemp5));
			fRec45[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp6 = ((fRec42[0] * fRec43[0]) * ftbl0FaustViolinDSPSIG0[int((65536.0f * fRec45[0]))]);
			float fTemp7 = ((fRec31[0] + (fSlow6 / ((fTemp4 + fTemp6) + 1.0f))) + -0.0799999982f);
			int iTemp8 = int(((fConst32 * (fTemp0 * fTemp7)) + -1.49999499f));
			float fTemp9 = ((fRec31[0] + (fSlow6 / ((fTemp4 + 1.0f) + fTemp6))) + -0.0799999982f);
			float fTemp10 = (fConst32 * (fTemp0 * fTemp9));
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
			float fTempFTZ18 = (((((fRec8[((IOTA - (int(std::min<float>(fConst31, float(std::max<int>(0, int(iTemp8))))) + 1)) & 2047)] * fTemp14) * fTemp16) * fTemp18) * fTemp20) + (fTemp21 * ((((((fRec8[((IOTA - (int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp8 + 1)))))) + 1)) & 2047)] * fTemp22) * fTemp23) * fTemp24) + (0.5f * (((fTemp13 * fRec8[((IOTA - (int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp8 + 2)))))) + 1)) & 2047)]) * fTemp25) * fTemp26))) + (0.166666672f * ((fTemp27 * fRec8[((IOTA - (int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp8 + 3)))))) + 1)) & 2047)]) * fTemp28))) + (0.0416666679f * (fTemp29 * fRec8[((IOTA - (int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp8 + 4)))))) + 1)) & 2047)])))));
			fRec26[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fSlow20 + (fConst34 * fRec47[1]));
			fRec47[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fThen9 = (iSlow19 ? 0.699999988f : fRec47[0]);
			float fThen10 = (iSlow18 ? 0.400000006f : fThen9);
			float fTempFTZ20 = fRec6[1];
			fRec48[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (-1.0f * (0.99880147f * ((0.800000012f * fRec48[2]) + (0.100000001f * (fRec48[1] + fRec48[3])))));
			fRec49[(IOTA & 2047)] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			int iTemp30 = int(((fConst32 * (fRec29[0] * fTemp7)) + -1.49999499f));
			int iTemp31 = int(std::min<float>(fConst31, float(std::max<int>(0, int(iTemp30)))));
			float fTemp32 = (fConst32 * (fRec29[0] * fTemp9));
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
			int iTemp43 = int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp30 + 1))))));
			float fTemp44 = (0.0f - fTemp36);
			float fTemp45 = (0.0f - (0.5f * fTemp38));
			float fTemp46 = (0.0f - (0.333333343f * fTemp40));
			int iTemp47 = int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp30 + 2))))));
			float fTemp48 = (0.0f - fTemp38);
			float fTemp49 = (0.0f - (0.5f * fTemp40));
			float fTemp50 = (fTemp34 * fTemp36);
			int iTemp51 = int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp30 + 3))))));
			float fTemp52 = (0.0f - fTemp40);
			float fTemp53 = (fTemp50 * fTemp38);
			int iTemp54 = int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp30 + 4))))));
			fVec2[0] = (((((fRec49[((IOTA - (iTemp31 + 2)) & 2047)] * fTemp35) * fTemp37) * fTemp39) * fTemp41) + (fTemp42 * ((((((fRec49[((IOTA - (iTemp43 + 2)) & 2047)] * fTemp44) * fTemp45) * fTemp46) + (0.5f * (((fTemp34 * fRec49[((IOTA - (iTemp47 + 2)) & 2047)]) * fTemp48) * fTemp49))) + (0.166666672f * ((fTemp50 * fRec49[((IOTA - (iTemp51 + 2)) & 2047)]) * fTemp52))) + (0.0416666679f * (fTemp53 * fRec49[((IOTA - (iTemp54 + 2)) & 2047)])))));
			float fTemp55 = ((0.200000003f * (fRec41[0] * (iSlow2 ? 0.600000024f : fThen10))) - (fRec26[1] + fVec2[1]));
			float fTempFTZ22 = (fSlow21 + (fConst34 * fRec50[1]));
			fRec50[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fThen12 = (iSlow19 ? 0.550000012f : fRec50[0]);
			float fThen13 = (iSlow3 ? 0.649999976f : fThen12);
			float fTempFTZ23 = (fSlow22 + (fConst44 * fRec51[1]));
			fRec51[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fSlow23 + (fConst46 * fRec52[1]));
			fRec52[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fElse14 = (0.349999994f * (fRec51[0] * (1.0f - fRec52[0])));
			float fTempFTZ25 = ((fConst52 * fRec60[1]) + (fConst53 * fRec59[1]));
			fRec59[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = ((fTemp1 + (fConst53 * fRec60[1])) - (fConst52 * fRec59[1]));
			fRec60[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			int iTemp56 = ((fRec59[1] <= 0.0f) & (fRec59[0] > 0.0f));
			float fTempFTZ27 = ((fRec58[1] * float((1 - iTemp56))) + (4.65661287e-10f * (fTemp3 * float(iTemp56))));
			fRec58[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (0.0f - (fConst49 * ((fConst50 * fRec57[1]) - (fRec58[0] + fRec58[1]))));
			fRec57[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (0.0f - (fConst49 * ((fConst50 * fRec56[1]) - (fRec57[0] + fRec57[1]))));
			fRec56[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (0.0f - (fConst49 * ((fConst50 * fRec55[1]) - (fRec56[0] + fRec56[1]))));
			fRec55[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (0.0f - (fConst49 * ((fConst50 * fRec54[1]) - (fRec55[0] + fRec55[1]))));
			fRec54[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (0.0f - (fConst49 * ((fConst50 * fRec53[1]) - (fRec54[0] + fRec54[1]))));
			fRec53[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTemp57 = (fTemp55 * std::min<float>(1.0f, (1.0f / FaustViolinDSP_faustpower4_f((std::fabs((fTemp55 * (5.0f - (4.0f * ((fRec41[0] * ((iSlow2 ? 0.219999999f : fThen13) + (iSlow10 ? fElse14 : 0.0f))) * ((0.0120000001f * (fRec41[0] * fRec53[0])) + 0.200000003f)))))) + 0.75f)))));
			float fTempFTZ33 = (fRec26[1] + fTemp57);
			float fRec27 = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTemp58 = (fVec2[1] + fTemp57);
			fVec3[(IOTA & 2047)] = fTemp58;
			int iTemp59 = int(fTemp11);
			float fTempFTZ34 = (((((fTemp14 * fTemp16) * fTemp18) * fTemp20) * fVec3[((IOTA - int(std::min<float>(fConst31, float(std::max<int>(0, int(iTemp59)))))) & 2047)]) + (fTemp21 * ((((((fTemp22 * fTemp23) * fTemp24) * fVec3[((IOTA - int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp59 + 1))))))) & 2047)]) + (0.5f * (((fTemp13 * fTemp25) * fTemp26) * fVec3[((IOTA - int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp59 + 2))))))) & 2047)]))) + (0.166666672f * ((fTemp27 * fTemp28) * fVec3[((IOTA - int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp59 + 3))))))) & 2047)]))) + (0.0416666679f * (fTemp29 * fVec3[((IOTA - int(std::min<float>(fConst31, float(std::max<int>(0, int((iTemp59 + 4))))))) & 2047)])))));
			float fRec28 = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = fRec27;
			fRec23[(IOTA & 2047)] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (((((fTemp35 * fTemp37) * fTemp39) * fTemp41) * fRec23[((IOTA - (iTemp31 + 1)) & 2047)]) + (fTemp42 * ((((((fTemp44 * fTemp45) * fTemp46) * fRec23[((IOTA - (iTemp43 + 1)) & 2047)]) + (0.5f * (((fTemp34 * fTemp48) * fTemp49) * fRec23[((IOTA - (iTemp47 + 1)) & 2047)]))) + (0.166666672f * ((fTemp50 * fTemp52) * fRec23[((IOTA - (iTemp51 + 1)) & 2047)]))) + (0.0416666679f * (fTemp53 * fRec23[((IOTA - (iTemp54 + 1)) & 2047)])))));
			float fRec24 = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = fRec28;
			fRec25[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec25[1];
			fRec22[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fRec22[1] - (fConst54 * ((fConst55 * fRec20[2]) + (fConst56 * fRec20[1]))));
			fRec20[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = ((fConst30 * fRec20[0]) + (fConst57 * fRec20[2]));
			float fTemp60 = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fRec18 = fTemp60;
			float fRec19 = fTemp60;
			iRec12[0] = iRec17;
			float fTempFTZ41 = fRec21;
			float fRec13 = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = fRec18;
			float fRec14 = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = fRec19;
			float fRec15 = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = fRec13;
			fRec8[(IOTA & 2047)] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = fRec24;
			float fRec9 = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = fRec14;
			float fRec10 = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = fRec15;
			float fRec11 = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = fRec9;
			fRec6[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = fRec11;
			fRec7[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = ((fRec7[0] + (0.995000005f * fRec5[1])) - fRec7[1]);
			fRec5[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTemp61 = (fConst26 * fRec4[1]);
			float fTempFTZ51 = (std::max<float>(-1.0f, std::min<float>(1.0f, fRec5[0])) - (fConst25 * ((fConst58 * fRec4[2]) + fTemp61)));
			fRec4[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTemp62 = (fConst20 * fRec3[1]);
			float fTempFTZ52 = ((fConst25 * ((fTemp61 + (fConst60 * fRec4[0])) + (fConst61 * fRec4[2]))) - (fConst19 * ((fConst62 * fRec3[2]) + fTemp62)));
			fRec3[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTemp63 = (fConst14 * fRec2[1]);
			float fTempFTZ53 = ((fConst19 * ((fTemp62 + (fConst64 * fRec3[0])) + (fConst65 * fRec3[2]))) - (fConst13 * ((fConst66 * fRec2[2]) + fTemp63)));
			fRec2[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTemp64 = (fConst7 * fRec1[1]);
			float fTempFTZ54 = ((fConst13 * ((fTemp63 + (fConst68 * fRec2[0])) + (fConst69 * fRec2[2]))) - (fConst70 * ((fConst71 * fRec1[2]) + fTemp64)));
			fRec1[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			output0[i0] = FAUSTFLOAT((fConst6 * (fRec0[0] * ((fTemp64 + (fConst73 * fRec1[0])) + (fConst74 * fRec1[2])))));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			iRec16[1] = iRec16[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec31[1] = fRec31[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			iRec40[1] = iRec40[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec26[1] = fRec26[0];
			fRec47[1] = fRec47[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec48[j0] = fRec48[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec59[1] = fRec59[0];
			fRec60[1] = fRec60[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec25[1] = fRec25[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec22[j1] = fRec22[(j1 - 1)];
			}
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			iRec12[1] = iRec12[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
