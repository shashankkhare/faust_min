/* ------------------------------------------------------------
name: "tanpura"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustTanpuraDSP_H__
#define  __FaustTanpuraDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTanpuraDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTanpuraDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	float fRec2[2];
	FAUSTFLOAT fHslider3;
	float fRec3[2];
	float fVec0[2];
	float fRec1[2];
	float fConst4;
	int iRec5[2];
	float fConst5;
	float fConst6;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int IOTA;
	float fVec2[32768];
	int iRec6[2];
	float fConst7;
	float fVec3[2];
	float fConst8;
	float fRec4[2];
	float fRec0[8192];
	float fRec9[2];
	float fVec4[2];
	float fRec8[2];
	int iRec11[2];
	float fVec5[2];
	float fRec10[2];
	float fRec7[8192];
	float fRec14[2];
	float fVec6[2];
	float fRec13[2];
	int iRec16[2];
	float fVec7[2];
	float fRec15[2];
	float fRec12[8192];
	float fRec19[2];
	float fVec8[2];
	float fRec18[2];
	int iRec21[2];
	float fVec9[2];
	float fRec20[2];
	float fRec17[8192];
	
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
		m->declare("filename", "tanpura.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tanpura");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		float fConst3 = (1.0f / std::tan((1256.63708f / fConst0)));
		fConst4 = (1.0f / (fConst3 + 1.0f));
		fConst5 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst6 = (1.0f / fConst5);
		fConst7 = (1.0f / std::max<float>(1.0f, (0.00999999978f * fConst0)));
		fConst8 = (1.0f - fConst3);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(130.81f);
		fHslider3 = FAUSTFLOAT(0.69999999999999996f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec5[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		IOTA = 0;
		for (int l6 = 0; (l6 < 32768); l6 = (l6 + 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec6[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec4[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 8192); l10 = (l10 + 1)) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec4[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec8[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iRec11[l14] = 0;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec10[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 8192); l17 = (l17 + 1)) {
			fRec7[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec14[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fVec6[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec13[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			iRec16[l21] = 0;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fVec7[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec15[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 8192); l24 = (l24 + 1)) {
			fRec12[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec19[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fVec8[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec18[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			iRec21[l28] = 0;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fVec9[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec20[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 8192); l31 = (l31 + 1)) {
			fRec17[l31] = 0.0f;
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
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(130.809998f), FAUSTFLOAT(20.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider3, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.25f * (float(fHslider0) * float(fHslider1)));
		float fSlow1 = (fConst1 * float(fHslider2));
		float fSlow2 = ((0.300000012f * float(fHslider3)) + 0.200000003f);
		float fSlow3 = float(fButton0);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec2[0] = (fSlow1 + (fConst2 * fRec2[1]));
			float fTemp0 = (fConst0 / std::max<float>(20.0f, (1.5f * fRec2[0])));
			float fTemp1 = (fTemp0 + -2.0f);
			int iTemp2 = int(fTemp1);
			float fTemp3 = std::floor(fTemp1);
			float fTemp4 = ((fRec0[((IOTA - (std::min<int>(4097, std::max<int>(0, iTemp2)) + 1)) & 8191)] * (fTemp3 + (3.0f - fTemp0))) + ((fTemp0 + (-2.0f - fTemp3)) * fRec0[((IOTA - (std::min<int>(4097, std::max<int>(0, (iTemp2 + 1))) + 1)) & 8191)]));
			float fTemp5 = float(tanhf(float((fTemp4 - (fSlow2 * (float((fTemp4 > 0.400000006f)) * (fTemp4 + -0.400000006f)))))));
			fRec3[0] = ((0.90044713f * fTemp5) - (0.434965521f * fRec3[1]));
			float fTemp6 = ((0.434965521f * fTemp5) + (0.90044713f * fRec3[1]));
			fVec0[0] = fTemp6;
			fRec1[0] = ((0.995000005f * fRec1[1]) + (0.996999979f * (fTemp6 - fVec0[1])));
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float fTemp7 = float(iRec5[0]);
			fVec1[0] = fSlow3;
			float fTemp8 = (fSlow3 - fVec1[1]);
			float fTemp9 = (fTemp8 * float((fTemp8 > 0.0f)));
			fVec2[(IOTA & 32767)] = fTemp9;
			float fTemp10 = fVec2[((IOTA - 1) & 32767)];
			iRec6[0] = (((iRec6[1] + (iRec6[1] > 0)) * (fTemp9 <= fTemp10)) + (fTemp9 > fTemp10));
			float fTemp11 = float(iRec6[0]);
			float fTemp12 = (fTemp7 * std::max<float>(0.0f, std::min<float>((fConst6 * fTemp11), ((fConst7 * (fConst5 - fTemp11)) + 1.0f))));
			fVec3[0] = fTemp12;
			fRec4[0] = (fConst4 * ((4.65661287e-10f * (fTemp12 + fVec3[1])) - (fConst8 * fRec4[1])));
			fRec0[(IOTA & 8191)] = (fRec1[0] + fRec4[0]);
			float fTemp13 = (fConst0 / std::max<float>(20.0f, fRec2[0]));
			float fTemp14 = (fTemp13 + -2.0f);
			int iTemp15 = int(fTemp14);
			int iTemp16 = (std::min<int>(4097, std::max<int>(0, iTemp15)) + 1);
			float fTemp17 = std::floor(fTemp14);
			float fTemp18 = (fTemp17 + (3.0f - fTemp13));
			float fTemp19 = (fTemp13 + (-2.0f - fTemp17));
			int iTemp20 = (std::min<int>(4097, std::max<int>(0, (iTemp15 + 1))) + 1);
			float fTemp21 = ((fRec7[((IOTA - iTemp16) & 8191)] * fTemp18) + (fTemp19 * fRec7[((IOTA - iTemp20) & 8191)]));
			float fTemp22 = float(tanhf(float((fTemp21 - (fSlow2 * (float((fTemp21 > 0.400000006f)) * (fTemp21 + -0.400000006f)))))));
			fRec9[0] = ((0.90044713f * fTemp22) - (0.434965521f * fRec9[1]));
			float fTemp23 = ((0.434965521f * fTemp22) + (0.90044713f * fRec9[1]));
			fVec4[0] = fTemp23;
			fRec8[0] = ((0.995000005f * fRec8[1]) + (0.996999979f * (fTemp23 - fVec4[1])));
			float fTemp24 = fVec2[((IOTA - 8820) & 32767)];
			float fTemp25 = fVec2[((IOTA - 8821) & 32767)];
			iRec11[0] = (((iRec11[1] + (iRec11[1] > 0)) * (fTemp24 <= fTemp25)) + (fTemp24 > fTemp25));
			float fTemp26 = float(iRec11[0]);
			float fTemp27 = (fTemp7 * std::max<float>(0.0f, std::min<float>((fConst6 * fTemp26), ((fConst7 * (fConst5 - fTemp26)) + 1.0f))));
			fVec5[0] = fTemp27;
			fRec10[0] = (fConst4 * ((4.65661287e-10f * (fTemp27 + fVec5[1])) - (fConst8 * fRec10[1])));
			fRec7[(IOTA & 8191)] = (fRec8[0] + fRec10[0]);
			float fTemp28 = ((fTemp18 * fRec12[((IOTA - iTemp16) & 8191)]) + (fTemp19 * fRec12[((IOTA - iTemp20) & 8191)]));
			float fTemp29 = float(tanhf(float((fTemp28 - (fSlow2 * (float((fTemp28 > 0.400000006f)) * (fTemp28 + -0.400000006f)))))));
			fRec14[0] = ((0.90044713f * fTemp29) - (0.434965521f * fRec14[1]));
			float fTemp30 = ((0.434965521f * fTemp29) + (0.90044713f * fRec14[1]));
			fVec6[0] = fTemp30;
			fRec13[0] = ((0.995000005f * fRec13[1]) + (0.996999979f * (fTemp30 - fVec6[1])));
			float fTemp31 = fVec2[((IOTA - 17640) & 32767)];
			float fTemp32 = fVec2[((IOTA - 17641) & 32767)];
			iRec16[0] = (((iRec16[1] + (iRec16[1] > 0)) * (fTemp31 <= fTemp32)) + (fTemp31 > fTemp32));
			float fTemp33 = float(iRec16[0]);
			float fTemp34 = (fTemp7 * std::max<float>(0.0f, std::min<float>((fConst6 * fTemp33), ((fConst7 * (fConst5 - fTemp33)) + 1.0f))));
			fVec7[0] = fTemp34;
			fRec15[0] = (fConst4 * ((4.65661287e-10f * (fTemp34 + fVec7[1])) - (fConst8 * fRec15[1])));
			fRec12[(IOTA & 8191)] = (fRec13[0] + fRec15[0]);
			float fTemp35 = (fConst0 / std::max<float>(20.0f, (0.5f * fRec2[0])));
			float fTemp36 = (fTemp35 + -2.0f);
			int iTemp37 = int(fTemp36);
			float fTemp38 = std::floor(fTemp36);
			float fTemp39 = ((fRec17[((IOTA - (std::min<int>(4097, std::max<int>(0, iTemp37)) + 1)) & 8191)] * (fTemp38 + (3.0f - fTemp35))) + ((fTemp35 + (-2.0f - fTemp38)) * fRec17[((IOTA - (std::min<int>(4097, std::max<int>(0, (iTemp37 + 1))) + 1)) & 8191)]));
			float fTemp40 = float(tanhf(float((fTemp39 - (fSlow2 * (float((fTemp39 > 0.400000006f)) * (fTemp39 + -0.400000006f)))))));
			fRec19[0] = ((0.90044713f * fTemp40) - (0.434965521f * fRec19[1]));
			float fTemp41 = ((0.434965521f * fTemp40) + (0.90044713f * fRec19[1]));
			fVec8[0] = fTemp41;
			fRec18[0] = ((0.995000005f * fRec18[1]) + (0.996999979f * (fTemp41 - fVec8[1])));
			float fTemp42 = fVec2[((IOTA - 26460) & 32767)];
			float fTemp43 = fVec2[((IOTA - 26461) & 32767)];
			iRec21[0] = (((iRec21[1] + (iRec21[1] > 0)) * (fTemp42 <= fTemp43)) + (fTemp42 > fTemp43));
			float fTemp44 = float(iRec21[0]);
			float fTemp45 = (fTemp7 * std::max<float>(0.0f, std::min<float>((fConst6 * fTemp44), ((fConst7 * (fConst5 - fTemp44)) + 1.0f))));
			fVec9[0] = fTemp45;
			fRec20[0] = (fConst4 * ((4.65661287e-10f * (fTemp45 + fVec9[1])) - (fConst8 * fRec20[1])));
			fRec17[(IOTA & 8191)] = (fRec18[0] + fRec20[0]);
			output0[i0] = FAUSTFLOAT((fSlow0 * (((fRec0[((IOTA - 0) & 8191)] + fRec7[((IOTA - 0) & 8191)]) + fRec12[((IOTA - 0) & 8191)]) + fRec17[((IOTA - 0) & 8191)])));
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			iRec5[1] = iRec5[0];
			fVec1[1] = fVec1[0];
			IOTA = (IOTA + 1);
			iRec6[1] = iRec6[0];
			fVec3[1] = fVec3[0];
			fRec4[1] = fRec4[0];
			fRec9[1] = fRec9[0];
			fVec4[1] = fVec4[0];
			fRec8[1] = fRec8[0];
			iRec11[1] = iRec11[0];
			fVec5[1] = fVec5[0];
			fRec10[1] = fRec10[0];
			fRec14[1] = fRec14[0];
			fVec6[1] = fVec6[0];
			fRec13[1] = fRec13[0];
			iRec16[1] = iRec16[0];
			fVec7[1] = fVec7[0];
			fRec15[1] = fRec15[0];
			fRec19[1] = fRec19[0];
			fVec8[1] = fVec8[0];
			fRec18[1] = fRec18[0];
			iRec21[1] = iRec21[0];
			fVec9[1] = fVec9[0];
			fRec20[1] = fRec20[0];
		}
	}

};

#endif
