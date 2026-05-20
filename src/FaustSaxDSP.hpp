/* ------------------------------------------------------------
name: "sax"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSaxDSP_H__
#define  __FaustSaxDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustSaxDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec4[2];
	
  public:
	
	int getNumInputsFaustSaxDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSaxDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSaxDSPSIG0(int sample_rate) {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec4[l3] = 0;
		}
	}
	
	void fillFaustSaxDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec4[0] = ((iVec1[1] + iRec4[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec4[0])));
			iVec1[1] = iVec1[0];
			iRec4[1] = iRec4[0];
		}
	}

};

static FaustSaxDSPSIG0* newFaustSaxDSPSIG0() { return (FaustSaxDSPSIG0*)new FaustSaxDSPSIG0(); }
static void deleteFaustSaxDSPSIG0(FaustSaxDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustSaxDSPSIG0[65536];
static float FaustSaxDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSaxDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSaxDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec3[2];
	FAUSTFLOAT fHslider3;
	float fRec5[2];
	float fRec1[2];
	float fConst2;
	float fRec0[3];
	float fConst3;
	float fConst4;
	float fRec6[2];
	float fConst5;
	float fConst6;
	int iRec7[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "sax.dsp");
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
		m->declare("name", "sax");
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
		FaustSaxDSPSIG0* sig0 = newFaustSaxDSPSIG0();
		sig0->instanceInitFaustSaxDSPSIG0(sample_rate);
		sig0->fillFaustSaxDSPSIG0(65536, ftbl0FaustSaxDSPSIG0);
		deleteFaustSaxDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (3.14159274f / fConst0);
		fConst3 = std::max<float>(1.0f, (0.0500000007f * fConst0));
		fConst4 = (1.0f / fConst3);
		fConst5 = (0.200000003f / std::max<float>(1.0f, (0.100000001f * fConst0)));
		fConst6 = (1.0f / std::max<float>(1.0f, (0.200000003f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.014999999999999999f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(5.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec7[l8] = 0;
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
	
	virtual FaustSaxDSP* clone() {
		return new FaustSaxDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("sax");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(440.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider2, FAUSTFLOAT(0.0149999997f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider3, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (0.5f * fSlow0);
		float fSlow2 = float(fHslider1);
		float fSlow3 = float(fHslider2);
		float fSlow4 = float(fButton0);
		float fSlow5 = (0.00499999989f * (fSlow0 * fSlow4));
		float fSlow6 = (fConst1 * float(fHslider3));
		float fSlow7 = (1.5f * fSlow2);
		int iSlow8 = (fSlow4 == 0.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow4;
			float fTempFTZ0 = (fSlow5 + (0.995000005f * fRec3[1]));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow6 + (fRec5[1] - std::floor((fSlow6 + fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = std::max<float>(1.1920929e-07f, std::fabs((fSlow2 * ((fSlow3 * (fRec3[0] * ftbl0FaustSaxDSPSIG0[int((65536.0f * fRec5[0]))])) + 1.0f))));
			float fTemp1 = (fRec1[1] + (fConst1 * fTemp0));
			float fTemp2 = (fTemp1 + -1.0f);
			int iTemp3 = (fTemp2 < 0.0f);
			float fTempFTZ2 = (iTemp3 ? fTemp1 : fTemp2);
			fRec1[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fThen1 = (fTemp1 + (fTemp2 * (1.0f - (fConst0 / fTemp0))));
			float fTempFTZ3 = (iTemp3 ? fTemp1 : fThen1);
			float fRec2 = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp4 = std::tan((fConst2 * (fSlow7 + (3500.0f * fRec3[0]))));
			float fTemp5 = (1.0f / fTemp4);
			float fTemp6 = (((fTemp5 + 1.41421354f) / fTemp4) + 1.0f);
			float fTempFTZ4 = ((2.0f * fRec2) + (-1.0f - (((fRec0[2] * (((fTemp5 + -1.41421354f) / fTemp4) + 1.0f)) + (2.0f * (fRec0[1] * (1.0f - (1.0f / FaustSaxDSP_faustpower2_f(fTemp4)))))) / fTemp6)));
			fRec0[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow4 + (fRec6[1] * float((fVec0[1] >= fSlow4))));
			fRec6[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			iRec7[0] = (iSlow8 * (iRec7[1] + 1));
			output0[i0] = FAUSTFLOAT((fSlow1 * (((fRec0[2] + (fRec0[0] + (2.0f * fRec0[1]))) * std::max<float>(0.0f, (std::min<float>((fConst4 * fRec6[0]), std::max<float>(((fConst5 * (fConst3 - fRec6[0])) + 1.0f), 0.800000012f)) * (1.0f - (fConst6 * float(iRec7[0])))))) / fTemp6)));
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec6[1] = fRec6[0];
			iRec7[1] = iRec7[0];
		}
	}

};

#endif
