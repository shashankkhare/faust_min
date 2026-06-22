/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "panflute"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustPanfluteDSP_H__
#define  __FaustPanfluteDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustPanfluteDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec31[2];
	
  public:
	
	int getNumInputsFaustPanfluteDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustPanfluteDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustPanfluteDSPSIG0(int sample_rate) {
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iVec0[l11] = 0;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec31[l12] = 0;
		}
	}
	
	void fillFaustPanfluteDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec31[0] = ((iVec0[1] + iRec31[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec31[0])));
			iVec0[1] = iVec0[0];
			iRec31[1] = iRec31[0];
		}
	}

};

static FaustPanfluteDSPSIG0* newFaustPanfluteDSPSIG0() { return (FaustPanfluteDSPSIG0*)new FaustPanfluteDSPSIG0(); }
static void deleteFaustPanfluteDSPSIG0(FaustPanfluteDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustPanfluteDSPSIG0[65536];
static float FaustPanfluteDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustPanfluteDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustPanfluteDSP : public dsp {
	
 private:
	
	int iRec15[2];
	float fRec21[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fButton0;
	float fConst2;
	FAUSTFLOAT fHslider1;
	float fConst3;
	float fRec23[2];
	float fRec22[2];
	FAUSTFLOAT fHslider2;
	float fRec24[2];
	int iRec26[2];
	float fRec25[4];
	float fRec27[2];
	int IOTA;
	float fRec28[2048];
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec29[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec30[2];
	FAUSTFLOAT fHslider7;
	float fRec32[2];
	FAUSTFLOAT fHslider8;
	float fRec33[2];
	float fVec1[2];
	float fVec2[2048];
	float fVec3[2];
	float fRec20[2];
	float fRec11[2048];
	float fRec7[2];
	float fRec3[2048];
	float fRec1[2];
	float fRec2[2];
	float fRec0[2];
	float fConst6;
	float fConst7;
	float fRec34[2];
	FAUSTFLOAT fHslider9;
	float fRec35[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "panflute.dsp");
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
		m->declare("name", "panflute");
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
		FaustPanfluteDSPSIG0* sig0 = newFaustPanfluteDSPSIG0();
		sig0->instanceInitFaustPanfluteDSPSIG0(sample_rate);
		sig0->fillFaustPanfluteDSPSIG0(65536, ftbl0FaustPanfluteDSPSIG0);
		deleteFaustPanfluteDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = (0.00882352982f * fConst0);
		fConst5 = (0.00147058826f * fConst0);
		fConst6 = std::exp((0.0f - (25.0f / fConst0)));
		fConst7 = (1.0f - fConst6);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.65000000000000002f);
		fHslider2 = FAUSTFLOAT(0.29999999999999999f);
		fHslider3 = FAUSTFLOAT(0.059999999999999998f);
		fHslider4 = FAUSTFLOAT(440.0f);
		fHslider5 = FAUSTFLOAT(0.029999999999999999f);
		fHslider6 = FAUSTFLOAT(0.5f);
		fHslider7 = FAUSTFLOAT(5.5f);
		fHslider8 = FAUSTFLOAT(0.5f);
		fHslider9 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec15[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec21[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec23[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec22[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec24[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec26[l5] = 0;
		}
		for (int l6 = 0; (l6 < 4); l6 = (l6 + 1)) {
			fRec25[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec27[l7] = 0.0f;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 2048); l8 = (l8 + 1)) {
			fRec28[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec29[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec30[l10] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec32[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec33[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec1[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2048); l16 = (l16 + 1)) {
			fVec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fVec3[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec20[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2048); l19 = (l19 + 1)) {
			fRec11[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec7[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2048); l21 = (l21 + 1)) {
			fRec3[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec1[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec2[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec0[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec34[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec35[l26] = 0.0f;
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
	
	virtual FaustPanfluteDSP* clone() {
		return new FaustPanfluteDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("panflute");
		ui_interface->addHorizontalSlider("breathiness", &fHslider2, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(440.0f), FAUSTFLOAT(261.0f), FAUSTFLOAT(2093.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider9, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("glide", &fHslider3, FAUSTFLOAT(0.0599999987f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider1, FAUSTFLOAT(0.649999976f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider5, FAUSTFLOAT(0.0299999993f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider7, FAUSTFLOAT(5.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = ((0.0149999997f * (1.0f - float(fHslider0))) + 0.00300000003f);
		int iSlow1 = (std::fabs(fSlow0) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst1 / (iSlow1 ? 1.0f : fSlow0))));
		float fSlow2 = (iSlow1 ? 0.0f : fThen1);
		float fSlow3 = float(fButton0);
		float fSlow4 = (fConst2 * float(fHslider1));
		float fSlow5 = (1.0f - fSlow2);
		float fSlow6 = (fConst2 * float(fHslider2));
		float fSlow7 = float(fHslider3);
		int iSlow8 = (std::fabs(fSlow7) < 1.1920929e-07f);
		float fThen3 = std::exp((0.0f - (fConst1 / (iSlow8 ? 1.0f : fSlow7))));
		float fSlow9 = (iSlow8 ? 0.0f : fThen3);
		float fSlow10 = (float(fHslider4) * (1.0f - fSlow9));
		float fSlow11 = float(fHslider5);
		float fSlow12 = (fConst2 * float(fHslider6));
		float fSlow13 = (fConst1 * float(fHslider7));
		float fSlow14 = (fConst2 * float(fHslider8));
		float fSlow15 = (fConst7 * fSlow3);
		float fSlow16 = (fConst2 * float(fHslider9));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec15[0] = 0;
			float fTempFTZ0 = ((0.699999988f * fRec21[1]) + (0.284999996f * fRec20[1]));
			fRec21[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fRec21[0] + float(iRec15[1]));
			float fRec19 = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow4 + (fConst3 * fRec23[1]));
			fRec23[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((fRec22[1] * fSlow2) + (std::min<float>(1.0f, (fSlow3 * fRec23[0])) * fSlow5));
			fRec22[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow6 + (fConst3 * fRec24[1]));
			fRec24[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			iRec26[0] = ((1103515245 * iRec26[1]) + 12345);
			float fTempFTZ5 = (((0.522189379f * fRec25[3]) + ((4.65661287e-10f * float(iRec26[0])) + (2.49495602f * fRec25[1]))) - (2.0172658f * fRec25[2]));
			fRec25[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = fRec1[1];
			fRec27[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.949999988f * fRec27[1]);
			fRec28[(IOTA & 2047)] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = ((fRec29[1] * fSlow9) + fSlow10);
			fRec29[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fSlow12 + (fConst3 * fRec30[1]));
			fRec30[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fSlow13 + (fRec32[1] - std::floor((fSlow13 + fRec32[1]))));
			fRec32[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp0 = ((340.0f / (fRec29[0] * ((fSlow11 * (fRec30[0] * ftbl0FaustPanfluteDSPSIG0[int((65536.0f * fRec32[0]))])) + 1.0f))) + 0.270000011f);
			float fTempFTZ11 = (fSlow14 + (fConst3 * fRec33[1]));
			fRec33[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp1 = (0.400000006f * (fRec33[0] + -0.5f));
			float fTemp2 = (fConst5 * (fTemp0 * (fTemp1 + 0.270000011f)));
			float fTemp3 = (fTemp2 + -1.49999499f);
			int iTemp4 = int(fTemp3);
			int iTemp5 = (int(std::min<float>(fConst4, float(std::max<int>(0, iTemp4)))) + 1);
			float fTemp6 = std::floor(fTemp3);
			float fTemp7 = (fTemp2 + (-1.0f - fTemp6));
			float fTemp8 = (0.0f - fTemp7);
			float fTemp9 = (fTemp2 + (-2.0f - fTemp6));
			float fTemp10 = (0.0f - (0.5f * fTemp9));
			float fTemp11 = (fTemp2 + (-3.0f - fTemp6));
			float fTemp12 = (0.0f - (0.333333343f * fTemp11));
			float fTemp13 = (fTemp2 + (-4.0f - fTemp6));
			float fTemp14 = (0.0f - (0.25f * fTemp13));
			float fTemp15 = (fTemp2 - fTemp6);
			int iTemp16 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp4 + 1))))) + 1);
			float fTemp17 = (0.0f - fTemp9);
			float fTemp18 = (0.0f - (0.5f * fTemp11));
			float fTemp19 = (0.0f - (0.333333343f * fTemp13));
			int iTemp20 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp4 + 2))))) + 1);
			float fTemp21 = (0.0f - fTemp11);
			float fTemp22 = (0.0f - (0.5f * fTemp13));
			float fTemp23 = (fTemp7 * fTemp9);
			int iTemp24 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp4 + 3))))) + 1);
			float fTemp25 = (0.0f - fTemp13);
			float fTemp26 = (fTemp23 * fTemp11);
			int iTemp27 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp4 + 4))))) + 1);
			fVec1[0] = (((((fRec28[((IOTA - iTemp5) & 2047)] * fTemp8) * fTemp10) * fTemp12) * fTemp14) + (fTemp15 * ((((((fRec28[((IOTA - iTemp16) & 2047)] * fTemp17) * fTemp18) * fTemp19) + (0.5f * (((fTemp7 * fRec28[((IOTA - iTemp20) & 2047)]) * fTemp21) * fTemp22))) + (0.166666672f * ((fTemp23 * fRec28[((IOTA - iTemp24) & 2047)]) * fTemp25))) + (0.0416666679f * (fTemp26 * fRec28[((IOTA - iTemp27) & 2047)])))));
			float fTemp28 = ((fRec22[0] * ((0.300000012f * (fRec24[0] * (((0.0499220341f * fRec25[0]) + (0.0506126992f * fRec25[2])) - ((0.0959935337f * fRec25[1]) + (0.00440878607f * fRec25[3]))))) + 1.0f)) - (0.5f * fVec1[1]));
			float fTemp29 = ((0.5f * fRec7[1]) + std::max<float>(-1.0f, std::min<float>(1.0f, (fTemp28 * (FaustPanfluteDSP_faustpower2_f(fTemp28) + -1.0f)))));
			fVec2[(IOTA & 2047)] = fTemp29;
			float fTemp30 = (fConst5 * (fTemp0 * (0.730000019f - fTemp1)));
			float fTemp31 = (fTemp30 + -1.49999499f);
			int iTemp32 = int(fTemp31);
			int iTemp33 = (int(std::min<float>(fConst4, float(std::max<int>(0, iTemp32)))) + 1);
			float fTemp34 = std::floor(fTemp31);
			float fTemp35 = (fTemp30 + (-1.0f - fTemp34));
			float fTemp36 = (0.0f - fTemp35);
			float fTemp37 = (fTemp30 + (-2.0f - fTemp34));
			float fTemp38 = (0.0f - (0.5f * fTemp37));
			float fTemp39 = (fTemp30 + (-3.0f - fTemp34));
			float fTemp40 = (0.0f - (0.333333343f * fTemp39));
			float fTemp41 = (fTemp30 + (-4.0f - fTemp34));
			float fTemp42 = (0.0f - (0.25f * fTemp41));
			float fTemp43 = (fTemp30 - fTemp34);
			int iTemp44 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp32 + 1))))) + 1);
			float fTemp45 = (0.0f - fTemp37);
			float fTemp46 = (0.0f - (0.5f * fTemp39));
			float fTemp47 = (0.0f - (0.333333343f * fTemp41));
			int iTemp48 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp32 + 2))))) + 1);
			float fTemp49 = (0.0f - fTemp39);
			float fTemp50 = (0.0f - (0.5f * fTemp41));
			float fTemp51 = (fTemp35 * fTemp37);
			int iTemp52 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp32 + 3))))) + 1);
			float fTemp53 = (0.0f - fTemp41);
			float fTemp54 = (fTemp51 * fTemp39);
			int iTemp55 = (int(std::min<float>(fConst4, float(std::max<int>(0, (iTemp32 + 4))))) + 1);
			fVec3[0] = (((((fVec2[((IOTA - iTemp33) & 2047)] * fTemp36) * fTemp38) * fTemp40) * fTemp42) + (fTemp43 * ((((((fVec2[((IOTA - iTemp44) & 2047)] * fTemp45) * fTemp46) * fTemp47) + (0.5f * (((fTemp35 * fVec2[((IOTA - iTemp48) & 2047)]) * fTemp49) * fTemp50))) + (0.166666672f * ((fTemp51 * fVec2[((IOTA - iTemp52) & 2047)]) * fTemp53))) + (0.0416666679f * (fTemp54 * fVec2[((IOTA - iTemp55) & 2047)])))));
			float fTempFTZ12 = fVec3[1];
			fRec20[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = fRec19;
			float fRec16 = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = fRec20[0];
			float fTemp56 = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fRec17 = fTemp56;
			float fRec18 = fTemp56;
			float fTempFTZ15 = fRec16;
			fRec11[(IOTA & 2047)] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (((((fTemp36 * fTemp38) * fTemp40) * fTemp42) * fRec11[((IOTA - iTemp33) & 2047)]) + (fTemp43 * ((((((fTemp45 * fTemp46) * fTemp47) * fRec11[((IOTA - iTemp44) & 2047)]) + (0.5f * (((fTemp35 * fTemp49) * fTemp50) * fRec11[((IOTA - iTemp48) & 2047)]))) + (0.166666672f * ((fTemp51 * fTemp53) * fRec11[((IOTA - iTemp52) & 2047)]))) + (0.0416666679f * (fTemp54 * fRec11[((IOTA - iTemp55) & 2047)])))));
			float fRec12 = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec17;
			float fRec13 = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec18;
			float fRec14 = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = fRec12;
			fRec7[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec7[1];
			float fRec8 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec13;
			float fRec9 = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = fRec14;
			float fRec10 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec8;
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (((((fTemp8 * fTemp10) * fTemp12) * fTemp14) * fRec3[((IOTA - iTemp5) & 2047)]) + (fTemp15 * ((((((fTemp17 * fTemp18) * fTemp19) * fRec3[((IOTA - iTemp16) & 2047)]) + (0.5f * (((fTemp7 * fTemp21) * fTemp22) * fRec3[((IOTA - iTemp20) & 2047)]))) + (0.166666672f * ((fTemp23 * fTemp25) * fRec3[((IOTA - iTemp24) & 2047)]))) + (0.0416666679f * (fTemp26 * fRec3[((IOTA - iTemp27) & 2047)])))));
			float fRec4 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec9;
			float fRec5 = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec10;
			float fRec6 = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec4;
			fRec1[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = fRec6;
			fRec2[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = ((fRec2[0] + (0.995000005f * fRec0[1])) - fRec2[1]);
			fRec0[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (fSlow15 + (fConst6 * fRec34[1]));
			fRec34[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fSlow16 + (fConst3 * fRec35[1]));
			fRec35[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			output0[i0] = FAUSTFLOAT((2.0f * ((fRec0[0] * fRec34[0]) * fRec35[0])));
			iRec15[1] = iRec15[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			iRec26[1] = iRec26[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec25[j0] = fRec25[(j0 - 1)];
			}
			fRec27[1] = fRec27[0];
			IOTA = (IOTA + 1);
			fRec29[1] = fRec29[0];
			fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fVec1[1] = fVec1[0];
			fVec3[1] = fVec3[0];
			fRec20[1] = fRec20[0];
			fRec7[1] = fRec7[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
		}
	}

};

#endif
