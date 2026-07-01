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
	
	int iVec2[2];
	int iRec36[2];
	
  public:
	
	int getNumInputsFaustBansuriDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustBansuriDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustBansuriDSPSIG0(int sample_rate) {
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iVec2[l17] = 0;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iRec36[l18] = 0;
		}
	}
	
	void fillFaustBansuriDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec2[0] = 1;
			iRec36[0] = ((iVec2[1] + iRec36[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec36[0])));
			iVec2[1] = iVec2[0];
			iRec36[1] = iRec36[0];
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
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider0;
	float fConst6;
	float fRec0[2];
	float fConst7;
	float fConst8;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec2[2];
	int iRec18[2];
	float fConst10;
	float fConst11;
	float fConst12;
	float fRec25[2];
	float fVec1[2];
	float fConst13;
	float fRec24[2];
	FAUSTFLOAT fHslider1;
	float fConst14;
	FAUSTFLOAT fHslider2;
	float fRec27[2];
	float fRec26[2];
	FAUSTFLOAT fHslider3;
	float fRec28[2];
	float fConst15;
	float fRec29[2];
	int iRec31[2];
	float fRec30[4];
	float fRec32[2];
	int IOTA;
	float fRec33[2048];
	float fConst16;
	float fConst17;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec34[2];
	FAUSTFLOAT fHslider6;
	float fRec35[2];
	float fConst18;
	float fRec37[2];
	FAUSTFLOAT fHslider7;
	float fRec38[2];
	float fVec3[2];
	float fVec4[2048];
	float fVec5[2];
	float fRec23[2];
	float fRec14[2048];
	float fRec10[2];
	float fRec6[2048];
	float fRec4[2];
	float fRec5[2];
	float fRec3[2];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec1[3];
	
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
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
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
		float fConst1 = std::tan((15707.9629f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 1.41421354f) / fConst1) + 1.0f);
		fConst4 = (0.400000006f / fConst3);
		fConst5 = (44.0999985f / fConst0);
		fConst6 = (1.0f - fConst5);
		fConst7 = std::exp((0.0f - (25.0f / fConst0)));
		fConst8 = (1.0f - fConst7);
		float fConst9 = (1.0f / std::tan((14137.167f / fConst0)));
		fConst10 = (1.0f / (fConst9 + 1.0f));
		fConst11 = std::exp((0.0f - (50.0f / fConst0)));
		fConst12 = (1.0f - fConst11);
		fConst13 = (1.0f - fConst9);
		fConst14 = (1.0f / fConst0);
		fConst15 = std::exp((0.0f - (16.666666f / fConst0)));
		fConst16 = (0.00882352982f * fConst0);
		fConst17 = (0.00147058826f * fConst0);
		fConst18 = (5.0f / fConst0);
		fConst19 = (1.0f / fConst3);
		fConst20 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst21 = (2.0f * (1.0f - (1.0f / FaustBansuriDSP_faustpower2_f(fConst1))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.88f);
		fHslider3 = FAUSTFLOAT(0.34999999999999998f);
		fHslider4 = FAUSTFLOAT(0.080000000000000002f);
		fHslider5 = FAUSTFLOAT(440.0f);
		fHslider6 = FAUSTFLOAT(0.20000000000000001f);
		fHslider7 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec18[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec25[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec24[l6] = 0.0f;
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
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec37[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec38[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fVec3[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2048); l22 = (l22 + 1)) {
			fVec4[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fVec5[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec23[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2048); l25 = (l25 + 1)) {
			fRec14[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec10[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2048); l27 = (l27 + 1)) {
			fRec6[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec4[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec5[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec3[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec1[l31] = 0.0f;
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
		ui_interface->addHorizontalSlider("breathiness", &fHslider3, FAUSTFLOAT(0.349999994f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider5, FAUSTFLOAT(440.0f), FAUSTFLOAT(220.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("glide", &fHslider4, FAUSTFLOAT(0.0799999982f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider2, FAUSTFLOAT(0.879999995f), FAUSTFLOAT(0.200000003f), FAUSTFLOAT(1.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato", &fHslider6, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst5 * float(fHslider0));
		float fSlow1 = float(fButton0);
		float fSlow2 = (fConst8 * fSlow1);
		float fSlow3 = (fConst12 * fSlow1);
		float fSlow4 = ((0.100000001f * (1.0f - float(fHslider1))) + 0.00499999989f);
		int iSlow5 = (std::fabs(fSlow4) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst14 / (iSlow5 ? 1.0f : fSlow4))));
		float fSlow6 = (iSlow5 ? 0.0f : fThen1);
		float fSlow7 = (fConst5 * float(fHslider2));
		float fSlow8 = (1.0f - fSlow6);
		float fSlow9 = (fConst5 * float(fHslider3));
		float fSlow10 = float(fHslider4);
		int iSlow11 = (std::fabs(fSlow10) < 1.1920929e-07f);
		float fThen3 = std::exp((0.0f - (fConst14 / (iSlow11 ? 1.0f : fSlow10))));
		float fSlow12 = (iSlow11 ? 0.0f : fThen3);
		float fSlow13 = (float(fHslider5) * (1.0f - fSlow12));
		float fSlow14 = (fConst5 * float(fHslider6));
		float fSlow15 = (fConst5 * float(fHslider7));
		float fSlow16 = (0.25f * fSlow1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst6 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec0[0] = fSlow1;
			float fTempFTZ1 = (fSlow2 + (fConst7 * fRec2[1]));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec18[0] = 0;
			float fTempFTZ2 = (fSlow3 + (fConst11 * fRec25[1]));
			fRec25[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp0 = (fRec25[0] * fRec23[1]);
			fVec1[0] = fTemp0;
			float fTempFTZ3 = (fConst10 * ((0.970000029f * (fTemp0 + fVec1[1])) - (fConst13 * fRec24[1])));
			fRec24[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fRec24[0] + float(iRec18[1]));
			float fRec22 = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow7 + (fConst6 * fRec27[1]));
			fRec27[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = ((fRec26[1] * fSlow6) + (std::min<float>(1.5f, (fSlow1 * fRec27[0])) * fSlow8));
			fRec26[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fSlow9 + (fConst6 * fRec28[1]));
			fRec28[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = ((fConst15 * fRec29[1]) + (0.5f * float(((fSlow1 - fVec0[1]) > 0.0f))));
			fRec29[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			iRec31[0] = ((1103515245 * iRec31[1]) + 12345);
			float fTempFTZ9 = (((0.522189379f * fRec30[3]) + ((4.65661287e-10f * float(iRec31[0])) + (2.49495602f * fRec30[1]))) - (2.0172658f * fRec30[2]));
			fRec30[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp1 = ((fRec28[0] + fRec29[0]) * (((0.0499220341f * fRec30[0]) + (0.0506126992f * fRec30[2])) - ((0.0959935337f * fRec30[1]) + (0.00440878607f * fRec30[3]))));
			float fTempFTZ10 = fRec4[1];
			fRec32[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (0.99000001f * (fRec25[0] * fRec32[1]));
			fRec33[(IOTA & 2047)] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = ((fRec34[1] * fSlow12) + fSlow13);
			fRec34[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fSlow14 + (fConst6 * fRec35[1]));
			fRec35[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fConst18 + (fRec37[1] - std::floor((fConst18 + fRec37[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp2 = ((340.0f / (fRec34[0] * ((0.0149999997f * (fRec35[0] * ftbl0FaustBansuriDSPSIG0[int((65536.0f * fRec37[0]))])) + 1.0f))) + 0.0500000007f);
			float fTempFTZ15 = (fSlow15 + (fConst6 * fRec38[1]));
			fRec38[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp3 = (0.100000001f * fRec38[0]);
			float fTemp4 = (fConst17 * (fTemp2 * (fTemp3 + 0.200000003f)));
			float fTemp5 = (fTemp4 + -1.49999499f);
			int iTemp6 = int(fTemp5);
			int iTemp7 = (int(std::min<float>(fConst16, float(std::max<int>(0, iTemp6)))) + 1);
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
			int iTemp18 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp6 + 1))))) + 1);
			float fTemp19 = (0.0f - fTemp11);
			float fTemp20 = (0.0f - (0.5f * fTemp13));
			float fTemp21 = (0.0f - (0.333333343f * fTemp15));
			int iTemp22 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp6 + 2))))) + 1);
			float fTemp23 = (0.0f - fTemp13);
			float fTemp24 = (0.0f - (0.5f * fTemp15));
			float fTemp25 = (fTemp9 * fTemp11);
			int iTemp26 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp6 + 3))))) + 1);
			float fTemp27 = (0.0f - fTemp15);
			float fTemp28 = (fTemp25 * fTemp13);
			int iTemp29 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp6 + 4))))) + 1);
			fVec3[0] = (((((fRec33[((IOTA - iTemp7) & 2047)] * fTemp10) * fTemp12) * fTemp14) * fTemp16) + (fTemp17 * ((((((fRec33[((IOTA - iTemp18) & 2047)] * fTemp19) * fTemp20) * fTemp21) + (0.5f * (((fTemp9 * fRec33[((IOTA - iTemp22) & 2047)]) * fTemp23) * fTemp24))) + (0.166666672f * ((fTemp25 * fRec33[((IOTA - iTemp26) & 2047)]) * fTemp27))) + (0.0416666679f * (fTemp28 * fRec33[((IOTA - iTemp29) & 2047)])))));
			float fTemp30 = ((fRec26[0] * ((0.0500000007f * fTemp1) + 1.0f)) - (0.5f * fVec3[1]));
			float fTemp31 = ((0.5f * fRec10[1]) + std::max<float>(-1.0f, std::min<float>(1.0f, (fTemp30 * (FaustBansuriDSP_faustpower2_f(fTemp30) + -1.0f)))));
			fVec4[(IOTA & 2047)] = fTemp31;
			float fTemp32 = (fConst17 * (fTemp2 * (0.800000012f - fTemp3)));
			float fTemp33 = (fTemp32 + -1.49999499f);
			int iTemp34 = int(fTemp33);
			int iTemp35 = (int(std::min<float>(fConst16, float(std::max<int>(0, iTemp34)))) + 1);
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
			int iTemp46 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp34 + 1))))) + 1);
			float fTemp47 = (0.0f - fTemp39);
			float fTemp48 = (0.0f - (0.5f * fTemp41));
			float fTemp49 = (0.0f - (0.333333343f * fTemp43));
			int iTemp50 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp34 + 2))))) + 1);
			float fTemp51 = (0.0f - fTemp41);
			float fTemp52 = (0.0f - (0.5f * fTemp43));
			float fTemp53 = (fTemp37 * fTemp39);
			int iTemp54 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp34 + 3))))) + 1);
			float fTemp55 = (0.0f - fTemp43);
			float fTemp56 = (fTemp53 * fTemp41);
			int iTemp57 = (int(std::min<float>(fConst16, float(std::max<int>(0, (iTemp34 + 4))))) + 1);
			fVec5[0] = (((((fVec4[((IOTA - iTemp35) & 2047)] * fTemp38) * fTemp40) * fTemp42) * fTemp44) + (fTemp45 * ((((((fVec4[((IOTA - iTemp46) & 2047)] * fTemp47) * fTemp48) * fTemp49) + (0.5f * (((fTemp37 * fVec4[((IOTA - iTemp50) & 2047)]) * fTemp51) * fTemp52))) + (0.166666672f * ((fTemp53 * fVec4[((IOTA - iTemp54) & 2047)]) * fTemp55))) + (0.0416666679f * (fTemp56 * fVec4[((IOTA - iTemp57) & 2047)])))));
			float fTempFTZ16 = fVec5[1];
			fRec23[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec22;
			float fRec19 = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec23[0];
			float fTemp58 = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fRec20 = fTemp58;
			float fRec21 = fTemp58;
			float fTempFTZ19 = fRec19;
			fRec14[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (((((fTemp38 * fTemp40) * fTemp42) * fTemp44) * fRec14[((IOTA - iTemp35) & 2047)]) + (fTemp45 * ((((((fTemp47 * fTemp48) * fTemp49) * fRec14[((IOTA - iTemp46) & 2047)]) + (0.5f * (((fTemp37 * fTemp51) * fTemp52) * fRec14[((IOTA - iTemp50) & 2047)]))) + (0.166666672f * ((fTemp53 * fTemp55) * fRec14[((IOTA - iTemp54) & 2047)]))) + (0.0416666679f * (fTemp56 * fRec14[((IOTA - iTemp57) & 2047)])))));
			float fRec15 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec20;
			float fRec16 = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = fRec21;
			float fRec17 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec15;
			fRec10[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec10[1];
			float fRec11 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec16;
			float fRec12 = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec17;
			float fRec13 = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec11;
			fRec6[(IOTA & 2047)] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (((((fTemp10 * fTemp12) * fTemp14) * fTemp16) * fRec6[((IOTA - iTemp7) & 2047)]) + (fTemp17 * ((((((fTemp19 * fTemp20) * fTemp21) * fRec6[((IOTA - iTemp18) & 2047)]) + (0.5f * (((fTemp9 * fTemp23) * fTemp24) * fRec6[((IOTA - iTemp22) & 2047)]))) + (0.166666672f * ((fTemp25 * fTemp27) * fRec6[((IOTA - iTemp26) & 2047)]))) + (0.0416666679f * (fTemp28 * fRec6[((IOTA - iTemp29) & 2047)])))));
			float fRec7 = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec12;
			float fRec8 = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = fRec13;
			float fRec9 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = fRec7;
			fRec4[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec9;
			fRec5[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = ((fRec5[0] + (0.995000005f * fRec3[1])) - fRec5[1]);
			fRec3[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = ((fRec2[0] * (fRec3[0] + (fSlow16 * fTemp1))) - (fConst19 * ((fConst20 * fRec1[2]) + (fConst21 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			output0[i0] = FAUSTFLOAT((fConst4 * (fRec0[0] * (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))))));
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			iRec18[1] = iRec18[0];
			fRec25[1] = fRec25[0];
			fVec1[1] = fVec1[0];
			fRec24[1] = fRec24[0];
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
			fRec37[1] = fRec37[0];
			fRec38[1] = fRec38[0];
			fVec3[1] = fVec3[0];
			fVec5[1] = fVec5[0];
			fRec23[1] = fRec23[0];
			fRec10[1] = fRec10[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
