/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "electric_guitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustElectric_guitarDSP_H__
#define  __FaustElectric_guitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustElectric_guitarDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustElectric_guitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustElectric_guitarDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst4;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst5;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fConst6;
	float fRec27[2];
	float fRec31[2];
	float fRec33[4];
	int IOTA;
	float fRec34[2048];
	float fVec0[2];
	FAUSTFLOAT fHslider6;
	float fConst7;
	int iRec36[2];
	float fRec35[3];
	float fConst8;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec37[2];
	float fVec2[3];
	float fRec32[2048];
	float fRec23[2];
	float fRec19[2];
	float fRec15[2048];
	float fRec17[2];
	float fRec13[4];
	float fRec8[2];
	float fRec4[2048];
	float fRec2[2];
	float fRec3[2];
	float fRec1[2];
	float fConst9;
	float fConst10;
	float fConst11;
	float fRec0[3];
	
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
		m->declare("filename", "electric_guitar.dsp");
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
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "electric_guitar");
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
		float fConst1 = std::tan((12566.3711f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 1.41421354f) / fConst1) + 1.0f);
		fConst4 = (1.33000004f / fConst3);
		fConst5 = (0.00147058826f * fConst0);
		fConst6 = (0.00882352982f * fConst0);
		fConst7 = (15.707963f / fConst0);
		fConst8 = (0.00200000009f * fConst0);
		fConst9 = (1.0f / fConst3);
		fConst10 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst11 = (2.0f * (1.0f - (1.0f / FaustElectric_guitarDSP_faustpower2_f(fConst1))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.69999999999999996f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(0.5f);
		fHslider5 = FAUSTFLOAT(196.0f);
		fHslider6 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec27[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec31[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 4); l2 = (l2 + 1)) {
			fRec33[l2] = 0.0f;
		}
		IOTA = 0;
		for (int l3 = 0; (l3 < 2048); l3 = (l3 + 1)) {
			fRec34[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec36[l5] = 0;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec35[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec37[l8] = 0;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2048); l10 = (l10 + 1)) {
			fRec32[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec23[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec19[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2048); l13 = (l13 + 1)) {
			fRec15[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec17[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 4); l15 = (l15 + 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec8[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2048); l17 = (l17 + 1)) {
			fRec4[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec2[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec3[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec1[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec0[l21] = 0.0f;
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
	
	virtual FaustElectric_guitarDSP* clone() {
		return new FaustElectric_guitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("electric_guitar");
		ui_interface->addHorizontalSlider("drive", &fHslider1, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider5, FAUSTFLOAT(196.0f), FAUSTFLOAT(82.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mute", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("pluckPosition", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.99000001f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst4 * float(fHslider0));
		float fSlow1 = (std::pow(10.0f, (2.0f * float(fHslider1))) * ((19.0f * float(fHslider2)) + 1.0f));
		float fSlow2 = float(fHslider3);
		float fSlow3 = float(fHslider4);
		float fSlow4 = float(fHslider5);
		float fSlow5 = ((340.0f / fSlow4) + -0.109999999f);
		float fSlow6 = (fConst5 * ((1.0f - fSlow3) * fSlow5));
		float fSlow7 = (fSlow6 + -1.49999499f);
		float fSlow8 = std::floor(fSlow7);
		float fSlow9 = (fSlow6 + (-1.0f - fSlow8));
		float fSlow10 = (fSlow6 + (-2.0f - fSlow8));
		float fSlow11 = (fSlow6 + (-3.0f - fSlow8));
		float fSlow12 = (fSlow6 + (-4.0f - fSlow8));
		float fSlow13 = ((((0.0f - fSlow9) * (0.0f - (0.5f * fSlow10))) * (0.0f - (0.333333343f * fSlow11))) * (0.0f - (0.25f * fSlow12)));
		int iSlow14 = int(fSlow7);
		int iSlow15 = int(std::min<float>(fConst6, float(std::max<int>(0, iSlow14))));
		int iSlow16 = (iSlow15 + 1);
		float fSlow17 = (fSlow6 - fSlow8);
		float fSlow18 = (((0.0f - fSlow10) * (0.0f - (0.5f * fSlow11))) * (0.0f - (0.333333343f * fSlow12)));
		int iSlow19 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow14 + 1)))));
		int iSlow20 = (iSlow19 + 1);
		float fSlow21 = (0.5f * ((fSlow9 * (0.0f - fSlow11)) * (0.0f - (0.5f * fSlow12))));
		int iSlow22 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow14 + 2)))));
		int iSlow23 = (iSlow22 + 1);
		float fSlow24 = (fSlow9 * fSlow10);
		float fSlow25 = (0.166666672f * (fSlow24 * (0.0f - fSlow12)));
		int iSlow26 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow14 + 3)))));
		int iSlow27 = (iSlow26 + 1);
		float fSlow28 = (0.0416666679f * (fSlow24 * fSlow11));
		int iSlow29 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow14 + 4)))));
		int iSlow30 = (iSlow29 + 1);
		float fSlow31 = (fConst5 * (fSlow3 * fSlow5));
		float fSlow32 = (fSlow31 + -1.49999499f);
		float fSlow33 = std::floor(fSlow32);
		float fSlow34 = (fSlow31 + (-1.0f - fSlow33));
		float fSlow35 = (fSlow31 + (-2.0f - fSlow33));
		float fSlow36 = (fSlow31 + (-3.0f - fSlow33));
		float fSlow37 = (fSlow31 + (-4.0f - fSlow33));
		float fSlow38 = ((((0.0f - fSlow34) * (0.0f - (0.5f * fSlow35))) * (0.0f - (0.333333343f * fSlow36))) * (0.0f - (0.25f * fSlow37)));
		int iSlow39 = int(fSlow32);
		int iSlow40 = int(std::min<float>(fConst6, float(std::max<int>(0, iSlow39))));
		int iSlow41 = (iSlow40 + 2);
		float fSlow42 = (fSlow31 - fSlow33);
		float fSlow43 = (((0.0f - fSlow35) * (0.0f - (0.5f * fSlow36))) * (0.0f - (0.333333343f * fSlow37)));
		int iSlow44 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow39 + 1)))));
		int iSlow45 = (iSlow44 + 2);
		float fSlow46 = (0.5f * ((fSlow34 * (0.0f - fSlow36)) * (0.0f - (0.5f * fSlow37))));
		int iSlow47 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow39 + 2)))));
		int iSlow48 = (iSlow47 + 2);
		float fSlow49 = (fSlow34 * fSlow35);
		float fSlow50 = (0.166666672f * (fSlow49 * (0.0f - fSlow37)));
		int iSlow51 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow39 + 3)))));
		int iSlow52 = (iSlow51 + 2);
		float fSlow53 = (0.0416666679f * (fSlow49 * fSlow36));
		int iSlow54 = int(std::min<float>(fConst6, float(std::max<int>(0, (iSlow39 + 4)))));
		int iSlow55 = (iSlow54 + 2);
		float fSlow56 = std::tan((fConst7 * fSlow4));
		float fSlow57 = (1.0f / fSlow56);
		float fSlow58 = (((fSlow57 + 1.41421354f) / fSlow56) + 1.0f);
		float fSlow59 = (100.0f * (float(fHslider6) / fSlow58));
		float fSlow60 = (1.0f / fSlow58);
		float fSlow61 = (((fSlow57 + -1.41421354f) / fSlow56) + 1.0f);
		float fSlow62 = (2.0f * (1.0f - (1.0f / FaustElectric_guitarDSP_faustpower2_f(fSlow56))));
		float fSlow63 = (1.0f / std::max<float>(1.0f, (fConst8 * FaustElectric_guitarDSP_faustpower2_f((1.0f - (0.000500000024f * fSlow4))))));
		float fSlow64 = float(fButton0);
		int iSlow65 = (iSlow40 + 1);
		int iSlow66 = (iSlow44 + 1);
		int iSlow67 = (iSlow47 + 1);
		int iSlow68 = (iSlow51 + 1);
		int iSlow69 = (iSlow54 + 1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (-1.0f * (0.997305274f * ((0.899999976f * fRec13[2]) + (0.0500000007f * (fRec13[1] + fRec13[3])))));
			float fRec12 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((fSlow13 * fRec4[((IOTA - iSlow16) & 2047)]) + (fSlow17 * ((((fSlow18 * fRec4[((IOTA - iSlow20) & 2047)]) + (fSlow21 * fRec4[((IOTA - iSlow23) & 2047)])) + (fSlow25 * fRec4[((IOTA - iSlow27) & 2047)])) + (fSlow28 * fRec4[((IOTA - iSlow30) & 2047)]))));
			fRec27[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((0.0500000007f * fRec31[1]) + (0.949999988f * fRec27[1]));
			fRec31[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = fRec31[0];
			float fRec28 = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = fRec2[1];
			fRec33[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (-1.0f * (0.997305274f * ((0.899999976f * fRec33[2]) + (0.0500000007f * (fRec33[1] + fRec33[3])))));
			fRec34[(IOTA & 2047)] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			fVec0[0] = ((fSlow38 * fRec34[((IOTA - iSlow41) & 2047)]) + (fSlow42 * ((((fSlow43 * fRec34[((IOTA - iSlow45) & 2047)]) + (fSlow46 * fRec34[((IOTA - iSlow48) & 2047)])) + (fSlow50 * fRec34[((IOTA - iSlow52) & 2047)])) + (fSlow53 * fRec34[((IOTA - iSlow55) & 2047)]))));
			iRec36[0] = ((1103515245 * iRec36[1]) + 12345);
			float fTempFTZ6 = ((4.65661287e-10f * float(iRec36[0])) - (fSlow60 * ((fSlow61 * fRec35[2]) + (fSlow62 * fRec35[1]))));
			fRec35[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			fVec1[0] = fSlow64;
			iRec37[0] = (((iRec37[1] + (iRec37[1] > 0)) * (fSlow64 <= fVec1[1])) + (fSlow64 > fVec1[1]));
			float fTemp0 = (fSlow63 * float(iRec37[0]));
			float fTemp1 = (fSlow59 * ((fRec35[2] + (fRec35[0] + (2.0f * fRec35[1]))) * std::max<float>(0.0f, std::min<float>(fTemp0, (2.0f - fTemp0)))));
			float fTemp2 = (fVec0[1] + fTemp1);
			fVec2[0] = fTemp2;
			float fTempFTZ7 = ((0.0500000007f * fRec32[((IOTA - 1) & 2047)]) + (0.949999988f * fVec2[2]));
			fRec32[(IOTA & 2047)] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = ((fSlow13 * fRec32[((IOTA - iSlow15) & 2047)]) + (fSlow17 * ((((fSlow18 * fRec32[((IOTA - iSlow19) & 2047)]) + (fSlow21 * fRec32[((IOTA - iSlow22) & 2047)])) + (fSlow25 * fRec32[((IOTA - iSlow26) & 2047)])) + (fSlow28 * fRec32[((IOTA - iSlow29) & 2047)]))));
			float fRec29 = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fVec2[1] + fRec23[1]);
			float fRec30 = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = fRec28;
			fRec23[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = fRec23[1];
			float fRec24 = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = fRec29;
			float fRec25 = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = fRec30;
			float fRec26 = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = fRec24;
			fRec19[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fTemp1 + fRec19[1]);
			float fRec20 = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = fRec25;
			float fRec21 = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec26;
			float fRec22 = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec20;
			fRec15[(IOTA & 2047)] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = ((fSlow38 * fRec15[((IOTA - iSlow65) & 2047)]) + (fSlow42 * ((((fSlow43 * fRec15[((IOTA - iSlow66) & 2047)]) + (fSlow46 * fRec15[((IOTA - iSlow67) & 2047)])) + (fSlow50 * fRec15[((IOTA - iSlow68) & 2047)])) + (fSlow53 * fRec15[((IOTA - iSlow69) & 2047)]))));
			float fRec16 = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = fRec21;
			fRec17[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec22;
			float fRec18 = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fSlow2 * fRec17[1]);
			fRec13[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec18;
			float fRec14 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec12;
			fRec8[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fSlow2 * fRec8[1]);
			float fRec9 = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec13[0];
			float fRec10 = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec14;
			float fRec11 = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = fRec9;
			fRec4[(IOTA & 2047)] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = fRec16;
			float fRec5 = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = fRec10;
			float fRec6 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = fRec11;
			float fRec7 = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec5;
			fRec2[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = fRec7;
			fRec3[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = ((fRec3[0] + (0.995000005f * fRec1[1])) - fRec3[1]);
			fRec1[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTemp3 = std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow1 * fRec1[0])));
			float fTempFTZ35 = (float(tanhf(float((fTemp3 * (1.0f - (0.333333343f * FaustElectric_guitarDSP_faustpower2_f(fTemp3))))))) - (fConst9 * ((fConst10 * fRec0[2]) + (fConst11 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fRec0[2] + (fRec0[0] + (2.0f * fRec0[1])))));
			fRec27[1] = fRec27[0];
			fRec31[1] = fRec31[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec33[j0] = fRec33[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec0[1] = fVec0[0];
			iRec36[1] = iRec36[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fVec1[1] = fVec1[0];
			iRec37[1] = iRec37[0];
			fVec2[2] = fVec2[1];
			fVec2[1] = fVec2[0];
			fRec23[1] = fRec23[0];
			fRec19[1] = fRec19[0];
			fRec17[1] = fRec17[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec13[j1] = fRec13[(j1 - 1)];
			}
			fRec8[1] = fRec8[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
