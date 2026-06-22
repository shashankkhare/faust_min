/* ------------------------------------------------------------
author: "Shashank Khare"
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tibetanBowl"
version: "1.0"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTibetanbowlDSP_H__
#define  __FaustTibetanbowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustTibetanbowlDSPSIG0 {
	
  private:
	
	int iVec15[2];
	int iRec54[2];
	
  public:
	
	int getNumInputsFaustTibetanbowlDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTibetanbowlDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTibetanbowlDSPSIG0(int sample_rate) {
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			iVec15[l59] = 0;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			iRec54[l60] = 0;
		}
	}
	
	void fillFaustTibetanbowlDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec15[0] = 1;
			iRec54[0] = ((iVec15[1] + iRec54[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec54[0])));
			iVec15[1] = iVec15[0];
			iRec54[1] = iRec54[0];
		}
	}

};

static FaustTibetanbowlDSPSIG0* newFaustTibetanbowlDSPSIG0() { return (FaustTibetanbowlDSPSIG0*)new FaustTibetanbowlDSPSIG0(); }
static void deleteFaustTibetanbowlDSPSIG0(FaustTibetanbowlDSPSIG0* dsp) { delete dsp; }

static float FaustTibetanbowlDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustTibetanbowlDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}
static float ftbl0FaustTibetanbowlDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTibetanbowlDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTibetanbowlDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fEntry0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst4;
	FAUSTFLOAT fHslider0;
	float fConst5;
	float fConst7;
	float fConst8;
	float fRec11[2];
	float fRec10[2];
	int IOTA;
	float fVec0[32768];
	int iConst10;
	FAUSTFLOAT fHslider1;
	float fConst11;
	FAUSTFLOAT fHslider2;
	float fConst12;
	float fRec12[2];
	FAUSTFLOAT fEntry1;
	float fConst14;
	float fConst15;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fVec1[2];
	float fRec27[2];
	FAUSTFLOAT fHslider5;
	float fConst16;
	float fConst17;
	float fRec28[2];
	int iRec29[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fConst18;
	float fRec30[2];
	float fVec2[2048];
	FAUSTFLOAT fEntry2;
	float fConst19;
	float fConst20;
	float fRec26[3];
	float fRec25[2];
	float fRec13[2];
	float fVec3[1024];
	float fConst21;
	float fConst22;
	float fRec32[3];
	float fRec31[2];
	float fRec14[2];
	float fVec4[512];
	float fConst23;
	float fConst24;
	float fRec34[3];
	float fRec33[2];
	float fRec15[2];
	float fVec5[512];
	float fConst25;
	float fConst26;
	float fRec36[3];
	float fRec35[2];
	float fRec16[2];
	float fVec6[256];
	float fConst27;
	float fConst28;
	float fRec38[3];
	float fRec37[2];
	float fRec17[2];
	float fVec7[256];
	float fConst29;
	float fConst30;
	float fRec40[3];
	float fRec39[2];
	float fRec18[2];
	float fVec8[128];
	float fConst31;
	float fConst32;
	float fRec42[3];
	float fRec41[2];
	float fRec19[2];
	float fVec9[128];
	float fConst33;
	float fConst34;
	float fRec44[3];
	float fRec43[2];
	float fRec20[2];
	float fVec10[128];
	float fConst35;
	float fConst36;
	float fRec46[3];
	float fRec45[2];
	float fRec21[2];
	float fVec11[64];
	float fConst37;
	float fConst38;
	float fRec48[3];
	float fRec47[2];
	float fRec22[2];
	float fVec12[64];
	float fConst39;
	float fConst40;
	float fRec50[3];
	float fRec49[2];
	float fRec23[2];
	float fVec13[64];
	float fConst41;
	float fConst42;
	float fRec52[3];
	float fRec51[2];
	float fRec24[2];
	float fVec14[2];
	FAUSTFLOAT fHslider8;
	float fRec53[2];
	float fConst43;
	FAUSTFLOAT fHslider9;
	float fRec56[2];
	float fRec55[2];
	float fRec62[2];
	float fRec61[2];
	float fRec60[2];
	float fRec59[2];
	float fRec58[2];
	float fRec57[2];
	float fRec68[2];
	float fRec67[2];
	float fRec66[2];
	float fRec65[2];
	float fRec64[2];
	float fRec63[2];
	float fVec16[1024];
	FAUSTFLOAT fHslider10;
	float fVec17[4096];
	int iConst44;
	float fVec18[2048];
	int iConst45;
	float fRec8[2];
	float fConst48;
	float fConst49;
	float fRec72[2];
	float fRec71[2];
	float fVec19[32768];
	int iConst51;
	float fVec20[4096];
	int iConst52;
	float fRec69[2];
	float fConst55;
	float fConst56;
	float fRec76[2];
	float fRec75[2];
	float fVec21[16384];
	int iConst58;
	float fVec22[4096];
	int iConst59;
	float fRec73[2];
	float fConst62;
	float fConst63;
	float fRec80[2];
	float fRec79[2];
	float fVec23[32768];
	int iConst65;
	float fVec24[4096];
	int iConst66;
	float fRec77[2];
	float fConst69;
	float fConst70;
	float fRec84[2];
	float fRec83[2];
	float fVec25[16384];
	int iConst72;
	float fVec26[4096];
	float fVec27[2048];
	int iConst73;
	float fRec81[2];
	float fConst76;
	float fConst77;
	float fRec88[2];
	float fRec87[2];
	float fVec28[16384];
	int iConst79;
	float fVec29[4096];
	int iConst80;
	float fRec85[2];
	float fConst83;
	float fConst84;
	float fRec92[2];
	float fRec91[2];
	float fVec30[16384];
	int iConst86;
	float fVec31[4096];
	int iConst87;
	float fRec89[2];
	float fConst90;
	float fConst91;
	float fRec96[2];
	float fRec95[2];
	float fVec32[16384];
	int iConst93;
	float fVec33[2048];
	int iConst94;
	float fRec93[2];
	float fRec0[3];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Shashank Khare");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "Banded Waveguide Tibetan Bowl");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "tibetanbowl.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("instruments.lib/author", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("instruments.lib/copyright", "Romain Michon");
		m->declare("instruments.lib/licence", "STK-4.3");
		m->declare("instruments.lib/name", "Faust-STK Tools Library");
		m->declare("instruments.lib/version", "1.0");
		m->declare("licence", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tibetanBowl");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.1");
		m->declare("version", "1.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		FaustTibetanbowlDSPSIG0* sig0 = newFaustTibetanbowlDSPSIG0();
		sig0->instanceInitFaustTibetanbowlDSPSIG0(sample_rate);
		sig0->fillFaustTibetanbowlDSPSIG0(65536, ftbl0FaustTibetanbowlDSPSIG0);
		deleteFaustTibetanbowlDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::cos((37699.1133f / fConst0));
		float fConst2 = std::floor(((0.219990999f * fConst0) + 0.5f));
		float fConst3 = ((0.0f - (6.90775537f * fConst2)) / fConst0);
		fConst4 = (0.5f * fConst3);
		fConst5 = (0.333333343f * fConst3);
		float fConst6 = (1.0f / std::tan((628.318542f / fConst0)));
		fConst7 = (1.0f / (fConst6 + 1.0f));
		fConst8 = (1.0f - fConst6);
		float fConst9 = std::floor(((0.0191229992f * fConst0) + 0.5f));
		iConst10 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst2 - fConst9))));
		fConst11 = (44.0999985f / fConst0);
		fConst12 = (1.0f - fConst11);
		float fConst13 = (1.0f - (100.530968f / fConst0));
		fConst14 = FaustTibetanbowlDSP_faustpower2_f(fConst13);
		fConst15 = (0.5f * (1.0f - fConst14));
		fConst16 = (0.5f * fConst0);
		fConst17 = (1.0f / std::max<float>(1.0f, fConst16));
		fConst18 = std::exp((0.0f - (66.6666641f / fConst0)));
		fConst19 = (0.0f - (2.0f * fConst13));
		fConst20 = (6.28318548f / fConst0);
		fConst21 = (0.370370358f * fConst0);
		fConst22 = (16.9645996f / fConst0);
		fConst23 = (0.208333328f * fConst0);
		fConst24 = (30.1592903f / fConst0);
		fConst25 = (0.13333334f * fConst0);
		fConst26 = (47.1238899f / fConst0);
		fConst27 = (0.094339624f * fConst0);
		fConst28 = (66.6017609f / fConst0);
		fConst29 = (0.0704225376f * fConst0);
		fConst30 = (89.2212296f / fConst0);
		fConst31 = (0.0549450554f * fConst0);
		fConst32 = (114.353973f / fConst0);
		fConst33 = (0.0440528616f * fConst0);
		fConst34 = (142.628311f / fConst0);
		fConst35 = (0.0361010842f * fConst0);
		fConst36 = (174.044235f / fConst0);
		fConst37 = (0.0301204827f * fConst0);
		fConst38 = (208.601746f / fConst0);
		fConst39 = (0.025510205f * fConst0);
		fConst40 = (246.300858f / fConst0);
		fConst41 = (0.0218818374f * fConst0);
		fConst42 = (287.141571f / fConst0);
		fConst43 = (1.0f / fConst0);
		iConst44 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (0.0199999996f * fConst0))));
		iConst45 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst9 + -1.0f))));
		float fConst46 = std::floor(((0.256891012f * fConst0) + 0.5f));
		float fConst47 = ((0.0f - (6.90775537f * fConst46)) / fConst0);
		fConst48 = (0.5f * fConst47);
		fConst49 = (0.333333343f * fConst47);
		float fConst50 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		iConst51 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst46 - fConst50))));
		iConst52 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst50 + -1.0f))));
		float fConst53 = std::floor(((0.192303002f * fConst0) + 0.5f));
		float fConst54 = ((0.0f - (6.90775537f * fConst53)) / fConst0);
		fConst55 = (0.5f * fConst54);
		fConst56 = (0.333333343f * fConst54);
		float fConst57 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		iConst58 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst53 - fConst57))));
		iConst59 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst57 + -1.0f))));
		float fConst60 = std::floor(((0.210389003f * fConst0) + 0.5f));
		float fConst61 = ((0.0f - (6.90775537f * fConst60)) / fConst0);
		fConst62 = (0.5f * fConst61);
		fConst63 = (0.333333343f * fConst61);
		float fConst64 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		iConst65 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst60 - fConst64))));
		iConst66 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst64 + -1.0f))));
		float fConst67 = std::floor(((0.125f * fConst0) + 0.5f));
		float fConst68 = ((0.0f - (6.90775537f * fConst67)) / fConst0);
		fConst69 = (0.5f * fConst68);
		fConst70 = (0.333333343f * fConst68);
		float fConst71 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		iConst72 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst67 - fConst71))));
		iConst73 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst71 + -1.0f))));
		float fConst74 = std::floor(((0.127837002f * fConst0) + 0.5f));
		float fConst75 = ((0.0f - (6.90775537f * fConst74)) / fConst0);
		fConst76 = (0.5f * fConst75);
		fConst77 = (0.333333343f * fConst75);
		float fConst78 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		iConst79 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst74 - fConst78))));
		iConst80 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst78 + -1.0f))));
		float fConst81 = std::floor(((0.174713001f * fConst0) + 0.5f));
		float fConst82 = ((0.0f - (6.90775537f * fConst81)) / fConst0);
		fConst83 = (0.5f * fConst82);
		fConst84 = (0.333333343f * fConst82);
		float fConst85 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		iConst86 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst81 - fConst85))));
		iConst87 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst85 + -1.0f))));
		float fConst88 = std::floor(((0.153128996f * fConst0) + 0.5f));
		float fConst89 = ((0.0f - (6.90775537f * fConst88)) / fConst0);
		fConst90 = (0.5f * fConst89);
		fConst91 = (0.333333343f * fConst89);
		float fConst92 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		iConst93 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst88 - fConst92))));
		iConst94 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst92 + -1.0f))));
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider0 = FAUSTFLOAT(0.71999999999999997f);
		fHslider1 = FAUSTFLOAT(0.59999999999999998f);
		fHslider2 = FAUSTFLOAT(0.13700000000000001f);
		fEntry1 = FAUSTFLOAT(100.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.80000000000000004f);
		fHslider6 = FAUSTFLOAT(1.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fEntry2 = FAUSTFLOAT(400.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(220.0f);
		fHslider10 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec11[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec10[l1] = 0.0f;
		}
		IOTA = 0;
		for (int l2 = 0; (l2 < 32768); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec12[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec27[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec28[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec29[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec30[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2048); l9 = (l9 + 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec26[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec25[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 1024); l13 = (l13 + 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec32[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec31[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 512); l17 = (l17 + 1)) {
			fVec4[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec34[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec33[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec15[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 512); l21 = (l21 + 1)) {
			fVec5[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec36[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec35[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec16[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 256); l25 = (l25 + 1)) {
			fVec6[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec38[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec37[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec17[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 256); l29 = (l29 + 1)) {
			fVec7[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec40[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec39[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec18[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 128); l33 = (l33 + 1)) {
			fVec8[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec42[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec41[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec19[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 128); l37 = (l37 + 1)) {
			fVec9[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec44[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec43[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec20[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 128); l41 = (l41 + 1)) {
			fVec10[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec46[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec45[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec21[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 64); l45 = (l45 + 1)) {
			fVec11[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec48[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec47[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec22[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 64); l49 = (l49 + 1)) {
			fVec12[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec50[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec49[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec23[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 64); l53 = (l53 + 1)) {
			fVec13[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec52[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec51[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec24[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fVec14[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec53[l58] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec56[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec55[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec62[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec61[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec60[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec59[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec58[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec57[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec68[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec67[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec66[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec65[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec64[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec63[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 1024); l75 = (l75 + 1)) {
			fVec16[l75] = 0.0f;
		}
		for (int l76 = 0; (l76 < 4096); l76 = (l76 + 1)) {
			fVec17[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 2048); l77 = (l77 + 1)) {
			fVec18[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec8[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec72[l79] = 0.0f;
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec71[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 32768); l81 = (l81 + 1)) {
			fVec19[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 4096); l82 = (l82 + 1)) {
			fVec20[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec69[l83] = 0.0f;
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec76[l84] = 0.0f;
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec75[l85] = 0.0f;
		}
		for (int l86 = 0; (l86 < 16384); l86 = (l86 + 1)) {
			fVec21[l86] = 0.0f;
		}
		for (int l87 = 0; (l87 < 4096); l87 = (l87 + 1)) {
			fVec22[l87] = 0.0f;
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec73[l88] = 0.0f;
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec80[l89] = 0.0f;
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec79[l90] = 0.0f;
		}
		for (int l91 = 0; (l91 < 32768); l91 = (l91 + 1)) {
			fVec23[l91] = 0.0f;
		}
		for (int l92 = 0; (l92 < 4096); l92 = (l92 + 1)) {
			fVec24[l92] = 0.0f;
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec77[l93] = 0.0f;
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec84[l94] = 0.0f;
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec83[l95] = 0.0f;
		}
		for (int l96 = 0; (l96 < 16384); l96 = (l96 + 1)) {
			fVec25[l96] = 0.0f;
		}
		for (int l97 = 0; (l97 < 4096); l97 = (l97 + 1)) {
			fVec26[l97] = 0.0f;
		}
		for (int l98 = 0; (l98 < 2048); l98 = (l98 + 1)) {
			fVec27[l98] = 0.0f;
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec81[l99] = 0.0f;
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec88[l100] = 0.0f;
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec87[l101] = 0.0f;
		}
		for (int l102 = 0; (l102 < 16384); l102 = (l102 + 1)) {
			fVec28[l102] = 0.0f;
		}
		for (int l103 = 0; (l103 < 4096); l103 = (l103 + 1)) {
			fVec29[l103] = 0.0f;
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec85[l104] = 0.0f;
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec92[l105] = 0.0f;
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec91[l106] = 0.0f;
		}
		for (int l107 = 0; (l107 < 16384); l107 = (l107 + 1)) {
			fVec30[l107] = 0.0f;
		}
		for (int l108 = 0; (l108 < 4096); l108 = (l108 + 1)) {
			fVec31[l108] = 0.0f;
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec89[l109] = 0.0f;
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec96[l110] = 0.0f;
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec95[l111] = 0.0f;
		}
		for (int l112 = 0; (l112 < 16384); l112 = (l112 + 1)) {
			fVec32[l112] = 0.0f;
		}
		for (int l113 = 0; (l113 < 2048); l113 = (l113 + 1)) {
			fVec33[l113] = 0.0f;
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec93[l114] = 0.0f;
		}
		for (int l115 = 0; (l115 < 3); l115 = (l115 + 1)) {
			fRec0[l115] = 0.0f;
		}
		for (int l116 = 0; (l116 < 3); l116 = (l116 + 1)) {
			fRec1[l116] = 0.0f;
		}
		for (int l117 = 0; (l117 < 3); l117 = (l117 + 1)) {
			fRec2[l117] = 0.0f;
		}
		for (int l118 = 0; (l118 < 3); l118 = (l118 + 1)) {
			fRec3[l118] = 0.0f;
		}
		for (int l119 = 0; (l119 < 3); l119 = (l119 + 1)) {
			fRec4[l119] = 0.0f;
		}
		for (int l120 = 0; (l120 < 3); l120 = (l120 + 1)) {
			fRec5[l120] = 0.0f;
		}
		for (int l121 = 0; (l121 < 3); l121 = (l121 + 1)) {
			fRec6[l121] = 0.0f;
		}
		for (int l122 = 0; (l122 < 3); l122 = (l122 + 1)) {
			fRec7[l122] = 0.0f;
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
	
	virtual FaustTibetanbowlDSP* clone() {
		return new FaustTibetanbowlDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tibetanBowl");
		ui_interface->openHorizontalBox("Physical_and_Nonlinearity");
		ui_interface->openVerticalBox("Nonlinear_Filter_Parameters");
		ui_interface->declare(&fHslider9, "3", "");
		ui_interface->declare(&fHslider9, "tooltip", "Sine modulation frequency (works if Modulation Type=3)");
		ui_interface->declare(&fHslider9, "unit", "Hz");
		ui_interface->addHorizontalSlider("Modulation_Frequency", &fHslider9, FAUSTFLOAT(220.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fEntry1, "3", "");
		ui_interface->declare(&fEntry1, "tooltip", "0=theta modulated by signal; 1=averaged signal; 2=squared signal; 3=sine freqMod; 4=sine freq");
		ui_interface->addNumEntry("Modulation_Type", &fEntry1, FAUSTFLOAT(100.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider8, "3", "");
		ui_interface->declare(&fHslider8, "tooltip", "Nonlinearity factor (0 to 1)");
		ui_interface->addHorizontalSlider("Nonlinearity", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Physical_Parameters");
		ui_interface->declare(&fHslider6, "2", "");
		ui_interface->declare(&fHslider6, "tooltip", "A value between 0 and 1");
		ui_interface->addHorizontalSlider("Base_Gain", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider7, "2", "");
		ui_interface->declare(&fHslider7, "tooltip", "A value between 0 and 1");
		ui_interface->addHorizontalSlider("Integration_Constant", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Reverb");
		ui_interface->addHorizontalSlider("reverbGain", &fHslider2, FAUSTFLOAT(0.136999995f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("roomSize", &fHslider0, FAUSTFLOAT(0.720000029f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Spat");
		ui_interface->addHorizontalSlider("pan angle", &fHslider1, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("spatial width", &fHslider10, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
		ui_interface->addNumEntry("freq", &fEntry2, FAUSTFLOAT(400.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(1.0f));
		ui_interface->addNumEntry("gain", &fEntry0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gate", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("strike", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider5, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (2.5f * float(fEntry0));
		float fSlow1 = float(fHslider0);
		float fSlow2 = std::exp((fConst4 / fSlow1));
		float fSlow3 = FaustTibetanbowlDSP_faustpower2_f(fSlow2);
		float fSlow4 = (1.0f - (fConst1 * fSlow3));
		float fSlow5 = (1.0f - fSlow3);
		float fSlow6 = (fSlow4 / fSlow5);
		float fSlow7 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow4) / FaustTibetanbowlDSP_faustpower2_f(fSlow5)) + -1.0f)));
		float fSlow8 = (fSlow6 - fSlow7);
		float fSlow9 = (fSlow2 * (fSlow7 + (1.0f - fSlow6)));
		float fSlow10 = ((std::exp((fConst5 / fSlow1)) / fSlow2) + -1.0f);
		float fSlow11 = float(fHslider1);
		float fSlow12 = (fConst11 * float(fHslider2));
		float fSlow13 = float(fEntry1);
		float fSlow14 = float((fSlow13 >= 3.0f));
		float fSlow15 = float(fHslider3);
		float fSlow16 = (0.0833333358f * fSlow15);
		float fSlow17 = float(fHslider4);
		float fSlow18 = (fConst11 * fSlow17);
		float fSlow19 = float(fHslider5);
		float fSlow20 = ((0.200000003f * fSlow19) + 0.0299999993f);
		int iSlow21 = (fSlow17 == 0.0f);
		float fSlow22 = ((0.100000001f * float(fHslider6)) + 0.899999976f);
		float fSlow23 = float(fHslider7);
		float fSlow24 = (10.0f - (9.0f * fSlow19));
		float fSlow25 = (1.0f - fSlow15);
		float fSlow26 = float(fEntry2);
		int iSlow27 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst0 / fSlow26))));
		float fSlow28 = (fConst19 * std::cos((fConst20 * fSlow26)));
		float fSlow29 = (0.800000012f * fSlow25);
		int iSlow30 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst21 / fSlow26))));
		float fSlow31 = (fConst19 * std::cos((fConst22 * fSlow26)));
		float fSlow32 = (0.600000024f * fSlow25);
		int iSlow33 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst23 / fSlow26))));
		float fSlow34 = (fConst19 * std::cos((fConst24 * fSlow26)));
		int iSlow35 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst25 / fSlow26))));
		float fSlow36 = (fConst19 * std::cos((fConst26 * fSlow26)));
		int iSlow37 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst27 / fSlow26))));
		float fSlow38 = (fConst19 * std::cos((fConst28 * fSlow26)));
		int iSlow39 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst29 / fSlow26))));
		float fSlow40 = (fConst19 * std::cos((fConst30 * fSlow26)));
		int iSlow41 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst31 / fSlow26))));
		float fSlow42 = (fConst19 * std::cos((fConst32 * fSlow26)));
		int iSlow43 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst33 / fSlow26))));
		float fSlow44 = (fConst19 * std::cos((fConst34 * fSlow26)));
		float fSlow45 = (0.400000006f * fSlow25);
		int iSlow46 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst35 / fSlow26))));
		float fSlow47 = (fConst19 * std::cos((fConst36 * fSlow26)));
		int iSlow48 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst37 / fSlow26))));
		float fSlow49 = (fConst19 * std::cos((fConst38 * fSlow26)));
		int iSlow50 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst39 / fSlow26))));
		float fSlow51 = (fConst19 * std::cos((fConst40 * fSlow26)));
		int iSlow52 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst41 / fSlow26))));
		float fSlow53 = (fConst19 * std::cos((fConst42 * fSlow26)));
		float fSlow54 = (fConst11 * float(fHslider8));
		float fSlow55 = (fSlow26 * float((fSlow13 == 4.0f)));
		float fSlow56 = float((fSlow13 != 4.0f));
		float fSlow57 = (fConst11 * float(fHslider9));
		float fSlow58 = float((fSlow13 < 3.0f));
		float fSlow59 = (3.14159274f * float((fSlow13 == 0.0f)));
		float fSlow60 = (1.57079637f * float((fSlow13 == 1.0f)));
		float fSlow61 = (3.14159274f * float((fSlow13 == 2.0f)));
		int iSlow62 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst16 * (float(fHslider10) / fSlow26)))));
		float fSlow63 = std::exp((fConst48 / fSlow1));
		float fSlow64 = FaustTibetanbowlDSP_faustpower2_f(fSlow63);
		float fSlow65 = (1.0f - (fConst1 * fSlow64));
		float fSlow66 = (1.0f - fSlow64);
		float fSlow67 = (fSlow65 / fSlow66);
		float fSlow68 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow65) / FaustTibetanbowlDSP_faustpower2_f(fSlow66)) + -1.0f)));
		float fSlow69 = (fSlow67 - fSlow68);
		float fSlow70 = (fSlow63 * (fSlow68 + (1.0f - fSlow67)));
		float fSlow71 = ((std::exp((fConst49 / fSlow1)) / fSlow63) + -1.0f);
		float fSlow72 = std::exp((fConst55 / fSlow1));
		float fSlow73 = FaustTibetanbowlDSP_faustpower2_f(fSlow72);
		float fSlow74 = (1.0f - (fConst1 * fSlow73));
		float fSlow75 = (1.0f - fSlow73);
		float fSlow76 = (fSlow74 / fSlow75);
		float fSlow77 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow74) / FaustTibetanbowlDSP_faustpower2_f(fSlow75)) + -1.0f)));
		float fSlow78 = (fSlow76 - fSlow77);
		float fSlow79 = (fSlow72 * (fSlow77 + (1.0f - fSlow76)));
		float fSlow80 = ((std::exp((fConst56 / fSlow1)) / fSlow72) + -1.0f);
		float fSlow81 = std::exp((fConst62 / fSlow1));
		float fSlow82 = FaustTibetanbowlDSP_faustpower2_f(fSlow81);
		float fSlow83 = (1.0f - (fConst1 * fSlow82));
		float fSlow84 = (1.0f - fSlow82);
		float fSlow85 = (fSlow83 / fSlow84);
		float fSlow86 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow83) / FaustTibetanbowlDSP_faustpower2_f(fSlow84)) + -1.0f)));
		float fSlow87 = (fSlow85 - fSlow86);
		float fSlow88 = (fSlow81 * (fSlow86 + (1.0f - fSlow85)));
		float fSlow89 = ((std::exp((fConst63 / fSlow1)) / fSlow81) + -1.0f);
		float fSlow90 = std::exp((fConst69 / fSlow1));
		float fSlow91 = FaustTibetanbowlDSP_faustpower2_f(fSlow90);
		float fSlow92 = (1.0f - (fConst1 * fSlow91));
		float fSlow93 = (1.0f - fSlow91);
		float fSlow94 = (fSlow92 / fSlow93);
		float fSlow95 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow92) / FaustTibetanbowlDSP_faustpower2_f(fSlow93)) + -1.0f)));
		float fSlow96 = (fSlow94 - fSlow95);
		float fSlow97 = (fSlow90 * (fSlow95 + (1.0f - fSlow94)));
		float fSlow98 = ((std::exp((fConst70 / fSlow1)) / fSlow90) + -1.0f);
		float fSlow99 = (1.0f - fSlow11);
		float fSlow100 = std::exp((fConst76 / fSlow1));
		float fSlow101 = FaustTibetanbowlDSP_faustpower2_f(fSlow100);
		float fSlow102 = (1.0f - (fConst1 * fSlow101));
		float fSlow103 = (1.0f - fSlow101);
		float fSlow104 = (fSlow102 / fSlow103);
		float fSlow105 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow102) / FaustTibetanbowlDSP_faustpower2_f(fSlow103)) + -1.0f)));
		float fSlow106 = (fSlow104 - fSlow105);
		float fSlow107 = (fSlow100 * (fSlow105 + (1.0f - fSlow104)));
		float fSlow108 = ((std::exp((fConst77 / fSlow1)) / fSlow100) + -1.0f);
		float fSlow109 = std::exp((fConst83 / fSlow1));
		float fSlow110 = FaustTibetanbowlDSP_faustpower2_f(fSlow109);
		float fSlow111 = (1.0f - (fConst1 * fSlow110));
		float fSlow112 = (1.0f - fSlow110);
		float fSlow113 = (fSlow111 / fSlow112);
		float fSlow114 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow111) / FaustTibetanbowlDSP_faustpower2_f(fSlow112)) + -1.0f)));
		float fSlow115 = (fSlow113 - fSlow114);
		float fSlow116 = (fSlow109 * (fSlow114 + (1.0f - fSlow113)));
		float fSlow117 = ((std::exp((fConst84 / fSlow1)) / fSlow109) + -1.0f);
		float fSlow118 = std::exp((fConst90 / fSlow1));
		float fSlow119 = FaustTibetanbowlDSP_faustpower2_f(fSlow118);
		float fSlow120 = (1.0f - (fConst1 * fSlow119));
		float fSlow121 = (1.0f - fSlow119);
		float fSlow122 = (fSlow120 / fSlow121);
		float fSlow123 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow120) / FaustTibetanbowlDSP_faustpower2_f(fSlow121)) + -1.0f)));
		float fSlow124 = (fSlow122 - fSlow123);
		float fSlow125 = (fSlow118 * (fSlow123 + (1.0f - fSlow122)));
		float fSlow126 = ((std::exp((fConst91 / fSlow1)) / fSlow118) + -1.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (0.0f - (fConst7 * ((fConst8 * fRec11[1]) - (fRec7[1] + fRec7[2]))));
			fRec11[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((fSlow8 * fRec10[1]) + (fSlow9 * (fRec7[1] + (fSlow10 * fRec11[0]))));
			fRec10[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			fVec0[(IOTA & 32767)] = ((0.353553385f * fRec10[0]) + 9.99999968e-21f);
			float fTempFTZ2 = (fSlow12 + (fConst12 * fRec12[1]));
			fRec12[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			fVec1[0] = fSlow17;
			float fTempFTZ3 = (fSlow18 + (fConst12 * fRec27[1]));
			fRec27[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow17 + (fRec28[1] * float((fVec1[1] >= fSlow17))));
			fRec28[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			iRec29[0] = (iSlow21 * (iRec29[1] + 1));
			float fTemp0 = (((fSlow20 * std::max<float>(0.0f, (std::min<float>((fConst17 * fRec28[0]), 1.0f) * (1.0f - (fConst17 * float(iRec29[0])))))) - (fSlow22 * (((((((((((fRec13[1] + fRec14[1]) + fRec15[1]) + fRec16[1]) + fRec17[1]) + fRec18[1]) + fRec19[1]) + fRec20[1]) + fRec21[1]) + fRec22[1]) + fRec23[1]) + fRec24[1]))) - fSlow23);
			float fTemp1 = FaustTibetanbowlDSP_faustpower4_f((std::fabs((fSlow24 * fTemp0)) + 0.75f));
			float fTemp2 = (1.0f / fTemp1);
			float fTemp3 = (fSlow16 * ((fRec27[0] * fTemp0) * (float((fTemp2 > 1.0f)) + (float((fTemp2 <= 1.0f)) / fTemp1))));
			float fThen0 = (fConst18 * fRec30[1]);
			float fTempFTZ5 = ((fSlow17 > fVec1[1]) ? fSlow19 : fThen0);
			fRec30[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp4 = (fSlow25 * fRec30[0]);
			fVec2[(IOTA & 2047)] = ((fRec25[1] + fTemp3) + fTemp4);
			float fTempFTZ6 = ((0.998000026f * fVec2[((IOTA - iSlow27) & 2047)]) - ((fSlow28 * fRec26[1]) + (fConst14 * fRec26[2])));
			fRec26[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fConst15 * (fRec26[0] - fRec26[2]));
			fRec25[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = fRec25[0];
			fRec13[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp5 = (fTemp3 + (fSlow29 * fRec30[0]));
			fVec3[(IOTA & 1023)] = (fRec31[1] + fTemp5);
			float fTempFTZ9 = ((0.998000026f * fVec3[((IOTA - iSlow30) & 1023)]) - ((fSlow31 * fRec32[1]) + (fConst14 * fRec32[2])));
			fRec32[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fConst15 * (fRec32[0] - fRec32[2]));
			fRec31[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = fRec31[0];
			fRec14[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp6 = (fTemp3 + (fSlow32 * fRec30[0]));
			fVec4[(IOTA & 511)] = (fRec33[1] + fTemp6);
			float fTempFTZ12 = ((0.998000026f * fVec4[((IOTA - iSlow33) & 511)]) - ((fSlow34 * fRec34[1]) + (fConst14 * fRec34[2])));
			fRec34[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fConst15 * (fRec34[0] - fRec34[2]));
			fRec33[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = fRec33[0];
			fRec15[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			fVec5[(IOTA & 511)] = (fTemp6 + fRec35[1]);
			float fTempFTZ15 = ((0.998000026f * fVec5[((IOTA - iSlow35) & 511)]) - ((fSlow36 * fRec36[1]) + (fConst14 * fRec36[2])));
			fRec36[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fConst15 * (fRec36[0] - fRec36[2]));
			fRec35[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec35[0];
			fRec16[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			fVec6[(IOTA & 255)] = (fTemp5 + fRec37[1]);
			float fTempFTZ18 = ((0.998000026f * fVec6[((IOTA - iSlow37) & 255)]) - ((fSlow38 * fRec38[1]) + (fConst14 * fRec38[2])));
			fRec38[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fConst15 * (fRec38[0] - fRec38[2]));
			fRec37[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec37[0];
			fRec17[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			fVec7[(IOTA & 255)] = (fTemp5 + fRec39[1]);
			float fTempFTZ21 = ((0.998000026f * fVec7[((IOTA - iSlow39) & 255)]) - ((fSlow40 * fRec40[1]) + (fConst14 * fRec40[2])));
			fRec40[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fConst15 * (fRec40[0] - fRec40[2]));
			fRec39[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec39[0];
			fRec18[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp7 = (fTemp3 + fTemp4);
			fVec8[(IOTA & 127)] = (fRec41[1] + fTemp7);
			float fTempFTZ24 = ((0.998000026f * fVec8[((IOTA - iSlow41) & 127)]) - ((fSlow42 * fRec42[1]) + (fConst14 * fRec42[2])));
			fRec42[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fConst15 * (fRec42[0] - fRec42[2]));
			fRec41[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec41[0];
			fRec19[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			fVec9[(IOTA & 127)] = (fTemp7 + fRec43[1]);
			float fTempFTZ27 = ((0.998000026f * fVec9[((IOTA - iSlow43) & 127)]) - ((fSlow44 * fRec44[1]) + (fConst14 * fRec44[2])));
			fRec44[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fConst15 * (fRec44[0] - fRec44[2]));
			fRec43[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec43[0];
			fRec20[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp8 = (fTemp3 + (fSlow45 * fRec30[0]));
			fVec10[(IOTA & 127)] = (fRec45[1] + fTemp8);
			float fTempFTZ30 = ((0.998000026f * fVec10[((IOTA - iSlow46) & 127)]) - ((fSlow47 * fRec46[1]) + (fConst14 * fRec46[2])));
			fRec46[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fConst15 * (fRec46[0] - fRec46[2]));
			fRec45[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec45[0];
			fRec21[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			fVec11[(IOTA & 63)] = (fTemp8 + fRec47[1]);
			float fTempFTZ33 = ((0.998000026f * fVec11[((IOTA - iSlow48) & 63)]) - ((fSlow49 * fRec48[1]) + (fConst14 * fRec48[2])));
			fRec48[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fConst15 * (fRec48[0] - fRec48[2]));
			fRec47[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = fRec47[0];
			fRec22[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			fVec12[(IOTA & 63)] = (fTemp5 + fRec49[1]);
			float fTempFTZ36 = ((0.998000026f * fVec12[((IOTA - iSlow50) & 63)]) - ((fSlow51 * fRec50[1]) + (fConst14 * fRec50[2])));
			fRec50[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fConst15 * (fRec50[0] - fRec50[2]));
			fRec49[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec49[0];
			fRec23[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			fVec13[(IOTA & 63)] = (fTemp5 + fRec51[1]);
			float fTempFTZ39 = ((0.998000026f * fVec13[((IOTA - iSlow52) & 63)]) - ((fSlow53 * fRec52[1]) + (fConst14 * fRec52[2])));
			fRec52[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fConst15 * (fRec52[0] - fRec52[2]));
			fRec51[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = fRec51[0];
			fRec24[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTemp9 = (((((((((((fRec13[0] + fRec14[0]) + fRec15[0]) + fRec16[0]) + fRec17[0]) + fRec18[0]) + fRec19[0]) + fRec20[0]) + fRec21[0]) + fRec22[0]) + fRec23[0]) + fRec24[0]);
			fVec14[0] = fTemp9;
			float fTempFTZ42 = (fSlow54 + (fConst12 * fRec53[1]));
			fRec53[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = (fSlow57 + (fConst12 * fRec56[1]));
			fRec56[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTemp10 = (fRec55[1] + (fConst43 * (fSlow55 + (fSlow56 * fRec56[0]))));
			float fTempFTZ44 = (fTemp10 - std::floor(fTemp10));
			fRec55[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTemp11 = (3.14159274f * (fRec53[0] * ftbl0FaustTibetanbowlDSPSIG0[int((65536.0f * fRec55[0]))]));
			float fTemp12 = std::sin(fTemp11);
			float fTemp13 = std::cos(fTemp11);
			float fTemp14 = ((fTemp9 * fTemp13) - (fTemp12 * fRec57[1]));
			float fTemp15 = ((fTemp13 * fTemp14) - (fTemp12 * fRec58[1]));
			float fTemp16 = ((fTemp13 * fTemp15) - (fTemp12 * fRec59[1]));
			float fTemp17 = ((fTemp13 * fTemp16) - (fTemp12 * fRec60[1]));
			float fTemp18 = ((fTemp13 * fTemp17) - (fTemp12 * fRec61[1]));
			float fTempFTZ45 = ((fTemp13 * fTemp18) - (fTemp12 * fRec62[1]));
			fRec62[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = ((fTemp12 * fTemp18) + (fTemp13 * fRec62[1]));
			fRec61[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = ((fTemp12 * fTemp17) + (fTemp13 * fRec61[1]));
			fRec60[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = ((fTemp12 * fTemp16) + (fTemp13 * fRec60[1]));
			fRec59[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = ((fTemp12 * fTemp15) + (fTemp13 * fRec59[1]));
			fRec58[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = ((fTemp12 * fTemp14) + (fTemp13 * fRec58[1]));
			fRec57[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTemp19 = (fRec53[0] * (((fSlow59 * fTemp9) + (fSlow60 * (fTemp9 + fVec14[1]))) + (fSlow61 * FaustTibetanbowlDSP_faustpower2_f(fTemp9))));
			float fTemp20 = std::sin(fTemp19);
			float fTemp21 = std::cos(fTemp19);
			float fTemp22 = ((fTemp9 * fTemp21) - (fTemp20 * fRec63[1]));
			float fTemp23 = ((fTemp21 * fTemp22) - (fTemp20 * fRec64[1]));
			float fTemp24 = ((fTemp21 * fTemp23) - (fTemp20 * fRec65[1]));
			float fTemp25 = ((fTemp21 * fTemp24) - (fTemp20 * fRec66[1]));
			float fTemp26 = ((fTemp21 * fTemp25) - (fTemp20 * fRec67[1]));
			float fTempFTZ51 = ((fTemp21 * fTemp26) - (fTemp20 * fRec68[1]));
			fRec68[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = ((fTemp20 * fTemp26) + (fTemp21 * fRec68[1]));
			fRec67[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = ((fTemp20 * fTemp25) + (fTemp21 * fRec67[1]));
			fRec66[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTempFTZ54 = ((fTemp20 * fTemp24) + (fTemp21 * fRec66[1]));
			fRec65[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fTempFTZ55 = ((fTemp20 * fTemp23) + (fTemp21 * fRec65[1]));
			fRec64[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fTempFTZ56 = ((fTemp20 * fTemp22) + (fTemp21 * fRec64[1]));
			fRec63[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fTemp27 = ((fSlow14 * ((fTemp9 * fTemp12) + (fRec57[1] * fTemp13))) + (fSlow58 * ((fTemp9 * (1.0f - fRec53[0])) + (fRec53[0] * ((fTemp9 * fTemp20) + (fRec63[1] * fTemp21))))));
			fVec16[(IOTA & 1023)] = fTemp27;
			float fTemp28 = fVec16[((IOTA - iSlow62) & 1023)];
			fVec17[(IOTA & 4095)] = (fSlow11 * (fRec12[0] * fTemp28));
			float fTemp29 = (0.300000012f * fVec17[((IOTA - iConst44) & 4095)]);
			float fTemp30 = (((0.600000024f * fRec8[1]) + fVec0[((IOTA - iConst10) & 32767)]) - fTemp29);
			fVec18[(IOTA & 2047)] = fTemp30;
			float fTempFTZ57 = fVec18[((IOTA - iConst45) & 2047)];
			fRec8[0] = ((std::fabs(fTempFTZ57) > 1.17549435e-38f) ? fTempFTZ57 : 0.0f);
			float fTempFTZ58 = (0.0f - (0.600000024f * fTemp30));
			float fRec9 = ((std::fabs(fTempFTZ58) > 1.17549435e-38f) ? fTempFTZ58 : 0.0f);
			float fTempFTZ59 = (0.0f - (fConst7 * ((fConst8 * fRec72[1]) - (fRec3[1] + fRec3[2]))));
			fRec72[0] = ((std::fabs(fTempFTZ59) > 1.17549435e-38f) ? fTempFTZ59 : 0.0f);
			float fTempFTZ60 = ((fSlow69 * fRec71[1]) + (fSlow70 * (fRec3[1] + (fSlow71 * fRec72[0]))));
			fRec71[0] = ((std::fabs(fTempFTZ60) > 1.17549435e-38f) ? fTempFTZ60 : 0.0f);
			fVec19[(IOTA & 32767)] = ((0.353553385f * fRec71[0]) + 9.99999968e-21f);
			float fTemp31 = (((0.600000024f * fRec69[1]) + fVec19[((IOTA - iConst51) & 32767)]) - fTemp29);
			fVec20[(IOTA & 4095)] = fTemp31;
			float fTempFTZ61 = fVec20[((IOTA - iConst52) & 4095)];
			fRec69[0] = ((std::fabs(fTempFTZ61) > 1.17549435e-38f) ? fTempFTZ61 : 0.0f);
			float fTempFTZ62 = (0.0f - (0.600000024f * fTemp31));
			float fRec70 = ((std::fabs(fTempFTZ62) > 1.17549435e-38f) ? fTempFTZ62 : 0.0f);
			float fTempFTZ63 = (0.0f - (fConst7 * ((fConst8 * fRec76[1]) - (fRec5[1] + fRec5[2]))));
			fRec76[0] = ((std::fabs(fTempFTZ63) > 1.17549435e-38f) ? fTempFTZ63 : 0.0f);
			float fTempFTZ64 = ((fSlow78 * fRec75[1]) + (fSlow79 * (fRec5[1] + (fSlow80 * fRec76[0]))));
			fRec75[0] = ((std::fabs(fTempFTZ64) > 1.17549435e-38f) ? fTempFTZ64 : 0.0f);
			fVec21[(IOTA & 16383)] = ((0.353553385f * fRec75[0]) + 9.99999968e-21f);
			float fTemp32 = (fVec21[((IOTA - iConst58) & 16383)] + (fTemp29 + (0.600000024f * fRec73[1])));
			fVec22[(IOTA & 4095)] = fTemp32;
			float fTempFTZ65 = fVec22[((IOTA - iConst59) & 4095)];
			fRec73[0] = ((std::fabs(fTempFTZ65) > 1.17549435e-38f) ? fTempFTZ65 : 0.0f);
			float fTempFTZ66 = (0.0f - (0.600000024f * fTemp32));
			float fRec74 = ((std::fabs(fTempFTZ66) > 1.17549435e-38f) ? fTempFTZ66 : 0.0f);
			float fTempFTZ67 = (0.0f - (fConst7 * ((fConst8 * fRec80[1]) - (fRec1[1] + fRec1[2]))));
			fRec80[0] = ((std::fabs(fTempFTZ67) > 1.17549435e-38f) ? fTempFTZ67 : 0.0f);
			float fTempFTZ68 = ((fSlow87 * fRec79[1]) + (fSlow88 * (fRec1[1] + (fSlow89 * fRec80[0]))));
			fRec79[0] = ((std::fabs(fTempFTZ68) > 1.17549435e-38f) ? fTempFTZ68 : 0.0f);
			fVec23[(IOTA & 32767)] = ((0.353553385f * fRec79[0]) + 9.99999968e-21f);
			float fTemp33 = (fTemp29 + ((0.600000024f * fRec77[1]) + fVec23[((IOTA - iConst65) & 32767)]));
			fVec24[(IOTA & 4095)] = fTemp33;
			float fTempFTZ69 = fVec24[((IOTA - iConst66) & 4095)];
			fRec77[0] = ((std::fabs(fTempFTZ69) > 1.17549435e-38f) ? fTempFTZ69 : 0.0f);
			float fTempFTZ70 = (0.0f - (0.600000024f * fTemp33));
			float fRec78 = ((std::fabs(fTempFTZ70) > 1.17549435e-38f) ? fTempFTZ70 : 0.0f);
			float fTempFTZ71 = (0.0f - (fConst7 * ((fConst8 * fRec84[1]) - (fRec6[1] + fRec6[2]))));
			fRec84[0] = ((std::fabs(fTempFTZ71) > 1.17549435e-38f) ? fTempFTZ71 : 0.0f);
			float fTempFTZ72 = ((fSlow96 * fRec83[1]) + (fSlow97 * (fRec6[1] + (fSlow98 * fRec84[0]))));
			fRec83[0] = ((std::fabs(fTempFTZ72) > 1.17549435e-38f) ? fTempFTZ72 : 0.0f);
			fVec25[(IOTA & 16383)] = ((0.353553385f * fRec83[0]) + 9.99999968e-21f);
			fVec26[(IOTA & 4095)] = (fSlow99 * (fRec12[0] * fTemp27));
			float fTemp34 = (0.300000012f * fVec26[((IOTA - iConst44) & 4095)]);
			float fTemp35 = (fVec25[((IOTA - iConst72) & 16383)] - (fTemp34 + (0.600000024f * fRec81[1])));
			fVec27[(IOTA & 2047)] = fTemp35;
			float fTempFTZ73 = fVec27[((IOTA - iConst73) & 2047)];
			fRec81[0] = ((std::fabs(fTempFTZ73) > 1.17549435e-38f) ? fTempFTZ73 : 0.0f);
			float fTempFTZ74 = (0.600000024f * fTemp35);
			float fRec82 = ((std::fabs(fTempFTZ74) > 1.17549435e-38f) ? fTempFTZ74 : 0.0f);
			float fTempFTZ75 = (0.0f - (fConst7 * ((fConst8 * fRec88[1]) - (fRec2[1] + fRec2[2]))));
			fRec88[0] = ((std::fabs(fTempFTZ75) > 1.17549435e-38f) ? fTempFTZ75 : 0.0f);
			float fTempFTZ76 = ((fSlow106 * fRec87[1]) + (fSlow107 * (fRec2[1] + (fSlow108 * fRec88[0]))));
			fRec87[0] = ((std::fabs(fTempFTZ76) > 1.17549435e-38f) ? fTempFTZ76 : 0.0f);
			fVec28[(IOTA & 16383)] = ((0.353553385f * fRec87[0]) + 9.99999968e-21f);
			float fTemp36 = (fVec28[((IOTA - iConst79) & 16383)] - (fTemp34 + (0.600000024f * fRec85[1])));
			fVec29[(IOTA & 4095)] = fTemp36;
			float fTempFTZ77 = fVec29[((IOTA - iConst80) & 4095)];
			fRec85[0] = ((std::fabs(fTempFTZ77) > 1.17549435e-38f) ? fTempFTZ77 : 0.0f);
			float fTempFTZ78 = (0.600000024f * fTemp36);
			float fRec86 = ((std::fabs(fTempFTZ78) > 1.17549435e-38f) ? fTempFTZ78 : 0.0f);
			float fTempFTZ79 = (0.0f - (fConst7 * ((fConst8 * fRec92[1]) - (fRec4[1] + fRec4[2]))));
			fRec92[0] = ((std::fabs(fTempFTZ79) > 1.17549435e-38f) ? fTempFTZ79 : 0.0f);
			float fTempFTZ80 = ((fSlow115 * fRec91[1]) + (fSlow116 * (fRec4[1] + (fSlow117 * fRec92[0]))));
			fRec91[0] = ((std::fabs(fTempFTZ80) > 1.17549435e-38f) ? fTempFTZ80 : 0.0f);
			fVec30[(IOTA & 16383)] = ((0.353553385f * fRec91[0]) + 9.99999968e-21f);
			float fTemp37 = ((fTemp34 + fVec30[((IOTA - iConst86) & 16383)]) - (0.600000024f * fRec89[1]));
			fVec31[(IOTA & 4095)] = fTemp37;
			float fTempFTZ81 = fVec31[((IOTA - iConst87) & 4095)];
			fRec89[0] = ((std::fabs(fTempFTZ81) > 1.17549435e-38f) ? fTempFTZ81 : 0.0f);
			float fTempFTZ82 = (0.600000024f * fTemp37);
			float fRec90 = ((std::fabs(fTempFTZ82) > 1.17549435e-38f) ? fTempFTZ82 : 0.0f);
			float fTempFTZ83 = (0.0f - (fConst7 * ((fConst8 * fRec96[1]) - (fRec0[1] + fRec0[2]))));
			fRec96[0] = ((std::fabs(fTempFTZ83) > 1.17549435e-38f) ? fTempFTZ83 : 0.0f);
			float fTempFTZ84 = ((fSlow124 * fRec95[1]) + (fSlow125 * (fRec0[1] + (fSlow126 * fRec96[0]))));
			fRec95[0] = ((std::fabs(fTempFTZ84) > 1.17549435e-38f) ? fTempFTZ84 : 0.0f);
			fVec32[(IOTA & 16383)] = ((0.353553385f * fRec95[0]) + 9.99999968e-21f);
			float fTemp38 = ((fVec32[((IOTA - iConst93) & 16383)] + fTemp34) - (0.600000024f * fRec93[1]));
			fVec33[(IOTA & 2047)] = fTemp38;
			float fTempFTZ85 = fVec33[((IOTA - iConst94) & 2047)];
			fRec93[0] = ((std::fabs(fTempFTZ85) > 1.17549435e-38f) ? fTempFTZ85 : 0.0f);
			float fTempFTZ86 = (0.600000024f * fTemp38);
			float fRec94 = ((std::fabs(fTempFTZ86) > 1.17549435e-38f) ? fTempFTZ86 : 0.0f);
			float fTemp39 = (fRec94 + fRec90);
			float fTemp40 = (fRec82 + (fRec86 + fTemp39));
			float fTempFTZ87 = (fRec8[1] + (fRec69[1] + (fRec73[1] + (fRec77[1] + (fRec81[1] + (fRec85[1] + (fRec89[1] + (fRec93[1] + (fRec9 + (fRec70 + (fRec74 + (fRec78 + fTemp40))))))))))));
			fRec0[0] = ((std::fabs(fTempFTZ87) > 1.17549435e-38f) ? fTempFTZ87 : 0.0f);
			float fTempFTZ88 = ((fRec81[1] + (fRec85[1] + (fRec89[1] + (fRec93[1] + fTemp40)))) - (fRec8[1] + (fRec69[1] + (fRec73[1] + (fRec77[1] + (fRec9 + (fRec70 + (fRec78 + fRec74))))))));
			fRec1[0] = ((std::fabs(fTempFTZ88) > 1.17549435e-38f) ? fTempFTZ88 : 0.0f);
			float fTemp41 = (fRec86 + fRec82);
			float fTempFTZ89 = ((fRec73[1] + (fRec77[1] + (fRec89[1] + (fRec93[1] + (fRec74 + (fRec78 + fTemp39)))))) - (fRec8[1] + (fRec69[1] + (fRec81[1] + (fRec85[1] + (fRec9 + (fRec70 + fTemp41)))))));
			fRec2[0] = ((std::fabs(fTempFTZ89) > 1.17549435e-38f) ? fTempFTZ89 : 0.0f);
			float fTempFTZ90 = ((fRec8[1] + (fRec69[1] + (fRec89[1] + (fRec93[1] + (fRec9 + (fRec70 + fTemp39)))))) - (fRec73[1] + (fRec77[1] + (fRec81[1] + (fRec85[1] + (fRec74 + (fRec78 + fTemp41)))))));
			fRec3[0] = ((std::fabs(fTempFTZ90) > 1.17549435e-38f) ? fTempFTZ90 : 0.0f);
			float fTemp42 = (fRec94 + fRec86);
			float fTemp43 = (fRec90 + fRec82);
			float fTempFTZ91 = ((fRec69[1] + (fRec77[1] + (fRec85[1] + (fRec93[1] + (fRec70 + (fRec78 + fTemp42)))))) - (fRec8[1] + (fRec73[1] + (fRec81[1] + (fRec89[1] + (fRec9 + (fRec74 + fTemp43)))))));
			fRec4[0] = ((std::fabs(fTempFTZ91) > 1.17549435e-38f) ? fTempFTZ91 : 0.0f);
			float fTempFTZ92 = ((fRec8[1] + (fRec73[1] + (fRec85[1] + (fRec93[1] + (fRec9 + (fRec74 + fTemp42)))))) - (fRec69[1] + (fRec77[1] + (fRec81[1] + (fRec89[1] + (fRec70 + (fRec78 + fTemp43)))))));
			fRec5[0] = ((std::fabs(fTempFTZ92) > 1.17549435e-38f) ? fTempFTZ92 : 0.0f);
			float fTemp44 = (fRec94 + fRec82);
			float fTemp45 = (fRec90 + fRec86);
			float fTempFTZ93 = ((fRec8[1] + (fRec77[1] + (fRec81[1] + (fRec93[1] + (fRec9 + (fRec78 + fTemp44)))))) - (fRec69[1] + (fRec73[1] + (fRec85[1] + (fRec89[1] + (fRec70 + (fRec74 + fTemp45)))))));
			fRec6[0] = ((std::fabs(fTempFTZ93) > 1.17549435e-38f) ? fTempFTZ93 : 0.0f);
			float fTempFTZ94 = ((fRec69[1] + (fRec73[1] + (fRec81[1] + (fRec93[1] + (fRec70 + (fRec74 + fTemp44)))))) - (fRec8[1] + (fRec77[1] + (fRec85[1] + (fRec89[1] + (fRec9 + (fRec78 + fTemp45)))))));
			fRec7[0] = ((std::fabs(fTempFTZ94) > 1.17549435e-38f) ? fTempFTZ94 : 0.0f);
			float fTemp46 = (1.0f - fRec12[0]);
			output0[i0] = FAUSTFLOAT((fSlow0 * ((0.370000005f * (fRec1[0] + fRec2[0])) + (fSlow99 * (fTemp46 * fTemp27)))));
			output1[i0] = FAUSTFLOAT((fSlow0 * ((0.370000005f * (fRec1[0] - fRec2[0])) + (fSlow11 * (fTemp46 * fTemp28)))));
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			IOTA = (IOTA + 1);
			fRec12[1] = fRec12[0];
			fVec1[1] = fVec1[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			iRec29[1] = iRec29[0];
			fRec30[1] = fRec30[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec13[1] = fRec13[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec14[1] = fRec14[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec15[1] = fRec15[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec16[1] = fRec16[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec17[1] = fRec17[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec18[1] = fRec18[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec19[1] = fRec19[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec20[1] = fRec20[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec21[1] = fRec21[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec22[1] = fRec22[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec23[1] = fRec23[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec24[1] = fRec24[0];
			fVec14[1] = fVec14[0];
			fRec53[1] = fRec53[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec8[1] = fRec8[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec77[1] = fRec77[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec89[1] = fRec89[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[1] = fRec93[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
		}
	}

};

#endif
