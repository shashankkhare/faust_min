/* ------------------------------------------------------------
name: "bayan"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
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
	int fSampleRate;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fConst3;
	FAUSTFLOAT fHslider3;
	float fConst4;
	float fRec1[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[3];
	float fConst5;
	float fRec2[3];
	float fConst6;
	float fRec3[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
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
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.90000000000000002f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(110.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
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
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(110.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.899999976f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("meend", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider1);
		float fSlow1 = (20.0f * (float(fHslider0) * ((9.99999975e-06f * fSlow0) + 1.0f)));
		float fSlow2 = ((0.0500000007f * float((fSlow0 < 0.5f))) + (0.400000006f * float((fSlow0 >= 0.5f))));
		float fSlow3 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.79999995f * fSlow2))));
		float fSlow4 = float(fHslider2);
		float fSlow5 = (fConst2 * fSlow4);
		float fSlow6 = (fConst3 * float(fHslider3));
		float fSlow7 = float(fHslider4);
		float fSlow8 = (fSlow7 * (1.0f - fSlow3));
		float fSlow9 = float(fButton0);
		float fSlow10 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, fSlow2)));
		float fSlow11 = (fConst5 * fSlow4);
		float fSlow12 = (fSlow7 * (1.0f - fSlow10));
		float fSlow13 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.5f * fSlow2))));
		float fSlow14 = (fConst6 * fSlow4);
		float fSlow15 = (fSlow7 * (1.0f - fSlow13));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec1[0] = (fSlow6 + (fConst4 * fRec1[1]));
			fVec0[0] = fSlow9;
			float fTemp0 = (fSlow9 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			fRec0[0] = ((fSlow3 * ((2.0f * (std::cos((fSlow5 * fRec1[0])) * fRec0[1])) - (fSlow3 * fRec0[2]))) + (fSlow8 * fTemp1));
			fRec2[0] = ((fSlow10 * ((2.0f * (std::cos((fSlow11 * fRec1[0])) * fRec2[1])) - (fSlow10 * fRec2[2]))) + (fSlow12 * fTemp1));
			fRec3[0] = ((fSlow13 * ((2.0f * (std::cos((fSlow14 * fRec1[0])) * fRec3[1])) - (fSlow13 * fRec3[2]))) + (fSlow15 * fTemp1));
			output0[i0] = FAUSTFLOAT((fSlow1 * float(tanhf(float((1.04999995f * ((fRec0[0] + (0.699999988f * fRec2[0])) + (0.400000006f * fRec3[0]))))))));
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
