/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "dayan"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
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
#include <float.h>
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
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[3];
	float fConst3;
	float fRec1[3];
	float fConst4;
	float fRec2[3];
	float fConst5;
	float fRec3[3];
	float fConst6;
	float fRec4[3];
	float fRec5[3];
	float fConst7;
	float fRec6[3];
	float fConst8;
	float fRec7[3];
	float fConst9;
	float fRec8[3];
	float fConst10;
	float fRec9[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "dayan.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "dayan");
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
		fConst1 = (1.0f / fConst0);
		fConst2 = (6.28318548f / fConst0);
		fConst3 = (12.566371f / fConst0);
		fConst4 = (18.849556f / fConst0);
		fConst5 = (25.1327419f / fConst0);
		fConst6 = (31.415926f / fConst0);
		fConst7 = (10.0091143f / fConst0);
		fConst8 = (13.4146004f / fConst0);
		fConst9 = (14.4199104f / fConst0);
		fConst10 = (16.6692905f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(293.66000000000003f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
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
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(293.660004f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = (24.0f * ((0.200000003f * fSlow1) + 1.0f));
		float fSlow3 = float(fHslider2);
		int iSlow4 = (fSlow3 >= 2.0f);
		int iSlow5 = (fSlow3 >= 1.0f);
		int iSlow6 = (fSlow3 >= 3.0f);
		float fThen2 = (iSlow5 ? 2.0f : 1.29999995f);
		float fElse2 = (iSlow6 ? 1.0f : 1.20000005f);
		float fSlow7 = (iSlow4 ? fElse2 : fThen2);
		float fThen5 = (iSlow5 ? 0.5f : 0.699999988f);
		float fElse5 = (iSlow6 ? 0.949999988f : 0.300000012f);
		float fSlow8 = (iSlow4 ? fElse5 : fThen5);
		float fSlow9 = (1.0f - (0.119999997f * fSlow1));
		float fThen8 = (iSlow5 ? 0.00999999978f : 0.100000001f);
		float fElse8 = (iSlow6 ? 0.5f : 0.300000012f);
		float fSlow10 = (iSlow4 ? fElse8 : fThen8);
		float fSlow11 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (3.5f * fSlow10))));
		float fSlow12 = float(fHslider3);
		float fSlow13 = (2.0f * std::cos((fConst2 * fSlow12)));
		float fSlow14 = (0.00200000009f * fSlow1);
		float fSlow15 = float(fButton0);
		float fSlow16 = (iSlow5 ? 0.300000012f : 0.0500000007f);
		float fElse11 = (iSlow6 ? 1.5f : 0.150000006f);
		float fSlow17 = (iSlow4 ? fElse11 : fSlow16);
		float fSlow18 = ((0.0599999987f * fSlow1) + 1.0f);
		float fSlow19 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.79999995f * fSlow10))));
		float fSlow20 = (2.0f * std::cos((fConst3 * fSlow12)));
		float fSlow21 = (iSlow5 ? 0.150000006f : 0.300000012f);
		float fElse14 = (iSlow6 ? 0.800000012f : 1.0f);
		float fSlow22 = (iSlow4 ? fElse14 : fSlow21);
		float fSlow23 = ((0.239999995f * fSlow1) + 1.0f);
		float fSlow24 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.0f * fSlow10))));
		float fSlow25 = (2.0f * std::cos((fConst4 * fSlow12)));
		float fSlow26 = (iSlow5 ? 0.0500000007f : 1.0f);
		float fElse17 = (iSlow6 ? 0.400000006f : 0.5f);
		float fSlow27 = (iSlow4 ? fElse17 : fSlow26);
		float fSlow28 = ((0.419999987f * fSlow1) + 1.0f);
		float fSlow29 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.39999998f * fSlow10))));
		float fSlow30 = (2.0f * std::cos((fConst5 * fSlow12)));
		float fSlow31 = (iSlow5 ? 0.0199999996f : 0.600000024f);
		float fElse20 = (iSlow6 ? 0.25f : 0.200000003f);
		float fSlow32 = (iSlow4 ? fElse20 : fSlow31);
		float fSlow33 = ((0.600000024f * fSlow1) + 1.0f);
		float fSlow34 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.899999976f * fSlow10))));
		float fSlow35 = (2.0f * std::cos((fConst6 * fSlow12)));
		float fSlow36 = (iSlow5 ? 0.00999999978f : 0.300000012f);
		float fElse23 = (iSlow6 ? 0.150000006f : 0.100000001f);
		float fSlow37 = (iSlow4 ? fElse23 : fSlow36);
		float fSlow38 = (1.0f - fSlow8);
		float fSlow39 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.5f * fSlow10))));
		float fSlow40 = (iSlow4 ? 0.200000003f : fSlow16);
		float fSlow41 = (2.0f * std::cos((fConst7 * fSlow12)));
		float fElse26 = (iSlow6 ? 0.100000001f : 0.699999988f);
		float fSlow42 = (iSlow4 ? fElse26 : fSlow21);
		float fSlow43 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.5f * fSlow10))));
		float fSlow44 = (2.0f * std::cos((fConst8 * fSlow12)));
		float fElse28 = (iSlow6 ? 0.0500000007f : 1.0f);
		float fSlow45 = (iSlow4 ? fElse28 : fSlow26);
		float fSlow46 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, fSlow10)));
		float fSlow47 = (2.0f * std::cos((fConst9 * fSlow12)));
		float fElse30 = (iSlow6 ? 0.0199999996f : 0.5f);
		float fSlow48 = (iSlow4 ? fElse30 : fSlow31);
		float fSlow49 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.600000024f * fSlow10))));
		float fSlow50 = (2.0f * std::cos((fConst10 * fSlow12)));
		float fElse32 = (iSlow6 ? 0.00999999978f : 0.200000003f);
		float fSlow51 = (iSlow4 ? fElse32 : fSlow36);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow15;
			float fTemp0 = (fSlow15 - fVec0[1]);
			float fTemp1 = (fSlow14 * (fTemp0 * float((fTemp0 > 0.0f))));
			float fTempFTZ0 = ((fSlow11 * ((fSlow13 * fRec0[1]) - (fSlow11 * fRec0[2]))) + fTemp1);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fTemp1 + (fSlow19 * ((fSlow20 * fRec1[1]) - (fSlow19 * fRec1[2]))));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp1 + (fSlow24 * ((fSlow25 * fRec2[1]) - (fSlow24 * fRec2[2]))));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 + (fSlow29 * ((fSlow30 * fRec3[1]) - (fSlow29 * fRec3[2]))));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 + (fSlow34 * ((fSlow35 * fRec4[1]) - (fSlow34 * fRec4[2]))));
			fRec4[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 + (fSlow39 * ((fSlow13 * fRec5[1]) - (fSlow39 * fRec5[2]))));
			fRec5[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp1 + (fSlow24 * ((fSlow41 * fRec6[1]) - (fSlow24 * fRec6[2]))));
			fRec6[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp1 + (fSlow43 * ((fSlow44 * fRec7[1]) - (fSlow43 * fRec7[2]))));
			fRec7[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp1 + (fSlow46 * ((fSlow47 * fRec8[1]) - (fSlow46 * fRec8[2]))));
			fRec8[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp1 + (fSlow49 * ((fSlow50 * fRec9[1]) - (fSlow49 * fRec9[2]))));
			fRec9[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((fSlow2 * (fSlow7 * ((fSlow8 * (((((fSlow9 * (fRec0[0] * fSlow17)) + (fSlow18 * (fRec1[0] * fSlow22))) + (fSlow23 * (fRec2[0] * fSlow27))) + (fSlow28 * (fRec3[0] * fSlow32))) + (fSlow33 * (fRec4[0] * fSlow37)))) + (fSlow38 * (((((fSlow9 * (fRec5[0] * fSlow40)) + (fSlow18 * (fRec6[0] * fSlow42))) + (fSlow23 * (fRec7[0] * fSlow45))) + (fSlow28 * (fRec8[0] * fSlow48))) + (fSlow33 * (fRec9[0] * fSlow51))))))))))));
			fVec0[1] = fVec0[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
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
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
		}
	}

};

#endif
