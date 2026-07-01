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
	
	int fSampleRate;
	float fConst4;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	float fConst7;
	int iRec3[2];
	float fConst8;
	float fConst9;
	float fRec2[3];
	float fConst10;
	float fConst11;
	int iRec4[2];
	float fConst12;
	float fConst13;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fCheckbox0;
	float fRec1[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec0[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
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
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
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
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "dagu");
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
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((2513.27417f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 1.41421354f) / fConst1) + 1.0f);
		fConst4 = (0.600000024f / fConst3);
		float fConst5 = std::tan((942.477783f / fConst0));
		float fConst6 = (1.0f / fConst5);
		fConst7 = (1.0f / (((fConst6 + 1.41421354f) / fConst5) + 1.0f));
		fConst8 = (((fConst6 + -1.41421354f) / fConst5) + 1.0f);
		fConst9 = (2.0f * (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fConst5))));
		fConst10 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst11 = (1.0f / fConst10);
		fConst12 = (1.0f / std::max<float>(1.0f, (0.0199999996f * fConst0)));
		fConst13 = (3.14159274f / fConst0);
		fConst14 = (1.0f / fConst3);
		fConst15 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst16 = (2.0f * (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fConst1))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(55.0f);
		fCheckbox0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec3[l2] = 0;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec4[l4] = 0;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec0[l9] = 0.0f;
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
		ui_interface->addCheckButton("Skin Type: Cowhide (Checked) / Oxhide (Unchecked)", &fCheckbox0);
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(55.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst4 * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fButton0);
		float fSlow3 = (fConst13 * float(fHslider2));
		float fSlow4 = std::tan(fSlow3);
		float fSlow5 = (1.0f / fSlow4);
		int iSlow6 = int(float(fCheckbox0));
		float fSlow7 = (iSlow6 ? 0.5f : 1.29999995f);
		float fSlow8 = (0.0399999991f / fSlow7);
		float fSlow9 = ((fSlow5 * (fSlow5 - fSlow8)) + 1.0f);
		float fSlow10 = (2.0f * (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fSlow4))));
		float fSlow11 = ((fSlow5 * (fSlow5 + fSlow8)) + 1.0f);
		float fSlow12 = std::tan((fSlow3 * (iSlow6 ? 1.59000003f : 1.63f)));
		float fSlow13 = (1.0f / fSlow12);
		float fSlow14 = (0.055555556f / fSlow7);
		float fSlow15 = (((fSlow13 - fSlow14) / fSlow12) + 1.0f);
		float fSlow16 = (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fSlow12)));
		float fSlow17 = (((fSlow14 + fSlow13) / fSlow12) + 1.0f);
		float fSlow18 = std::tan((fSlow3 * (iSlow6 ? 2.1400001f : 2.29999995f)));
		float fSlow19 = (1.0f / fSlow18);
		float fSlow20 = (0.0833333358f / fSlow7);
		float fSlow21 = (((fSlow19 - fSlow20) / fSlow18) + 1.0f);
		float fSlow22 = (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fSlow18)));
		float fSlow23 = (((fSlow20 + fSlow19) / fSlow18) + 1.0f);
		float fSlow24 = std::tan((fSlow3 * (iSlow6 ? 3.5999999f : 3.8499999f)));
		float fSlow25 = (1.0f / fSlow24);
		float fSlow26 = (0.166666672f / fSlow7);
		float fSlow27 = (((fSlow25 - fSlow26) / fSlow24) + 1.0f);
		float fSlow28 = (1.0f - (1.0f / FaustDaguDSP_faustpower2_f(fSlow24)));
		float fSlow29 = (((fSlow26 + fSlow25) / fSlow24) + 1.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow2;
			int iTemp0 = (fSlow2 > fVec0[1]);
			iVec1[0] = iTemp0;
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			float fTempFTZ0 = ((4.65661287e-10f * float(iRec3[0])) - (fConst7 * ((fConst8 * fRec2[2]) + (fConst9 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec4[0] = (((iRec4[1] + (iRec4[1] > 0)) * (iTemp0 <= iVec1[1])) + (iTemp0 > iVec1[1]));
			float fTemp1 = float(iRec4[0]);
			float fTemp2 = (fSlow1 * (float(iTemp0) + (fConst7 * ((fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))) * std::max<float>(0.0f, std::min<float>((fConst11 * fTemp1), ((fConst12 * (fConst10 - fTemp1)) + 1.0f)))))));
			float fTempFTZ1 = (fTemp2 - (((fRec1[2] * fSlow9) + (fSlow10 * fRec1[1])) / fSlow11));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp2 - (((fRec5[2] * fSlow15) + (2.0f * (fRec5[1] * fSlow16))) / fSlow17));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp2 - (((fRec6[2] * fSlow21) + (2.0f * (fRec6[1] * fSlow22))) / fSlow23));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp2 - (((fRec7[2] * fSlow27) + (2.0f * (fRec7[1] * fSlow28))) / fSlow29));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp3 = std::max<float>(-1.0f, std::min<float>(1.0f, (6.33957291f * (((((fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))) / fSlow11) + (((fRec5[1] + (0.5f * fRec5[0])) + (0.5f * fRec5[2])) / fSlow17)) + ((((0.25f * fRec6[0]) + (0.5f * fRec6[1])) + (0.25f * fRec6[2])) / fSlow23)) + ((((0.100000001f * fRec7[0]) + (0.200000003f * fRec7[1])) + (0.100000001f * fRec7[2])) / fSlow29)))));
			float fTempFTZ5 = ((fTemp3 * (1.0f - (0.333333343f * FaustDaguDSP_faustpower2_f(fTemp3)))) - (fConst14 * ((fConst15 * fRec0[2]) + (fConst16 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fRec0[2] + (fRec0[0] + (2.0f * fRec0[1])))));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec3[1] = iRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			iRec4[1] = iRec4[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
