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
	float fConst9;
	float fConst14;
	FAUSTFLOAT fHslider1;
	float fConst24;
	float fConst31;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst33;
	int iRec5[2];
	float fConst34;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec4[5];
	float fConst44;
	float fConst45;
	FAUSTFLOAT fHslider4;
	int iVec0[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec7[2];
	int iVec2[2];
	int iRec6[2];
	float fConst46;
	float fRec8[2];
	int IOTA;
	float fVec3[8192];
	float fRec3[2];
	float fRec10[2];
	float fVec4[8192];
	float fRec9[2];
	FAUSTFLOAT fHslider5;
	float fRec12[2];
	float fVec5[8192];
	float fRec11[2];
	FAUSTFLOAT fHslider6;
	float fRec14[2];
	float fConst53;
	float fConst60;
	float fConst62;
	float fConst63;
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fRec15[5];
	float fRec17[2];
	int iVec6[2];
	int iRec16[2];
	float fVec7[8192];
	FAUSTFLOAT fHslider7;
	float fRec13[3];
	float fRec19[2];
	float fVec8[8192];
	float fRec18[2];
	float fConst72;
	float fConst73;
	float fConst74;
	float fRec2[3];
	float fConst79;
	float fConst80;
	float fConst81;
	float fConst82;
	float fRec20[3];
	float fConst83;
	float fConst87;
	float fConst88;
	float fConst89;
	float fConst90;
	float fConst91;
	float fRec21[3];
	float fConst95;
	float fConst96;
	float fConst97;
	float fConst98;
	float fConst99;
	float fRec22[3];
	float fConst104;
	float fConst105;
	float fConst106;
	float fConst107;
	float fRec23[3];
	float fConst112;
	float fConst113;
	float fConst114;
	float fConst115;
	float fRec24[3];
	float fConst116;
	float fConst121;
	float fConst122;
	float fConst123;
	float fConst124;
	float fRec25[3];
	float fConst129;
	float fConst130;
	float fConst131;
	float fConst132;
	float fRec26[3];
	float fConst133;
	float fConst138;
	float fConst139;
	float fConst140;
	float fConst141;
	float fRec27[3];
	float fConst146;
	float fConst147;
	float fConst148;
	float fConst149;
	float fRec28[3];
	float fConst154;
	float fConst155;
	float fConst156;
	float fConst157;
	float fRec29[3];
	float fConst162;
	float fConst163;
	float fConst164;
	float fConst165;
	float fRec30[3];
	float fConst166;
	float fConst171;
	float fConst172;
	float fConst173;
	float fConst174;
	float fRec31[3];
	float fConst179;
	float fConst180;
	float fConst181;
	float fConst182;
	float fRec32[3];
	float fConst183;
	float fConst184;
	float fConst189;
	float fConst190;
	float fConst191;
	float fConst192;
	float fRec33[3];
	float fConst197;
	float fConst198;
	float fConst199;
	float fConst200;
	float fRec34[3];
	float fConst201;
	float fConst202;
	float fConst206;
	float fConst207;
	float fConst208;
	float fConst209;
	float fConst210;
	float fRec35[3];
	float fConst215;
	float fConst216;
	float fConst217;
	float fConst218;
	float fRec36[3];
	float fConst223;
	float fConst224;
	float fConst225;
	float fConst226;
	float fRec37[3];
	float fConst227;
	float fConst231;
	float fConst232;
	float fConst233;
	float fConst234;
	float fRec38[3];
	float fConst235;
	float fConst236;
	float fConst237;
	float fConst238;
	float fConst239;
	float fConst240;
	float fConst241;
	float fConst242;
	float fConst243;
	float fConst244;
	float fRec1[3];
	float fConst245;
	float fConst246;
	float fConst247;
	float fRec0[3];
	float fConst251;
	float fConst252;
	float fConst253;
	float fConst254;
	float fConst255;
	float fRec39[3];
	float fConst260;
	float fConst261;
	float fConst262;
	float fConst263;
	float fRec40[3];
	float fConst268;
	float fConst269;
	float fConst270;
	float fConst271;
	float fRec41[3];
	float fConst276;
	float fConst277;
	float fConst278;
	float fConst279;
	float fRec42[3];
	float fConst280;
	float fConst284;
	float fConst285;
	float fConst286;
	float fConst287;
	float fConst288;
	float fRec43[3];
	float fConst289;
	float fConst290;
	float fConst291;
	FAUSTFLOAT fHslider8;
	float fVec9[8192];
	float fRec44[2];
	float fVec10[4096];
	float fRec45[2];
	float fVec11[4096];
	float fRec46[2];
	
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
		float fConst3 = (((fConst2 + 0.370370358f) / fConst1) + 1.0f);
		fConst4 = (1.0f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		float fConst6 = std::tan((13194.6895f / fConst0));
		float fConst7 = (1.0f / fConst6);
		float fConst8 = (((fConst7 + 1.41421354f) / fConst6) + 1.0f);
		fConst9 = (1.0f / fConst8);
		float fConst10 = std::tan((1905.69006f / fConst0));
		float fConst11 = (1.0f / fConst10);
		float fConst12 = (((fConst11 + 0.25f) / fConst10) + 1.0f);
		float fConst13 = (fConst10 * fConst12);
		fConst14 = (1.0f / fConst13);
		float fConst15 = (1.0f / fConst0);
		float fConst16 = FaustSarodDSP_faustpower2_f(fConst15);
		float fConst17 = std::tan((1256.63708f / fConst0));
		float fConst18 = (fConst0 * fConst17);
		float fConst19 = FaustSarodDSP_faustpower2_f(fConst0);
		float fConst20 = std::sqrt((4.0f * ((fConst19 * fConst17) * std::tan((251.327408f / fConst0)))));
		float fConst21 = FaustSarodDSP_faustpower2_f(fConst20);
		float fConst22 = ((2.0f * fConst18) - (0.5f * (fConst21 / fConst18)));
		float fConst23 = FaustSarodDSP_faustpower2_f(fConst22);
		fConst24 = (4.0f * fConst23);
		float fConst25 = (fConst24 + (8.0f * fConst21));
		float fConst26 = (fConst15 * fConst21);
		float fConst27 = (2.82842708f * fConst22);
		float fConst28 = (fConst22 / fConst0);
		float fConst29 = (11.3137083f * fConst28);
		float fConst30 = (((fConst16 * (fConst25 + (fConst26 * (fConst27 + fConst26)))) + fConst29) + 16.0f);
		fConst31 = (0.200000003f * (fConst16 / fConst30));
		float fConst32 = (8.0f * fConst23);
		fConst33 = (0.0f - fConst32);
		fConst34 = (1.0f / fConst30);
		float fConst35 = FaustSarodDSP_faustpower3_f(fConst15);
		float fConst36 = (fConst35 * fConst21);
		float fConst37 = (5.65685415f * fConst22);
		float fConst38 = (4.0f * fConst26);
		float fConst39 = (22.6274166f * fConst28);
		fConst40 = ((fConst36 * (fConst37 + fConst38)) + (-64.0f - fConst39));
		fConst41 = ((fConst16 * ((0.0f - (fConst32 + (16.0f * fConst21))) + (6.0f * (fConst16 * FaustSarodDSP_faustpower4_f(fConst20))))) + 96.0f);
		fConst42 = ((fConst39 + (fConst36 * (fConst38 - fConst37))) + -64.0f);
		fConst43 = ((fConst16 * (fConst25 + (fConst26 * (fConst26 - fConst27)))) + (16.0f - fConst29));
		fConst44 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst45 = (1.0f / fConst44);
		fConst46 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		float fConst47 = std::tan((3769.91113f / fConst0));
		float fConst48 = (fConst0 * fConst47);
		float fConst49 = std::sqrt((4.0f * ((fConst19 * fConst47) * std::tan((314.159271f / fConst0)))));
		float fConst50 = FaustSarodDSP_faustpower2_f(fConst49);
		float fConst51 = ((2.0f * fConst48) - (0.5f * (fConst50 / fConst48)));
		float fConst52 = FaustSarodDSP_faustpower2_f(fConst51);
		fConst53 = (4.0f * fConst52);
		float fConst54 = (fConst53 + (8.0f * fConst50));
		float fConst55 = (fConst15 * fConst50);
		float fConst56 = (2.82842708f * fConst51);
		float fConst57 = (fConst51 / fConst0);
		float fConst58 = (11.3137083f * fConst57);
		float fConst59 = (((fConst16 * (fConst54 + (fConst55 * (fConst55 + fConst56)))) + fConst58) + 16.0f);
		fConst60 = (0.180000007f * (fConst16 / fConst59));
		float fConst61 = (8.0f * fConst52);
		fConst62 = (0.0f - fConst61);
		fConst63 = (1.0f / fConst59);
		float fConst64 = (fConst35 * fConst50);
		float fConst65 = (4.0f * fConst55);
		float fConst66 = (5.65685415f * fConst51);
		float fConst67 = (22.6274166f * fConst57);
		fConst68 = ((fConst64 * (fConst65 + fConst66)) + (-64.0f - fConst67));
		fConst69 = ((fConst16 * ((0.0f - (fConst61 + (16.0f * fConst50))) + (6.0f * (fConst16 * FaustSarodDSP_faustpower4_f(fConst49))))) + 96.0f);
		fConst70 = ((fConst67 + (fConst64 * (fConst65 - fConst66))) + -64.0f);
		fConst71 = ((fConst16 * (fConst54 + (fConst55 * (fConst55 - fConst56)))) + (16.0f - fConst58));
		fConst72 = (1.0f / fConst12);
		fConst73 = (((fConst11 + -0.25f) / fConst10) + 1.0f);
		fConst74 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst10))));
		float fConst75 = std::tan((1917.31396f / fConst0));
		float fConst76 = (1.0f / fConst75);
		float fConst77 = (((fConst76 + 0.25f) / fConst75) + 1.0f);
		float fConst78 = (fConst75 * fConst77);
		fConst79 = (1.0f / fConst78);
		fConst80 = (1.0f / fConst77);
		fConst81 = (((fConst76 + -0.25f) / fConst75) + 1.0f);
		fConst82 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst75))));
		fConst83 = (0.0f - (0.0799999982f / fConst78));
		float fConst84 = std::tan((1801.07507f / fConst0));
		float fConst85 = (1.0f / fConst84);
		float fConst86 = (((fConst85 + 0.25f) / fConst84) + 1.0f);
		fConst87 = (0.100000001f / (fConst84 * fConst86));
		fConst88 = (0.0f - fConst87);
		fConst89 = (1.0f / fConst86);
		fConst90 = (((fConst85 + -0.25f) / fConst84) + 1.0f);
		fConst91 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst84))));
		float fConst92 = std::tan((1739.18567f / fConst0));
		float fConst93 = (1.0f / fConst92);
		float fConst94 = (((fConst93 + 0.25f) / fConst92) + 1.0f);
		fConst95 = (0.119999997f / (fConst92 * fConst94));
		fConst96 = (0.0f - fConst95);
		fConst97 = (1.0f / fConst94);
		fConst98 = (((fConst93 + -0.25f) / fConst92) + 1.0f);
		fConst99 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst92))));
		float fConst100 = std::tan((1683.57947f / fConst0));
		float fConst101 = (1.0f / fConst100);
		float fConst102 = (((fConst101 + 0.25f) / fConst100) + 1.0f);
		float fConst103 = (fConst100 * fConst102);
		fConst104 = (1.0f / fConst103);
		fConst105 = (1.0f / fConst102);
		fConst106 = (((fConst101 + -0.25f) / fConst100) + 1.0f);
		fConst107 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst100))));
		float fConst108 = std::tan((1709.65466f / fConst0));
		float fConst109 = (1.0f / fConst108);
		float fConst110 = (((fConst109 + 0.25f) / fConst108) + 1.0f);
		float fConst111 = (fConst108 * fConst110);
		fConst112 = (1.0f / fConst111);
		fConst113 = (1.0f / fConst110);
		fConst114 = (((fConst109 + -0.25f) / fConst108) + 1.0f);
		fConst115 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst108))));
		fConst116 = (0.0f - (0.150000006f / fConst111));
		float fConst117 = std::tan((1565.76978f / fConst0));
		float fConst118 = (1.0f / fConst117);
		float fConst119 = (((fConst118 + 0.25f) / fConst117) + 1.0f);
		float fConst120 = (fConst117 * fConst119);
		fConst121 = (1.0f / fConst120);
		fConst122 = (1.0f / fConst119);
		fConst123 = (((fConst118 + -0.25f) / fConst117) + 1.0f);
		fConst124 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst117))));
		float fConst125 = std::tan((1642.73877f / fConst0));
		float fConst126 = (1.0f / fConst125);
		float fConst127 = (((fConst126 + 0.25f) / fConst125) + 1.0f);
		float fConst128 = (fConst125 * fConst127);
		fConst129 = (1.0f / fConst128);
		fConst130 = (1.0f / fConst127);
		fConst131 = (((fConst126 + -0.25f) / fConst125) + 1.0f);
		fConst132 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst125))));
		fConst133 = (0.0f - (0.200000003f / fConst128));
		float fConst134 = std::tan((743.61499f / fConst0));
		float fConst135 = (1.0f / fConst134);
		float fConst136 = (((fConst135 + 0.25f) / fConst134) + 1.0f);
		float fConst137 = (fConst134 * fConst136);
		fConst138 = (1.0f / fConst137);
		fConst139 = (1.0f / fConst136);
		fConst140 = (((fConst135 + -0.25f) / fConst134) + 1.0f);
		fConst141 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst134))));
		float fConst142 = std::tan((754.610535f / fConst0));
		float fConst143 = (1.0f / fConst142);
		float fConst144 = (((fConst143 + 0.25f) / fConst142) + 1.0f);
		float fConst145 = (fConst142 * fConst144);
		fConst146 = (1.0f / fConst145);
		fConst147 = (1.0f / fConst144);
		fConst148 = (((fConst143 + -0.25f) / fConst142) + 1.0f);
		fConst149 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst142))));
		float fConst150 = std::tan((1461.78308f / fConst0));
		float fConst151 = (1.0f / fConst150);
		float fConst152 = (((fConst151 + 0.25f) / fConst150) + 1.0f);
		float fConst153 = (fConst150 * fConst152);
		fConst154 = (1.0f / fConst153);
		fConst155 = (1.0f / fConst152);
		fConst156 = (((fConst151 + -0.25f) / fConst150) + 1.0f);
		fConst157 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst150))));
		float fConst158 = std::tan((1499.79639f / fConst0));
		float fConst159 = (1.0f / fConst158);
		float fConst160 = (((fConst159 + 0.25f) / fConst158) + 1.0f);
		float fConst161 = (fConst158 * fConst160);
		fConst162 = (1.0f / fConst161);
		fConst163 = (1.0f / fConst160);
		fConst164 = (((fConst159 + -0.25f) / fConst158) + 1.0f);
		fConst165 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst158))));
		fConst166 = (0.0f - (0.25f / fConst153));
		float fConst167 = std::tan((1328.89368f / fConst0));
		float fConst168 = (1.0f / fConst167);
		float fConst169 = (((fConst168 + 0.25f) / fConst167) + 1.0f);
		float fConst170 = (fConst167 * fConst169);
		fConst171 = (1.0f / fConst170);
		fConst172 = (1.0f / fConst169);
		fConst173 = (((fConst168 + -0.25f) / fConst167) + 1.0f);
		fConst174 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst167))));
		float fConst175 = std::tan((1378.21667f / fConst0));
		float fConst176 = (1.0f / fConst175);
		float fConst177 = (((fConst176 + 0.25f) / fConst175) + 1.0f);
		float fConst178 = (fConst175 * fConst177);
		fConst179 = (1.0f / fConst178);
		fConst180 = (1.0f / fConst177);
		fConst181 = (((fConst176 + -0.25f) / fConst175) + 1.0f);
		fConst182 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst175))));
		fConst183 = (0.0f - (0.300000012f / fConst178));
		fConst184 = (0.0f - (0.300000012f / fConst170));
		float fConst185 = std::tan((1213.91138f / fConst0));
		float fConst186 = (1.0f / fConst185);
		float fConst187 = (((fConst186 + 0.25f) / fConst185) + 1.0f);
		float fConst188 = (fConst185 * fConst187);
		fConst189 = (1.0f / fConst188);
		fConst190 = (1.0f / fConst187);
		fConst191 = (((fConst186 + -0.25f) / fConst185) + 1.0f);
		fConst192 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst185))));
		float fConst193 = std::tan((1265.11938f / fConst0));
		float fConst194 = (1.0f / fConst193);
		float fConst195 = (((fConst194 + 0.25f) / fConst193) + 1.0f);
		float fConst196 = (fConst193 * fConst195);
		fConst197 = (1.0f / fConst196);
		fConst198 = (1.0f / fConst195);
		fConst199 = (((fConst194 + -0.25f) / fConst193) + 1.0f);
		fConst200 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst193))));
		fConst201 = (0.0f - (0.349999994f / fConst196));
		fConst202 = (0.0f - (0.349999994f / fConst188));
		float fConst203 = std::tan((1075.36719f / fConst0));
		float fConst204 = (1.0f / fConst203);
		float fConst205 = (((fConst204 + 0.25f) / fConst203) + 1.0f);
		fConst206 = (0.400000006f / (fConst203 * fConst205));
		fConst207 = (0.0f - fConst206);
		fConst208 = (1.0f / fConst205);
		fConst209 = (((fConst204 + -0.25f) / fConst203) + 1.0f);
		fConst210 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst203))));
		float fConst211 = std::tan((990.858337f / fConst0));
		float fConst212 = (1.0f / fConst211);
		float fConst213 = (((fConst212 + 0.25f) / fConst211) + 1.0f);
		float fConst214 = (fConst211 * fConst213);
		fConst215 = (1.0f / fConst214);
		fConst216 = (1.0f / fConst213);
		fConst217 = (((fConst212 + -0.25f) / fConst211) + 1.0f);
		fConst218 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst211))));
		float fConst219 = std::tan((1007.50879f / fConst0));
		float fConst220 = (1.0f / fConst219);
		float fConst221 = (((fConst220 + 0.25f) / fConst219) + 1.0f);
		float fConst222 = (fConst219 * fConst221);
		fConst223 = (1.0f / fConst222);
		fConst224 = (1.0f / fConst221);
		fConst225 = (((fConst220 + -0.25f) / fConst219) + 1.0f);
		fConst226 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst219))));
		fConst227 = (0.0f - (0.449999988f / fConst222));
		float fConst228 = std::tan((471.238892f / fConst0));
		float fConst229 = (1.0f / fConst228);
		float fConst230 = (((fConst229 + 0.25f) / fConst228) + 1.0f);
		fConst231 = (0.5f / (fConst228 * fConst230));
		fConst232 = (1.0f / fConst230);
		fConst233 = (((fConst229 + -0.25f) / fConst228) + 1.0f);
		fConst234 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst228))));
		fConst235 = (0.0f - fConst231);
		fConst236 = (0.0f - (0.25f / fConst137));
		fConst237 = (0.0f - (0.25f / fConst145));
		fConst238 = (0.0f - (0.449999988f / fConst214));
		fConst239 = (0.0f - (0.25f / fConst161));
		fConst240 = (0.0f - (0.200000003f / fConst120));
		fConst241 = (0.0f - (0.150000006f / fConst103));
		fConst242 = (0.0f - (0.0799999982f / fConst13));
		fConst243 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst244 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst245 = (1.0f / fConst3);
		fConst246 = (((fConst2 + -0.370370358f) / fConst1) + 1.0f);
		fConst247 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst248 = std::tan((5026.54834f / fConst0));
		float fConst249 = (1.0f / fConst248);
		float fConst250 = (((fConst249 + 0.370370358f) / fConst248) + 1.0f);
		fConst251 = (1.0f / (fConst248 * fConst250));
		fConst252 = (0.0f - fConst251);
		fConst253 = (1.0f / fConst250);
		fConst254 = (((fConst249 + -0.370370358f) / fConst248) + 1.0f);
		fConst255 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst248))));
		float fConst256 = std::tan((1005.30963f / fConst0));
		float fConst257 = (1.0f / fConst256);
		float fConst258 = (((fConst257 + 0.231481478f) / fConst256) + 1.0f);
		float fConst259 = (fConst256 * fConst258);
		fConst260 = (1.0f / fConst259);
		fConst261 = (1.0f / fConst258);
		fConst262 = (((fConst257 + -0.231481478f) / fConst256) + 1.0f);
		fConst263 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst256))));
		float fConst264 = std::tan((1727.87598f / fConst0));
		float fConst265 = (1.0f / fConst264);
		float fConst266 = (((fConst265 + 0.231481478f) / fConst264) + 1.0f);
		float fConst267 = (fConst264 * fConst266);
		fConst268 = (1.0f / fConst267);
		fConst269 = (1.0f / fConst266);
		fConst270 = (((fConst265 + -0.231481478f) / fConst264) + 1.0f);
		fConst271 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst264))));
		float fConst272 = std::tan((2827.43335f / fConst0));
		float fConst273 = (1.0f / fConst272);
		float fConst274 = (((fConst273 + 0.231481478f) / fConst272) + 1.0f);
		float fConst275 = (fConst272 * fConst274);
		fConst276 = (1.0f / fConst275);
		fConst277 = (1.0f / fConst274);
		fConst278 = (((fConst273 + -0.231481478f) / fConst272) + 1.0f);
		fConst279 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst272))));
		fConst280 = (0.0f - (0.300000012f / fConst267));
		float fConst281 = std::tan((565.486694f / fConst0));
		float fConst282 = (1.0f / fConst281);
		float fConst283 = (((fConst282 + 0.231481478f) / fConst281) + 1.0f);
		fConst284 = (1.0f / (fConst281 * fConst283));
		fConst285 = (0.0f - fConst284);
		fConst286 = (1.0f / fConst283);
		fConst287 = (((fConst282 + -0.231481478f) / fConst281) + 1.0f);
		fConst288 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst281))));
		fConst289 = (0.5f / fConst8);
		fConst290 = (0.0f - (0.300000012f / fConst259));
		fConst291 = (0.0f - (0.300000012f / fConst275));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(166.5f);
		fHslider2 = FAUSTFLOAT(0.25f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(111.0f);
		fHslider6 = FAUSTFLOAT(146.83000000000001f);
		fHslider7 = FAUSTFLOAT(0.050000000000000003f);
		fHslider8 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec5[l0] = 0;
		}
		for (int l1 = 0; (l1 < 5); l1 = (l1 + 1)) {
			fRec4[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iVec0[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec7[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec6[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec8[l7] = 0.0f;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 8192); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 8192); l11 = (l11 + 1)) {
			fVec4[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 8192); l14 = (l14 + 1)) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec11[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 5); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec17[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			iVec6[l19] = 0;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			iRec16[l20] = 0;
		}
		for (int l21 = 0; (l21 < 8192); l21 = (l21 + 1)) {
			fVec7[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec13[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec19[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 8192); l24 = (l24 + 1)) {
			fVec8[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec18[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec2[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec20[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec21[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec22[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec23[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec24[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec25[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec26[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec27[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec28[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec29[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec30[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec31[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec32[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec33[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec34[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec35[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec36[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec37[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec38[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec1[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec0[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec39[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec40[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec41[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec42[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec43[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 8192); l53 = (l53 + 1)) {
			fVec9[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec44[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 4096); l55 = (l55 + 1)) {
			fVec10[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec45[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 4096); l57 = (l57 + 1)) {
			fVec11[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec46[l58] = 0.0f;
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
		ui_interface->addHorizontalSlider("chikari_freq1", &fHslider5, FAUSTFLOAT(111.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_freq2", &fHslider1, FAUSTFLOAT(166.5f), FAUSTFLOAT(40.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_gain", &fHslider2, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider6, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jawari_hardness", &fHslider7, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("strike", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (4.84749985f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fSlow1 + 1.0f);
		float fSlow3 = (fConst0 / fSlow2);
		float fSlow4 = (fSlow3 + -1.0f);
		float fSlow5 = std::floor(fSlow4);
		float fSlow6 = (fSlow5 + (2.0f - fSlow3));
		float fSlow7 = float(fHslider3);
		float fSlow8 = (fConst31 * (float(fHslider2) * fSlow7));
		int iSlow9 = (float(fHslider4) > 0.5f);
		float fSlow10 = float(fButton0);
		float fSlow11 = std::pow(0.00100000005f, (0.400000006f / fSlow2));
		int iSlow12 = int(fSlow4);
		int iSlow13 = std::min<int>(16385, std::max<int>(0, iSlow12));
		float fSlow14 = (fSlow3 + (-1.0f - fSlow5));
		int iSlow15 = std::min<int>(16385, std::max<int>(0, (iSlow12 + 1)));
		float fSlow16 = (fSlow1 + -1.0f);
		float fSlow17 = (fConst0 / fSlow16);
		float fSlow18 = (fSlow17 + -1.0f);
		float fSlow19 = std::floor(fSlow18);
		float fSlow20 = (fSlow19 + (2.0f - fSlow17));
		float fSlow21 = std::pow(0.00100000005f, (0.400000006f / fSlow16));
		int iSlow22 = int(fSlow18);
		int iSlow23 = std::min<int>(16385, std::max<int>(0, iSlow22));
		float fSlow24 = (fSlow17 + (-1.0f - fSlow19));
		int iSlow25 = std::min<int>(16385, std::max<int>(0, (iSlow22 + 1)));
		float fSlow26 = float(fHslider5);
		float fSlow27 = (fSlow26 + 1.0f);
		float fSlow28 = (fConst0 / fSlow27);
		float fSlow29 = (fSlow28 + -1.0f);
		float fSlow30 = std::floor(fSlow29);
		float fSlow31 = (fSlow30 + (2.0f - fSlow28));
		float fSlow32 = std::pow(0.00100000005f, (0.400000006f / fSlow27));
		int iSlow33 = int(fSlow29);
		int iSlow34 = std::min<int>(16385, std::max<int>(0, iSlow33));
		float fSlow35 = (fSlow28 + (-1.0f - fSlow30));
		int iSlow36 = std::min<int>(16385, std::max<int>(0, (iSlow33 + 1)));
		float fSlow37 = float((1 - iSlow9));
		float fSlow38 = float(fHslider6);
		float fSlow39 = (fSlow10 * std::pow(0.00100000005f, (1.0f / (fSlow38 * (4.0f - (3.20000005f * std::max<float>(0.0f, std::min<float>(1.0f, (0.00138888892f * (fSlow38 + -80.0f))))))))));
		float fSlow40 = (fConst60 * fSlow7);
		float fSlow41 = (fConst0 / fSlow38);
		float fSlow42 = (600.0f * float(fHslider7));
		float fSlow43 = (5.0f * fSlow37);
		float fSlow44 = (fSlow26 + -1.0f);
		float fSlow45 = (fConst0 / fSlow44);
		float fSlow46 = (fSlow45 + -1.0f);
		float fSlow47 = std::floor(fSlow46);
		float fSlow48 = (fSlow47 + (2.0f - fSlow45));
		float fSlow49 = std::pow(0.00100000005f, (0.400000006f / fSlow44));
		int iSlow50 = int(fSlow46);
		int iSlow51 = std::min<int>(16385, std::max<int>(0, iSlow50));
		float fSlow52 = (fSlow45 + (-1.0f - fSlow47));
		int iSlow53 = std::min<int>(16385, std::max<int>(0, (iSlow50 + 1)));
		float fSlow54 = (0.333333343f * float(fHslider8));
		float fSlow55 = (fConst0 / std::max<float>(fSlow38, 40.0f));
		float fSlow56 = (fSlow55 + -1.0f);
		float fSlow57 = std::floor(fSlow56);
		float fSlow58 = (fSlow57 + (2.0f - fSlow55));
		int iSlow59 = int(fSlow56);
		int iSlow60 = std::min<int>(16385, std::max<int>(0, iSlow59));
		float fSlow61 = (fSlow55 + (-1.0f - fSlow57));
		int iSlow62 = std::min<int>(16385, std::max<int>(0, (iSlow59 + 1)));
		float fSlow63 = (fConst0 / std::max<float>((1.5f * fSlow38), 40.0f));
		float fSlow64 = (fSlow63 + -1.0f);
		float fSlow65 = std::floor(fSlow64);
		float fSlow66 = (fSlow65 + (2.0f - fSlow63));
		int iSlow67 = int(fSlow64);
		int iSlow68 = std::min<int>(16385, std::max<int>(0, iSlow67));
		float fSlow69 = (fSlow63 + (-1.0f - fSlow65));
		int iSlow70 = std::min<int>(16385, std::max<int>(0, (iSlow67 + 1)));
		float fSlow71 = (fConst0 / std::max<float>((2.0f * fSlow38), 40.0f));
		float fSlow72 = (fSlow71 + -1.0f);
		float fSlow73 = std::floor(fSlow72);
		float fSlow74 = (fSlow73 + (2.0f - fSlow71));
		int iSlow75 = int(fSlow72);
		int iSlow76 = std::min<int>(16385, std::max<int>(0, iSlow75));
		float fSlow77 = (fSlow71 + (-1.0f - fSlow73));
		int iSlow78 = std::min<int>(16385, std::max<int>(0, (iSlow75 + 1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * float(iRec5[0]));
			float fTempFTZ0 = (fTemp0 - (fConst34 * ((((fConst40 * fRec4[1]) + (fConst41 * fRec4[2])) + (fConst42 * fRec4[3])) + (fConst43 * fRec4[4]))));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iVec0[0] = iSlow9;
			fVec1[0] = fSlow10;
			int iTemp1 = (fSlow10 > fVec1[1]);
			float fThen0 = std::max<float>(0.0f, (fRec7[1] + -1.0f));
			float fTempFTZ1 = (((iSlow9 > iVec0[1]) | (iTemp1 & iSlow9)) ? 150.0f : fThen0);
			fRec7[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			int iTemp2 = (fRec7[0] > 0.0f);
			iVec2[0] = iTemp2;
			iRec6[0] = (((iRec6[1] + (iRec6[1] > 0)) * (iTemp2 <= iVec2[1])) + (iTemp2 > iVec2[1]));
			float fTemp3 = float(iRec6[0]);
			float fTemp4 = (fSlow8 * ((((fConst33 * fRec4[2]) + (fConst24 * fRec4[0])) + (fConst24 * fRec4[4])) * std::max<float>(0.0f, std::min<float>((fConst45 * fTemp3), (1.0f - (fConst46 * (fTemp3 - fConst44)))))));
			float fTempFTZ2 = ((0.0500000007f * fRec8[1]) + (0.949999988f * fRec3[1]));
			fRec8[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp5 = (fTemp4 + (fSlow11 * fRec8[0]));
			fVec3[(IOTA & 8191)] = fTemp5;
			float fTempFTZ3 = ((fSlow6 * fVec3[((IOTA - iSlow13) & 8191)]) + (fSlow14 * fVec3[((IOTA - iSlow15) & 8191)]));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((0.0500000007f * fRec10[1]) + (0.949999988f * fRec9[1]));
			fRec10[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp6 = (fTemp4 + (fSlow21 * fRec10[0]));
			fVec4[(IOTA & 8191)] = fTemp6;
			float fTempFTZ5 = ((fSlow20 * fVec4[((IOTA - iSlow23) & 8191)]) + (fSlow24 * fVec4[((IOTA - iSlow25) & 8191)]));
			fRec9[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = ((0.0500000007f * fRec12[1]) + (0.949999988f * fRec11[1]));
			fRec12[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp7 = (fTemp4 + (fSlow32 * fRec12[0]));
			fVec5[(IOTA & 8191)] = fTemp7;
			float fTempFTZ7 = ((fSlow31 * fVec5[((IOTA - iSlow34) & 8191)]) + (fSlow35 * fVec5[((IOTA - iSlow36) & 8191)]));
			fRec11[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fRec13[2] - (0.200000003f * (fRec14[1] - fRec13[1])));
			fRec14[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp8 = std::fabs(fRec14[0]);
			float fElse2 = (((fRec14[0] > 0.0f) ? 1.0f : -1.0f) * ((0.150000006f * (fTemp8 + -0.800000012f)) + 0.800000012f));
			float fTempFTZ9 = (fTemp0 - (fConst63 * ((((fConst68 * fRec15[1]) + (fConst69 * fRec15[2])) + (fConst70 * fRec15[3])) + (fConst71 * fRec15[4]))));
			fRec15[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fThen3 = std::max<float>(0.0f, (fRec17[1] + -1.0f));
			float fTempFTZ10 = (iTemp1 ? 150.0f : fThen3);
			fRec17[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			int iTemp9 = (fRec17[0] > 0.0f);
			iVec6[0] = iTemp9;
			iRec16[0] = (((iRec16[1] + (iRec16[1] > 0)) * (iTemp9 <= iVec6[1])) + (iTemp9 > iVec6[1]));
			float fTemp10 = float(iRec16[0]);
			float fTemp11 = ((fSlow39 * ((fTemp8 > 0.800000012f) ? fElse2 : fRec14[0])) + (fSlow40 * ((((fConst62 * fRec15[2]) + (fConst53 * fRec15[0])) + (fConst53 * fRec15[4])) * std::max<float>(0.0f, std::min<float>((fConst45 * fTemp10), (1.0f - (fConst46 * (fTemp10 - fConst44))))))));
			float fTemp12 = (fSlow37 * fTemp11);
			fVec7[(IOTA & 8191)] = fTemp12;
			float fTemp13 = std::max<float>(2.0f, (fSlow41 - (fSlow42 * std::max<float>(0.0f, (fSlow43 * fTemp11)))));
			int iTemp14 = int(fTemp13);
			float fTemp15 = std::floor(fTemp13);
			float fTempFTZ11 = ((fVec7[((IOTA - std::min<int>(16385, int(std::max<int>(0, int(iTemp14))))) & 8191)] * (fTemp15 + (1.0f - fTemp13))) + ((fTemp13 - fTemp15) * fVec7[((IOTA - std::min<int>(16385, int(std::max<int>(0, int((iTemp14 + 1)))))) & 8191)]));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = ((0.0500000007f * fRec19[1]) + (0.949999988f * fRec18[1]));
			fRec19[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp16 = ((fSlow49 * fRec19[0]) + fTemp4);
			fVec8[(IOTA & 8191)] = fTemp16;
			float fTempFTZ13 = ((fSlow48 * fVec8[((IOTA - iSlow51) & 8191)]) + (fSlow52 * fVec8[((IOTA - iSlow53) & 8191)]));
			fRec18[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp17 = float(tanhf(float((2.0f * (fRec3[0] + (fRec9[0] + (fRec11[0] + (fRec13[0] + fRec18[0]))))))));
			float fTemp18 = (0.5f * fTemp17);
			float fTempFTZ14 = (fTemp18 - (fConst72 * ((fConst73 * fRec2[2]) + (fConst74 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fTemp18 - (fConst80 * ((fConst81 * fRec20[2]) + (fConst82 * fRec20[1]))));
			fRec20[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fTemp18 - (fConst89 * ((fConst90 * fRec21[2]) + (fConst91 * fRec21[1]))));
			fRec21[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fTemp18 - (fConst97 * ((fConst98 * fRec22[2]) + (fConst99 * fRec22[1]))));
			fRec22[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fTemp18 - (fConst105 * ((fConst106 * fRec23[2]) + (fConst107 * fRec23[1]))));
			fRec23[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fTemp18 - (fConst113 * ((fConst114 * fRec24[2]) + (fConst115 * fRec24[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fTemp18 - (fConst122 * ((fConst123 * fRec25[2]) + (fConst124 * fRec25[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fTemp18 - (fConst130 * ((fConst131 * fRec26[2]) + (fConst132 * fRec26[1]))));
			fRec26[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fTemp18 - (fConst139 * ((fConst140 * fRec27[2]) + (fConst141 * fRec27[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fTemp18 - (fConst147 * ((fConst148 * fRec28[2]) + (fConst149 * fRec28[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fTemp18 - (fConst155 * ((fConst156 * fRec29[2]) + (fConst157 * fRec29[1]))));
			fRec29[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fTemp18 - (fConst163 * ((fConst164 * fRec30[2]) + (fConst165 * fRec30[1]))));
			fRec30[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (fTemp18 - (fConst172 * ((fConst173 * fRec31[2]) + (fConst174 * fRec31[1]))));
			fRec31[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (fTemp18 - (fConst180 * ((fConst181 * fRec32[2]) + (fConst182 * fRec32[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fTemp18 - (fConst190 * ((fConst191 * fRec33[2]) + (fConst192 * fRec33[1]))));
			fRec33[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (fTemp18 - (fConst198 * ((fConst199 * fRec34[2]) + (fConst200 * fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (fTemp18 - (fConst208 * ((fConst209 * fRec35[2]) + (fConst210 * fRec35[1]))));
			fRec35[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fTemp18 - (fConst216 * ((fConst217 * fRec36[2]) + (fConst218 * fRec36[1]))));
			fRec36[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (fTemp18 - (fConst224 * ((fConst225 * fRec37[2]) + (fConst226 * fRec37[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (fTemp18 - (fConst232 * ((fConst233 * fRec38[2]) + (fConst234 * fRec38[1]))));
			fRec38[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (((0.0799999982f * ((fConst14 * fRec2[0]) + (fConst79 * fRec20[0]))) + ((fConst83 * fRec20[2]) + (((fConst88 * fRec21[2]) + (((fConst96 * fRec22[2]) + (((0.150000006f * ((fConst104 * fRec23[0]) + (fConst112 * fRec24[0]))) + ((fConst116 * fRec24[2]) + (((0.200000003f * ((fConst121 * fRec25[0]) + (fConst129 * fRec26[0]))) + ((fConst133 * fRec26[2]) + (((0.25f * ((((fTemp17 + (fConst138 * fRec27[0])) + (fConst146 * fRec28[0])) + (fConst154 * fRec29[0])) + (fConst162 * fRec30[0]))) + (((fConst166 * fRec29[2]) + ((0.300000012f * ((fConst171 * fRec31[0]) + (fConst179 * fRec32[0]))) + ((fConst183 * fRec32[2]) + ((fConst184 * fRec31[2]) + ((0.349999994f * ((fConst189 * fRec33[0]) + (fConst197 * fRec34[0]))) + ((fConst201 * fRec34[2]) + ((fConst202 * fRec33[2]) + ((fConst207 * fRec35[2]) + ((fConst206 * fRec35[0]) + ((0.449999988f * ((fConst215 * fRec36[0]) + (fConst223 * fRec37[0]))) + ((fConst227 * fRec37[2]) + (((((fConst231 * fRec38[0]) + (fConst235 * fRec38[2])) + (fConst236 * fRec27[2])) + (fConst237 * fRec28[2])) + (fConst238 * fRec36[2]))))))))))))) + (fConst239 * fRec30[2]))) + (fConst240 * fRec25[2])))) + (fConst241 * fRec23[2])))) + (fConst95 * fRec22[0]))) + (fConst87 * fRec21[0]))) + (fConst242 * fRec2[2])))) - (fConst9 * ((fConst243 * fRec1[2]) + (fConst244 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTemp19 = (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1])));
			float fTemp20 = (fConst9 * fTemp19);
			float fTempFTZ35 = (fTemp20 - (fConst245 * ((fConst246 * fRec0[2]) + (fConst247 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fTemp20 - (fConst253 * ((fConst254 * fRec39[2]) + (fConst255 * fRec39[1]))));
			fRec39[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp20 - (fConst261 * ((fConst262 * fRec40[2]) + (fConst263 * fRec40[1]))));
			fRec40[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fTemp20 - (fConst269 * ((fConst270 * fRec41[2]) + (fConst271 * fRec41[1]))));
			fRec41[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fTemp20 - (fConst277 * ((fConst278 * fRec42[2]) + (fConst279 * fRec42[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fTemp20 - (fConst286 * ((fConst287 * fRec43[2]) + (fConst288 * fRec43[1]))));
			fRec43[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTemp21 = ((fConst5 * fRec0[2]) + (((fConst252 * fRec39[2]) + (((0.300000012f * (((fConst260 * fRec40[0]) + (fConst268 * fRec41[0])) + (fConst276 * fRec42[0]))) + (((fConst280 * fRec41[2]) + (((fConst285 * fRec43[2]) + ((fConst289 * fTemp19) + (fConst284 * fRec43[0]))) + (fConst290 * fRec40[2]))) + (fConst291 * fRec42[2]))) + (fConst251 * fRec39[0]))) + (fConst4 * fRec0[0])));
			float fTemp22 = (fSlow10 * fTemp21);
			float fTemp23 = ((0.996999979f * fRec44[1]) + fTemp22);
			fVec9[(IOTA & 8191)] = fTemp23;
			float fTempFTZ41 = ((fSlow58 * fVec9[((IOTA - iSlow60) & 8191)]) + (fSlow61 * fVec9[((IOTA - iSlow62) & 8191)]));
			fRec44[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTemp24 = (fTemp22 + (0.996999979f * fRec45[1]));
			fVec10[(IOTA & 4095)] = fTemp24;
			float fTempFTZ42 = ((fSlow66 * fVec10[((IOTA - iSlow68) & 4095)]) + (fSlow69 * fVec10[((IOTA - iSlow70) & 4095)]));
			fRec45[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTemp25 = (fTemp22 + (0.996999979f * fRec46[1]));
			fVec11[(IOTA & 4095)] = fTemp25;
			float fTempFTZ43 = ((fSlow74 * fVec11[((IOTA - iSlow76) & 4095)]) + (fSlow77 * fVec11[((IOTA - iSlow78) & 4095)]));
			fRec46[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp21 + (fSlow54 * ((fRec44[0] + fRec45[0]) + fRec46[0])))));
			iRec5[1] = iRec5[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec4[j0] = fRec4[(j0 - 1)];
			}
			iVec0[1] = iVec0[0];
			fVec1[1] = fVec1[0];
			fRec7[1] = fRec7[0];
			iVec2[1] = iVec2[0];
			iRec6[1] = iRec6[0];
			fRec8[1] = fRec8[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec14[1] = fRec14[0];
			for (int j1 = 4; (j1 > 0); j1 = (j1 - 1)) {
				fRec15[j1] = fRec15[(j1 - 1)];
			}
			fRec17[1] = fRec17[0];
			iVec6[1] = iVec6[0];
			iRec16[1] = iRec16[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
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
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
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
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec46[1] = fRec46[0];
		}
	}

};

#endif
