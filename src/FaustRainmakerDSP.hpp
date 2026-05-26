/* ------------------------------------------------------------
name: "rainmaker"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustRainmakerDSP_H__
#define  __FaustRainmakerDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustRainmakerDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec14[2];
	
  public:
	
	int getNumInputsFaustRainmakerDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustRainmakerDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustRainmakerDSPSIG0(int sample_rate) {
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iVec1[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec14[l4] = 0;
		}
	}
	
	void fillFaustRainmakerDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec14[0] = ((iVec1[1] + iRec14[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec14[0])));
			iVec1[1] = iVec1[0];
			iRec14[1] = iRec14[0];
		}
	}

};

static FaustRainmakerDSPSIG0* newFaustRainmakerDSPSIG0() { return (FaustRainmakerDSPSIG0*)new FaustRainmakerDSPSIG0(); }
static void deleteFaustRainmakerDSPSIG0(FaustRainmakerDSPSIG0* dsp) { delete dsp; }

static float FaustRainmakerDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustRainmakerDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustRainmakerDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustRainmakerDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst3;
	float fConst4;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider0;
	float fConst8;
	float fConst9;
	float fConst11;
	float fConst12;
	float fRec11[2];
	float fRec10[2];
	float fVec0[3];
	int iConst14;
	float fConst15;
	FAUSTFLOAT fHslider1;
	float fRec15[2];
	float fRec13[2];
	int iRec16[2];
	float fConst16;
	float fConst17;
	FAUSTFLOAT fHslider2;
	float fConst18;
	float fRec17[2];
	float fRec12[3];
	int IOTA;
	float fVec2[4096];
	int iConst19;
	float fVec3[3];
	int iConst20;
	float fRec8[2];
	float fConst23;
	float fConst24;
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec21[2];
	float fRec20[2];
	float fVec4[3];
	int iConst30;
	float fVec5[3];
	int iConst31;
	float fRec18[2];
	float fConst34;
	float fConst35;
	float fConst37;
	float fConst38;
	float fConst39;
	float fRec25[2];
	float fRec24[2];
	float fVec6[3];
	int iConst41;
	float fVec7[3];
	int iConst42;
	float fRec22[2];
	float fConst45;
	float fConst46;
	float fConst48;
	float fConst49;
	float fConst50;
	float fRec29[2];
	float fRec28[2];
	float fVec8[3];
	int iConst52;
	float fVec9[3];
	int iConst53;
	float fRec26[2];
	float fConst56;
	float fConst57;
	float fConst59;
	float fConst60;
	float fConst61;
	float fRec33[2];
	float fRec32[2];
	float fVec10[3];
	int iConst63;
	float fVec11[3];
	int iConst64;
	float fRec30[2];
	float fConst67;
	float fConst68;
	float fConst70;
	float fConst71;
	float fConst72;
	float fRec37[2];
	float fRec36[2];
	float fVec12[3];
	int iConst74;
	float fVec13[3];
	int iConst75;
	float fRec34[2];
	float fConst78;
	float fConst79;
	float fConst81;
	float fConst82;
	float fConst83;
	float fRec41[2];
	float fRec40[2];
	float fVec14[3];
	int iConst85;
	float fVec15[3];
	int iConst86;
	float fRec38[2];
	float fConst89;
	float fConst90;
	float fConst92;
	float fConst93;
	float fConst94;
	float fRec45[2];
	float fRec44[2];
	float fVec16[3];
	int iConst96;
	float fVec17[3];
	int iConst97;
	float fRec42[2];
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
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "rainmaker.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "rainmaker");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		FaustRainmakerDSPSIG0* sig0 = newFaustRainmakerDSPSIG0();
		sig0->instanceInitFaustRainmakerDSPSIG0(sample_rate);
		sig0->fillFaustRainmakerDSPSIG0(65536, ftbl0FaustRainmakerDSPSIG0);
		deleteFaustRainmakerDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::floor(((0.219990999f * fConst0) + 0.5f));
		float fConst2 = ((0.0f - (6.90775537f * fConst1)) / fConst0);
		fConst3 = std::exp(fConst2);
		fConst4 = FaustRainmakerDSP_faustpower2_f(fConst3);
		float fConst5 = (1.0f - fConst4);
		fConst6 = (1.0f / fConst5);
		fConst7 = (6.28318548f / fConst0);
		fConst8 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst5));
		fConst9 = ((std::exp((0.125f * fConst2)) / fConst3) + -1.0f);
		float fConst10 = (1.0f / std::tan((628.318542f / fConst0)));
		fConst11 = (1.0f / (fConst10 + 1.0f));
		fConst12 = (1.0f - fConst10);
		float fConst13 = std::floor(((0.0191229992f * fConst0) + 0.5f));
		iConst14 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst1 - fConst13))));
		fConst15 = (1.0f / fConst0);
		fConst16 = (3.14159274f / fConst0);
		fConst17 = (44.0999985f / fConst0);
		fConst18 = (1.0f - fConst17);
		iConst19 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (0.0120000001f * fConst0))));
		iConst20 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst13 + -1.0f))));
		float fConst21 = std::floor(((0.256891012f * fConst0) + 0.5f));
		float fConst22 = ((0.0f - (6.90775537f * fConst21)) / fConst0);
		fConst23 = std::exp(fConst22);
		fConst24 = FaustRainmakerDSP_faustpower2_f(fConst23);
		float fConst25 = (1.0f - fConst24);
		fConst26 = (1.0f / fConst25);
		fConst27 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst25));
		fConst28 = ((std::exp((0.125f * fConst22)) / fConst23) + -1.0f);
		float fConst29 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		iConst30 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst21 - fConst29))));
		iConst31 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst29 + -1.0f))));
		float fConst32 = std::floor(((0.192303002f * fConst0) + 0.5f));
		float fConst33 = ((0.0f - (6.90775537f * fConst32)) / fConst0);
		fConst34 = std::exp(fConst33);
		fConst35 = FaustRainmakerDSP_faustpower2_f(fConst34);
		float fConst36 = (1.0f - fConst35);
		fConst37 = (1.0f / fConst36);
		fConst38 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst36));
		fConst39 = ((std::exp((0.125f * fConst33)) / fConst34) + -1.0f);
		float fConst40 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		iConst41 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst32 - fConst40))));
		iConst42 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst40 + -1.0f))));
		float fConst43 = std::floor(((0.210389003f * fConst0) + 0.5f));
		float fConst44 = ((0.0f - (6.90775537f * fConst43)) / fConst0);
		fConst45 = std::exp(fConst44);
		fConst46 = FaustRainmakerDSP_faustpower2_f(fConst45);
		float fConst47 = (1.0f - fConst46);
		fConst48 = (1.0f / fConst47);
		fConst49 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst47));
		fConst50 = ((std::exp((0.125f * fConst44)) / fConst45) + -1.0f);
		float fConst51 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		iConst52 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst43 - fConst51))));
		iConst53 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst51 + -1.0f))));
		float fConst54 = std::floor(((0.125f * fConst0) + 0.5f));
		float fConst55 = ((0.0f - (6.90775537f * fConst54)) / fConst0);
		fConst56 = std::exp(fConst55);
		fConst57 = FaustRainmakerDSP_faustpower2_f(fConst56);
		float fConst58 = (1.0f - fConst57);
		fConst59 = (1.0f / fConst58);
		fConst60 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst58));
		fConst61 = ((std::exp((0.125f * fConst55)) / fConst56) + -1.0f);
		float fConst62 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		iConst63 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst54 - fConst62))));
		iConst64 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst62 + -1.0f))));
		float fConst65 = std::floor(((0.127837002f * fConst0) + 0.5f));
		float fConst66 = ((0.0f - (6.90775537f * fConst65)) / fConst0);
		fConst67 = std::exp(fConst66);
		fConst68 = FaustRainmakerDSP_faustpower2_f(fConst67);
		float fConst69 = (1.0f - fConst68);
		fConst70 = (1.0f / fConst69);
		fConst71 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst69));
		fConst72 = ((std::exp((0.125f * fConst66)) / fConst67) + -1.0f);
		float fConst73 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		iConst74 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst65 - fConst73))));
		iConst75 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst73 + -1.0f))));
		float fConst76 = std::floor(((0.174713001f * fConst0) + 0.5f));
		float fConst77 = ((0.0f - (6.90775537f * fConst76)) / fConst0);
		fConst78 = std::exp(fConst77);
		fConst79 = FaustRainmakerDSP_faustpower2_f(fConst78);
		float fConst80 = (1.0f - fConst79);
		fConst81 = (1.0f / fConst80);
		fConst82 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst80));
		fConst83 = ((std::exp((0.125f * fConst77)) / fConst78) + -1.0f);
		float fConst84 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		iConst85 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst76 - fConst84))));
		iConst86 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst84 + -1.0f))));
		float fConst87 = std::floor(((0.153128996f * fConst0) + 0.5f));
		float fConst88 = ((0.0f - (6.90775537f * fConst87)) / fConst0);
		fConst89 = std::exp(fConst88);
		fConst90 = FaustRainmakerDSP_faustpower2_f(fConst89);
		float fConst91 = (1.0f - fConst90);
		fConst92 = (1.0f / fConst91);
		fConst93 = (1.0f / FaustRainmakerDSP_faustpower2_f(fConst91));
		fConst94 = ((std::exp((0.125f * fConst88)) / fConst89) + -1.0f);
		float fConst95 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		iConst96 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst87 - fConst95))));
		iConst97 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fConst95 + -1.0f))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.050000000000000003f);
		fHslider2 = FAUSTFLOAT(220.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec11[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec10[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec15[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec13[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec16[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec17[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec12[l9] = 0.0f;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 4096); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec21[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec20[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fVec5[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec18[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec25[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec24[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fVec6[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fVec7[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec22[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec29[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec28[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fVec8[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fVec9[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec26[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec33[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec32[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fVec10[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fVec11[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec30[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec37[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec36[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fVec12[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fVec13[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec34[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec41[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec40[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fVec14[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fVec15[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec38[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec45[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec44[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fVec16[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fVec17[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec42[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec0[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec1[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec2[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec3[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec4[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec5[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec6[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec7[l55] = 0.0f;
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
	
	virtual FaustRainmakerDSP* clone() {
		return new FaustRainmakerDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("rainmaker");
		ui_interface->addHorizontalSlider("Instrument_Material", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("Tilt_Speed_Hz", &fHslider1, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(220.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = (float(fHslider0) == 0.0f);
		float fSlow1 = std::cos((fConst7 * float((iSlow0 ? 3000 : 6000))));
		float fSlow2 = (1.0f - (fConst4 * fSlow1));
		float fSlow3 = (fConst6 * fSlow2);
		float fSlow4 = std::sqrt(std::max<float>(0.0f, ((fConst8 * FaustRainmakerDSP_faustpower2_f(fSlow2)) + -1.0f)));
		float fSlow5 = (fSlow3 - fSlow4);
		float fSlow6 = (fSlow4 + (1.0f - fSlow3));
		float fSlow7 = (fConst15 * float(fHslider1));
		float fSlow8 = float((iSlow0 ? 150 : 45));
		float fSlow9 = (fConst17 * float(fHslider2));
		float fSlow10 = (1.0f - (fConst24 * fSlow1));
		float fSlow11 = (fConst26 * fSlow10);
		float fSlow12 = std::sqrt(std::max<float>(0.0f, ((fConst27 * FaustRainmakerDSP_faustpower2_f(fSlow10)) + -1.0f)));
		float fSlow13 = (fSlow11 - fSlow12);
		float fSlow14 = (fSlow12 + (1.0f - fSlow11));
		float fSlow15 = (1.0f - (fConst35 * fSlow1));
		float fSlow16 = (fConst37 * fSlow15);
		float fSlow17 = std::sqrt(std::max<float>(0.0f, ((fConst38 * FaustRainmakerDSP_faustpower2_f(fSlow15)) + -1.0f)));
		float fSlow18 = (fSlow16 - fSlow17);
		float fSlow19 = (fSlow17 + (1.0f - fSlow16));
		float fSlow20 = (1.0f - (fConst46 * fSlow1));
		float fSlow21 = (fConst48 * fSlow20);
		float fSlow22 = std::sqrt(std::max<float>(0.0f, ((fConst49 * FaustRainmakerDSP_faustpower2_f(fSlow20)) + -1.0f)));
		float fSlow23 = (fSlow21 - fSlow22);
		float fSlow24 = (fSlow22 + (1.0f - fSlow21));
		float fSlow25 = (1.0f - (fConst57 * fSlow1));
		float fSlow26 = (fConst59 * fSlow25);
		float fSlow27 = std::sqrt(std::max<float>(0.0f, ((fConst60 * FaustRainmakerDSP_faustpower2_f(fSlow25)) + -1.0f)));
		float fSlow28 = (fSlow26 - fSlow27);
		float fSlow29 = (fSlow27 + (1.0f - fSlow26));
		float fSlow30 = (1.0f - (fConst68 * fSlow1));
		float fSlow31 = (fConst70 * fSlow30);
		float fSlow32 = std::sqrt(std::max<float>(0.0f, ((fConst71 * FaustRainmakerDSP_faustpower2_f(fSlow30)) + -1.0f)));
		float fSlow33 = (fSlow31 - fSlow32);
		float fSlow34 = (fSlow32 + (1.0f - fSlow31));
		float fSlow35 = (1.0f - (fConst79 * fSlow1));
		float fSlow36 = (fConst81 * fSlow35);
		float fSlow37 = std::sqrt(std::max<float>(0.0f, ((fConst82 * FaustRainmakerDSP_faustpower2_f(fSlow35)) + -1.0f)));
		float fSlow38 = (fSlow36 - fSlow37);
		float fSlow39 = (fSlow37 + (1.0f - fSlow36));
		float fSlow40 = (1.0f - (fConst90 * fSlow1));
		float fSlow41 = (fConst92 * fSlow40);
		float fSlow42 = std::sqrt(std::max<float>(0.0f, ((fConst93 * FaustRainmakerDSP_faustpower2_f(fSlow40)) + -1.0f)));
		float fSlow43 = (fSlow41 - fSlow42);
		float fSlow44 = (fSlow42 + (1.0f - fSlow41));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (0.0f - (fConst11 * ((fConst12 * fRec11[1]) - (fRec7[1] + fRec7[2]))));
			fRec11[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((fRec10[1] * fSlow5) + (fConst3 * ((fRec7[1] + (fConst9 * fRec11[0])) * fSlow6)));
			fRec10[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			fVec0[0] = ((0.353553385f * fRec10[0]) + 9.99999968e-21f);
			float fTempFTZ2 = (fSlow7 + (fRec15[1] - std::floor((fSlow7 + fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.999000013f * fRec13[1]) + (0.00100000005f * std::fabs(ftbl0FaustRainmakerDSPSIG0[int((65536.0f * fRec15[0]))])));
			fRec13[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			iRec16[0] = ((1103515245 * iRec16[1]) + 12345);
			float fTempFTZ4 = (fSlow9 + (fConst18 * fRec17[1]));
			fRec17[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp0 = std::tan((fConst16 * fRec17[0]));
			float fTemp1 = (1.0f / fTemp0);
			float fTemp2 = (((fTemp1 + 0.5f) / fTemp0) + 1.0f);
			float fTempFTZ5 = ((3.10440866e-12f * ((fRec13[0] * fSlow8) * float(iRec16[0]))) - (((fRec12[2] * (((fTemp1 + -0.5f) / fTemp0) + 1.0f)) + (2.0f * (fRec12[1] * (1.0f - (1.0f / FaustRainmakerDSP_faustpower2_f(fTemp0)))))) / fTemp2));
			fRec12[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp3 = (fTemp0 * fTemp2);
			fVec2[(IOTA & 4095)] = ((fRec12[0] / fTemp3) + (fRec12[2] * (0.0f - (1.0f / fTemp3))));
			float fTemp4 = (0.300000012f * fVec2[((IOTA - iConst19) & 4095)]);
			float fTemp5 = (((0.600000024f * fRec8[1]) + fVec0[iConst14]) - fTemp4);
			fVec3[0] = fTemp5;
			float fTempFTZ6 = fVec3[iConst20];
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.0f - (0.600000024f * fTemp5));
			float fRec9 = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (0.0f - (fConst11 * ((fConst12 * fRec21[1]) - (fRec3[1] + fRec3[2]))));
			fRec21[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((fRec20[1] * fSlow13) + (fConst23 * ((fRec3[1] + (fConst28 * fRec21[0])) * fSlow14)));
			fRec20[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			fVec4[0] = ((0.353553385f * fRec20[0]) + 9.99999968e-21f);
			float fTemp6 = (((0.600000024f * fRec18[1]) + fVec4[iConst30]) - fTemp4);
			fVec5[0] = fTemp6;
			float fTempFTZ10 = fVec5[iConst31];
			fRec18[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (0.0f - (0.600000024f * fTemp6));
			float fRec19 = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (0.0f - (fConst11 * ((fConst12 * fRec25[1]) - (fRec5[1] + fRec5[2]))));
			fRec25[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = ((fRec24[1] * fSlow18) + (fConst34 * ((fRec5[1] + (fConst39 * fRec25[0])) * fSlow19)));
			fRec24[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			fVec6[0] = ((0.353553385f * fRec24[0]) + 9.99999968e-21f);
			float fTemp7 = (fVec6[iConst41] + (fTemp4 + (0.600000024f * fRec22[1])));
			fVec7[0] = fTemp7;
			float fTempFTZ14 = fVec7[iConst42];
			fRec22[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (0.0f - (0.600000024f * fTemp7));
			float fRec23 = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (0.0f - (fConst11 * ((fConst12 * fRec29[1]) - (fRec1[1] + fRec1[2]))));
			fRec29[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = ((fRec28[1] * fSlow23) + (fConst45 * ((fRec1[1] + (fConst50 * fRec29[0])) * fSlow24)));
			fRec28[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			fVec8[0] = ((0.353553385f * fRec28[0]) + 9.99999968e-21f);
			float fTemp8 = (fVec8[iConst52] + (fTemp4 + (0.600000024f * fRec26[1])));
			fVec9[0] = fTemp8;
			float fTempFTZ18 = fVec9[iConst53];
			fRec26[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (0.0f - (0.600000024f * fTemp8));
			float fRec27 = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (0.0f - (fConst11 * ((fConst12 * fRec33[1]) - (fRec6[1] + fRec6[2]))));
			fRec33[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = ((fRec32[1] * fSlow28) + (fConst56 * ((fRec6[1] + (fConst61 * fRec33[0])) * fSlow29)));
			fRec32[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			fVec10[0] = ((0.353553385f * fRec32[0]) + 9.99999968e-21f);
			float fTemp9 = (fVec10[iConst63] - (fTemp4 + (0.600000024f * fRec30[1])));
			fVec11[0] = fTemp9;
			float fTempFTZ22 = fVec11[iConst64];
			fRec30[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (0.600000024f * fTemp9);
			float fRec31 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (0.0f - (fConst11 * ((fConst12 * fRec37[1]) - (fRec2[1] + fRec2[2]))));
			fRec37[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = ((fRec36[1] * fSlow33) + (fConst67 * ((fRec2[1] + (fConst72 * fRec37[0])) * fSlow34)));
			fRec36[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			fVec12[0] = ((0.353553385f * fRec36[0]) + 9.99999968e-21f);
			float fTemp10 = (fVec12[iConst74] - (fTemp4 + (0.600000024f * fRec34[1])));
			fVec13[0] = fTemp10;
			float fTempFTZ26 = fVec13[iConst75];
			fRec34[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (0.600000024f * fTemp10);
			float fRec35 = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (0.0f - (fConst11 * ((fConst12 * fRec41[1]) - (fRec4[1] + fRec4[2]))));
			fRec41[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = ((fRec40[1] * fSlow38) + (fConst78 * ((fRec4[1] + (fConst83 * fRec41[0])) * fSlow39)));
			fRec40[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			fVec14[0] = ((0.353553385f * fRec40[0]) + 9.99999968e-21f);
			float fTemp11 = ((fTemp4 + fVec14[iConst85]) - (0.600000024f * fRec38[1]));
			fVec15[0] = fTemp11;
			float fTempFTZ30 = fVec15[iConst86];
			fRec38[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (0.600000024f * fTemp11);
			float fRec39 = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (0.0f - (fConst11 * ((fConst12 * fRec45[1]) - (fRec0[1] + fRec0[2]))));
			fRec45[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = ((fRec44[1] * fSlow43) + (fConst89 * ((fRec0[1] + (fConst94 * fRec45[0])) * fSlow44)));
			fRec44[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			fVec16[0] = ((0.353553385f * fRec44[0]) + 9.99999968e-21f);
			float fTemp12 = ((fVec16[iConst96] + fTemp4) - (0.600000024f * fRec42[1]));
			fVec17[0] = fTemp12;
			float fTempFTZ34 = fVec17[iConst97];
			fRec42[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (0.600000024f * fTemp12);
			float fRec43 = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTemp13 = (fRec43 + fRec39);
			float fTemp14 = (fRec31 + (fRec35 + fTemp13));
			float fTempFTZ36 = (fRec8[1] + (fRec18[1] + (fRec22[1] + (fRec26[1] + (fRec30[1] + (fRec34[1] + (fRec38[1] + (fRec42[1] + (fRec9 + (fRec19 + (fRec23 + (fRec27 + fTemp14))))))))))));
			fRec0[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = ((fRec30[1] + (fRec34[1] + (fRec38[1] + (fRec42[1] + fTemp14)))) - (fRec8[1] + (fRec18[1] + (fRec22[1] + (fRec26[1] + (fRec9 + (fRec19 + (fRec27 + fRec23))))))));
			fRec1[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTemp15 = (fRec35 + fRec31);
			float fTempFTZ38 = ((fRec22[1] + (fRec26[1] + (fRec38[1] + (fRec42[1] + (fRec23 + (fRec27 + fTemp13)))))) - (fRec8[1] + (fRec18[1] + (fRec30[1] + (fRec34[1] + (fRec9 + (fRec19 + fTemp15)))))));
			fRec2[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = ((fRec8[1] + (fRec18[1] + (fRec38[1] + (fRec42[1] + (fRec9 + (fRec19 + fTemp13)))))) - (fRec22[1] + (fRec26[1] + (fRec30[1] + (fRec34[1] + (fRec23 + (fRec27 + fTemp15)))))));
			fRec3[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTemp16 = (fRec43 + fRec35);
			float fTemp17 = (fRec39 + fRec31);
			float fTempFTZ40 = ((fRec18[1] + (fRec26[1] + (fRec34[1] + (fRec42[1] + (fRec19 + (fRec27 + fTemp16)))))) - (fRec8[1] + (fRec22[1] + (fRec30[1] + (fRec38[1] + (fRec9 + (fRec23 + fTemp17)))))));
			fRec4[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = ((fRec8[1] + (fRec22[1] + (fRec34[1] + (fRec42[1] + (fRec9 + (fRec23 + fTemp16)))))) - (fRec18[1] + (fRec26[1] + (fRec30[1] + (fRec38[1] + (fRec19 + (fRec27 + fTemp17)))))));
			fRec5[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTemp18 = (fRec43 + fRec31);
			float fTemp19 = (fRec39 + fRec35);
			float fTempFTZ42 = ((fRec8[1] + (fRec26[1] + (fRec30[1] + (fRec42[1] + (fRec9 + (fRec27 + fTemp18)))))) - (fRec18[1] + (fRec22[1] + (fRec34[1] + (fRec38[1] + (fRec19 + (fRec23 + fTemp19)))))));
			fRec6[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = ((fRec18[1] + (fRec22[1] + (fRec30[1] + (fRec42[1] + (fRec19 + (fRec23 + fTemp18)))))) - (fRec8[1] + (fRec26[1] + (fRec34[1] + (fRec38[1] + (fRec9 + (fRec27 + fTemp19)))))));
			fRec7[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			output0[i0] = FAUSTFLOAT((0.370000005f * (fRec1[0] + fRec2[0])));
			output1[i0] = FAUSTFLOAT((0.370000005f * (fRec1[0] - fRec2[0])));
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			iRec16[1] = iRec16[0];
			fRec17[1] = fRec17[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			IOTA = (IOTA + 1);
			fVec3[2] = fVec3[1];
			fVec3[1] = fVec3[0];
			fRec8[1] = fRec8[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fVec4[2] = fVec4[1];
			fVec4[1] = fVec4[0];
			fVec5[2] = fVec5[1];
			fVec5[1] = fVec5[0];
			fRec18[1] = fRec18[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fVec6[2] = fVec6[1];
			fVec6[1] = fVec6[0];
			fVec7[2] = fVec7[1];
			fVec7[1] = fVec7[0];
			fRec22[1] = fRec22[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fVec8[2] = fVec8[1];
			fVec8[1] = fVec8[0];
			fVec9[2] = fVec9[1];
			fVec9[1] = fVec9[0];
			fRec26[1] = fRec26[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fVec10[2] = fVec10[1];
			fVec10[1] = fVec10[0];
			fVec11[2] = fVec11[1];
			fVec11[1] = fVec11[0];
			fRec30[1] = fRec30[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fVec12[2] = fVec12[1];
			fVec12[1] = fVec12[0];
			fVec13[2] = fVec13[1];
			fVec13[1] = fVec13[0];
			fRec34[1] = fRec34[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fVec14[2] = fVec14[1];
			fVec14[1] = fVec14[0];
			fVec15[2] = fVec15[1];
			fVec15[1] = fVec15[0];
			fRec38[1] = fRec38[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fVec16[2] = fVec16[1];
			fVec16[1] = fVec16[0];
			fVec17[2] = fVec17[1];
			fVec17[1] = fVec17[0];
			fRec42[1] = fRec42[0];
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
