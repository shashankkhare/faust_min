/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "flute"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustFluteDSP_H__
#define  __FaustFluteDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustFluteDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustFluteDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustFluteDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fRec2[2];
	float fConst4;
	FAUSTFLOAT fHslider3;
	int iRec4[2];
	float fRec3[3];
	FAUSTFLOAT fHslider4;
	float fRec5[2];
	FAUSTFLOAT fHslider5;
	float fRec7[2];
	float fConst5;
	FAUSTFLOAT fHslider6;
	int IOTA;
	float fVec0[2048];
	float fVec1[2];
	float fRec9[2];
	float fRec8[2];
	float fRec6[2];
	float fVec2[32768];
	float fRec0[2048];
	float fConst6;
	float fConst7;
	float fRec10[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "flute.dsp");
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
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
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
		m->declare("fm.lib/copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "flute");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (1.0f / fConst0);
		fConst4 = (3.14159274f / fConst0);
		fConst5 = (0.5f * fConst0);
		fConst6 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst7 = (1.0f - fConst6);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.71999999999999997f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(440.0f);
		fHslider4 = FAUSTFLOAT(0.14999999999999999f);
		fHslider5 = FAUSTFLOAT(0.02f);
		fHslider6 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec4[l2] = 0;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec7[l5] = 0.0f;
		}
		IOTA = 0;
		for (int l6 = 0; (l6 < 2048); l6 = (l6 + 1)) {
			fVec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec6[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 32768); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fRec0[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
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
	
	virtual FaustFluteDSP* clone() {
		return new FaustFluteDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("flute");
		ui_interface->addHorizontalSlider("calibration", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1200.0f), FAUSTFLOAT(1200.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(440.0f), FAUSTFLOAT(150.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("loss", &fHslider5, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider4, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider1, FAUSTFLOAT(0.720000029f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.0496375002f * float(fHslider0));
		float fSlow1 = (fConst1 * float(fHslider1));
		float fSlow2 = ((0.0900000036f * (1.0f - float(fHslider2))) + 0.00999999978f);
		int iSlow3 = (std::fabs(fSlow2) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst3 / (iSlow3 ? 1.0f : fSlow2))));
		float fSlow4 = (iSlow3 ? 0.0f : fThen1);
		float fSlow5 = float(fButton0);
		float fSlow6 = (fSlow5 * (1.0f - fSlow4));
		float fSlow7 = float(fHslider3);
		float fSlow8 = std::tan((fConst4 * std::max<float>(40.0f, (0.600000024f * fSlow7))));
		float fSlow9 = (1.0f / fSlow8);
		float fSlow10 = (1.0f / (((fSlow9 + 1.41421354f) / fSlow8) + 1.0f));
		float fSlow11 = FaustFluteDSP_faustpower2_f(fSlow8);
		float fSlow12 = (1.0f / fSlow11);
		float fSlow13 = (((fSlow9 + -1.41421354f) / fSlow8) + 1.0f);
		float fSlow14 = (2.0f * (1.0f - fSlow12));
		float fSlow15 = (0.0f - (2.0f / fSlow11));
		float fSlow16 = (fConst1 * float(fHslider4));
		float fSlow17 = (fConst1 * float(fHslider5));
		float fSlow18 = (0.000833333354f * float(fHslider6));
		float fSlow19 = std::max<float>(40.0f, fSlow7);
		int iSlow20 = (std::min<int>(16384, std::max<int>(0, int(((fConst5 * (std::pow(2.0f, (-1.0f * fSlow18)) / fSlow19)) + -2.5f)))) + 1);
		float fSlow21 = (fConst5 * (std::pow(2.0f, (0.0f - fSlow18)) / fSlow19));
		float fSlow22 = float(int((fSlow21 + -2.5f)));
		float fSlow23 = (fSlow21 + (-2.99998999f - fSlow22));
		int iSlow24 = std::min<int>(1024, std::max<int>(0, int(fSlow23)));
		float fSlow25 = (fSlow22 + std::floor(fSlow23));
		float fSlow26 = ((fSlow25 + (3.5f - fSlow21)) / (fSlow21 + (-1.5f - fSlow25)));
		float fSlow27 = (fConst7 * fSlow5);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow1 + (fConst2 * fRec1[1]));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((fRec2[1] * fSlow4) + fSlow6);
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTempFTZ2 = ((4.65661287e-10f * float(iRec4[0])) - (fSlow10 * ((fSlow13 * fRec3[2]) + (fSlow14 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow16 + (fConst2 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp0 = ((fRec1[0] * fRec2[0]) * ((fSlow10 * ((((fSlow12 * fRec3[0]) + (fSlow15 * fRec3[1])) + (fSlow12 * fRec3[2])) * ((0.0250000004f * std::pow(fRec5[0], 2.0f)) + 0.00200000009f))) + 1.0f));
			float fTempFTZ4 = (fSlow17 + (fConst2 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp1 = (1.0f / std::tan((fConst4 * (8500.0f - (6500.0f * fRec7[0])))));
			fVec0[(IOTA & 2047)] = fRec0[((IOTA - iSlow20) & 2047)];
			float fTemp2 = fVec0[((IOTA - iSlow24) & 2047)];
			fVec1[0] = fTemp2;
			float fTempFTZ5 = (fVec1[1] - (fSlow26 * (fRec9[1] - fTemp2)));
			fRec9[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = ((fRec9[0] + (0.995000005f * fRec8[1])) - fRec9[1]);
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.0f - (((fRec6[1] * (1.0f - fTemp1)) - (fRec8[0] + fRec8[1])) / (fTemp1 + 1.0f)));
			fRec6[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp3 = (fRec6[0] * (0.99000001f - (0.0399999991f * fRec7[0])));
			fVec2[(IOTA & 32767)] = (fTemp0 - fTemp3);
			float fTemp4 = std::max<float>(-1.10000002f, std::min<float>(1.10000002f, fVec2[((IOTA - std::min<int>(16384, std::max<int>(0, int((fSlow21 * std::max<float>(0.0199999996f, (0.449999988f * fRec5[0]))))))) & 32767)]));
			float fTempFTZ8 = ((fTemp4 + (9.99999975e-05f * fTemp0)) - (fTemp3 + (0.333299994f * std::pow(fTemp4, 3.0f))));
			fRec0[(IOTA & 2047)] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fSlow27 + (fConst6 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fRec0[((IOTA - 0) & 2047)] * fRec10[0])));
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			iRec4[1] = iRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			IOTA = (IOTA + 1);
			fVec1[1] = fVec1[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec10[1] = fRec10[0];
		}
	}

};

#endif
