/* ------------------------------------------------------------
author: "Romain Michon"
copyright: "Romain Michon (rmichon@ccrma.stanford.edu)"
name: "tibetanBowl"
version: "1.0"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustTibetanbowlDSP_H__
#define  __FaustTibetanbowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

class FaustTibetanbowlDSPSIG0 {
	
  private:
	
	int iVec14[2];
	int iRec52[2];
	
  public:
	
	int getNumInputsFaustTibetanbowlDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTibetanbowlDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTibetanbowlDSPSIG0(int sample_rate) {
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			iVec14[l56] = 0;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			iRec52[l57] = 0;
		}
	}
	
	void fillFaustTibetanbowlDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec14[0] = 1;
			iRec52[0] = ((iVec14[1] + iRec52[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec52[0])));
			iVec14[1] = iVec14[0];
			iRec52[1] = iRec52[0];
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
	float fVec2[8192];
	float fConst19;
	FAUSTFLOAT fEntry2;
	float fConst20;
	float fConst21;
	float fRec26[3];
	float fRec25[2];
	float fRec13[2];
	float fVec3[8192];
	float fConst22;
	float fConst23;
	float fRec32[3];
	float fRec31[2];
	float fRec14[2];
	float fVec4[4096];
	float fConst24;
	float fConst25;
	float fRec34[3];
	float fRec33[2];
	float fRec15[2];
	float fVec5[4096];
	float fConst26;
	float fConst27;
	float fRec36[3];
	float fRec35[2];
	float fRec16[2];
	float fVec6[2048];
	float fConst28;
	float fConst29;
	float fRec38[3];
	float fRec37[2];
	float fRec17[2];
	float fRec18[2];
	float fVec7[2048];
	float fConst30;
	float fConst31;
	float fRec40[3];
	float fRec39[2];
	float fRec19[2];
	float fVec8[2048];
	float fConst32;
	float fConst33;
	float fRec42[3];
	float fRec41[2];
	float fRec20[2];
	float fVec9[1024];
	float fConst34;
	float fConst35;
	float fRec44[3];
	float fRec43[2];
	float fRec21[2];
	float fVec10[1024];
	float fConst36;
	float fConst37;
	float fRec46[3];
	float fRec45[2];
	float fRec22[2];
	float fVec11[1024];
	float fConst38;
	float fConst39;
	float fRec48[3];
	float fRec47[2];
	float fRec23[2];
	float fVec12[512];
	float fConst40;
	float fConst41;
	float fRec50[3];
	float fRec49[2];
	float fRec24[2];
	float fVec13[2];
	FAUSTFLOAT fHslider8;
	float fRec51[2];
	float fConst42;
	FAUSTFLOAT fHslider9;
	float fRec54[2];
	float fRec53[2];
	float fRec60[2];
	float fRec59[2];
	float fRec58[2];
	float fRec57[2];
	float fRec56[2];
	float fRec55[2];
	float fRec66[2];
	float fRec65[2];
	float fRec64[2];
	float fRec63[2];
	float fRec62[2];
	float fRec61[2];
	float fVec15[8192];
	FAUSTFLOAT fHslider10;
	float fVec16[4096];
	int iConst43;
	float fVec17[2048];
	int iConst44;
	float fRec8[2];
	float fConst47;
	float fConst48;
	float fRec70[2];
	float fRec69[2];
	float fVec18[32768];
	int iConst50;
	float fVec19[4096];
	int iConst51;
	float fRec67[2];
	float fConst54;
	float fConst55;
	float fRec74[2];
	float fRec73[2];
	float fVec20[16384];
	int iConst57;
	float fVec21[4096];
	int iConst58;
	float fRec71[2];
	float fConst61;
	float fConst62;
	float fRec78[2];
	float fRec77[2];
	float fVec22[32768];
	int iConst64;
	float fVec23[4096];
	int iConst65;
	float fRec75[2];
	float fConst68;
	float fConst69;
	float fRec82[2];
	float fRec81[2];
	float fVec24[16384];
	int iConst71;
	float fVec25[4096];
	float fVec26[2048];
	int iConst72;
	float fRec79[2];
	float fConst75;
	float fConst76;
	float fRec86[2];
	float fRec85[2];
	float fVec27[16384];
	int iConst78;
	float fVec28[4096];
	int iConst79;
	float fRec83[2];
	float fConst82;
	float fConst83;
	float fRec90[2];
	float fRec89[2];
	float fVec29[16384];
	int iConst85;
	float fVec30[4096];
	int iConst86;
	float fRec87[2];
	float fConst89;
	float fConst90;
	float fRec94[2];
	float fRec93[2];
	float fVec31[16384];
	int iConst92;
	float fVec32[2048];
	int iConst93;
	float fRec91[2];
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
		m->declare("author", "Romain Michon");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "Banded Waveguide Modeld Tibetan Bowl");
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
		m->declare("licence", "STK-4.3");
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
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
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
		fConst19 = (1.00390685f * fConst0);
		fConst20 = (0.0f - (2.0f * fConst13));
		fConst21 = (6.25873327f / fConst0);
		fConst22 = (0.996123433f * fConst0);
		fConst23 = (6.30763721f / fConst0);
		fConst24 = (0.33566305f * fConst0);
		fConst25 = (18.7187271f / fConst0);
		fConst26 = (0.334079713f * fConst0);
		fConst27 = (18.8074436f / fConst0);
		fConst28 = (0.175301671f * fConst0);
		fConst29 = (35.8421288f / fConst0);
		fConst30 = (0.111133337f * fConst0);
		fConst31 = (56.5373573f / fConst0);
		fConst32 = (0.110920116f * fConst0);
		fConst33 = (56.6460381f / fConst0);
		fConst34 = (0.0779239163f * fConst0);
		fConst35 = (80.632309f / fConst0);
		fConst36 = (0.0780799687f * fConst0);
		fConst37 = (80.4711533f / fConst0);
		fConst38 = (0.0578676164f * fConst0);
		fConst39 = (108.578606f / fConst0);
		fConst40 = (0.0455041304f * fConst0);
		fConst41 = (138.079453f / fConst0);
		fConst42 = (1.0f / fConst0);
		iConst43 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (0.0199999996f * fConst0))));
		iConst44 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst9 + -1.0f))));
		float fConst45 = std::floor(((0.256891012f * fConst0) + 0.5f));
		float fConst46 = ((0.0f - (6.90775537f * fConst45)) / fConst0);
		fConst47 = (0.5f * fConst46);
		fConst48 = (0.333333343f * fConst46);
		float fConst49 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		iConst50 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst45 - fConst49))));
		iConst51 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst49 + -1.0f))));
		float fConst52 = std::floor(((0.192303002f * fConst0) + 0.5f));
		float fConst53 = ((0.0f - (6.90775537f * fConst52)) / fConst0);
		fConst54 = (0.5f * fConst53);
		fConst55 = (0.333333343f * fConst53);
		float fConst56 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		iConst57 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst52 - fConst56))));
		iConst58 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst56 + -1.0f))));
		float fConst59 = std::floor(((0.210389003f * fConst0) + 0.5f));
		float fConst60 = ((0.0f - (6.90775537f * fConst59)) / fConst0);
		fConst61 = (0.5f * fConst60);
		fConst62 = (0.333333343f * fConst60);
		float fConst63 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		iConst64 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst59 - fConst63))));
		iConst65 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst63 + -1.0f))));
		float fConst66 = std::floor(((0.125f * fConst0) + 0.5f));
		float fConst67 = ((0.0f - (6.90775537f * fConst66)) / fConst0);
		fConst68 = (0.5f * fConst67);
		fConst69 = (0.333333343f * fConst67);
		float fConst70 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		iConst71 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst66 - fConst70))));
		iConst72 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst70 + -1.0f))));
		float fConst73 = std::floor(((0.127837002f * fConst0) + 0.5f));
		float fConst74 = ((0.0f - (6.90775537f * fConst73)) / fConst0);
		fConst75 = (0.5f * fConst74);
		fConst76 = (0.333333343f * fConst74);
		float fConst77 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		iConst78 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst73 - fConst77))));
		iConst79 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst77 + -1.0f))));
		float fConst80 = std::floor(((0.174713001f * fConst0) + 0.5f));
		float fConst81 = ((0.0f - (6.90775537f * fConst80)) / fConst0);
		fConst82 = (0.5f * fConst81);
		fConst83 = (0.333333343f * fConst81);
		float fConst84 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		iConst85 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst80 - fConst84))));
		iConst86 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst84 + -1.0f))));
		float fConst87 = std::floor(((0.153128996f * fConst0) + 0.5f));
		float fConst88 = ((0.0f - (6.90775537f * fConst87)) / fConst0);
		fConst89 = (0.5f * fConst88);
		fConst90 = (0.333333343f * fConst88);
		float fConst91 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		iConst92 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst87 - fConst91))));
		iConst93 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst91 + -1.0f))));
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider0 = FAUSTFLOAT(0.71999999999999997f);
		fHslider1 = FAUSTFLOAT(0.59999999999999998f);
		fHslider2 = FAUSTFLOAT(0.13700000000000001f);
		fEntry1 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.80000000000000004f);
		fHslider6 = FAUSTFLOAT(1.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fEntry2 = FAUSTFLOAT(440.0f);
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
		for (int l9 = 0; (l9 < 8192); l9 = (l9 + 1)) {
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
		for (int l13 = 0; (l13 < 8192); l13 = (l13 + 1)) {
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
		for (int l17 = 0; (l17 < 4096); l17 = (l17 + 1)) {
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
		for (int l21 = 0; (l21 < 4096); l21 = (l21 + 1)) {
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
		for (int l25 = 0; (l25 < 2048); l25 = (l25 + 1)) {
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
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec18[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2048); l30 = (l30 + 1)) {
			fVec7[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec40[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec39[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec19[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2048); l34 = (l34 + 1)) {
			fVec8[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec42[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec41[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec20[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 1024); l38 = (l38 + 1)) {
			fVec9[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec44[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec43[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec21[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 1024); l42 = (l42 + 1)) {
			fVec10[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec46[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec45[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec22[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 1024); l46 = (l46 + 1)) {
			fVec11[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec48[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec47[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec23[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 512); l50 = (l50 + 1)) {
			fVec12[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec50[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec49[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec24[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fVec13[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec51[l55] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec54[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec53[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec60[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec59[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec58[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec57[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec56[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec55[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec66[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec65[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec64[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec63[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec62[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec61[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 8192); l72 = (l72 + 1)) {
			fVec15[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 4096); l73 = (l73 + 1)) {
			fVec16[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 2048); l74 = (l74 + 1)) {
			fVec17[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec8[l75] = 0.0f;
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec70[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec69[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 32768); l78 = (l78 + 1)) {
			fVec18[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 4096); l79 = (l79 + 1)) {
			fVec19[l79] = 0.0f;
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec67[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec74[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec73[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 16384); l83 = (l83 + 1)) {
			fVec20[l83] = 0.0f;
		}
		for (int l84 = 0; (l84 < 4096); l84 = (l84 + 1)) {
			fVec21[l84] = 0.0f;
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec71[l85] = 0.0f;
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec78[l86] = 0.0f;
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec77[l87] = 0.0f;
		}
		for (int l88 = 0; (l88 < 32768); l88 = (l88 + 1)) {
			fVec22[l88] = 0.0f;
		}
		for (int l89 = 0; (l89 < 4096); l89 = (l89 + 1)) {
			fVec23[l89] = 0.0f;
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec75[l90] = 0.0f;
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec82[l91] = 0.0f;
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec81[l92] = 0.0f;
		}
		for (int l93 = 0; (l93 < 16384); l93 = (l93 + 1)) {
			fVec24[l93] = 0.0f;
		}
		for (int l94 = 0; (l94 < 4096); l94 = (l94 + 1)) {
			fVec25[l94] = 0.0f;
		}
		for (int l95 = 0; (l95 < 2048); l95 = (l95 + 1)) {
			fVec26[l95] = 0.0f;
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec79[l96] = 0.0f;
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec86[l97] = 0.0f;
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec85[l98] = 0.0f;
		}
		for (int l99 = 0; (l99 < 16384); l99 = (l99 + 1)) {
			fVec27[l99] = 0.0f;
		}
		for (int l100 = 0; (l100 < 4096); l100 = (l100 + 1)) {
			fVec28[l100] = 0.0f;
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec83[l101] = 0.0f;
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec90[l102] = 0.0f;
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec89[l103] = 0.0f;
		}
		for (int l104 = 0; (l104 < 16384); l104 = (l104 + 1)) {
			fVec29[l104] = 0.0f;
		}
		for (int l105 = 0; (l105 < 4096); l105 = (l105 + 1)) {
			fVec30[l105] = 0.0f;
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec87[l106] = 0.0f;
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec94[l107] = 0.0f;
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec93[l108] = 0.0f;
		}
		for (int l109 = 0; (l109 < 16384); l109 = (l109 + 1)) {
			fVec31[l109] = 0.0f;
		}
		for (int l110 = 0; (l110 < 2048); l110 = (l110 + 1)) {
			fVec32[l110] = 0.0f;
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec91[l111] = 0.0f;
		}
		for (int l112 = 0; (l112 < 3); l112 = (l112 + 1)) {
			fRec0[l112] = 0.0f;
		}
		for (int l113 = 0; (l113 < 3); l113 = (l113 + 1)) {
			fRec1[l113] = 0.0f;
		}
		for (int l114 = 0; (l114 < 3); l114 = (l114 + 1)) {
			fRec2[l114] = 0.0f;
		}
		for (int l115 = 0; (l115 < 3); l115 = (l115 + 1)) {
			fRec3[l115] = 0.0f;
		}
		for (int l116 = 0; (l116 < 3); l116 = (l116 + 1)) {
			fRec4[l116] = 0.0f;
		}
		for (int l117 = 0; (l117 < 3); l117 = (l117 + 1)) {
			fRec5[l117] = 0.0f;
		}
		for (int l118 = 0; (l118 < 3); l118 = (l118 + 1)) {
			fRec6[l118] = 0.0f;
		}
		for (int l119 = 0; (l119 < 3); l119 = (l119 + 1)) {
			fRec7[l119] = 0.0f;
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
		ui_interface->declare(&fHslider9, "tooltip", "Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)");
		ui_interface->declare(&fHslider9, "unit", "Hz");
		ui_interface->addHorizontalSlider("Modulation_Frequency", &fHslider9, FAUSTFLOAT(220.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fEntry1, "3", "");
		ui_interface->declare(&fEntry1, "tooltip", "0=theta is modulated by the incoming signal; 1=theta is modulated by the averaged incoming signal; 2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod; 4=theta is modulated by a sine wave of frequency freq;");
		ui_interface->addNumEntry("Modulation_Type", &fEntry1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider8, "3", "");
		ui_interface->declare(&fHslider8, "tooltip", "Nonlinearity factor (value between 0 and 1)");
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
		ui_interface->addNumEntry("freq", &fEntry2, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addNumEntry("gain", &fEntry0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gate", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("strike", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
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
		float fSlow16 = (0.0833333358f * (0.0f - (fSlow15 + -1.0f)));
		float fSlow17 = float(fHslider4);
		float fSlow18 = (fConst11 * fSlow17);
		float fSlow19 = float(fHslider5);
		float fSlow20 = ((0.200000003f * fSlow19) + 0.0299999993f);
		int iSlow21 = (fSlow17 == 0.0f);
		float fSlow22 = ((0.100000001f * float(fHslider6)) + 0.899999976f);
		float fSlow23 = float(fHslider7);
		float fSlow24 = (10.0f - (9.0f * fSlow19));
		float fSlow25 = (1.1900357f * fSlow15);
		float fSlow26 = float(fEntry2);
		int iSlow27 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst19 / fSlow26))));
		float fSlow28 = (fConst20 * std::cos((fConst21 * fSlow26)));
		int iSlow29 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst22 / fSlow26))));
		float fSlow30 = (fConst20 * std::cos((fConst23 * fSlow26)));
		float fSlow31 = (1.0914886f * fSlow15);
		int iSlow32 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst24 / fSlow26))));
		float fSlow33 = (fConst20 * std::cos((fConst25 * fSlow26)));
		int iSlow34 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst26 / fSlow26))));
		float fSlow35 = (fConst20 * std::cos((fConst27 * fSlow26)));
		float fSlow36 = (4.29950428f * fSlow15);
		int iSlow37 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst28 / fSlow26))));
		float fSlow38 = (fConst20 * std::cos((fConst29 * fSlow26)));
		float fSlow39 = (4.00630331f * fSlow15);
		int iSlow40 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst30 / fSlow26))));
		float fSlow41 = (fConst20 * std::cos((fConst31 * fSlow26)));
		int iSlow42 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst32 / fSlow26))));
		float fSlow43 = (fConst20 * std::cos((fConst33 * fSlow26)));
		float fSlow44 = (0.706303418f * fSlow15);
		int iSlow45 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst34 / fSlow26))));
		float fSlow46 = (fConst20 * std::cos((fConst35 * fSlow26)));
		int iSlow47 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst36 / fSlow26))));
		float fSlow48 = (fConst20 * std::cos((fConst37 * fSlow26)));
		float fSlow49 = (5.7063036f * fSlow15);
		int iSlow50 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst38 / fSlow26))));
		float fSlow51 = (fConst20 * std::cos((fConst39 * fSlow26)));
		int iSlow52 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst40 / fSlow26))));
		float fSlow53 = (fConst20 * std::cos((fConst41 * fSlow26)));
		float fSlow54 = (fConst11 * float(fHslider8));
		float fSlow55 = (fSlow26 * float((fSlow13 == 4.0f)));
		float fSlow56 = float((fSlow13 != 4.0f));
		float fSlow57 = (fConst11 * float(fHslider9));
		float fSlow58 = float((fSlow13 < 3.0f));
		float fSlow59 = (3.14159274f * float((fSlow13 == 0.0f)));
		float fSlow60 = (1.57079637f * float((fSlow13 == 1.0f)));
		float fSlow61 = (3.14159274f * float((fSlow13 == 2.0f)));
		int iSlow62 = int(std::min<float>(4096.0f, std::max<float>(0.0f, (fConst16 * (float(fHslider10) / fSlow26)))));
		float fSlow63 = std::exp((fConst47 / fSlow1));
		float fSlow64 = FaustTibetanbowlDSP_faustpower2_f(fSlow63);
		float fSlow65 = (1.0f - (fConst1 * fSlow64));
		float fSlow66 = (1.0f - fSlow64);
		float fSlow67 = (fSlow65 / fSlow66);
		float fSlow68 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow65) / FaustTibetanbowlDSP_faustpower2_f(fSlow66)) + -1.0f)));
		float fSlow69 = (fSlow67 - fSlow68);
		float fSlow70 = (fSlow63 * (fSlow68 + (1.0f - fSlow67)));
		float fSlow71 = ((std::exp((fConst48 / fSlow1)) / fSlow63) + -1.0f);
		float fSlow72 = std::exp((fConst54 / fSlow1));
		float fSlow73 = FaustTibetanbowlDSP_faustpower2_f(fSlow72);
		float fSlow74 = (1.0f - (fConst1 * fSlow73));
		float fSlow75 = (1.0f - fSlow73);
		float fSlow76 = (fSlow74 / fSlow75);
		float fSlow77 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow74) / FaustTibetanbowlDSP_faustpower2_f(fSlow75)) + -1.0f)));
		float fSlow78 = (fSlow76 - fSlow77);
		float fSlow79 = (fSlow72 * (fSlow77 + (1.0f - fSlow76)));
		float fSlow80 = ((std::exp((fConst55 / fSlow1)) / fSlow72) + -1.0f);
		float fSlow81 = std::exp((fConst61 / fSlow1));
		float fSlow82 = FaustTibetanbowlDSP_faustpower2_f(fSlow81);
		float fSlow83 = (1.0f - (fConst1 * fSlow82));
		float fSlow84 = (1.0f - fSlow82);
		float fSlow85 = (fSlow83 / fSlow84);
		float fSlow86 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow83) / FaustTibetanbowlDSP_faustpower2_f(fSlow84)) + -1.0f)));
		float fSlow87 = (fSlow85 - fSlow86);
		float fSlow88 = (fSlow81 * (fSlow86 + (1.0f - fSlow85)));
		float fSlow89 = ((std::exp((fConst62 / fSlow1)) / fSlow81) + -1.0f);
		float fSlow90 = std::exp((fConst68 / fSlow1));
		float fSlow91 = FaustTibetanbowlDSP_faustpower2_f(fSlow90);
		float fSlow92 = (1.0f - (fConst1 * fSlow91));
		float fSlow93 = (1.0f - fSlow91);
		float fSlow94 = (fSlow92 / fSlow93);
		float fSlow95 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow92) / FaustTibetanbowlDSP_faustpower2_f(fSlow93)) + -1.0f)));
		float fSlow96 = (fSlow94 - fSlow95);
		float fSlow97 = (fSlow90 * (fSlow95 + (1.0f - fSlow94)));
		float fSlow98 = ((std::exp((fConst69 / fSlow1)) / fSlow90) + -1.0f);
		float fSlow99 = (1.0f - fSlow11);
		float fSlow100 = std::exp((fConst75 / fSlow1));
		float fSlow101 = FaustTibetanbowlDSP_faustpower2_f(fSlow100);
		float fSlow102 = (1.0f - (fConst1 * fSlow101));
		float fSlow103 = (1.0f - fSlow101);
		float fSlow104 = (fSlow102 / fSlow103);
		float fSlow105 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow102) / FaustTibetanbowlDSP_faustpower2_f(fSlow103)) + -1.0f)));
		float fSlow106 = (fSlow104 - fSlow105);
		float fSlow107 = (fSlow100 * (fSlow105 + (1.0f - fSlow104)));
		float fSlow108 = ((std::exp((fConst76 / fSlow1)) / fSlow100) + -1.0f);
		float fSlow109 = std::exp((fConst82 / fSlow1));
		float fSlow110 = FaustTibetanbowlDSP_faustpower2_f(fSlow109);
		float fSlow111 = (1.0f - (fConst1 * fSlow110));
		float fSlow112 = (1.0f - fSlow110);
		float fSlow113 = (fSlow111 / fSlow112);
		float fSlow114 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow111) / FaustTibetanbowlDSP_faustpower2_f(fSlow112)) + -1.0f)));
		float fSlow115 = (fSlow113 - fSlow114);
		float fSlow116 = (fSlow109 * (fSlow114 + (1.0f - fSlow113)));
		float fSlow117 = ((std::exp((fConst83 / fSlow1)) / fSlow109) + -1.0f);
		float fSlow118 = std::exp((fConst89 / fSlow1));
		float fSlow119 = FaustTibetanbowlDSP_faustpower2_f(fSlow118);
		float fSlow120 = (1.0f - (fConst1 * fSlow119));
		float fSlow121 = (1.0f - fSlow119);
		float fSlow122 = (fSlow120 / fSlow121);
		float fSlow123 = std::sqrt(std::max<float>(0.0f, ((FaustTibetanbowlDSP_faustpower2_f(fSlow120) / FaustTibetanbowlDSP_faustpower2_f(fSlow121)) + -1.0f)));
		float fSlow124 = (fSlow122 - fSlow123);
		float fSlow125 = (fSlow118 * (fSlow123 + (1.0f - fSlow122)));
		float fSlow126 = ((std::exp((fConst90 / fSlow1)) / fSlow118) + -1.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec11[0] = (0.0f - (fConst7 * ((fConst8 * fRec11[1]) - (fRec7[1] + fRec7[2]))));
			fRec10[0] = ((fSlow8 * fRec10[1]) + (fSlow9 * (fRec7[1] + (fSlow10 * fRec11[0]))));
			fVec0[(IOTA & 32767)] = ((0.353553385f * fRec10[0]) + 9.99999968e-21f);
			fRec12[0] = (fSlow12 + (fConst12 * fRec12[1]));
			fVec1[0] = fSlow17;
			fRec27[0] = (fSlow18 + (fConst12 * fRec27[1]));
			fRec28[0] = (fSlow17 + (fRec28[1] * float((fVec1[1] >= fSlow17))));
			iRec29[0] = (iSlow21 * (iRec29[1] + 1));
			float fTemp0 = (((fSlow20 * std::max<float>(0.0f, (std::min<float>((fConst17 * fRec28[0]), 1.0f) * (1.0f - (fConst17 * float(iRec29[0])))))) - (fSlow22 * ((((((fRec13[1] + fRec15[1]) + fRec17[1]) + fRec19[1]) + fRec21[1]) + fRec23[1]) + (((((fRec14[1] + fRec16[1]) + fRec18[1]) + fRec20[1]) + fRec22[1]) + fRec24[1])))) - fSlow23);
			float fTemp1 = FaustTibetanbowlDSP_faustpower4_f((std::fabs((fSlow24 * fTemp0)) + 0.75f));
			float fTemp2 = (1.0f / fTemp1);
			float fTemp3 = (fSlow16 * ((fRec27[0] * fTemp0) * (float((fTemp2 > 1.0f)) + (float((fTemp2 <= 1.0f)) / fTemp1))));
			float fThen0 = (fConst18 * fRec30[1]);
			fRec30[0] = ((fSlow17 > fVec1[1]) ? fSlow19 : fThen0);
			float fTemp4 = (fSlow25 * fRec30[0]);
			fVec2[(IOTA & 8191)] = ((fRec25[1] + fTemp3) + fTemp4);
			fRec26[0] = ((0.999426007f * fVec2[((IOTA - iSlow27) & 8191)]) - ((fSlow28 * fRec26[1]) + (fConst14 * fRec26[2])));
			fRec25[0] = (fConst15 * (fRec26[0] - fRec26[2]));
			fRec13[0] = fRec25[0];
			fVec3[(IOTA & 8191)] = (fRec31[1] + (fTemp3 + fTemp4));
			fRec32[0] = ((0.999426007f * fVec3[((IOTA - iSlow29) & 8191)]) - ((fSlow30 * fRec32[1]) + (fConst14 * fRec32[2])));
			fRec31[0] = (fConst15 * (fRec32[0] - fRec32[2]));
			fRec14[0] = fRec31[0];
			float fTemp5 = (fTemp3 + (fSlow31 * fRec30[0]));
			fVec4[(IOTA & 4095)] = (fRec33[1] + fTemp5);
			fRec34[0] = ((0.99948281f * fVec4[((IOTA - iSlow32) & 4095)]) - ((fSlow33 * fRec34[1]) + (fConst14 * fRec34[2])));
			fRec33[0] = (fConst15 * (fRec34[0] - fRec34[2]));
			fRec15[0] = fRec33[0];
			fVec5[(IOTA & 4095)] = (fTemp5 + fRec35[1]);
			fRec36[0] = ((0.99948281f * fVec5[((IOTA - iSlow34) & 4095)]) - ((fSlow35 * fRec36[1]) + (fConst14 * fRec36[2])));
			fRec35[0] = (fConst15 * (fRec36[0] - fRec36[2]));
			fRec16[0] = fRec35[0];
			fVec6[(IOTA & 2047)] = (fRec37[1] + (fTemp3 + (fSlow36 * fRec30[0])));
			fRec38[0] = ((0.999499977f * fVec6[((IOTA - iSlow37) & 2047)]) - ((fSlow38 * fRec38[1]) + (fConst14 * fRec38[2])));
			fRec37[0] = (fConst15 * (fRec38[0] - fRec38[2]));
			fRec17[0] = fRec37[0];
			fRec18[0] = fRec37[0];
			float fTemp6 = (fTemp3 + (fSlow39 * fRec30[0]));
			fVec7[(IOTA & 2047)] = (fRec39[1] + fTemp6);
			fRec40[0] = ((0.999499977f * fVec7[((IOTA - iSlow40) & 2047)]) - ((fSlow41 * fRec40[1]) + (fConst14 * fRec40[2])));
			fRec39[0] = (fConst15 * (fRec40[0] - fRec40[2]));
			fRec19[0] = fRec39[0];
			fVec8[(IOTA & 2047)] = (fTemp6 + fRec41[1]);
			fRec42[0] = ((0.999499977f * fVec8[((IOTA - iSlow42) & 2047)]) - ((fSlow43 * fRec42[1]) + (fConst14 * fRec42[2])));
			fRec41[0] = (fConst15 * (fRec42[0] - fRec42[2]));
			fRec20[0] = fRec41[0];
			float fTemp7 = (fTemp3 + (fSlow44 * fRec30[0]));
			fVec9[(IOTA & 1023)] = (fRec43[1] + fTemp7);
			fRec44[0] = ((0.999465525f * fVec9[((IOTA - iSlow45) & 1023)]) - ((fSlow46 * fRec44[1]) + (fConst14 * fRec44[2])));
			fRec43[0] = (fConst15 * (fRec44[0] - fRec44[2]));
			fRec21[0] = fRec43[0];
			fVec10[(IOTA & 1023)] = (fTemp7 + fRec45[1]);
			fRec46[0] = ((0.999465525f * fVec10[((IOTA - iSlow47) & 1023)]) - ((fSlow48 * fRec46[1]) + (fConst14 * fRec46[2])));
			fRec45[0] = (fConst15 * (fRec46[0] - fRec46[2]));
			fRec22[0] = fRec45[0];
			float fTemp8 = (fTemp3 + (fSlow49 * fRec30[0]));
			fVec11[(IOTA & 1023)] = (fRec47[1] + fTemp8);
			fRec48[0] = ((0.999499977f * fVec11[((IOTA - iSlow50) & 1023)]) - ((fSlow51 * fRec48[1]) + (fConst14 * fRec48[2])));
			fRec47[0] = (fConst15 * (fRec48[0] - fRec48[2]));
			fRec23[0] = fRec47[0];
			fVec12[(IOTA & 511)] = (fTemp8 + fRec49[1]);
			fRec50[0] = ((0.999499977f * fVec12[((IOTA - iSlow52) & 511)]) - ((fSlow53 * fRec50[1]) + (fConst14 * fRec50[2])));
			fRec49[0] = (fConst15 * (fRec50[0] - fRec50[2]));
			fRec24[0] = fRec49[0];
			float fTemp9 = (fRec24[0] + (fRec22[0] + (fRec20[0] + (fRec18[0] + (fRec16[0] + ((((((fRec13[0] + fRec15[0]) + fRec17[0]) + fRec19[0]) + fRec21[0]) + fRec23[0]) + fRec14[0]))))));
			fVec13[0] = fTemp9;
			fRec51[0] = (fSlow54 + (fConst12 * fRec51[1]));
			fRec54[0] = (fSlow57 + (fConst12 * fRec54[1]));
			float fTemp10 = (fRec53[1] + (fConst42 * (fSlow55 + (fSlow56 * fRec54[0]))));
			fRec53[0] = (fTemp10 - std::floor(fTemp10));
			float fTemp11 = (3.14159274f * (fRec51[0] * ftbl0FaustTibetanbowlDSPSIG0[int((65536.0f * fRec53[0]))]));
			float fTemp12 = std::sin(fTemp11);
			float fTemp13 = std::cos(fTemp11);
			float fTemp14 = ((fTemp9 * fTemp13) - (fTemp12 * fRec55[1]));
			float fTemp15 = ((fTemp13 * fTemp14) - (fTemp12 * fRec56[1]));
			float fTemp16 = ((fTemp13 * fTemp15) - (fTemp12 * fRec57[1]));
			float fTemp17 = ((fTemp13 * fTemp16) - (fTemp12 * fRec58[1]));
			float fTemp18 = ((fTemp13 * fTemp17) - (fTemp12 * fRec59[1]));
			fRec60[0] = ((fTemp13 * fTemp18) - (fTemp12 * fRec60[1]));
			fRec59[0] = ((fTemp12 * fTemp18) + (fTemp13 * fRec60[1]));
			fRec58[0] = ((fTemp12 * fTemp17) + (fTemp13 * fRec59[1]));
			fRec57[0] = ((fTemp12 * fTemp16) + (fTemp13 * fRec58[1]));
			fRec56[0] = ((fTemp12 * fTemp15) + (fTemp13 * fRec57[1]));
			fRec55[0] = ((fTemp12 * fTemp14) + (fTemp13 * fRec56[1]));
			float fTemp19 = (fRec51[0] * (((fSlow59 * fTemp9) + (fSlow60 * (fTemp9 + fVec13[1]))) + (fSlow61 * FaustTibetanbowlDSP_faustpower2_f(fTemp9))));
			float fTemp20 = std::sin(fTemp19);
			float fTemp21 = std::cos(fTemp19);
			float fTemp22 = ((fTemp9 * fTemp21) - (fTemp20 * fRec61[1]));
			float fTemp23 = ((fTemp21 * fTemp22) - (fTemp20 * fRec62[1]));
			float fTemp24 = ((fTemp21 * fTemp23) - (fTemp20 * fRec63[1]));
			float fTemp25 = ((fTemp21 * fTemp24) - (fTemp20 * fRec64[1]));
			float fTemp26 = ((fTemp21 * fTemp25) - (fTemp20 * fRec65[1]));
			fRec66[0] = ((fTemp21 * fTemp26) - (fTemp20 * fRec66[1]));
			fRec65[0] = ((fTemp20 * fTemp26) + (fTemp21 * fRec66[1]));
			fRec64[0] = ((fTemp20 * fTemp25) + (fTemp21 * fRec65[1]));
			fRec63[0] = ((fTemp20 * fTemp24) + (fTemp21 * fRec64[1]));
			fRec62[0] = ((fTemp20 * fTemp23) + (fTemp21 * fRec63[1]));
			fRec61[0] = ((fTemp20 * fTemp22) + (fTemp21 * fRec62[1]));
			float fTemp27 = ((fSlow14 * ((fTemp9 * fTemp12) + (fRec55[1] * fTemp13))) + (fSlow58 * ((fRec51[0] * ((fTemp9 * fTemp20) + (fRec61[1] * fTemp21))) + ((1.0f - fRec51[0]) * fTemp9))));
			fVec15[(IOTA & 8191)] = fTemp27;
			float fTemp28 = fVec15[((IOTA - iSlow62) & 8191)];
			fVec16[(IOTA & 4095)] = (fSlow11 * (fRec12[0] * fTemp28));
			float fTemp29 = (0.300000012f * fVec16[((IOTA - iConst43) & 4095)]);
			float fTemp30 = (((0.600000024f * fRec8[1]) + fVec0[((IOTA - iConst10) & 32767)]) - fTemp29);
			fVec17[(IOTA & 2047)] = fTemp30;
			fRec8[0] = fVec17[((IOTA - iConst44) & 2047)];
			float fRec9 = (0.0f - (0.600000024f * fTemp30));
			fRec70[0] = (0.0f - (fConst7 * ((fConst8 * fRec70[1]) - (fRec3[1] + fRec3[2]))));
			fRec69[0] = ((fSlow69 * fRec69[1]) + (fSlow70 * (fRec3[1] + (fSlow71 * fRec70[0]))));
			fVec18[(IOTA & 32767)] = ((0.353553385f * fRec69[0]) + 9.99999968e-21f);
			float fTemp31 = (((0.600000024f * fRec67[1]) + fVec18[((IOTA - iConst50) & 32767)]) - fTemp29);
			fVec19[(IOTA & 4095)] = fTemp31;
			fRec67[0] = fVec19[((IOTA - iConst51) & 4095)];
			float fRec68 = (0.0f - (0.600000024f * fTemp31));
			fRec74[0] = (0.0f - (fConst7 * ((fConst8 * fRec74[1]) - (fRec5[1] + fRec5[2]))));
			fRec73[0] = ((fSlow78 * fRec73[1]) + (fSlow79 * (fRec5[1] + (fSlow80 * fRec74[0]))));
			fVec20[(IOTA & 16383)] = ((0.353553385f * fRec73[0]) + 9.99999968e-21f);
			float fTemp32 = (fVec20[((IOTA - iConst57) & 16383)] + (fTemp29 + (0.600000024f * fRec71[1])));
			fVec21[(IOTA & 4095)] = fTemp32;
			fRec71[0] = fVec21[((IOTA - iConst58) & 4095)];
			float fRec72 = (0.0f - (0.600000024f * fTemp32));
			fRec78[0] = (0.0f - (fConst7 * ((fConst8 * fRec78[1]) - (fRec1[1] + fRec1[2]))));
			fRec77[0] = ((fSlow87 * fRec77[1]) + (fSlow88 * (fRec1[1] + (fSlow89 * fRec78[0]))));
			fVec22[(IOTA & 32767)] = ((0.353553385f * fRec77[0]) + 9.99999968e-21f);
			float fTemp33 = (fTemp29 + ((0.600000024f * fRec75[1]) + fVec22[((IOTA - iConst64) & 32767)]));
			fVec23[(IOTA & 4095)] = fTemp33;
			fRec75[0] = fVec23[((IOTA - iConst65) & 4095)];
			float fRec76 = (0.0f - (0.600000024f * fTemp33));
			fRec82[0] = (0.0f - (fConst7 * ((fConst8 * fRec82[1]) - (fRec6[1] + fRec6[2]))));
			fRec81[0] = ((fSlow96 * fRec81[1]) + (fSlow97 * (fRec6[1] + (fSlow98 * fRec82[0]))));
			fVec24[(IOTA & 16383)] = ((0.353553385f * fRec81[0]) + 9.99999968e-21f);
			fVec25[(IOTA & 4095)] = (fSlow99 * (fRec12[0] * fTemp27));
			float fTemp34 = (0.300000012f * fVec25[((IOTA - iConst43) & 4095)]);
			float fTemp35 = (fVec24[((IOTA - iConst71) & 16383)] - (fTemp34 + (0.600000024f * fRec79[1])));
			fVec26[(IOTA & 2047)] = fTemp35;
			fRec79[0] = fVec26[((IOTA - iConst72) & 2047)];
			float fRec80 = (0.600000024f * fTemp35);
			fRec86[0] = (0.0f - (fConst7 * ((fConst8 * fRec86[1]) - (fRec2[1] + fRec2[2]))));
			fRec85[0] = ((fSlow106 * fRec85[1]) + (fSlow107 * (fRec2[1] + (fSlow108 * fRec86[0]))));
			fVec27[(IOTA & 16383)] = ((0.353553385f * fRec85[0]) + 9.99999968e-21f);
			float fTemp36 = (fVec27[((IOTA - iConst78) & 16383)] - (fTemp34 + (0.600000024f * fRec83[1])));
			fVec28[(IOTA & 4095)] = fTemp36;
			fRec83[0] = fVec28[((IOTA - iConst79) & 4095)];
			float fRec84 = (0.600000024f * fTemp36);
			fRec90[0] = (0.0f - (fConst7 * ((fConst8 * fRec90[1]) - (fRec4[1] + fRec4[2]))));
			fRec89[0] = ((fSlow115 * fRec89[1]) + (fSlow116 * (fRec4[1] + (fSlow117 * fRec90[0]))));
			fVec29[(IOTA & 16383)] = ((0.353553385f * fRec89[0]) + 9.99999968e-21f);
			float fTemp37 = ((fTemp34 + fVec29[((IOTA - iConst85) & 16383)]) - (0.600000024f * fRec87[1]));
			fVec30[(IOTA & 4095)] = fTemp37;
			fRec87[0] = fVec30[((IOTA - iConst86) & 4095)];
			float fRec88 = (0.600000024f * fTemp37);
			fRec94[0] = (0.0f - (fConst7 * ((fConst8 * fRec94[1]) - (fRec0[1] + fRec0[2]))));
			fRec93[0] = ((fSlow124 * fRec93[1]) + (fSlow125 * (fRec0[1] + (fSlow126 * fRec94[0]))));
			fVec31[(IOTA & 16383)] = ((0.353553385f * fRec93[0]) + 9.99999968e-21f);
			float fTemp38 = ((fVec31[((IOTA - iConst92) & 16383)] + fTemp34) - (0.600000024f * fRec91[1]));
			fVec32[(IOTA & 2047)] = fTemp38;
			fRec91[0] = fVec32[((IOTA - iConst93) & 2047)];
			float fRec92 = (0.600000024f * fTemp38);
			float fTemp39 = (fRec92 + fRec88);
			float fTemp40 = (fRec80 + (fRec84 + fTemp39));
			fRec0[0] = (fRec8[1] + (fRec67[1] + (fRec71[1] + (fRec75[1] + (fRec79[1] + (fRec83[1] + (fRec87[1] + (fRec91[1] + (fRec9 + (fRec68 + (fRec72 + (fRec76 + fTemp40))))))))))));
			fRec1[0] = ((fRec79[1] + (fRec83[1] + (fRec87[1] + (fRec91[1] + fTemp40)))) - (fRec8[1] + (fRec67[1] + (fRec71[1] + (fRec75[1] + (fRec9 + (fRec68 + (fRec76 + fRec72))))))));
			float fTemp41 = (fRec84 + fRec80);
			fRec2[0] = ((fRec71[1] + (fRec75[1] + (fRec87[1] + (fRec91[1] + (fRec72 + (fRec76 + fTemp39)))))) - (fRec8[1] + (fRec67[1] + (fRec79[1] + (fRec83[1] + (fRec9 + (fRec68 + fTemp41)))))));
			fRec3[0] = ((fRec8[1] + (fRec67[1] + (fRec87[1] + (fRec91[1] + (fRec9 + (fRec68 + fTemp39)))))) - (fRec71[1] + (fRec75[1] + (fRec79[1] + (fRec83[1] + (fRec72 + (fRec76 + fTemp41)))))));
			float fTemp42 = (fRec92 + fRec84);
			float fTemp43 = (fRec88 + fRec80);
			fRec4[0] = ((fRec67[1] + (fRec75[1] + (fRec83[1] + (fRec91[1] + (fRec68 + (fRec76 + fTemp42)))))) - (fRec8[1] + (fRec71[1] + (fRec79[1] + (fRec87[1] + (fRec9 + (fRec72 + fTemp43)))))));
			fRec5[0] = ((fRec8[1] + (fRec71[1] + (fRec83[1] + (fRec91[1] + (fRec9 + (fRec72 + fTemp42)))))) - (fRec67[1] + (fRec75[1] + (fRec79[1] + (fRec87[1] + (fRec68 + (fRec76 + fTemp43)))))));
			float fTemp44 = (fRec92 + fRec80);
			float fTemp45 = (fRec88 + fRec84);
			fRec6[0] = ((fRec8[1] + (fRec75[1] + (fRec79[1] + (fRec91[1] + (fRec9 + (fRec76 + fTemp44)))))) - (fRec67[1] + (fRec71[1] + (fRec83[1] + (fRec87[1] + (fRec68 + (fRec72 + fTemp45)))))));
			fRec7[0] = ((fRec67[1] + (fRec71[1] + (fRec79[1] + (fRec91[1] + (fRec68 + (fRec72 + fTemp44)))))) - (fRec8[1] + (fRec75[1] + (fRec83[1] + (fRec87[1] + (fRec9 + (fRec76 + fTemp45)))))));
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
			fRec18[1] = fRec18[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec19[1] = fRec19[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec20[1] = fRec20[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec21[1] = fRec21[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec22[1] = fRec22[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec23[1] = fRec23[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec24[1] = fRec24[0];
			fVec13[1] = fVec13[0];
			fRec51[1] = fRec51[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec8[1] = fRec8[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec74[1] = fRec74[0];
			fRec73[1] = fRec73[0];
			fRec71[1] = fRec71[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec75[1] = fRec75[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec79[1] = fRec79[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec83[1] = fRec83[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
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
