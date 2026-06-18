/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "voice"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustVoiceDSP_H__
#define  __FaustVoiceDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustVoiceDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec5[2];
	
  public:
	
	int getNumInputsFaustVoiceDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustVoiceDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustVoiceDSPSIG0(int sample_rate) {
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec0[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec5[l5] = 0;
		}
	}
	
	void fillFaustVoiceDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec5[0] = ((iVec0[1] + iRec5[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec5[0])));
			iVec0[1] = iVec0[0];
			iRec5[1] = iRec5[0];
		}
	}

};

static FaustVoiceDSPSIG0* newFaustVoiceDSPSIG0() { return (FaustVoiceDSPSIG0*)new FaustVoiceDSPSIG0(); }
static void deleteFaustVoiceDSPSIG0(FaustVoiceDSPSIG0* dsp) { delete dsp; }

static float FaustVoiceDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustVoiceDSPSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustVoiceDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustVoiceDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fRec0[2];
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fConst3;
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec3[2];
	float fRec2[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec6[2];
	int iRec7[2];
	float fRec4[2];
	FAUSTFLOAT fHslider8;
	float fRec9[2];
	float fRec8[2];
	FAUSTFLOAT fHslider9;
	float fRec10[2];
	FAUSTFLOAT fHslider10;
	float fRec11[2];
	FAUSTFLOAT fHslider11;
	float fRec12[2];
	FAUSTFLOAT fHslider12;
	float fRec13[2];
	FAUSTFLOAT fHslider13;
	float fRec15[2];
	float fRec14[2];
	FAUSTFLOAT fHslider14;
	float fRec16[2];
	FAUSTFLOAT fHslider15;
	float fRec17[2];
	FAUSTFLOAT fHslider16;
	float fRec19[2];
	float fRec18[2];
	FAUSTFLOAT fHslider17;
	float fRec20[2];
	FAUSTFLOAT fHslider18;
	float fRec21[2];
	FAUSTFLOAT fHslider19;
	float fRec23[2];
	float fRec22[2];
	FAUSTFLOAT fHslider20;
	float fRec24[2];
	FAUSTFLOAT fHslider21;
	float fRec25[2];
	FAUSTFLOAT fHslider22;
	float fRec27[2];
	float fRec26[2];
	FAUSTFLOAT fHslider23;
	float fRec28[2];
	FAUSTFLOAT fHslider24;
	float fRec29[2];
	float fConst4;
	float fRec30[3];
	float fVec1[14];
	float fConst5;
	float fRec31[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "voice.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "voice");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		return 2;
	}
	
	static void classInit(int sample_rate) {
		FaustVoiceDSPSIG0* sig0 = newFaustVoiceDSPSIG0();
		sig0->instanceInitFaustVoiceDSPSIG0(sample_rate);
		sig0->fillFaustVoiceDSPSIG0(65536, ftbl0FaustVoiceDSPSIG0);
		deleteFaustVoiceDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = (3.14159274f / fConst0);
		fConst5 = (0.230000004f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(0.69999999999999996f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(80.0f);
		fHslider4 = FAUSTFLOAT(0.5f);
		fHslider5 = FAUSTFLOAT(220.0f);
		fHslider6 = FAUSTFLOAT(0.012f);
		fHslider7 = FAUSTFLOAT(5.5f);
		fHslider8 = FAUSTFLOAT(800.0f);
		fHslider9 = FAUSTFLOAT(0.5f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(0.80000000000000004f);
		fHslider12 = FAUSTFLOAT(90.0f);
		fHslider13 = FAUSTFLOAT(1200.0f);
		fHslider14 = FAUSTFLOAT(0.59999999999999998f);
		fHslider15 = FAUSTFLOAT(120.0f);
		fHslider16 = FAUSTFLOAT(2500.0f);
		fHslider17 = FAUSTFLOAT(0.40000000000000002f);
		fHslider18 = FAUSTFLOAT(130.0f);
		fHslider19 = FAUSTFLOAT(3500.0f);
		fHslider20 = FAUSTFLOAT(0.20000000000000001f);
		fHslider21 = FAUSTFLOAT(160.0f);
		fHslider22 = FAUSTFLOAT(4500.0f);
		fHslider23 = FAUSTFLOAT(1500.0f);
		fHslider24 = FAUSTFLOAT(0.14999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec7[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec4[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec15[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec17[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec19[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec18[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec20[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec21[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec23[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec22[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec24[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec25[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec27[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec26[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec29[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec30[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 14); l32 = (l32 + 1)) {
			fVec1[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec31[l33] = 0.0f;
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
	
	virtual FaustVoiceDSP* clone() {
		return new FaustVoiceDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("voice");
		ui_interface->addHorizontalSlider("breathiness", &fHslider24, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("chest", &fHslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("f1_amp", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("f1_bw", &fHslider3, FAUSTFLOAT(80.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f1_freq", &fHslider8, FAUSTFLOAT(800.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f2_amp", &fHslider11, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("f2_bw", &fHslider12, FAUSTFLOAT(90.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f2_freq", &fHslider13, FAUSTFLOAT(1200.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f3_amp", &fHslider14, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("f3_bw", &fHslider15, FAUSTFLOAT(120.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f3_freq", &fHslider16, FAUSTFLOAT(2500.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f4_amp", &fHslider17, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("f4_bw", &fHslider18, FAUSTFLOAT(130.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f4_freq", &fHslider19, FAUSTFLOAT(3500.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f5_amp", &fHslider20, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("f5_bw", &fHslider21, FAUSTFLOAT(160.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("f5_freq", &fHslider22, FAUSTFLOAT(4500.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(5000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider5, FAUSTFLOAT(220.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("glottal", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("nasal", &fHslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("nasal_freq", &fHslider23, FAUSTFLOAT(1500.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(3000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider6, FAUSTFLOAT(0.0120000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0799999982f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider7, FAUSTFLOAT(5.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = ((0.119999997f * (1.0f - float(fHslider0))) + 0.0799999982f);
		int iSlow1 = (std::fabs(fSlow0) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst1 / (iSlow1 ? 1.0f : fSlow0))));
		float fSlow2 = (iSlow1 ? 0.0f : fThen1);
		float fSlow3 = ((float(fHslider1) * float(fButton0)) * (1.0f - fSlow2));
		float fSlow4 = (fConst2 * float(fHslider2));
		float fSlow5 = (fConst2 * float(fHslider3));
		float fSlow6 = (fConst2 * float(fHslider4));
		float fSlow7 = float(fHslider5);
		float fSlow8 = (fConst1 * fSlow7);
		float fSlow9 = float(fHslider6);
		float fSlow10 = (fConst1 * float(fHslider7));
		float fSlow11 = (fConst2 * float(fHslider8));
		float fSlow12 = (fConst2 * float(fHslider9));
		float fSlow13 = (fConst2 * float(fHslider10));
		float fSlow14 = (fConst2 * float(fHslider11));
		float fSlow15 = (fConst2 * float(fHslider12));
		float fSlow16 = (fConst2 * float(fHslider13));
		float fSlow17 = (fConst2 * float(fHslider14));
		float fSlow18 = (fConst2 * float(fHslider15));
		float fSlow19 = (fConst2 * float(fHslider16));
		float fSlow20 = (fConst2 * float(fHslider17));
		float fSlow21 = (fConst2 * float(fHslider18));
		float fSlow22 = (fConst2 * float(fHslider19));
		float fSlow23 = (fConst2 * float(fHslider20));
		float fSlow24 = (fConst2 * float(fHslider21));
		float fSlow25 = (fConst2 * float(fHslider22));
		float fSlow26 = (fConst2 * float(fHslider23));
		float fSlow27 = (fConst2 * float(fHslider24));
		float fSlow28 = (fConst4 * fSlow7);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = ((fRec0[1] * fSlow2) + fSlow3);
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow4 + (fConst3 * fRec1[1]));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow6 + (fConst3 * fRec3[1]));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp0 = (1.0f - (0.300000012f * (fRec3[0] + -0.5f)));
			float fTempFTZ3 = ((fConst3 * fRec2[1]) + (fSlow5 * fTemp0));
			fRec2[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp1 = FaustVoiceDSP_faustpower2_f(fRec2[0]);
			float fTempFTZ4 = (fSlow10 + (fRec6[1] - std::floor((fSlow10 + fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			iRec7[0] = ((1103515245 * iRec7[1]) + 12345);
			float fTemp2 = float(iRec7[0]);
			float fTemp3 = ((fRec0[0] * ((fSlow9 * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec6[0]))]) + (1.39698387e-12f * fTemp2))) + 1.0f);
			float fTemp4 = (fRec4[1] + (fSlow8 * fTemp3));
			float fTempFTZ5 = (fTemp4 - std::floor(fTemp4));
			fRec4[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp5 = (std::cos((6.28318548f * fRec4[0])) + -1.0f);
			float fTemp6 = std::max<float>(1.0f, (fSlow7 * fTemp3));
			float fTemp7 = FaustVoiceDSP_faustpower2_f(fTemp6);
			float fTempFTZ6 = (fSlow11 + (fConst3 * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((fConst3 * fRec8[1]) + (fConst2 * fRec9[0]));
			fRec8[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fSlow12 + (fConst3 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp8 = ((fRec8[0] * (1.0f - (0.150000006f * (fRec10[0] + -0.5f)))) / fTemp6);
			float fTemp9 = std::floor(fTemp8);
			float fTempFTZ9 = (fSlow13 + (fConst3 * fRec11[1]));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fSlow14 + (fConst3 * fRec12[1]));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = ((fConst3 * fRec13[1]) + (fSlow15 * fTemp0));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp10 = FaustVoiceDSP_faustpower2_f(fRec13[0]);
			float fTempFTZ12 = (fSlow16 + (fConst3 * fRec15[1]));
			fRec15[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = ((fConst3 * fRec14[1]) + (fConst2 * fRec15[0]));
			fRec14[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp11 = (fRec14[0] / fTemp6);
			float fTemp12 = std::floor(fTemp11);
			float fTempFTZ14 = (fSlow17 + (fConst3 * fRec16[1]));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = ((fConst3 * fRec17[1]) + (fSlow18 * fTemp0));
			fRec17[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp13 = FaustVoiceDSP_faustpower2_f(fRec17[0]);
			float fTempFTZ16 = (fSlow19 + (fConst3 * fRec19[1]));
			fRec19[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = ((fConst3 * fRec18[1]) + (fConst2 * fRec19[0]));
			fRec18[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp14 = (fRec18[0] / fTemp6);
			float fTemp15 = std::floor(fTemp14);
			float fTempFTZ18 = (fSlow20 + (fConst3 * fRec20[1]));
			fRec20[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = ((fConst3 * fRec21[1]) + (fSlow21 * fTemp0));
			fRec21[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp16 = FaustVoiceDSP_faustpower2_f(fRec21[0]);
			float fTempFTZ20 = (fSlow22 + (fConst3 * fRec23[1]));
			fRec23[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = ((fConst3 * fRec22[1]) + (fConst2 * fRec23[0]));
			fRec22[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp17 = (fRec22[0] / fTemp6);
			float fTemp18 = std::floor(fTemp17);
			float fTempFTZ22 = (fSlow23 + (fConst3 * fRec24[1]));
			fRec24[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = ((fConst3 * fRec25[1]) + (fSlow24 * fTemp0));
			fRec25[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp19 = FaustVoiceDSP_faustpower2_f(fRec25[0]);
			float fTempFTZ24 = (fSlow25 + (fConst3 * fRec27[1]));
			fRec27[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = ((fConst3 * fRec26[1]) + (fConst2 * fRec27[0]));
			fRec26[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTemp20 = (fRec26[0] / fTemp6);
			float fTemp21 = std::floor(fTemp20);
			float fTempFTZ26 = (fSlow26 + (fConst3 * fRec28[1]));
			fRec28[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTemp22 = (fRec28[0] / fTemp6);
			float fTemp23 = std::floor(fTemp22);
			float fTempFTZ27 = (fSlow27 + (fConst3 * fRec29[1]));
			fRec29[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTemp24 = std::tan((fSlow28 * fTemp3));
			float fTemp25 = (1.0f / fTemp24);
			float fTemp26 = (((fTemp25 + 0.833333313f) / fTemp24) + 1.0f);
			float fTempFTZ28 = ((4.65661287e-10f * fTemp2) - (((fRec30[2] * (((fTemp25 + -0.833333313f) / fTemp24) + 1.0f)) + (2.0f * (fRec30[1] * (1.0f - (1.0f / FaustVoiceDSP_faustpower2_f(fTemp24)))))) / fTemp26));
			fRec30[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTemp27 = (fTemp24 * fTemp26);
			float fTemp28 = (fRec0[0] * ((((((((((fRec1[0] * std::exp(std::max<float>(-80.0f, (0.5f * ((fTemp1 * fTemp5) / fTemp7))))) * (((fTemp9 + (1.0f - fTemp8)) * std::cos((6.28318548f * (fRec4[0] * fTemp9)))) + ((fTemp8 - fTemp9) * std::cos((6.28318548f * (fRec4[0] * (fTemp9 + 1.0f))))))) * std::sqrt(((0.5f * (fTemp1 / fTemp7)) + 1.0f))) * (fRec10[0] + 0.5f)) * (1.0f - (0.400000006f * fRec11[0]))) + (0.5f * ((((fRec12[0] * std::exp(std::max<float>(-80.0f, (0.5f * ((fTemp10 * fTemp5) / fTemp7))))) * (((fTemp12 + (1.0f - fTemp11)) * std::cos((6.28318548f * (fRec4[0] * fTemp12)))) + ((fTemp11 - fTemp12) * std::cos((6.28318548f * (fRec4[0] * (fTemp12 + 1.0f))))))) * std::sqrt(((0.5f * (fTemp10 / fTemp7)) + 1.0f))) * (fRec10[0] + 1.0f)))) + (2.0f * (fRec3[0] * (((((fRec16[0] * std::exp(std::max<float>(-80.0f, (0.5f * ((fTemp13 * fTemp5) / fTemp7))))) * (((fTemp15 + (1.0f - fTemp14)) * std::cos((6.28318548f * (fRec4[0] * fTemp15)))) + ((fTemp14 - fTemp15) * std::cos((6.28318548f * (fRec4[0] * (fTemp15 + 1.0f))))))) * std::sqrt(((0.5f * (fTemp13 / fTemp7)) + 1.0f))) + (((fRec20[0] * std::exp(std::max<float>(-80.0f, (0.5f * ((fTemp16 * fTemp5) / fTemp7))))) * (((fTemp18 + (1.0f - fTemp17)) * std::cos((6.28318548f * (fRec4[0] * fTemp18)))) + ((fTemp17 - fTemp18) * std::cos((6.28318548f * (fRec4[0] * (fTemp18 + 1.0f))))))) * std::sqrt(((0.5f * (fTemp16 / fTemp7)) + 1.0f)))) + (((fRec24[0] * std::exp(std::max<float>(-80.0f, (0.5f * ((fTemp19 * fTemp5) / fTemp7))))) * (((fTemp21 + (1.0f - fTemp20)) * std::cos((6.28318548f * (fRec4[0] * fTemp21)))) + ((fTemp20 - fTemp21) * std::cos((6.28318548f * (fRec4[0] * (fTemp21 + 1.0f))))))) * std::sqrt(((0.5f * (fTemp19 / fTemp7)) + 1.0f))))))) + (0.600000024f * (((fRec11[0] * std::exp(std::max<float>(-80.0f, (11250.0f * (fTemp5 / fTemp7))))) * (((fTemp23 + (1.0f - fTemp22)) * std::cos((6.28318548f * (fRec4[0] * fTemp23)))) + ((fTemp22 - fTemp23) * std::cos((6.28318548f * (fRec4[0] * (fTemp23 + 1.0f))))))) * std::sqrt(((11250.0f / fTemp7) + 1.0f))))) * (1.0f - (0.5f * fRec29[0]))) + ((fRec0[0] * fRec29[0]) * ((fRec30[0] / fTemp27) + (fRec30[2] * (0.0f - (1.0f / fTemp27)))))));
			fVec1[0] = fTemp28;
			float fTemp29 = (0.25f * fTemp28);
			float fTempFTZ29 = (fConst5 + (fRec31[1] - std::floor((fConst5 + fRec31[1]))));
			fRec31[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTemp30 = (3.0f * ftbl0FaustVoiceDSPSIG0[int((65536.0f * fRec31[0]))]);
			float fTemp31 = (fTemp30 + 8.5f);
			int iTemp32 = int(fTemp31);
			float fTemp33 = std::floor(fTemp31);
			float fTemp34 = ((fVec1[std::min<int>(4097, std::max<int>(0, iTemp32))] * (fTemp33 + (-7.5f - fTemp30))) + ((fTemp30 + (8.5f - fTemp33)) * fVec1[std::min<int>(4097, std::max<int>(0, (iTemp32 + 1)))]));
			output0[i0] = FAUSTFLOAT((fTemp29 + (0.0874999985f * fTemp34)));
			output1[i0] = FAUSTFLOAT((fTemp29 - (0.0437499993f * fTemp34)));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec6[1] = fRec6[0];
			iRec7[1] = iRec7[0];
			fRec4[1] = fRec4[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			for (int j0 = 13; (j0 > 0); j0 = (j0 - 1)) {
				fVec1[j0] = fVec1[(j0 - 1)];
			}
			fRec31[1] = fRec31[0];
		}
	}

};

#endif
