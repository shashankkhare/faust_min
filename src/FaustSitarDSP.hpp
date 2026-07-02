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

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustSitarDSPSIG0 {
	
  private:
	
	int iVec6[2];
	int iRec11[2];
	
  public:
	
	int getNumInputsFaustSitarDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSitarDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSitarDSPSIG0(int sample_rate) {
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iVec6[l14] = 0;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			iRec11[l15] = 0;
		}
	}
	
	void fillFaustSitarDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec6[0] = 1;
			iRec11[0] = ((iVec6[1] + iRec11[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec11[0])));
			iVec6[1] = iVec6[0];
			iRec11[1] = iRec11[0];
		}
	}

};

static FaustSitarDSPSIG0* newFaustSitarDSPSIG0() { return (FaustSitarDSPSIG0*)new FaustSitarDSPSIG0(); }
static void deleteFaustSitarDSPSIG0(FaustSitarDSPSIG0* dsp) { delete dsp; }

static float FaustSitarDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustSitarDSPSIG0[65536];
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
	float fVec0[2];
	float fRec3[2];
	FAUSTFLOAT fHslider4;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider5;
	float fVec1[2];
	float fRec6[2];
	float fConst11;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fConst13;
	float fConst16;
	int iRec9[2];
	float fConst17;
	float fConst18;
	float fRec8[3];
	float fConst19;
	float fConst20;
	float fRec7[3];
	float fConst21;
	float fConst22;
	float fConst23;
	FAUSTFLOAT fButton0;
	float fVec2[2];
	int iVec3[2];
	int iRec10[2];
	float fConst24;
	int IOTA;
	float fVec4[2048];
	float fRec5[2048];
	float fVec5[2];
	float fRec4[2];
	float fConst25;
	float fRec12[2];
	FAUSTFLOAT fHslider8;
	float fConst26;
	float fVec7[2];
	float fRec14[2];
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec15[3];
	int iVec8[2];
	int iVec9[2];
	int iRec16[2];
	float fVec10[1024];
	float fRec13[1024];
	float fConst34;
	float fVec11[2];
	float fRec18[2];
	float fVec12[512];
	float fRec17[512];
	float fVec13[1024];
	float fRec2[1024];
	float fVec14[2];
	float fRec20[2];
	float fVec15[1024];
	float fRec19[1024];
	float fVec16[2];
	float fRec22[2];
	float fVec17[512];
	float fRec21[512];
	float fVec18[2];
	float fRec1[2];
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec0[3];
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec23[3];
	float fConst46;
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fRec24[3];
	float fConst59;
	float fConst60;
	float fConst61;
	float fConst62;
	float fRec25[3];
	float fConst63;
	float fConst64;
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fConst72;
	float fRec26[3];
	float fConst76;
	float fConst77;
	float fConst78;
	float fConst79;
	float fConst80;
	float fRec27[3];
	float fConst81;
	
 public:
	
	void metadata(Meta* m) { 
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
		m->declare("name", "sitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
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
		float fConst6 = (1.0f / std::tan((31.415926f / fConst0)));
		fConst7 = (1.0f / (fConst6 + 1.0f));
		fConst8 = (1.0f - fConst6);
		float fConst9 = std::tan((188.49556f / fConst0));
		float fConst10 = (1.0f / fConst9);
		fConst11 = (1.0f / (((fConst10 + 1.41421354f) / fConst9) + 1.0f));
		float fConst12 = FaustSitarDSP_faustpower2_f(fConst9);
		fConst13 = (1.0f / fConst12);
		float fConst14 = std::tan((18849.5566f / fConst0));
		float fConst15 = (1.0f / fConst14);
		fConst16 = (1.0f / (((fConst15 + 1.41421354f) / fConst14) + 1.0f));
		fConst17 = (((fConst15 + -1.41421354f) / fConst14) + 1.0f);
		fConst18 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst14))));
		fConst19 = (((fConst10 + -1.41421354f) / fConst9) + 1.0f);
		fConst20 = (2.0f * (1.0f - fConst13));
		fConst21 = (0.0f - (2.0f / fConst12));
		fConst22 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst23 = (1.0f / fConst22);
		fConst24 = (1.0f / std::max<float>(1.0f, (0.00800000038f * fConst0)));
		fConst25 = (1.0f / fConst0);
		fConst26 = (0.5f * fConst0);
		float fConst27 = std::tan((1884.95557f / fConst0));
		float fConst28 = (1.0f / fConst27);
		float fConst29 = (((fConst28 + 1.41421354f) / fConst27) + 1.0f);
		fConst30 = (0.349999994f / fConst29);
		fConst31 = (1.0f / fConst29);
		fConst32 = (((fConst28 + -1.41421354f) / fConst27) + 1.0f);
		fConst33 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst27))));
		fConst34 = (0.333333343f * fConst0);
		fConst35 = (1.0f / fConst3);
		fConst36 = (((fConst2 + -0.200000003f) / fConst1) + 1.0f);
		fConst37 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst1))));
		float fConst38 = std::tan((11309.7334f / fConst0));
		float fConst39 = (1.0f / fConst38);
		float fConst40 = (((fConst39 + 0.5f) / fConst38) + 1.0f);
		float fConst41 = (fConst38 * fConst40);
		fConst42 = (1.0f / fConst41);
		fConst43 = (1.0f / fConst40);
		fConst44 = (((fConst39 + -0.5f) / fConst38) + 1.0f);
		fConst45 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst38))));
		fConst46 = (0.0f - (0.400000006f / fConst41));
		float fConst47 = std::tan((4398.22949f / fConst0));
		float fConst48 = (1.0f / fConst47);
		float fConst49 = (((fConst48 + 0.333333343f) / fConst47) + 1.0f);
		float fConst50 = (fConst47 * fConst49);
		fConst51 = (1.0f / fConst50);
		fConst52 = (1.0f / fConst49);
		fConst53 = (((fConst48 + -0.333333343f) / fConst47) + 1.0f);
		fConst54 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst47))));
		float fConst55 = std::tan((6911.50391f / fConst0));
		float fConst56 = (1.0f / fConst55);
		float fConst57 = (((fConst56 + 0.400000006f) / fConst55) + 1.0f);
		float fConst58 = (fConst55 * fConst57);
		fConst59 = (1.0f / fConst58);
		fConst60 = (1.0f / fConst57);
		fConst61 = (((fConst56 + -0.400000006f) / fConst55) + 1.0f);
		fConst62 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst55))));
		fConst63 = (0.0f - (0.699999988f / fConst58));
		fConst64 = (0.0f - (0.699999988f / fConst50));
		float fConst65 = std::tan((2827.43335f / fConst0));
		float fConst66 = (1.0f / fConst65);
		float fConst67 = (((fConst66 + 0.285714298f) / fConst65) + 1.0f);
		fConst68 = (0.800000012f / (fConst65 * fConst67));
		fConst69 = (0.0f - fConst68);
		fConst70 = (1.0f / fConst67);
		fConst71 = (((fConst66 + -0.285714298f) / fConst65) + 1.0f);
		fConst72 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst65))));
		float fConst73 = std::tan((1413.71667f / fConst0));
		float fConst74 = (1.0f / fConst73);
		float fConst75 = (((fConst74 + 0.25f) / fConst73) + 1.0f);
		fConst76 = (0.5f / (fConst73 * fConst75));
		fConst77 = (0.0f - fConst76);
		fConst78 = (1.0f / fConst75);
		fConst79 = (((fConst74 + -0.25f) / fConst73) + 1.0f);
		fConst80 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst73))));
		fConst81 = (0.0f - (0.400000006f / fConst4));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.29999999999999999f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(1.2f);
		fHslider3 = FAUSTFLOAT(138.59999999999999f);
		fHslider4 = FAUSTFLOAT(0.29999999999999999f);
		fHslider5 = FAUSTFLOAT(5.0f);
		fHslider6 = FAUSTFLOAT(0.59999999999999998f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(277.19999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec9[l4] = 0;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec8[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iVec3[l8] = 0;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec10[l9] = 0;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 2048); l10 = (l10 + 1)) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2048); l11 = (l11 + 1)) {
			fRec5[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec5[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec4[l13] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fVec7[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec14[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec15[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			iVec8[l20] = 0;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			iVec9[l21] = 0;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			iRec16[l22] = 0;
		}
		for (int l23 = 0; (l23 < 1024); l23 = (l23 + 1)) {
			fVec10[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 1024); l24 = (l24 + 1)) {
			fRec13[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fVec11[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec18[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 512); l27 = (l27 + 1)) {
			fVec12[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 512); l28 = (l28 + 1)) {
			fRec17[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 1024); l29 = (l29 + 1)) {
			fVec13[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 1024); l30 = (l30 + 1)) {
			fRec2[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fVec14[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec20[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 1024); l33 = (l33 + 1)) {
			fVec15[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 1024); l34 = (l34 + 1)) {
			fRec19[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fVec16[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec22[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 512); l37 = (l37 + 1)) {
			fVec17[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 512); l38 = (l38 + 1)) {
			fRec21[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fVec18[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec1[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec0[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec23[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec24[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec25[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec26[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec27[l46] = 0.0f;
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
		ui_interface->declare(&fHslider8, "unit", "Hz");
		ui_interface->addHorizontalSlider("chikari_base", &fHslider8, FAUSTFLOAT(277.200012f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(138.600006f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("jivari", &fHslider4, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("strike", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "unit", "s");
		ui_interface->addHorizontalSlider("sustain", &fHslider5, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("symp_drift", &fHslider2, FAUSTFLOAT(1.20000005f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider6, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (7.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		float fSlow3 = float(fHslider3);
		float fSlow4 = (fConst0 / std::max<float>(((0.600000024f * fSlow2) + (1.5f * fSlow3)), 40.0f));
		int iSlow5 = int(fSlow4);
		float fSlow6 = float(iSlow5);
		float fSlow7 = (fSlow4 + (-0.499989986f - fSlow6));
		int iSlow8 = (std::min<int>(1024, std::max<int>(0, int(fSlow7))) + 1);
		float fSlow9 = (fSlow6 + std::floor(fSlow7));
		float fSlow10 = ((fSlow9 + (1.0f - fSlow4)) / (fSlow4 + (1.0f - fSlow9)));
		float fSlow11 = float(fHslider4);
		float fSlow12 = (2100.0f * (fSlow11 / fSlow3));
		float fSlow13 = std::pow(0.00100000005f, (1.0f / (fSlow3 * std::max<float>(0.400000006f, (float(fHslider5) * (1.0f - (0.349999994f * fSlow11)))))));
		float fSlow14 = (fConst0 / fSlow3);
		int iSlow15 = int(fSlow14);
		float fSlow16 = float(iSlow15);
		float fSlow17 = (fSlow14 + (-0.499989986f - fSlow16));
		int iSlow18 = (std::min<int>(1024, std::max<int>(0, int(fSlow17))) + 1);
		float fSlow19 = (fSlow16 + std::floor(fSlow17));
		float fSlow20 = ((fSlow19 + (1.0f - fSlow14)) / (fSlow14 + (1.0f - fSlow19)));
		float fSlow21 = float(fHslider6);
		float fSlow22 = float(fHslider7);
		int iSlow23 = (fSlow22 == 2.0f);
		float fSlow24 = (fConst11 * (fSlow21 * float((iSlow23 + (fSlow22 == 0.0f)))));
		int iSlow25 = iSlow23;
		float fSlow26 = (iSlow25 ? 0.649999976f : 0.400000006f);
		float fSlow27 = float(fButton0);
		int iSlow28 = std::min<int>(16384, std::max<int>(0, iSlow15));
		float fSlow29 = (iSlow25 ? 1.29999995f : 1.0f);
		float fSlow30 = (fConst25 * fSlow3);
		float fSlow31 = float(fHslider8);
		float fSlow32 = std::pow(0.00100000005f, (0.3125f / fSlow31));
		float fSlow33 = (fConst26 / fSlow31);
		int iSlow34 = int(fSlow33);
		float fSlow35 = float(iSlow34);
		float fSlow36 = (fSlow33 + (-0.499989986f - fSlow35));
		int iSlow37 = (std::min<int>(1024, std::max<int>(0, int(fSlow36))) + 1);
		float fSlow38 = (fSlow35 + std::floor(fSlow36));
		float fSlow39 = ((fSlow38 + (1.0f - fSlow33)) / (fSlow33 + (1.0f - fSlow38)));
		float fSlow40 = (fConst30 * fSlow21);
		int iSlow41 = (fSlow22 == 1.0f);
		int iSlow42 = std::min<int>(16384, std::max<int>(0, iSlow34));
		float fSlow43 = std::pow(0.00100000005f, (0.208333328f / fSlow31));
		float fSlow44 = (fConst34 / fSlow31);
		int iSlow45 = int(fSlow44);
		float fSlow46 = float(iSlow45);
		float fSlow47 = (fSlow44 + (-0.499989986f - fSlow46));
		int iSlow48 = (std::min<int>(1024, std::max<int>(0, int(fSlow47))) + 1);
		float fSlow49 = (fSlow46 + std::floor(fSlow47));
		float fSlow50 = ((fSlow49 + (1.0f - fSlow44)) / (fSlow44 + (1.0f - fSlow49)));
		int iSlow51 = std::min<int>(16384, std::max<int>(0, iSlow45));
		int iSlow52 = std::min<int>(16384, std::max<int>(0, iSlow5));
		float fSlow53 = (fConst0 / std::max<float>(((2.0f * fSlow3) - (0.400000006f * fSlow2)), 40.0f));
		int iSlow54 = int(fSlow53);
		float fSlow55 = float(iSlow54);
		float fSlow56 = (fSlow53 + (-0.499989986f - fSlow55));
		int iSlow57 = (std::min<int>(1024, std::max<int>(0, int(fSlow56))) + 1);
		float fSlow58 = (fSlow55 + std::floor(fSlow56));
		float fSlow59 = ((fSlow58 + (1.0f - fSlow53)) / (fSlow53 + (1.0f - fSlow58)));
		int iSlow60 = std::min<int>(16384, std::max<int>(0, iSlow54));
		float fSlow61 = (fConst0 / std::max<float>(((0.5f * fSlow2) + (3.0f * fSlow3)), 40.0f));
		int iSlow62 = int(fSlow61);
		float fSlow63 = float(iSlow62);
		float fSlow64 = (fSlow61 + (-0.499989986f - fSlow63));
		int iSlow65 = (std::min<int>(1024, std::max<int>(0, int(fSlow64))) + 1);
		float fSlow66 = (fSlow63 + std::floor(fSlow64));
		float fSlow67 = ((fSlow66 + (1.0f - fSlow61)) / (fSlow61 + (1.0f - fSlow66)));
		int iSlow68 = std::min<int>(16384, std::max<int>(0, iSlow62));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTemp0 = fRec2[((IOTA - iSlow8) & 1023)];
			fVec0[0] = fTemp0;
			float fTempFTZ0 = (fVec0[1] - (fSlow10 * (fRec3[1] - fTemp0)));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp1 = fRec5[((IOTA - iSlow18) & 2047)];
			fVec1[0] = fTemp1;
			float fTempFTZ1 = (fVec1[1] - (fSlow20 * (fRec6[1] - fTemp1)));
			fRec6[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec9[0] = ((1103515245 * iRec9[1]) + 12345);
			float fTemp2 = (4.65661287e-10f * float(iRec9[0]));
			float fTempFTZ2 = (fTemp2 - (fConst16 * ((fConst17 * fRec8[2]) + (fConst18 * fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((fConst16 * (fRec8[2] + (fRec8[0] + (2.0f * fRec8[1])))) - (fConst11 * ((fConst19 * fRec7[2]) + (fConst20 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			fVec2[0] = fSlow27;
			int iTemp3 = (fSlow27 > fVec2[1]);
			iVec3[0] = iTemp3;
			iRec10[0] = ((iTemp3 > iVec3[1]) + ((iTemp3 <= iVec3[1]) * (iRec10[1] + (iRec10[1] > 0))));
			float fTemp4 = float(iRec10[0]);
			fVec4[(IOTA & 2047)] = ((fSlow13 * ((0.00200000009f * fRec6[0]) + (0.998000026f * fRec6[1]))) + (fSlow24 * ((fSlow26 * (((fConst13 * fRec7[0]) + (fConst21 * fRec7[1])) + (fConst13 * fRec7[2]))) * std::max<float>(0.0f, std::min<float>((fConst23 * fTemp4), (1.0f - (fConst24 * (fTemp4 - fConst22))))))));
			float fTempFTZ4 = fVec4[((IOTA - iSlow28) & 2047)];
			fRec5[(IOTA & 2047)] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp5 = std::fabs(fRec5[((IOTA - 0) & 2047)]);
			fVec5[0] = fTemp5;
			float fTempFTZ5 = (0.0f - (fConst7 * ((fConst8 * fRec4[1]) - (fTemp5 + fVec5[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fSlow30 + (fRec12[1] - std::floor((fSlow30 + fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp6 = std::max<float>(1.0f, ((fSlow12 * ((std::sqrt(fRec4[0]) * fSlow29) * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec12[0]))])) + 4.0f));
			float fTemp7 = (fTemp6 + 4.99999987e-06f);
			float fTemp8 = std::floor(fTemp7);
			int iTemp9 = int(fTemp7);
			float fTemp10 = ((fTemp6 - fTemp8) * fRec5[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp9 + 1)))))) & 2047)]);
			float fTemp11 = (fRec5[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp9))))) & 2047)] * (0.0f - (fTemp6 + (-1.0f - fTemp8))));
			float fTemp12 = fRec13[((IOTA - iSlow37) & 1023)];
			fVec7[0] = fTemp12;
			float fTempFTZ7 = (fVec7[1] - (fSlow39 * (fRec14[1] - fTemp12)));
			fRec14[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp2 - (fConst31 * ((fConst32 * fRec15[2]) + (fConst33 * fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			iVec8[0] = iSlow41;
			int iTemp13 = (iSlow41 > iVec8[1]);
			iVec9[0] = iTemp13;
			iRec16[0] = (((iRec16[1] + (iRec16[1] > 0)) * (iTemp13 <= iVec9[1])) + (iTemp13 > iVec9[1]));
			float fTemp14 = float(iRec16[0]);
			float fTemp15 = (fSlow40 * ((fRec15[2] + (fRec15[0] + (2.0f * fRec15[1]))) * std::max<float>(0.0f, std::min<float>((fConst23 * fTemp14), (1.0f - (fConst24 * (fTemp14 - fConst22)))))));
			fVec10[(IOTA & 1023)] = ((fSlow32 * ((0.00200000009f * fRec14[0]) + (0.998000026f * fRec14[1]))) + fTemp15);
			float fTempFTZ9 = fVec10[((IOTA - iSlow42) & 1023)];
			fRec13[(IOTA & 1023)] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp16 = fRec17[((IOTA - iSlow48) & 511)];
			fVec11[0] = fTemp16;
			float fTempFTZ10 = (fVec11[1] - (fSlow50 * (fRec18[1] - fTemp16)));
			fRec18[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			fVec12[(IOTA & 511)] = (fTemp15 + (fSlow43 * ((0.00200000009f * fRec18[0]) + (0.998000026f * fRec18[1]))));
			float fTempFTZ11 = fVec12[((IOTA - iSlow51) & 511)];
			fRec17[(IOTA & 511)] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp17 = (0.5f * (fRec13[((IOTA - 0) & 1023)] + fRec17[((IOTA - 0) & 511)]));
			float fTemp18 = (fTemp10 + (fTemp11 + fTemp17));
			float fTemp19 = (0.349999994f * fTemp18);
			fVec13[(IOTA & 1023)] = ((0.998399973f * ((0.00200000009f * fRec3[0]) + (0.998000026f * fRec3[1]))) + fTemp19);
			float fTempFTZ12 = fVec13[((IOTA - iSlow52) & 1023)];
			fRec2[(IOTA & 1023)] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp20 = fRec19[((IOTA - iSlow57) & 1023)];
			fVec14[0] = fTemp20;
			float fTempFTZ13 = (fVec14[1] - (fSlow59 * (fRec20[1] - fTemp20)));
			fRec20[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			fVec15[(IOTA & 1023)] = (fTemp19 + (0.998399973f * ((0.00200000009f * fRec20[0]) + (0.998000026f * fRec20[1]))));
			float fTempFTZ14 = fVec15[((IOTA - iSlow60) & 1023)];
			fRec19[(IOTA & 1023)] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp21 = fRec21[((IOTA - iSlow65) & 511)];
			fVec16[0] = fTemp21;
			float fTempFTZ15 = (fVec16[1] - (fSlow67 * (fRec22[1] - fTemp21)));
			fRec22[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			fVec17[(IOTA & 511)] = (fTemp19 + (0.998399973f * ((0.00200000009f * fRec22[0]) + (0.998000026f * fRec22[1]))));
			float fTempFTZ16 = fVec17[((IOTA - iSlow68) & 511)];
			fRec21[(IOTA & 511)] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp22 = (fSlow1 * ((fRec2[((IOTA - 0) & 1023)] + fRec19[((IOTA - 0) & 1023)]) + fRec21[((IOTA - 0) & 511)]));
			fVec18[0] = (fTemp18 + fTemp22);
			float fTempFTZ17 = ((fTemp22 + (fTemp10 + (fTemp11 + ((0.995000005f * fRec1[1]) + fTemp17)))) - fVec18[1]);
			fRec1[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fRec1[0] - (fConst35 * ((fConst36 * fRec0[2]) + (fConst37 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fRec1[0] - (fConst43 * ((fConst44 * fRec23[2]) + (fConst45 * fRec23[1]))));
			fRec23[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fRec1[0] - (fConst52 * ((fConst53 * fRec24[2]) + (fConst54 * fRec24[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fRec1[0] - (fConst60 * ((fConst61 * fRec25[2]) + (fConst62 * fRec25[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fRec1[0] - (fConst70 * ((fConst71 * fRec26[2]) + (fConst72 * fRec26[1]))));
			fRec26[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fRec1[0] - (fConst78 * ((fConst79 * fRec27[2]) + (fConst80 * fRec27[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp23 = ((0.400000006f * ((fConst5 * fRec0[0]) + (fConst42 * fRec23[0]))) + ((fConst46 * fRec23[2]) + ((0.699999988f * ((fConst51 * fRec24[0]) + (fConst59 * fRec25[0]))) + ((fConst63 * fRec25[2]) + ((fConst64 * fRec24[2]) + ((fConst69 * fRec26[2]) + ((fConst68 * fRec26[0]) + ((fConst77 * fRec27[2]) + ((fConst76 * fRec27[0]) + ((0.25f * fRec1[0]) + (fConst81 * fRec0[2])))))))))));
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp23 - (0.0599999987f * FaustSitarDSP_faustpower3_f(fTemp23)))));
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			fVec1[1] = fVec1[0];
			fRec6[1] = fRec6[0];
			iRec9[1] = iRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec2[1] = fVec2[0];
			iVec3[1] = iVec3[0];
			iRec10[1] = iRec10[0];
			IOTA = (IOTA + 1);
			fVec5[1] = fVec5[0];
			fRec4[1] = fRec4[0];
			fRec12[1] = fRec12[0];
			fVec7[1] = fVec7[0];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			iVec8[1] = iVec8[0];
			iVec9[1] = iVec9[0];
			iRec16[1] = iRec16[0];
			fVec11[1] = fVec11[0];
			fRec18[1] = fRec18[0];
			fVec14[1] = fVec14[0];
			fRec20[1] = fRec20[0];
			fVec16[1] = fVec16[0];
			fRec22[1] = fRec22[0];
			fVec18[1] = fVec18[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
		}
	}

};

#endif
