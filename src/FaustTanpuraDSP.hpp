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

static float FaustTanpuraDSP_faustpower2_f(float value) {
	return (value * value);
}

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
	FAUSTFLOAT fHslider5;
	float fRec2[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fButton0;
	int IOTA;
	float fVec0[524288];
	int iVec1[2];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	int iRec4[2];
	FAUSTFLOAT fHslider10;
	float fRec6[2];
	int iVec2[2];
	int iRec5[2];
	float fConst2;
	float fConst3;
	float fRec3[3];
	float fRec1[16384];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	float fRec8[2];
	int iConst4;
	int iConst5;
	int iVec3[2];
	float fRec11[2];
	int iVec4[2];
	int iRec10[2];
	float fRec9[3];
	float fRec7[8192];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fRec13[2];
	int iConst6;
	int iConst7;
	int iVec5[2];
	float fRec16[2];
	int iVec6[2];
	int iRec15[2];
	float fRec14[3];
	float fRec12[8192];
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	float fRec18[2];
	int iConst8;
	int iConst9;
	int iVec7[2];
	float fConst10;
	float fRec21[2];
	int iVec8[2];
	int iRec20[2];
	float fRec19[3];
	float fRec17[16384];
	float fVec9[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "tanpura.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
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
		fConst1 = (3.0f / fConst0);
		fConst2 = (0.5f * fConst0);
		fConst3 = (9.42477798f / fConst0);
		iConst4 = int(fConst2);
		iConst5 = (iConst4 + 1);
		iConst6 = int(fConst0);
		iConst7 = (iConst6 + 1);
		iConst8 = int((1.5f * fConst0));
		iConst9 = (iConst8 + 1);
		fConst10 = (4.71238899f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(55.0f);
		fHslider3 = FAUSTFLOAT(0.070000000000000007f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(130.81f);
		fHslider6 = FAUSTFLOAT(0.014999999999999999f);
		fHslider7 = FAUSTFLOAT(0.55000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(0.80000000000000004f);
		fHslider9 = FAUSTFLOAT(0.40000000000000002f);
		fHslider10 = FAUSTFLOAT(0.0115f);
		fHslider11 = FAUSTFLOAT(1.0f);
		fHslider12 = FAUSTFLOAT(35.0f);
		fHslider13 = FAUSTFLOAT(1.0f);
		fHslider14 = FAUSTFLOAT(35.0f);
		fHslider15 = FAUSTFLOAT(1.0f);
		fHslider16 = FAUSTFLOAT(20.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0f;
		}
		IOTA = 0;
		for (int l1 = 0; (l1 < 524288); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec4[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec5[l6] = 0;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 16384); l8 = (l8 + 1)) {
			fRec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iVec3[l10] = 0;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iVec4[l12] = 0;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			iRec10[l13] = 0;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec9[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 8192); l15 = (l15 + 1)) {
			fRec7[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec13[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iVec5[l17] = 0;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			iVec6[l19] = 0;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			iRec15[l20] = 0;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec14[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 8192); l22 = (l22 + 1)) {
			fRec12[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec18[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			iVec7[l24] = 0;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec21[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			iVec8[l26] = 0;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			iRec20[l27] = 0;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec19[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 16384); l29 = (l29 + 1)) {
			fRec17[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fVec9[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec0[l31] = 0.0f;
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
		ui_interface->addHorizontalSlider("dispersion", &fHslider3, FAUSTFLOAT(0.0700000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excDur", &fHslider10, FAUSTFLOAT(0.0115f), FAUSTFLOAT(9.99999975e-05f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excGain", &fHslider9, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider5, FAUSTFLOAT(130.809998f), FAUSTFLOAT(40.0f), FAUSTFLOAT(600.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq1", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider7, FAUSTFLOAT(0.550000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("jivariThreshold", &fHslider6, FAUSTFLOAT(0.0149999997f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("stringGainVal0", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stringGainVal1", &fHslider11, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stringGainVal2", &fHslider13, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stringGainVal3", &fHslider15, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain0", &fHslider2, FAUSTFLOAT(55.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain1", &fHslider12, FAUSTFLOAT(35.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain2", &fHslider14, FAUSTFLOAT(35.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain3", &fHslider16, FAUSTFLOAT(20.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider8, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (7.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::exp((0.0f - (fConst1 / std::max<float>(0.00100000005f, float(fHslider2)))));
		float fSlow3 = float(fHslider3);
		float fSlow4 = std::sin(fSlow3);
		float fSlow5 = float(fHslider4);
		float fSlow6 = float(fHslider5);
		float fThen0 = (1.5f * fSlow6);
		float fSlow7 = ((fSlow5 > 0.0f) ? fSlow5 : fThen0);
		float fSlow8 = std::max<float>(20.0f, fSlow7);
		float fSlow9 = (fConst0 / fSlow8);
		float fSlow10 = (fSlow9 + -2.0f);
		int iSlow11 = int(fSlow10);
		int iSlow12 = (std::min<int>(8193, std::max<int>(0, iSlow11)) + 1);
		float fSlow13 = std::floor(fSlow10);
		float fSlow14 = (fSlow13 + (3.0f - fSlow9));
		float fSlow15 = (fSlow9 + (-2.0f - fSlow13));
		int iSlow16 = (std::min<int>(8193, std::max<int>(0, (iSlow11 + 1))) + 1);
		float fSlow17 = std::cos(fSlow3);
		float fSlow18 = float(fHslider6);
		float fSlow19 = (fSlow3 * (float(fHslider7) + 1.0f));
		float fSlow20 = float(fButton0);
		float fSlow21 = ((fSlow6 * float(fHslider8)) * float(fHslider9));
		float fSlow22 = (1.39698392e-10f * fSlow21);
		float fSlow23 = float(fHslider10);
		float fSlow24 = (fConst0 * fSlow23);
		float fSlow25 = std::max<float>(1.0f, fSlow24);
		float fSlow26 = (1.0f / fSlow25);
		float fSlow27 = (1.0f / std::max<float>(1.0f, (fConst2 * fSlow23)));
		float fSlow28 = std::tan((fConst3 * fSlow7));
		float fSlow29 = (1.0f / fSlow28);
		float fSlow30 = (((fSlow29 + -1.41421354f) / fSlow28) + 1.0f);
		float fSlow31 = (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fSlow28)));
		float fSlow32 = (((fSlow29 + 1.41421354f) / fSlow28) + 1.0f);
		float fSlow33 = float(fHslider11);
		float fSlow34 = std::exp((0.0f - (fConst1 / std::max<float>(0.00100000005f, float(fHslider12)))));
		float fSlow35 = std::max<float>(20.0f, fSlow6);
		float fSlow36 = (fConst0 / fSlow35);
		float fSlow37 = (fSlow36 + -2.0f);
		float fSlow38 = std::floor(fSlow37);
		float fSlow39 = (fSlow38 + (3.0f - fSlow36));
		int iSlow40 = int(fSlow37);
		int iSlow41 = (std::min<int>(8193, std::max<int>(0, iSlow40)) + 1);
		float fSlow42 = (fSlow36 + (-2.0f - fSlow38));
		int iSlow43 = (std::min<int>(8193, std::max<int>(0, (iSlow40 + 1))) + 1);
		float fSlow44 = std::tan((fConst3 * fSlow6));
		float fSlow45 = (1.0f / fSlow44);
		float fSlow46 = (1.0f / (((fSlow45 + 1.41421354f) / fSlow44) + 1.0f));
		float fSlow47 = (1.39698392e-10f * (fSlow21 / fSlow35));
		float fSlow48 = (((fSlow45 + -1.41421354f) / fSlow44) + 1.0f);
		float fSlow49 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fSlow44))));
		float fSlow50 = float(fHslider13);
		float fSlow51 = std::exp((0.0f - (fConst1 / std::max<float>(0.00100000005f, float(fHslider14)))));
		float fSlow52 = float(fHslider15);
		float fSlow53 = std::exp((0.0f - (fConst1 / std::max<float>(0.00100000005f, float(fHslider16)))));
		float fSlow54 = std::max<float>(20.0f, (0.5f * fSlow6));
		float fSlow55 = (fConst0 / fSlow54);
		float fSlow56 = (fSlow55 + -2.0f);
		float fSlow57 = std::floor(fSlow56);
		float fSlow58 = (fSlow57 + (3.0f - fSlow55));
		int iSlow59 = int(fSlow56);
		int iSlow60 = (std::min<int>(8193, std::max<int>(0, iSlow59)) + 1);
		float fSlow61 = (fSlow55 + (-2.0f - fSlow57));
		int iSlow62 = (std::min<int>(8193, std::max<int>(0, (iSlow59 + 1))) + 1);
		float fSlow63 = std::tan((fConst10 * fSlow6));
		float fSlow64 = (1.0f / fSlow63);
		float fSlow65 = (1.0f / (((fSlow64 + 1.41421354f) / fSlow63) + 1.0f));
		float fSlow66 = (1.39698392e-10f * (fSlow21 / fSlow54));
		float fSlow67 = (((fSlow64 + -1.41421354f) / fSlow63) + 1.0f);
		float fSlow68 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fSlow63))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTemp0 = ((fRec1[((IOTA - iSlow12) & 16383)] * fSlow14) + (fSlow15 * fRec1[((IOTA - iSlow16) & 16383)]));
			float fTempFTZ0 = ((fSlow17 * fTemp0) - (fSlow4 * fRec2[1]));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp1 = ((fSlow4 * fTemp0) + (fSlow17 * fRec2[1]));
			float fElse1 = (fSlow18 - (fSlow19 * (fTemp1 - fSlow18)));
			fVec0[(IOTA & 524287)] = fSlow20;
			int iTemp2 = ((fSlow20 - fVec0[((IOTA - 1) & 524287)]) > 0.0f);
			iVec1[0] = iTemp2;
			float fTemp3 = float((float((iTemp2 - iVec1[1])) > 0.0f));
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTemp4 = float(iRec4[0]);
			float fThen2 = std::max<float>(0.0f, (fRec6[1] + -1.0f));
			float fTempFTZ1 = ((fTemp3 > 0.0f) ? fSlow24 : fThen2);
			fRec6[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			int iTemp5 = (fRec6[0] > 0.0f);
			iVec2[0] = iTemp5;
			iRec5[0] = (((iRec5[1] + (iRec5[1] > 0)) * (iTemp5 <= iVec2[1])) + (iTemp5 > iVec2[1]));
			float fTemp6 = float(iRec5[0]);
			float fTempFTZ2 = ((fSlow22 * ((fTemp4 * std::max<float>(0.0f, std::min<float>((fSlow26 * fTemp6), ((fSlow27 * (fSlow25 - fTemp6)) + 1.0f)))) / fSlow8)) - (((fRec3[2] * fSlow30) + (2.0f * (fRec3[1] * fSlow31))) / fSlow32));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((fSlow2 * (std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fTemp1 > fSlow18) ? fElse1 : fTemp1))) * (1.0f - fTemp3))) + ((fRec3[2] + (fRec3[0] + (2.0f * fRec3[1]))) / fSlow32));
			fRec1[(IOTA & 16383)] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp7 = ((fSlow39 * fRec7[((IOTA - iSlow41) & 8191)]) + (fSlow42 * fRec7[((IOTA - iSlow43) & 8191)]));
			float fTempFTZ4 = ((fSlow17 * fTemp7) - (fSlow4 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp8 = ((fSlow4 * fTemp7) + (fSlow17 * fRec8[1]));
			float fElse3 = (fSlow18 - (fSlow19 * (fTemp8 - fSlow18)));
			int iTemp9 = ((fVec0[((IOTA - iConst4) & 524287)] - fVec0[((IOTA - iConst5) & 524287)]) > 0.0f);
			iVec3[0] = iTemp9;
			float fTemp10 = float((float((iTemp9 - iVec3[1])) > 0.0f));
			float fThen4 = std::max<float>(0.0f, (fRec11[1] + -1.0f));
			float fTempFTZ5 = ((fTemp10 > 0.0f) ? fSlow24 : fThen4);
			fRec11[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			int iTemp11 = (fRec11[0] > 0.0f);
			iVec4[0] = iTemp11;
			iRec10[0] = (((iRec10[1] + (iRec10[1] > 0)) * (iTemp11 <= iVec4[1])) + (iTemp11 > iVec4[1]));
			float fTemp12 = float(iRec10[0]);
			float fTempFTZ6 = ((fSlow47 * (fTemp4 * std::max<float>(0.0f, std::min<float>((fSlow26 * fTemp12), ((fSlow27 * (fSlow25 - fTemp12)) + 1.0f))))) - (fSlow46 * ((fSlow48 * fRec9[2]) + (fSlow49 * fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((fSlow34 * (std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fTemp8 > fSlow18) ? fElse3 : fTemp8))) * (1.0f - fTemp10))) + (fSlow46 * (fRec9[2] + (fRec9[0] + (2.0f * fRec9[1])))));
			fRec7[(IOTA & 8191)] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp13 = ((fSlow39 * fRec12[((IOTA - iSlow41) & 8191)]) + (fSlow42 * fRec12[((IOTA - iSlow43) & 8191)]));
			float fTempFTZ8 = ((fSlow17 * fTemp13) - (fSlow4 * fRec13[1]));
			fRec13[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp14 = ((fSlow4 * fTemp13) + (fSlow17 * fRec13[1]));
			float fElse5 = (fSlow18 - (fSlow19 * (fTemp14 - fSlow18)));
			int iTemp15 = ((fVec0[((IOTA - iConst6) & 524287)] - fVec0[((IOTA - iConst7) & 524287)]) > 0.0f);
			iVec5[0] = iTemp15;
			float fTemp16 = float((float((iTemp15 - iVec5[1])) > 0.0f));
			float fThen6 = std::max<float>(0.0f, (fRec16[1] + -1.0f));
			float fTempFTZ9 = ((fTemp16 > 0.0f) ? fSlow24 : fThen6);
			fRec16[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			int iTemp17 = (fRec16[0] > 0.0f);
			iVec6[0] = iTemp17;
			iRec15[0] = (((iRec15[1] + (iRec15[1] > 0)) * (iTemp17 <= iVec6[1])) + (iTemp17 > iVec6[1]));
			float fTemp18 = float(iRec15[0]);
			float fTempFTZ10 = ((fSlow47 * (fTemp4 * std::max<float>(0.0f, std::min<float>((fSlow26 * fTemp18), ((fSlow27 * (fSlow25 - fTemp18)) + 1.0f))))) - (fSlow46 * ((fSlow48 * fRec14[2]) + (fSlow49 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = ((fSlow51 * (std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fTemp14 > fSlow18) ? fElse5 : fTemp14))) * (1.0f - fTemp16))) + (fSlow46 * (fRec14[2] + (fRec14[0] + (2.0f * fRec14[1])))));
			fRec12[(IOTA & 8191)] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp19 = ((fSlow58 * fRec17[((IOTA - iSlow60) & 16383)]) + (fSlow61 * fRec17[((IOTA - iSlow62) & 16383)]));
			float fTempFTZ12 = ((fSlow17 * fTemp19) - (fSlow4 * fRec18[1]));
			fRec18[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp20 = ((fSlow4 * fTemp19) + (fSlow17 * fRec18[1]));
			float fElse7 = (fSlow18 - (fSlow19 * (fTemp20 - fSlow18)));
			int iTemp21 = ((fVec0[((IOTA - iConst8) & 524287)] - fVec0[((IOTA - iConst9) & 524287)]) > 0.0f);
			iVec7[0] = iTemp21;
			float fTemp22 = float((float((iTemp21 - iVec7[1])) > 0.0f));
			float fThen8 = std::max<float>(0.0f, (fRec21[1] + -1.0f));
			float fTempFTZ13 = ((fTemp22 > 0.0f) ? fSlow24 : fThen8);
			fRec21[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			int iTemp23 = (fRec21[0] > 0.0f);
			iVec8[0] = iTemp23;
			iRec20[0] = (((iRec20[1] + (iRec20[1] > 0)) * (iTemp23 <= iVec8[1])) + (iTemp23 > iVec8[1]));
			float fTemp24 = float(iRec20[0]);
			float fTempFTZ14 = ((fSlow66 * (fTemp4 * std::max<float>(0.0f, std::min<float>((fSlow26 * fTemp24), ((fSlow27 * (fSlow25 - fTemp24)) + 1.0f))))) - (fSlow65 * ((fSlow67 * fRec19[2]) + (fSlow68 * fRec19[1]))));
			fRec19[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = ((fSlow53 * (std::max<float>(-1.20000005f, std::min<float>(1.20000005f, ((fTemp20 > fSlow18) ? fElse7 : fTemp20))) * (1.0f - fTemp22))) + (fSlow65 * (fRec19[2] + (fRec19[0] + (2.0f * fRec19[1])))));
			fRec17[(IOTA & 16383)] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp25 = (fSlow0 * ((((fSlow1 * fRec1[((IOTA - 0) & 16383)]) + (fSlow33 * fRec7[((IOTA - 0) & 8191)])) + (fSlow50 * fRec12[((IOTA - 0) & 8191)])) + (fSlow52 * fRec17[((IOTA - 0) & 16383)])));
			fVec9[0] = fTemp25;
			float fTempFTZ16 = (((0.995000005f * fRec0[1]) + fTemp25) - fVec9[1]);
			fRec0[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] / (std::fabs(fRec0[0]) + 1.0f)));
			fRec2[1] = fRec2[0];
			IOTA = (IOTA + 1);
			iVec1[1] = iVec1[0];
			iRec4[1] = iRec4[0];
			fRec6[1] = fRec6[0];
			iVec2[1] = iVec2[0];
			iRec5[1] = iRec5[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec8[1] = fRec8[0];
			iVec3[1] = iVec3[0];
			fRec11[1] = fRec11[0];
			iVec4[1] = iVec4[0];
			iRec10[1] = iRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec13[1] = fRec13[0];
			iVec5[1] = iVec5[0];
			fRec16[1] = fRec16[0];
			iVec6[1] = iVec6[0];
			iRec15[1] = iRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec18[1] = fRec18[0];
			iVec7[1] = iVec7[0];
			fRec21[1] = fRec21[0];
			iVec8[1] = iVec8[0];
			iRec20[1] = iRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fVec9[1] = fVec9[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
