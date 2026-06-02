/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "dagu"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustDaguDSP_H__
#define  __FaustDaguDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustDaguDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustDaguDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustDaguDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	int iRec1[2];
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iVec2[2];
	int iRec2[2];
	float fConst3;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider2;
	float fConst6;
	float fRec3[2];
	float fRec0[3];
	float fConst7;
	float fRec4[3];
	float fConst8;
	float fRec5[3];
	float fConst9;
	float fRec6[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "dagu.dsp");
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
		m->declare("name", "dagu");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / std::max<float>(1.0f, (0.0500000007f * fConst0)));
		fConst4 = (11.9380522f / fConst0);
		fConst5 = (44.0999985f / fConst0);
		fConst6 = (1.0f - fConst5);
		fConst7 = (7.22566319f / fConst0);
		fConst8 = (5.02654839f / fConst0);
		fConst9 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(55.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iVec2[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec2[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec4[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec5[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec6[l9] = 0.0f;
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
	
	virtual FaustDaguDSP* clone() {
		return new FaustDaguDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("dagu");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(55.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.800000012f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fButton0);
		float fSlow3 = (fConst5 * float(fHslider2));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			iRec1[0] = ((1103515245 * iRec1[1]) + 12345);
			fVec1[0] = fSlow2;
			int iTemp0 = (fSlow2 > fVec1[1]);
			iVec2[0] = iTemp0;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (iTemp0 <= iVec2[1])) + (iTemp0 > iVec2[1]));
			float fTemp1 = float(iRec2[0]);
			float fTemp2 = (fSlow1 * (float((1 - iVec0[1])) + (2.32830644e-10f * (float(iRec1[0]) * std::max<float>(0.0f, std::min<float>((fConst2 * fTemp1), ((fConst3 * (fConst1 - fTemp1)) + 1.0f)))))));
			float fTempFTZ0 = (fSlow3 + (fConst6 * fRec3[1]));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp3 = std::tan((fConst4 * fRec3[0]));
			float fTemp4 = (1.0f / fTemp3);
			float fTemp5 = (((fTemp4 + 0.100000001f) / fTemp3) + 1.0f);
			float fTempFTZ1 = (fTemp2 - (((fRec0[2] * (((fTemp4 + -0.100000001f) / fTemp3) + 1.0f)) + (2.0f * (fRec0[1] * (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fTemp3)))))) / fTemp5));
			fRec0[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp6 = (fTemp3 * fTemp5);
			float fTemp7 = std::tan((fConst7 * fRec3[0]));
			float fTemp8 = (1.0f / fTemp7);
			float fTemp9 = (((fTemp8 + 0.0666666701f) / fTemp7) + 1.0f);
			float fTempFTZ2 = (fTemp2 - (((fRec4[2] * (((fTemp8 + -0.0666666701f) / fTemp7) + 1.0f)) + (2.0f * (fRec4[1] * (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fTemp7)))))) / fTemp9));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp10 = (fTemp7 * fTemp9);
			float fTemp11 = std::tan((fConst8 * fRec3[0]));
			float fTemp12 = (1.0f / fTemp11);
			float fTemp13 = (((fTemp12 + 0.0833333358f) / fTemp11) + 1.0f);
			float fTempFTZ3 = (fTemp2 - (((fRec5[2] * (((fTemp12 + -0.0833333358f) / fTemp11) + 1.0f)) + (2.0f * (fRec5[1] * (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fTemp11)))))) / fTemp13));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp14 = (fTemp11 * fTemp13);
			float fTemp15 = std::tan((fConst9 * fRec3[0]));
			float fTemp16 = (1.0f / fTemp15);
			float fTemp17 = (((fTemp16 + 0.125f) / fTemp15) + 1.0f);
			float fTempFTZ4 = (fTemp2 - (((fRec6[2] * (((fTemp16 + -0.125f) / fTemp15) + 1.0f)) + (2.0f * (fRec6[1] * (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fTemp15)))))) / fTemp17));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp18 = (fTemp15 * fTemp17);
			output0[i0] = FAUSTFLOAT(std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow0 * float(tanhf(float((1.5f * ((fRec0[2] * (0.0f - (0.100000001f / fTemp6))) + (((fRec4[2] * (0.0f - (0.300000012f / fTemp10))) + (((fRec5[2] * (0.0f - (0.600000024f / fTemp14))) + (((fRec6[0] / fTemp18) + (fRec6[2] * (0.0f - (1.0f / fTemp18)))) + (0.600000024f * (fRec5[0] / fTemp14)))) + (0.300000012f * (fRec4[0] / fTemp10)))) + (0.100000001f * (fRec0[0] / fTemp6))))))))))));
			iVec0[1] = iVec0[0];
			iRec1[1] = iRec1[0];
			fVec1[1] = fVec1[0];
			iVec2[1] = iVec2[0];
			iRec2[1] = iRec2[0];
			fRec3[1] = fRec3[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
