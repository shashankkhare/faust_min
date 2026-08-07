/* ------------------------------------------------------------
name: "seawave"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSeawaveDSP_H__
#define  __FaustSeawaveDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustSeawaveDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec5[2];
	
  public:
	
	int getNumInputsFaustSeawaveDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSeawaveDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSeawaveDSPSIG0(int sample_rate) {
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iVec0[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec5[l4] = 0;
		}
	}
	
	void fillFaustSeawaveDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec5[0] = ((iVec0[1] + iRec5[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec5[0])));
			iVec0[1] = iVec0[0];
			iRec5[1] = iRec5[0];
		}
	}

};

static FaustSeawaveDSPSIG0* newFaustSeawaveDSPSIG0() { return (FaustSeawaveDSPSIG0*)new FaustSeawaveDSPSIG0(); }
static void deleteFaustSeawaveDSPSIG0(FaustSeawaveDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustSeawaveDSPSIG0[65536];
static float FaustSeawaveDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSeawaveDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSeawaveDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int iRec3[2];
	float fRec2[4];
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider1;
	float fConst3;
	float fRec4[2];
	float fConst4;
	float fRec6[2];
	float fConst5;
	float fRec7[2];
	float fRec1[3];
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fRec11[2];
	float fConst11;
	float fRec12[2];
	float fRec10[2];
	float fRec9[2];
	float fRec8[2];
	float fRec13[3];
	float fVec1[2];
	float fRec0[2];
	float fConst12;
	float fConst13;
	FAUSTFLOAT fButton0;
	float fRec14[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("filename", "seawave.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "seawave");
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
		FaustSeawaveDSPSIG0* sig0 = newFaustSeawaveDSPSIG0();
		sig0->instanceInitFaustSeawaveDSPSIG0(sample_rate);
		sig0->fillFaustSeawaveDSPSIG0(65536, ftbl0FaustSeawaveDSPSIG0);
		deleteFaustSeawaveDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = (0.136999995f / fConst0);
		fConst5 = (0.191f / fConst0);
		fConst6 = std::exp((0.0f - (20.0f / fConst0)));
		fConst7 = (1.0f - fConst6);
		fConst8 = std::exp((0.0f - (1.25f / fConst0)));
		fConst9 = (1.0f / fConst0);
		fConst10 = (0.0130000003f / fConst0);
		fConst11 = (0.0209999997f / fConst0);
		fConst12 = std::exp((0.0f - (0.5f / fConst0)));
		fConst13 = (1.0f - fConst12);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec3[l0] = 0;
		}
		for (int l1 = 0; (l1 < 4); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec11[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec12[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fVec1[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec0[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
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
	
	virtual FaustSeawaveDSP* clone() {
		return new FaustSeawaveDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("seawave");
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (20.0f * float(fHslider0));
		float fSlow1 = (fConst2 * float(fHslider1));
		float fSlow2 = (fConst13 * float(fButton0));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			float fTempFTZ0 = (((0.522189379f * fRec2[3]) + ((4.65661287e-10f * float(iRec3[0])) + (2.49495602f * fRec2[1]))) - (2.0172658f * fRec2[2]));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = ((0.0499220341f * fRec2[0]) + (0.0506126992f * fRec2[2]));
			float fTemp1 = ((0.0959935337f * fRec2[1]) + (0.00440878607f * fRec2[3]));
			float fTempFTZ1 = (fSlow1 + (fConst3 * fRec4[1]));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fConst4 + (fRec6[1] - std::floor((fConst4 + fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fConst5 + (fRec7[1] - std::floor((fConst5 + fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp2 = ((0.300000012f * (ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec6[0]))] + 1.0f)) + (0.200000003f * (ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec7[0]))] + 1.0f)));
			float fTemp3 = std::tan((fConst1 * (((200.0f * fRec4[0]) + 100.0f) * ((0.5f * fTemp2) + 0.800000012f))));
			float fTemp4 = (1.0f / fTemp3);
			float fTemp5 = (((fTemp4 + 1.41421354f) / fTemp3) + 1.0f);
			float fTempFTZ4 = (fTemp0 - (fTemp1 + (((fRec1[2] * (((fTemp4 + -1.41421354f) / fTemp3) + 1.0f)) + (2.0f * (fRec1[1] * (1.0f - (1.0f / FaustSeawaveDSP_faustpower2_f(fTemp3)))))) / fTemp5)));
			fRec1[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fConst10 + (fRec11[1] - std::floor((fConst10 + fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fConst11 + (fRec12[1] - std::floor((fConst11 + fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp6 = (fRec10[1] + (fConst9 * ((0.00999999978f * (ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec11[0]))] + ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec12[0]))])) + 0.0799999982f)));
			float fTempFTZ7 = (fTemp6 - std::floor(fTemp6));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			int iTemp7 = (fRec10[0] >= 0.850000024f);
			float fTempFTZ8 = ((fConst8 * fRec9[1]) + float((iTemp7 & (fRec10[1] < 0.850000024f))));
			fRec9[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((fConst6 * fRec8[1]) + (fConst7 * fRec9[0]));
			fRec8[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp8 = std::tan((fConst1 * ((200.0f * fTemp2) + 600.0f)));
			float fTemp9 = (1.0f / fTemp8);
			float fTemp10 = FaustSeawaveDSP_faustpower2_f(fTemp8);
			float fTemp11 = (((fTemp9 + 1.41421354f) / fTemp8) + 1.0f);
			float fTempFTZ10 = (fTemp0 - (fTemp1 + (((fRec13[2] * (((fTemp9 + -1.41421354f) / fTemp8) + 1.0f)) + (2.0f * (fRec13[1] * (1.0f - (1.0f / fTemp10))))) / fTemp11)));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fThen0 = (0.588235319f * fRec10[0]);
			float fElse0 = ((3.33333325f * (fRec10[0] + -0.850000024f)) + 0.5f);
			float fTemp12 = (((0.850000024f * (((fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))) * (1.0f - (0.550000012f * fRec8[0]))) / fTemp5)) + (0.25f * (((fRec8[0] * (((fRec13[1] * (0.0f - (2.0f / fTemp10))) + (fRec13[0] / fTemp10)) + (fRec13[2] / fTemp10))) * ((0.300000012f * fRec4[0]) + 0.400000006f)) / fTemp11))) * (1.0f - std::cos((6.28318548f * (iTemp7 ? fElse0 : fThen0)))));
			fVec1[0] = fTemp12;
			float fTempFTZ11 = ((0.995000005f * fRec0[1]) + (0.5f * (fTemp12 - fVec1[1])));
			fRec0[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fSlow2 + (fConst12 * fRec14[1]));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * (fRec0[0] * fRec14[0]))))));
			iRec3[1] = iRec3[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec2[j0] = fRec2[(j0 - 1)];
			}
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fVec1[1] = fVec1[0];
			fRec0[1] = fRec0[0];
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
