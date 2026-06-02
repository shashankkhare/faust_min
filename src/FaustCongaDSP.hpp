/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "conga"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustCongaDSP_H__
#define  __FaustCongaDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustCongaDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustCongaDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustCongaDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	float fConst3;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int iRec5[2];
	float fConst4;
	FAUSTFLOAT fHslider3;
	float fRec4[3];
	float fRec3[3];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	int iRec6[2];
	float fConst5;
	FAUSTFLOAT fHslider4;
	float fConst6;
	float fConst7;
	float fRec2[3];
	float fConst8;
	float fConst9;
	float fRec7[3];
	float fConst10;
	float fConst11;
	float fRec8[3];
	float fConst12;
	float fConst13;
	float fRec9[3];
	float fConst14;
	float fConst15;
	float fRec10[3];
	float fConst16;
	float fConst17;
	float fRec11[3];
	float fRec1[3];
	
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
		m->declare("filename", "conga.dsp");
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
		m->declare("name", "conga");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
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
		fConst3 = (12.566371f / fConst0);
		fConst4 = (3.14159274f / fConst0);
		fConst5 = (0.00200000009f * fConst0);
		fConst6 = (6.28318548f / fConst0);
		fConst7 = (2.0f / fConst0);
		fConst8 = (9.99026489f / fConst0);
		fConst9 = (2.85714293f / fConst0);
		fConst10 = (13.4460163f / fConst0);
		fConst11 = (4.0f / fConst0);
		fConst12 = (14.4513264f / fConst0);
		fConst13 = (5.0f / fConst0);
		fConst14 = (16.6504402f / fConst0);
		fConst15 = (6.66666651f / fConst0);
		fConst16 = (18.3469009f / fConst0);
		fConst17 = (10.0f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(150.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec5[l1] = 0;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec1[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec6[l6] = 0;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec1[l13] = 0.0f;
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
	
	virtual FaustCongaDSP* clone() {
		return new FaustCongaDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("conga");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(150.0f), FAUSTFLOAT(80.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("position", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("strike", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::tan((fConst3 * fSlow1));
		float fSlow3 = (1.0f / fSlow2);
		float fSlow4 = (1.0f / (((fSlow3 + 1.41421354f) / fSlow2) + 1.0f));
		float fSlow5 = float(fHslider2);
		int iSlow6 = int(float(fHslider3));
		float fThen1 = ((iSlow6 >= 1) ? 0.5f : 0.100000001f);
		float fSlow7 = ((iSlow6 >= 2) ? 0.899999976f : fThen1);
		float fSlow8 = std::tan((fConst4 * ((500.0f * fSlow7) + 40.0f)));
		float fSlow9 = (1.0f / fSlow8);
		float fSlow10 = (((fSlow9 + -1.41421354f) / fSlow8) + 1.0f);
		float fSlow11 = FaustCongaDSP_faustpower2_f(fSlow8);
		float fSlow12 = (1.0f - (1.0f / fSlow11));
		float fSlow13 = (((fSlow9 + 1.41421354f) / fSlow8) + 1.0f);
		float fSlow14 = (0.0f - (2.0f / fSlow11));
		float fSlow15 = std::tan((fConst4 * ((15000.0f * fSlow7) + 500.0f)));
		float fSlow16 = (1.0f / fSlow15);
		float fSlow17 = (((fSlow16 + -1.41421354f) / fSlow15) + 1.0f);
		float fSlow18 = (1.0f - (1.0f / FaustCongaDSP_faustpower2_f(fSlow15)));
		float fSlow19 = (((fSlow16 + 1.41421354f) / fSlow15) + 1.0f);
		float fSlow20 = float(fButton0);
		int iSlow21 = (fSlow20 > 0.0f);
		int iSlow22 = int(float(fHslider4));
		int iSlow23 = (iSlow22 >= 2);
		int iSlow24 = (iSlow22 >= 1);
		float fThen3 = (iSlow24 ? 0.649999976f : 0.25f);
		float fSlow25 = std::max<float>(1.0f, (fConst5 * (iSlow23 ? 1.29999995f : fThen3)));
		float fSlow26 = std::cos((fConst6 * fSlow1));
		float fThen5 = (iSlow24 ? 0.600000024f : 1.0f);
		float fSlow27 = (iSlow23 ? 0.150000006f : fThen5);
		float fSlow28 = std::pow(0.00100000005f, (fConst7 / fSlow27));
		float fSlow29 = (0.0f - (2.0f * fSlow28));
		float fSlow30 = FaustCongaDSP_faustpower2_f(fSlow28);
		float fSlow31 = std::cos((fConst8 * fSlow1));
		float fSlow32 = std::pow(0.00100000005f, (fConst9 / fSlow27));
		float fSlow33 = (0.0f - (2.0f * fSlow32));
		float fSlow34 = FaustCongaDSP_faustpower2_f(fSlow32);
		float fSlow35 = std::cos((fConst10 * fSlow1));
		float fSlow36 = std::pow(0.00100000005f, (fConst11 / fSlow27));
		float fSlow37 = (0.0f - (2.0f * fSlow36));
		float fSlow38 = FaustCongaDSP_faustpower2_f(fSlow36);
		float fSlow39 = std::cos((fConst12 * fSlow1));
		float fSlow40 = std::pow(0.00100000005f, (fConst13 / fSlow27));
		float fSlow41 = (0.0f - (2.0f * fSlow40));
		float fSlow42 = FaustCongaDSP_faustpower2_f(fSlow40);
		float fSlow43 = std::cos((fConst14 * fSlow1));
		float fSlow44 = std::pow(0.00100000005f, (fConst15 / fSlow27));
		float fSlow45 = (0.0f - (2.0f * fSlow44));
		float fSlow46 = FaustCongaDSP_faustpower2_f(fSlow44);
		float fSlow47 = std::cos((fConst16 * fSlow1));
		float fSlow48 = std::pow(0.00100000005f, (fConst17 / fSlow27));
		float fSlow49 = (0.0f - (2.0f * fSlow48));
		float fSlow50 = FaustCongaDSP_faustpower2_f(fSlow48);
		float fSlow51 = (((fSlow3 + -1.41421354f) / fSlow2) + 1.0f);
		float fSlow52 = (2.0f * (1.0f - (1.0f / FaustCongaDSP_faustpower2_f(fSlow2))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float fTempFTZ1 = ((4.65661287e-10f * float(iRec5[0])) - (((fRec4[2] * fSlow10) + (2.0f * (fRec4[1] * fSlow12))) / fSlow13));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (((((fRec4[1] * fSlow14) + (fRec4[0] / fSlow11)) + (fRec4[2] / fSlow11)) / fSlow13) - (((fRec3[2] * fSlow17) + (2.0f * (fRec3[1] * fSlow18))) / fSlow19));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			fVec0[0] = fSlow20;
			int iTemp0 = (iSlow21 & (fVec0[1] <= 0.0f));
			iVec1[0] = iTemp0;
			iRec6[0] = (((iRec6[1] + (iRec6[1] > 0)) * (iTemp0 <= iVec1[1])) + (iTemp0 > iVec1[1]));
			float fTemp1 = (float(iRec6[0]) / fSlow25);
			float fTemp2 = (fSlow5 * (((fRec3[2] + (fRec3[0] + (2.0f * fRec3[1]))) * std::max<float>(0.0f, std::min<float>(fTemp1, (2.0f - fTemp1)))) / fSlow19));
			float fTempFTZ3 = (fTemp2 - ((fSlow26 * (fRec2[1] * fSlow29)) + (fSlow30 * fRec2[2])));
			fRec2[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp2 - ((fSlow31 * (fRec7[1] * fSlow33)) + (fSlow34 * fRec7[2])));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp2 - ((fSlow35 * (fRec8[1] * fSlow37)) + (fSlow38 * fRec8[2])));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp2 - ((fSlow39 * (fRec9[1] * fSlow41)) + (fSlow42 * fRec9[2])));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp2 - ((fSlow43 * (fRec10[1] * fSlow45)) + (fSlow46 * fRec10[2])));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp2 - ((fSlow47 * (fRec11[1] * fSlow49)) + (fSlow50 * fRec11[2])));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((0.166666672f * ((((((fRec2[0] + (0.25f * (fRec7[0] - fRec7[2]))) + (0.111111112f * (fRec8[0] - fRec8[2]))) + (0.0625f * (fRec9[0] - fRec9[2]))) + (0.0399999991f * (fRec10[0] - fRec10[2]))) + (0.027777778f * (fRec11[0] - fRec11[2]))) - fRec2[2])) - (fSlow4 * ((fSlow51 * fRec1[2]) + (fSlow52 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((1.5f * (fRec0[0] * float(tanhf(float((fSlow4 * (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))))))))));
			fRec0[1] = fRec0[0];
			iRec5[1] = iRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec6[1] = iRec6[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
