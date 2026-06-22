/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "santoor"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSantoorDSP_H__
#define  __FaustSantoorDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSantoorDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSantoorDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	int iRec2[2];
	float fConst1;
	float fConst2;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iVec2[2];
	int iRec3[2];
	float fConst3;
	int IOTA;
	float fVec3[2048];
	float fRec0[2];
	float fConst4;
	float fRec5[2];
	float fVec4[2048];
	float fRec4[2];
	float fConst5;
	float fRec7[2];
	float fVec5[2048];
	float fRec6[2];
	
 public:
	
	void metadata(Meta* m) { 
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
		m->declare("filename", "santoor.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "santoor");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / std::max<float>(1.0f, (0.00999999978f * fConst0)));
		fConst4 = (0.998004019f * fConst0);
		fConst5 = (1.00200403f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec3[l5] = 0;
		}
		IOTA = 0;
		for (int l6 = 0; (l6 < 2048); l6 = (l6 + 1)) {
			fVec3[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec0[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec5[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2048); l9 = (l9 + 1)) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec4[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fVec5[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec6[l13] = 0.0f;
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
	
	virtual FaustSantoorDSP* clone() {
		return new FaustSantoorDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("santoor");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(440.0f), FAUSTFLOAT(130.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fConst0 / fSlow1);
		int iSlow3 = int((fSlow2 + -1.0f));
		float fSlow4 = float(iSlow3);
		float fSlow5 = (fSlow4 + (2.0f - fSlow2));
		float fSlow6 = float(fHslider2);
		float fSlow7 = float(fButton0);
		int iSlow8 = std::min<int>(4096, std::max<int>(0, iSlow3));
		float fSlow9 = (fSlow2 + (-1.0f - fSlow4));
		int iSlow10 = std::min<int>(4096, std::max<int>(0, (iSlow3 + 1)));
		float fSlow11 = (fConst4 / fSlow1);
		int iSlow12 = int((fSlow11 + -1.0f));
		float fSlow13 = float(iSlow12);
		float fSlow14 = (fSlow13 + (2.0f - fSlow11));
		int iSlow15 = std::min<int>(4096, std::max<int>(0, iSlow12));
		float fSlow16 = (fSlow11 + (-1.0f - fSlow13));
		int iSlow17 = std::min<int>(4096, std::max<int>(0, (iSlow12 + 1)));
		float fSlow18 = (fConst5 / fSlow1);
		int iSlow19 = int((fSlow18 + -1.0f));
		float fSlow20 = float(iSlow19);
		float fSlow21 = (fSlow20 + (2.0f - fSlow18));
		int iSlow22 = std::min<int>(4096, std::max<int>(0, iSlow19));
		float fSlow23 = (fSlow18 + (-1.0f - fSlow20));
		int iSlow24 = std::min<int>(4096, std::max<int>(0, (iSlow19 + 1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			float fTempFTZ0 = ((0.0500000007f * fRec1[1]) + (0.949999988f * fRec0[1]));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec2[0] = ((1103515245 * iRec2[1]) + 12345);
			fVec1[0] = fSlow7;
			int iTemp0 = (fSlow7 > fVec1[1]);
			iVec2[0] = iTemp0;
			iRec3[0] = (((iRec3[1] + (iRec3[1] > 0)) * (iTemp0 <= iVec2[1])) + (iTemp0 > iVec2[1]));
			float fTemp1 = float(iRec3[0]);
			float fTemp2 = (fSlow6 * ((0.800000012f * float((1 - iVec0[1]))) + (9.31322588e-11f * (float(iRec2[0]) * std::max<float>(0.0f, std::min<float>((fConst2 * fTemp1), ((fConst3 * (fConst1 - fTemp1)) + 1.0f)))))));
			float fTemp3 = ((0.999000013f * fRec1[0]) + fTemp2);
			fVec3[(IOTA & 2047)] = fTemp3;
			float fTempFTZ1 = ((fSlow5 * fVec3[((IOTA - iSlow8) & 2047)]) + (fSlow9 * fVec3[((IOTA - iSlow10) & 2047)]));
			fRec0[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((0.0500000007f * fRec5[1]) + (0.949999988f * fRec4[1]));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp4 = (fTemp2 + (0.999000013f * fRec5[0]));
			fVec4[(IOTA & 2047)] = fTemp4;
			float fTempFTZ3 = ((fSlow14 * fVec4[((IOTA - iSlow15) & 2047)]) + (fSlow16 * fVec4[((IOTA - iSlow17) & 2047)]));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((0.0500000007f * fRec7[1]) + (0.949999988f * fRec6[1]));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp5 = (fTemp2 + (0.999000013f * fRec7[0]));
			fVec5[(IOTA & 2047)] = fTemp5;
			float fTempFTZ5 = ((fSlow21 * fVec5[((IOTA - iSlow22) & 2047)]) + (fSlow23 * fVec5[((IOTA - iSlow24) & 2047)]));
			fRec6[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			output0[i0] = FAUSTFLOAT(std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow0 * ((fRec0[0] + fRec4[0]) + fRec6[0])))));
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			fVec1[1] = fVec1[0];
			iVec2[1] = iVec2[0];
			iRec3[1] = iRec3[0];
			IOTA = (IOTA + 1);
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
