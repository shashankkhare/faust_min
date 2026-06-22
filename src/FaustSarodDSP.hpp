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
	float fConst13;
	float fConst14;
	FAUSTFLOAT fHslider1;
	float fConst25;
	float fConst32;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst34;
	int iRec5[2];
	float fConst35;
	float fConst41;
	float fConst42;
	float fConst43;
	float fConst44;
	float fRec4[5];
	float fConst45;
	float fConst46;
	FAUSTFLOAT fHslider4;
	int iVec0[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec7[2];
	int iVec2[2];
	int iRec6[2];
	float fConst47;
	float fConst48;
	float fConst49;
	float fRec8[2];
	float fRec9[2];
	int IOTA;
	float fVec3[2048];
	float fRec3[2];
	float fRec11[2];
	float fVec4[2048];
	float fRec10[2];
	FAUSTFLOAT fHslider5;
	float fRec13[2];
	float fVec5[2048];
	float fRec12[2];
	float fRec15[2];
	float fRec16[2];
	FAUSTFLOAT fHslider6;
	float fRec18[2];
	float fRec17[2];
	float fConst56;
	float fConst63;
	float fConst65;
	float fConst66;
	float fConst71;
	float fConst72;
	float fConst73;
	float fConst74;
	float fRec19[5];
	float fRec21[2];
	int iVec6[2];
	int iRec20[2];
	float fVec7[32768];
	FAUSTFLOAT fHslider7;
	float fRec14[3];
	float fRec23[2];
	float fVec8[2048];
	float fRec22[2];
	float fConst75;
	float fConst76;
	float fConst77;
	float fRec2[3];
	float fConst81;
	float fConst82;
	float fConst83;
	float fConst84;
	float fConst85;
	float fRec24[3];
	float fConst89;
	float fConst90;
	float fConst91;
	float fConst92;
	float fConst93;
	float fRec25[3];
	float fConst96;
	float fConst97;
	float fConst98;
	float fConst99;
	float fConst100;
	float fRec26[3];
	float fConst104;
	float fConst105;
	float fConst106;
	float fConst107;
	float fConst108;
	float fRec27[3];
	float fConst113;
	float fConst114;
	float fConst115;
	float fConst116;
	float fRec28[3];
	float fConst121;
	float fConst122;
	float fConst123;
	float fConst124;
	float fRec29[3];
	float fConst125;
	float fConst129;
	float fConst130;
	float fConst131;
	float fConst132;
	float fConst133;
	float fRec30[3];
	float fConst137;
	float fConst138;
	float fConst139;
	float fConst140;
	float fConst141;
	float fRec31[3];
	float fConst146;
	float fConst147;
	float fConst148;
	float fConst149;
	float fRec32[3];
	float fConst154;
	float fConst155;
	float fConst156;
	float fConst157;
	float fRec33[3];
	float fConst158;
	float fConst163;
	float fConst164;
	float fConst165;
	float fConst166;
	float fRec34[3];
	float fConst171;
	float fConst172;
	float fConst173;
	float fConst174;
	float fRec35[3];
	float fConst175;
	float fConst180;
	float fConst181;
	float fConst182;
	float fConst183;
	float fRec36[3];
	float fConst188;
	float fConst189;
	float fConst190;
	float fConst191;
	float fRec37[3];
	float fConst196;
	float fConst197;
	float fConst198;
	float fConst199;
	float fRec38[3];
	float fConst204;
	float fConst205;
	float fConst206;
	float fConst207;
	float fRec39[3];
	float fConst208;
	float fConst213;
	float fConst214;
	float fConst215;
	float fConst216;
	float fRec40[3];
	float fConst221;
	float fConst222;
	float fConst223;
	float fConst224;
	float fRec41[3];
	float fConst225;
	float fConst226;
	float fConst231;
	float fConst232;
	float fConst233;
	float fConst234;
	float fRec42[3];
	float fConst239;
	float fConst240;
	float fConst241;
	float fConst242;
	float fRec43[3];
	float fConst243;
	float fConst244;
	float fConst248;
	float fConst249;
	float fConst250;
	float fConst251;
	float fConst252;
	float fRec44[3];
	float fConst257;
	float fConst258;
	float fConst259;
	float fConst260;
	float fRec45[3];
	float fConst265;
	float fConst266;
	float fConst267;
	float fConst268;
	float fRec46[3];
	float fConst269;
	float fConst272;
	float fConst273;
	float fConst274;
	float fConst275;
	float fRec47[3];
	float fConst276;
	float fConst277;
	float fConst278;
	float fConst279;
	float fConst280;
	float fConst281;
	float fConst282;
	float fConst283;
	float fConst284;
	float fConst285;
	float fRec1[3];
	float fConst286;
	float fConst287;
	float fConst288;
	float fRec0[3];
	float fConst292;
	float fConst293;
	float fConst294;
	float fConst295;
	float fConst296;
	float fRec48[3];
	float fConst301;
	float fConst302;
	float fConst303;
	float fConst304;
	float fRec49[3];
	float fConst309;
	float fConst310;
	float fConst311;
	float fConst312;
	float fRec50[3];
	float fConst317;
	float fConst318;
	float fConst319;
	float fConst320;
	float fRec51[3];
	float fConst321;
	float fConst322;
	float fConst323;
	float fConst327;
	float fConst328;
	float fConst329;
	float fConst330;
	float fConst331;
	float fRec52[3];
	float fConst332;
	FAUSTFLOAT fHslider8;
	float fVec9[2048];
	float fRec53[2];
	float fVec10[1024];
	float fRec54[2];
	float fVec11[1024];
	float fRec55[2];
	
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((8796.45898f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.370370358f) / fConst1) + 1.0f);
		fConst4 = (1.0f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		float fConst6 = std::tan((25132.7422f / fConst0));
		float fConst7 = (1.0f / fConst6);
		float fConst8 = (((fConst7 + 1.41421354f) / fConst6) + 1.0f);
		fConst9 = (1.0f / fConst8);
		float fConst10 = std::tan((10995.5742f / fConst0));
		float fConst11 = (1.0f / fConst10);
		float fConst12 = (((fConst11 + 0.125f) / fConst10) + 1.0f);
		fConst13 = (0.0199999996f / (fConst10 * fConst12));
		fConst14 = (0.0f - fConst13);
		float fConst15 = (1.0f / fConst0);
		float fConst16 = FaustSarodDSP_faustpower2_f(fConst15);
		float fConst17 = std::tan((4712.38916f / fConst0));
		float fConst18 = (fConst0 * fConst17);
		float fConst19 = FaustSarodDSP_faustpower2_f(fConst0);
		float fConst20 = std::tan((471.238892f / fConst0));
		float fConst21 = std::sqrt((4.0f * ((fConst19 * fConst17) * fConst20)));
		float fConst22 = FaustSarodDSP_faustpower2_f(fConst21);
		float fConst23 = ((2.0f * fConst18) - (0.5f * (fConst22 / fConst18)));
		float fConst24 = FaustSarodDSP_faustpower2_f(fConst23);
		fConst25 = (4.0f * fConst24);
		float fConst26 = (fConst25 + (8.0f * fConst22));
		float fConst27 = (fConst15 * fConst22);
		float fConst28 = (2.82842708f * fConst23);
		float fConst29 = (fConst23 / fConst0);
		float fConst30 = (11.3137083f * fConst29);
		float fConst31 = (((fConst16 * (fConst26 + (fConst27 * (fConst28 + fConst27)))) + fConst30) + 16.0f);
		fConst32 = (0.0500000007f * (fConst16 / fConst31));
		float fConst33 = (8.0f * fConst24);
		fConst34 = (0.0f - fConst33);
		fConst35 = (1.0f / fConst31);
		float fConst36 = FaustSarodDSP_faustpower3_f(fConst15);
		float fConst37 = (fConst36 * fConst22);
		float fConst38 = (5.65685415f * fConst23);
		float fConst39 = (4.0f * fConst27);
		float fConst40 = (22.6274166f * fConst29);
		fConst41 = ((fConst37 * (fConst38 + fConst39)) + (-64.0f - fConst40));
		fConst42 = ((fConst16 * ((0.0f - (fConst33 + (16.0f * fConst22))) + (6.0f * (fConst16 * FaustSarodDSP_faustpower4_f(fConst21))))) + 96.0f);
		fConst43 = ((fConst40 + (fConst37 * (fConst39 - fConst38))) + -64.0f);
		fConst44 = ((fConst16 * (fConst26 + (fConst27 * (fConst27 - fConst28)))) + (16.0f - fConst30));
		fConst45 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst46 = (1.0f / fConst45);
		fConst47 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		fConst48 = (44.0999985f / fConst0);
		fConst49 = (1.0f - fConst48);
		float fConst50 = std::tan((3769.91113f / fConst0));
		float fConst51 = (fConst0 * fConst50);
		float fConst52 = std::sqrt((4.0f * ((fConst19 * fConst50) * std::tan((314.159271f / fConst0)))));
		float fConst53 = FaustSarodDSP_faustpower2_f(fConst52);
		float fConst54 = ((2.0f * fConst51) - (0.5f * (fConst53 / fConst51)));
		float fConst55 = FaustSarodDSP_faustpower2_f(fConst54);
		fConst56 = (4.0f * fConst55);
		float fConst57 = (fConst56 + (8.0f * fConst53));
		float fConst58 = (fConst15 * fConst53);
		float fConst59 = (2.82842708f * fConst54);
		float fConst60 = (fConst54 / fConst0);
		float fConst61 = (11.3137083f * fConst60);
		float fConst62 = (((fConst16 * (fConst57 + (fConst58 * (fConst58 + fConst59)))) + fConst61) + 16.0f);
		fConst63 = (0.180000007f * (fConst16 / fConst62));
		float fConst64 = (8.0f * fConst55);
		fConst65 = (0.0f - fConst64);
		fConst66 = (1.0f / fConst62);
		float fConst67 = (fConst36 * fConst53);
		float fConst68 = (4.0f * fConst58);
		float fConst69 = (5.65685415f * fConst54);
		float fConst70 = (22.6274166f * fConst60);
		fConst71 = ((fConst67 * (fConst68 + fConst69)) + (-64.0f - fConst70));
		fConst72 = ((fConst16 * ((0.0f - (fConst64 + (16.0f * fConst53))) + (6.0f * (fConst16 * FaustSarodDSP_faustpower4_f(fConst52))))) + 96.0f);
		fConst73 = ((fConst70 + (fConst67 * (fConst68 - fConst69))) + -64.0f);
		fConst74 = ((fConst16 * (fConst57 + (fConst58 * (fConst58 - fConst59)))) + (16.0f - fConst61));
		fConst75 = (1.0f / fConst12);
		fConst76 = (((fConst11 + -0.125f) / fConst10) + 1.0f);
		fConst77 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst10))));
		float fConst78 = std::tan((8168.14111f / fConst0));
		float fConst79 = (1.0f / fConst78);
		float fConst80 = (((fConst79 + 0.166666672f) / fConst78) + 1.0f);
		fConst81 = (0.0299999993f / (fConst78 * fConst80));
		fConst82 = (0.0f - fConst81);
		fConst83 = (1.0f / fConst80);
		fConst84 = (((fConst79 + -0.166666672f) / fConst78) + 1.0f);
		fConst85 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst78))));
		float fConst86 = std::tan((5654.8667f / fConst0));
		float fConst87 = (1.0f / fConst86);
		float fConst88 = (((fConst87 + 0.166666672f) / fConst86) + 1.0f);
		fConst89 = (0.0399999991f / (fConst86 * fConst88));
		fConst90 = (0.0f - fConst89);
		fConst91 = (1.0f / fConst88);
		fConst92 = (((fConst87 + -0.166666672f) / fConst86) + 1.0f);
		fConst93 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst86))));
		float fConst94 = (1.0f / fConst50);
		float fConst95 = (((fConst94 + 0.200000003f) / fConst50) + 1.0f);
		fConst96 = (0.0500000007f / (fConst50 * fConst95));
		fConst97 = (0.0f - fConst96);
		fConst98 = (1.0f / fConst95);
		fConst99 = (((fConst94 + -0.200000003f) / fConst50) + 1.0f);
		fConst100 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst50))));
		float fConst101 = std::tan((2670.35376f / fConst0));
		float fConst102 = (1.0f / fConst101);
		float fConst103 = (((fConst102 + 0.200000003f) / fConst101) + 1.0f);
		fConst104 = (0.0599999987f / (fConst101 * fConst103));
		fConst105 = (0.0f - fConst104);
		fConst106 = (1.0f / fConst103);
		fConst107 = (((fConst102 + -0.200000003f) / fConst101) + 1.0f);
		fConst108 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst101))));
		float fConst109 = std::tan((1905.69006f / fConst0));
		float fConst110 = (1.0f / fConst109);
		float fConst111 = (((fConst110 + 0.25f) / fConst109) + 1.0f);
		float fConst112 = (fConst109 * fConst111);
		fConst113 = (1.0f / fConst112);
		fConst114 = (1.0f / fConst111);
		fConst115 = (((fConst110 + -0.25f) / fConst109) + 1.0f);
		fConst116 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst109))));
		float fConst117 = std::tan((1917.31396f / fConst0));
		float fConst118 = (1.0f / fConst117);
		float fConst119 = (((fConst118 + 0.25f) / fConst117) + 1.0f);
		float fConst120 = (fConst117 * fConst119);
		fConst121 = (1.0f / fConst120);
		fConst122 = (1.0f / fConst119);
		fConst123 = (((fConst118 + -0.25f) / fConst117) + 1.0f);
		fConst124 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst117))));
		fConst125 = (0.0f - (0.0799999982f / fConst120));
		float fConst126 = std::tan((1801.07507f / fConst0));
		float fConst127 = (1.0f / fConst126);
		float fConst128 = (((fConst127 + 0.25f) / fConst126) + 1.0f);
		fConst129 = (0.100000001f / (fConst126 * fConst128));
		fConst130 = (0.0f - fConst129);
		fConst131 = (1.0f / fConst128);
		fConst132 = (((fConst127 + -0.25f) / fConst126) + 1.0f);
		fConst133 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst126))));
		float fConst134 = std::tan((1739.18567f / fConst0));
		float fConst135 = (1.0f / fConst134);
		float fConst136 = (((fConst135 + 0.25f) / fConst134) + 1.0f);
		fConst137 = (0.119999997f / (fConst134 * fConst136));
		fConst138 = (0.0f - fConst137);
		fConst139 = (1.0f / fConst136);
		fConst140 = (((fConst135 + -0.25f) / fConst134) + 1.0f);
		fConst141 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst134))));
		float fConst142 = std::tan((1683.57947f / fConst0));
		float fConst143 = (1.0f / fConst142);
		float fConst144 = (((fConst143 + 0.25f) / fConst142) + 1.0f);
		float fConst145 = (fConst142 * fConst144);
		fConst146 = (1.0f / fConst145);
		fConst147 = (1.0f / fConst144);
		fConst148 = (((fConst143 + -0.25f) / fConst142) + 1.0f);
		fConst149 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst142))));
		float fConst150 = std::tan((1709.65466f / fConst0));
		float fConst151 = (1.0f / fConst150);
		float fConst152 = (((fConst151 + 0.25f) / fConst150) + 1.0f);
		float fConst153 = (fConst150 * fConst152);
		fConst154 = (1.0f / fConst153);
		fConst155 = (1.0f / fConst152);
		fConst156 = (((fConst151 + -0.25f) / fConst150) + 1.0f);
		fConst157 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst150))));
		fConst158 = (0.0f - (0.150000006f / fConst153));
		float fConst159 = std::tan((1565.76978f / fConst0));
		float fConst160 = (1.0f / fConst159);
		float fConst161 = (((fConst160 + 0.25f) / fConst159) + 1.0f);
		float fConst162 = (fConst159 * fConst161);
		fConst163 = (1.0f / fConst162);
		fConst164 = (1.0f / fConst161);
		fConst165 = (((fConst160 + -0.25f) / fConst159) + 1.0f);
		fConst166 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst159))));
		float fConst167 = std::tan((1642.73877f / fConst0));
		float fConst168 = (1.0f / fConst167);
		float fConst169 = (((fConst168 + 0.25f) / fConst167) + 1.0f);
		float fConst170 = (fConst167 * fConst169);
		fConst171 = (1.0f / fConst170);
		fConst172 = (1.0f / fConst169);
		fConst173 = (((fConst168 + -0.25f) / fConst167) + 1.0f);
		fConst174 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst167))));
		fConst175 = (0.0f - (0.200000003f / fConst170));
		float fConst176 = std::tan((743.61499f / fConst0));
		float fConst177 = (1.0f / fConst176);
		float fConst178 = (((fConst177 + 0.25f) / fConst176) + 1.0f);
		float fConst179 = (fConst176 * fConst178);
		fConst180 = (1.0f / fConst179);
		fConst181 = (1.0f / fConst178);
		fConst182 = (((fConst177 + -0.25f) / fConst176) + 1.0f);
		fConst183 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst176))));
		float fConst184 = std::tan((754.610535f / fConst0));
		float fConst185 = (1.0f / fConst184);
		float fConst186 = (((fConst185 + 0.25f) / fConst184) + 1.0f);
		float fConst187 = (fConst184 * fConst186);
		fConst188 = (1.0f / fConst187);
		fConst189 = (1.0f / fConst186);
		fConst190 = (((fConst185 + -0.25f) / fConst184) + 1.0f);
		fConst191 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst184))));
		float fConst192 = std::tan((1461.78308f / fConst0));
		float fConst193 = (1.0f / fConst192);
		float fConst194 = (((fConst193 + 0.25f) / fConst192) + 1.0f);
		float fConst195 = (fConst192 * fConst194);
		fConst196 = (1.0f / fConst195);
		fConst197 = (1.0f / fConst194);
		fConst198 = (((fConst193 + -0.25f) / fConst192) + 1.0f);
		fConst199 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst192))));
		float fConst200 = std::tan((1499.79639f / fConst0));
		float fConst201 = (1.0f / fConst200);
		float fConst202 = (((fConst201 + 0.25f) / fConst200) + 1.0f);
		float fConst203 = (fConst200 * fConst202);
		fConst204 = (1.0f / fConst203);
		fConst205 = (1.0f / fConst202);
		fConst206 = (((fConst201 + -0.25f) / fConst200) + 1.0f);
		fConst207 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst200))));
		fConst208 = (0.0f - (0.25f / fConst195));
		float fConst209 = std::tan((1328.89368f / fConst0));
		float fConst210 = (1.0f / fConst209);
		float fConst211 = (((fConst210 + 0.25f) / fConst209) + 1.0f);
		float fConst212 = (fConst209 * fConst211);
		fConst213 = (1.0f / fConst212);
		fConst214 = (1.0f / fConst211);
		fConst215 = (((fConst210 + -0.25f) / fConst209) + 1.0f);
		fConst216 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst209))));
		float fConst217 = std::tan((1378.21667f / fConst0));
		float fConst218 = (1.0f / fConst217);
		float fConst219 = (((fConst218 + 0.25f) / fConst217) + 1.0f);
		float fConst220 = (fConst217 * fConst219);
		fConst221 = (1.0f / fConst220);
		fConst222 = (1.0f / fConst219);
		fConst223 = (((fConst218 + -0.25f) / fConst217) + 1.0f);
		fConst224 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst217))));
		fConst225 = (0.0f - (0.300000012f / fConst220));
		fConst226 = (0.0f - (0.300000012f / fConst212));
		float fConst227 = std::tan((1213.91138f / fConst0));
		float fConst228 = (1.0f / fConst227);
		float fConst229 = (((fConst228 + 0.25f) / fConst227) + 1.0f);
		float fConst230 = (fConst227 * fConst229);
		fConst231 = (1.0f / fConst230);
		fConst232 = (1.0f / fConst229);
		fConst233 = (((fConst228 + -0.25f) / fConst227) + 1.0f);
		fConst234 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst227))));
		float fConst235 = std::tan((1265.11938f / fConst0));
		float fConst236 = (1.0f / fConst235);
		float fConst237 = (((fConst236 + 0.25f) / fConst235) + 1.0f);
		float fConst238 = (fConst235 * fConst237);
		fConst239 = (1.0f / fConst238);
		fConst240 = (1.0f / fConst237);
		fConst241 = (((fConst236 + -0.25f) / fConst235) + 1.0f);
		fConst242 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst235))));
		fConst243 = (0.0f - (0.349999994f / fConst238));
		fConst244 = (0.0f - (0.349999994f / fConst230));
		float fConst245 = std::tan((1075.36719f / fConst0));
		float fConst246 = (1.0f / fConst245);
		float fConst247 = (((fConst246 + 0.25f) / fConst245) + 1.0f);
		fConst248 = (0.400000006f / (fConst245 * fConst247));
		fConst249 = (0.0f - fConst248);
		fConst250 = (1.0f / fConst247);
		fConst251 = (((fConst246 + -0.25f) / fConst245) + 1.0f);
		fConst252 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst245))));
		float fConst253 = std::tan((990.858337f / fConst0));
		float fConst254 = (1.0f / fConst253);
		float fConst255 = (((fConst254 + 0.25f) / fConst253) + 1.0f);
		float fConst256 = (fConst253 * fConst255);
		fConst257 = (1.0f / fConst256);
		fConst258 = (1.0f / fConst255);
		fConst259 = (((fConst254 + -0.25f) / fConst253) + 1.0f);
		fConst260 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst253))));
		float fConst261 = std::tan((1007.50879f / fConst0));
		float fConst262 = (1.0f / fConst261);
		float fConst263 = (((fConst262 + 0.25f) / fConst261) + 1.0f);
		float fConst264 = (fConst261 * fConst263);
		fConst265 = (1.0f / fConst264);
		fConst266 = (1.0f / fConst263);
		fConst267 = (((fConst262 + -0.25f) / fConst261) + 1.0f);
		fConst268 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst261))));
		fConst269 = (0.0f - (0.449999988f / fConst264));
		float fConst270 = (1.0f / fConst20);
		float fConst271 = (((fConst270 + 0.25f) / fConst20) + 1.0f);
		fConst272 = (0.5f / (fConst20 * fConst271));
		fConst273 = (1.0f / fConst271);
		fConst274 = (((fConst270 + -0.25f) / fConst20) + 1.0f);
		fConst275 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst20))));
		fConst276 = (0.0f - fConst272);
		fConst277 = (0.0f - (0.25f / fConst179));
		fConst278 = (0.0f - (0.25f / fConst187));
		fConst279 = (0.0f - (0.449999988f / fConst256));
		fConst280 = (0.0f - (0.25f / fConst203));
		fConst281 = (0.0f - (0.200000003f / fConst162));
		fConst282 = (0.0f - (0.150000006f / fConst145));
		fConst283 = (0.0f - (0.0799999982f / fConst112));
		fConst284 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst285 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst286 = (1.0f / fConst3);
		fConst287 = (((fConst2 + -0.370370358f) / fConst1) + 1.0f);
		fConst288 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst289 = std::tan((5026.54834f / fConst0));
		float fConst290 = (1.0f / fConst289);
		float fConst291 = (((fConst290 + 0.370370358f) / fConst289) + 1.0f);
		fConst292 = (1.0f / (fConst289 * fConst291));
		fConst293 = (0.0f - fConst292);
		fConst294 = (1.0f / fConst291);
		fConst295 = (((fConst290 + -0.370370358f) / fConst289) + 1.0f);
		fConst296 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst289))));
		float fConst297 = std::tan((1005.30963f / fConst0));
		float fConst298 = (1.0f / fConst297);
		float fConst299 = (((fConst298 + 0.231481478f) / fConst297) + 1.0f);
		float fConst300 = (fConst297 * fConst299);
		fConst301 = (1.0f / fConst300);
		fConst302 = (1.0f / fConst299);
		fConst303 = (((fConst298 + -0.231481478f) / fConst297) + 1.0f);
		fConst304 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst297))));
		float fConst305 = std::tan((1727.87598f / fConst0));
		float fConst306 = (1.0f / fConst305);
		float fConst307 = (((fConst306 + 0.231481478f) / fConst305) + 1.0f);
		float fConst308 = (fConst305 * fConst307);
		fConst309 = (1.0f / fConst308);
		fConst310 = (1.0f / fConst307);
		fConst311 = (((fConst306 + -0.231481478f) / fConst305) + 1.0f);
		fConst312 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst305))));
		float fConst313 = std::tan((2827.43335f / fConst0));
		float fConst314 = (1.0f / fConst313);
		float fConst315 = (((fConst314 + 0.231481478f) / fConst313) + 1.0f);
		float fConst316 = (fConst313 * fConst315);
		fConst317 = (1.0f / fConst316);
		fConst318 = (1.0f / fConst315);
		fConst319 = (((fConst314 + -0.231481478f) / fConst313) + 1.0f);
		fConst320 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst313))));
		fConst321 = (0.0f - (0.300000012f / fConst316));
		fConst322 = (0.0f - (0.300000012f / fConst308));
		fConst323 = (0.0f - (0.300000012f / fConst300));
		float fConst324 = std::tan((565.486694f / fConst0));
		float fConst325 = (1.0f / fConst324);
		float fConst326 = (((fConst325 + 0.231481478f) / fConst324) + 1.0f);
		fConst327 = (1.0f / (fConst324 * fConst326));
		fConst328 = (0.0f - fConst327);
		fConst329 = (1.0f / fConst326);
		fConst330 = (((fConst325 + -0.231481478f) / fConst324) + 1.0f);
		fConst331 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst324))));
		fConst332 = (0.5f / fConst8);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(166.5f);
		fHslider2 = FAUSTFLOAT(0.10000000000000001f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(130.0f);
		fHslider6 = FAUSTFLOAT(146.83000000000001f);
		fHslider7 = FAUSTFLOAT(0.050000000000000003f);
		fHslider8 = FAUSTFLOAT(0.10000000000000001f);
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
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec9[l8] = 0.0f;
		}
		IOTA = 0;
		for (int l9 = 0; (l9 < 2048); l9 = (l9 + 1)) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec3[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fVec4[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2048); l15 = (l15 + 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec17[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 5); l21 = (l21 + 1)) {
			fRec19[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec21[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			iVec6[l23] = 0;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			iRec20[l24] = 0;
		}
		for (int l25 = 0; (l25 < 32768); l25 = (l25 + 1)) {
			fVec7[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec14[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec23[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2048); l28 = (l28 + 1)) {
			fVec8[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec22[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec2[l30] = 0.0f;
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
			fRec39[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec40[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec41[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec42[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec43[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec44[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec45[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec46[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec47[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec1[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec0[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec48[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec49[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec50[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec51[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec52[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2048); l62 = (l62 + 1)) {
			fVec9[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec53[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 1024); l64 = (l64 + 1)) {
			fVec10[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec54[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 1024); l66 = (l66 + 1)) {
			fVec11[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec55[l67] = 0.0f;
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
		ui_interface->addHorizontalSlider("chikari_freq1", &fHslider5, FAUSTFLOAT(130.0f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_freq2", &fHslider1, FAUSTFLOAT(166.5f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_gain", &fHslider2, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider6, FAUSTFLOAT(146.830002f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jawari_hardness", &fHslider7, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("strike", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider8, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
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
		float fSlow8 = (fConst32 * (float(fHslider2) * fSlow7));
		int iSlow9 = (float(fHslider4) > 0.5f);
		float fSlow10 = float(fButton0);
		float fSlow11 = std::pow(0.00100000005f, (0.400000006f / fSlow2));
		int iSlow12 = (1 - iSlow9);
		float fSlow13 = (fConst48 * std::max<float>(fSlow10, float(iSlow12)));
		int iSlow14 = int(fSlow4);
		int iSlow15 = std::min<int>(16385, std::max<int>(0, iSlow14));
		float fSlow16 = (fSlow3 + (-1.0f - fSlow5));
		int iSlow17 = std::min<int>(16385, std::max<int>(0, (iSlow14 + 1)));
		float fSlow18 = (fSlow1 + -1.0f);
		float fSlow19 = (fConst0 / fSlow18);
		float fSlow20 = (fSlow19 + -1.0f);
		float fSlow21 = std::floor(fSlow20);
		float fSlow22 = (fSlow21 + (2.0f - fSlow19));
		float fSlow23 = std::pow(0.00100000005f, (0.400000006f / fSlow18));
		int iSlow24 = int(fSlow20);
		int iSlow25 = std::min<int>(16385, std::max<int>(0, iSlow24));
		float fSlow26 = (fSlow19 + (-1.0f - fSlow21));
		int iSlow27 = std::min<int>(16385, std::max<int>(0, (iSlow24 + 1)));
		float fSlow28 = float(fHslider5);
		float fSlow29 = (fSlow28 + 1.0f);
		float fSlow30 = (fConst0 / fSlow29);
		float fSlow31 = (fSlow30 + -1.0f);
		float fSlow32 = std::floor(fSlow31);
		float fSlow33 = (fSlow32 + (2.0f - fSlow30));
		float fSlow34 = std::pow(0.00100000005f, (0.400000006f / fSlow29));
		int iSlow35 = int(fSlow31);
		int iSlow36 = std::min<int>(16385, std::max<int>(0, iSlow35));
		float fSlow37 = (fSlow30 + (-1.0f - fSlow32));
		int iSlow38 = std::min<int>(16385, std::max<int>(0, (iSlow35 + 1)));
		float fSlow39 = (fConst48 * std::max<float>(fSlow10, float(iSlow9)));
		float fSlow40 = float(fHslider6);
		float fSlow41 = float(iSlow12);
		float fSlow42 = (fSlow40 * fSlow41);
		float fSlow43 = float(iSlow9);
		float fSlow44 = (fConst63 * (fSlow7 * fSlow41));
		float fSlow45 = (600.0f * float(fHslider7));
		float fSlow46 = (fSlow28 + -1.0f);
		float fSlow47 = (fConst0 / fSlow46);
		float fSlow48 = (fSlow47 + -1.0f);
		float fSlow49 = std::floor(fSlow48);
		float fSlow50 = (fSlow49 + (2.0f - fSlow47));
		float fSlow51 = std::pow(0.00100000005f, (0.400000006f / fSlow46));
		int iSlow52 = int(fSlow48);
		int iSlow53 = std::min<int>(16385, std::max<int>(0, iSlow52));
		float fSlow54 = (fSlow47 + (-1.0f - fSlow49));
		int iSlow55 = std::min<int>(16385, std::max<int>(0, (iSlow52 + 1)));
		float fSlow56 = (0.333333343f * float(fHslider8));
		float fSlow57 = (fConst0 / std::max<float>(fSlow40, 40.0f));
		float fSlow58 = (fSlow57 + -1.0f);
		float fSlow59 = std::floor(fSlow58);
		float fSlow60 = (fSlow59 + (2.0f - fSlow57));
		int iSlow61 = int(fSlow58);
		int iSlow62 = std::min<int>(16385, std::max<int>(0, iSlow61));
		float fSlow63 = (fSlow57 + (-1.0f - fSlow59));
		int iSlow64 = std::min<int>(16385, std::max<int>(0, (iSlow61 + 1)));
		float fSlow65 = (fConst0 / std::max<float>((1.5f * fSlow40), 40.0f));
		float fSlow66 = (fSlow65 + -1.0f);
		float fSlow67 = std::floor(fSlow66);
		float fSlow68 = (fSlow67 + (2.0f - fSlow65));
		int iSlow69 = int(fSlow66);
		int iSlow70 = std::min<int>(16385, std::max<int>(0, iSlow69));
		float fSlow71 = (fSlow65 + (-1.0f - fSlow67));
		int iSlow72 = std::min<int>(16385, std::max<int>(0, (iSlow69 + 1)));
		float fSlow73 = (fConst0 / std::max<float>((2.0f * fSlow40), 40.0f));
		float fSlow74 = (fSlow73 + -1.0f);
		float fSlow75 = std::floor(fSlow74);
		float fSlow76 = (fSlow75 + (2.0f - fSlow73));
		int iSlow77 = int(fSlow74);
		int iSlow78 = std::min<int>(16385, std::max<int>(0, iSlow77));
		float fSlow79 = (fSlow73 + (-1.0f - fSlow75));
		int iSlow80 = std::min<int>(16385, std::max<int>(0, (iSlow77 + 1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * float(iRec5[0]));
			float fTempFTZ0 = (fTemp0 - (fConst35 * ((((fConst41 * fRec4[1]) + (fConst42 * fRec4[2])) + (fConst43 * fRec4[3])) + (fConst44 * fRec4[4]))));
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
			float fTemp4 = (fSlow8 * ((((fConst34 * fRec4[2]) + (fConst25 * fRec4[0])) + (fConst25 * fRec4[4])) * std::max<float>(0.0f, std::min<float>((fConst46 * fTemp3), (1.0f - (fConst47 * (fTemp3 - fConst45)))))));
			float fTempFTZ2 = (fSlow13 + (fConst49 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.0500000007f * fRec9[1]) + (0.949999988f * fRec3[1]));
			fRec9[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp5 = (fTemp4 + (fSlow11 * (fRec8[0] * fRec9[0])));
			fVec3[(IOTA & 2047)] = fTemp5;
			float fTempFTZ4 = ((fSlow6 * fVec3[((IOTA - iSlow15) & 2047)]) + (fSlow16 * fVec3[((IOTA - iSlow17) & 2047)]));
			fRec3[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((0.0500000007f * fRec11[1]) + (0.949999988f * fRec10[1]));
			fRec11[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp6 = (fTemp4 + (fSlow23 * (fRec8[0] * fRec11[0])));
			fVec4[(IOTA & 2047)] = fTemp6;
			float fTempFTZ6 = ((fSlow22 * fVec4[((IOTA - iSlow25) & 2047)]) + (fSlow26 * fVec4[((IOTA - iSlow27) & 2047)]));
			fRec10[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((0.0500000007f * fRec13[1]) + (0.949999988f * fRec12[1]));
			fRec13[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp7 = (fTemp4 + (fSlow34 * (fRec8[0] * fRec13[0])));
			fVec5[(IOTA & 2047)] = fTemp7;
			float fTempFTZ8 = ((fSlow33 * fVec5[((IOTA - iSlow36) & 2047)]) + (fSlow37 * fVec5[((IOTA - iSlow38) & 2047)]));
			fRec12[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fSlow39 + (fConst49 * fRec15[1]));
			fRec15[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fRec14[2] - (0.200000003f * (fRec16[1] - fRec14[1])));
			fRec16[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp8 = std::fabs(fRec16[0]);
			float fElse2 = (((fRec16[0] > 0.0f) ? 1.0f : -1.0f) * ((0.150000006f * (fTemp8 + -0.800000012f)) + 0.800000012f));
			int iTemp9 = iTemp1;
			float fTempFTZ11 = (fSlow42 + (fSlow43 * fRec18[1]));
			fRec18[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fThen3 = ((0.00100000005f * fRec18[0]) + (0.999000013f * fRec17[1]));
			float fTempFTZ12 = (iTemp9 ? fRec18[0] : fThen3);
			fRec17[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp0 - (fConst66 * ((((fConst71 * fRec19[1]) + (fConst72 * fRec19[2])) + (fConst73 * fRec19[3])) + (fConst74 * fRec19[4]))));
			fRec19[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fThen4 = std::max<float>(0.0f, (fRec21[1] + -1.0f));
			float fTempFTZ14 = (iTemp9 ? 150.0f : fThen4);
			fRec21[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			int iTemp10 = (fRec21[0] > 0.0f);
			iVec6[0] = iTemp10;
			iRec20[0] = (((iRec20[1] + (iRec20[1] > 0)) * (iTemp10 <= iVec6[1])) + (iTemp10 > iVec6[1]));
			float fTemp11 = float(iRec20[0]);
			float fTemp12 = (((fRec15[0] * ((fTemp8 > 0.800000012f) ? fElse2 : fRec16[0])) * std::pow(0.00100000005f, (1.0f / (fRec17[0] * (4.0f - (3.20000005f * std::max<float>(0.0f, std::min<float>(1.0f, (0.00138888892f * (fRec17[0] + -80.0f)))))))))) + (fSlow44 * ((((fConst65 * fRec19[2]) + (fConst56 * fRec19[0])) + (fConst56 * fRec19[4])) * std::max<float>(0.0f, std::min<float>((fConst46 * fTemp11), (1.0f - (fConst47 * (fTemp11 - fConst45))))))));
			fVec7[(IOTA & 32767)] = fTemp12;
			float fTemp13 = std::max<float>(2.0f, ((fConst0 / fRec17[0]) - (fSlow45 * std::max<float>(0.0f, (5.0f * fTemp12)))));
			int iTemp14 = int(fTemp13);
			float fTemp15 = std::floor(fTemp13);
			float fTempFTZ15 = ((fVec7[((IOTA - std::min<int>(16385, int(std::max<int>(0, int(iTemp14))))) & 32767)] * (fTemp15 + (1.0f - fTemp13))) + ((fTemp13 - fTemp15) * fVec7[((IOTA - std::min<int>(16385, int(std::max<int>(0, int((iTemp14 + 1)))))) & 32767)]));
			fRec14[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = ((0.0500000007f * fRec23[1]) + (0.949999988f * fRec22[1]));
			fRec23[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp16 = ((fSlow51 * (fRec23[0] * fRec8[0])) + fTemp4);
			fVec8[(IOTA & 2047)] = fTemp16;
			float fTempFTZ17 = ((fSlow50 * fVec8[((IOTA - iSlow53) & 2047)]) + (fSlow54 * fVec8[((IOTA - iSlow55) & 2047)]));
			fRec22[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp17 = float(tanhf(float((2.0f * (fRec3[0] + (fRec10[0] + (fRec12[0] + (fRec14[0] + fRec22[0]))))))));
			float fTemp18 = (0.5f * fTemp17);
			float fTempFTZ18 = (fTemp18 - (fConst75 * ((fConst76 * fRec2[2]) + (fConst77 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fTemp18 - (fConst83 * ((fConst84 * fRec24[2]) + (fConst85 * fRec24[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fTemp18 - (fConst91 * ((fConst92 * fRec25[2]) + (fConst93 * fRec25[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fTemp18 - (fConst98 * ((fConst99 * fRec26[2]) + (fConst100 * fRec26[1]))));
			fRec26[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fTemp18 - (fConst106 * ((fConst107 * fRec27[2]) + (fConst108 * fRec27[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fTemp18 - (fConst114 * ((fConst115 * fRec28[2]) + (fConst116 * fRec28[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fTemp18 - (fConst122 * ((fConst123 * fRec29[2]) + (fConst124 * fRec29[1]))));
			fRec29[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fTemp18 - (fConst131 * ((fConst132 * fRec30[2]) + (fConst133 * fRec30[1]))));
			fRec30[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (fTemp18 - (fConst139 * ((fConst140 * fRec31[2]) + (fConst141 * fRec31[1]))));
			fRec31[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (fTemp18 - (fConst147 * ((fConst148 * fRec32[2]) + (fConst149 * fRec32[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fTemp18 - (fConst155 * ((fConst156 * fRec33[2]) + (fConst157 * fRec33[1]))));
			fRec33[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (fTemp18 - (fConst164 * ((fConst165 * fRec34[2]) + (fConst166 * fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (fTemp18 - (fConst172 * ((fConst173 * fRec35[2]) + (fConst174 * fRec35[1]))));
			fRec35[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fTemp18 - (fConst181 * ((fConst182 * fRec36[2]) + (fConst183 * fRec36[1]))));
			fRec36[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (fTemp18 - (fConst189 * ((fConst190 * fRec37[2]) + (fConst191 * fRec37[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (fTemp18 - (fConst197 * ((fConst198 * fRec38[2]) + (fConst199 * fRec38[1]))));
			fRec38[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fTemp18 - (fConst205 * ((fConst206 * fRec39[2]) + (fConst207 * fRec39[1]))));
			fRec39[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fTemp18 - (fConst214 * ((fConst215 * fRec40[2]) + (fConst216 * fRec40[1]))));
			fRec40[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fTemp18 - (fConst222 * ((fConst223 * fRec41[2]) + (fConst224 * fRec41[1]))));
			fRec41[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp18 - (fConst232 * ((fConst233 * fRec42[2]) + (fConst234 * fRec42[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fTemp18 - (fConst240 * ((fConst241 * fRec43[2]) + (fConst242 * fRec43[1]))));
			fRec43[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fTemp18 - (fConst250 * ((fConst251 * fRec44[2]) + (fConst252 * fRec44[1]))));
			fRec44[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fTemp18 - (fConst258 * ((fConst259 * fRec45[2]) + (fConst260 * fRec45[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = (fTemp18 - (fConst266 * ((fConst267 * fRec46[2]) + (fConst268 * fRec46[1]))));
			fRec46[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = (fTemp18 - (fConst273 * ((fConst274 * fRec47[2]) + (fConst275 * fRec47[1]))));
			fRec47[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = (((fConst14 * fRec2[2]) + (((fConst82 * fRec24[2]) + (((fConst90 * fRec25[2]) + (((fConst97 * fRec26[2]) + (((fConst105 * fRec27[2]) + (((0.0799999982f * ((fConst113 * fRec28[0]) + (fConst121 * fRec29[0]))) + ((fConst125 * fRec29[2]) + (((fConst130 * fRec30[2]) + (((fConst138 * fRec31[2]) + (((0.150000006f * ((fConst146 * fRec32[0]) + (fConst154 * fRec33[0]))) + ((fConst158 * fRec33[2]) + (((0.200000003f * ((fConst163 * fRec34[0]) + (fConst171 * fRec35[0]))) + ((fConst175 * fRec35[2]) + (((0.25f * ((((fTemp17 + (fConst180 * fRec36[0])) + (fConst188 * fRec37[0])) + (fConst196 * fRec38[0])) + (fConst204 * fRec39[0]))) + (((fConst208 * fRec38[2]) + ((0.300000012f * ((fConst213 * fRec40[0]) + (fConst221 * fRec41[0]))) + ((fConst225 * fRec41[2]) + ((fConst226 * fRec40[2]) + ((0.349999994f * ((fConst231 * fRec42[0]) + (fConst239 * fRec43[0]))) + ((fConst243 * fRec43[2]) + ((fConst244 * fRec42[2]) + ((fConst249 * fRec44[2]) + ((fConst248 * fRec44[0]) + ((0.449999988f * ((fConst257 * fRec45[0]) + (fConst265 * fRec46[0]))) + ((fConst269 * fRec46[2]) + (((((fConst272 * fRec47[0]) + (fConst276 * fRec47[2])) + (fConst277 * fRec36[2])) + (fConst278 * fRec37[2])) + (fConst279 * fRec45[2]))))))))))))) + (fConst280 * fRec39[2]))) + (fConst281 * fRec34[2])))) + (fConst282 * fRec32[2])))) + (fConst137 * fRec31[0]))) + (fConst129 * fRec30[0]))) + (fConst283 * fRec28[2])))) + (fConst104 * fRec27[0]))) + (fConst96 * fRec26[0]))) + (fConst89 * fRec25[0]))) + (fConst81 * fRec24[0]))) + (fConst13 * fRec2[0]))) - (fConst9 * ((fConst284 * fRec1[2]) + (fConst285 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTemp19 = (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1])));
			float fTemp20 = (fConst9 * fTemp19);
			float fTempFTZ44 = (fTemp20 - (fConst286 * ((fConst287 * fRec0[2]) + (fConst288 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTemp21 = (fConst5 * fRec0[2]);
			float fTemp22 = (fConst4 * fRec0[0]);
			float fTempFTZ45 = (fTemp20 - (fConst294 * ((fConst295 * fRec48[2]) + (fConst296 * fRec48[1]))));
			fRec48[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTemp23 = (fConst293 * fRec48[2]);
			float fTemp24 = (fConst292 * fRec48[0]);
			float fTempFTZ46 = (fTemp20 - (fConst302 * ((fConst303 * fRec49[2]) + (fConst304 * fRec49[1]))));
			fRec49[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = (fTemp20 - (fConst310 * ((fConst311 * fRec50[2]) + (fConst312 * fRec50[1]))));
			fRec50[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = (fTemp20 - (fConst318 * ((fConst319 * fRec51[2]) + (fConst320 * fRec51[1]))));
			fRec51[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTemp25 = (0.300000012f * (((fConst301 * fRec49[0]) + (fConst309 * fRec50[0])) + (fConst317 * fRec51[0])));
			float fTemp26 = (fConst321 * fRec51[2]);
			float fTemp27 = (fConst322 * fRec50[2]);
			float fTemp28 = (fConst323 * fRec49[2]);
			float fTempFTZ49 = (fTemp20 - (fConst329 * ((fConst330 * fRec52[2]) + (fConst331 * fRec52[1]))));
			fRec52[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTemp29 = (fConst328 * fRec52[2]);
			float fTemp30 = (fConst327 * fRec52[0]);
			float fTemp31 = (fConst332 * fTemp19);
			float fTemp32 = (fSlow10 * (fTemp21 + ((fTemp23 + ((fTemp25 + ((fTemp27 + ((fTemp29 + (fTemp31 + fTemp30)) + fTemp28)) + fTemp26)) + fTemp24)) + fTemp22)));
			float fTemp33 = ((0.996999979f * fRec53[1]) + fTemp32);
			fVec9[(IOTA & 2047)] = fTemp33;
			float fTempFTZ50 = ((fSlow60 * fVec9[((IOTA - iSlow62) & 2047)]) + (fSlow63 * fVec9[((IOTA - iSlow64) & 2047)]));
			fRec53[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTemp34 = (fTemp32 + (0.996999979f * fRec54[1]));
			fVec10[(IOTA & 1023)] = fTemp34;
			float fTempFTZ51 = ((fSlow68 * fVec10[((IOTA - iSlow70) & 1023)]) + (fSlow71 * fVec10[((IOTA - iSlow72) & 1023)]));
			fRec54[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTemp35 = (fTemp32 + (0.996999979f * fRec55[1]));
			fVec11[(IOTA & 1023)] = fTemp35;
			float fTempFTZ52 = ((fSlow76 * fVec11[((IOTA - iSlow78) & 1023)]) + (fSlow79 * fVec11[((IOTA - iSlow80) & 1023)]));
			fRec55[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp21 + (fTemp22 + (fTemp23 + (fTemp24 + (fTemp25 + (fTemp26 + (fTemp27 + (fTemp28 + (fTemp29 + (fTemp30 + (fTemp31 + (fSlow56 * ((fRec53[0] + fRec54[0]) + fRec55[0])))))))))))))));
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
			fRec9[1] = fRec9[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			for (int j1 = 4; (j1 > 0); j1 = (j1 - 1)) {
				fRec19[j1] = fRec19[(j1 - 1)];
			}
			fRec21[1] = fRec21[0];
			iVec6[1] = iVec6[0];
			iRec20[1] = iRec20[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			fRec54[1] = fRec54[0];
			fRec55[1] = fRec55[0];
		}
	}

};

#endif
