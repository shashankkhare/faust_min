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
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec1[2];
	int iRec2[2];
	float fRec0[2];
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fRec4[2];
	int iRec6[2];
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fRec7[2];
	float fRec5[3];
	FAUSTFLOAT fHslider2;
	float fRec8[2];
	FAUSTFLOAT fHslider3;
	float fRec10[2];
	float fConst5;
	FAUSTFLOAT fHslider4;
	int IOTA;
	float fVec1[2048];
	float fVec2[2];
	float fRec12[2];
	float fRec11[2];
	float fRec9[2];
	float fVec3[32768];
	float fRec3[8192];
	FAUSTFLOAT fHslider5;
	float fRec13[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
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
		fConst1 = (1.0f / std::max<float>(1.0f, (0.0500000007f * fConst0)));
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = (3.14159274f / fConst0);
		fConst5 = (0.5f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.71999999999999997f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.14999999999999999f);
		fHslider3 = FAUSTFLOAT(0.02f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec0[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec6[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec10[l9] = 0.0f;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 2048); l10 = (l10 + 1)) {
			fVec1[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec9[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 32768); l15 = (l15 + 1)) {
			fVec3[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 8192); l16 = (l16 + 1)) {
			fRec3[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec13[l17] = 0.0f;
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
		ui_interface->addHorizontalSlider("calibration", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1200.0f), FAUSTFLOAT(1200.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(440.0f), FAUSTFLOAT(150.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider5, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("loss", &fHslider3, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider2, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider0, FAUSTFLOAT(0.720000029f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fButton0);
		int iSlow1 = (fSlow0 == 0.0f);
		float fSlow2 = (fConst2 * float(fHslider0));
		float fSlow3 = (0.00499999989f * float(fHslider1));
		float fSlow4 = (fConst2 * float(fHslider2));
		float fSlow5 = (fConst2 * float(fHslider3));
		float fSlow6 = (0.000833333354f * float(fHslider4));
		float fSlow7 = (fConst5 * std::pow(2.0f, (-1.0f * fSlow6)));
		float fSlow8 = (fConst5 * std::pow(2.0f, (0.0f - fSlow6)));
		float fSlow9 = (0.970000029f * float(fHslider5));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow0;
			float fTempFTZ0 = (fSlow0 + (fRec1[1] * float((fVec0[1] >= fSlow0))));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec2[0] = (iSlow1 * (iRec2[1] + 1));
			float fTempFTZ1 = ((0.995000005f * fRec0[1]) + (0.00499999989f * std::max<float>(0.0f, (std::min<float>((fConst1 * fRec1[0]), 1.0f) - (fConst1 * float(iRec2[0]))))));
			fRec0[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow2 + (fConst3 * fRec4[1]));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fTempFTZ3 = (fSlow3 + (0.995000005f * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp0 = std::tan((fConst4 * std::max<float>(40.0f, (0.600000024f * fRec7[0]))));
			float fTemp1 = (1.0f / fTemp0);
			float fTemp2 = FaustFluteDSP_faustpower2_f(fTemp0);
			float fTemp3 = (((fTemp1 + 1.41421354f) / fTemp0) + 1.0f);
			float fTempFTZ4 = ((4.65661287e-10f * float(iRec6[0])) - (((fRec5[2] * (((fTemp1 + -1.41421354f) / fTemp0) + 1.0f)) + (2.0f * (fRec5[1] * (1.0f - (1.0f / fTemp2))))) / fTemp3));
			fRec5[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow4 + (fConst3 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp4 = ((fRec4[0] * fRec0[0]) * ((((((fRec5[1] * (0.0f - (2.0f / fTemp2))) + (fRec5[0] / fTemp2)) + (fRec5[2] / fTemp2)) * ((0.100000001f * std::pow(fRec8[0], 2.0f)) + 0.200000003f)) / fTemp3) + 1.0f));
			float fTempFTZ6 = (fSlow5 + (fConst3 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp5 = (1.0f / std::tan((fConst4 * (8500.0f - (6500.0f * fRec10[0])))));
			float fTemp6 = std::max<float>(40.0f, fRec7[0]);
			fVec1[(IOTA & 2047)] = fRec3[((IOTA - (std::min<int>(16384, std::max<int>(0, int(((fSlow7 / fTemp6) + -2.5f)))) + 1)) & 8191)];
			float fTemp7 = (fSlow8 / fTemp6);
			float fTemp8 = float(int((fTemp7 + -2.5f)));
			float fTemp9 = (fTemp7 + (-2.99998999f - fTemp8));
			float fTemp10 = fVec1[((IOTA - std::min<int>(1024, std::max<int>(0, int(fTemp9)))) & 2047)];
			fVec2[0] = fTemp10;
			float fTemp11 = (fTemp8 + std::floor(fTemp9));
			float fTempFTZ7 = (fVec2[1] - (((fTemp11 + (3.5f - fTemp7)) * (fRec12[1] - fTemp10)) / (fTemp7 + (-1.5f - fTemp11))));
			fRec12[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = ((fRec12[0] + (0.995000005f * fRec11[1])) - fRec12[1]);
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (0.0f - (((fRec9[1] * (1.0f - fTemp5)) - (fRec11[0] + fRec11[1])) / (fTemp5 + 1.0f)));
			fRec9[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp12 = (fRec9[0] * (0.99000001f - (0.0399999991f * fRec10[0])));
			fVec3[(IOTA & 32767)] = (fTemp4 - fTemp12);
			float fTemp13 = std::max<float>(-1.10000002f, std::min<float>(1.10000002f, fVec3[((IOTA - std::min<int>(16384, std::max<int>(0, int((fSlow8 * (std::max<float>(0.0199999996f, (0.449999988f * fRec8[0])) / fTemp6)))))) & 32767)]));
			float fTempFTZ10 = ((fTemp13 + (9.99999975e-05f * fTemp4)) - (fTemp12 + (0.333299994f * std::pow(fTemp13, 3.0f))));
			fRec3[(IOTA & 8191)] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fSlow9 + (0.0299999993f * fRec13[1]));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			output0[i0] = FAUSTFLOAT((0.0372281f * ((fRec0[0] * fRec3[((IOTA - 0) & 8191)]) * fRec13[0])));
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			iRec6[1] = iRec6[0];
			fRec7[1] = fRec7[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec9[1] = fRec9[0];
			fRec13[1] = fRec13[0];
		}
	}

};

#endif
