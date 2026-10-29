/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "guzheng"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustGuzhengDSP_H__
#define  __FaustGuzhengDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustGuzhengDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec30[2];
	
  public:
	
	int getNumInputsFaustGuzhengDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustGuzhengDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustGuzhengDSPSIG0(int sample_rate) {
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec1[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec30[l5] = 0;
		}
	}
	
	void fillFaustGuzhengDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec30[0] = ((iVec1[1] + iRec30[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec30[0])));
			iVec1[1] = iVec1[0];
			iRec30[1] = iRec30[0];
		}
	}

};

static FaustGuzhengDSPSIG0* newFaustGuzhengDSPSIG0() { return (FaustGuzhengDSPSIG0*)new FaustGuzhengDSPSIG0(); }
static void deleteFaustGuzhengDSPSIG0(FaustGuzhengDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustGuzhengDSPSIG0[65536];
static float FaustGuzhengDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustGuzhengDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustGuzhengDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst4;
	float fConst5;
	float fConst7;
	float fConst9;
	float fConst10;
	int iRec13[2];
	float fConst11;
	float fConst12;
	FAUSTFLOAT fHslider1;
	float fConst13;
	FAUSTFLOAT fHslider2;
	float fConst14;
	float fRec28[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst15;
	float fConst16;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec29[2];
	float fConst17;
	FAUSTFLOAT fHslider5;
	float fRec32[2];
	float fRec31[2];
	FAUSTFLOAT fHslider6;
	float fRec33[2];
	float fRec25[2];
	float fRec34[2];
	float fRec36[4];
	int IOTA;
	float fRec37[2048];
	float fVec2[2];
	FAUSTFLOAT fHslider7;
	int iRec39[2];
	float fConst18;
	float fRec38[3];
	float fConst19;
	float fRec42[3];
	float fRec41[3];
	int iRec43[2];
	float fConst20;
	float fVec3[2];
	int iRec40[2];
	float fVec4[2];
	float fRec35[2048];
	float fRec22[2];
	float fRec19[2048];
	float fRec21[2];
	float fRec18[4];
	int iRec9[2];
	float fRec5[2048];
	float fRec3[2];
	float fRec4[2];
	float fRec2[2];
	float fConst21;
	float fRec44[2];
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec1[3];
	float fRec45[3];
	float fRec46[3];
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec47[3];
	float fRec48[3];
	float fVec5[2];
	float fRec0[2];
	
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
		m->declare("filename", "guzheng.dsp");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "guzheng");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
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
		FaustGuzhengDSPSIG0* sig0 = newFaustGuzhengDSPSIG0();
		sig0->instanceInitFaustGuzhengDSPSIG0(sample_rate);
		sig0->fillFaustGuzhengDSPSIG0(65536, ftbl0FaustGuzhengDSPSIG0);
		deleteFaustGuzhengDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((1822.12378f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.166666672f) / fConst1) + 1.0f);
		fConst4 = (0.5f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		float fConst6 = std::tan((8796.45898f / fConst0));
		fConst7 = (1.0f / fConst6);
		float fConst8 = (fConst7 + 1.0f);
		fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f - fConst7);
		fConst11 = (0.00882352982f * fConst0);
		fConst12 = (0.00147058826f * fConst0);
		fConst13 = (44.0999985f / fConst0);
		fConst14 = (1.0f - fConst13);
		fConst15 = std::exp((0.0f - (12.5f / fConst0)));
		fConst16 = (1.0f - fConst15);
		fConst17 = (1.0f / fConst0);
		fConst18 = (15.707963f / fConst0);
		fConst19 = (3.14159274f / fConst0);
		fConst20 = (0.00200000009f * fConst0);
		fConst21 = (0.0f - (1.0f / (fConst6 * fConst8)));
		fConst22 = (1.0f / fConst3);
		fConst23 = (((fConst2 + -0.166666672f) / fConst1) + 1.0f);
		fConst24 = (2.0f * (1.0f - (1.0f / FaustGuzhengDSP_faustpower2_f(fConst1))));
		float fConst25 = std::tan((565.486694f / fConst0));
		float fConst26 = (1.0f / fConst25);
		float fConst27 = (((fConst26 + 0.200000003f) / fConst25) + 1.0f);
		fConst28 = (0.349999994f / (fConst25 * fConst27));
		fConst29 = (0.0f - fConst28);
		fConst30 = (1.0f / fConst27);
		fConst31 = (((fConst26 + -0.200000003f) / fConst25) + 1.0f);
		fConst32 = (2.0f * (1.0f - (1.0f / FaustGuzhengDSP_faustpower2_f(fConst25))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.91000000000000003f);
		fHslider3 = FAUSTFLOAT(261.63f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(5.2000000000000002f);
		fHslider6 = FAUSTFLOAT(0.044999999999999998f);
		fHslider7 = FAUSTFLOAT(0.80000000000000004f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec13[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec28[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec29[l3] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec32[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec31[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec33[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec25[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec34[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 4); l11 = (l11 + 1)) {
			fRec36[l11] = 0.0f;
		}
		IOTA = 0;
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fRec37[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fVec2[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iRec39[l14] = 0;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec38[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec42[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec41[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iRec43[l18] = 0;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fVec3[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			iRec40[l20] = 0;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fVec4[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2048); l22 = (l22 + 1)) {
			fRec35[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2048); l24 = (l24 + 1)) {
			fRec19[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec21[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 4); l26 = (l26 + 1)) {
			fRec18[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			iRec9[l27] = 0;
		}
		for (int l28 = 0; (l28 < 2048); l28 = (l28 + 1)) {
			fRec5[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec3[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec4[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec2[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec44[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec1[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec45[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec46[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec47[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec48[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fVec5[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec0[l39] = 0.0f;
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
	
	virtual FaustGuzhengDSP* clone() {
		return new FaustGuzhengDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("guzheng");
		ui_interface->addHorizontalSlider("calibration", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-100.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(261.630005f), FAUSTFLOAT(65.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("pluckPosition", &fHslider2, FAUSTFLOAT(0.910000026f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.99000001f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider7, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider6, FAUSTFLOAT(0.0450000018f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.119999997f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider5, FAUSTFLOAT(5.19999981f), FAUSTFLOAT(1.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (360.0f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		int iSlow2 = (fSlow1 == 1.0f);
		int iSlow3 = (fSlow1 == 2.0f);
		int iSlow4 = (fSlow1 == 3.0f);
		float fSlow5 = (fConst13 * float(fHslider2));
		float fSlow6 = float(fHslider3);
		float fSlow7 = (fSlow6 * std::pow(2.0f, (0.000833333354f * float(fHslider4))));
		float fSlow8 = float(fButton0);
		float fSlow9 = (fConst16 * fSlow8);
		float fSlow10 = (fConst13 * float(fHslider5));
		float fSlow11 = (fConst13 * float(fHslider6));
		float fSlow12 = float(fHslider7);
		float fThen6 = (iSlow4 ? 0.119999997f : 0.140000001f);
		float fThen7 = (iSlow3 ? 0.180000007f : fThen6);
		float fSlow13 = (iSlow2 ? 0.109999999f : fThen7);
		float fThen9 = (iSlow4 ? 600.0f : 220.0f);
		float fThen10 = (iSlow3 ? 160.0f : fThen9);
		float fSlow14 = std::tan((fConst19 * (iSlow2 ? 120.0f : fThen10)));
		float fSlow15 = FaustGuzhengDSP_faustpower2_f(fSlow14);
		float fSlow16 = (0.0f - (2.0f / fSlow15));
		float fSlow17 = (1.0f / fSlow14);
		float fSlow18 = (((fSlow17 + -1.41421354f) / fSlow14) + 1.0f);
		float fSlow19 = (1.0f - (1.0f / fSlow15));
		float fSlow20 = (((fSlow17 + 1.41421354f) / fSlow14) + 1.0f);
		float fThen12 = (iSlow4 ? 12000.0f : 8500.0f);
		float fThen13 = (iSlow3 ? 7500.0f : fThen12);
		float fSlow21 = std::tan((fConst19 * (iSlow2 ? 3800.0f : fThen13)));
		float fSlow22 = (1.0f / fSlow21);
		float fSlow23 = (((fSlow22 + -1.41421354f) / fSlow21) + 1.0f);
		float fSlow24 = (1.0f - (1.0f / FaustGuzhengDSP_faustpower2_f(fSlow21)));
		float fSlow25 = (((fSlow22 + 1.41421354f) / fSlow21) + 1.0f);
		float fThen15 = (iSlow4 ? 0.349999994f : 0.449999988f);
		float fThen16 = (iSlow3 ? 0.600000024f : fThen15);
		float fSlow26 = std::max<float>(1.0f, (fConst20 * (iSlow2 ? 0.280000001f : fThen16)));
		float fSlow27 = std::tan((fConst19 * std::min<float>(18000.0f, (3.0f * fSlow6))));
		float fSlow28 = (1.0f / fSlow27);
		float fSlow29 = (((fSlow28 + 0.125f) / fSlow27) + 1.0f);
		float fSlow30 = (0.600000024f / (fSlow27 * fSlow29));
		float fSlow31 = (0.0f - fSlow30);
		float fSlow32 = (1.0f / fSlow29);
		float fSlow33 = (((fSlow28 + -0.125f) / fSlow27) + 1.0f);
		float fSlow34 = (2.0f * (1.0f - (1.0f / FaustGuzhengDSP_faustpower2_f(fSlow27))));
		float fSlow35 = std::tan((fConst19 * std::min<float>(18000.0f, (2.0f * fSlow6))));
		float fSlow36 = (1.0f / fSlow35);
		float fSlow37 = (((fSlow36 + 0.100000001f) / fSlow35) + 1.0f);
		float fSlow38 = (0.800000012f / (fSlow35 * fSlow37));
		float fSlow39 = (1.0f / fSlow37);
		float fSlow40 = (((fSlow36 + -0.100000001f) / fSlow35) + 1.0f);
		float fSlow41 = (2.0f * (1.0f - (1.0f / FaustGuzhengDSP_faustpower2_f(fSlow35))));
		float fSlow42 = (0.0f - fSlow38);
		float fSlow43 = std::tan((fConst19 * fSlow6));
		float fSlow44 = (1.0f / fSlow43);
		float fSlow45 = (((fSlow44 + 0.125f) / fSlow43) + 1.0f);
		float fSlow46 = (0.5f / (fSlow43 * fSlow45));
		float fSlow47 = (0.0f - fSlow46);
		float fSlow48 = (1.0f / fSlow45);
		float fSlow49 = (((fSlow44 + -0.125f) / fSlow43) + 1.0f);
		float fSlow50 = (2.0f * (1.0f - (1.0f / FaustGuzhengDSP_faustpower2_f(fSlow43))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec13[0] = 0;
			int iRec14 = iRec13[1];
			float fTempFTZ0 = (float(iRec9[1]) - (0.997843683f * ((0.699999988f * fRec18[2]) + (0.150000006f * (fRec18[1] + fRec18[3])))));
			float fRec17 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow5 + (fConst14 * fRec28[1]));
			fRec28[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fThen1 = (iSlow4 ? 0.5f : fRec28[0]);
			float fThen2 = (iSlow3 ? 0.879999995f : fThen1);
			float fTemp0 = (iSlow2 ? 0.819999993f : fThen2);
			fVec0[0] = fSlow8;
			float fTempFTZ2 = (fSlow9 + (fConst15 * fRec29[1]));
			fRec29[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow10 + (fConst14 * fRec32[1]));
			fRec32[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp1 = (fRec31[1] + (fConst17 * fRec32[0]));
			float fTempFTZ4 = (fTemp1 - std::floor(fTemp1));
			fRec31[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow11 + (fConst14 * fRec33[1]));
			fRec33[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fElse3 = (0.349999994f * fRec33[0]);
			float fTemp2 = std::max<float>(20.0f, (fSlow7 * (((fRec29[0] * ftbl0FaustGuzhengDSPSIG0[int((65536.0f * fRec31[0]))]) * (iSlow4 ? fElse3 : fRec33[0])) + 1.0f)));
			float fElse4 = (2.0f * fTemp2);
			float fTemp3 = (iSlow4 ? fElse4 : fTemp2);
			float fTemp4 = ((340.0f / fTemp3) + -0.100000001f);
			float fTemp5 = (fConst12 * ((1.0f - fTemp0) * fTemp4));
			float fTemp6 = (fTemp5 + -1.49999499f);
			int iTemp7 = int(fTemp6);
			int iTemp8 = int(std::min<float>(fConst11, float(std::max<int>(0, iTemp7))));
			float fTemp9 = std::floor(fTemp6);
			float fTemp10 = (fTemp5 + (-1.0f - fTemp9));
			float fTemp11 = (0.0f - fTemp10);
			float fTemp12 = (fTemp5 + (-2.0f - fTemp9));
			float fTemp13 = (0.0f - (0.5f * fTemp12));
			float fTemp14 = (fTemp5 + (-3.0f - fTemp9));
			float fTemp15 = (0.0f - (0.333333343f * fTemp14));
			float fTemp16 = (fTemp5 + (-4.0f - fTemp9));
			float fTemp17 = (0.0f - (0.25f * fTemp16));
			float fTemp18 = (fTemp5 - fTemp9);
			int iTemp19 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp7 + 1)))));
			float fTemp20 = (0.0f - fTemp12);
			float fTemp21 = (0.0f - (0.5f * fTemp14));
			float fTemp22 = (0.0f - (0.333333343f * fTemp16));
			int iTemp23 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp7 + 2)))));
			float fTemp24 = (0.0f - fTemp14);
			float fTemp25 = (0.0f - (0.5f * fTemp16));
			float fTemp26 = (fTemp10 * fTemp12);
			int iTemp27 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp7 + 3)))));
			float fTemp28 = (0.0f - fTemp16);
			float fTemp29 = (fTemp26 * fTemp14);
			int iTemp30 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp7 + 4)))));
			float fTempFTZ6 = (((((fRec5[((IOTA - (iTemp8 + 1)) & 2047)] * fTemp11) * fTemp13) * fTemp15) * fTemp17) + (fTemp18 * ((((((fRec5[((IOTA - (iTemp19 + 1)) & 2047)] * fTemp20) * fTemp21) * fTemp22) + (0.5f * (((fTemp10 * fRec5[((IOTA - (iTemp23 + 1)) & 2047)]) * fTemp24) * fTemp25))) + (0.166666672f * ((fTemp26 * fRec5[((IOTA - (iTemp27 + 1)) & 2047)]) * fTemp28))) + (0.0416666679f * (fTemp29 * fRec5[((IOTA - (iTemp30 + 1)) & 2047)])))));
			fRec25[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((0.0500000007f * fRec34[1]) + (0.949999988f * fRec25[1]));
			fRec34[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = fRec34[0];
			float fRec26 = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = fRec3[1];
			fRec36[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (-1.0f * (0.997843683f * ((0.699999988f * fRec36[2]) + (0.150000006f * (fRec36[1] + fRec36[3])))));
			fRec37[(IOTA & 2047)] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp31 = (fConst12 * (fTemp0 * fTemp4));
			float fTemp32 = (fTemp31 + -1.49999499f);
			int iTemp33 = int(fTemp32);
			int iTemp34 = int(std::min<float>(fConst11, float(std::max<int>(0, iTemp33))));
			float fTemp35 = std::floor(fTemp32);
			float fTemp36 = (fTemp31 + (-1.0f - fTemp35));
			float fTemp37 = (0.0f - fTemp36);
			float fTemp38 = (fTemp31 + (-2.0f - fTemp35));
			float fTemp39 = (0.0f - (0.5f * fTemp38));
			float fTemp40 = (fTemp31 + (-3.0f - fTemp35));
			float fTemp41 = (0.0f - (0.333333343f * fTemp40));
			float fTemp42 = (fTemp31 + (-4.0f - fTemp35));
			float fTemp43 = (0.0f - (0.25f * fTemp42));
			float fTemp44 = (fTemp31 - fTemp35);
			int iTemp45 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp33 + 1)))));
			float fTemp46 = (0.0f - fTemp38);
			float fTemp47 = (0.0f - (0.5f * fTemp40));
			float fTemp48 = (0.0f - (0.333333343f * fTemp42));
			int iTemp49 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp33 + 2)))));
			float fTemp50 = (0.0f - fTemp40);
			float fTemp51 = (0.0f - (0.5f * fTemp42));
			float fTemp52 = (fTemp36 * fTemp38);
			int iTemp53 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp33 + 3)))));
			float fTemp54 = (0.0f - fTemp42);
			float fTemp55 = (fTemp52 * fTemp40);
			int iTemp56 = int(std::min<float>(fConst11, float(std::max<int>(0, (iTemp33 + 4)))));
			fVec2[0] = (((((fRec37[((IOTA - (iTemp34 + 2)) & 2047)] * fTemp37) * fTemp39) * fTemp41) * fTemp43) + (fTemp44 * ((((((fRec37[((IOTA - (iTemp45 + 2)) & 2047)] * fTemp46) * fTemp47) * fTemp48) + (0.5f * (((fTemp36 * fRec37[((IOTA - (iTemp49 + 2)) & 2047)]) * fTemp50) * fTemp51))) + (0.166666672f * ((fTemp52 * fRec37[((IOTA - (iTemp53 + 2)) & 2047)]) * fTemp54))) + (0.0416666679f * (fTemp55 * fRec37[((IOTA - (iTemp56 + 2)) & 2047)])))));
			iRec39[0] = ((1103515245 * iRec39[1]) + 12345);
			float fTemp57 = (4.65661287e-10f * float(iRec39[0]));
			float fTemp58 = std::tan((fConst18 * fTemp3));
			float fTemp59 = (1.0f / fTemp58);
			float fTemp60 = (((fTemp59 + 1.41421354f) / fTemp58) + 1.0f);
			float fTempFTZ11 = (fTemp57 - (((fRec38[2] * (((fTemp59 + -1.41421354f) / fTemp58) + 1.0f)) + (2.0f * (fRec38[1] * (1.0f - (1.0f / FaustGuzhengDSP_faustpower2_f(fTemp58)))))) / fTemp60));
			fRec38[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fTemp57 - (((fRec42[2] * fSlow18) + (2.0f * (fRec42[1] * fSlow19))) / fSlow20));
			fRec42[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (((((fSlow16 * fRec42[1]) + (fRec42[0] / fSlow15)) + (fRec42[2] / fSlow15)) / fSlow20) - (((fRec41[2] * fSlow23) + (2.0f * (fRec41[1] * fSlow24))) / fSlow25));
			fRec41[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			iRec43[0] = ((fSlow8 > fVec0[1]) + ((fSlow8 <= fVec0[1]) * (iRec43[1] + (iRec43[1] > 0))));
			float fTemp61 = (float(iRec43[0]) / fSlow26);
			float fTemp62 = (((fRec41[2] + (fRec41[0] + (2.0f * fRec41[1]))) * std::max<float>(0.0f, std::min<float>(fTemp61, (2.0f - fTemp61)))) / fSlow25);
			fVec3[0] = fTemp62;
			iRec40[0] = (((iRec40[1] + (iRec40[1] > 0)) * (fTemp62 <= fVec3[1])) + (fTemp62 > fVec3[1]));
			float fTemp63 = (float(iRec40[0]) / std::max<float>(1.0f, (fConst20 * FaustGuzhengDSP_faustpower2_f((1.0f - (0.00033333333f * fTemp3))))));
			float fTemp64 = (fSlow12 * (((fSlow13 * (fRec38[2] + (fRec38[0] + (2.0f * fRec38[1])))) * std::max<float>(0.0f, std::min<float>(fTemp63, (2.0f - fTemp63)))) / fTemp60));
			fVec4[0] = (fVec2[1] + fTemp64);
			float fTempFTZ14 = ((0.0500000007f * fRec35[((IOTA - 1) & 2047)]) + (0.949999988f * fVec4[1]));
			fRec35[(IOTA & 2047)] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (((((fTemp11 * fTemp13) * fTemp15) * fTemp17) * fRec35[((IOTA - iTemp8) & 2047)]) + (fTemp18 * ((((((fTemp20 * fTemp21) * fTemp22) * fRec35[((IOTA - iTemp19) & 2047)]) + (0.5f * (((fTemp10 * fTemp24) * fTemp25) * fRec35[((IOTA - iTemp23) & 2047)]))) + (0.166666672f * ((fTemp26 * fTemp28) * fRec35[((IOTA - iTemp27) & 2047)]))) + (0.0416666679f * (fTemp29 * fRec35[((IOTA - iTemp30) & 2047)])))));
			float fRec27 = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = fRec26;
			fRec22[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fTemp64 + fRec22[1]);
			float fRec23 = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec27;
			float fRec24 = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = fRec23;
			fRec19[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (((((fTemp37 * fTemp39) * fTemp41) * fTemp43) * fRec19[((IOTA - (iTemp34 + 1)) & 2047)]) + (fTemp44 * ((((((fTemp46 * fTemp47) * fTemp48) * fRec19[((IOTA - (iTemp45 + 1)) & 2047)]) + (0.5f * (((fTemp36 * fTemp50) * fTemp51) * fRec19[((IOTA - (iTemp49 + 1)) & 2047)]))) + (0.166666672f * ((fTemp52 * fTemp54) * fRec19[((IOTA - (iTemp53 + 1)) & 2047)]))) + (0.0416666679f * (fTemp55 * fRec19[((IOTA - (iTemp56 + 1)) & 2047)])))));
			float fRec20 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec24;
			fRec21[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = fRec21[1];
			fRec18[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec18[1];
			float fTemp65 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fRec15 = fTemp65;
			float fRec16 = fTemp65;
			iRec9[0] = iRec14;
			float fTempFTZ24 = fRec17;
			float fRec10 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec15;
			float fRec11 = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec16;
			float fRec12 = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec10;
			fRec5[(IOTA & 2047)] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = fRec20;
			float fRec6 = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec11;
			float fRec7 = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = fRec12;
			float fRec8 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = fRec6;
			fRec3[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec8;
			fRec4[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (0.0f - (fConst9 * ((fConst10 * fRec2[1]) - (fRec4[0] + fRec4[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = ((fConst21 * fRec4[1]) - (fConst9 * ((fConst10 * fRec44[1]) - (fConst7 * fRec4[0]))));
			fRec44[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTemp66 = (fRec2[0] + (1.38038421f * fRec44[0]));
			float fTempFTZ35 = (fTemp66 - (fConst22 * ((fConst23 * fRec1[2]) + (fConst24 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fTemp66 - (fSlow32 * ((fSlow33 * fRec45[2]) + (fSlow34 * fRec45[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp66 - (fSlow39 * ((fSlow40 * fRec46[2]) + (fSlow41 * fRec46[1]))));
			fRec46[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTemp67 = (0.333333343f * ((fConst5 * fRec1[2]) + (((fSlow31 * fRec45[2]) + (((fSlow38 * fRec46[0]) + (fSlow42 * fRec46[2])) + (fSlow30 * fRec45[0]))) + (fConst4 * fRec1[0]))));
			float fTempFTZ38 = (fTemp66 - (fConst30 * ((fConst31 * fRec47[2]) + (fConst32 * fRec47[1]))));
			fRec47[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTemp68 = (fConst29 * fRec47[2]);
			float fTemp69 = (fConst28 * fRec47[0]);
			float fTempFTZ39 = (fTemp66 - (fSlow48 * ((fSlow49 * fRec48[2]) + (fSlow50 * fRec48[1]))));
			fRec48[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTemp70 = (fSlow47 * fRec48[2]);
			float fTemp71 = (fSlow46 * fRec48[0]);
			fVec5[0] = ((fTemp68 + ((fTemp71 + fTemp70) + fTemp69)) + fTemp67);
			float fTempFTZ40 = ((fTemp67 + (fTemp68 + (fTemp69 + (fTemp70 + ((0.995000005f * fRec0[1]) + fTemp71))))) - fVec5[1]);
			fRec0[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * fRec0[0])))));
			iRec13[1] = iRec13[0];
			fRec28[1] = fRec28[0];
			fVec0[1] = fVec0[0];
			fRec29[1] = fRec29[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			fRec25[1] = fRec25[0];
			fRec34[1] = fRec34[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec36[j0] = fRec36[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			iRec39[1] = iRec39[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			iRec43[1] = iRec43[0];
			fVec3[1] = fVec3[0];
			iRec40[1] = iRec40[0];
			fVec4[1] = fVec4[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec18[j1] = fRec18[(j1 - 1)];
			}
			iRec9[1] = iRec9[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec44[1] = fRec44[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fVec5[1] = fVec5[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
