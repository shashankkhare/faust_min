/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "churchbell"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustChurchbellDSP_H__
#define  __FaustChurchbellDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustChurchbellDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustChurchbellDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustChurchbellDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int fSampleRate;
	float fConst2;
	float fConst3;
	float fConst4;
	float fRec1[3];
	float fConst6;
	float fConst7;
	float fConst8;
	float fRec2[3];
	float fConst10;
	float fConst11;
	float fConst12;
	float fRec3[3];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec4[3];
	float fConst18;
	float fConst19;
	float fConst20;
	float fRec5[3];
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec6[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec7[3];
	float fVec1[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "churchbell.dsp");
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
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "churchbell");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
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
		float fConst1 = std::min<float>(0.999989986f, std::pow(0.00100000005f, (0.25f / fConst0)));
		fConst2 = (0.0f - (2.0f * fConst1));
		fConst3 = (18.849556f / fConst0);
		fConst4 = FaustChurchbellDSP_faustpower2_f(fConst1);
		float fConst5 = std::min<float>(0.999989986f, std::pow(0.00100000005f, (0.166666672f / fConst0)));
		fConst6 = (0.0f - (2.0f * fConst5));
		fConst7 = (15.0796452f / fConst0);
		fConst8 = FaustChurchbellDSP_faustpower2_f(fConst5);
		float fConst9 = std::min<float>(0.999989986f, std::pow(0.00100000005f, (0.100000001f / fConst0)));
		fConst10 = (0.0f - (2.0f * fConst9));
		fConst11 = (6.28318548f / fConst0);
		fConst12 = FaustChurchbellDSP_faustpower2_f(fConst9);
		float fConst13 = std::min<float>(0.999989986f, std::pow(0.00100000005f, (0.125f / fConst0)));
		fConst14 = (0.0f - (2.0f * fConst13));
		fConst15 = (12.566371f / fConst0);
		fConst16 = FaustChurchbellDSP_faustpower2_f(fConst13);
		float fConst17 = std::min<float>(0.999989986f, std::pow(0.00100000005f, (0.333333343f / fConst0)));
		fConst18 = (0.0f - (2.0f * fConst17));
		fConst19 = (25.1327419f / fConst0);
		fConst20 = FaustChurchbellDSP_faustpower2_f(fConst17);
		float fConst21 = std::min<float>(0.999989986f, std::pow(0.00100000005f, (0.5f / fConst0)));
		fConst22 = (0.0f - (2.0f * fConst21));
		fConst23 = (37.6991119f / fConst0);
		fConst24 = FaustChurchbellDSP_faustpower2_f(fConst21);
		float fConst25 = std::min<float>(0.999989986f, std::pow(0.00100000005f, (1.0f / fConst0)));
		fConst26 = (0.0f - (2.0f * fConst25));
		fConst27 = (50.2654839f / fConst0);
		fConst28 = FaustChurchbellDSP_faustpower2_f(fConst25);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fHslider1 = FAUSTFLOAT(200.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec0[l9] = 0.0f;
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
	
	virtual FaustChurchbellDSP* clone() {
		return new FaustChurchbellDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("churchbell");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(200.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (12.25f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (0.00681818184f * (fSlow1 * float(fHslider2)));
		float fSlow3 = float(fButton0);
		float fSlow4 = (fConst2 * std::cos((fConst3 * fSlow1)));
		float fSlow5 = (fConst6 * std::cos((fConst7 * fSlow1)));
		float fSlow6 = (fConst10 * std::cos((fConst11 * fSlow1)));
		float fSlow7 = (fConst14 * std::cos((fConst15 * fSlow1)));
		float fSlow8 = (fConst18 * std::cos((fConst19 * fSlow1)));
		float fSlow9 = (fConst22 * std::cos((fConst23 * fSlow1)));
		float fSlow10 = (fConst26 * std::cos((fConst27 * fSlow1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow3;
			float fTemp0 = (fSlow3 - fVec0[1]);
			float fTemp1 = (fSlow2 * (fTemp0 * float((fTemp0 > 0.0f))));
			fRec1[0] = (fTemp1 - ((fSlow4 * fRec1[1]) + (fConst4 * fRec1[2])));
			fRec2[0] = (fTemp1 - ((fSlow5 * fRec2[1]) + (fConst8 * fRec2[2])));
			fRec3[0] = (fTemp1 - ((fSlow6 * fRec3[1]) + (fConst12 * fRec3[2])));
			fRec4[0] = (fTemp1 - ((fSlow7 * fRec4[1]) + (fConst16 * fRec4[2])));
			fRec5[0] = (fTemp1 - ((fSlow8 * fRec5[1]) + (fConst20 * fRec5[2])));
			fRec6[0] = (fTemp1 - ((fSlow9 * fRec6[1]) + (fConst24 * fRec6[2])));
			fRec7[0] = (fTemp1 - ((fSlow10 * fRec7[1]) + (fConst28 * fRec7[2])));
			float fTemp2 = (((((0.600000024f * (fRec1[0] - fRec1[2])) + ((0.800000012f * (fRec2[0] - fRec2[2])) + ((0.899999976f * (fRec3[0] - fRec3[2])) + (fRec4[0] + fRec5[0])))) + (0.400000006f * (fRec6[0] - fRec6[2]))) + (0.200000003f * (fRec7[0] - fRec7[2]))) - (fRec4[2] + fRec5[2]));
			fVec1[0] = fTemp2;
			fRec0[0] = ((0.995000005f * fRec0[1]) + (0.142857149f * (fTemp2 - fVec1[1])));
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * fRec0[0])))));
			fVec0[1] = fVec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec1[1] = fVec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
