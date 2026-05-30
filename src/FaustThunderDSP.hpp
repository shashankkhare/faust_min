/* ------------------------------------------------------------
name: "thunder"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustThunderDSP_H__
#define  __FaustThunderDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
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
	int iRec13[2];
	float fConst8;
	float fConst9;
	float fConst10;
	float fRec12[3];
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec14[2];
	float fConst15;
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fRec15[3];
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst28;
	float fConst29;
	float fRec16[2];
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fRec17[3];
	float fConst37;
	float fConst38;
	float fConst39;
	int IOTA;
	float fRec11[8192];
	float fVec1[16384];
	float fConst41;
	float fRec10[2];
	float fVec2[65536];
	float fConst43;
	float fVec3[4096];
	float fConst44;
	float fRec8[2];
	float fConst46;
	float fRec20[2];
	float fVec4[65536];
	float fConst48;
	float fVec5[8192];
	float fConst49;
	float fRec18[2];
	float fConst51;
	float fRec23[2];
	float fVec6[65536];
	float fConst53;
	float fVec7[8192];
	float fConst54;
	float fRec21[2];
	float fConst56;
	float fRec26[2];
	float fVec8[65536];
	float fConst58;
	float fVec9[8192];
	float fConst59;
	float fRec24[2];
	float fConst61;
	float fRec29[2];
	float fVec10[32768];
	float fConst63;
	float fVec11[4096];
	float fConst64;
	float fRec27[2];
	float fConst66;
	float fRec32[2];
	float fVec12[32768];
	float fConst68;
	float fVec13[8192];
	float fConst69;
	float fRec30[2];
	float fConst71;
	float fRec35[2];
	float fVec14[65536];
	float fConst73;
	float fVec15[8192];
	float fConst74;
	float fRec33[2];
	float fConst76;
	float fRec38[2];
	float fVec16[32768];
	float fConst78;
	float fVec17[4096];
	float fConst79;
	float fRec36[2];
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
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
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
		float fConst2 = std::tan((3769.91113f / fConst0));
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
		fConst15 = (1.0f / std::max<float>(1.0f, (0.400000006f * fConst0)));
		float fConst16 = std::tan((1884.95557f / fConst0));
		float fConst17 = (1.0f / fConst16);
		float fConst18 = (((fConst17 + 0.666666687f) / fConst16) + 1.0f);
		fConst19 = (1.0f / (fConst16 * fConst18));
		fConst20 = (1.0f / fConst18);
		fConst21 = (((fConst17 + -0.666666687f) / fConst16) + 1.0f);
		fConst22 = (2.0f * (1.0f - (1.0f / FaustThunderDSP_faustpower2_f(fConst16))));
		fConst23 = (0.0f - fConst19);
		fConst24 = std::max<float>(1.0f, (0.100000001f * fConst0));
		fConst25 = (1.0f / fConst24);
		fConst26 = (1.0f / std::max<float>(1.0f, (2.5f * fConst0)));
		float fConst27 = (1.0f / std::tan((2513.27417f / fConst0)));
		fConst28 = (1.0f / (fConst27 + 1.0f));
		fConst29 = (1.0f - fConst27);
		float fConst30 = std::tan((1099.55737f / fConst0));
		float fConst31 = (1.0f / fConst30);
		float fConst32 = (((fConst31 + 1.41421354f) / fConst30) + 1.0f);
		fConst33 = (15.0f / fConst32);
		fConst34 = (1.0f / fConst32);
		fConst35 = (((fConst31 + -1.41421354f) / fConst30) + 1.0f);
		fConst36 = (2.0f * (1.0f - (1.0f / FaustThunderDSP_faustpower2_f(fConst30))));
		fConst37 = std::max<float>(1.0f, (0.00999999978f * fConst0));
		fConst38 = (1.0f / fConst37);
		fConst39 = (1.0f / std::max<float>(1.0f, (3.5f * fConst0)));
		float fConst40 = std::floor(((0.219990999f * fConst0) + 0.5f));
		fConst41 = ((0.0f - (6.90775537f * fConst40)) / fConst0);
		float fConst42 = std::floor(((0.0191229992f * fConst0) + 0.5f));
		fConst43 = std::max<float>(0.0f, (fConst40 - fConst42));
		fConst44 = std::max<float>(0.0f, (fConst42 + -1.0f));
		float fConst45 = std::floor(((0.256891012f * fConst0) + 0.5f));
		fConst46 = ((0.0f - (6.90775537f * fConst45)) / fConst0);
		float fConst47 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		fConst48 = std::max<float>(0.0f, (fConst45 - fConst47));
		fConst49 = std::max<float>(0.0f, (fConst47 + -1.0f));
		float fConst50 = std::floor(((0.192303002f * fConst0) + 0.5f));
		fConst51 = ((0.0f - (6.90775537f * fConst50)) / fConst0);
		float fConst52 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		fConst53 = std::max<float>(0.0f, (fConst50 - fConst52));
		fConst54 = std::max<float>(0.0f, (fConst52 + -1.0f));
		float fConst55 = std::floor(((0.210389003f * fConst0) + 0.5f));
		fConst56 = ((0.0f - (6.90775537f * fConst55)) / fConst0);
		float fConst57 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		fConst58 = std::max<float>(0.0f, (fConst55 - fConst57));
		fConst59 = std::max<float>(0.0f, (fConst57 + -1.0f));
		float fConst60 = std::floor(((0.125f * fConst0) + 0.5f));
		fConst61 = ((0.0f - (6.90775537f * fConst60)) / fConst0);
		float fConst62 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		fConst63 = std::max<float>(0.0f, (fConst60 - fConst62));
		fConst64 = std::max<float>(0.0f, (fConst62 + -1.0f));
		float fConst65 = std::floor(((0.127837002f * fConst0) + 0.5f));
		fConst66 = ((0.0f - (6.90775537f * fConst65)) / fConst0);
		float fConst67 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		fConst68 = std::max<float>(0.0f, (fConst65 - fConst67));
		fConst69 = std::max<float>(0.0f, (fConst67 + -1.0f));
		float fConst70 = std::floor(((0.174713001f * fConst0) + 0.5f));
		fConst71 = ((0.0f - (6.90775537f * fConst70)) / fConst0);
		float fConst72 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		fConst73 = std::max<float>(0.0f, (fConst70 - fConst72));
		fConst74 = std::max<float>(0.0f, (fConst72 + -1.0f));
		float fConst75 = std::floor(((0.153128996f * fConst0) + 0.5f));
		fConst76 = ((0.0f - (6.90775537f * fConst75)) / fConst0);
		float fConst77 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		fConst78 = std::max<float>(0.0f, (fConst75 - fConst77));
		fConst79 = std::max<float>(0.0f, (fConst77 + -1.0f));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec13[l0] = 0;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec12[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec14[l3] = 0;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec15[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec16[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec17[l6] = 0.0f;
		}
		IOTA = 0;
		for (int l7 = 0; (l7 < 8192); l7 = (l7 + 1)) {
			fRec11[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 16384); l8 = (l8 + 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 65536); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 4096); l11 = (l11 + 1)) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec20[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 65536); l14 = (l14 + 1)) {
			fVec4[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 8192); l15 = (l15 + 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec18[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec23[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 65536); l18 = (l18 + 1)) {
			fVec6[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 8192); l19 = (l19 + 1)) {
			fVec7[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec21[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec26[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 65536); l22 = (l22 + 1)) {
			fVec8[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 8192); l23 = (l23 + 1)) {
			fVec9[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec24[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec29[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 32768); l26 = (l26 + 1)) {
			fVec10[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 4096); l27 = (l27 + 1)) {
			fVec11[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec27[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec32[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 32768); l30 = (l30 + 1)) {
			fVec12[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 8192); l31 = (l31 + 1)) {
			fVec13[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec30[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec35[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 65536); l34 = (l34 + 1)) {
			fVec14[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 8192); l35 = (l35 + 1)) {
			fVec15[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec33[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec38[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 32768); l38 = (l38 + 1)) {
			fVec16[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 4096); l39 = (l39 + 1)) {
			fVec17[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec36[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec0[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec1[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec2[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec3[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec4[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec5[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec6[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec7[l48] = 0.0f;
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
			iRec13[0] = ((1103515245 * iRec13[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * float(iRec13[0]));
			fRec12[0] = (fTemp0 - (fConst8 * ((fConst9 * fRec12[2]) + (fConst10 * fRec12[1]))));
			fVec0[0] = fSlow1;
			iRec14[0] = (((iRec14[1] + (iRec14[1] > 0)) * (fSlow1 <= fVec0[1])) + (fSlow1 > fVec0[1]));
			float fTemp1 = float(iRec14[0]);
			float fTemp2 = (fConst5 * ((((fConst7 * fRec12[0]) + (fConst11 * fRec12[1])) + (fConst7 * fRec12[2])) * std::max<float>(0.0f, std::min<float>((fConst14 * fTemp1), ((fConst15 * (fConst13 - fTemp1)) + 1.0f)))));
			fRec15[0] = (fTemp0 - (fConst20 * ((fConst21 * fRec15[2]) + (fConst22 * fRec15[1]))));
			float fTemp3 = (((fConst19 * fRec15[0]) + (fConst23 * fRec15[2])) * std::max<float>(0.0f, std::min<float>((fConst25 * fTemp1), ((fConst26 * (fConst24 - fTemp1)) + 1.0f))));
			fRec16[0] = (fConst28 * ((0.600000024f * (fRec11[((IOTA - 8001) & 8191)] + fRec11[((IOTA - 8002) & 8191)])) - (fConst29 * fRec16[1])));
			fRec17[0] = (fTemp0 - (fConst34 * ((fConst35 * fRec17[2]) + (fConst36 * fRec17[1]))));
			float fTemp4 = (0.600000024f * (std::max<float>(-1.0f, std::min<float>(1.0f, (fConst33 * (fRec17[2] + (fRec17[0] + (2.0f * fRec17[1])))))) * std::max<float>(0.0f, std::min<float>((fConst38 * fTemp1), ((fConst39 * (fConst37 - fTemp1)) + 1.0f)))));
			fRec11[(IOTA & 8191)] = (fTemp2 + ((0.5f * fTemp3) + (fRec16[0] + fTemp4)));
			float fTemp5 = ((0.5f * (fRec11[((IOTA - 0) & 8191)] + fTemp3)) + (fTemp4 + fTemp2));
			fVec1[(IOTA & 16383)] = fTemp5;
			float fTemp6 = std::cos((fConst1 * fTemp5));
			float fTemp7 = std::exp((fConst41 / fTemp5));
			float fTemp8 = FaustThunderDSP_faustpower2_f(fTemp7);
			float fTemp9 = (1.0f - (fTemp6 * fTemp8));
			float fTemp10 = (1.0f - fTemp8);
			float fTemp11 = (fTemp9 / fTemp10);
			float fTemp12 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp9) / FaustThunderDSP_faustpower2_f(fTemp10)) + -1.0f)));
			fRec10[0] = ((fRec10[1] * (fTemp11 - fTemp12)) + ((fTemp7 * fRec7[1]) * (fTemp12 + (1.0f - fTemp11))));
			fVec2[(IOTA & 65535)] = ((0.353553385f * fRec10[0]) + 9.99999968e-21f);
			float fTemp13 = std::floor(((0.0191229992f * fTemp5) + 0.5f));
			float fTemp14 = (0.300000012f * fVec1[((IOTA - int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst12 * fTemp5))))) & 16383)]);
			float fTemp15 = (((0.600000024f * fRec8[1]) + fVec2[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.219990999f * fTemp5) + 0.5f)) - fTemp13)))))))), fConst43))) & 65535)]) - fTemp14);
			fVec3[(IOTA & 4095)] = fTemp15;
			fRec8[0] = fVec3[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp13))))))), fConst44))) & 4095)];
			float fRec9 = (0.0f - (0.600000024f * fTemp15));
			float fTemp16 = std::exp((fConst46 / fTemp5));
			float fTemp17 = FaustThunderDSP_faustpower2_f(fTemp16);
			float fTemp18 = (1.0f - (fTemp6 * fTemp17));
			float fTemp19 = (1.0f - fTemp17);
			float fTemp20 = (fTemp18 / fTemp19);
			float fTemp21 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp18) / FaustThunderDSP_faustpower2_f(fTemp19)) + -1.0f)));
			fRec20[0] = ((fRec20[1] * (fTemp20 - fTemp21)) + ((fTemp16 * fRec3[1]) * (fTemp21 + (1.0f - fTemp20))));
			fVec4[(IOTA & 65535)] = ((0.353553385f * fRec20[0]) + 9.99999968e-21f);
			float fTemp22 = std::floor(((0.0273330007f * fTemp5) + 0.5f));
			float fTemp23 = (((0.600000024f * fRec18[1]) + fVec4[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.256891012f * fTemp5) + 0.5f)) - fTemp22)))))))), fConst48))) & 65535)]) - fTemp14);
			fVec5[(IOTA & 8191)] = fTemp23;
			fRec18[0] = fVec5[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp22))))))), fConst49))) & 8191)];
			float fRec19 = (0.0f - (0.600000024f * fTemp23));
			float fTemp24 = std::exp((fConst51 / fTemp5));
			float fTemp25 = FaustThunderDSP_faustpower2_f(fTemp24);
			float fTemp26 = (1.0f - (fTemp6 * fTemp25));
			float fTemp27 = (1.0f - fTemp25);
			float fTemp28 = (fTemp26 / fTemp27);
			float fTemp29 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp26) / FaustThunderDSP_faustpower2_f(fTemp27)) + -1.0f)));
			fRec23[0] = ((fRec23[1] * (fTemp28 - fTemp29)) + ((fTemp24 * fRec5[1]) * (fTemp29 + (1.0f - fTemp28))));
			fVec6[(IOTA & 65535)] = ((0.353553385f * fRec23[0]) + 9.99999968e-21f);
			float fTemp30 = std::floor(((0.0292910002f * fTemp5) + 0.5f));
			float fTemp31 = (fVec6[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.192303002f * fTemp5) + 0.5f)) - fTemp30)))))))), fConst53))) & 65535)] + (fTemp14 + (0.600000024f * fRec21[1])));
			fVec7[(IOTA & 8191)] = fTemp31;
			fRec21[0] = fVec7[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp30))))))), fConst54))) & 8191)];
			float fRec22 = (0.0f - (0.600000024f * fTemp31));
			float fTemp32 = std::exp((fConst56 / fTemp5));
			float fTemp33 = FaustThunderDSP_faustpower2_f(fTemp32);
			float fTemp34 = (1.0f - (fTemp6 * fTemp33));
			float fTemp35 = (1.0f - fTemp33);
			float fTemp36 = (fTemp34 / fTemp35);
			float fTemp37 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp34) / FaustThunderDSP_faustpower2_f(fTemp35)) + -1.0f)));
			fRec26[0] = ((fRec26[1] * (fTemp36 - fTemp37)) + ((fTemp32 * fRec1[1]) * (fTemp37 + (1.0f - fTemp36))));
			fVec8[(IOTA & 65535)] = ((0.353553385f * fRec26[0]) + 9.99999968e-21f);
			float fTemp38 = std::floor(((0.0244210009f * fTemp5) + 0.5f));
			float fTemp39 = (fVec8[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.210389003f * fTemp5) + 0.5f)) - fTemp38)))))))), fConst58))) & 65535)] + (fTemp14 + (0.600000024f * fRec24[1])));
			fVec9[(IOTA & 8191)] = fTemp39;
			fRec24[0] = fVec9[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp38))))))), fConst59))) & 8191)];
			float fRec25 = (0.0f - (0.600000024f * fTemp39));
			float fTemp40 = std::exp((fConst61 / fTemp5));
			float fTemp41 = FaustThunderDSP_faustpower2_f(fTemp40);
			float fTemp42 = (1.0f - (fTemp6 * fTemp41));
			float fTemp43 = (1.0f - fTemp41);
			float fTemp44 = (fTemp42 / fTemp43);
			float fTemp45 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp42) / FaustThunderDSP_faustpower2_f(fTemp43)) + -1.0f)));
			fRec29[0] = ((fRec29[1] * (fTemp44 - fTemp45)) + ((fTemp40 * fRec6[1]) * (fTemp45 + (1.0f - fTemp44))));
			fVec10[(IOTA & 32767)] = ((0.353553385f * fRec29[0]) + 9.99999968e-21f);
			float fTemp46 = std::floor(((0.0134579996f * fTemp5) + 0.5f));
			float fTemp47 = (fVec10[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.125f * fTemp5) + 0.5f)) - fTemp46)))))))), fConst63))) & 32767)] - (fTemp14 + (0.600000024f * fRec27[1])));
			fVec11[(IOTA & 4095)] = fTemp47;
			fRec27[0] = fVec11[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp46))))))), fConst64))) & 4095)];
			float fRec28 = (0.600000024f * fTemp47);
			float fTemp48 = std::exp((fConst66 / fTemp5));
			float fTemp49 = FaustThunderDSP_faustpower2_f(fTemp48);
			float fTemp50 = (1.0f - (fTemp6 * fTemp49));
			float fTemp51 = (1.0f - fTemp49);
			float fTemp52 = (fTemp50 / fTemp51);
			float fTemp53 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp50) / FaustThunderDSP_faustpower2_f(fTemp51)) + -1.0f)));
			fRec32[0] = ((fRec32[1] * (fTemp52 - fTemp53)) + ((fTemp48 * fRec2[1]) * (fTemp53 + (1.0f - fTemp52))));
			fVec12[(IOTA & 32767)] = ((0.353553385f * fRec32[0]) + 9.99999968e-21f);
			float fTemp54 = std::floor(((0.0316039994f * fTemp5) + 0.5f));
			float fTemp55 = (fVec12[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.127837002f * fTemp5) + 0.5f)) - fTemp54)))))))), fConst68))) & 32767)] - (fTemp14 + (0.600000024f * fRec30[1])));
			fVec13[(IOTA & 8191)] = fTemp55;
			fRec30[0] = fVec13[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp54))))))), fConst69))) & 8191)];
			float fRec31 = (0.600000024f * fTemp55);
			float fTemp56 = std::exp((fConst71 / fTemp5));
			float fTemp57 = FaustThunderDSP_faustpower2_f(fTemp56);
			float fTemp58 = (1.0f - (fTemp6 * fTemp57));
			float fTemp59 = (1.0f - fTemp57);
			float fTemp60 = (fTemp58 / fTemp59);
			float fTemp61 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp58) / FaustThunderDSP_faustpower2_f(fTemp59)) + -1.0f)));
			fRec35[0] = ((fRec35[1] * (fTemp60 - fTemp61)) + ((fTemp56 * fRec4[1]) * (fTemp61 + (1.0f - fTemp60))));
			fVec14[(IOTA & 65535)] = ((0.353553385f * fRec35[0]) + 9.99999968e-21f);
			float fTemp62 = std::floor(((0.0229039993f * fTemp5) + 0.5f));
			float fTemp63 = ((fTemp14 + fVec14[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.174713001f * fTemp5) + 0.5f)) - fTemp62)))))))), fConst73))) & 65535)]) - (0.600000024f * fRec33[1]));
			fVec15[(IOTA & 8191)] = fTemp63;
			fRec33[0] = fVec15[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp62))))))), fConst74))) & 8191)];
			float fRec34 = (0.600000024f * fTemp63);
			float fTemp64 = std::exp((fConst76 / fTemp5));
			float fTemp65 = FaustThunderDSP_faustpower2_f(fTemp64);
			float fTemp66 = (1.0f - (fTemp65 * fTemp6));
			float fTemp67 = (1.0f - fTemp65);
			float fTemp68 = (fTemp66 / fTemp67);
			float fTemp69 = std::sqrt(std::max<float>(0.0f, ((FaustThunderDSP_faustpower2_f(fTemp66) / FaustThunderDSP_faustpower2_f(fTemp67)) + -1.0f)));
			fRec38[0] = ((fRec38[1] * (fTemp68 - fTemp69)) + ((fTemp64 * fRec0[1]) * (fTemp69 + (1.0f - fTemp68))));
			fVec16[(IOTA & 32767)] = ((0.353553385f * fRec38[0]) + 9.99999968e-21f);
			float fTemp70 = std::floor(((0.0203460008f * fTemp5) + 0.5f));
			float fTemp71 = ((fVec16[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log((std::floor(((0.153128996f * fTemp5) + 0.5f)) - fTemp70)))))))), fConst78))) & 32767)] + fTemp14) - (0.600000024f * fRec36[1]));
			fVec17[(IOTA & 4095)] = fTemp71;
			fRec36[0] = fVec17[((IOTA - int(std::min<float>(float(int(std::pow(2.0f, std::max<float>(1.0f, std::ceil((1.44269502f * std::log(fTemp70))))))), fConst79))) & 4095)];
			float fRec37 = (0.600000024f * fTemp71);
			float fTemp72 = (fRec37 + fRec34);
			float fTemp73 = (fRec28 + (fRec31 + fTemp72));
			fRec0[0] = (fRec8[1] + (fRec18[1] + (fRec21[1] + (fRec24[1] + (fRec27[1] + (fRec30[1] + (fRec33[1] + (fRec36[1] + (fRec9 + (fRec19 + (fRec22 + (fRec25 + fTemp73))))))))))));
			fRec1[0] = ((fRec27[1] + (fRec30[1] + (fRec33[1] + (fRec36[1] + fTemp73)))) - (fRec8[1] + (fRec18[1] + (fRec21[1] + (fRec24[1] + (fRec9 + (fRec19 + (fRec25 + fRec22))))))));
			float fTemp74 = (fRec31 + fRec28);
			fRec2[0] = ((fRec21[1] + (fRec24[1] + (fRec33[1] + (fRec36[1] + (fRec22 + (fRec25 + fTemp72)))))) - (fRec8[1] + (fRec18[1] + (fRec27[1] + (fRec30[1] + (fRec9 + (fRec19 + fTemp74)))))));
			fRec3[0] = ((fRec8[1] + (fRec18[1] + (fRec33[1] + (fRec36[1] + (fRec9 + (fRec19 + fTemp72)))))) - (fRec21[1] + (fRec24[1] + (fRec27[1] + (fRec30[1] + (fRec22 + (fRec25 + fTemp74)))))));
			float fTemp75 = (fRec37 + fRec31);
			float fTemp76 = (fRec34 + fRec28);
			fRec4[0] = ((fRec18[1] + (fRec24[1] + (fRec30[1] + (fRec36[1] + (fRec19 + (fRec25 + fTemp75)))))) - (fRec8[1] + (fRec21[1] + (fRec27[1] + (fRec33[1] + (fRec9 + (fRec22 + fTemp76)))))));
			fRec5[0] = ((fRec8[1] + (fRec21[1] + (fRec30[1] + (fRec36[1] + (fRec9 + (fRec22 + fTemp75)))))) - (fRec18[1] + (fRec24[1] + (fRec27[1] + (fRec33[1] + (fRec19 + (fRec25 + fTemp76)))))));
			float fTemp77 = (fRec37 + fRec28);
			float fTemp78 = (fRec34 + fRec31);
			fRec6[0] = ((fRec8[1] + (fRec24[1] + (fRec27[1] + (fRec36[1] + (fRec9 + (fRec25 + fTemp77)))))) - (fRec18[1] + (fRec21[1] + (fRec30[1] + (fRec33[1] + (fRec19 + (fRec22 + fTemp78)))))));
			fRec7[0] = ((fRec18[1] + (fRec21[1] + (fRec27[1] + (fRec36[1] + (fRec19 + (fRec22 + fTemp77)))))) - (fRec8[1] + (fRec24[1] + (fRec30[1] + (fRec33[1] + (fRec9 + (fRec25 + fTemp78)))))));
			output0[i0] = FAUSTFLOAT((fSlow0 * std::max<float>(-1.0f, std::min<float>(1.0f, (0.296000004f * ((fRec1[0] + fRec2[0]) + (fRec1[0] - fRec2[0])))))));
			iRec13[1] = iRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fVec0[1] = fVec0[0];
			iRec14[1] = iRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			IOTA = (IOTA + 1);
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
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
