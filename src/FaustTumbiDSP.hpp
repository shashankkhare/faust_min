/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tumbi"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTumbiDSP_H__
#define  __FaustTumbiDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustTumbiDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec3[2];
	
  public:
	
	int getNumInputsFaustTumbiDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTumbiDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTumbiDSPSIG0(int sample_rate) {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec3[l2] = 0;
		}
	}
	
	void fillFaustTumbiDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec3[0] = ((iVec0[1] + iRec3[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec3[0])));
			iVec0[1] = iVec0[0];
			iRec3[1] = iRec3[0];
		}
	}

};

static FaustTumbiDSPSIG0* newFaustTumbiDSPSIG0() { return (FaustTumbiDSPSIG0*)new FaustTumbiDSPSIG0(); }
static void deleteFaustTumbiDSPSIG0(FaustTumbiDSPSIG0* dsp) { delete dsp; }

static float FaustTumbiDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustTumbiDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTumbiDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTumbiDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst3;
	float fConst5;
	FAUSTFLOAT fHslider1;
	float fConst6;
	FAUSTFLOAT fHslider2;
	float fConst7;
	float fRec2[2];
	float fConst8;
	FAUSTFLOAT fHslider3;
	float fRec5[2];
	float fRec4[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec6[2];
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec7[3];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec8[2];
	int iRec9[2];
	int IOTA;
	float fVec2[8192];
	float fRec1[2];
	float fConst17;
	float fConst18;
	float fRec0[3];
	float fConst19;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "tumbi.dsp");
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
		m->declare("name", "tumbi");
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
		return 1;
	}
	
	static void classInit(int sample_rate) {
		FaustTumbiDSPSIG0* sig0 = newFaustTumbiDSPSIG0();
		sig0->instanceInitFaustTumbiDSPSIG0(sample_rate);
		sig0->fillFaustTumbiDSPSIG0(65536, ftbl0FaustTumbiDSPSIG0);
		deleteFaustTumbiDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((471.238892f / fConst0));
		float fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / (((fConst2 + 1.41421354f) / fConst1) + 1.0f));
		float fConst4 = FaustTumbiDSP_faustpower2_f(fConst1);
		fConst5 = (1.0f / fConst4);
		fConst6 = (44.0999985f / fConst0);
		fConst7 = (1.0f - fConst6);
		fConst8 = (1.0f / fConst0);
		float fConst9 = std::tan((628.318542f / fConst0));
		float fConst10 = (1.0f / fConst9);
		float fConst11 = (((fConst10 + 0.5f) / fConst9) + 1.0f);
		fConst12 = (0.00999999978f / (fConst9 * fConst11));
		fConst13 = (0.0f - fConst12);
		fConst14 = (1.0f / fConst11);
		fConst15 = (((fConst10 + -0.5f) / fConst9) + 1.0f);
		fConst16 = (2.0f * (1.0f - (1.0f / FaustTumbiDSP_faustpower2_f(fConst9))));
		fConst17 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst18 = (2.0f * (1.0f - fConst5));
		fConst19 = (0.0f - (2.0f / fConst4));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(329.63f);
		fHslider2 = FAUSTFLOAT(0.0030000000000000001f);
		fHslider3 = FAUSTFLOAT(5.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.80000000000000004f);
		fHslider5 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec9[l9] = 0;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 8192); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec1[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec0[l12] = 0.0f;
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
	
	virtual FaustTumbiDSP* clone() {
		return new FaustTumbiDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tumbi");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(329.630005f), FAUSTFLOAT(80.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider5, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider4, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider2, FAUSTFLOAT(0.00300000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider3, FAUSTFLOAT(5.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (fConst0 / float(fHslider1));
		float fSlow2 = (fConst6 * float(fHslider2));
		float fSlow3 = (fConst6 * float(fHslider3));
		float fSlow4 = float(fButton0);
		float fSlow5 = (1.5f * float(fHslider4));
		float fSlow6 = float(fHslider5);
		float fSlow7 = (1.0f - (0.800000012f * fSlow6));
		float fSlow8 = (2.32830644e-10f * fSlow6);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow2 + (fConst7 * fRec2[1]));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow3 + (fConst7 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (fRec4[1] + (fConst8 * fRec5[0]));
			float fTempFTZ2 = (fTemp0 - std::floor(fTemp0));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			fVec1[0] = fSlow4;
			float fTemp1 = float((fSlow4 > fVec1[1]));
			float fTempFTZ3 = ((0.999499977f * fRec6[1]) + fTemp1);
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp2 = (fSlow1 / (((fRec2[0] * ftbl0FaustTumbiDSPSIG0[int((65536.0f * fRec4[0]))]) + (0.00499999989f * fRec6[0])) + 1.0f));
			int iTemp3 = int((fTemp2 + -1.0f));
			float fTemp4 = float(iTemp3);
			float fTemp5 = (fRec1[1] * (1.0f - (0.00499999989f * std::fabs(fRec1[1]))));
			float fTempFTZ4 = (fTemp5 - (fConst14 * ((fConst15 * fRec7[2]) + (fConst16 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 + (0.995000005f * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			iRec9[0] = ((1103515245 * iRec9[1]) + 12345);
			float fTemp6 = ((0.99970001f * ((fConst13 * fRec7[2]) + (fTemp5 + (fConst12 * fRec7[0])))) + float(tanhf(float((fSlow5 * ((fSlow7 * fTemp1) + (fSlow8 * (fRec8[0] * float(iRec9[0])))))))));
			fVec2[(IOTA & 8191)] = fTemp6;
			float fTempFTZ6 = (((fTemp4 + (2.0f - fTemp2)) * fVec2[((IOTA - std::min<int>(4096, int(std::max<int>(0, int(iTemp3))))) & 8191)]) + ((fTemp2 + (-1.0f - fTemp4)) * fVec2[((IOTA - std::min<int>(4096, int(std::max<int>(0, int((iTemp3 + 1)))))) & 8191)]));
			fRec1[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((0.600000024f * fRec1[0]) - (fConst3 * ((fConst17 * fRec0[2]) + (fConst18 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			output0[i0] = FAUSTFLOAT(std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow0 * float(tanhf(float((fConst3 * (((fConst5 * fRec0[0]) + (fConst19 * fRec0[1])) + (fConst5 * fRec0[2]))))))))));
			fRec2[1] = fRec2[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fVec1[1] = fVec1[0];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			iRec9[1] = iRec9[0];
			IOTA = (IOTA + 1);
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
