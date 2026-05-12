/* ------------------------------------------------------------
name: "dayan"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustDayanDSP_H__
#define  __FaustDayanDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustDayanDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustDayanDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst1;
	float fConst2;
	float fConst3;
	float fRec1[2];
	float fConst4;
	FAUSTFLOAT fHslider2;
	float fRec2[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[3];
	float fRec3[2];
	float fConst5;
	float fRec4[3];
	float fRec5[2];
	float fConst6;
	float fRec6[3];
	float fRec7[2];
	float fConst7;
	float fRec8[3];
	float fRec9[2];
	float fConst8;
	float fRec10[3];
	float fRec11[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("filename", "dayan.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "dayan");
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
		fConst1 = (1.0f / fConst0);
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = (6.28318548f / fConst0);
		fConst5 = (9.42477798f / fConst0);
		fConst6 = (12.566371f / fConst0);
		fConst7 = (15.707963f / fConst0);
		fConst8 = (18.849556f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(293.66000000000003f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec0[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
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
	
	virtual FaustDayanDSP* clone() {
		return new FaustDayanDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("dayan");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(293.660004f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider1);
		float fSlow1 = (24.0f * (float(fHslider0) * ((9.99999975e-06f * fSlow0) + 1.0f)));
		float fSlow2 = float(((fSlow0 < 1.5f) * (fSlow0 >= 0.5f)));
		float fSlow3 = float(((fSlow0 < 0.5f) * (fSlow0 >= 0.0500000007f)));
		float fSlow4 = float((fSlow0 < 0.0500000007f));
		float fSlow5 = float((fSlow0 >= 1.5f));
		float fSlow6 = (fConst2 * ((0.300000012f * fSlow2) + ((0.00999999978f * fSlow3) + ((0.100000001f * fSlow4) + (0.5f * fSlow5)))));
		float fSlow7 = (fConst2 * float(fHslider2));
		float fSlow8 = float(fHslider3);
		float fSlow9 = float(fButton0);
		float fSlow10 = (0.5f * fSlow3);
		float fSlow11 = (fConst2 * ((fSlow4 + fSlow10) + (1.5f * (fSlow5 + fSlow2))));
		float fSlow12 = (fConst2 * ((0.800000012f * (fSlow5 + fSlow4)) + (fSlow3 + (1.20000005f * fSlow2))));
		float fSlow13 = (fConst2 * ((0.800000012f * fSlow2) + (fSlow10 + ((0.600000024f * fSlow4) + (0.400000006f * fSlow5)))));
		float fSlow14 = (fSlow5 + fSlow3);
		float fSlow15 = (fConst2 * ((0.100000001f * fSlow14) + (fSlow4 + (0.400000006f * fSlow2))));
		float fSlow16 = (fConst2 * ((0.0500000007f * fSlow14) + (fSlow4 + (0.200000003f * fSlow2))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec1[0] = (fSlow6 + (fConst3 * fRec1[1]));
			float fTemp0 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (3.5f * fRec1[0]))));
			fRec2[0] = (fSlow7 + (fConst3 * fRec2[1]));
			fVec0[0] = fSlow9;
			float fTemp1 = (fSlow9 - fVec0[1]);
			float fTemp2 = (fTemp1 * float((fTemp1 > 0.0f)));
			fRec0[0] = ((fTemp0 * ((2.0f * (std::cos((fConst4 * fRec2[0])) * fRec0[1])) - (fTemp0 * fRec0[2]))) + (fSlow8 * (fTemp2 * (1.0f - fTemp0))));
			fRec3[0] = (fSlow11 + (fConst3 * fRec3[1]));
			float fTemp3 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.79999995f * fRec1[0]))));
			fRec4[0] = ((fTemp3 * ((2.0f * (std::cos((fConst5 * fRec2[0])) * fRec4[1])) - (fTemp3 * fRec4[2]))) + (fSlow8 * (fTemp2 * (1.0f - fTemp3))));
			fRec5[0] = (fSlow12 + (fConst3 * fRec5[1]));
			float fTemp4 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.0f * fRec1[0]))));
			fRec6[0] = ((fTemp4 * ((2.0f * (std::cos((fConst6 * fRec2[0])) * fRec6[1])) - (fTemp4 * fRec6[2]))) + (fSlow8 * (fTemp2 * (1.0f - fTemp4))));
			fRec7[0] = (fSlow13 + (fConst3 * fRec7[1]));
			float fTemp5 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.39999998f * fRec1[0]))));
			fRec8[0] = ((fTemp5 * ((2.0f * (std::cos((fConst7 * fRec2[0])) * fRec8[1])) - (fTemp5 * fRec8[2]))) + (fSlow8 * (fTemp2 * (1.0f - fTemp5))));
			fRec9[0] = (fSlow15 + (fConst3 * fRec9[1]));
			float fTemp6 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.899999976f * fRec1[0]))));
			fRec10[0] = ((fTemp6 * ((2.0f * (std::cos((fConst8 * fRec2[0])) * fRec10[1])) - (fTemp6 * fRec10[2]))) + (fSlow8 * (fTemp2 * (1.0f - fTemp6))));
			fRec11[0] = (fSlow16 + (fConst3 * fRec11[1]));
			output0[i0] = FAUSTFLOAT((fSlow1 * float(tanhf(float((1.10000002f * (((((fRec0[0] * fRec3[0]) + (fRec4[0] * fRec5[0])) + (fRec6[0] * fRec7[0])) + (fRec8[0] * fRec9[0])) + (fRec10[0] * fRec11[0]))))))));
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fVec0[1] = fVec0[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
		}
	}

};

#endif
