/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "harmonium"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustHarmoniumDSP_H__
#define  __FaustHarmoniumDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustHarmoniumDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec2[2];
	
  public:
	
	int getNumInputsFaustHarmoniumDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustHarmoniumDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustHarmoniumDSPSIG0(int sample_rate) {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec2[l2] = 0;
		}
	}
	
	void fillFaustHarmoniumDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec2[0] = ((iVec1[1] + iRec2[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec2[0])));
			iVec1[1] = iVec1[0];
			iRec2[1] = iRec2[0];
		}
	}

};

static FaustHarmoniumDSPSIG0* newFaustHarmoniumDSPSIG0() { return (FaustHarmoniumDSPSIG0*)new FaustHarmoniumDSPSIG0(); }
static void deleteFaustHarmoniumDSPSIG0(FaustHarmoniumDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustHarmoniumDSPSIG0[65536];
static float FaustHarmoniumDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustHarmoniumDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustHarmoniumDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	FAUSTFLOAT fHslider2;
	float fConst6;
	float fRec3[2];
	float fRec1[2];
	float fConst7;
	float fRec4[2];
	float fConst8;
	int iRec5[2];
	float fConst9;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst10;
	float fRec8[2];
	float fRec6[2];
	FAUSTFLOAT fHslider5;
	float fRec9[2];
	float fRec11[2];
	float fConst11;
	float fConst12;
	float fConst13;
	float fRec0[3];
	float fConst17;
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec13[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec14[3];
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec15[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "harmonium.dsp");
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
		m->declare("name", "harmonium");
		m->declare("options", "[nvoices:6]");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
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
		FaustHarmoniumDSPSIG0* sig0 = newFaustHarmoniumDSPSIG0();
		sig0->instanceInitFaustHarmoniumDSPSIG0(sample_rate);
		sig0->fillFaustHarmoniumDSPSIG0(65536, ftbl0FaustHarmoniumDSPSIG0);
		deleteFaustHarmoniumDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((3926.99072f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.400000006f) / fConst1) + 1.0f);
		fConst4 = (0.349999994f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		fConst6 = (0.600000024f / fConst0);
		fConst7 = (1.0f / std::max<float>(1.0f, (0.0199999996f * fConst0)));
		fConst8 = (1.0f / std::max<float>(1.0f, (0.200000003f * fConst0)));
		fConst9 = (1.0f / fConst0);
		fConst10 = (6.5f / fConst0);
		fConst11 = (1.0f / fConst3);
		fConst12 = (((fConst2 + -0.400000006f) / fConst1) + 1.0f);
		fConst13 = (2.0f * (1.0f - (1.0f / FaustHarmoniumDSP_faustpower2_f(fConst1))));
		float fConst14 = std::tan((2136.28296f / fConst0));
		float fConst15 = (1.0f / fConst14);
		float fConst16 = (((fConst15 + 0.285714298f) / fConst14) + 1.0f);
		fConst17 = (0.5f / (fConst14 * fConst16));
		fConst18 = (0.0f - fConst17);
		fConst19 = (1.0f / fConst16);
		fConst20 = (((fConst15 + -0.285714298f) / fConst14) + 1.0f);
		fConst21 = (2.0f * (1.0f - (1.0f / FaustHarmoniumDSP_faustpower2_f(fConst14))));
		float fConst22 = std::tan((1068.14148f / fConst0));
		float fConst23 = (1.0f / fConst22);
		float fConst24 = (((fConst23 + 0.25f) / fConst22) + 1.0f);
		fConst25 = (0.550000012f / (fConst22 * fConst24));
		fConst26 = (0.0f - fConst25);
		fConst27 = (1.0f / fConst24);
		fConst28 = (((fConst23 + -0.25f) / fConst22) + 1.0f);
		fConst29 = (2.0f * (1.0f - (1.0f / FaustHarmoniumDSP_faustpower2_f(fConst22))));
		float fConst30 = std::tan((424.115021f / fConst0));
		float fConst31 = (1.0f / fConst30);
		float fConst32 = (((fConst31 + 0.333333343f) / fConst30) + 1.0f);
		fConst33 = (0.400000006f / (fConst30 * fConst32));
		fConst34 = (0.0f - fConst33);
		fConst35 = (1.0f / fConst32);
		fConst36 = (((fConst31 + -0.333333343f) / fConst30) + 1.0f);
		fConst37 = (2.0f * (1.0f - (1.0f / FaustHarmoniumDSP_faustpower2_f(fConst30))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.69999999999999996f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(440.0f);
		fHslider4 = FAUSTFLOAT(0.25f);
		fHslider5 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec5[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec11[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec0[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec14[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec15[l14] = 0.0f;
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
	
	virtual FaustHarmoniumDSP* clone() {
		return new FaustHarmoniumDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("harmonium");
		ui_interface->addHorizontalSlider("bellows_growl", &fHslider4, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(440.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("pressure", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("reed_octaves", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (1.02900004f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fButton0);
		float fSlow3 = (0.99970001f - (0.0799999982f * (fSlow2 * fSlow1)));
		float fSlow4 = float(fHslider2);
		int iSlow5 = (fSlow2 == 0.0f);
		float fSlow6 = float(fHslider3);
		float fSlow7 = (0.0120000001f * (float(fHslider4) * fSlow1));
		float fSlow8 = (3.5f * fSlow1);
		float fSlow9 = float(fHslider5);
		float fSlow10 = (0.449999988f * std::min<float>(1.0f, fSlow9));
		float fSlow11 = (2.0f * fSlow6);
		float fSlow12 = (2.0999999f * fSlow1);
		float fSlow13 = (0.5f * std::max<float>(0.0f, (fSlow9 + -1.0f)));
		float fSlow14 = (0.5f * fSlow6);
		float fSlow15 = (2.79999995f * fSlow1);
		float fSlow16 = (0.180000007f * fSlow1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow2;
			float fTempFTZ0 = (fConst6 + (fRec3[1] - std::floor((fConst6 + fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (std::min<float>(1.0f, std::max<float>(0.0f, (fSlow3 * fRec1[1]))) + (fSlow4 * ((0.25f * (ftbl0FaustHarmoniumDSPSIG0[int((65536.0f * fRec3[0]))] + 1.0f)) + 0.5f)));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow2 + (fRec4[1] * float((fVec0[1] >= fSlow2))));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			iRec5[0] = (iSlow5 * (iRec5[1] + 1));
			float fTemp0 = (fRec1[0] * std::max<float>(0.0f, (std::min<float>((fConst7 * fRec4[0]), 1.0f) - (fConst8 * float(iRec5[0])))));
			float fTempFTZ3 = (fConst10 + (fRec8[1] - std::floor((fConst10 + fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp1 = ((fSlow7 * (fTemp0 * ((0.300000012f * ftbl0FaustHarmoniumDSPSIG0[int((65536.0f * fRec8[0]))]) + 0.699999988f))) + 1.0f);
			float fTemp2 = std::max<float>(1.1920929e-07f, std::fabs((fSlow6 * fTemp1)));
			float fTemp3 = (fRec6[1] + (fConst9 * fTemp2));
			float fTemp4 = (fTemp3 + -1.0f);
			int iTemp5 = (fTemp4 < 0.0f);
			float fTempFTZ4 = (iTemp5 ? fTemp3 : fTemp4);
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fThen1 = (fTemp3 + (fTemp4 * (1.0f - (fConst0 / fTemp2))));
			float fTempFTZ5 = (iTemp5 ? fTemp3 : fThen1);
			float fRec7 = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp6 = std::max<float>(1.1920929e-07f, std::fabs((fSlow11 * fTemp1)));
			float fTemp7 = (fRec9[1] + (fConst9 * fTemp6));
			float fTemp8 = (fTemp7 + -1.0f);
			int iTemp9 = (fTemp8 < 0.0f);
			float fTempFTZ6 = (iTemp9 ? fTemp7 : fTemp8);
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fThen3 = (fTemp7 + (fTemp8 * (1.0f - (fConst0 / fTemp6))));
			float fTempFTZ7 = (iTemp9 ? fTemp7 : fThen3);
			float fRec10 = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp10 = std::max<float>(1.1920929e-07f, std::fabs((fSlow14 * fTemp1)));
			float fTemp11 = (fRec11[1] + (fConst9 * fTemp10));
			float fTemp12 = (fTemp11 + -1.0f);
			int iTemp13 = (fTemp12 < 0.0f);
			float fTempFTZ8 = (iTemp13 ? fTemp11 : fTemp12);
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fThen5 = (fTemp11 + (fTemp12 * (1.0f - (fConst0 / fTemp10))));
			float fTempFTZ9 = (iTemp13 ? fTemp11 : fThen5);
			float fRec12 = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp14 = (fTemp0 * (((0.600000024f * float(tanhf(float((((2.0f * fRec7) + -1.0f) * ((fSlow8 * fTemp0) + 1.5f)))))) + (fSlow10 * float(tanhf(float((((2.0f * fRec10) + -1.0f) * ((fSlow12 * fTemp0) + 1.5f))))))) + (fSlow13 * float(tanhf(float((((2.0f * fRec12) + -1.0f) * ((fSlow15 * fTemp0) + 1.5f))))))));
			float fTemp15 = (fSlow1 * fTemp14);
			float fTempFTZ10 = (fTemp15 - (fConst11 * ((fConst12 * fRec0[2]) + (fConst13 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp15 - (fConst19 * ((fConst20 * fRec13[2]) + (fConst21 * fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fTemp15 - (fConst27 * ((fConst28 * fRec14[2]) + (fConst29 * fRec14[1]))));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp15 - (fConst35 * ((fConst36 * fRec15[2]) + (fConst37 * fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * ((fConst5 * fRec0[2]) + (((fConst18 * fRec13[2]) + (((fConst26 * fRec14[2]) + (((fConst34 * fRec15[2]) + ((fSlow16 * fTemp14) + (fConst33 * fRec15[0]))) + (fConst25 * fRec14[0]))) + (fConst17 * fRec13[0]))) + (fConst4 * fRec0[0])))));
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			iRec5[1] = iRec5[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
		}
	}

};

#endif
