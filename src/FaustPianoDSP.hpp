/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "piano"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustPianoDSP_H__
#define  __FaustPianoDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustPianoDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustPianoDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustPianoDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	FAUSTFLOAT fHslider3;
	float fRec2[2];
	int iRec3[2];
	float fConst2;
	float fVec1[2];
	float fRec1[2];
	FAUSTFLOAT fHslider4;
	float fRec5[2];
	float fVec2[2];
	float fRec4[2];
	int IOTA;
	float fRec0[8192];
	float fConst3;
	float fRec8[2];
	float fVec3[2];
	float fRec7[2];
	float fRec6[8192];
	float fConst4;
	float fRec11[2];
	float fVec4[2];
	float fRec10[2];
	float fRec9[8192];
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fRec12[3];
	float fConst17;
	float fConst18;
	float fConst19;
	float fConst20;
	float fRec13[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec14[3];
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fRec15[3];
	float fConst37;
	float fConst38;
	float fConst39;
	float fConst40;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "piano.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "piano");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (1.0f / fConst0);
		fConst3 = (0.999700069f * fConst0);
		fConst4 = (1.00030005f * fConst0);
		float fConst5 = std::tan((345.575195f / fConst0));
		float fConst6 = (1.0f / fConst5);
		float fConst7 = (((fConst6 + 0.166666672f) / fConst5) + 1.0f);
		float fConst8 = (fConst5 * fConst7);
		fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f / fConst7);
		fConst11 = (((fConst6 + -0.166666672f) / fConst5) + 1.0f);
		fConst12 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst5))));
		float fConst13 = std::tan((691.150391f / fConst0));
		float fConst14 = (1.0f / fConst13);
		float fConst15 = (((fConst14 + 0.200000003f) / fConst13) + 1.0f);
		float fConst16 = (fConst13 * fConst15);
		fConst17 = (1.0f / fConst16);
		fConst18 = (1.0f / fConst15);
		fConst19 = (((fConst14 + -0.200000003f) / fConst13) + 1.0f);
		fConst20 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst13))));
		float fConst21 = std::tan((1382.30078f / fConst0));
		float fConst22 = (1.0f / fConst21);
		float fConst23 = (((fConst22 + 0.25f) / fConst21) + 1.0f);
		float fConst24 = (fConst21 * fConst23);
		fConst25 = (1.0f / fConst24);
		fConst26 = (1.0f / fConst23);
		fConst27 = (((fConst22 + -0.25f) / fConst21) + 1.0f);
		fConst28 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst21))));
		float fConst29 = std::tan((2764.60156f / fConst0));
		float fConst30 = (1.0f / fConst29);
		float fConst31 = (((fConst30 + 0.333333343f) / fConst29) + 1.0f);
		float fConst32 = (fConst29 * fConst31);
		fConst33 = (1.0f / fConst32);
		fConst34 = (1.0f / fConst31);
		fConst35 = (((fConst30 + -0.333333343f) / fConst29) + 1.0f);
		fConst36 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst29))));
		fConst37 = (0.0f - (0.800000012f / fConst8));
		fConst38 = (0.0f - (0.800000012f / fConst16));
		fConst39 = (0.0f - (0.800000012f / fConst24));
		fConst40 = (0.0f - (0.800000012f / fConst32));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.69999999999999996f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(110.0f);
		fHslider4 = FAUSTFLOAT(0.25f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec3[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec4[l7] = 0.0f;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 8192); l8 = (l8 + 1)) {
			fRec0[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 8192); l12 = (l12 + 1)) {
			fRec6[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fVec4[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec10[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 8192); l16 = (l16 + 1)) {
			fRec9[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec12[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec13[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec14[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec15[l20] = 0.0f;
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
	
	virtual FaustPianoDSP* clone() {
		return new FaustPianoDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("piano");
		ui_interface->addHorizontalSlider("brightness", &fHslider1, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(110.0f), FAUSTFLOAT(27.5f), FAUSTFLOAT(4186.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("stiffness", &fHslider4, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (1.5f * float(fHslider0));
		float fSlow1 = float(fHslider2);
		float fSlow2 = (1.0f / std::tan((fConst1 * ((8000.0f * (float(fHslider1) * fSlow1)) + 1500.0f))));
		float fSlow3 = (1.0f / (fSlow2 + 1.0f));
		float fSlow4 = (1.0f - fSlow2);
		float fSlow5 = float(fButton0);
		float fSlow6 = float(fHslider3);
		float fSlow7 = std::max<float>(0.00300000003f, (2.0f / fSlow6));
		float fSlow8 = (fConst0 * fSlow7);
		float fSlow9 = (0.699999988f * std::sqrt((0.00383141753f * std::max<float>(55.0f, fSlow6))));
		float fSlow10 = (6.28318548f * (fSlow6 * fSlow7));
		float fSlow11 = (fConst2 / fSlow7);
		float fSlow12 = std::max<float>(20.0f, fSlow6);
		float fSlow13 = ((fSlow5 * std::max<float>(0.699999988f, (1.0f - (4.5999999f / fSlow12)))) + (std::max<float>(0.5f, (1.0f - (17.2999992f / fSlow12))) * (1.0f - fSlow5)));
		float fSlow14 = (1.0f / std::tan((fConst1 * (6000.0f - (0.800000012f * fSlow6)))));
		float fSlow15 = (1.0f / (fSlow14 + 1.0f));
		float fSlow16 = (1.0f - fSlow14);
		float fSlow17 = ((0.119999997f * float(fHslider4)) + 0.0199999996f);
		float fSlow18 = std::sin(fSlow17);
		float fSlow19 = (fConst0 / fSlow6);
		float fSlow20 = std::floor(fSlow19);
		float fSlow21 = (fSlow20 + (1.0f - fSlow19));
		int iSlow22 = int(fSlow19);
		int iSlow23 = (std::min<int>(8193, std::max<int>(0, iSlow22)) + 1);
		float fSlow24 = (fSlow19 - fSlow20);
		int iSlow25 = (std::min<int>(8193, std::max<int>(0, (iSlow22 + 1))) + 1);
		float fSlow26 = std::cos(fSlow17);
		float fSlow27 = (fConst3 / fSlow6);
		float fSlow28 = std::floor(fSlow27);
		float fSlow29 = (fSlow28 + (1.0f - fSlow27));
		int iSlow30 = int(fSlow27);
		int iSlow31 = (std::min<int>(8193, std::max<int>(0, iSlow30)) + 1);
		float fSlow32 = (fSlow27 - fSlow28);
		int iSlow33 = (std::min<int>(8193, std::max<int>(0, (iSlow30 + 1))) + 1);
		float fSlow34 = (fConst4 / fSlow6);
		float fSlow35 = std::floor(fSlow34);
		float fSlow36 = (fSlow35 + (1.0f - fSlow34));
		int iSlow37 = int(fSlow34);
		int iSlow38 = (std::min<int>(8193, std::max<int>(0, iSlow37)) + 1);
		float fSlow39 = (fSlow34 - fSlow35);
		int iSlow40 = (std::min<int>(8193, std::max<int>(0, (iSlow37 + 1))) + 1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow5;
			float fThen0 = std::max<float>(0.0f, (fRec2[1] + -1.0f));
			float fTempFTZ0 = ((float(((fSlow5 - fVec0[1]) > 0.0f)) > 0.0f) ? fSlow8 : fThen0);
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			float fTemp0 = (fSlow1 * (float((fRec2[0] > 0.0f)) * ((1.39698392e-10f * float(iRec3[0])) + (fSlow9 * std::sin((fSlow10 * (1.0f - (fSlow11 * fRec2[0]))))))));
			fVec1[0] = fTemp0;
			float fTempFTZ1 = (0.0f - (fSlow3 * ((fSlow4 * fRec1[1]) - (fTemp0 + fVec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp1 = ((fSlow21 * fRec0[((IOTA - iSlow23) & 8191)]) + (fSlow24 * fRec0[((IOTA - iSlow25) & 8191)]));
			float fTempFTZ2 = ((fSlow26 * fTemp1) - (fSlow18 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp2 = ((fSlow18 * fTemp1) + (fSlow26 * fRec5[1]));
			fVec2[0] = fTemp2;
			float fTempFTZ3 = (0.0f - (fSlow15 * ((fSlow16 * fRec4[1]) - (fTemp2 + fVec2[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fRec1[0] + (fSlow13 * fRec4[0]));
			fRec0[(IOTA & 8191)] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp3 = ((fSlow29 * fRec6[((IOTA - iSlow31) & 8191)]) + (fSlow32 * fRec6[((IOTA - iSlow33) & 8191)]));
			float fTempFTZ5 = ((fSlow26 * fTemp3) - (fSlow18 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp4 = ((fSlow18 * fTemp3) + (fSlow26 * fRec8[1]));
			fVec3[0] = fTemp4;
			float fTempFTZ6 = (0.0f - (fSlow15 * ((fSlow16 * fRec7[1]) - (fTemp4 + fVec3[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fRec1[0] + (fSlow13 * fRec7[0]));
			fRec6[(IOTA & 8191)] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp5 = ((fSlow36 * fRec9[((IOTA - iSlow38) & 8191)]) + (fSlow39 * fRec9[((IOTA - iSlow40) & 8191)]));
			float fTempFTZ8 = ((fSlow26 * fTemp5) - (fSlow18 * fRec11[1]));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp6 = ((fSlow18 * fTemp5) + (fSlow26 * fRec11[1]));
			fVec4[0] = fTemp6;
			float fTempFTZ9 = (0.0f - (fSlow15 * ((fSlow16 * fRec10[1]) - (fTemp6 + fVec4[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fRec1[0] + (fSlow13 * fRec10[0]));
			fRec9[(IOTA & 8191)] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp7 = ((0.400000006f * fRec0[((IOTA - 0) & 8191)]) + (0.300000012f * (fRec6[((IOTA - 0) & 8191)] + fRec9[((IOTA - 0) & 8191)])));
			float fTempFTZ11 = (fTemp7 - (fConst10 * ((fConst11 * fRec12[2]) + (fConst12 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fTemp7 - (fConst18 * ((fConst19 * fRec13[2]) + (fConst20 * fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp7 - (fConst26 * ((fConst27 * fRec14[2]) + (fConst28 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fTemp7 - (fConst34 * ((fConst35 * fRec15[2]) + (fConst36 * fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp8 = (fTemp7 + (0.0799999982f * ((0.800000012f * ((((fConst9 * fRec12[0]) + (fConst17 * fRec13[0])) + (fConst25 * fRec14[0])) + (fConst33 * fRec15[0]))) + ((((fConst37 * fRec12[2]) + (fConst38 * fRec13[2])) + (fConst39 * fRec14[2])) + (fConst40 * fRec15[2])))));
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp8 / (std::fabs((fSlow0 * fTemp8)) + 1.0f))));
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			iRec3[1] = iRec3[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec5[1] = fRec5[0];
			fVec2[1] = fVec2[0];
			fRec4[1] = fRec4[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fVec3[1] = fVec3[0];
			fRec7[1] = fRec7[0];
			fRec11[1] = fRec11[0];
			fVec4[1] = fVec4[0];
			fRec10[1] = fRec10[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
		}
	}

};

#endif
