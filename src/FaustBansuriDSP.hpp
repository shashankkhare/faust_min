/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "bansuri"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBansuriDSP_H__
#define  __FaustBansuriDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustBansuriDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec33[2];
	
  public:
	
	int getNumInputsFaustBansuriDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustBansuriDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustBansuriDSPSIG0(int sample_rate) {
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iVec1[l14] = 0;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			iRec33[l15] = 0;
		}
	}
	
	void fillFaustBansuriDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec33[0] = ((iVec1[1] + iRec33[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec33[0])));
			iVec1[1] = iVec1[0];
			iRec33[1] = iRec33[0];
		}
	}

};

static FaustBansuriDSPSIG0* newFaustBansuriDSPSIG0() { return (FaustBansuriDSPSIG0*)new FaustBansuriDSPSIG0(); }
static void deleteFaustBansuriDSPSIG0(FaustBansuriDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustBansuriDSPSIG0[65536];
static float FaustBansuriDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBansuriDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBansuriDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	int iRec16[2];
	float fRec23[2];
	float fRec22[2];
	FAUSTFLOAT fHslider1;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	FAUSTFLOAT fHslider2;
	float fRec25[2];
	float fRec24[2];
	FAUSTFLOAT fHslider3;
	float fRec26[2];
	float fConst4;
	float fRec27[2];
	int iRec28[2];
	float fRec29[2];
	int IOTA;
	float fRec30[2048];
	float fConst5;
	float fConst6;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec31[2];
	FAUSTFLOAT fHslider6;
	float fRec32[2];
	float fConst7;
	float fRec34[2];
	FAUSTFLOAT fHslider7;
	float fRec35[2];
	float fVec2[2];
	float fVec3[2048];
	float fVec4[2];
	float fRec21[2];
	float fRec12[2048];
	float fRec8[2];
	float fRec4[2048];
	float fRec2[2];
	float fRec3[2];
	float fRec1[2];
	float fRec36[4];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "bansuri.dsp");
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
		m->declare("name", "bansuri");
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
		FaustBansuriDSPSIG0* sig0 = newFaustBansuriDSPSIG0();
		sig0->instanceInitFaustBansuriDSPSIG0(sample_rate);
		sig0->fillFaustBansuriDSPSIG0(65536, ftbl0FaustBansuriDSPSIG0);
		deleteFaustBansuriDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (1.0f / fConst0);
		fConst4 = std::exp((0.0f - (12.5f / fConst0)));
		fConst5 = (0.00882352982f * fConst0);
		fConst6 = (0.00147058826f * fConst0);
		fConst7 = (5.5f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(0.20000000000000001f);
		fHslider4 = FAUSTFLOAT(0.080000000000000002f);
		fHslider5 = FAUSTFLOAT(440.0f);
		fHslider6 = FAUSTFLOAT(0.29999999999999999f);
		fHslider7 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec16[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec23[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec22[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec25[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec24[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec26[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec27[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec28[l9] = 0;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec29[l10] = 0.0f;
		}
		IOTA = 0;
		for (int l11 = 0; (l11 < 2048); l11 = (l11 + 1)) {
			fRec30[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec31[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec32[l13] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec34[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec35[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec2[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2048); l19 = (l19 + 1)) {
			fVec3[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fVec4[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2048); l22 = (l22 + 1)) {
			fRec12[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec8[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2048); l24 = (l24 + 1)) {
			fRec4[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec2[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec3[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec1[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 4); l28 = (l28 + 1)) {
			fRec36[l28] = 0.0f;
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
	
	virtual FaustBansuriDSP* clone() {
		return new FaustBansuriDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bansuri");
		ui_interface->addHorizontalSlider("breathiness", &fHslider3, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider5, FAUSTFLOAT(440.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("glide", &fHslider4, FAUSTFLOAT(0.0799999982f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato", &fHslider6, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = ((0.100000001f * (1.0f - float(fHslider1))) + 0.00499999989f);
		int iSlow2 = (std::fabs(fSlow1) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst3 / (iSlow2 ? 1.0f : fSlow1))));
		float fSlow3 = (iSlow2 ? 0.0f : fThen1);
		float fSlow4 = float(fButton0);
		float fSlow5 = (fConst1 * float(fHslider2));
		float fSlow6 = (1.0f - fSlow3);
		float fSlow7 = (fConst1 * float(fHslider3));
		float fSlow8 = float(fHslider4);
		int iSlow9 = (std::fabs(fSlow8) < 1.1920929e-07f);
		float fThen3 = std::exp((0.0f - (fConst3 / (iSlow9 ? 1.0f : fSlow8))));
		float fSlow10 = (iSlow9 ? 0.0f : fThen3);
		float fSlow11 = (float(fHslider5) * (1.0f - fSlow10));
		float fSlow12 = (fConst1 * float(fHslider6));
		float fSlow13 = (fConst1 * float(fHslider7));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec16[0] = 0;
			float fTempFTZ1 = ((0.300000012f * fRec23[1]) + (0.67900002f * fRec21[1]));
			fRec23[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((0.400000006f * fRec22[1]) + (0.600000024f * fRec23[0]));
			fRec22[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fRec22[0] + float(iRec16[1]));
			float fRec20 = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			fVec0[0] = fSlow4;
			float fTempFTZ4 = (fSlow5 + (fConst2 * fRec25[1]));
			fRec25[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((fRec24[1] * fSlow3) + (std::min<float>(1.0f, (fSlow4 * fRec25[0])) * fSlow6));
			fRec24[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fSlow7 + (fConst2 * fRec26[1]));
			fRec26[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((fConst4 * fRec27[1]) + (0.5f * float(((fSlow4 - fVec0[1]) > 0.0f))));
			fRec27[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			iRec28[0] = ((1103515245 * iRec28[1]) + 12345);
			float fTemp0 = float(iRec28[0]);
			float fTempFTZ8 = fRec2[1];
			fRec29[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (0.980000019f * fRec29[1]);
			fRec30[(IOTA & 2047)] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = ((fRec31[1] * fSlow10) + fSlow11);
			fRec31[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fSlow12 + (fConst2 * fRec32[1]));
			fRec32[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fConst7 + (fRec34[1] - std::floor((fConst7 + fRec34[1]))));
			fRec34[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp1 = ((340.0f / (fRec31[0] * ((0.0199999996f * (fRec32[0] * ftbl0FaustBansuriDSPSIG0[int((65536.0f * fRec34[0]))])) + 1.0f))) + 0.270000011f);
			float fTempFTZ13 = (fSlow13 + (fConst2 * fRec35[1]));
			fRec35[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp2 = (0.400000006f * (fRec35[0] + -0.5f));
			float fTemp3 = (fConst6 * (fTemp1 * (fTemp2 + 0.270000011f)));
			float fTemp4 = (fTemp3 + -1.49999499f);
			int iTemp5 = int(fTemp4);
			int iTemp6 = (int(std::min<float>(fConst5, float(std::max<int>(0, iTemp5)))) + 1);
			float fTemp7 = std::floor(fTemp4);
			float fTemp8 = (fTemp3 + (-1.0f - fTemp7));
			float fTemp9 = (0.0f - fTemp8);
			float fTemp10 = (fTemp3 + (-2.0f - fTemp7));
			float fTemp11 = (0.0f - (0.5f * fTemp10));
			float fTemp12 = (fTemp3 + (-3.0f - fTemp7));
			float fTemp13 = (0.0f - (0.333333343f * fTemp12));
			float fTemp14 = (fTemp3 + (-4.0f - fTemp7));
			float fTemp15 = (0.0f - (0.25f * fTemp14));
			float fTemp16 = (fTemp3 - fTemp7);
			int iTemp17 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp5 + 1))))) + 1);
			float fTemp18 = (0.0f - fTemp10);
			float fTemp19 = (0.0f - (0.5f * fTemp12));
			float fTemp20 = (0.0f - (0.333333343f * fTemp14));
			int iTemp21 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp5 + 2))))) + 1);
			float fTemp22 = (0.0f - fTemp12);
			float fTemp23 = (0.0f - (0.5f * fTemp14));
			float fTemp24 = (fTemp8 * fTemp10);
			int iTemp25 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp5 + 3))))) + 1);
			float fTemp26 = (0.0f - fTemp14);
			float fTemp27 = (fTemp24 * fTemp12);
			int iTemp28 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp5 + 4))))) + 1);
			fVec2[0] = (((((fRec30[((IOTA - iTemp6) & 2047)] * fTemp9) * fTemp11) * fTemp13) * fTemp15) + (fTemp16 * ((((((fRec30[((IOTA - iTemp17) & 2047)] * fTemp18) * fTemp19) * fTemp20) + (0.5f * (((fTemp8 * fRec30[((IOTA - iTemp21) & 2047)]) * fTemp22) * fTemp23))) + (0.166666672f * ((fTemp24 * fRec30[((IOTA - iTemp25) & 2047)]) * fTemp26))) + (0.0416666679f * (fTemp27 * fRec30[((IOTA - iTemp28) & 2047)])))));
			float fTemp29 = ((fRec24[0] * ((4.65661287e-10f * ((fRec26[0] + fRec27[0]) * fTemp0)) + 1.0f)) - (0.5f * fVec2[1]));
			float fTemp30 = ((0.5f * fRec8[1]) + std::max<float>(-1.0f, std::min<float>(1.0f, (fTemp29 * (FaustBansuriDSP_faustpower2_f(fTemp29) + -1.0f)))));
			fVec3[(IOTA & 2047)] = fTemp30;
			float fTemp31 = (fConst6 * (fTemp1 * (0.730000019f - fTemp2)));
			float fTemp32 = (fTemp31 + -1.49999499f);
			int iTemp33 = int(fTemp32);
			int iTemp34 = (int(std::min<float>(fConst5, float(std::max<int>(0, iTemp33)))) + 1);
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
			int iTemp45 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp33 + 1))))) + 1);
			float fTemp46 = (0.0f - fTemp38);
			float fTemp47 = (0.0f - (0.5f * fTemp40));
			float fTemp48 = (0.0f - (0.333333343f * fTemp42));
			int iTemp49 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp33 + 2))))) + 1);
			float fTemp50 = (0.0f - fTemp40);
			float fTemp51 = (0.0f - (0.5f * fTemp42));
			float fTemp52 = (fTemp36 * fTemp38);
			int iTemp53 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp33 + 3))))) + 1);
			float fTemp54 = (0.0f - fTemp42);
			float fTemp55 = (fTemp52 * fTemp40);
			int iTemp56 = (int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp33 + 4))))) + 1);
			fVec4[0] = (((((fVec3[((IOTA - iTemp34) & 2047)] * fTemp37) * fTemp39) * fTemp41) * fTemp43) + (fTemp44 * ((((((fVec3[((IOTA - iTemp45) & 2047)] * fTemp46) * fTemp47) * fTemp48) + (0.5f * (((fTemp36 * fVec3[((IOTA - iTemp49) & 2047)]) * fTemp50) * fTemp51))) + (0.166666672f * ((fTemp52 * fVec3[((IOTA - iTemp53) & 2047)]) * fTemp54))) + (0.0416666679f * (fTemp55 * fVec3[((IOTA - iTemp56) & 2047)])))));
			float fTempFTZ14 = fVec4[1];
			fRec21[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = fRec20;
			float fRec17 = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = fRec21[0];
			float fTemp57 = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fRec18 = fTemp57;
			float fRec19 = fTemp57;
			float fTempFTZ17 = fRec17;
			fRec12[(IOTA & 2047)] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (((((fTemp37 * fTemp39) * fTemp41) * fTemp43) * fRec12[((IOTA - iTemp34) & 2047)]) + (fTemp44 * ((((((fTemp46 * fTemp47) * fTemp48) * fRec12[((IOTA - iTemp45) & 2047)]) + (0.5f * (((fTemp36 * fTemp50) * fTemp51) * fRec12[((IOTA - iTemp49) & 2047)]))) + (0.166666672f * ((fTemp52 * fTemp54) * fRec12[((IOTA - iTemp53) & 2047)]))) + (0.0416666679f * (fTemp55 * fRec12[((IOTA - iTemp56) & 2047)])))));
			float fRec13 = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = fRec18;
			float fRec14 = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec19;
			float fRec15 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec13;
			fRec8[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = fRec8[1];
			float fRec9 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec14;
			float fRec10 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec15;
			float fRec11 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec9;
			fRec4[(IOTA & 2047)] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (((((fTemp9 * fTemp11) * fTemp13) * fTemp15) * fRec4[((IOTA - iTemp6) & 2047)]) + (fTemp16 * ((((((fTemp18 * fTemp19) * fTemp20) * fRec4[((IOTA - iTemp17) & 2047)]) + (0.5f * (((fTemp8 * fTemp22) * fTemp23) * fRec4[((IOTA - iTemp21) & 2047)]))) + (0.166666672f * ((fTemp24 * fTemp26) * fRec4[((IOTA - iTemp25) & 2047)]))) + (0.0416666679f * (fTemp27 * fRec4[((IOTA - iTemp28) & 2047)])))));
			float fRec5 = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec10;
			float fRec6 = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = fRec11;
			float fRec7 = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec5;
			fRec2[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = fRec7;
			fRec3[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = ((fRec3[0] + (0.995000005f * fRec1[1])) - fRec3[1]);
			fRec1[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (((0.522189379f * fRec36[3]) + ((4.65661287e-10f * fTemp0) + (2.49495602f * fRec36[1]))) - (2.0172658f * fRec36[2]));
			fRec36[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] * (fRec1[0] + (0.200000003f * (fRec27[0] * (((0.0499220341f * fRec36[0]) + (0.0506126992f * fRec36[2])) - ((0.0959935337f * fRec36[1]) + (0.00440878607f * fRec36[3]))))))));
			fRec0[1] = fRec0[0];
			iRec16[1] = iRec16[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fVec0[1] = fVec0[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			iRec28[1] = iRec28[0];
			fRec29[1] = fRec29[0];
			IOTA = (IOTA + 1);
			fRec31[1] = fRec31[0];
			fRec32[1] = fRec32[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fVec2[1] = fVec2[0];
			fVec4[1] = fVec4[0];
			fRec21[1] = fRec21[0];
			fRec8[1] = fRec8[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec36[j0] = fRec36[(j0 - 1)];
			}
		}
	}

};

#endif
