/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "sitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
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
#include <float.h>
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
	FAUSTFLOAT fHslider5;
	float fRec15[2];
	float fVec3[2];
	float fRec14[2];
	float fRec13[2];
	float fRec12[2];
	float fRec11[2];
	float fRec10[2];
	float fVec4[16384];
	float fRec9[2];
	FAUSTFLOAT fHslider6;
	float fRec22[2];
	float fVec5[2];
	float fRec21[2];
	float fRec20[2];
	float fRec19[2];
	float fRec18[2];
	float fRec17[2];
	float fVec6[16384];
	float fRec16[2];
	FAUSTFLOAT fHslider7;
	float fRec29[2];
	float fVec7[2];
	float fRec28[2];
	float fRec27[2];
	float fRec26[2];
	float fRec25[2];
	float fRec24[2];
	float fVec8[16384];
	float fRec23[2];
	FAUSTFLOAT fHslider8;
	float fConst1;
	float fConst2;
	float fRec30[3];
	float fConst3;
	float fRec31[3];
	float fConst4;
	float fRec32[3];
	float fConst5;
	float fRec33[3];
	float fConst6;
	float fRec34[3];
	float fConst7;
	float fRec35[3];
	float fConst8;
	float fRec36[3];
	float fConst9;
	float fRec37[3];
	float fConst10;
	float fRec38[3];
	float fConst11;
	float fRec39[3];
	float fConst12;
	float fRec40[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
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
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(2.0f);
		fHslider7 = FAUSTFLOAT(4.0f);
		fHslider8 = FAUSTFLOAT(0.20000000000000001f);
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
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec15[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec11[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec10[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 16384); l19 = (l19 + 1)) {
			fVec4[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec9[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec22[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fVec5[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec21[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec20[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec19[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec18[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec17[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 16384); l28 = (l28 + 1)) {
			fVec6[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec16[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec29[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fVec7[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec28[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec27[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec26[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec25[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec24[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 16384); l37 = (l37 + 1)) {
			fVec8[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec23[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec30[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec31[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec32[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec33[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec34[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec35[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec36[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec37[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec38[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec39[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec40[l49] = 0.0f;
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
		ui_interface->addHorizontalSlider("chikari1_ratio", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari2_ratio", &fHslider6, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chikari3_ratio", &fHslider7, FAUSTFLOAT(4.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("symp_gain", &fHslider8, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
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
		float fSlow22 = (0.349999994f * float((float(fHslider4) >= 0.5f)));
		float fSlow23 = (fConst0 / (fSlow0 * float(fHslider5)));
		int iSlow24 = int((fSlow23 + -1.0f));
		float fSlow25 = float(iSlow24);
		float fSlow26 = (fSlow25 + (2.0f - fSlow23));
		int iSlow27 = std::min<int>(8192, std::max<int>(0, iSlow24));
		float fSlow28 = (fSlow23 + (-1.0f - fSlow25));
		int iSlow29 = std::min<int>(8192, std::max<int>(0, (iSlow24 + 1)));
		float fSlow30 = (fConst0 / (fSlow0 * float(fHslider6)));
		int iSlow31 = int((fSlow30 + -1.0f));
		float fSlow32 = float(iSlow31);
		float fSlow33 = (fSlow32 + (2.0f - fSlow30));
		int iSlow34 = std::min<int>(8192, std::max<int>(0, iSlow31));
		float fSlow35 = (fSlow30 + (-1.0f - fSlow32));
		int iSlow36 = std::min<int>(8192, std::max<int>(0, (iSlow31 + 1)));
		float fSlow37 = (fConst0 / (float(fHslider7) * fSlow0));
		int iSlow38 = int((fSlow37 + -1.0f));
		float fSlow39 = float(iSlow38);
		float fSlow40 = (fSlow39 + (2.0f - fSlow37));
		int iSlow41 = std::min<int>(8192, std::max<int>(0, iSlow38));
		float fSlow42 = (fSlow37 + (-1.0f - fSlow39));
		int iSlow43 = std::min<int>(8192, std::max<int>(0, (iSlow38 + 1)));
		float fSlow44 = float(fHslider8);
		float fSlow45 = std::pow(0.00100000005f, (fConst1 / (1.20000005f - (0.600000024f * fSlow1))));
		float fSlow46 = (2.0f * std::cos((fConst2 * fSlow0)));
		float fSlow47 = (2.0f * std::cos((fConst3 * fSlow0)));
		float fSlow48 = (2.0f * std::cos((fConst4 * fSlow0)));
		float fSlow49 = (2.0f * std::cos((fConst5 * fSlow0)));
		float fSlow50 = (2.0f * std::cos((fConst6 * fSlow0)));
		float fSlow51 = (2.0f * std::cos((fConst7 * fSlow0)));
		float fSlow52 = (2.0f * std::cos((fConst8 * fSlow0)));
		float fSlow53 = (2.0f * std::cos((fConst9 * fSlow0)));
		float fSlow54 = (2.0f * std::cos((fConst10 * fSlow0)));
		float fSlow55 = (2.0f * std::cos((fConst11 * fSlow0)));
		float fSlow56 = (2.0f * std::cos((fConst12 * fSlow0)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fElse0 = (fSlow11 + (0.0799999982f - (fSlow14 * ((fRec0[1] + -0.0799999982f) - fSlow11))));
			float fTempFTZ0 = ((fSlow9 * fRec6[1]) + (fSlow10 * std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fRec0[1] > fSlow12) ? fElse0 : fRec0[1])))));
			fRec6[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = (fSlow7 * fRec6[0]);
			fVec0[0] = fTemp0;
			float fTempFTZ1 = (fVec0[1] - (fSlow15 * (fRec5[1] - fTemp0)));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fRec5[1] - (fSlow15 * (fRec4[1] - fRec5[0])));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fRec4[1] - (fSlow15 * (fRec3[1] - fRec4[0])));
			fRec3[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fRec3[1] - (fSlow15 * (fRec2[1] - fRec3[0])));
			fRec2[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((fRec2[0] + (fSlow16 * fRec1[1])) - fRec2[1]);
			fRec1[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			fVec1[0] = fSlow17;
			float fThen1 = std::max<float>(0.0f, (fRec7[1] + -1.0f));
			float fTempFTZ6 = (((fSlow17 - fVec1[1]) > 0.0f) ? 24.0f : fThen1);
			fRec7[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			int iTemp1 = (fRec7[0] > 0.0f);
			float fTemp2 = float((iTemp1 == 0));
			iRec8[0] = ((1103515245 * iRec8[1]) + 12345);
			float fTemp3 = (fSlow18 * (float(iTemp1) * ((0.5f * std::sin((0.261799395f * (24.0f - fRec7[0])))) + (2.32830644e-10f * float(iRec8[0])))));
			float fTemp4 = ((std::max<float>(-1.0f, std::min<float>(1.0f, fRec1[0])) * fTemp2) + fTemp3);
			fVec2[(IOTA & 8191)] = fTemp4;
			float fTempFTZ7 = ((fSlow6 * fVec2[((IOTA - iSlow19) & 8191)]) + (fSlow20 * fVec2[((IOTA - iSlow21) & 8191)]));
			fRec0[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fElse2 = (fSlow11 + (0.0799999982f - (fSlow14 * ((fRec9[1] + -0.0799999982f) - fSlow11))));
			float fTempFTZ8 = ((fSlow9 * fRec15[1]) + (fSlow10 * std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fRec9[1] > fSlow12) ? fElse2 : fRec9[1])))));
			fRec15[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp5 = (fSlow7 * fRec15[0]);
			fVec3[0] = fTemp5;
			float fTempFTZ9 = (fVec3[1] - (fSlow15 * (fRec14[1] - fTemp5)));
			fRec14[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fRec14[1] - (fSlow15 * (fRec13[1] - fRec14[0])));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fRec13[1] - (fSlow15 * (fRec12[1] - fRec13[0])));
			fRec12[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fRec12[1] - (fSlow15 * (fRec11[1] - fRec12[0])));
			fRec11[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = ((fRec11[0] + (fSlow16 * fRec10[1])) - fRec11[1]);
			fRec10[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp6 = ((std::max<float>(-1.0f, std::min<float>(1.0f, fRec10[0])) * fTemp2) + fTemp3);
			fVec4[(IOTA & 16383)] = fTemp6;
			float fTempFTZ14 = ((fSlow26 * fVec4[((IOTA - iSlow27) & 16383)]) + (fSlow28 * fVec4[((IOTA - iSlow29) & 16383)]));
			fRec9[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fElse3 = (fSlow11 + (0.0799999982f - (fSlow14 * ((fRec16[1] + -0.0799999982f) - fSlow11))));
			float fTempFTZ15 = ((fSlow9 * fRec22[1]) + (fSlow10 * std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fRec16[1] > fSlow12) ? fElse3 : fRec16[1])))));
			fRec22[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp7 = (fSlow7 * fRec22[0]);
			fVec5[0] = fTemp7;
			float fTempFTZ16 = (fVec5[1] - (fSlow15 * (fRec21[1] - fTemp7)));
			fRec21[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fRec21[1] - (fSlow15 * (fRec20[1] - fRec21[0])));
			fRec20[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fRec20[1] - (fSlow15 * (fRec19[1] - fRec20[0])));
			fRec19[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fRec19[1] - (fSlow15 * (fRec18[1] - fRec19[0])));
			fRec18[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = ((fRec18[0] + (fSlow16 * fRec17[1])) - fRec18[1]);
			fRec17[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp8 = ((std::max<float>(-1.0f, std::min<float>(1.0f, fRec17[0])) * fTemp2) + fTemp3);
			fVec6[(IOTA & 16383)] = fTemp8;
			float fTempFTZ21 = ((fSlow33 * fVec6[((IOTA - iSlow34) & 16383)]) + (fSlow35 * fVec6[((IOTA - iSlow36) & 16383)]));
			fRec16[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fElse4 = (fSlow11 + (0.0799999982f - (fSlow14 * ((fRec23[1] + -0.0799999982f) - fSlow11))));
			float fTempFTZ22 = ((fSlow9 * fRec29[1]) + (fSlow10 * std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fRec23[1] > fSlow12) ? fElse4 : fRec23[1])))));
			fRec29[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTemp9 = (fSlow7 * fRec29[0]);
			fVec7[0] = fTemp9;
			float fTempFTZ23 = (fVec7[1] - (fSlow15 * (fRec28[1] - fTemp9)));
			fRec28[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fRec28[1] - (fSlow15 * (fRec27[1] - fRec28[0])));
			fRec27[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fRec27[1] - (fSlow15 * (fRec26[1] - fRec27[0])));
			fRec26[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = (fRec26[1] - (fSlow15 * (fRec25[1] - fRec26[0])));
			fRec25[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = ((fRec25[0] + (fSlow16 * fRec24[1])) - fRec25[1]);
			fRec24[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTemp10 = ((std::max<float>(-1.0f, std::min<float>(1.0f, fRec24[0])) * fTemp2) + fTemp3);
			fVec8[(IOTA & 16383)] = fTemp10;
			float fTempFTZ28 = ((fSlow40 * fVec8[((IOTA - iSlow41) & 16383)]) + (fSlow42 * fVec8[((IOTA - iSlow43) & 16383)]));
			fRec23[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTemp11 = (fRec0[0] + (fSlow22 * ((fRec9[0] + fRec16[0]) + fRec23[0])));
			float fTempFTZ29 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow46 * fRec30[1]) - (fSlow45 * fRec30[2])))));
			fRec30[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow47 * fRec31[1]) - (fSlow45 * fRec31[2])))));
			fRec31[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow48 * fRec32[1]) - (fSlow45 * fRec32[2])))));
			fRec32[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow49 * fRec33[1]) - (fSlow45 * fRec33[2])))));
			fRec33[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow50 * fRec34[1]) - (fSlow45 * fRec34[2])))));
			fRec34[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow51 * fRec35[1]) - (fSlow45 * fRec35[2])))));
			fRec35[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow52 * fRec36[1]) - (fSlow45 * fRec36[2])))));
			fRec36[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow53 * fRec37[1]) - (fSlow45 * fRec37[2])))));
			fRec37[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow54 * fRec38[1]) - (fSlow45 * fRec38[2])))));
			fRec38[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow55 * fRec39[1]) - (fSlow45 * fRec39[2])))));
			fRec39[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fTemp11 + (fSlow45 * (fTemp2 * ((fSlow56 * fRec40[1]) - (fSlow45 * fRec40[2])))));
			fRec40[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow2 * (fTemp11 + (fSlow44 * ((((((((((fRec30[0] + fRec31[0]) + fRec32[0]) + fRec33[0]) + fRec34[0]) + fRec35[0]) + fRec36[0]) + fRec37[0]) + fRec38[0]) + fRec39[0]) + fRec40[0]))))))));
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
			fRec15[1] = fRec15[0];
			fVec3[1] = fVec3[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec22[1] = fRec22[0];
			fVec5[1] = fVec5[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec29[1] = fRec29[0];
			fVec7[1] = fVec7[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
		}
	}

};

#endif
