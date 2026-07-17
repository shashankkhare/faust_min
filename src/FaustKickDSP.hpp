/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "kick"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustKickDSP_H__
#define  __FaustKickDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustKickDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec5[2];
	
  public:
	
	int getNumInputsFaustKickDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustKickDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustKickDSPSIG0(int sample_rate) {
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec1[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec5[l5] = 0;
		}
	}
	
	void fillFaustKickDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec5[0] = ((iVec1[1] + iRec5[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec5[0])));
			iVec1[1] = iVec1[0];
			iRec5[1] = iRec5[0];
		}
	}

};

static FaustKickDSPSIG0* newFaustKickDSPSIG0() { return (FaustKickDSPSIG0*)new FaustKickDSPSIG0(); }
static void deleteFaustKickDSPSIG0(FaustKickDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustKickDSPSIG0[65536];
static float FaustKickDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustKickDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustKickDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec1[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec3[2];
	int iRec4[2];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fConst4;
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	float fRec8[2];
	float fRec2[3];
	float fConst5;
	float fRec9[3];
	float fConst6;
	float fRec10[3];
	float fRec11[3];
	float fRec12[3];
	float fRec13[3];
	float fVec2[2];
	float fRec0[2];
	FAUSTFLOAT fHslider4;
	float fRec14[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "kick.dsp");
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
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "kick");
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
		return 1;
	}
	
	static void classInit(int sample_rate) {
		FaustKickDSPSIG0* sig0 = newFaustKickDSPSIG0();
		sig0->instanceInitFaustKickDSPSIG0(sample_rate);
		sig0->fillFaustKickDSPSIG0(65536, ftbl0FaustKickDSPSIG0);
		deleteFaustKickDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (3.0f / fConst0);
		fConst4 = (6.72300816f / fConst0);
		fConst5 = (4.99513245f / fConst0);
		fConst6 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(55.0f);
		fHslider3 = FAUSTFLOAT(1.2f);
		fHslider4 = FAUSTFLOAT(0.80000000000000004f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec4[l3] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec2[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec0[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec14[l17] = 0.0f;
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
	
	virtual FaustKickDSP* clone() {
		return new FaustKickDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("kick");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(55.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider4, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("headTuning", &fHslider3, FAUSTFLOAT(1.20000005f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.5f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sub_boost", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fButton0);
		float fSlow3 = float(fHslider2);
		float fSlow4 = (fConst3 * fSlow3);
		float fSlow5 = (fConst4 * fSlow3);
		float fSlow6 = (fConst1 * float(fHslider3));
		float fSlow7 = (fConst5 * fSlow3);
		float fSlow8 = (fConst6 * fSlow3);
		float fSlow9 = (fConst1 * float(fHslider4));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec1[1]));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec0[0] = fSlow2;
			int iTemp0 = ((fSlow2 - fVec0[1]) > 0.0f);
			float fThen0 = (0.99000001f * fRec3[1]);
			float fTempFTZ1 = (iTemp0 ? 1.0f : fThen0);
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTempFTZ2 = (fSlow4 + (fRec6[1] - std::floor((fSlow4 + fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp1 = (fSlow1 * (std::max<float>(0.0f, fRec3[0]) * ((9.31322588e-11f * float(iRec4[0])) + (0.800000012f * ftbl0FaustKickDSPSIG0[int((65536.0f * fRec6[0]))]))));
			float fTempFTZ3 = (fSlow6 + (fConst2 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fThen1 = (0.995999992f * fRec8[1]);
			float fTempFTZ4 = (iTemp0 ? 1.0f : fThen1);
			fRec8[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp2 = ((1.79999995f * fRec8[0]) + 1.0f);
			float fTemp3 = (fRec7[0] * fTemp2);
			float fTemp4 = std::tan((fSlow5 * fTemp3));
			float fTemp5 = (1.0f / fTemp4);
			float fTemp6 = (((fTemp5 + 0.0666666701f) / fTemp4) + 1.0f);
			float fTempFTZ5 = (fTemp1 - (((fRec2[2] * (((fTemp5 + -0.0666666701f) / fTemp4) + 1.0f)) + (2.0f * (fRec2[1] * (1.0f - (1.0f / FaustKickDSP_faustpower2_f(fTemp4)))))) / fTemp6));
			fRec2[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp7 = (fTemp4 * fTemp6);
			float fTemp8 = std::tan((fSlow7 * fTemp3));
			float fTemp9 = (1.0f / fTemp8);
			float fTemp10 = (((fTemp9 + 0.125f) / fTemp8) + 1.0f);
			float fTempFTZ6 = (fTemp1 - (((fRec9[2] * (((fTemp9 + -0.125f) / fTemp8) + 1.0f)) + (2.0f * (fRec9[1] * (1.0f - (1.0f / FaustKickDSP_faustpower2_f(fTemp8)))))) / fTemp10));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp11 = (fTemp8 * fTemp10);
			float fTemp12 = std::tan((fSlow8 * fTemp3));
			float fTemp13 = (1.0f / fTemp12);
			float fTemp14 = (((fTemp13 + 0.0285714287f) / fTemp12) + 1.0f);
			float fTempFTZ7 = (fTemp1 - (((fRec10[2] * (((fTemp13 + -0.0285714287f) / fTemp12) + 1.0f)) + (2.0f * (fRec10[1] * (1.0f - (1.0f / FaustKickDSP_faustpower2_f(fTemp12)))))) / fTemp14));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp15 = (fTemp12 * fTemp14);
			float fTemp16 = (1.5f * (fRec1[0] * ((fRec2[2] * (0.0f - (0.200000003f / fTemp7))) + (((fRec9[2] * (0.0f - (0.300000012f / fTemp11))) + (((0.699999988f * (fRec10[0] / fTemp15)) + (fRec10[2] * (0.0f - (0.699999988f / fTemp15)))) + (0.300000012f * (fRec9[0] / fTemp11)))) + (0.200000003f * (fRec2[0] / fTemp7))))));
			float fTemp17 = std::tan((fSlow5 * fTemp2));
			float fTemp18 = (1.0f / fTemp17);
			float fTemp19 = (((fTemp18 + 0.0666666701f) / fTemp17) + 1.0f);
			float fTempFTZ8 = (fTemp1 - (((fRec11[2] * (((fTemp18 + -0.0666666701f) / fTemp17) + 1.0f)) + (2.0f * (fRec11[1] * (1.0f - (1.0f / FaustKickDSP_faustpower2_f(fTemp17)))))) / fTemp19));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp20 = (fTemp17 * fTemp19);
			float fTemp21 = (fRec11[2] * (0.0f - (0.200000003f / fTemp20)));
			float fTemp22 = (0.200000003f * (fRec11[0] / fTemp20));
			float fTemp23 = std::tan((fSlow7 * fTemp2));
			float fTemp24 = (1.0f / fTemp23);
			float fTemp25 = (((fTemp24 + 0.125f) / fTemp23) + 1.0f);
			float fTempFTZ9 = (fTemp1 - (((fRec12[2] * (((fTemp24 + -0.125f) / fTemp23) + 1.0f)) + (2.0f * (fRec12[1] * (1.0f - (1.0f / FaustKickDSP_faustpower2_f(fTemp23)))))) / fTemp25));
			fRec12[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp26 = (fTemp23 * fTemp25);
			float fTemp27 = (fRec12[2] * (0.0f - (0.300000012f / fTemp26)));
			float fTemp28 = (0.300000012f * (fRec12[0] / fTemp26));
			float fTemp29 = std::tan((fSlow8 * fTemp2));
			float fTemp30 = (1.0f / fTemp29);
			float fTemp31 = (((fTemp30 + 0.0833333358f) / fTemp29) + 1.0f);
			float fTempFTZ10 = (fTemp1 - (((fRec13[2] * (((fTemp30 + -0.0833333358f) / fTemp29) + 1.0f)) + (2.0f * (fRec13[1] * (1.0f - (1.0f / FaustKickDSP_faustpower2_f(fTemp29)))))) / fTemp31));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp32 = (fTemp29 * fTemp31);
			float fTemp33 = (fRec13[2] * (0.0f - (0.600000024f / fTemp32)));
			float fTemp34 = (0.600000024f * (fRec13[0] / fTemp32));
			fVec2[0] = ((fTemp21 + ((fTemp27 + ((fTemp34 + fTemp33) + fTemp28)) + fTemp22)) + fTemp16);
			float fTempFTZ11 = ((fTemp16 + (fTemp21 + (fTemp22 + (fTemp27 + (fTemp28 + (fTemp33 + ((0.995000005f * fRec0[1]) + fTemp34))))))) - fVec2[1]);
			fRec0[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fSlow9 + (fConst2 * fRec14[1]));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			output0[i0] = FAUSTFLOAT((37.5f * (float(tanhf(float(fRec0[0]))) * fRec14[0])));
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			iRec4[1] = iRec4[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fVec2[1] = fVec2[0];
			fRec0[1] = fRec0[0];
			fRec14[1] = fRec14[0];
		}
	}

};

#endif
