/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "trumpet"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTrumpetDSP_H__
#define  __FaustTrumpetDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustTrumpetDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec6[2];
	
  public:
	
	int getNumInputsFaustTrumpetDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTrumpetDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTrumpetDSPSIG0(int sample_rate) {
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec1[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec6[l5] = 0;
		}
	}
	
	void fillFaustTrumpetDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec6[0] = ((iVec1[1] + iRec6[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec6[0])));
			iVec1[1] = iVec1[0];
			iRec6[1] = iRec6[0];
		}
	}

};

static FaustTrumpetDSPSIG0* newFaustTrumpetDSPSIG0() { return (FaustTrumpetDSPSIG0*)new FaustTrumpetDSPSIG0(); }
static void deleteFaustTrumpetDSPSIG0(FaustTrumpetDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustTrumpetDSPSIG0[65536];
static float FaustTrumpetDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTrumpetDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTrumpetDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[2];
	float fConst3;
	float fConst4;
	int iRec1[2];
	float fConst5;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	float fRec3[2];
	float fConst6;
	float fRec2[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "trumpet.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/resonlp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonlp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonlp:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "trumpet");
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
		FaustTrumpetDSPSIG0* sig0 = newFaustTrumpetDSPSIG0();
		sig0->instanceInitFaustTrumpetDSPSIG0(sample_rate);
		sig0->fillFaustTrumpetDSPSIG0(65536, ftbl0FaustTrumpetDSPSIG0);
		deleteFaustTrumpetDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::max<float>(1.0f, (0.0500000007f * fConst0));
		fConst2 = (1.0f / fConst1);
		fConst3 = (0.200000003f / std::max<float>(1.0f, (0.100000001f * fConst0)));
		fConst4 = (1.0f / std::max<float>(1.0f, (0.200000003f * fConst0)));
		fConst5 = (1.0f / fConst0);
		fConst6 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.014999999999999999f);
		fHslider3 = FAUSTFLOAT(5.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec1[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec2[l8] = 0.0f;
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
	
	virtual FaustTrumpetDSP* clone() {
		return new FaustTrumpetDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("trumpet");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(440.0f), FAUSTFLOAT(164.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider2, FAUSTFLOAT(0.0149999997f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider3, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (1.20000005f * fSlow0);
		float fSlow2 = float(fButton0);
		int iSlow3 = (fSlow2 == 0.0f);
		float fSlow4 = float(fHslider1);
		float fSlow5 = float(fHslider2);
		float fSlow6 = (0.00499999989f * (fSlow0 * fSlow2));
		float fSlow7 = (fConst5 * float(fHslider3));
		float fSlow8 = (2.0f * fSlow4);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow2;
			float fTempFTZ0 = (fSlow2 + (fRec0[1] * float((fVec0[1] >= fSlow2))));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec1[0] = (iSlow3 * (iRec1[1] + 1));
			float fTemp0 = std::max<float>(0.0f, (std::min<float>((fConst2 * fRec0[0]), std::max<float>((1.0f - (fConst3 * (fRec0[0] - fConst1))), 0.800000012f)) * (1.0f - (fConst4 * float(iRec1[0])))));
			float fTempFTZ1 = (fSlow6 + (0.995000005f * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow7 + (fRec7[1] - std::floor((fSlow7 + fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp1 = std::max<float>(1.1920929e-07f, std::fabs((fSlow4 * ((fSlow5 * (fRec5[0] * ftbl0FaustTrumpetDSPSIG0[int((65536.0f * fRec7[0]))])) + 1.0f))));
			float fTemp2 = (fRec3[1] + (fConst5 * fTemp1));
			float fTemp3 = (fTemp2 + -1.0f);
			int iTemp4 = (fTemp3 < 0.0f);
			float fTempFTZ3 = (iTemp4 ? fTemp2 : fTemp3);
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fThen1 = (fTemp2 + (fTemp3 * (1.0f - (fConst0 / fTemp1))));
			float fTempFTZ4 = (iTemp4 ? fTemp2 : fThen1);
			float fRec4 = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp5 = std::tan((fConst6 * (fSlow8 + ((800.0f * fRec5[0]) + (400.0f * fTemp0)))));
			float fTemp6 = (1.0f / fTemp5);
			float fTemp7 = (((fTemp6 + 0.333333343f) / fTemp5) + 1.0f);
			float fTempFTZ5 = ((2.0f * fRec4) + (-1.0f - (((fRec2[2] * (((fTemp6 + -0.333333343f) / fTemp5) + 1.0f)) + (2.0f * (fRec2[1] * (1.0f - (1.0f / FaustTrumpetDSP_faustpower2_f(fTemp5)))))) / fTemp7)));
			fRec2[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow1 * ((fTemp0 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1])))) / fTemp7)));
			fVec0[1] = fVec0[0];
			fRec0[1] = fRec0[0];
			iRec1[1] = iRec1[0];
			fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
		}
	}

};

#endif
