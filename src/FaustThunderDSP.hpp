/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "thunder"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustThunderDSP_H__
#define  __FaustThunderDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustThunderDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustThunderDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustThunderDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	float fConst5;
	float fConst7;
	int iRec12[2];
	float fConst8;
	float fConst9;
	float fConst10;
	float fRec11[3];
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec13[2];
	float fConst15;
	float fConst19;
	float fRec15[4];
	float fConst20;
	float fConst21;
	float fConst22;
	float fRec14[3];
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec16[3];
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fConst38;
	float fRec18[2];
	int IOTA;
	float fRec17[32768];
	float fVec1[16384];
	float fConst40;
	float fRec10[2];
	float fVec2[65536];
	float fConst42;
	float fVec3[4096];
	float fConst43;
	float fRec8[2];
	float fConst45;
	float fRec21[2];
	float fVec4[65536];
	float fConst47;
	float fVec5[8192];
	float fConst48;
	float fRec19[2];
	float fConst50;
	float fRec24[2];
	float fVec6[65536];
	float fConst52;
	float fVec7[8192];
	float fConst53;
	float fRec22[2];
	float fConst55;
	float fRec27[2];
	float fVec8[65536];
	float fConst57;
	float fVec9[8192];
	float fConst58;
	float fRec25[2];
	float fConst60;
	float fRec30[2];
	float fVec10[32768];
	float fConst62;
	float fVec11[4096];
	float fConst63;
	float fRec28[2];
	float fConst65;
	float fRec33[2];
	float fVec12[32768];
	float fConst67;
	float fVec13[8192];
	float fConst68;
	float fRec31[2];
	float fConst70;
	float fRec36[2];
	float fVec14[65536];
	float fConst72;
	float fVec15[8192];
	float fConst73;
	float fRec34[2];
	float fConst75;
	float fRec39[2];
	float fVec16[32768];
	float fConst77;
	float fVec17[4096];
	float fConst78;
	float fRec37[2];
	float fRec0[2];
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec4[2];
	float fRec5[2];
	float fRec6[2];
	float fRec7[2];
	
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
		m->declare("filename", "thunder.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
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
		m->declare("name", "thunder");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		return 1;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (6.28318548f / fConst0);
		float fConst2 = std::tan((2513.27417f / fConst0));
		float fConst3 = (1.0f / fConst2);
		float fConst4 = (((fConst3 + 1.41421354f) / fConst2) + 1.0f);
		fConst5 = (1.5f / fConst4);
		float fConst6 = FaustThunderDSP_faustpower2_f(fConst2);
		fConst7 = (1.0f / fConst6);
		fConst8 = (1.0f / fConst4);
		fConst9 = (((fConst3 + -1.41421354f) / fConst2) + 1.0f);
		fConst10 = (2.0f * (1.0f - fConst7));
		fConst11 = (0.0f - (2.0f / fConst6));
		fConst12 = (0.00100000005f * fConst0);
		fConst13 = std::max<float>(1.0f, fConst12);
		fConst14 = (1.0f / fConst13);
		fConst15 = (1.0f / std::max<float>(1.0f, (0.600000024f * fConst0)));
		float fConst16 = std::tan((1256.63708f / fConst0));
		float fConst17 = (1.0f / fConst16);
		float fConst18 = (((fConst17 + 0.5f) / fConst16) + 1.0f);
		fConst19 = (1.0f / (fConst16 * fConst18));
		fConst20 = (1.0f / fConst18);
		fConst21 = (((fConst17 + -0.5f) / fConst16) + 1.0f);
		fConst22 = (2.0f * (1.0f - (1.0f / FaustThunderDSP_faustpower2_f(fConst16))));
		fConst23 = (0.0f - fConst19);
		fConst24 = std::max<float>(1.0f, (0.100000001f * fConst0));
		fConst25 = (1.0f / fConst24);
		fConst26 = (1.0f / std::max<float>(1.0f, (3.5f * fConst0)));
		float fConst27 = std::tan((628.318542f / fConst0));
		float fConst28 = (1.0f / fConst27);
		float fConst29 = (((fConst28 + 1.41421354f) / fConst27) + 1.0f);
		fConst30 = (25.0f / fConst29);
		fConst31 = (1.0f / fConst29);
		fConst32 = (((fConst28 + -1.41421354f) / fConst27) + 1.0f);
		fConst33 = (2.0f * (1.0f - (1.0f / FaustThunderDSP_faustpower2_f(fConst27))));
		fConst34 = std::max<float>(1.0f, (0.00999999978f * fConst0));
		fConst35 = (1.0f / fConst34);
		fConst36 = (1.0f / std::max<float>(1.0f, (4.5f * fConst0)));
		fConst37 = (1.0f / (fConst17 + 1.0f));
		fConst38 = (1.0f - fConst17);
		float fConst39 = std::floor(((0.219990999f * fConst0) + 0.5f));
		fConst40 = ((0.0f - (6.90775537f * fConst39)) / fConst0);
		float fConst41 = std::floor(((0.0191229992f * fConst0) + 0.5f));
		fConst42 = std::max<float>(0.0f, (fConst39 - fConst41));
		fConst43 = std::max<float>(0.0f, (fConst41 + -1.0f));
		float fConst44 = std::floor(((0.256891012f * fConst0) + 0.5f));
		fConst45 = ((0.0f - (6.90775537f * fConst44)) / fConst0);
		float fConst46 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		fConst47 = std::max<float>(0.0f, (fConst44 - fConst46));
		fConst48 = std::max<float>(0.0f, (fConst46 + -1.0f));
		float fConst49 = std::floor(((0.192303002f * fConst0) + 0.5f));
		fConst50 = ((0.0f - (6.90775537f * fConst49)) / fConst0);
		float fConst51 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		fConst52 = std::max<float>(0.0f, (fConst49 - fConst51));
		fConst53 = std::max<float>(0.0f, (fConst51 + -1.0f));
		float fConst54 = std::floor(((0.210389003f * fConst0) + 0.5f));
		fConst55 = ((0.0f - (6.90775537f * fConst54)) / fConst0);
		float fConst56 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		fConst57 = std::max<float>(0.0f, (fConst54 - fConst56));
		fConst58 = std::max<float>(0.0f, (fConst56 + -1.0f));
		float fConst59 = std::floor(((0.125f * fConst0) + 0.5f));
		fConst60 = ((0.0f - (6.90775537f * fConst59)) / fConst0);
		float fConst61 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		fConst62 = std::max<float>(0.0f, (fConst59 - fConst61));
		fConst63 = std::max<float>(0.0f, (fConst61 + -1.0f));
		float fConst64 = std::floor(((0.127837002f * fConst0) + 0.5f));
		fConst65 = ((0.0f - (6.90775537f * fConst64)) / fConst0);
		float fConst66 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		fConst67 = std::max<float>(0.0f, (fConst64 - fConst66));
		fConst68 = std::max<float>(0.0f, (fConst66 + -1.0f));
		float fConst69 = std::floor(((0.174713001f * fConst0) + 0.5f));
		fConst70 = ((0.0f - (6.90775537f * fConst69)) / fConst0);
		float fConst71 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		fConst72 = std::max<float>(0.0f, (fConst69 - fConst71));
		fConst73 = std::max<float>(0.0f, (fConst71 + -1.0f));
		float fConst74 = std::floor(((0.153128996f * fConst0) + 0.5f));
		fConst75 = ((0.0f - (6.90775537f * fConst74)) / fConst0);
		float fConst76 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		fConst77 = std::max<float>(0.0f, (fConst74 - fConst76));
		fConst78 = std::max<float>(0.0f, (fConst76 + -1.0f));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec12[l0] = 0;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec11[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec13[l3] = 0;
		}
		for (int l4 = 0; (l4 < 4); l4 = (l4 + 1)) {
			fRec15[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec14[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec16[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec18[l7] = 0.0f;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 32768); l8 = (l8 + 1)) {
			fRec17[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 16384); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 65536); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 4096); l12 = (l12 + 1)) {
			fVec3[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec8[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec21[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 65536); l15 = (l15 + 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 8192); l16 = (l16 + 1)) {
			fVec5[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec19[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec24[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 65536); l19 = (l19 + 1)) {
			fVec6[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 8192); l20 = (l20 + 1)) {
			fVec7[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec22[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec27[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 65536); l23 = (l23 + 1)) {
			fVec8[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 8192); l24 = (l24 + 1)) {
			fVec9[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec25[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec30[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 32768); l27 = (l27 + 1)) {
			fVec10[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 4096); l28 = (l28 + 1)) {
			fVec11[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec33[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 32768); l31 = (l31 + 1)) {
			fVec12[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 8192); l32 = (l32 + 1)) {
			fVec13[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec31[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec36[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 65536); l35 = (l35 + 1)) {
			fVec14[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 8192); l36 = (l36 + 1)) {
			fVec15[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec34[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec39[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 32768); l39 = (l39 + 1)) {
			fVec16[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 4096); l40 = (l40 + 1)) {
			fVec17[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec37[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec0[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec1[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec2[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec3[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec4[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec5[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec6[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec7[l49] = 0.0f;
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
	
	virtual FaustThunderDSP* clone() {
		return new FaustThunderDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("thunder");
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fButton0);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec12[0] = ((1103515245 * iRec12[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * float(iRec12[0]));
			float fTempFTZ0 = (fTemp0 - (fConst8 * ((fConst9 * fRec11[2]) + (fConst10 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec0[0] = fSlow1;
			iRec13[0] = (((iRec13[1] + (iRec13[1] > 0)) * (fSlow1 <= fVec0[1])) + (fSlow1 > fVec0[1]));
			float fTemp1 = float(iRec13[0]);
			float fTemp2 = (fConst5 * ((((fConst7 * fRec11[0]) + (fConst11 * fRec11[1])) + (fConst7 * fRec11[2])) * std::max<float>(0.0f, std::min<float>((fConst14 * fTemp1), ((fConst15 * (fConst13 - fTemp1)) + 1.0f)))));
			float fTempFTZ1 = (((0.522189379f * fRec15[3]) + (fTemp0 + (2.49495602f * fRec15[1]))) - (2.0172658f * fRec15[2]));
			fRec15[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp3 = ((0.0499220341f * fRec15[0]) + (0.0506126992f * fRec15[2]));
			float fTemp4 = ((0.0959935337f * fRec15[1]) + (0.00440878607f * fRec15[3]));
			float fTempFTZ2 = (fTemp3 - (fTemp4 + (fConst20 * ((fConst21 * fRec14[2]) + (fConst22 * fRec14[1])))));
			fRec14[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp5 = (0.600000024f * (((fConst19 * fRec14[0]) + (fConst23 * fRec14[2])) * std::max<float>(0.0f, std::min<float>((fConst25 * fTemp1), ((fConst26 * (fConst24 - fTemp1)) + 1.0f)))));
			float fTempFTZ3 = (fTemp3 - (fTemp4 + (fConst31 * ((fConst32 * fRec16[2]) + (fConst33 * fRec16[1])))));
			fRec16[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp6 = (0.800000012f * (float(tanhf(float((fConst30 * (fRec16[2] + (fRec16[0] + (2.0f * fRec16[1]))))))) * std::max<float>(0.0f, std::min<float>((fConst35 * fTemp1), ((fConst36 * (fConst34 - fTemp1)) + 1.0f)))));
			float fTempFTZ4 = (fConst37 * ((0.5f * (fRec17[((IOTA - 24001) & 32767)] + fRec17[((IOTA - 24002) & 32767)])) - (fConst38 * fRec18[1])));
			fRec18[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp2 + (fTemp5 + (fRec18[0] + fTemp6)));
			fRec17[(IOTA & 32767)] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp7 = (fTemp2 + (fTemp5 + (fTemp6 + (0.699999988f * fRec17[((IOTA - 0) & 32767)]))));
			fVec1[(IOTA & 16383)] = fTemp7;
			float fTemp8 = std::cos((fConst1 * fTemp7));
			float fTemp9 = std::exp((fConst40 / fTemp7));
			float fTemp10 = FaustThunderDSP_faustpower2_f(fTemp9);
			float fTemp11 = (1.0f - (fTemp8 * fTemp10));
			float fTemp12 = (1.0f - fTemp10);
			float fTemp13 = (fTemp11 / fTemp12);
			float fTemp14 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp11) / FaustThunderDSP_faustpower2_f(fTemp12)) + -1.0f)));
			float fTempFTZ6 = ((fRec10[1] * (fTemp13 - fTemp14)) + ((fTemp9 * fRec7[1]) * (fTemp14 + (1.0f - fTemp13))));
			fRec10[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			fVec2[(IOTA & 65535)] = ((0.353553385f * fRec10[0]) + 9.99999968e-21f);
			float fTemp15 = std::floor(((0.0191229992f * fTemp7) + 0.5f));
			float fTemp16 = (0.300000012f * fVec1[((IOTA - int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst12 * fTemp7))))) & 16383)]);
			float fTemp17 = (((0.600000024f * fRec8[1]) + fVec2[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.219990999f * fTemp7) + 0.5f)) - fTemp15)))))))), fConst42))) & 65535)]) - fTemp16);
			fVec3[(IOTA & 4095)] = fTemp17;
			float fTempFTZ7 = fVec3[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp15))))))), fConst43))) & 4095)];
			fRec8[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (0.0f - (0.600000024f * fTemp17));
			float fRec9 = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp18 = std::exp((fConst45 / fTemp7));
			float fTemp19 = FaustThunderDSP_faustpower2_f(fTemp18);
			float fTemp20 = (1.0f - (fTemp8 * fTemp19));
			float fTemp21 = (1.0f - fTemp19);
			float fTemp22 = (fTemp20 / fTemp21);
			float fTemp23 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp20) / FaustThunderDSP_faustpower2_f(fTemp21)) + -1.0f)));
			float fTempFTZ9 = ((fRec21[1] * (fTemp22 - fTemp23)) + ((fTemp18 * fRec3[1]) * (fTemp23 + (1.0f - fTemp22))));
			fRec21[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			fVec4[(IOTA & 65535)] = ((0.353553385f * fRec21[0]) + 9.99999968e-21f);
			float fTemp24 = std::floor(((0.0273330007f * fTemp7) + 0.5f));
			float fTemp25 = (((0.600000024f * fRec19[1]) + fVec4[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.256891012f * fTemp7) + 0.5f)) - fTemp24)))))))), fConst47))) & 65535)]) - fTemp16);
			fVec5[(IOTA & 8191)] = fTemp25;
			float fTempFTZ10 = fVec5[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp24))))))), fConst48))) & 8191)];
			fRec19[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (0.0f - (0.600000024f * fTemp25));
			float fRec20 = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp26 = std::exp((fConst50 / fTemp7));
			float fTemp27 = FaustThunderDSP_faustpower2_f(fTemp26);
			float fTemp28 = (1.0f - (fTemp8 * fTemp27));
			float fTemp29 = (1.0f - fTemp27);
			float fTemp30 = (fTemp28 / fTemp29);
			float fTemp31 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp28) / FaustThunderDSP_faustpower2_f(fTemp29)) + -1.0f)));
			float fTempFTZ12 = ((fRec24[1] * (fTemp30 - fTemp31)) + ((fTemp26 * fRec5[1]) * (fTemp31 + (1.0f - fTemp30))));
			fRec24[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			fVec6[(IOTA & 65535)] = ((0.353553385f * fRec24[0]) + 9.99999968e-21f);
			float fTemp32 = std::floor(((0.0292910002f * fTemp7) + 0.5f));
			float fTemp33 = (fVec6[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.192303002f * fTemp7) + 0.5f)) - fTemp32)))))))), fConst52))) & 65535)] + (fTemp16 + (0.600000024f * fRec22[1])));
			fVec7[(IOTA & 8191)] = fTemp33;
			float fTempFTZ13 = fVec7[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp32))))))), fConst53))) & 8191)];
			fRec22[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (0.0f - (0.600000024f * fTemp33));
			float fRec23 = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp34 = std::exp((fConst55 / fTemp7));
			float fTemp35 = FaustThunderDSP_faustpower2_f(fTemp34);
			float fTemp36 = (1.0f - (fTemp8 * fTemp35));
			float fTemp37 = (1.0f - fTemp35);
			float fTemp38 = (fTemp36 / fTemp37);
			float fTemp39 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp36) / FaustThunderDSP_faustpower2_f(fTemp37)) + -1.0f)));
			float fTempFTZ15 = ((fRec27[1] * (fTemp38 - fTemp39)) + ((fTemp34 * fRec1[1]) * (fTemp39 + (1.0f - fTemp38))));
			fRec27[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			fVec8[(IOTA & 65535)] = ((0.353553385f * fRec27[0]) + 9.99999968e-21f);
			float fTemp40 = std::floor(((0.0244210009f * fTemp7) + 0.5f));
			float fTemp41 = (fVec8[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.210389003f * fTemp7) + 0.5f)) - fTemp40)))))))), fConst57))) & 65535)] + (fTemp16 + (0.600000024f * fRec25[1])));
			fVec9[(IOTA & 8191)] = fTemp41;
			float fTempFTZ16 = fVec9[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp40))))))), fConst58))) & 8191)];
			fRec25[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (0.0f - (0.600000024f * fTemp41));
			float fRec26 = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp42 = std::exp((fConst60 / fTemp7));
			float fTemp43 = FaustThunderDSP_faustpower2_f(fTemp42);
			float fTemp44 = (1.0f - (fTemp8 * fTemp43));
			float fTemp45 = (1.0f - fTemp43);
			float fTemp46 = (fTemp44 / fTemp45);
			float fTemp47 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp44) / FaustThunderDSP_faustpower2_f(fTemp45)) + -1.0f)));
			float fTempFTZ18 = ((fRec30[1] * (fTemp46 - fTemp47)) + ((fTemp42 * fRec6[1]) * (fTemp47 + (1.0f - fTemp46))));
			fRec30[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			fVec10[(IOTA & 32767)] = ((0.353553385f * fRec30[0]) + 9.99999968e-21f);
			float fTemp48 = std::floor(((0.0134579996f * fTemp7) + 0.5f));
			float fTemp49 = (fVec10[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.125f * fTemp7) + 0.5f)) - fTemp48)))))))), fConst62))) & 32767)] - (fTemp16 + (0.600000024f * fRec28[1])));
			fVec11[(IOTA & 4095)] = fTemp49;
			float fTempFTZ19 = fVec11[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp48))))))), fConst63))) & 4095)];
			fRec28[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (0.600000024f * fTemp49);
			float fRec29 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp50 = std::exp((fConst65 / fTemp7));
			float fTemp51 = FaustThunderDSP_faustpower2_f(fTemp50);
			float fTemp52 = (1.0f - (fTemp8 * fTemp51));
			float fTemp53 = (1.0f - fTemp51);
			float fTemp54 = (fTemp52 / fTemp53);
			float fTemp55 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp52) / FaustThunderDSP_faustpower2_f(fTemp53)) + -1.0f)));
			float fTempFTZ21 = ((fRec33[1] * (fTemp54 - fTemp55)) + ((fTemp50 * fRec2[1]) * (fTemp55 + (1.0f - fTemp54))));
			fRec33[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			fVec12[(IOTA & 32767)] = ((0.353553385f * fRec33[0]) + 9.99999968e-21f);
			float fTemp56 = std::floor(((0.0316039994f * fTemp7) + 0.5f));
			float fTemp57 = (fVec12[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.127837002f * fTemp7) + 0.5f)) - fTemp56)))))))), fConst67))) & 32767)] - (fTemp16 + (0.600000024f * fRec31[1])));
			fVec13[(IOTA & 8191)] = fTemp57;
			float fTempFTZ22 = fVec13[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp56))))))), fConst68))) & 8191)];
			fRec31[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (0.600000024f * fTemp57);
			float fRec32 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp58 = std::exp((fConst70 / fTemp7));
			float fTemp59 = FaustThunderDSP_faustpower2_f(fTemp58);
			float fTemp60 = (1.0f - (fTemp8 * fTemp59));
			float fTemp61 = (1.0f - fTemp59);
			float fTemp62 = (fTemp60 / fTemp61);
			float fTemp63 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp60) / FaustThunderDSP_faustpower2_f(fTemp61)) + -1.0f)));
			float fTempFTZ24 = ((fRec36[1] * (fTemp62 - fTemp63)) + ((fTemp58 * fRec4[1]) * (fTemp63 + (1.0f - fTemp62))));
			fRec36[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			fVec14[(IOTA & 65535)] = ((0.353553385f * fRec36[0]) + 9.99999968e-21f);
			float fTemp64 = std::floor(((0.0229039993f * fTemp7) + 0.5f));
			float fTemp65 = ((fTemp16 + fVec14[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.174713001f * fTemp7) + 0.5f)) - fTemp64)))))))), fConst72))) & 65535)]) - (0.600000024f * fRec34[1]));
			fVec15[(IOTA & 8191)] = fTemp65;
			float fTempFTZ25 = fVec15[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp64))))))), fConst73))) & 8191)];
			fRec34[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (0.600000024f * fTemp65);
			float fRec35 = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTemp66 = std::exp((fConst75 / fTemp7));
			float fTemp67 = FaustThunderDSP_faustpower2_f(fTemp66);
			float fTemp68 = (1.0f - (fTemp67 * fTemp8));
			float fTemp69 = (1.0f - fTemp67);
			float fTemp70 = (fTemp68 / fTemp69);
			float fTemp71 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp68) / FaustThunderDSP_faustpower2_f(fTemp69)) + -1.0f)));
			float fTempFTZ27 = ((fRec39[1] * (fTemp70 - fTemp71)) + ((fTemp66 * fRec0[1]) * (fTemp71 + (1.0f - fTemp70))));
			fRec39[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			fVec16[(IOTA & 32767)] = ((0.353553385f * fRec39[0]) + 9.99999968e-21f);
			float fTemp72 = std::floor(((0.0203460008f * fTemp7) + 0.5f));
			float fTemp73 = ((fVec16[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.153128996f * fTemp7) + 0.5f)) - fTemp72)))))))), fConst77))) & 32767)] + fTemp16) - (0.600000024f * fRec37[1]));
			fVec17[(IOTA & 4095)] = fTemp73;
			float fTempFTZ28 = fVec17[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp72))))))), fConst78))) & 4095)];
			fRec37[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (0.600000024f * fTemp73);
			float fRec38 = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp74 = (fRec38 + fRec35);
			float fTemp75 = (fRec29 + (fRec32 + fTemp74));
			float fTempFTZ30 = (fRec8[1] + (fRec19[1] + (fRec22[1] + (fRec25[1] + (fRec28[1] + (fRec31[1] + (fRec34[1] + (fRec37[1] + (fRec9 + (fRec20 + (fRec23 + (fRec26 + fTemp75))))))))))));
			fRec0[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = ((fRec28[1] + (fRec31[1] + (fRec34[1] + (fRec37[1] + fTemp75)))) - (fRec8[1] + (fRec19[1] + (fRec22[1] + (fRec25[1] + (fRec9 + (fRec20 + (fRec26 + fRec23))))))));
			fRec1[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTemp76 = (fRec32 + fRec29);
			float fTempFTZ32 = ((fRec22[1] + (fRec25[1] + (fRec34[1] + (fRec37[1] + (fRec23 + (fRec26 + fTemp74)))))) - (fRec8[1] + (fRec19[1] + (fRec28[1] + (fRec31[1] + (fRec9 + (fRec20 + fTemp76)))))));
			fRec2[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = ((fRec8[1] + (fRec19[1] + (fRec34[1] + (fRec37[1] + (fRec9 + (fRec20 + fTemp74)))))) - (fRec22[1] + (fRec25[1] + (fRec28[1] + (fRec31[1] + (fRec23 + (fRec26 + fTemp76)))))));
			fRec3[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTemp77 = (fRec38 + fRec32);
			float fTemp78 = (fRec35 + fRec29);
			float fTempFTZ34 = ((fRec19[1] + (fRec25[1] + (fRec31[1] + (fRec37[1] + (fRec20 + (fRec26 + fTemp77)))))) - (fRec8[1] + (fRec22[1] + (fRec28[1] + (fRec34[1] + (fRec9 + (fRec23 + fTemp78)))))));
			fRec4[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = ((fRec8[1] + (fRec22[1] + (fRec31[1] + (fRec37[1] + (fRec9 + (fRec23 + fTemp77)))))) - (fRec19[1] + (fRec25[1] + (fRec28[1] + (fRec34[1] + (fRec20 + (fRec26 + fTemp78)))))));
			fRec5[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTemp79 = (fRec38 + fRec29);
			float fTemp80 = (fRec35 + fRec32);
			float fTempFTZ36 = ((fRec8[1] + (fRec25[1] + (fRec28[1] + (fRec37[1] + (fRec9 + (fRec26 + fTemp79)))))) - (fRec19[1] + (fRec22[1] + (fRec31[1] + (fRec34[1] + (fRec20 + (fRec23 + fTemp80)))))));
			fRec6[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = ((fRec19[1] + (fRec22[1] + (fRec28[1] + (fRec37[1] + (fRec20 + (fRec23 + fTemp79)))))) - (fRec8[1] + (fRec25[1] + (fRec31[1] + (fRec34[1] + (fRec9 + (fRec26 + fTemp80)))))));
			fRec7[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((0.296000004f * ((fRec1[0] + fRec2[0]) + (fRec1[0] - fRec2[0]))))))));
			iRec12[1] = iRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fVec0[1] = fVec0[0];
			iRec13[1] = iRec13[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec15[j0] = fRec15[(j0 - 1)];
			}
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec18[1] = fRec18[0];
			IOTA = (IOTA + 1);
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
		}
	}

};

#endif
