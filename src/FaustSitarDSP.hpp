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

static float FaustSitarDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustSitarDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float FaustSitarDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
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
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fConst6;
	float fConst16;
	float fConst23;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int iVec1[2];
	float fConst25;
	int iRec3[2];
	float fConst26;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec2[5];
	float fConst36;
	float fConst37;
	float fRec5[2];
	int iVec2[2];
	int iRec4[2];
	float fConst38;
	int IOTA;
	float fVec3[8192];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec1[2];
	FAUSTFLOAT fHslider5;
	float fRec7[2];
	float fConst45;
	float fConst52;
	float fConst54;
	float fConst55;
	float fConst60;
	float fConst61;
	float fConst62;
	float fConst63;
	float fRec8[5];
	float fRec10[2];
	int iVec4[2];
	int iRec9[2];
	float fVec5[8192];
	float fRec6[2];
	float fConst64;
	float fRec12[2];
	float fVec6[4096];
	float fRec11[2];
	float fVec7[3];
	float fConst65;
	float fConst66;
	float fConst67;
	float fRec0[3];
	float fConst72;
	float fConst73;
	float fConst74;
	float fConst75;
	float fRec13[3];
	float fConst80;
	float fConst81;
	float fConst82;
	float fConst83;
	float fRec14[3];
	float fConst88;
	float fConst89;
	float fConst90;
	float fConst91;
	float fRec15[3];
	float fConst92;
	float fConst97;
	float fConst98;
	float fConst99;
	float fConst100;
	float fRec16[3];
	float fConst105;
	float fConst106;
	float fConst107;
	float fConst108;
	float fRec17[3];
	float fConst113;
	float fConst114;
	float fConst115;
	float fConst116;
	float fRec18[3];
	float fConst117;
	float fConst122;
	float fConst123;
	float fConst124;
	float fConst125;
	float fRec19[3];
	float fConst130;
	float fConst131;
	float fConst132;
	float fConst133;
	float fRec20[3];
	float fConst134;
	float fConst135;
	float fConst136;
	float fConst137;
	float fConst138;
	float fConst142;
	float fConst143;
	float fConst144;
	float fConst145;
	float fRec21[3];
	float fConst146;
	float fConst147;
	FAUSTFLOAT fHslider6;
	float fVec8[8192];
	float fRec22[2];
	float fVec9[4096];
	float fRec23[2];
	float fVec10[4096];
	float fRec24[2];
	
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
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "sitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((15707.9629f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.5f) / fConst1) + 1.0f);
		fConst4 = (0.300000012f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		fConst6 = std::pow(0.00100000005f, (0.125f / fConst0));
		float fConst7 = (1.0f / fConst0);
		float fConst8 = FaustSitarDSP_faustpower2_f(fConst7);
		float fConst9 = std::tan((3769.91113f / fConst0));
		float fConst10 = (fConst0 * fConst9);
		float fConst11 = FaustSitarDSP_faustpower2_f(fConst0);
		float fConst12 = std::sqrt((4.0f * ((fConst11 * fConst9) * std::tan((628.318542f / fConst0)))));
		float fConst13 = FaustSitarDSP_faustpower2_f(fConst12);
		float fConst14 = ((2.0f * fConst10) - (0.5f * (fConst13 / fConst10)));
		float fConst15 = FaustSitarDSP_faustpower2_f(fConst14);
		fConst16 = (4.0f * fConst15);
		float fConst17 = (fConst16 + (8.0f * fConst13));
		float fConst18 = (fConst7 * fConst13);
		float fConst19 = (2.82842708f * fConst14);
		float fConst20 = (fConst14 / fConst0);
		float fConst21 = (11.3137083f * fConst20);
		float fConst22 = (((fConst8 * (fConst17 + (fConst18 * (fConst18 + fConst19)))) + fConst21) + 16.0f);
		fConst23 = (0.200000003f * (fConst8 / fConst22));
		float fConst24 = (8.0f * fConst15);
		fConst25 = (0.0f - fConst24);
		fConst26 = (1.0f / fConst22);
		float fConst27 = FaustSitarDSP_faustpower3_f(fConst7);
		float fConst28 = (fConst27 * fConst13);
		float fConst29 = (4.0f * fConst18);
		float fConst30 = (5.65685415f * fConst14);
		float fConst31 = (22.6274166f * fConst20);
		fConst32 = ((fConst28 * (fConst29 + fConst30)) + (-64.0f - fConst31));
		fConst33 = ((fConst8 * ((0.0f - (fConst24 + (16.0f * fConst13))) + (6.0f * (fConst8 * FaustSitarDSP_faustpower4_f(fConst12))))) + 96.0f);
		fConst34 = ((fConst31 + (fConst28 * (fConst29 - fConst30))) + -64.0f);
		fConst35 = ((fConst8 * (fConst17 + (fConst18 * (fConst18 - fConst19)))) + (16.0f - fConst21));
		fConst36 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst37 = (1.0f / fConst36);
		fConst38 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		float fConst39 = std::tan((2513.27417f / fConst0));
		float fConst40 = (fConst0 * fConst39);
		float fConst41 = std::sqrt((4.0f * ((fConst11 * fConst39) * std::tan((942.477783f / fConst0)))));
		float fConst42 = FaustSitarDSP_faustpower2_f(fConst41);
		float fConst43 = ((2.0f * fConst40) - (0.5f * (fConst42 / fConst40)));
		float fConst44 = FaustSitarDSP_faustpower2_f(fConst43);
		fConst45 = (4.0f * fConst44);
		float fConst46 = (fConst45 + (8.0f * fConst42));
		float fConst47 = (fConst7 * fConst42);
		float fConst48 = (2.82842708f * fConst43);
		float fConst49 = (fConst43 / fConst0);
		float fConst50 = (11.3137083f * fConst49);
		float fConst51 = (((fConst8 * (fConst46 + (fConst47 * (fConst47 + fConst48)))) + fConst50) + 16.0f);
		fConst52 = (0.0500000007f * (fConst8 / fConst51));
		float fConst53 = (8.0f * fConst44);
		fConst54 = (0.0f - fConst53);
		fConst55 = (1.0f / fConst51);
		float fConst56 = (fConst27 * fConst42);
		float fConst57 = (4.0f * fConst47);
		float fConst58 = (5.65685415f * fConst43);
		float fConst59 = (22.6274166f * fConst49);
		fConst60 = ((fConst56 * (fConst57 + fConst58)) + (-64.0f - fConst59));
		fConst61 = ((fConst8 * ((0.0f - (fConst53 + (16.0f * fConst42))) + (6.0f * (fConst8 * FaustSitarDSP_faustpower4_f(fConst41))))) + 96.0f);
		fConst62 = ((fConst59 + (fConst56 * (fConst57 - fConst58))) + -64.0f);
		fConst63 = ((fConst8 * (fConst46 + (fConst47 * (fConst47 - fConst48)))) + (16.0f - fConst50));
		fConst64 = (0.666666687f * fConst0);
		fConst65 = (1.0f / fConst3);
		fConst66 = (((fConst2 + -0.5f) / fConst1) + 1.0f);
		fConst67 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst1))));
		float fConst68 = std::tan((785.398193f / fConst0));
		float fConst69 = (1.0f / fConst68);
		float fConst70 = (((fConst69 + 0.333333343f) / fConst68) + 1.0f);
		float fConst71 = (fConst68 * fConst70);
		fConst72 = (1.0f / fConst71);
		fConst73 = (1.0f / fConst70);
		fConst74 = (((fConst69 + -0.333333343f) / fConst68) + 1.0f);
		fConst75 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst68))));
		float fConst76 = std::tan((1727.87598f / fConst0));
		float fConst77 = (1.0f / fConst76);
		float fConst78 = (((fConst77 + 0.333333343f) / fConst76) + 1.0f);
		float fConst79 = (fConst76 * fConst78);
		fConst80 = (1.0f / fConst79);
		fConst81 = (1.0f / fConst78);
		fConst82 = (((fConst77 + -0.333333343f) / fConst76) + 1.0f);
		fConst83 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst76))));
		float fConst84 = std::tan((10995.5742f / fConst0));
		float fConst85 = (1.0f / fConst84);
		float fConst86 = (((fConst85 + 0.333333343f) / fConst84) + 1.0f);
		float fConst87 = (fConst84 * fConst86);
		fConst88 = (1.0f / fConst87);
		fConst89 = (1.0f / fConst86);
		fConst90 = (((fConst85 + -0.333333343f) / fConst84) + 1.0f);
		fConst91 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst84))));
		fConst92 = (0.0f - (0.5f / fConst87));
		float fConst93 = std::tan((1099.55737f / fConst0));
		float fConst94 = (1.0f / fConst93);
		float fConst95 = (((fConst94 + 0.333333343f) / fConst93) + 1.0f);
		float fConst96 = (fConst93 * fConst95);
		fConst97 = (1.0f / fConst96);
		fConst98 = (1.0f / fConst95);
		fConst99 = (((fConst94 + -0.333333343f) / fConst93) + 1.0f);
		fConst100 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst93))));
		float fConst101 = std::tan((3455.75195f / fConst0));
		float fConst102 = (1.0f / fConst101);
		float fConst103 = (((fConst102 + 0.333333343f) / fConst101) + 1.0f);
		float fConst104 = (fConst101 * fConst103);
		fConst105 = (1.0f / fConst104);
		fConst106 = (1.0f / fConst103);
		fConst107 = (((fConst102 + -0.333333343f) / fConst101) + 1.0f);
		fConst108 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst101))));
		float fConst109 = std::tan((6911.50391f / fConst0));
		float fConst110 = (1.0f / fConst109);
		float fConst111 = (((fConst110 + 0.333333343f) / fConst109) + 1.0f);
		float fConst112 = (fConst109 * fConst111);
		fConst113 = (1.0f / fConst112);
		fConst114 = (1.0f / fConst111);
		fConst115 = (((fConst110 + -0.333333343f) / fConst109) + 1.0f);
		fConst116 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst109))));
		fConst117 = (0.0f - (0.800000012f / fConst112));
		float fConst118 = std::tan((2356.19458f / fConst0));
		float fConst119 = (1.0f / fConst118);
		float fConst120 = (((fConst119 + 0.333333343f) / fConst118) + 1.0f);
		float fConst121 = (fConst118 * fConst120);
		fConst122 = (1.0f / fConst121);
		fConst123 = (1.0f / fConst120);
		fConst124 = (((fConst119 + -0.333333343f) / fConst118) + 1.0f);
		fConst125 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst118))));
		float fConst126 = std::tan((5026.54834f / fConst0));
		float fConst127 = (1.0f / fConst126);
		float fConst128 = (((fConst127 + 0.333333343f) / fConst126) + 1.0f);
		float fConst129 = (fConst126 * fConst128);
		fConst130 = (1.0f / fConst129);
		fConst131 = (1.0f / fConst128);
		fConst132 = (((fConst127 + -0.333333343f) / fConst126) + 1.0f);
		fConst133 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst126))));
		fConst134 = (0.0f - (0.600000024f / fConst129));
		fConst135 = (0.0f - (0.800000012f / fConst104));
		fConst136 = (0.0f - (0.600000024f / fConst121));
		fConst137 = (0.0f - (0.5f / fConst79));
		fConst138 = (0.0f - (0.800000012f / fConst96));
		float fConst139 = std::tan((471.238892f / fConst0));
		float fConst140 = (1.0f / fConst139);
		float fConst141 = (((fConst140 + 0.333333343f) / fConst139) + 1.0f);
		fConst142 = (1.0f / (fConst139 * fConst141));
		fConst143 = (1.0f / fConst141);
		fConst144 = (((fConst140 + -0.333333343f) / fConst139) + 1.0f);
		fConst145 = (2.0f * (1.0f - (1.0f / FaustSitarDSP_faustpower2_f(fConst139))));
		fConst146 = (0.0f - fConst142);
		fConst147 = (0.0f - (0.5f / fConst71));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.29999999999999999f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(222.0f);
		fHslider4 = FAUSTFLOAT(0.10000000000000001f);
		fHslider5 = FAUSTFLOAT(440.0f);
		fHslider6 = FAUSTFLOAT(0.14999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec3[l2] = 0;
		}
		for (int l3 = 0; (l3 < 5); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec4[l6] = 0;
		}
		IOTA = 0;
		for (int l7 = 0; (l7 < 8192); l7 = (l7 + 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 5); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iVec4[l12] = 0;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			iRec9[l13] = 0;
		}
		for (int l14 = 0; (l14 < 8192); l14 = (l14 + 1)) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec6[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 4096); l17 = (l17 + 1)) {
			fVec6[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec11[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fVec7[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec0[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec13[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec14[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec15[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec16[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec17[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec18[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec19[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec20[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec21[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 8192); l30 = (l30 + 1)) {
			fVec8[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec22[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 4096); l32 = (l32 + 1)) {
			fVec9[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec23[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 4096); l34 = (l34 + 1)) {
			fVec10[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec24[l35] = 0.0f;
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
		ui_interface->declare(&fHslider5, "unit", "Hz");
		ui_interface->addHorizontalSlider("chikari_freq", &fHslider5, FAUSTFLOAT(440.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(222.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider4, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider6, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (23.0f * float(fHslider0));
		float fSlow1 = float(fButton0);
		float fSlow2 = float(fHslider1);
		int iSlow3 = (float(fHslider2) > 0.5f);
		float fSlow4 = (fConst23 * (fSlow2 * float((1 - iSlow3))));
		float fSlow5 = float(fHslider3);
		float fSlow6 = (fConst0 / fSlow5);
		float fSlow7 = (600.0f * float(fHslider4));
		float fSlow8 = float(fHslider5);
		float fSlow9 = (fConst0 / fSlow8);
		float fSlow10 = (fSlow9 + -1.0f);
		float fSlow11 = std::floor(fSlow10);
		float fSlow12 = (fSlow11 + (2.0f - fSlow9));
		float fSlow13 = std::pow(0.00100000005f, (0.400000006f / fSlow8));
		float fSlow14 = (fConst52 * fSlow2);
		int iSlow15 = int(fSlow10);
		int iSlow16 = std::min<int>(16385, std::max<int>(0, iSlow15));
		float fSlow17 = (fSlow9 + (-1.0f - fSlow11));
		int iSlow18 = std::min<int>(16385, std::max<int>(0, (iSlow15 + 1)));
		float fSlow19 = (fConst64 / fSlow8);
		float fSlow20 = (fSlow19 + -1.0f);
		float fSlow21 = std::floor(fSlow20);
		float fSlow22 = (fSlow21 + (2.0f - fSlow19));
		float fSlow23 = std::pow(0.00100000005f, (0.266666681f / fSlow8));
		int iSlow24 = int(fSlow20);
		int iSlow25 = std::min<int>(16385, std::max<int>(0, iSlow24));
		float fSlow26 = (fSlow19 + (-1.0f - fSlow21));
		int iSlow27 = std::min<int>(16385, std::max<int>(0, (iSlow24 + 1)));
		float fSlow28 = (0.333333343f * float(fHslider6));
		float fSlow29 = (fConst0 / std::max<float>(fSlow5, 40.0f));
		float fSlow30 = (fSlow29 + -1.0f);
		float fSlow31 = std::floor(fSlow30);
		float fSlow32 = (fSlow31 + (2.0f - fSlow29));
		int iSlow33 = int(fSlow30);
		int iSlow34 = std::min<int>(16385, std::max<int>(0, iSlow33));
		float fSlow35 = (fSlow29 + (-1.0f - fSlow31));
		int iSlow36 = std::min<int>(16385, std::max<int>(0, (iSlow33 + 1)));
		float fSlow37 = (fConst0 / std::max<float>((1.5f * fSlow5), 40.0f));
		float fSlow38 = (fSlow37 + -1.0f);
		float fSlow39 = std::floor(fSlow38);
		float fSlow40 = (fSlow39 + (2.0f - fSlow37));
		int iSlow41 = int(fSlow38);
		int iSlow42 = std::min<int>(16385, std::max<int>(0, iSlow41));
		float fSlow43 = (fSlow37 + (-1.0f - fSlow39));
		int iSlow44 = std::min<int>(16385, std::max<int>(0, (iSlow41 + 1)));
		float fSlow45 = (fConst0 / std::max<float>((2.0f * fSlow5), 40.0f));
		float fSlow46 = (fSlow45 + -1.0f);
		float fSlow47 = std::floor(fSlow46);
		float fSlow48 = (fSlow47 + (2.0f - fSlow45));
		int iSlow49 = int(fSlow46);
		int iSlow50 = std::min<int>(16385, std::max<int>(0, iSlow49));
		float fSlow51 = (fSlow45 + (-1.0f - fSlow47));
		int iSlow52 = std::min<int>(16385, std::max<int>(0, (iSlow49 + 1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow1;
			iVec1[0] = iSlow3;
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * float(iRec3[0]));
			float fTempFTZ0 = (fTemp0 - (fConst26 * ((((fConst32 * fRec2[1]) + (fConst33 * fRec2[2])) + (fConst34 * fRec2[3])) + (fConst35 * fRec2[4]))));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fThen0 = std::max<float>(0.0f, (fRec5[1] + -1.0f));
			float fTempFTZ1 = (((fSlow1 - fVec0[1]) > 0.0f) ? 150.0f : fThen0);
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			int iTemp1 = (fRec5[0] > 0.0f);
			iVec2[0] = iTemp1;
			iRec4[0] = (((iRec4[1] + (iRec4[1] > 0)) * (iTemp1 <= iVec2[1])) + (iTemp1 > iVec2[1]));
			float fTemp2 = float(iRec4[0]);
			float fTemp3 = ((fConst6 * fRec1[1]) + (fSlow4 * ((((fConst25 * fRec2[2]) + (fConst16 * fRec2[0])) + (fConst16 * fRec2[4])) * std::max<float>(0.0f, std::min<float>((fConst37 * fTemp2), ((fConst38 * (fConst36 - fTemp2)) + 1.0f))))));
			fVec3[(IOTA & 8191)] = fTemp3;
			float fTemp4 = std::max<float>(2.0f, (fSlow6 - (fSlow7 * std::max<float>(0.0f, (5.0f * fTemp3)))));
			int iTemp5 = int(fTemp4);
			float fTemp6 = std::floor(fTemp4);
			float fTempFTZ2 = ((fVec3[((IOTA - std::min<int>(16385, int(std::max<int>(0, int(iTemp5))))) & 8191)] * (fTemp6 + (1.0f - fTemp4))) + ((fTemp4 - fTemp6) * fVec3[((IOTA - std::min<int>(16385, int(std::max<int>(0, int((iTemp5 + 1)))))) & 8191)]));
			fRec1[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.0500000007f * fRec7[1]) + (0.949999988f * fRec6[1]));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp0 - (fConst55 * ((((fConst60 * fRec8[1]) + (fConst61 * fRec8[2])) + (fConst62 * fRec8[3])) + (fConst63 * fRec8[4]))));
			fRec8[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fThen1 = std::max<float>(0.0f, (fRec10[1] + -1.0f));
			float fTempFTZ5 = ((iSlow3 > iVec1[1]) ? 150.0f : fThen1);
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			int iTemp7 = (fRec10[0] > 0.0f);
			iVec4[0] = iTemp7;
			iRec9[0] = (((iRec9[1] + (iRec9[1] > 0)) * (iTemp7 <= iVec4[1])) + (iTemp7 > iVec4[1]));
			float fTemp8 = float(iRec9[0]);
			float fTemp9 = (fSlow14 * ((((fConst54 * fRec8[2]) + (fConst45 * fRec8[0])) + (fConst45 * fRec8[4])) * std::max<float>(0.0f, std::min<float>((fConst37 * fTemp8), ((fConst38 * (fConst36 - fTemp8)) + 1.0f)))));
			float fTemp10 = ((fSlow13 * fRec7[0]) + fTemp9);
			fVec5[(IOTA & 8191)] = fTemp10;
			float fTempFTZ6 = ((fSlow12 * fVec5[((IOTA - iSlow16) & 8191)]) + (fSlow17 * fVec5[((IOTA - iSlow18) & 8191)]));
			fRec6[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((0.0500000007f * fRec12[1]) + (0.949999988f * fRec11[1]));
			fRec12[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp11 = (fTemp9 + (fSlow23 * fRec12[0]));
			fVec6[(IOTA & 4095)] = fTemp11;
			float fTempFTZ8 = ((fSlow22 * fVec6[((IOTA - iSlow25) & 4095)]) + (fSlow26 * fVec6[((IOTA - iSlow27) & 4095)]));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp12 = (fSlow1 * (fRec1[0] + (2.0f * (fRec6[0] + fRec11[0]))));
			fVec7[0] = fTemp12;
			float fTemp13 = (fTemp12 + (0.999000013f * fVec7[2]));
			float fTempFTZ9 = (fTemp13 - (fVec7[1] + (fConst65 * ((fConst66 * fRec0[2]) + (fConst67 * fRec0[1])))));
			fRec0[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fTemp13 - (fVec7[1] + (fConst73 * ((fConst74 * fRec13[2]) + (fConst75 * fRec13[1])))));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp13 - (fVec7[1] + (fConst81 * ((fConst82 * fRec14[2]) + (fConst83 * fRec14[1])))));
			fRec14[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fTemp13 - (fVec7[1] + (fConst89 * ((fConst90 * fRec15[2]) + (fConst91 * fRec15[1])))));
			fRec15[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp13 - (fVec7[1] + (fConst98 * ((fConst99 * fRec16[2]) + (fConst100 * fRec16[1])))));
			fRec16[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fTemp13 - (fVec7[1] + (fConst106 * ((fConst107 * fRec17[2]) + (fConst108 * fRec17[1])))));
			fRec17[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fTemp13 - (fVec7[1] + (fConst114 * ((fConst115 * fRec18[2]) + (fConst116 * fRec18[1])))));
			fRec18[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fTemp13 - (fVec7[1] + (fConst123 * ((fConst124 * fRec19[2]) + (fConst125 * fRec19[1])))));
			fRec19[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fTemp13 - (fVec7[1] + (fConst131 * ((fConst132 * fRec20[2]) + (fConst133 * fRec20[1])))));
			fRec20[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fTemp13 - (fVec7[1] + (fConst143 * ((fConst144 * fRec21[2]) + (fConst145 * fRec21[1])))));
			fRec21[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp14 = ((fConst5 * fRec0[2]) + (((0.5f * (((fConst72 * fRec13[0]) + (fConst80 * fRec14[0])) + (fConst88 * fRec15[0]))) + ((fConst92 * fRec15[2]) + ((0.800000012f * (((fConst97 * fRec16[0]) + (fConst105 * fRec17[0])) + (fConst113 * fRec18[0]))) + ((fConst117 * fRec18[2]) + ((0.600000024f * (((fTemp13 - fVec7[1]) + (fConst122 * fRec19[0])) + (fConst130 * fRec20[0]))) + ((fConst134 * fRec20[2]) + ((fConst135 * fRec17[2]) + ((fConst136 * fRec19[2]) + ((fConst137 * fRec14[2]) + ((fConst138 * fRec16[2]) + (((fConst142 * fRec21[0]) + (fConst146 * fRec21[2])) + (fConst147 * fRec13[2])))))))))))) + (fConst4 * fRec0[0])));
			float fTemp15 = (fSlow1 * fTemp14);
			float fTemp16 = ((0.996999979f * fRec22[1]) + fTemp15);
			fVec8[(IOTA & 8191)] = fTemp16;
			float fTempFTZ19 = ((fSlow32 * fVec8[((IOTA - iSlow34) & 8191)]) + (fSlow35 * fVec8[((IOTA - iSlow36) & 8191)]));
			fRec22[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp17 = (fTemp15 + (0.996999979f * fRec23[1]));
			fVec9[(IOTA & 4095)] = fTemp17;
			float fTempFTZ20 = ((fSlow40 * fVec9[((IOTA - iSlow42) & 4095)]) + (fSlow43 * fVec9[((IOTA - iSlow44) & 4095)]));
			fRec23[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp18 = (fTemp15 + (0.996999979f * fRec24[1]));
			fVec10[(IOTA & 4095)] = fTemp18;
			float fTempFTZ21 = ((fSlow48 * fVec10[((IOTA - iSlow50) & 4095)]) + (fSlow51 * fVec10[((IOTA - iSlow52) & 4095)]));
			fRec24[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp14 + (fSlow28 * ((fRec22[0] + fRec23[0]) + fRec24[0])))));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec3[1] = iRec3[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec2[j0] = fRec2[(j0 - 1)];
			}
			fRec5[1] = fRec5[0];
			iVec2[1] = iVec2[0];
			iRec4[1] = iRec4[0];
			IOTA = (IOTA + 1);
			fRec1[1] = fRec1[0];
			fRec7[1] = fRec7[0];
			for (int j1 = 4; (j1 > 0); j1 = (j1 - 1)) {
				fRec8[j1] = fRec8[(j1 - 1)];
			}
			fRec10[1] = fRec10[0];
			iVec4[1] = iVec4[0];
			iRec9[1] = iRec9[0];
			fRec6[1] = fRec6[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fVec7[2] = fVec7[1];
			fVec7[1] = fVec7[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
		}
	}

};

#endif
