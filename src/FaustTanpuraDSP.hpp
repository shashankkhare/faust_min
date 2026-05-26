/* ------------------------------------------------------------
name: "tanpura"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTanpuraDSP_H__
#define  __FaustTanpuraDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTanpuraDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTanpuraDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int IOTA;
	int iVec1[524288];
	int iConst2;
	int iConst3;
	FAUSTFLOAT fHslider5;
	float fRec3[2];
	int iRec4[2];
	float fVec2[2];
	float fRec2[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	float fVec3[2];
	FAUSTFLOAT fHslider9;
	float fConst5;
	float fConst7;
	float fVec4[2];
	float fConst8;
	float fConst9;
	float fRec5[2];
	float fRec6[2];
	FAUSTFLOAT fHslider10;
	float fRec7[2];
	float fRec1[16384];
	int iConst10;
	int iConst11;
	float fRec10[2];
	float fVec5[2];
	float fRec9[2];
	FAUSTFLOAT fHslider11;
	float fVec6[2];
	float fVec7[2];
	float fRec11[2];
	float fRec12[2];
	float fRec13[2];
	float fRec8[8192];
	float fRec16[2];
	float fVec8[2];
	float fRec15[2];
	FAUSTFLOAT fHslider12;
	float fVec9[2];
	float fVec10[2];
	float fRec17[2];
	float fRec18[2];
	float fRec19[2];
	FAUSTFLOAT fHslider13;
	float fRec14[16384];
	int iConst12;
	int iConst13;
	float fRec22[2];
	float fVec11[2];
	float fRec21[2];
	FAUSTFLOAT fHslider14;
	float fVec12[2];
	float fVec13[2];
	float fRec23[2];
	float fRec24[2];
	float fRec25[2];
	float fRec20[8192];
	float fVec14[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "tanpura.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tanpura");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		iConst2 = int((1.5f * fConst0));
		iConst3 = (iConst2 + 1);
		float fConst4 = std::tan((6911.50391f / fConst0));
		fConst5 = (1.0f / fConst4);
		float fConst6 = (fConst5 + 1.0f);
		fConst7 = (0.0f - (1.0f / (fConst4 * fConst6)));
		fConst8 = (1.0f / fConst6);
		fConst9 = (1.0f - fConst5);
		iConst10 = int(fConst0);
		iConst11 = (iConst10 + 1);
		iConst12 = int((0.5f * fConst0));
		iConst13 = (iConst12 + 1);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(2000.0f);
		fHslider3 = FAUSTFLOAT(0.80000000000000004f);
		fHslider4 = FAUSTFLOAT(0.40000000000000002f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.0115f);
		fHslider6 = FAUSTFLOAT(130.81f);
		fHslider7 = FAUSTFLOAT(20.0f);
		fHslider8 = FAUSTFLOAT(0.070000000000000007f);
		fHslider9 = FAUSTFLOAT(0.55000000000000004f);
		fHslider10 = FAUSTFLOAT(0.014999999999999999f);
		fHslider11 = FAUSTFLOAT(35.0f);
		fHslider12 = FAUSTFLOAT(0.0f);
		fHslider13 = FAUSTFLOAT(55.0f);
		fHslider14 = FAUSTFLOAT(35.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		IOTA = 0;
		for (int l1 = 0; (l1 < 524288); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec4[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec3[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec4[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec5[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec6[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 16384); l11 = (l11 + 1)) {
			fRec1[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fVec5[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec9[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec6[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fVec7[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec11[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec12[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec13[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 8192); l20 = (l20 + 1)) {
			fRec8[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec16[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fVec8[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec15[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fVec9[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fVec10[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec17[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec18[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec19[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 16384); l29 = (l29 + 1)) {
			fRec14[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec22[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fVec11[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec21[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fVec12[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fVec13[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec23[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec24[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec25[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 8192); l38 = (l38 + 1)) {
			fRec20[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fVec14[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec0[l40] = 0.0f;
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
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("dispersion", &fHslider8, FAUSTFLOAT(0.0700000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excDur", &fHslider5, FAUSTFLOAT(0.0115f), FAUSTFLOAT(9.99999975e-05f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excGain", &fHslider4, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("excLPF", &fHslider2, FAUSTFLOAT(2000.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("freq", &fHslider6, FAUSTFLOAT(130.809998f), FAUSTFLOAT(40.0f), FAUSTFLOAT(600.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq1", &fHslider12, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider9, FAUSTFLOAT(0.550000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("jivariThreshold", &fHslider10, FAUSTFLOAT(0.0149999997f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("stringGainVal", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain0", &fHslider13, FAUSTFLOAT(55.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain1", &fHslider14, FAUSTFLOAT(35.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain2", &fHslider11, FAUSTFLOAT(35.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain3", &fHslider7, FAUSTFLOAT(20.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.25f * (float(fHslider0) * float(fHslider1)));
		float fSlow1 = (1.0f / std::tan((fConst1 * float(fHslider2))));
		float fSlow2 = (1.0f / (fSlow1 + 1.0f));
		float fSlow3 = (1.0f - fSlow1);
		float fSlow4 = (4.65661287e-10f * (float(fHslider3) * float(fHslider4)));
		float fSlow5 = float(fButton0);
		float fSlow6 = (fConst0 * float(fHslider5));
		float fSlow7 = float(fHslider6);
		float fSlow8 = std::exp((0.0f - (6.0f / (fSlow7 * std::max<float>(0.100000001f, float(fHslider7))))));
		float fSlow9 = float(fHslider8);
		float fSlow10 = std::sin(fSlow9);
		float fSlow11 = (fConst0 / std::max<float>(20.0f, (0.5f * fSlow7)));
		float fSlow12 = (fSlow11 + -2.0f);
		float fSlow13 = std::floor(fSlow12);
		float fSlow14 = (fSlow13 + (3.0f - fSlow11));
		int iSlow15 = int(fSlow12);
		int iSlow16 = (std::min<int>(8193, std::max<int>(0, iSlow15)) + 1);
		float fSlow17 = (fSlow11 + (-2.0f - fSlow13));
		int iSlow18 = (std::min<int>(8193, std::max<int>(0, (iSlow15 + 1))) + 1);
		float fSlow19 = float(fHslider9);
		float fSlow20 = float(fHslider10);
		float fSlow21 = std::cos(fSlow9);
		float fSlow22 = std::exp((0.0f - (3.0f / (fSlow7 * std::max<float>(0.100000001f, float(fHslider11))))));
		float fSlow23 = (fConst0 / std::max<float>(20.0f, fSlow7));
		float fSlow24 = (fSlow23 + -2.0f);
		float fSlow25 = std::floor(fSlow24);
		float fSlow26 = (fSlow25 + (3.0f - fSlow23));
		int iSlow27 = int(fSlow24);
		int iSlow28 = (std::min<int>(8193, std::max<int>(0, iSlow27)) + 1);
		float fSlow29 = (fSlow23 + (-2.0f - fSlow25));
		int iSlow30 = (std::min<int>(8193, std::max<int>(0, (iSlow27 + 1))) + 1);
		float fSlow31 = float(fHslider12);
		float fThen3 = (1.5f * fSlow7);
		float fSlow32 = ((fSlow31 > 0.0f) ? fSlow31 : fThen3);
		float fSlow33 = (fConst0 / std::max<float>(20.0f, fSlow32));
		float fSlow34 = (fSlow33 + -2.0f);
		int iSlow35 = int(fSlow34);
		int iSlow36 = (std::min<int>(8193, std::max<int>(0, iSlow35)) + 1);
		float fSlow37 = std::floor(fSlow34);
		float fSlow38 = (fSlow37 + (3.0f - fSlow33));
		float fSlow39 = (fSlow33 + (-2.0f - fSlow37));
		int iSlow40 = (std::min<int>(8193, std::max<int>(0, (iSlow35 + 1))) + 1);
		float fSlow41 = std::exp((0.0f - ((3.0f / std::max<float>(0.100000001f, float(fHslider13))) / fSlow32)));
		float fSlow42 = std::exp((0.0f - (3.0f / (fSlow7 * std::max<float>(0.100000001f, float(fHslider14))))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow5;
			int iTemp0 = ((fSlow5 - fVec0[1]) > 0.0f);
			iVec1[(IOTA & 524287)] = iTemp0;
			float fTemp1 = float((float((iVec1[((IOTA - iConst2) & 524287)] - iVec1[((IOTA - iConst3) & 524287)])) > 0.0f));
			float fThen0 = std::max<float>(0.0f, (fRec3[1] + -1.0f));
			float fTempFTZ0 = ((fTemp1 > 0.0f) ? fSlow6 : fThen0);
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTemp2 = float(iRec4[0]);
			float fTemp3 = (fSlow4 * (float((fRec3[0] > 0.0f)) * fTemp2));
			fVec2[0] = fTemp3;
			float fTempFTZ1 = (0.0f - (fSlow2 * ((fSlow3 * fRec2[1]) - (fTemp3 + fVec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp4 = ((fSlow14 * fRec1[((IOTA - iSlow16) & 16383)]) + (fSlow17 * fRec1[((IOTA - iSlow18) & 16383)]));
			fVec3[0] = fTemp4;
			float fTemp5 = (fTemp4 - fVec3[1]);
			fVec4[0] = fTemp5;
			float fTempFTZ2 = ((fConst7 * fVec4[1]) - (fConst8 * ((fConst9 * fRec5[1]) - (fConst5 * fTemp5))));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.996999979f * fRec6[1]) + (0.00300000003f * std::fabs(fTemp4)));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp6 = ((0.99970001f * fTemp4) + (fSlow19 * (fRec5[0] * std::max<float>(0.0f, (fRec6[0] - fSlow20)))));
			float fTempFTZ4 = ((fSlow21 * fTemp6) - (fSlow10 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fRec2[0] + (fSlow8 * (((fSlow10 * fTemp6) + (fSlow21 * fRec7[1])) * (1.0f - fTemp1))));
			fRec1[(IOTA & 16383)] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp7 = float((float((iVec1[((IOTA - iConst10) & 524287)] - iVec1[((IOTA - iConst11) & 524287)])) > 0.0f));
			float fThen1 = std::max<float>(0.0f, (fRec10[1] + -1.0f));
			float fTempFTZ6 = ((fTemp7 > 0.0f) ? fSlow6 : fThen1);
			fRec10[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp8 = (fSlow4 * (fTemp2 * float((fRec10[0] > 0.0f))));
			fVec5[0] = fTemp8;
			float fTempFTZ7 = (0.0f - (fSlow2 * ((fSlow3 * fRec9[1]) - (fTemp8 + fVec5[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp9 = ((fSlow26 * fRec8[((IOTA - iSlow28) & 8191)]) + (fSlow29 * fRec8[((IOTA - iSlow30) & 8191)]));
			fVec6[0] = fTemp9;
			float fTemp10 = (fTemp9 - fVec6[1]);
			fVec7[0] = fTemp10;
			float fTempFTZ8 = ((fConst7 * fVec7[1]) - (fConst8 * ((fConst9 * fRec11[1]) - (fConst5 * fTemp10))));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((0.996999979f * fRec12[1]) + (0.00300000003f * std::fabs(fTemp9)));
			fRec12[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp11 = ((0.99970001f * fTemp9) + (fSlow19 * (fRec11[0] * std::max<float>(0.0f, (fRec12[0] - fSlow20)))));
			float fTempFTZ10 = ((fSlow21 * fTemp11) - (fSlow10 * fRec13[1]));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fRec9[0] + (fSlow22 * (((fSlow10 * fTemp11) + (fSlow21 * fRec13[1])) * (1.0f - fTemp7))));
			fRec8[(IOTA & 8191)] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp12 = float((float((iTemp0 - iVec1[((IOTA - 1) & 524287)])) > 0.0f));
			float fThen2 = std::max<float>(0.0f, (fRec16[1] + -1.0f));
			float fTempFTZ12 = ((fTemp12 > 0.0f) ? fSlow6 : fThen2);
			fRec16[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp13 = (fSlow4 * (fTemp2 * float((fRec16[0] > 0.0f))));
			fVec8[0] = fTemp13;
			float fTempFTZ13 = (0.0f - (fSlow2 * ((fSlow3 * fRec15[1]) - (fTemp13 + fVec8[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp14 = ((fRec14[((IOTA - iSlow36) & 16383)] * fSlow38) + (fSlow39 * fRec14[((IOTA - iSlow40) & 16383)]));
			fVec9[0] = fTemp14;
			float fTemp15 = (fTemp14 - fVec9[1]);
			fVec10[0] = fTemp15;
			float fTempFTZ14 = ((fConst7 * fVec10[1]) - (fConst8 * ((fConst9 * fRec17[1]) - (fConst5 * fTemp15))));
			fRec17[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = ((0.996999979f * fRec18[1]) + (0.00300000003f * std::fabs(fTemp14)));
			fRec18[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp16 = ((0.99970001f * fTemp14) + (fSlow19 * (fRec17[0] * std::max<float>(0.0f, (fRec18[0] - fSlow20)))));
			float fTempFTZ16 = ((fSlow21 * fTemp16) - (fSlow10 * fRec19[1]));
			fRec19[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fRec15[0] + ((((fSlow10 * fTemp16) + (fSlow21 * fRec19[1])) * fSlow41) * (1.0f - fTemp12)));
			fRec14[(IOTA & 16383)] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp17 = float((float((iVec1[((IOTA - iConst12) & 524287)] - iVec1[((IOTA - iConst13) & 524287)])) > 0.0f));
			float fThen4 = std::max<float>(0.0f, (fRec22[1] + -1.0f));
			float fTempFTZ18 = ((fTemp17 > 0.0f) ? fSlow6 : fThen4);
			fRec22[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTemp18 = (fSlow4 * (fTemp2 * float((fRec22[0] > 0.0f))));
			fVec11[0] = fTemp18;
			float fTempFTZ19 = (0.0f - (fSlow2 * ((fSlow3 * fRec21[1]) - (fTemp18 + fVec11[1]))));
			fRec21[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp19 = ((fSlow26 * fRec20[((IOTA - iSlow28) & 8191)]) + (fSlow29 * fRec20[((IOTA - iSlow30) & 8191)]));
			fVec12[0] = fTemp19;
			float fTemp20 = (fTemp19 - fVec12[1]);
			fVec13[0] = fTemp20;
			float fTempFTZ20 = ((fConst7 * fVec13[1]) - (fConst8 * ((fConst9 * fRec23[1]) - (fConst5 * fTemp20))));
			fRec23[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = ((0.996999979f * fRec24[1]) + (0.00300000003f * std::fabs(fTemp19)));
			fRec24[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp21 = ((0.99970001f * fTemp19) + (fSlow19 * (fRec23[0] * std::max<float>(0.0f, (fRec24[0] - fSlow20)))));
			float fTempFTZ22 = ((fSlow21 * fTemp21) - (fSlow10 * fRec25[1]));
			fRec25[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fRec21[0] + (fSlow42 * (((fSlow10 * fTemp21) + (fSlow21 * fRec25[1])) * (1.0f - fTemp17))));
			fRec20[(IOTA & 8191)] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp22 = (fSlow0 * (fRec1[((IOTA - 0) & 16383)] + (fRec8[((IOTA - 0) & 8191)] + (fRec14[((IOTA - 0) & 16383)] + fRec20[((IOTA - 0) & 8191)]))));
			fVec14[0] = fTemp22;
			float fTempFTZ24 = (((0.995000005f * fRec0[1]) + fTemp22) - fVec14[1]);
			fRec0[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] / (std::fabs(fRec0[0]) + 1.0f)));
			fVec0[1] = fVec0[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			iRec4[1] = iRec4[0];
			fVec2[1] = fVec2[0];
			fRec2[1] = fRec2[0];
			fVec3[1] = fVec3[0];
			fVec4[1] = fVec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec10[1] = fRec10[0];
			fVec5[1] = fVec5[0];
			fRec9[1] = fRec9[0];
			fVec6[1] = fVec6[0];
			fVec7[1] = fVec7[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
			fVec8[1] = fVec8[0];
			fRec15[1] = fRec15[0];
			fVec9[1] = fVec9[0];
			fVec10[1] = fVec10[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec22[1] = fRec22[0];
			fVec11[1] = fVec11[0];
			fRec21[1] = fRec21[0];
			fVec12[1] = fVec12[0];
			fVec13[1] = fVec13[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fVec14[1] = fVec14[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
