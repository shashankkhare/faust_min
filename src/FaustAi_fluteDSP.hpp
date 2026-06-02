/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "ai_flute"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustAi_fluteDSP_H__
#define  __FaustAi_fluteDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustAi_fluteDSPSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec5[2];
	
  public:
	
	int getNumInputsFaustAi_fluteDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustAi_fluteDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustAi_fluteDSPSIG0(int sample_rate) {
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iVec2[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec5[l7] = 0;
		}
	}
	
	void fillFaustAi_fluteDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec2[0] = 1;
			iRec5[0] = ((iVec2[1] + iRec5[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec5[0])));
			iVec2[1] = iVec2[0];
			iRec5[1] = iRec5[0];
		}
	}

};

static FaustAi_fluteDSPSIG0* newFaustAi_fluteDSPSIG0() { return (FaustAi_fluteDSPSIG0*)new FaustAi_fluteDSPSIG0(); }
static void deleteFaustAi_fluteDSPSIG0(FaustAi_fluteDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustAi_fluteDSPSIG0[65536];
static float FaustAi_fluteDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustAi_fluteDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustAi_fluteDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	int IOTA;
	float fVec0[65536];
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	FAUSTFLOAT fHslider2;
	int iRec3[2];
	float fVec1[2048];
	FAUSTFLOAT fHslider3;
	float fRec4[2];
	FAUSTFLOAT fHslider4;
	float fConst4;
	FAUSTFLOAT fHslider5;
	float fRec6[2];
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
		m->declare("filename", "ai_flute.dsp");
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
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "ai_flute");
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
		FaustAi_fluteDSPSIG0* sig0 = newFaustAi_fluteDSPSIG0();
		sig0->instanceInitFaustAi_fluteDSPSIG0(sample_rate);
		sig0->fillFaustAi_fluteDSPSIG0(65536, ftbl0FaustAi_fluteDSPSIG0);
		deleteFaustAi_fluteDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = (1.0f / std::tan((15707.9629f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = (1.0f - fConst1);
		fConst4 = (1.0f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.01f);
		fHslider3 = FAUSTFLOAT(440.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(5.0f);
	}
	
	virtual void instanceClear() {
		IOTA = 0;
		for (int l0 = 0; (l0 < 65536); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec3[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2048); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec0[l10] = 0.0f;
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
	
	virtual FaustAi_fluteDSP* clone() {
		return new FaustAi_fluteDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ai_flute");
		ui_interface->addHorizontalSlider("ai_breath_noise", &fHslider2, FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("ai_pressure", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("ai_vibrato_depth", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("ai_vibrato_rate", &fHslider5, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(15.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fButton0);
		float fSlow1 = float(fHslider0);
		float fSlow2 = float(fHslider1);
		float fSlow3 = (4.65661287e-10f * float(fHslider2));
		float fSlow4 = float(fHslider3);
		float fSlow5 = (0.00999999978f * float(fHslider4));
		float fSlow6 = (fConst4 * float(fHslider5));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[(IOTA & 65535)] = 0.999000013f;
			float fTemp0 = float((0.999000013f == fVec0[((IOTA - 44100) & 65535)]));
			float fTemp1 = (1.0f - (0.00100000005f * fTemp0));
			float fTempFTZ0 = ((0.00100000005f * (fTemp0 * fRec1[1])) + (fSlow1 * fTemp1));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((0.00100000005f * (fRec2[1] * fTemp0)) + (fSlow2 * fTemp1));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			float fTemp2 = (fSlow0 * (fRec2[0] + (fSlow3 * float(iRec3[0]))));
			fVec1[(IOTA & 2047)] = fTemp2;
			float fTempFTZ2 = ((0.00100000005f * (fTemp0 * fRec4[1])) + (fSlow4 * fTemp1));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow6 + (fRec6[1] - std::floor((fSlow6 + fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp3 = (fConst0 / (fRec4[0] * ((fSlow5 * ftbl0FaustAi_fluteDSPSIG0[int((65536.0f * fRec6[0]))]) + 1.0f)));
			int iTemp4 = int(fTemp3);
			float fTemp5 = std::floor(fTemp3);
			float fTemp6 = std::max<float>(-1.0f, std::min<float>(1.0f, (10.0f * ((fVec1[((IOTA - std::min<int>(1025, int(std::max<int>(0, int(iTemp4))))) & 2047)] * (fTemp5 + (1.0f - fTemp3))) + ((fTemp3 - fTemp5) * fVec1[((IOTA - std::min<int>(1025, int(std::max<int>(0, int((iTemp4 + 1)))))) & 2047)])))));
			float fTemp7 = (fSlow0 * ((fRec1[0] * fTemp6) * (1.0f - (0.333333343f * FaustAi_fluteDSP_faustpower2_f(fTemp6)))));
			fVec3[0] = fTemp7;
			float fTempFTZ4 = (0.0f - (fConst2 * ((fConst3 * fRec0[1]) - (fTemp7 + fVec3[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			output0[i0] = FAUSTFLOAT((0.5f * fRec0[0]));
			IOTA = (IOTA + 1);
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			iRec3[1] = iRec3[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
