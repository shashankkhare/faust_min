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
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(293.660004f), FAUSTFLOAT(100.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (14.1637001f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (4.0f * ((0.200000003f * fSlow1) + 1.0f));
		float fSlow3 = float(fHslider2);
		int iSlow4 = (fSlow3 >= 2.0f);
		int iSlow5 = (fSlow3 >= 1.0f);
		int iSlow6 = (fSlow3 >= 3.0f);
		float fThen2 = (iSlow5 ? 2.0f : 1.0f);
		float fElse2 = (iSlow6 ? 1.29999995f : 1.20000005f);
		float fSlow7 = (iSlow4 ? fElse2 : fThen2);
		float fThen4 = (iSlow5 ? 0.5f : 0.949999988f);
		int iSlow8 = (fSlow3 >= 4.0f);
		float fThen6 = (iSlow4 ? 0.200000003f : fThen4);
		float fElse6 = (iSlow8 ? 0.699999988f : 0.300000012f);
		float fSlow9 = (iSlow6 ? fElse6 : fThen6);
		float fSlow10 = (1.0f - (0.119999997f * fSlow1));
		float fThen8 = (iSlow5 ? 0.00999999978f : 0.5f);
		float fThen10 = (iSlow4 ? 0.0299999993f : fThen8);
		float fElse10 = (iSlow8 ? 0.100000001f : 0.300000012f);
		float fSlow11 = (iSlow6 ? fElse10 : fThen10);
		float fSlow12 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (3.5f * fSlow11))));
		float fSlow13 = float(fHslider3);
		float fSlow14 = (2.0f * std::cos((fConst2 * fSlow13)));
		float fSlow15 = (0.00200000009f * fSlow1);
		float fSlow16 = float(fButton0);
		float fThen12 = (iSlow5 ? 0.300000012f : 1.5f);
		float fThen14 = (iSlow4 ? 0.100000001f : fThen12);
		float fElse14 = (iSlow8 ? 0.0500000007f : 0.150000006f);
		float fSlow17 = (iSlow6 ? fElse14 : fThen14);
		float fSlow18 = ((0.0599999987f * fSlow1) + 1.0f);
		float fSlow19 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.79999995f * fSlow11))));
		float fSlow20 = (2.0f * std::cos((fConst3 * fSlow13)));
		float fThen16 = (iSlow5 ? 0.150000006f : 0.800000012f);
		float fThen18 = (iSlow4 ? 0.0500000007f : fThen16);
		float fElse18 = (iSlow8 ? 0.300000012f : 1.0f);
		float fSlow21 = (iSlow6 ? fElse18 : fThen18);
		float fSlow22 = ((0.239999995f * fSlow1) + 1.0f);
		float fSlow23 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.0f * fSlow11))));
		float fSlow24 = (2.0f * std::cos((fConst4 * fSlow13)));
		float fThen20 = (iSlow5 ? 0.0500000007f : 0.400000006f);
		float fThen22 = (iSlow4 ? 0.0199999996f : fThen20);
		float fElse22 = (iSlow8 ? 1.0f : 0.5f);
		float fSlow25 = (iSlow6 ? fElse22 : fThen22);
		float fSlow26 = ((0.419999987f * fSlow1) + 1.0f);
		float fSlow27 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.39999998f * fSlow11))));
		float fSlow28 = (2.0f * std::cos((fConst5 * fSlow13)));
		float fThen24 = (iSlow5 ? 0.0199999996f : 0.25f);
		float fThen26 = (iSlow4 ? 0.00999999978f : fThen24);
		float fElse26 = (iSlow8 ? 0.600000024f : 0.200000003f);
		float fSlow29 = (iSlow6 ? fElse26 : fThen26);
		float fSlow30 = ((0.600000024f * fSlow1) + 1.0f);
		float fSlow31 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.899999976f * fSlow11))));
		float fSlow32 = (2.0f * std::cos((fConst6 * fSlow13)));
		float fThen28 = (iSlow5 ? 0.00999999978f : 0.150000006f);
		float fThen30 = (iSlow4 ? 0.00999999978f : fThen28);
		float fElse30 = (iSlow8 ? 0.300000012f : 0.100000001f);
		float fSlow33 = (iSlow6 ? fElse30 : fThen30);
		float fSlow34 = (1.0f - fSlow9);
		float fSlow35 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.5f * fSlow11))));
		float fThen32 = (iSlow5 ? 0.300000012f : 0.200000003f);
		float fThen34 = (iSlow4 ? 0.100000001f : fThen32);
		float fElse34 = (iSlow8 ? 0.0500000007f : 0.200000003f);
		float fSlow36 = (iSlow6 ? fElse34 : fThen34);
		float fSlow37 = (2.0f * std::cos((fConst7 * fSlow13)));
		float fThen36 = (iSlow5 ? 0.150000006f : 0.100000001f);
		float fThen38 = (iSlow4 ? 0.200000003f : fThen36);
		float fElse38 = (iSlow8 ? 0.300000012f : 0.699999988f);
		float fSlow38 = (iSlow6 ? fElse38 : fThen38);
		float fSlow39 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.5f * fSlow11))));
		float fSlow40 = (2.0f * std::cos((fConst8 * fSlow13)));
		float fThen40 = (iSlow4 ? 0.400000006f : 0.0500000007f);
		float fSlow41 = (iSlow6 ? 1.0f : fThen40);
		float fSlow42 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, fSlow11)));
		float fSlow43 = (2.0f * std::cos((fConst9 * fSlow13)));
		float fThen43 = (iSlow4 ? 0.600000024f : 0.0199999996f);
		float fElse43 = (iSlow8 ? 0.600000024f : 0.5f);
		float fSlow44 = (iSlow6 ? fElse43 : fThen43);
		float fSlow45 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.600000024f * fSlow11))));
		float fSlow46 = (2.0f * std::cos((fConst10 * fSlow13)));
		float fThen46 = (iSlow4 ? 0.800000012f : 0.00999999978f);
		float fElse46 = (iSlow8 ? 0.300000012f : 0.200000003f);
		float fSlow47 = (iSlow6 ? fElse46 : fThen46);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow16;
			float fTemp0 = (fSlow16 - fVec0[1]);
			float fTemp1 = (fSlow15 * (fTemp0 * float((fTemp0 > 0.0f))));
			float fTempFTZ0 = ((fSlow12 * ((fSlow14 * fRec0[1]) - (fSlow12 * fRec0[2]))) + fTemp1);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fTemp1 + (fSlow19 * ((fSlow20 * fRec1[1]) - (fSlow19 * fRec1[2]))));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp1 + (fSlow23 * ((fSlow24 * fRec2[1]) - (fSlow23 * fRec2[2]))));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 + (fSlow27 * ((fSlow28 * fRec3[1]) - (fSlow27 * fRec3[2]))));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 + (fSlow31 * ((fSlow32 * fRec4[1]) - (fSlow31 * fRec4[2]))));
			fRec4[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 + (fSlow35 * ((fSlow14 * fRec5[1]) - (fSlow35 * fRec5[2]))));
			fRec5[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp1 + (fSlow23 * ((fSlow37 * fRec6[1]) - (fSlow23 * fRec6[2]))));
			fRec6[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp1 + (fSlow39 * ((fSlow40 * fRec7[1]) - (fSlow39 * fRec7[2]))));
			fRec7[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp1 + (fSlow42 * ((fSlow43 * fRec8[1]) - (fSlow42 * fRec8[2]))));
			fRec8[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp1 + (fSlow45 * ((fSlow46 * fRec9[1]) - (fSlow45 * fRec9[2]))));
			fRec9[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((fSlow2 * (fSlow7 * ((fSlow9 * (((((fSlow10 * (fRec0[0] * fSlow17)) + (fSlow18 * (fRec1[0] * fSlow21))) + (fSlow22 * (fRec2[0] * fSlow25))) + (fSlow26 * (fRec3[0] * fSlow29))) + (fSlow30 * (fRec4[0] * fSlow33)))) + (fSlow34 * (((((fSlow10 * (fRec5[0] * fSlow36)) + (fSlow18 * (fRec6[0] * fSlow38))) + (fSlow22 * (fRec7[0] * fSlow41))) + (fSlow26 * (fRec8[0] * fSlow44))) + (fSlow30 * (fRec9[0] * fSlow47))))))))))));
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
