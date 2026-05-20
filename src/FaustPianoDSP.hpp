/* ------------------------------------------------------------
name: "piano"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustPianoDSP_H__
#define  __FaustPianoDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustPianoDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustPianoDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fVec0[2];
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fVec2[2];
	float fRec2[2];
	int IOTA;
	float fRec0[8192];
	float fConst2;
	float fVec3[2];
	float fRec5[2];
	float fRec4[8192];
	float fConst3;
	float fVec4[2];
	float fRec7[2];
	float fRec6[8192];
	float fConst5;
	float fConst6;
	float fRec8[2];
	float fRec3[512];
	float fConst7;
	float fConst8;
	float fRec9[2];
	float fConst9;
	FAUSTFLOAT fHslider5;
	float fConst10;
	int iRec10[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "piano.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "piano");
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
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (0.999400377f * fConst0);
		fConst3 = (1.00060034f * fConst0);
		float fConst4 = (1.0f / std::tan((3769.91113f / fConst0)));
		fConst5 = (1.0f / (fConst4 + 1.0f));
		fConst6 = (1.0f - fConst4);
		fConst7 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst8 = (1.0f / fConst7);
		fConst9 = (1.0f / std::max<float>(1.0f, (0.100000001f * fConst0)));
		fConst10 = (1.0f / std::max<float>(1.0f, fConst0));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.10000000000000001f);
		fHslider2 = FAUSTFLOAT(440.0f);
		fHslider3 = FAUSTFLOAT(0.80000000000000004f);
		fHslider4 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.80000000000000004f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 8192); l5 = (l5 + 1)) {
			fRec0[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec3[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 8192); l8 = (l8 + 1)) {
			fRec4[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 8192); l11 = (l11 + 1)) {
			fRec6[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 512); l13 = (l13 + 1)) {
			fRec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec9[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			iRec10[l15] = 0;
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
	
	virtual FaustPianoDSP* clone() {
		return new FaustPianoDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("piano");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(4000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("hardness", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stiffness", &fHslider1, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider5, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (30.0f * float(fHslider0));
		float fSlow1 = (1.0f / std::tan((fConst1 * (4000.0f - (1000.0f * float(fHslider1))))));
		float fSlow2 = (1.0f / (fSlow1 + 1.0f));
		float fSlow3 = (1.0f - fSlow1);
		float fSlow4 = float(fHslider2);
		float fSlow5 = (fConst0 / fSlow4);
		float fSlow6 = std::floor(fSlow5);
		float fSlow7 = (fSlow6 + (1.0f - fSlow5));
		int iSlow8 = int(fSlow5);
		int iSlow9 = (std::min<int>(4097, std::max<int>(0, iSlow8)) + 1);
		float fSlow10 = (fSlow5 - fSlow6);
		int iSlow11 = (std::min<int>(4097, std::max<int>(0, (iSlow8 + 1))) + 1);
		float fSlow12 = float(fHslider3);
		float fSlow13 = (1.0f / std::tan((fConst1 * ((8000.0f * (fSlow12 * float(fHslider4))) + 2000.0f))));
		float fSlow14 = (1.0f / (fSlow13 + 1.0f));
		float fSlow15 = (1.0f - fSlow13);
		float fSlow16 = float(fButton0);
		float fSlow17 = (fConst2 / fSlow4);
		float fSlow18 = std::floor(fSlow17);
		float fSlow19 = (fSlow18 + (1.0f - fSlow17));
		int iSlow20 = int(fSlow17);
		int iSlow21 = (std::min<int>(4097, std::max<int>(0, iSlow20)) + 1);
		float fSlow22 = (fSlow17 - fSlow18);
		int iSlow23 = (std::min<int>(4097, std::max<int>(0, (iSlow20 + 1))) + 1);
		float fSlow24 = (fConst3 / fSlow4);
		float fSlow25 = std::floor(fSlow24);
		float fSlow26 = (fSlow25 + (1.0f - fSlow24));
		int iSlow27 = int(fSlow24);
		int iSlow28 = (std::min<int>(4097, std::max<int>(0, iSlow27)) + 1);
		float fSlow29 = (fSlow24 - fSlow25);
		int iSlow30 = (std::min<int>(4097, std::max<int>(0, (iSlow27 + 1))) + 1);
		float fSlow31 = float(fHslider5);
		float fSlow32 = (fConst9 * (1.0f - fSlow31));
		int iSlow33 = (fSlow16 == 0.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTemp0 = ((fSlow7 * fRec0[((IOTA - iSlow9) & 8191)]) + (fSlow10 * fRec0[((IOTA - iSlow11) & 8191)]));
			fVec0[0] = fTemp0;
			fRec1[0] = (0.0f - (fSlow2 * ((fSlow3 * fRec1[1]) - (fTemp0 + fVec0[1]))));
			fVec1[0] = fSlow16;
			float fTemp1 = (fSlow16 - fVec1[1]);
			float fTemp2 = (fTemp1 * float((fTemp1 > 0.0f)));
			fVec2[0] = fTemp2;
			fRec2[0] = (0.0f - (fSlow14 * ((fSlow15 * fRec2[1]) - (fTemp2 + fVec2[1]))));
			float fTemp3 = (fSlow12 * fRec2[0]);
			fRec0[(IOTA & 8191)] = ((0.99000001f * fRec1[0]) + fTemp3);
			float fTemp4 = (0.400000006f * fRec0[((IOTA - 0) & 8191)]);
			float fTemp5 = ((fSlow19 * fRec4[((IOTA - iSlow21) & 8191)]) + (fSlow22 * fRec4[((IOTA - iSlow23) & 8191)]));
			fVec3[0] = fTemp5;
			fRec5[0] = (0.0f - (fSlow2 * ((fSlow3 * fRec5[1]) - (fTemp5 + fVec3[1]))));
			fRec4[(IOTA & 8191)] = (fTemp3 + (0.99000001f * fRec5[0]));
			float fTemp6 = ((fSlow26 * fRec6[((IOTA - iSlow28) & 8191)]) + (fSlow29 * fRec6[((IOTA - iSlow30) & 8191)]));
			fVec4[0] = fTemp6;
			fRec7[0] = (0.0f - (fSlow2 * ((fSlow3 * fRec7[1]) - (fTemp6 + fVec4[1]))));
			fRec6[(IOTA & 8191)] = (fTemp3 + (0.99000001f * fRec7[0]));
			float fTemp7 = (fRec4[((IOTA - 0) & 8191)] + fRec6[((IOTA - 0) & 8191)]);
			fRec8[0] = (0.0f - (fConst5 * ((fConst6 * fRec8[1]) - (fRec3[((IOTA - 257) & 511)] + fRec3[((IOTA - 258) & 511)]))));
			fRec3[(IOTA & 511)] = ((0.300000012f * fTemp7) + (fTemp4 + (0.25f * fRec8[0])));
			fRec9[0] = (fSlow16 + (fRec9[1] * float((fVec1[1] >= fSlow16))));
			iRec10[0] = (iSlow33 * (iRec10[1] + 1));
			output0[i0] = FAUSTFLOAT((fSlow0 * ((fTemp4 + (0.300000012f * (fRec3[((IOTA - 0) & 511)] + fTemp7))) * std::max<float>(0.0f, (std::min<float>((fConst8 * fRec9[0]), std::max<float>(((fSlow32 * (fConst7 - fRec9[0])) + 1.0f), fSlow31)) * (1.0f - (fConst10 * float(iRec10[0]))))))));
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fVec1[1] = fVec1[0];
			fVec2[1] = fVec2[0];
			fRec2[1] = fRec2[0];
			IOTA = (IOTA + 1);
			fVec3[1] = fVec3[0];
			fRec5[1] = fRec5[0];
			fVec4[1] = fVec4[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			iRec10[1] = iRec10[0];
		}
	}

};

#endif
