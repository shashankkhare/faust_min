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
	int iRec2[2];
	
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
			iRec2[l2] = 0;
		}
	}
	
	void fillFaustVoiceDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec2[0] = ((iVec0[1] + iRec2[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec2[0])));
			iVec0[1] = iVec0[0];
			iRec2[1] = iRec2[0];
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
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec3[2];
	int iRec4[2];
	float fRec1[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider5;
	float fRec6[2];
	float fRec5[2];
	FAUSTFLOAT fHslider6;
	float fRec7[2];
	FAUSTFLOAT fHslider7;
	float fRec8[2];
	float fRec9[2];
	FAUSTFLOAT fHslider8;
	float fRec10[2];
	float fRec11[2];
	float fRec12[2];
	float fRec13[2];
	FAUSTFLOAT fHslider9;
	float fRec14[2];
	float fConst4;
	float fRec15[3];
	float fVec1[14];
	float fConst5;
	float fRec16[2];
	
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
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
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
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.5f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(0.5f);
		fHslider9 = FAUSTFLOAT(0.14999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec4[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 14); l17 = (l17 + 1)) {
			fVec1[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
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
		ui_interface->addHorizontalSlider("breathiness", &fHslider9, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chest", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(220.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("glottal", &fHslider8, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("nasal", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider3, FAUSTFLOAT(0.0120000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0799999982f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider4, FAUSTFLOAT(5.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("vowel", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.00999999978f));
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
		float fSlow5 = (fConst1 * fSlow4);
		float fSlow6 = float(fHslider3);
		float fSlow7 = (fConst1 * float(fHslider4));
		float fSlow8 = (fConst2 * float(fHslider5));
		float fSlow9 = (fConst2 * float(fHslider6));
		float fSlow10 = (fConst2 * float(fHslider7));
		float fSlow11 = (fConst2 * float(fHslider8));
		float fSlow12 = (fConst2 * float(fHslider9));
		float fSlow13 = (fConst4 * fSlow4);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = ((fRec0[1] * fSlow2) + fSlow3);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow7 + (fRec3[1] - std::floor((fSlow7 + fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTemp0 = float(iRec4[0]);
			float fTemp1 = ((fRec0[0] * ((fSlow6 * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec3[0]))]) + (1.39698387e-12f * fTemp0))) + 1.0f);
			float fTemp2 = (fRec1[1] + (fSlow5 * fTemp1));
			float fTempFTZ2 = (fTemp2 - std::floor(fTemp2));
			fRec1[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp3 = (std::cos((6.28318548f * fRec1[0])) + -1.0f);
			float fTemp4 = (fSlow4 * fTemp1);
			float fTemp5 = std::max<float>(1.0f, fTemp4);
			float fTemp6 = FaustVoiceDSP_faustpower2_f(fTemp5);
			float fTemp7 = (fTemp3 / fTemp6);
			float fTempFTZ3 = (fSlow8 + (fConst3 * fRec6[1]));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			int iTemp8 = (fRec6[0] < 1.0f);
			int iTemp9 = (fRec6[0] < 2.0f);
			int iTemp10 = (fRec6[0] < 3.0f);
			float fTemp11 = (fRec6[0] + -3.0f);
			float fTemp12 = (fRec6[0] + -2.0f);
			float fThen2 = (400.0f - (100.0f * fTemp11));
			float fElse2 = ((100.0f * fTemp12) + 300.0f);
			float fTemp13 = (fRec6[0] + -1.0f);
			float fTemp14 = (100.0f * fTemp13);
			float fThen3 = (iTemp10 ? fElse2 : fThen2);
			float fElse3 = (400.0f - fTemp14);
			float fThen4 = (iTemp9 ? fElse3 : fThen3);
			float fElse4 = (800.0f - (400.0f * fRec6[0]));
			float fTempFTZ4 = ((fConst3 * fRec5[1]) + (fConst2 * std::max<float>((iTemp8 ? fElse4 : fThen4), fTemp4)));
			fRec5[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow9 + (fConst3 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp15 = (std::max<float>(fTemp4, (fRec5[0] * (1.0f - (0.150000006f * (fRec7[0] + -0.5f))))) / fTemp5);
			float fTemp16 = std::floor(fTemp15);
			float fTemp17 = (0.0500000007f * fTemp11);
			float fThen5 = (0.899999976f - fTemp17);
			float fElse5 = ((0.200000003f * fTemp12) + 0.699999988f);
			float fTemp18 = (0.100000001f * fTemp13);
			float fThen6 = (iTemp10 ? fElse5 : fThen5);
			float fElse6 = (0.800000012f - fTemp18);
			float fThen7 = (iTemp9 ? fElse6 : fThen6);
			float fElse7 = (1.0f - (0.200000003f * fRec6[0]));
			float fTempFTZ6 = (fSlow10 + (fConst3 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fElse8 = (2300.0f - (1500.0f * fTemp12));
			float fThen9 = (iTemp10 ? fElse8 : 800.0f);
			float fElse9 = ((500.0f * fTemp13) + 1800.0f);
			float fThen10 = (iTemp9 ? fElse9 : fThen9);
			float fElse10 = ((600.0f * fRec6[0]) + 1200.0f);
			float fTempFTZ7 = ((fConst3 * fRec9[1]) + (fConst2 * std::max<float>((iTemp8 ? fElse10 : fThen10), (fRec5[0] + 200.0f))));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp19 = (fRec9[0] / fTemp5);
			float fTemp20 = std::floor(fTemp19);
			float fThen11 = (0.600000024f - (0.0500000007f * fTemp11));
			float fElse11 = (0.949999988f - (0.349999994f * fTemp12));
			float fThen12 = (iTemp10 ? fElse11 : fThen11);
			float fElse12 = (1.0f - (0.0500000007f * fTemp13));
			float fThen13 = (iTemp9 ? fElse12 : fThen12);
			float fElse13 = ((0.150000006f * fRec6[0]) + 0.850000024f);
			float fTempFTZ8 = (fSlow11 + (fConst3 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp21 = FaustVoiceDSP_faustpower2_f((1.0f - (0.300000012f * (fRec10[0] + -0.5f))));
			float fTemp22 = ((fTemp3 * fTemp21) / fTemp6);
			float fTemp23 = (200.0f * fTemp11);
			float fThen14 = (2500.0f - fTemp23);
			float fElse14 = (3000.0f - (500.0f * fTemp12));
			float fThen15 = (iTemp10 ? fElse14 : fThen14);
			float fElse15 = ((400.0f * fTemp13) + 2600.0f);
			float fTemp24 = (100.0f * fRec6[0]);
			float fThen16 = (iTemp9 ? fElse15 : fThen15);
			float fElse16 = (fTemp24 + 2500.0f);
			float fTempFTZ9 = ((fConst3 * fRec11[1]) + (fConst2 * std::max<float>((iTemp8 ? fElse16 : fThen16), (fRec9[0] + 200.0f))));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp25 = (fRec11[0] / fTemp5);
			float fTemp26 = std::floor(fTemp25);
			float fTemp27 = (fTemp21 / fTemp6);
			float fThen17 = (0.400000006f - fTemp17);
			float fElse17 = (0.800000012f - (0.400000006f * fTemp12));
			float fThen18 = (iTemp10 ? fElse17 : fThen17);
			float fElse18 = (fTemp18 + 0.699999988f);
			float fThen19 = (iTemp9 ? fElse18 : fThen18);
			float fElse19 = ((0.150000006f * fRec6[0]) + 0.550000012f);
			float fTemp28 = (400.0f * fTemp12);
			float fThen20 = (3300.0f - fTemp23);
			float fElse20 = (3700.0f - fTemp28);
			float fThen21 = (iTemp10 ? fElse20 : fThen20);
			float fElse21 = (fTemp14 + 3600.0f);
			float fThen22 = (iTemp9 ? fElse21 : fThen21);
			float fElse22 = (fTemp24 + 3500.0f);
			float fTempFTZ10 = ((fConst3 * fRec12[1]) + (fConst2 * std::max<float>((iTemp8 ? fElse22 : fThen22), (fRec11[0] + 200.0f))));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp29 = (fRec12[0] / fTemp5);
			float fTemp30 = std::floor(fTemp29);
			float fThen23 = (0.25f - (0.0500000007f * fTemp11));
			float fElse23 = (0.5f - (0.25f * fTemp12));
			float fThen24 = (iTemp10 ? fElse23 : fThen23);
			float fElse24 = ((0.100000001f * fTemp13) + 0.400000006f);
			float fThen25 = (iTemp9 ? fElse24 : fThen24);
			float fElse25 = ((0.100000001f * fRec6[0]) + 0.300000012f);
			float fThen26 = (4200.0f - fTemp23);
			float fElse26 = (4600.0f - fTemp28);
			float fThen27 = (iTemp10 ? fElse26 : fThen26);
			float fElse27 = (fTemp14 + 4500.0f);
			float fThen28 = (iTemp9 ? fElse27 : fThen27);
			float fTempFTZ11 = ((fConst3 * fRec13[1]) + (fConst2 * std::max<float>((iTemp8 ? 4500.0f : fThen28), (fRec12[0] + 200.0f))));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp31 = (fRec13[0] / fTemp5);
			float fTemp32 = std::floor(fTemp31);
			float fElse29 = (0.25f - (0.150000006f * fTemp12));
			float fThen30 = (iTemp10 ? fElse29 : 0.100000001f);
			float fElse30 = ((0.0500000007f * fTemp13) + 0.200000003f);
			float fThen31 = (iTemp9 ? fElse30 : fThen30);
			float fElse31 = ((0.0500000007f * fRec6[0]) + 0.150000006f);
			float fTemp33 = (1500.0f / fTemp5);
			float fTemp34 = std::floor(fTemp33);
			float fTempFTZ12 = (fSlow12 + (fConst3 * fRec14[1]));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp35 = std::tan((fSlow13 * fTemp1));
			float fTemp36 = (1.0f / fTemp35);
			float fTemp37 = (((fTemp36 + 0.833333313f) / fTemp35) + 1.0f);
			float fTempFTZ13 = ((4.65661287e-10f * fTemp0) - (((fRec15[2] * (((fTemp36 + -0.833333313f) / fTemp35) + 1.0f)) + (2.0f * (fRec15[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp35)))))) / fTemp37));
			fRec15[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp38 = (fTemp35 * fTemp37);
			float fTemp39 = (fRec0[0] * ((((((((((std::exp(std::max<float>(-80.0f, (3200.0f * fTemp7))) * (((fTemp16 + (1.0f - fTemp15)) * std::cos((6.28318548f * (fRec1[0] * fTemp16)))) + ((fTemp15 - fTemp16) * std::cos((6.28318548f * (fRec1[0] * (fTemp16 + 1.0f))))))) * std::sqrt(((3200.0f / fTemp6) + 1.0f))) * (iTemp8 ? fElse7 : fThen7)) * (fRec7[0] + 0.5f)) * (1.0f - (0.400000006f * fRec8[0]))) + (0.5f * ((((std::exp(std::max<float>(-80.0f, (4050.0f * fTemp7))) * (((fTemp20 + (1.0f - fTemp19)) * std::cos((6.28318548f * (fRec1[0] * fTemp20)))) + ((fTemp19 - fTemp20) * std::cos((6.28318548f * (fRec1[0] * (fTemp20 + 1.0f))))))) * std::sqrt(((4050.0f / fTemp6) + 1.0f))) * (iTemp8 ? fElse13 : fThen13)) * (fRec7[0] + 1.0f)))) + (2.0f * (fRec10[0] * (((((std::exp(std::max<float>(-80.0f, (7200.0f * fTemp22))) * (((fTemp26 + (1.0f - fTemp25)) * std::cos((6.28318548f * (fRec1[0] * fTemp26)))) + ((fTemp25 - fTemp26) * std::cos((6.28318548f * (fRec1[0] * (fTemp26 + 1.0f))))))) * std::sqrt(((7200.0f * fTemp27) + 1.0f))) * (iTemp8 ? fElse19 : fThen19)) + (((std::exp(std::max<float>(-80.0f, (8450.0f * fTemp22))) * (((fTemp30 + (1.0f - fTemp29)) * std::cos((6.28318548f * (fRec1[0] * fTemp30)))) + ((fTemp29 - fTemp30) * std::cos((6.28318548f * (fRec1[0] * (fTemp30 + 1.0f))))))) * std::sqrt(((8450.0f * fTemp27) + 1.0f))) * (iTemp8 ? fElse25 : fThen25))) + (((std::exp(std::max<float>(-80.0f, (12800.0f * fTemp22))) * (((fTemp32 + (1.0f - fTemp31)) * std::cos((6.28318548f * (fRec1[0] * fTemp32)))) + ((fTemp31 - fTemp32) * std::cos((6.28318548f * (fRec1[0] * (fTemp32 + 1.0f))))))) * std::sqrt(((12800.0f * fTemp27) + 1.0f))) * (iTemp8 ? fElse31 : fThen31)))))) + (0.600000024f * (((fRec8[0] * std::exp(std::max<float>(-80.0f, (11250.0f * fTemp7)))) * (((fTemp34 + (1.0f - fTemp33)) * std::cos((6.28318548f * (fRec1[0] * fTemp34)))) + ((fTemp33 - fTemp34) * std::cos((6.28318548f * (fRec1[0] * (fTemp34 + 1.0f))))))) * std::sqrt(((11250.0f / fTemp6) + 1.0f))))) * (1.0f - (0.5f * fRec14[0]))) + ((fRec0[0] * fRec14[0]) * ((fRec15[0] / fTemp38) + (fRec15[2] * (0.0f - (1.0f / fTemp38)))))));
			fVec1[0] = fTemp39;
			float fTemp40 = (0.25f * fTemp39);
			float fTempFTZ14 = (fConst5 + (fRec16[1] - std::floor((fConst5 + fRec16[1]))));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp41 = (3.0f * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec16[0]))]);
			float fTemp42 = (fTemp41 + 8.5f);
			int iTemp43 = int(fTemp42);
			float fTemp44 = std::floor(fTemp42);
			float fTemp45 = ((fVec1[std::min<int>(4097, std::max<int>(0, iTemp43))] * (fTemp44 + (-7.5f - fTemp41))) + ((fTemp41 + (8.5f - fTemp44)) * fVec1[std::min<int>(4097, std::max<int>(0, (iTemp43 + 1)))]));
			output0[i0] = FAUSTFLOAT((fTemp40 + (0.0874999985f * fTemp45)));
			output1[i0] = FAUSTFLOAT((fTemp40 - (0.0437499993f * fTemp45)));
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			iRec4[1] = iRec4[0];
			fRec1[1] = fRec1[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			for (int j0 = 13; (j0 > 0); j0 = (j0 - 1)) {
				fVec1[j0] = fVec1[(j0 - 1)];
			}
			fRec16[1] = fRec16[0];
		}
	}

};

#endif
