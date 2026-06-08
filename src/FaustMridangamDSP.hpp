/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "mridangam"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustMridangamDSP_H__
#define  __FaustMridangamDSP_H__

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
#define FAUSTCLASS FaustMridangamDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustMridangamDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider2;
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
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "mridangam.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "mridangam");
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
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(2.0f);
		fHslider3 = FAUSTFLOAT(146.83000000000001f);
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
	
	virtual FaustMridangamDSP* clone() {
		return new FaustMridangamDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("mridangam");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = ((0.300000012f * fSlow1) + 1.0f);
		float fSlow3 = (20.0f * fSlow2);
		float fSlow4 = (1.0f - (0.100000001f * fSlow1));
		float fSlow5 = float(fHslider2);
		int iSlow6 = (fSlow5 >= 3.0f);
		int iSlow7 = (fSlow5 >= 2.0f);
		int iSlow8 = (fSlow5 >= 1.0f);
		float fThen1 = (iSlow8 ? 0.0500000007f : 0.600000024f);
		int iSlow9 = (fSlow5 >= 5.0f);
		int iSlow10 = (fSlow5 >= 4.0f);
		float fThen3 = (iSlow10 ? 0.100000001f : 0.400000006f);
		float fThen4 = (iSlow7 ? 0.699999988f : fThen1);
		float fElse4 = (iSlow9 ? 0.0299999993f : fThen3);
		float fSlow11 = (iSlow6 ? fElse4 : fThen4);
		float fSlow12 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (3.5f * fSlow11))));
		float fSlow13 = float(fHslider3);
		float fThen7 = (iSlow10 ? 1.0f : 1.20000005f);
		float fThen8 = (iSlow7 ? 1.0f : 0.5f);
		float fElse8 = (iSlow9 ? 1.5f : fThen7);
		float fSlow14 = (iSlow6 ? fElse8 : fThen8);
		float fSlow15 = std::cos(((fConst2 * fSlow13) * fSlow14));
		float fSlow16 = (0.00200000009f * fSlow1);
		float fSlow17 = float(fButton0);
		float fThen10 = (iSlow8 ? 1.20000005f : 1.5f);
		float fThen12 = (iSlow10 ? 1.0f : 0.200000003f);
		float fThen13 = (iSlow7 ? 0.5f : fThen10);
		float fElse13 = (iSlow9 ? 0.100000001f : fThen12);
		float fSlow18 = (iSlow6 ? fElse13 : fThen13);
		float fSlow19 = ((0.0500000007f * fSlow1) + 1.0f);
		float fSlow20 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.79999995f * fSlow11))));
		float fSlow21 = std::cos(((fConst3 * fSlow13) * fSlow14));
		float fThen15 = (iSlow8 ? 0.400000006f : 0.800000012f);
		float fThen17 = (iSlow10 ? 0.800000012f : 0.5f);
		float fThen18 = (iSlow7 ? 1.0f : fThen15);
		float fElse18 = (iSlow9 ? 0.200000003f : fThen17);
		float fSlow22 = (iSlow6 ? fElse18 : fThen18);
		float fSlow23 = ((0.150000006f * fSlow1) + 1.0f);
		float fSlow24 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.0f * fSlow11))));
		float fSlow25 = std::cos(((fConst4 * fSlow13) * fSlow14));
		float fThen20 = (iSlow8 ? 0.100000001f : 0.300000012f);
		float fThen22 = (iSlow10 ? 0.400000006f : 0.800000012f);
		float fThen23 = (iSlow7 ? 0.800000012f : fThen20);
		float fElse23 = (iSlow9 ? 0.300000012f : fThen22);
		float fSlow26 = (iSlow6 ? fElse23 : fThen23);
		float fSlow27 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.39999998f * fSlow11))));
		float fSlow28 = std::cos(((fConst5 * fSlow13) * fSlow14));
		float fThen25 = (iSlow8 ? 0.0f : 0.100000001f);
		float fThen27 = (iSlow10 ? 0.200000003f : 1.0f);
		float fThen28 = (iSlow7 ? 0.600000024f : fThen25);
		float fElse28 = (iSlow9 ? 0.5f : fThen27);
		float fSlow29 = (iSlow6 ? fElse28 : fThen28);
		float fSlow30 = ((0.400000006f * fSlow1) + 1.0f);
		float fSlow31 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.899999976f * fSlow11))));
		float fSlow32 = std::cos(((fConst6 * fSlow13) * fSlow14));
		float fThen31 = (iSlow10 ? 0.100000001f : 0.800000012f);
		float fThen32 = (iSlow7 ? 0.400000006f : 0.0f);
		float fElse32 = (iSlow9 ? 0.800000012f : fThen31);
		float fSlow33 = (iSlow6 ? fElse32 : fThen32);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow17;
			float fTemp0 = (fSlow17 - fVec0[1]);
			float fTemp1 = (fSlow16 * (fTemp0 * float((fTemp0 > 0.0f))));
			float fTempFTZ0 = ((fSlow12 * ((2.0f * (fSlow15 * fRec0[1])) - (fSlow12 * fRec0[2]))) + fTemp1);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fTemp1 + (fSlow20 * ((2.0f * (fSlow21 * fRec1[1])) - (fSlow20 * fRec1[2]))));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp1 + (fSlow24 * ((2.0f * (fSlow25 * fRec2[1])) - (fSlow24 * fRec2[2]))));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 + (fSlow27 * ((2.0f * (fSlow28 * fRec3[1])) - (fSlow27 * fRec3[2]))));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 + (fSlow31 * ((2.0f * (fSlow32 * fRec4[1])) - (fSlow31 * fRec4[2]))));
			fRec4[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((fSlow3 * (((((fSlow4 * (fRec0[0] * fSlow18)) + (fSlow19 * (fRec1[0] * fSlow22))) + (fSlow23 * (fRec2[0] * fSlow26))) + (fSlow2 * (fRec3[0] * fSlow29))) + (fSlow30 * (fRec4[0] * fSlow33)))))))));
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
		}
	}

};

#endif
