/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "master_reverb"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustMaster_reverbDSP_H__
#define  __FaustMaster_reverbDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustMaster_reverbDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustMaster_reverbDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustMaster_reverbDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst5;
	float fConst6;
	float fRec11[2];
	float fRec10[2];
	int IOTA;
	float fVec0[32768];
	int iConst8;
	float fConst12;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fRec12[3];
	float fConst18;
	float fVec1[16384];
	int iConst19;
	float fVec2[2048];
	int iConst20;
	float fRec8[2];
	float fConst22;
	float fRec16[2];
	float fRec15[2];
	float fVec3[32768];
	int iConst24;
	float fVec4[4096];
	int iConst25;
	float fRec13[2];
	float fConst27;
	float fRec20[2];
	float fRec19[2];
	float fVec5[16384];
	int iConst29;
	float fVec6[4096];
	int iConst30;
	float fRec17[2];
	float fConst32;
	float fRec24[2];
	float fRec23[2];
	float fVec7[32768];
	int iConst34;
	float fVec8[4096];
	int iConst35;
	float fRec21[2];
	float fConst37;
	float fRec28[2];
	float fRec27[2];
	float fVec9[16384];
	int iConst39;
	float fRec29[3];
	float fVec10[16384];
	float fVec11[2048];
	int iConst40;
	float fRec25[2];
	float fConst42;
	float fRec33[2];
	float fRec32[2];
	float fVec12[16384];
	int iConst44;
	float fVec13[4096];
	int iConst45;
	float fRec30[2];
	float fConst47;
	float fRec37[2];
	float fRec36[2];
	float fVec14[16384];
	int iConst49;
	float fVec15[4096];
	int iConst50;
	float fRec34[2];
	float fConst52;
	float fRec41[2];
	float fRec40[2];
	float fVec16[16384];
	int iConst54;
	float fVec17[2048];
	int iConst55;
	float fRec38[2];
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
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "master_reverb.dsp");
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
		m->declare("name", "master_reverb");
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
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::floor(((0.219990999f * fConst0) + 0.5f));
		fConst2 = ((0.0f - (6.90775537f * fConst1)) / fConst0);
		fConst3 = (6.28318548f / fConst0);
		float fConst4 = (1.0f / std::tan((628.318542f / fConst0)));
		fConst5 = (1.0f / (fConst4 + 1.0f));
		fConst6 = (1.0f - fConst4);
		float fConst7 = std::floor(((0.0191229992f * fConst0) + 0.5f));
		iConst8 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst1 - fConst7))));
		float fConst9 = std::tan((251.327408f / fConst0));
		float fConst10 = (1.0f / fConst9);
		float fConst11 = (((fConst10 + 1.41421354f) / fConst9) + 1.0f);
		fConst12 = (0.300000012f / fConst11);
		float fConst13 = FaustMaster_reverbDSP_faustpower2_f(fConst9);
		fConst14 = (1.0f / fConst13);
		fConst15 = (1.0f / fConst11);
		fConst16 = (((fConst10 + -1.41421354f) / fConst9) + 1.0f);
		fConst17 = (2.0f * (1.0f - fConst14));
		fConst18 = (0.0f - (2.0f / fConst13));
		iConst19 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (0.0599999987f * fConst0))));
		iConst20 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst7 + -1.0f))));
		float fConst21 = std::floor(((0.256891012f * fConst0) + 0.5f));
		fConst22 = ((0.0f - (6.90775537f * fConst21)) / fConst0);
		float fConst23 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		iConst24 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst21 - fConst23))));
		iConst25 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst23 + -1.0f))));
		float fConst26 = std::floor(((0.192303002f * fConst0) + 0.5f));
		fConst27 = ((0.0f - (6.90775537f * fConst26)) / fConst0);
		float fConst28 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		iConst29 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst26 - fConst28))));
		iConst30 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst28 + -1.0f))));
		float fConst31 = std::floor(((0.210389003f * fConst0) + 0.5f));
		fConst32 = ((0.0f - (6.90775537f * fConst31)) / fConst0);
		float fConst33 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		iConst34 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst31 - fConst33))));
		iConst35 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst33 + -1.0f))));
		float fConst36 = std::floor(((0.125f * fConst0) + 0.5f));
		fConst37 = ((0.0f - (6.90775537f * fConst36)) / fConst0);
		float fConst38 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		iConst39 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst36 - fConst38))));
		iConst40 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst38 + -1.0f))));
		float fConst41 = std::floor(((0.127837002f * fConst0) + 0.5f));
		fConst42 = ((0.0f - (6.90775537f * fConst41)) / fConst0);
		float fConst43 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		iConst44 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst41 - fConst43))));
		iConst45 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst43 + -1.0f))));
		float fConst46 = std::floor(((0.174713001f * fConst0) + 0.5f));
		fConst47 = ((0.0f - (6.90775537f * fConst46)) / fConst0);
		float fConst48 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		iConst49 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst46 - fConst48))));
		iConst50 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst48 + -1.0f))));
		float fConst51 = std::floor(((0.153128996f * fConst0) + 0.5f));
		fConst52 = ((0.0f - (6.90775537f * fConst51)) / fConst0);
		float fConst53 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		iConst54 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst51 - fConst53))));
		iConst55 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst53 + -1.0f))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(8.0f);
		fHslider1 = FAUSTFLOAT(6000.0f);
		fHslider2 = FAUSTFLOAT(2.0f);
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
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec12[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 16384); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2048); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec8[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec16[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec15[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 32768); l9 = (l9 + 1)) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 4096); l10 = (l10 + 1)) {
			fVec4[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec13[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec20[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec19[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 16384); l14 = (l14 + 1)) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 4096); l15 = (l15 + 1)) {
			fVec6[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec17[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec24[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec23[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 32768); l19 = (l19 + 1)) {
			fVec7[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 4096); l20 = (l20 + 1)) {
			fVec8[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec28[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec27[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 16384); l24 = (l24 + 1)) {
			fVec9[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec29[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 16384); l26 = (l26 + 1)) {
			fVec10[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2048); l27 = (l27 + 1)) {
			fVec11[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec25[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec33[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec32[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 16384); l31 = (l31 + 1)) {
			fVec12[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 4096); l32 = (l32 + 1)) {
			fVec13[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec30[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec37[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec36[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 16384); l36 = (l36 + 1)) {
			fVec14[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 4096); l37 = (l37 + 1)) {
			fVec15[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec34[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec41[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec40[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 16384); l41 = (l41 + 1)) {
			fVec16[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2048); l42 = (l42 + 1)) {
			fVec17[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec38[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec0[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec1[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec2[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec3[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec4[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec5[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec6[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec7[l51] = 0.0f;
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
	
	virtual FaustMaster_reverbDSP* clone() {
		return new FaustMaster_reverbDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("master_reverb");
		ui_interface->addHorizontalSlider("damping_freq", &fHslider1, FAUSTFLOAT(6000.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(10000.0f), FAUSTFLOAT(10.0f));
		ui_interface->addHorizontalSlider("decay_time", &fHslider0, FAUSTFLOAT(8.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(30.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("low_rt60", &fHslider2, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = std::exp((fConst2 / fSlow0));
		float fSlow2 = FaustMaster_reverbDSP_faustpower2_f(fSlow1);
		float fSlow3 = std::cos((fConst3 * float(fHslider1)));
		float fSlow4 = (1.0f - (fSlow2 * fSlow3));
		float fSlow5 = (1.0f - fSlow2);
		float fSlow6 = (fSlow4 / fSlow5);
		float fSlow7 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow4) / FaustMaster_reverbDSP_faustpower2_f(fSlow5)) + -1.0f)));
		float fSlow8 = (fSlow6 - fSlow7);
		float fSlow9 = (fSlow1 * (fSlow7 + (1.0f - fSlow6)));
		float fSlow10 = float(fHslider2);
		float fSlow11 = ((std::exp((fConst2 / fSlow10)) / fSlow1) + -1.0f);
		float fSlow12 = std::exp((fConst22 / fSlow0));
		float fSlow13 = FaustMaster_reverbDSP_faustpower2_f(fSlow12);
		float fSlow14 = (1.0f - (fSlow13 * fSlow3));
		float fSlow15 = (1.0f - fSlow13);
		float fSlow16 = (fSlow14 / fSlow15);
		float fSlow17 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow14) / FaustMaster_reverbDSP_faustpower2_f(fSlow15)) + -1.0f)));
		float fSlow18 = (fSlow16 - fSlow17);
		float fSlow19 = (fSlow12 * (fSlow17 + (1.0f - fSlow16)));
		float fSlow20 = ((std::exp((fConst22 / fSlow10)) / fSlow12) + -1.0f);
		float fSlow21 = std::exp((fConst27 / fSlow0));
		float fSlow22 = FaustMaster_reverbDSP_faustpower2_f(fSlow21);
		float fSlow23 = (1.0f - (fSlow22 * fSlow3));
		float fSlow24 = (1.0f - fSlow22);
		float fSlow25 = (fSlow23 / fSlow24);
		float fSlow26 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow23) / FaustMaster_reverbDSP_faustpower2_f(fSlow24)) + -1.0f)));
		float fSlow27 = (fSlow25 - fSlow26);
		float fSlow28 = (fSlow21 * (fSlow26 + (1.0f - fSlow25)));
		float fSlow29 = ((std::exp((fConst27 / fSlow10)) / fSlow21) + -1.0f);
		float fSlow30 = std::exp((fConst32 / fSlow0));
		float fSlow31 = FaustMaster_reverbDSP_faustpower2_f(fSlow30);
		float fSlow32 = (1.0f - (fSlow31 * fSlow3));
		float fSlow33 = (1.0f - fSlow31);
		float fSlow34 = (fSlow32 / fSlow33);
		float fSlow35 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow32) / FaustMaster_reverbDSP_faustpower2_f(fSlow33)) + -1.0f)));
		float fSlow36 = (fSlow34 - fSlow35);
		float fSlow37 = (fSlow30 * (fSlow35 + (1.0f - fSlow34)));
		float fSlow38 = ((std::exp((fConst32 / fSlow10)) / fSlow30) + -1.0f);
		float fSlow39 = std::exp((fConst37 / fSlow0));
		float fSlow40 = FaustMaster_reverbDSP_faustpower2_f(fSlow39);
		float fSlow41 = (1.0f - (fSlow40 * fSlow3));
		float fSlow42 = (1.0f - fSlow40);
		float fSlow43 = (fSlow41 / fSlow42);
		float fSlow44 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow41) / FaustMaster_reverbDSP_faustpower2_f(fSlow42)) + -1.0f)));
		float fSlow45 = (fSlow43 - fSlow44);
		float fSlow46 = (fSlow39 * (fSlow44 + (1.0f - fSlow43)));
		float fSlow47 = ((std::exp((fConst37 / fSlow10)) / fSlow39) + -1.0f);
		float fSlow48 = std::exp((fConst42 / fSlow0));
		float fSlow49 = FaustMaster_reverbDSP_faustpower2_f(fSlow48);
		float fSlow50 = (1.0f - (fSlow49 * fSlow3));
		float fSlow51 = (1.0f - fSlow49);
		float fSlow52 = (fSlow50 / fSlow51);
		float fSlow53 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow50) / FaustMaster_reverbDSP_faustpower2_f(fSlow51)) + -1.0f)));
		float fSlow54 = (fSlow52 - fSlow53);
		float fSlow55 = (fSlow48 * (fSlow53 + (1.0f - fSlow52)));
		float fSlow56 = ((std::exp((fConst42 / fSlow10)) / fSlow48) + -1.0f);
		float fSlow57 = std::exp((fConst47 / fSlow0));
		float fSlow58 = FaustMaster_reverbDSP_faustpower2_f(fSlow57);
		float fSlow59 = (1.0f - (fSlow58 * fSlow3));
		float fSlow60 = (1.0f - fSlow58);
		float fSlow61 = (fSlow59 / fSlow60);
		float fSlow62 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow59) / FaustMaster_reverbDSP_faustpower2_f(fSlow60)) + -1.0f)));
		float fSlow63 = (fSlow61 - fSlow62);
		float fSlow64 = (fSlow57 * (fSlow62 + (1.0f - fSlow61)));
		float fSlow65 = ((std::exp((fConst47 / fSlow10)) / fSlow57) + -1.0f);
		float fSlow66 = std::exp((fConst52 / fSlow0));
		float fSlow67 = FaustMaster_reverbDSP_faustpower2_f(fSlow66);
		float fSlow68 = (1.0f - (fSlow67 * fSlow3));
		float fSlow69 = (1.0f - fSlow67);
		float fSlow70 = (fSlow68 / fSlow69);
		float fSlow71 = std::sqrt(std::max<float>(0.0f, ((FaustMaster_reverbDSP_faustpower2_f(fSlow68) / FaustMaster_reverbDSP_faustpower2_f(fSlow69)) + -1.0f)));
		float fSlow72 = (fSlow70 - fSlow71);
		float fSlow73 = (fSlow66 * (fSlow71 + (1.0f - fSlow70)));
		float fSlow74 = ((std::exp((fConst52 / fSlow10)) / fSlow66) + -1.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec11[0] = (0.0f - (fConst5 * ((fConst6 * fRec11[1]) - (fRec7[1] + fRec7[2]))));
			fRec10[0] = ((fSlow8 * fRec10[1]) + (fSlow9 * (fRec7[1] + (fSlow11 * fRec11[0]))));
			fVec0[(IOTA & 32767)] = ((0.353553385f * fRec10[0]) + 9.99999968e-21f);
			fRec12[0] = (float(input1[i0]) - (fConst15 * ((fConst16 * fRec12[2]) + (fConst17 * fRec12[1]))));
			fVec1[(IOTA & 16383)] = (((fConst14 * fRec12[0]) + (fConst18 * fRec12[1])) + (fConst14 * fRec12[2]));
			float fTemp0 = (fConst12 * fVec1[((IOTA - iConst19) & 16383)]);
			float fTemp1 = (((0.600000024f * fRec8[1]) + fVec0[((IOTA - iConst8) & 32767)]) - fTemp0);
			fVec2[(IOTA & 2047)] = fTemp1;
			fRec8[0] = fVec2[((IOTA - iConst20) & 2047)];
			float fRec9 = (0.0f - (0.600000024f * fTemp1));
			fRec16[0] = (0.0f - (fConst5 * ((fConst6 * fRec16[1]) - (fRec3[1] + fRec3[2]))));
			fRec15[0] = ((fSlow18 * fRec15[1]) + (fSlow19 * (fRec3[1] + (fSlow20 * fRec16[0]))));
			fVec3[(IOTA & 32767)] = ((0.353553385f * fRec15[0]) + 9.99999968e-21f);
			float fTemp2 = (((0.600000024f * fRec13[1]) + fVec3[((IOTA - iConst24) & 32767)]) - fTemp0);
			fVec4[(IOTA & 4095)] = fTemp2;
			fRec13[0] = fVec4[((IOTA - iConst25) & 4095)];
			float fRec14 = (0.0f - (0.600000024f * fTemp2));
			fRec20[0] = (0.0f - (fConst5 * ((fConst6 * fRec20[1]) - (fRec5[1] + fRec5[2]))));
			fRec19[0] = ((fSlow27 * fRec19[1]) + (fSlow28 * (fRec5[1] + (fSlow29 * fRec20[0]))));
			fVec5[(IOTA & 16383)] = ((0.353553385f * fRec19[0]) + 9.99999968e-21f);
			float fTemp3 = (fVec5[((IOTA - iConst29) & 16383)] + (fTemp0 + (0.600000024f * fRec17[1])));
			fVec6[(IOTA & 4095)] = fTemp3;
			fRec17[0] = fVec6[((IOTA - iConst30) & 4095)];
			float fRec18 = (0.0f - (0.600000024f * fTemp3));
			fRec24[0] = (0.0f - (fConst5 * ((fConst6 * fRec24[1]) - (fRec1[1] + fRec1[2]))));
			fRec23[0] = ((fSlow36 * fRec23[1]) + (fSlow37 * (fRec1[1] + (fSlow38 * fRec24[0]))));
			fVec7[(IOTA & 32767)] = ((0.353553385f * fRec23[0]) + 9.99999968e-21f);
			float fTemp4 = (fTemp0 + ((0.600000024f * fRec21[1]) + fVec7[((IOTA - iConst34) & 32767)]));
			fVec8[(IOTA & 4095)] = fTemp4;
			fRec21[0] = fVec8[((IOTA - iConst35) & 4095)];
			float fRec22 = (0.0f - (0.600000024f * fTemp4));
			fRec28[0] = (0.0f - (fConst5 * ((fConst6 * fRec28[1]) - (fRec6[1] + fRec6[2]))));
			fRec27[0] = ((fSlow45 * fRec27[1]) + (fSlow46 * (fRec6[1] + (fSlow47 * fRec28[0]))));
			fVec9[(IOTA & 16383)] = ((0.353553385f * fRec27[0]) + 9.99999968e-21f);
			fRec29[0] = (float(input0[i0]) - (fConst15 * ((fConst16 * fRec29[2]) + (fConst17 * fRec29[1]))));
			fVec10[(IOTA & 16383)] = (((fConst14 * fRec29[0]) + (fConst18 * fRec29[1])) + (fConst14 * fRec29[2]));
			float fTemp5 = (fConst12 * fVec10[((IOTA - iConst19) & 16383)]);
			float fTemp6 = (fVec9[((IOTA - iConst39) & 16383)] - (fTemp5 + (0.600000024f * fRec25[1])));
			fVec11[(IOTA & 2047)] = fTemp6;
			fRec25[0] = fVec11[((IOTA - iConst40) & 2047)];
			float fRec26 = (0.600000024f * fTemp6);
			fRec33[0] = (0.0f - (fConst5 * ((fConst6 * fRec33[1]) - (fRec2[1] + fRec2[2]))));
			fRec32[0] = ((fSlow54 * fRec32[1]) + (fSlow55 * (fRec2[1] + (fSlow56 * fRec33[0]))));
			fVec12[(IOTA & 16383)] = ((0.353553385f * fRec32[0]) + 9.99999968e-21f);
			float fTemp7 = (fVec12[((IOTA - iConst44) & 16383)] - (fTemp5 + (0.600000024f * fRec30[1])));
			fVec13[(IOTA & 4095)] = fTemp7;
			fRec30[0] = fVec13[((IOTA - iConst45) & 4095)];
			float fRec31 = (0.600000024f * fTemp7);
			fRec37[0] = (0.0f - (fConst5 * ((fConst6 * fRec37[1]) - (fRec4[1] + fRec4[2]))));
			fRec36[0] = ((fSlow63 * fRec36[1]) + (fSlow64 * (fRec4[1] + (fSlow65 * fRec37[0]))));
			fVec14[(IOTA & 16383)] = ((0.353553385f * fRec36[0]) + 9.99999968e-21f);
			float fTemp8 = ((fTemp5 + fVec14[((IOTA - iConst49) & 16383)]) - (0.600000024f * fRec34[1]));
			fVec15[(IOTA & 4095)] = fTemp8;
			fRec34[0] = fVec15[((IOTA - iConst50) & 4095)];
			float fRec35 = (0.600000024f * fTemp8);
			fRec41[0] = (0.0f - (fConst5 * ((fConst6 * fRec41[1]) - (fRec0[1] + fRec0[2]))));
			fRec40[0] = ((fSlow72 * fRec40[1]) + (fSlow73 * (fRec0[1] + (fSlow74 * fRec41[0]))));
			fVec16[(IOTA & 16383)] = ((0.353553385f * fRec40[0]) + 9.99999968e-21f);
			float fTemp9 = ((fVec16[((IOTA - iConst54) & 16383)] + fTemp5) - (0.600000024f * fRec38[1]));
			fVec17[(IOTA & 2047)] = fTemp9;
			fRec38[0] = fVec17[((IOTA - iConst55) & 2047)];
			float fRec39 = (0.600000024f * fTemp9);
			float fTemp10 = (fRec39 + fRec35);
			float fTemp11 = (fRec26 + (fRec31 + fTemp10));
			fRec0[0] = (fRec8[1] + (fRec13[1] + (fRec17[1] + (fRec21[1] + (fRec25[1] + (fRec30[1] + (fRec34[1] + (fRec38[1] + (fRec9 + (fRec14 + (fRec18 + (fRec22 + fTemp11))))))))))));
			fRec1[0] = ((fRec25[1] + (fRec30[1] + (fRec34[1] + (fRec38[1] + fTemp11)))) - (fRec8[1] + (fRec13[1] + (fRec17[1] + (fRec21[1] + (fRec9 + (fRec14 + (fRec22 + fRec18))))))));
			float fTemp12 = (fRec31 + fRec26);
			fRec2[0] = ((fRec17[1] + (fRec21[1] + (fRec34[1] + (fRec38[1] + (fRec18 + (fRec22 + fTemp10)))))) - (fRec8[1] + (fRec13[1] + (fRec25[1] + (fRec30[1] + (fRec9 + (fRec14 + fTemp12)))))));
			fRec3[0] = ((fRec8[1] + (fRec13[1] + (fRec34[1] + (fRec38[1] + (fRec9 + (fRec14 + fTemp10)))))) - (fRec17[1] + (fRec21[1] + (fRec25[1] + (fRec30[1] + (fRec18 + (fRec22 + fTemp12)))))));
			float fTemp13 = (fRec39 + fRec31);
			float fTemp14 = (fRec35 + fRec26);
			fRec4[0] = ((fRec13[1] + (fRec21[1] + (fRec30[1] + (fRec38[1] + (fRec14 + (fRec22 + fTemp13)))))) - (fRec8[1] + (fRec17[1] + (fRec25[1] + (fRec34[1] + (fRec9 + (fRec18 + fTemp14)))))));
			fRec5[0] = ((fRec8[1] + (fRec17[1] + (fRec30[1] + (fRec38[1] + (fRec9 + (fRec18 + fTemp13)))))) - (fRec13[1] + (fRec21[1] + (fRec25[1] + (fRec34[1] + (fRec14 + (fRec22 + fTemp14)))))));
			float fTemp15 = (fRec39 + fRec26);
			float fTemp16 = (fRec35 + fRec31);
			fRec6[0] = ((fRec8[1] + (fRec21[1] + (fRec25[1] + (fRec38[1] + (fRec9 + (fRec22 + fTemp15)))))) - (fRec13[1] + (fRec17[1] + (fRec30[1] + (fRec34[1] + (fRec14 + (fRec18 + fTemp16)))))));
			fRec7[0] = ((fRec13[1] + (fRec17[1] + (fRec25[1] + (fRec38[1] + (fRec14 + (fRec18 + fTemp15)))))) - (fRec8[1] + (fRec21[1] + (fRec30[1] + (fRec34[1] + (fRec9 + (fRec22 + fTemp16)))))));
			output0[i0] = FAUSTFLOAT((0.370000005f * (fRec1[0] + fRec2[0])));
			output1[i0] = FAUSTFLOAT((0.370000005f * (fRec1[0] - fRec2[0])));
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			IOTA = (IOTA + 1);
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec8[1] = fRec8[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec17[1] = fRec17[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec25[1] = fRec25[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
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
