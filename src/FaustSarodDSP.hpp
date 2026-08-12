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
	float fConst26;
	float fConst33;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	float fRec9[2];
	float fConst35;
	int iRec11[2];
	float fConst36;
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec10[5];
	int iConst46;
	int iRec12[2];
	int iConst47;
	float fConst48;
	float fConst49;
	int IOTA;
	float fVec4[8192];
	float fRec3[2048];
	float fConst50;
	float fConst51;
	float fRec13[2];
	float fRec14[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	float fConst59;
	float fConst66;
	float fConst68;
	float fConst69;
	float fConst74;
	float fConst75;
	float fConst76;
	float fConst77;
	float fRec17[5];
	int iRec18[2];
	float fVec5[2];
	float fVec6[2048];
	float fRec16[2048];
	float fRec15[2];
	float fRec19[2];
	float fVec7[2];
	float fVec8[2048];
	float fRec21[2048];
	float fRec20[2];
	float fRec22[2];
	FAUSTFLOAT fHslider12;
	float fVec9[2];
	float fVec10[2048];
	float fRec24[2048];
	float fRec23[2];
	float fRec25[2];
	float fVec11[2];
	float fVec12[2048];
	float fRec26[2048];
	float fRec27[2];
	float fRec28[2];
	float fConst79;
	FAUSTFLOAT fHslider13;
	float fRec31[2];
	float fConst80;
	float fConst81;
	float fRec32[3];
	float fVec13[2];
	float fVec14[8192];
	float fRec30[2048];
	float fRec29[2];
	float fRec33[2];
	float fVec15[2];
	float fVec16[8192];
	float fRec35[2048];
	float fRec34[2];
	float fRec36[2];
	float fVec17[2];
	float fVec18[8192];
	float fRec37[2048];
	float fRec38[2];
	float fRec39[2];
	float fConst82;
	float fConst83;
	float fConst84;
	float fRec2[3];
	float fConst88;
	float fConst89;
	float fConst90;
	float fConst91;
	float fConst92;
	float fRec40[3];
	float fConst94;
	float fConst95;
	float fConst96;
	float fConst97;
	float fConst98;
	float fRec41[3];
	float fConst102;
	float fConst103;
	float fConst104;
	float fConst105;
	float fConst106;
	float fRec42[3];
	float fConst111;
	float fConst112;
	float fConst113;
	float fConst114;
	float fRec43[3];
	float fConst119;
	float fConst120;
	float fConst121;
	float fConst122;
	float fRec44[3];
	float fConst127;
	float fConst128;
	float fConst129;
	float fConst130;
	float fRec45[3];
	float fConst135;
	float fConst136;
	float fConst137;
	float fConst138;
	float fRec46[3];
	float fConst143;
	float fConst144;
	float fConst145;
	float fConst146;
	float fRec47[3];
	float fConst151;
	float fConst152;
	float fConst153;
	float fConst154;
	float fRec48[3];
	float fConst159;
	float fConst160;
	float fConst161;
	float fConst162;
	float fRec49[3];
	float fConst167;
	float fConst168;
	float fConst169;
	float fConst170;
	float fRec50[3];
	float fConst175;
	float fConst176;
	float fConst177;
	float fConst178;
	float fRec51[3];
	float fConst183;
	float fConst184;
	float fConst185;
	float fConst186;
	float fRec52[3];
	float fConst187;
	float fConst192;
	float fConst193;
	float fConst194;
	float fConst195;
	float fRec53[3];
	float fConst200;
	float fConst201;
	float fConst202;
	float fConst203;
	float fRec54[3];
	float fConst208;
	float fConst209;
	float fConst210;
	float fConst211;
	float fRec55[3];
	float fConst212;
	float fConst213;
	float fConst214;
	float fConst215;
	float fConst219;
	float fConst220;
	float fConst221;
	float fConst222;
	float fRec56[3];
	float fConst227;
	float fConst228;
	float fConst229;
	float fConst230;
	float fRec57[3];
	float fConst235;
	float fConst236;
	float fConst237;
	float fConst238;
	float fRec58[3];
	float fConst243;
	float fConst244;
	float fConst245;
	float fConst246;
	float fRec59[3];
	float fConst251;
	float fConst252;
	float fConst253;
	float fConst254;
	float fRec60[3];
	float fConst259;
	float fConst260;
	float fConst261;
	float fConst262;
	float fRec61[3];
	float fConst267;
	float fConst268;
	float fConst269;
	float fConst270;
	float fRec62[3];
	float fConst275;
	float fConst276;
	float fConst277;
	float fConst278;
	float fRec63[3];
	float fConst279;
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
	float fRec1[3];
	float fConst297;
	float fConst298;
	float fRec0[3];
	float fConst300;
	float fConst301;
	float fConst302;
	float fConst303;
	float fRec64[3];
	float fConst307;
	float fConst308;
	float fConst309;
	float fConst310;
	float fConst311;
	float fRec65[3];
	float fConst316;
	float fConst317;
	float fConst318;
	float fConst319;
	float fRec66[3];
	float fConst324;
	float fConst325;
	float fConst326;
	float fConst327;
	float fRec67[3];
	float fConst328;
	float fConst332;
	float fConst333;
	float fConst334;
	float fConst335;
	float fConst336;
	float fRec68[3];
	float fConst340;
	float fConst341;
	float fConst342;
	float fConst343;
	float fConst344;
	float fRec69[3];
	float fConst345;
	float fConst346;
	
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
		float fConst18 = FaustSarodDSP_faustpower2_f(fConst15);
		float fConst19 = std::tan((3141.59277f / fConst0));
		float fConst20 = (fConst0 * fConst19);
		float fConst21 = FaustSarodDSP_faustpower2_f(fConst0);
		float fConst22 = std::sqrt((4.0f * ((fConst21 * fConst19) * std::tan((251.327408f / fConst0)))));
		float fConst23 = FaustSarodDSP_faustpower2_f(fConst22);
		float fConst24 = ((2.0f * fConst20) - (0.5f * (fConst23 / fConst20)));
		float fConst25 = FaustSarodDSP_faustpower2_f(fConst24);
		fConst26 = (4.0f * fConst25);
		float fConst27 = (fConst26 + (8.0f * fConst23));
		float fConst28 = (fConst15 * fConst23);
		float fConst29 = (2.82842708f * fConst24);
		float fConst30 = (fConst24 / fConst0);
		float fConst31 = (11.3137083f * fConst30);
		float fConst32 = (((fConst18 * (fConst27 + (fConst28 * (fConst29 + fConst28)))) + fConst31) + 16.0f);
		fConst33 = (fConst18 / fConst32);
		float fConst34 = (8.0f * fConst25);
		fConst35 = (0.0f - fConst34);
		fConst36 = (1.0f / fConst32);
		float fConst37 = FaustSarodDSP_faustpower3_f(fConst15);
		float fConst38 = (fConst37 * fConst23);
		float fConst39 = (5.65685415f * fConst24);
		float fConst40 = (4.0f * fConst28);
		float fConst41 = (22.6274166f * fConst30);
		fConst42 = ((fConst38 * (fConst39 + fConst40)) + (-64.0f - fConst41));
		fConst43 = ((fConst18 * ((0.0f - (fConst34 + (16.0f * fConst23))) + (6.0f * (fConst18 * FaustSarodDSP_faustpower4_f(fConst22))))) + 96.0f);
		fConst44 = ((fConst41 + (fConst38 * (fConst40 - fConst39))) + -64.0f);
		fConst45 = ((fConst18 * (fConst27 + (fConst28 * (fConst28 - fConst29)))) + (16.0f - fConst31));
		iConst46 = int((0.0350000001f * fConst0));
		iConst47 = int((0.0250000004f * fConst0));
		fConst48 = (1.0f / float(std::max<int>(1, int((0.00999999978f * fConst0)))));
		fConst49 = (1.0f / float(std::max<int>(1, iConst47)));
		fConst50 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst51 = (1.0f - fConst50);
		float fConst52 = std::tan((37699.1133f / fConst0));
		float fConst53 = (fConst0 * fConst52);
		float fConst54 = std::tan((471.238892f / fConst0));
		float fConst55 = std::sqrt((4.0f * ((fConst21 * fConst52) * fConst54)));
		float fConst56 = FaustSarodDSP_faustpower2_f(fConst55);
		float fConst57 = ((2.0f * fConst53) - (0.5f * (fConst56 / fConst53)));
		float fConst58 = FaustSarodDSP_faustpower2_f(fConst57);
		fConst59 = (4.0f * fConst58);
		float fConst60 = (fConst59 + (8.0f * fConst56));
		float fConst61 = (fConst15 * fConst56);
		float fConst62 = (2.82842708f * fConst57);
		float fConst63 = (fConst57 / fConst0);
		float fConst64 = (11.3137083f * fConst63);
		float fConst65 = (((fConst18 * (fConst60 + (fConst61 * (fConst62 + fConst61)))) + fConst64) + 16.0f);
		fConst66 = (0.0500000007f * (fConst18 / fConst65));
		float fConst67 = (8.0f * fConst58);
		fConst68 = (0.0f - fConst67);
		fConst69 = (1.0f / fConst65);
		float fConst70 = (fConst37 * fConst56);
		float fConst71 = (5.65685415f * fConst57);
		float fConst72 = (4.0f * fConst61);
		float fConst73 = (22.6274166f * fConst63);
		fConst74 = ((fConst70 * (fConst71 + fConst72)) + (-64.0f - fConst73));
		fConst75 = ((fConst18 * ((0.0f - (fConst67 + (16.0f * fConst56))) + (6.0f * (fConst18 * FaustSarodDSP_faustpower4_f(fConst55))))) + 96.0f);
		fConst76 = ((fConst73 + (fConst70 * (fConst72 - fConst71))) + -64.0f);
		fConst77 = ((fConst18 * (fConst60 + (fConst61 * (fConst61 - fConst62)))) + (16.0f - fConst64));
		float fConst78 = (1.0f / fConst52);
		fConst79 = (1.0f / (((fConst78 + 1.41421354f) / fConst52) + 1.0f));
		fConst80 = (((fConst78 + -1.41421354f) / fConst52) + 1.0f);
		fConst81 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst52))));
		fConst82 = (1.0f / fConst12);
		fConst83 = (((fConst11 + -0.400000006f) / fConst10) + 1.0f);
		fConst84 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst10))));
		float fConst85 = std::tan((8168.14111f / fConst0));
		float fConst86 = (1.0f / fConst85);
		float fConst87 = (((fConst86 + 0.400000006f) / fConst85) + 1.0f);
		fConst88 = (0.600000024f / (fConst85 * fConst87));
		fConst89 = (0.0f - fConst88);
		fConst90 = (1.0f / fConst87);
		fConst91 = (((fConst86 + -0.400000006f) / fConst85) + 1.0f);
		fConst92 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst85))));
		float fConst93 = (((fConst2 + 0.400000006f) / fConst1) + 1.0f);
		fConst94 = (0.649999976f / (fConst1 * fConst93));
		fConst95 = (0.0f - fConst94);
		fConst96 = (1.0f / fConst93);
		fConst97 = (((fConst2 + -0.400000006f) / fConst1) + 1.0f);
		fConst98 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst99 = std::tan((3769.91113f / fConst0));
		float fConst100 = (1.0f / fConst99);
		float fConst101 = (((fConst100 + 0.400000006f) / fConst99) + 1.0f);
		fConst102 = (0.400000006f / (fConst99 * fConst101));
		fConst103 = (0.0f - fConst102);
		fConst104 = (1.0f / fConst101);
		fConst105 = (((fConst100 + -0.400000006f) / fConst99) + 1.0f);
		fConst106 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst99))));
		float fConst107 = std::tan((1328.89368f / fConst0));
		float fConst108 = (1.0f / fConst107);
		float fConst109 = (((fConst108 + 0.666666687f) / fConst107) + 1.0f);
		float fConst110 = (fConst107 * fConst109);
		fConst111 = (1.0f / fConst110);
		fConst112 = (1.0f / fConst109);
		fConst113 = (((fConst108 + -0.666666687f) / fConst107) + 1.0f);
		fConst114 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst107))));
		float fConst115 = std::tan((1378.21667f / fConst0));
		float fConst116 = (1.0f / fConst115);
		float fConst117 = (((fConst116 + 0.666666687f) / fConst115) + 1.0f);
		float fConst118 = (fConst115 * fConst117);
		fConst119 = (1.0f / fConst118);
		fConst120 = (1.0f / fConst117);
		fConst121 = (((fConst116 + -0.666666687f) / fConst115) + 1.0f);
		fConst122 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst115))));
		float fConst123 = std::tan((1461.78308f / fConst0));
		float fConst124 = (1.0f / fConst123);
		float fConst125 = (((fConst124 + 0.666666687f) / fConst123) + 1.0f);
		float fConst126 = (fConst123 * fConst125);
		fConst127 = (1.0f / fConst126);
		fConst128 = (1.0f / fConst125);
		fConst129 = (((fConst124 + -0.666666687f) / fConst123) + 1.0f);
		fConst130 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst123))));
		float fConst131 = std::tan((1499.79639f / fConst0));
		float fConst132 = (1.0f / fConst131);
		float fConst133 = (((fConst132 + 0.666666687f) / fConst131) + 1.0f);
		float fConst134 = (fConst131 * fConst133);
		fConst135 = (1.0f / fConst134);
		fConst136 = (1.0f / fConst133);
		fConst137 = (((fConst132 + -0.666666687f) / fConst131) + 1.0f);
		fConst138 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst131))));
		float fConst139 = std::tan((1565.76978f / fConst0));
		float fConst140 = (1.0f / fConst139);
		float fConst141 = (((fConst140 + 0.666666687f) / fConst139) + 1.0f);
		float fConst142 = (fConst139 * fConst141);
		fConst143 = (1.0f / fConst142);
		fConst144 = (1.0f / fConst141);
		fConst145 = (((fConst140 + -0.666666687f) / fConst139) + 1.0f);
		fConst146 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst139))));
		float fConst147 = std::tan((1642.73877f / fConst0));
		float fConst148 = (1.0f / fConst147);
		float fConst149 = (((fConst148 + 0.666666687f) / fConst147) + 1.0f);
		float fConst150 = (fConst147 * fConst149);
		fConst151 = (1.0f / fConst150);
		fConst152 = (1.0f / fConst149);
		fConst153 = (((fConst148 + -0.666666687f) / fConst147) + 1.0f);
		fConst154 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst147))));
		float fConst155 = std::tan((1683.57947f / fConst0));
		float fConst156 = (1.0f / fConst155);
		float fConst157 = (((fConst156 + 0.666666687f) / fConst155) + 1.0f);
		float fConst158 = (fConst155 * fConst157);
		fConst159 = (1.0f / fConst158);
		fConst160 = (1.0f / fConst157);
		fConst161 = (((fConst156 + -0.666666687f) / fConst155) + 1.0f);
		fConst162 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst155))));
		float fConst163 = std::tan((1709.65466f / fConst0));
		float fConst164 = (1.0f / fConst163);
		float fConst165 = (((fConst164 + 0.666666687f) / fConst163) + 1.0f);
		float fConst166 = (fConst163 * fConst165);
		fConst167 = (1.0f / fConst166);
		fConst168 = (1.0f / fConst165);
		fConst169 = (((fConst164 + -0.666666687f) / fConst163) + 1.0f);
		fConst170 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst163))));
		float fConst171 = std::tan((1905.69006f / fConst0));
		float fConst172 = (1.0f / fConst171);
		float fConst173 = (((fConst172 + 0.5f) / fConst171) + 1.0f);
		float fConst174 = (fConst171 * fConst173);
		fConst175 = (1.0f / fConst174);
		fConst176 = (1.0f / fConst173);
		fConst177 = (((fConst172 + -0.5f) / fConst171) + 1.0f);
		fConst178 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst171))));
		float fConst179 = std::tan((2670.35376f / fConst0));
		float fConst180 = (1.0f / fConst179);
		float fConst181 = (((fConst180 + 0.666666687f) / fConst179) + 1.0f);
		float fConst182 = (fConst179 * fConst181);
		fConst183 = (1.0f / fConst182);
		fConst184 = (1.0f / fConst181);
		fConst185 = (((fConst180 + -0.666666687f) / fConst179) + 1.0f);
		fConst186 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst179))));
		fConst187 = (0.0f - (0.150000006f / fConst182));
		float fConst188 = std::tan((1739.18567f / fConst0));
		float fConst189 = (1.0f / fConst188);
		float fConst190 = (((fConst189 + 0.666666687f) / fConst188) + 1.0f);
		float fConst191 = (fConst188 * fConst190);
		fConst192 = (1.0f / fConst191);
		fConst193 = (1.0f / fConst190);
		fConst194 = (((fConst189 + -0.666666687f) / fConst188) + 1.0f);
		fConst195 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst188))));
		float fConst196 = std::tan((1801.07507f / fConst0));
		float fConst197 = (1.0f / fConst196);
		float fConst198 = (((fConst197 + 0.666666687f) / fConst196) + 1.0f);
		float fConst199 = (fConst196 * fConst198);
		fConst200 = (1.0f / fConst199);
		fConst201 = (1.0f / fConst198);
		fConst202 = (((fConst197 + -0.666666687f) / fConst196) + 1.0f);
		fConst203 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst196))));
		float fConst204 = std::tan((1917.31396f / fConst0));
		float fConst205 = (1.0f / fConst204);
		float fConst206 = (((fConst205 + 0.5f) / fConst204) + 1.0f);
		float fConst207 = (fConst204 * fConst206);
		fConst208 = (1.0f / fConst207);
		fConst209 = (1.0f / fConst206);
		fConst210 = (((fConst205 + -0.5f) / fConst204) + 1.0f);
		fConst211 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst204))));
		fConst212 = (0.0f - (0.119999997f / fConst207));
		fConst213 = (0.0f - (0.150000006f / fConst174));
		fConst214 = (0.0f - (0.119999997f / fConst199));
		fConst215 = (0.0f - (0.150000006f / fConst110));
		float fConst216 = (1.0f / fConst54);
		float fConst217 = (((fConst216 + 0.333333343f) / fConst54) + 1.0f);
		float fConst218 = (fConst54 * fConst217);
		fConst219 = (1.0f / fConst218);
		fConst220 = (1.0f / fConst217);
		fConst221 = (((fConst216 + -0.333333343f) / fConst54) + 1.0f);
		fConst222 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst54))));
		float fConst223 = std::tan((743.61499f / fConst0));
		float fConst224 = (1.0f / fConst223);
		float fConst225 = (((fConst224 + 0.333333343f) / fConst223) + 1.0f);
		float fConst226 = (fConst223 * fConst225);
		fConst227 = (1.0f / fConst226);
		fConst228 = (1.0f / fConst225);
		fConst229 = (((fConst224 + -0.333333343f) / fConst223) + 1.0f);
		fConst230 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst223))));
		float fConst231 = std::tan((754.610535f / fConst0));
		float fConst232 = (1.0f / fConst231);
		float fConst233 = (((fConst232 + 0.333333343f) / fConst231) + 1.0f);
		float fConst234 = (fConst231 * fConst233);
		fConst235 = (1.0f / fConst234);
		fConst236 = (1.0f / fConst233);
		fConst237 = (((fConst232 + -0.333333343f) / fConst231) + 1.0f);
		fConst238 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst231))));
		float fConst239 = std::tan((990.858337f / fConst0));
		float fConst240 = (1.0f / fConst239);
		float fConst241 = (((fConst240 + 0.333333343f) / fConst239) + 1.0f);
		float fConst242 = (fConst239 * fConst241);
		fConst243 = (1.0f / fConst242);
		fConst244 = (1.0f / fConst241);
		fConst245 = (((fConst240 + -0.333333343f) / fConst239) + 1.0f);
		fConst246 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst239))));
		float fConst247 = std::tan((1007.50879f / fConst0));
		float fConst248 = (1.0f / fConst247);
		float fConst249 = (((fConst248 + 0.333333343f) / fConst247) + 1.0f);
		float fConst250 = (fConst247 * fConst249);
		fConst251 = (1.0f / fConst250);
		fConst252 = (1.0f / fConst249);
		fConst253 = (((fConst248 + -0.333333343f) / fConst247) + 1.0f);
		fConst254 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst247))));
		float fConst255 = std::tan((1075.36719f / fConst0));
		float fConst256 = (1.0f / fConst255);
		float fConst257 = (((fConst256 + 0.333333343f) / fConst255) + 1.0f);
		float fConst258 = (fConst255 * fConst257);
		fConst259 = (1.0f / fConst258);
		fConst260 = (1.0f / fConst257);
		fConst261 = (((fConst256 + -0.333333343f) / fConst255) + 1.0f);
		fConst262 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst255))));
		float fConst263 = std::tan((1213.91138f / fConst0));
		float fConst264 = (1.0f / fConst263);
		float fConst265 = (((fConst264 + 0.333333343f) / fConst263) + 1.0f);
		float fConst266 = (fConst263 * fConst265);
		fConst267 = (1.0f / fConst266);
		fConst268 = (1.0f / fConst265);
		fConst269 = (((fConst264 + -0.333333343f) / fConst263) + 1.0f);
		fConst270 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst263))));
		float fConst271 = std::tan((1265.11938f / fConst0));
		float fConst272 = (1.0f / fConst271);
		float fConst273 = (((fConst272 + 0.333333343f) / fConst271) + 1.0f);
		float fConst274 = (fConst271 * fConst273);
		fConst275 = (1.0f / fConst274);
		fConst276 = (1.0f / fConst273);
		fConst277 = (((fConst272 + -0.333333343f) / fConst271) + 1.0f);
		fConst278 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst271))));
		fConst279 = (0.0f - (0.25f / fConst274));
		fConst280 = (0.0f - (0.25f / fConst266));
		fConst281 = (0.0f - (0.25f / fConst258));
		fConst282 = (0.0f - (0.25f / fConst250));
		fConst283 = (0.0f - (0.25f / fConst242));
		fConst284 = (0.0f - (0.25f / fConst234));
		fConst285 = (0.0f - (0.25f / fConst218));
		fConst286 = (0.0f - (0.25f / fConst226));
		fConst287 = (0.0f - (0.150000006f / fConst118));
		fConst288 = (0.0f - (0.150000006f / fConst126));
		fConst289 = (0.0f - (0.150000006f / fConst134));
		fConst290 = (0.0f - (0.150000006f / fConst142));
		fConst291 = (0.0f - (0.150000006f / fConst150));
		fConst292 = (0.0f - (0.150000006f / fConst158));
		fConst293 = (0.0f - (0.150000006f / fConst166));
		fConst294 = (0.0f - (0.119999997f / fConst191));
		fConst295 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst296 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst297 = (1.0f / fConst3);
		fConst298 = (((fConst2 + -0.333333343f) / fConst1) + 1.0f);
		float fConst299 = (((fConst100 + 0.333333343f) / fConst99) + 1.0f);
		fConst300 = (0.699999988f / (fConst99 * fConst299));
		fConst301 = (0.0f - fConst300);
		fConst302 = (1.0f / fConst299);
		fConst303 = (((fConst100 + -0.333333343f) / fConst99) + 1.0f);
		float fConst304 = std::tan((3298.67236f / fConst0));
		float fConst305 = (1.0f / fConst304);
		float fConst306 = (((fConst305 + 0.285714298f) / fConst304) + 1.0f);
		fConst307 = (0.850000024f / (fConst304 * fConst306));
		fConst308 = (0.0f - fConst307);
		fConst309 = (1.0f / fConst306);
		fConst310 = (((fConst305 + -0.285714298f) / fConst304) + 1.0f);
		fConst311 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst304))));
		float fConst312 = std::tan((1005.30963f / fConst0));
		float fConst313 = (1.0f / fConst312);
		float fConst314 = (((fConst313 + 0.666666687f) / fConst312) + 1.0f);
		float fConst315 = (fConst312 * fConst314);
		fConst316 = (1.0f / fConst315);
		fConst317 = (1.0f / fConst314);
		fConst318 = (((fConst313 + -0.666666687f) / fConst312) + 1.0f);
		fConst319 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst312))));
		float fConst320 = std::tan((2984.51294f / fConst0));
		float fConst321 = (1.0f / fConst320);
		float fConst322 = (((fConst321 + 0.285714298f) / fConst320) + 1.0f);
		float fConst323 = (fConst320 * fConst322);
		fConst324 = (1.0f / fConst323);
		fConst325 = (1.0f / fConst322);
		fConst326 = (((fConst321 + -0.285714298f) / fConst320) + 1.0f);
		fConst327 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst320))));
		fConst328 = (0.0f - (0.800000012f / fConst323));
		float fConst329 = std::tan((1727.87598f / fConst0));
		float fConst330 = (1.0f / fConst329);
		float fConst331 = (((fConst330 + 0.5f) / fConst329) + 1.0f);
		fConst332 = (0.600000024f / (fConst329 * fConst331));
		fConst333 = (0.0f - fConst332);
		fConst334 = (1.0f / fConst331);
		fConst335 = (((fConst330 + -0.5f) / fConst329) + 1.0f);
		fConst336 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst329))));
		float fConst337 = std::tan((565.486694f / fConst0));
		float fConst338 = (1.0f / fConst337);
		float fConst339 = (((fConst338 + 0.400000006f) / fConst337) + 1.0f);
		fConst340 = (1.60000002f / (fConst337 * fConst339));
		fConst341 = (0.0f - fConst340);
		fConst342 = (1.0f / fConst339);
		fConst343 = (((fConst338 + -0.400000006f) / fConst337) + 1.0f);
		fConst344 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst337))));
		fConst345 = (0.25f / fConst8);
		fConst346 = (0.0f - (0.800000012f / fConst315));
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
		fHslider9 = FAUSTFLOAT(0.5f);
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
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iRec11[l10] = 0;
		}
		for (int l11 = 0; (l11 < 5); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec12[l12] = 0;
		}
		IOTA = 0;
		for (int l13 = 0; (l13 < 8192); l13 = (l13 + 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2048); l14 = (l14 + 1)) {
			fRec3[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 5); l17 = (l17 + 1)) {
			fRec17[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iRec18[l18] = 0;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fVec5[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2048); l20 = (l20 + 1)) {
			fVec6[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2048); l21 = (l21 + 1)) {
			fRec16[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec15[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec19[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fVec7[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2048); l25 = (l25 + 1)) {
			fVec8[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2048); l26 = (l26 + 1)) {
			fRec21[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec20[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec22[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fVec9[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2048); l30 = (l30 + 1)) {
			fVec10[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2048); l31 = (l31 + 1)) {
			fRec24[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec23[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec25[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fVec11[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2048); l35 = (l35 + 1)) {
			fVec12[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2048); l36 = (l36 + 1)) {
			fRec26[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec27[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec28[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec31[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec32[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fVec13[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 8192); l42 = (l42 + 1)) {
			fVec14[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2048); l43 = (l43 + 1)) {
			fRec30[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec29[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec33[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fVec15[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 8192); l47 = (l47 + 1)) {
			fVec16[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2048); l48 = (l48 + 1)) {
			fRec35[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec34[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec36[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fVec17[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 8192); l52 = (l52 + 1)) {
			fVec18[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2048); l53 = (l53 + 1)) {
			fRec37[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec38[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec39[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec2[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec40[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec41[l58] = 0.0f;
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
			fRec1[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec0[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec64[l83] = 0.0f;
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec65[l84] = 0.0f;
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
		ui_interface->addHorizontalSlider("exc_gain", &fHslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
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
		float fSlow11 = ((20.0f * fSlow10) + 1.0f);
		float fSlow12 = (1.0f / fSlow11);
		float fSlow13 = (1.0f - (0.349999994f * fSlow10));
		float fSlow14 = float(fHslider8);
		float fSlow15 = (fConst33 * ((fSlow14 * float(fHslider9)) * fSlow4));
		float fSlow16 = (fConst16 * std::max<float>(fSlow1, float(iSlow3)));
		float fSlow17 = (1350.0f * fSlow10);
		float fSlow18 = (0.25f * float(fHslider10));
		float fSlow19 = float(fHslider11);
		float fSlow20 = (fSlow19 + 1.0f);
		float fSlow21 = std::max<float>(40.0f, fSlow20);
		float fSlow22 = (675.0f * (fSlow10 / fSlow21));
		float fSlow23 = (fConst66 * fSlow14);
		float fSlow24 = std::max<float>(0.400000006f, (1.5f * (1.0f - (0.174999997f * fSlow10))));
		float fSlow25 = std::pow(0.00100000005f, (1.0f / (fSlow21 * fSlow24)));
		float fSlow26 = (fConst0 / fSlow21);
		int iSlow27 = int(fSlow26);
		float fSlow28 = float(iSlow27);
		float fSlow29 = (fSlow26 + (4.99999987e-06f - fSlow28));
		float fSlow30 = (fSlow28 + std::floor(fSlow29));
		float fSlow31 = (fSlow26 - fSlow30);
		float fSlow32 = (fSlow26 + (-1.0f - fSlow30));
		float fSlow33 = (fSlow26 + (-2.0f - fSlow30));
		float fSlow34 = (((0.0f - fSlow31) * (0.0f - (0.5f * fSlow32))) * (0.0f - (0.333333343f * fSlow33)));
		int iSlow35 = int(fSlow29);
		int iSlow36 = (std::min<int>(1024, std::max<int>(0, iSlow35)) + 1);
		float fSlow37 = (fSlow26 + (1.0f - fSlow30));
		float fSlow38 = ((0.0f - fSlow32) * (0.0f - (0.5f * fSlow33)));
		int iSlow39 = (std::min<int>(1024, std::max<int>(0, (iSlow35 + 1))) + 1);
		float fSlow40 = (0.5f * (fSlow31 * (0.0f - fSlow33)));
		int iSlow41 = (std::min<int>(1024, std::max<int>(0, (iSlow35 + 2))) + 1);
		float fSlow42 = (0.166666672f * (fSlow31 * fSlow32));
		int iSlow43 = (std::min<int>(1024, std::max<int>(0, (iSlow35 + 3))) + 1);
		float fSlow44 = (0.5f * fSlow10);
		float fSlow45 = ((10.0f * fSlow10) + 1.0f);
		float fSlow46 = (1.0f / fSlow45);
		int iSlow47 = std::min<int>(16384, std::max<int>(0, (iSlow27 + -1)));
		float fSlow48 = (fConst15 * fSlow20);
		float fSlow49 = (fSlow19 + -1.0f);
		float fSlow50 = std::max<float>(40.0f, fSlow49);
		float fSlow51 = (675.0f * (fSlow10 / fSlow50));
		float fSlow52 = std::pow(0.00100000005f, (1.0f / (fSlow24 * fSlow50)));
		float fSlow53 = (fConst0 / fSlow50);
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
		float fSlow72 = (fConst15 * fSlow49);
		float fSlow73 = float(fHslider12);
		float fSlow74 = (fSlow73 + 1.0f);
		float fSlow75 = std::max<float>(40.0f, fSlow74);
		float fSlow76 = (675.0f * (fSlow10 / fSlow75));
		float fSlow77 = std::pow(0.00100000005f, (1.0f / (fSlow24 * fSlow75)));
		float fSlow78 = (fConst0 / fSlow75);
		int iSlow79 = int(fSlow78);
		float fSlow80 = float(iSlow79);
		float fSlow81 = (fSlow78 + (4.99999987e-06f - fSlow80));
		float fSlow82 = (fSlow80 + std::floor(fSlow81));
		float fSlow83 = (fSlow78 - fSlow82);
		float fSlow84 = (fSlow78 + (-1.0f - fSlow82));
		float fSlow85 = (fSlow78 + (-2.0f - fSlow82));
		float fSlow86 = (((0.0f - fSlow83) * (0.0f - (0.5f * fSlow84))) * (0.0f - (0.333333343f * fSlow85)));
		int iSlow87 = int(fSlow81);
		int iSlow88 = (std::min<int>(1024, std::max<int>(0, iSlow87)) + 1);
		float fSlow89 = (fSlow78 + (1.0f - fSlow82));
		float fSlow90 = ((0.0f - fSlow84) * (0.0f - (0.5f * fSlow85)));
		int iSlow91 = (std::min<int>(1024, std::max<int>(0, (iSlow87 + 1))) + 1);
		float fSlow92 = (0.5f * (fSlow83 * (0.0f - fSlow85)));
		int iSlow93 = (std::min<int>(1024, std::max<int>(0, (iSlow87 + 2))) + 1);
		float fSlow94 = (0.166666672f * (fSlow83 * fSlow84));
		int iSlow95 = (std::min<int>(1024, std::max<int>(0, (iSlow87 + 3))) + 1);
		int iSlow96 = std::min<int>(16384, std::max<int>(0, (iSlow79 + -1)));
		float fSlow97 = (fConst15 * fSlow74);
		float fSlow98 = (fSlow73 + -1.0f);
		float fSlow99 = std::max<float>(40.0f, fSlow98);
		float fSlow100 = std::pow(0.00100000005f, (1.0f / (fSlow24 * fSlow99)));
		float fSlow101 = (fConst0 / fSlow99);
		int iSlow102 = int(fSlow101);
		float fSlow103 = float(iSlow102);
		float fSlow104 = (fSlow101 + (4.99999987e-06f - fSlow103));
		float fSlow105 = (fSlow103 + std::floor(fSlow104));
		float fSlow106 = (fSlow101 - fSlow105);
		float fSlow107 = (fSlow101 + (-1.0f - fSlow105));
		float fSlow108 = (fSlow101 + (-2.0f - fSlow105));
		float fSlow109 = (((0.0f - fSlow106) * (0.0f - (0.5f * fSlow107))) * (0.0f - (0.333333343f * fSlow108)));
		int iSlow110 = int(fSlow104);
		int iSlow111 = (std::min<int>(1024, std::max<int>(0, iSlow110)) + 1);
		float fSlow112 = (fSlow101 + (1.0f - fSlow105));
		float fSlow113 = ((0.0f - fSlow107) * (0.0f - (0.5f * fSlow108)));
		int iSlow114 = (std::min<int>(1024, std::max<int>(0, (iSlow110 + 1))) + 1);
		float fSlow115 = (0.5f * (fSlow106 * (0.0f - fSlow108)));
		int iSlow116 = (std::min<int>(1024, std::max<int>(0, (iSlow110 + 2))) + 1);
		float fSlow117 = (0.166666672f * (fSlow106 * fSlow107));
		int iSlow118 = (std::min<int>(1024, std::max<int>(0, (iSlow110 + 3))) + 1);
		int iSlow119 = std::min<int>(16384, std::max<int>(0, (iSlow102 + -1)));
		float fSlow120 = (675.0f * (fSlow10 / fSlow99));
		float fSlow121 = (fConst15 * fSlow98);
		float fSlow122 = (fConst79 * float(fHslider13));
		float fSlow123 = (fConst16 * fSlow1);
		float fSlow124 = (0.5f * fSlow1);
		float fSlow125 = std::max<float>((2.0f * fSlow2), 40.0f);
		float fSlow126 = (fConst15 * fSlow125);
		float fSlow127 = std::max<float>((1.5f * fSlow2), 40.0f);
		float fSlow128 = (fConst15 * fSlow127);
		float fSlow129 = std::max<float>(fSlow2, 40.0f);
		float fSlow130 = (fConst15 * fSlow129);
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
			float fThen1 = (fTemp15 - (fSlow10 * (fTemp15 - (fSlow12 * float(tanhf(float((fSlow11 * fTemp15))))))));
			float fTempFTZ4 = (fSlow16 + (fConst17 * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			iRec11[0] = ((1103515245 * iRec11[1]) + 12345);
			float fTemp16 = (4.65661287e-10f * float(iRec11[0]));
			float fTempFTZ5 = (fTemp16 - (fConst36 * ((((fConst42 * fRec10[1]) + (fConst43 * fRec10[2])) + (fConst44 * fRec10[3])) + (fConst45 * fRec10[4]))));
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			int iThen2 = std::min<int>((iRec12[1] + 1), iConst46);
			iRec12[0] = (iTemp1 ? 0 : iThen2);
			float fThen3 = std::max<float>(0.0f, (fConst48 * float((iConst46 - iRec12[0]))));
			float fElse3 = (fConst49 * float(iRec12[0]));
			fVec4[(IOTA & 8191)] = ((((fTemp15 > 0.0f) ? fTemp15 : fThen1) * std::pow(0.00100000005f, (1.0f / (fTemp4 * std::max<float>(0.400000006f, (fSlow13 * (2.0f - (0.850000024f * std::max<float>(0.0f, std::min<float>(1.0f, (0.00138888892f * (fRec4[0] + -80.0f)))))))))))) + (fSlow15 * ((fRec9[0] * (((fConst35 * fRec10[2]) + (fConst26 * fRec10[0])) + (fConst26 * fRec10[4]))) * ((iRec12[0] <= iConst47) ? fElse3 : fThen3))));
			float fTempFTZ6 = fVec4[((IOTA - std::min<int>(16384, int(std::max<int>(0, int((iTemp6 + -1)))))) & 8191)];
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp17 = std::fabs(fRec3[((IOTA - 0) & 2047)]);
			float fTempFTZ7 = std::max<float>(fTemp17, ((fConst50 * fRec13[1]) + (fConst51 * fTemp17)));
			fRec13[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp18 = (fRec14[1] + (fConst15 * fTemp3));
			float fTempFTZ8 = (fTemp18 - std::floor(fTemp18));
			fRec14[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp19 = std::max<float>(1.0f, ((fSlow17 * ((fRec13[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec14[0]))]) / fTemp4)) + 4.0f));
			float fTemp20 = (fTemp19 + 4.99999987e-06f);
			int iTemp21 = int(fTemp20);
			float fTemp22 = std::floor(fTemp20);
			float fTempFTZ9 = (fTemp16 - (fConst69 * ((((fConst74 * fRec17[1]) + (fConst75 * fRec17[2])) + (fConst76 * fRec17[3])) + (fConst77 * fRec17[4]))));
			fRec17[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			int iTemp23 = ((iSlow3 > iVec1[1]) | (iTemp0 & iSlow3));
			int iThen4 = std::min<int>((iRec18[1] + 1), iConst46);
			iRec18[0] = (iTemp23 ? 0 : iThen4);
			float fThen5 = std::max<float>(0.0f, (fConst48 * float((iConst46 - iRec18[0]))));
			float fElse5 = (fConst49 * float(iRec18[0]));
			float fTemp24 = (fSlow23 * (((((fConst68 * fRec17[2]) + (fConst59 * fRec17[0])) + (fConst59 * fRec17[4])) * ((iRec18[0] <= iConst47) ? fElse5 : fThen5)) * float(iTemp23)));
			float fTemp25 = ((fSlow34 * fRec16[((IOTA - iSlow36) & 2047)]) + (fSlow37 * (((fSlow38 * fRec16[((IOTA - iSlow39) & 2047)]) + (fSlow40 * fRec16[((IOTA - iSlow41) & 2047)])) + (fSlow42 * fRec16[((IOTA - iSlow43) & 2047)]))));
			fVec5[0] = fTemp25;
			float fTemp26 = ((0.00200000009f * fTemp25) + (0.998000026f * fVec5[1]));
			float fThen6 = (fTemp26 - (fSlow44 * (fTemp26 - (fSlow46 * float(tanhf(float((fSlow45 * fTemp26))))))));
			fVec6[(IOTA & 2047)] = (fTemp24 + (fSlow25 * ((fTemp26 > 0.0f) ? fTemp26 : fThen6)));
			float fTempFTZ10 = fVec6[((IOTA - iSlow47) & 2047)];
			fRec16[(IOTA & 2047)] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp27 = std::fabs(fRec16[((IOTA - 0) & 2047)]);
			float fTempFTZ11 = std::max<float>(fTemp27, ((fConst50 * fRec15[1]) + (fConst51 * fTemp27)));
			fRec15[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fSlow48 + (fRec19[1] - std::floor((fSlow48 + fRec19[1]))));
			fRec19[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp28 = std::max<float>(1.0f, ((fSlow22 * (fRec15[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec19[0]))])) + 4.0f));
			float fTemp29 = (fTemp28 + 4.99999987e-06f);
			float fTemp30 = std::floor(fTemp29);
			int iTemp31 = int(fTemp29);
			float fTemp32 = ((fSlow61 * fRec21[((IOTA - iSlow63) & 2047)]) + (fSlow64 * (((fSlow65 * fRec21[((IOTA - iSlow66) & 2047)]) + (fSlow67 * fRec21[((IOTA - iSlow68) & 2047)])) + (fSlow69 * fRec21[((IOTA - iSlow70) & 2047)]))));
			fVec7[0] = fTemp32;
			float fTemp33 = ((0.00200000009f * fTemp32) + (0.998000026f * fVec7[1]));
			float fThen7 = (fTemp33 - (fSlow44 * (fTemp33 - (fSlow46 * float(tanhf(float((fSlow45 * fTemp33))))))));
			fVec8[(IOTA & 2047)] = (fTemp24 + (fSlow52 * ((fTemp33 > 0.0f) ? fTemp33 : fThen7)));
			float fTempFTZ13 = fVec8[((IOTA - iSlow71) & 2047)];
			fRec21[(IOTA & 2047)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp34 = std::fabs(fRec21[((IOTA - 0) & 2047)]);
			float fTempFTZ14 = std::max<float>(fTemp34, ((fConst50 * fRec20[1]) + (fConst51 * fTemp34)));
			fRec20[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fSlow72 + (fRec22[1] - std::floor((fSlow72 + fRec22[1]))));
			fRec22[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp35 = std::max<float>(1.0f, ((fSlow51 * (fRec20[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec22[0]))])) + 4.0f));
			float fTemp36 = (fTemp35 + 4.99999987e-06f);
			float fTemp37 = std::floor(fTemp36);
			int iTemp38 = int(fTemp36);
			float fTemp39 = ((fSlow86 * fRec24[((IOTA - iSlow88) & 2047)]) + (fSlow89 * (((fSlow90 * fRec24[((IOTA - iSlow91) & 2047)]) + (fSlow92 * fRec24[((IOTA - iSlow93) & 2047)])) + (fSlow94 * fRec24[((IOTA - iSlow95) & 2047)]))));
			fVec9[0] = fTemp39;
			float fTemp40 = ((0.00200000009f * fTemp39) + (0.998000026f * fVec9[1]));
			float fThen8 = (fTemp40 - (fSlow44 * (fTemp40 - (fSlow46 * float(tanhf(float((fSlow45 * fTemp40))))))));
			fVec10[(IOTA & 2047)] = (fTemp24 + (fSlow77 * ((fTemp40 > 0.0f) ? fTemp40 : fThen8)));
			float fTempFTZ16 = fVec10[((IOTA - iSlow96) & 2047)];
			fRec24[(IOTA & 2047)] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp41 = std::fabs(fRec24[((IOTA - 0) & 2047)]);
			float fTempFTZ17 = std::max<float>(fTemp41, ((fConst50 * fRec23[1]) + (fConst51 * fTemp41)));
			fRec23[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fSlow97 + (fRec25[1] - std::floor((fSlow97 + fRec25[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp42 = std::max<float>(1.0f, ((fSlow76 * (fRec23[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec25[0]))])) + 4.0f));
			float fTemp43 = (fTemp42 + 4.99999987e-06f);
			float fTemp44 = std::floor(fTemp43);
			int iTemp45 = int(fTemp43);
			float fTemp46 = ((fSlow109 * fRec26[((IOTA - iSlow111) & 2047)]) + (fSlow112 * (((fSlow113 * fRec26[((IOTA - iSlow114) & 2047)]) + (fSlow115 * fRec26[((IOTA - iSlow116) & 2047)])) + (fSlow117 * fRec26[((IOTA - iSlow118) & 2047)]))));
			fVec11[0] = fTemp46;
			float fTemp47 = ((0.00200000009f * fTemp46) + (0.998000026f * fVec11[1]));
			float fThen9 = (fTemp47 - (fSlow44 * (fTemp47 - (fSlow46 * float(tanhf(float((fSlow45 * fTemp47))))))));
			fVec12[(IOTA & 2047)] = ((fSlow100 * ((fTemp47 > 0.0f) ? fTemp47 : fThen9)) + fTemp24);
			float fTempFTZ19 = fVec12[((IOTA - iSlow119) & 2047)];
			fRec26[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp48 = std::fabs(fRec26[((IOTA - 0) & 2047)]);
			float fTempFTZ20 = std::max<float>(fTemp48, ((fConst50 * fRec27[1]) + (fConst51 * fTemp48)));
			fRec27[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fSlow121 + (fRec28[1] - std::floor((fSlow121 + fRec28[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp49 = std::max<float>(1.0f, ((fSlow120 * (fRec27[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec28[0]))])) + 4.0f));
			float fTemp50 = (fTemp49 + 4.99999987e-06f);
			int iTemp51 = int(fTemp50);
			float fTemp52 = std::floor(fTemp50);
			float fTemp53 = float(tanhf(float((2.0f * (((fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp21))))) & 2047)] * (0.0f - (fTemp19 + (-1.0f - fTemp22)))) + ((fTemp19 - fTemp22) * fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp21 + 1)))))) & 2047)])) + (fSlow18 * (((fTemp28 - fTemp30) * fRec16[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp31 + 1)))))) & 2047)]) + ((((fTemp35 - fTemp37) * fRec21[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp38 + 1)))))) & 2047)]) + ((((fTemp42 - fTemp44) * fRec24[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp45 + 1)))))) & 2047)]) + (((fRec26[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp51))))) & 2047)] * (0.0f - (fTemp49 + (-1.0f - fTemp52)))) + ((fTemp49 - fTemp52) * fRec26[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp51 + 1)))))) & 2047)])) + (fRec24[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp45))))) & 2047)] * (0.0f - (fTemp42 + (-1.0f - fTemp44)))))) + (fRec21[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp38))))) & 2047)] * (0.0f - (fTemp35 + (-1.0f - fTemp37)))))) + (fRec16[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp31))))) & 2047)] * (0.0f - (fTemp28 + (-1.0f - fTemp30))))))))))));
			float fTempFTZ22 = (fSlow123 + (fConst17 * fRec31[1]));
			fRec31[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = ((fSlow124 * fTemp53) - (fConst79 * ((fConst80 * fRec32[2]) + (fConst81 * fRec32[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp54 = (fSlow122 * (fRec31[0] * (fRec32[2] + (fRec32[0] + (2.0f * fRec32[1])))));
			float fTemp55 = std::max<float>(40.0f, (fSlow125 * fTemp2));
			float fTemp56 = (fConst0 / fTemp55);
			int iTemp57 = int(fTemp56);
			float fTemp58 = float(iTemp57);
			float fTemp59 = (fTemp56 + (4.99999987e-06f - fTemp58));
			int iTemp60 = int(fTemp59);
			float fTemp61 = (fTemp58 + std::floor(fTemp59));
			float fTemp62 = (fTemp56 - fTemp61);
			float fTemp63 = (fTemp56 + (-1.0f - fTemp61));
			float fTemp64 = (fTemp56 + (-2.0f - fTemp61));
			float fTemp65 = ((((fRec30[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp60)) + 1)) & 2047)] * (0.0f - fTemp62)) * (0.0f - (0.5f * fTemp63))) * (0.0f - (0.333333343f * fTemp64))) + ((fTemp56 + (1.0f - fTemp61)) * ((((fRec30[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp60 + 1))) + 1)) & 2047)] * (0.0f - fTemp63)) * (0.0f - (0.5f * fTemp64))) + (0.5f * ((fTemp62 * fRec30[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp60 + 2))) + 1)) & 2047)]) * (0.0f - fTemp64)))) + (0.166666672f * ((fTemp62 * fTemp63) * fRec30[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp60 + 3))) + 1)) & 2047)])))));
			fVec13[0] = fTemp65;
			float fTemp66 = ((0.00200000009f * fTemp65) + (0.998000026f * fVec13[1]));
			float fThen10 = (fTemp66 - (0.0500000007f * (fTemp66 - (0.5f * float(tanhf(float((2.0f * fTemp66))))))));
			fVec14[(IOTA & 8191)] = (fTemp54 + (((fTemp66 > 0.0f) ? fTemp66 : fThen10) * std::pow(0.00100000005f, (0.254452914f / fTemp55))));
			float fTempFTZ24 = fVec14[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp57 + -1)))) & 8191)];
			fRec30[(IOTA & 2047)] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTemp67 = std::fabs(fRec30[((IOTA - 0) & 2047)]);
			float fTempFTZ25 = std::max<float>(fTemp67, ((fConst50 * fRec29[1]) + (fConst51 * fTemp67)));
			fRec29[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTemp68 = (fRec33[1] + (fSlow126 * fTemp2));
			float fTempFTZ26 = (fTemp68 - std::floor(fTemp68));
			fRec33[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTemp69 = std::max<float>(1.0f, ((67.5f * ((fRec29[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec33[0]))]) / fTemp55)) + 4.0f));
			float fTemp70 = (fTemp69 + 4.99999987e-06f);
			float fTemp71 = std::floor(fTemp70);
			int iTemp72 = int(fTemp70);
			float fTemp73 = std::max<float>(40.0f, (fSlow127 * fTemp2));
			float fTemp74 = (fConst0 / fTemp73);
			int iTemp75 = int(fTemp74);
			float fTemp76 = float(iTemp75);
			float fTemp77 = (fTemp74 + (4.99999987e-06f - fTemp76));
			int iTemp78 = int(fTemp77);
			float fTemp79 = (fTemp76 + std::floor(fTemp77));
			float fTemp80 = (fTemp74 - fTemp79);
			float fTemp81 = (fTemp74 + (-1.0f - fTemp79));
			float fTemp82 = (fTemp74 + (-2.0f - fTemp79));
			float fTemp83 = ((((fRec35[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp78)) + 1)) & 2047)] * (0.0f - fTemp80)) * (0.0f - (0.5f * fTemp81))) * (0.0f - (0.333333343f * fTemp82))) + ((fTemp74 + (1.0f - fTemp79)) * ((((fRec35[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp78 + 1))) + 1)) & 2047)] * (0.0f - fTemp81)) * (0.0f - (0.5f * fTemp82))) + (0.5f * ((fTemp80 * fRec35[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp78 + 2))) + 1)) & 2047)]) * (0.0f - fTemp82)))) + (0.166666672f * ((fTemp80 * fTemp81) * fRec35[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp78 + 3))) + 1)) & 2047)])))));
			fVec15[0] = fTemp83;
			float fTemp84 = ((0.00200000009f * fTemp83) + (0.998000026f * fVec15[1]));
			float fThen11 = (fTemp84 - (0.0500000007f * (fTemp84 - (0.5f * float(tanhf(float((2.0f * fTemp84))))))));
			fVec16[(IOTA & 8191)] = (fTemp54 + (((fTemp84 > 0.0f) ? fTemp84 : fThen11) * std::pow(0.00100000005f, (0.254452914f / fTemp73))));
			float fTempFTZ27 = fVec16[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp75 + -1)))) & 8191)];
			fRec35[(IOTA & 2047)] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTemp85 = std::fabs(fRec35[((IOTA - 0) & 2047)]);
			float fTempFTZ28 = std::max<float>(fTemp85, ((fConst50 * fRec34[1]) + (fConst51 * fTemp85)));
			fRec34[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTemp86 = (fRec36[1] + (fSlow128 * fTemp2));
			float fTempFTZ29 = (fTemp86 - std::floor(fTemp86));
			fRec36[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp87 = std::max<float>(1.0f, ((67.5f * ((fRec34[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec36[0]))]) / fTemp73)) + 4.0f));
			float fTemp88 = (fTemp87 + 4.99999987e-06f);
			float fTemp89 = std::floor(fTemp88);
			int iTemp90 = int(fTemp88);
			float fTemp91 = std::max<float>(40.0f, (fSlow129 * fTemp2));
			float fTemp92 = (fConst0 / fTemp91);
			int iTemp93 = int(fTemp92);
			float fTemp94 = float(iTemp93);
			float fTemp95 = (fTemp92 + (4.99999987e-06f - fTemp94));
			int iTemp96 = int(fTemp95);
			float fTemp97 = (fTemp94 + std::floor(fTemp95));
			float fTemp98 = (fTemp92 - fTemp97);
			float fTemp99 = (fTemp92 + (-1.0f - fTemp97));
			float fTemp100 = (fTemp92 + (-2.0f - fTemp97));
			float fTemp101 = ((((fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, iTemp96)) + 1)) & 2047)] * (0.0f - fTemp98)) * (0.0f - (0.5f * fTemp99))) * (0.0f - (0.333333343f * fTemp100))) + ((fTemp92 + (1.0f - fTemp97)) * ((((fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp96 + 1))) + 1)) & 2047)] * (0.0f - fTemp99)) * (0.0f - (0.5f * fTemp100))) + (0.5f * ((fTemp98 * fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp96 + 2))) + 1)) & 2047)]) * (0.0f - fTemp100)))) + (0.166666672f * ((fTemp98 * fTemp99) * fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, (iTemp96 + 3))) + 1)) & 2047)])))));
			fVec17[0] = fTemp101;
			float fTemp102 = ((0.00200000009f * fTemp101) + (0.998000026f * fVec17[1]));
			float fThen12 = (fTemp102 - (0.0500000007f * (fTemp102 - (0.5f * float(tanhf(float((2.0f * fTemp102))))))));
			fVec18[(IOTA & 8191)] = ((((fTemp102 > 0.0f) ? fTemp102 : fThen12) * std::pow(0.00100000005f, (0.254452914f / fTemp91))) + fTemp54);
			float fTempFTZ30 = fVec18[((IOTA - std::min<int>(16384, std::max<int>(0, (iTemp93 + -1)))) & 8191)];
			fRec37[(IOTA & 2047)] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTemp103 = std::fabs(fRec37[((IOTA - 0) & 2047)]);
			float fTempFTZ31 = std::max<float>(fTemp103, ((fConst50 * fRec38[1]) + (fConst51 * fTemp103)));
			fRec38[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTemp104 = (fRec39[1] + (fSlow130 * fTemp2));
			float fTempFTZ32 = (fTemp104 - std::floor(fTemp104));
			fRec39[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTemp105 = std::max<float>(1.0f, ((67.5f * ((fRec38[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec39[0]))]) / fTemp91)) + 4.0f));
			float fTemp106 = (fTemp105 + 4.99999987e-06f);
			int iTemp107 = int(fTemp106);
			float fTemp108 = std::floor(fTemp106);
			float fTemp109 = ((0.5f * fTemp53) + (0.150000006f * (((fTemp69 - fTemp71) * fRec30[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp72 + 1)))))) & 2047)]) + ((((fTemp87 - fTemp89) * fRec35[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp90 + 1)))))) & 2047)]) + (((fRec37[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp107))))) & 2047)] * (0.0f - (fTemp105 + (-1.0f - fTemp108)))) + ((fTemp105 - fTemp108) * fRec37[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp107 + 1)))))) & 2047)])) + (fRec35[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp90))))) & 2047)] * (0.0f - (fTemp87 + (-1.0f - fTemp89)))))) + (fRec30[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp72))))) & 2047)] * (0.0f - (fTemp69 + (-1.0f - fTemp71))))))));
			float fTempFTZ33 = (fTemp109 - (fConst82 * ((fConst83 * fRec2[2]) + (fConst84 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fTemp109 - (fConst90 * ((fConst91 * fRec40[2]) + (fConst92 * fRec40[1]))));
			fRec40[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fTemp109 - (fConst96 * ((fConst97 * fRec41[2]) + (fConst98 * fRec41[1]))));
			fRec41[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fTemp109 - (fConst104 * ((fConst105 * fRec42[2]) + (fConst106 * fRec42[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp109 - (fConst112 * ((fConst113 * fRec43[2]) + (fConst114 * fRec43[1]))));
			fRec43[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fTemp109 - (fConst120 * ((fConst121 * fRec44[2]) + (fConst122 * fRec44[1]))));
			fRec44[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fTemp109 - (fConst128 * ((fConst129 * fRec45[2]) + (fConst130 * fRec45[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fTemp109 - (fConst136 * ((fConst137 * fRec46[2]) + (fConst138 * fRec46[1]))));
			fRec46[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = (fTemp109 - (fConst144 * ((fConst145 * fRec47[2]) + (fConst146 * fRec47[1]))));
			fRec47[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = (fTemp109 - (fConst152 * ((fConst153 * fRec48[2]) + (fConst154 * fRec48[1]))));
			fRec48[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = (fTemp109 - (fConst160 * ((fConst161 * fRec49[2]) + (fConst162 * fRec49[1]))));
			fRec49[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = (fTemp109 - (fConst168 * ((fConst169 * fRec50[2]) + (fConst170 * fRec50[1]))));
			fRec50[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = (fTemp109 - (fConst176 * ((fConst177 * fRec51[2]) + (fConst178 * fRec51[1]))));
			fRec51[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = (fTemp109 - (fConst184 * ((fConst185 * fRec52[2]) + (fConst186 * fRec52[1]))));
			fRec52[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = (fTemp109 - (fConst193 * ((fConst194 * fRec53[2]) + (fConst195 * fRec53[1]))));
			fRec53[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = (fTemp109 - (fConst201 * ((fConst202 * fRec54[2]) + (fConst203 * fRec54[1]))));
			fRec54[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = (fTemp109 - (fConst209 * ((fConst210 * fRec55[2]) + (fConst211 * fRec55[1]))));
			fRec55[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = (fTemp109 - (fConst220 * ((fConst221 * fRec56[2]) + (fConst222 * fRec56[1]))));
			fRec56[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTempFTZ51 = (fTemp109 - (fConst228 * ((fConst229 * fRec57[2]) + (fConst230 * fRec57[1]))));
			fRec57[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = (fTemp109 - (fConst236 * ((fConst237 * fRec58[2]) + (fConst238 * fRec58[1]))));
			fRec58[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = (fTemp109 - (fConst244 * ((fConst245 * fRec59[2]) + (fConst246 * fRec59[1]))));
			fRec59[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTempFTZ54 = (fTemp109 - (fConst252 * ((fConst253 * fRec60[2]) + (fConst254 * fRec60[1]))));
			fRec60[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fTempFTZ55 = (fTemp109 - (fConst260 * ((fConst261 * fRec61[2]) + (fConst262 * fRec61[1]))));
			fRec61[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fTempFTZ56 = (fTemp109 - (fConst268 * ((fConst269 * fRec62[2]) + (fConst270 * fRec62[1]))));
			fRec62[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fTempFTZ57 = (fTemp109 - (fConst276 * ((fConst277 * fRec63[2]) + (fConst278 * fRec63[1]))));
			fRec63[0] = ((std::fabs(fTempFTZ57) > 1.17549435e-38f) ? fTempFTZ57 : 0.0f);
			float fTempFTZ58 = (((fConst14 * fRec2[2]) + (((fConst89 * fRec40[2]) + (((fConst95 * fRec41[2]) + (((fConst103 * fRec42[2]) + (((0.150000006f * ((((((((((fTemp109 + (fConst111 * fRec43[0])) + (fConst119 * fRec44[0])) + (fConst127 * fRec45[0])) + (fConst135 * fRec46[0])) + (fConst143 * fRec47[0])) + (fConst151 * fRec48[0])) + (fConst159 * fRec49[0])) + (fConst167 * fRec50[0])) + (fConst175 * fRec51[0])) + (fConst183 * fRec52[0]))) + ((fConst187 * fRec52[2]) + ((0.119999997f * (((fConst192 * fRec53[0]) + (fConst200 * fRec54[0])) + (fConst208 * fRec55[0]))) + ((fConst212 * fRec55[2]) + ((fConst213 * fRec51[2]) + ((fConst214 * fRec54[2]) + ((((((((((fConst215 * fRec43[2]) + ((0.25f * ((((((((fConst219 * fRec56[0]) + (fConst227 * fRec57[0])) + (fConst235 * fRec58[0])) + (fConst243 * fRec59[0])) + (fConst251 * fRec60[0])) + (fConst259 * fRec61[0])) + (fConst267 * fRec62[0])) + (fConst275 * fRec63[0]))) + ((fConst279 * fRec63[2]) + ((fConst280 * fRec62[2]) + ((fConst281 * fRec61[2]) + ((fConst282 * fRec60[2]) + ((fConst283 * fRec59[2]) + ((fConst284 * fRec58[2]) + ((fConst285 * fRec56[2]) + (fConst286 * fRec57[2])))))))))) + (fConst287 * fRec44[2])) + (fConst288 * fRec45[2])) + (fConst289 * fRec46[2])) + (fConst290 * fRec47[2])) + (fConst291 * fRec48[2])) + (fConst292 * fRec49[2])) + (fConst293 * fRec50[2])) + (fConst294 * fRec53[2])))))))) + (fConst102 * fRec42[0]))) + (fConst94 * fRec41[0]))) + (fConst88 * fRec40[0]))) + (fConst13 * fRec2[0]))) - (fConst9 * ((fConst295 * fRec1[2]) + (fConst296 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ58) > 1.17549435e-38f) ? fTempFTZ58 : 0.0f);
			float fTemp110 = (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1])));
			float fTemp111 = (fConst9 * fTemp110);
			float fTempFTZ59 = (fTemp111 - (fConst297 * ((fConst298 * fRec0[2]) + (fConst98 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ59) > 1.17549435e-38f) ? fTempFTZ59 : 0.0f);
			float fTempFTZ60 = (fTemp111 - (fConst302 * ((fConst303 * fRec64[2]) + (fConst106 * fRec64[1]))));
			fRec64[0] = ((std::fabs(fTempFTZ60) > 1.17549435e-38f) ? fTempFTZ60 : 0.0f);
			float fTempFTZ61 = (fTemp111 - (fConst309 * ((fConst310 * fRec65[2]) + (fConst311 * fRec65[1]))));
			fRec65[0] = ((std::fabs(fTempFTZ61) > 1.17549435e-38f) ? fTempFTZ61 : 0.0f);
			float fTempFTZ62 = (fTemp111 - (fConst317 * ((fConst318 * fRec66[2]) + (fConst319 * fRec66[1]))));
			fRec66[0] = ((std::fabs(fTempFTZ62) > 1.17549435e-38f) ? fTempFTZ62 : 0.0f);
			float fTempFTZ63 = (fTemp111 - (fConst325 * ((fConst326 * fRec67[2]) + (fConst327 * fRec67[1]))));
			fRec67[0] = ((std::fabs(fTempFTZ63) > 1.17549435e-38f) ? fTempFTZ63 : 0.0f);
			float fTempFTZ64 = (fTemp111 - (fConst334 * ((fConst335 * fRec68[2]) + (fConst336 * fRec68[1]))));
			fRec68[0] = ((std::fabs(fTempFTZ64) > 1.17549435e-38f) ? fTempFTZ64 : 0.0f);
			float fTempFTZ65 = (fTemp111 - (fConst342 * ((fConst343 * fRec69[2]) + (fConst344 * fRec69[1]))));
			fRec69[0] = ((std::fabs(fTempFTZ65) > 1.17549435e-38f) ? fTempFTZ65 : 0.0f);
			float fTemp112 = float(tanhf(float((fSlow0 * ((fConst5 * fRec0[2]) + (((fConst301 * fRec64[2]) + (((fConst308 * fRec65[2]) + (((0.800000012f * ((fConst316 * fRec66[0]) + (fConst324 * fRec67[0]))) + ((fConst328 * fRec67[2]) + ((fConst333 * fRec68[2]) + ((fConst332 * fRec68[0]) + (((fConst341 * fRec69[2]) + ((fConst345 * fTemp110) + (fConst340 * fRec69[0]))) + (fConst346 * fRec66[2])))))) + (fConst307 * fRec65[0]))) + (fConst300 * fRec64[0]))) + (fConst4 * fRec0[0])))))));
			output0[i0] = FAUSTFLOAT(fTemp112);
			output1[i0] = FAUSTFLOAT(fTemp112);
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fVec3[1] = fVec3[0];
			fRec9[1] = fRec9[0];
			iRec11[1] = iRec11[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec10[j0] = fRec10[(j0 - 1)];
			}
			iRec12[1] = iRec12[0];
			IOTA = (IOTA + 1);
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			for (int j1 = 4; (j1 > 0); j1 = (j1 - 1)) {
				fRec17[j1] = fRec17[(j1 - 1)];
			}
			iRec18[1] = iRec18[0];
			fVec5[1] = fVec5[0];
			fRec15[1] = fRec15[0];
			fRec19[1] = fRec19[0];
			fVec7[1] = fVec7[0];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fVec9[1] = fVec9[0];
			fRec23[1] = fRec23[0];
			fRec25[1] = fRec25[0];
			fVec11[1] = fVec11[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fVec13[1] = fVec13[0];
			fRec29[1] = fRec29[0];
			fRec33[1] = fRec33[0];
			fVec15[1] = fVec15[0];
			fRec34[1] = fRec34[0];
			fRec36[1] = fRec36[0];
			fVec17[1] = fVec17[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec67[2] = fRec67[1];
			fRec67[1] = fRec67[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
		}
	}

};

#endif
