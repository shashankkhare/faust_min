/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "ghatam"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustGhatamDSP_H__
#define  __FaustGhatamDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustGhatamDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustGhatamDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustGhatamDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fConst3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec1[3];
	float fRec0[3];
	float fConst4;
	float fRec2[3];
	float fConst5;
	float fRec3[3];
	float fConst6;
	float fRec4[3];
	float fConst7;
	float fRec5[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "ghatam.dsp");
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
		m->declare("name", "ghatam");
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
		fConst1 = (1.0f / fConst0);
		fConst2 = (21.488493f / fConst0);
		fConst3 = (3.14159274f / fConst0);
		fConst4 = (32.2955742f / fConst0);
		fConst5 = (42.7884903f / fConst0);
		fConst6 = (54.3495522f / fConst0);
		fConst7 = (6.28318548f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(130.81f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
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
	
	virtual FaustGhatamDSP* clone() {
		return new FaustGhatamDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ghatam");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(130.809998f), FAUSTFLOAT(100.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("slap_force", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = ((0.400000006f * fSlow1) + 0.800000012f);
		float fSlow3 = float(fHslider2);
		int iSlow4 = (fSlow3 >= 3.0f);
		int iSlow5 = (fSlow3 >= 2.0f);
		int iSlow6 = (fSlow3 >= 1.0f);
		float fThen1 = (iSlow6 ? 0.600000024f : 0.400000006f);
		int iSlow7 = (fSlow3 >= 4.0f);
		float fThen3 = (iSlow5 ? 0.200000003f : fThen1);
		float fElse3 = (iSlow7 ? 0.100000001f : 0.800000012f);
		float fSlow8 = (iSlow4 ? fElse3 : fThen3);
		float fSlow9 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, fSlow8)));
		float fSlow10 = float(fHslider3);
		float fSlow11 = (2.0f * std::cos((fConst2 * fSlow10)));
		float fSlow12 = std::tan((fConst3 * (fSlow10 + (10000.0f * std::pow(float(fHslider4), 2.0f)))));
		float fSlow13 = (1.0f / fSlow12);
		float fSlow14 = (((fSlow13 + 1.41421354f) / fSlow12) + 1.0f);
		float fSlow15 = (0.00200000009f * (fSlow1 / fSlow14));
		float fSlow16 = float(fButton0);
		float fSlow17 = (1.0f / fSlow14);
		float fSlow18 = (((fSlow13 + -1.41421354f) / fSlow12) + 1.0f);
		float fSlow19 = (2.0f * (1.0f - (1.0f / FaustGhatamDSP_faustpower2_f(fSlow12))));
		float fThen5 = (iSlow6 ? 1.20000005f : 0.800000012f);
		float fThen7 = (iSlow5 ? 0.200000003f : fThen5);
		float fElse7 = (iSlow7 ? 0.400000006f : 1.5f);
		float fSlow20 = (iSlow4 ? fElse7 : fThen7);
		float fSlow21 = (0.600000024f * (fSlow1 + 1.0f));
		float fSlow22 = (2.0f * std::cos((fConst4 * fSlow10)));
		float fThen9 = (iSlow6 ? 1.0f : 0.600000024f);
		float fThen11 = (iSlow5 ? 0.100000001f : fThen9);
		float fElse11 = (iSlow7 ? 0.200000003f : 1.20000005f);
		float fSlow23 = (iSlow4 ? fElse11 : fThen11);
		float fSlow24 = (0.800000012f * fSlow1);
		float fSlow25 = (fSlow24 + 0.400000006f);
		float fSlow26 = (2.0f * std::cos((fConst5 * fSlow10)));
		float fThen13 = (iSlow6 ? 0.800000012f : 0.5f);
		float fThen15 = (iSlow5 ? 0.0f : fThen13);
		float fElse15 = (iSlow7 ? 0.100000001f : 1.0f);
		float fSlow27 = (iSlow4 ? fElse15 : fThen15);
		float fSlow28 = (fSlow24 + 0.300000012f);
		float fSlow29 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.800000012f * fSlow8))));
		float fSlow30 = (2.0f * std::cos((fConst6 * fSlow10)));
		float fThen17 = (iSlow6 ? 0.600000024f : 0.300000012f);
		float fThen19 = (iSlow5 ? 0.0f : fThen17);
		float fElse19 = (iSlow7 ? 0.0f : 0.800000012f);
		float fSlow31 = (iSlow4 ? fElse19 : fThen19);
		float fSlow32 = (1.20000005f - (0.200000003f * fSlow1));
		float fThen21 = (iSlow6 ? 0.00999999978f : 0.349999994f);
		float fThen23 = (iSlow5 ? 0.300000012f : fThen21);
		float fElse23 = (iSlow7 ? 0.25f : 0.00499999989f);
		float fSlow33 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (iSlow4 ? fElse23 : fThen23))));
		float fElse25 = (iSlow7 ? 0.800000012f : 1.0f);
		float fSlow34 = std::cos(((fConst7 * fSlow10) * (iSlow4 ? fElse25 : 1.0f)));
		float fThen27 = (iSlow6 ? 0.0500000007f : 0.5f);
		float fThen29 = (iSlow5 ? 0.800000012f : fThen27);
		float fElse29 = (iSlow7 ? 0.800000012f : 0.0f);
		float fSlow35 = (iSlow4 ? fElse29 : fThen29);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow16;
			float fTemp0 = (fSlow16 - fVec0[1]);
			float fTempFTZ0 = ((fTemp0 * float((fTemp0 > 0.0f))) - (fSlow17 * ((fSlow18 * fRec1[2]) + (fSlow19 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp1 = (fSlow15 * (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))));
			float fTempFTZ1 = ((fSlow9 * ((fSlow11 * fRec0[1]) - (fSlow9 * fRec0[2]))) + fTemp1);
			fRec0[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp1 + (fSlow9 * ((fSlow22 * fRec2[1]) - (fSlow9 * fRec2[2]))));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 + (fSlow9 * ((fSlow26 * fRec3[1]) - (fSlow9 * fRec3[2]))));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 + (fSlow29 * ((fSlow30 * fRec4[1]) - (fSlow29 * fRec4[2]))));
			fRec4[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 + (fSlow33 * ((2.0f * (fSlow34 * fRec5[1])) - (fSlow33 * fRec5[2]))));
			fRec5[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((15.0f * (((((fSlow2 * (fRec0[0] * fSlow20)) + (fSlow21 * (fRec2[0] * fSlow23))) + (fSlow25 * (fRec3[0] * fSlow27))) + (fSlow28 * (fRec4[0] * fSlow31))) + (fSlow32 * (fRec5[0] * fSlow35)))))))));
			fVec0[1] = fVec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
		}
	}

};

#endif
