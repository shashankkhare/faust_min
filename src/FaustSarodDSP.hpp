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
	int iVec0[2];
	float fRec5[2];
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	float fConst22;
	float fConst29;
	float fConst31;
	int iRec7[2];
	float fConst32;
	float fConst37;
	float fConst38;
	float fConst39;
	float fConst40;
	float fRec6[5];
	float fConst41;
	float fConst42;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iVec2[2];
	int iRec8[2];
	float fConst43;
	int IOTA;
	float fVec3[8192];
	float fRec3[2];
	float fConst44;
	float fConst45;
	FAUSTFLOAT fHslider3;
	float fConst46;
	float fRec9[3];
	float fConst47;
	float fRec10[3];
	float fConst48;
	float fRec11[3];
	float fConst49;
	float fRec12[3];
	float fConst50;
	float fConst51;
	float fConst52;
	float fRec2[3];
	float fConst56;
	float fConst57;
	float fConst58;
	float fConst59;
	float fConst60;
	float fRec13[3];
	float fConst64;
	float fConst65;
	float fConst66;
	float fConst67;
	float fConst68;
	float fRec14[3];
	float fConst72;
	float fConst73;
	float fConst74;
	float fConst75;
	float fConst76;
	float fRec15[3];
	float fConst80;
	float fConst81;
	float fConst82;
	float fConst83;
	float fConst84;
	float fRec16[3];
	float fConst88;
	float fConst89;
	float fConst90;
	float fConst91;
	float fRec17[3];
	float fConst92;
	float fConst93;
	float fConst94;
	float fRec1[3];
	float fConst95;
	float fConst96;
	float fConst97;
	float fRec0[3];
	float fConst100;
	float fConst101;
	float fConst102;
	float fConst103;
	float fConst104;
	float fRec18[3];
	float fConst108;
	float fConst109;
	float fConst110;
	float fConst111;
	float fConst112;
	float fRec19[3];
	float fRec20[3];
	float fConst116;
	float fConst117;
	float fConst118;
	float fConst119;
	float fConst120;
	float fRec21[3];
	float fConst124;
	float fConst125;
	float fConst126;
	float fConst127;
	float fRec22[3];
	float fConst128;
	
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
		fConst29 = (0.699999988f * (fConst15 / fConst28));
		float fConst30 = (8.0f * fConst21);
		fConst31 = (0.0f - fConst30);
		fConst32 = (1.0f / fConst28);
		float fConst33 = (FaustSarodDSP_faustpower3_f(fConst14) * fConst19);
		float fConst34 = (5.65685415f * fConst20);
		float fConst35 = (4.0f * fConst24);
		float fConst36 = (22.6274166f * fConst26);
		fConst37 = ((fConst33 * (fConst34 + fConst35)) + (-64.0f - fConst36));
		fConst38 = ((fConst15 * ((0.0f - (fConst30 + (16.0f * fConst19))) + (6.0f * (fConst15 * FaustSarodDSP_faustpower4_f(fConst18))))) + 96.0f);
		fConst39 = ((fConst36 + (fConst33 * (fConst35 - fConst34))) + -64.0f);
		fConst40 = ((fConst15 * (fConst23 + (fConst24 * (fConst24 - fConst25)))) + (16.0f - fConst27));
		fConst41 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst42 = (1.0f / fConst41);
		fConst43 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		fConst44 = std::pow(0.00100000005f, (0.833333313f / fConst0));
		fConst45 = (2.0f * (1.0f - fConst44));
		fConst46 = (18.849556f / fConst0);
		fConst47 = (12.566371f / fConst0);
		fConst48 = (6.28318548f / fConst0);
		fConst49 = (9.42477798f / fConst0);
		fConst50 = (1.0f / fConst11);
		fConst51 = (((fConst10 + -0.0666666701f) / fConst9) + 1.0f);
		fConst52 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst9))));
		float fConst53 = std::tan((1376.01758f / fConst0));
		float fConst54 = (1.0f / fConst53);
		float fConst55 = (((fConst54 + 0.200000003f) / fConst53) + 1.0f);
		fConst56 = (1.0f / (fConst53 * fConst55));
		fConst57 = (0.0f - fConst56);
		fConst58 = (1.0f / fConst55);
		fConst59 = (((fConst54 + -0.200000003f) / fConst53) + 1.0f);
		fConst60 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst53))));
		float fConst61 = std::tan((1248.78308f / fConst0));
		float fConst62 = (1.0f / fConst61);
		float fConst63 = (((fConst62 + 0.200000003f) / fConst61) + 1.0f);
		fConst64 = (1.0f / (fConst61 * fConst63));
		fConst65 = (0.0f - fConst64);
		fConst66 = (1.0f / fConst63);
		fConst67 = (((fConst62 + -0.200000003f) / fConst61) + 1.0f);
		fConst68 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst61))));
		float fConst69 = std::tan((1008.45123f / fConst0));
		float fConst70 = (1.0f / fConst69);
		float fConst71 = (((fConst70 + 0.0666666701f) / fConst69) + 1.0f);
		fConst72 = (1.0f / (fConst69 * fConst71));
		fConst73 = (0.0f - fConst72);
		fConst74 = (1.0f / fConst71);
		fConst75 = (((fConst70 + -0.0666666701f) / fConst69) + 1.0f);
		fConst76 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst69))));
		float fConst77 = std::tan((749.269836f / fConst0));
		float fConst78 = (1.0f / fConst77);
		float fConst79 = (((fConst78 + 0.100000001f) / fConst77) + 1.0f);
		fConst80 = (1.0f / (fConst77 * fConst79));
		fConst81 = (0.0f - fConst80);
		fConst82 = (1.0f / fConst79);
		fConst83 = (((fConst78 + -0.100000001f) / fConst77) + 1.0f);
		fConst84 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst77))));
		float fConst85 = std::tan((471.238892f / fConst0));
		float fConst86 = (1.0f / fConst85);
		float fConst87 = (((fConst86 + 0.100000001f) / fConst85) + 1.0f);
		fConst88 = (1.0f / (fConst85 * fConst87));
		fConst89 = (1.0f / fConst87);
		fConst90 = (((fConst86 + -0.100000001f) / fConst85) + 1.0f);
		fConst91 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst85))));
		fConst92 = (0.0f - fConst88);
		fConst93 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst94 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst95 = (1.0f / fConst3);
		fConst96 = (((fConst2 + -0.200000003f) / fConst1) + 1.0f);
		fConst97 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst98 = (1.0f / fConst16);
		float fConst99 = (((fConst98 + 0.200000003f) / fConst16) + 1.0f);
		fConst100 = (1.0f / (fConst16 * fConst99));
		fConst101 = (0.0f - fConst100);
		fConst102 = (1.0f / fConst99);
		fConst103 = (((fConst98 + -0.200000003f) / fConst16) + 1.0f);
		fConst104 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst16))));
		float fConst105 = std::tan((2827.43335f / fConst0));
		float fConst106 = (1.0f / fConst105);
		float fConst107 = (((fConst106 + 0.100000001f) / fConst105) + 1.0f);
		fConst108 = (1.0f / (fConst105 * fConst107));
		fConst109 = (0.0f - fConst108);
		fConst110 = (1.0f / fConst107);
		fConst111 = (((fConst106 + -0.100000001f) / fConst105) + 1.0f);
		fConst112 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst105))));
		float fConst113 = std::tan((1005.30963f / fConst0));
		float fConst114 = (1.0f / fConst113);
		float fConst115 = (((fConst114 + 0.0666666701f) / fConst113) + 1.0f);
		fConst116 = (1.0f / (fConst113 * fConst115));
		fConst117 = (0.0f - fConst116);
		fConst118 = (1.0f / fConst115);
		fConst119 = (((fConst114 + -0.0666666701f) / fConst113) + 1.0f);
		fConst120 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst113))));
		float fConst121 = std::tan((565.486694f / fConst0));
		float fConst122 = (1.0f / fConst121);
		float fConst123 = (((fConst122 + 0.100000001f) / fConst121) + 1.0f);
		fConst124 = (1.0f / (fConst121 * fConst123));
		fConst125 = (1.0f / fConst123);
		fConst126 = (((fConst122 + -0.100000001f) / fConst121) + 1.0f);
		fConst127 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst121))));
		fConst128 = (0.0f - fConst124);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(146.83000000000001f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.29999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec5[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec7[l3] = 0;
		}
		for (int l4 = 0; (l4 < 5); l4 = (l4 + 1)) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iVec2[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec8[l7] = 0;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 8192); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec2[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec17[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec1[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec0[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec18[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec19[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec20[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec21[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec22[l26] = 0.0f;
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
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("symp_gain", &fHslider3, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
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
		float fSlow11 = (2.0f * float(fHslider2));
		float fSlow12 = float(fButton0);
		int iSlow13 = std::min<int>(16384, std::max<int>(0, iSlow3));
		float fSlow14 = (fSlow2 + (-1.0f - fSlow4));
		int iSlow15 = std::min<int>(16384, std::max<int>(0, (iSlow3 + 1)));
		float fSlow16 = (fConst45 * float(fHslider3));
		float fSlow17 = (2.0f * std::cos((fConst46 * fSlow1)));
		float fSlow18 = (2.0f * std::cos((fConst47 * fSlow1)));
		float fSlow19 = (2.0f * std::cos((fConst48 * fSlow1)));
		float fSlow20 = (2.0f * std::cos((fConst49 * fSlow1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			float fTempFTZ0 = ((fSlow9 * fRec5[1]) + (fSlow10 * fRec3[1]));
			fRec5[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fRec5[1] + (0.200000003f * (fRec5[0] - fRec4[1])));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = std::fabs(fRec4[0]);
			float fElse1 = (((fRec4[0] > 0.0f) ? 1.0f : -1.0f) * ((0.150000006f * (fTemp0 + -0.0399999991f)) + 0.0399999991f));
			iRec7[0] = ((1103515245 * iRec7[1]) + 12345);
			float fTempFTZ2 = ((4.65661287e-10f * float(iRec7[0])) - (fConst32 * ((((fConst37 * fRec6[1]) + (fConst38 * fRec6[2])) + (fConst39 * fRec6[3])) + (fConst40 * fRec6[4]))));
			fRec6[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			fVec1[0] = fSlow12;
			int iTemp1 = (fSlow12 > fVec1[1]);
			iVec2[0] = iTemp1;
			iRec8[0] = ((iTemp1 > iVec2[1]) + ((iTemp1 <= iVec2[1]) * (iRec8[1] + (iRec8[1] > 0))));
			float fTemp2 = float(iRec8[0]);
			float fTemp3 = ((fSlow7 * ((fTemp0 > 0.0399999991f) ? fElse1 : fRec4[0])) + (fSlow11 * (((0.300000012f * float((1 - iVec0[1]))) + (fConst29 * (((fConst31 * fRec6[2]) + (fConst22 * fRec6[0])) + (fConst22 * fRec6[4])))) * std::max<float>(0.0f, std::min<float>((fConst42 * fTemp2), (1.0f - (fConst43 * (fTemp2 - fConst41))))))));
			fVec3[(IOTA & 8191)] = fTemp3;
			float fTempFTZ3 = ((fSlow5 * fVec3[((IOTA - iSlow13) & 8191)]) + (fSlow14 * fVec3[((IOTA - iSlow15) & 8191)]));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fRec3[0] + (fConst44 * ((fSlow17 * fRec9[1]) - (fConst44 * fRec9[2]))));
			fRec9[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fRec3[0] + (fConst44 * ((fSlow18 * fRec10[1]) - (fConst44 * fRec10[2]))));
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fRec3[0] + (fConst44 * ((fSlow19 * fRec11[1]) - (fConst44 * fRec11[2]))));
			fRec11[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fRec3[0] + (fConst44 * ((fSlow20 * fRec12[1]) - (fConst44 * fRec12[2]))));
			fRec12[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp4 = (0.5f * float(tanhf(float((2.0f * (fRec3[0] + (fSlow16 * (fRec9[0] + (fRec10[0] + (fRec11[0] + fRec12[0]))))))))));
			float fTempFTZ8 = (fTemp4 - (fConst50 * ((fConst51 * fRec2[2]) + (fConst52 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp4 - (fConst58 * ((fConst59 * fRec13[2]) + (fConst60 * fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fTemp4 - (fConst66 * ((fConst67 * fRec14[2]) + (fConst68 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp4 - (fConst74 * ((fConst75 * fRec15[2]) + (fConst76 * fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fTemp4 - (fConst82 * ((fConst83 * fRec16[2]) + (fConst84 * fRec16[1]))));
			fRec16[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp4 - (fConst89 * ((fConst90 * fRec17[2]) + (fConst91 * fRec17[1]))));
			fRec17[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (((fConst13 * fRec2[2]) + (((fConst57 * fRec13[2]) + (((fConst65 * fRec14[2]) + (((fConst73 * fRec15[2]) + (((fConst81 * fRec16[2]) + (((fConst88 * fRec17[0]) + (fConst92 * fRec17[2])) + (fConst80 * fRec16[0]))) + (fConst72 * fRec15[0]))) + (fConst64 * fRec14[0]))) + (fConst56 * fRec13[0]))) + (fConst12 * fRec2[0]))) - (fConst8 * ((fConst93 * fRec1[2]) + (fConst94 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp5 = (fConst8 * (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))));
			float fTempFTZ15 = (fTemp5 - (fConst95 * ((fConst96 * fRec0[2]) + (fConst97 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fTemp5 - (fConst102 * ((fConst103 * fRec18[2]) + (fConst104 * fRec18[1]))));
			fRec18[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fTemp5 - (fConst110 * ((fConst111 * fRec19[2]) + (fConst112 * fRec19[1]))));
			fRec19[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fTemp5 - (fConst50 * ((fConst51 * fRec20[2]) + (fConst52 * fRec20[1]))));
			fRec20[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fTemp5 - (fConst118 * ((fConst119 * fRec21[2]) + (fConst120 * fRec21[1]))));
			fRec21[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fTemp5 - (fConst125 * ((fConst126 * fRec22[2]) + (fConst127 * fRec22[1]))));
			fRec22[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * ((fConst5 * fRec0[2]) + (((fConst101 * fRec18[2]) + (((fConst109 * fRec19[2]) + (((fConst13 * fRec20[2]) + (((fConst117 * fRec21[2]) + (((fConst124 * fRec22[0]) + (fConst128 * fRec22[2])) + (fConst116 * fRec21[0]))) + (fConst12 * fRec20[0]))) + (fConst108 * fRec19[0]))) + (fConst100 * fRec18[0]))) + (fConst4 * fRec0[0]))))))));
			iVec0[1] = iVec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			iRec7[1] = iRec7[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec6[j0] = fRec6[(j0 - 1)];
			}
			fVec1[1] = fVec1[0];
			iVec2[1] = iVec2[0];
			iRec8[1] = iRec8[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
		}
	}

};

#endif
