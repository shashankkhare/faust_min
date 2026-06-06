/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "sarod"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSarodDSP_H__
#define  __FaustSarodDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustSarodDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustSarodDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float FaustSarodDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSarodDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSarodDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst4;
	float fConst5;
	float fConst8;
	float fConst12;
	float fConst13;
	FAUSTFLOAT fHslider1;
	float fRec5[2];
	float fRec4[2];
	float fConst22;
	float fConst30;
	FAUSTFLOAT fHslider2;
	float fConst32;
	int iRec7[2];
	float fConst33;
	float fConst38;
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec6[5];
	float fConst42;
	float fConst43;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec9[2];
	int iVec1[2];
	int iRec8[2];
	float fConst44;
	int IOTA;
	float fVec2[8192];
	float fRec3[2];
	FAUSTFLOAT fHslider3;
	float fRec11[2];
	float fConst45;
	FAUSTFLOAT fHslider4;
	float fVec3[8192];
	float fRec10[2];
	float fConst46;
	float fConst47;
	FAUSTFLOAT fHslider5;
	float fConst48;
	float fRec12[3];
	float fConst49;
	float fRec13[3];
	float fConst50;
	float fRec14[3];
	float fConst51;
	float fRec15[3];
	float fConst52;
	float fConst53;
	float fConst54;
	float fRec2[3];
	float fConst58;
	float fConst59;
	float fConst60;
	float fConst61;
	float fConst62;
	float fRec16[3];
	float fConst66;
	float fConst67;
	float fConst68;
	float fConst69;
	float fConst70;
	float fRec17[3];
	float fConst74;
	float fConst75;
	float fConst76;
	float fConst77;
	float fConst78;
	float fRec18[3];
	float fConst82;
	float fConst83;
	float fConst84;
	float fConst85;
	float fConst86;
	float fRec19[3];
	float fConst90;
	float fConst91;
	float fConst92;
	float fConst93;
	float fRec20[3];
	float fConst94;
	float fConst95;
	float fConst96;
	float fRec1[3];
	float fConst97;
	float fConst98;
	float fConst99;
	float fRec0[3];
	float fConst102;
	float fConst103;
	float fConst104;
	float fConst105;
	float fConst106;
	float fRec21[3];
	float fConst110;
	float fConst111;
	float fConst112;
	float fConst113;
	float fConst114;
	float fRec22[3];
	float fRec23[3];
	float fConst118;
	float fConst119;
	float fConst120;
	float fConst121;
	float fConst122;
	float fRec24[3];
	float fConst126;
	float fConst127;
	float fConst128;
	float fConst129;
	float fRec25[3];
	float fConst130;
	
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
		m->declare("filename", "sarod.dsp");
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
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "sarod");
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
		float fConst1 = std::tan((8796.45898f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.200000003f) / fConst1) + 1.0f);
		fConst4 = (1.0f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		float fConst6 = std::tan((13194.6895f / fConst0));
		float fConst7 = (1.0f / fConst6);
		fConst8 = (1.0f / (((fConst7 + 1.41421354f) / fConst6) + 1.0f));
		float fConst9 = std::tan((1727.87598f / fConst0));
		float fConst10 = (1.0f / fConst9);
		float fConst11 = (((fConst10 + 0.0666666701f) / fConst9) + 1.0f);
		fConst12 = (1.0f / (fConst9 * fConst11));
		fConst13 = (0.0f - fConst12);
		float fConst14 = (1.0f / fConst0);
		float fConst15 = FaustSarodDSP_faustpower2_f(fConst14);
		float fConst16 = std::tan((5026.54834f / fConst0));
		float fConst17 = (fConst0 * fConst16);
		float fConst18 = std::sqrt((4.0f * ((FaustSarodDSP_faustpower2_f(fConst0) * fConst16) * std::tan((2513.27417f / fConst0)))));
		float fConst19 = FaustSarodDSP_faustpower2_f(fConst18);
		float fConst20 = ((2.0f * fConst17) - (0.5f * (fConst19 / fConst17)));
		float fConst21 = FaustSarodDSP_faustpower2_f(fConst20);
		fConst22 = (4.0f * fConst21);
		float fConst23 = (fConst22 + (8.0f * fConst19));
		float fConst24 = (fConst14 * fConst19);
		float fConst25 = (2.82842708f * fConst20);
		float fConst26 = (fConst20 / fConst0);
		float fConst27 = (11.3137083f * fConst26);
		float fConst28 = (((fConst15 * (fConst23 + (fConst24 * (fConst25 + fConst24)))) + fConst27) + 16.0f);
		float fConst29 = (fConst15 / fConst28);
		fConst30 = (0.200000003f * fConst29);
		float fConst31 = (8.0f * fConst21);
		fConst32 = (0.0f - fConst31);
		fConst33 = (1.0f / fConst28);
		float fConst34 = (FaustSarodDSP_faustpower3_f(fConst14) * fConst19);
		float fConst35 = (5.65685415f * fConst20);
		float fConst36 = (4.0f * fConst24);
		float fConst37 = (22.6274166f * fConst26);
		fConst38 = ((fConst34 * (fConst35 + fConst36)) + (-64.0f - fConst37));
		fConst39 = ((fConst15 * ((0.0f - (fConst31 + (16.0f * fConst19))) + (6.0f * (fConst15 * FaustSarodDSP_faustpower4_f(fConst18))))) + 96.0f);
		fConst40 = ((fConst37 + (fConst34 * (fConst36 - fConst35))) + -64.0f);
		fConst41 = ((fConst15 * (fConst23 + (fConst24 * (fConst24 - fConst25)))) + (16.0f - fConst27));
		fConst42 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst43 = (1.0f / fConst42);
		fConst44 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		fConst45 = (0.140000001f * fConst29);
		fConst46 = std::pow(0.00100000005f, (0.833333313f / fConst0));
		fConst47 = (2.0f * (1.0f - fConst46));
		fConst48 = (18.849556f / fConst0);
		fConst49 = (12.566371f / fConst0);
		fConst50 = (6.28318548f / fConst0);
		fConst51 = (9.42477798f / fConst0);
		fConst52 = (1.0f / fConst11);
		fConst53 = (((fConst10 + -0.0666666701f) / fConst9) + 1.0f);
		fConst54 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst9))));
		float fConst55 = std::tan((1376.01758f / fConst0));
		float fConst56 = (1.0f / fConst55);
		float fConst57 = (((fConst56 + 0.200000003f) / fConst55) + 1.0f);
		fConst58 = (1.0f / (fConst55 * fConst57));
		fConst59 = (0.0f - fConst58);
		fConst60 = (1.0f / fConst57);
		fConst61 = (((fConst56 + -0.200000003f) / fConst55) + 1.0f);
		fConst62 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst55))));
		float fConst63 = std::tan((1248.78308f / fConst0));
		float fConst64 = (1.0f / fConst63);
		float fConst65 = (((fConst64 + 0.200000003f) / fConst63) + 1.0f);
		fConst66 = (1.0f / (fConst63 * fConst65));
		fConst67 = (0.0f - fConst66);
		fConst68 = (1.0f / fConst65);
		fConst69 = (((fConst64 + -0.200000003f) / fConst63) + 1.0f);
		fConst70 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst63))));
		float fConst71 = std::tan((1008.45123f / fConst0));
		float fConst72 = (1.0f / fConst71);
		float fConst73 = (((fConst72 + 0.0666666701f) / fConst71) + 1.0f);
		fConst74 = (1.0f / (fConst71 * fConst73));
		fConst75 = (0.0f - fConst74);
		fConst76 = (1.0f / fConst73);
		fConst77 = (((fConst72 + -0.0666666701f) / fConst71) + 1.0f);
		fConst78 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst71))));
		float fConst79 = std::tan((749.269836f / fConst0));
		float fConst80 = (1.0f / fConst79);
		float fConst81 = (((fConst80 + 0.100000001f) / fConst79) + 1.0f);
		fConst82 = (1.0f / (fConst79 * fConst81));
		fConst83 = (0.0f - fConst82);
		fConst84 = (1.0f / fConst81);
		fConst85 = (((fConst80 + -0.100000001f) / fConst79) + 1.0f);
		fConst86 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst79))));
		float fConst87 = std::tan((471.238892f / fConst0));
		float fConst88 = (1.0f / fConst87);
		float fConst89 = (((fConst88 + 0.100000001f) / fConst87) + 1.0f);
		fConst90 = (1.0f / (fConst87 * fConst89));
		fConst91 = (1.0f / fConst89);
		fConst92 = (((fConst88 + -0.100000001f) / fConst87) + 1.0f);
		fConst93 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst87))));
		fConst94 = (0.0f - fConst90);
		fConst95 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst96 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst97 = (1.0f / fConst3);
		fConst98 = (((fConst2 + -0.200000003f) / fConst1) + 1.0f);
		fConst99 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst100 = (1.0f / fConst16);
		float fConst101 = (((fConst100 + 0.200000003f) / fConst16) + 1.0f);
		fConst102 = (1.0f / (fConst16 * fConst101));
		fConst103 = (0.0f - fConst102);
		fConst104 = (1.0f / fConst101);
		fConst105 = (((fConst100 + -0.200000003f) / fConst16) + 1.0f);
		fConst106 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst16))));
		float fConst107 = std::tan((2827.43335f / fConst0));
		float fConst108 = (1.0f / fConst107);
		float fConst109 = (((fConst108 + 0.100000001f) / fConst107) + 1.0f);
		fConst110 = (1.0f / (fConst107 * fConst109));
		fConst111 = (0.0f - fConst110);
		fConst112 = (1.0f / fConst109);
		fConst113 = (((fConst108 + -0.100000001f) / fConst107) + 1.0f);
		fConst114 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst107))));
		float fConst115 = std::tan((1005.30963f / fConst0));
		float fConst116 = (1.0f / fConst115);
		float fConst117 = (((fConst116 + 0.0666666701f) / fConst115) + 1.0f);
		fConst118 = (1.0f / (fConst115 * fConst117));
		fConst119 = (0.0f - fConst118);
		fConst120 = (1.0f / fConst117);
		fConst121 = (((fConst116 + -0.0666666701f) / fConst115) + 1.0f);
		fConst122 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst115))));
		float fConst123 = std::tan((565.486694f / fConst0));
		float fConst124 = (1.0f / fConst123);
		float fConst125 = (((fConst124 + 0.100000001f) / fConst123) + 1.0f);
		fConst126 = (1.0f / (fConst123 * fConst125));
		fConst127 = (1.0f / fConst125);
		fConst128 = (((fConst124 + -0.100000001f) / fConst123) + 1.0f);
		fConst129 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst123))));
		fConst130 = (0.0f - fConst126);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(146.83000000000001f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(880.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.29999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec5[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec4[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec7[l2] = 0;
		}
		for (int l3 = 0; (l3 < 5); l3 = (l3 + 1)) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec9[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iVec1[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec8[l7] = 0;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 8192); l8 = (l8 + 1)) {
			fVec2[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec11[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 8192); l11 = (l11 + 1)) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec2[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec17[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec18[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec19[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec20[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec1[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec0[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec21[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec22[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec23[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec24[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec25[l29] = 0.0f;
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
	
	virtual FaustSarodDSP* clone() {
		return new FaustSarodDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("sarod");
		ui_interface->addHorizontalSlider("chikari_freq", &fHslider3, FAUSTFLOAT(880.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider5, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (3.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fConst0 / fSlow1);
		int iSlow3 = int((fSlow2 + -1.0f));
		float fSlow4 = float(iSlow3);
		float fSlow5 = (fSlow4 + (2.0f - fSlow2));
		float fSlow6 = std::max<float>(0.0f, std::min<float>(1.0f, (0.00138888892f * (fSlow1 + -80.0f))));
		float fSlow7 = std::pow(0.00100000005f, (1.0f / (fSlow1 * (4.0f - (3.20000005f * fSlow6)))));
		float fSlow8 = (0.00499999989f * fSlow6);
		float fSlow9 = (0.0149999997f - fSlow8);
		float fSlow10 = (fSlow8 + 0.985000014f);
		float fSlow11 = float(fHslider2);
		float fSlow12 = (fConst30 * fSlow11);
		float fSlow13 = float(fButton0);
		int iSlow14 = std::min<int>(16384, std::max<int>(0, iSlow3));
		float fSlow15 = (fSlow2 + (-1.0f - fSlow4));
		int iSlow16 = std::min<int>(16384, std::max<int>(0, (iSlow3 + 1)));
		float fSlow17 = float(fHslider3);
		float fSlow18 = (fConst0 / fSlow17);
		int iSlow19 = int((fSlow18 + -1.0f));
		float fSlow20 = float(iSlow19);
		float fSlow21 = (fSlow20 + (2.0f - fSlow18));
		float fSlow22 = std::pow(0.00100000005f, (0.400000006f / fSlow17));
		float fSlow23 = (fConst45 * (fSlow11 * float((float(fHslider4) > 0.5f))));
		int iSlow24 = std::min<int>(16384, std::max<int>(0, iSlow19));
		float fSlow25 = (fSlow18 + (-1.0f - fSlow20));
		int iSlow26 = std::min<int>(16384, std::max<int>(0, (iSlow19 + 1)));
		float fSlow27 = (fConst47 * float(fHslider5));
		float fSlow28 = (2.0f * std::cos((fConst48 * fSlow1)));
		float fSlow29 = (2.0f * std::cos((fConst49 * fSlow1)));
		float fSlow30 = (2.0f * std::cos((fConst50 * fSlow1)));
		float fSlow31 = (2.0f * std::cos((fConst51 * fSlow1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = ((fSlow9 * fRec5[1]) + (fSlow10 * fRec3[1]));
			fRec5[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fRec5[1] + (0.200000003f * (fRec5[0] - fRec4[1])));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = std::fabs(fRec4[0]);
			float fElse1 = (((fRec4[0] > 0.0f) ? 1.0f : -1.0f) * ((0.150000006f * (fTemp0 + -0.0399999991f)) + 0.0399999991f));
			iRec7[0] = ((1103515245 * iRec7[1]) + 12345);
			float fTempFTZ2 = ((4.65661287e-10f * float(iRec7[0])) - (fConst33 * ((((fConst38 * fRec6[1]) + (fConst39 * fRec6[2])) + (fConst40 * fRec6[3])) + (fConst41 * fRec6[4]))));
			fRec6[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			fVec0[0] = fSlow13;
			float fThen2 = std::max<float>(0.0f, (fRec9[1] + -1.0f));
			float fTempFTZ3 = ((fSlow13 > fVec0[1]) ? 150.0f : fThen2);
			fRec9[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			int iTemp1 = (fRec9[0] > 0.0f);
			iVec1[0] = iTemp1;
			iRec8[0] = (((iRec8[1] + (iRec8[1] > 0)) * (iTemp1 <= iVec1[1])) + (iTemp1 > iVec1[1]));
			float fTemp2 = float(iRec8[0]);
			float fTemp3 = ((((fConst32 * fRec6[2]) + (fConst22 * fRec6[0])) + (fConst22 * fRec6[4])) * std::max<float>(0.0f, std::min<float>((fConst43 * fTemp2), (1.0f - (fConst44 * (fTemp2 - fConst42))))));
			float fTemp4 = ((fSlow7 * ((fTemp0 > 0.0399999991f) ? fElse1 : fRec4[0])) + (fSlow12 * fTemp3));
			fVec2[(IOTA & 8191)] = fTemp4;
			float fTempFTZ4 = ((fSlow5 * fVec2[((IOTA - iSlow14) & 8191)]) + (fSlow15 * fVec2[((IOTA - iSlow16) & 8191)]));
			fRec3[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((0.0500000007f * fRec11[1]) + (0.949999988f * fRec10[1]));
			fRec11[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp5 = ((fSlow22 * fRec11[0]) + (fSlow23 * fTemp3));
			fVec3[(IOTA & 8191)] = fTemp5;
			float fTempFTZ6 = ((fSlow21 * fVec3[((IOTA - iSlow24) & 8191)]) + (fSlow25 * fVec3[((IOTA - iSlow26) & 8191)]));
			fRec10[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fRec3[0] + (fConst46 * ((fSlow28 * fRec12[1]) - (fConst46 * fRec12[2]))));
			fRec12[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fRec3[0] + (fConst46 * ((fSlow29 * fRec13[1]) - (fConst46 * fRec13[2]))));
			fRec13[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fRec3[0] + (fConst46 * ((fSlow30 * fRec14[1]) - (fConst46 * fRec14[2]))));
			fRec14[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fRec3[0] + (fConst46 * ((fSlow31 * fRec15[1]) - (fConst46 * fRec15[2]))));
			fRec15[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp6 = (0.5f * float(tanhf(float((2.0f * ((fRec3[0] + fRec10[0]) + (fSlow27 * (fRec12[0] + (fRec13[0] + (fRec14[0] + fRec15[0]))))))))));
			float fTempFTZ11 = (fTemp6 - (fConst52 * ((fConst53 * fRec2[2]) + (fConst54 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fTemp6 - (fConst60 * ((fConst61 * fRec16[2]) + (fConst62 * fRec16[1]))));
			fRec16[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp6 - (fConst68 * ((fConst69 * fRec17[2]) + (fConst70 * fRec17[1]))));
			fRec17[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fTemp6 - (fConst76 * ((fConst77 * fRec18[2]) + (fConst78 * fRec18[1]))));
			fRec18[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fTemp6 - (fConst84 * ((fConst85 * fRec19[2]) + (fConst86 * fRec19[1]))));
			fRec19[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fTemp6 - (fConst91 * ((fConst92 * fRec20[2]) + (fConst93 * fRec20[1]))));
			fRec20[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (((fConst13 * fRec2[2]) + (((fConst59 * fRec16[2]) + (((fConst67 * fRec17[2]) + (((fConst75 * fRec18[2]) + (((fConst83 * fRec19[2]) + (((fConst90 * fRec20[0]) + (fConst94 * fRec20[2])) + (fConst82 * fRec19[0]))) + (fConst74 * fRec18[0]))) + (fConst66 * fRec17[0]))) + (fConst58 * fRec16[0]))) + (fConst12 * fRec2[0]))) - (fConst8 * ((fConst95 * fRec1[2]) + (fConst96 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp7 = (fConst8 * (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))));
			float fTempFTZ18 = (fTemp7 - (fConst97 * ((fConst98 * fRec0[2]) + (fConst99 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fTemp7 - (fConst104 * ((fConst105 * fRec21[2]) + (fConst106 * fRec21[1]))));
			fRec21[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fTemp7 - (fConst112 * ((fConst113 * fRec22[2]) + (fConst114 * fRec22[1]))));
			fRec22[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fTemp7 - (fConst52 * ((fConst53 * fRec23[2]) + (fConst54 * fRec23[1]))));
			fRec23[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fTemp7 - (fConst120 * ((fConst121 * fRec24[2]) + (fConst122 * fRec24[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fTemp7 - (fConst127 * ((fConst128 * fRec25[2]) + (fConst129 * fRec25[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * ((fConst5 * fRec0[2]) + (((fConst103 * fRec21[2]) + (((fConst111 * fRec22[2]) + (((fConst13 * fRec23[2]) + (((fConst119 * fRec24[2]) + (((fConst126 * fRec25[0]) + (fConst130 * fRec25[2])) + (fConst118 * fRec24[0]))) + (fConst12 * fRec23[0]))) + (fConst110 * fRec22[0]))) + (fConst102 * fRec21[0]))) + (fConst4 * fRec0[0]))))))));
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			iRec7[1] = iRec7[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec6[j0] = fRec6[(j0 - 1)];
			}
			fVec0[1] = fVec0[0];
			fRec9[1] = fRec9[0];
			iVec1[1] = iVec1[0];
			iRec8[1] = iRec8[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
		}
	}

};

#endif
