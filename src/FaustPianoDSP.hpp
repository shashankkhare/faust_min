/* ------------------------------------------------------------
name: "piano"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustPianoDSP_H__
#define  __FaustPianoDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
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
	int iRec2[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fVec1[2];
	int iRec3[2];
	float fConst4;
	float fVec2[2];
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec5[2];
	float fVec3[2];
	float fRec4[2];
	int IOTA;
	float fRec0[8192];
	float fConst5;
	float fRec8[2];
	float fVec4[2];
	float fRec7[2];
	float fRec6[8192];
	float fConst6;
	float fRec11[2];
	float fVec5[2];
	float fRec10[2];
	float fRec9[8192];
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fRec12[3];
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fRec13[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fRec14[3];
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec15[3];
	float fConst38;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
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
		fConst2 = std::max<float>(1.0f, (9.99999975e-05f * fConst0));
		fConst3 = (1.0f / fConst2);
		fConst4 = (1.0f / std::max<float>(1.0f, (0.00800000038f * fConst0)));
		fConst5 = (0.99930048f * fConst0);
		fConst6 = (1.00060034f * fConst0);
		float fConst7 = std::tan((2764.60156f / fConst0));
		float fConst8 = (1.0f / fConst7);
		float fConst9 = (((fConst8 + 0.166666672f) / fConst7) + 1.0f);
		fConst10 = (1.0f / (fConst7 * fConst9));
		fConst11 = (0.0f - fConst10);
		fConst12 = (1.0f / fConst9);
		fConst13 = (((fConst8 + -0.166666672f) / fConst7) + 1.0f);
		fConst14 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst7))));
		float fConst15 = std::tan((1382.30078f / fConst0));
		float fConst16 = (1.0f / fConst15);
		float fConst17 = (((fConst16 + 0.125f) / fConst15) + 1.0f);
		fConst18 = (1.0f / (fConst15 * fConst17));
		fConst19 = (0.0f - fConst18);
		fConst20 = (1.0f / fConst17);
		fConst21 = (((fConst16 + -0.125f) / fConst15) + 1.0f);
		fConst22 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst15))));
		float fConst23 = std::tan((691.150391f / fConst0));
		float fConst24 = (1.0f / fConst23);
		float fConst25 = (((fConst24 + 0.100000001f) / fConst23) + 1.0f);
		fConst26 = (1.0f / (fConst23 * fConst25));
		fConst27 = (0.0f - fConst26);
		fConst28 = (1.0f / fConst25);
		fConst29 = (((fConst24 + -0.100000001f) / fConst23) + 1.0f);
		fConst30 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst23))));
		float fConst31 = std::tan((345.575195f / fConst0));
		float fConst32 = (1.0f / fConst31);
		float fConst33 = (((fConst32 + 0.0833333358f) / fConst31) + 1.0f);
		fConst34 = (1.0f / (fConst31 * fConst33));
		fConst35 = (1.0f / fConst33);
		fConst36 = (((fConst32 + -0.0833333358f) / fConst31) + 1.0f);
		fConst37 = (2.0f * (1.0f - (1.0f / FaustPianoDSP_faustpower2_f(fConst31))));
		fConst38 = (0.0f - fConst34);
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
			iRec2[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec3[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec4[l8] = 0.0f;
		}
		IOTA = 0;
		for (int l9 = 0; (l9 < 8192); l9 = (l9 + 1)) {
			fRec0[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec4[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec7[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 8192); l13 = (l13 + 1)) {
			fRec6[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec11[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec10[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 8192); l17 = (l17 + 1)) {
			fRec9[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec12[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec13[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec14[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec15[l21] = 0.0f;
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
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(110.0f), FAUSTFLOAT(27.0f), FAUSTFLOAT(4000.0f), FAUSTFLOAT(0.100000001f));
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
		float fSlow5 = (4.65661287e-10f * fSlow1);
		float fSlow6 = float(fButton0);
		float fSlow7 = float(fHslider3);
		float fSlow8 = (0.999599993f - (2.00000002e-07f * fSlow7));
		float fSlow9 = (0.400000006f * fSlow8);
		float fSlow10 = (1.0f / std::tan((fConst1 * (6000.0f - (0.800000012f * fSlow7)))));
		float fSlow11 = (1.0f / (fSlow10 + 1.0f));
		float fSlow12 = (1.0f - fSlow10);
		float fSlow13 = ((0.119999997f * float(fHslider4)) + 0.0199999996f);
		float fSlow14 = std::sin(fSlow13);
		float fSlow15 = (fConst0 / fSlow7);
		float fSlow16 = std::floor(fSlow15);
		float fSlow17 = (fSlow16 + (1.0f - fSlow15));
		int iSlow18 = int(fSlow15);
		int iSlow19 = (std::min<int>(8193, std::max<int>(0, iSlow18)) + 1);
		float fSlow20 = (fSlow15 - fSlow16);
		int iSlow21 = (std::min<int>(8193, std::max<int>(0, (iSlow18 + 1))) + 1);
		float fSlow22 = std::cos(fSlow13);
		float fSlow23 = (0.300000012f * fSlow8);
		float fSlow24 = (fConst5 / fSlow7);
		float fSlow25 = std::floor(fSlow24);
		float fSlow26 = (fSlow25 + (1.0f - fSlow24));
		int iSlow27 = int(fSlow24);
		int iSlow28 = (std::min<int>(8193, std::max<int>(0, iSlow27)) + 1);
		float fSlow29 = (fSlow24 - fSlow25);
		int iSlow30 = (std::min<int>(8193, std::max<int>(0, (iSlow27 + 1))) + 1);
		float fSlow31 = (fConst6 / fSlow7);
		float fSlow32 = std::floor(fSlow31);
		float fSlow33 = (fSlow32 + (1.0f - fSlow31));
		int iSlow34 = int(fSlow31);
		int iSlow35 = (std::min<int>(8193, std::max<int>(0, iSlow34)) + 1);
		float fSlow36 = (fSlow31 - fSlow32);
		int iSlow37 = (std::min<int>(8193, std::max<int>(0, (iSlow34 + 1))) + 1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec2[0] = ((1103515245 * iRec2[1]) + 12345);
			fVec0[0] = fSlow6;
			float fTemp0 = (fSlow6 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			fVec1[0] = fTemp1;
			iRec3[0] = (((iRec3[1] + (iRec3[1] > 0)) * (fTemp1 <= fVec1[1])) + (fTemp1 > fVec1[1]));
			float fTemp2 = float(iRec3[0]);
			float fTemp3 = (fSlow5 * (float(iRec2[0]) * std::max<float>(0.0f, std::min<float>((fConst3 * fTemp2), ((fConst4 * (fConst2 - fTemp2)) + 1.0f)))));
			fVec2[0] = fTemp3;
			fRec1[0] = (0.0f - (fSlow3 * ((fSlow4 * fRec1[1]) - (fTemp3 + fVec2[1]))));
			float fTemp4 = ((fSlow17 * fRec0[((IOTA - iSlow19) & 8191)]) + (fSlow20 * fRec0[((IOTA - iSlow21) & 8191)]));
			fRec5[0] = ((fSlow22 * fTemp4) - (fSlow14 * fRec5[1]));
			float fTemp5 = ((fSlow14 * fTemp4) + (fSlow22 * fRec5[1]));
			fVec3[0] = fTemp5;
			fRec4[0] = (0.0f - (fSlow11 * ((fSlow12 * fRec4[1]) - (fTemp5 + fVec3[1]))));
			fRec0[(IOTA & 8191)] = (fRec1[0] + (fSlow9 * fRec4[0]));
			float fTemp6 = ((fSlow26 * fRec6[((IOTA - iSlow28) & 8191)]) + (fSlow29 * fRec6[((IOTA - iSlow30) & 8191)]));
			fRec8[0] = ((fSlow22 * fTemp6) - (fSlow14 * fRec8[1]));
			float fTemp7 = ((fSlow14 * fTemp6) + (fSlow22 * fRec8[1]));
			fVec4[0] = fTemp7;
			fRec7[0] = (0.0f - (fSlow11 * ((fSlow12 * fRec7[1]) - (fTemp7 + fVec4[1]))));
			fRec6[(IOTA & 8191)] = (fRec1[0] + (fSlow23 * fRec7[0]));
			float fTemp8 = ((fSlow33 * fRec9[((IOTA - iSlow35) & 8191)]) + (fSlow36 * fRec9[((IOTA - iSlow37) & 8191)]));
			fRec11[0] = ((fSlow22 * fTemp8) - (fSlow14 * fRec11[1]));
			float fTemp9 = ((fSlow14 * fTemp8) + (fSlow22 * fRec11[1]));
			fVec5[0] = fTemp9;
			fRec10[0] = (0.0f - (fSlow11 * ((fSlow12 * fRec10[1]) - (fTemp9 + fVec5[1]))));
			fRec9[(IOTA & 8191)] = (fRec1[0] + (fSlow23 * fRec10[0]));
			float fTemp10 = ((fRec0[((IOTA - 0) & 8191)] + fRec6[((IOTA - 0) & 8191)]) + fRec9[((IOTA - 0) & 8191)]);
			fRec12[0] = (fTemp10 - (fConst12 * ((fConst13 * fRec12[2]) + (fConst14 * fRec12[1]))));
			fRec13[0] = (fTemp10 - (fConst20 * ((fConst21 * fRec13[2]) + (fConst22 * fRec13[1]))));
			fRec14[0] = (fTemp10 - (fConst28 * ((fConst29 * fRec14[2]) + (fConst30 * fRec14[1]))));
			fRec15[0] = (fTemp10 - (fConst35 * ((fConst36 * fRec15[2]) + (fConst37 * fRec15[1]))));
			float fTemp11 = (fTemp10 + (0.25f * ((fConst11 * fRec12[2]) + (((fConst19 * fRec13[2]) + (((fConst27 * fRec14[2]) + (((fConst34 * fRec15[0]) + (fConst38 * fRec15[2])) + (fConst26 * fRec14[0]))) + (fConst18 * fRec13[0]))) + (fConst10 * fRec12[0])))));
			output0[i0] = FAUSTFLOAT((fSlow0 * (fTemp11 / (std::fabs((fSlow0 * fTemp11)) + 1.0f))));
			iRec2[1] = iRec2[0];
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			iRec3[1] = iRec3[0];
			fVec2[1] = fVec2[0];
			fRec1[1] = fRec1[0];
			fRec5[1] = fRec5[0];
			fVec3[1] = fVec3[0];
			fRec4[1] = fRec4[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fVec4[1] = fVec4[0];
			fRec7[1] = fRec7[0];
			fRec11[1] = fRec11[0];
			fVec5[1] = fVec5[0];
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
