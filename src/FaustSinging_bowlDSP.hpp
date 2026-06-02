/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "singing_bowl"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSinging_bowlDSP_H__
#define  __FaustSinging_bowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustSinging_bowlDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSinging_bowlDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSinging_bowlDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	float fConst6;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fConst7;
	float fConst8;
	float fConst9;
	float fRec3[3];
	float fConst10;
	float fConst11;
	float fRec4[2];
	int iRec6[2];
	float fConst12;
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	float fRec5[3];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec1[3];
	float fConst18;
	float fConst19;
	float fConst20;
	float fRec8[3];
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec9[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec10[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "singing_bowl.dsp");
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
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "singing_bowl");
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
		float fConst3 = std::tan((12566.3711f / fConst0));
		float fConst4 = (1.0f / fConst3);
		float fConst5 = (((fConst4 + 1.41421354f) / fConst3) + 1.0f);
		fConst6 = (8.0f / fConst5);
		fConst7 = (1.0f / fConst5);
		fConst8 = (((fConst4 + -1.41421354f) / fConst3) + 1.0f);
		fConst9 = (2.0f * (1.0f - (1.0f / FaustSinging_bowlDSP_faustpower2_f(fConst3))));
		fConst10 = std::exp((0.0f - (10.0f / fConst0)));
		fConst11 = (1.0f - fConst10);
		fConst12 = (3.14159274f / fConst0);
		float fConst13 = std::pow(0.00100000005f, (0.0666666701f / fConst0));
		fConst14 = (0.0f - (2.0f * fConst13));
		fConst15 = (6.28318548f / fConst0);
		fConst16 = FaustSinging_bowlDSP_faustpower2_f(fConst13);
		float fConst17 = std::pow(0.00100000005f, (0.125f / fConst0));
		fConst18 = (0.0f - (2.0f * fConst17));
		fConst19 = (17.5929184f / fConst0);
		fConst20 = FaustSinging_bowlDSP_faustpower2_f(fConst17);
		float fConst21 = std::pow(0.00100000005f, (0.25f / fConst0));
		fConst22 = (0.0f - (2.0f * fConst21));
		fConst23 = (33.9291992f / fConst0);
		fConst24 = FaustSinging_bowlDSP_faustpower2_f(fConst21);
		float fConst25 = std::pow(0.00100000005f, (0.5f / fConst0));
		fConst26 = (0.0f - (2.0f * fConst25));
		fConst27 = (55.9203491f / fConst0);
		fConst28 = FaustSinging_bowlDSP_faustpower2_f(fConst25);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(110.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
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
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec1[l8] = 0.0f;
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
	
	virtual FaustSinging_bowlDSP* clone() {
		return new FaustSinging_bowlDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("singing_bowl");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(110.0f), FAUSTFLOAT(60.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = (fConst1 * float(fHslider1));
		float fSlow2 = float(fHslider2);
		float fSlow3 = (fConst6 * (1.0f - fSlow2));
		float fSlow4 = float(fButton0);
		int iSlow5 = (fSlow4 > 0.0f);
		float fSlow6 = (0.150000006f * fSlow2);
		float fSlow7 = (fConst11 * fSlow4);
		float fSlow8 = (fConst1 * float(fHslider3));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow1 + (fConst2 * fRec2[1]));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			fVec0[0] = fSlow4;
			float fTempFTZ2 = (float((iSlow5 & (fVec0[1] <= 0.0f))) - (fConst7 * ((fConst8 * fRec3[2]) + (fConst9 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow7 + (fConst10 * fRec4[1]));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fTempFTZ4 = (fSlow8 + (fConst2 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp0 = std::tan((fConst12 * fRec7[0]));
			float fTemp1 = (1.0f / fTemp0);
			float fTemp2 = (((fTemp1 + 0.5f) / fTemp0) + 1.0f);
			float fTempFTZ5 = ((4.65661287e-10f * float(iRec6[0])) - (((fRec5[2] * (((fTemp1 + -0.5f) / fTemp0) + 1.0f)) + (2.0f * (fRec5[1] * (1.0f - (1.0f / FaustSinging_bowlDSP_faustpower2_f(fTemp0)))))) / fTemp2));
			fRec5[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp3 = (fTemp0 * fTemp2);
			float fTemp4 = (fRec2[0] * ((fSlow3 * (fRec3[2] + (fRec3[0] + (2.0f * fRec3[1])))) + (fSlow6 * (fRec4[0] * ((fRec5[0] / fTemp3) + (fRec5[2] * (0.0f - (1.0f / fTemp3))))))));
			float fTempFTZ6 = (fTemp4 - ((fConst14 * (fRec1[1] * std::cos((fConst15 * fRec7[0])))) + (fConst16 * fRec1[2])));
			fRec1[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp4 - ((fConst18 * (fRec8[1] * std::cos((fConst19 * fRec7[0])))) + (fConst20 * fRec8[2])));
			fRec8[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp4 - ((fConst22 * (fRec9[1] * std::cos((fConst23 * fRec7[0])))) + (fConst24 * fRec9[2])));
			fRec9[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp4 - ((fConst26 * (fRec10[1] * std::cos((fConst27 * fRec7[0])))) + (fConst28 * fRec10[2])));
			fRec10[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((0.25f * (fRec0[0] * ((((fRec1[0] + (0.5f * (fRec8[0] - fRec8[2]))) + (0.200000003f * (fRec9[0] - fRec9[2]))) + (0.100000001f * (fRec10[0] - fRec10[2]))) - fRec1[2]))));
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fVec0[1] = fVec0[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			iRec6[1] = iRec6[0];
			fRec7[1] = fRec7[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
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
