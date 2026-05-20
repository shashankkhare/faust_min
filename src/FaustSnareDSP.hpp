/* ------------------------------------------------------------
name: "snare"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSnareDSP_H__
#define  __FaustSnareDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustSnareDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec0[2];
	
  public:
	
	int getNumInputsFaustSnareDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSnareDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSnareDSPSIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec0[l1] = 0;
		}
	}
	
	void fillFaustSnareDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec0[0] = ((iVec0[1] + iRec0[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec0[0])));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
		}
	}

};

static FaustSnareDSPSIG0* newFaustSnareDSPSIG0() { return (FaustSnareDSPSIG0*)new FaustSnareDSPSIG0(); }
static void deleteFaustSnareDSPSIG0(FaustSnareDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustSnareDSPSIG0[65536];
static float FaustSnareDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSnareDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSnareDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fRec1[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec2[2];
	float fConst4;
	float fConst12;
	int iRec4[2];
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec3[3];
	float fConst16;
	float fConst17;
	FAUSTFLOAT fHslider3;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "snare.dsp");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "snare");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		FaustSnareDSPSIG0* sig0 = newFaustSnareDSPSIG0();
		sig0->instanceInitFaustSnareDSPSIG0(sample_rate);
		sig0->fillFaustSnareDSPSIG0(65536, ftbl0FaustSnareDSPSIG0);
		deleteFaustSnareDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst3 = (1.0f / fConst2);
		fConst4 = (1.0f / std::max<float>(1.0f, (0.100000001f * fConst0)));
		float fConst5 = std::tan((18849.5566f / fConst0));
		float fConst6 = (fConst0 * fConst5);
		float fConst7 = FaustSnareDSP_faustpower2_f(std::sqrt((4.0f * ((FaustSnareDSP_faustpower2_f(fConst0) * fConst5) * std::tan((6283.18555f / fConst0))))));
		float fConst8 = ((2.0f * fConst6) - (0.5f * (fConst7 / fConst6)));
		float fConst9 = (FaustSnareDSP_faustpower2_f(fConst1) * fConst7);
		float fConst10 = (2.0f * (fConst8 / fConst0));
		float fConst11 = ((fConst9 + fConst10) + 4.0f);
		fConst12 = (2.0f * (fConst8 / (fConst0 * fConst11)));
		fConst13 = (1.0f / fConst11);
		fConst14 = ((2.0f * fConst9) + -8.0f);
		fConst15 = (fConst9 + (4.0f - fConst10));
		fConst16 = (0.0f - fConst12);
		fConst17 = (0.200000003f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.59999999999999998f);
		fHslider2 = FAUSTFLOAT(180.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec2[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec4[l5] = 0;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec3[l6] = 0.0f;
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
	
	virtual FaustSnareDSP* clone() {
		return new FaustSnareDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("snare");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(180.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("wire_rattle", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = ((fSlow0 * float(fHslider1)) * ((0.200000003f * fSlow0) + 1.0f));
		float fSlow2 = (fConst1 * float(fHslider2));
		float fSlow3 = float(fButton0);
		float fSlow4 = ((0.699999988f * fSlow0) + 0.300000012f);
		float fSlow5 = (1.0f / std::max<float>(1.0f, (fConst17 * (float(fHslider3) + 1.0f))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow2 + (fRec1[1] - std::floor((fSlow2 + fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec1[0] = fSlow3;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (fSlow3 <= fVec1[1])) + (fSlow3 > fVec1[1]));
			float fTemp0 = float(iRec2[0]);
			float fTemp1 = (fConst3 * fTemp0);
			float fTemp2 = (fConst2 - fTemp0);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTempFTZ1 = ((4.65661287e-10f * float(iRec4[0])) - (fConst13 * ((fConst14 * fRec3[1]) + (fConst15 * fRec3[2]))));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow1 * ((ftbl0FaustSnareDSPSIG0[int((65536.0f * fRec1[0]))] * std::max<float>(0.0f, std::min<float>(fTemp1, ((fConst4 * fTemp2) + 1.0f)))) + (fSlow4 * (((fConst12 * fRec3[0]) + (fConst16 * fRec3[2])) * std::max<float>(0.0f, std::min<float>(fTemp1, ((fSlow5 * fTemp2) + 1.0f))))))));
			fRec1[1] = fRec1[0];
			fVec1[1] = fVec1[0];
			iRec2[1] = iRec2[0];
			iRec4[1] = iRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
