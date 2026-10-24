/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "bansuri"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBansuriDSP_H__
#define  __FaustBansuriDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustBansuriDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec11[2];
	
  public:
	
	int getNumInputsFaustBansuriDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustBansuriDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustBansuriDSPSIG0(int sample_rate) {
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iVec1[l9] = 0;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iRec11[l10] = 0;
		}
	}
	
	void fillFaustBansuriDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec11[0] = ((iVec1[1] + iRec11[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec11[0])));
			iVec1[1] = iVec1[0];
			iRec11[1] = iRec11[0];
		}
	}

};

static FaustBansuriDSPSIG0* newFaustBansuriDSPSIG0() { return (FaustBansuriDSPSIG0*)new FaustBansuriDSPSIG0(); }
static void deleteFaustBansuriDSPSIG0(FaustBansuriDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustBansuriDSPSIG0[65536];
static float FaustBansuriDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBansuriDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBansuriDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst4;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	float fConst5;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec3[2];
	int iRec4[2];
	float fRec2[2];
	float fConst6;
	FAUSTFLOAT fHslider1;
	float fConst7;
	float fRec6[2];
	int iRec8[2];
	float fConst8;
	FAUSTFLOAT fHslider2;
	float fRec9[2];
	FAUSTFLOAT fHslider3;
	float fRec10[2];
	float fConst9;
	float fRec12[2];
	float fRec7[3];
	FAUSTFLOAT fHslider4;
	float fRec13[2];
	FAUSTFLOAT fHslider5;
	float fRec14[2];
	float fConst10;
	FAUSTFLOAT fHslider6;
	int IOTA;
	float fVec2[2048];
	float fVec3[2];
	float fRec17[2];
	float fRec16[2];
	float fRec15[3];
	float fVec4[32768];
	float fRec5[8192];
	float fConst14;
	FAUSTFLOAT fHslider7;
	float fRec18[2];
	float fConst17;
	float fConst19;
	float fRec21[4];
	float fConst20;
	float fConst21;
	float fRec20[3];
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fRec19[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec1[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "bansuri.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
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
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
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
		m->declare("fm.lib/copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "bansuri");
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
		FaustBansuriDSPSIG0* sig0 = newFaustBansuriDSPSIG0();
		sig0->instanceInitFaustBansuriDSPSIG0(sample_rate);
		sig0->fillFaustBansuriDSPSIG0(65536, ftbl0FaustBansuriDSPSIG0);
		deleteFaustBansuriDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((15707.9629f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 1.41421354f) / fConst1) + 1.0f);
		fConst4 = (0.242975295f / fConst3);
		fConst5 = (1.0f / std::max<float>(1.0f, (0.0500000007f * fConst0)));
		fConst6 = (44.0999985f / fConst0);
		fConst7 = (1.0f - fConst6);
		fConst8 = (3.14159274f / fConst0);
		fConst9 = (5.0f / fConst0);
		fConst10 = (0.5f * fConst0);
		float fConst11 = std::tan((10053.0967f / fConst0));
		float fConst12 = (1.0f / fConst11);
		float fConst13 = (((fConst12 + 1.41421354f) / fConst11) + 1.0f);
		fConst14 = (0.349999994f / fConst13);
		float fConst15 = std::tan((785.398193f / fConst0));
		float fConst16 = (1.0f / fConst15);
		fConst17 = (1.0f / (((fConst16 + 1.41421354f) / fConst15) + 1.0f));
		float fConst18 = FaustBansuriDSP_faustpower2_f(fConst15);
		fConst19 = (1.0f / fConst18);
		fConst20 = (((fConst16 + -1.41421354f) / fConst15) + 1.0f);
		fConst21 = (2.0f * (1.0f - fConst19));
		fConst22 = (0.0f - (2.0f / fConst18));
		fConst23 = (1.0f / fConst13);
		fConst24 = (((fConst12 + -1.41421354f) / fConst11) + 1.0f);
		fConst25 = (2.0f * (1.0f - (1.0f / FaustBansuriDSP_faustpower2_f(fConst11))));
		fConst26 = (1.0f / fConst3);
		fConst27 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst28 = (2.0f * (1.0f - (1.0f / FaustBansuriDSP_faustpower2_f(fConst1))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.71999999999999997f);
		fHslider2 = FAUSTFLOAT(440.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.14999999999999999f);
		fHslider5 = FAUSTFLOAT(0.02f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(0.14999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
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
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec8[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec9[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec10[l8] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec12[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec7[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec14[l14] = 0.0f;
		}
		IOTA = 0;
		for (int l15 = 0; (l15 < 2048); l15 = (l15 + 1)) {
			fVec2[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fVec3[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec17[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec15[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 32768); l20 = (l20 + 1)) {
			fVec4[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 8192); l21 = (l21 + 1)) {
			fRec5[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec18[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 4); l23 = (l23 + 1)) {
			fRec21[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec20[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec19[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec1[l26] = 0.0f;
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
	
	virtual FaustBansuriDSP* clone() {
		return new FaustBansuriDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bansuri");
		ui_interface->addHorizontalSlider("breathiness", &fHslider7, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("calibration", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1200.0f), FAUSTFLOAT(1200.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(440.0f), FAUSTFLOAT(150.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("loss", &fHslider5, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider4, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider1, FAUSTFLOAT(0.720000029f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.970000029f * float(fHslider0));
		float fSlow1 = float(fButton0);
		int iSlow2 = (fSlow1 == 0.0f);
		float fSlow3 = (fConst6 * float(fHslider1));
		float fSlow4 = (0.00499999989f * float(fHslider2));
		float fSlow5 = (fConst6 * float(fHslider3));
		float fSlow6 = (fConst6 * float(fHslider4));
		float fSlow7 = (fConst6 * float(fHslider5));
		float fSlow8 = (0.000833333354f * float(fHslider6));
		float fSlow9 = (fConst10 * std::pow(2.0f, (-1.0f * fSlow8)));
		float fSlow10 = (fConst10 * std::pow(2.0f, (0.0f - fSlow8)));
		float fSlow11 = (2.5f * std::pow(2.0f, fSlow8));
		float fSlow12 = (fConst6 * float(fHslider7));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (0.0299999993f * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec0[0] = fSlow1;
			float fTempFTZ1 = (fSlow1 + (fRec3[1] * float((fVec0[1] >= fSlow1))));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			iRec4[0] = (iSlow2 * (iRec4[1] + 1));
			float fTempFTZ2 = ((0.995000005f * fRec2[1]) + (0.00499999989f * std::max<float>(0.0f, (std::min<float>((fConst5 * fRec3[0]), 1.0f) - (fConst5 * float(iRec4[0]))))));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow3 + (fConst7 * fRec6[1]));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			iRec8[0] = ((1103515245 * iRec8[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * float(iRec8[0]));
			float fTempFTZ4 = (fSlow4 + (0.995000005f * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fSlow5 + (fConst7 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fConst9 + (fRec12[1] - std::floor((fConst9 + fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp1 = (fRec9[0] * ((0.0149999997f * (fRec10[0] * ftbl0FaustBansuriDSPSIG0[int((65536.0f * fRec12[0]))])) + 1.0f));
			float fTemp2 = std::tan((fConst8 * std::max<float>(40.0f, (0.600000024f * fTemp1))));
			float fTemp3 = (1.0f / fTemp2);
			float fTemp4 = FaustBansuriDSP_faustpower2_f(fTemp2);
			float fTemp5 = (((fTemp3 + 1.41421354f) / fTemp2) + 1.0f);
			float fTempFTZ7 = (fTemp0 - (((fRec7[2] * (((fTemp3 + -1.41421354f) / fTemp2) + 1.0f)) + (2.0f * (fRec7[1] * (1.0f - (1.0f / fTemp4))))) / fTemp5));
			fRec7[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fSlow6 + (fConst7 * fRec13[1]));
			fRec13[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp6 = (float(tanhf(float((2.0f * (fRec6[0] * fRec2[0]))))) * ((((((fRec7[1] * (0.0f - (2.0f / fTemp4))) + (fRec7[0] / fTemp4)) + (fRec7[2] / fTemp4)) * ((0.100000001f * std::pow(fRec13[0], 2.0f)) + 0.200000003f)) / fTemp5) + 1.0f));
			float fTempFTZ9 = (fSlow7 + (fConst7 * fRec14[1]));
			fRec14[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp7 = (0.99000001f - (0.0399999991f * fRec14[0]));
			float fTemp8 = std::max<float>(40.0f, fTemp1);
			fVec2[(IOTA & 2047)] = fRec5[((IOTA - (std::min<int>(16384, std::max<int>(0, int(((fSlow9 / fTemp8) + -2.5f)))) + 1)) & 8191)];
			float fTemp9 = (fSlow10 / fTemp8);
			float fTemp10 = float(int((fTemp9 + -2.5f)));
			float fTemp11 = (fTemp9 + (-2.99998999f - fTemp10));
			float fTemp12 = fVec2[((IOTA - std::min<int>(1024, std::max<int>(0, int(fTemp11)))) & 2047)];
			fVec3[0] = fTemp12;
			float fTemp13 = (fTemp10 + std::floor(fTemp11));
			float fTempFTZ10 = (fVec3[1] - (((fTemp13 + (3.5f - fTemp9)) * (fRec17[1] - fTemp12)) / (fTemp9 + (-1.5f - fTemp13))));
			fRec17[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = ((fRec17[0] + (0.995000005f * fRec16[1])) - fRec17[1]);
			fRec16[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp14 = std::tan((fConst8 * std::min<float>((8500.0f - (6500.0f * fRec14[0])), std::max<float>((fSlow11 * fTemp1), 100.0f))));
			float fTemp15 = (1.0f / fTemp14);
			float fTemp16 = (((fTemp15 + 1.41421354f) / fTemp14) + 1.0f);
			float fTempFTZ12 = (fRec16[0] - (((fRec15[2] * (((fTemp15 + -1.41421354f) / fTemp14) + 1.0f)) + (2.0f * (fRec15[1] * (1.0f - (1.0f / FaustBansuriDSP_faustpower2_f(fTemp14)))))) / fTemp16));
			fRec15[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			fVec4[(IOTA & 32767)] = ((0.5f * fTemp6) - ((fTemp7 * (fRec15[2] + (fRec15[0] + (2.0f * fRec15[1])))) / fTemp16));
			float fTempFTZ13 = ((4.85714293f * (float(tanhf(float((0.349999994f * std::max<float>(-1.5f, std::min<float>(1.5f, fVec4[((IOTA - std::min<int>(16384, std::max<int>(0, int((fSlow10 * (std::max<float>(0.0199999996f, (0.449999988f * fRec13[0])) / fTemp8)))))) & 32767)])))))) / fTemp7)) + (4.99999987e-05f * fTemp6));
			fRec5[(IOTA & 8191)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fSlow12 + (fConst7 * fRec18[1]));
			fRec18[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (((0.522189379f * fRec21[3]) + (fTemp0 + (2.49495602f * fRec21[1]))) - (2.0172658f * fRec21[2]));
			fRec21[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (((0.0499220341f * fRec21[0]) + (0.0506126992f * fRec21[2])) - (((0.0959935337f * fRec21[1]) + (0.00440878607f * fRec21[3])) + (fConst17 * ((fConst20 * fRec20[2]) + (fConst21 * fRec20[1])))));
			fRec20[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = ((fConst17 * (((fConst19 * fRec20[0]) + (fConst22 * fRec20[1])) + (fConst19 * fRec20[2]))) - (fConst23 * ((fConst24 * fRec19[2]) + (fConst25 * fRec19[1]))));
			fRec19[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = ((fRec2[0] * (fRec5[((IOTA - 0) & 8191)] + (fConst14 * ((fRec2[0] * fRec18[0]) * (fRec19[2] + (fRec19[0] + (2.0f * fRec19[1]))))))) - (fConst26 * ((fConst27 * fRec1[2]) + (fConst28 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			output0[i0] = FAUSTFLOAT((fConst4 * (fRec0[0] * (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))))));
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			iRec4[1] = iRec4[0];
			fRec2[1] = fRec2[0];
			fRec6[1] = fRec6[0];
			iRec8[1] = iRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec12[1] = fRec12[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			IOTA = (IOTA + 1);
			fVec3[1] = fVec3[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec21[j0] = fRec21[(j0 - 1)];
			}
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
