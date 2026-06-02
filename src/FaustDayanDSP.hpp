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
		fConst3 = (9.42477798f / fConst0);
		fConst4 = (12.566371f / fConst0);
		fConst5 = (15.707963f / fConst0);
		fConst6 = (18.849556f / fConst0);
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
		float fSlow3 = (1.0f - (0.119999997f * fSlow1));
		float fSlow4 = float(fHslider2);
		float fSlow5 = ((0.300000012f * float(((fSlow4 < 2.5f) * (fSlow4 >= 1.5f)))) + ((0.00999999978f * float(((fSlow4 < 1.5f) * (fSlow4 >= 0.5f)))) + ((0.100000001f * float((fSlow4 < 0.5f))) + (0.5f * float((fSlow4 >= 2.5f))))));
		float fSlow6 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (3.5f * fSlow5))));
		float fSlow7 = float(fHslider3);
		float fSlow8 = (2.0f * std::cos((fConst2 * fSlow7)));
		float fSlow9 = (0.00200000009f * fSlow1);
		float fSlow10 = float(fButton0);
		int iSlow11 = (fSlow4 >= 2.0f);
		int iSlow12 = (fSlow4 >= 1.0f);
		float fThen1 = (iSlow12 ? 0.5f : 1.0f);
		float fSlow13 = (iSlow11 ? 1.5f : fThen1);
		float fSlow14 = ((0.0599999987f * fSlow1) + 1.0f);
		float fSlow15 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.79999995f * fSlow5))));
		float fSlow16 = (2.0f * std::cos((fConst3 * fSlow7)));
		int iSlow17 = (fSlow4 >= 3.0f);
		float fThen4 = (iSlow12 ? 1.0f : 0.800000012f);
		float fElse4 = (iSlow17 ? 0.800000012f : 1.20000005f);
		float fSlow18 = (iSlow11 ? fElse4 : fThen4);
		float fSlow19 = ((0.239999995f * fSlow1) + 1.0f);
		float fSlow20 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (2.0f * fSlow5))));
		float fSlow21 = (2.0f * std::cos((fConst4 * fSlow7)));
		float fThen7 = (iSlow12 ? 0.5f : 0.600000024f);
		float fElse7 = (iSlow17 ? 0.400000006f : 0.800000012f);
		float fSlow22 = (iSlow11 ? fElse7 : fThen7);
		float fSlow23 = ((0.419999987f * fSlow1) + 1.0f);
		float fSlow24 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.39999998f * fSlow5))));
		float fSlow25 = (2.0f * std::cos((fConst5 * fSlow7)));
		float fThen10 = (iSlow12 ? 0.100000001f : 1.0f);
		float fElse10 = (iSlow17 ? 0.100000001f : 0.400000006f);
		float fSlow26 = (iSlow11 ? fElse10 : fThen10);
		float fSlow27 = ((0.600000024f * fSlow1) + 1.0f);
		float fSlow28 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.899999976f * fSlow5))));
		float fSlow29 = (2.0f * std::cos((fConst6 * fSlow7)));
		float fThen13 = (iSlow12 ? 0.0500000007f : 1.0f);
		float fElse13 = (iSlow17 ? 0.0500000007f : 0.200000003f);
		float fSlow30 = (iSlow11 ? fElse13 : fThen13);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow10;
			float fTemp0 = (fSlow10 - fVec0[1]);
			float fTemp1 = (fSlow9 * (fTemp0 * float((fTemp0 > 0.0f))));
			float fTempFTZ0 = ((fSlow6 * ((fSlow8 * fRec0[1]) - (fSlow6 * fRec0[2]))) + fTemp1);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fTemp1 + (fSlow15 * ((fSlow16 * fRec1[1]) - (fSlow15 * fRec1[2]))));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp1 + (fSlow20 * ((fSlow21 * fRec2[1]) - (fSlow20 * fRec2[2]))));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 + (fSlow24 * ((fSlow25 * fRec3[1]) - (fSlow24 * fRec3[2]))));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 + (fSlow28 * ((fSlow29 * fRec4[1]) - (fSlow28 * fRec4[2]))));
			fRec4[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((fSlow2 * (((((fSlow3 * (fRec0[0] * fSlow13)) + (fSlow14 * (fRec1[0] * fSlow18))) + (fSlow19 * (fRec2[0] * fSlow22))) + (fSlow23 * (fRec3[0] * fSlow26))) + (fSlow27 * (fRec4[0] * fSlow30)))))))));
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
