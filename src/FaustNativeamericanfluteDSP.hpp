/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "nativeamericanflute"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustNativeamericanfluteDSP_H__
#define  __FaustNativeamericanfluteDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustNativeamericanfluteDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec37[2];
	
  public:
	
	int getNumInputsFaustNativeamericanfluteDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustNativeamericanfluteDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustNativeamericanfluteDSPSIG0(int sample_rate) {
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iVec1[l18] = 0;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			iRec37[l19] = 0;
		}
	}
	
	void fillFaustNativeamericanfluteDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec37[0] = ((iVec1[1] + iRec37[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec37[0])));
			iVec1[1] = iVec1[0];
			iRec37[1] = iRec37[0];
		}
	}

};

static FaustNativeamericanfluteDSPSIG0* newFaustNativeamericanfluteDSPSIG0() { return (FaustNativeamericanfluteDSPSIG0*)new FaustNativeamericanfluteDSPSIG0(); }
static void deleteFaustNativeamericanfluteDSPSIG0(FaustNativeamericanfluteDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustNativeamericanfluteDSPSIG0[65536];
static float FaustNativeamericanfluteDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustNativeamericanfluteDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustNativeamericanfluteDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[2];
	float fConst2;
	FAUSTFLOAT fHslider1;
	float fConst3;
	float fRec1[2];
	int iRec17[2];
	float fConst4;
	float fConst5;
	float fRec25[2];
	float fRec24[2];
	float fRec23[2];
	FAUSTFLOAT fHslider2;
	float fRec27[2];
	float fRec26[2];
	FAUSTFLOAT fHslider3;
	float fRec28[2];
	float fConst6;
	float fRec29[2];
	int iRec31[2];
	float fRec30[4];
	float fRec32[2];
	int IOTA;
	float fRec33[2048];
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	FAUSTFLOAT fHslider4;
	float fRec34[2];
	FAUSTFLOAT fHslider5;
	float fRec35[2];
	FAUSTFLOAT fHslider6;
	float fRec36[2];
	FAUSTFLOAT fHslider7;
	float fRec39[2];
	float fRec38[2];
	FAUSTFLOAT fHslider8;
	float fRec40[2];
	float fVec2[2];
	float fVec3[2048];
	float fVec4[2];
	float fRec22[2];
	float fRec13[2048];
	float fRec9[2];
	float fRec5[2048];
	float fRec3[2];
	float fRec4[2];
	float fRec2[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "nativeamericanflute.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "nativeamericanflute");
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
		FaustNativeamericanfluteDSPSIG0* sig0 = newFaustNativeamericanfluteDSPSIG0();
		sig0->instanceInitFaustNativeamericanfluteDSPSIG0(sample_rate);
		sig0->fillFaustNativeamericanfluteDSPSIG0(65536, ftbl0FaustNativeamericanfluteDSPSIG0);
		deleteFaustNativeamericanfluteDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = std::exp((0.0f - (100.0f / fConst0)));
		fConst5 = (1.0f - fConst4);
		fConst6 = std::exp((0.0f - (12.5f / fConst0)));
		fConst7 = (0.00882352982f * fConst0);
		fConst8 = (0.00147058826f * fConst0);
		fConst9 = std::exp((0.0f - (333.333344f / fConst0)));
		fConst10 = (1.0f - fConst9);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(0.20000000000000001f);
		fHslider4 = FAUSTFLOAT(440.0f);
		fHslider5 = FAUSTFLOAT(0.59999999999999998f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(5.5f);
		fHslider8 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec17[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec25[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec24[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec23[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec27[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec26[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec28[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec29[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iRec31[l11] = 0;
		}
		for (int l12 = 0; (l12 < 4); l12 = (l12 + 1)) {
			fRec30[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec32[l13] = 0.0f;
		}
		IOTA = 0;
		for (int l14 = 0; (l14 < 2048); l14 = (l14 + 1)) {
			fRec33[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec34[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec35[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec36[l17] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec39[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec38[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec40[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fVec2[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2048); l24 = (l24 + 1)) {
			fVec3[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fVec4[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec22[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2048); l27 = (l27 + 1)) {
			fRec13[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec9[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2048); l29 = (l29 + 1)) {
			fRec5[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec3[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec4[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec2[l32] = 0.0f;
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
	
	virtual FaustNativeamericanfluteDSP* clone() {
		return new FaustNativeamericanfluteDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("nativeamericanflute");
		ui_interface->addHorizontalSlider("breathiness", &fHslider3, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(440.0f), FAUSTFLOAT(293.0f), FAUSTFLOAT(1174.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato", &fHslider5, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider7, FAUSTFLOAT(5.5f), FAUSTFLOAT(1.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = ((0.0560000017f * (1.0f - float(fHslider0))) + 0.00200000009f);
		int iSlow1 = (std::fabs(fSlow0) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst1 / (iSlow1 ? 1.0f : fSlow0))));
		float fSlow2 = (iSlow1 ? 0.0f : fThen1);
		float fSlow3 = float(fButton0);
		float fSlow4 = (1.0f - fSlow2);
		float fSlow5 = (fSlow3 * fSlow4);
		float fSlow6 = (fConst2 * float(fHslider1));
		float fSlow7 = (fConst5 * fSlow3);
		float fSlow8 = (fConst2 * float(fHslider2));
		float fSlow9 = (fConst2 * float(fHslider3));
		float fSlow10 = (0.0599999987f * fSlow3);
		float fSlow11 = float(fHslider4);
		float fSlow12 = (fConst10 * fSlow11);
		float fSlow13 = (fConst2 * float(fHslider5));
		float fSlow14 = (fConst2 * float(fHslider6));
		float fSlow15 = (fConst2 * float(fHslider7));
		float fSlow16 = (fConst2 * float(fHslider8));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow3;
			float fTempFTZ0 = ((fSlow2 * fRec0[1]) + fSlow5);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow6 + (fConst3 * fRec1[1]));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec17[0] = 0;
			float fTempFTZ2 = (fSlow7 + (fConst4 * fRec25[1]));
			fRec25[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.300000012f * fRec24[1]) + (0.67900002f * (fRec25[0] * fRec22[1])));
			fRec24[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((0.400000006f * fRec23[1]) + (0.600000024f * fRec24[0]));
			fRec23[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fRec23[0] + float(iRec17[1]));
			float fRec21 = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fSlow8 + (fConst3 * fRec27[1]));
			fRec27[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((fRec26[1] * fSlow2) + (std::min<float>(1.0f, (fSlow3 * fRec27[0])) * fSlow4));
			fRec26[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fSlow9 + (fConst3 * fRec28[1]));
			fRec28[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((fConst6 * fRec29[1]) + (0.5f * float(((fSlow3 - fVec0[1]) > 0.0f))));
			fRec29[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			iRec31[0] = ((1103515245 * iRec31[1]) + 12345);
			float fTempFTZ10 = (((0.522189379f * fRec30[3]) + ((4.65661287e-10f * float(iRec31[0])) + (2.49495602f * fRec30[1]))) - (2.0172658f * fRec30[2]));
			fRec30[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp0 = (((0.0499220341f * fRec30[0]) + (0.0506126992f * fRec30[2])) - ((0.0959935337f * fRec30[1]) + (0.00440878607f * fRec30[3])));
			float fTempFTZ11 = fRec3[1];
			fRec32[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (0.980000019f * (fRec25[0] * fRec32[1]));
			fRec33[(IOTA & 2047)] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fSlow12 + (fConst9 * fRec34[1]));
			fRec34[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fSlow13 + (fConst3 * fRec35[1]));
			fRec35[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fSlow14 + (fConst3 * fRec36[1]));
			fRec36[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fSlow15 + (fConst3 * fRec39[1]));
			fRec39[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp1 = (fRec38[1] + (fConst1 * fRec39[0]));
			float fTempFTZ17 = (fTemp1 - std::floor(fTemp1));
			fRec38[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp2 = ((340.0f / (fRec34[0] + (fSlow11 * ((fRec35[0] * fRec36[0]) * ftbl0FaustNativeamericanfluteDSPSIG0[int((65536.0f * fRec38[0]))])))) + 0.0270000007f);
			float fTempFTZ18 = (fSlow16 + (fConst3 * fRec40[1]));
			fRec40[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp3 = (0.25f * fRec40[0]);
			float fTemp4 = (fConst8 * (fTemp2 * (fTemp3 + 0.150000006f)));
			float fTemp5 = (fTemp4 + -1.49999499f);
			int iTemp6 = int(fTemp5);
			int iTemp7 = (int(std::min<float>(fConst7, float(std::max<int>(0, iTemp6)))) + 1);
			float fTemp8 = std::floor(fTemp5);
			float fTemp9 = (fTemp4 + (-1.0f - fTemp8));
			float fTemp10 = (0.0f - fTemp9);
			float fTemp11 = (fTemp4 + (-2.0f - fTemp8));
			float fTemp12 = (0.0f - (0.5f * fTemp11));
			float fTemp13 = (fTemp4 + (-3.0f - fTemp8));
			float fTemp14 = (0.0f - (0.333333343f * fTemp13));
			float fTemp15 = (fTemp4 + (-4.0f - fTemp8));
			float fTemp16 = (0.0f - (0.25f * fTemp15));
			float fTemp17 = (fTemp4 - fTemp8);
			int iTemp18 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp6 + 1))))) + 1);
			float fTemp19 = (0.0f - fTemp11);
			float fTemp20 = (0.0f - (0.5f * fTemp13));
			float fTemp21 = (0.0f - (0.333333343f * fTemp15));
			int iTemp22 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp6 + 2))))) + 1);
			float fTemp23 = (0.0f - fTemp13);
			float fTemp24 = (0.0f - (0.5f * fTemp15));
			float fTemp25 = (fTemp9 * fTemp11);
			int iTemp26 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp6 + 3))))) + 1);
			float fTemp27 = (0.0f - fTemp15);
			float fTemp28 = (fTemp25 * fTemp13);
			int iTemp29 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp6 + 4))))) + 1);
			fVec2[0] = (((((fRec33[((IOTA - iTemp7) & 2047)] * fTemp10) * fTemp12) * fTemp14) * fTemp16) + (fTemp17 * ((((((fRec33[((IOTA - iTemp18) & 2047)] * fTemp19) * fTemp20) * fTemp21) + (0.5f * (((fTemp9 * fRec33[((IOTA - iTemp22) & 2047)]) * fTemp23) * fTemp24))) + (0.166666672f * ((fTemp25 * fRec33[((IOTA - iTemp26) & 2047)]) * fTemp27))) + (0.0416666679f * (fTemp28 * fRec33[((IOTA - iTemp29) & 2047)])))));
			float fTemp30 = (((fRec26[0] * (((fRec28[0] + fRec29[0]) * fTemp0) + 1.0f)) + (fSlow10 * (fRec28[0] * fTemp0))) - (0.5f * fVec2[1]));
			float fTemp31 = ((0.5f * fRec9[1]) + std::max<float>(-1.0f, std::min<float>(1.0f, (fTemp30 * (FaustNativeamericanfluteDSP_faustpower2_f(fTemp30) + -1.0f)))));
			fVec3[(IOTA & 2047)] = fTemp31;
			float fTemp32 = (fConst8 * (fTemp2 * (0.850000024f - fTemp3)));
			float fTemp33 = (fTemp32 + -1.49999499f);
			int iTemp34 = int(fTemp33);
			int iTemp35 = (int(std::min<float>(fConst7, float(std::max<int>(0, iTemp34)))) + 1);
			float fTemp36 = std::floor(fTemp33);
			float fTemp37 = (fTemp32 + (-1.0f - fTemp36));
			float fTemp38 = (0.0f - fTemp37);
			float fTemp39 = (fTemp32 + (-2.0f - fTemp36));
			float fTemp40 = (0.0f - (0.5f * fTemp39));
			float fTemp41 = (fTemp32 + (-3.0f - fTemp36));
			float fTemp42 = (0.0f - (0.333333343f * fTemp41));
			float fTemp43 = (fTemp32 + (-4.0f - fTemp36));
			float fTemp44 = (0.0f - (0.25f * fTemp43));
			float fTemp45 = (fTemp32 - fTemp36);
			int iTemp46 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp34 + 1))))) + 1);
			float fTemp47 = (0.0f - fTemp39);
			float fTemp48 = (0.0f - (0.5f * fTemp41));
			float fTemp49 = (0.0f - (0.333333343f * fTemp43));
			int iTemp50 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp34 + 2))))) + 1);
			float fTemp51 = (0.0f - fTemp41);
			float fTemp52 = (0.0f - (0.5f * fTemp43));
			float fTemp53 = (fTemp37 * fTemp39);
			int iTemp54 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp34 + 3))))) + 1);
			float fTemp55 = (0.0f - fTemp43);
			float fTemp56 = (fTemp53 * fTemp41);
			int iTemp57 = (int(std::min<float>(fConst7, float(std::max<int>(0, (iTemp34 + 4))))) + 1);
			fVec4[0] = (((((fVec3[((IOTA - iTemp35) & 2047)] * fTemp38) * fTemp40) * fTemp42) * fTemp44) + (fTemp45 * ((((((fVec3[((IOTA - iTemp46) & 2047)] * fTemp47) * fTemp48) * fTemp49) + (0.5f * (((fTemp37 * fVec3[((IOTA - iTemp50) & 2047)]) * fTemp51) * fTemp52))) + (0.166666672f * ((fTemp53 * fVec3[((IOTA - iTemp54) & 2047)]) * fTemp55))) + (0.0416666679f * (fTemp56 * fVec3[((IOTA - iTemp57) & 2047)])))));
			float fTempFTZ19 = fVec4[1];
			fRec22[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec21;
			float fRec18 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec22[0];
			float fTemp58 = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fRec19 = fTemp58;
			float fRec20 = fTemp58;
			float fTempFTZ22 = fRec18;
			fRec13[(IOTA & 2047)] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (((((fTemp38 * fTemp40) * fTemp42) * fTemp44) * fRec13[((IOTA - iTemp35) & 2047)]) + (fTemp45 * ((((((fTemp47 * fTemp48) * fTemp49) * fRec13[((IOTA - iTemp46) & 2047)]) + (0.5f * (((fTemp37 * fTemp51) * fTemp52) * fRec13[((IOTA - iTemp50) & 2047)]))) + (0.166666672f * ((fTemp53 * fTemp55) * fRec13[((IOTA - iTemp54) & 2047)]))) + (0.0416666679f * (fTemp56 * fRec13[((IOTA - iTemp57) & 2047)])))));
			float fRec14 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec19;
			float fRec15 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec20;
			float fRec16 = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec14;
			fRec9[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec9[1];
			float fRec10 = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = fRec15;
			float fRec11 = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec16;
			float fRec12 = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = fRec10;
			fRec5[(IOTA & 2047)] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (((((fTemp10 * fTemp12) * fTemp14) * fTemp16) * fRec5[((IOTA - iTemp7) & 2047)]) + (fTemp17 * ((((((fTemp19 * fTemp20) * fTemp21) * fRec5[((IOTA - iTemp18) & 2047)]) + (0.5f * (((fTemp9 * fTemp23) * fTemp24) * fRec5[((IOTA - iTemp22) & 2047)]))) + (0.166666672f * ((fTemp25 * fTemp27) * fRec5[((IOTA - iTemp26) & 2047)]))) + (0.0416666679f * (fTemp28 * fRec5[((IOTA - iTemp29) & 2047)])))));
			float fRec6 = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec11;
			float fRec7 = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = fRec12;
			float fRec8 = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = fRec6;
			fRec3[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = fRec8;
			fRec4[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = ((fRec4[0] + (0.995000005f * fRec2[1])) - fRec4[1]);
			fRec2[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			output0[i0] = FAUSTFLOAT((0.280000001f * ((fRec0[0] * fRec1[0]) * (fRec2[0] + (0.200000003f * (fRec29[0] * fTemp0))))));
			fVec0[1] = fVec0[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			iRec17[1] = iRec17[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			iRec31[1] = iRec31[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec30[j0] = fRec30[(j0 - 1)];
			}
			fRec32[1] = fRec32[0];
			IOTA = (IOTA + 1);
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec40[1] = fRec40[0];
			fVec2[1] = fVec2[0];
			fVec4[1] = fVec4[0];
			fRec22[1] = fRec22[0];
			fRec9[1] = fRec9[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
