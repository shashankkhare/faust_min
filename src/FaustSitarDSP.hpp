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
	int iRec7[2];
	
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
			iRec7[l5] = 0;
		}
	}
	
	void fillFaustSitarDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec2[0] = 1;
			iRec7[0] = ((iVec2[1] + iRec7[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec7[0])));
			iVec2[1] = iVec2[0];
			iRec7[1] = iRec7[0];
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
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
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
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fConst11;
	FAUSTFLOAT fHslider6;
	float fRec8[2];
	FAUSTFLOAT fHslider7;
	float fRec9[2];
	float fVec3[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	int iRec10[2];
	int IOTA;
	float fVec4[8192];
	float fRec6[2048];
	float fConst12;
	float fConst13;
	float fRec11[2];
	float fRec12[2];
	FAUSTFLOAT fHslider12;
	float fConst14;
	float fConst15;
	int iVec5[2];
	float fRec16[2];
	int iVec6[2];
	int iRec15[2];
	float fConst16;
	float fVec7[2];
	float fVec8[2048];
	float fRec14[2048];
	float fRec13[2];
	float fConst17;
	float fRec17[2];
	float fVec9[2];
	float fVec10[2048];
	float fRec18[2048];
	float fRec19[2];
	float fConst18;
	float fRec20[2];
	FAUSTFLOAT fHslider13;
	float fVec11[2];
	float fVec12[8192];
	float fRec3[2048];
	float fRec2[2];
	float fRec21[2];
	float fVec13[2];
	float fVec14[8192];
	float fRec23[2048];
	float fRec22[2];
	float fRec24[2];
	float fVec15[2];
	float fVec16[8192];
	float fRec25[2048];
	float fRec26[2];
	float fRec27[2];
	float fVec17[2];
	float fRec1[2];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec0[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec28[3];
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec29[3];
	float fConst41;
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec30[3];
	float fConst50;
	float fConst51;
	float fConst52;
	float fConst53;
	float fRec31[3];
	float fConst58;
	float fConst59;
	float fConst60;
	float fConst61;
	float fRec32[3];
	float fConst62;
	float fConst66;
	float fConst67;
	float fConst68;
	float fConst69;
	float fConst70;
	float fRec33[3];
	float fConst74;
	float fConst75;
	float fConst76;
	float fConst77;
	float fConst78;
	float fRec34[3];
	float fConst79;
	
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
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
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
		return 2;
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
		float fConst1 = std::tan((2953.09717f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.285714298f) / fConst1) + 1.0f);
		fConst4 = (0.159999996f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		fConst6 = (44.0999985f / fConst0);
		fConst7 = (1.0f - fConst6);
		fConst8 = std::max<float>(1.0f, (0.00400000019f * fConst0));
		fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		fConst11 = (1.0f / fConst0);
		fConst12 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst13 = (1.0f - fConst12);
		fConst14 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst15 = (1.0f / fConst14);
		fConst16 = (1.0f / std::max<float>(1.0f, (0.00800000038f * fConst0)));
		fConst17 = (3.0f / fConst0);
		fConst18 = (2.0f / fConst0);
		fConst19 = (1.0f / fConst3);
		fConst20 = (((fConst2 + -0.285714298f) / fConst1) + 1.0f);
		fConst21 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst1))));
		float fConst22 = std::tan((2616.94678f / fConst0));
		float fConst23 = (1.0f / fConst22);
		float fConst24 = (((fConst23 + 0.285714298f) / fConst22) + 1.0f);
		fConst25 = (0.200000003f / (fConst22 * fConst24));
		fConst26 = (0.0f - fConst25);
		fConst27 = (1.0f / fConst24);
		fConst28 = (((fConst23 + -0.285714298f) / fConst22) + 1.0f);
		fConst29 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst22))));
		float fConst30 = std::tan((2340.48657f / fConst0));
		float fConst31 = (1.0f / fConst30);
		float fConst32 = (((fConst31 + 0.285714298f) / fConst30) + 1.0f);
		fConst33 = (0.239999995f / (fConst30 * fConst32));
		fConst34 = (0.0f - fConst33);
		fConst35 = (1.0f / fConst32);
		fConst36 = (((fConst31 + -0.285714298f) / fConst30) + 1.0f);
		fConst37 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst30))));
		float fConst38 = std::tan((1759.29187f / fConst0));
		float fConst39 = (1.0f / fConst38);
		float fConst40 = (((fConst39 + 0.285714298f) / fConst38) + 1.0f);
		fConst41 = (0.300000012f / (fConst38 * fConst40));
		fConst42 = (0.0f - fConst41);
		fConst43 = (1.0f / fConst40);
		fConst44 = (((fConst39 + -0.285714298f) / fConst38) + 1.0f);
		fConst45 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst38))));
		float fConst46 = std::tan((452.389343f / fConst0));
		float fConst47 = (1.0f / fConst46);
		float fConst48 = (((fConst47 + 0.285714298f) / fConst46) + 1.0f);
		float fConst49 = (fConst46 * fConst48);
		fConst50 = (1.0f / fConst49);
		fConst51 = (1.0f / fConst48);
		fConst52 = (((fConst47 + -0.285714298f) / fConst46) + 1.0f);
		fConst53 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst46))));
		float fConst54 = std::tan((1350.88489f / fConst0));
		float fConst55 = (1.0f / fConst54);
		float fConst56 = (((fConst55 + 0.285714298f) / fConst54) + 1.0f);
		float fConst57 = (fConst54 * fConst56);
		fConst58 = (1.0f / fConst57);
		fConst59 = (1.0f / fConst56);
		fConst60 = (((fConst55 + -0.285714298f) / fConst54) + 1.0f);
		fConst61 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst54))));
		fConst62 = (0.0f - (0.899999976f / fConst57));
		float fConst63 = std::tan((942.477783f / fConst0));
		float fConst64 = (1.0f / fConst63);
		float fConst65 = (((fConst64 + 0.285714298f) / fConst63) + 1.0f);
		fConst66 = (1.60000002f / (fConst63 * fConst65));
		fConst67 = (0.0f - fConst66);
		fConst68 = (1.0f / fConst65);
		fConst69 = (((fConst64 + -0.285714298f) / fConst63) + 1.0f);
		fConst70 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst63))));
		float fConst71 = std::tan((345.575195f / fConst0));
		float fConst72 = (1.0f / fConst71);
		float fConst73 = (((fConst72 + 0.285714298f) / fConst71) + 1.0f);
		fConst74 = (1.39999998f / (fConst71 * fConst73));
		fConst75 = (0.0f - fConst74);
		fConst76 = (1.0f / fConst73);
		fConst77 = (((fConst72 + -0.285714298f) / fConst71) + 1.0f);
		fConst78 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst71))));
		fConst79 = (0.0f - (0.899999976f / fConst49));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.29999999999999999f);
		fHslider1 = FAUSTFLOAT(0.089999999999999997f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(138.59999999999999f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.01f);
		fHslider6 = FAUSTFLOAT(4.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(7.5f);
		fHslider10 = FAUSTFLOAT(0.59999999999999998f);
		fHslider11 = FAUSTFLOAT(0.059999999999999998f);
		fHslider12 = FAUSTFLOAT(111.0f);
		fHslider13 = FAUSTFLOAT(1.2f);
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
			fRec8[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec9[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec10[l9] = 0;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 8192); l10 = (l10 + 1)) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2048); l11 = (l11 + 1)) {
			fRec6[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iVec5[l14] = 0;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec16[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			iVec6[l16] = 0;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iRec15[l17] = 0;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec7[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2048); l19 = (l19 + 1)) {
			fVec8[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2048); l20 = (l20 + 1)) {
			fRec14[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec13[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec17[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fVec9[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2048); l24 = (l24 + 1)) {
			fVec10[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2048); l25 = (l25 + 1)) {
			fRec18[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec19[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec20[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fVec11[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 8192); l29 = (l29 + 1)) {
			fVec12[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2048); l30 = (l30 + 1)) {
			fRec3[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec2[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec21[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fVec13[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 8192); l34 = (l34 + 1)) {
			fVec14[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2048); l35 = (l35 + 1)) {
			fRec23[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec22[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec24[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fVec15[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 8192); l39 = (l39 + 1)) {
			fVec16[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2048); l40 = (l40 + 1)) {
			fRec25[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec26[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec27[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fVec17[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec1[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec0[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec28[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec29[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec30[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec31[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec32[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec33[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec34[l52] = 0.0f;
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
		ui_interface->addHorizontalSlider("calibration", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-100.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider12, "unit", "Hz");
		ui_interface->addHorizontalSlider("chikari_freq", &fHslider12, FAUSTFLOAT(111.0f), FAUSTFLOAT(55.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("exc_gain", &fHslider11, FAUSTFLOAT(0.0599999987f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(138.600006f), FAUSTFLOAT(130.0f), FAUSTFLOAT(2400.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("strike", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider9, "unit", "s");
		ui_interface->addHorizontalSlider("sustain", &fHslider9, FAUSTFLOAT(7.5f), FAUSTFLOAT(0.5f), FAUSTFLOAT(30.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider13, "unit", "Hz");
		ui_interface->addHorizontalSlider("symp_drift", &fHslider13, FAUSTFLOAT(1.20000005f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider1, FAUSTFLOAT(0.0900000036f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider10, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider4, "style", "check");
		ui_interface->addHorizontalSlider("vibrato", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider5, FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider6, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (65.8878174f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		float fSlow3 = (607.5f * fSlow2);
		float fSlow4 = float(fButton0);
		float fSlow5 = float(fHslider3);
		float fSlow6 = (float(fHslider4) * float(fHslider5));
		float fSlow7 = (fConst11 * float(fHslider6));
		float fSlow8 = (fConst6 * float(fHslider7));
		float fSlow9 = float(fHslider8);
		int iSlow10 = (fSlow9 == 2.0f);
		int iSlow11 = iSlow10;
		float fSlow12 = (iSlow11 ? 1.39999998f : 1.0f);
		float fSlow13 = (((20.0f * fSlow2) * fSlow12) + 1.0f);
		float fSlow14 = float(fHslider9);
		float fSlow15 = std::max<float>(0.400000006f, (fSlow14 * (1.0f - ((0.349999994f * fSlow2) * fSlow12))));
		float fSlow16 = float(fHslider10);
		float fSlow17 = (4.65661287e-10f * ((fSlow16 * float(fHslider11)) * float((iSlow10 + (fSlow9 == 0.0f)))));
		float fSlow18 = (iSlow11 ? 0.649999976f : 0.400000006f);
		float fSlow19 = (1350.0f * fSlow2);
		float fSlow20 = (fConst11 * fSlow5);
		float fSlow21 = float(fHslider12);
		float fSlow22 = std::max<float>(40.0f, (3.0f * fSlow21));
		float fSlow23 = (945.0f * (fSlow2 / fSlow22));
		float fSlow24 = (1.62981448e-10f * fSlow16);
		int iSlow25 = (fSlow9 == 1.0f);
		float fSlow26 = std::max<float>(0.400000006f, (1.79999995f * (1.0f - (0.245000005f * fSlow2))));
		float fSlow27 = std::pow(0.00100000005f, (1.0f / (fSlow22 * fSlow26)));
		float fSlow28 = (fConst0 / fSlow22);
		int iSlow29 = int(fSlow28);
		float fSlow30 = float(iSlow29);
		float fSlow31 = (fSlow28 + (4.99999987e-06f - fSlow30));
		float fSlow32 = (fSlow30 + std::floor(fSlow31));
		float fSlow33 = (fSlow28 - fSlow32);
		float fSlow34 = (fSlow28 + (-1.0f - fSlow32));
		float fSlow35 = (fSlow28 + (-2.0f - fSlow32));
		float fSlow36 = (((0.0f - fSlow33) * (0.0f - (0.5f * fSlow34))) * (0.0f - (0.333333343f * fSlow35)));
		int iSlow37 = int(fSlow31);
		int iSlow38 = (std::min<int>(1024, std::max<int>(0, iSlow37)) + 1);
		float fSlow39 = (fSlow28 + (1.0f - fSlow32));
		float fSlow40 = ((0.0f - fSlow34) * (0.0f - (0.5f * fSlow35)));
		int iSlow41 = (std::min<int>(1024, std::max<int>(0, (iSlow37 + 1))) + 1);
		float fSlow42 = (0.5f * (fSlow33 * (0.0f - fSlow35)));
		int iSlow43 = (std::min<int>(1024, std::max<int>(0, (iSlow37 + 2))) + 1);
		float fSlow44 = (0.166666672f * (fSlow33 * fSlow34));
		int iSlow45 = (std::min<int>(1024, std::max<int>(0, (iSlow37 + 3))) + 1);
		float fSlow46 = (0.699999988f * fSlow2);
		float fSlow47 = ((14.0f * fSlow2) + 1.0f);
		float fSlow48 = (1.0f / fSlow47);
		int iSlow49 = std::min<int>(16384, std::max<int>(0, (iSlow29 + -1)));
		float fSlow50 = (fConst17 * fSlow21);
		float fSlow51 = std::max<float>(40.0f, (2.0f * fSlow21));
		float fSlow52 = std::pow(0.00100000005f, (1.0f / (fSlow26 * fSlow51)));
		float fSlow53 = (fConst0 / fSlow51);
		int iSlow54 = int(fSlow53);
		float fSlow55 = float(iSlow54);
		float fSlow56 = (fSlow53 + (4.99999987e-06f - fSlow55));
		float fSlow57 = (fSlow55 + std::floor(fSlow56));
		float fSlow58 = (fSlow53 - fSlow57);
		float fSlow59 = (fSlow53 + (-1.0f - fSlow57));
		float fSlow60 = (fSlow53 + (-2.0f - fSlow57));
		float fSlow61 = (((0.0f - fSlow58) * (0.0f - (0.5f * fSlow59))) * (0.0f - (0.333333343f * fSlow60)));
		int iSlow62 = int(fSlow56);
		int iSlow63 = (std::min<int>(1024, std::max<int>(0, iSlow62)) + 1);
		float fSlow64 = (fSlow53 + (1.0f - fSlow57));
		float fSlow65 = ((0.0f - fSlow59) * (0.0f - (0.5f * fSlow60)));
		int iSlow66 = (std::min<int>(1024, std::max<int>(0, (iSlow62 + 1))) + 1);
		float fSlow67 = (0.5f * (fSlow58 * (0.0f - fSlow60)));
		int iSlow68 = (std::min<int>(1024, std::max<int>(0, (iSlow62 + 2))) + 1);
		float fSlow69 = (0.166666672f * (fSlow58 * fSlow59));
		int iSlow70 = (std::min<int>(1024, std::max<int>(0, (iSlow62 + 3))) + 1);
		int iSlow71 = std::min<int>(16384, std::max<int>(0, (iSlow54 + -1)));
		float fSlow72 = (945.0f * (fSlow2 / fSlow51));
		float fSlow73 = (fConst18 * fSlow21);
		float fSlow74 = float(fHslider13);
		float fSlow75 = std::max<float>(((0.5f * fSlow74) + (3.0f * fSlow5)), 40.0f);
		float fSlow76 = (0.449999988f * fSlow2);
		float fSlow77 = ((9.0f * fSlow2) + 1.0f);
		float fSlow78 = (1.0f / fSlow77);
		float fSlow79 = (1.0f / std::max<float>(0.400000006f, (1.5f * (fSlow14 * (1.0f - (0.157499999f * fSlow2))))));
		float fSlow80 = (fConst11 * fSlow75);
		float fSlow81 = std::max<float>(((2.0f * fSlow5) - (0.400000006f * fSlow74)), 40.0f);
		float fSlow82 = (fConst11 * fSlow81);
		float fSlow83 = std::max<float>(((0.600000024f * fSlow74) + (1.5f * fSlow5)), 40.0f);
		float fSlow84 = (fConst11 * fSlow83);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow4;
			int iTemp0 = (fSlow4 > fVec0[1]);
			iVec1[0] = iTemp0;
			iRec5[0] = ((iTemp0 > iVec1[1]) + ((iTemp0 <= iVec1[1]) * (iRec5[1] + (iRec5[1] > 0))));
			float fTemp1 = float(iRec5[0]);
			float fTemp2 = std::max<float>(0.0f, std::min<float>((fConst9 * fTemp1), (1.0f - (fConst10 * (fTemp1 - fConst8)))));
			float fTempFTZ0 = ((fConst7 * fRec4[1]) + (fConst6 * fTemp2));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow7 + (fRec8[1] - std::floor((fSlow7 + fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow8 + (fConst7 * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp3 = std::pow(2.0f, (0.000833333354f * fRec9[0]));
			float fTemp4 = (((fSlow6 * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec8[0]))]) + 1.0f) * fTemp3);
			float fTemp5 = std::max<float>(40.0f, (fSlow5 * fTemp4));
			float fTemp6 = (fConst0 / fTemp5);
			int iTemp7 = int(fTemp6);
			float fTemp8 = float(iTemp7);
			float fTemp9 = (fTemp6 + (4.99999987e-06f - fTemp8));
			int iTemp10 = int(fTemp9);
			float fTemp11 = (fTemp8 + std::floor(fTemp9));
			float fTemp12 = (fTemp6 - fTemp11);
			float fTemp13 = (fTemp6 + (-1.0f - fTemp11));
			float fTemp14 = (fTemp6 + (-2.0f - fTemp11));
			float fTemp15 = ((((fRec6[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp10)) + 1)) & 2047)] * (0.0f - fTemp12)) * (0.0f - (0.5f * fTemp13))) * (0.0f - (0.333333343f * fTemp14))) + ((fTemp6 + (1.0f - fTemp11)) * ((((fRec6[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp10 + 1))) + 1)) & 2047)] * (0.0f - fTemp13)) * (0.0f - (0.5f * fTemp14))) + (0.5f * ((fTemp12 * fRec6[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp10 + 2))) + 1)) & 2047)]) * (0.0f - fTemp14)))) + (0.166666672f * ((fTemp12 * fTemp13) * fRec6[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp10 + 3))) + 1)) & 2047)])))));
			fVec3[0] = fTemp15;
			float fTemp16 = ((0.00200000009f * fTemp15) + (0.998000026f * fVec3[1]));
			float fThen1 = (fTemp16 - (fSlow2 * (fSlow12 * (fTemp16 - (float(tanhf(float((fTemp16 * fSlow13)))) / fSlow13)))));
			iRec10[0] = ((1103515245 * iRec10[1]) + 12345);
			float fTemp17 = float(iRec10[0]);
			fVec4[(IOTA & 8191)] = ((((fTemp16 > 0.0f) ? fTemp16 : fThen1) * std::pow(0.00100000005f, (1.0f / (fTemp5 * fSlow15)))) + (fSlow17 * ((fTemp17 * fSlow18) * fTemp2)));
			float fTempFTZ3 = fVec4[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp7 + -1)))) & 8191)];
			fRec6[(IOTA & 2047)] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp18 = std::fabs(fRec6[((IOTA - 0) & 2047)]);
			float fTempFTZ4 = std::max<float>(fTemp18, ((fConst12 * fRec11[1]) + (fConst13 * fTemp18)));
			fRec11[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp19 = (fRec12[1] + (fSlow20 * fTemp4));
			float fTempFTZ5 = (fTemp19 - std::floor(fTemp19));
			fRec12[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp20 = std::max<float>(1.0f, ((fSlow19 * (((fRec11[0] * fSlow12) * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec12[0]))]) / fTemp5)) + 4.0f));
			float fTemp21 = (fTemp20 + 4.99999987e-06f);
			int iTemp22 = int(fTemp21);
			float fTemp23 = std::floor(fTemp21);
			float fTemp24 = (fRec6[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp22))))) & 2047)] * (0.0f - (fTemp20 + (-1.0f - fTemp23))));
			float fTemp25 = ((fTemp20 - fTemp23) * fRec6[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp22 + 1)))))) & 2047)]);
			iVec5[0] = iSlow25;
			int iTemp26 = ((iSlow25 > iVec5[1]) | (iTemp0 & iSlow25));
			float fThen3 = std::max<float>(0.0f, (fRec16[1] + -1.0f));
			float fTempFTZ6 = (iTemp26 ? 150.0f : fThen3);
			fRec16[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			int iTemp27 = (fRec16[0] > 0.0f);
			iVec6[0] = iTemp27;
			iRec15[0] = (((iRec15[1] + (iRec15[1] > 0)) * (iTemp27 <= iVec6[1])) + (iTemp27 > iVec6[1]));
			float fTemp28 = float(iRec15[0]);
			float fTemp29 = (fSlow24 * ((fTemp17 * std::max<float>(0.0f, std::min<float>((fConst15 * fTemp28), (1.0f - (fConst16 * (fTemp28 - fConst14)))))) * float(iTemp26)));
			float fTemp30 = ((fSlow36 * fRec14[((IOTA - iSlow38) & 2047)]) + (fSlow39 * (((fSlow40 * fRec14[((IOTA - iSlow41) & 2047)]) + (fSlow42 * fRec14[((IOTA - iSlow43) & 2047)])) + (fSlow44 * fRec14[((IOTA - iSlow45) & 2047)]))));
			fVec7[0] = fTemp30;
			float fTemp31 = ((0.00200000009f * fTemp30) + (0.998000026f * fVec7[1]));
			float fThen4 = (fTemp31 - (fSlow46 * (fTemp31 - (fSlow48 * float(tanhf(float((fSlow47 * fTemp31))))))));
			fVec8[(IOTA & 2047)] = (fTemp29 + (fSlow27 * ((fTemp31 > 0.0f) ? fTemp31 : fThen4)));
			float fTempFTZ7 = fVec8[((IOTA - iSlow49) & 2047)];
			fRec14[(IOTA & 2047)] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp32 = std::fabs(fRec14[((IOTA - 0) & 2047)]);
			float fTempFTZ8 = std::max<float>(fTemp32, ((fConst12 * fRec13[1]) + (fConst13 * fTemp32)));
			fRec13[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fSlow50 + (fRec17[1] - std::floor((fSlow50 + fRec17[1]))));
			fRec17[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp33 = std::max<float>(1.0f, ((fSlow23 * (fRec13[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec17[0]))])) + 4.0f));
			float fTemp34 = (fTemp33 + 4.99999987e-06f);
			float fTemp35 = std::floor(fTemp34);
			int iTemp36 = int(fTemp34);
			float fTemp37 = ((fSlow61 * fRec18[((IOTA - iSlow63) & 2047)]) + (fSlow64 * (((fSlow65 * fRec18[((IOTA - iSlow66) & 2047)]) + (fSlow67 * fRec18[((IOTA - iSlow68) & 2047)])) + (fSlow69 * fRec18[((IOTA - iSlow70) & 2047)]))));
			fVec9[0] = fTemp37;
			float fTemp38 = ((0.00200000009f * fTemp37) + (0.998000026f * fVec9[1]));
			float fThen5 = (fTemp38 - (fSlow46 * (fTemp38 - (fSlow48 * float(tanhf(float((fSlow47 * fTemp38))))))));
			fVec10[(IOTA & 2047)] = ((fSlow52 * ((fTemp38 > 0.0f) ? fTemp38 : fThen5)) + fTemp29);
			float fTempFTZ10 = fVec10[((IOTA - iSlow71) & 2047)];
			fRec18[(IOTA & 2047)] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp39 = std::fabs(fRec18[((IOTA - 0) & 2047)]);
			float fTempFTZ11 = std::max<float>(fTemp39, ((fConst12 * fRec19[1]) + (fConst13 * fTemp39)));
			fRec19[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fSlow73 + (fRec20[1] - std::floor((fSlow73 + fRec20[1]))));
			fRec20[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp40 = std::max<float>(1.0f, ((fSlow72 * (fRec19[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec20[0]))])) + 4.0f));
			float fTemp41 = (fTemp40 + 4.99999987e-06f);
			int iTemp42 = int(fTemp41);
			float fTemp43 = std::floor(fTemp41);
			float fTemp44 = (0.5f * (((fTemp33 - fTemp35) * fRec14[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp36 + 1)))))) & 2047)]) + (((fRec18[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp42))))) & 2047)] * (0.0f - (fTemp40 + (-1.0f - fTemp43)))) + ((fTemp40 - fTemp43) * fRec18[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp42 + 1)))))) & 2047)])) + (fRec14[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp36))))) & 2047)] * (0.0f - (fTemp33 + (-1.0f - fTemp35)))))));
			float fTemp45 = ((fTemp24 + fTemp25) + fTemp44);
			float fTemp46 = (0.349999994f * (fRec4[0] * fTemp45));
			float fTemp47 = std::max<float>(40.0f, (fSlow75 * fTemp3));
			float fTemp48 = (fConst0 / fTemp47);
			int iTemp49 = int(fTemp48);
			float fTemp50 = float(iTemp49);
			float fTemp51 = (fTemp48 + (4.99999987e-06f - fTemp50));
			int iTemp52 = int(fTemp51);
			float fTemp53 = (fTemp50 + std::floor(fTemp51));
			float fTemp54 = (fTemp48 - fTemp53);
			float fTemp55 = (fTemp48 + (-1.0f - fTemp53));
			float fTemp56 = (fTemp48 + (-2.0f - fTemp53));
			float fTemp57 = ((((fRec3[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp52)) + 1)) & 2047)] * (0.0f - fTemp54)) * (0.0f - (0.5f * fTemp55))) * (0.0f - (0.333333343f * fTemp56))) + ((fTemp48 + (1.0f - fTemp53)) * ((((fRec3[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp52 + 1))) + 1)) & 2047)] * (0.0f - fTemp55)) * (0.0f - (0.5f * fTemp56))) + (0.5f * ((fTemp54 * fRec3[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp52 + 2))) + 1)) & 2047)]) * (0.0f - fTemp56)))) + (0.166666672f * ((fTemp54 * fTemp55) * fRec3[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp52 + 3))) + 1)) & 2047)])))));
			fVec11[0] = fTemp57;
			float fTemp58 = ((0.00200000009f * fTemp57) + (0.998000026f * fVec11[1]));
			float fThen6 = (fTemp58 - (fSlow76 * (fTemp58 - (fSlow78 * float(tanhf(float((fSlow77 * fTemp58))))))));
			fVec12[(IOTA & 8191)] = (fTemp46 + (((fTemp58 > 0.0f) ? fTemp58 : fThen6) * std::pow(0.00100000005f, (fSlow79 / fTemp47))));
			float fTempFTZ13 = fVec12[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp49 + -1)))) & 8191)];
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp59 = std::fabs(fRec3[((IOTA - 0) & 2047)]);
			float fTempFTZ14 = std::max<float>(fTemp59, ((fConst12 * fRec2[1]) + (fConst13 * fTemp59)));
			fRec2[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp60 = (fRec21[1] + (fSlow80 * fTemp3));
			float fTempFTZ15 = (fTemp60 - std::floor(fTemp60));
			fRec21[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp61 = std::max<float>(1.0f, ((fSlow3 * ((fRec2[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec21[0]))]) / fTemp47)) + 4.0f));
			float fTemp62 = (fTemp61 + 4.99999987e-06f);
			float fTemp63 = std::floor(fTemp62);
			int iTemp64 = int(fTemp62);
			float fTemp65 = std::max<float>(40.0f, (fSlow81 * fTemp3));
			float fTemp66 = (fConst0 / fTemp65);
			int iTemp67 = int(fTemp66);
			float fTemp68 = float(iTemp67);
			float fTemp69 = (fTemp66 + (4.99999987e-06f - fTemp68));
			int iTemp70 = int(fTemp69);
			float fTemp71 = (fTemp68 + std::floor(fTemp69));
			float fTemp72 = (fTemp66 - fTemp71);
			float fTemp73 = (fTemp66 + (-1.0f - fTemp71));
			float fTemp74 = (fTemp66 + (-2.0f - fTemp71));
			float fTemp75 = ((((fRec23[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp70)) + 1)) & 2047)] * (0.0f - fTemp72)) * (0.0f - (0.5f * fTemp73))) * (0.0f - (0.333333343f * fTemp74))) + ((fTemp66 + (1.0f - fTemp71)) * ((((fRec23[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp70 + 1))) + 1)) & 2047)] * (0.0f - fTemp73)) * (0.0f - (0.5f * fTemp74))) + (0.5f * ((fTemp72 * fRec23[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp70 + 2))) + 1)) & 2047)]) * (0.0f - fTemp74)))) + (0.166666672f * ((fTemp72 * fTemp73) * fRec23[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp70 + 3))) + 1)) & 2047)])))));
			fVec13[0] = fTemp75;
			float fTemp76 = ((0.00200000009f * fTemp75) + (0.998000026f * fVec13[1]));
			float fThen7 = (fTemp76 - (fSlow76 * (fTemp76 - (fSlow78 * float(tanhf(float((fSlow77 * fTemp76))))))));
			fVec14[(IOTA & 8191)] = (fTemp46 + (((fTemp76 > 0.0f) ? fTemp76 : fThen7) * std::pow(0.00100000005f, (fSlow79 / fTemp65))));
			float fTempFTZ16 = fVec14[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp67 + -1)))) & 8191)];
			fRec23[(IOTA & 2047)] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp77 = std::fabs(fRec23[((IOTA - 0) & 2047)]);
			float fTempFTZ17 = std::max<float>(fTemp77, ((fConst12 * fRec22[1]) + (fConst13 * fTemp77)));
			fRec22[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp78 = (fRec24[1] + (fSlow82 * fTemp3));
			float fTempFTZ18 = (fTemp78 - std::floor(fTemp78));
			fRec24[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp79 = std::max<float>(1.0f, ((fSlow3 * ((fRec22[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec24[0]))]) / fTemp65)) + 4.0f));
			float fTemp80 = (fTemp79 + 4.99999987e-06f);
			float fTemp81 = std::floor(fTemp80);
			int iTemp82 = int(fTemp80);
			float fTemp83 = std::max<float>(40.0f, (fSlow83 * fTemp3));
			float fTemp84 = (fConst0 / fTemp83);
			int iTemp85 = int(fTemp84);
			float fTemp86 = float(iTemp85);
			float fTemp87 = (fTemp84 + (4.99999987e-06f - fTemp86));
			int iTemp88 = int(fTemp87);
			float fTemp89 = (fTemp86 + std::floor(fTemp87));
			float fTemp90 = (fTemp84 - fTemp89);
			float fTemp91 = (fTemp84 + (-1.0f - fTemp89));
			float fTemp92 = (fTemp84 + (-2.0f - fTemp89));
			float fTemp93 = ((((fRec25[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp88)) + 1)) & 2047)] * (0.0f - fTemp90)) * (0.0f - (0.5f * fTemp91))) * (0.0f - (0.333333343f * fTemp92))) + ((fTemp84 + (1.0f - fTemp89)) * ((((fRec25[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp88 + 1))) + 1)) & 2047)] * (0.0f - fTemp91)) * (0.0f - (0.5f * fTemp92))) + (0.5f * ((fTemp90 * fRec25[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp88 + 2))) + 1)) & 2047)]) * (0.0f - fTemp92)))) + (0.166666672f * ((fTemp90 * fTemp91) * fRec25[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp88 + 3))) + 1)) & 2047)])))));
			fVec15[0] = fTemp93;
			float fTemp94 = ((0.00200000009f * fTemp93) + (0.998000026f * fVec15[1]));
			float fThen8 = (fTemp94 - (fSlow76 * (fTemp94 - (fSlow78 * float(tanhf(float((fSlow77 * fTemp94))))))));
			fVec16[(IOTA & 8191)] = ((((fTemp94 > 0.0f) ? fTemp94 : fThen8) * std::pow(0.00100000005f, (fSlow79 / fTemp83))) + fTemp46);
			float fTempFTZ19 = fVec16[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp85 + -1)))) & 8191)];
			fRec25[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp95 = std::fabs(fRec25[((IOTA - 0) & 2047)]);
			float fTempFTZ20 = std::max<float>(fTemp95, ((fConst12 * fRec26[1]) + (fConst13 * fTemp95)));
			fRec26[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp96 = (fRec27[1] + (fSlow84 * fTemp3));
			float fTempFTZ21 = (fTemp96 - std::floor(fTemp96));
			fRec27[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp97 = std::max<float>(1.0f, ((fSlow3 * ((fRec26[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec27[0]))]) / fTemp83)) + 4.0f));
			float fTemp98 = (fTemp97 + 4.99999987e-06f);
			int iTemp99 = int(fTemp98);
			float fTemp100 = std::floor(fTemp98);
			float fTemp101 = (fSlow1 * (((fTemp61 - fTemp63) * fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp64 + 1)))))) & 2047)]) + ((((fTemp79 - fTemp81) * fRec23[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp82 + 1)))))) & 2047)]) + (((fRec25[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp99))))) & 2047)] * (0.0f - (fTemp97 + (-1.0f - fTemp100)))) + ((fTemp97 - fTemp100) * fRec25[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp99 + 1)))))) & 2047)])) + (fRec23[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp82))))) & 2047)] * (0.0f - (fTemp79 + (-1.0f - fTemp81)))))) + (fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp64))))) & 2047)] * (0.0f - (fTemp61 + (-1.0f - fTemp63)))))));
			fVec17[0] = (fTemp45 + fTemp101);
			float fTempFTZ22 = ((fTemp101 + (fTemp44 + (fTemp25 + ((0.995000005f * fRec1[1]) + fTemp24)))) - fVec17[1]);
			fRec1[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fRec1[0] - (fConst19 * ((fConst20 * fRec0[2]) + (fConst21 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fRec1[0] - (fConst27 * ((fConst28 * fRec28[2]) + (fConst29 * fRec28[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fRec1[0] - (fConst35 * ((fConst36 * fRec29[2]) + (fConst37 * fRec29[1]))));
			fRec29[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (fRec1[0] - (fConst43 * ((fConst44 * fRec30[2]) + (fConst45 * fRec30[1]))));
			fRec30[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (fRec1[0] - (fConst51 * ((fConst52 * fRec31[2]) + (fConst53 * fRec31[1]))));
			fRec31[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fRec1[0] - (fConst59 * ((fConst60 * fRec32[2]) + (fConst61 * fRec32[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (fRec1[0] - (fConst68 * ((fConst69 * fRec33[2]) + (fConst70 * fRec33[1]))));
			fRec33[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (fRec1[0] - (fConst76 * ((fConst77 * fRec34[2]) + (fConst78 * fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTemp102 = ((fConst5 * fRec0[2]) + (((fConst26 * fRec28[2]) + (((fConst34 * fRec29[2]) + (((fConst42 * fRec30[2]) + (((0.899999976f * ((fConst50 * fRec31[0]) + (fConst58 * fRec32[0]))) + ((fConst62 * fRec32[2]) + ((fConst67 * fRec33[2]) + ((fConst66 * fRec33[0]) + (((fConst75 * fRec34[2]) + ((0.219999999f * fRec1[0]) + (fConst74 * fRec34[0]))) + (fConst79 * fRec31[2])))))) + (fConst41 * fRec30[0]))) + (fConst33 * fRec29[0]))) + (fConst25 * fRec28[0]))) + (fConst4 * fRec0[0])));
			float fTemp103 = float(tanhf(float((fSlow0 * (fTemp102 - (0.0599999987f * FaustSitarDSP_faustpower3_f(fTemp102)))))));
			output0[i0] = FAUSTFLOAT(fTemp103);
			output1[i0] = FAUSTFLOAT(fTemp103);
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec5[1] = iRec5[0];
			fRec4[1] = fRec4[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fVec3[1] = fVec3[0];
			iRec10[1] = iRec10[0];
			IOTA = (IOTA + 1);
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			iVec5[1] = iVec5[0];
			fRec16[1] = fRec16[0];
			iVec6[1] = iVec6[0];
			iRec15[1] = iRec15[0];
			fVec7[1] = fVec7[0];
			fRec13[1] = fRec13[0];
			fRec17[1] = fRec17[0];
			fVec9[1] = fVec9[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fVec11[1] = fVec11[0];
			fRec2[1] = fRec2[0];
			fRec21[1] = fRec21[0];
			fVec13[1] = fVec13[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			fVec15[1] = fVec15[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fVec17[1] = fVec17[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
		}
	}

};

#endif
