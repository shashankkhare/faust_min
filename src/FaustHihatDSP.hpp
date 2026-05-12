/* ------------------------------------------------------------
name: "hihat"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustHihatDSP_H__
#define  __FaustHihatDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustHihatDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustHihatDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustHihatDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fConst5;
	int iRec1[2];
	float fConst6;
	float fConst7;
	float fRec0[3];
	float fConst8;
	float fConst9;
	float fConst10;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec2[2];
	FAUSTFLOAT fHslider1;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "hihat.dsp");
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
		m->declare("name", "hihat");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((18849.5566f / fConst0));
		float fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / (((fConst2 + 1.41421354f) / fConst1) + 1.0f));
		float fConst4 = FaustHihatDSP_faustpower2_f(fConst1);
		fConst5 = (1.0f / fConst4);
		fConst6 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst7 = (2.0f * (1.0f - fConst5));
		fConst8 = (0.0f - (2.0f / fConst4));
		fConst9 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst10 = (1.0f / fConst9);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.20000000000000001f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec1[l0] = 0;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec2[l3] = 0;
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
	
	virtual FaustHihatDSP* clone() {
		return new FaustHihatDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("hihat");
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("openness", &fHslider1, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst3 * float(fHslider0));
		float fSlow1 = float(fButton0);
		float fSlow2 = (1.0f / std::max<float>(1.0f, (fConst0 * ((0.400000006f * float(fHslider1)) + 0.0500000007f))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec1[0] = ((1103515245 * iRec1[1]) + 12345);
			fRec0[0] = ((4.65661287e-10f * float(iRec1[0])) - (fConst3 * ((fConst6 * fRec0[2]) + (fConst7 * fRec0[1]))));
			fVec0[0] = fSlow1;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (fSlow1 <= fVec0[1])) + (fSlow1 > fVec0[1]));
			float fTemp0 = float(iRec2[0]);
			output0[i0] = FAUSTFLOAT((fSlow0 * ((((fConst5 * fRec0[0]) + (fConst8 * fRec0[1])) + (fConst5 * fRec0[2])) * std::max<float>(0.0f, std::min<float>((fConst10 * fTemp0), ((fSlow2 * (fConst9 - fTemp0)) + 1.0f))))));
			iRec1[1] = iRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			iRec2[1] = iRec2[0];
		}
	}

};

#endif
