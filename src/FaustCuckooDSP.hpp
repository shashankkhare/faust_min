/* ------------------------------------------------------------
name: "cuckoo"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustCuckooDSP_H__
#define  __FaustCuckooDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustCuckooDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec1[2];
	
  public:
	
	int getNumInputsFaustCuckooDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustCuckooDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustCuckooDSPSIG0(int sample_rate) {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec1[l2] = 0;
		}
	}
	
	void fillFaustCuckooDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec1[0] = ((iVec0[1] + iRec1[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec1[0])));
			iVec0[1] = iVec0[0];
			iRec1[1] = iRec1[0];
		}
	}

};

static FaustCuckooDSPSIG0* newFaustCuckooDSPSIG0() { return (FaustCuckooDSPSIG0*)new FaustCuckooDSPSIG0(); }
static void deleteFaustCuckooDSPSIG0(FaustCuckooDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustCuckooDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustCuckooDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustCuckooDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec4[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	float fConst4;
	float fRec3[2];
	float fRec2[2];
	float fConst5;
	float fRec6[2];
	float fConst6;
	float fRec7[2];
	float fConst7;
	float fRec9[2];
	float fRec8[2];
	float fRec10[2];
	float fRec11[2];
	float fRec13[2];
	float fRec12[2];
	float fRec14[2];
	float fRec15[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("filename", "cuckoo.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "cuckoo");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
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
		FaustCuckooDSPSIG0* sig0 = newFaustCuckooDSPSIG0();
		sig0->instanceInitFaustCuckooDSPSIG0(sample_rate);
		sig0->fillFaustCuckooDSPSIG0(65536, ftbl0FaustCuckooDSPSIG0);
		deleteFaustCuckooDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (1.0f / fConst0);
		fConst4 = (0.0566666685f / fConst0);
		fConst5 = (2.0f / fConst0);
		fConst6 = (3.0f / fConst0);
		fConst7 = (10.4719753f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(587.33000000000004f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec4[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec8[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec12[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
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
	
	virtual FaustCuckooDSP* clone() {
		return new FaustCuckooDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("cuckoo");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(587.330017f), FAUSTFLOAT(200.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("type", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		int iSlow1 = int(float(fHslider1));
		int iSlow2 = (iSlow1 == 0);
		int iSlow3 = (iSlow1 == 1);
		float fSlow4 = float(fButton0);
		int iSlow5 = (fSlow4 > 0.0f);
		float fSlow6 = (fConst1 * float(fHslider2));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec1[0] = fSlow4;
			int iElse0 = (iRec4[1] + 1);
			int iThen1 = (iSlow5 ? iElse0 : 0);
			iRec4[0] = ((fSlow4 > fVec1[1]) ? 1 : iThen1);
			float fTemp0 = float(iRec4[0]);
			float fTemp1 = (fConst3 * fTemp0);
			int iTemp2 = (fTemp1 < 0.310000002f);
			int iTemp3 = (fTemp1 < 0.709999979f);
			int iTemp4 = (fTemp1 < 1.11000001f);
			float fTempFTZ1 = (fSlow6 + (fConst2 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp5 = (fTemp1 + -1.12f);
			float fTemp6 = std::sin((10.4719753f * (fTemp1 + -0.800000012f)));
			float fThen2 = (fRec5[0] * (1.14199996f - (0.546666682f * fTemp5)));
			float fElse2 = (1.09599996f * (fRec5[0] * ((0.0469999984f * fTemp6) + 1.0f)));
			float fTemp7 = std::sin((10.4719753f * (fTemp1 + -0.319999993f)));
			float fThen3 = (iTemp4 ? fElse2 : fThen2);
			float fElse3 = (1.10899997f * (fRec5[0] * ((0.0500000007f * fTemp7) + 1.0f)));
			float fThen4 = (iTemp3 ? fElse3 : fThen3);
			float fElse4 = (fRec5[0] * (1.0f - (fConst4 * fTemp0)));
			float fTempFTZ2 = ((fConst2 * fRec3[1]) + (fConst1 * (iTemp2 ? fElse4 : fThen4)));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp8 = (fRec2[1] + (fConst3 * fRec3[0]));
			float fTempFTZ3 = (fTemp8 - std::floor(fTemp8));
			fRec2[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp9 = (fRec6[1] + (fConst5 * fRec3[0]));
			float fTempFTZ4 = (fTemp9 - std::floor(fTemp9));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp10 = (fRec7[1] + (fConst6 * fRec3[0]));
			float fTempFTZ5 = (fTemp10 - std::floor(fTemp10));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp11 = std::sin((fConst7 * fTemp0));
			float fTemp12 = (std::max<float>(0.0f, fTemp11) * float(((fTemp1 >= 0.0f) * (fTemp1 < 0.300000012f))));
			float fTemp13 = std::sin((6.98131704f * fTemp5));
			float fTemp14 = (((0.75f * (std::max<float>(0.0f, fTemp7) * float(((fTemp1 >= 0.319999993f) * (fTemp1 < 0.620000005f))))) + (0.649999976f * (fTemp12 + (std::max<float>(0.0f, fTemp6) * float(((fTemp1 >= 0.800000012f) * (fTemp1 < 1.10000002f))))))) + (std::max<float>(0.0f, fTemp13) * float(((fTemp1 >= 1.12f) * (fTemp1 < 1.57000005f)))));
			float fThen5 = (0.840900004f * fRec5[0]);
			float fTempFTZ6 = ((fConst2 * fRec9[1]) + (fConst1 * ((fTemp1 < 0.349999994f) ? fRec5[0] : fThen5)));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp15 = (fRec8[1] + (fConst3 * fRec9[0]));
			float fTempFTZ7 = (fTemp15 - std::floor(fTemp15));
			fRec8[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp16 = (fRec10[1] + (fConst5 * fRec9[0]));
			float fTempFTZ8 = (fTemp16 - std::floor(fTemp16));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp17 = (fRec11[1] + (fConst6 * fRec9[0]));
			float fTempFTZ9 = (fTemp17 - std::floor(fTemp17));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fThen6 = (0.850000024f * (((ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec2[0]))] + (0.119999997f * ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec6[0]))])) + (0.0399999991f * ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec7[0]))])) * fTemp14));
			float fElse6 = (0.850000024f * (((ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec8[0]))] + (0.119999997f * ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec10[0]))])) + (0.0399999991f * ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec11[0]))])) * (fTemp12 + (std::max<float>(0.0f, std::sin((10.4719753f * (fTemp1 + -0.400000006f)))) * float(((fTemp1 >= 0.400000006f) * (fTemp1 < 0.699999988f)))))));
			float fThen7 = (0.79369998f * (fRec5[0] * ((0.0799999982f * fTemp13) + 1.0f)));
			float fElse7 = (fRec5[0] * ((0.0799999982f * std::sin((10.4719753f * (fTemp1 + -0.75999999f)))) + 1.0f));
			float fThen8 = (iTemp4 ? fElse7 : fThen7);
			float fElse8 = (1.18920004f * (fRec5[0] * ((0.0799999982f * fTemp7) + 1.0f)));
			float fThen9 = (iTemp3 ? fElse8 : fThen8);
			float fElse9 = (fRec5[0] * ((0.0799999982f * fTemp11) + 1.0f));
			float fTempFTZ10 = ((fConst2 * fRec13[1]) + (fConst1 * (iTemp2 ? fElse9 : fThen9)));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp18 = (fRec12[1] + (fConst3 * fRec13[0]));
			float fTempFTZ11 = (fTemp18 - std::floor(fTemp18));
			fRec12[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp19 = (fRec14[1] + (fConst5 * fRec13[0]));
			float fTempFTZ12 = (fTemp19 - std::floor(fTemp19));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp20 = (fRec15[1] + (fConst6 * fRec13[0]));
			float fTempFTZ13 = (fTemp20 - std::floor(fTemp20));
			fRec15[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fThen10 = (iSlow3 ? fElse6 : fThen6);
			float fElse10 = (0.850000024f * (fTemp14 * ((ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec12[0]))] + (0.119999997f * ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec14[0]))])) + (0.0399999991f * ftbl0FaustCuckooDSPSIG0[int((65536.0f * fRec15[0]))]))));
			output0[i0] = FAUSTFLOAT((fRec0[0] * (iSlow2 ? fElse10 : fThen10)));
			fRec0[1] = fRec0[0];
			fVec1[1] = fVec1[0];
			iRec4[1] = iRec4[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
		}
	}

};

#endif
