/* ------------------------------------------------------------
name: "bayan"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBayanDSP_H__
#define  __FaustBayanDSP_H__

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
#define FAUSTCLASS FaustBayanDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBayanDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fConst3;
	FAUSTFLOAT fHslider4;
	float fConst4;
	float fRec1[2];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[3];
	float fConst5;
	float fRec2[3];
	float fConst6;
	float fRec3[3];
	float fConst7;
	float fRec4[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("filename", "bayan.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "bayan");
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
		fConst2 = (6.28318548f / fConst0);
		fConst3 = (44.0999985f / fConst0);
		fConst4 = (1.0f - fConst3);
		fConst5 = (13.1946888f / fConst0);
		fConst6 = (20.1061935f / fConst0);
		fConst7 = (28.274334f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.90000000000000002f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(110.0f);
		fHslider4 = FAUSTFLOAT(1.2f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec0[l2] = 0.0f;
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
	
	virtual FaustBayanDSP* clone() {
		return new FaustBayanDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bayan");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(110.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.899999976f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("meend", &fHslider4, FAUSTFLOAT(1.20000005f), FAUSTFLOAT(0.5f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		int iSlow2 = (fSlow1 >= 2.0f);
		int iSlow3 = (fSlow1 >= 1.0f);
		int iSlow4 = (fSlow1 >= 3.0f);
		float fThen2 = (iSlow3 ? 1.10000002f : 0.899999976f);
		float fElse2 = (iSlow4 ? 0.899999976f : 1.0f);
		float fSlow5 = (iSlow2 ? fElse2 : fThen2);
		float fSlow6 = float(fHslider2);
		float fSlow7 = (1.0f - (0.0500000007f * fSlow6));
		float fThen5 = (iSlow3 ? 0.550000012f : 0.0299999993f);
		float fElse5 = (iSlow4 ? 0.0299999993f : 0.25f);
		float fSlow8 = (iSlow2 ? fElse5 : fThen5);
		float fSlow9 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.79999995f * fSlow8))));
		float fSlow10 = float(fHslider3);
		float fSlow11 = (fConst2 * fSlow10);
		float fElse6 = float(fHslider4);
		float fSlow12 = (fConst3 * (((fSlow1 < 2.5f) * (fSlow1 > 0.5f)) ? fElse6 : 1.0f));
		float fSlow13 = (0.00200000009f * fSlow6);
		float fSlow14 = float(fButton0);
		float fElse8 = (iSlow4 ? 1.5f : 1.20000005f);
		float fSlow15 = (iSlow2 ? fElse8 : 1.5f);
		float fSlow16 = ((0.100000001f * fSlow6) + 1.0f);
		float fSlow17 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.20000005f * fSlow8))));
		float fSlow18 = (fConst5 * fSlow10);
		float fThen11 = (iSlow3 ? 0.800000012f : 0.300000012f);
		float fElse11 = (iSlow4 ? 0.300000012f : 0.899999976f);
		float fSlow19 = (iSlow2 ? fElse11 : fThen11);
		float fSlow20 = ((0.25f * fSlow6) + 1.0f);
		float fSlow21 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.800000012f * fSlow8))));
		float fSlow22 = (fConst6 * fSlow10);
		float fThen14 = (iSlow3 ? 0.5f : 0.100000001f);
		float fElse14 = (iSlow4 ? 0.100000001f : 0.699999988f);
		float fSlow23 = (iSlow2 ? fElse14 : fThen14);
		float fSlow24 = ((0.400000006f * fSlow6) + 1.0f);
		float fSlow25 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.5f * fSlow8))));
		float fSlow26 = (fConst7 * fSlow10);
		float fThen17 = (iSlow3 ? 0.300000012f : 0.0f);
		float fElse17 = (iSlow4 ? 0.0f : 0.5f);
		float fSlow27 = (iSlow2 ? fElse17 : fThen17);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow12 + (fConst4 * fRec1[1]));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec0[0] = fSlow14;
			float fTemp0 = (fSlow14 - fVec0[1]);
			float fTemp1 = (fSlow13 * (fTemp0 * float((fTemp0 > 0.0f))));
			float fTempFTZ1 = ((fSlow9 * ((2.0f * (std::cos((fSlow11 * fRec1[0])) * fRec0[1])) - (fSlow9 * fRec0[2]))) + fTemp1);
			fRec0[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp1 + (fSlow17 * ((2.0f * (std::cos((fSlow18 * fRec1[0])) * fRec2[1])) - (fSlow17 * fRec2[2]))));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 + (fSlow21 * ((2.0f * (std::cos((fSlow22 * fRec1[0])) * fRec3[1])) - (fSlow21 * fRec3[2]))));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 + (fSlow25 * ((2.0f * (std::cos((fSlow26 * fRec1[0])) * fRec4[1])) - (fSlow25 * fRec4[2]))));
			fRec4[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((20.0f * (fSlow5 * ((((fSlow7 * (fRec0[0] * fSlow15)) + (fSlow16 * (fRec2[0] * fSlow19))) + (fSlow20 * (fRec3[0] * fSlow23))) + (fSlow24 * (fRec4[0] * fSlow27))))))))));
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
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
