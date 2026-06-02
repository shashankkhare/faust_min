/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "bongo"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBongoDSP_H__
#define  __FaustBongoDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustBongoDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBongoDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBongoDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	int iRec4[2];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec3[3];
	float fRec2[3];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	int iRec5[2];
	float fConst4;
	FAUSTFLOAT fHslider3;
	float fConst5;
	FAUSTFLOAT fHslider4;
	float fConst6;
	float fRec1[3];
	float fConst7;
	float fConst8;
	float fRec6[3];
	float fConst9;
	float fConst10;
	float fRec7[3];
	float fConst11;
	float fConst12;
	float fRec8[3];
	float fConst13;
	float fConst14;
	float fRec9[3];
	float fConst15;
	float fConst16;
	float fRec10[3];
	float fConst17;
	float fConst18;
	
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
		m->declare("filename", "bongo.dsp");
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
		m->declare("name", "bongo");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (3.14159274f / fConst0);
		fConst4 = (0.00200000009f * fConst0);
		fConst5 = (6.28318548f / fConst0);
		fConst6 = (5.0f / fConst0);
		fConst7 = (10.1787605f / fConst0);
		fConst8 = (8.33333302f / fConst0);
		fConst9 = (13.8230076f / fConst0);
		fConst10 = (12.5f / fConst0);
		fConst11 = (17.3415909f / fConst0);
		fConst12 = (16.666666f / fConst0);
		fConst13 = (19.4778748f / fConst0);
		fConst14 = (25.0f / fConst0);
		fConst15 = (21.3628292f / fConst0);
		fConst16 = (50.0f / fConst0);
		fConst17 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst18 = (1.0f / fConst17);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(300.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec4[l1] = 0;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec0[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec1[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec5[l6] = 0;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
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
	
	virtual FaustBongoDSP* clone() {
		return new FaustBongoDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bongo");
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(300.0f), FAUSTFLOAT(150.0f), FAUSTFLOAT(600.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("position", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("strike", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = float(fHslider1);
		int iSlow2 = int(float(fHslider2));
		float fThen1 = ((iSlow2 >= 1) ? 0.550000012f : 0.150000006f);
		float fSlow3 = ((iSlow2 >= 2) ? 0.949999988f : fThen1);
		float fSlow4 = std::tan((fConst3 * ((500.0f * fSlow3) + 40.0f)));
		float fSlow5 = (1.0f / fSlow4);
		float fSlow6 = (((fSlow5 + -1.41421354f) / fSlow4) + 1.0f);
		float fSlow7 = FaustBongoDSP_faustpower2_f(fSlow4);
		float fSlow8 = (1.0f - (1.0f / fSlow7));
		float fSlow9 = (((fSlow5 + 1.41421354f) / fSlow4) + 1.0f);
		float fSlow10 = (0.0f - (2.0f / fSlow7));
		float fSlow11 = std::tan((fConst3 * ((15000.0f * fSlow3) + 500.0f)));
		float fSlow12 = (1.0f / fSlow11);
		float fSlow13 = (((fSlow12 + -1.41421354f) / fSlow11) + 1.0f);
		float fSlow14 = (1.0f - (1.0f / FaustBongoDSP_faustpower2_f(fSlow11)));
		float fSlow15 = (((fSlow12 + 1.41421354f) / fSlow11) + 1.0f);
		float fSlow16 = float(fButton0);
		int iSlow17 = (fSlow16 > 0.0f);
		int iSlow18 = int(float(fHslider3));
		int iSlow19 = (iSlow18 >= 2);
		int iSlow20 = (iSlow18 >= 1);
		float fThen3 = (iSlow20 ? 0.949999988f : 0.449999988f);
		float fSlow21 = std::max<float>(1.0f, (fConst4 * (iSlow19 ? 1.79999995f : fThen3)));
		float fSlow22 = float(fHslider4);
		float fSlow23 = std::cos((fConst5 * fSlow22));
		float fThen5 = (iSlow20 ? 0.400000006f : 1.0f);
		float fSlow24 = (iSlow19 ? 0.100000001f : fThen5);
		float fSlow25 = std::pow(0.00100000005f, (fConst6 / fSlow24));
		float fSlow26 = (0.0f - (2.0f * fSlow25));
		float fSlow27 = FaustBongoDSP_faustpower2_f(fSlow25);
		float fSlow28 = std::cos((fConst7 * fSlow22));
		float fSlow29 = std::pow(0.00100000005f, (fConst8 / fSlow24));
		float fSlow30 = (0.0f - (2.0f * fSlow29));
		float fSlow31 = FaustBongoDSP_faustpower2_f(fSlow29);
		float fSlow32 = std::cos((fConst9 * fSlow22));
		float fSlow33 = std::pow(0.00100000005f, (fConst10 / fSlow24));
		float fSlow34 = (0.0f - (2.0f * fSlow33));
		float fSlow35 = FaustBongoDSP_faustpower2_f(fSlow33);
		float fSlow36 = std::cos((fConst11 * fSlow22));
		float fSlow37 = std::pow(0.00100000005f, (fConst12 / fSlow24));
		float fSlow38 = (0.0f - (2.0f * fSlow37));
		float fSlow39 = FaustBongoDSP_faustpower2_f(fSlow37);
		float fSlow40 = std::cos((fConst13 * fSlow22));
		float fSlow41 = std::pow(0.00100000005f, (fConst14 / fSlow24));
		float fSlow42 = (0.0f - (2.0f * fSlow41));
		float fSlow43 = FaustBongoDSP_faustpower2_f(fSlow41);
		float fSlow44 = std::cos((fConst15 * fSlow22));
		float fSlow45 = std::pow(0.00100000005f, (fConst16 / fSlow24));
		float fSlow46 = (0.0f - (2.0f * fSlow45));
		float fSlow47 = FaustBongoDSP_faustpower2_f(fSlow45);
		float fThen7 = (iSlow20 ? 0.0799999982f : 0.180000007f);
		float fSlow48 = std::max<float>(1.0f, (fConst0 * (iSlow19 ? 0.0199999996f : fThen7)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTempFTZ1 = ((4.65661287e-10f * float(iRec4[0])) - (((fRec3[2] * fSlow6) + (2.0f * (fRec3[1] * fSlow8))) / fSlow9));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (((((fRec3[1] * fSlow10) + (fRec3[0] / fSlow7)) + (fRec3[2] / fSlow7)) / fSlow9) - (((fRec2[2] * fSlow13) + (2.0f * (fRec2[1] * fSlow14))) / fSlow15));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			fVec0[0] = fSlow16;
			int iTemp0 = (iSlow17 & (fVec0[1] <= 0.0f));
			iVec1[0] = iTemp0;
			iRec5[0] = (((iRec5[1] + (iRec5[1] > 0)) * (iTemp0 <= iVec1[1])) + (iTemp0 > iVec1[1]));
			float fTemp1 = float(iRec5[0]);
			float fTemp2 = (fTemp1 / fSlow21);
			float fTemp3 = (fSlow1 * (((fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))) * std::max<float>(0.0f, std::min<float>(fTemp2, (2.0f - fTemp2)))) / fSlow15));
			float fTempFTZ3 = (fTemp3 - ((fSlow23 * (fRec1[1] * fSlow26)) + (fSlow27 * fRec1[2])));
			fRec1[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp3 - ((fSlow28 * (fRec6[1] * fSlow30)) + (fSlow31 * fRec6[2])));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp3 - ((fSlow32 * (fRec7[1] * fSlow34)) + (fSlow35 * fRec7[2])));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp3 - ((fSlow36 * (fRec8[1] * fSlow38)) + (fSlow39 * fRec8[2])));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp3 - ((fSlow40 * (fRec9[1] * fSlow42)) + (fSlow43 * fRec9[2])));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp3 - ((fSlow44 * (fRec10[1] * fSlow46)) + (fSlow47 * fRec10[2])));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			output0[i0] = FAUSTFLOAT((0.666666687f * ((fRec0[0] * ((((((fRec1[0] + (0.25f * (fRec6[0] - fRec6[2]))) + (0.111111112f * (fRec7[0] - fRec7[2]))) + (0.0625f * (fRec8[0] - fRec8[2]))) + (0.0399999991f * (fRec9[0] - fRec9[2]))) + (0.027777778f * (fRec10[0] - fRec10[2]))) - fRec1[2])) * std::max<float>(0.0f, std::min<float>((fConst18 * fTemp1), (((fConst17 - fTemp1) / fSlow48) + 1.0f))))));
			fRec0[1] = fRec0[0];
			iRec4[1] = iRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec5[1] = iRec5[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
		}
	}

};

#endif
