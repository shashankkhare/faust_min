/* ------------------------------------------------------------
name: "sarod"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustSarodDSP_H__
#define  __FaustSarodDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSarodDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSarodDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	float fRec2[2];
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	int iRec3[2];
	float fConst1;
	float fConst2;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iVec2[2];
	int iRec4[2];
	float fConst3;
	int IOTA;
	float fVec3[8192];
	float fRec0[2];
	FAUSTFLOAT fHslider3;
	float fConst4;
	float fConst5;
	float fRec5[3];
	float fConst6;
	float fRec6[3];
	float fConst7;
	float fRec7[3];
	float fConst8;
	float fRec8[3];
	float fConst9;
	float fRec9[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "sarod.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "sarod");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
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
		fConst1 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / std::max<float>(1.0f, (0.0199999996f * fConst0)));
		fConst4 = std::pow(0.00100000005f, (0.5f / fConst0));
		fConst5 = (6.28318548f / fConst0);
		fConst6 = (7.85398149f / fConst0);
		fConst7 = (9.42477798f / fConst0);
		fConst8 = (12.566371f / fConst0);
		fConst9 = (18.849556f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(146.83000000000001f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.29999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec3[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec4[l6] = 0;
		}
		IOTA = 0;
		for (int l7 = 0; (l7 < 8192); l7 = (l7 + 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec0[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec5[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec6[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec9[l13] = 0.0f;
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
	
	virtual FaustSarodDSP* clone() {
		return new FaustSarodDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("sarod");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("symp_gain", &fHslider3, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.800000012f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fConst0 / fSlow1);
		int iSlow3 = int((fSlow2 + -1.0f));
		float fSlow4 = float(iSlow3);
		float fSlow5 = (fSlow4 + (2.0f - fSlow2));
		float fSlow6 = float(fHslider2);
		float fSlow7 = float(fButton0);
		int iSlow8 = std::min<int>(16384, std::max<int>(0, iSlow3));
		float fSlow9 = (fSlow2 + (-1.0f - fSlow4));
		int iSlow10 = std::min<int>(16384, std::max<int>(0, (iSlow3 + 1)));
		float fSlow11 = float(fHslider3);
		float fSlow12 = (2.0f * std::cos((fConst5 * fSlow1)));
		float fSlow13 = (2.0f * std::cos((fConst6 * fSlow1)));
		float fSlow14 = (2.0f * std::cos((fConst7 * fSlow1)));
		float fSlow15 = (2.0f * std::cos((fConst8 * fSlow1)));
		float fSlow16 = (2.0f * std::cos((fConst9 * fSlow1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			fRec2[0] = ((0.00499999989f * fRec2[1]) + (0.995000005f * fRec0[1]));
			fRec1[0] = (fRec2[1] + (0.200000003f * (fRec2[0] - fRec1[1])));
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			fVec1[0] = fSlow7;
			int iTemp0 = (fSlow7 > fVec1[1]);
			iVec2[0] = iTemp0;
			iRec4[0] = ((iTemp0 > iVec2[1]) + ((iTemp0 <= iVec2[1]) * (iRec4[1] + (iRec4[1] > 0))));
			float fTemp1 = float(iRec4[0]);
			float fTemp2 = ((0.998000026f * fRec1[0]) + (fSlow6 * (((0.400000006f * float((1 - iVec0[1]))) + (2.79396783e-10f * float(iRec3[0]))) * std::max<float>(0.0f, std::min<float>((fConst2 * fTemp1), (1.0f - (fConst3 * (fTemp1 - fConst1))))))));
			fVec3[(IOTA & 8191)] = fTemp2;
			fRec0[0] = ((fSlow5 * fVec3[((IOTA - iSlow8) & 8191)]) + (fSlow9 * fVec3[((IOTA - iSlow10) & 8191)]));
			fRec5[0] = (fRec0[0] + (fConst4 * ((fSlow12 * fRec5[1]) - (fConst4 * fRec5[2]))));
			fRec6[0] = (fRec0[0] + (fConst4 * ((fSlow13 * fRec6[1]) - (fConst4 * fRec6[2]))));
			fRec7[0] = (fRec0[0] + (fConst4 * ((fSlow14 * fRec7[1]) - (fConst4 * fRec7[2]))));
			fRec8[0] = (fRec0[0] + (fConst4 * ((fSlow15 * fRec8[1]) - (fConst4 * fRec8[2]))));
			fRec9[0] = (fRec0[0] + (fConst4 * ((fSlow16 * fRec9[1]) - (fConst4 * fRec9[2]))));
			output0[i0] = FAUSTFLOAT(std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow0 * (fRec0[0] + (fSlow11 * ((((fRec5[0] + fRec6[0]) + fRec7[0]) + fRec8[0]) + fRec9[0])))))));
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			iRec3[1] = iRec3[0];
			fVec1[1] = fVec1[0];
			iVec2[1] = iVec2[0];
			iRec4[1] = iRec4[0];
			IOTA = (IOTA + 1);
			fRec0[1] = fRec0[0];
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
