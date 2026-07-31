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
	float fRec9[2];
	FAUSTFLOAT fHslider7;
	float fRec10[2];
	float fVec3[2];
	float fRec7[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	float fConst15;
	FAUSTFLOAT fHslider10;
	float fConst17;
	float fConst20;
	int iRec13[2];
	float fConst21;
	float fConst22;
	float fRec12[3];
	float fConst23;
	float fConst24;
	float fRec11[3];
	float fConst25;
	int IOTA;
	float fVec4[8192];
	float fRec6[2048];
	float fConst26;
	float fConst27;
	float fRec14[2];
	float fRec15[2];
	FAUSTFLOAT fHslider11;
	float fConst28;
	int iVec5[2];
	float fRec19[2];
	int iVec6[2];
	int iRec18[2];
	float fVec7[2];
	float fRec20[2];
	float fVec8[2048];
	float fRec17[2048];
	float fRec16[2];
	float fConst29;
	float fRec21[2];
	float fVec9[2];
	float fRec23[2];
	float fVec10[2048];
	float fRec22[2048];
	float fRec24[2];
	float fConst30;
	float fRec25[2];
	FAUSTFLOAT fHslider12;
	float fVec11[2];
	float fRec26[2];
	float fVec12[8192];
	float fRec3[2048];
	float fRec2[2];
	float fRec27[2];
	float fVec13[2];
	float fRec30[2];
	float fVec14[8192];
	float fRec29[2048];
	float fRec28[2];
	float fRec31[2];
	float fVec15[2];
	float fRec33[2];
	float fVec16[8192];
	float fRec32[2048];
	float fRec34[2];
	float fRec35[2];
	float fVec17[2];
	float fRec1[2];
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec0[3];
	float fConst38;
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec36[3];
	float fConst46;
	float fConst47;
	float fConst48;
	float fConst49;
	float fRec37[3];
	float fConst50;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec38[3];
	float fConst62;
	float fConst63;
	float fConst64;
	float fConst65;
	float fConst66;
	float fRec39[3];
	float fConst70;
	float fConst71;
	float fConst72;
	float fConst73;
	float fConst74;
	float fRec40[3];
	float fConst78;
	float fConst79;
	float fConst80;
	float fConst81;
	float fConst82;
	float fRec41[3];
	float fConst86;
	float fConst87;
	float fConst88;
	float fConst89;
	float fConst90;
	float fRec42[3];
	float fConst91;
	
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
		float fConst1 = std::tan((11309.7334f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.333333343f) / fConst1) + 1.0f);
		fConst4 = (0.400000006f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
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
		fConst32 = (((fConst2 + -0.333333343f) / fConst1) + 1.0f);
		fConst33 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst1))));
		float fConst34 = std::tan((1413.71667f / fConst0));
		float fConst35 = (1.0f / fConst34);
		float fConst36 = (((fConst35 + 0.25f) / fConst34) + 1.0f);
		float fConst37 = (fConst34 * fConst36);
		fConst38 = (1.0f / fConst37);
		fConst39 = (1.0f / fConst36);
		fConst40 = (((fConst35 + -0.25f) / fConst34) + 1.0f);
		fConst41 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst34))));
		float fConst42 = std::tan((6911.50391f / fConst0));
		float fConst43 = (1.0f / fConst42);
		float fConst44 = (((fConst43 + 0.285714298f) / fConst42) + 1.0f);
		float fConst45 = (fConst42 * fConst44);
		fConst46 = (1.0f / fConst45);
		fConst47 = (1.0f / fConst44);
		fConst48 = (((fConst43 + -0.285714298f) / fConst42) + 1.0f);
		fConst49 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst42))));
		fConst50 = (0.0f - (0.600000024f / fConst45));
		float fConst51 = std::tan((4398.22949f / fConst0));
		float fConst52 = (1.0f / fConst51);
		float fConst53 = (((fConst52 + 0.333333343f) / fConst51) + 1.0f);
		fConst54 = (0.649999976f / (fConst51 * fConst53));
		fConst55 = (0.0f - fConst54);
		fConst56 = (1.0f / fConst53);
		fConst57 = (((fConst52 + -0.333333343f) / fConst51) + 1.0f);
		fConst58 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst51))));
		float fConst59 = std::tan((2827.43335f / fConst0));
		float fConst60 = (1.0f / fConst59);
		float fConst61 = (((fConst60 + 0.285714298f) / fConst59) + 1.0f);
		fConst62 = (0.75f / (fConst59 * fConst61));
		fConst63 = (0.0f - fConst62);
		fConst64 = (1.0f / fConst61);
		fConst65 = (((fConst60 + -0.285714298f) / fConst59) + 1.0f);
		fConst66 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst59))));
		float fConst67 = std::tan((879.645935f / fConst0));
		float fConst68 = (1.0f / fConst67);
		float fConst69 = (((fConst68 + 0.25f) / fConst67) + 1.0f);
		fConst70 = (0.850000024f / (fConst67 * fConst69));
		fConst71 = (0.0f - fConst70);
		fConst72 = (1.0f / fConst69);
		fConst73 = (((fConst68 + -0.25f) / fConst67) + 1.0f);
		fConst74 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst67))));
		float fConst75 = std::tan((565.486694f / fConst0));
		float fConst76 = (1.0f / fConst75);
		float fConst77 = (((fConst76 + 0.222222224f) / fConst75) + 1.0f);
		fConst78 = (1.10000002f / (fConst75 * fConst77));
		fConst79 = (0.0f - fConst78);
		fConst80 = (1.0f / fConst77);
		fConst81 = (((fConst76 + -0.222222224f) / fConst75) + 1.0f);
		fConst82 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst75))));
		float fConst83 = std::tan((345.575195f / fConst0));
		float fConst84 = (1.0f / fConst83);
		float fConst85 = (((fConst84 + 0.200000003f) / fConst83) + 1.0f);
		fConst86 = (1.25f / (fConst83 * fConst85));
		fConst87 = (0.0f - fConst86);
		fConst88 = (1.0f / fConst85);
		fConst89 = (((fConst84 + -0.200000003f) / fConst83) + 1.0f);
		fConst90 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst83))));
		fConst91 = (0.0f - (0.600000024f / fConst37));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.29999999999999999f);
		fHslider1 = FAUSTFLOAT(0.84999999999999998f);
		fHslider2 = FAUSTFLOAT(0.34999999999999998f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(138.59999999999999f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.01f);
		fHslider6 = FAUSTFLOAT(4.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(5.0f);
		fHslider10 = FAUSTFLOAT(0.59999999999999998f);
		fHslider11 = FAUSTFLOAT(111.0f);
		fHslider12 = FAUSTFLOAT(1.2f);
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
			fRec10[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iRec13[l10] = 0;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec12[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		IOTA = 0;
		for (int l13 = 0; (l13 < 8192); l13 = (l13 + 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2048); l14 = (l14 + 1)) {
			fRec6[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iVec5[l17] = 0;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec19[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			iVec6[l19] = 0;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			iRec18[l20] = 0;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fVec7[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec20[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2048); l23 = (l23 + 1)) {
			fVec8[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2048); l24 = (l24 + 1)) {
			fRec17[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec16[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec21[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fVec9[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec23[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2048); l29 = (l29 + 1)) {
			fVec10[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2048); l30 = (l30 + 1)) {
			fRec22[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec24[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec25[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fVec11[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec26[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 8192); l35 = (l35 + 1)) {
			fVec12[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2048); l36 = (l36 + 1)) {
			fRec3[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec2[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec27[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fVec13[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec30[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 8192); l41 = (l41 + 1)) {
			fVec14[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2048); l42 = (l42 + 1)) {
			fRec29[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec28[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec31[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fVec15[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec33[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 8192); l47 = (l47 + 1)) {
			fVec16[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2048); l48 = (l48 + 1)) {
			fRec32[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec34[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec35[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fVec17[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec1[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec0[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec36[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec37[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec38[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec39[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec40[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec41[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec42[l60] = 0.0f;
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
		ui_interface->declare(&fHslider11, "unit", "Hz");
		ui_interface->addHorizontalSlider("chikari_freq", &fHslider11, FAUSTFLOAT(111.0f), FAUSTFLOAT(55.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(138.600006f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.349999994f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("strike", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider9, "unit", "s");
		ui_interface->addHorizontalSlider("sustain", &fHslider9, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider12, "unit", "Hz");
		ui_interface->addHorizontalSlider("symp_drift", &fHslider12, FAUSTFLOAT(1.20000005f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider1, FAUSTFLOAT(0.850000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider10, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider4, "style", "check");
		ui_interface->addHorizontalSlider("vibrato", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider5, FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider6, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (134.4375f * float(fHslider0));
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
		float fSlow14 = (((2.0f * fSlow2) * fSlow12) + 1.0f);
		float fSlow15 = float(fHslider9);
		float fSlow16 = std::max<float>(0.400000006f, (fSlow15 * (1.0f - ((0.349999994f * fSlow2) * fSlow12))));
		float fSlow17 = float(fHslider10);
		float fSlow18 = (fConst15 * (fSlow17 * float((iSlow10 + (fSlow9 == 0.0f)))));
		float fSlow19 = (iSlow11 ? 0.649999976f : 0.400000006f);
		float fSlow20 = (1350.0f * fSlow2);
		float fSlow21 = (fConst11 * fSlow5);
		float fSlow22 = float(fHslider11);
		float fSlow23 = std::max<float>(40.0f, (3.0f * fSlow22));
		float fSlow24 = (945.0f * (fSlow2 / fSlow23));
		float fSlow25 = (fConst28 * fSlow17);
		int iSlow26 = (fSlow9 == 1.0f);
		float fSlow27 = std::max<float>(0.400000006f, (1.79999995f * (1.0f - (0.245000005f * fSlow2))));
		float fSlow28 = std::pow(0.00100000005f, (1.0f / (fSlow23 * fSlow27)));
		float fSlow29 = (fConst0 / fSlow23);
		int iSlow30 = int(fSlow29);
		float fSlow31 = float(iSlow30);
		float fSlow32 = (fSlow29 + (-0.499989986f - fSlow31));
		int iSlow33 = (std::min<int>(1024, std::max<int>(0, int(fSlow32))) + 1);
		float fSlow34 = (fSlow31 + std::floor(fSlow32));
		float fSlow35 = ((fSlow34 + (1.0f - fSlow29)) / (fSlow29 + (1.0f - fSlow34)));
		float fSlow36 = ((14.0f * fSlow2) + 1.0f);
		float fSlow37 = (1.0f / fSlow36);
		float fSlow38 = ((1.39999998f * fSlow2) + 1.0f);
		float fSlow39 = (1.0f / fSlow38);
		int iSlow40 = std::min<int>(16384, std::max<int>(0, iSlow30));
		float fSlow41 = (fConst29 * fSlow22);
		float fSlow42 = std::max<float>(40.0f, (2.0f * fSlow22));
		float fSlow43 = std::pow(0.00100000005f, (1.0f / (fSlow27 * fSlow42)));
		float fSlow44 = (fConst0 / fSlow42);
		int iSlow45 = int(fSlow44);
		float fSlow46 = float(iSlow45);
		float fSlow47 = (fSlow44 + (-0.499989986f - fSlow46));
		int iSlow48 = (std::min<int>(1024, std::max<int>(0, int(fSlow47))) + 1);
		float fSlow49 = (fSlow46 + std::floor(fSlow47));
		float fSlow50 = ((fSlow49 + (1.0f - fSlow44)) / (fSlow44 + (1.0f - fSlow49)));
		int iSlow51 = std::min<int>(16384, std::max<int>(0, iSlow45));
		float fSlow52 = (945.0f * (fSlow2 / fSlow42));
		float fSlow53 = (fConst30 * fSlow22);
		float fSlow54 = float(fHslider12);
		float fSlow55 = std::max<float>(((0.5f * fSlow54) + (3.0f * fSlow5)), 40.0f);
		float fSlow56 = ((9.0f * fSlow2) + 1.0f);
		float fSlow57 = (1.0f / fSlow56);
		float fSlow58 = ((0.899999976f * fSlow2) + 1.0f);
		float fSlow59 = (1.0f / fSlow58);
		float fSlow60 = (1.0f / std::max<float>(0.400000006f, (1.5f * (fSlow15 * (1.0f - (0.157499999f * fSlow2))))));
		float fSlow61 = (fConst11 * fSlow55);
		float fSlow62 = std::max<float>(((2.0f * fSlow5) - (0.400000006f * fSlow54)), 40.0f);
		float fSlow63 = (fConst11 * fSlow62);
		float fSlow64 = std::max<float>(((0.600000024f * fSlow54) + (1.5f * fSlow5)), 40.0f);
		float fSlow65 = (fConst11 * fSlow64);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow4;
			int iTemp0 = (fSlow4 > fVec0[1]);
			iVec1[0] = iTemp0;
			iRec5[0] = ((iTemp0 > iVec1[1]) + ((iTemp0 <= iVec1[1]) * (iRec5[1] + (iRec5[1] > 0))));
			float fTemp1 = float(iRec5[0]);
			float fTemp2 = std::max<float>(0.0f, std::min<float>((fConst9 * fTemp1), (1.0f - (fConst10 * (fTemp1 - fConst8)))));
			float fTempFTZ0 = ((fConst7 * fRec4[1]) + (fConst6 * fTemp2));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow7 + (fRec9[1] - std::floor((fSlow7 + fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow8 + (fConst7 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp3 = std::pow(2.0f, (0.000833333354f * fRec10[0]));
			float fTemp4 = (((fSlow6 * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec9[0]))]) + 1.0f) * fTemp3);
			float fTemp5 = std::max<float>(40.0f, (fSlow5 * fTemp4));
			float fTemp6 = (fConst0 / fTemp5);
			int iTemp7 = int(fTemp6);
			float fTemp8 = float(iTemp7);
			float fTemp9 = (fTemp6 + (-0.499989986f - fTemp8));
			float fTemp10 = fRec6[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp9))) + 1)) & 2047)];
			fVec3[0] = fTemp10;
			float fTemp11 = (fTemp8 + std::floor(fTemp9));
			float fTempFTZ3 = (fVec3[1] - (((fTemp11 + (1.0f - fTemp6)) * (fRec7[1] - fTemp10)) / (fTemp6 + (1.0f - fTemp11))));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp12 = ((0.00200000009f * fRec7[0]) + (0.998000026f * fRec7[1]));
			float fThen1 = (float(tanhf(float((fTemp12 * fSlow13)))) / fSlow13);
			float fElse1 = (float(tanhf(float((fTemp12 * fSlow14)))) / fSlow14);
			iRec13[0] = ((1103515245 * iRec13[1]) + 12345);
			float fTempFTZ4 = ((4.65661287e-10f * float(iRec13[0])) - (fConst20 * ((fConst21 * fRec12[2]) + (fConst22 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((fConst20 * (fRec12[2] + (fRec12[0] + (2.0f * fRec12[1])))) - (fConst15 * ((fConst23 * fRec11[2]) + (fConst24 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp13 = (((fConst17 * fRec11[0]) + (fConst25 * fRec11[1])) + (fConst17 * fRec11[2]));
			fVec4[(IOTA & 8191)] = ((((fTemp12 > 0.0f) ? fElse1 : fThen1) * std::pow(0.00100000005f, (1.0f / (fTemp5 * fSlow16)))) + (fSlow18 * ((fSlow19 * fTemp13) * fTemp2)));
			float fTempFTZ6 = fVec4[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp7))) & 8191)];
			fRec6[(IOTA & 2047)] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp14 = std::fabs(fRec6[((IOTA - 0) & 2047)]);
			float fTempFTZ7 = std::max<float>(fTemp14, ((fConst26 * fRec14[1]) + (fConst27 * fTemp14)));
			fRec14[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp15 = (fRec15[1] + (fSlow21 * fTemp4));
			float fTempFTZ8 = (fTemp15 - std::floor(fTemp15));
			fRec15[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp16 = std::max<float>(1.0f, ((fSlow20 * (((fRec14[0] * fSlow12) * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec15[0]))]) / fTemp5)) + 4.0f));
			float fTemp17 = (fTemp16 + 4.99999987e-06f);
			int iTemp18 = int(fTemp17);
			float fTemp19 = std::floor(fTemp17);
			float fTemp20 = (fRec6[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp18))))) & 2047)] * (0.0f - (fTemp16 + (-1.0f - fTemp19))));
			float fTemp21 = ((fTemp16 - fTemp19) * fRec6[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp18 + 1)))))) & 2047)]);
			iVec5[0] = iSlow26;
			int iTemp22 = ((iSlow26 > iVec5[1]) | (iTemp0 & iSlow26));
			float fThen3 = std::max<float>(0.0f, (fRec19[1] + -1.0f));
			float fTempFTZ9 = (iTemp22 ? 150.0f : fThen3);
			fRec19[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			int iTemp23 = (fRec19[0] > 0.0f);
			iVec6[0] = iTemp23;
			iRec18[0] = (((iRec18[1] + (iRec18[1] > 0)) * (iTemp23 <= iVec6[1])) + (iTemp23 > iVec6[1]));
			float fTemp24 = float(iRec18[0]);
			float fTemp25 = (fSlow25 * ((fTemp13 * std::max<float>(0.0f, std::min<float>((fConst9 * fTemp24), (1.0f - (fConst10 * (fTemp24 - fConst8)))))) * float(iTemp22)));
			float fTemp26 = fRec17[((IOTA - iSlow33) & 2047)];
			fVec7[0] = fTemp26;
			float fTempFTZ10 = (fVec7[1] - (fSlow35 * (fRec20[1] - fTemp26)));
			fRec20[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp27 = ((0.00200000009f * fRec20[0]) + (0.998000026f * fRec20[1]));
			float fThen4 = (fSlow37 * float(tanhf(float((fSlow36 * fTemp27)))));
			float fElse4 = (fSlow39 * float(tanhf(float((fSlow38 * fTemp27)))));
			fVec8[(IOTA & 2047)] = (fTemp25 + (fSlow28 * ((fTemp27 > 0.0f) ? fElse4 : fThen4)));
			float fTempFTZ11 = fVec8[((IOTA - iSlow40) & 2047)];
			fRec17[(IOTA & 2047)] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp28 = std::fabs(fRec17[((IOTA - 0) & 2047)]);
			float fTempFTZ12 = std::max<float>(fTemp28, ((fConst26 * fRec16[1]) + (fConst27 * fTemp28)));
			fRec16[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fSlow41 + (fRec21[1] - std::floor((fSlow41 + fRec21[1]))));
			fRec21[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp29 = std::max<float>(1.0f, ((fSlow24 * (fRec16[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec21[0]))])) + 4.0f));
			float fTemp30 = (fTemp29 + 4.99999987e-06f);
			float fTemp31 = std::floor(fTemp30);
			int iTemp32 = int(fTemp30);
			float fTemp33 = fRec22[((IOTA - iSlow48) & 2047)];
			fVec9[0] = fTemp33;
			float fTempFTZ14 = (fVec9[1] - (fSlow50 * (fRec23[1] - fTemp33)));
			fRec23[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp34 = ((0.00200000009f * fRec23[0]) + (0.998000026f * fRec23[1]));
			float fThen5 = (fSlow37 * float(tanhf(float((fSlow36 * fTemp34)))));
			float fElse5 = (fSlow39 * float(tanhf(float((fSlow38 * fTemp34)))));
			fVec10[(IOTA & 2047)] = ((fSlow43 * ((fTemp34 > 0.0f) ? fElse5 : fThen5)) + fTemp25);
			float fTempFTZ15 = fVec10[((IOTA - iSlow51) & 2047)];
			fRec22[(IOTA & 2047)] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp35 = std::fabs(fRec22[((IOTA - 0) & 2047)]);
			float fTempFTZ16 = std::max<float>(fTemp35, ((fConst26 * fRec24[1]) + (fConst27 * fTemp35)));
			fRec24[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fSlow53 + (fRec25[1] - std::floor((fSlow53 + fRec25[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp36 = std::max<float>(1.0f, ((fSlow52 * (fRec24[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec25[0]))])) + 4.0f));
			float fTemp37 = (fTemp36 + 4.99999987e-06f);
			int iTemp38 = int(fTemp37);
			float fTemp39 = std::floor(fTemp37);
			float fTemp40 = (0.5f * (((fTemp29 - fTemp31) * fRec17[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp32 + 1)))))) & 2047)]) + (((fRec22[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp38))))) & 2047)] * (0.0f - (fTemp36 + (-1.0f - fTemp39)))) + ((fTemp36 - fTemp39) * fRec22[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp38 + 1)))))) & 2047)])) + (fRec17[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp32))))) & 2047)] * (0.0f - (fTemp29 + (-1.0f - fTemp31)))))));
			float fTemp41 = ((fTemp20 + fTemp21) + fTemp40);
			float fTemp42 = (0.349999994f * (fRec4[0] * fTemp41));
			float fTemp43 = std::max<float>(40.0f, (fSlow55 * fTemp3));
			float fTemp44 = (fConst0 / fTemp43);
			int iTemp45 = int(fTemp44);
			float fTemp46 = float(iTemp45);
			float fTemp47 = (fTemp44 + (-0.499989986f - fTemp46));
			float fTemp48 = fRec3[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp47))) + 1)) & 2047)];
			fVec11[0] = fTemp48;
			float fTemp49 = (fTemp46 + std::floor(fTemp47));
			float fTempFTZ18 = (fVec11[1] - (((fTemp49 + (1.0f - fTemp44)) * (fRec26[1] - fTemp48)) / (fTemp44 + (1.0f - fTemp49))));
			fRec26[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp50 = ((0.00200000009f * fRec26[0]) + (0.998000026f * fRec26[1]));
			float fThen6 = (fSlow57 * float(tanhf(float((fSlow56 * fTemp50)))));
			float fElse6 = (fSlow59 * float(tanhf(float((fSlow58 * fTemp50)))));
			fVec12[(IOTA & 8191)] = (fTemp42 + (((fTemp50 > 0.0f) ? fElse6 : fThen6) * std::pow(0.00100000005f, (fSlow60 / fTemp43))));
			float fTempFTZ19 = fVec12[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp45))) & 8191)];
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp51 = std::fabs(fRec3[((IOTA - 0) & 2047)]);
			float fTempFTZ20 = std::max<float>(fTemp51, ((fConst26 * fRec2[1]) + (fConst27 * fTemp51)));
			fRec2[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp52 = (fRec27[1] + (fSlow61 * fTemp3));
			float fTempFTZ21 = (fTemp52 - std::floor(fTemp52));
			fRec27[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp53 = std::max<float>(1.0f, ((fSlow3 * ((fRec2[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec27[0]))]) / fTemp43)) + 4.0f));
			float fTemp54 = (fTemp53 + 4.99999987e-06f);
			float fTemp55 = std::floor(fTemp54);
			int iTemp56 = int(fTemp54);
			float fTemp57 = std::max<float>(40.0f, (fSlow62 * fTemp3));
			float fTemp58 = (fConst0 / fTemp57);
			int iTemp59 = int(fTemp58);
			float fTemp60 = float(iTemp59);
			float fTemp61 = (fTemp58 + (-0.499989986f - fTemp60));
			float fTemp62 = fRec29[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp61))) + 1)) & 2047)];
			fVec13[0] = fTemp62;
			float fTemp63 = (fTemp60 + std::floor(fTemp61));
			float fTempFTZ22 = (fVec13[1] - (((fTemp63 + (1.0f - fTemp58)) * (fRec30[1] - fTemp62)) / (fTemp58 + (1.0f - fTemp63))));
			fRec30[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTemp64 = ((0.00200000009f * fRec30[0]) + (0.998000026f * fRec30[1]));
			float fThen7 = (fSlow57 * float(tanhf(float((fSlow56 * fTemp64)))));
			float fElse7 = (fSlow59 * float(tanhf(float((fSlow58 * fTemp64)))));
			fVec14[(IOTA & 8191)] = (fTemp42 + (((fTemp64 > 0.0f) ? fElse7 : fThen7) * std::pow(0.00100000005f, (fSlow60 / fTemp57))));
			float fTempFTZ23 = fVec14[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp59))) & 8191)];
			fRec29[(IOTA & 2047)] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp65 = std::fabs(fRec29[((IOTA - 0) & 2047)]);
			float fTempFTZ24 = std::max<float>(fTemp65, ((fConst26 * fRec28[1]) + (fConst27 * fTemp65)));
			fRec28[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTemp66 = (fRec31[1] + (fSlow63 * fTemp3));
			float fTempFTZ25 = (fTemp66 - std::floor(fTemp66));
			fRec31[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTemp67 = std::max<float>(1.0f, ((fSlow3 * ((fRec28[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec31[0]))]) / fTemp57)) + 4.0f));
			float fTemp68 = (fTemp67 + 4.99999987e-06f);
			float fTemp69 = std::floor(fTemp68);
			int iTemp70 = int(fTemp68);
			float fTemp71 = std::max<float>(40.0f, (fSlow64 * fTemp3));
			float fTemp72 = (fConst0 / fTemp71);
			int iTemp73 = int(fTemp72);
			float fTemp74 = float(iTemp73);
			float fTemp75 = (fTemp72 + (-0.499989986f - fTemp74));
			float fTemp76 = fRec32[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp75))) + 1)) & 2047)];
			fVec15[0] = fTemp76;
			float fTemp77 = (fTemp74 + std::floor(fTemp75));
			float fTempFTZ26 = (fVec15[1] - (((fTemp77 + (1.0f - fTemp72)) * (fRec33[1] - fTemp76)) / (fTemp72 + (1.0f - fTemp77))));
			fRec33[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTemp78 = ((0.00200000009f * fRec33[0]) + (0.998000026f * fRec33[1]));
			float fThen8 = (fSlow57 * float(tanhf(float((fSlow56 * fTemp78)))));
			float fElse8 = (fSlow59 * float(tanhf(float((fSlow58 * fTemp78)))));
			fVec16[(IOTA & 8191)] = ((((fTemp78 > 0.0f) ? fElse8 : fThen8) * std::pow(0.00100000005f, (fSlow60 / fTemp71))) + fTemp42);
			float fTempFTZ27 = fVec16[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp73))) & 8191)];
			fRec32[(IOTA & 2047)] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTemp79 = std::fabs(fRec32[((IOTA - 0) & 2047)]);
			float fTempFTZ28 = std::max<float>(fTemp79, ((fConst26 * fRec34[1]) + (fConst27 * fTemp79)));
			fRec34[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTemp80 = (fRec35[1] + (fSlow65 * fTemp3));
			float fTempFTZ29 = (fTemp80 - std::floor(fTemp80));
			fRec35[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp81 = std::max<float>(1.0f, ((fSlow3 * ((fRec34[0] * ftbl0FaustSitarDSPSIG0[int((65536.0f * fRec35[0]))]) / fTemp71)) + 4.0f));
			float fTemp82 = (fTemp81 + 4.99999987e-06f);
			int iTemp83 = int(fTemp82);
			float fTemp84 = std::floor(fTemp82);
			float fTemp85 = (fSlow1 * (((fTemp53 - fTemp55) * fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp56 + 1)))))) & 2047)]) + ((((fTemp67 - fTemp69) * fRec29[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp70 + 1)))))) & 2047)]) + (((fRec32[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp83))))) & 2047)] * (0.0f - (fTemp81 + (-1.0f - fTemp84)))) + ((fTemp81 - fTemp84) * fRec32[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp83 + 1)))))) & 2047)])) + (fRec29[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp70))))) & 2047)] * (0.0f - (fTemp67 + (-1.0f - fTemp69)))))) + (fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp56))))) & 2047)] * (0.0f - (fTemp53 + (-1.0f - fTemp55)))))));
			fVec17[0] = (fTemp41 + fTemp85);
			float fTempFTZ30 = ((fTemp85 + (fTemp40 + (fTemp21 + ((0.995000005f * fRec1[1]) + fTemp20)))) - fVec17[1]);
			fRec1[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fRec1[0] - (fConst31 * ((fConst32 * fRec0[2]) + (fConst33 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (fRec1[0] - (fConst39 * ((fConst40 * fRec36[2]) + (fConst41 * fRec36[1]))));
			fRec36[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (fRec1[0] - (fConst47 * ((fConst48 * fRec37[2]) + (fConst49 * fRec37[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fRec1[0] - (fConst56 * ((fConst57 * fRec38[2]) + (fConst58 * fRec38[1]))));
			fRec38[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fRec1[0] - (fConst64 * ((fConst65 * fRec39[2]) + (fConst66 * fRec39[1]))));
			fRec39[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fRec1[0] - (fConst72 * ((fConst73 * fRec40[2]) + (fConst74 * fRec40[1]))));
			fRec40[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fRec1[0] - (fConst80 * ((fConst81 * fRec41[2]) + (fConst82 * fRec41[1]))));
			fRec41[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fRec1[0] - (fConst88 * ((fConst89 * fRec42[2]) + (fConst90 * fRec42[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTemp86 = ((fConst5 * fRec0[2]) + (((0.600000024f * ((fConst38 * fRec36[0]) + (fConst46 * fRec37[0]))) + ((fConst50 * fRec37[2]) + ((fConst55 * fRec38[2]) + ((fConst54 * fRec38[0]) + ((fConst63 * fRec39[2]) + ((fConst62 * fRec39[0]) + (((fConst71 * fRec40[2]) + (((fConst79 * fRec41[2]) + (((fConst87 * fRec42[2]) + ((0.200000003f * fRec1[0]) + (fConst86 * fRec42[0]))) + (fConst78 * fRec41[0]))) + (fConst70 * fRec40[0]))) + (fConst91 * fRec36[2])))))))) + (fConst4 * fRec0[0])));
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp86 - (0.0599999987f * FaustSitarDSP_faustpower3_f(fTemp86)))));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec5[1] = iRec5[0];
			fRec4[1] = fRec4[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fVec3[1] = fVec3[0];
			fRec7[1] = fRec7[0];
			iRec13[1] = iRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			IOTA = (IOTA + 1);
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			iVec5[1] = iVec5[0];
			fRec19[1] = fRec19[0];
			iVec6[1] = iVec6[0];
			iRec18[1] = iRec18[0];
			fVec7[1] = fVec7[0];
			fRec20[1] = fRec20[0];
			fRec16[1] = fRec16[0];
			fRec21[1] = fRec21[0];
			fVec9[1] = fVec9[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fVec11[1] = fVec11[0];
			fRec26[1] = fRec26[0];
			fRec2[1] = fRec2[0];
			fRec27[1] = fRec27[0];
			fVec13[1] = fVec13[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec31[1] = fRec31[0];
			fVec15[1] = fVec15[0];
			fRec33[1] = fRec33[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fVec17[1] = fVec17[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
		}
	}

};

#endif
