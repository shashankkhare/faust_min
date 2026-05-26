/* ------------------------------------------------------------
name: "sitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustSitarDSP_H__
#define  __FaustSitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSitarDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fVec0[2];
	float fRec5[2];
	float fRec4[2];
	float fRec3[2];
	float fRec2[2];
	float fRec1[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec7[2];
	FAUSTFLOAT fHslider3;
	int iRec8[2];
	int IOTA;
	float fVec2[8192];
	float fRec0[2];
	FAUSTFLOAT fHslider4;
	float fConst1;
	float fConst2;
	float fRec9[3];
	float fConst3;
	float fRec10[3];
	float fConst4;
	float fRec11[3];
	float fConst5;
	float fRec12[3];
	float fConst6;
	float fRec13[3];
	float fConst7;
	float fRec14[3];
	float fConst8;
	float fRec15[3];
	float fConst9;
	float fRec16[3];
	float fConst10;
	float fRec17[3];
	float fConst11;
	float fRec18[3];
	float fConst12;
	float fRec19[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "sitar.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "sitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		fConst1 = (1.0f / fConst0);
		fConst2 = (6.28318548f / fConst0);
		fConst3 = (7.06858349f / fConst0);
		fConst4 = (7.85398149f / fConst0);
		fConst5 = (8.37548637f / fConst0);
		fConst6 = (9.42477798f / fConst0);
		fConst7 = (10.4677868f / fConst0);
		fConst8 = (11.7809725f / fConst0);
		fConst9 = (12.566371f / fConst0);
		fConst10 = (14.137167f / fConst0);
		fConst11 = (15.707963f / fConst0);
		fConst12 = (18.849556f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(146.83000000000001f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(0.20000000000000001f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec6[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec5[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec8[l9] = 0;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 8192); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec0[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec11[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec12[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec13[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec14[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec15[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec16[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec17[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec18[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec19[l22] = 0.0f;
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
	
	virtual FaustSitarDSP* clone() {
		return new FaustSitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("sitar");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider4, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider1);
		float fSlow1 = std::max<float>(0.0f, std::min<float>(1.0f, (0.00192307692f * (fSlow0 + -80.0f))));
		float fSlow2 = (float(fHslider0) * ((1.5f * fSlow1) + 1.0f));
		float fSlow3 = (fConst0 / fSlow0);
		int iSlow4 = int((fSlow3 + -1.0f));
		float fSlow5 = float(iSlow4);
		float fSlow6 = (fSlow5 + (2.0f - fSlow3));
		float fSlow7 = std::pow(0.00100000005f, (1.0f / (fSlow0 * (9.0f - (3.0f * fSlow1)))));
		float fSlow8 = (0.00999999978f * fSlow1);
		float fSlow9 = (0.0299999993f - fSlow8);
		float fSlow10 = (fSlow8 + 0.970000029f);
		float fSlow11 = (0.0399999991f * fSlow1);
		float fSlow12 = (fSlow11 + 0.0799999982f);
		float fSlow13 = (0.850000024f - (0.25f * fSlow1));
		float fSlow14 = ((float(fHslider2) * fSlow13) + fSlow13);
		float fSlow15 = (0.349999994f - (0.200000003f * fSlow1));
		float fSlow16 = (fSlow8 + 0.985000014f);
		float fSlow17 = float(fButton0);
		float fSlow18 = (float(fHslider3) * (0.25f - (0.0500000007f * fSlow1)));
		int iSlow19 = std::min<int>(16384, std::max<int>(0, iSlow4));
		float fSlow20 = (fSlow3 + (-1.0f - fSlow5));
		int iSlow21 = std::min<int>(16384, std::max<int>(0, (iSlow4 + 1)));
		float fSlow22 = float(fHslider4);
		float fSlow23 = std::pow(0.00100000005f, (fConst1 / (1.20000005f - (0.600000024f * fSlow1))));
		float fSlow24 = (2.0f * std::cos((fConst2 * fSlow0)));
		float fSlow25 = (2.0f * std::cos((fConst3 * fSlow0)));
		float fSlow26 = (2.0f * std::cos((fConst4 * fSlow0)));
		float fSlow27 = (2.0f * std::cos((fConst5 * fSlow0)));
		float fSlow28 = (2.0f * std::cos((fConst6 * fSlow0)));
		float fSlow29 = (2.0f * std::cos((fConst7 * fSlow0)));
		float fSlow30 = (2.0f * std::cos((fConst8 * fSlow0)));
		float fSlow31 = (2.0f * std::cos((fConst9 * fSlow0)));
		float fSlow32 = (2.0f * std::cos((fConst10 * fSlow0)));
		float fSlow33 = (2.0f * std::cos((fConst11 * fSlow0)));
		float fSlow34 = (2.0f * std::cos((fConst12 * fSlow0)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fElse0 = (fSlow11 + (0.0799999982f - (fSlow14 * ((fRec0[1] + -0.0799999982f) - fSlow11))));
			fRec6[0] = ((fSlow9 * fRec6[1]) + (fSlow10 * std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fRec0[1] > fSlow12) ? fElse0 : fRec0[1])))));
			float fTemp0 = (fSlow7 * fRec6[0]);
			fVec0[0] = fTemp0;
			fRec5[0] = (fVec0[1] - (fSlow15 * (fRec5[1] - fTemp0)));
			fRec4[0] = (fRec5[1] - (fSlow15 * (fRec4[1] - fRec5[0])));
			fRec3[0] = (fRec4[1] - (fSlow15 * (fRec3[1] - fRec4[0])));
			fRec2[0] = (fRec3[1] - (fSlow15 * (fRec2[1] - fRec3[0])));
			fRec1[0] = ((fRec2[0] + (fSlow16 * fRec1[1])) - fRec2[1]);
			fVec1[0] = fSlow17;
			float fThen1 = std::max<float>(0.0f, (fRec7[1] + -1.0f));
			fRec7[0] = (((fSlow17 - fVec1[1]) > 0.0f) ? 24.0f : fThen1);
			int iTemp1 = (fRec7[0] > 0.0f);
			float fTemp2 = float((iTemp1 == 0));
			iRec8[0] = ((1103515245 * iRec8[1]) + 12345);
			float fTemp3 = ((std::max<float>(-1.0f, std::min<float>(1.0f, fRec1[0])) * fTemp2) + (fSlow18 * (float(iTemp1) * ((0.5f * std::sin((0.261799395f * (24.0f - fRec7[0])))) + (2.32830644e-10f * float(iRec8[0]))))));
			fVec2[(IOTA & 8191)] = fTemp3;
			fRec0[0] = ((fSlow6 * fVec2[((IOTA - iSlow19) & 8191)]) + (fSlow20 * fVec2[((IOTA - iSlow21) & 8191)]));
			fRec9[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow24 * fRec9[1]) - (fSlow23 * fRec9[2])))));
			fRec10[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow25 * fRec10[1]) - (fSlow23 * fRec10[2])))));
			fRec11[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow26 * fRec11[1]) - (fSlow23 * fRec11[2])))));
			fRec12[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow27 * fRec12[1]) - (fSlow23 * fRec12[2])))));
			fRec13[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow28 * fRec13[1]) - (fSlow23 * fRec13[2])))));
			fRec14[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow29 * fRec14[1]) - (fSlow23 * fRec14[2])))));
			fRec15[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow30 * fRec15[1]) - (fSlow23 * fRec15[2])))));
			fRec16[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow31 * fRec16[1]) - (fSlow23 * fRec16[2])))));
			fRec17[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow32 * fRec17[1]) - (fSlow23 * fRec17[2])))));
			fRec18[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow33 * fRec18[1]) - (fSlow23 * fRec18[2])))));
			fRec19[0] = (fRec0[0] + (fSlow23 * (fTemp2 * ((fSlow34 * fRec19[1]) - (fSlow23 * fRec19[2])))));
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow2 * (fRec0[0] + (fSlow22 * ((((((((((fRec9[0] + fRec10[0]) + fRec11[0]) + fRec12[0]) + fRec13[0]) + fRec14[0]) + fRec15[0]) + fRec16[0]) + fRec17[0]) + fRec18[0]) + fRec19[0]))))))));
			fRec6[1] = fRec6[0];
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fVec1[1] = fVec1[0];
			fRec7[1] = fRec7[0];
			iRec8[1] = iRec8[0];
			IOTA = (IOTA + 1);
			fRec0[1] = fRec0[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
		}
	}

};

#endif
