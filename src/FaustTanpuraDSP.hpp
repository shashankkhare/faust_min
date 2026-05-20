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

const static float fFaustTanpuraDSPSIG0Wave0[32] = {65.4100037f,0.0149999997f,0.550000012f,0.0149999997f,0.5f,1500.0f,0.100000001f,1.0f,130.809998f,0.0149999997f,0.550000012f,0.0115f,0.400000006f,2000.0f,0.0700000003f,1.0f,196.0f,0.0149999997f,0.550000012f,0.00850000046f,0.449999988f,2400.0f,0.0500000007f,1.0f,261.630005f,0.00499999989f,0.75f,0.0149999997f,0.5f,1000.0f,0.0700000003f,1.0f};
class FaustTanpuraDSPSIG0 {
	
  private:
	
	int fFaustTanpuraDSPSIG0Wave0_idx;
	
  public:
	
	int getNumInputsFaustTanpuraDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTanpuraDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTanpuraDSPSIG0(int sample_rate) {
		fFaustTanpuraDSPSIG0Wave0_idx = 0;
	}
	
	void fillFaustTanpuraDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			table[i1] = fFaustTanpuraDSPSIG0Wave0[fFaustTanpuraDSPSIG0Wave0_idx];
			fFaustTanpuraDSPSIG0Wave0_idx = ((1 + fFaustTanpuraDSPSIG0Wave0_idx) % 32);
		}
	}

};

static FaustTanpuraDSPSIG0* newFaustTanpuraDSPSIG0() { return (FaustTanpuraDSPSIG0*)new FaustTanpuraDSPSIG0(); }
static void deleteFaustTanpuraDSPSIG0(FaustTanpuraDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustTanpuraDSPSIG0[32];

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
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider1;
	float fConst3;
	float fRec3[2];
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider2;
	int iRec4[2];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int IOTA;
	int iVec1[524288];
	float fRec5[2];
	float fVec2[2];
	float fRec2[2];
	float fVec3[2];
	float fConst9;
	float fConst11;
	float fVec4[2];
	float fConst12;
	float fConst13;
	float fRec6[2];
	float fRec7[2];
	float fRec8[2];
	float fRec1[16384];
	FAUSTFLOAT fHslider3;
	float fRec9[2];
	int iConst14;
	int iConst15;
	float fRec12[2];
	float fVec5[2];
	float fRec11[2];
	float fVec6[2];
	float fVec7[2];
	float fRec13[2];
	float fRec14[2];
	float fRec15[2];
	float fRec10[16384];
	int iConst16;
	int iConst17;
	float fRec18[2];
	float fVec8[2];
	float fRec17[2];
	float fVec9[2];
	float fVec10[2];
	float fRec19[2];
	float fRec20[2];
	float fRec21[2];
	float fRec16[16384];
	int iConst18;
	int iConst19;
	float fRec24[2];
	float fVec11[2];
	float fRec23[2];
	float fVec12[2];
	float fVec13[2];
	float fRec25[2];
	float fRec26[2];
	float fRec27[2];
	float fRec22[16384];
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
		FaustTanpuraDSPSIG0* sig0 = newFaustTanpuraDSPSIG0();
		sig0->instanceInitFaustTanpuraDSPSIG0(sample_rate);
		sig0->fillFaustTanpuraDSPSIG0(32, ftbl0FaustTanpuraDSPSIG0);
		deleteFaustTanpuraDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (44.0999985f / fConst0);
		fConst3 = (1.0f - fConst2);
		fConst4 = ftbl0FaustTanpuraDSPSIG0[24];
		fConst5 = ftbl0FaustTanpuraDSPSIG0[16];
		fConst6 = ftbl0FaustTanpuraDSPSIG0[8];
		fConst7 = ftbl0FaustTanpuraDSPSIG0[0];
		float fConst8 = std::tan((6911.50391f / fConst0));
		fConst9 = (1.0f / fConst8);
		float fConst10 = (fConst9 + 1.0f);
		fConst11 = (0.0f - (1.0f / (fConst8 * fConst10)));
		fConst12 = (1.0f / fConst10);
		fConst13 = (1.0f - fConst9);
		iConst14 = int((0.5f * fConst0));
		iConst15 = (iConst14 + 1);
		iConst16 = int(fConst0);
		iConst17 = (iConst16 + 1);
		iConst18 = int((1.5f * fConst0));
		iConst19 = (iConst18 + 1);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(196.22f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(130.81f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec3[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec4[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		IOTA = 0;
		for (int l3 = 0; (l3 < 524288); l3 = (l3 + 1)) {
			iVec1[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec4[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec6[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec8[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 16384); l12 = (l12 + 1)) {
			fRec1[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec9[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec11[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fVec6[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec7[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec13[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec14[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec15[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 16384); l22 = (l22 + 1)) {
			fRec10[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec18[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fVec8[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec17[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fVec9[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fVec10[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec19[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec20[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec21[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 16384); l31 = (l31 + 1)) {
			fRec16[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec24[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fVec11[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec23[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fVec12[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fVec13[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec25[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec26[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec27[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 16384); l40 = (l40 + 1)) {
			fRec22[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fVec14[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec0[l42] = 0.0f;
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
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(130.809998f), FAUSTFLOAT(40.0f), FAUSTFLOAT(600.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq1", &fHslider1, FAUSTFLOAT(196.220001f), FAUSTFLOAT(40.0f), FAUSTFLOAT(600.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.25f * float(fHslider0));
		float fSlow1 = (fConst2 * float(fHslider1));
		float fSlow2 = (4.65661287e-10f * float(fHslider2));
		float fSlow3 = float(fButton0);
		float fSlow4 = (fConst2 * float(fHslider3));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow1 + (fConst3 * fRec3[1]));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = ((std::fabs((fRec3[0] - fConst6)) < std::fabs((fRec3[0] - fConst7))) ? 1.0f : 0.0f);
			float fTemp1 = ((std::fabs((fRec3[0] - fConst5)) < std::fabs((fRec3[0] - ftbl0FaustTanpuraDSPSIG0[int((8.0f * fTemp0))]))) ? 2.0f : fTemp0);
			float fTemp2 = (8.0f * ((std::fabs((fRec3[0] - fConst4)) < std::fabs((fRec3[0] - ftbl0FaustTanpuraDSPSIG0[int((8.0f * fTemp1))]))) ? 3.0f : fTemp1));
			float fTemp3 = (1.0f / std::tan((fConst1 * ftbl0FaustTanpuraDSPSIG0[int((fTemp2 + 5.0f))])));
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTemp4 = float(iRec4[0]);
			fVec0[0] = fSlow3;
			int iTemp5 = ((fSlow3 - fVec0[1]) > 0.0f);
			iVec1[(IOTA & 524287)] = iTemp5;
			float fTemp6 = float((float((iTemp5 - iVec1[((IOTA - 1) & 524287)])) > 0.0f));
			float fThen3 = std::max<float>(0.0f, (fRec5[1] + -1.0f));
			float fElse3 = (fConst0 * ftbl0FaustTanpuraDSPSIG0[int((fTemp2 + 3.0f))]);
			float fTempFTZ1 = ((fTemp6 > 0.0f) ? fElse3 : fThen3);
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp7 = (fSlow2 * ((fTemp4 * float((fRec5[0] > 0.0f))) * ftbl0FaustTanpuraDSPSIG0[int((fTemp2 + 4.0f))]));
			fVec2[0] = fTemp7;
			float fTempFTZ2 = (0.0f - (((fRec2[1] * (1.0f - fTemp3)) - (fTemp7 + fVec2[1])) / (fTemp3 + 1.0f)));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp8 = (fConst0 / std::max<float>(20.0f, fRec3[0]));
			float fTemp9 = (fTemp8 + -2.0f);
			int iTemp10 = int(fTemp9);
			float fTemp11 = std::floor(fTemp9);
			float fTemp12 = ((fRec1[((IOTA - (std::min<int>(8193, std::max<int>(0, iTemp10)) + 1)) & 16383)] * (fTemp11 + (3.0f - fTemp8))) + ((fTemp8 + (-2.0f - fTemp11)) * fRec1[((IOTA - (std::min<int>(8193, std::max<int>(0, (iTemp10 + 1))) + 1)) & 16383)]));
			fVec3[0] = fTemp12;
			float fTemp13 = (fTemp12 - fVec3[1]);
			fVec4[0] = fTemp13;
			float fTempFTZ3 = ((fConst11 * fVec4[1]) - (fConst12 * ((fConst13 * fRec6[1]) - (fConst9 * fTemp13))));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((0.996999979f * fRec7[1]) + (0.00300000003f * std::fabs(fTemp12)));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp14 = ((0.99970001f * fTemp12) + ((fRec6[0] * std::max<float>(0.0f, (fRec7[0] - ftbl0FaustTanpuraDSPSIG0[int((fTemp2 + 1.0f))]))) * ftbl0FaustTanpuraDSPSIG0[int((fTemp2 + 2.0f))]));
			float fTemp15 = ftbl0FaustTanpuraDSPSIG0[int((fTemp2 + 6.0f))];
			float fTemp16 = std::sin(fTemp15);
			float fTemp17 = std::cos(fTemp15);
			float fTempFTZ5 = ((fTemp14 * fTemp17) - (fTemp16 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fRec2[0] + (0.999750018f * (((fTemp14 * fTemp16) + (fRec8[1] * fTemp17)) * (1.0f - fTemp6))));
			fRec1[(IOTA & 16383)] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fSlow4 + (fConst3 * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp18 = ((std::fabs((fRec9[0] - fConst6)) < std::fabs((fRec9[0] - fConst7))) ? 1.0f : 0.0f);
			float fTemp19 = ((std::fabs((fRec9[0] - fConst5)) < std::fabs((fRec9[0] - ftbl0FaustTanpuraDSPSIG0[int((8.0f * fTemp18))]))) ? 2.0f : fTemp18);
			float fTemp20 = (8.0f * ((std::fabs((fRec9[0] - fConst4)) < std::fabs((fRec9[0] - ftbl0FaustTanpuraDSPSIG0[int((8.0f * fTemp19))]))) ? 3.0f : fTemp19));
			float fTemp21 = (1.0f / std::tan((fConst1 * ftbl0FaustTanpuraDSPSIG0[int((fTemp20 + 5.0f))])));
			float fTemp22 = (1.0f - fTemp21);
			float fTemp23 = float((float((iVec1[((IOTA - iConst14) & 524287)] - iVec1[((IOTA - iConst15) & 524287)])) > 0.0f));
			float fTemp24 = (fConst0 * ftbl0FaustTanpuraDSPSIG0[int((fTemp20 + 3.0f))]);
			float fThen7 = std::max<float>(0.0f, (fRec12[1] + -1.0f));
			float fTempFTZ8 = ((fTemp23 > 0.0f) ? fTemp24 : fThen7);
			fRec12[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp25 = ftbl0FaustTanpuraDSPSIG0[int((fTemp20 + 4.0f))];
			float fTemp26 = (fSlow2 * ((fTemp4 * float((fRec12[0] > 0.0f))) * fTemp25));
			fVec5[0] = fTemp26;
			float fTemp27 = (fTemp21 + 1.0f);
			float fTempFTZ9 = (0.0f - (((fRec11[1] * fTemp22) - (fTemp26 + fVec5[1])) / fTemp27));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp28 = (fConst0 / std::max<float>(20.0f, fRec9[0]));
			float fTemp29 = (fTemp28 + -2.0f);
			int iTemp30 = int(fTemp29);
			int iTemp31 = (std::min<int>(8193, std::max<int>(0, iTemp30)) + 1);
			float fTemp32 = std::floor(fTemp29);
			float fTemp33 = (fTemp32 + (3.0f - fTemp28));
			float fTemp34 = (fTemp28 + (-2.0f - fTemp32));
			int iTemp35 = (std::min<int>(8193, std::max<int>(0, (iTemp30 + 1))) + 1);
			float fTemp36 = ((fRec10[((IOTA - iTemp31) & 16383)] * fTemp33) + (fTemp34 * fRec10[((IOTA - iTemp35) & 16383)]));
			fVec6[0] = fTemp36;
			float fTemp37 = (fTemp36 - fVec6[1]);
			fVec7[0] = fTemp37;
			float fTempFTZ10 = ((fConst11 * fVec7[1]) - (fConst12 * ((fConst13 * fRec13[1]) - (fConst9 * fTemp37))));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = ((0.996999979f * fRec14[1]) + (0.00300000003f * std::fabs(fTemp36)));
			fRec14[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp38 = ftbl0FaustTanpuraDSPSIG0[int((fTemp20 + 1.0f))];
			float fTemp39 = ftbl0FaustTanpuraDSPSIG0[int((fTemp20 + 2.0f))];
			float fTemp40 = ((0.99970001f * fTemp36) + ((fRec13[0] * std::max<float>(0.0f, (fRec14[0] - fTemp38))) * fTemp39));
			float fTemp41 = ftbl0FaustTanpuraDSPSIG0[int((fTemp20 + 6.0f))];
			float fTemp42 = std::sin(fTemp41);
			float fTemp43 = std::cos(fTemp41);
			float fTempFTZ12 = ((fTemp40 * fTemp43) - (fTemp42 * fRec15[1]));
			fRec15[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fRec11[0] + (0.999750018f * (((fTemp40 * fTemp42) + (fRec15[1] * fTemp43)) * (1.0f - fTemp23))));
			fRec10[(IOTA & 16383)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp44 = float((float((iVec1[((IOTA - iConst16) & 524287)] - iVec1[((IOTA - iConst17) & 524287)])) > 0.0f));
			float fThen8 = std::max<float>(0.0f, (fRec18[1] + -1.0f));
			float fTempFTZ14 = ((fTemp44 > 0.0f) ? fTemp24 : fThen8);
			fRec18[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp45 = (fSlow2 * ((fTemp4 * float((fRec18[0] > 0.0f))) * fTemp25));
			fVec8[0] = fTemp45;
			float fTempFTZ15 = (0.0f - (((fTemp22 * fRec17[1]) - (fTemp45 + fVec8[1])) / fTemp27));
			fRec17[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp46 = ((fTemp33 * fRec16[((IOTA - iTemp31) & 16383)]) + (fTemp34 * fRec16[((IOTA - iTemp35) & 16383)]));
			fVec9[0] = fTemp46;
			float fTemp47 = (fTemp46 - fVec9[1]);
			fVec10[0] = fTemp47;
			float fTempFTZ16 = ((fConst11 * fVec10[1]) - (fConst12 * ((fConst13 * fRec19[1]) - (fConst9 * fTemp47))));
			fRec19[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = ((0.996999979f * fRec20[1]) + (0.00300000003f * std::fabs(fTemp46)));
			fRec20[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTemp48 = ((0.99970001f * fTemp46) + ((fRec19[0] * fTemp39) * std::max<float>(0.0f, (fRec20[0] - fTemp38))));
			float fTempFTZ18 = ((fTemp43 * fTemp48) - (fTemp42 * fRec21[1]));
			fRec21[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fRec17[0] + (0.999750018f * (((fTemp42 * fTemp48) + (fTemp43 * fRec21[1])) * (1.0f - fTemp44))));
			fRec16[(IOTA & 16383)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTemp49 = (0.5f * fRec9[0]);
			float fTemp50 = ((std::fabs((fTemp49 - fConst6)) < std::fabs((fTemp49 - fConst7))) ? 1.0f : 0.0f);
			float fTemp51 = ((std::fabs((fTemp49 - fConst5)) < std::fabs((fTemp49 - ftbl0FaustTanpuraDSPSIG0[int((8.0f * fTemp50))]))) ? 2.0f : fTemp50);
			float fTemp52 = (8.0f * ((std::fabs((fTemp49 - fConst4)) < std::fabs((fTemp49 - ftbl0FaustTanpuraDSPSIG0[int((8.0f * fTemp51))]))) ? 3.0f : fTemp51));
			float fTemp53 = (1.0f / std::tan((fConst1 * ftbl0FaustTanpuraDSPSIG0[int((fTemp52 + 5.0f))])));
			float fTemp54 = float((float((iVec1[((IOTA - iConst18) & 524287)] - iVec1[((IOTA - iConst19) & 524287)])) > 0.0f));
			float fThen12 = std::max<float>(0.0f, (fRec24[1] + -1.0f));
			float fElse12 = (fConst0 * ftbl0FaustTanpuraDSPSIG0[int((fTemp52 + 3.0f))]);
			float fTempFTZ20 = ((fTemp54 > 0.0f) ? fElse12 : fThen12);
			fRec24[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp55 = (fSlow2 * ((float((fRec24[0] > 0.0f)) * fTemp4) * ftbl0FaustTanpuraDSPSIG0[int((fTemp52 + 4.0f))]));
			fVec11[0] = fTemp55;
			float fTempFTZ21 = (0.0f - (((fRec23[1] * (1.0f - fTemp53)) - (fTemp55 + fVec11[1])) / (fTemp53 + 1.0f)));
			fRec23[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp56 = (fConst0 / std::max<float>(20.0f, fTemp49));
			float fTemp57 = (fTemp56 + -2.0f);
			int iTemp58 = int(fTemp57);
			float fTemp59 = std::floor(fTemp57);
			float fTemp60 = ((fRec22[((IOTA - (std::min<int>(8193, std::max<int>(0, iTemp58)) + 1)) & 16383)] * (fTemp59 + (3.0f - fTemp56))) + ((fTemp56 + (-2.0f - fTemp59)) * fRec22[((IOTA - (std::min<int>(8193, std::max<int>(0, (iTemp58 + 1))) + 1)) & 16383)]));
			fVec12[0] = fTemp60;
			float fTemp61 = (fTemp60 - fVec12[1]);
			fVec13[0] = fTemp61;
			float fTempFTZ22 = ((fConst11 * fVec13[1]) - (fConst12 * ((fConst13 * fRec25[1]) - (fConst9 * fTemp61))));
			fRec25[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = ((0.996999979f * fRec26[1]) + (0.00300000003f * std::fabs(fTemp60)));
			fRec26[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTemp62 = ((0.99970001f * fTemp60) + ((fRec25[0] * std::max<float>(0.0f, (fRec26[0] - ftbl0FaustTanpuraDSPSIG0[int((fTemp52 + 1.0f))]))) * ftbl0FaustTanpuraDSPSIG0[int((fTemp52 + 2.0f))]));
			float fTemp63 = ftbl0FaustTanpuraDSPSIG0[int((fTemp52 + 6.0f))];
			float fTemp64 = std::sin(fTemp63);
			float fTemp65 = std::cos(fTemp63);
			float fTempFTZ24 = ((fTemp62 * fTemp65) - (fTemp64 * fRec27[1]));
			fRec27[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fRec23[0] + (0.999750018f * (((fTemp62 * fTemp64) + (fRec27[1] * fTemp65)) * (1.0f - fTemp54))));
			fRec22[(IOTA & 16383)] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTemp66 = (fSlow0 * (((fRec1[((IOTA - 0) & 16383)] * ftbl0FaustTanpuraDSPSIG0[int((fTemp2 + 7.0f))]) + (ftbl0FaustTanpuraDSPSIG0[int((fTemp20 + 7.0f))] * (fRec10[((IOTA - 0) & 16383)] + fRec16[((IOTA - 0) & 16383)]))) + (fRec22[((IOTA - 0) & 16383)] * ftbl0FaustTanpuraDSPSIG0[int((fTemp52 + 7.0f))])));
			fVec14[0] = fTemp66;
			float fTempFTZ26 = (((0.995000005f * fRec0[1]) + fTemp66) - fVec14[1]);
			fRec0[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] / (std::fabs(fRec0[0]) + 1.0f)));
			fRec3[1] = fRec3[0];
			iRec4[1] = iRec4[0];
			fVec0[1] = fVec0[0];
			IOTA = (IOTA + 1);
			fRec5[1] = fRec5[0];
			fVec2[1] = fVec2[0];
			fRec2[1] = fRec2[0];
			fVec3[1] = fVec3[0];
			fVec4[1] = fVec4[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec12[1] = fRec12[0];
			fVec5[1] = fVec5[0];
			fRec11[1] = fRec11[0];
			fVec6[1] = fVec6[0];
			fVec7[1] = fVec7[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fVec8[1] = fVec8[0];
			fRec17[1] = fRec17[0];
			fVec9[1] = fVec9[0];
			fVec10[1] = fVec10[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec24[1] = fRec24[0];
			fVec11[1] = fVec11[0];
			fRec23[1] = fRec23[0];
			fVec12[1] = fVec12[0];
			fVec13[1] = fVec13[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			fRec27[1] = fRec27[0];
			fVec14[1] = fVec14[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
