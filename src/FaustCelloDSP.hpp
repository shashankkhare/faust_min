/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "cello"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustCelloDSP_H__
#define  __FaustCelloDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustCelloDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec37[2];
	
  public:
	
	int getNumInputsFaustCelloDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustCelloDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustCelloDSPSIG0(int sample_rate) {
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			iVec1[l15] = 0;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			iRec37[l16] = 0;
		}
	}
	
	void fillFaustCelloDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec37[0] = ((iVec1[1] + iRec37[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec37[0])));
			iVec1[1] = iVec1[0];
			iRec37[1] = iRec37[0];
		}
	}

};

static FaustCelloDSPSIG0* newFaustCelloDSPSIG0() { return (FaustCelloDSPSIG0*)new FaustCelloDSPSIG0(); }
static void deleteFaustCelloDSPSIG0(FaustCelloDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustCelloDSPSIG0[65536];
static float FaustCelloDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}
static float FaustCelloDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustCelloDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustCelloDSP : public dsp {
	
 private:
	
	int iRec11[2];
	int iVec0[2];
	int fSampleRate;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider0;
	float fConst8;
	float fRec24[2];
	FAUSTFLOAT fHslider1;
	float fRec25[2];
	float fConst10;
	float fConst11;
	float fConst13;
	float fConst14;
	float fRec32[2];
	float fRec33[2];
	int iRec34[2];
	float fRec31[2];
	float fRec30[2];
	float fRec29[2];
	float fRec28[2];
	float fRec27[2];
	float fRec26[2];
	FAUSTFLOAT fHslider2;
	float fRec35[2];
	float fConst15;
	float fConst16;
	FAUSTFLOAT fButton0;
	float fRec36[2];
	float fConst17;
	FAUSTFLOAT fHslider3;
	float fRec39[2];
	float fRec38[2];
	float fRec21[2];
	FAUSTFLOAT fHslider4;
	float fRec41[2];
	float fRec40[2];
	float fRec42[4];
	int IOTA;
	float fRec43[2048];
	float fVec2[2];
	FAUSTFLOAT fHslider5;
	float fRec45[2];
	float fRec44[2];
	float fVec3[2048];
	float fRec18[2048];
	float fRec20[2];
	float fRec17[4];
	float fConst18;
	float fConst19;
	float fConst20;
	float fRec15[3];
	float fConst21;
	int iRec7[2];
	float fRec3[2048];
	float fRec1[2];
	float fConst22;
	float fConst23;
	float fRec46[2];
	float fVec4[2];
	float fRec0[2];
	FAUSTFLOAT fHslider6;
	float fRec47[2];
	FAUSTFLOAT fHslider7;
	float fRec48[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "cello.dsp");
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
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "cello");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
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
		FaustCelloDSPSIG0* sig0 = newFaustCelloDSPSIG0();
		sig0->instanceInitFaustCelloDSPSIG0(sample_rate);
		sig0->fillFaustCelloDSPSIG0(65536, ftbl0FaustCelloDSPSIG0);
		deleteFaustCelloDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((471.238892f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.666666687f) / fConst1) + 1.0f);
		fConst4 = (1.0f / (fConst1 * fConst3));
		fConst5 = (0.00882352982f * fConst0);
		fConst6 = (0.00147058826f * fConst0);
		fConst7 = (44.0999985f / fConst0);
		fConst8 = (1.0f - fConst7);
		float fConst9 = (1.0f / std::tan((4.71238899f / fConst0)));
		fConst10 = (1.0f / (fConst9 + 1.0f));
		fConst11 = (1.0f - fConst9);
		float fConst12 = (9.42477798f / fConst0);
		fConst13 = std::sin(fConst12);
		fConst14 = std::cos(fConst12);
		fConst15 = std::exp((0.0f - (3.33333325f / fConst0)));
		fConst16 = (1.0f - fConst15);
		fConst17 = (1.0f / fConst0);
		fConst18 = (1.0f / fConst3);
		fConst19 = (((fConst2 + -0.666666687f) / fConst1) + 1.0f);
		fConst20 = (2.0f * (1.0f - (1.0f / FaustCelloDSP_faustpower2_f(fConst1))));
		fConst21 = (0.0f - fConst4);
		fConst22 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst23 = (1.0f - fConst22);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.14999999999999999f);
		fHslider1 = FAUSTFLOAT(130.81f);
		fHslider2 = FAUSTFLOAT(0.0080000000000000002f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(5.0f);
		fHslider4 = FAUSTFLOAT(0.10000000000000001f);
		fHslider5 = FAUSTFLOAT(0.40000000000000002f);
		fHslider6 = FAUSTFLOAT(0.5f);
		fHslider7 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec11[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec0[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec24[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec25[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec32[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec33[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec34[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec31[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec30[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec29[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec28[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec27[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec26[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec35[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec36[l14] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec39[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec38[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec21[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec41[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec40[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 4); l22 = (l22 + 1)) {
			fRec42[l22] = 0.0f;
		}
		IOTA = 0;
		for (int l23 = 0; (l23 < 2048); l23 = (l23 + 1)) {
			fRec43[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fVec2[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec45[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec44[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2048); l27 = (l27 + 1)) {
			fVec3[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2048); l28 = (l28 + 1)) {
			fRec18[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec20[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 4); l30 = (l30 + 1)) {
			fRec17[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec15[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			iRec7[l32] = 0;
		}
		for (int l33 = 0; (l33 < 2048); l33 = (l33 + 1)) {
			fRec3[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec1[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec46[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fVec4[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec0[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec47[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec48[l39] = 0.0f;
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
	
	virtual FaustCelloDSP* clone() {
		return new FaustCelloDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("cello");
		ui_interface->addHorizontalSlider("bowPosition", &fHslider0, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("bowPressure", &fHslider5, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("bowVelocity", &fHslider4, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(130.809998f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider2, FAUSTFLOAT(0.00800000038f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0299999993f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider3, FAUSTFLOAT(5.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst7 * float(fHslider0));
		float fSlow1 = (fConst7 * float(fHslider1));
		float fSlow2 = (fConst7 * float(fHslider2));
		float fSlow3 = float(fButton0);
		float fSlow4 = (fConst16 * fSlow3);
		float fSlow5 = (fConst7 * float(fHslider3));
		float fSlow6 = (0.00100000005f * fSlow3);
		float fSlow7 = (fConst7 * float(fHslider4));
		float fSlow8 = (fConst7 * float(fHslider5));
		float fSlow9 = (fConst23 * fSlow3);
		float fSlow10 = (fConst7 * float(fHslider6));
		float fSlow11 = (fConst7 * ((0.75f * float(fHslider7)) + 0.25f));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec11[0] = 0;
			iVec0[0] = 1;
			int iRec12 = iRec11[1];
			float fTempFTZ0 = (float(iRec7[1]) - (0.989264667f * ((0.600000024f * fRec17[2]) + (0.200000003f * (fRec17[1] + fRec17[3])))));
			float fRec16 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow0 + (fConst8 * fRec24[1]));
			fRec24[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (1.0f - fRec24[0]);
			float fTempFTZ2 = (fSlow1 + (fConst8 * fRec25[1]));
			fRec25[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((fConst13 * fRec33[1]) + (fConst14 * fRec32[1]));
			fRec32[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((float((1 - iVec0[1])) + (fConst14 * fRec33[1])) - (fConst13 * fRec32[1]));
			fRec33[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			int iTemp1 = ((fRec32[1] <= 0.0f) & (fRec32[0] > 0.0f));
			iRec34[0] = ((1103515245 * iRec34[1]) + 12345);
			float fTempFTZ5 = ((fRec31[1] * float((1 - iTemp1))) + (4.65661287e-10f * (float(iRec34[0]) * float(iTemp1))));
			fRec31[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (0.0f - (fConst10 * ((fConst11 * fRec30[1]) - (fRec31[0] + fRec31[1]))));
			fRec30[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.0f - (fConst10 * ((fConst11 * fRec29[1]) - (fRec30[0] + fRec30[1]))));
			fRec29[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (0.0f - (fConst10 * ((fConst11 * fRec28[1]) - (fRec29[0] + fRec29[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (0.0f - (fConst10 * ((fConst11 * fRec27[1]) - (fRec28[0] + fRec28[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (0.0f - (fConst10 * ((fConst11 * fRec26[1]) - (fRec27[0] + fRec27[1]))));
			fRec26[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp2 = (0.00100000005f * fRec26[0]);
			float fTempFTZ11 = (fSlow2 + (fConst8 * fRec35[1]));
			fRec35[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fSlow4 + (fConst15 * fRec36[1]));
			fRec36[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fSlow5 + (fConst8 * fRec39[1]));
			fRec39[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp3 = (fRec38[1] + (fConst17 * fRec39[0]));
			float fTempFTZ14 = (fTemp3 - std::floor(fTemp3));
			fRec38[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp4 = ((fRec35[0] * fRec36[0]) * ftbl0FaustCelloDSPSIG0[int((65536.0f * fRec38[0]))]);
			float fTemp5 = std::max<float>(0.00999999978f, ((340.0f / (fRec25[0] * ((fTemp2 + fTemp4) + 1.0f))) + -0.0799999982f));
			int iTemp6 = int(((fConst6 * (fTemp0 * fTemp5)) + -1.49999499f));
			float fTemp7 = std::max<float>(0.00999999978f, ((340.0f / (fRec25[0] * ((fTemp2 + 1.0f) + fTemp4))) + -0.0799999982f));
			float fTemp8 = (fConst6 * (fTemp0 * fTemp7));
			float fTemp9 = (fTemp8 + -1.49999499f);
			float fTemp10 = std::floor(fTemp9);
			float fTemp11 = (fTemp8 + (-1.0f - fTemp10));
			float fTemp12 = (0.0f - fTemp11);
			float fTemp13 = (fTemp8 + (-2.0f - fTemp10));
			float fTemp14 = (0.0f - (0.5f * fTemp13));
			float fTemp15 = (fTemp8 + (-3.0f - fTemp10));
			float fTemp16 = (0.0f - (0.333333343f * fTemp15));
			float fTemp17 = (fTemp8 + (-4.0f - fTemp10));
			float fTemp18 = (0.0f - (0.25f * fTemp17));
			float fTemp19 = (fTemp8 - fTemp10);
			float fTemp20 = (0.0f - fTemp13);
			float fTemp21 = (0.0f - (0.5f * fTemp15));
			float fTemp22 = (0.0f - (0.333333343f * fTemp17));
			float fTemp23 = (0.0f - fTemp15);
			float fTemp24 = (0.0f - (0.5f * fTemp17));
			float fTemp25 = (fTemp11 * fTemp13);
			float fTemp26 = (0.0f - fTemp17);
			float fTemp27 = (fTemp25 * fTemp15);
			float fTempFTZ15 = (((((fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int(iTemp6))))) + 1)) & 2047)] * fTemp12) * fTemp14) * fTemp16) * fTemp18) + (fTemp19 * ((((((fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp6 + 1)))))) + 1)) & 2047)] * fTemp20) * fTemp21) * fTemp22) + (0.5f * (((fTemp11 * fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp6 + 2)))))) + 1)) & 2047)]) * fTemp23) * fTemp24))) + (0.166666672f * ((fTemp25 * fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp6 + 3)))))) + 1)) & 2047)]) * fTemp26))) + (0.0416666679f * (fTemp27 * fRec3[((IOTA - (int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp6 + 4)))))) + 1)) & 2047)])))));
			fRec21[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fSlow7 + (fConst8 * fRec41[1]));
			fRec41[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = ((0.999000013f * fRec40[1]) + (fSlow6 * fRec41[0]));
			fRec40[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec1[1];
			fRec42[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (-1.0f * (0.99880147f * ((0.800000012f * fRec42[2]) + (0.100000001f * (fRec42[1] + fRec42[3])))));
			fRec43[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			int iTemp28 = int(((fConst6 * (fRec24[0] * fTemp5)) + -1.49999499f));
			int iTemp29 = int(std::min<float>(fConst5, float(std::max<int>(0, int(iTemp28)))));
			float fTemp30 = (fConst6 * (fRec24[0] * fTemp7));
			float fTemp31 = std::floor((fTemp30 + -1.49999499f));
			float fTemp32 = (fTemp30 + (-1.0f - fTemp31));
			float fTemp33 = (0.0f - fTemp32);
			float fTemp34 = (fTemp30 + (-2.0f - fTemp31));
			float fTemp35 = (0.0f - (0.5f * fTemp34));
			float fTemp36 = (fTemp30 + (-3.0f - fTemp31));
			float fTemp37 = (0.0f - (0.333333343f * fTemp36));
			float fTemp38 = (fTemp30 + (-4.0f - fTemp31));
			float fTemp39 = (0.0f - (0.25f * fTemp38));
			float fTemp40 = (fTemp30 - fTemp31);
			int iTemp41 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp28 + 1))))));
			float fTemp42 = (0.0f - fTemp34);
			float fTemp43 = (0.0f - (0.5f * fTemp36));
			float fTemp44 = (0.0f - (0.333333343f * fTemp38));
			int iTemp45 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp28 + 2))))));
			float fTemp46 = (0.0f - fTemp36);
			float fTemp47 = (0.0f - (0.5f * fTemp38));
			float fTemp48 = (fTemp32 * fTemp34);
			int iTemp49 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp28 + 3))))));
			float fTemp50 = (0.0f - fTemp38);
			float fTemp51 = (fTemp48 * fTemp36);
			int iTemp52 = int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp28 + 4))))));
			fVec2[0] = (((((fRec43[((IOTA - (iTemp29 + 2)) & 2047)] * fTemp33) * fTemp35) * fTemp37) * fTemp39) + (fTemp40 * ((((((fRec43[((IOTA - (iTemp41 + 2)) & 2047)] * fTemp42) * fTemp43) * fTemp44) + (0.5f * (((fTemp32 * fRec43[((IOTA - (iTemp45 + 2)) & 2047)]) * fTemp46) * fTemp47))) + (0.166666672f * ((fTemp48 * fRec43[((IOTA - (iTemp49 + 2)) & 2047)]) * fTemp50))) + (0.0416666679f * (fTemp51 * fRec43[((IOTA - (iTemp52 + 2)) & 2047)])))));
			float fTemp53 = (fRec40[0] - (fRec21[1] + fVec2[1]));
			float fTempFTZ20 = (fSlow8 + (fConst8 * fRec45[1]));
			fRec45[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = ((0.999000013f * fRec44[1]) + (fSlow6 * fRec45[0]));
			fRec44[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp54 = (fTemp53 * std::min<float>(1.0f, (1.0f / FaustCelloDSP_faustpower4_f((std::fabs(((5.0f - (4.0f * fRec44[0])) * fTemp53)) + 0.75f)))));
			float fTempFTZ22 = (fRec21[1] + fTemp54);
			float fRec22 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTemp55 = (fVec2[1] + fTemp54);
			fVec3[(IOTA & 2047)] = fTemp55;
			int iTemp56 = int(fTemp9);
			float fTempFTZ23 = (((((fTemp12 * fTemp14) * fTemp16) * fTemp18) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int(iTemp56)))))) & 2047)]) + (fTemp19 * ((((((fTemp20 * fTemp21) * fTemp22) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp56 + 1))))))) & 2047)]) + (0.5f * (((fTemp11 * fTemp23) * fTemp24) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp56 + 2))))))) & 2047)]))) + (0.166666672f * ((fTemp25 * fTemp26) * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp56 + 3))))))) & 2047)]))) + (0.0416666679f * (fTemp27 * fVec3[((IOTA - int(std::min<float>(fConst5, float(std::max<int>(0, int((iTemp56 + 4))))))) & 2047)])))));
			float fRec23 = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec22;
			fRec18[(IOTA & 2047)] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (((((fTemp33 * fTemp35) * fTemp37) * fTemp39) * fRec18[((IOTA - (iTemp29 + 1)) & 2047)]) + (fTemp40 * ((((((fTemp42 * fTemp43) * fTemp44) * fRec18[((IOTA - (iTemp41 + 1)) & 2047)]) + (0.5f * (((fTemp32 * fTemp46) * fTemp47) * fRec18[((IOTA - (iTemp45 + 1)) & 2047)]))) + (0.166666672f * ((fTemp48 * fTemp50) * fRec18[((IOTA - (iTemp49 + 1)) & 2047)]))) + (0.0416666679f * (fTemp51 * fRec18[((IOTA - (iTemp52 + 1)) & 2047)])))));
			float fRec19 = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec23;
			fRec20[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec20[1];
			fRec17[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = (fRec17[1] - (fConst18 * ((fConst19 * fRec15[2]) + (fConst20 * fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = ((fConst4 * fRec15[0]) + (fConst21 * fRec15[2]));
			float fTemp57 = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fRec13 = fTemp57;
			float fRec14 = fTemp57;
			iRec7[0] = iRec12;
			float fTempFTZ30 = fRec16;
			float fRec8 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = fRec13;
			float fRec9 = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec14;
			float fRec10 = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = fRec8;
			fRec3[(IOTA & 2047)] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = fRec19;
			float fRec4 = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = fRec9;
			float fRec5 = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = fRec10;
			float fRec6 = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = fRec4;
			fRec1[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec6;
			float fRec2 = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fSlow9 + (fConst22 * fRec46[1]));
			fRec46[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTemp58 = (fRec2 * fRec46[0]);
			fVec4[0] = fTemp58;
			float fTempFTZ40 = ((fTemp58 + (0.995000005f * fRec0[1])) - fVec4[1]);
			fRec0[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = (fSlow10 + (fConst8 * fRec47[1]));
			fRec47[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = (fSlow11 + (fConst8 * fRec48[1]));
			fRec48[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			output0[i0] = FAUSTFLOAT(((float(tanhf(float(fRec0[0]))) * fRec47[0]) * fRec48[0]));
			iRec11[1] = iRec11[0];
			iVec0[1] = iVec0[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			iRec34[1] = iRec34[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec21[1] = fRec21[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec42[j0] = fRec42[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec20[1] = fRec20[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec17[j1] = fRec17[(j1 - 1)];
			}
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			iRec7[1] = iRec7[0];
			fRec1[1] = fRec1[0];
			fRec46[1] = fRec46[0];
			fVec4[1] = fVec4[0];
			fRec0[1] = fRec0[0];
			fRec47[1] = fRec47[0];
			fRec48[1] = fRec48[0];
		}
	}

};

#endif
