/* ------------------------------------------------------------
name: "seawave"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSeawaveDSP_H__
#define  __FaustSeawaveDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustSeawaveDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec1[2];
	
  public:
	
	int getNumInputsFaustSeawaveDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSeawaveDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSeawaveDSPSIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec1[l1] = 0;
		}
	}
	
	void fillFaustSeawaveDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec1[0] = ((iVec0[1] + iRec1[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec1[0])));
			iVec0[1] = iVec0[0];
			iRec1[1] = iRec1[0];
		}
	}

};

static FaustSeawaveDSPSIG0* newFaustSeawaveDSPSIG0() { return (FaustSeawaveDSPSIG0*)new FaustSeawaveDSPSIG0(); }
static void deleteFaustSeawaveDSPSIG0(FaustSeawaveDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustSeawaveDSPSIG0[65536];
static float FaustSeawaveDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustSeawaveDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float FaustSeawaveDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSeawaveDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSeawaveDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fButton0;
	int fSampleRate;
	float fConst1;
	float fRec2[2];
	float fConst2;
	float fRec3[2];
	float fConst3;
	float fRec4[2];
	float fConst4;
	float fRec5[2];
	float fConst5;
	FAUSTFLOAT fHslider0;
	float fConst6;
	float fRec6[2];
	float fVec1[2];
	int iRec8[2];
	float fVec2[2];
	float fConst7;
	float fConst8;
	float fRec9[2];
	float fRec7[3];
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst15;
	float fConst17;
	float fConst18;
	float fRec11[3];
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	float fRec10[5];
	float fConst26;
	float fConst28;
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec13[2];
	float fConst33;
	float fConst34;
	float fRec12[3];
	float fConst35;
	float fConst39;
	float fConst41;
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec15[2];
	float fConst46;
	float fConst47;
	float fConst48;
	float fRec14[3];
	float fConst49;
	float fVec3[2];
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec16[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("filename", "seawave.dsp");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/tf1sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "seawave");
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
		FaustSeawaveDSPSIG0* sig0 = newFaustSeawaveDSPSIG0();
		sig0->instanceInitFaustSeawaveDSPSIG0(sample_rate);
		sig0->fillFaustSeawaveDSPSIG0(65536, ftbl0FaustSeawaveDSPSIG0);
		deleteFaustSeawaveDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (0.108999997f / fConst0);
		fConst2 = (0.0790000036f / fConst0);
		fConst3 = (0.0309999995f / fConst0);
		fConst4 = (0.0529999994f / fConst0);
		fConst5 = (44.0999985f / fConst0);
		fConst6 = (1.0f - fConst5);
		fConst7 = (3.14159274f / fConst0);
		fConst8 = (0.0430000015f / fConst0);
		fConst9 = (1.0f / fConst0);
		fConst10 = FaustSeawaveDSP_faustpower2_f(fConst9);
		fConst11 = (0.5f * fConst10);
		fConst12 = (2.0f / fConst0);
		fConst13 = (2.0f * fConst10);
		float fConst14 = std::tan((1.88495564f / fConst0));
		fConst15 = (4.0f * (FaustSeawaveDSP_faustpower2_f(fConst0) * fConst14));
		float fConst16 = (fConst0 * fConst14);
		fConst17 = (2.0f * fConst16);
		fConst18 = (0.5f / fConst16);
		fConst19 = FaustSeawaveDSP_faustpower3_f(fConst9);
		fConst20 = (4.0f * fConst9);
		fConst21 = (16.0f / fConst0);
		fConst22 = (6.0f * fConst10);
		fConst23 = (8.0f / fConst0);
		float fConst24 = std::tan((12566.3711f / fConst0));
		float fConst25 = (1.0f / fConst24);
		fConst26 = (1.0f / (((fConst25 + 1.0f) / fConst24) + 1.0f));
		float fConst27 = FaustSeawaveDSP_faustpower2_f(fConst24);
		fConst28 = (1.0f / fConst27);
		float fConst29 = (fConst25 + 1.0f);
		fConst30 = (1.0f / (fConst24 * fConst29));
		fConst31 = (0.0f - fConst30);
		fConst32 = ((1.0f - fConst25) / fConst29);
		fConst33 = (((fConst25 + -1.0f) / fConst24) + 1.0f);
		fConst34 = (2.0f * (1.0f - fConst28));
		fConst35 = (0.0f - (2.0f / fConst27));
		float fConst36 = std::tan((6283.18555f / fConst0));
		float fConst37 = (1.0f / fConst36);
		float fConst38 = (((fConst37 + 1.0f) / fConst36) + 1.0f);
		fConst39 = (8.0f / fConst38);
		float fConst40 = FaustSeawaveDSP_faustpower2_f(fConst36);
		fConst41 = (1.0f / fConst40);
		float fConst42 = (fConst37 + 1.0f);
		fConst43 = (1.0f / (fConst36 * fConst42));
		fConst44 = (0.0f - fConst43);
		fConst45 = ((1.0f - fConst37) / fConst42);
		fConst46 = (1.0f / fConst38);
		fConst47 = (((fConst37 + -1.0f) / fConst36) + 1.0f);
		fConst48 = (2.0f * (1.0f - fConst41));
		fConst49 = (0.0f - (2.0f / fConst40));
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec8[l8] = 0;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 5); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec12[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec14[l17] = 0.0f;
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
	
	virtual FaustSeawaveDSP* clone() {
		return new FaustSeawaveDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("seawave");
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("intensity", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = ((float(fButton0) > 0.0f) ? 1.0f : 0.0f);
		float fSlow1 = (fConst5 * float(fHslider0));
		float fSlow2 = (fConst5 * float(fHslider1));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fConst1 + (fRec2[1] - std::floor((fConst1 + fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fConst2 + (fRec3[1] - std::floor((fConst2 + fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fConst3 + (fRec4[1] - std::floor((fConst3 + fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fConst4 + (fRec5[1] - std::floor((fConst4 + fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow1 + (fConst6 * fRec6[1]));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp0 = (0.400000006f * fRec6[0]);
			float fTemp1 = std::pow((std::max<float>(0.0f, (((0.075000003f * (ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec2[0]))] + 1.0f)) + ((0.125f * (ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec3[0]))] + 1.0f)) + ((0.150000006f * ((ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec4[0]))] + 1.0f) + (ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec5[0]))] + 1.0f))) + fTemp0))) + -0.550000012f)) / (fTemp0 + 0.451000005f)), 2.0f);
			fVec1[0] = fTemp1;
			iRec8[0] = ((1103515245 * iRec8[1]) + 12345);
			float fTemp2 = float(iRec8[0]);
			fVec2[0] = fTemp2;
			float fTemp3 = (4.65661287e-10f * fTemp2);
			float fTempFTZ5 = (fConst8 + (fRec9[1] - std::floor((fConst8 + fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp4 = ((0.25f * ftbl0FaustSeawaveDSPSIG0[int((65536.0f * fRec9[0]))]) + 1.0f);
			float fTemp5 = std::tan((fConst7 * (((120.0f * fRec6[0]) + 30.0f) * fTemp4)));
			float fTemp6 = (1.0f / fTemp5);
			float fTemp7 = (((fTemp6 + 1.41421354f) / fTemp5) + 1.0f);
			float fTempFTZ6 = (fTemp3 - (((fRec7[2] * (((fTemp6 + -1.41421354f) / fTemp5) + 1.0f)) + (2.0f * (fRec7[1] * (1.0f - (1.0f / FaustSeawaveDSP_faustpower2_f(fTemp5)))))) / fTemp7));
			fRec7[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp8 = std::sqrt((fConst15 * std::tan((fConst7 * (fTemp4 * ((1600.0f * fRec6[0]) + 400.0f))))));
			float fTemp9 = FaustSeawaveDSP_faustpower2_f(fTemp8);
			float fTemp10 = (fConst10 * fTemp9);
			float fTemp11 = (fConst17 - (fConst18 * fTemp9));
			float fTemp12 = (fConst12 * fTemp11);
			float fTemp13 = ((fTemp10 + fTemp12) + 4.0f);
			float fTempFTZ7 = (fTemp3 - (((fRec11[1] * ((fConst13 * fTemp9) + -8.0f)) + (fRec11[2] * (fTemp10 + (4.0f - fTemp12)))) / fTemp13));
			fRec11[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp14 = (4.0f * fTemp11);
			float fTemp15 = (fConst20 * fTemp9);
			float fTemp16 = (fConst21 * fTemp11);
			float fTemp17 = FaustSeawaveDSP_faustpower2_f(fTemp11);
			float fTemp18 = (8.0f * fTemp17);
			float fTemp19 = ((4.0f * fTemp17) + (8.0f * fTemp9));
			float fTemp20 = (fConst9 * fTemp9);
			float fTemp21 = (2.0f * fTemp11);
			float fTemp22 = (fConst23 * fTemp11);
			float fTemp23 = (((fConst10 * (fTemp19 + (fConst9 * (fTemp9 * (fTemp20 + fTemp21))))) + fTemp22) + 16.0f);
			float fTempFTZ8 = (((fConst12 * ((fRec11[0] * fTemp11) / fTemp13)) + (fRec11[2] * (0.0f - (fConst12 * (fTemp11 / fTemp13))))) - (((((fRec10[1] * ((fConst19 * (fTemp9 * (fTemp14 + fTemp15))) + (-64.0f - fTemp16))) + (fRec10[2] * ((fConst10 * ((0.0f - (fTemp18 + (16.0f * fTemp9))) + (fConst22 * FaustSeawaveDSP_faustpower4_f(fTemp8)))) + 96.0f))) + (fRec10[3] * ((fTemp16 + (fConst19 * (fTemp9 * (fTemp15 - fTemp14)))) + -64.0f))) + (fRec10[4] * ((fConst10 * (fTemp19 + (fConst9 * (fTemp9 * (fTemp20 - fTemp21))))) + (16.0f - fTemp22)))) / fTemp23));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((4.65661287e-10f * ((fConst30 * fTemp2) + (fConst31 * fVec2[1]))) - (fConst32 * fRec13[1]));
			fRec13[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fRec13[0] - (fConst26 * ((fConst33 * fRec12[2]) + (fConst34 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = ((4.65661287e-10f * ((fConst43 * fTemp2) + (fConst44 * fVec2[1]))) - (fConst45 * fRec15[1]));
			fRec15[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fRec15[0] - (fConst46 * ((fConst47 * fRec14[2]) + (fConst48 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp24 = (fTemp1 * ((((((fRec7[2] + (fRec7[0] + (2.0f * fRec7[1]))) * ((0.600000024f * fRec6[0]) + 0.200000003f)) / fTemp7) + (fConst11 * ((((fRec10[2] * (0.0f - fTemp18)) + (4.0f * (fRec10[0] * fTemp17))) + (4.0f * (fTemp17 * fRec10[4]))) / fTemp23))) + (fConst26 * ((((fConst28 * fRec12[0]) + (fConst35 * fRec12[1])) + (fConst28 * fRec12[2])) * ((0.200000003f * fRec6[0]) + 0.0500000007f)))) + (fConst39 * (((((fConst41 * fRec14[0]) + (fConst49 * fRec14[1])) + (fConst41 * fRec14[2])) * std::max<float>(0.0f, (fTemp1 - fVec1[1]))) * ((0.5f * fRec6[0]) + 0.100000001f)))));
			fVec3[0] = fTemp24;
			float fTempFTZ13 = (((0.995000005f * fRec0[1]) + fTemp24) - fVec3[1]);
			fRec0[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fSlow2 + (fConst6 * fRec16[1]));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			output0[i0] = FAUSTFLOAT(((fSlow0 * fRec0[0]) * fRec16[0]));
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			iRec8[1] = iRec8[0];
			fVec2[1] = fVec2[0];
			fRec9[1] = fRec9[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec10[j0] = fRec10[(j0 - 1)];
			}
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
			fRec16[1] = fRec16[0];
		}
	}

};

#endif
