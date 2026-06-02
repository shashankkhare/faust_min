/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tom"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTomDSP_H__
#define  __FaustTomDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustTomDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec0[2];
	
  public:
	
	int getNumInputsFaustTomDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTomDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTomDSPSIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec0[l1] = 0;
		}
	}
	
	void fillFaustTomDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec0[0] = ((iVec0[1] + iRec0[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec0[0])));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
		}
	}

};

static FaustTomDSPSIG0* newFaustTomDSPSIG0() { return (FaustTomDSPSIG0*)new FaustTomDSPSIG0(); }
static void deleteFaustTomDSPSIG0(FaustTomDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustTomDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTomDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTomDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec2[2];
	float fConst4;
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	int iRec3[2];
	float fConst5;
	
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
		m->declare("filename", "tom.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tom");
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
		FaustTomDSPSIG0* sig0 = newFaustTomDSPSIG0();
		sig0->instanceInitFaustTomDSPSIG0(sample_rate);
		sig0->fillFaustTomDSPSIG0(65536, ftbl0FaustTomDSPSIG0);
		deleteFaustTomDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst3 = (1.0f / fConst2);
		fConst4 = (1.0f / std::max<float>(1.0f, (0.0299999993f * fConst0)));
		fConst5 = (1.0f / std::max<float>(1.0f, (0.00999999978f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.69999999999999996f);
		fHslider2 = FAUSTFLOAT(110.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec2[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec3[l5] = 0;
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
	
	virtual FaustTomDSP* clone() {
		return new FaustTomDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tom");
		ui_interface->addHorizontalSlider("decay_time", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(110.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = ((fSlow0 * float(fHslider1)) * ((0.200000003f * fSlow0) + 1.0f));
		float fSlow2 = (fConst1 * float(fHslider2));
		float fSlow3 = (0.300000012f * (fSlow0 + 1.0f));
		float fSlow4 = float(fButton0);
		float fSlow5 = (1.0f / std::max<float>(1.0f, (fConst0 * float(fHslider3))));
		float fSlow6 = (4.65661294e-11f * fSlow0);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec1[0] = fSlow4;
			iRec2[0] = ((fSlow4 > fVec1[1]) + ((fSlow4 <= fVec1[1]) * (iRec2[1] + (iRec2[1] > 0))));
			float fTemp0 = float(iRec2[0]);
			float fTemp1 = (fConst3 * fTemp0);
			float fTemp2 = (fRec1[1] + (fSlow2 * ((fSlow3 * std::max<float>(0.0f, std::min<float>(fTemp1, (1.0f - (fConst4 * (fTemp0 - fConst2)))))) + 1.0f)));
			float fTempFTZ0 = (fTemp2 - std::floor(fTemp2));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp3 = (fConst2 - fTemp0);
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			output0[i0] = FAUSTFLOAT((fSlow1 * ((ftbl0FaustTomDSPSIG0[int((65536.0f * fRec1[0]))] * std::max<float>(0.0f, std::min<float>(fTemp1, ((fSlow5 * fTemp3) + 1.0f)))) + (fSlow6 * (float(iRec3[0]) * std::max<float>(0.0f, std::min<float>(fTemp1, ((fConst5 * fTemp3) + 1.0f))))))));
			fVec1[1] = fVec1[0];
			iRec2[1] = iRec2[0];
			fRec1[1] = fRec1[0];
			iRec3[1] = iRec3[0];
		}
	}

};

#endif
