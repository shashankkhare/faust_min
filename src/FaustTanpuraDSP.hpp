/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tanpura"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTanpuraDSP_H__
#define  __FaustTanpuraDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustTanpuraDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTanpuraDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTanpuraDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst2;
	FAUSTFLOAT fHslider4;
	float fConst3;
	float fRec2[2];
	float fRec3[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	int iRec5[2];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	float fRec7[2];
	int iVec2[2];
	int iRec6[2];
	float fConst4;
	float fConst5;
	float fRec4[3];
	int IOTA;
	float fRec1[16384];
	float fVec3[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "tanpura.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "tanpura");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.0f / fConst0);
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = (0.5f * fConst0);
		fConst5 = (9.42477798f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(35.0f);
		fHslider3 = FAUSTFLOAT(0.070000000000000007f);
		fHslider4 = FAUSTFLOAT(130.81f);
		fHslider5 = FAUSTFLOAT(0.014999999999999999f);
		fHslider6 = FAUSTFLOAT(0.55000000000000004f);
		fHslider7 = FAUSTFLOAT(0.80000000000000004f);
		fHslider8 = FAUSTFLOAT(0.40000000000000002f);
		fHslider9 = FAUSTFLOAT(0.0115f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec5[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec1[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec7[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iVec2[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec6[l7] = 0;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec4[l8] = 0.0f;
		}
		IOTA = 0;
		for (int l9 = 0; (l9 < 16384); l9 = (l9 + 1)) {
			fRec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec0[l11] = 0.0f;
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
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("dispersion", &fHslider3, FAUSTFLOAT(0.0700000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excDur", &fHslider9, FAUSTFLOAT(0.0115f), FAUSTFLOAT(9.99999975e-05f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excGain", &fHslider8, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(130.809998f), FAUSTFLOAT(130.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider6, FAUSTFLOAT(0.550000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("jivariThreshold", &fHslider5, FAUSTFLOAT(0.0149999997f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("stringGainVal", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider2, FAUSTFLOAT(35.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider7, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (135.242996f * (float(fHslider0) * float(fHslider1)));
		float fSlow1 = std::exp((0.0f - (fConst1 / std::max<float>(0.00100000005f, float(fHslider2)))));
		float fSlow2 = float(fHslider3);
		float fSlow3 = std::sin(fSlow2);
		float fSlow4 = float(fHslider4);
		float fSlow5 = (fConst2 * fSlow4);
		float fSlow6 = std::cos(fSlow2);
		float fSlow7 = float(fHslider5);
		float fSlow8 = (fSlow2 * (float(fHslider6) + 1.0f));
		float fSlow9 = (1.39698392e-10f * ((fSlow4 * float(fHslider7)) * float(fHslider8)));
		float fSlow10 = float(fHslider9);
		float fSlow11 = (fConst0 * fSlow10);
		float fSlow12 = std::max<float>(1.0f, fSlow11);
		float fSlow13 = (1.0f / fSlow12);
		float fSlow14 = float(fButton0);
		float fSlow15 = (1.0f / std::max<float>(1.0f, (fConst4 * fSlow10)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow5 + (fConst3 * fRec2[1]));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = std::max<float>(20.0f, fRec2[0]);
			float fTemp1 = (fConst0 / fTemp0);
			float fTemp2 = (fTemp1 + -2.0f);
			int iTemp3 = int(fTemp2);
			float fTemp4 = std::floor(fTemp2);
			float fTemp5 = ((fRec1[((IOTA - (std::min<int>(8193, std::max<int>(0, iTemp3)) + 1)) & 16383)] * (fTemp4 + (3.0f - fTemp1))) + ((fTemp1 + (-2.0f - fTemp4)) * fRec1[((IOTA - (std::min<int>(8193, std::max<int>(0, (iTemp3 + 1))) + 1)) & 16383)]));
			float fTempFTZ1 = ((fSlow6 * fTemp5) - (fSlow3 * fRec3[1]));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp6 = ((fSlow3 * fTemp5) + (fSlow6 * fRec3[1]));
			float fElse0 = (fSlow7 - (fSlow8 * (fTemp6 - fSlow7)));
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			fVec0[0] = fSlow14;
			int iTemp7 = ((fSlow14 - fVec0[1]) > 0.0f);
			iVec1[0] = iTemp7;
			float fThen1 = std::max<float>(0.0f, (fRec7[1] + -1.0f));
			float fTempFTZ2 = ((float((float((iTemp7 - iVec1[1])) > 0.0f)) > 0.0f) ? fSlow11 : fThen1);
			fRec7[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			int iTemp8 = (fRec7[0] > 0.0f);
			iVec2[0] = iTemp8;
			iRec6[0] = (((iRec6[1] + (iRec6[1] > 0)) * (iTemp8 <= iVec2[1])) + (iTemp8 > iVec2[1]));
			float fTemp9 = float(iRec6[0]);
			float fTemp10 = std::tan((fConst5 * fRec2[0]));
			float fTemp11 = (1.0f / fTemp10);
			float fTemp12 = (((fTemp11 + 1.41421354f) / fTemp10) + 1.0f);
			float fTempFTZ3 = ((fSlow9 * ((float(iRec5[0]) * std::max<float>(0.0f, std::min<float>((fSlow13 * fTemp9), ((fSlow15 * (fSlow12 - fTemp9)) + 1.0f)))) / fTemp0)) - (((fRec4[2] * (((fTemp11 + -1.41421354f) / fTemp10) + 1.0f)) + (2.0f * (fRec4[1] * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fTemp10)))))) / fTemp12));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((fSlow1 * std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fTemp6 > fSlow7) ? fElse0 : fTemp6)))) + ((fRec4[2] + (fRec4[0] + (2.0f * fRec4[1]))) / fTemp12));
			fRec1[(IOTA & 16383)] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp13 = (fSlow0 * fRec1[((IOTA - 0) & 16383)]);
			fVec3[0] = fTemp13;
			float fTempFTZ5 = (((0.995000005f * fRec0[1]) + fTemp13) - fVec3[1]);
			fRec0[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] / (std::fabs(fRec0[0]) + 1.0f)));
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			iRec5[1] = iRec5[0];
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec7[1] = fRec7[0];
			iVec2[1] = iVec2[0];
			iRec6[1] = iRec6[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			IOTA = (IOTA + 1);
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
