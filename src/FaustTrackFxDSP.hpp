/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "track_fx"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTrackFxDSP_H__
#define  __FaustTrackFxDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustTrackFxDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTrackFxDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTrackFxDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fCheckbox1;
	int fSampleRate;
	float fConst0;
	float fConst2;
	float fConst3;
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider1;
	float fConst9;
	float fConst10;
	float fConst12;
	float fConst14;
	float fVec0[2];
	float fConst15;
	float fConst16;
	float fRec5[2];
	float fConst17;
	float fConst18;
	float fRec4[3];
	float fConst19;
	FAUSTFLOAT fHslider2;
	float fRec7[2];
	float fRec6[3];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst20;
	float fRec3[3];
	float fVec1[2];
	float fRec2[2];
	float fConst21;
	float fConst23;
	float fConst24;
	float fRec1[3];
	FAUSTFLOAT fHslider5;
	float fConst25;
	float fRec9[2];
	float fRec8[3];
	float fConst26;
	FAUSTFLOAT fHslider6;
	int iConst27;
	FAUSTFLOAT fHslider7;
	int IOTA;
	float fRec0[262144];
	float fVec2[2];
	float fRec15[2];
	float fRec14[3];
	float fRec17[2];
	float fRec16[3];
	float fRec13[3];
	float fVec3[2];
	float fRec12[2];
	float fRec11[3];
	float fRec19[2];
	float fRec18[3];
	float fRec10[262144];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.1");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "track_fx.dsp");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/low_shelf:author", "Julius O. Smith III");
		m->declare("filters.lib/low_shelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/low_shelf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/lowshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowshelf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "MIT-style STK-4.3 license");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "track_fx");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((7853.98145f / fConst0));
		fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / (((fConst2 + 1.0f) / fConst1) + 1.0f));
		float fConst4 = (fConst2 + 1.0f);
		fConst5 = (1.0f / fConst4);
		fConst6 = (1.0f - fConst2);
		fConst7 = (3.14159274f / fConst0);
		float fConst8 = std::tan((785.398193f / fConst0));
		fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f / (((fConst9 + 1.0f) / fConst8) + 1.0f));
		float fConst11 = FaustTrackFxDSP_faustpower2_f(fConst8);
		fConst12 = (1.0f / fConst11);
		float fConst13 = (fConst9 + 1.0f);
		fConst14 = (0.0f - (1.0f / (fConst8 * fConst13)));
		fConst15 = (1.0f / fConst13);
		fConst16 = (1.0f - fConst9);
		fConst17 = (((fConst9 + -1.0f) / fConst8) + 1.0f);
		fConst18 = (2.0f * (1.0f - fConst12));
		fConst19 = (0.0f - (2.0f / fConst11));
		fConst20 = (6.28318548f / fConst0);
		fConst21 = (((fConst2 + -1.0f) / fConst1) + 1.0f);
		float fConst22 = FaustTrackFxDSP_faustpower2_f(fConst1);
		fConst23 = (1.0f / fConst22);
		fConst24 = (2.0f * (1.0f - fConst23));
		fConst25 = (0.0f - (1.0f / (fConst1 * fConst4)));
		fConst26 = (0.0f - (2.0f / fConst22));
		iConst27 = int(fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(1000.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.29999999999999999f);
		fHslider7 = FAUSTFLOAT(0.25f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec5[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec7[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		IOTA = 0;
		for (int l11 = 0; (l11 < 262144); l11 = (l11 + 1)) {
			fRec0[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec2[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec15[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec17[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec16[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec13[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec3[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec12[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec11[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec19[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec18[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 262144); l23 = (l23 + 1)) {
			fRec10[l23] = 0.0f;
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
	
	virtual FaustTrackFxDSP* clone() {
		return new FaustTrackFxDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("track_fx");
		ui_interface->addHorizontalSlider("bass_db", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(-18.0f), FAUSTFLOAT(18.0f), FAUSTFLOAT(0.5f));
		ui_interface->addCheckButton("bypass_echo", &fCheckbox0);
		ui_interface->addCheckButton("bypass_eq", &fCheckbox1);
		ui_interface->addHorizontalSlider("echo_feedback", &fHslider6, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.949999988f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("echo_mix", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("echo_time", &fHslider7, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("mid_db", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(-18.0f), FAUSTFLOAT(18.0f), FAUSTFLOAT(0.5f));
		ui_interface->addHorizontalSlider("mid_freq", &fHslider1, FAUSTFLOAT(1000.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("mid_q", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(18.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("treble_db", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-18.0f), FAUSTFLOAT(18.0f), FAUSTFLOAT(0.5f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = int(float(fCheckbox0));
		float fSlow1 = float(fHslider0);
		int iSlow2 = int(float(fCheckbox1));
		float fSlow3 = float(fHslider1);
		float fSlow4 = std::tan((fConst7 * fSlow3));
		float fSlow5 = (2.0f * (1.0f - (1.0f / FaustTrackFxDSP_faustpower2_f(fSlow4))));
		float fSlow6 = std::pow(10.0f, (0.0500000007f * float(fHslider2)));
		float fSlow7 = (1.0f / fSlow4);
		float fSlow8 = float(fHslider3);
		int iSlow9 = (fSlow8 > 0.0f);
		float fSlow10 = (float(fHslider4) * std::sin((fConst20 * fSlow3)));
		float fSlow11 = (fConst7 * ((fSlow3 * std::pow(10.0f, (0.0500000007f * std::fabs(fSlow8)))) / fSlow10));
		float fSlow12 = (fConst7 * (fSlow3 / fSlow10));
		float fSlow13 = (iSlow9 ? fSlow12 : fSlow11);
		float fSlow14 = (1.0f - (fSlow7 * (fSlow13 - fSlow7)));
		float fSlow15 = ((fSlow7 * (fSlow7 + fSlow13)) + 1.0f);
		float fSlow16 = (iSlow9 ? fSlow11 : fSlow12);
		float fSlow17 = ((fSlow7 * (fSlow7 + fSlow16)) + 1.0f);
		float fSlow18 = (1.0f - (fSlow7 * (fSlow16 - fSlow7)));
		float fSlow19 = std::pow(10.0f, (0.0500000007f * float(fHslider5)));
		float fSlow20 = float(fHslider6);
		int iSlow21 = (std::min<int>(iConst27, std::max<int>(0, int((fConst0 * float(fHslider7))))) + 1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTemp0 = float(input0[i0]);
			float fTemp1 = (iSlow2 ? 0.0f : fTemp0);
			fVec0[0] = fTemp1;
			float fTempFTZ0 = ((fConst14 * fVec0[1]) - (fConst15 * ((fConst16 * fRec5[1]) - (fConst9 * fTemp1))));
			fRec5[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fRec5[0] - (fConst10 * ((fConst17 * fRec4[2]) + (fConst18 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (0.0f - (fConst15 * ((fConst16 * fRec7[1]) - (fTemp1 + fVec0[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fRec7[0] - (fConst10 * ((fConst17 * fRec6[2]) + (fConst18 * fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp2 = (fSlow5 * fRec3[1]);
			float fTempFTZ4 = ((fConst10 * ((((fConst12 * fRec4[0]) + (fConst19 * fRec4[1])) + (fConst12 * fRec4[2])) + (fSlow6 * (fRec6[2] + (fRec6[0] + (2.0f * fRec6[1])))))) - (((fRec3[2] * fSlow14) + fTemp2) / fSlow15));
			fRec3[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp3 = (((fTemp2 + (fRec3[0] * fSlow17)) + (fRec3[2] * fSlow18)) / fSlow15);
			fVec1[0] = fTemp3;
			float fTempFTZ5 = (0.0f - (fConst5 * ((fConst6 * fRec2[1]) - (fTemp3 + fVec1[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fRec2[0] - (fConst3 * ((fConst21 * fRec1[2]) + (fConst24 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((fConst25 * fVec1[1]) - (fConst5 * ((fConst6 * fRec9[1]) - (fConst2 * fTemp3))));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fRec9[0] - (fConst3 * ((fConst21 * fRec8[2]) + (fConst24 * fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fThen3 = (fConst3 * ((fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))) + (fSlow19 * (((fConst23 * fRec8[0]) + (fConst26 * fRec8[1])) + (fConst23 * fRec8[2])))));
			float fTemp4 = (iSlow2 ? fTemp0 : fThen3);
			float fTemp5 = (iSlow0 ? 0.0f : fTemp4);
			float fTempFTZ9 = (fTemp5 + (fSlow20 * fRec0[((IOTA - iSlow21) & 262143)]));
			fRec0[(IOTA & 262143)] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fThen5 = ((fSlow1 * fRec0[((IOTA - 0) & 262143)]) + fTemp5);
			output0[i0] = FAUSTFLOAT((iSlow0 ? fTemp4 : fThen5));
			float fTemp6 = float(input1[i0]);
			float fTemp7 = (iSlow2 ? 0.0f : fTemp6);
			fVec2[0] = fTemp7;
			float fTempFTZ10 = ((fConst14 * fVec2[1]) - (fConst15 * ((fConst16 * fRec15[1]) - (fConst9 * fTemp7))));
			fRec15[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fRec15[0] - (fConst10 * ((fConst17 * fRec14[2]) + (fConst18 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (0.0f - (fConst15 * ((fConst16 * fRec17[1]) - (fTemp7 + fVec2[1]))));
			fRec17[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fRec17[0] - (fConst10 * ((fConst17 * fRec16[2]) + (fConst18 * fRec16[1]))));
			fRec16[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp8 = (fSlow5 * fRec13[1]);
			float fTempFTZ14 = ((fConst10 * ((((fConst12 * fRec14[0]) + (fConst19 * fRec14[1])) + (fConst12 * fRec14[2])) + (fSlow6 * (fRec16[2] + (fRec16[0] + (2.0f * fRec16[1])))))) - (((fSlow14 * fRec13[2]) + fTemp8) / fSlow15));
			fRec13[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp9 = (((fTemp8 + (fRec13[0] * fSlow17)) + (fSlow18 * fRec13[2])) / fSlow15);
			fVec3[0] = fTemp9;
			float fTempFTZ15 = (0.0f - (fConst5 * ((fConst6 * fRec12[1]) - (fTemp9 + fVec3[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fRec12[0] - (fConst3 * ((fConst21 * fRec11[2]) + (fConst24 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = ((fConst25 * fVec3[1]) - (fConst5 * ((fConst6 * fRec19[1]) - (fConst2 * fTemp9))));
			fRec19[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fRec19[0] - (fConst3 * ((fConst21 * fRec18[2]) + (fConst24 * fRec18[1]))));
			fRec18[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fThen7 = (fConst3 * ((fRec11[2] + (fRec11[0] + (2.0f * fRec11[1]))) + (fSlow19 * (((fConst23 * fRec18[0]) + (fConst26 * fRec18[1])) + (fConst23 * fRec18[2])))));
			float fTemp10 = (iSlow2 ? fTemp6 : fThen7);
			float fTemp11 = (iSlow0 ? 0.0f : fTemp10);
			float fTempFTZ19 = (fTemp11 + (fSlow20 * fRec10[((IOTA - iSlow21) & 262143)]));
			fRec10[(IOTA & 262143)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fThen9 = ((fSlow1 * fRec10[((IOTA - 0) & 262143)]) + fTemp11);
			output1[i0] = FAUSTFLOAT((iSlow0 ? fTemp10 : fThen9));
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fVec1[1] = fVec1[0];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fVec3[1] = fVec3[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
		}
	}

};

#endif
