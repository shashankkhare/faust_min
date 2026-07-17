/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "sitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSitarDSP_H__
#define  __FaustSitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustSitarDSPSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec8[2];
	
  public:
	
	int getNumInputsFaustSitarDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSitarDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSitarDSPSIG0(int sample_rate) {
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec8[l5] = 0;
		}
	}
	
	void fillFaustSitarDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec2[0] = 1;
			iRec8[0] = ((iVec2[1] + iRec8[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec8[0])));
			iVec2[1] = iVec2[0];
			iRec8[1] = iRec8[0];
		}
	}

};

static FaustSitarDSPSIG0* newFaustSitarDSPSIG0() { return (FaustSitarDSPSIG0*)new FaustSitarDSPSIG0(); }
static void deleteFaustSitarDSPSIG0(FaustSitarDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustSitarDSPSIG0[65536];
static float FaustSitarDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustSitarDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSitarDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst5;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	int iRec5[2];
	float fConst10;
	float fRec4[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fConst11;
	FAUSTFLOAT fHslider7;
	float fRec9[2];
	float fVec3[2];
	float fRec7[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	float fConst15;
	FAUSTFLOAT fHslider10;
	float fConst17;
	float fConst20;
	int iRec12[2];
	float fConst21;
	float fConst22;
	float fRec11[3];
	float fConst23;
	float fConst24;
	float fRec10[3];
	float fConst25;
	int IOTA;
	float fVec4[4096];
	float fRec6[2048];
	float fConst26;
	float fConst27;
	float fRec13[2];
	float fRec14[2];
	FAUSTFLOAT fHslider11;
	float fConst28;
	float fVec5[2];
	float fRec17[2];
	float fVec6[2048];
	float fRec16[2048];
	float fRec15[2];
	float fConst29;
	float fRec18[2];
	float fVec7[2];
	float fRec20[2];
	float fVec8[2048];
	float fRec19[2048];
	float fRec21[2];
	float fConst30;
	float fRec22[2];
	float fVec9[2];
	float fRec23[2];
	float fVec10[512];
	float fRec3[2048];
	float fRec2[2];
	float fRec24[2];
	float fVec11[2];
	float fRec27[2];
	float fVec12[1024];
	float fRec26[2048];
	float fRec25[2];
	float fRec28[2];
	float fVec13[2];
	float fRec30[2];
	float fVec14[1024];
	float fRec29[2048];
	float fRec31[2];
	float fRec32[2];
	float fVec15[2];
	float fRec1[2];
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec0[3];
	float fConst38;
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec33[3];
	float fConst42;
	float fConst47;
	float fConst48;
	float fConst49;
	float fConst50;
	float fRec34[3];
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec35[3];
	float fConst59;
	float fConst60;
	float fConst64;
	float fConst65;
	float fConst66;
	float fConst67;
	float fConst68;
	float fRec36[3];
	float fConst72;
	float fConst73;
	float fConst74;
	float fConst75;
	float fConst76;
	float fRec37[3];
	float fConst77;
	
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
		m->declare("filename", "sitar.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "sitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		FaustSitarDSPSIG0* sig0 = newFaustSitarDSPSIG0();
		sig0->instanceInitFaustSitarDSPSIG0(sample_rate);
		sig0->fillFaustSitarDSPSIG0(65536, ftbl0FaustSitarDSPSIG0);
		deleteFaustSitarDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((785.398193f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.200000003f) / fConst1) + 1.0f);
		float fConst4 = (fConst1 * fConst3);
		fConst5 = (1.0f / fConst4);
		fConst6 = (44.0999985f / fConst0);
		fConst7 = (1.0f - fConst6);
		fConst8 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f / std::max<float>(1.0f, (0.00800000038f * fConst0)));
		fConst11 = (1.0f / fConst0);
		float fConst12 = std::tan((188.49556f / fConst0));
		float fConst13 = (1.0f / fConst12);
		float fConst14 = (((fConst13 + 1.41421354f) / fConst12) + 1.0f);
		fConst15 = (1.0f / fConst14);
		float fConst16 = FaustSitarDSP_faustpower2_f(fConst12);
		fConst17 = (1.0f / fConst16);
		float fConst18 = std::tan((18849.5566f / fConst0));
		float fConst19 = (1.0f / fConst18);
		fConst20 = (1.0f / (((fConst19 + 1.41421354f) / fConst18) + 1.0f));
		fConst21 = (((fConst19 + -1.41421354f) / fConst18) + 1.0f);
		fConst22 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst18))));
		fConst23 = (((fConst13 + -1.41421354f) / fConst12) + 1.0f);
		fConst24 = (2.0f * (1.0f - fConst17));
		fConst25 = (0.0f - (2.0f / fConst16));
		fConst26 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst27 = (1.0f - fConst26);
		fConst28 = (0.349999994f / fConst14);
		fConst29 = (3.0f / fConst0);
		fConst30 = (2.0f / fConst0);
		fConst31 = (1.0f / fConst3);
		fConst32 = (((fConst2 + -0.200000003f) / fConst1) + 1.0f);
		fConst33 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst1))));
		float fConst34 = std::tan((11309.7334f / fConst0));
		float fConst35 = (1.0f / fConst34);
		float fConst36 = (((fConst35 + 0.333333343f) / fConst34) + 1.0f);
		float fConst37 = (fConst34 * fConst36);
		fConst38 = (1.0f / fConst37);
		fConst39 = (1.0f / fConst36);
		fConst40 = (((fConst35 + -0.333333343f) / fConst34) + 1.0f);
		fConst41 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst34))));
		fConst42 = (0.0f - (0.400000006f / fConst37));
		float fConst43 = std::tan((4398.22949f / fConst0));
		float fConst44 = (1.0f / fConst43);
		float fConst45 = (((fConst44 + 0.333333343f) / fConst43) + 1.0f);
		float fConst46 = (fConst43 * fConst45);
		fConst47 = (1.0f / fConst46);
		fConst48 = (1.0f / fConst45);
		fConst49 = (((fConst44 + -0.333333343f) / fConst43) + 1.0f);
		fConst50 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst43))));
		float fConst51 = std::tan((6911.50391f / fConst0));
		float fConst52 = (1.0f / fConst51);
		float fConst53 = (((fConst52 + 0.285714298f) / fConst51) + 1.0f);
		float fConst54 = (fConst51 * fConst53);
		fConst55 = (1.0f / fConst54);
		fConst56 = (1.0f / fConst53);
		fConst57 = (((fConst52 + -0.285714298f) / fConst51) + 1.0f);
		fConst58 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst51))));
		fConst59 = (0.0f - (0.699999988f / fConst54));
		fConst60 = (0.0f - (0.699999988f / fConst46));
		float fConst61 = std::tan((2827.43335f / fConst0));
		float fConst62 = (1.0f / fConst61);
		float fConst63 = (((fConst62 + 0.285714298f) / fConst61) + 1.0f);
		fConst64 = (0.800000012f / (fConst61 * fConst63));
		fConst65 = (0.0f - fConst64);
		fConst66 = (1.0f / fConst63);
		fConst67 = (((fConst62 + -0.285714298f) / fConst61) + 1.0f);
		fConst68 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst61))));
		float fConst69 = std::tan((1413.71667f / fConst0));
		float fConst70 = (1.0f / fConst69);
		float fConst71 = (((fConst70 + 0.25f) / fConst69) + 1.0f);
		fConst72 = (0.5f / (fConst69 * fConst71));
		fConst73 = (0.0f - fConst72);
		fConst74 = (1.0f / fConst71);
		fConst75 = (((fConst70 + -0.25f) / fConst69) + 1.0f);
		fConst76 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst69))));
		fConst77 = (0.0f - (0.400000006f / fConst4));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.29999999999999999f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.34999999999999998f);
		fHslider3 = FAUSTFLOAT(1.2f);
		fHslider4 = FAUSTFLOAT(138.59999999999999f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.01f);
		fHslider7 = FAUSTFLOAT(4.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(5.0f);
		fHslider10 = FAUSTFLOAT(0.59999999999999998f);
		fHslider11 = FAUSTFLOAT(111.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec5[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec9[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec12[l9] = 0;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec11[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		IOTA = 0;
		for (int l12 = 0; (l12 < 4096); l12 = (l12 + 1)) {
			fVec4[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2048); l13 = (l13 + 1)) {
			fRec6[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fVec5[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec17[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2048); l18 = (l18 + 1)) {
			fVec6[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2048); l19 = (l19 + 1)) {
			fRec16[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec15[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec18[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fVec7[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec20[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2048); l24 = (l24 + 1)) {
			fVec8[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2048); l25 = (l25 + 1)) {
			fRec19[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec21[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec22[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fVec9[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec23[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 512); l30 = (l30 + 1)) {
			fVec10[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2048); l31 = (l31 + 1)) {
			fRec3[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec2[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec24[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fVec11[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec27[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 1024); l36 = (l36 + 1)) {
			fVec12[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2048); l37 = (l37 + 1)) {
			fRec26[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec25[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec28[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fVec13[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec30[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 1024); l42 = (l42 + 1)) {
			fVec14[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2048); l43 = (l43 + 1)) {
			fRec29[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec31[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec32[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fVec15[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec1[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec0[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec33[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec34[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec35[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec36[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec37[l53] = 0.0f;
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
	
	virtual FaustSitarDSP* clone() {
		return new FaustSitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("sitar");
		ui_interface->declare(&fHslider11, "unit", "Hz");
		ui_interface->addHorizontalSlider("chikari_freq", &fHslider11, FAUSTFLOAT(111.0f), FAUSTFLOAT(55.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(138.600006f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.349999994f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("strike", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider9, "unit", "s");
		ui_interface->addHorizontalSlider("sustain", &fHslider9, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("symp_drift", &fHslider3, FAUSTFLOAT(1.20000005f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider10, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider5, "style", "check");
		ui_interface->addHorizontalSlider("vibrato", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider6, FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider7, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (7.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		float fSlow3 = float(fHslider3);
		float fSlow4 = float(fHslider4);
		float fSlow5 = std::max<float>(((0.5f * fSlow3) + (3.0f * fSlow4)), 40.0f);
		float fSlow6 = std::max<float>(40.0f, fSlow5);
		float fSlow7 = (607.5f * (fSlow2 / fSlow6));
		float fSlow8 = float(fButton0);
		float fSlow9 = (float(fHslider5) * float(fHslider6));
		float fSlow10 = (fConst11 * float(fHslider7));
		float fSlow11 = float(fHslider8);
		int iSlow12 = (fSlow11 == 2.0f);
		int iSlow13 = iSlow12;
		float fSlow14 = (iSlow13 ? 1.39999998f : 1.0f);
		float fSlow15 = (((20.0f * fSlow2) * fSlow14) + 1.0f);
		float fSlow16 = (((2.0f * fSlow2) * fSlow14) + 1.0f);
		float fSlow17 = float(fHslider9);
		float fSlow18 = std::max<float>(0.400000006f, (fSlow17 * (1.0f - ((0.349999994f * fSlow2) * fSlow14))));
		float fSlow19 = float(fHslider10);
		float fSlow20 = (fConst15 * (fSlow19 * float((iSlow12 + (fSlow11 == 0.0f)))));
		float fSlow21 = (iSlow13 ? 0.649999976f : 0.400000006f);
		float fSlow22 = (1350.0f * fSlow2);
		float fSlow23 = (fConst11 * fSlow4);
		float fSlow24 = float(fHslider11);
		float fSlow25 = std::max<float>(40.0f, (3.0f * fSlow24));
		float fSlow26 = (945.0f * (fSlow2 / fSlow25));
		float fSlow27 = (fConst28 * (fSlow19 * float((fSlow11 == 1.0f))));
		float fSlow28 = std::max<float>(0.400000006f, (1.79999995f * (1.0f - (0.245000005f * fSlow2))));
		float fSlow29 = std::pow(0.00100000005f, (1.0f / (fSlow25 * fSlow28)));
		float fSlow30 = (fConst0 / fSlow25);
		int iSlow31 = int(fSlow30);
		float fSlow32 = float(iSlow31);
		float fSlow33 = (fSlow30 + (-0.499989986f - fSlow32));
		int iSlow34 = (std::min<int>(1024, std::max<int>(0, int(fSlow33))) + 1);
		float fSlow35 = (fSlow32 + std::floor(fSlow33));
		float fSlow36 = ((fSlow35 + (1.0f - fSlow30)) / (fSlow30 + (1.0f - fSlow35)));
		float fSlow37 = ((14.0f * fSlow2) + 1.0f);
		float fSlow38 = (1.0f / fSlow37);
		float fSlow39 = ((1.39999998f * fSlow2) + 1.0f);
		float fSlow40 = (1.0f / fSlow39);
		int iSlow41 = std::min<int>(16384, std::max<int>(0, iSlow31));
		float fSlow42 = (fConst29 * fSlow24);
		float fSlow43 = std::max<float>(40.0f, (2.0f * fSlow24));
		float fSlow44 = std::pow(0.00100000005f, (1.0f / (fSlow28 * fSlow43)));
		float fSlow45 = (fConst0 / fSlow43);
		int iSlow46 = int(fSlow45);
		float fSlow47 = float(iSlow46);
		float fSlow48 = (fSlow45 + (-0.499989986f - fSlow47));
		int iSlow49 = (std::min<int>(1024, std::max<int>(0, int(fSlow48))) + 1);
		float fSlow50 = (fSlow47 + std::floor(fSlow48));
		float fSlow51 = ((fSlow50 + (1.0f - fSlow45)) / (fSlow45 + (1.0f - fSlow50)));
		int iSlow52 = std::min<int>(16384, std::max<int>(0, iSlow46));
		float fSlow53 = (945.0f * (fSlow2 / fSlow43));
		float fSlow54 = (fConst30 * fSlow24);
		float fSlow55 = std::max<float>(0.400000006f, (1.5f * (fSlow17 * (1.0f - (0.157499999f * fSlow2)))));
		float fSlow56 = std::pow(0.00100000005f, (1.0f / (fSlow6 * fSlow55)));
		float fSlow57 = (fConst0 / fSlow6);
		int iSlow58 = int(fSlow57);
		float fSlow59 = float(iSlow58);
		float fSlow60 = (fSlow57 + (-0.499989986f - fSlow59));
		int iSlow61 = (std::min<int>(1024, std::max<int>(0, int(fSlow60))) + 1);
		float fSlow62 = (fSlow59 + std::floor(fSlow60));
		float fSlow63 = ((fSlow62 + (1.0f - fSlow57)) / (fSlow57 + (1.0f - fSlow62)));
		float fSlow64 = ((9.0f * fSlow2) + 1.0f);
		float fSlow65 = (1.0f / fSlow64);
		float fSlow66 = ((0.899999976f * fSlow2) + 1.0f);
		float fSlow67 = (1.0f / fSlow66);
		int iSlow68 = std::min<int>(16384, std::max<int>(0, iSlow58));
		float fSlow69 = (fConst11 * fSlow5);
		float fSlow70 = std::max<float>(((2.0f * fSlow4) - (0.400000006f * fSlow3)), 40.0f);
		float fSlow71 = std::max<float>(40.0f, fSlow70);
		float fSlow72 = (607.5f * (fSlow2 / fSlow71));
		float fSlow73 = std::pow(0.00100000005f, (1.0f / (fSlow55 * fSlow71)));
		float fSlow74 = (fConst0 / fSlow71);
		int iSlow75 = int(fSlow74);
		float fSlow76 = float(iSlow75);
		float fSlow77 = (fSlow74 + (-0.499989986f - fSlow76));
		int iSlow78 = (std::min<int>(1024, std::max<int>(0, int(fSlow77))) + 1);
		float fSlow79 = (fSlow76 + std::floor(fSlow77));
		float fSlow80 = ((fSlow79 + (1.0f - fSlow74)) / (fSlow74 + (1.0f - fSlow79)));
		int iSlow81 = std::min<int>(16384, std::max<int>(0, iSlow75));
		float fSlow82 = (fConst11 * fSlow70);
		float fSlow83 = std::max<float>(((0.600000024f * fSlow3) + (1.5f * fSlow4)), 40.0f);
		float fSlow84 = std::max<float>(40.0f, fSlow83);
		float fSlow85 = std::pow(0.00100000005f, (1.0f / (fSlow55 * fSlow84)));
		float fSlow86 = (fConst0 / fSlow84);
		int iSlow87 = int(fSlow86);
		float fSlow88 = float(iSlow87);
		float fSlow89 = (fSlow86 + (-0.499989986f - fSlow88));
		int iSlow90 = (std::min<int>(1024, std::max<int>(0, int(fSlow89))) + 1);
		float fSlow91 = (fSlow88 + std::floor(fSlow89));
		float fSlow92 = ((fSlow91 + (1.0f - fSlow86)) / (fSlow86 + (1.0f - fSlow91)));
		int iSlow93 = std::min<int>(16384, std::max<int>(0, iSlow87));
		float fSlow94 = (607.5f * (fSlow2 / fSlow84));
		float fSlow95 = (fConst11 * fSlow83);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow8;
			int iTemp0 = (fSlow8 > fVec0[1]);
			iVec1[0] = iTemp0;
			iRec5[0] = ((iTemp0 > iVec1[1]) + ((iTemp0 <= iVec1[1]) * (iRec5[1] + (iRec5[1] > 0))));
			float fTemp1 = float(iRec5[0]);
			float fTemp2 = std::max<float>(0.0f, std::min<float>((fConst9 * fTemp1), (1.0f - (fConst10 * (fTemp1 - fConst8)))));
			float fTempFTZ0 = ((fConst7 * fRec4[1]) + (fConst6 * fTemp2));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow10 + (fRec9[1] - std::floor((fSlow10 + fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp3 = ((fSlow9 * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec9[0]))]) + 1.0f);
			float fTemp4 = std::max<float>(40.0f, (fSlow4 * fTemp3));
			float fTemp5 = (fConst0 / fTemp4);
			int iTemp6 = int(fTemp5);
			float fTemp7 = float(iTemp6);
			float fTemp8 = (fTemp5 + (-0.499989986f - fTemp7));
			float fTemp9 = fRec6[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp8))) + 1)) & 2047)];
			fVec3[0] = fTemp9;
			float fTemp10 = (fTemp7 + std::floor(fTemp8));
			float fTempFTZ2 = (fVec3[1] - (((fTemp10 + (1.0f - fTemp5)) * (fRec7[1] - fTemp9)) / (fTemp5 + (1.0f - fTemp10))));
			fRec7[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp11 = ((0.00200000009f * fRec7[0]) + (0.998000026f * fRec7[1]));
			float fThen1 = (float(tanhf(float((fTemp11 * fSlow15)))) / fSlow15);
			float fElse1 = (float(tanhf(float((fTemp11 * fSlow16)))) / fSlow16);
			iRec12[0] = ((1103515245 * iRec12[1]) + 12345);
			float fTempFTZ3 = ((4.65661287e-10f * float(iRec12[0])) - (fConst20 * ((fConst21 * fRec11[2]) + (fConst22 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((fConst20 * (fRec11[2] + (fRec11[0] + (2.0f * fRec11[1])))) - (fConst15 * ((fConst23 * fRec10[2]) + (fConst24 * fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp12 = (((fConst17 * fRec10[0]) + (fConst25 * fRec10[1])) + (fConst17 * fRec10[2]));
			fVec4[(IOTA & 4095)] = ((((fTemp11 > 0.0f) ? fElse1 : fThen1) * std::pow(0.00100000005f, (1.0f / (fTemp4 * fSlow18)))) + (fSlow20 * ((fSlow21 * fTemp12) * fTemp2)));
			float fTempFTZ5 = fVec4[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp6))) & 4095)];
			fRec6[(IOTA & 2047)] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp13 = std::fabs(fRec6[((IOTA - 0) & 2047)]);
			float fTempFTZ6 = std::max<float>(fTemp13, ((fConst26 * fRec13[1]) + (fConst27 * fTemp13)));
			fRec13[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp14 = (fRec14[1] + (fSlow23 * fTemp3));
			float fTempFTZ7 = (fTemp14 - std::floor(fTemp14));
			fRec14[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp15 = std::max<float>(1.0f, ((fSlow22 * (((fRec13[0] * fSlow14) * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec14[0]))]) / fTemp4)) + 4.0f));
			float fTemp16 = (fTemp15 + 4.99999987e-06f);
			int iTemp17 = int(fTemp16);
			float fTemp18 = std::floor(fTemp16);
			float fTemp19 = (fRec6[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp17))))) & 2047)] * (0.0f - (fTemp15 + (-1.0f - fTemp18))));
			float fTemp20 = ((fTemp15 - fTemp18) * fRec6[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp17 + 1)))))) & 2047)]);
			float fTemp21 = (fSlow27 * (fTemp12 * fTemp2));
			float fTemp22 = fRec16[((IOTA - iSlow34) & 2047)];
			fVec5[0] = fTemp22;
			float fTempFTZ8 = (fVec5[1] - (fSlow36 * (fRec17[1] - fTemp22)));
			fRec17[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp23 = ((0.00200000009f * fRec17[0]) + (0.998000026f * fRec17[1]));
			float fThen3 = (fSlow38 * float(tanhf(float((fSlow37 * fTemp23)))));
			float fElse3 = (fSlow40 * float(tanhf(float((fSlow39 * fTemp23)))));
			fVec6[(IOTA & 2047)] = (fTemp21 + (fSlow29 * ((fTemp23 > 0.0f) ? fElse3 : fThen3)));
			float fTempFTZ9 = fVec6[((IOTA - iSlow41) & 2047)];
			fRec16[(IOTA & 2047)] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp24 = std::fabs(fRec16[((IOTA - 0) & 2047)]);
			float fTempFTZ10 = std::max<float>(fTemp24, ((fConst26 * fRec15[1]) + (fConst27 * fTemp24)));
			fRec15[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fSlow42 + (fRec18[1] - std::floor((fSlow42 + fRec18[1]))));
			fRec18[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp25 = std::max<float>(1.0f, ((fSlow26 * (fRec15[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec18[0]))])) + 4.0f));
			float fTemp26 = (fTemp25 + 4.99999987e-06f);
			float fTemp27 = std::floor(fTemp26);
			int iTemp28 = int(fTemp26);
			float fTemp29 = fRec19[((IOTA - iSlow49) & 2047)];
			fVec7[0] = fTemp29;
			float fTempFTZ12 = (fVec7[1] - (fSlow51 * (fRec20[1] - fTemp29)));
			fRec20[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp30 = ((0.00200000009f * fRec20[0]) + (0.998000026f * fRec20[1]));
			float fThen4 = (fSlow38 * float(tanhf(float((fSlow37 * fTemp30)))));
			float fElse4 = (fSlow40 * float(tanhf(float((fSlow39 * fTemp30)))));
			fVec8[(IOTA & 2047)] = ((fSlow44 * ((fTemp30 > 0.0f) ? fElse4 : fThen4)) + fTemp21);
			float fTempFTZ13 = fVec8[((IOTA - iSlow52) & 2047)];
			fRec19[(IOTA & 2047)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp31 = std::fabs(fRec19[((IOTA - 0) & 2047)]);
			float fTempFTZ14 = std::max<float>(fTemp31, ((fConst26 * fRec21[1]) + (fConst27 * fTemp31)));
			fRec21[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fSlow54 + (fRec22[1] - std::floor((fSlow54 + fRec22[1]))));
			fRec22[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp32 = std::max<float>(1.0f, ((fSlow53 * (fRec21[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec22[0]))])) + 4.0f));
			float fTemp33 = (fTemp32 + 4.99999987e-06f);
			int iTemp34 = int(fTemp33);
			float fTemp35 = std::floor(fTemp33);
			float fTemp36 = (0.5f * (((fTemp25 - fTemp27) * fRec16[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp28 + 1)))))) & 2047)]) + (((fRec19[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp34))))) & 2047)] * (0.0f - (fTemp32 + (-1.0f - fTemp35)))) + ((fTemp32 - fTemp35) * fRec19[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp34 + 1)))))) & 2047)])) + (fRec16[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp28))))) & 2047)] * (0.0f - (fTemp25 + (-1.0f - fTemp27)))))));
			float fTemp37 = ((fTemp19 + fTemp20) + fTemp36);
			float fTemp38 = (0.349999994f * (fRec4[0] * fTemp37));
			float fTemp39 = fRec3[((IOTA - iSlow61) & 2047)];
			fVec9[0] = fTemp39;
			float fTempFTZ16 = (fVec9[1] - (fSlow63 * (fRec23[1] - fTemp39)));
			fRec23[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp40 = ((0.00200000009f * fRec23[0]) + (0.998000026f * fRec23[1]));
			float fThen5 = (fSlow65 * float(tanhf(float((fSlow64 * fTemp40)))));
			float fElse5 = (fSlow67 * float(tanhf(float((fSlow66 * fTemp40)))));
			fVec10[(IOTA & 511)] = (fTemp38 + (fSlow56 * ((fTemp40 > 0.0f) ? fElse5 : fThen5)));
			float fTempFTZ17 = fVec10[((IOTA - iSlow68) & 511)];
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp41 = std::fabs(fRec3[((IOTA - 0) & 2047)]);
			float fTempFTZ18 = std::max<float>(fTemp41, ((fConst26 * fRec2[1]) + (fConst27 * fTemp41)));
			fRec2[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fSlow69 + (fRec24[1] - std::floor((fSlow69 + fRec24[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp42 = std::max<float>(1.0f, ((fSlow7 * (fRec2[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec24[0]))])) + 4.0f));
			float fTemp43 = (fTemp42 + 4.99999987e-06f);
			float fTemp44 = std::floor(fTemp43);
			int iTemp45 = int(fTemp43);
			float fTemp46 = fRec26[((IOTA - iSlow78) & 2047)];
			fVec11[0] = fTemp46;
			float fTempFTZ20 = (fVec11[1] - (fSlow80 * (fRec27[1] - fTemp46)));
			fRec27[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp47 = ((0.00200000009f * fRec27[0]) + (0.998000026f * fRec27[1]));
			float fThen6 = (fSlow65 * float(tanhf(float((fSlow64 * fTemp47)))));
			float fElse6 = (fSlow67 * float(tanhf(float((fSlow66 * fTemp47)))));
			fVec12[(IOTA & 1023)] = (fTemp38 + (fSlow73 * ((fTemp47 > 0.0f) ? fElse6 : fThen6)));
			float fTempFTZ21 = fVec12[((IOTA - iSlow81) & 1023)];
			fRec26[(IOTA & 2047)] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp48 = std::fabs(fRec26[((IOTA - 0) & 2047)]);
			float fTempFTZ22 = std::max<float>(fTemp48, ((fConst26 * fRec25[1]) + (fConst27 * fTemp48)));
			fRec25[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fSlow82 + (fRec28[1] - std::floor((fSlow82 + fRec28[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp49 = std::max<float>(1.0f, ((fSlow72 * (fRec25[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec28[0]))])) + 4.0f));
			float fTemp50 = (fTemp49 + 4.99999987e-06f);
			float fTemp51 = std::floor(fTemp50);
			int iTemp52 = int(fTemp50);
			float fTemp53 = fRec29[((IOTA - iSlow90) & 2047)];
			fVec13[0] = fTemp53;
			float fTempFTZ24 = (fVec13[1] - (fSlow92 * (fRec30[1] - fTemp53)));
			fRec30[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTemp54 = ((0.00200000009f * fRec30[0]) + (0.998000026f * fRec30[1]));
			float fThen7 = (fSlow65 * float(tanhf(float((fSlow64 * fTemp54)))));
			float fElse7 = (fSlow67 * float(tanhf(float((fSlow66 * fTemp54)))));
			fVec14[(IOTA & 1023)] = ((fSlow85 * ((fTemp54 > 0.0f) ? fElse7 : fThen7)) + fTemp38);
			float fTempFTZ25 = fVec14[((IOTA - iSlow93) & 1023)];
			fRec29[(IOTA & 2047)] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTemp55 = std::fabs(fRec29[((IOTA - 0) & 2047)]);
			float fTempFTZ26 = std::max<float>(fTemp55, ((fConst26 * fRec31[1]) + (fConst27 * fTemp55)));
			fRec31[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (fSlow95 + (fRec32[1] - std::floor((fSlow95 + fRec32[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTemp56 = std::max<float>(1.0f, ((fSlow94 * (fRec31[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec32[0]))])) + 4.0f));
			float fTemp57 = (fTemp56 + 4.99999987e-06f);
			int iTemp58 = int(fTemp57);
			float fTemp59 = std::floor(fTemp57);
			float fTemp60 = (fSlow1 * (((fTemp42 - fTemp44) * fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp45 + 1)))))) & 2047)]) + ((((fTemp49 - fTemp51) * fRec26[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp52 + 1)))))) & 2047)]) + (((fRec29[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp58))))) & 2047)] * (0.0f - (fTemp56 + (-1.0f - fTemp59)))) + ((fTemp56 - fTemp59) * fRec29[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp58 + 1)))))) & 2047)])) + (fRec26[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp52))))) & 2047)] * (0.0f - (fTemp49 + (-1.0f - fTemp51)))))) + (fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp45))))) & 2047)] * (0.0f - (fTemp42 + (-1.0f - fTemp44)))))));
			fVec15[0] = (fTemp37 + fTemp60);
			float fTempFTZ28 = ((fTemp60 + (fTemp36 + (fTemp20 + ((0.995000005f * fRec1[1]) + fTemp19)))) - fVec15[1]);
			fRec1[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (fRec1[0] - (fConst31 * ((fConst32 * fRec0[2]) + (fConst33 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (fRec1[0] - (fConst39 * ((fConst40 * fRec33[2]) + (fConst41 * fRec33[1]))));
			fRec33[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fRec1[0] - (fConst48 * ((fConst49 * fRec34[2]) + (fConst50 * fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (fRec1[0] - (fConst56 * ((fConst57 * fRec35[2]) + (fConst58 * fRec35[1]))));
			fRec35[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (fRec1[0] - (fConst66 * ((fConst67 * fRec36[2]) + (fConst68 * fRec36[1]))));
			fRec36[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fRec1[0] - (fConst74 * ((fConst75 * fRec37[2]) + (fConst76 * fRec37[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTemp61 = ((0.400000006f * ((fConst5 * fRec0[0]) + (fConst38 * fRec33[0]))) + ((fConst42 * fRec33[2]) + ((0.699999988f * ((fConst47 * fRec34[0]) + (fConst55 * fRec35[0]))) + ((fConst59 * fRec35[2]) + ((fConst60 * fRec34[2]) + ((fConst65 * fRec36[2]) + ((fConst64 * fRec36[0]) + ((fConst73 * fRec37[2]) + ((fConst72 * fRec37[0]) + ((0.25f * fRec1[0]) + (fConst77 * fRec0[2])))))))))));
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp61 - (0.0599999987f * FaustSitarDSP_faustpower3_f(fTemp61)))));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec5[1] = iRec5[0];
			fRec4[1] = fRec4[0];
			fRec9[1] = fRec9[0];
			fVec3[1] = fVec3[0];
			fRec7[1] = fRec7[0];
			iRec12[1] = iRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			IOTA = (IOTA + 1);
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fVec5[1] = fVec5[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fVec7[1] = fVec7[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
			fVec9[1] = fVec9[0];
			fRec23[1] = fRec23[0];
			fRec2[1] = fRec2[0];
			fRec24[1] = fRec24[0];
			fVec11[1] = fVec11[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec28[1] = fRec28[0];
			fVec13[1] = fVec13[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			fRec32[1] = fRec32[0];
			fVec15[1] = fVec15[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
		}
	}

};

#endif
