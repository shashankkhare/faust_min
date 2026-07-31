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
	int iRec7[2];
	
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
			iRec7[l5] = 0;
		}
	}
	
	void fillFaustSarodDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec2[0] = 1;
			iRec7[0] = ((iVec2[1] + iRec7[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec7[0])));
			iVec2[1] = iVec2[0];
			iRec7[1] = iRec7[0];
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
	float fRec6[2];
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst15;
	FAUSTFLOAT fHslider5;
	float fRec8[2];
	float fConst16;
	FAUSTFLOAT fHslider6;
	float fConst17;
	float fRec9[2];
	float fVec3[2];
	float fRec4[2];
	FAUSTFLOAT fHslider7;
	float fConst26;
	float fConst33;
	FAUSTFLOAT fHslider8;
	float fRec10[2];
	float fConst35;
	int iRec12[2];
	float fConst36;
	float fConst42;
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec11[5];
	float fConst46;
	float fConst47;
	float fRec14[2];
	int iVec4[2];
	int iRec13[2];
	float fConst48;
	int IOTA;
	float fVec5[8192];
	float fRec3[2048];
	float fConst49;
	float fConst50;
	float fRec15[2];
	float fRec16[2];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	float fConst58;
	float fConst65;
	float fConst67;
	float fConst68;
	float fConst73;
	float fConst74;
	float fConst75;
	float fConst76;
	float fRec19[5];
	float fRec21[2];
	int iVec6[2];
	int iRec20[2];
	float fVec7[2];
	float fRec22[2];
	float fVec8[2048];
	float fRec18[2048];
	float fRec17[2];
	float fRec23[2];
	float fVec9[2];
	float fRec26[2];
	float fVec10[2048];
	float fRec25[2048];
	float fRec24[2];
	float fRec27[2];
	FAUSTFLOAT fHslider11;
	float fVec11[2];
	float fRec30[2];
	float fVec12[2048];
	float fRec29[2048];
	float fRec28[2];
	float fRec31[2];
	float fVec13[2];
	float fRec33[2];
	float fVec14[2048];
	float fRec32[2048];
	float fRec34[2];
	float fRec35[2];
	float fConst78;
	FAUSTFLOAT fHslider12;
	float fRec38[2];
	float fConst79;
	float fConst80;
	float fRec39[3];
	float fVec15[2];
	float fRec40[2];
	float fVec16[8192];
	float fRec37[2048];
	float fRec36[2];
	float fRec41[2];
	float fVec17[2];
	float fRec44[2];
	float fVec18[8192];
	float fRec43[2048];
	float fRec42[2];
	float fRec45[2];
	float fVec19[2];
	float fRec47[2];
	float fVec20[8192];
	float fRec46[2048];
	float fRec48[2];
	float fRec49[2];
	float fConst81;
	float fConst82;
	float fConst83;
	float fRec2[3];
	float fConst87;
	float fConst88;
	float fConst89;
	float fConst90;
	float fConst91;
	float fRec50[3];
	float fConst93;
	float fConst94;
	float fConst95;
	float fConst96;
	float fConst97;
	float fRec51[3];
	float fConst101;
	float fConst102;
	float fConst103;
	float fConst104;
	float fConst105;
	float fRec52[3];
	float fConst110;
	float fConst111;
	float fConst112;
	float fConst113;
	float fRec53[3];
	float fConst118;
	float fConst119;
	float fConst120;
	float fConst121;
	float fRec54[3];
	float fConst126;
	float fConst127;
	float fConst128;
	float fConst129;
	float fRec55[3];
	float fConst134;
	float fConst135;
	float fConst136;
	float fConst137;
	float fRec56[3];
	float fConst142;
	float fConst143;
	float fConst144;
	float fConst145;
	float fRec57[3];
	float fConst150;
	float fConst151;
	float fConst152;
	float fConst153;
	float fRec58[3];
	float fConst158;
	float fConst159;
	float fConst160;
	float fConst161;
	float fRec59[3];
	float fConst166;
	float fConst167;
	float fConst168;
	float fConst169;
	float fRec60[3];
	float fConst174;
	float fConst175;
	float fConst176;
	float fConst177;
	float fRec61[3];
	float fConst182;
	float fConst183;
	float fConst184;
	float fConst185;
	float fRec62[3];
	float fConst186;
	float fConst191;
	float fConst192;
	float fConst193;
	float fConst194;
	float fRec63[3];
	float fConst199;
	float fConst200;
	float fConst201;
	float fConst202;
	float fRec64[3];
	float fConst207;
	float fConst208;
	float fConst209;
	float fConst210;
	float fRec65[3];
	float fConst211;
	float fConst212;
	float fConst213;
	float fConst214;
	float fConst218;
	float fConst219;
	float fConst220;
	float fConst221;
	float fRec66[3];
	float fConst226;
	float fConst227;
	float fConst228;
	float fConst229;
	float fRec67[3];
	float fConst234;
	float fConst235;
	float fConst236;
	float fConst237;
	float fRec68[3];
	float fConst242;
	float fConst243;
	float fConst244;
	float fConst245;
	float fRec69[3];
	float fConst250;
	float fConst251;
	float fConst252;
	float fConst253;
	float fRec70[3];
	float fConst258;
	float fConst259;
	float fConst260;
	float fConst261;
	float fRec71[3];
	float fConst266;
	float fConst267;
	float fConst268;
	float fConst269;
	float fRec72[3];
	float fConst274;
	float fConst275;
	float fConst276;
	float fConst277;
	float fRec73[3];
	float fConst278;
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
	float fRec1[3];
	float fConst296;
	float fConst297;
	float fRec0[3];
	float fConst299;
	float fConst300;
	float fConst301;
	float fConst302;
	float fRec74[3];
	float fConst306;
	float fConst307;
	float fConst308;
	float fConst309;
	float fConst310;
	float fRec75[3];
	float fConst314;
	float fConst315;
	float fConst316;
	float fConst317;
	float fConst318;
	float fRec76[3];
	float fConst322;
	float fConst323;
	float fConst324;
	float fConst325;
	float fConst326;
	float fRec77[3];
	float fConst330;
	float fConst331;
	float fConst332;
	float fConst333;
	float fConst334;
	float fRec78[3];
	float fConst338;
	float fConst339;
	float fConst340;
	float fConst341;
	float fConst342;
	float fRec79[3];
	float fConst343;
	
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
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
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
		fConst4 = (0.550000012f / (fConst1 * fConst3));
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
		float fConst19 = std::tan((15707.9629f / fConst0));
		float fConst20 = (fConst0 * fConst19);
		float fConst21 = FaustSarodDSP_faustpower2_f(fConst0);
		float fConst22 = std::sqrt((4.0f * ((fConst21 * fConst19) * std::tan((314.159271f / fConst0)))));
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
		fConst46 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst47 = (1.0f / fConst46);
		fConst48 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		fConst49 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst50 = (1.0f - fConst49);
		float fConst51 = std::tan((37699.1133f / fConst0));
		float fConst52 = (fConst0 * fConst51);
		float fConst53 = std::tan((471.238892f / fConst0));
		float fConst54 = std::sqrt((4.0f * ((fConst21 * fConst51) * fConst53)));
		float fConst55 = FaustSarodDSP_faustpower2_f(fConst54);
		float fConst56 = ((2.0f * fConst52) - (0.5f * (fConst55 / fConst52)));
		float fConst57 = FaustSarodDSP_faustpower2_f(fConst56);
		fConst58 = (4.0f * fConst57);
		float fConst59 = (fConst58 + (8.0f * fConst55));
		float fConst60 = (fConst15 * fConst55);
		float fConst61 = (2.82842708f * fConst56);
		float fConst62 = (fConst56 / fConst0);
		float fConst63 = (11.3137083f * fConst62);
		float fConst64 = (((fConst18 * (fConst59 + (fConst60 * (fConst61 + fConst60)))) + fConst63) + 16.0f);
		fConst65 = (0.0500000007f * (fConst18 / fConst64));
		float fConst66 = (8.0f * fConst57);
		fConst67 = (0.0f - fConst66);
		fConst68 = (1.0f / fConst64);
		float fConst69 = (fConst37 * fConst55);
		float fConst70 = (5.65685415f * fConst56);
		float fConst71 = (4.0f * fConst60);
		float fConst72 = (22.6274166f * fConst62);
		fConst73 = ((fConst69 * (fConst70 + fConst71)) + (-64.0f - fConst72));
		fConst74 = ((fConst18 * ((0.0f - (fConst66 + (16.0f * fConst55))) + (6.0f * (fConst18 * FaustSarodDSP_faustpower4_f(fConst54))))) + 96.0f);
		fConst75 = ((fConst72 + (fConst69 * (fConst71 - fConst70))) + -64.0f);
		fConst76 = ((fConst18 * (fConst59 + (fConst60 * (fConst60 - fConst61)))) + (16.0f - fConst63));
		float fConst77 = (1.0f / fConst51);
		fConst78 = (1.0f / (((fConst77 + 1.41421354f) / fConst51) + 1.0f));
		fConst79 = (((fConst77 + -1.41421354f) / fConst51) + 1.0f);
		fConst80 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst51))));
		fConst81 = (1.0f / fConst12);
		fConst82 = (((fConst11 + -0.400000006f) / fConst10) + 1.0f);
		fConst83 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst10))));
		float fConst84 = std::tan((8168.14111f / fConst0));
		float fConst85 = (1.0f / fConst84);
		float fConst86 = (((fConst85 + 0.400000006f) / fConst84) + 1.0f);
		fConst87 = (0.600000024f / (fConst84 * fConst86));
		fConst88 = (0.0f - fConst87);
		fConst89 = (1.0f / fConst86);
		fConst90 = (((fConst85 + -0.400000006f) / fConst84) + 1.0f);
		fConst91 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst84))));
		float fConst92 = (((fConst2 + 0.400000006f) / fConst1) + 1.0f);
		fConst93 = (0.649999976f / (fConst1 * fConst92));
		fConst94 = (0.0f - fConst93);
		fConst95 = (1.0f / fConst92);
		fConst96 = (((fConst2 + -0.400000006f) / fConst1) + 1.0f);
		fConst97 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst1))));
		float fConst98 = std::tan((3769.91113f / fConst0));
		float fConst99 = (1.0f / fConst98);
		float fConst100 = (((fConst99 + 0.400000006f) / fConst98) + 1.0f);
		fConst101 = (0.400000006f / (fConst98 * fConst100));
		fConst102 = (0.0f - fConst101);
		fConst103 = (1.0f / fConst100);
		fConst104 = (((fConst99 + -0.400000006f) / fConst98) + 1.0f);
		fConst105 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst98))));
		float fConst106 = std::tan((1328.89368f / fConst0));
		float fConst107 = (1.0f / fConst106);
		float fConst108 = (((fConst107 + 0.666666687f) / fConst106) + 1.0f);
		float fConst109 = (fConst106 * fConst108);
		fConst110 = (1.0f / fConst109);
		fConst111 = (1.0f / fConst108);
		fConst112 = (((fConst107 + -0.666666687f) / fConst106) + 1.0f);
		fConst113 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst106))));
		float fConst114 = std::tan((1378.21667f / fConst0));
		float fConst115 = (1.0f / fConst114);
		float fConst116 = (((fConst115 + 0.666666687f) / fConst114) + 1.0f);
		float fConst117 = (fConst114 * fConst116);
		fConst118 = (1.0f / fConst117);
		fConst119 = (1.0f / fConst116);
		fConst120 = (((fConst115 + -0.666666687f) / fConst114) + 1.0f);
		fConst121 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst114))));
		float fConst122 = std::tan((1461.78308f / fConst0));
		float fConst123 = (1.0f / fConst122);
		float fConst124 = (((fConst123 + 0.666666687f) / fConst122) + 1.0f);
		float fConst125 = (fConst122 * fConst124);
		fConst126 = (1.0f / fConst125);
		fConst127 = (1.0f / fConst124);
		fConst128 = (((fConst123 + -0.666666687f) / fConst122) + 1.0f);
		fConst129 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst122))));
		float fConst130 = std::tan((1499.79639f / fConst0));
		float fConst131 = (1.0f / fConst130);
		float fConst132 = (((fConst131 + 0.666666687f) / fConst130) + 1.0f);
		float fConst133 = (fConst130 * fConst132);
		fConst134 = (1.0f / fConst133);
		fConst135 = (1.0f / fConst132);
		fConst136 = (((fConst131 + -0.666666687f) / fConst130) + 1.0f);
		fConst137 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst130))));
		float fConst138 = std::tan((1565.76978f / fConst0));
		float fConst139 = (1.0f / fConst138);
		float fConst140 = (((fConst139 + 0.666666687f) / fConst138) + 1.0f);
		float fConst141 = (fConst138 * fConst140);
		fConst142 = (1.0f / fConst141);
		fConst143 = (1.0f / fConst140);
		fConst144 = (((fConst139 + -0.666666687f) / fConst138) + 1.0f);
		fConst145 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst138))));
		float fConst146 = std::tan((1642.73877f / fConst0));
		float fConst147 = (1.0f / fConst146);
		float fConst148 = (((fConst147 + 0.666666687f) / fConst146) + 1.0f);
		float fConst149 = (fConst146 * fConst148);
		fConst150 = (1.0f / fConst149);
		fConst151 = (1.0f / fConst148);
		fConst152 = (((fConst147 + -0.666666687f) / fConst146) + 1.0f);
		fConst153 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst146))));
		float fConst154 = std::tan((1683.57947f / fConst0));
		float fConst155 = (1.0f / fConst154);
		float fConst156 = (((fConst155 + 0.666666687f) / fConst154) + 1.0f);
		float fConst157 = (fConst154 * fConst156);
		fConst158 = (1.0f / fConst157);
		fConst159 = (1.0f / fConst156);
		fConst160 = (((fConst155 + -0.666666687f) / fConst154) + 1.0f);
		fConst161 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst154))));
		float fConst162 = std::tan((1709.65466f / fConst0));
		float fConst163 = (1.0f / fConst162);
		float fConst164 = (((fConst163 + 0.666666687f) / fConst162) + 1.0f);
		float fConst165 = (fConst162 * fConst164);
		fConst166 = (1.0f / fConst165);
		fConst167 = (1.0f / fConst164);
		fConst168 = (((fConst163 + -0.666666687f) / fConst162) + 1.0f);
		fConst169 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst162))));
		float fConst170 = std::tan((1905.69006f / fConst0));
		float fConst171 = (1.0f / fConst170);
		float fConst172 = (((fConst171 + 0.5f) / fConst170) + 1.0f);
		float fConst173 = (fConst170 * fConst172);
		fConst174 = (1.0f / fConst173);
		fConst175 = (1.0f / fConst172);
		fConst176 = (((fConst171 + -0.5f) / fConst170) + 1.0f);
		fConst177 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst170))));
		float fConst178 = std::tan((2670.35376f / fConst0));
		float fConst179 = (1.0f / fConst178);
		float fConst180 = (((fConst179 + 0.666666687f) / fConst178) + 1.0f);
		float fConst181 = (fConst178 * fConst180);
		fConst182 = (1.0f / fConst181);
		fConst183 = (1.0f / fConst180);
		fConst184 = (((fConst179 + -0.666666687f) / fConst178) + 1.0f);
		fConst185 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst178))));
		fConst186 = (0.0f - (0.150000006f / fConst181));
		float fConst187 = std::tan((1739.18567f / fConst0));
		float fConst188 = (1.0f / fConst187);
		float fConst189 = (((fConst188 + 0.666666687f) / fConst187) + 1.0f);
		float fConst190 = (fConst187 * fConst189);
		fConst191 = (1.0f / fConst190);
		fConst192 = (1.0f / fConst189);
		fConst193 = (((fConst188 + -0.666666687f) / fConst187) + 1.0f);
		fConst194 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst187))));
		float fConst195 = std::tan((1801.07507f / fConst0));
		float fConst196 = (1.0f / fConst195);
		float fConst197 = (((fConst196 + 0.666666687f) / fConst195) + 1.0f);
		float fConst198 = (fConst195 * fConst197);
		fConst199 = (1.0f / fConst198);
		fConst200 = (1.0f / fConst197);
		fConst201 = (((fConst196 + -0.666666687f) / fConst195) + 1.0f);
		fConst202 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst195))));
		float fConst203 = std::tan((1917.31396f / fConst0));
		float fConst204 = (1.0f / fConst203);
		float fConst205 = (((fConst204 + 0.5f) / fConst203) + 1.0f);
		float fConst206 = (fConst203 * fConst205);
		fConst207 = (1.0f / fConst206);
		fConst208 = (1.0f / fConst205);
		fConst209 = (((fConst204 + -0.5f) / fConst203) + 1.0f);
		fConst210 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst203))));
		fConst211 = (0.0f - (0.119999997f / fConst206));
		fConst212 = (0.0f - (0.150000006f / fConst173));
		fConst213 = (0.0f - (0.119999997f / fConst198));
		fConst214 = (0.0f - (0.150000006f / fConst109));
		float fConst215 = (1.0f / fConst53);
		float fConst216 = (((fConst215 + 0.333333343f) / fConst53) + 1.0f);
		float fConst217 = (fConst53 * fConst216);
		fConst218 = (1.0f / fConst217);
		fConst219 = (1.0f / fConst216);
		fConst220 = (((fConst215 + -0.333333343f) / fConst53) + 1.0f);
		fConst221 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst53))));
		float fConst222 = std::tan((743.61499f / fConst0));
		float fConst223 = (1.0f / fConst222);
		float fConst224 = (((fConst223 + 0.333333343f) / fConst222) + 1.0f);
		float fConst225 = (fConst222 * fConst224);
		fConst226 = (1.0f / fConst225);
		fConst227 = (1.0f / fConst224);
		fConst228 = (((fConst223 + -0.333333343f) / fConst222) + 1.0f);
		fConst229 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst222))));
		float fConst230 = std::tan((754.610535f / fConst0));
		float fConst231 = (1.0f / fConst230);
		float fConst232 = (((fConst231 + 0.333333343f) / fConst230) + 1.0f);
		float fConst233 = (fConst230 * fConst232);
		fConst234 = (1.0f / fConst233);
		fConst235 = (1.0f / fConst232);
		fConst236 = (((fConst231 + -0.333333343f) / fConst230) + 1.0f);
		fConst237 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst230))));
		float fConst238 = std::tan((990.858337f / fConst0));
		float fConst239 = (1.0f / fConst238);
		float fConst240 = (((fConst239 + 0.333333343f) / fConst238) + 1.0f);
		float fConst241 = (fConst238 * fConst240);
		fConst242 = (1.0f / fConst241);
		fConst243 = (1.0f / fConst240);
		fConst244 = (((fConst239 + -0.333333343f) / fConst238) + 1.0f);
		fConst245 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst238))));
		float fConst246 = std::tan((1007.50879f / fConst0));
		float fConst247 = (1.0f / fConst246);
		float fConst248 = (((fConst247 + 0.333333343f) / fConst246) + 1.0f);
		float fConst249 = (fConst246 * fConst248);
		fConst250 = (1.0f / fConst249);
		fConst251 = (1.0f / fConst248);
		fConst252 = (((fConst247 + -0.333333343f) / fConst246) + 1.0f);
		fConst253 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst246))));
		float fConst254 = std::tan((1075.36719f / fConst0));
		float fConst255 = (1.0f / fConst254);
		float fConst256 = (((fConst255 + 0.333333343f) / fConst254) + 1.0f);
		float fConst257 = (fConst254 * fConst256);
		fConst258 = (1.0f / fConst257);
		fConst259 = (1.0f / fConst256);
		fConst260 = (((fConst255 + -0.333333343f) / fConst254) + 1.0f);
		fConst261 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst254))));
		float fConst262 = std::tan((1213.91138f / fConst0));
		float fConst263 = (1.0f / fConst262);
		float fConst264 = (((fConst263 + 0.333333343f) / fConst262) + 1.0f);
		float fConst265 = (fConst262 * fConst264);
		fConst266 = (1.0f / fConst265);
		fConst267 = (1.0f / fConst264);
		fConst268 = (((fConst263 + -0.333333343f) / fConst262) + 1.0f);
		fConst269 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst262))));
		float fConst270 = std::tan((1265.11938f / fConst0));
		float fConst271 = (1.0f / fConst270);
		float fConst272 = (((fConst271 + 0.333333343f) / fConst270) + 1.0f);
		float fConst273 = (fConst270 * fConst272);
		fConst274 = (1.0f / fConst273);
		fConst275 = (1.0f / fConst272);
		fConst276 = (((fConst271 + -0.333333343f) / fConst270) + 1.0f);
		fConst277 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst270))));
		fConst278 = (0.0f - (0.25f / fConst273));
		fConst279 = (0.0f - (0.25f / fConst265));
		fConst280 = (0.0f - (0.25f / fConst257));
		fConst281 = (0.0f - (0.25f / fConst249));
		fConst282 = (0.0f - (0.25f / fConst241));
		fConst283 = (0.0f - (0.25f / fConst233));
		fConst284 = (0.0f - (0.25f / fConst217));
		fConst285 = (0.0f - (0.25f / fConst225));
		fConst286 = (0.0f - (0.150000006f / fConst117));
		fConst287 = (0.0f - (0.150000006f / fConst125));
		fConst288 = (0.0f - (0.150000006f / fConst133));
		fConst289 = (0.0f - (0.150000006f / fConst141));
		fConst290 = (0.0f - (0.150000006f / fConst149));
		fConst291 = (0.0f - (0.150000006f / fConst157));
		fConst292 = (0.0f - (0.150000006f / fConst165));
		fConst293 = (0.0f - (0.119999997f / fConst190));
		fConst294 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst295 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst6))));
		fConst296 = (1.0f / fConst3);
		fConst297 = (((fConst2 + -0.333333343f) / fConst1) + 1.0f);
		float fConst298 = (((fConst99 + 0.333333343f) / fConst98) + 1.0f);
		fConst299 = (0.800000012f / (fConst98 * fConst298));
		fConst300 = (0.0f - fConst299);
		fConst301 = (1.0f / fConst298);
		fConst302 = (((fConst99 + -0.333333343f) / fConst98) + 1.0f);
		float fConst303 = std::tan((3298.67236f / fConst0));
		float fConst304 = (1.0f / fConst303);
		float fConst305 = (((fConst304 + 0.285714298f) / fConst303) + 1.0f);
		fConst306 = (0.899999976f / (fConst303 * fConst305));
		fConst307 = (0.0f - fConst306);
		fConst308 = (1.0f / fConst305);
		fConst309 = (((fConst304 + -0.285714298f) / fConst303) + 1.0f);
		fConst310 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst303))));
		float fConst311 = std::tan((2984.51294f / fConst0));
		float fConst312 = (1.0f / fConst311);
		float fConst313 = (((fConst312 + 0.285714298f) / fConst311) + 1.0f);
		fConst314 = (0.850000024f / (fConst311 * fConst313));
		fConst315 = (0.0f - fConst314);
		fConst316 = (1.0f / fConst313);
		fConst317 = (((fConst312 + -0.285714298f) / fConst311) + 1.0f);
		fConst318 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst311))));
		float fConst319 = std::tan((1727.87598f / fConst0));
		float fConst320 = (1.0f / fConst319);
		float fConst321 = (((fConst320 + 0.5f) / fConst319) + 1.0f);
		fConst322 = (0.5f / (fConst319 * fConst321));
		fConst323 = (0.0f - fConst322);
		fConst324 = (1.0f / fConst321);
		fConst325 = (((fConst320 + -0.5f) / fConst319) + 1.0f);
		fConst326 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst319))));
		float fConst327 = std::tan((1005.30963f / fConst0));
		float fConst328 = (1.0f / fConst327);
		float fConst329 = (((fConst328 + 0.666666687f) / fConst327) + 1.0f);
		fConst330 = (0.600000024f / (fConst327 * fConst329));
		fConst331 = (0.0f - fConst330);
		fConst332 = (1.0f / fConst329);
		fConst333 = (((fConst328 + -0.666666687f) / fConst327) + 1.0f);
		fConst334 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst327))));
		float fConst335 = std::tan((565.486694f / fConst0));
		float fConst336 = (1.0f / fConst335);
		float fConst337 = (((fConst336 + 0.400000006f) / fConst335) + 1.0f);
		fConst338 = (1.45000005f / (fConst335 * fConst337));
		fConst339 = (0.0f - fConst338);
		fConst340 = (1.0f / fConst337);
		fConst341 = (((fConst336 + -0.400000006f) / fConst335) + 1.0f);
		fConst342 = (2.0f * (1.0f - (1.0f / FaustSarodDSP_faustpower2_f(fConst335))));
		fConst343 = (0.349999994f / fConst8);
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
		fHslider9 = FAUSTFLOAT(0.10000000000000001f);
		fHslider10 = FAUSTFLOAT(166.5f);
		fHslider11 = FAUSTFLOAT(130.0f);
		fHslider12 = FAUSTFLOAT(0.050000000000000003f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec6[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec5[l3] = 0.0f;
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
			fRec4[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iRec12[l11] = 0;
		}
		for (int l12 = 0; (l12 < 5); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec14[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iVec4[l14] = 0;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			iRec13[l15] = 0;
		}
		IOTA = 0;
		for (int l16 = 0; (l16 < 8192); l16 = (l16 + 1)) {
			fVec5[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2048); l17 = (l17 + 1)) {
			fRec3[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec15[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec16[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 5); l20 = (l20 + 1)) {
			fRec19[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			iVec6[l22] = 0;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			iRec20[l23] = 0;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fVec7[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec22[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2048); l26 = (l26 + 1)) {
			fVec8[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2048); l27 = (l27 + 1)) {
			fRec18[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec17[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec23[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fVec9[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec26[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2048); l32 = (l32 + 1)) {
			fVec10[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2048); l33 = (l33 + 1)) {
			fRec25[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec24[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec27[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fVec11[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec30[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2048); l38 = (l38 + 1)) {
			fVec12[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2048); l39 = (l39 + 1)) {
			fRec29[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec28[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec31[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fVec13[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec33[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2048); l44 = (l44 + 1)) {
			fVec14[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2048); l45 = (l45 + 1)) {
			fRec32[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec34[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec35[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec38[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec39[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fVec15[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec40[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 8192); l52 = (l52 + 1)) {
			fVec16[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2048); l53 = (l53 + 1)) {
			fRec37[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec36[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec41[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fVec17[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec44[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 8192); l58 = (l58 + 1)) {
			fVec18[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2048); l59 = (l59 + 1)) {
			fRec43[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec42[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec45[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fVec19[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec47[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 8192); l64 = (l64 + 1)) {
			fVec20[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2048); l65 = (l65 + 1)) {
			fRec46[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec48[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec49[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec2[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 3); l69 = (l69 + 1)) {
			fRec50[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 3); l70 = (l70 + 1)) {
			fRec51[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) {
			fRec52[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) {
			fRec53[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec54[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec55[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec56[l75] = 0.0f;
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec57[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 3); l77 = (l77 + 1)) {
			fRec58[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 3); l78 = (l78 + 1)) {
			fRec59[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec60[l79] = 0.0f;
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec61[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 3); l81 = (l81 + 1)) {
			fRec62[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec63[l82] = 0.0f;
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
		for (int l89 = 0; (l89 < 3); l89 = (l89 + 1)) {
			fRec70[l89] = 0.0f;
		}
		for (int l90 = 0; (l90 < 3); l90 = (l90 + 1)) {
			fRec71[l90] = 0.0f;
		}
		for (int l91 = 0; (l91 < 3); l91 = (l91 + 1)) {
			fRec72[l91] = 0.0f;
		}
		for (int l92 = 0; (l92 < 3); l92 = (l92 + 1)) {
			fRec73[l92] = 0.0f;
		}
		for (int l93 = 0; (l93 < 3); l93 = (l93 + 1)) {
			fRec1[l93] = 0.0f;
		}
		for (int l94 = 0; (l94 < 3); l94 = (l94 + 1)) {
			fRec0[l94] = 0.0f;
		}
		for (int l95 = 0; (l95 < 3); l95 = (l95 + 1)) {
			fRec74[l95] = 0.0f;
		}
		for (int l96 = 0; (l96 < 3); l96 = (l96 + 1)) {
			fRec75[l96] = 0.0f;
		}
		for (int l97 = 0; (l97 < 3); l97 = (l97 + 1)) {
			fRec76[l97] = 0.0f;
		}
		for (int l98 = 0; (l98 < 3); l98 = (l98 + 1)) {
			fRec77[l98] = 0.0f;
		}
		for (int l99 = 0; (l99 < 3); l99 = (l99 + 1)) {
			fRec78[l99] = 0.0f;
		}
		for (int l100 = 0; (l100 < 3); l100 = (l100 + 1)) {
			fRec79[l100] = 0.0f;
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
		ui_interface->addHorizontalSlider("chikari_freq1", &fHslider11, FAUSTFLOAT(130.0f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_freq2", &fHslider10, FAUSTFLOAT(166.5f), FAUSTFLOAT(130.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari_gain", &fHslider9, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(90.0f), FAUSTFLOAT(900.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jawari", &fHslider7, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider12, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
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
		float fSlow0 = float(fHslider0);
		float fSlow1 = (2.49950004f * fSlow0);
		float fSlow2 = float(fButton0);
		float fSlow3 = float(fHslider1);
		int iSlow4 = (float(fHslider2) > 0.5f);
		float fSlow5 = float((1 - iSlow4));
		float fSlow6 = (fSlow3 * fSlow5);
		float fSlow7 = float(iSlow4);
		float fSlow8 = ((fSlow2 * float(fHslider3)) * float(fHslider4));
		float fSlow9 = (fConst15 * float(fHslider5));
		float fSlow10 = (fConst16 * float(fHslider6));
		float fSlow11 = float(fHslider7);
		float fSlow12 = ((20.0f * fSlow11) + 1.0f);
		float fSlow13 = (1.0f / fSlow12);
		float fSlow14 = ((2.0f * fSlow11) + 1.0f);
		float fSlow15 = (1.0f / fSlow14);
		float fSlow16 = (1.0f - (0.349999994f * fSlow11));
		float fSlow17 = float(fHslider8);
		float fSlow18 = (fConst33 * (fSlow17 * fSlow5));
		float fSlow19 = (fConst16 * std::max<float>(fSlow2, float(iSlow4)));
		float fSlow20 = (1350.0f * fSlow11);
		float fSlow21 = (0.25f * float(fHslider9));
		float fSlow22 = float(fHslider10);
		float fSlow23 = (fSlow22 + 1.0f);
		float fSlow24 = std::max<float>(40.0f, fSlow23);
		float fSlow25 = (675.0f * (fSlow11 / fSlow24));
		float fSlow26 = (fConst65 * fSlow17);
		float fSlow27 = std::max<float>(0.400000006f, (1.5f * (1.0f - (0.174999997f * fSlow11))));
		float fSlow28 = std::pow(0.00100000005f, (1.0f / (fSlow24 * fSlow27)));
		float fSlow29 = (fConst0 / fSlow24);
		int iSlow30 = int(fSlow29);
		float fSlow31 = float(iSlow30);
		float fSlow32 = (fSlow29 + (-0.499989986f - fSlow31));
		int iSlow33 = (std::min<int>(1024, std::max<int>(0, int(fSlow32))) + 1);
		float fSlow34 = (fSlow31 + std::floor(fSlow32));
		float fSlow35 = ((fSlow34 + (1.0f - fSlow29)) / (fSlow29 + (1.0f - fSlow34)));
		float fSlow36 = ((10.0f * fSlow11) + 1.0f);
		float fSlow37 = (1.0f / fSlow36);
		float fSlow38 = (fSlow11 + 1.0f);
		float fSlow39 = (1.0f / fSlow38);
		int iSlow40 = std::min<int>(16384, std::max<int>(0, iSlow30));
		float fSlow41 = (fConst15 * fSlow23);
		float fSlow42 = (fSlow22 + -1.0f);
		float fSlow43 = std::max<float>(40.0f, fSlow42);
		float fSlow44 = (675.0f * (fSlow11 / fSlow43));
		float fSlow45 = std::pow(0.00100000005f, (1.0f / (fSlow27 * fSlow43)));
		float fSlow46 = (fConst0 / fSlow43);
		int iSlow47 = int(fSlow46);
		float fSlow48 = float(iSlow47);
		float fSlow49 = (fSlow46 + (-0.499989986f - fSlow48));
		int iSlow50 = (std::min<int>(1024, std::max<int>(0, int(fSlow49))) + 1);
		float fSlow51 = (fSlow48 + std::floor(fSlow49));
		float fSlow52 = ((fSlow51 + (1.0f - fSlow46)) / (fSlow46 + (1.0f - fSlow51)));
		int iSlow53 = std::min<int>(16384, std::max<int>(0, iSlow47));
		float fSlow54 = (fConst15 * fSlow42);
		float fSlow55 = float(fHslider11);
		float fSlow56 = (fSlow55 + 1.0f);
		float fSlow57 = std::max<float>(40.0f, fSlow56);
		float fSlow58 = (675.0f * (fSlow11 / fSlow57));
		float fSlow59 = std::pow(0.00100000005f, (1.0f / (fSlow27 * fSlow57)));
		float fSlow60 = (fConst0 / fSlow57);
		int iSlow61 = int(fSlow60);
		float fSlow62 = float(iSlow61);
		float fSlow63 = (fSlow60 + (-0.499989986f - fSlow62));
		int iSlow64 = (std::min<int>(1024, std::max<int>(0, int(fSlow63))) + 1);
		float fSlow65 = (fSlow62 + std::floor(fSlow63));
		float fSlow66 = ((fSlow65 + (1.0f - fSlow60)) / (fSlow60 + (1.0f - fSlow65)));
		int iSlow67 = std::min<int>(16384, std::max<int>(0, iSlow61));
		float fSlow68 = (fConst15 * fSlow56);
		float fSlow69 = (fSlow55 + -1.0f);
		float fSlow70 = std::max<float>(40.0f, fSlow69);
		float fSlow71 = std::pow(0.00100000005f, (1.0f / (fSlow27 * fSlow70)));
		float fSlow72 = (fConst0 / fSlow70);
		int iSlow73 = int(fSlow72);
		float fSlow74 = float(iSlow73);
		float fSlow75 = (fSlow72 + (-0.499989986f - fSlow74));
		int iSlow76 = (std::min<int>(1024, std::max<int>(0, int(fSlow75))) + 1);
		float fSlow77 = (fSlow74 + std::floor(fSlow75));
		float fSlow78 = ((fSlow77 + (1.0f - fSlow72)) / (fSlow72 + (1.0f - fSlow77)));
		int iSlow79 = std::min<int>(16384, std::max<int>(0, iSlow73));
		float fSlow80 = (675.0f * (fSlow11 / fSlow70));
		float fSlow81 = (fConst15 * fSlow69);
		float fSlow82 = (fConst78 * float(fHslider12));
		float fSlow83 = (fConst16 * fSlow2);
		float fSlow84 = (0.5f * fSlow2);
		float fSlow85 = std::max<float>((2.0f * fSlow3), 40.0f);
		float fSlow86 = (fConst15 * fSlow85);
		float fSlow87 = std::max<float>((1.5f * fSlow3), 40.0f);
		float fSlow88 = (fConst15 * fSlow87);
		float fSlow89 = std::max<float>(fSlow3, 40.0f);
		float fSlow90 = (fConst15 * fSlow89);
		float fSlow91 = (2.77722216f * fSlow0);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow2;
			int iTemp0 = (fSlow2 > fVec0[1]);
			int iTemp1 = iTemp0;
			iVec1[0] = iSlow4;
			float fTempFTZ0 = (fSlow6 + (fSlow7 * fRec6[1]));
			fRec6[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fThen0 = ((0.00100000005f * fRec6[0]) + (0.999000013f * fRec5[1]));
			float fTempFTZ1 = (iTemp1 ? fRec6[0] : fThen0);
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow9 + (fRec8[1] - std::floor((fSlow9 + fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow10 + (fConst17 * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp2 = std::pow(2.0f, (0.000833333354f * fRec9[0]));
			float fTemp3 = ((fRec5[0] * ((fSlow8 * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec8[0]))]) + 1.0f)) * fTemp2);
			float fTemp4 = std::max<float>(40.0f, fTemp3);
			float fTemp5 = (fConst0 / fTemp4);
			int iTemp6 = int(fTemp5);
			float fTemp7 = float(iTemp6);
			float fTemp8 = (fTemp5 + (-0.499989986f - fTemp7));
			float fTemp9 = fRec3[((IOTA - (std::min<int>(1024, int(std::max<int>(0, int(fTemp8)))) + 1)) & 2047)];
			fVec3[0] = fTemp9;
			float fTemp10 = (fTemp7 + std::floor(fTemp8));
			float fTempFTZ4 = (fVec3[1] - (((fTemp10 + (1.0f - fTemp5)) * (fRec4[1] - fTemp9)) / (fTemp5 + (1.0f - fTemp10))));
			fRec4[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp11 = ((0.00200000009f * fRec4[0]) + (0.998000026f * fRec4[1]));
			float fThen1 = (fSlow13 * float(tanhf(float((fSlow12 * fTemp11)))));
			float fElse1 = (fSlow15 * float(tanhf(float((fSlow14 * fTemp11)))));
			float fTempFTZ5 = (fSlow19 + (fConst17 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			iRec12[0] = ((1103515245 * iRec12[1]) + 12345);
			float fTemp12 = (4.65661287e-10f * float(iRec12[0]));
			float fTempFTZ6 = (fTemp12 - (fConst36 * ((((fConst42 * fRec11[1]) + (fConst43 * fRec11[2])) + (fConst44 * fRec11[3])) + (fConst45 * fRec11[4]))));
			fRec11[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fThen2 = std::max<float>(0.0f, (fRec14[1] + -1.0f));
			float fTempFTZ7 = (iTemp1 ? 150.0f : fThen2);
			fRec14[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			int iTemp13 = (fRec14[0] > 0.0f);
			iVec4[0] = iTemp13;
			iRec13[0] = (((iRec13[1] + (iRec13[1] > 0)) * (iTemp13 <= iVec4[1])) + (iTemp13 > iVec4[1]));
			float fTemp14 = float(iRec13[0]);
			fVec5[(IOTA & 8191)] = ((((fTemp11 > 0.0f) ? fElse1 : fThen1) * std::pow(0.00100000005f, (1.0f / (fTemp4 * std::max<float>(0.400000006f, (fSlow16 * (4.0f - (1.70000005f * std::max<float>(0.0f, std::min<float>(1.0f, (0.00138888892f * (fRec5[0] + -80.0f)))))))))))) + (fSlow18 * ((fRec10[0] * (((fConst35 * fRec11[2]) + (fConst26 * fRec11[0])) + (fConst26 * fRec11[4]))) * std::max<float>(0.0f, std::min<float>((fConst47 * fTemp14), (1.0f - (fConst48 * (fTemp14 - fConst46))))))));
			float fTempFTZ8 = fVec5[((IOTA - std::min<int>(16384, int(std::max<int>(0, int(iTemp6))))) & 8191)];
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp15 = std::fabs(fRec3[((IOTA - 0) & 2047)]);
			float fTempFTZ9 = std::max<float>(fTemp15, ((fConst49 * fRec15[1]) + (fConst50 * fTemp15)));
			fRec15[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp16 = (fRec16[1] + (fConst15 * fTemp3));
			float fTempFTZ10 = (fTemp16 - std::floor(fTemp16));
			fRec16[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp17 = std::max<float>(1.0f, ((fSlow20 * ((fRec15[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec16[0]))]) / fTemp4)) + 4.0f));
			float fTemp18 = (fTemp17 + 4.99999987e-06f);
			int iTemp19 = int(fTemp18);
			float fTemp20 = std::floor(fTemp18);
			float fTempFTZ11 = (fTemp12 - (fConst68 * ((((fConst73 * fRec19[1]) + (fConst74 * fRec19[2])) + (fConst75 * fRec19[3])) + (fConst76 * fRec19[4]))));
			fRec19[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			int iTemp21 = ((iSlow4 > iVec1[1]) | (iTemp0 & iSlow4));
			float fThen3 = std::max<float>(0.0f, (fRec21[1] + -1.0f));
			float fTempFTZ12 = (iTemp21 ? 150.0f : fThen3);
			fRec21[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			int iTemp22 = (fRec21[0] > 0.0f);
			iVec6[0] = iTemp22;
			iRec20[0] = (((iRec20[1] + (iRec20[1] > 0)) * (iTemp22 <= iVec6[1])) + (iTemp22 > iVec6[1]));
			float fTemp23 = float(iRec20[0]);
			float fTemp24 = (fSlow26 * (((((fConst67 * fRec19[2]) + (fConst58 * fRec19[0])) + (fConst58 * fRec19[4])) * std::max<float>(0.0f, std::min<float>((fConst47 * fTemp23), (1.0f - (fConst48 * (fTemp23 - fConst46)))))) * float(iTemp21)));
			float fTemp25 = fRec18[((IOTA - iSlow33) & 2047)];
			fVec7[0] = fTemp25;
			float fTempFTZ13 = (fVec7[1] - (fSlow35 * (fRec22[1] - fTemp25)));
			fRec22[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp26 = ((0.00200000009f * fRec22[0]) + (0.998000026f * fRec22[1]));
			float fThen4 = (fSlow37 * float(tanhf(float((fSlow36 * fTemp26)))));
			float fElse4 = (fSlow39 * float(tanhf(float((fSlow38 * fTemp26)))));
			fVec8[(IOTA & 2047)] = (fTemp24 + (fSlow28 * ((fTemp26 > 0.0f) ? fElse4 : fThen4)));
			float fTempFTZ14 = fVec8[((IOTA - iSlow40) & 2047)];
			fRec18[(IOTA & 2047)] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp27 = std::fabs(fRec18[((IOTA - 0) & 2047)]);
			float fTempFTZ15 = std::max<float>(fTemp27, ((fConst49 * fRec17[1]) + (fConst50 * fTemp27)));
			fRec17[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fSlow41 + (fRec23[1] - std::floor((fSlow41 + fRec23[1]))));
			fRec23[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp28 = std::max<float>(1.0f, ((fSlow25 * (fRec17[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec23[0]))])) + 4.0f));
			float fTemp29 = (fTemp28 + 4.99999987e-06f);
			float fTemp30 = std::floor(fTemp29);
			int iTemp31 = int(fTemp29);
			float fTemp32 = fRec25[((IOTA - iSlow50) & 2047)];
			fVec9[0] = fTemp32;
			float fTempFTZ17 = (fVec9[1] - (fSlow52 * (fRec26[1] - fTemp32)));
			fRec26[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp33 = ((0.00200000009f * fRec26[0]) + (0.998000026f * fRec26[1]));
			float fThen5 = (fSlow37 * float(tanhf(float((fSlow36 * fTemp33)))));
			float fElse5 = (fSlow39 * float(tanhf(float((fSlow38 * fTemp33)))));
			fVec10[(IOTA & 2047)] = (fTemp24 + (fSlow45 * ((fTemp33 > 0.0f) ? fElse5 : fThen5)));
			float fTempFTZ18 = fVec10[((IOTA - iSlow53) & 2047)];
			fRec25[(IOTA & 2047)] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp34 = std::fabs(fRec25[((IOTA - 0) & 2047)]);
			float fTempFTZ19 = std::max<float>(fTemp34, ((fConst49 * fRec24[1]) + (fConst50 * fTemp34)));
			fRec24[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fSlow54 + (fRec27[1] - std::floor((fSlow54 + fRec27[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp35 = std::max<float>(1.0f, ((fSlow44 * (fRec24[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec27[0]))])) + 4.0f));
			float fTemp36 = (fTemp35 + 4.99999987e-06f);
			float fTemp37 = std::floor(fTemp36);
			int iTemp38 = int(fTemp36);
			float fTemp39 = fRec29[((IOTA - iSlow64) & 2047)];
			fVec11[0] = fTemp39;
			float fTempFTZ21 = (fVec11[1] - (fSlow66 * (fRec30[1] - fTemp39)));
			fRec30[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp40 = ((0.00200000009f * fRec30[0]) + (0.998000026f * fRec30[1]));
			float fThen6 = (fSlow37 * float(tanhf(float((fSlow36 * fTemp40)))));
			float fElse6 = (fSlow39 * float(tanhf(float((fSlow38 * fTemp40)))));
			fVec12[(IOTA & 2047)] = (fTemp24 + (fSlow59 * ((fTemp40 > 0.0f) ? fElse6 : fThen6)));
			float fTempFTZ22 = fVec12[((IOTA - iSlow67) & 2047)];
			fRec29[(IOTA & 2047)] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTemp41 = std::fabs(fRec29[((IOTA - 0) & 2047)]);
			float fTempFTZ23 = std::max<float>(fTemp41, ((fConst49 * fRec28[1]) + (fConst50 * fTemp41)));
			fRec28[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fSlow68 + (fRec31[1] - std::floor((fSlow68 + fRec31[1]))));
			fRec31[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTemp42 = std::max<float>(1.0f, ((fSlow58 * (fRec28[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec31[0]))])) + 4.0f));
			float fTemp43 = (fTemp42 + 4.99999987e-06f);
			float fTemp44 = std::floor(fTemp43);
			int iTemp45 = int(fTemp43);
			float fTemp46 = fRec32[((IOTA - iSlow76) & 2047)];
			fVec13[0] = fTemp46;
			float fTempFTZ25 = (fVec13[1] - (fSlow78 * (fRec33[1] - fTemp46)));
			fRec33[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTemp47 = ((0.00200000009f * fRec33[0]) + (0.998000026f * fRec33[1]));
			float fThen7 = (fSlow37 * float(tanhf(float((fSlow36 * fTemp47)))));
			float fElse7 = (fSlow39 * float(tanhf(float((fSlow38 * fTemp47)))));
			fVec14[(IOTA & 2047)] = ((fSlow71 * ((fTemp47 > 0.0f) ? fElse7 : fThen7)) + fTemp24);
			float fTempFTZ26 = fVec14[((IOTA - iSlow79) & 2047)];
			fRec32[(IOTA & 2047)] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTemp48 = std::fabs(fRec32[((IOTA - 0) & 2047)]);
			float fTempFTZ27 = std::max<float>(fTemp48, ((fConst49 * fRec34[1]) + (fConst50 * fTemp48)));
			fRec34[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fSlow81 + (fRec35[1] - std::floor((fSlow81 + fRec35[1]))));
			fRec35[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTemp49 = std::max<float>(1.0f, ((fSlow80 * (fRec34[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec35[0]))])) + 4.0f));
			float fTemp50 = (fTemp49 + 4.99999987e-06f);
			int iTemp51 = int(fTemp50);
			float fTemp52 = std::floor(fTemp50);
			float fTemp53 = float(tanhf(float((2.0f * (((fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp19))))) & 2047)] * (0.0f - (fTemp17 + (-1.0f - fTemp20)))) + ((fTemp17 - fTemp20) * fRec3[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp19 + 1)))))) & 2047)])) + (fSlow21 * (((fTemp28 - fTemp30) * fRec18[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp31 + 1)))))) & 2047)]) + ((((fTemp35 - fTemp37) * fRec25[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp38 + 1)))))) & 2047)]) + ((((fTemp42 - fTemp44) * fRec29[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp45 + 1)))))) & 2047)]) + (((fRec32[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp51))))) & 2047)] * (0.0f - (fTemp49 + (-1.0f - fTemp52)))) + ((fTemp49 - fTemp52) * fRec32[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp51 + 1)))))) & 2047)])) + (fRec29[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp45))))) & 2047)] * (0.0f - (fTemp42 + (-1.0f - fTemp44)))))) + (fRec25[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp38))))) & 2047)] * (0.0f - (fTemp35 + (-1.0f - fTemp37)))))) + (fRec18[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp31))))) & 2047)] * (0.0f - (fTemp28 + (-1.0f - fTemp30))))))))))));
			float fTempFTZ29 = (fSlow83 + (fConst17 * fRec38[1]));
			fRec38[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = ((fSlow84 * fTemp53) - (fConst78 * ((fConst79 * fRec39[2]) + (fConst80 * fRec39[1]))));
			fRec39[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTemp54 = (fSlow82 * (fRec38[0] * (fRec39[2] + (fRec39[0] + (2.0f * fRec39[1])))));
			float fTemp55 = std::max<float>(40.0f, (fSlow85 * fTemp2));
			float fTemp56 = (fConst0 / fTemp55);
			int iTemp57 = int(fTemp56);
			float fTemp58 = float(iTemp57);
			float fTemp59 = (fTemp56 + (-0.499989986f - fTemp58));
			float fTemp60 = fRec37[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp59))) + 1)) & 2047)];
			fVec15[0] = fTemp60;
			float fTemp61 = (fTemp58 + std::floor(fTemp59));
			float fTempFTZ31 = (fVec15[1] - (((fTemp61 + (1.0f - fTemp56)) * (fRec40[1] - fTemp60)) / (fTemp56 + (1.0f - fTemp61))));
			fRec40[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTemp62 = ((0.00200000009f * fRec40[0]) + (0.998000026f * fRec40[1]));
			float fThen8 = (0.5f * float(tanhf(float((2.0f * fTemp62)))));
			float fElse8 = (0.909090936f * float(tanhf(float((1.10000002f * fTemp62)))));
			fVec16[(IOTA & 8191)] = (fTemp54 + (((fTemp62 > 0.0f) ? fElse8 : fThen8) * std::pow(0.00100000005f, (0.254452914f / fTemp55))));
			float fTempFTZ32 = fVec16[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp57))) & 8191)];
			fRec37[(IOTA & 2047)] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTemp63 = std::fabs(fRec37[((IOTA - 0) & 2047)]);
			float fTempFTZ33 = std::max<float>(fTemp63, ((fConst49 * fRec36[1]) + (fConst50 * fTemp63)));
			fRec36[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTemp64 = (fRec41[1] + (fSlow86 * fTemp2));
			float fTempFTZ34 = (fTemp64 - std::floor(fTemp64));
			fRec41[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTemp65 = std::max<float>(1.0f, ((67.5f * ((fRec36[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec41[0]))]) / fTemp55)) + 4.0f));
			float fTemp66 = (fTemp65 + 4.99999987e-06f);
			float fTemp67 = std::floor(fTemp66);
			int iTemp68 = int(fTemp66);
			float fTemp69 = std::max<float>(40.0f, (fSlow87 * fTemp2));
			float fTemp70 = (fConst0 / fTemp69);
			int iTemp71 = int(fTemp70);
			float fTemp72 = float(iTemp71);
			float fTemp73 = (fTemp70 + (-0.499989986f - fTemp72));
			float fTemp74 = fRec43[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp73))) + 1)) & 2047)];
			fVec17[0] = fTemp74;
			float fTemp75 = (fTemp72 + std::floor(fTemp73));
			float fTempFTZ35 = (fVec17[1] - (((fTemp75 + (1.0f - fTemp70)) * (fRec44[1] - fTemp74)) / (fTemp70 + (1.0f - fTemp75))));
			fRec44[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTemp76 = ((0.00200000009f * fRec44[0]) + (0.998000026f * fRec44[1]));
			float fThen9 = (0.5f * float(tanhf(float((2.0f * fTemp76)))));
			float fElse9 = (0.909090936f * float(tanhf(float((1.10000002f * fTemp76)))));
			fVec18[(IOTA & 8191)] = (fTemp54 + (((fTemp76 > 0.0f) ? fElse9 : fThen9) * std::pow(0.00100000005f, (0.254452914f / fTemp69))));
			float fTempFTZ36 = fVec18[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp71))) & 8191)];
			fRec43[(IOTA & 2047)] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTemp77 = std::fabs(fRec43[((IOTA - 0) & 2047)]);
			float fTempFTZ37 = std::max<float>(fTemp77, ((fConst49 * fRec42[1]) + (fConst50 * fTemp77)));
			fRec42[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTemp78 = (fRec45[1] + (fSlow88 * fTemp2));
			float fTempFTZ38 = (fTemp78 - std::floor(fTemp78));
			fRec45[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTemp79 = std::max<float>(1.0f, ((67.5f * ((fRec42[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec45[0]))]) / fTemp69)) + 4.0f));
			float fTemp80 = (fTemp79 + 4.99999987e-06f);
			float fTemp81 = std::floor(fTemp80);
			int iTemp82 = int(fTemp80);
			float fTemp83 = std::max<float>(40.0f, (fSlow89 * fTemp2));
			float fTemp84 = (fConst0 / fTemp83);
			int iTemp85 = int(fTemp84);
			float fTemp86 = float(iTemp85);
			float fTemp87 = (fTemp84 + (-0.499989986f - fTemp86));
			float fTemp88 = fRec46[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp87))) + 1)) & 2047)];
			fVec19[0] = fTemp88;
			float fTemp89 = (fTemp86 + std::floor(fTemp87));
			float fTempFTZ39 = (fVec19[1] - (((fTemp89 + (1.0f - fTemp84)) * (fRec47[1] - fTemp88)) / (fTemp84 + (1.0f - fTemp89))));
			fRec47[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTemp90 = ((0.00200000009f * fRec47[0]) + (0.998000026f * fRec47[1]));
			float fThen10 = (0.5f * float(tanhf(float((2.0f * fTemp90)))));
			float fElse10 = (0.909090936f * float(tanhf(float((1.10000002f * fTemp90)))));
			fVec20[(IOTA & 8191)] = ((((fTemp90 > 0.0f) ? fElse10 : fThen10) * std::pow(0.00100000005f, (0.254452914f / fTemp83))) + fTemp54);
			float fTempFTZ40 = fVec20[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp85))) & 8191)];
			fRec46[(IOTA & 2047)] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTemp91 = std::fabs(fRec46[((IOTA - 0) & 2047)]);
			float fTempFTZ41 = std::max<float>(fTemp91, ((fConst49 * fRec48[1]) + (fConst50 * fTemp91)));
			fRec48[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTemp92 = (fRec49[1] + (fSlow90 * fTemp2));
			float fTempFTZ42 = (fTemp92 - std::floor(fTemp92));
			fRec49[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTemp93 = std::max<float>(1.0f, ((67.5f * ((fRec48[0] * ftbl0FaustSarodDSPSIG0[int((65536.0f * fRec49[0]))]) / fTemp83)) + 4.0f));
			float fTemp94 = (fTemp93 + 4.99999987e-06f);
			int iTemp95 = int(fTemp94);
			float fTemp96 = std::floor(fTemp94);
			float fTemp97 = ((0.5f * fTemp53) + (0.150000006f * (((fTemp65 - fTemp67) * fRec37[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp68 + 1)))))) & 2047)]) + ((((fTemp79 - fTemp81) * fRec43[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp82 + 1)))))) & 2047)]) + (((fRec46[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp95))))) & 2047)] * (0.0f - (fTemp93 + (-1.0f - fTemp96)))) + ((fTemp93 - fTemp96) * fRec46[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp95 + 1)))))) & 2047)])) + (fRec43[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp82))))) & 2047)] * (0.0f - (fTemp79 + (-1.0f - fTemp81)))))) + (fRec37[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp68))))) & 2047)] * (0.0f - (fTemp65 + (-1.0f - fTemp67))))))));
			float fTempFTZ43 = (fTemp97 - (fConst81 * ((fConst82 * fRec2[2]) + (fConst83 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = (fTemp97 - (fConst89 * ((fConst90 * fRec50[2]) + (fConst91 * fRec50[1]))));
			fRec50[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = (fTemp97 - (fConst95 * ((fConst96 * fRec51[2]) + (fConst97 * fRec51[1]))));
			fRec51[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = (fTemp97 - (fConst103 * ((fConst104 * fRec52[2]) + (fConst105 * fRec52[1]))));
			fRec52[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = (fTemp97 - (fConst111 * ((fConst112 * fRec53[2]) + (fConst113 * fRec53[1]))));
			fRec53[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = (fTemp97 - (fConst119 * ((fConst120 * fRec54[2]) + (fConst121 * fRec54[1]))));
			fRec54[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = (fTemp97 - (fConst127 * ((fConst128 * fRec55[2]) + (fConst129 * fRec55[1]))));
			fRec55[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = (fTemp97 - (fConst135 * ((fConst136 * fRec56[2]) + (fConst137 * fRec56[1]))));
			fRec56[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTempFTZ51 = (fTemp97 - (fConst143 * ((fConst144 * fRec57[2]) + (fConst145 * fRec57[1]))));
			fRec57[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = (fTemp97 - (fConst151 * ((fConst152 * fRec58[2]) + (fConst153 * fRec58[1]))));
			fRec58[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = (fTemp97 - (fConst159 * ((fConst160 * fRec59[2]) + (fConst161 * fRec59[1]))));
			fRec59[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTempFTZ54 = (fTemp97 - (fConst167 * ((fConst168 * fRec60[2]) + (fConst169 * fRec60[1]))));
			fRec60[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fTempFTZ55 = (fTemp97 - (fConst175 * ((fConst176 * fRec61[2]) + (fConst177 * fRec61[1]))));
			fRec61[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fTempFTZ56 = (fTemp97 - (fConst183 * ((fConst184 * fRec62[2]) + (fConst185 * fRec62[1]))));
			fRec62[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fTempFTZ57 = (fTemp97 - (fConst192 * ((fConst193 * fRec63[2]) + (fConst194 * fRec63[1]))));
			fRec63[0] = ((std::fabs(fTempFTZ57) > 1.17549435e-38f) ? fTempFTZ57 : 0.0f);
			float fTempFTZ58 = (fTemp97 - (fConst200 * ((fConst201 * fRec64[2]) + (fConst202 * fRec64[1]))));
			fRec64[0] = ((std::fabs(fTempFTZ58) > 1.17549435e-38f) ? fTempFTZ58 : 0.0f);
			float fTempFTZ59 = (fTemp97 - (fConst208 * ((fConst209 * fRec65[2]) + (fConst210 * fRec65[1]))));
			fRec65[0] = ((std::fabs(fTempFTZ59) > 1.17549435e-38f) ? fTempFTZ59 : 0.0f);
			float fTempFTZ60 = (fTemp97 - (fConst219 * ((fConst220 * fRec66[2]) + (fConst221 * fRec66[1]))));
			fRec66[0] = ((std::fabs(fTempFTZ60) > 1.17549435e-38f) ? fTempFTZ60 : 0.0f);
			float fTempFTZ61 = (fTemp97 - (fConst227 * ((fConst228 * fRec67[2]) + (fConst229 * fRec67[1]))));
			fRec67[0] = ((std::fabs(fTempFTZ61) > 1.17549435e-38f) ? fTempFTZ61 : 0.0f);
			float fTempFTZ62 = (fTemp97 - (fConst235 * ((fConst236 * fRec68[2]) + (fConst237 * fRec68[1]))));
			fRec68[0] = ((std::fabs(fTempFTZ62) > 1.17549435e-38f) ? fTempFTZ62 : 0.0f);
			float fTempFTZ63 = (fTemp97 - (fConst243 * ((fConst244 * fRec69[2]) + (fConst245 * fRec69[1]))));
			fRec69[0] = ((std::fabs(fTempFTZ63) > 1.17549435e-38f) ? fTempFTZ63 : 0.0f);
			float fTempFTZ64 = (fTemp97 - (fConst251 * ((fConst252 * fRec70[2]) + (fConst253 * fRec70[1]))));
			fRec70[0] = ((std::fabs(fTempFTZ64) > 1.17549435e-38f) ? fTempFTZ64 : 0.0f);
			float fTempFTZ65 = (fTemp97 - (fConst259 * ((fConst260 * fRec71[2]) + (fConst261 * fRec71[1]))));
			fRec71[0] = ((std::fabs(fTempFTZ65) > 1.17549435e-38f) ? fTempFTZ65 : 0.0f);
			float fTempFTZ66 = (fTemp97 - (fConst267 * ((fConst268 * fRec72[2]) + (fConst269 * fRec72[1]))));
			fRec72[0] = ((std::fabs(fTempFTZ66) > 1.17549435e-38f) ? fTempFTZ66 : 0.0f);
			float fTempFTZ67 = (fTemp97 - (fConst275 * ((fConst276 * fRec73[2]) + (fConst277 * fRec73[1]))));
			fRec73[0] = ((std::fabs(fTempFTZ67) > 1.17549435e-38f) ? fTempFTZ67 : 0.0f);
			float fTempFTZ68 = (((fConst14 * fRec2[2]) + (((fConst88 * fRec50[2]) + (((fConst94 * fRec51[2]) + (((fConst102 * fRec52[2]) + (((0.150000006f * ((((((((((fTemp97 + (fConst110 * fRec53[0])) + (fConst118 * fRec54[0])) + (fConst126 * fRec55[0])) + (fConst134 * fRec56[0])) + (fConst142 * fRec57[0])) + (fConst150 * fRec58[0])) + (fConst158 * fRec59[0])) + (fConst166 * fRec60[0])) + (fConst174 * fRec61[0])) + (fConst182 * fRec62[0]))) + ((fConst186 * fRec62[2]) + ((0.119999997f * (((fConst191 * fRec63[0]) + (fConst199 * fRec64[0])) + (fConst207 * fRec65[0]))) + ((fConst211 * fRec65[2]) + ((fConst212 * fRec61[2]) + ((fConst213 * fRec64[2]) + ((((((((((fConst214 * fRec53[2]) + ((0.25f * ((((((((fConst218 * fRec66[0]) + (fConst226 * fRec67[0])) + (fConst234 * fRec68[0])) + (fConst242 * fRec69[0])) + (fConst250 * fRec70[0])) + (fConst258 * fRec71[0])) + (fConst266 * fRec72[0])) + (fConst274 * fRec73[0]))) + ((fConst278 * fRec73[2]) + ((fConst279 * fRec72[2]) + ((fConst280 * fRec71[2]) + ((fConst281 * fRec70[2]) + ((fConst282 * fRec69[2]) + ((fConst283 * fRec68[2]) + ((fConst284 * fRec66[2]) + (fConst285 * fRec67[2])))))))))) + (fConst286 * fRec54[2])) + (fConst287 * fRec55[2])) + (fConst288 * fRec56[2])) + (fConst289 * fRec57[2])) + (fConst290 * fRec58[2])) + (fConst291 * fRec59[2])) + (fConst292 * fRec60[2])) + (fConst293 * fRec63[2])))))))) + (fConst101 * fRec52[0]))) + (fConst93 * fRec51[0]))) + (fConst87 * fRec50[0]))) + (fConst13 * fRec2[0]))) - (fConst9 * ((fConst294 * fRec1[2]) + (fConst295 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ68) > 1.17549435e-38f) ? fTempFTZ68 : 0.0f);
			float fTemp98 = (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1])));
			float fTemp99 = (fConst9 * fTemp98);
			float fTempFTZ69 = (fTemp99 - (fConst296 * ((fConst297 * fRec0[2]) + (fConst97 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ69) > 1.17549435e-38f) ? fTempFTZ69 : 0.0f);
			float fTempFTZ70 = (fTemp99 - (fConst301 * ((fConst302 * fRec74[2]) + (fConst105 * fRec74[1]))));
			fRec74[0] = ((std::fabs(fTempFTZ70) > 1.17549435e-38f) ? fTempFTZ70 : 0.0f);
			float fTempFTZ71 = (fTemp99 - (fConst308 * ((fConst309 * fRec75[2]) + (fConst310 * fRec75[1]))));
			fRec75[0] = ((std::fabs(fTempFTZ71) > 1.17549435e-38f) ? fTempFTZ71 : 0.0f);
			float fTempFTZ72 = (fTemp99 - (fConst316 * ((fConst317 * fRec76[2]) + (fConst318 * fRec76[1]))));
			fRec76[0] = ((std::fabs(fTempFTZ72) > 1.17549435e-38f) ? fTempFTZ72 : 0.0f);
			float fTempFTZ73 = (fTemp99 - (fConst324 * ((fConst325 * fRec77[2]) + (fConst326 * fRec77[1]))));
			fRec77[0] = ((std::fabs(fTempFTZ73) > 1.17549435e-38f) ? fTempFTZ73 : 0.0f);
			float fTempFTZ74 = (fTemp99 - (fConst332 * ((fConst333 * fRec78[2]) + (fConst334 * fRec78[1]))));
			fRec78[0] = ((std::fabs(fTempFTZ74) > 1.17549435e-38f) ? fTempFTZ74 : 0.0f);
			float fTempFTZ75 = (fTemp99 - (fConst340 * ((fConst341 * fRec79[2]) + (fConst342 * fRec79[1]))));
			fRec79[0] = ((std::fabs(fTempFTZ75) > 1.17549435e-38f) ? fTempFTZ75 : 0.0f);
			float fTemp100 = ((fConst5 * fRec0[2]) + (((fConst300 * fRec74[2]) + (((fConst307 * fRec75[2]) + (((fConst315 * fRec76[2]) + (((fConst323 * fRec77[2]) + (((fConst331 * fRec78[2]) + (((fConst339 * fRec79[2]) + ((fConst343 * fTemp98) + (fConst338 * fRec79[0]))) + (fConst330 * fRec78[0]))) + (fConst322 * fRec77[0]))) + (fConst314 * fRec76[0]))) + (fConst306 * fRec75[0]))) + (fConst299 * fRec74[0]))) + (fConst4 * fRec0[0])));
			float fTemp101 = (fSlow1 * fTemp100);
			float fThen11 = (0.899999976f * float(tanhf(float((fSlow91 * fTemp100)))));
			float fTemp102 = ((std::fabs(fTemp101) < 0.899999976f) ? fTemp101 : fThen11);
			output0[i0] = FAUSTFLOAT(fTemp102);
			output1[i0] = FAUSTFLOAT(fTemp102);
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fVec3[1] = fVec3[0];
			fRec4[1] = fRec4[0];
			fRec10[1] = fRec10[0];
			iRec12[1] = iRec12[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec11[j0] = fRec11[(j0 - 1)];
			}
			fRec14[1] = fRec14[0];
			iVec4[1] = iVec4[0];
			iRec13[1] = iRec13[0];
			IOTA = (IOTA + 1);
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			for (int j1 = 4; (j1 > 0); j1 = (j1 - 1)) {
				fRec19[j1] = fRec19[(j1 - 1)];
			}
			fRec21[1] = fRec21[0];
			iVec6[1] = iVec6[0];
			iRec20[1] = iRec20[0];
			fVec7[1] = fVec7[0];
			fRec22[1] = fRec22[0];
			fRec17[1] = fRec17[0];
			fRec23[1] = fRec23[0];
			fVec9[1] = fVec9[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			fVec11[1] = fVec11[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec31[1] = fRec31[0];
			fVec13[1] = fVec13[0];
			fRec33[1] = fRec33[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fVec15[1] = fVec15[0];
			fRec40[1] = fRec40[0];
			fRec36[1] = fRec36[0];
			fRec41[1] = fRec41[0];
			fVec17[1] = fVec17[0];
			fRec44[1] = fRec44[0];
			fRec42[1] = fRec42[0];
			fRec45[1] = fRec45[0];
			fVec19[1] = fVec19[0];
			fRec47[1] = fRec47[0];
			fRec48[1] = fRec48[0];
			fRec49[1] = fRec49[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			fRec75[2] = fRec75[1];
			fRec75[1] = fRec75[0];
			fRec76[2] = fRec76[1];
			fRec76[1] = fRec76[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
		}
	}

};

#endif
