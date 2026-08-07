/* ------------------------------------------------------------
name: "rain"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustRainDSP_H__
#define  __FaustRainDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustRainDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec5[2];
	
  public:
	
	int getNumInputsFaustRainDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustRainDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustRainDSPSIG0(int sample_rate) {
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec0[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec5[l6] = 0;
		}
	}
	
	void fillFaustRainDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec5[0] = ((iVec0[1] + iRec5[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec5[0])));
			iVec0[1] = iVec0[0];
			iRec5[1] = iRec5[0];
		}
	}

};

static FaustRainDSPSIG0* newFaustRainDSPSIG0() { return (FaustRainDSPSIG0*)new FaustRainDSPSIG0(); }
static void deleteFaustRainDSPSIG0(FaustRainDSPSIG0* dsp) { delete dsp; }

static float FaustRainDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustRainDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustRainDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustRainDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	float fConst3;
	float fConst4;
	FAUSTFLOAT fButton0;
	float fRec1[2];
	int iRec4[2];
	float fRec3[4];
	float fConst5;
	float fRec2[3];
	float fConst6;
	float fRec6[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("filename", "rain.dsp");
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
		m->declare("name", "rain");
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
		FaustRainDSPSIG0* sig0 = newFaustRainDSPSIG0();
		sig0->instanceInitFaustRainDSPSIG0(sample_rate);
		sig0->fillFaustRainDSPSIG0(65536, ftbl0FaustRainDSPSIG0);
		deleteFaustRainDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = std::exp((0.0f - (0.5f / fConst0)));
		fConst4 = (1.0f - fConst3);
		fConst5 = (3.14159274f / fConst0);
		fConst6 = (0.119999997f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec4[l2] = 0;
		}
		for (int l3 = 0; (l3 < 4); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
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
	
	virtual FaustRainDSP* clone() {
		return new FaustRainDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("rain");
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = (fConst4 * float(fButton0));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow1 + (fConst3 * fRec1[1]));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTempFTZ2 = (((0.522189379f * fRec3[3]) + ((4.65661287e-10f * float(iRec4[0])) + (2.49495602f * fRec3[1]))) - (2.0172658f * fRec3[2]));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp0 = std::tan((fConst5 * ((1200.0f * fRec0[0]) + 300.0f)));
			float fTemp1 = (1.0f / fTemp0);
			float fTemp2 = (((fTemp1 + 1.41421354f) / fTemp0) + 1.0f);
			float fTempFTZ3 = (((0.0499220341f * fRec3[0]) + (0.0506126992f * fRec3[2])) - (((0.0959935337f * fRec3[1]) + (0.00440878607f * fRec3[3])) + (((fRec2[2] * (((fTemp1 + -1.41421354f) / fTemp0) + 1.0f)) + (2.0f * (fRec2[1] * (1.0f - (1.0f / FaustRainDSP_faustpower2_f(fTemp0)))))) / fTemp2)));
			fRec2[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fConst6 + (fRec6[1] - std::floor((fConst6 + fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			output0[i0] = FAUSTFLOAT((4.0f * ((((fRec0[0] * fRec1[0]) * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1])))) * ((0.150000006f * ftbl0FaustRainDSPSIG0[int((65536.0f * fRec6[0]))]) + 0.850000024f)) / fTemp2)));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			iRec4[1] = iRec4[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec3[j0] = fRec3[(j0 - 1)];
			}
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
