/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "cricket"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustCricketDSP_H__
#define  __FaustCricketDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustCricketDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec1[2];
	
  public:
	
	int getNumInputsFaustCricketDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustCricketDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustCricketDSPSIG0(int sample_rate) {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec1[l2] = 0;
		}
	}
	
	void fillFaustCricketDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec1[0] = ((iVec0[1] + iRec1[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec1[0])));
			iVec0[1] = iVec0[0];
			iRec1[1] = iRec1[0];
		}
	}

};

static FaustCricketDSPSIG0* newFaustCricketDSPSIG0() { return (FaustCricketDSPSIG0*)new FaustCricketDSPSIG0(); }
static void deleteFaustCricketDSPSIG0(FaustCricketDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustCricketDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustCricketDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustCricketDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fButton0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	float fConst3;
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fRec2[2];
	float fConst4;
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "cricket.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "cricket");
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
		FaustCricketDSPSIG0* sig0 = newFaustCricketDSPSIG0();
		sig0->instanceInitFaustCricketDSPSIG0(sample_rate);
		sig0->fillFaustCricketDSPSIG0(65536, ftbl0FaustCricketDSPSIG0);
		deleteFaustCricketDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (1.0f / fConst0);
		fConst4 = (2.0f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(4500.0f);
		fHslider2 = FAUSTFLOAT(3.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
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
	
	virtual FaustCricketDSP* clone() {
		return new FaustCricketDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("cricket");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(4500.0f), FAUSTFLOAT(3000.0f), FAUSTFLOAT(6000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("rate", &fHslider2, FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = ((float(fButton0) > 0.0f) ? 1.0f : 0.0f);
		float fSlow1 = (fConst1 * float(fHslider0));
		float fSlow2 = (fConst1 * float(fHslider1));
		float fSlow3 = (fConst3 * float(fHslider2));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow1 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow2 + (fConst2 * fRec3[1]));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (fRec2[1] + (fConst3 * fRec3[0]));
			float fTempFTZ2 = (fTemp0 - std::floor(fTemp0));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp1 = (fRec4[1] + (fConst4 * fRec3[0]));
			float fTempFTZ3 = (fTemp1 - std::floor(fTemp1));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow3 + (fRec5[1] - std::floor((fSlow3 + fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp2 = (10.0f * fRec5[0]);
			float fTemp3 = (fTemp2 - float(int(fTemp2)));
			float fElse1 = std::sin((4.48798943f * fTemp3));
			float fElse2 = (((fTemp3 < 0.699999988f) ? fElse1 : 0.0f) * std::sin((7.85398149f * fRec5[0])));
			output0[i0] = FAUSTFLOAT((((fSlow0 * fRec0[0]) * ((0.899999976f * ftbl0FaustCricketDSPSIG0[int((65536.0f * fRec2[0]))]) + (0.100000001f * ftbl0FaustCricketDSPSIG0[int((65536.0f * fRec4[0]))]))) * ((fRec5[0] < 0.400000006f) ? fElse2 : 0.0f)));
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
		}
	}

};

#endif
