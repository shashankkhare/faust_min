/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "acoustic_guitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustAcousticGuitarDSP_H__
#define  __FaustAcousticGuitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustAcousticGuitarDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustAcousticGuitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustAcousticGuitarDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst3;
	int iRec13[2];
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider1;
	float fConst6;
	FAUSTFLOAT fHslider2;
	float fConst7;
	float fRec29[2];
	float fRec26[2];
	float fRec30[2];
	float fRec32[2];
	int IOTA;
	float fRec33[2048];
	float fVec0[2];
	FAUSTFLOAT fHslider3;
	float fConst8;
	int iRec35[2];
	float fRec34[3];
	float fConst9;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fVec2[2];
	int iRec36[2];
	float fVec3[2];
	float fRec31[2048];
	float fRec23[2];
	float fRec20[2048];
	float fRec22[2];
	float fRec18[2];
	int iRec19[4];
	int iRec9[2];
	float fRec5[2048];
	float fRec3[2];
	float fRec4[2];
	float fConst10;
	float fConst11;
	float fRec2[3];
	float fConst13;
	float fConst14;
	int iRec48[2];
	float fRec61[2];
	float fRec64[2];
	float fRec66[2];
	float fRec67[2048];
	float fVec4[2];
	float fVec5[2];
	float fRec65[2048];
	float fRec58[2];
	float fRec55[2048];
	float fRec57[2];
	float fRec53[2];
	int iRec54[4];
	int iRec44[2];
	float fRec40[2048];
	float fRec38[2];
	float fRec39[2];
	float fRec37[2];
	float fConst16;
	float fConst18;
	float fConst19;
	float fRec68[2];
	float fConst20;
	float fRec69[2];
	float fConst21;
	float fRec1[3];
	float fRec70[3];
	float fRec71[3];
	float fRec72[3];
	float fVec6[2];
	float fRec0[2];
	FAUSTFLOAT fHslider4;
	float fRec73[2];
	
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
		m->declare("filename", "acoustic_guitar.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("fm.lib/copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "acoustic_guitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
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
		float fConst1 = std::tan((2356.19458f / fConst0));
		float fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / (((fConst2 + 1.41421354f) / fConst1) + 1.0f));
		fConst4 = (0.00882352982f * fConst0);
		fConst5 = (0.00147058826f * fConst0);
		fConst6 = (44.0999985f / fConst0);
		fConst7 = (1.0f - fConst6);
		fConst8 = (15.707963f / fConst0);
		fConst9 = (0.00200000009f * fConst0);
		fConst10 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst11 = (2.0f * (1.0f - (1.0f / FaustAcousticGuitarDSP_faustpower2_f(fConst1))));
		float fConst12 = (1.0f / std::tan((6911.50391f / fConst0)));
		fConst13 = (1.0f / (fConst12 + 1.0f));
		fConst14 = (1.0f - fConst12);
		float fConst15 = std::tan((9424.77832f / fConst0));
		fConst16 = (1.0f / fConst15);
		float fConst17 = (fConst16 + 1.0f);
		fConst18 = (1.0f / fConst17);
		fConst19 = (1.0f - fConst16);
		fConst20 = (0.0f - (1.0f / (fConst15 * fConst17)));
		fConst21 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(196.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec13[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec29[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec26[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec30[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec32[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 2048); l5 = (l5 + 1)) {
			fRec33[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec35[l7] = 0;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec34[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iRec36[l11] = 0;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec3[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2048); l13 = (l13 + 1)) {
			fRec31[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec23[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2048); l15 = (l15 + 1)) {
			fRec20[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec22[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec18[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 4); l18 = (l18 + 1)) {
			iRec19[l18] = 0;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			iRec9[l19] = 0;
		}
		for (int l20 = 0; (l20 < 2048); l20 = (l20 + 1)) {
			fRec5[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec3[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec4[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec2[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			iRec48[l24] = 0;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec61[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec64[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec66[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2048); l28 = (l28 + 1)) {
			fRec67[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fVec4[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fVec5[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2048); l31 = (l31 + 1)) {
			fRec65[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec58[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2048); l33 = (l33 + 1)) {
			fRec55[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec57[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec53[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 4); l36 = (l36 + 1)) {
			iRec54[l36] = 0;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			iRec44[l37] = 0;
		}
		for (int l38 = 0; (l38 < 2048); l38 = (l38 + 1)) {
			fRec40[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec38[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec39[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec37[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec68[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec69[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec1[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec70[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec71[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec72[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fVec6[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec0[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec73[l50] = 0.0f;
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
	
	virtual FaustAcousticGuitarDSP* clone() {
		return new FaustAcousticGuitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("acoustic_guitar");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(196.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("pluckPosition", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.99000001f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("stringType", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		int iSlow0 = int(float(fHslider0));
		int iSlow1 = (iSlow0 == 0);
		int iSlow2 = (iSlow0 == 1);
		float fSlow3 = float(fHslider1);
		float fSlow4 = (fConst5 * ((340.0f / fSlow3) + -0.100000001f));
		float fSlow5 = (fConst6 * float(fHslider2));
		float fSlow6 = std::tan((fConst8 * fSlow3));
		float fSlow7 = (1.0f / fSlow6);
		float fSlow8 = (((fSlow7 + 1.41421354f) / fSlow6) + 1.0f);
		float fSlow9 = (50.0f * (float(fHslider3) / fSlow8));
		float fSlow10 = (1.0f / fSlow8);
		float fSlow11 = (((fSlow7 + -1.41421354f) / fSlow6) + 1.0f);
		float fSlow12 = (2.0f * (1.0f - (1.0f / FaustAcousticGuitarDSP_faustpower2_f(fSlow6))));
		float fSlow13 = (1.0f / std::max<float>(1.0f, (fConst9 * FaustAcousticGuitarDSP_faustpower2_f((1.0f - (0.00033333333f * fSlow3))))));
		float fSlow14 = float(fButton0);
		int iSlow15 = (iSlow0 > 0);
		int iSlow16 = (iSlow0 > 1);
		float fElse3 = (iSlow16 ? 210.0f : 320.0f);
		float fSlow17 = std::tan((fConst21 * (iSlow15 ? fElse3 : 410.0f)));
		float fSlow18 = (1.0f / fSlow17);
		float fSlow19 = (((fSlow18 + -0.0833333358f) / fSlow17) + 1.0f);
		float fSlow20 = (1.0f - (1.0f / FaustAcousticGuitarDSP_faustpower2_f(fSlow17)));
		float fSlow21 = (((fSlow18 + 0.0833333358f) / fSlow17) + 1.0f);
		float fSlow22 = (fSlow17 * fSlow21);
		float fSlow23 = (0.0f - (0.300000012f / fSlow22));
		float fElse5 = (iSlow16 ? 138.0f : 195.0f);
		float fSlow24 = std::tan((fConst21 * (iSlow15 ? fElse5 : 220.0f)));
		float fSlow25 = (1.0f / fSlow24);
		float fSlow26 = (((fSlow25 + -0.055555556f) / fSlow24) + 1.0f);
		float fSlow27 = (1.0f - (1.0f / FaustAcousticGuitarDSP_faustpower2_f(fSlow24)));
		float fSlow28 = (((fSlow25 + 0.055555556f) / fSlow24) + 1.0f);
		float fSlow29 = (fSlow24 * fSlow28);
		float fSlow30 = (0.0f - (0.400000006f / fSlow29));
		float fElse7 = (iSlow16 ? 105.0f : 160.0f);
		float fSlow31 = std::tan((fConst21 * (iSlow15 ? fElse7 : 190.0f)));
		float fSlow32 = (1.0f / fSlow31);
		float fSlow33 = (((fSlow32 + -0.0666666701f) / fSlow31) + 1.0f);
		float fSlow34 = (1.0f - (1.0f / FaustAcousticGuitarDSP_faustpower2_f(fSlow31)));
		float fSlow35 = (((fSlow32 + 0.0666666701f) / fSlow31) + 1.0f);
		float fSlow36 = (fSlow31 * fSlow35);
		float fSlow37 = (0.0f - (0.5f / fSlow36));
		float fElse9 = (iSlow16 ? 52.0f : 85.0f);
		float fSlow38 = std::tan((fConst21 * (iSlow15 ? fElse9 : 100.0f)));
		float fSlow39 = (1.0f / fSlow38);
		float fElse11 = (iSlow16 ? 38.0f : 12.0f);
		float fSlow40 = (1.0f / (iSlow15 ? fElse11 : 25.0f));
		float fSlow41 = (((fSlow39 - fSlow40) / fSlow38) + 1.0f);
		float fSlow42 = (1.0f - (1.0f / FaustAcousticGuitarDSP_faustpower2_f(fSlow38)));
		float fSlow43 = (((fSlow40 + fSlow39) / fSlow38) + 1.0f);
		float fElse13 = (iSlow16 ? 1.39999998f : 0.800000012f);
		float fSlow44 = (iSlow15 ? fElse13 : 0.400000006f);
		float fSlow45 = (fSlow38 * fSlow43);
		float fSlow46 = (0.0f - (fSlow44 / fSlow45));
		float fSlow47 = (fConst6 * float(fHslider4));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec13[0] = 0;
			int iRec14 = iRec13[1];
			float fTempFTZ0 = ((fRec18[1] + float(iRec9[1])) - (0.997843683f * ((0.699999988f * float(iRec19[2])) + (0.150000006f * float((iRec19[1] + iRec19[3]))))));
			float fRec17 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow5 + (fConst7 * fRec29[1]));
			fRec29[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (fSlow4 * (1.0f - fRec29[0]));
			float fTemp1 = (fTemp0 + -1.49999499f);
			int iTemp2 = int(fTemp1);
			int iTemp3 = int(std::min<float>(fConst4, float(std::max<int>(0, iTemp2))));
			int iTemp4 = (iTemp3 + 1);
			float fTemp5 = std::floor(fTemp1);
			float fTemp6 = (fTemp0 + (-1.0f - fTemp5));
			float fTemp7 = (0.0f - fTemp6);
			float fTemp8 = (fTemp0 + (-2.0f - fTemp5));
			float fTemp9 = (0.0f - (0.5f * fTemp8));
			float fTemp10 = (fTemp0 + (-3.0f - fTemp5));
			float fTemp11 = (0.0f - (0.333333343f * fTemp10));
			float fTemp12 = (fTemp0 + (-4.0f - fTemp5));
			float fTemp13 = (0.0f - (0.25f * fTemp12));
			float fTemp14 = (fTemp0 - fTemp5);
			int iTemp15 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp2 + 1)))));
			int iTemp16 = (iTemp15 + 1);
			float fTemp17 = (0.0f - fTemp8);
			float fTemp18 = (0.0f - (0.5f * fTemp10));
			float fTemp19 = (0.0f - (0.333333343f * fTemp12));
			int iTemp20 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp2 + 2)))));
			int iTemp21 = (iTemp20 + 1);
			float fTemp22 = (0.0f - fTemp10);
			float fTemp23 = (0.0f - (0.5f * fTemp12));
			float fTemp24 = (fTemp6 * fTemp8);
			int iTemp25 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp2 + 3)))));
			int iTemp26 = (iTemp25 + 1);
			float fTemp27 = (0.0f - fTemp12);
			float fTemp28 = (fTemp24 * fTemp10);
			int iTemp29 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp2 + 4)))));
			int iTemp30 = (iTemp29 + 1);
			float fTempFTZ2 = (((((fRec5[((IOTA - iTemp4) & 2047)] * fTemp7) * fTemp9) * fTemp11) * fTemp13) + (fTemp14 * ((((((fRec5[((IOTA - iTemp16) & 2047)] * fTemp17) * fTemp18) * fTemp19) + (0.5f * (((fTemp6 * fRec5[((IOTA - iTemp21) & 2047)]) * fTemp22) * fTemp23))) + (0.166666672f * ((fTemp24 * fRec5[((IOTA - iTemp26) & 2047)]) * fTemp27))) + (0.0416666679f * (fTemp28 * fRec5[((IOTA - iTemp30) & 2047)])))));
			fRec26[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.0500000007f * fRec30[1]) + (0.949999988f * fRec26[1]));
			fRec30[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = fRec30[0];
			float fRec27 = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp31 = (((fTemp7 * fTemp9) * fTemp11) * fTemp13);
			float fTempFTZ5 = fRec3[1];
			fRec32[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fRec32[1] - (0.997843683f * ((0.699999988f * fRec33[((IOTA - 2) & 2047)]) + (0.150000006f * (fRec33[((IOTA - 1) & 2047)] + fRec33[((IOTA - 3) & 2047)])))));
			fRec33[(IOTA & 2047)] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp32 = (fSlow4 * fRec29[0]);
			float fTemp33 = (fTemp32 + -1.49999499f);
			int iTemp34 = int(fTemp33);
			int iTemp35 = int(std::min<float>(fConst4, float(std::max<int>(0, iTemp34))));
			int iTemp36 = (iTemp35 + 2);
			float fTemp37 = std::floor(fTemp33);
			float fTemp38 = (fTemp32 + (-1.0f - fTemp37));
			float fTemp39 = (0.0f - fTemp38);
			float fTemp40 = (fTemp32 + (-2.0f - fTemp37));
			float fTemp41 = (0.0f - (0.5f * fTemp40));
			float fTemp42 = (fTemp32 + (-3.0f - fTemp37));
			float fTemp43 = (0.0f - (0.333333343f * fTemp42));
			float fTemp44 = (fTemp32 + (-4.0f - fTemp37));
			float fTemp45 = (0.0f - (0.25f * fTemp44));
			float fTemp46 = (fTemp32 - fTemp37);
			int iTemp47 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp34 + 1)))));
			int iTemp48 = (iTemp47 + 2);
			float fTemp49 = (0.0f - fTemp40);
			float fTemp50 = (0.0f - (0.5f * fTemp42));
			float fTemp51 = (0.0f - (0.333333343f * fTemp44));
			int iTemp52 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp34 + 2)))));
			int iTemp53 = (iTemp52 + 2);
			float fTemp54 = (0.0f - fTemp42);
			float fTemp55 = (0.0f - (0.5f * fTemp44));
			float fTemp56 = (fTemp38 * fTemp40);
			int iTemp57 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp34 + 3)))));
			int iTemp58 = (iTemp57 + 2);
			float fTemp59 = (0.0f - fTemp44);
			float fTemp60 = (fTemp56 * fTemp42);
			int iTemp61 = int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp34 + 4)))));
			int iTemp62 = (iTemp61 + 2);
			fVec0[0] = (((((fRec33[((IOTA - iTemp36) & 2047)] * fTemp39) * fTemp41) * fTemp43) * fTemp45) + (fTemp46 * ((((((fRec33[((IOTA - iTemp48) & 2047)] * fTemp49) * fTemp50) * fTemp51) + (0.5f * (((fTemp38 * fRec33[((IOTA - iTemp53) & 2047)]) * fTemp54) * fTemp55))) + (0.166666672f * ((fTemp56 * fRec33[((IOTA - iTemp58) & 2047)]) * fTemp59))) + (0.0416666679f * (fTemp60 * fRec33[((IOTA - iTemp62) & 2047)])))));
			iRec35[0] = ((1103515245 * iRec35[1]) + 12345);
			float fTempFTZ7 = ((4.65661287e-10f * float(iRec35[0])) - (fSlow10 * ((fSlow11 * fRec34[2]) + (fSlow12 * fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			fVec1[0] = fSlow14;
			float fTemp63 = (fSlow14 - fVec1[1]);
			float fTemp64 = (fTemp63 * float((fTemp63 > 0.0f)));
			fVec2[0] = fTemp64;
			iRec36[0] = (((iRec36[1] + (iRec36[1] > 0)) * (fTemp64 <= fVec2[1])) + (fTemp64 > fVec2[1]));
			float fTemp65 = (fSlow13 * float(iRec36[0]));
			float fTemp66 = (fSlow9 * ((fRec34[2] + (fRec34[0] + (2.0f * fRec34[1]))) * std::max<float>(0.0f, std::min<float>(fTemp65, (2.0f - fTemp65)))));
			fVec3[0] = (fVec0[1] + fTemp66);
			float fTempFTZ8 = ((0.0500000007f * fRec31[((IOTA - 1) & 2047)]) + (0.949999988f * fVec3[1]));
			fRec31[(IOTA & 2047)] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp67 = ((fTemp17 * fTemp18) * fTemp19);
			float fTemp68 = ((fTemp6 * fTemp22) * fTemp23);
			float fTemp69 = (fTemp24 * fTemp27);
			float fTempFTZ9 = ((fTemp31 * fRec31[((IOTA - iTemp3) & 2047)]) + (fTemp14 * ((((fTemp67 * fRec31[((IOTA - iTemp15) & 2047)]) + (0.5f * (fTemp68 * fRec31[((IOTA - iTemp20) & 2047)]))) + (0.166666672f * (fTemp69 * fRec31[((IOTA - iTemp25) & 2047)]))) + (0.0416666679f * (fTemp28 * fRec31[((IOTA - iTemp29) & 2047)])))));
			float fRec28 = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = fRec27;
			fRec23[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp66 + fRec23[1]);
			float fRec24 = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = fRec28;
			float fRec25 = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = fRec24;
			fRec20[(IOTA & 2047)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp70 = (((fTemp39 * fTemp41) * fTemp43) * fTemp45);
			int iTemp71 = (iTemp35 + 1);
			float fTemp72 = ((fTemp49 * fTemp50) * fTemp51);
			int iTemp73 = (iTemp47 + 1);
			float fTemp74 = ((fTemp38 * fTemp54) * fTemp55);
			int iTemp75 = (iTemp52 + 1);
			float fTemp76 = (fTemp56 * fTemp59);
			int iTemp77 = (iTemp57 + 1);
			int iTemp78 = (iTemp61 + 1);
			float fTempFTZ14 = ((fTemp70 * fRec20[((IOTA - iTemp71) & 2047)]) + (fTemp46 * ((((fTemp72 * fRec20[((IOTA - iTemp73) & 2047)]) + (0.5f * (fTemp74 * fRec20[((IOTA - iTemp75) & 2047)]))) + (0.166666672f * (fTemp76 * fRec20[((IOTA - iTemp77) & 2047)]))) + (0.0416666679f * (fTemp60 * fRec20[((IOTA - iTemp78) & 2047)])))));
			float fRec21 = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = fRec25;
			fRec22[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = fRec22[1];
			fRec18[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			iRec19[0] = 0;
			float fTempFTZ17 = fRec18[1];
			float fTemp79 = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fRec15 = fTemp79;
			float fRec16 = fTemp79;
			iRec9[0] = iRec14;
			float fTempFTZ18 = fRec17;
			float fRec10 = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = fRec15;
			float fRec11 = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec16;
			float fRec12 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec10;
			fRec5[(IOTA & 2047)] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = fRec21;
			float fRec6 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec11;
			float fRec7 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec12;
			float fRec8 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec6;
			fRec3[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec8;
			fRec4[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (fRec4[0] - (fConst3 * ((fConst10 * fRec2[2]) + (fConst11 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			iRec48[0] = 0;
			int iRec49 = iRec48[1];
			float fTempFTZ28 = ((fRec53[1] + float(iRec44[1])) - (0.997843683f * ((0.699999988f * float(iRec54[2])) + (0.150000006f * float((iRec54[1] + iRec54[3]))))));
			float fRec52 = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = ((fTemp31 * fRec40[((IOTA - iTemp4) & 2047)]) + (fTemp14 * ((((fTemp67 * fRec40[((IOTA - iTemp16) & 2047)]) + (0.5f * (fTemp68 * fRec40[((IOTA - iTemp21) & 2047)]))) + (0.166666672f * (fTemp69 * fRec40[((IOTA - iTemp26) & 2047)]))) + (0.0416666679f * (fTemp28 * fRec40[((IOTA - iTemp30) & 2047)])))));
			fRec61[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = ((0.400000006f * fRec64[1]) + (0.600000024f * fRec61[1]));
			fRec64[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = fRec64[0];
			float fRec62 = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec38[1];
			fRec66[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (fRec66[1] - (0.997843683f * ((0.699999988f * fRec67[((IOTA - 2) & 2047)]) + (0.150000006f * (fRec67[((IOTA - 1) & 2047)] + fRec67[((IOTA - 3) & 2047)])))));
			fRec67[(IOTA & 2047)] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			fVec4[0] = ((fTemp70 * fRec67[((IOTA - iTemp36) & 2047)]) + (fTemp46 * ((((fTemp72 * fRec67[((IOTA - iTemp48) & 2047)]) + (0.5f * (fTemp74 * fRec67[((IOTA - iTemp53) & 2047)]))) + (0.166666672f * (fTemp76 * fRec67[((IOTA - iTemp58) & 2047)]))) + (0.0416666679f * (fTemp60 * fRec67[((IOTA - iTemp62) & 2047)])))));
			fVec5[0] = (fTemp66 + fVec4[1]);
			float fTempFTZ34 = ((0.400000006f * fRec65[((IOTA - 1) & 2047)]) + (0.600000024f * fVec5[1]));
			fRec65[(IOTA & 2047)] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = ((fTemp31 * fRec65[((IOTA - iTemp3) & 2047)]) + (fTemp14 * ((((fTemp67 * fRec65[((IOTA - iTemp15) & 2047)]) + (0.5f * (fTemp68 * fRec65[((IOTA - iTemp20) & 2047)]))) + (0.166666672f * (fTemp69 * fRec65[((IOTA - iTemp25) & 2047)]))) + (0.0416666679f * (fTemp28 * fRec65[((IOTA - iTemp29) & 2047)])))));
			float fRec63 = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = fRec62;
			fRec58[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp66 + fRec58[1]);
			float fRec59 = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec63;
			float fRec60 = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = fRec59;
			fRec55[(IOTA & 2047)] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = ((fTemp70 * fRec55[((IOTA - iTemp71) & 2047)]) + (fTemp46 * ((((fTemp72 * fRec55[((IOTA - iTemp73) & 2047)]) + (0.5f * (fTemp74 * fRec55[((IOTA - iTemp75) & 2047)]))) + (0.166666672f * (fTemp76 * fRec55[((IOTA - iTemp77) & 2047)]))) + (0.0416666679f * (fTemp60 * fRec55[((IOTA - iTemp78) & 2047)])))));
			float fRec56 = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = fRec60;
			fRec57[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = fRec57[1];
			fRec53[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			iRec54[0] = 0;
			float fTempFTZ43 = fRec53[1];
			float fTemp80 = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fRec50 = fTemp80;
			float fRec51 = fTemp80;
			iRec44[0] = iRec49;
			float fTempFTZ44 = fRec52;
			float fRec45 = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = fRec50;
			float fRec46 = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fTempFTZ46 = fRec51;
			float fRec47 = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = fRec45;
			fRec40[(IOTA & 2047)] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = fRec56;
			float fRec41 = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = fRec46;
			float fRec42 = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = fRec47;
			float fRec43 = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTempFTZ51 = fRec41;
			fRec38[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = fRec43;
			fRec39[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = (0.0f - (fConst13 * ((fConst14 * fRec37[1]) - (fRec39[0] + fRec39[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fThen0 = (fConst3 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))));
			float fTempFTZ54 = (0.0f - (fConst18 * ((fConst19 * fRec68[1]) - (fRec4[0] + fRec4[1]))));
			fRec68[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fTempFTZ55 = ((fConst20 * fRec4[1]) - (fConst18 * ((fConst19 * fRec69[1]) - (fConst16 * fRec4[0]))));
			fRec69[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fThen1 = (iSlow2 ? fRec37[0] : fThen0);
			float fElse1 = (fRec68[0] + (1.41253757f * fRec69[0]));
			float fTemp81 = (iSlow1 ? fElse1 : fThen1);
			float fTempFTZ56 = (fTemp81 - (((fRec1[2] * fSlow19) + (2.0f * (fRec1[1] * fSlow20))) / fSlow21));
			fRec1[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fTempFTZ57 = (fTemp81 - (((fRec70[2] * fSlow26) + (2.0f * (fRec70[1] * fSlow27))) / fSlow28));
			fRec70[0] = ((std::fabs(fTempFTZ57) > 1.17549435e-38f) ? fTempFTZ57 : 0.0f);
			float fTempFTZ58 = (fTemp81 - (((fRec71[2] * fSlow33) + (2.0f * (fRec71[1] * fSlow34))) / fSlow35));
			fRec71[0] = ((std::fabs(fTempFTZ58) > 1.17549435e-38f) ? fTempFTZ58 : 0.0f);
			float fTemp82 = (0.333333343f * ((fRec1[2] * fSlow23) + (((fRec70[2] * fSlow30) + (((0.5f * (fRec71[0] / fSlow36)) + (fRec71[2] * fSlow37)) + (0.400000006f * (fRec70[0] / fSlow29)))) + (0.300000012f * (fRec1[0] / fSlow22)))));
			float fTempFTZ59 = (fTemp81 - (((fRec72[2] * fSlow41) + (2.0f * (fRec72[1] * fSlow42))) / fSlow43));
			fRec72[0] = ((std::fabs(fTempFTZ59) > 1.17549435e-38f) ? fTempFTZ59 : 0.0f);
			float fTemp83 = (fRec72[2] * fSlow46);
			float fTemp84 = ((fSlow44 * fRec72[0]) / fSlow45);
			fVec6[0] = ((fTemp84 + fTemp83) + fTemp82);
			float fTempFTZ60 = ((fTemp82 + (fTemp83 + ((0.995000005f * fRec0[1]) + fTemp84))) - fVec6[1]);
			fRec0[0] = ((std::fabs(fTempFTZ60) > 1.17549435e-38f) ? fTempFTZ60 : 0.0f);
			float fTempFTZ61 = (fSlow47 + (fConst7 * fRec73[1]));
			fRec73[0] = ((std::fabs(fTempFTZ61) > 1.17549435e-38f) ? fTempFTZ61 : 0.0f);
			output0[i0] = FAUSTFLOAT((float(tanhf(float(fRec0[0]))) * fRec73[0]));
			iRec13[1] = iRec13[0];
			fRec29[1] = fRec29[0];
			fRec26[1] = fRec26[0];
			fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			IOTA = (IOTA + 1);
			fVec0[1] = fVec0[0];
			iRec35[1] = iRec35[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fVec1[1] = fVec1[0];
			fVec2[1] = fVec2[0];
			iRec36[1] = iRec36[0];
			fVec3[1] = fVec3[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec18[1] = fRec18[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				iRec19[j0] = iRec19[(j0 - 1)];
			}
			iRec9[1] = iRec9[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			iRec48[1] = iRec48[0];
			fRec61[1] = fRec61[0];
			fRec64[1] = fRec64[0];
			fRec66[1] = fRec66[0];
			fVec4[1] = fVec4[0];
			fVec5[1] = fVec5[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec53[1] = fRec53[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				iRec54[j1] = iRec54[(j1 - 1)];
			}
			iRec44[1] = iRec44[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec68[1] = fRec68[0];
			fRec69[1] = fRec69[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fVec6[1] = fVec6[0];
			fRec0[1] = fRec0[0];
			fRec73[1] = fRec73[0];
		}
	}

};

#endif
