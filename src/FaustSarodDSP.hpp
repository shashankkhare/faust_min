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

class FaustSarodDSPSIG0 {
	
  private:
	
	int iVec7[2];
	int iRec17[2];
	
  public:
	
	int getNumInputsFaustSarodDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSarodDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSarodDSPSIG0(int sample_rate) {
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			iVec7[l21] = 0;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			iRec17[l22] = 0;
		}
	}
	
	void fillFaustSarodDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec7[0] = 1;
			iRec17[0] = ((iVec7[1] + iRec17[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec17[0])));
			iVec7[1] = iVec7[0];
			iRec17[1] = iRec17[0];
		}
	}

};

static FaustSarodDSPSIG0* newFaustSarodDSPSIG0() { return (FaustSarodDSPSIG0*)new FaustSarodDSPSIG0(); }
static void deleteFaustSarodDSPSIG0(FaustSarodDSPSIG0* dsp) { delete dsp; }

static float FaustSarodDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustSarodDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float FaustSarodDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}
static float ftbl0FaustSarodDSPSIG0[65536];

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
	float fRec4[2];
	float fConst15;
	float fConst24;
	float fConst31;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	int iVec0[2];
	float fConst33;
	int iRec6[2];
	float fConst34;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec5[5];
	float fConst44;
	float fConst45;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec8[2];
	int iVec2[2];
	int iRec7[2];
	float fConst46;
	int IOTA;
	float fVec3[8192];
	FAUSTFLOAT fHslider4;
	float fRec3[3];
	FAUSTFLOAT fHslider5;
	float fRec10[2];
	float fConst53;
	float fConst60;
	float fConst62;
	float fConst63;
	float fConst68;
	float fConst69;
	float fConst70;
	float fConst71;
	float fRec11[5];
	float fRec13[2];
	int iVec4[2];
	int iRec12[2];
	float fVec5[8192];
	float fRec9[2];
	float fConst72;
	float fRec15[2];
	float fVec6[4096];
	float fRec14[2];
	FAUSTFLOAT fHslider6;
	float fConst73;
	float fConst74;
	float fRec16[2];
	float fRec18[2];
	float fConst75;
	float fRec19[2];
	float fConst76;
	float fRec20[2];
	float fConst77;
	float fRec21[2];
	float fConst78;
	float fRec22[2];
	float fConst79;
	float fRec23[2];
	float fConst80;
	float fRec24[2];
	float fConst81;
	float fRec25[2];
	float fConst82;
	float fConst83;
	float fConst84;
	float fRec2[3];
	float fConst89;
	float fConst90;
	float fConst91;
	float fConst92;
	float fRec26[3];
	float fConst97;
	float fConst98;
	float fConst99;
	float fConst100;
	float fRec27[3];
	float fConst105;
	float fConst106;
	float fConst107;
	float fConst108;
	float fRec28[3];
	float fConst113;
	float fConst114;
	float fConst115;
	float fConst116;
	float fRec29[3];
	float fConst121;
	float fConst122;
	float fConst123;
	float fConst124;
	float fRec30[3];
	float fConst129;
	float fConst130;
	float fConst131;
	float fConst132;
	float fRec31[3];
	float fConst137;
	float fConst138;
	float fConst139;
	float fConst140;
	float fRec32[3];
	float fConst145;
	float fConst146;
	float fConst147;
	float fConst148;
	float fRec33[3];
	float fConst153;
	float fConst154;
	float fConst155;
	float fConst156;
	float fRec34[3];
	float fConst161;
	float fConst162;
	float fConst163;
	float fConst164;
	float fRec35[3];
	float fConst169;
	float fConst170;
	float fConst171;
	float fConst172;
	float fRec36[3];
	float fConst177;
	float fConst178;
	float fConst179;
	float fConst180;
	float fRec37[3];
	float fConst185;
	float fConst186;
	float fConst187;
	float fConst188;
	float fRec38[3];
	float fConst193;
	float fConst194;
	float fConst195;
	float fConst196;
	float fRec39[3];
	float fConst201;
	float fConst202;
	float fConst203;
	float fConst204;
	float fRec40[3];
	float fConst209;
	float fConst210;
	float fConst211;
	float fConst212;
	float fRec41[3];
	float fConst217;
	float fConst218;
	float fConst219;
	float fConst220;
	float fRec42[3];
	float fConst225;
	float fConst226;
	float fConst227;
	float fConst228;
	float fRec43[3];
	float fConst233;
	float fConst234;
	float fConst235;
	float fConst236;
	float fRec44[3];
	float fConst237;
	float fConst238;
	float fConst239;
	float fConst240;
	float fConst241;
	float fConst242;
	float fConst243;
	float fConst244;
	float fConst245;
	float fConst246;
	float fConst247;
	float fConst248;
	float fConst249;
	float fConst250;
	float fConst251;
	float fConst252;
	float fConst253;
	float fConst254;
	float fConst255;
	float fConst256;
	float fConst257;
	float fConst258;
	float fRec1[3];
	float fConst259;
	float fConst260;
	float fConst261;
	float fRec0[3];
	float fConst265;
	float fConst266;
	float fConst267;
	float fConst268;
	float fConst269;
	float fRec45[3];
	float fConst274;
	float fConst275;
	float fConst276;
	float fConst277;
	float fRec46[3];
	float fConst282;
	float fConst283;
	float fConst284;
	float fConst285;
	float fRec47[3];
	float fConst290;
	float fConst291;
	float fConst292;
	float fConst293;
	float fRec48[3];
	float fConst294;
	float fConst298;
	float fConst299;
	float fConst300;
	float fConst301;
	float fConst302;
	float fRec49[3];
	float fConst303;
	float fConst304;
	float fConst305;
	
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
		FaustSarodDSPSIG0* sig0 = newFaustSarodDSPSIG0();
		sig0->instanceInitFaustSarodDSPSIG0(sample_rate);
		sig0->fillFaustSarodDSPSIG0(65536, ftbl0FaustSarodDSPSIG0);
		deleteFaustSarodDSPSIG0(sig0);
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
		float fConst8 = (((fConst7 + 1.41421354f) / fConst6) + 1.0f);
		fConst9 = (1.0f / fConst8);
		float fConst10 = std::tan((471.238892f / fConst0));
		float fConst11 = (1.0f / fConst10);
		float fConst12 = (((fConst11 + 0.0833333358f) / fConst10) + 1.0f);
		float fConst13 = (fConst10 * fConst12);
		fConst14 = (1.0f / fConst13);
		fConst15 = (1.0f / fConst0);
		float fConst16 = FaustSarodDSP_faustpower2_f(fConst15);
		float fConst17 = std::tan((3769.91113f / fConst0));
		float fConst18 = (fConst0 * fConst17);
		float fConst19 = FaustSarodDSP_faustpower2_f(fConst0);
		float fConst20 = std::sqrt((4.0f * ((fConst19 * fConst17) * std::tan((314.159271f / fConst0)))));
		float fConst21 = FaustSarodDSP_faustpower2_f(fConst20);
		float fConst22 = ((2.0f * fConst18) - (0.5f * (fConst21 / fConst18)));
		float fConst23 = FaustSarodDSP_faustpower2_f(fConst22);
		fConst24 = (4.0f * fConst23);
		float fConst25 = (fConst24 + (8.0f * fConst21));
		float fConst26 = (fConst15 * fConst21);
		float fConst27 = (2.82842708f * fConst22);
		float fConst28 = (fConst22 / fConst0);
		float fConst29 = (11.3137083f * fConst28);
		float fConst30 = (((fConst16 * (fConst25 + (fConst26 * (fConst26 + fConst27)))) + fConst29) + 16.0f);
		fConst31 = (0.200000003f * (fConst16 / fConst30));
		float fConst32 = (8.0f * fConst23);
		fConst33 = (0.0f - fConst32);
		fConst34 = (1.0f / fConst30);
		float fConst35 = FaustSarodDSP_faustpower3_f(fConst15);
		float fConst36 = (fConst35 * fConst21);
		float fConst37 = (4.0f * fConst26);
		float fConst38 = (5.65685415f * fConst22);
		float fConst39 = (22.6274166f * fConst28);
		fConst40 = ((fConst36 * (fConst37 + fConst38)) + (-64.0f - fConst39));
		fConst41 = ((fConst16 * ((0.0f - (fConst32 + (16.0f * fConst21))) + (6.0f * (fConst16 * FaustSarodDSP_faustpower4_f(fConst20))))) + 96.0f);
		fConst42 = ((fConst39 + (fConst36 * (fConst37 - fConst38))) + -64.0f);
		fConst43 = ((fConst16 * (fConst25 + (fConst26 * (fConst26 - fConst27)))) + (16.0f - fConst29));
		fConst44 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst45 = (1.0f / fConst44);
		fConst46 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		float fConst47 = std::tan((2513.27417f / fConst0));
		float fConst48 = (fConst0 * fConst47);
		float fConst49 = std::sqrt((4.0f * ((fConst19 * fConst47) * std::tan((942.477783f / fConst0)))));
		float fConst50 = FaustSarodDSP_faustpower2_f(fConst49);
		float fConst51 = ((2.0f * fConst48) - (0.5f * (fConst50 / fConst48)));
		float fConst52 = FaustSarodDSP_faustpower2_f(fConst51);
		fConst53 = (4.0f * fConst52);
		float fConst54 = (fConst53 + (8.0f * fConst50));
		float fConst55 = (fConst15 * fConst50);
		float fConst56 = (2.82842708f * fConst51);
		float fConst57 = (fConst51 / fConst0);
		float fConst58 = (11.3137083f * fConst57);
		float fConst59 = (((fConst16 * (fConst54 + (fConst55 * (fConst56 + fConst55)))) + fConst58) + 16.0f);
		fConst60 = (0.0500000007f * (fConst16 / fConst59));
		float fConst61 = (8.0f * fConst52);
		fConst62 = (0.0f - fConst61);
		fConst63 = (1.0f / fConst59);
		float fConst64 = (fConst35 * fConst50);
		float fConst65 = (5.65685415f * fConst51);
		float fConst66 = (4.0f * fConst55);
		float fConst67 = (22.6274166f * fConst57);
		fConst68 = ((fConst64 * (fConst65 + fConst66)) + (-64.0f - fConst67));
		fConst69 = ((fConst16 * ((0.0f - (fConst61 + (16.0f * fConst50))) + (6.0f * (fConst16 * FaustSarodDSP_faustpower4_f(fConst49))))) + 96.0f);
		fConst70 = ((fConst67 + (fConst64 * (fConst66 - fConst65))) + -64.0f);
		fConst71 = ((fConst16 * (fConst54 + (fConst55 * (fConst55 - fConst56)))) + (16.0f - fConst58));
		fConst72 = (0.666666687f * fConst0);
		fConst73 = (4.0f / fConst0);
		fConst74 = float(int((3.5f * fConst0)));
		fConst75 = (0.998000026f / fConst0);
		fConst76 = (1.5f / fConst0);
		fConst77 = (1.49699998f / fConst0);
		fConst78 = (2.0f / fConst0);
		fConst79 = (1.99600005f / fConst0);
		fConst80 = (3.0f / fConst0);
		fConst81 = (2.99399996f / fConst0);
		fConst82 = (1.0f / fConst12);
		fConst83 = (((fConst11 + -0.0833333358f) / fConst10) + 1.0f);
		fConst84 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst10))));
		float fConst85 = std::tan((743.61499f / fConst0));
		float fConst86 = (1.0f / fConst85);
		float fConst87 = (((fConst86 + 0.0833333358f) / fConst85) + 1.0f);
		float fConst88 = (fConst85 * fConst87);
		fConst89 = (1.0f / fConst88);
		fConst90 = (1.0f / fConst87);
		fConst91 = (((fConst86 + -0.0833333358f) / fConst85) + 1.0f);
		fConst92 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst85))));
		float fConst93 = std::tan((754.610535f / fConst0));
		float fConst94 = (1.0f / fConst93);
		float fConst95 = (((fConst94 + 0.0833333358f) / fConst93) + 1.0f);
		float fConst96 = (fConst93 * fConst95);
		fConst97 = (1.0f / fConst96);
		fConst98 = (1.0f / fConst95);
		fConst99 = (((fConst94 + -0.0833333358f) / fConst93) + 1.0f);
		fConst100 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst93))));
		float fConst101 = std::tan((990.858337f / fConst0));
		float fConst102 = (1.0f / fConst101);
		float fConst103 = (((fConst102 + 0.0833333358f) / fConst101) + 1.0f);
		float fConst104 = (fConst101 * fConst103);
		fConst105 = (1.0f / fConst104);
		fConst106 = (1.0f / fConst103);
		fConst107 = (((fConst102 + -0.0833333358f) / fConst101) + 1.0f);
		fConst108 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst101))));
		float fConst109 = std::tan((1007.50879f / fConst0));
		float fConst110 = (1.0f / fConst109);
		float fConst111 = (((fConst110 + 0.0833333358f) / fConst109) + 1.0f);
		float fConst112 = (fConst109 * fConst111);
		fConst113 = (1.0f / fConst112);
		fConst114 = (1.0f / fConst111);
		fConst115 = (((fConst110 + -0.0833333358f) / fConst109) + 1.0f);
		fConst116 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst109))));
		float fConst117 = std::tan((1075.36719f / fConst0));
		float fConst118 = (1.0f / fConst117);
		float fConst119 = (((fConst118 + 0.0833333358f) / fConst117) + 1.0f);
		float fConst120 = (fConst117 * fConst119);
		fConst121 = (1.0f / fConst120);
		fConst122 = (1.0f / fConst119);
		fConst123 = (((fConst118 + -0.0833333358f) / fConst117) + 1.0f);
		fConst124 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst117))));
		float fConst125 = std::tan((1213.91138f / fConst0));
		float fConst126 = (1.0f / fConst125);
		float fConst127 = (((fConst126 + 0.0833333358f) / fConst125) + 1.0f);
		float fConst128 = (fConst125 * fConst127);
		fConst129 = (1.0f / fConst128);
		fConst130 = (1.0f / fConst127);
		fConst131 = (((fConst126 + -0.0833333358f) / fConst125) + 1.0f);
		fConst132 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst125))));
		float fConst133 = std::tan((1265.11938f / fConst0));
		float fConst134 = (1.0f / fConst133);
		float fConst135 = (((fConst134 + 0.0833333358f) / fConst133) + 1.0f);
		float fConst136 = (fConst133 * fConst135);
		fConst137 = (1.0f / fConst136);
		fConst138 = (1.0f / fConst135);
		fConst139 = (((fConst134 + -0.0833333358f) / fConst133) + 1.0f);
		fConst140 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst133))));
		float fConst141 = std::tan((1328.89368f / fConst0));
		float fConst142 = (1.0f / fConst141);
		float fConst143 = (((fConst142 + 0.0833333358f) / fConst141) + 1.0f);
		float fConst144 = (fConst141 * fConst143);
		fConst145 = (1.0f / fConst144);
		fConst146 = (1.0f / fConst143);
		fConst147 = (((fConst142 + -0.0833333358f) / fConst141) + 1.0f);
		fConst148 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst141))));
		float fConst149 = std::tan((1378.21667f / fConst0));
		float fConst150 = (1.0f / fConst149);
		float fConst151 = (((fConst150 + 0.0833333358f) / fConst149) + 1.0f);
		float fConst152 = (fConst149 * fConst151);
		fConst153 = (1.0f / fConst152);
		fConst154 = (1.0f / fConst151);
		fConst155 = (((fConst150 + -0.0833333358f) / fConst149) + 1.0f);
		fConst156 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst149))));
		float fConst157 = std::tan((1461.78308f / fConst0));
		float fConst158 = (1.0f / fConst157);
		float fConst159 = (((fConst158 + 0.0833333358f) / fConst157) + 1.0f);
		float fConst160 = (fConst157 * fConst159);
		fConst161 = (1.0f / fConst160);
		fConst162 = (1.0f / fConst159);
		fConst163 = (((fConst158 + -0.0833333358f) / fConst157) + 1.0f);
		fConst164 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst157))));
		float fConst165 = std::tan((1499.79639f / fConst0));
		float fConst166 = (1.0f / fConst165);
		float fConst167 = (((fConst166 + 0.0833333358f) / fConst165) + 1.0f);
		float fConst168 = (fConst165 * fConst167);
		fConst169 = (1.0f / fConst168);
		fConst170 = (1.0f / fConst167);
		fConst171 = (((fConst166 + -0.0833333358f) / fConst165) + 1.0f);
		fConst172 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst165))));
		float fConst173 = std::tan((1565.76978f / fConst0));
		float fConst174 = (1.0f / fConst173);
		float fConst175 = (((fConst174 + 0.0833333358f) / fConst173) + 1.0f);
		float fConst176 = (fConst173 * fConst175);
		fConst177 = (1.0f / fConst176);
		fConst178 = (1.0f / fConst175);
		fConst179 = (((fConst174 + -0.0833333358f) / fConst173) + 1.0f);
		fConst180 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst173))));
		float fConst181 = std::tan((1642.73877f / fConst0));
		float fConst182 = (1.0f / fConst181);
		float fConst183 = (((fConst182 + 0.0833333358f) / fConst181) + 1.0f);
		float fConst184 = (fConst181 * fConst183);
		fConst185 = (1.0f / fConst184);
		fConst186 = (1.0f / fConst183);
		fConst187 = (((fConst182 + -0.0833333358f) / fConst181) + 1.0f);
		fConst188 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst181))));
		float fConst189 = std::tan((1683.57947f / fConst0));
		float fConst190 = (1.0f / fConst189);
		float fConst191 = (((fConst190 + 0.0833333358f) / fConst189) + 1.0f);
		float fConst192 = (fConst189 * fConst191);
		fConst193 = (1.0f / fConst192);
		fConst194 = (1.0f / fConst191);
		fConst195 = (((fConst190 + -0.0833333358f) / fConst189) + 1.0f);
		fConst196 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst189))));
		float fConst197 = std::tan((1709.65466f / fConst0));
		float fConst198 = (1.0f / fConst197);
		float fConst199 = (((fConst198 + 0.0833333358f) / fConst197) + 1.0f);
		float fConst200 = (fConst197 * fConst199);
		fConst201 = (1.0f / fConst200);
		fConst202 = (1.0f / fConst199);
		fConst203 = (((fConst198 + -0.0833333358f) / fConst197) + 1.0f);
		fConst204 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst197))));
		float fConst205 = std::tan((1739.18567f / fConst0));
		float fConst206 = (1.0f / fConst205);
		float fConst207 = (((fConst206 + 0.0833333358f) / fConst205) + 1.0f);
		float fConst208 = (fConst205 * fConst207);
		fConst209 = (1.0f / fConst208);
		fConst210 = (1.0f / fConst207);
		fConst211 = (((fConst206 + -0.0833333358f) / fConst205) + 1.0f);
		fConst212 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst205))));
		float fConst213 = std::tan((1801.07507f / fConst0));
		float fConst214 = (1.0f / fConst213);
		float fConst215 = (((fConst214 + 0.0833333358f) / fConst213) + 1.0f);
		float fConst216 = (fConst213 * fConst215);
		fConst217 = (1.0f / fConst216);
		fConst218 = (1.0f / fConst215);
		fConst219 = (((fConst214 + -0.0833333358f) / fConst213) + 1.0f);
		fConst220 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst213))));
		float fConst221 = std::tan((1905.69006f / fConst0));
		float fConst222 = (1.0f / fConst221);
		float fConst223 = (((fConst222 + 0.0833333358f) / fConst221) + 1.0f);
		float fConst224 = (fConst221 * fConst223);
		fConst225 = (1.0f / fConst224);
		fConst226 = (1.0f / fConst223);
		fConst227 = (((fConst222 + -0.0833333358f) / fConst221) + 1.0f);
		fConst228 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst221))));
		float fConst229 = std::tan((1917.31396f / fConst0));
		float fConst230 = (1.0f / fConst229);
		float fConst231 = (((fConst230 + 0.0833333358f) / fConst229) + 1.0f);
		float fConst232 = (fConst229 * fConst231);
		fConst233 = (1.0f / fConst232);
		fConst234 = (1.0f / fConst231);
		fConst235 = (((fConst230 + -0.0833333358f) / fConst229) + 1.0f);
		fConst236 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst229))));
		fConst237 = (0.0f - (0.5f / fConst88));
		fConst238 = (0.0f - (0.5f / fConst13));
		fConst239 = (0.0f - (0.5f / fConst96));
		fConst240 = (0.0f - (0.5f / fConst104));
		fConst241 = (0.0f - (0.5f / fConst112));
		fConst242 = (0.0f - (0.5f / fConst120));
		fConst243 = (0.0f - (0.5f / fConst128));
		fConst244 = (0.0f - (0.5f / fConst136));
		fConst245 = (0.0f - (0.5f / fConst144));
		fConst246 = (0.0f - (0.5f / fConst152));
		fConst247 = (0.0f - (0.5f / fConst160));
		fConst248 = (0.0f - (0.5f / fConst168));
		fConst249 = (0.0f - (0.5f / fConst176));
		fConst250 = (0.0f - (0.5f / fConst184));
		fConst251 = (0.0f - (0.5f / fConst192));
		fConst252 = (0.0f - (0.5f / fConst200));
		fConst253 = (0.0f - (0.5f / fConst208));
		fConst254 = (0.0f - (0.5f / fConst216));
		fConst255 = (0.0f - (0.5f / fConst224));
		fConst256 = (0.0f - (0.5f / fConst232));
		fConst257 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst258 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst259 = (1.0f / fConst3);
		fConst260 = (((fConst2 + -0.200000003f) / fConst1) + 1.0f);
		fConst261 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst262 = std::tan((5026.54834f / fConst0));
		float fConst263 = (1.0f / fConst262);
		float fConst264 = (((fConst263 + 0.200000003f) / fConst262) + 1.0f);
		fConst265 = (1.0f / (fConst262 * fConst264));
		fConst266 = (0.0f - fConst265);
		fConst267 = (1.0f / fConst264);
		fConst268 = (((fConst263 + -0.200000003f) / fConst262) + 1.0f);
		fConst269 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst262))));
		float fConst270 = std::tan((1005.30963f / fConst0));
		float fConst271 = (1.0f / fConst270);
		float fConst272 = (((fConst271 + 0.125f) / fConst270) + 1.0f);
		float fConst273 = (fConst270 * fConst272);
		fConst274 = (1.0f / fConst273);
		fConst275 = (1.0f / fConst272);
		fConst276 = (((fConst271 + -0.125f) / fConst270) + 1.0f);
		fConst277 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst270))));
		float fConst278 = std::tan((1727.87598f / fConst0));
		float fConst279 = (1.0f / fConst278);
		float fConst280 = (((fConst279 + 0.125f) / fConst278) + 1.0f);
		float fConst281 = (fConst278 * fConst280);
		fConst282 = (1.0f / fConst281);
		fConst283 = (1.0f / fConst280);
		fConst284 = (((fConst279 + -0.125f) / fConst278) + 1.0f);
		fConst285 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst278))));
		float fConst286 = std::tan((2827.43335f / fConst0));
		float fConst287 = (1.0f / fConst286);
		float fConst288 = (((fConst287 + 0.125f) / fConst286) + 1.0f);
		float fConst289 = (fConst286 * fConst288);
		fConst290 = (1.0f / fConst289);
		fConst291 = (1.0f / fConst288);
		fConst292 = (((fConst287 + -0.125f) / fConst286) + 1.0f);
		fConst293 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst286))));
		fConst294 = (0.0f - (0.300000012f / fConst281));
		float fConst295 = std::tan((565.486694f / fConst0));
		float fConst296 = (1.0f / fConst295);
		float fConst297 = (((fConst296 + 0.125f) / fConst295) + 1.0f);
		fConst298 = (1.0f / (fConst295 * fConst297));
		fConst299 = (0.0f - fConst298);
		fConst300 = (1.0f / fConst297);
		fConst301 = (((fConst296 + -0.125f) / fConst295) + 1.0f);
		fConst302 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst295))));
		fConst303 = (0.5f / fConst8);
		fConst304 = (0.0f - (0.300000012f / fConst273));
		fConst305 = (0.0f - (0.300000012f / fConst289));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(146.83000000000001f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.050000000000000003f);
		fHslider5 = FAUSTFLOAT(440.0f);
		fHslider6 = FAUSTFLOAT(0.29999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec4[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec6[l2] = 0;
		}
		for (int l3 = 0; (l3 < 5); l3 = (l3 + 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec8[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iVec2[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec7[l7] = 0;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 8192); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 5); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			iVec4[l13] = 0;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iRec12[l14] = 0;
		}
		for (int l15 = 0; (l15 < 8192); l15 = (l15 + 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec9[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 4096); l18 = (l18 + 1)) {
			fVec6[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec14[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec16[l20] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec18[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec19[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec20[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec21[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec22[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec23[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec24[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec25[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec2[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec26[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec27[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec28[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec29[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec30[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec31[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec32[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec33[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec34[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec35[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec36[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec37[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec38[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec39[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec40[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec41[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec42[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec43[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec44[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec1[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec0[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec45[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec46[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec47[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec48[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec49[l57] = 0.0f;
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
		ui_interface->addHorizontalSlider("chikari_freq", &fHslider5, FAUSTFLOAT(440.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jawari_hardness", &fHslider4, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("strike", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider6, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::pow(0.00100000005f, (1.0f / (fSlow1 * (4.0f - (3.20000005f * std::max<float>(0.0f, std::min<float>(1.0f, (0.00138888892f * (fSlow1 + -80.0f)))))))));
		float fSlow3 = float(fHslider2);
		int iSlow4 = (float(fHslider3) > 0.5f);
		float fSlow5 = (fConst31 * (fSlow3 * float((1 - iSlow4))));
		float fSlow6 = float(fButton0);
		float fSlow7 = (fConst0 / fSlow1);
		float fSlow8 = (600.0f * float(fHslider4));
		float fSlow9 = float(fHslider5);
		float fSlow10 = (fConst0 / fSlow9);
		float fSlow11 = (fSlow10 + -1.0f);
		float fSlow12 = std::floor(fSlow11);
		float fSlow13 = (fSlow12 + (2.0f - fSlow10));
		float fSlow14 = std::pow(0.00100000005f, (0.400000006f / fSlow9));
		float fSlow15 = (fConst60 * fSlow3);
		int iSlow16 = int(fSlow11);
		int iSlow17 = std::min<int>(16385, std::max<int>(0, iSlow16));
		float fSlow18 = (fSlow10 + (-1.0f - fSlow12));
		int iSlow19 = std::min<int>(16385, std::max<int>(0, (iSlow16 + 1)));
		float fSlow20 = (fConst72 / fSlow9);
		float fSlow21 = (fSlow20 + -1.0f);
		float fSlow22 = std::floor(fSlow21);
		float fSlow23 = (fSlow22 + (2.0f - fSlow20));
		float fSlow24 = std::pow(0.00100000005f, (0.266666681f / fSlow9));
		int iSlow25 = int(fSlow21);
		int iSlow26 = std::min<int>(16385, std::max<int>(0, iSlow25));
		float fSlow27 = (fSlow20 + (-1.0f - fSlow22));
		int iSlow28 = std::min<int>(16385, std::max<int>(0, (iSlow25 + 1)));
		float fSlow29 = float(fHslider6);
		float fSlow30 = (iSlow4 ? fSlow9 : fSlow1);
		float fSlow31 = (fConst15 * fSlow30);
		float fSlow32 = (fConst75 * fSlow30);
		float fSlow33 = (fConst76 * fSlow30);
		float fSlow34 = (fConst77 * fSlow30);
		float fSlow35 = (fConst78 * fSlow30);
		float fSlow36 = (fConst79 * fSlow30);
		float fSlow37 = (fConst80 * fSlow30);
		float fSlow38 = (fConst81 * fSlow30);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fRec3[2] - (0.200000003f * (fRec4[1] - fRec3[1])));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = std::fabs(fRec4[0]);
			float fElse1 = (((fRec4[0] > 0.0f) ? 1.0f : -1.0f) * ((0.150000006f * (fTemp0 + -0.800000012f)) + 0.800000012f));
			iVec0[0] = iSlow4;
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fTemp1 = (4.65661287e-10f * float(iRec6[0]));
			float fTempFTZ1 = (fTemp1 - (fConst34 * ((((fConst40 * fRec5[1]) + (fConst41 * fRec5[2])) + (fConst42 * fRec5[3])) + (fConst43 * fRec5[4]))));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			fVec1[0] = fSlow6;
			int iTemp2 = (fSlow6 > fVec1[1]);
			float fThen2 = std::max<float>(0.0f, (fRec8[1] + -1.0f));
			float fTempFTZ2 = (iTemp2 ? 150.0f : fThen2);
			fRec8[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			int iTemp3 = (fRec8[0] > 0.0f);
			iVec2[0] = iTemp3;
			iRec7[0] = (((iRec7[1] + (iRec7[1] > 0)) * (iTemp3 <= iVec2[1])) + (iTemp3 > iVec2[1]));
			float fTemp4 = float(iRec7[0]);
			float fTemp5 = ((fSlow2 * ((fTemp0 > 0.800000012f) ? fElse1 : fRec4[0])) + (fSlow5 * ((((fConst33 * fRec5[2]) + (fConst24 * fRec5[0])) + (fConst24 * fRec5[4])) * std::max<float>(0.0f, std::min<float>((fConst45 * fTemp4), (1.0f - (fConst46 * (fTemp4 - fConst44))))))));
			fVec3[(IOTA & 8191)] = fTemp5;
			float fTemp6 = std::max<float>(2.0f, (fSlow7 - (fSlow8 * std::max<float>(0.0f, (5.0f * fTemp5)))));
			int iTemp7 = int(fTemp6);
			float fTemp8 = std::floor(fTemp6);
			float fTempFTZ3 = ((fVec3[((IOTA - std::min<int>(16385, int(std::max<int>(0, int(iTemp7))))) & 8191)] * (fTemp8 + (1.0f - fTemp6))) + ((fTemp6 - fTemp8) * fVec3[((IOTA - std::min<int>(16385, int(std::max<int>(0, int((iTemp7 + 1)))))) & 8191)]));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((0.0500000007f * fRec10[1]) + (0.949999988f * fRec9[1]));
			fRec10[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 - (fConst63 * ((((fConst68 * fRec11[1]) + (fConst69 * fRec11[2])) + (fConst70 * fRec11[3])) + (fConst71 * fRec11[4]))));
			fRec11[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			int iTemp9 = (iSlow4 > iVec0[1]);
			float fThen3 = std::max<float>(0.0f, (fRec13[1] + -1.0f));
			float fTempFTZ6 = (iTemp9 ? 150.0f : fThen3);
			fRec13[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			int iTemp10 = (fRec13[0] > 0.0f);
			iVec4[0] = iTemp10;
			iRec12[0] = (((iRec12[1] + (iRec12[1] > 0)) * (iTemp10 <= iVec4[1])) + (iTemp10 > iVec4[1]));
			float fTemp11 = float(iRec12[0]);
			float fTemp12 = (fSlow15 * ((((fConst62 * fRec11[2]) + (fConst53 * fRec11[0])) + (fConst53 * fRec11[4])) * std::max<float>(0.0f, std::min<float>((fConst45 * fTemp11), (1.0f - (fConst46 * (fTemp11 - fConst44)))))));
			float fTemp13 = ((fSlow14 * fRec10[0]) + fTemp12);
			fVec5[(IOTA & 8191)] = fTemp13;
			float fTempFTZ7 = ((fSlow13 * fVec5[((IOTA - iSlow17) & 8191)]) + (fSlow18 * fVec5[((IOTA - iSlow19) & 8191)]));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = ((0.0500000007f * fRec15[1]) + (0.949999988f * fRec14[1]));
			fRec15[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp14 = (fTemp12 + (fSlow24 * fRec15[0]));
			fVec6[(IOTA & 4095)] = fTemp14;
			float fTempFTZ9 = ((fSlow23 * fVec6[((IOTA - iSlow26) & 4095)]) + (fSlow27 * fVec6[((IOTA - iSlow28) & 4095)]));
			fRec14[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fThen4 = std::max<float>(0.0f, (fRec16[1] + -1.0f));
			float fTempFTZ10 = ((iTemp9 + iTemp2) ? fConst74 : fThen4);
			fRec16[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp15 = (fConst74 - fRec16[0]);
			float fTemp16 = (0.0f - (fConst73 * fTemp15));
			float fTemp17 = (fConst15 * fTemp15);
			float fTemp18 = (fRec18[1] + fSlow31);
			float fTempFTZ11 = (fTemp18 - std::floor(fTemp18));
			fRec18[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp19 = (fRec19[1] + fSlow32);
			float fTempFTZ12 = (fTemp19 - std::floor(fTemp19));
			fRec19[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp20 = (fRec20[1] + fSlow33);
			float fTempFTZ13 = (fTemp20 - std::floor(fTemp20));
			fRec20[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp21 = (fRec21[1] + fSlow34);
			float fTempFTZ14 = (fTemp21 - std::floor(fTemp21));
			fRec21[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp22 = (fRec22[1] + fSlow35);
			float fTempFTZ15 = (fTemp22 - std::floor(fTemp22));
			fRec22[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp23 = (fRec23[1] + fSlow36);
			float fTempFTZ16 = (fTemp23 - std::floor(fTemp23));
			fRec23[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp24 = (fRec24[1] + fSlow37);
			float fTempFTZ17 = (fTemp24 - std::floor(fTemp24));
			fRec24[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp25 = (fRec25[1] + fSlow38);
			float fTempFTZ18 = (fTemp25 - std::floor(fTemp25));
			fRec25[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp26 = float(tanhf(float((2.0f * ((fRec3[0] + (2.0f * (fRec9[0] + fRec14[0]))) + (fSlow29 * ((((0.0500000007f * (((1.0f - std::exp((8.33333302f * fTemp16))) * std::exp((0.0f - (1.5f * std::max<float>(0.0f, (fTemp17 + -0.119999997f)))))) * (ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec18[0]))] + ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec19[0]))]))) + (0.0299999993f * (((1.0f - std::exp((6.66666651f * fTemp16))) * std::exp((0.0f - (1.20000005f * std::max<float>(0.0f, (fTemp17 + -0.150000006f)))))) * (ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec20[0]))] + ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec21[0]))])))) + (0.0399999991f * (((1.0f - std::exp((10.0f * fTemp16))) * std::exp((0.0f - (1.79999995f * std::max<float>(0.0f, (fTemp17 + -0.100000001f)))))) * (ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec22[0]))] + ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec23[0]))])))) + (0.0199999996f * (((1.0f - std::exp((5.0f * fTemp16))) * std::exp((0.0f - std::max<float>(0.0f, (fTemp17 + -0.200000003f))))) * (ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec24[0]))] + ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec25[0]))]))))))))));
			float fTemp27 = (0.5f * fTemp26);
			float fTempFTZ19 = (fTemp27 - (fConst82 * ((fConst83 * fRec2[2]) + (fConst84 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fTemp27 - (fConst90 * ((fConst91 * fRec26[2]) + (fConst92 * fRec26[1]))));
			fRec26[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fTemp27 - (fConst98 * ((fConst99 * fRec27[2]) + (fConst100 * fRec27[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fTemp27 - (fConst106 * ((fConst107 * fRec28[2]) + (fConst108 * fRec28[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fTemp27 - (fConst114 * ((fConst115 * fRec29[2]) + (fConst116 * fRec29[1]))));
			fRec29[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fTemp27 - (fConst122 * ((fConst123 * fRec30[2]) + (fConst124 * fRec30[1]))));
			fRec30[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fTemp27 - (fConst130 * ((fConst131 * fRec31[2]) + (fConst132 * fRec31[1]))));
			fRec31[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (fTemp27 - (fConst138 * ((fConst139 * fRec32[2]) + (fConst140 * fRec32[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (fTemp27 - (fConst146 * ((fConst147 * fRec33[2]) + (fConst148 * fRec33[1]))));
			fRec33[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fTemp27 - (fConst154 * ((fConst155 * fRec34[2]) + (fConst156 * fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (fTemp27 - (fConst162 * ((fConst163 * fRec35[2]) + (fConst164 * fRec35[1]))));
			fRec35[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (fTemp27 - (fConst170 * ((fConst171 * fRec36[2]) + (fConst172 * fRec36[1]))));
			fRec36[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fTemp27 - (fConst178 * ((fConst179 * fRec37[2]) + (fConst180 * fRec37[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (fTemp27 - (fConst186 * ((fConst187 * fRec38[2]) + (fConst188 * fRec38[1]))));
			fRec38[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (fTemp27 - (fConst194 * ((fConst195 * fRec39[2]) + (fConst196 * fRec39[1]))));
			fRec39[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fTemp27 - (fConst202 * ((fConst203 * fRec40[2]) + (fConst204 * fRec40[1]))));
			fRec40[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fTemp27 - (fConst210 * ((fConst211 * fRec41[2]) + (fConst212 * fRec41[1]))));
			fRec41[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fTemp27 - (fConst218 * ((fConst219 * fRec42[2]) + (fConst220 * fRec42[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp27 - (fConst226 * ((fConst227 * fRec43[2]) + (fConst228 * fRec43[1]))));
			fRec43[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fTemp27 - (fConst234 * ((fConst235 * fRec44[2]) + (fConst236 * fRec44[1]))));
			fRec44[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (((0.5f * ((((((((((((((((((((fConst14 * fRec2[0]) + (fConst89 * fRec26[0])) + (fConst97 * fRec27[0])) + (fConst105 * fRec28[0])) + (fConst113 * fRec29[0])) + (fConst121 * fRec30[0])) + (fConst129 * fRec31[0])) + (fConst137 * fRec32[0])) + (fConst145 * fRec33[0])) + (fConst153 * fRec34[0])) + (fConst161 * fRec35[0])) + (fConst169 * fRec36[0])) + (fConst177 * fRec37[0])) + (fConst185 * fRec38[0])) + (fConst193 * fRec39[0])) + (fConst201 * fRec40[0])) + (fConst209 * fRec41[0])) + (fConst217 * fRec42[0])) + (fConst225 * fRec43[0])) + (fConst233 * fRec44[0]))) + ((((((((((((((((((((fConst237 * fRec26[2]) + ((0.25f * fTemp26) + (fConst238 * fRec2[2]))) + (fConst239 * fRec27[2])) + (fConst240 * fRec28[2])) + (fConst241 * fRec29[2])) + (fConst242 * fRec30[2])) + (fConst243 * fRec31[2])) + (fConst244 * fRec32[2])) + (fConst245 * fRec33[2])) + (fConst246 * fRec34[2])) + (fConst247 * fRec35[2])) + (fConst248 * fRec36[2])) + (fConst249 * fRec37[2])) + (fConst250 * fRec38[2])) + (fConst251 * fRec39[2])) + (fConst252 * fRec40[2])) + (fConst253 * fRec41[2])) + (fConst254 * fRec42[2])) + (fConst255 * fRec43[2])) + (fConst256 * fRec44[2]))) - (fConst9 * ((fConst257 * fRec1[2]) + (fConst258 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTemp28 = (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1])));
			float fTemp29 = (fConst9 * fTemp28);
			float fTempFTZ40 = (fTemp29 - (fConst259 * ((fConst260 * fRec0[2]) + (fConst261 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = (fTemp29 - (fConst267 * ((fConst268 * fRec45[2]) + (fConst269 * fRec45[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = (fTemp29 - (fConst275 * ((fConst276 * fRec46[2]) + (fConst277 * fRec46[1]))));
			fRec46[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = (fTemp29 - (fConst283 * ((fConst284 * fRec47[2]) + (fConst285 * fRec47[1]))));
			fRec47[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = (fTemp29 - (fConst291 * ((fConst292 * fRec48[2]) + (fConst293 * fRec48[1]))));
			fRec48[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = (fTemp29 - (fConst300 * ((fConst301 * fRec49[2]) + (fConst302 * fRec49[1]))));
			fRec49[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * ((fConst5 * fRec0[2]) + (((fConst266 * fRec45[2]) + (((0.300000012f * (((fConst274 * fRec46[0]) + (fConst282 * fRec47[0])) + (fConst290 * fRec48[0]))) + (((fConst294 * fRec47[2]) + (((fConst299 * fRec49[2]) + ((fConst303 * fTemp28) + (fConst298 * fRec49[0]))) + (fConst304 * fRec46[2]))) + (fConst305 * fRec48[2]))) + (fConst265 * fRec45[0]))) + (fConst4 * fRec0[0])))));
			fRec4[1] = fRec4[0];
			iVec0[1] = iVec0[0];
			iRec6[1] = iRec6[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec5[j0] = fRec5[(j0 - 1)];
			}
			fVec1[1] = fVec1[0];
			fRec8[1] = fRec8[0];
			iVec2[1] = iVec2[0];
			iRec7[1] = iRec7[0];
			IOTA = (IOTA + 1);
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec10[1] = fRec10[0];
			for (int j1 = 4; (j1 > 0); j1 = (j1 - 1)) {
				fRec11[j1] = fRec11[(j1 - 1)];
			}
			fRec13[1] = fRec13[0];
			iVec4[1] = iVec4[0];
			iRec12[1] = iRec12[0];
			fRec9[1] = fRec9[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec16[1] = fRec16[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
		}
	}

};

#endif
