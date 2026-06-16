/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "voice"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustVoiceDSP_H__
#define  __FaustVoiceDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustVoiceDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec3[2];
	
  public:
	
	int getNumInputsFaustVoiceDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustVoiceDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustVoiceDSPSIG0(int sample_rate) {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec3[l2] = 0;
		}
	}
	
	void fillFaustVoiceDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec3[0] = ((iVec0[1] + iRec3[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec3[0])));
			iVec0[1] = iVec0[0];
			iRec3[1] = iRec3[0];
		}
	}

};

static FaustVoiceDSPSIG0* newFaustVoiceDSPSIG0() { return (FaustVoiceDSPSIG0*)new FaustVoiceDSPSIG0(); }
static void deleteFaustVoiceDSPSIG0(FaustVoiceDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustVoiceDSPSIG0[65536];
static float FaustVoiceDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustVoiceDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustVoiceDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fRec0[2];
	float fConst2;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec4[2];
	int iRec5[2];
	float fRec6[2];
	float fVec1[2];
	float fRec2[2];
	float fConst3;
	FAUSTFLOAT fHslider5;
	float fConst4;
	float fRec8[2];
	float fRec9[3];
	FAUSTFLOAT fHslider6;
	float fRec11[2];
	float fRec15[2];
	float fRec14[2];
	float fRec13[2];
	float fRec12[2];
	float fRec10[2];
	float fRec1[3];
	float fRec16[3];
	float fRec17[3];
	float fRec18[3];
	float fRec19[3];
	float fVec2[14];
	float fConst5;
	float fRec20[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "voice.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
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
		m->declare("name", "voice");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
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
		FaustVoiceDSPSIG0* sig0 = newFaustVoiceDSPSIG0();
		sig0->instanceInitFaustVoiceDSPSIG0(sample_rate);
		sig0->fillFaustVoiceDSPSIG0(65536, ftbl0FaustVoiceDSPSIG0);
		deleteFaustVoiceDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (3.14159274f / fConst0);
		fConst3 = (44.0999985f / fConst0);
		fConst4 = (1.0f - fConst3);
		fConst5 = (0.230000004f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(0.69999999999999996f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(220.0f);
		fHslider3 = FAUSTFLOAT(0.012f);
		fHslider4 = FAUSTFLOAT(5.5f);
		fHslider5 = FAUSTFLOAT(0.14999999999999999f);
		fHslider6 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec5[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec11[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec15[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec14[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec10[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec1[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec17[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec19[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 14); l21 = (l21 + 1)) {
			fVec2[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec20[l22] = 0.0f;
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
	
	virtual FaustVoiceDSP* clone() {
		return new FaustVoiceDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("voice");
		ui_interface->addHorizontalSlider("breathiness", &fHslider5, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(220.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider3, FAUSTFLOAT(0.0120000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0799999982f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider4, FAUSTFLOAT(5.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("vowel", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = ((0.119999997f * (1.0f - float(fHslider0))) + 0.0799999982f);
		int iSlow1 = (std::fabs(fSlow0) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst1 / (iSlow1 ? 1.0f : fSlow0))));
		float fSlow2 = (iSlow1 ? 0.0f : fThen1);
		float fSlow3 = ((float(fHslider1) * float(fButton0)) * (1.0f - fSlow2));
		float fSlow4 = float(fHslider2);
		float fSlow5 = (1.5f * fSlow4);
		float fSlow6 = float(fHslider3);
		float fSlow7 = (fConst1 * float(fHslider4));
		float fSlow8 = (fConst3 * float(fHslider5));
		float fSlow9 = (fConst2 * fSlow4);
		float fSlow10 = (fConst3 * float(fHslider6));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = ((fRec0[1] * fSlow2) + fSlow3);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow7 + (fRec4[1] - std::floor((fSlow7 + fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float fTemp0 = float(iRec5[0]);
			float fTemp1 = ((fRec0[0] * ((fSlow6 * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec4[0]))]) + (1.39698387e-12f * fTemp0))) + 1.0f);
			float fTemp2 = (fSlow4 * fTemp1);
			float fTemp3 = (1.0f / std::tan((fConst2 * std::max<float>((fSlow5 * fTemp1), (4500.0f - fTemp2)))));
			float fTemp4 = std::max<float>(1.1920929e-07f, std::fabs(fTemp2));
			float fTemp5 = (fRec6[1] + (fConst1 * fTemp4));
			float fTemp6 = (fTemp5 + -1.0f);
			int iTemp7 = (fTemp6 < 0.0f);
			float fTempFTZ2 = (iTemp7 ? fTemp5 : fTemp6);
			fRec6[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fThen3 = (fTemp5 + (fTemp6 * (1.0f - (fConst0 / fTemp4))));
			float fTempFTZ3 = (iTemp7 ? fTemp5 : fThen3);
			float fRec7 = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp8 = ((2.0f * fRec7) + -1.0f);
			fVec1[0] = fTemp8;
			float fTempFTZ4 = (0.0f - (((fRec2[1] * (1.0f - fTemp3)) - (fTemp8 + fVec1[1])) / (fTemp3 + 1.0f)));
			fRec2[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow8 + (fConst4 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp9 = std::tan((fSlow9 * fTemp1));
			float fTemp10 = (1.0f / fTemp9);
			float fTemp11 = (((fTemp10 + 0.833333313f) / fTemp9) + 1.0f);
			float fTempFTZ6 = ((4.65661287e-10f * fTemp0) - (((fRec9[2] * (((fTemp10 + -0.833333313f) / fTemp9) + 1.0f)) + (2.0f * (fRec9[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp9)))))) / fTemp11));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp12 = (fTemp9 * fTemp11);
			float fTemp13 = ((fRec2[0] * (1.0f - (0.5f * fRec8[0]))) + ((fRec0[0] * fRec8[0]) * ((fRec9[0] / fTemp12) + (fRec9[2] * (0.0f - (1.0f / fTemp12))))));
			float fTempFTZ7 = (fSlow10 + (fConst4 * fRec11[1]));
			fRec11[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			int iTemp14 = (fRec11[0] < 1.0f);
			int iTemp15 = (fRec11[0] < 2.0f);
			int iTemp16 = (fRec11[0] < 3.0f);
			float fTemp17 = (fRec11[0] + -3.0f);
			float fTemp18 = (200.0f * fTemp17);
			float fTemp19 = (fRec11[0] + -2.0f);
			float fTemp20 = (400.0f * fTemp19);
			float fThen4 = (4200.0f - fTemp18);
			float fElse4 = (4600.0f - fTemp20);
			float fTemp21 = (fRec11[0] + -1.0f);
			float fTemp22 = (100.0f * fTemp21);
			float fThen5 = (iTemp16 ? fElse4 : fThen4);
			float fElse5 = (fTemp22 + 4500.0f);
			float fThen6 = (iTemp15 ? fElse5 : fThen5);
			float fThen7 = (3300.0f - fTemp18);
			float fElse7 = (3700.0f - fTemp20);
			float fThen8 = (iTemp16 ? fElse7 : fThen7);
			float fElse8 = (fTemp22 + 3600.0f);
			float fTemp23 = (100.0f * fRec11[0]);
			float fThen9 = (iTemp15 ? fElse8 : fThen8);
			float fElse9 = (fTemp23 + 3500.0f);
			float fThen10 = (2500.0f - fTemp18);
			float fElse10 = (3000.0f - (500.0f * fTemp19));
			float fThen11 = (iTemp16 ? fElse10 : fThen10);
			float fElse11 = ((400.0f * fTemp21) + 2600.0f);
			float fThen12 = (iTemp15 ? fElse11 : fThen11);
			float fElse12 = (fTemp23 + 2500.0f);
			float fElse13 = (2300.0f - (1500.0f * fTemp19));
			float fThen14 = (iTemp16 ? fElse13 : 800.0f);
			float fElse14 = ((500.0f * fTemp21) + 1800.0f);
			float fThen15 = (iTemp15 ? fElse14 : fThen14);
			float fElse15 = ((600.0f * fRec11[0]) + 1200.0f);
			float fThen16 = (400.0f - (100.0f * fTemp17));
			float fElse16 = ((100.0f * fTemp19) + 300.0f);
			float fThen17 = (iTemp16 ? fElse16 : fThen16);
			float fElse17 = (400.0f - fTemp22);
			float fThen18 = (iTemp15 ? fElse17 : fThen17);
			float fElse18 = (800.0f - (400.0f * fRec11[0]));
			float fTempFTZ8 = ((fConst4 * fRec15[1]) + (fConst3 * std::max<float>((iTemp14 ? fElse18 : fThen18), fTemp2)));
			fRec15[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((fConst4 * fRec14[1]) + (fConst3 * std::max<float>((iTemp14 ? fElse15 : fThen15), (fRec15[0] + 200.0f))));
			fRec14[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = ((fConst4 * fRec13[1]) + (fConst3 * std::max<float>((iTemp14 ? fElse12 : fThen12), (fRec14[0] + 200.0f))));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = ((fConst4 * fRec12[1]) + (fConst3 * std::max<float>((iTemp14 ? fElse9 : fThen9), (fRec13[0] + 200.0f))));
			fRec12[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = ((fConst4 * fRec10[1]) + (fConst3 * std::max<float>((iTemp14 ? 4500.0f : fThen6), (fRec12[0] + 200.0f))));
			fRec10[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp24 = std::tan((fConst2 * fRec10[0]));
			float fTemp25 = (1.0f / fTemp24);
			float fTemp26 = (160.0f / fRec10[0]);
			float fTemp27 = (((fTemp25 + fTemp26) / fTemp24) + 1.0f);
			float fTempFTZ13 = (fTemp13 - (((fRec1[2] * (((fTemp25 - fTemp26) / fTemp24) + 1.0f)) + (2.0f * (fRec1[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp24)))))) / fTemp27));
			fRec1[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fElse19 = (0.25f - (0.150000006f * fTemp19));
			float fThen20 = (iTemp16 ? fElse19 : 0.100000001f);
			float fElse20 = ((0.0500000007f * fTemp21) + 0.200000003f);
			float fThen21 = (iTemp15 ? fElse20 : fThen20);
			float fElse21 = ((0.0500000007f * fRec11[0]) + 0.150000006f);
			float fTemp28 = (iTemp14 ? fElse21 : fThen21);
			float fTemp29 = (fTemp24 * fTemp27);
			float fTemp30 = std::tan((fConst2 * fRec12[0]));
			float fTemp31 = (1.0f / fTemp30);
			float fTemp32 = (130.0f / fRec12[0]);
			float fTemp33 = (((fTemp31 + fTemp32) / fTemp30) + 1.0f);
			float fTempFTZ14 = (fTemp13 - (((fRec16[2] * (((fTemp31 - fTemp32) / fTemp30) + 1.0f)) + (2.0f * (fRec16[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp30)))))) / fTemp33));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fThen22 = (0.25f - (0.0500000007f * fTemp17));
			float fElse22 = (0.5f - (0.25f * fTemp19));
			float fThen23 = (iTemp16 ? fElse22 : fThen22);
			float fElse23 = ((0.100000001f * fTemp21) + 0.400000006f);
			float fThen24 = (iTemp15 ? fElse23 : fThen23);
			float fElse24 = ((0.100000001f * fRec11[0]) + 0.300000012f);
			float fTemp34 = (iTemp14 ? fElse24 : fThen24);
			float fTemp35 = (fTemp30 * fTemp33);
			float fTemp36 = std::tan((fConst2 * fRec13[0]));
			float fTemp37 = (1.0f / fTemp36);
			float fTemp38 = (120.0f / fRec13[0]);
			float fTemp39 = (((fTemp37 + fTemp38) / fTemp36) + 1.0f);
			float fTempFTZ15 = (fTemp13 - (((fRec17[2] * (((fTemp37 - fTemp38) / fTemp36) + 1.0f)) + (2.0f * (fRec17[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp36)))))) / fTemp39));
			fRec17[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp40 = (0.0500000007f * fTemp17);
			float fThen25 = (0.400000006f - fTemp40);
			float fElse25 = (0.800000012f - (0.400000006f * fTemp19));
			float fTemp41 = (0.100000001f * fTemp21);
			float fThen26 = (iTemp16 ? fElse25 : fThen25);
			float fElse26 = (fTemp41 + 0.699999988f);
			float fThen27 = (iTemp15 ? fElse26 : fThen26);
			float fElse27 = ((0.150000006f * fRec11[0]) + 0.550000012f);
			float fTemp42 = (iTemp14 ? fElse27 : fThen27);
			float fTemp43 = (fTemp36 * fTemp39);
			float fTemp44 = std::tan((fConst2 * fRec14[0]));
			float fTemp45 = (1.0f / fTemp44);
			float fTemp46 = (90.0f / fRec14[0]);
			float fTemp47 = (((fTemp45 + fTemp46) / fTemp44) + 1.0f);
			float fTempFTZ16 = (fTemp13 - (((fRec18[2] * (((fTemp45 - fTemp46) / fTemp44) + 1.0f)) + (2.0f * (fRec18[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp44)))))) / fTemp47));
			fRec18[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fThen28 = (0.600000024f - (0.0500000007f * fTemp17));
			float fElse28 = (0.949999988f - (0.349999994f * fTemp19));
			float fThen29 = (iTemp16 ? fElse28 : fThen28);
			float fElse29 = (1.0f - (0.0500000007f * fTemp21));
			float fThen30 = (iTemp15 ? fElse29 : fThen29);
			float fElse30 = ((0.150000006f * fRec11[0]) + 0.850000024f);
			float fTemp48 = (iTemp14 ? fElse30 : fThen30);
			float fTemp49 = (fTemp44 * fTemp47);
			float fTemp50 = std::tan((fConst2 * fRec15[0]));
			float fTemp51 = (1.0f / fTemp50);
			float fTemp52 = (80.0f / fRec15[0]);
			float fTemp53 = (((fTemp51 + fTemp52) / fTemp50) + 1.0f);
			float fTempFTZ17 = (fTemp13 - (((fRec19[2] * (((fTemp51 - fTemp52) / fTemp50) + 1.0f)) + (2.0f * (fRec19[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp50)))))) / fTemp53));
			fRec19[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fThen31 = (0.899999976f - fTemp40);
			float fElse31 = ((0.200000003f * fTemp19) + 0.699999988f);
			float fThen32 = (iTemp16 ? fElse31 : fThen31);
			float fElse32 = (0.800000012f - fTemp41);
			float fThen33 = (iTemp15 ? fElse32 : fThen32);
			float fElse33 = (1.0f - (0.200000003f * fRec11[0]));
			float fTemp54 = (iTemp14 ? fElse33 : fThen33);
			float fTemp55 = (fTemp50 * fTemp53);
			float fTemp56 = (fRec0[0] * ((fRec1[2] * (0.0f - (fTemp28 / fTemp29))) + (((fRec16[2] * (0.0f - (fTemp34 / fTemp35))) + (((fRec17[2] * (0.0f - (fTemp42 / fTemp43))) + (((fRec18[2] * (0.0f - (fTemp48 / fTemp49))) + ((((fRec19[0] * fTemp54) / fTemp55) + (fRec19[2] * (0.0f - (fTemp54 / fTemp55)))) + ((fRec18[0] * fTemp48) / fTemp49))) + ((fRec17[0] * fTemp42) / fTemp43))) + ((fRec16[0] * fTemp34) / fTemp35))) + ((fRec1[0] * fTemp28) / fTemp29))));
			fVec2[0] = fTemp56;
			float fTemp57 = (0.400000006f * fTemp56);
			float fTempFTZ18 = (fConst5 + (fRec20[1] - std::floor((fConst5 + fRec20[1]))));
			fRec20[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp58 = (3.0f * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec20[0]))]);
			float fTemp59 = (fTemp58 + 8.5f);
			int iTemp60 = int(fTemp59);
			float fTemp61 = std::floor(fTemp59);
			float fTemp62 = ((fVec2[std::min<int>(4097, std::max<int>(0, iTemp60))] * (fTemp61 + (-7.5f - fTemp58))) + ((fTemp58 + (8.5f - fTemp61)) * fVec2[std::min<int>(4097, std::max<int>(0, (iTemp60 + 1)))]));
			output0[i0] = FAUSTFLOAT((fTemp57 + (0.140000001f * fTemp62)));
			output1[i0] = FAUSTFLOAT((fTemp57 - (0.0700000003f * fTemp62)));
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			iRec5[1] = iRec5[0];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			fRec2[1] = fRec2[0];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			for (int j0 = 13; (j0 > 0); j0 = (j0 - 1)) {
				fVec2[j0] = fVec2[(j0 - 1)];
			}
			fRec20[1] = fRec20[0];
		}
	}

};

#endif
