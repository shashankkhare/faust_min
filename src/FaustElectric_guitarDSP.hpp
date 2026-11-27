/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "electric_guitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustElectric_guitarDSP_H__
#define  __FaustElectric_guitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustElectric_guitarDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustElectric_guitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustElectric_guitarDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst4;
	FAUSTFLOAT fHslider0;
	float fConst9;
	float fConst10;
	float fConst13;
	float fConst15;
	FAUSTFLOAT fHslider1;
	float fConst16;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fConst17;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec7[2];
	int iRec8[2];
	float fVec1[2];
	float fRec6[2];
	FAUSTFLOAT fHslider5;
	float fRec10[2];
	float fVec2[2];
	float fRec9[2];
	float fConst18;
	float fConst19;
	FAUSTFLOAT fHslider6;
	float fRec11[2];
	int IOTA;
	float fRec5[4096];
	FAUSTFLOAT fHslider7;
	float fRec14[2];
	float fVec3[2];
	float fRec13[2];
	float fRec12[4096];
	float fVec4[2048];
	float fVec5[2];
	float fRec4[2];
	float fVec6[2];
	float fRec3[2];
	float fConst20;
	float fConst21;
	float fRec2[3];
	float fConst22;
	float fConst23;
	float fRec1[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec0[3];
	float fConst30;
	float fRec15[2];
	float fConst31;
	int iRec16[2];
	
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
		m->declare("filename", "electric_guitar.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/peak_eq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/peak_eq_cq:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq_cq:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq_cq:license", "MIT-style STK-4.3 license");
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
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "electric_guitar");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((11938.0518f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 1.41421354f) / fConst1) + 1.0f);
		fConst4 = (10.8000002f / fConst3);
		float fConst5 = std::tan((3455.75195f / fConst0));
		float fConst6 = (1.0f / fConst5);
		float fConst7 = (fConst0 * std::sin((6911.50391f / fConst0)));
		float fConst8 = (3141.59277f / fConst7);
		fConst9 = (1.0f / (((fConst6 + fConst8) / fConst5) + 1.0f));
		fConst10 = (2.0f * (1.0f - (1.0f / FaustElectric_guitarDSP_faustpower2_f(fConst5))));
		float fConst11 = std::tan((267.03537f / fConst0));
		float fConst12 = (1.0f / fConst11);
		fConst13 = (1.0f / (((fConst12 + 1.41421354f) / fConst11) + 1.0f));
		float fConst14 = FaustElectric_guitarDSP_faustpower2_f(fConst11);
		fConst15 = (1.0f / fConst14);
		fConst16 = (3.14159274f / fConst0);
		fConst17 = (1.20000005f * fConst0);
		fConst18 = std::exp((0.0f - (166.666672f / fConst0)));
		fConst19 = (1.0f - fConst18);
		fConst20 = (((fConst12 + -1.41421354f) / fConst11) + 1.0f);
		fConst21 = (2.0f * (1.0f - fConst15));
		fConst22 = (0.0f - (2.0f / fConst14));
		fConst23 = (((fConst6 - fConst8) / fConst5) + 1.0f);
		float fConst24 = (3955.03076f / fConst7);
		fConst25 = (((fConst6 + fConst24) / fConst5) + 1.0f);
		fConst26 = (((fConst6 - fConst24) / fConst5) + 1.0f);
		fConst27 = (1.0f / fConst3);
		fConst28 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst29 = (2.0f * (1.0f - (1.0f / FaustElectric_guitarDSP_faustpower2_f(fConst1))));
		fConst30 = (1.0f / std::max<float>(1.0f, (0.00100000005f * fConst0)));
		fConst31 = (1.0f / std::max<float>(1.0f, (0.0399999991f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.17999999999999999f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(196.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(0.34999999999999998f);
		fHslider7 = FAUSTFLOAT(0.78000000000000003f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec7[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec8[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec10[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec9[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec11[l8] = 0.0f;
		}
		IOTA = 0;
		for (int l9 = 0; (l9 < 4096); l9 = (l9 + 1)) {
			fRec5[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec14[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 4096); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2048); l14 = (l14 + 1)) {
			fVec4[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec4[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fVec6[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec3[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec2[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec1[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec0[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec15[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			iRec16[l23] = 0;
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
	
	virtual FaustElectric_guitarDSP* clone() {
		return new FaustElectric_guitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("electric_guitar");
		ui_interface->addHorizontalSlider("calibration", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-100.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("drive", &fHslider1, FAUSTFLOAT(0.180000007f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(196.0f), FAUSTFLOAT(82.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mute", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("pluckPosition", &fHslider7, FAUSTFLOAT(0.779999971f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.949999988f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider6, FAUSTFLOAT(0.349999994f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst4 * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (((2.5f * fSlow1) + 1.0f) * std::pow(10.0f, (0.899999976f * fSlow1)));
		float fSlow3 = float(fHslider2);
		float fSlow4 = (1.0f / std::tan((fConst16 * ((5500.0f * fSlow3) + 1400.0f))));
		float fSlow5 = (1.0f / (fSlow4 + 1.0f));
		float fSlow6 = (1.0f - fSlow4);
		float fSlow7 = float(fButton0);
		float fSlow8 = (float(fHslider3) * std::pow(2.0f, (0.000833333354f * float(fHslider4))));
		float fSlow9 = std::max<float>(8.0f, std::min<float>(192.0f, (fConst17 / fSlow8)));
		float fSlow10 = (1.0f / fSlow9);
		float fSlow11 = (4.65661287e-10f * ((0.349999994f * fSlow3) + 0.25f));
		float fSlow12 = ((0.800000012f * float(fHslider5)) + 0.200000003f);
		float fSlow13 = (1.0f / std::tan((fConst16 * std::min<float>(14000.0f, ((7.0f * fSlow8) + 3200.0f)))));
		float fSlow14 = (1.0f / (fSlow13 + 1.0f));
		float fSlow15 = (1.0f - fSlow13);
		float fSlow16 = (0.0500000007f * std::max<float>(0.0f, (1.0f - (0.000454545458f * fSlow8))));
		float fSlow17 = std::sin(fSlow16);
		float fSlow18 = std::max<float>(2.0f, ((fConst0 / fSlow8) + -2.5f));
		float fSlow19 = std::floor(fSlow18);
		float fSlow20 = (fSlow19 + (1.0f - fSlow18));
		int iSlow21 = int(fSlow18);
		int iSlow22 = (std::min<int>(4097, std::max<int>(0, iSlow21)) + 1);
		float fSlow23 = (fSlow18 - fSlow19);
		int iSlow24 = (std::min<int>(4097, std::max<int>(0, (iSlow21 + 1))) + 1);
		float fSlow25 = std::cos(fSlow16);
		float fElse1 = ((2.79999995f * float(fHslider6)) + 1.60000002f);
		float fSlow26 = (fConst19 * ((fSlow7 > 0.0f) ? fElse1 : 0.0350000001f));
		float fSlow27 = std::max<float>(1.5f, (fConst0 * ((1.0f - float(fHslider7)) / fSlow8)));
		float fSlow28 = std::floor(fSlow27);
		float fSlow29 = (fSlow28 + (1.0f - fSlow27));
		float fSlow30 = (1.00059998f * fSlow18);
		float fSlow31 = std::floor(fSlow30);
		float fSlow32 = (fSlow31 + (1.0f - fSlow30));
		int iSlow33 = int(fSlow30);
		int iSlow34 = (std::min<int>(4097, std::max<int>(0, iSlow33)) + 1);
		float fSlow35 = (fSlow30 - fSlow31);
		int iSlow36 = (std::min<int>(4097, std::max<int>(0, (iSlow33 + 1))) + 1);
		int iSlow37 = int(fSlow27);
		int iSlow38 = std::min<int>(1025, std::max<int>(0, iSlow37));
		float fSlow39 = (fSlow27 - fSlow28);
		int iSlow40 = std::min<int>(1025, std::max<int>(0, (iSlow37 + 1)));
		int iSlow41 = (fSlow7 == 0.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow7;
			float fThen0 = std::max<float>(0.0f, (fRec7[1] + -1.0f));
			float fTempFTZ0 = ((float(((fSlow7 - fVec0[1]) > 0.0f)) > 0.0f) ? fSlow9 : fThen0);
			fRec7[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec8[0] = ((1103515245 * iRec8[1]) + 12345);
			float fTemp0 = (fSlow3 * ((float((fRec7[0] > 0.0f)) * std::sin((3.14159274f * (1.0f - (fSlow10 * fRec7[0]))))) * ((fSlow11 * float(iRec8[0])) + 0.75f)));
			fVec1[0] = fTemp0;
			float fTempFTZ1 = (0.0f - (fSlow5 * ((fSlow6 * fRec6[1]) - (fTemp0 + fVec1[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp1 = ((fSlow20 * fRec5[((IOTA - iSlow22) & 4095)]) + (fSlow23 * fRec5[((IOTA - iSlow24) & 4095)]));
			float fTempFTZ2 = ((fSlow25 * fTemp1) - (fSlow17 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp2 = ((fSlow17 * fTemp1) + (fSlow25 * fRec10[1]));
			fVec2[0] = fTemp2;
			float fTempFTZ3 = (0.0f - (fSlow14 * ((fSlow15 * fRec9[1]) - (fTemp2 + fVec2[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((fConst18 * fRec11[1]) + fSlow26);
			fRec11[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp3 = std::pow(0.00100000005f, (1.0f / std::max<float>(1.0f, (fSlow8 * fRec11[0]))));
			float fTempFTZ5 = (fRec6[0] + (fSlow12 * (fRec9[0] * fTemp3)));
			fRec5[(IOTA & 4095)] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp4 = fRec5[((IOTA - 0) & 4095)];
			float fTemp5 = ((fSlow32 * fRec12[((IOTA - iSlow34) & 4095)]) + (fSlow35 * fRec12[((IOTA - iSlow36) & 4095)]));
			float fTempFTZ6 = ((fSlow25 * fTemp5) - (fSlow17 * fRec14[1]));
			fRec14[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp6 = ((fSlow17 * fTemp5) + (fSlow25 * fRec14[1]));
			fVec3[0] = fTemp6;
			float fTempFTZ7 = (0.0f - (fSlow14 * ((fSlow15 * fRec13[1]) - (fTemp6 + fVec3[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fRec6[0] + (fSlow12 * (fRec13[0] * fTemp3)));
			fRec12[(IOTA & 4095)] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp7 = (0.25f * fRec12[((IOTA - 0) & 4095)]);
			float fTemp8 = ((0.75f * fTemp4) + fTemp7);
			fVec4[(IOTA & 2047)] = fTemp8;
			float fTemp9 = (0.75f * (fTemp4 - ((fSlow29 * fVec4[((IOTA - iSlow38) & 2047)]) + (fSlow39 * fVec4[((IOTA - iSlow40) & 2047)]))));
			fVec5[0] = (fTemp7 + fTemp9);
			float fTempFTZ9 = ((fTemp9 + ((0.995000005f * fRec4[1]) + fTemp7)) - fVec5[1]);
			fRec4[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp10 = std::max<float>(-1.0f, std::min<float>(1.0f, ((fSlow2 * fRec4[0]) + 0.0599999987f)));
			float fTemp11 = (fTemp10 * (1.0f - (0.333333343f * FaustElectric_guitarDSP_faustpower2_f(fTemp10))));
			fVec6[0] = fTemp11;
			float fTempFTZ10 = (((0.995000005f * fRec3[1]) + fTemp11) - fVec6[1]);
			fRec3[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fRec3[0] - (fConst13 * ((fConst20 * fRec2[2]) + (fConst21 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp12 = (fConst10 * fRec1[1]);
			float fTempFTZ12 = ((fConst13 * (((fConst15 * fRec2[0]) + (fConst22 * fRec2[1])) + (fConst15 * fRec2[2]))) - (fConst9 * ((fConst23 * fRec1[2]) + fTemp12)));
			fRec1[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = ((fConst9 * ((fTemp12 + (fConst25 * fRec1[0])) + (fConst26 * fRec1[2]))) - (fConst27 * ((fConst28 * fRec0[2]) + (fConst29 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fSlow7 + (fRec15[1] * float((fVec0[1] >= fSlow7))));
			fRec15[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			iRec16[0] = (iSlow41 * (iRec16[1] + 1));
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * ((fRec0[2] + (fRec0[0] + (2.0f * fRec0[1]))) * std::max<float>(0.0f, (std::min<float>((fConst30 * fRec15[0]), 1.0f) - (fConst31 * float(iRec16[0]))))))))));
			fVec0[1] = fVec0[0];
			fRec7[1] = fRec7[0];
			iRec8[1] = iRec8[0];
			fVec1[1] = fVec1[0];
			fRec6[1] = fRec6[0];
			fRec10[1] = fRec10[0];
			fVec2[1] = fVec2[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			IOTA = (IOTA + 1);
			fRec14[1] = fRec14[0];
			fVec3[1] = fVec3[0];
			fRec13[1] = fRec13[0];
			fVec5[1] = fVec5[0];
			fRec4[1] = fRec4[0];
			fVec6[1] = fVec6[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec15[1] = fRec15[0];
			iRec16[1] = iRec16[0];
		}
	}

};

#endif
