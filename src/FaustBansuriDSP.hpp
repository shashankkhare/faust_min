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

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustBansuriDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec12[2];
	
  public:
	
	int getNumInputsFaustBansuriDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustBansuriDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustBansuriDSPSIG0(int sample_rate) {
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iVec1[l10] = 0;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iRec12[l11] = 0;
		}
	}
	
	void fillFaustBansuriDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec12[0] = ((iVec1[1] + iRec12[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec12[0])));
			iVec1[1] = iVec1[0];
			iRec12[1] = iRec12[0];
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
	float fConst6;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec2[2];
	FAUSTFLOAT fHslider1;
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider2;
	float fConst9;
	float fRec5[2];
	float fRec4[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	float fConst10;
	float fRec7[2];
	int iRec9[2];
	float fRec8[4];
	float fConst11;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec11[2];
	float fConst12;
	float fRec13[2];
	float fRec10[3];
	FAUSTFLOAT fHslider7;
	float fRec14[2];
	FAUSTFLOAT fHslider8;
	float fRec16[2];
	float fConst13;
	int IOTA;
	float fVec2[2048];
	float fVec3[2];
	float fRec18[2];
	float fRec17[2];
	float fRec15[2];
	float fVec4[32768];
	float fRec3[4096];
	float fConst17;
	float fConst20;
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec20[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec19[3];
	float fConst29;
	float fConst30;
	float fConst31;
	float fRec1[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
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
		fConst4 = (0.157499999f / fConst3);
		fConst5 = std::exp((0.0f - (25.0f / fConst0)));
		fConst6 = (1.0f - fConst5);
		fConst7 = (1.0f / fConst0);
		fConst8 = (44.0999985f / fConst0);
		fConst9 = (1.0f - fConst8);
		fConst10 = std::exp((0.0f - (8.33333302f / fConst0)));
		fConst11 = (3.14159274f / fConst0);
		fConst12 = (5.0f / fConst0);
		fConst13 = (0.5f * fConst0);
		float fConst14 = std::tan((10053.0967f / fConst0));
		float fConst15 = (1.0f / fConst14);
		float fConst16 = (((fConst15 + 1.41421354f) / fConst14) + 1.0f);
		fConst17 = (12.0f / fConst16);
		float fConst18 = std::tan((785.398193f / fConst0));
		float fConst19 = (1.0f / fConst18);
		fConst20 = (1.0f / (((fConst19 + 1.41421354f) / fConst18) + 1.0f));
		float fConst21 = FaustBansuriDSP_faustpower2_f(fConst18);
		fConst22 = (1.0f / fConst21);
		fConst23 = (((fConst19 + -1.41421354f) / fConst18) + 1.0f);
		fConst24 = (2.0f * (1.0f - fConst22));
		fConst25 = (0.0f - (2.0f / fConst21));
		fConst26 = (1.0f / fConst16);
		fConst27 = (((fConst15 + -1.41421354f) / fConst14) + 1.0f);
		fConst28 = (2.0f * (1.0f - (1.0f / FaustBansuriDSP_faustpower2_f(fConst14))));
		fConst29 = (1.0f / fConst3);
		fConst30 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst31 = (2.0f * (1.0f - (1.0f / FaustBansuriDSP_faustpower2_f(fConst1))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.88f);
		fHslider3 = FAUSTFLOAT(0.29999999999999999f);
		fHslider4 = FAUSTFLOAT(440.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.20000000000000001f);
		fHslider7 = FAUSTFLOAT(0.5f);
		fHslider8 = FAUSTFLOAT(0.90000000000000002f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec9[l7] = 0;
		}
		for (int l8 = 0; (l8 < 4); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec11[l9] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec16[l15] = 0.0f;
		}
		IOTA = 0;
		for (int l16 = 0; (l16 < 2048); l16 = (l16 + 1)) {
			fVec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fVec3[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec18[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec17[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec15[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 32768); l21 = (l21 + 1)) {
			fVec4[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 4096); l22 = (l22 + 1)) {
			fRec3[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec20[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec19[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec1[l25] = 0.0f;
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
		ui_interface->addHorizontalSlider("breathiness", &fHslider3, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("calibration", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1200.0f), FAUSTFLOAT(1200.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(440.0f), FAUSTFLOAT(160.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider7, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider2, FAUSTFLOAT(0.879999995f), FAUSTFLOAT(0.200000003f), FAUSTFLOAT(1.5f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider6, FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("wallLoss", &fHslider8, FAUSTFLOAT(0.899999976f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.970000029f * float(fHslider0));
		float fSlow1 = float(fButton0);
		float fSlow2 = (fConst6 * fSlow1);
		float fSlow3 = ((0.100000001f * (1.0f - float(fHslider1))) + 0.00499999989f);
		int iSlow4 = (std::fabs(fSlow3) < 1.1920929e-07f);
		float fThen1 = std::exp((0.0f - (fConst7 / (iSlow4 ? 1.0f : fSlow3))));
		float fSlow5 = (iSlow4 ? 0.0f : fThen1);
		float fSlow6 = (fConst8 * float(fHslider2));
		float fSlow7 = (1.0f - fSlow5);
		float fSlow8 = (fConst8 * float(fHslider3));
		float fSlow9 = (float(fHslider4) * std::pow(2.0f, (0.000833333354f * float(fHslider5))));
		float fSlow10 = (0.600000024f * fSlow9);
		float fSlow11 = (fConst8 * float(fHslider6));
		float fSlow12 = (fConst8 * float(fHslider7));
		float fSlow13 = (fConst8 * float(fHslider8));
		float fSlow14 = (fConst17 * fSlow1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (0.0299999993f * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec0[0] = fSlow1;
			float fTempFTZ1 = (fSlow2 + (fConst5 * fRec2[1]));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow6 + (fConst9 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((fRec4[1] * fSlow5) + (std::min<float>(1.5f, (fSlow1 * fRec5[0])) * fSlow7));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow8 + (fConst9 * fRec6[1]));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((fConst10 * fRec7[1]) + (0.5f * float(((fSlow1 - fVec0[1]) > 0.0f))));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp0 = (fRec6[0] + fRec7[0]);
			iRec9[0] = ((1103515245 * iRec9[1]) + 12345);
			float fTempFTZ6 = (((0.522189379f * fRec8[3]) + ((4.65661287e-10f * float(iRec9[0])) + (2.49495602f * fRec8[1]))) - (2.0172658f * fRec8[2]));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp1 = ((0.0499220341f * fRec8[0]) + (0.0506126992f * fRec8[2]));
			float fTemp2 = ((0.0959935337f * fRec8[1]) + (0.00440878607f * fRec8[3]));
			float fTempFTZ7 = (fSlow11 + (fConst9 * fRec11[1]));
			fRec11[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fConst12 + (fRec13[1] - std::floor((fConst12 + fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp3 = ((0.0149999997f * (fRec11[0] * ftbl0FaustBansuriDSPSIG0[int((65536.0f * fRec13[0]))])) + 1.0f);
			float fTemp4 = std::tan((fConst11 * std::max<float>(40.0f, (fSlow10 * fTemp3))));
			float fTemp5 = (1.0f / fTemp4);
			float fTemp6 = FaustBansuriDSP_faustpower2_f(fTemp4);
			float fTemp7 = (((fTemp5 + 1.41421354f) / fTemp4) + 1.0f);
			float fTempFTZ9 = (fTemp1 - (fTemp2 + (((fRec10[2] * (((fTemp5 + -1.41421354f) / fTemp4) + 1.0f)) + (2.0f * (fRec10[1] * (1.0f - (1.0f / fTemp6))))) / fTemp7)));
			fRec10[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fSlow12 + (fConst9 * fRec14[1]));
			fRec14[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp8 = ((fRec4[0] * ((0.0500000007f * (fTemp0 * (fTemp1 - fTemp2))) + 1.0f)) * ((((((fRec10[1] * (0.0f - (2.0f / fTemp6))) + (fRec10[0] / fTemp6)) + (fRec10[2] / fTemp6)) * (((0.200000003f * std::pow(fRec14[0], 2.0f)) + (1.20000005f * fRec7[0])) + 0.600000024f)) / fTemp7) + 1.0f));
			float fTempFTZ11 = (fSlow13 + (fConst9 * fRec16[1]));
			fRec16[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp9 = (1.0f / std::tan((fConst11 * (8500.0f - (6500.0f * fRec16[0])))));
			float fTemp10 = std::max<float>(40.0f, (fSlow9 * fTemp3));
			float fTemp11 = (fConst13 / fTemp10);
			int iTemp12 = int((fTemp11 + -2.5f));
			fVec2[(IOTA & 2047)] = fRec3[((IOTA - (std::min<int>(16384, std::max<int>(0, iTemp12)) + 1)) & 4095)];
			float fTemp13 = float(iTemp12);
			float fTemp14 = (fTemp11 + (-2.99998999f - fTemp13));
			float fTemp15 = fVec2[((IOTA - std::min<int>(1024, std::max<int>(0, int(fTemp14)))) & 2047)];
			fVec3[0] = fTemp15;
			float fTemp16 = (fTemp13 + std::floor(fTemp14));
			float fTempFTZ12 = (fVec3[1] - (((fTemp16 + (3.5f - fTemp11)) * (fRec18[1] - fTemp15)) / (fTemp11 + (-1.5f - fTemp16))));
			fRec18[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = ((fRec18[0] + (0.995000005f * fRec17[1])) - fRec18[1]);
			fRec17[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (0.0f - (((fRec15[1] * (1.0f - fTemp9)) - (fRec17[0] + fRec17[1])) / (fTemp9 + 1.0f)));
			fRec15[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp17 = (fRec15[0] * (0.99000001f - (0.0399999991f * fRec16[0])));
			fVec4[(IOTA & 32767)] = (fTemp8 - fTemp17);
			float fTemp18 = std::max<float>(-1.10000002f, std::min<float>(1.10000002f, fVec4[((IOTA - std::min<int>(16384, std::max<int>(0, int((fConst13 * (std::max<float>(0.0199999996f, ((0.300000012f * fRec14[0]) + 0.200000003f)) / fTemp10)))))) & 32767)]));
			float fTempFTZ15 = ((fTemp18 + (9.99999975e-05f * fTemp8)) - (fTemp17 + (0.333299994f * std::pow(fTemp18, 3.0f))));
			fRec3[(IOTA & 4095)] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fTemp1 - (fTemp2 + (fConst20 * ((fConst23 * fRec20[2]) + (fConst24 * fRec20[1])))));
			fRec20[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = ((fConst20 * (((fConst22 * fRec20[0]) + (fConst25 * fRec20[1])) + (fConst22 * fRec20[2]))) - (fConst26 * ((fConst27 * fRec19[2]) + (fConst28 * fRec19[1]))));
			fRec19[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = ((fRec2[0] * (fRec3[((IOTA - 0) & 4095)] + (fSlow14 * (fTemp0 * (fRec19[2] + (fRec19[0] + (2.0f * fRec19[1]))))))) - (fConst29 * ((fConst30 * fRec1[2]) + (fConst31 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			output0[i0] = FAUSTFLOAT((fConst4 * (fRec0[0] * (fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))))));
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			iRec9[1] = iRec9[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec8[j0] = fRec8[(j0 - 1)];
			}
			fRec11[1] = fRec11[0];
			fRec13[1] = fRec13[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec14[1] = fRec14[0];
			fRec16[1] = fRec16[0];
			IOTA = (IOTA + 1);
			fVec3[1] = fVec3[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
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
