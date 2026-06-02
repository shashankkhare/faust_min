/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "bell"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBellDSP_H__
#define  __FaustBellDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustBellDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec0[2];
	
  public:
	
	int getNumInputsFaustBellDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustBellDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustBellDSPSIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec0[l1] = 0;
		}
	}
	
	void fillFaustBellDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec0[0] = ((iVec0[1] + iRec0[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec0[0])));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
		}
	}

};

static FaustBellDSPSIG0* newFaustBellDSPSIG0() { return (FaustBellDSPSIG0*)new FaustBellDSPSIG0(); }
static void deleteFaustBellDSPSIG0(FaustBellDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustBellDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBellDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBellDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fRec1[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec2[2];
	FAUSTFLOAT fHslider3;
	float fConst4;
	float fRec3[2];
	float fConst5;
	float fConst6;
	float fRec4[2];
	float fConst7;
	float fConst8;
	float fRec5[2];
	float fConst9;
	
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
		m->declare("filename", "bell.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "bell");
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
		FaustBellDSPSIG0* sig0 = newFaustBellDSPSIG0();
		sig0->instanceInitFaustBellDSPSIG0(sample_rate);
		sig0->fillFaustBellDSPSIG0(65536, ftbl0FaustBellDSPSIG0);
		deleteFaustBellDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst3 = (1.0f / fConst2);
		fConst4 = (2.00099993f / fConst0);
		fConst5 = (0.699999988f * fConst0);
		fConst6 = (3.50200009f / fConst0);
		fConst7 = (0.5f * fConst0);
		fConst8 = (4.90299988f / fConst0);
		fConst9 = (0.300000012f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(440.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(2.0f);
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
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
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
	
	virtual FaustBellDSP* clone() {
		return new FaustBellDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bell");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(440.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("ring_time", &fHslider3, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (fSlow0 * float(fHslider1));
		float fSlow2 = float(fHslider2);
		float fSlow3 = (fConst1 * fSlow2);
		float fSlow4 = float(fButton0);
		float fSlow5 = float(fHslider3);
		float fSlow6 = (1.0f / std::max<float>(1.0f, (fConst0 * fSlow5)));
		float fSlow7 = ((0.140000001f * fSlow0) + 0.600000024f);
		float fSlow8 = (fConst4 * fSlow2);
		float fSlow9 = (1.0f / std::max<float>(1.0f, (fConst5 * fSlow5)));
		float fSlow10 = ((0.280000001f * fSlow0) + 0.400000006f);
		float fSlow11 = (fConst6 * fSlow2);
		float fSlow12 = (1.0f / std::max<float>(1.0f, (fConst7 * fSlow5)));
		float fSlow13 = ((0.419999987f * fSlow0) + 0.200000003f);
		float fSlow14 = (fConst8 * fSlow2);
		float fSlow15 = (1.0f / std::max<float>(1.0f, (fConst9 * fSlow5)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow3 + (fRec1[1] - std::floor((fSlow3 + fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec1[0] = fSlow4;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (fSlow4 <= fVec1[1])) + (fSlow4 > fVec1[1]));
			float fTemp0 = float(iRec2[0]);
			float fTemp1 = (fConst3 * fTemp0);
			float fTemp2 = (fConst2 - fTemp0);
			float fTempFTZ1 = (fSlow8 + (fRec3[1] - std::floor((fSlow8 + fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow11 + (fRec4[1] - std::floor((fSlow11 + fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow14 + (fRec5[1] - std::floor((fSlow14 + fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow1 * ((((ftbl0FaustBellDSPSIG0[int((65536.0f * fRec1[0]))] * std::max<float>(0.0f, std::min<float>(fTemp1, ((fSlow6 * fTemp2) + 1.0f)))) + (fSlow7 * (ftbl0FaustBellDSPSIG0[int((65536.0f * fRec3[0]))] * std::max<float>(0.0f, std::min<float>(fTemp1, ((fSlow9 * fTemp2) + 1.0f)))))) + (fSlow10 * (ftbl0FaustBellDSPSIG0[int((65536.0f * fRec4[0]))] * std::max<float>(0.0f, std::min<float>(fTemp1, ((fSlow12 * fTemp2) + 1.0f)))))) + (fSlow13 * (ftbl0FaustBellDSPSIG0[int((65536.0f * fRec5[0]))] * std::max<float>(0.0f, std::min<float>(fTemp1, ((fSlow15 * fTemp2) + 1.0f))))))));
			fRec1[1] = fRec1[0];
			fVec1[1] = fVec1[0];
			iRec2[1] = iRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
		}
	}

};

#endif
