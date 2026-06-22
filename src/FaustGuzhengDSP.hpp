/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "guzheng"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustGuzhengDSP_H__
#define  __FaustGuzhengDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustGuzhengDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec1[2];
	
  public:
	
	int getNumInputsFaustGuzhengDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustGuzhengDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustGuzhengDSPSIG0(int sample_rate) {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec1[l3] = 0;
		}
	}
	
	void fillFaustGuzhengDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec1[0] = ((iVec1[1] + iRec1[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec1[0])));
			iVec1[1] = iVec1[0];
			iRec1[1] = iRec1[0];
		}
	}

};

static FaustGuzhengDSPSIG0* newFaustGuzhengDSPSIG0() { return (FaustGuzhengDSPSIG0*)new FaustGuzhengDSPSIG0(); }
static void deleteFaustGuzhengDSPSIG0(FaustGuzhengDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustGuzhengDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustGuzhengDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustGuzhengDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	int iVec0[2];
	float fRec0[2];
	float fConst3;
	float fRec2[2];
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	FAUSTFLOAT fHslider4;
	float fRec7[2];
	int iRec8[2];
	float fConst4;
	float fConst5;
	FAUSTFLOAT fButton0;
	float fVec2[2];
	int iVec3[2];
	int iRec9[2];
	float fConst6;
	int IOTA;
	float fVec4[4096];
	float fRec3[512];
	
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
		m->declare("filename", "guzheng.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "guzheng");
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
		FaustGuzhengDSPSIG0* sig0 = newFaustGuzhengDSPSIG0();
		sig0->instanceInitFaustGuzhengDSPSIG0(sample_rate);
		sig0->fillFaustGuzhengDSPSIG0(65536, ftbl0FaustGuzhengDSPSIG0);
		deleteFaustGuzhengDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (0.5f / fConst0);
		fConst4 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst5 = (1.0f / fConst4);
		fConst6 = (1.0f / std::max<float>(1.0f, (0.0199999996f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.995f);
		fHslider3 = FAUSTFLOAT(0.80000000000000004f);
		fHslider4 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec8[l9] = 0;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iVec3[l11] = 0;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec9[l12] = 0;
		}
		IOTA = 0;
		for (int l13 = 0; (l13 < 4096); l13 = (l13 + 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 512); l14 = (l14 + 1)) {
			fRec3[l14] = 0.0f;
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
	
	virtual FaustGuzhengDSP* clone() {
		return new FaustGuzhengDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("guzheng");
		ui_interface->addHorizontalSlider("damping", &fHslider2, FAUSTFLOAT(0.995000005f), FAUSTFLOAT(0.899999976f), FAUSTFLOAT(0.999899983f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(440.0f), FAUSTFLOAT(65.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("pluck_noise", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = (fConst0 / float(fHslider1));
		int iSlow2 = int((fSlow1 + -1.0f));
		float fSlow3 = float(iSlow2);
		float fSlow4 = (fSlow3 + (2.0f - fSlow1));
		float fSlow5 = (fConst1 * float(fHslider2));
		float fSlow6 = (fConst1 * float(fHslider3));
		float fSlow7 = (fConst1 * float(fHslider4));
		float fSlow8 = float(fButton0);
		int iSlow9 = std::min<int>(16384, std::max<int>(0, iSlow2));
		float fSlow10 = (fSlow1 + (-1.0f - fSlow3));
		int iSlow11 = std::min<int>(16384, std::max<int>(0, (iSlow2 + 1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fConst3 + (fRec2[1] - std::floor((fConst3 + fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (100.0f * ftbl0FaustGuzhengDSPSIG0[int((65536.0f * fRec2[0]))]);
			float fTemp1 = (fTemp0 + 200.0f);
			float fTemp2 = std::floor(fTemp1);
			float fTempFTZ2 = ((0.00100000005f * fRec4[1]) + (0.999000013f * fRec3[((IOTA - 1) & 511)]));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow5 + (fConst2 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow6 + (fConst2 * fRec6[1]));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow7 + (fConst2 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			iRec8[0] = ((1103515245 * iRec8[1]) + 12345);
			fVec2[0] = fSlow8;
			int iTemp3 = (fSlow8 > fVec2[1]);
			iVec3[0] = iTemp3;
			iRec9[0] = (((iRec9[1] + (iRec9[1] > 0)) * (iTemp3 <= iVec3[1])) + (iTemp3 > iVec3[1]));
			float fTemp4 = float(iRec9[0]);
			float fTemp5 = ((fRec4[0] * fRec5[0]) + (fRec6[0] * (((1.0f - fRec7[0]) * float((1 - iVec0[1]))) + (4.65661287e-10f * ((fRec7[0] * float(iRec8[0])) * std::max<float>(0.0f, std::min<float>((fConst5 * fTemp4), ((fConst6 * (fConst4 - fTemp4)) + 1.0f))))))));
			fVec4[(IOTA & 4095)] = fTemp5;
			float fTempFTZ6 = ((fSlow4 * fVec4[((IOTA - iSlow9) & 4095)]) + (fSlow10 * fVec4[((IOTA - iSlow11) & 4095)]));
			fRec3[(IOTA & 511)] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			int iTemp6 = int(fTemp1);
			output0[i0] = FAUSTFLOAT(std::max<float>(-1.0f, std::min<float>(1.0f, (0.5f * (fRec0[0] * (((fTemp0 + (200.0f - fTemp2)) * fRec3[((IOTA - std::min<int>(4097, std::max<int>(0, (iTemp6 + 1)))) & 511)]) + (fRec3[((IOTA - 0) & 511)] + (fRec3[((IOTA - std::min<int>(4097, std::max<int>(0, iTemp6))) & 511)] * (fTemp2 + (-199.0f - fTemp0))))))))));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			iRec8[1] = iRec8[0];
			fVec2[1] = fVec2[0];
			iVec3[1] = iVec3[0];
			iRec9[1] = iRec9[0];
			IOTA = (IOTA + 1);
		}
	}

};

#endif
