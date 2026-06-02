/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "waterfall"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustWaterfallDSP_H__
#define  __FaustWaterfallDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustWaterfallDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec2[2];
	
  public:
	
	int getNumInputsFaustWaterfallDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustWaterfallDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustWaterfallDSPSIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec2[l1] = 0;
		}
	}
	
	void fillFaustWaterfallDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec2[0] = ((iVec0[1] + iRec2[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec2[0])));
			iVec0[1] = iVec0[0];
			iRec2[1] = iRec2[0];
		}
	}

};

static FaustWaterfallDSPSIG0* newFaustWaterfallDSPSIG0() { return (FaustWaterfallDSPSIG0*)new FaustWaterfallDSPSIG0(); }
static void deleteFaustWaterfallDSPSIG0(FaustWaterfallDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustWaterfallDSPSIG0[65536];
static float FaustWaterfallDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustWaterfallDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustWaterfallDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fButton0;
	int fSampleRate;
	float fConst1;
	float fConst2;
	float fConst3;
	float fRec3[2];
	float fConst4;
	float fRec4[2];
	float fConst5;
	float fRec5[2];
	FAUSTFLOAT fHslider0;
	float fRec6[2];
	float fRec1[2];
	int iRec9[2];
	float fVec1[2];
	float fConst6;
	float fConst7;
	float fRec10[2];
	float fRec8[2];
	float fRec7[3];
	float fConst11;
	float fConst13;
	float fRec12[3];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec11[3];
	float fConst17;
	float fConst19;
	float fConst20;
	float fConst23;
	float fConst25;
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec15[2];
	float fConst30;
	float fConst31;
	float fRec14[3];
	float fConst32;
	float fVec2[2];
	float fRec13[2];
	float fVec3[2];
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec16[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "waterfall.dsp");
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
		m->declare("name", "waterfall");
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
		FaustWaterfallDSPSIG0* sig0 = newFaustWaterfallDSPSIG0();
		sig0->instanceInitFaustWaterfallDSPSIG0(sample_rate);
		sig0->fillFaustWaterfallDSPSIG0(65536, ftbl0FaustWaterfallDSPSIG0);
		deleteFaustWaterfallDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (0.112999998f / fConst0);
		fConst4 = (0.0710000023f / fConst0);
		fConst5 = (0.0430000015f / fConst0);
		fConst6 = (3.14159274f / fConst0);
		fConst7 = (0.0520000011f / fConst0);
		float fConst8 = std::tan((628.318542f / fConst0));
		float fConst9 = (1.0f / fConst8);
		float fConst10 = (((fConst9 + 1.41421354f) / fConst8) + 1.0f);
		fConst11 = (0.600000024f / fConst10);
		float fConst12 = FaustWaterfallDSP_faustpower2_f(fConst8);
		fConst13 = (1.0f / fConst12);
		fConst14 = (1.0f / fConst10);
		fConst15 = (((fConst9 + -1.41421354f) / fConst8) + 1.0f);
		fConst16 = (2.0f * (1.0f - fConst13));
		fConst17 = (0.0f - (2.0f / fConst12));
		float fConst18 = (1.0f / std::tan((37699.1133f / fConst0)));
		fConst19 = (1.0f / (fConst18 + 1.0f));
		fConst20 = (1.0f - fConst18);
		float fConst21 = std::tan((9424.77832f / fConst0));
		float fConst22 = (1.0f / fConst21);
		fConst23 = (1.0f / (((fConst22 + 1.0f) / fConst21) + 1.0f));
		float fConst24 = FaustWaterfallDSP_faustpower2_f(fConst21);
		fConst25 = (1.0f / fConst24);
		float fConst26 = (fConst22 + 1.0f);
		fConst27 = (1.0f / (fConst21 * fConst26));
		fConst28 = (0.0f - fConst27);
		fConst29 = ((1.0f - fConst22) / fConst26);
		fConst30 = (((fConst22 + -1.0f) / fConst21) + 1.0f);
		fConst31 = (2.0f * (1.0f - fConst25));
		fConst32 = (0.0f - (2.0f / fConst24));
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec9[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec15[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fVec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec13[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec3[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec0[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec16[l20] = 0.0f;
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
	
	virtual FaustWaterfallDSP* clone() {
		return new FaustWaterfallDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("waterfall");
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("size", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = ((float(fButton0) > 0.0f) ? 1.0f : 0.0f);
		float fSlow1 = (fConst1 * float(fHslider0));
		float fSlow2 = (fConst1 * float(fHslider1));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fConst3 + (fRec3[1] - std::floor((fConst3 + fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fConst4 + (fRec4[1] - std::floor((fConst4 + fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fConst5 + (fRec5[1] - std::floor((fConst5 + fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fSlow1 + (fConst2 * fRec6[1]));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((fConst2 * fRec1[1]) + (fConst1 * std::pow((std::max<float>(0.0f, (((0.075000003f * (ftbl0FaustWaterfallDSPSIG0[int((65536.0f * fRec3[0]))] + 1.0f)) + ((0.174999997f * (ftbl0FaustWaterfallDSPSIG0[int((65536.0f * fRec4[0]))] + 1.0f)) + ((0.25f * (ftbl0FaustWaterfallDSPSIG0[int((65536.0f * fRec5[0]))] + 1.0f)) + (0.400000006f * fRec6[0])))) + -0.600000024f)) / ((0.400000006f * (fRec6[0] + 1.0f)) + 0.00100000005f)), 2.5f)));
			fRec1[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			iRec9[0] = ((1103515245 * iRec9[1]) + 12345);
			float fTemp0 = float(iRec9[0]);
			fVec1[0] = fTemp0;
			float fTempFTZ5 = (fConst7 + (fRec10[1] - std::floor((fConst7 + fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp1 = ((0.200000003f * ftbl0FaustWaterfallDSPSIG0[int((65536.0f * fRec10[0]))]) + 1.0f);
			float fTemp2 = std::tan((fConst6 * std::max<float>(40.0f, (((220.0f * fRec6[0]) + 80.0f) * fTemp1))));
			float fTemp3 = (1.0f / fTemp2);
			float fTempFTZ6 = (((4.65661287e-10f * (fTemp0 + fVec1[1])) - (fRec8[1] * (1.0f - fTemp3))) / (fTemp3 + 1.0f));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp4 = (((fTemp3 + 1.0f) / fTemp2) + 1.0f);
			float fTempFTZ7 = (fRec8[0] - (((fRec7[2] * (((fTemp3 + -1.0f) / fTemp2) + 1.0f)) + (2.0f * (fRec7[1] * (1.0f - (1.0f / FaustWaterfallDSP_faustpower2_f(fTemp2)))))) / fTemp4));
			fRec7[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp5 = std::tan((fConst6 * std::max<float>(300.0f, (fTemp1 * ((1500.0f * fRec6[0]) + 1000.0f)))));
			float fTemp6 = (1.0f / fTemp5);
			float fTemp7 = (((fTemp6 + 1.41421354f) / fTemp5) + 1.0f);
			float fTempFTZ8 = ((4.65661287e-10f * fTemp0) - (((fRec12[2] * (((fTemp6 + -1.41421354f) / fTemp5) + 1.0f)) + (2.0f * (fRec12[1] * (1.0f - (1.0f / FaustWaterfallDSP_faustpower2_f(fTemp5)))))) / fTemp7));
			fRec12[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (((fRec12[2] + (fRec12[0] + (2.0f * fRec12[1]))) / fTemp7) - (fConst14 * ((fConst15 * fRec11[2]) + (fConst16 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = ((4.65661287e-10f * ((fConst27 * fTemp0) + (fConst28 * fVec1[1]))) - (fConst29 * fRec15[1]));
			fRec15[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fRec15[0] - (fConst23 * ((fConst30 * fRec14[2]) + (fConst31 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp8 = (((fConst25 * fRec14[0]) + (fConst32 * fRec14[1])) + (fConst25 * fRec14[2]));
			fVec2[0] = fTemp8;
			float fTempFTZ12 = (0.0f - (fConst19 * ((fConst20 * fRec13[1]) - (fConst23 * (fTemp8 + fVec2[1])))));
			fRec13[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp9 = (fRec1[0] * (((((fRec7[2] + (fRec7[0] + (2.0f * fRec7[1]))) * ((0.699999988f * fRec6[0]) + 0.0500000007f)) / fTemp4) + (fConst11 * (((fConst13 * fRec11[0]) + (fConst17 * fRec11[1])) + (fConst13 * fRec11[2])))) + (fRec13[0] * ((0.25f * (1.0f - fRec6[0])) + 0.150000006f))));
			fVec3[0] = fTemp9;
			float fTempFTZ13 = (((0.995000005f * fRec0[1]) + fTemp9) - fVec3[1]);
			fRec0[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fSlow2 + (fConst2 * fRec16[1]));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			output0[i0] = FAUSTFLOAT(((fSlow0 * fRec0[0]) * fRec16[0]));
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec1[1] = fRec1[0];
			iRec9[1] = iRec9[0];
			fVec1[1] = fVec1[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fVec2[1] = fVec2[0];
			fRec13[1] = fRec13[0];
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
			fRec16[1] = fRec16[0];
		}
	}

};

#endif
