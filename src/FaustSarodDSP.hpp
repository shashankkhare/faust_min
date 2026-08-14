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
	
	int iVec2[2];
	int iRec6[2];
	
  public:
	
	int getNumInputsFaustSarodDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSarodDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSarodDSPSIG0(int sample_rate) {
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec6[l5] = 0;
		}
	}
	
	void fillFaustSarodDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec2[0] = 1;
			iRec6[0] = ((iVec2[1] + iRec6[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec6[0])));
			iVec2[1] = iVec2[0];
			iRec6[1] = iRec6[0];
		}
	}

};

static FaustSarodDSPSIG0* newFaustSarodDSPSIG0() { return (FaustSarodDSPSIG0*)new FaustSarodDSPSIG0(); }
static void deleteFaustSarodDSPSIG0(FaustSarodDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustSarodDSPSIG0[65536];
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
	FAUSTFLOAT fButton0;
	float fVec0[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int iVec1[2];
	float fRec5[2];
	float fRec4[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst15;
	FAUSTFLOAT fHslider5;
	float fRec7[2];
	float fConst16;
	FAUSTFLOAT fHslider6;
	float fConst17;
	float fRec8[2];
	float fVec3[2];
	FAUSTFLOAT fHslider7;
	int iConst18;
	float fConst19;
	int iRec10[2];
	float fRec9[2];
	float fConst28;
	float fConst35;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	float fRec11[2];
	float fConst37;
	int iRec13[2];
	float fConst38;
	float fConst44;
	float fConst45;
	float fConst46;
	float fConst47;
	float fRec12[5];
	int iConst48;
	int iRec14[2];
	float fConst49;
	float fConst50;
	int IOTA;
	float fVec4[8192];
	float fRec3[2048];
	float fConst51;
	float fConst52;
	float fRec15[2];
	float fRec16[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	float fConst60;
	float fConst67;
	float fConst69;
	float fConst70;
	float fConst75;
	float fConst76;
	float fConst77;
	float fConst78;
	float fRec19[5];
	int iRec20[2];
	float fVec5[2];
	float fVec6[2048];
	float fRec18[2048];
	float fRec17[2];
	float fRec21[2];
	float fVec7[2];
	float fVec8[2048];
	float fRec23[2048];
	float fRec22[2];
	float fRec24[2];
	FAUSTFLOAT fHslider12;
	float fVec9[2];
	float fVec10[2048];
	float fRec26[2048];
	float fRec25[2];
	float fRec27[2];
	float fVec11[2];
	float fVec12[2048];
	float fRec28[2048];
	float fRec29[2];
	float fRec30[2];
	float fConst80;
	FAUSTFLOAT fHslider13;
	float fRec33[2];
	float fConst81;
	float fConst82;
	float fRec34[3];
	float fVec13[2];
	float fVec14[8192];
	float fRec32[2048];
	float fRec31[2];
	float fRec35[2];
	float fVec15[2];
	float fVec16[8192];
	float fRec37[2048];
	float fRec36[2];
	float fRec38[2];
	float fVec17[2];
	float fVec18[8192];
	float fRec39[2048];
	float fRec40[2];
	float fRec41[2];
	float fConst83;
	float fConst84;
	float fConst85;
	float fRec2[3];
	float fConst89;
	float fConst90;
	float fConst91;
	float fConst92;
	float fConst93;
	float fRec42[3];
	float fConst95;
	float fConst96;
	float fConst97;
	float fConst98;
	float fConst99;
	float fRec43[3];
	float fConst103;
	float fConst104;
	float fConst105;
	float fConst106;
	float fConst107;
	float fRec44[3];
	float fConst112;
	float fConst113;
	float fConst114;
	float fConst115;
	float fRec45[3];
	float fConst120;
	float fConst121;
	float fConst122;
	float fConst123;
	float fRec46[3];
	float fConst128;
	float fConst129;
	float fConst130;
	float fConst131;
	float fRec47[3];
	float fConst136;
	float fConst137;
	float fConst138;
	float fConst139;
	float fRec48[3];
	float fConst144;
	float fConst145;
	float fConst146;
	float fConst147;
	float fRec49[3];
	float fConst152;
	float fConst153;
	float fConst154;
	float fConst155;
	float fRec50[3];
	float fConst160;
	float fConst161;
	float fConst162;
	float fConst163;
	float fRec51[3];
	float fConst168;
	float fConst169;
	float fConst170;
	float fConst171;
	float fRec52[3];
	float fConst176;
	float fConst177;
	float fConst178;
	float fConst179;
	float fRec53[3];
	float fConst184;
	float fConst185;
	float fConst186;
	float fConst187;
	float fRec54[3];
	float fConst188;
	float fConst193;
	float fConst194;
	float fConst195;
	float fConst196;
	float fRec55[3];
	float fConst201;
	float fConst202;
	float fConst203;
	float fConst204;
	float fRec56[3];
	float fConst209;
	float fConst210;
	float fConst211;
	float fConst212;
	float fRec57[3];
	float fConst213;
	float fConst214;
	float fConst215;
	float fConst216;
	float fConst220;
	float fConst221;
	float fConst222;
	float fConst223;
	float fRec58[3];
	float fConst228;
	float fConst229;
	float fConst230;
	float fConst231;
	float fRec59[3];
	float fConst236;
	float fConst237;
	float fConst238;
	float fConst239;
	float fRec60[3];
	float fConst244;
	float fConst245;
	float fConst246;
	float fConst247;
	float fRec61[3];
	float fConst252;
	float fConst253;
	float fConst254;
	float fConst255;
	float fRec62[3];
	float fConst260;
	float fConst261;
	float fConst262;
	float fConst263;
	float fRec63[3];
	float fConst268;
	float fConst269;
	float fConst270;
	float fConst271;
	float fRec64[3];
	float fConst276;
	float fConst277;
	float fConst278;
	float fConst279;
	float fRec65[3];
	float fConst280;
	float fConst281;
	float fConst282;
	float fConst283;
	float fConst284;
	float fConst285;
	float fConst286;
	float fConst287;
	float fConst288;
	float fConst289;
	float fConst290;
	float fConst291;
	float fConst292;
	float fConst293;
	float fConst294;
	float fConst295;
	float fConst296;
	float fConst297;
	float fRec1[3];
	float fConst298;
	float fConst299;
	float fRec0[3];
	float fConst301;
	float fConst302;
	float fConst303;
	float fConst304;
	float fRec66[3];
	float fConst308;
	float fConst309;
	float fConst310;
	float fConst311;
	float fConst312;
	float fRec67[3];
	float fConst317;
	float fConst318;
	float fConst319;
	float fConst320;
	float fRec68[3];
	float fConst325;
	float fConst326;
	float fConst327;
	float fConst328;
	float fRec69[3];
	float fConst329;
	float fConst333;
	float fConst334;
	float fConst335;
	float fConst336;
	float fConst337;
	float fRec70[3];
	float fConst341;
	float fConst342;
	float fConst343;
	float fConst344;
	float fConst345;
	float fRec71[3];
	float fConst346;
	float fConst347;
	
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
		m->declare("fm.lib/copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
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
		FaustSarodDSPSIG0* sig0 = newFaustSarodDSPSIG0();
		sig0->instanceInitFaustSarodDSPSIG0(sample_rate);
		sig0->fillFaustSarodDSPSIG0(65536, ftbl0FaustSarodDSPSIG0);
		deleteFaustSarodDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((5654.8667f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.333333343f) / fConst1) + 1.0f);
		fConst4 = (0.449999988f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		float fConst6 = std::tan((43982.2969f / fConst0));
		float fConst7 = (1.0f / fConst6);
		float fConst8 = (((fConst7 + 1.41421354f) / fConst6) + 1.0f);
		fConst9 = (1.0f / fConst8);
		float fConst10 = std::tan((10995.5742f / fConst0));
		float fConst11 = (1.0f / fConst10);
		float fConst12 = (((fConst11 + 0.400000006f) / fConst10) + 1.0f);
		fConst13 = (0.550000012f / (fConst10 * fConst12));
		fConst14 = (0.0f - fConst13);
		fConst15 = (1.0f / fConst0);
		fConst16 = (44.0999985f / fConst0);
		fConst17 = (1.0f - fConst16);
		iConst18 = int((0.00200000009f * fConst0));
		fConst19 = (1.0f / std::max<float>(1.0f, float(iConst18)));
		float fConst20 = FaustSarodDSP_faustpower2_f(fConst15);
		float fConst21 = std::tan((3141.59277f / fConst0));
		float fConst22 = (fConst0 * fConst21);
		float fConst23 = FaustSarodDSP_faustpower2_f(fConst0);
		float fConst24 = std::sqrt((4.0f * ((fConst23 * fConst21) * std::tan((251.327408f / fConst0)))));
		float fConst25 = FaustSarodDSP_faustpower2_f(fConst24);
		float fConst26 = ((2.0f * fConst22) - (0.5f * (fConst25 / fConst22)));
		float fConst27 = FaustSarodDSP_faustpower2_f(fConst26);
		fConst28 = (4.0f * fConst27);
		float fConst29 = (fConst28 + (8.0f * fConst25));
		float fConst30 = (fConst15 * fConst25);
		float fConst31 = (2.82842708f * fConst26);
		float fConst32 = (fConst26 / fConst0);
		float fConst33 = (11.3137083f * fConst32);
		float fConst34 = (((fConst20 * (fConst29 + (fConst30 * (fConst31 + fConst30)))) + fConst33) + 16.0f);
		fConst35 = (fConst20 / fConst34);
		float fConst36 = (8.0f * fConst27);
		fConst37 = (0.0f - fConst36);
		fConst38 = (1.0f / fConst34);
		float fConst39 = FaustSarodDSP_faustpower3_f(fConst15);
		float fConst40 = (fConst39 * fConst25);
		float fConst41 = (5.65685415f * fConst26);
		float fConst42 = (4.0f * fConst30);
		float fConst43 = (22.6274166f * fConst32);
		fConst44 = ((fConst40 * (fConst41 + fConst42)) + (-64.0f - fConst43));
		fConst45 = ((fConst20 * ((0.0f - (fConst36 + (16.0f * fConst25))) + (6.0f * (fConst20 * FaustSarodDSP_faustpower4_f(fConst24))))) + 96.0f);
		fConst46 = ((fConst43 + (fConst40 * (fConst42 - fConst41))) + -64.0f);
		fConst47 = ((fConst20 * (fConst29 + (fConst30 * (fConst30 - fConst31)))) + (16.0f - fConst33));
		iConst48 = int((0.0120000001f * fConst0));
		fConst49 = (1.0f / float(std::max<int>(1, int((0.00999999978f * fConst0)))));
		fConst50 = (1.0f / float(std::max<int>(1, iConst18)));
		fConst51 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst52 = (1.0f - fConst51);
		float fConst53 = std::tan((37699.1133f / fConst0));
		float fConst54 = (fConst0 * fConst53);
		float fConst55 = std::tan((471.238892f / fConst0));
		float fConst56 = std::sqrt((4.0f * ((fConst23 * fConst53) * fConst55)));
		float fConst57 = FaustSarodDSP_faustpower2_f(fConst56);
		float fConst58 = ((2.0f * fConst54) - (0.5f * (fConst57 / fConst54)));
		float fConst59 = FaustSarodDSP_faustpower2_f(fConst58);
		fConst60 = (4.0f * fConst59);
		float fConst61 = (fConst60 + (8.0f * fConst57));
		float fConst62 = (fConst15 * fConst57);
		float fConst63 = (2.82842708f * fConst58);
		float fConst64 = (fConst58 / fConst0);
		float fConst65 = (11.3137083f * fConst64);
		float fConst66 = (((fConst20 * (fConst61 + (fConst62 * (fConst63 + fConst62)))) + fConst65) + 16.0f);
		fConst67 = (0.0500000007f * (fConst20 / fConst66));
		float fConst68 = (8.0f * fConst59);
		fConst69 = (0.0f - fConst68);
		fConst70 = (1.0f / fConst66);
		float fConst71 = (fConst39 * fConst57);
		float fConst72 = (5.65685415f * fConst58);
		float fConst73 = (4.0f * fConst62);
		float fConst74 = (22.6274166f * fConst64);
		fConst75 = ((fConst71 * (fConst72 + fConst73)) + (-64.0f - fConst74));
		fConst76 = ((fConst20 * ((0.0f - (fConst68 + (16.0f * fConst57))) + (6.0f * (fConst20 * FaustSarodDSP_faustpower4_f(fConst56))))) + 96.0f);
		fConst77 = ((fConst74 + (fConst71 * (fConst73 - fConst72))) + -64.0f);
		fConst78 = ((fConst20 * (fConst61 + (fConst62 * (fConst62 - fConst63)))) + (16.0f - fConst65));
		float fConst79 = (1.0f / fConst53);
		fConst80 = (1.0f / (((fConst79 + 1.41421354f) / fConst53) + 1.0f));
		fConst81 = (((fConst79 + -1.41421354f) / fConst53) + 1.0f);
		fConst82 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst53))));
		fConst83 = (1.0f / fConst12);
		fConst84 = (((fConst11 + -0.400000006f) / fConst10) + 1.0f);
		fConst85 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst10))));
		float fConst86 = std::tan((8168.14111f / fConst0));
		float fConst87 = (1.0f / fConst86);
		float fConst88 = (((fConst87 + 0.400000006f) / fConst86) + 1.0f);
		fConst89 = (0.600000024f / (fConst86 * fConst88));
		fConst90 = (0.0f - fConst89);
		fConst91 = (1.0f / fConst88);
		fConst92 = (((fConst87 + -0.400000006f) / fConst86) + 1.0f);
		fConst93 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst86))));
		float fConst94 = (((fConst2 + 0.400000006f) / fConst1) + 1.0f);
		fConst95 = (0.649999976f / (fConst1 * fConst94));
		fConst96 = (0.0f - fConst95);
		fConst97 = (1.0f / fConst94);
		fConst98 = (((fConst2 + -0.400000006f) / fConst1) + 1.0f);
		fConst99 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst100 = std::tan((3769.91113f / fConst0));
		float fConst101 = (1.0f / fConst100);
		float fConst102 = (((fConst101 + 0.400000006f) / fConst100) + 1.0f);
		fConst103 = (0.400000006f / (fConst100 * fConst102));
		fConst104 = (0.0f - fConst103);
		fConst105 = (1.0f / fConst102);
		fConst106 = (((fConst101 + -0.400000006f) / fConst100) + 1.0f);
		fConst107 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst100))));
		float fConst108 = std::tan((1328.89368f / fConst0));
		float fConst109 = (1.0f / fConst108);
		float fConst110 = (((fConst109 + 0.666666687f) / fConst108) + 1.0f);
		float fConst111 = (fConst108 * fConst110);
		fConst112 = (1.0f / fConst111);
		fConst113 = (1.0f / fConst110);
		fConst114 = (((fConst109 + -0.666666687f) / fConst108) + 1.0f);
		fConst115 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst108))));
		float fConst116 = std::tan((1378.21667f / fConst0));
		float fConst117 = (1.0f / fConst116);
		float fConst118 = (((fConst117 + 0.666666687f) / fConst116) + 1.0f);
		float fConst119 = (fConst116 * fConst118);
		fConst120 = (1.0f / fConst119);
		fConst121 = (1.0f / fConst118);
		fConst122 = (((fConst117 + -0.666666687f) / fConst116) + 1.0f);
		fConst123 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst116))));
		float fConst124 = std::tan((1461.78308f / fConst0));
		float fConst125 = (1.0f / fConst124);
		float fConst126 = (((fConst125 + 0.666666687f) / fConst124) + 1.0f);
		float fConst127 = (fConst124 * fConst126);
		fConst128 = (1.0f / fConst127);
		fConst129 = (1.0f / fConst126);
		fConst130 = (((fConst125 + -0.666666687f) / fConst124) + 1.0f);
		fConst131 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst124))));
		float fConst132 = std::tan((1499.79639f / fConst0));
		float fConst133 = (1.0f / fConst132);
		float fConst134 = (((fConst133 + 0.666666687f) / fConst132) + 1.0f);
		float fConst135 = (fConst132 * fConst134);
		fConst136 = (1.0f / fConst135);
		fConst137 = (1.0f / fConst134);
		fConst138 = (((fConst133 + -0.666666687f) / fConst132) + 1.0f);
		fConst139 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst132))));
		float fConst140 = std::tan((1565.76978f / fConst0));
		float fConst141 = (1.0f / fConst140);
		float fConst142 = (((fConst141 + 0.666666687f) / fConst140) + 1.0f);
		float fConst143 = (fConst140 * fConst142);
		fConst144 = (1.0f / fConst143);
		fConst145 = (1.0f / fConst142);
		fConst146 = (((fConst141 + -0.666666687f) / fConst140) + 1.0f);
		fConst147 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst140))));
		float fConst148 = std::tan((1642.73877f / fConst0));
		float fConst149 = (1.0f / fConst148);
		float fConst150 = (((fConst149 + 0.666666687f) / fConst148) + 1.0f);
		float fConst151 = (fConst148 * fConst150);
		fConst152 = (1.0f / fConst151);
		fConst153 = (1.0f / fConst150);
		fConst154 = (((fConst149 + -0.666666687f) / fConst148) + 1.0f);
		fConst155 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst148))));
		float fConst156 = std::tan((1683.57947f / fConst0));
		float fConst157 = (1.0f / fConst156);
		float fConst158 = (((fConst157 + 0.666666687f) / fConst156) + 1.0f);
		float fConst159 = (fConst156 * fConst158);
		fConst160 = (1.0f / fConst159);
		fConst161 = (1.0f / fConst158);
		fConst162 = (((fConst157 + -0.666666687f) / fConst156) + 1.0f);
		fConst163 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst156))));
		float fConst164 = std::tan((1709.65466f / fConst0));
		float fConst165 = (1.0f / fConst164);
		float fConst166 = (((fConst165 + 0.666666687f) / fConst164) + 1.0f);
		float fConst167 = (fConst164 * fConst166);
		fConst168 = (1.0f / fConst167);
		fConst169 = (1.0f / fConst166);
		fConst170 = (((fConst165 + -0.666666687f) / fConst164) + 1.0f);
		fConst171 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst164))));
		float fConst172 = std::tan((1905.69006f / fConst0));
		float fConst173 = (1.0f / fConst172);
		float fConst174 = (((fConst173 + 0.5f) / fConst172) + 1.0f);
		float fConst175 = (fConst172 * fConst174);
		fConst176 = (1.0f / fConst175);
		fConst177 = (1.0f / fConst174);
		fConst178 = (((fConst173 + -0.5f) / fConst172) + 1.0f);
		fConst179 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst172))));
		float fConst180 = std::tan((2670.35376f / fConst0));
		float fConst181 = (1.0f / fConst180);
		float fConst182 = (((fConst181 + 0.666666687f) / fConst180) + 1.0f);
		float fConst183 = (fConst180 * fConst182);
		fConst184 = (1.0f / fConst183);
		fConst185 = (1.0f / fConst182);
		fConst186 = (((fConst181 + -0.666666687f) / fConst180) + 1.0f);
		fConst187 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst180))));
		fConst188 = (0.0f - (0.150000006f / fConst183));
		float fConst189 = std::tan((1739.18567f / fConst0));
		float fConst190 = (1.0f / fConst189);
		float fConst191 = (((fConst190 + 0.666666687f) / fConst189) + 1.0f);
		float fConst192 = (fConst189 * fConst191);
		fConst193 = (1.0f / fConst192);
		fConst194 = (1.0f / fConst191);
		fConst195 = (((fConst190 + -0.666666687f) / fConst189) + 1.0f);
		fConst196 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst189))));
		float fConst197 = std::tan((1801.07507f / fConst0));
		float fConst198 = (1.0f / fConst197);
		float fConst199 = (((fConst198 + 0.666666687f) / fConst197) + 1.0f);
		float fConst200 = (fConst197 * fConst199);
		fConst201 = (1.0f / fConst200);
		fConst202 = (1.0f / fConst199);
		fConst203 = (((fConst198 + -0.666666687f) / fConst197) + 1.0f);
		fConst204 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst197))));
		float fConst205 = std::tan((1917.31396f / fConst0));
		float fConst206 = (1.0f / fConst205);
		float fConst207 = (((fConst206 + 0.5f) / fConst205) + 1.0f);
		float fConst208 = (fConst205 * fConst207);
		fConst209 = (1.0f / fConst208);
		fConst210 = (1.0f / fConst207);
		fConst211 = (((fConst206 + -0.5f) / fConst205) + 1.0f);
		fConst212 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst205))));
		fConst213 = (0.0f - (0.119999997f / fConst208));
		fConst214 = (0.0f - (0.150000006f / fConst175));
		fConst215 = (0.0f - (0.119999997f / fConst200));
		fConst216 = (0.0f - (0.150000006f / fConst111));
		float fConst217 = (1.0f / fConst55);
		float fConst218 = (((fConst217 + 0.333333343f) / fConst55) + 1.0f);
		float fConst219 = (fConst55 * fConst218);
		fConst220 = (1.0f / fConst219);
		fConst221 = (1.0f / fConst218);
		fConst222 = (((fConst217 + -0.333333343f) / fConst55) + 1.0f);
		fConst223 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst55))));
		float fConst224 = std::tan((743.61499f / fConst0));
		float fConst225 = (1.0f / fConst224);
		float fConst226 = (((fConst225 + 0.333333343f) / fConst224) + 1.0f);
		float fConst227 = (fConst224 * fConst226);
		fConst228 = (1.0f / fConst227);
		fConst229 = (1.0f / fConst226);
		fConst230 = (((fConst225 + -0.333333343f) / fConst224) + 1.0f);
		fConst231 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst224))));
		float fConst232 = std::tan((754.610535f / fConst0));
		float fConst233 = (1.0f / fConst232);
		float fConst234 = (((fConst233 + 0.333333343f) / fConst232) + 1.0f);
		float fConst235 = (fConst232 * fConst234);
		fConst236 = (1.0f / fConst235);
		fConst237 = (1.0f / fConst234);
		fConst238 = (((fConst233 + -0.333333343f) / fConst232) + 1.0f);
		fConst239 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst232))));
		float fConst240 = std::tan((990.858337f / fConst0));
		float fConst241 = (1.0f / fConst240);
		float fConst242 = (((fConst241 + 0.333333343f) / fConst240) + 1.0f);
		float fConst243 = (fConst240 * fConst242);
		fConst244 = (1.0f / fConst243);
		fConst245 = (1.0f / fConst242);
		fConst246 = (((fConst241 + -0.333333343f) / fConst240) + 1.0f);
		fConst247 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst240))));
		float fConst248 = std::tan((1007.50879f / fConst0));
		float fConst249 = (1.0f / fConst248);
		float fConst250 = (((fConst249 + 0.333333343f) / fConst248) + 1.0f);
		float fConst251 = (fConst248 * fConst250);
		fConst252 = (1.0f / fConst251);
		fConst253 = (1.0f / fConst250);
		fConst254 = (((fConst249 + -0.333333343f) / fConst248) + 1.0f);
		fConst255 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst248))));
		float fConst256 = std::tan((1075.36719f / fConst0));
		float fConst257 = (1.0f / fConst256);
		float fConst258 = (((fConst257 + 0.333333343f) / fConst256) + 1.0f);
		float fConst259 = (fConst256 * fConst258);
		fConst260 = (1.0f / fConst259);
		fConst261 = (1.0f / fConst258);
		fConst262 = (((fConst257 + -0.333333343f) / fConst256) + 1.0f);
		fConst263 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst256))));
		float fConst264 = std::tan((1213.91138f / fConst0));
		float fConst265 = (1.0f / fConst264);
		float fConst266 = (((fConst265 + 0.333333343f) / fConst264) + 1.0f);
		float fConst267 = (fConst264 * fConst266);
		fConst268 = (1.0f / fConst267);
		fConst269 = (1.0f / fConst266);
		fConst270 = (((fConst265 + -0.333333343f) / fConst264) + 1.0f);
		fConst271 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst264))));
		float fConst272 = std::tan((1265.11938f / fConst0));
		float fConst273 = (1.0f / fConst272);
		float fConst274 = (((fConst273 + 0.333333343f) / fConst272) + 1.0f);
		float fConst275 = (fConst272 * fConst274);
		fConst276 = (1.0f / fConst275);
		fConst277 = (1.0f / fConst274);
		fConst278 = (((fConst273 + -0.333333343f) / fConst272) + 1.0f);
		fConst279 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst272))));
		fConst280 = (0.0f - (0.25f / fConst275));
		fConst281 = (0.0f - (0.25f / fConst267));
		fConst282 = (0.0f - (0.25f / fConst259));
		fConst283 = (0.0f - (0.25f / fConst251));
		fConst284 = (0.0f - (0.25f / fConst243));
		fConst285 = (0.0f - (0.25f / fConst235));
		fConst286 = (0.0f - (0.25f / fConst219));
		fConst287 = (0.0f - (0.25f / fConst227));
		fConst288 = (0.0f - (0.150000006f / fConst119));
		fConst289 = (0.0f - (0.150000006f / fConst127));
		fConst290 = (0.0f - (0.150000006f / fConst135));
		fConst291 = (0.0f - (0.150000006f / fConst143));
		fConst292 = (0.0f - (0.150000006f / fConst151));
		fConst293 = (0.0f - (0.150000006f / fConst159));
		fConst294 = (0.0f - (0.150000006f / fConst167));
		fConst295 = (0.0f - (0.119999997f / fConst192));
		fConst296 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst297 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst298 = (1.0f / fConst3);
		fConst299 = (((fConst2 + -0.333333343f) / fConst1) + 1.0f);
		float fConst300 = (((fConst101 + 0.333333343f) / fConst100) + 1.0f);
		fConst301 = (0.699999988f / (fConst100 * fConst300));
		fConst302 = (0.0f - fConst301);
		fConst303 = (1.0f / fConst300);
		fConst304 = (((fConst101 + -0.333333343f) / fConst100) + 1.0f);
		float fConst305 = std::tan((3298.67236f / fConst0));
		float fConst306 = (1.0f / fConst305);
		float fConst307 = (((fConst306 + 0.285714298f) / fConst305) + 1.0f);
		fConst308 = (0.850000024f / (fConst305 * fConst307));
		fConst309 = (0.0f - fConst308);
		fConst310 = (1.0f / fConst307);
		fConst311 = (((fConst306 + -0.285714298f) / fConst305) + 1.0f);
		fConst312 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst305))));
		float fConst313 = std::tan((1005.30963f / fConst0));
		float fConst314 = (1.0f / fConst313);
		float fConst315 = (((fConst314 + 0.666666687f) / fConst313) + 1.0f);
		float fConst316 = (fConst313 * fConst315);
		fConst317 = (1.0f / fConst316);
		fConst318 = (1.0f / fConst315);
		fConst319 = (((fConst314 + -0.666666687f) / fConst313) + 1.0f);
		fConst320 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst313))));
		float fConst321 = std::tan((2984.51294f / fConst0));
		float fConst322 = (1.0f / fConst321);
		float fConst323 = (((fConst322 + 0.285714298f) / fConst321) + 1.0f);
		float fConst324 = (fConst321 * fConst323);
		fConst325 = (1.0f / fConst324);
		fConst326 = (1.0f / fConst323);
		fConst327 = (((fConst322 + -0.285714298f) / fConst321) + 1.0f);
		fConst328 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst321))));
		fConst329 = (0.0f - (0.800000012f / fConst324));
		float fConst330 = std::tan((1727.87598f / fConst0));
		float fConst331 = (1.0f / fConst330);
		float fConst332 = (((fConst331 + 0.5f) / fConst330) + 1.0f);
		fConst333 = (0.600000024f / (fConst330 * fConst332));
		fConst334 = (0.0f - fConst333);
		fConst335 = (1.0f / fConst332);
		fConst336 = (((fConst331 + -0.5f) / fConst330) + 1.0f);
		fConst337 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst330))));
		float fConst338 = std::tan((565.486694f / fConst0));
		float fConst339 = (1.0f / fConst338);
		float fConst340 = (((fConst339 + 0.400000006f) / fConst338) + 1.0f);
		fConst341 = (1.60000002f / (fConst338 * fConst340));
		fConst342 = (0.0f - fConst341);
		fConst343 = (1.0f / fConst340);
		fConst344 = (((fConst339 + -0.400000006f) / fConst338) + 1.0f);
		fConst345 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst338))));
		fConst346 = (0.25f / fConst8);
		fConst347 = (0.0f - (0.800000012f / fConst316));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(146.83000000000001f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.01f);
		fHslider5 = FAUSTFLOAT(6.5f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(0.25f);
		fHslider8 = FAUSTFLOAT(0.5f);
		fHslider9 = FAUSTFLOAT(3.0f);
		fHslider10 = FAUSTFLOAT(0.20000000000000001f);
		fHslider11 = FAUSTFLOAT(166.5f);
		fHslider12 = FAUSTFLOAT(130.0f);
		fHslider13 = FAUSTFLOAT(0.050000000000000003f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec5[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec10[l9] = 0;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec13[l12] = 0;
		}
		for (int l13 = 0; (l13 < 5); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iRec14[l14] = 0;
		}
		IOTA = 0;
		for (int l15 = 0; (l15 < 8192); l15 = (l15 + 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2048); l16 = (l16 + 1)) {
			fRec3[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 5); l19 = (l19 + 1)) {
			fRec19[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			iRec20[l20] = 0;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fVec5[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2048); l22 = (l22 + 1)) {
			fVec6[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2048); l23 = (l23 + 1)) {
			fRec18[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec17[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec21[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fVec7[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2048); l27 = (l27 + 1)) {
			fVec8[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2048); l28 = (l28 + 1)) {
			fRec23[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec22[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec24[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fVec9[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2048); l32 = (l32 + 1)) {
			fVec10[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2048); l33 = (l33 + 1)) {
			fRec26[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec25[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec27[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fVec11[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2048); l37 = (l37 + 1)) {
			fVec12[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2048); l38 = (l38 + 1)) {
			fRec28[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec29[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec30[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec33[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec34[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fVec13[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 8192); l44 = (l44 + 1)) {
			fVec14[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2048); l45 = (l45 + 1)) {
			fRec32[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec31[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec35[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fVec15[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 8192); l49 = (l49 + 1)) {
			fVec16[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2048); l50 = (l50 + 1)) {
			fRec37[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec36[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec38[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fVec17[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 8192); l54 = (l54 + 1)) {
			fVec18[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2048); l55 = (l55 + 1)) {
			fRec39[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec40[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec41[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec2[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec42[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec43[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec44[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec45[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec46[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec47[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 3); l65 = (l65 + 1)) {
			fRec48[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 3); l66 = (l66 + 1)) {
			fRec49[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 3); l67 = (l67 + 1)) {
			fRec50[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec51[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 3); l69 = (l69 + 1)) {
			fRec52[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 3); l70 = (l70 + 1)) {
			fRec53[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) {
			fRec54[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) {
			fRec55[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec56[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec57[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec58[l75] = 0.0f;
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec59[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 3); l77 = (l77 + 1)) {
			fRec60[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 3); l78 = (l78 + 1)) {
			fRec61[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec62[l79] = 0.0f;
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec63[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 3); l81 = (l81 + 1)) {
			fRec64[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec65[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec1[l83] = 0.0f;
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec0[l84] = 0.0f;
		}
		for (int l85 = 0; (l85 < 3); l85 = (l85 + 1)) {
			fRec66[l85] = 0.0f;
		}
		for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) {
			fRec67[l86] = 0.0f;
		}
		for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) {
			fRec68[l87] = 0.0f;
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec69[l88] = 0.0f;
		}
		for (int l89 = 0; (l89 < 3); l89 = (l89 + 1)) {
			fRec70[l89] = 0.0f;
		}
		for (int l90 = 0; (l90 < 3); l90 = (l90 + 1)) {
			fRec71[l90] = 0.0f;
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
		ui_interface->addHorizontalSlider("calibration", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-100.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_freq1", &fHslider12, FAUSTFLOAT(130.0f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_freq2", &fHslider11, FAUSTFLOAT(166.5f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_gain", &fHslider10, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("exc_gain", &fHslider9, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(90.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jawari", &fHslider7, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider13, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "style", "check");
		ui_interface->addHorizontalSlider("vibrato", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider4, FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider5, FAUSTFLOAT(6.5f), FAUSTFLOAT(1.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (12.8643017f * float(fHslider0));
		float fSlow1 = float(fButton0);
		float fSlow2 = float(fHslider1);
		int iSlow3 = (float(fHslider2) > 0.5f);
		float fSlow4 = float((1 - iSlow3));
		float fSlow5 = (fSlow2 * fSlow4);
		float fSlow6 = float(iSlow3);
		float fSlow7 = ((fSlow1 * float(fHslider3)) * float(fHslider4));
		float fSlow8 = (fConst15 * float(fHslider5));
		float fSlow9 = (fConst16 * float(fHslider6));
		float fSlow10 = float(fHslider7);
		float fSlow11 = (20.0f * fSlow10);
		float fSlow12 = (0.349999994f * fSlow10);
		float fSlow13 = float(fHslider8);
		float fSlow14 = (fConst35 * ((fSlow13 * float(fHslider9)) * fSlow4));
		float fSlow15 = (fConst16 * std::max<float>(fSlow1, float(iSlow3)));
		float fSlow16 = (1350.0f * fSlow10);
		float fSlow17 = (0.25f * float(fHslider10));
		float fSlow18 = float(fHslider11);
		float fSlow19 = (fSlow18 + 1.0f);
		float fSlow20 = std::max<float>(40.0f, fSlow19);
		float fSlow21 = (675.0f * (fSlow10 / fSlow20));
		float fSlow22 = (fConst67 * fSlow13);
		float fSlow23 = std::max<float>(0.400000006f, (1.5f * (1.0f - (0.174999997f * fSlow10))));
		float fSlow24 = std::pow(0.00100000005f, (1.0f / (fSlow20 * fSlow23)));
		float fSlow25 = (fConst0 / fSlow20);
		int iSlow26 = int(fSlow25);
		float fSlow27 = float(iSlow26);
		float fSlow28 = (fSlow25 + (4.99999987e-06f - fSlow27));
		float fSlow29 = (fSlow27 + std::floor(fSlow28));
		float fSlow30 = (fSlow25 - fSlow29);
		float fSlow31 = (fSlow25 + (-1.0f - fSlow29));
		float fSlow32 = (fSlow25 + (-2.0f - fSlow29));
		float fSlow33 = (((0.0f - fSlow30) * (0.0f - (0.5f * fSlow31))) * (0.0f - (0.333333343f * fSlow32)));
		int iSlow34 = int(fSlow28);
		int iSlow35 = (std::min<int>(1024, std::max<int>(0, iSlow34)) + 1);
		float fSlow36 = (fSlow25 + (1.0f - fSlow29));
		float fSlow37 = ((0.0f - fSlow31) * (0.0f - (0.5f * fSlow32)));
		int iSlow38 = (std::min<int>(1024, std::max<int>(0, (iSlow34 + 1))) + 1);
		float fSlow39 = (0.5f * (fSlow30 * (0.0f - fSlow32)));
		int iSlow40 = (std::min<int>(1024, std::max<int>(0, (iSlow34 + 2))) + 1);
		float fSlow41 = (0.166666672f * (fSlow30 * fSlow31));
		int iSlow42 = (std::min<int>(1024, std::max<int>(0, (iSlow34 + 3))) + 1);
		float fSlow43 = (0.5f * fSlow10);
		float fSlow44 = ((10.0f * fSlow10) + 1.0f);
		float fSlow45 = (1.0f / fSlow44);
		int iSlow46 = std::min<int>(16384, std::max<int>(0, (iSlow26 + -1)));
		float fSlow47 = (fConst15 * fSlow19);
		float fSlow48 = (fSlow18 + -1.0f);
		float fSlow49 = std::max<float>(40.0f, fSlow48);
		float fSlow50 = (675.0f * (fSlow10 / fSlow49));
		float fSlow51 = std::pow(0.00100000005f, (1.0f / (fSlow23 * fSlow49)));
		float fSlow52 = (fConst0 / fSlow49);
		int iSlow53 = int(fSlow52);
		float fSlow54 = float(iSlow53);
		float fSlow55 = (fSlow52 + (4.99999987e-06f - fSlow54));
		float fSlow56 = (fSlow54 + std::floor(fSlow55));
		float fSlow57 = (fSlow52 - fSlow56);
		float fSlow58 = (fSlow52 + (-1.0f - fSlow56));
		float fSlow59 = (fSlow52 + (-2.0f - fSlow56));
		float fSlow60 = (((0.0f - fSlow57) * (0.0f - (0.5f * fSlow58))) * (0.0f - (0.333333343f * fSlow59)));
		int iSlow61 = int(fSlow55);
		int iSlow62 = (std::min<int>(1024, std::max<int>(0, iSlow61)) + 1);
		float fSlow63 = (fSlow52 + (1.0f - fSlow56));
		float fSlow64 = ((0.0f - fSlow58) * (0.0f - (0.5f * fSlow59)));
		int iSlow65 = (std::min<int>(1024, std::max<int>(0, (iSlow61 + 1))) + 1);
		float fSlow66 = (0.5f * (fSlow57 * (0.0f - fSlow59)));
		int iSlow67 = (std::min<int>(1024, std::max<int>(0, (iSlow61 + 2))) + 1);
		float fSlow68 = (0.166666672f * (fSlow57 * fSlow58));
		int iSlow69 = (std::min<int>(1024, std::max<int>(0, (iSlow61 + 3))) + 1);
		int iSlow70 = std::min<int>(16384, std::max<int>(0, (iSlow53 + -1)));
		float fSlow71 = (fConst15 * fSlow48);
		float fSlow72 = float(fHslider12);
		float fSlow73 = (fSlow72 + 1.0f);
		float fSlow74 = std::max<float>(40.0f, fSlow73);
		float fSlow75 = (675.0f * (fSlow10 / fSlow74));
		float fSlow76 = std::pow(0.00100000005f, (1.0f / (fSlow23 * fSlow74)));
		float fSlow77 = (fConst0 / fSlow74);
		int iSlow78 = int(fSlow77);
		float fSlow79 = float(iSlow78);
		float fSlow80 = (fSlow77 + (4.99999987e-06f - fSlow79));
		float fSlow81 = (fSlow79 + std::floor(fSlow80));
		float fSlow82 = (fSlow77 - fSlow81);
		float fSlow83 = (fSlow77 + (-1.0f - fSlow81));
		float fSlow84 = (fSlow77 + (-2.0f - fSlow81));
		float fSlow85 = (((0.0f - fSlow82) * (0.0f - (0.5f * fSlow83))) * (0.0f - (0.333333343f * fSlow84)));
		int iSlow86 = int(fSlow80);
		int iSlow87 = (std::min<int>(1024, std::max<int>(0, iSlow86)) + 1);
		float fSlow88 = (fSlow77 + (1.0f - fSlow81));
		float fSlow89 = ((0.0f - fSlow83) * (0.0f - (0.5f * fSlow84)));
		int iSlow90 = (std::min<int>(1024, std::max<int>(0, (iSlow86 + 1))) + 1);
		float fSlow91 = (0.5f * (fSlow82 * (0.0f - fSlow84)));
		int iSlow92 = (std::min<int>(1024, std::max<int>(0, (iSlow86 + 2))) + 1);
		float fSlow93 = (0.166666672f * (fSlow82 * fSlow83));
		int iSlow94 = (std::min<int>(1024, std::max<int>(0, (iSlow86 + 3))) + 1);
		int iSlow95 = std::min<int>(16384, std::max<int>(0, (iSlow78 + -1)));
		float fSlow96 = (fConst15 * fSlow73);
		float fSlow97 = (fSlow72 + -1.0f);
		float fSlow98 = std::max<float>(40.0f, fSlow97);
		float fSlow99 = std::pow(0.00100000005f, (1.0f / (fSlow23 * fSlow98)));
		float fSlow100 = (fConst0 / fSlow98);
		int iSlow101 = int(fSlow100);
		float fSlow102 = float(iSlow101);
		float fSlow103 = (fSlow100 + (4.99999987e-06f - fSlow102));
		float fSlow104 = (fSlow102 + std::floor(fSlow103));
		float fSlow105 = (fSlow100 - fSlow104);
		float fSlow106 = (fSlow100 + (-1.0f - fSlow104));
		float fSlow107 = (fSlow100 + (-2.0f - fSlow104));
		float fSlow108 = (((0.0f - fSlow105) * (0.0f - (0.5f * fSlow106))) * (0.0f - (0.333333343f * fSlow107)));
		int iSlow109 = int(fSlow103);
		int iSlow110 = (std::min<int>(1024, std::max<int>(0, iSlow109)) + 1);
		float fSlow111 = (fSlow100 + (1.0f - fSlow104));
		float fSlow112 = ((0.0f - fSlow106) * (0.0f - (0.5f * fSlow107)));
		int iSlow113 = (std::min<int>(1024, std::max<int>(0, (iSlow109 + 1))) + 1);
		float fSlow114 = (0.5f * (fSlow105 * (0.0f - fSlow107)));
		int iSlow115 = (std::min<int>(1024, std::max<int>(0, (iSlow109 + 2))) + 1);
		float fSlow116 = (0.166666672f * (fSlow105 * fSlow106));
		int iSlow117 = (std::min<int>(1024, std::max<int>(0, (iSlow109 + 3))) + 1);
		int iSlow118 = std::min<int>(16384, std::max<int>(0, (iSlow101 + -1)));
		float fSlow119 = (675.0f * (fSlow10 / fSlow98));
		float fSlow120 = (fConst15 * fSlow97);
		float fSlow121 = (fConst80 * float(fHslider13));
		float fSlow122 = (fConst16 * fSlow1);
		float fSlow123 = (0.5f * fSlow1);
		float fSlow124 = std::max<float>((2.0f * fSlow2), 40.0f);
		float fSlow125 = (fConst15 * fSlow124);
		float fSlow126 = std::max<float>((1.5f * fSlow2), 40.0f);
		float fSlow127 = (fConst15 * fSlow126);
		float fSlow128 = std::max<float>(fSlow2, 40.0f);
		float fSlow129 = (fConst15 * fSlow128);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow1;
			int iTemp0 = (fSlow1 > fVec0[1]);
			int iTemp1 = iTemp0;
			iVec1[0] = iSlow3;
			float fTempFTZ0 = (fSlow5 + (fSlow6 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fThen0 = ((0.00100000005f * fRec5[0]) + (0.999000013f * fRec4[1]));
			float fTempFTZ1 = (iTemp1 ? fRec5[0] : fThen0);
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow8 + (fRec7[1] - std::floor((fSlow8 + fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow9 + (fConst17 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp2 = std::pow(2.0f, (0.000833333354f * fRec8[0]));
			float fTemp3 = ((fRec4[0] * ((fSlow7 * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec7[0]))]) + 1.0f)) * fTemp2);
			float fTemp4 = std::max<float>(40.0f, fTemp3);
			float fTemp5 = (fConst0 / fTemp4);
			int iTemp6 = int(fTemp5);
			float fTemp7 = float(iTemp6);
			float fTemp8 = (fTemp5 + (4.99999987e-06f - fTemp7));
			int iTemp9 = int(fTemp8);
			float fTemp10 = (fTemp7 + std::floor(fTemp8));
			float fTemp11 = (fTemp5 - fTemp10);
			float fTemp12 = (fTemp5 + (-1.0f - fTemp10));
			float fTemp13 = (fTemp5 + (-2.0f - fTemp10));
			float fTemp14 = ((((fRec3[((IOTA - (std::min<int>(1024, int(std::max<int>(0, int(iTemp9)))) + 1)) & 2047)] * (0.0f - fTemp11)) * (0.0f - (0.5f * fTemp12))) * (0.0f - (0.333333343f * fTemp13))) + ((fTemp5 + (1.0f - fTemp10)) * ((((fRec3[((IOTA - (std::min<int>(1024, int(std::max<int>(0, int((iTemp9 + 1))))) + 1)) & 2047)] * (0.0f - fTemp12)) * (0.0f - (0.5f * fTemp13))) + (0.5f * ((fTemp11 * fRec3[((IOTA - (std::min<int>(1024, int(std::max<int>(0, int((iTemp9 + 2))))) + 1)) & 2047)]) * (0.0f - fTemp13)))) + (0.166666672f * ((fTemp11 * fTemp12) * fRec3[((IOTA - (std::min<int>(1024, int(std::max<int>(0, int((iTemp9 + 3))))) + 1)) & 2047)])))));
			fVec3[0] = fTemp14;
			float fTemp15 = ((0.00200000009f * fTemp14) + (0.998000026f * fVec3[1]));
			int iThen1 = std::min<int>((iRec10[1] + 1), iConst18);
			iRec10[0] = (iTemp1 ? 0 : iThen1);
			float fTempFTZ4 = ((fConst17 * fRec9[1]) + (fConst16 * std::min<float>(1.0f, (fConst19 * float(iRec10[0])))));
			fRec9[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp16 = ((0.899999976f * fRec9[0]) + 0.100000001f);
			float fTemp17 = ((fSlow11 * fTemp16) + 1.0f);
			float fThen2 = (fTemp15 - (fSlow10 * (fTemp16 * (fTemp15 - (float(tanhf(float((fTemp15 * fTemp17)))) / fTemp17)))));
			float fTempFTZ5 = (fSlow15 + (fConst17 * fRec11[1]));
			fRec11[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			iRec13[0] = ((1103515245 * iRec13[1]) + 12345);
			float fTemp18 = (4.65661287e-10f * float(iRec13[0]));
			float fTempFTZ6 = (fTemp18 - (fConst38 * ((((fConst44 * fRec12[1]) + (fConst45 * fRec12[2])) + (fConst46 * fRec12[3])) + (fConst47 * fRec12[4]))));
			fRec12[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			int iThen3 = std::min<int>((iRec14[1] + 1), iConst48);
			iRec14[0] = (iTemp1 ? 0 : iThen3);
			float fThen4 = std::max<float>(0.0f, (fConst49 * float((iConst48 - iRec14[0]))));
			float fElse4 = (fConst50 * float(iRec14[0]));
			fVec4[(IOTA & 8191)] = ((((fTemp15 > 0.0f) ? fTemp15 : fThen2) * std::pow(0.00100000005f, (1.0f / (fTemp4 * std::max<float>(0.400000006f, ((2.0f - (0.850000024f * std::max<float>(0.0f, std::min<float>(1.0f, (0.00138888892f * (fRec4[0] + -80.0f)))))) * (1.0f - (fSlow12 * fTemp16)))))))) + (fSlow14 * ((fRec11[0] * (((fConst37 * fRec12[2]) + (fConst28 * fRec12[0])) + (fConst28 * fRec12[4]))) * ((iRec14[0] <= iConst18) ? fElse4 : fThen4))));
			float fTempFTZ7 = fVec4[((IOTA - std::min<int>(16384, int(std::max<int>(0, int((iTemp6 + -1)))))) & 8191)];
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp19 = std::fabs(fRec3[((IOTA - 0) & 2047)]);
			float fTempFTZ8 = std::max<float>(fTemp19, ((fConst51 * fRec15[1]) + (fConst52 * fTemp19)));
			fRec15[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp20 = (fRec16[1] + (fConst15 * fTemp3));
			float fTempFTZ9 = (fTemp20 - std::floor(fTemp20));
			fRec16[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp21 = std::max<float>(1.0f, ((fSlow16 * (((fRec15[0] * fTemp16) * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec16[0]))]) / fTemp4)) + 4.0f));
			float fTemp22 = (fTemp21 + 4.99999987e-06f);
			int iTemp23 = int(fTemp22);
			float fTemp24 = std::floor(fTemp22);
			float fTempFTZ10 = (fTemp18 - (fConst70 * ((((fConst75 * fRec19[1]) + (fConst76 * fRec19[2])) + (fConst77 * fRec19[3])) + (fConst78 * fRec19[4]))));
			fRec19[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			int iTemp25 = ((iSlow3 > iVec1[1]) | (iTemp0 & iSlow3));
			int iThen5 = std::min<int>((iRec20[1] + 1), iConst48);
			iRec20[0] = (iTemp25 ? 0 : iThen5);
			float fThen6 = std::max<float>(0.0f, (fConst49 * float((iConst48 - iRec20[0]))));
			float fElse6 = (fConst50 * float(iRec20[0]));
			float fTemp26 = (fSlow22 * (((((fConst69 * fRec19[2]) + (fConst60 * fRec19[0])) + (fConst60 * fRec19[4])) * ((iRec20[0] <= iConst18) ? fElse6 : fThen6)) * float(iTemp25)));
			float fTemp27 = ((fSlow33 * fRec18[((IOTA - iSlow35) & 2047)]) + (fSlow36 * (((fSlow37 * fRec18[((IOTA - iSlow38) & 2047)]) + (fSlow39 * fRec18[((IOTA - iSlow40) & 2047)])) + (fSlow41 * fRec18[((IOTA - iSlow42) & 2047)]))));
			fVec5[0] = fTemp27;
			float fTemp28 = ((0.00200000009f * fTemp27) + (0.998000026f * fVec5[1]));
			float fThen7 = (fTemp28 - (fSlow43 * (fTemp28 - (fSlow45 * float(tanhf(float((fSlow44 * fTemp28))))))));
			fVec6[(IOTA & 2047)] = (fTemp26 + (fSlow24 * ((fTemp28 > 0.0f) ? fTemp28 : fThen7)));
			float fTempFTZ11 = fVec6[((IOTA - iSlow46) & 2047)];
			fRec18[(IOTA & 2047)] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp29 = std::fabs(fRec18[((IOTA - 0) & 2047)]);
			float fTempFTZ12 = std::max<float>(fTemp29, ((fConst51 * fRec17[1]) + (fConst52 * fTemp29)));
			fRec17[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fSlow47 + (fRec21[1] - std::floor((fSlow47 + fRec21[1]))));
			fRec21[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp30 = std::max<float>(1.0f, ((fSlow21 * (fRec17[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec21[0]))])) + 4.0f));
			float fTemp31 = (fTemp30 + 4.99999987e-06f);
			float fTemp32 = std::floor(fTemp31);
			int iTemp33 = int(fTemp31);
			float fTemp34 = ((fSlow60 * fRec23[((IOTA - iSlow62) & 2047)]) + (fSlow63 * (((fSlow64 * fRec23[((IOTA - iSlow65) & 2047)]) + (fSlow66 * fRec23[((IOTA - iSlow67) & 2047)])) + (fSlow68 * fRec23[((IOTA - iSlow69) & 2047)]))));
			fVec7[0] = fTemp34;
			float fTemp35 = ((0.00200000009f * fTemp34) + (0.998000026f * fVec7[1]));
			float fThen8 = (fTemp35 - (fSlow43 * (fTemp35 - (fSlow45 * float(tanhf(float((fSlow44 * fTemp35))))))));
			fVec8[(IOTA & 2047)] = (fTemp26 + (fSlow51 * ((fTemp35 > 0.0f) ? fTemp35 : fThen8)));
			float fTempFTZ14 = fVec8[((IOTA - iSlow70) & 2047)];
			fRec23[(IOTA & 2047)] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp36 = std::fabs(fRec23[((IOTA - 0) & 2047)]);
			float fTempFTZ15 = std::max<float>(fTemp36, ((fConst51 * fRec22[1]) + (fConst52 * fTemp36)));
			fRec22[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fSlow71 + (fRec24[1] - std::floor((fSlow71 + fRec24[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp37 = std::max<float>(1.0f, ((fSlow50 * (fRec22[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec24[0]))])) + 4.0f));
			float fTemp38 = (fTemp37 + 4.99999987e-06f);
			float fTemp39 = std::floor(fTemp38);
			int iTemp40 = int(fTemp38);
			float fTemp41 = ((fSlow85 * fRec26[((IOTA - iSlow87) & 2047)]) + (fSlow88 * (((fSlow89 * fRec26[((IOTA - iSlow90) & 2047)]) + (fSlow91 * fRec26[((IOTA - iSlow92) & 2047)])) + (fSlow93 * fRec26[((IOTA - iSlow94) & 2047)]))));
			fVec9[0] = fTemp41;
			float fTemp42 = ((0.00200000009f * fTemp41) + (0.998000026f * fVec9[1]));
			float fThen9 = (fTemp42 - (fSlow43 * (fTemp42 - (fSlow45 * float(tanhf(float((fSlow44 * fTemp42))))))));
			fVec10[(IOTA & 2047)] = (fTemp26 + (fSlow76 * ((fTemp42 > 0.0f) ? fTemp42 : fThen9)));
			float fTempFTZ17 = fVec10[((IOTA - iSlow95) & 2047)];
			fRec26[(IOTA & 2047)] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp43 = std::fabs(fRec26[((IOTA - 0) & 2047)]);
			float fTempFTZ18 = std::max<float>(fTemp43, ((fConst51 * fRec25[1]) + (fConst52 * fTemp43)));
			fRec25[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fSlow96 + (fRec27[1] - std::floor((fSlow96 + fRec27[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp44 = std::max<float>(1.0f, ((fSlow75 * (fRec25[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec27[0]))])) + 4.0f));
			float fTemp45 = (fTemp44 + 4.99999987e-06f);
			float fTemp46 = std::floor(fTemp45);
			int iTemp47 = int(fTemp45);
			float fTemp48 = ((fSlow108 * fRec28[((IOTA - iSlow110) & 2047)]) + (fSlow111 * (((fSlow112 * fRec28[((IOTA - iSlow113) & 2047)]) + (fSlow114 * fRec28[((IOTA - iSlow115) & 2047)])) + (fSlow116 * fRec28[((IOTA - iSlow117) & 2047)]))));
			fVec11[0] = fTemp48;
			float fTemp49 = ((0.00200000009f * fTemp48) + (0.998000026f * fVec11[1]));
			float fThen10 = (fTemp49 - (fSlow43 * (fTemp49 - (fSlow45 * float(tanhf(float((fSlow44 * fTemp49))))))));
			fVec12[(IOTA & 2047)] = ((fSlow99 * ((fTemp49 > 0.0f) ? fTemp49 : fThen10)) + fTemp26);
			float fTempFTZ20 = fVec12[((IOTA - iSlow118) & 2047)];
			fRec28[(IOTA & 2047)] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp50 = std::fabs(fRec28[((IOTA - 0) & 2047)]);
			float fTempFTZ21 = std::max<float>(fTemp50, ((fConst51 * fRec29[1]) + (fConst52 * fTemp50)));
			fRec29[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fSlow120 + (fRec30[1] - std::floor((fSlow120 + fRec30[1]))));
			fRec30[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTemp51 = std::max<float>(1.0f, ((fSlow119 * (fRec29[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec30[0]))])) + 4.0f));
			float fTemp52 = (fTemp51 + 4.99999987e-06f);
			int iTemp53 = int(fTemp52);
			float fTemp54 = std::floor(fTemp52);
			float fTemp55 = float(tanhf(float((2.0f * (((fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp23))))) & 2047)] * (0.0f - (fTemp21 + (-1.0f - fTemp24)))) + ((fTemp21 - fTemp24) * fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp23 + 1)))))) & 2047)])) + (fSlow17 * (((fTemp30 - fTemp32) * fRec18[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp33 + 1)))))) & 2047)]) + ((((fTemp37 - fTemp39) * fRec23[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp40 + 1)))))) & 2047)]) + ((((fTemp44 - fTemp46) * fRec26[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp47 + 1)))))) & 2047)]) + (((fRec28[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp53))))) & 2047)] * (0.0f - (fTemp51 + (-1.0f - fTemp54)))) + ((fTemp51 - fTemp54) * fRec28[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp53 + 1)))))) & 2047)])) + (fRec26[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp47))))) & 2047)] * (0.0f - (fTemp44 + (-1.0f - fTemp46)))))) + (fRec23[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp40))))) & 2047)] * (0.0f - (fTemp37 + (-1.0f - fTemp39)))))) + (fRec18[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp33))))) & 2047)] * (0.0f - (fTemp30 + (-1.0f - fTemp32))))))))))));
			float fTempFTZ23 = (fSlow122 + (fConst17 * fRec33[1]));
			fRec33[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = ((fSlow123 * fTemp55) - (fConst80 * ((fConst81 * fRec34[2]) + (fConst82 * fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTemp56 = (fSlow121 * (fRec33[0] * (fRec34[2] + (fRec34[0] + (2.0f * fRec34[1])))));
			float fTemp57 = std::max<float>(40.0f, (fSlow124 * fTemp2));
			float fTemp58 = (fConst0 / fTemp57);
			int iTemp59 = int(fTemp58);
			float fTemp60 = float(iTemp59);
			float fTemp61 = (fTemp58 + (4.99999987e-06f - fTemp60));
			int iTemp62 = int(fTemp61);
			float fTemp63 = (fTemp60 + std::floor(fTemp61));
			float fTemp64 = (fTemp58 - fTemp63);
			float fTemp65 = (fTemp58 + (-1.0f - fTemp63));
			float fTemp66 = (fTemp58 + (-2.0f - fTemp63));
			float fTemp67 = ((((fRec32[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp62)) + 1)) & 2047)] * (0.0f - fTemp64)) * (0.0f - (0.5f * fTemp65))) * (0.0f - (0.333333343f * fTemp66))) + ((fTemp58 + (1.0f - fTemp63)) * ((((fRec32[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp62 + 1))) + 1)) & 2047)] * (0.0f - fTemp65)) * (0.0f - (0.5f * fTemp66))) + (0.5f * ((fTemp64 * fRec32[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp62 + 2))) + 1)) & 2047)]) * (0.0f - fTemp66)))) + (0.166666672f * ((fTemp64 * fTemp65) * fRec32[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp62 + 3))) + 1)) & 2047)])))));
			fVec13[0] = fTemp67;
			float fTemp68 = ((0.00200000009f * fTemp67) + (0.998000026f * fVec13[1]));
			float fThen11 = (fTemp68 - (0.0500000007f * (fTemp68 - (0.5f * float(tanhf(float((2.0f * fTemp68))))))));
			fVec14[(IOTA & 8191)] = (fTemp56 + (((fTemp68 > 0.0f) ? fTemp68 : fThen11) * std::pow(0.00100000005f, (0.254452914f / fTemp57))));
			float fTempFTZ25 = fVec14[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp59 + -1)))) & 8191)];
			fRec32[(IOTA & 2047)] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTemp69 = std::fabs(fRec32[((IOTA - 0) & 2047)]);
			float fTempFTZ26 = std::max<float>(fTemp69, ((fConst51 * fRec31[1]) + (fConst52 * fTemp69)));
			fRec31[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTemp70 = (fRec35[1] + (fSlow125 * fTemp2));
			float fTempFTZ27 = (fTemp70 - std::floor(fTemp70));
			fRec35[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTemp71 = std::max<float>(1.0f, ((67.5f * ((fRec31[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec35[0]))]) / fTemp57)) + 4.0f));
			float fTemp72 = (fTemp71 + 4.99999987e-06f);
			float fTemp73 = std::floor(fTemp72);
			int iTemp74 = int(fTemp72);
			float fTemp75 = std::max<float>(40.0f, (fSlow126 * fTemp2));
			float fTemp76 = (fConst0 / fTemp75);
			int iTemp77 = int(fTemp76);
			float fTemp78 = float(iTemp77);
			float fTemp79 = (fTemp76 + (4.99999987e-06f - fTemp78));
			int iTemp80 = int(fTemp79);
			float fTemp81 = (fTemp78 + std::floor(fTemp79));
			float fTemp82 = (fTemp76 - fTemp81);
			float fTemp83 = (fTemp76 + (-1.0f - fTemp81));
			float fTemp84 = (fTemp76 + (-2.0f - fTemp81));
			float fTemp85 = ((((fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp80)) + 1)) & 2047)] * (0.0f - fTemp82)) * (0.0f - (0.5f * fTemp83))) * (0.0f - (0.333333343f * fTemp84))) + ((fTemp76 + (1.0f - fTemp81)) * ((((fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp80 + 1))) + 1)) & 2047)] * (0.0f - fTemp83)) * (0.0f - (0.5f * fTemp84))) + (0.5f * ((fTemp82 * fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp80 + 2))) + 1)) & 2047)]) * (0.0f - fTemp84)))) + (0.166666672f * ((fTemp82 * fTemp83) * fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp80 + 3))) + 1)) & 2047)])))));
			fVec15[0] = fTemp85;
			float fTemp86 = ((0.00200000009f * fTemp85) + (0.998000026f * fVec15[1]));
			float fThen12 = (fTemp86 - (0.0500000007f * (fTemp86 - (0.5f * float(tanhf(float((2.0f * fTemp86))))))));
			fVec16[(IOTA & 8191)] = (fTemp56 + (((fTemp86 > 0.0f) ? fTemp86 : fThen12) * std::pow(0.00100000005f, (0.254452914f / fTemp75))));
			float fTempFTZ28 = fVec16[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp77 + -1)))) & 8191)];
			fRec37[(IOTA & 2047)] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTemp87 = std::fabs(fRec37[((IOTA - 0) & 2047)]);
			float fTempFTZ29 = std::max<float>(fTemp87, ((fConst51 * fRec36[1]) + (fConst52 * fTemp87)));
			fRec36[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp88 = (fRec38[1] + (fSlow127 * fTemp2));
			float fTempFTZ30 = (fTemp88 - std::floor(fTemp88));
			fRec38[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTemp89 = std::max<float>(1.0f, ((67.5f * ((fRec36[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec38[0]))]) / fTemp75)) + 4.0f));
			float fTemp90 = (fTemp89 + 4.99999987e-06f);
			float fTemp91 = std::floor(fTemp90);
			int iTemp92 = int(fTemp90);
			float fTemp93 = std::max<float>(40.0f, (fSlow128 * fTemp2));
			float fTemp94 = (fConst0 / fTemp93);
			int iTemp95 = int(fTemp94);
			float fTemp96 = float(iTemp95);
			float fTemp97 = (fTemp94 + (4.99999987e-06f - fTemp96));
			int iTemp98 = int(fTemp97);
			float fTemp99 = (fTemp96 + std::floor(fTemp97));
			float fTemp100 = (fTemp94 - fTemp99);
			float fTemp101 = (fTemp94 + (-1.0f - fTemp99));
			float fTemp102 = (fTemp94 + (-2.0f - fTemp99));
			float fTemp103 = ((((fRec39[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp98)) + 1)) & 2047)] * (0.0f - fTemp100)) * (0.0f - (0.5f * fTemp101))) * (0.0f - (0.333333343f * fTemp102))) + ((fTemp94 + (1.0f - fTemp99)) * ((((fRec39[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp98 + 1))) + 1)) & 2047)] * (0.0f - fTemp101)) * (0.0f - (0.5f * fTemp102))) + (0.5f * ((fTemp100 * fRec39[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp98 + 2))) + 1)) & 2047)]) * (0.0f - fTemp102)))) + (0.166666672f * ((fTemp100 * fTemp101) * fRec39[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp98 + 3))) + 1)) & 2047)])))));
			fVec17[0] = fTemp103;
			float fTemp104 = ((0.00200000009f * fTemp103) + (0.998000026f * fVec17[1]));
			float fThen13 = (fTemp104 - (0.0500000007f * (fTemp104 - (0.5f * float(tanhf(float((2.0f * fTemp104))))))));
			fVec18[(IOTA & 8191)] = ((((fTemp104 > 0.0f) ? fTemp104 : fThen13) * std::pow(0.00100000005f, (0.254452914f / fTemp93))) + fTemp56);
			float fTempFTZ31 = fVec18[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp95 + -1)))) & 8191)];
			fRec39[(IOTA & 2047)] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTemp105 = std::fabs(fRec39[((IOTA - 0) & 2047)]);
			float fTempFTZ32 = std::max<float>(fTemp105, ((fConst51 * fRec40[1]) + (fConst52 * fTemp105)));
			fRec40[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTemp106 = (fRec41[1] + (fSlow129 * fTemp2));
			float fTempFTZ33 = (fTemp106 - std::floor(fTemp106));
			fRec41[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTemp107 = std::max<float>(1.0f, ((67.5f * ((fRec40[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec41[0]))]) / fTemp93)) + 4.0f));
			float fTemp108 = (fTemp107 + 4.99999987e-06f);
			int iTemp109 = int(fTemp108);
			float fTemp110 = std::floor(fTemp108);
			float fTemp111 = ((0.5f * fTemp55) + (0.150000006f * (((fTemp71 - fTemp73) * fRec32[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp74 + 1)))))) & 2047)]) + ((((fTemp89 - fTemp91) * fRec37[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp92 + 1)))))) & 2047)]) + (((fRec39[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp109))))) & 2047)] * (0.0f - (fTemp107 + (-1.0f - fTemp110)))) + ((fTemp107 - fTemp110) * fRec39[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp109 + 1)))))) & 2047)])) + (fRec37[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp92))))) & 2047)] * (0.0f - (fTemp89 + (-1.0f - fTemp91)))))) + (fRec32[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp74))))) & 2047)] * (0.0f - (fTemp71 + (-1.0f - fTemp73))))))));
			float fTempFTZ34 = (fTemp111 - (fConst83 * ((fConst84 * fRec2[2]) + (fConst85 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fTemp111 - (fConst91 * ((fConst92 * fRec42[2]) + (fConst93 * fRec42[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fTemp111 - (fConst97 * ((fConst98 * fRec43[2]) + (fConst99 * fRec43[1]))));
			fRec43[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp111 - (fConst105 * ((fConst106 * fRec44[2]) + (fConst107 * fRec44[1]))));
			fRec44[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fTemp111 - (fConst113 * ((fConst114 * fRec45[2]) + (fConst115 * fRec45[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fTemp111 - (fConst121 * ((fConst122 * fRec46[2]) + (fConst123 * fRec46[1]))));
			fRec46[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fTemp111 - (fConst129 * ((fConst130 * fRec47[2]) + (fConst131 * fRec47[1]))));
			fRec47[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = (fTemp111 - (fConst137 * ((fConst138 * fRec48[2]) + (fConst139 * fRec48[1]))));
			fRec48[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = (fTemp111 - (fConst145 * ((fConst146 * fRec49[2]) + (fConst147 * fRec49[1]))));
			fRec49[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = (fTemp111 - (fConst153 * ((fConst154 * fRec50[2]) + (fConst155 * fRec50[1]))));
			fRec50[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = (fTemp111 - (fConst161 * ((fConst162 * fRec51[2]) + (fConst163 * fRec51[1]))));
			fRec51[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = (fTemp111 - (fConst169 * ((fConst170 * fRec52[2]) + (fConst171 * fRec52[1]))));
			fRec52[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = (fTemp111 - (fConst177 * ((fConst178 * fRec53[2]) + (fConst179 * fRec53[1]))));
			fRec53[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = (fTemp111 - (fConst185 * ((fConst186 * fRec54[2]) + (fConst187 * fRec54[1]))));
			fRec54[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = (fTemp111 - (fConst194 * ((fConst195 * fRec55[2]) + (fConst196 * fRec55[1]))));
			fRec55[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = (fTemp111 - (fConst202 * ((fConst203 * fRec56[2]) + (fConst204 * fRec56[1]))));
			fRec56[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = (fTemp111 - (fConst210 * ((fConst211 * fRec57[2]) + (fConst212 * fRec57[1]))));
			fRec57[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTempFTZ51 = (fTemp111 - (fConst221 * ((fConst222 * fRec58[2]) + (fConst223 * fRec58[1]))));
			fRec58[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = (fTemp111 - (fConst229 * ((fConst230 * fRec59[2]) + (fConst231 * fRec59[1]))));
			fRec59[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = (fTemp111 - (fConst237 * ((fConst238 * fRec60[2]) + (fConst239 * fRec60[1]))));
			fRec60[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTempFTZ54 = (fTemp111 - (fConst245 * ((fConst246 * fRec61[2]) + (fConst247 * fRec61[1]))));
			fRec61[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fTempFTZ55 = (fTemp111 - (fConst253 * ((fConst254 * fRec62[2]) + (fConst255 * fRec62[1]))));
			fRec62[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fTempFTZ56 = (fTemp111 - (fConst261 * ((fConst262 * fRec63[2]) + (fConst263 * fRec63[1]))));
			fRec63[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fTempFTZ57 = (fTemp111 - (fConst269 * ((fConst270 * fRec64[2]) + (fConst271 * fRec64[1]))));
			fRec64[0] = ((std::fabs(fTempFTZ57) > 1.17549435e-38f) ? fTempFTZ57 : 0.0f);
			float fTempFTZ58 = (fTemp111 - (fConst277 * ((fConst278 * fRec65[2]) + (fConst279 * fRec65[1]))));
			fRec65[0] = ((std::fabs(fTempFTZ58) > 1.17549435e-38f) ? fTempFTZ58 : 0.0f);
			float fTempFTZ59 = (((fConst14 * fRec2[2]) + (((fConst90 * fRec42[2]) + (((fConst96 * fRec43[2]) + (((fConst104 * fRec44[2]) + (((0.150000006f * ((((((((((fTemp111 + (fConst112 * fRec45[0])) + (fConst120 * fRec46[0])) + (fConst128 * fRec47[0])) + (fConst136 * fRec48[0])) + (fConst144 * fRec49[0])) + (fConst152 * fRec50[0])) + (fConst160 * fRec51[0])) + (fConst168 * fRec52[0])) + (fConst176 * fRec53[0])) + (fConst184 * fRec54[0]))) + ((fConst188 * fRec54[2]) + ((0.119999997f * (((fConst193 * fRec55[0]) + (fConst201 * fRec56[0])) + (fConst209 * fRec57[0]))) + ((fConst213 * fRec57[2]) + ((fConst214 * fRec53[2]) + ((fConst215 * fRec56[2]) + ((((((((((fConst216 * fRec45[2]) + ((0.25f * ((((((((fConst220 * fRec58[0]) + (fConst228 * fRec59[0])) + (fConst236 * fRec60[0])) + (fConst244 * fRec61[0])) + (fConst252 * fRec62[0])) + (fConst260 * fRec63[0])) + (fConst268 * fRec64[0])) + (fConst276 * fRec65[0]))) + ((fConst280 * fRec65[2]) + ((fConst281 * fRec64[2]) + ((fConst282 * fRec63[2]) + ((fConst283 * fRec62[2]) + ((fConst284 * fRec61[2]) + ((fConst285 * fRec60[2]) + ((fConst286 * fRec58[2]) + (fConst287 * fRec59[2])))))))))) + (fConst288 * fRec46[2])) + (fConst289 * fRec47[2])) + (fConst290 * fRec48[2])) + (fConst291 * fRec49[2])) + (fConst292 * fRec50[2])) + (fConst293 * fRec51[2])) + (fConst294 * fRec52[2])) + (fConst295 * fRec55[2])))))))) + (fConst103 * fRec44[0]))) + (fConst95 * fRec43[0]))) + (fConst89 * fRec42[0]))) + (fConst13 * fRec2[0]))) - (fConst9 * ((fConst296 * fRec1[2]) + (fConst297 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ59) > 1.17549435e-38f) ? fTempFTZ59 : 0.0f);
			float fTemp112 = (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1])));
			float fTemp113 = (fConst9 * fTemp112);
			float fTempFTZ60 = (fTemp113 - (fConst298 * ((fConst299 * fRec0[2]) + (fConst99 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ60) > 1.17549435e-38f) ? fTempFTZ60 : 0.0f);
			float fTempFTZ61 = (fTemp113 - (fConst303 * ((fConst304 * fRec66[2]) + (fConst107 * fRec66[1]))));
			fRec66[0] = ((std::fabs(fTempFTZ61) > 1.17549435e-38f) ? fTempFTZ61 : 0.0f);
			float fTempFTZ62 = (fTemp113 - (fConst310 * ((fConst311 * fRec67[2]) + (fConst312 * fRec67[1]))));
			fRec67[0] = ((std::fabs(fTempFTZ62) > 1.17549435e-38f) ? fTempFTZ62 : 0.0f);
			float fTempFTZ63 = (fTemp113 - (fConst318 * ((fConst319 * fRec68[2]) + (fConst320 * fRec68[1]))));
			fRec68[0] = ((std::fabs(fTempFTZ63) > 1.17549435e-38f) ? fTempFTZ63 : 0.0f);
			float fTempFTZ64 = (fTemp113 - (fConst326 * ((fConst327 * fRec69[2]) + (fConst328 * fRec69[1]))));
			fRec69[0] = ((std::fabs(fTempFTZ64) > 1.17549435e-38f) ? fTempFTZ64 : 0.0f);
			float fTempFTZ65 = (fTemp113 - (fConst335 * ((fConst336 * fRec70[2]) + (fConst337 * fRec70[1]))));
			fRec70[0] = ((std::fabs(fTempFTZ65) > 1.17549435e-38f) ? fTempFTZ65 : 0.0f);
			float fTempFTZ66 = (fTemp113 - (fConst343 * ((fConst344 * fRec71[2]) + (fConst345 * fRec71[1]))));
			fRec71[0] = ((std::fabs(fTempFTZ66) > 1.17549435e-38f) ? fTempFTZ66 : 0.0f);
			float fTemp114 = float(tanhf(float((fSlow0 * ((fConst5 * fRec0[2]) + (((fConst302 * fRec66[2]) + (((fConst309 * fRec67[2]) + (((0.800000012f * ((fConst317 * fRec68[0]) + (fConst325 * fRec69[0]))) + ((fConst329 * fRec69[2]) + ((fConst334 * fRec70[2]) + ((fConst333 * fRec70[0]) + (((fConst342 * fRec71[2]) + ((fConst346 * fTemp112) + (fConst341 * fRec71[0]))) + (fConst347 * fRec68[2])))))) + (fConst308 * fRec67[0]))) + (fConst301 * fRec66[0]))) + (fConst4 * fRec0[0])))))));
			output0[i0] = FAUSTFLOAT(fTemp114);
			output1[i0] = FAUSTFLOAT(fTemp114);
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fVec3[1] = fVec3[0];
			iRec10[1] = iRec10[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			iRec13[1] = iRec13[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec12[j0] = fRec12[(j0 - 1)];
			}
			iRec14[1] = iRec14[0];
			IOTA = (IOTA + 1);
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			for (int j1 = 4; (j1 > 0); j1 = (j1 - 1)) {
				fRec19[j1] = fRec19[(j1 - 1)];
			}
			iRec20[1] = iRec20[0];
			fVec5[1] = fVec5[0];
			fRec17[1] = fRec17[0];
			fRec21[1] = fRec21[0];
			fVec7[1] = fVec7[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			fVec9[1] = fVec9[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fVec11[1] = fVec11[0];
			fRec29[1] = fRec29[0];
			fRec30[1] = fRec30[0];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fVec13[1] = fVec13[0];
			fRec31[1] = fRec31[0];
			fRec35[1] = fRec35[0];
			fVec15[1] = fVec15[0];
			fRec36[1] = fRec36[0];
			fRec38[1] = fRec38[0];
			fVec17[1] = fVec17[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec63[2] = fRec63[1];
			fRec63[1] = fRec63[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec67[2] = fRec67[1];
			fRec67[1] = fRec67[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
		}
	}

};

#endif
