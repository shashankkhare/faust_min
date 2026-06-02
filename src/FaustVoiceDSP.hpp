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
	int iRec4[2];
	
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
			iRec4[l2] = 0;
		}
	}
	
	void fillFaustVoiceDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec4[0] = ((iVec0[1] + iRec4[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec4[0])));
			iVec0[1] = iVec0[0];
			iRec4[1] = iRec4[0];
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
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec5[2];
	int iRec6[2];
	float fRec2[2];
	float fConst2;
	FAUSTFLOAT fHslider5;
	float fConst3;
	float fRec7[2];
	float fConst4;
	float fRec8[3];
	FAUSTFLOAT fHslider6;
	float fRec9[2];
	float fRec1[3];
	float fRec10[3];
	float fRec11[3];
	float fRec12[3];
	float fRec13[3];
	float fVec1[14];
	float fConst5;
	float fRec14[2];
	
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
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
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
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = (3.14159274f / fConst0);
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
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec6[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 14); l14 = (l14 + 1)) {
			fVec1[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
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
		float fSlow5 = float(fHslider3);
		float fSlow6 = (fConst1 * float(fHslider4));
		float fSlow7 = (fConst2 * float(fHslider5));
		float fSlow8 = (fConst4 * fSlow4);
		float fSlow9 = (fConst2 * float(fHslider6));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = ((fRec0[1] * fSlow2) + fSlow3);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow6 + (fRec5[1] - std::floor((fSlow6 + fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fTemp0 = float(iRec6[0]);
			float fTemp1 = ((fRec0[0] * ((fSlow5 * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec5[0]))]) + (1.39698387e-12f * fTemp0))) + 1.0f);
			float fTemp2 = std::max<float>(1.1920929e-07f, std::fabs((fSlow4 * fTemp1)));
			float fTemp3 = (fRec2[1] + (fConst1 * fTemp2));
			float fTemp4 = (fTemp3 + -1.0f);
			int iTemp5 = (fTemp4 < 0.0f);
			float fTempFTZ2 = (iTemp5 ? fTemp3 : fTemp4);
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fThen3 = (fTemp3 + (fTemp4 * (1.0f - (fConst0 / fTemp2))));
			float fTempFTZ3 = (iTemp5 ? fTemp3 : fThen3);
			float fRec3 = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow7 + (fConst3 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp6 = std::tan((fSlow8 * fTemp1));
			float fTemp7 = (1.0f / fTemp6);
			float fTemp8 = (((fTemp7 + 0.833333313f) / fTemp6) + 1.0f);
			float fTempFTZ5 = ((4.65661287e-10f * fTemp0) - (((fRec8[2] * (((fTemp7 + -0.833333313f) / fTemp6) + 1.0f)) + (2.0f * (fRec8[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp6)))))) / fTemp8));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp9 = (fTemp6 * fTemp8);
			float fTemp10 = ((((2.0f * fRec3) + -1.0f) * (1.0f - (0.5f * fRec7[0]))) + ((fRec0[0] * fRec7[0]) * ((fRec8[0] / fTemp9) + (fRec8[2] * (0.0f - (1.0f / fTemp9))))));
			float fTempFTZ6 = (fSlow9 + (fConst3 * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			int iTemp11 = (fRec9[0] < 1.0f);
			int iTemp12 = (fRec9[0] < 2.0f);
			int iTemp13 = (fRec9[0] < 3.0f);
			float fTemp14 = (fRec9[0] + -3.0f);
			float fTemp15 = (200.0f * fTemp14);
			float fTemp16 = (fRec9[0] + -2.0f);
			float fTemp17 = (400.0f * fTemp16);
			float fThen4 = (4200.0f - fTemp15);
			float fElse4 = (4600.0f - fTemp17);
			float fTemp18 = (fRec9[0] + -1.0f);
			float fTemp19 = (100.0f * fTemp18);
			float fThen5 = (iTemp13 ? fElse4 : fThen4);
			float fElse5 = (fTemp19 + 4500.0f);
			float fThen6 = (iTemp12 ? fElse5 : fThen5);
			float fTemp20 = (iTemp11 ? 4500.0f : fThen6);
			float fTemp21 = std::tan((fConst4 * fTemp20));
			float fTemp22 = (1.0f / fTemp21);
			float fTemp23 = (160.0f / fTemp20);
			float fTemp24 = (((fTemp22 + fTemp23) / fTemp21) + 1.0f);
			float fTempFTZ7 = (fTemp10 - (((fRec1[2] * (((fTemp22 - fTemp23) / fTemp21) + 1.0f)) + (2.0f * (fRec1[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp21)))))) / fTemp24));
			fRec1[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fElse7 = (0.25f - (0.150000006f * fTemp16));
			float fThen8 = (iTemp13 ? fElse7 : 0.100000001f);
			float fElse8 = ((0.0500000007f * fTemp18) + 0.200000003f);
			float fThen9 = (iTemp12 ? fElse8 : fThen8);
			float fElse9 = ((0.0500000007f * fRec9[0]) + 0.150000006f);
			float fTemp25 = (iTemp11 ? fElse9 : fThen9);
			float fTemp26 = (fTemp21 * fTemp24);
			float fThen10 = (3300.0f - fTemp15);
			float fElse10 = (3700.0f - fTemp17);
			float fThen11 = (iTemp13 ? fElse10 : fThen10);
			float fElse11 = (fTemp19 + 3600.0f);
			float fTemp27 = (100.0f * fRec9[0]);
			float fThen12 = (iTemp12 ? fElse11 : fThen11);
			float fElse12 = (fTemp27 + 3500.0f);
			float fTemp28 = (iTemp11 ? fElse12 : fThen12);
			float fTemp29 = std::tan((fConst4 * fTemp28));
			float fTemp30 = (1.0f / fTemp29);
			float fTemp31 = (130.0f / fTemp28);
			float fTemp32 = (((fTemp30 + fTemp31) / fTemp29) + 1.0f);
			float fTempFTZ8 = (fTemp10 - (((fRec10[2] * (((fTemp30 - fTemp31) / fTemp29) + 1.0f)) + (2.0f * (fRec10[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp29)))))) / fTemp32));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fThen13 = (0.25f - (0.0500000007f * fTemp14));
			float fElse13 = (0.5f - (0.25f * fTemp16));
			float fThen14 = (iTemp13 ? fElse13 : fThen13);
			float fElse14 = ((0.100000001f * fTemp18) + 0.400000006f);
			float fThen15 = (iTemp12 ? fElse14 : fThen14);
			float fElse15 = ((0.100000001f * fRec9[0]) + 0.300000012f);
			float fTemp33 = (iTemp11 ? fElse15 : fThen15);
			float fTemp34 = (fTemp29 * fTemp32);
			float fThen16 = (2500.0f - fTemp15);
			float fElse16 = (3000.0f - (500.0f * fTemp16));
			float fThen17 = (iTemp13 ? fElse16 : fThen16);
			float fElse17 = ((400.0f * fTemp18) + 2600.0f);
			float fThen18 = (iTemp12 ? fElse17 : fThen17);
			float fElse18 = (fTemp27 + 2500.0f);
			float fTemp35 = (iTemp11 ? fElse18 : fThen18);
			float fTemp36 = std::tan((fConst4 * fTemp35));
			float fTemp37 = (1.0f / fTemp36);
			float fTemp38 = (120.0f / fTemp35);
			float fTemp39 = (((fTemp37 + fTemp38) / fTemp36) + 1.0f);
			float fTempFTZ9 = (fTemp10 - (((fRec11[2] * (((fTemp37 - fTemp38) / fTemp36) + 1.0f)) + (2.0f * (fRec11[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp36)))))) / fTemp39));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp40 = (0.0500000007f * fTemp14);
			float fThen19 = (0.400000006f - fTemp40);
			float fElse19 = (0.800000012f - (0.400000006f * fTemp16));
			float fTemp41 = (0.100000001f * fTemp18);
			float fThen20 = (iTemp13 ? fElse19 : fThen19);
			float fElse20 = (fTemp41 + 0.699999988f);
			float fThen21 = (iTemp12 ? fElse20 : fThen20);
			float fElse21 = ((0.150000006f * fRec9[0]) + 0.550000012f);
			float fTemp42 = (iTemp11 ? fElse21 : fThen21);
			float fTemp43 = (fTemp36 * fTemp39);
			float fElse22 = (2300.0f - (1500.0f * fTemp16));
			float fThen23 = (iTemp13 ? fElse22 : 800.0f);
			float fElse23 = ((500.0f * fTemp18) + 1800.0f);
			float fThen24 = (iTemp12 ? fElse23 : fThen23);
			float fElse24 = ((600.0f * fRec9[0]) + 1200.0f);
			float fTemp44 = (iTemp11 ? fElse24 : fThen24);
			float fTemp45 = std::tan((fConst4 * fTemp44));
			float fTemp46 = (1.0f / fTemp45);
			float fTemp47 = (90.0f / fTemp44);
			float fTemp48 = (((fTemp46 + fTemp47) / fTemp45) + 1.0f);
			float fTempFTZ10 = (fTemp10 - (((fRec12[2] * (((fTemp46 - fTemp47) / fTemp45) + 1.0f)) + (2.0f * (fRec12[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp45)))))) / fTemp48));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fThen25 = (0.600000024f - (0.0500000007f * fTemp14));
			float fElse25 = (0.949999988f - (0.349999994f * fTemp16));
			float fThen26 = (iTemp13 ? fElse25 : fThen25);
			float fElse26 = (1.0f - (0.0500000007f * fTemp18));
			float fThen27 = (iTemp12 ? fElse26 : fThen26);
			float fElse27 = ((0.150000006f * fRec9[0]) + 0.850000024f);
			float fTemp49 = (iTemp11 ? fElse27 : fThen27);
			float fTemp50 = (fTemp45 * fTemp48);
			float fThen28 = (400.0f - (100.0f * fTemp14));
			float fElse28 = ((100.0f * fTemp16) + 300.0f);
			float fThen29 = (iTemp13 ? fElse28 : fThen28);
			float fElse29 = (400.0f - fTemp19);
			float fThen30 = (iTemp12 ? fElse29 : fThen29);
			float fElse30 = (800.0f - (400.0f * fRec9[0]));
			float fTemp51 = (iTemp11 ? fElse30 : fThen30);
			float fTemp52 = std::tan((fConst4 * fTemp51));
			float fTemp53 = (1.0f / fTemp52);
			float fTemp54 = (80.0f / fTemp51);
			float fTemp55 = (((fTemp53 + fTemp54) / fTemp52) + 1.0f);
			float fTempFTZ11 = (fTemp10 - (((fRec13[2] * (((fTemp53 - fTemp54) / fTemp52) + 1.0f)) + (2.0f * (fRec13[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp52)))))) / fTemp55));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fThen31 = (0.899999976f - fTemp40);
			float fElse31 = ((0.200000003f * fTemp16) + 0.699999988f);
			float fThen32 = (iTemp13 ? fElse31 : fThen31);
			float fElse32 = (0.800000012f - fTemp41);
			float fThen33 = (iTemp12 ? fElse32 : fThen32);
			float fElse33 = (1.0f - (0.200000003f * fRec9[0]));
			float fTemp56 = (iTemp11 ? fElse33 : fThen33);
			float fTemp57 = (fTemp52 * fTemp55);
			float fTemp58 = (fRec0[0] * ((fRec1[2] * (0.0f - (fTemp25 / fTemp26))) + (((fRec10[2] * (0.0f - (fTemp33 / fTemp34))) + (((fRec11[2] * (0.0f - (fTemp42 / fTemp43))) + (((fRec12[2] * (0.0f - (fTemp49 / fTemp50))) + ((((fRec13[0] * fTemp56) / fTemp57) + (fRec13[2] * (0.0f - (fTemp56 / fTemp57)))) + ((fRec12[0] * fTemp49) / fTemp50))) + ((fRec11[0] * fTemp42) / fTemp43))) + ((fRec10[0] * fTemp33) / fTemp34))) + ((fRec1[0] * fTemp25) / fTemp26))));
			fVec1[0] = fTemp58;
			float fTemp59 = (0.400000006f * fTemp58);
			float fTempFTZ12 = (fConst5 + (fRec14[1] - std::floor((fConst5 + fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp60 = (3.0f * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec14[0]))]);
			float fTemp61 = (fTemp60 + 8.5f);
			int iTemp62 = int(fTemp61);
			float fTemp63 = std::floor(fTemp61);
			float fTemp64 = ((fVec1[std::min<int>(4097, std::max<int>(0, iTemp62))] * (fTemp63 + (-7.5f - fTemp60))) + ((fTemp60 + (8.5f - fTemp63)) * fVec1[std::min<int>(4097, std::max<int>(0, (iTemp62 + 1)))]));
			output0[i0] = FAUSTFLOAT((fTemp59 + (0.140000001f * fTemp64)));
			output1[i0] = FAUSTFLOAT((fTemp59 - (0.0700000003f * fTemp64)));
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			iRec6[1] = iRec6[0];
			fRec2[1] = fRec2[0];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			for (int j0 = 13; (j0 > 0); j0 = (j0 - 1)) {
				fVec1[j0] = fVec1[(j0 - 1)];
			}
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
