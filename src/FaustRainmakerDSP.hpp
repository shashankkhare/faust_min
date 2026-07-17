/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "rainmaker"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustRainmakerDSP_H__
#define  __FaustRainmakerDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustRainmakerDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec2[2];
	
  public:
	
	int getNumInputsFaustRainmakerDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustRainmakerDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustRainmakerDSPSIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec2[l1] = 0;
		}
	}
	
	void fillFaustRainmakerDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec2[0] = ((iVec0[1] + iRec2[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec2[0])));
			iVec0[1] = iVec0[0];
			iRec2[1] = iRec2[0];
		}
	}

};

static FaustRainmakerDSPSIG0* newFaustRainmakerDSPSIG0() { return (FaustRainmakerDSPSIG0*)new FaustRainmakerDSPSIG0(); }
static void deleteFaustRainmakerDSPSIG0(FaustRainmakerDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustRainmakerDSPSIG0[65536];
static float FaustRainmakerDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustRainmakerDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustRainmakerDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	int iRec4[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider3;
	float fConst4;
	float fRec5[2];
	float fRec0[3];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec6[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	int iRec7[2];
	
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
		m->declare("filename", "rainmaker.dsp");
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
		m->declare("name", "rainmaker");
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
		FaustRainmakerDSPSIG0* sig0 = newFaustRainmakerDSPSIG0();
		sig0->instanceInitFaustRainmakerDSPSIG0(sample_rate);
		sig0->fillFaustRainmakerDSPSIG0(65536, ftbl0FaustRainmakerDSPSIG0);
		deleteFaustRainmakerDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (3.14159274f / fConst0);
		fConst3 = (44.0999985f / fConst0);
		fConst4 = (1.0f - fConst3);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.050000000000000003f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(220.0f);
		fHslider4 = FAUSTFLOAT(2.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.80000000000000004f);
		fHslider6 = FAUSTFLOAT(2.0f);
		fHslider7 = FAUSTFLOAT(2.0f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec4[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec7[l9] = 0;
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
	
	virtual FaustRainmakerDSP* clone() {
		return new FaustRainmakerDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("rainmaker");
		ui_interface->addHorizontalSlider("Instrument_Material", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("Tilt_Speed_Hz", &fHslider1, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("attack", &fHslider4, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("decay", &fHslider6, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(220.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("release", &fHslider7, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider5, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (3.0f * float(fHslider0));
		float fSlow1 = (fConst1 * float(fHslider1));
		float fSlow2 = float(((float(fHslider2) == 0.0f) ? 150 : 45));
		float fSlow3 = (fConst3 * float(fHslider3));
		float fSlow4 = std::max<float>(1.0f, (fConst0 * float(fHslider4)));
		float fSlow5 = (1.0f / fSlow4);
		float fSlow6 = float(fButton0);
		float fSlow7 = float(fHslider5);
		float fSlow8 = ((1.0f - fSlow7) / std::max<float>(1.0f, (fConst0 * float(fHslider6))));
		float fSlow9 = (1.0f / std::max<float>(1.0f, (fConst0 * float(fHslider7))));
		int iSlow10 = (fSlow6 == 0.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow1 + (fRec3[1] - std::floor((fSlow1 + fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((0.999000013f * fRec1[1]) + (0.00100000005f * std::fabs(ftbl0FaustRainmakerDSPSIG0[int((65536.0f * fRec3[0]))])));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTempFTZ2 = (fSlow3 + (fConst4 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp0 = std::tan((fConst2 * fRec5[0]));
			float fTemp1 = (1.0f / fTemp0);
			float fTemp2 = (((fTemp1 + 0.5f) / fTemp0) + 1.0f);
			float fTempFTZ3 = ((1.55220433e-12f * ((fRec1[0] * fSlow2) * float(iRec4[0]))) - (((fRec0[2] * (((fTemp1 + -0.5f) / fTemp0) + 1.0f)) + (2.0f * (fRec0[1] * (1.0f - (1.0f / FaustRainmakerDSP_faustpower2_f(fTemp0)))))) / fTemp2));
			fRec0[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp3 = (fTemp0 * fTemp2);
			fVec1[0] = fSlow6;
			float fTempFTZ4 = (fSlow6 + (fRec6[1] * float((fVec1[1] >= fSlow6))));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			iRec7[0] = (iSlow10 * (iRec7[1] + 1));
			output0[i0] = FAUSTFLOAT((fSlow0 * (((fRec0[0] / fTemp3) + (fRec0[2] * (0.0f - (1.0f / fTemp3)))) * std::max<float>(0.0f, (std::min<float>((fSlow5 * fRec6[0]), std::max<float>(((fSlow8 * (fSlow4 - fRec6[0])) + 1.0f), fSlow7)) * (1.0f - (fSlow9 * float(iRec7[0]))))))));
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			iRec4[1] = iRec4[0];
			fRec5[1] = fRec5[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fVec1[1] = fVec1[0];
			fRec6[1] = fRec6[0];
			iRec7[1] = iRec7[0];
		}
	}

};

#endif
