/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "acoustic_guitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustAcoustic_guitarDSP_H__
#define  __FaustAcoustic_guitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustAcoustic_guitarDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustAcoustic_guitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustAcoustic_guitarDSP : public dsp {
	
 private:
	
	int iRec11[2];
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	FAUSTFLOAT fHslider1;
	float fConst4;
	float fRec26[2];
	float fRec23[2];
	float fRec27[2];
	float fRec29[4];
	int IOTA;
	float fRec30[2048];
	float fVec0[2];
	FAUSTFLOAT fHslider2;
	float fConst5;
	int iRec32[2];
	float fRec31[3];
	float fConst6;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec33[2];
	float fVec2[2];
	float fRec28[2048];
	float fRec20[2];
	float fRec17[2048];
	float fRec19[2];
	float fRec16[4];
	int iRec7[2];
	float fRec3[2048];
	float fRec1[2];
	float fRec2[2];
	float fRec0[2];
	FAUSTFLOAT fHslider3;
	float fRec34[2];
	
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
		m->declare("filename", "acoustic_guitar.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "acoustic_guitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (0.00882352982f * fConst0);
		fConst2 = (0.00147058826f * fConst0);
		fConst3 = (44.0999985f / fConst0);
		fConst4 = (1.0f - fConst3);
		fConst5 = (15.707963f / fConst0);
		fConst6 = (0.00200000009f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(196.0f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec11[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec26[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec23[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec27[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 4); l4 = (l4 + 1)) {
			fRec29[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 2048); l5 = (l5 + 1)) {
			fRec30[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec32[l7] = 0;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec31[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iRec33[l10] = 0;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fRec28[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec20[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2048); l14 = (l14 + 1)) {
			fRec17[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec19[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 4); l16 = (l16 + 1)) {
			fRec16[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iRec7[l17] = 0;
		}
		for (int l18 = 0; (l18 < 2048); l18 = (l18 + 1)) {
			fRec3[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec1[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec2[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec0[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec34[l22] = 0.0f;
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
	
	virtual FaustAcoustic_guitarDSP* clone() {
		return new FaustAcoustic_guitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("acoustic_guitar");
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(196.0f), FAUSTFLOAT(82.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("pluckPosition", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.99000001f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (fConst2 * ((340.0f / fSlow0) + -0.100000001f));
		float fSlow2 = (fConst3 * float(fHslider1));
		float fSlow3 = std::tan((fConst5 * fSlow0));
		float fSlow4 = (1.0f / fSlow3);
		float fSlow5 = (((fSlow4 + 1.41421354f) / fSlow3) + 1.0f);
		float fSlow6 = (float(fHslider2) / fSlow5);
		float fSlow7 = (1.0f / fSlow5);
		float fSlow8 = (((fSlow4 + -1.41421354f) / fSlow3) + 1.0f);
		float fSlow9 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fSlow3))));
		float fSlow10 = (1.0f / std::max<float>(1.0f, (fConst6 * FaustAcoustic_guitarDSP_faustpower2_f((1.0f - (0.00033333333f * fSlow0))))));
		float fSlow11 = float(fButton0);
		float fSlow12 = (fConst3 * float(fHslider3));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec11[0] = 0;
			int iRec12 = iRec11[1];
			float fTempFTZ0 = (float(iRec7[1]) - (0.997843683f * ((0.699999988f * fRec16[2]) + (0.150000006f * (fRec16[1] + fRec16[3])))));
			float fRec15 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow2 + (fConst4 * fRec26[1]));
			fRec26[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (fSlow1 * (1.0f - fRec26[0]));
			float fTemp1 = (fTemp0 + -1.49999499f);
			int iTemp2 = int(fTemp1);
			int iTemp3 = int(std::min<float>(fConst1, float(std::max<int>(0, iTemp2))));
			float fTemp4 = std::floor(fTemp1);
			float fTemp5 = (fTemp0 + (-1.0f - fTemp4));
			float fTemp6 = (0.0f - fTemp5);
			float fTemp7 = (fTemp0 + (-2.0f - fTemp4));
			float fTemp8 = (0.0f - (0.5f * fTemp7));
			float fTemp9 = (fTemp0 + (-3.0f - fTemp4));
			float fTemp10 = (0.0f - (0.333333343f * fTemp9));
			float fTemp11 = (fTemp0 + (-4.0f - fTemp4));
			float fTemp12 = (0.0f - (0.25f * fTemp11));
			float fTemp13 = (fTemp0 - fTemp4);
			int iTemp14 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp2 + 1)))));
			float fTemp15 = (0.0f - fTemp7);
			float fTemp16 = (0.0f - (0.5f * fTemp9));
			float fTemp17 = (0.0f - (0.333333343f * fTemp11));
			int iTemp18 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp2 + 2)))));
			float fTemp19 = (0.0f - fTemp9);
			float fTemp20 = (0.0f - (0.5f * fTemp11));
			float fTemp21 = (fTemp5 * fTemp7);
			int iTemp22 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp2 + 3)))));
			float fTemp23 = (0.0f - fTemp11);
			float fTemp24 = (fTemp21 * fTemp9);
			int iTemp25 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp2 + 4)))));
			float fTempFTZ2 = (((((fRec3[((IOTA - (iTemp3 + 1)) & 2047)] * fTemp6) * fTemp8) * fTemp10) * fTemp12) + (fTemp13 * ((((((fRec3[((IOTA - (iTemp14 + 1)) & 2047)] * fTemp15) * fTemp16) * fTemp17) + (0.5f * (((fTemp5 * fRec3[((IOTA - (iTemp18 + 1)) & 2047)]) * fTemp19) * fTemp20))) + (0.166666672f * ((fTemp21 * fRec3[((IOTA - (iTemp22 + 1)) & 2047)]) * fTemp23))) + (0.0416666679f * (fTemp24 * fRec3[((IOTA - (iTemp25 + 1)) & 2047)])))));
			fRec23[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.0500000007f * fRec27[1]) + (0.949999988f * fRec23[1]));
			fRec27[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = fRec27[0];
			float fRec24 = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = fRec1[1];
			fRec29[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (-1.0f * (0.997843683f * ((0.699999988f * fRec29[2]) + (0.150000006f * (fRec29[1] + fRec29[3])))));
			fRec30[(IOTA & 2047)] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp26 = (fSlow1 * fRec26[0]);
			float fTemp27 = (fTemp26 + -1.49999499f);
			int iTemp28 = int(fTemp27);
			int iTemp29 = int(std::min<float>(fConst1, float(std::max<int>(0, iTemp28))));
			float fTemp30 = std::floor(fTemp27);
			float fTemp31 = (fTemp26 + (-1.0f - fTemp30));
			float fTemp32 = (0.0f - fTemp31);
			float fTemp33 = (fTemp26 + (-2.0f - fTemp30));
			float fTemp34 = (0.0f - (0.5f * fTemp33));
			float fTemp35 = (fTemp26 + (-3.0f - fTemp30));
			float fTemp36 = (0.0f - (0.333333343f * fTemp35));
			float fTemp37 = (fTemp26 + (-4.0f - fTemp30));
			float fTemp38 = (0.0f - (0.25f * fTemp37));
			float fTemp39 = (fTemp26 - fTemp30);
			int iTemp40 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp28 + 1)))));
			float fTemp41 = (0.0f - fTemp33);
			float fTemp42 = (0.0f - (0.5f * fTemp35));
			float fTemp43 = (0.0f - (0.333333343f * fTemp37));
			int iTemp44 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp28 + 2)))));
			float fTemp45 = (0.0f - fTemp35);
			float fTemp46 = (0.0f - (0.5f * fTemp37));
			float fTemp47 = (fTemp31 * fTemp33);
			int iTemp48 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp28 + 3)))));
			float fTemp49 = (0.0f - fTemp37);
			float fTemp50 = (fTemp47 * fTemp35);
			int iTemp51 = int(std::min<float>(fConst1, float(std::max<int>(0, (iTemp28 + 4)))));
			fVec0[0] = (((((fRec30[((IOTA - (iTemp29 + 2)) & 2047)] * fTemp32) * fTemp34) * fTemp36) * fTemp38) + (fTemp39 * ((((((fRec30[((IOTA - (iTemp40 + 2)) & 2047)] * fTemp41) * fTemp42) * fTemp43) + (0.5f * (((fTemp31 * fRec30[((IOTA - (iTemp44 + 2)) & 2047)]) * fTemp45) * fTemp46))) + (0.166666672f * ((fTemp47 * fRec30[((IOTA - (iTemp48 + 2)) & 2047)]) * fTemp49))) + (0.0416666679f * (fTemp50 * fRec30[((IOTA - (iTemp51 + 2)) & 2047)])))));
			iRec32[0] = ((1103515245 * iRec32[1]) + 12345);
			float fTempFTZ7 = ((4.65661287e-10f * float(iRec32[0])) - (fSlow7 * ((fSlow8 * fRec31[2]) + (fSlow9 * fRec31[1]))));
			fRec31[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			fVec1[0] = fSlow11;
			iRec33[0] = (((iRec33[1] + (iRec33[1] > 0)) * (fSlow11 <= fVec1[1])) + (fSlow11 > fVec1[1]));
			float fTemp52 = (fSlow10 * float(iRec33[0]));
			float fTemp53 = (fSlow6 * ((fRec31[2] + (fRec31[0] + (2.0f * fRec31[1]))) * std::max<float>(0.0f, std::min<float>(fTemp52, (2.0f - fTemp52)))));
			fVec2[0] = (fVec0[1] + fTemp53);
			float fTempFTZ8 = ((0.0500000007f * fRec28[((IOTA - 1) & 2047)]) + (0.949999988f * fVec2[1]));
			fRec28[(IOTA & 2047)] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (((((fTemp6 * fTemp8) * fTemp10) * fTemp12) * fRec28[((IOTA - iTemp3) & 2047)]) + (fTemp13 * ((((((fTemp15 * fTemp16) * fTemp17) * fRec28[((IOTA - iTemp14) & 2047)]) + (0.5f * (((fTemp5 * fTemp19) * fTemp20) * fRec28[((IOTA - iTemp18) & 2047)]))) + (0.166666672f * ((fTemp21 * fTemp23) * fRec28[((IOTA - iTemp22) & 2047)]))) + (0.0416666679f * (fTemp24 * fRec28[((IOTA - iTemp25) & 2047)])))));
			float fRec25 = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = fRec24;
			fRec20[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp53 + fRec20[1]);
			float fRec21 = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = fRec25;
			float fRec22 = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = fRec21;
			fRec17[(IOTA & 2047)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (((((fTemp32 * fTemp34) * fTemp36) * fTemp38) * fRec17[((IOTA - (iTemp29 + 1)) & 2047)]) + (fTemp39 * ((((((fTemp41 * fTemp42) * fTemp43) * fRec17[((IOTA - (iTemp40 + 1)) & 2047)]) + (0.5f * (((fTemp31 * fTemp45) * fTemp46) * fRec17[((IOTA - (iTemp44 + 1)) & 2047)]))) + (0.166666672f * ((fTemp47 * fTemp49) * fRec17[((IOTA - (iTemp48 + 1)) & 2047)]))) + (0.0416666679f * (fTemp50 * fRec17[((IOTA - (iTemp51 + 1)) & 2047)])))));
			float fRec18 = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = fRec22;
			fRec19[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = fRec19[1];
			fRec16[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec16[1];
			float fTemp54 = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fRec13 = fTemp54;
			float fRec14 = fTemp54;
			iRec7[0] = iRec12;
			float fTempFTZ18 = fRec15;
			float fRec8 = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = fRec13;
			float fRec9 = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec14;
			float fRec10 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec8;
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = fRec18;
			float fRec4 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec9;
			float fRec5 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec10;
			float fRec6 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec4;
			fRec1[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec6;
			fRec2[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = ((fRec2[0] + (0.995000005f * fRec0[1])) - fRec2[1]);
			fRec0[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fSlow12 + (fConst4 * fRec34[1]));
			fRec34[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			output0[i0] = FAUSTFLOAT((float(tanhf(float(fRec0[0]))) * fRec34[0]));
			iRec11[1] = iRec11[0];
			fRec26[1] = fRec26[0];
			fRec23[1] = fRec23[0];
			fRec27[1] = fRec27[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec29[j0] = fRec29[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec0[1] = fVec0[0];
			iRec32[1] = iRec32[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fVec1[1] = fVec1[0];
			iRec33[1] = iRec33[0];
			fVec2[1] = fVec2[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec16[j1] = fRec16[(j1 - 1)];
			}
			iRec7[1] = iRec7[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec34[1] = fRec34[0];
		}
	}

};

#endif
