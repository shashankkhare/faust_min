/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "bayan"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBayanDSP_H__
#define  __FaustBayanDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustBayanDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBayanDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBayanDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst3;
	float fConst5;
	FAUSTFLOAT fHslider1;
	float fConst6;
	FAUSTFLOAT fHslider2;
	float fRec2[2];
	float fConst10;
	float fConst13;
	float fConst15;
	int iRec5[2];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec6[2];
	float fConst16;
	float fConst17;
	float fRec4[3];
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec3[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec7[3];
	int IOTA;
	float fVec1[8192];
	float fConst29;
	FAUSTFLOAT fHslider3;
	float fConst30;
	float fRec8[2];
	FAUSTFLOAT fHslider4;
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec1[3];
	float fRec10[2];
	float fVec2[8192];
	FAUSTFLOAT fHslider5;
	float fRec9[3];
	float fConst34;
	float fConst35;
	float fRec11[3];
	float fConst36;
	float fRec12[3];
	float fConst37;
	float fRec13[3];
	float fConst38;
	float fRec14[3];
	float fConst42;
	float fConst43;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec16[3];
	float fConst44;
	float fConst45;
	float fConst46;
	float fRec15[3];
	float fConst47;
	float fConst48;
	float fRec0[3];
	float fConst49;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "bayan.dsp");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "bayan");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("physics.lib/author", "Shashank Khare");
		m->declare("physics.lib/copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("physics.lib/description", "Reusable acoustic physics formulas for modal and waveguide synthesis.");
		m->declare("physics.lib/name", "Acoustic Physics Library");
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
		float fConst1 = std::tan((78.5398178f / fConst0));
		float fConst2 = (1.0f / fConst1);
		fConst3 = (1.0f / (((fConst2 + 1.41421354f) / fConst1) + 1.0f));
		float fConst4 = FaustBayanDSP_faustpower2_f(fConst1);
		fConst5 = (1.0f / fConst4);
		fConst6 = (3.14159274f / fConst0);
		float fConst7 = std::tan((9424.77832f / fConst0));
		float fConst8 = (1.0f / fConst7);
		float fConst9 = (((fConst8 + 1.41421354f) / fConst7) + 1.0f);
		fConst10 = (1.5f / fConst9);
		float fConst11 = std::tan((628.318542f / fConst0));
		float fConst12 = (1.0f / fConst11);
		fConst13 = (1.0f / (((fConst12 + 1.41421354f) / fConst11) + 1.0f));
		float fConst14 = FaustBayanDSP_faustpower2_f(fConst11);
		fConst15 = (1.0f / fConst14);
		fConst16 = (((fConst12 + -1.41421354f) / fConst11) + 1.0f);
		fConst17 = (2.0f * (1.0f - fConst15));
		fConst18 = (0.0f - (2.0f / fConst14));
		fConst19 = (1.0f / fConst9);
		fConst20 = (((fConst8 + -1.41421354f) / fConst7) + 1.0f);
		fConst21 = (2.0f * (1.0f - (1.0f / FaustBayanDSP_faustpower2_f(fConst7))));
		float fConst22 = std::tan((1884.95557f / fConst0));
		float fConst23 = (1.0f / fConst22);
		float fConst24 = (((fConst23 + 1.41421354f) / fConst22) + 1.0f);
		fConst25 = (1.5f / fConst24);
		fConst26 = (1.0f / fConst24);
		fConst27 = (((fConst23 + -1.41421354f) / fConst22) + 1.0f);
		fConst28 = (2.0f * (1.0f - (1.0f / FaustBayanDSP_faustpower2_f(fConst22))));
		fConst29 = (44.0999985f / fConst0);
		fConst30 = (1.0f - fConst29);
		fConst31 = std::max<float>(1.0f, (0.0799999982f * fConst0));
		fConst32 = (1.0f / fConst31);
		fConst33 = (1.0f / std::max<float>(1.0f, (0.300000012f * fConst0)));
		fConst34 = (1.0f / fConst0);
		fConst35 = (10.0091143f / fConst0);
		fConst36 = (13.4146004f / fConst0);
		fConst37 = (14.4199104f / fConst0);
		fConst38 = (16.6692905f / fConst0);
		float fConst39 = std::tan((942.477783f / fConst0));
		float fConst40 = (1.0f / fConst39);
		float fConst41 = (((fConst40 + 1.41421354f) / fConst39) + 1.0f);
		fConst42 = (0.899999976f / fConst41);
		fConst43 = (171.5f / fConst0);
		fConst44 = (1.0f / fConst41);
		fConst45 = (((fConst40 + -1.41421354f) / fConst39) + 1.0f);
		fConst46 = (2.0f * (1.0f - (1.0f / FaustBayanDSP_faustpower2_f(fConst39))));
		fConst47 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst48 = (2.0f * (1.0f - fConst5));
		fConst49 = (0.0f - (2.0f / fConst4));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(110.0f);
		fHslider4 = FAUSTFLOAT(2.0f);
		fHslider5 = FAUSTFLOAT(1.02f);
		fHslider6 = FAUSTFLOAT(0.12f);
		fHslider7 = FAUSTFLOAT(0.01f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec5[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec6[l3] = 0;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		IOTA = 0;
		for (int l7 = 0; (l7 < 8192); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 8192); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec15[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec0[l19] = 0.0f;
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
	
	virtual FaustBayanDSP* clone() {
		return new FaustBayanDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bayan");
		ui_interface->addHorizontalSlider("bowl_radius", &fHslider6, FAUSTFLOAT(0.119999997f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.200000003f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("bowl_volume", &fHslider7, FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.00499999989f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("eccentricity", &fHslider5, FAUSTFLOAT(1.01999998f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.04999995f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(110.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("meend_inc_freq", &fHslider4, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.899999976f * float(fHslider0));
		int iSlow1 = int((float(fHslider1) + 0.5f));
		int iSlow2 = (iSlow1 >= 3);
		int iSlow3 = (iSlow1 >= 2);
		int iSlow4 = (iSlow1 >= 1);
		float fThen1 = (iSlow4 ? 1.5f : 1.20000005f);
		int iSlow5 = (iSlow1 >= 4);
		float fThen3 = (iSlow3 ? 0.5f : fThen1);
		float fElse3 = (iSlow5 ? 1.60000002f : 1.0f);
		float fSlow6 = (iSlow2 ? fElse3 : fThen3);
		float fThen5 = (iSlow4 ? 0.200000003f : 0.5f);
		float fThen7 = (iSlow3 ? 0.0500000007f : fThen5);
		float fElse7 = (iSlow5 ? 0.100000001f : 0.400000006f);
		float fSlow7 = (iSlow2 ? fElse7 : fThen7);
		float fSlow8 = float(fHslider2);
		int iSlow9 = (iSlow1 == 0);
		int iSlow10 = (iSlow9 | (iSlow1 == 3));
		float fSlow11 = (1.0f / std::tan((fConst6 * ((1500.0f * fSlow8) + (iSlow10 ? 2000.0f : 800.0f)))));
		float fSlow12 = (1.0f - fSlow11);
		float fSlow13 = (fSlow11 + 1.0f);
		float fSlow14 = (0.0399999991f * fSlow8);
		float fThen9 = (fSlow14 + 0.930000007f);
		float fThen10 = (iSlow4 ? 0.829999983f : fThen9);
		float fThen11 = (fSlow14 + 0.879999995f);
		float fThen12 = (iSlow3 ? 0.699999988f : fThen10);
		float fElse12 = (iSlow5 ? 0.850000024f : fThen11);
		float fSlow15 = (iSlow2 ? fElse12 : fThen12);
		float fSlow16 = (4.65661287e-10f * fSlow8);
		float fSlow17 = float(fButton0);
		float fSlow18 = std::max<float>(1.0f, (fConst0 * (iSlow10 ? 0.00200000009f : 0.00100000005f)));
		float fSlow19 = std::max<float>(1.0f, (fConst0 * (iSlow10 ? 0.0199999996f : 0.00999999978f)));
		float fSlow20 = (fConst29 * float(fHslider3));
		float fSlow21 = (fSlow8 * (std::pow(2.0f, (0.0833333358f * float(fHslider4))) + -1.0f));
		float fSlow22 = (iSlow9 ? 1.0f : 0.0f);
		float fSlow23 = (fConst0 / float(fHslider5));
		float fThen18 = (iSlow4 ? 0.800000012f : 0.5f);
		float fThen20 = (iSlow3 ? 0.200000003f : fThen18);
		float fElse20 = (iSlow5 ? 0.899999976f : 0.600000024f);
		float fSlow24 = (iSlow2 ? fElse20 : fThen20);
		float fSlow25 = (0.25f * fSlow8);
		float fSlow26 = float(fHslider6);
		float fSlow27 = std::tan((fConst43 * std::sqrt(std::max<float>(9.99999975e-05f, (3.14159274f * (std::pow(fSlow26, 2.0f) / std::max<float>(9.99999975e-05f, (1.5f * (fSlow26 * float(fHslider7))))))))));
		float fSlow28 = (1.0f / fSlow27);
		float fSlow29 = (((fSlow28 + 0.5f) / fSlow27) + 1.0f);
		float fSlow30 = (1.5f / (fSlow27 * fSlow29));
		float fSlow31 = (1.0f / fSlow29);
		float fSlow32 = (((fSlow28 + -0.5f) / fSlow27) + 1.0f);
		float fSlow33 = (2.0f * (1.0f - (1.0f / FaustBayanDSP_faustpower2_f(fSlow27))));
		float fSlow34 = (0.0f - fSlow30);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (0.0f - (((fRec2[1] * fSlow12) - (fRec1[1] + fRec1[2])) / fSlow13));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			fVec0[0] = fSlow17;
			iRec6[0] = ((fSlow17 > fVec0[1]) + ((fSlow17 <= fVec0[1]) * (iRec6[1] + (iRec6[1] > 0))));
			float fTemp0 = float(iRec6[0]);
			float fTemp1 = (fSlow16 * (float(iRec5[0]) * std::max<float>(0.0f, std::min<float>((fTemp0 / fSlow18), (1.0f - ((fTemp0 - fSlow18) / fSlow19))))));
			float fTempFTZ1 = (fTemp1 - (fConst13 * ((fConst16 * fRec4[2]) + (fConst17 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((fConst13 * (((fConst15 * fRec4[0]) + (fConst18 * fRec4[1])) + (fConst15 * fRec4[2]))) - (fConst19 * ((fConst20 * fRec3[2]) + (fConst21 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 - (fConst26 * ((fConst27 * fRec7[2]) + (fConst28 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fThen15 = (fConst10 * (fRec3[2] + (fRec3[0] + (2.0f * fRec3[1]))));
			float fElse15 = (fConst25 * (fRec7[2] + (fRec7[0] + (2.0f * fRec7[1]))));
			float fTemp2 = (iSlow10 ? fElse15 : fThen15);
			float fTemp3 = ((fRec2[0] * fSlow15) + fTemp2);
			fVec1[(IOTA & 8191)] = fTemp3;
			float fTempFTZ4 = (fSlow20 + (fConst30 * fRec8[1]));
			fRec8[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp4 = (fSlow22 * std::max<float>(0.0f, std::min<float>((fConst32 * fTemp0), (1.0f - (fConst33 * (fTemp0 - fConst31))))));
			float fTemp5 = (fRec8[0] * ((fSlow21 * fTemp4) + 1.0f));
			float fTemp6 = (fConst0 / fTemp5);
			int iTemp7 = int(fTemp6);
			float fTemp8 = std::floor(fTemp6);
			float fTempFTZ5 = ((fVec1[((IOTA - std::min<int>(4097, int(std::max<int>(0, int(iTemp7))))) & 8191)] * (fTemp8 + (1.0f - fTemp6))) + ((fTemp6 - fTemp8) * fVec1[((IOTA - std::min<int>(4097, int(std::max<int>(0, int((iTemp7 + 1)))))) & 8191)]));
			fRec1[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (0.0f - (((fSlow12 * fRec10[1]) - (fRec9[1] + fRec9[2])) / fSlow13));
			fRec10[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp9 = (fTemp2 + (fRec10[0] * fSlow15));
			fVec2[(IOTA & 8191)] = fTemp9;
			float fTemp10 = (fSlow23 / fTemp5);
			int iTemp11 = int(fTemp10);
			float fTemp12 = std::floor(fTemp10);
			float fTempFTZ7 = ((fVec2[((IOTA - std::min<int>(4097, int(std::max<int>(0, int(iTemp11))))) & 8191)] * (fTemp12 + (1.0f - fTemp10))) + ((fTemp10 - fTemp12) * fVec2[((IOTA - std::min<int>(4097, int(std::max<int>(0, int((iTemp11 + 1)))))) & 8191)]));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp13 = (fSlow25 + ((0.00100000005f * (200.0f - fTemp5)) + 0.150000006f));
			float fThen22 = (iSlow4 ? 0.0299999993f : fTemp13);
			float fThen23 = (0.699999988f * fTemp13);
			float fThen24 = (iSlow3 ? 0.00999999978f : fThen22);
			float fElse24 = (iSlow5 ? 0.0500000007f : fThen23);
			float fTemp14 = ((iSlow2 ? fElse24 : fThen24) * (1.0f - (0.850000024f * fTemp4)));
			float fTemp15 = std::pow(0.00100000005f, (fConst34 / std::max<float>(0.00100000005f, (0.800000012f * fTemp14))));
			float fTemp16 = (0.00200000009f * fTemp2);
			float fTempFTZ8 = ((fTemp15 * ((2.0f * (std::cos((fConst35 * fTemp5)) * fRec11[1])) - (fTemp15 * fRec11[2]))) + fTemp16);
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp17 = std::pow(0.00100000005f, (fConst34 / std::max<float>(0.00100000005f, (0.600000024f * fTemp14))));
			float fTempFTZ9 = (fTemp16 + (fTemp17 * ((2.0f * (std::cos((fConst36 * fTemp5)) * fRec12[1])) - (fTemp17 * fRec12[2]))));
			fRec12[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp18 = std::pow(0.00100000005f, (fConst34 / std::max<float>(0.00100000005f, (0.5f * fTemp14))));
			float fTempFTZ10 = (fTemp16 + (fTemp18 * ((2.0f * (std::cos((fConst37 * fTemp5)) * fRec13[1])) - (fTemp18 * fRec13[2]))));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp19 = std::pow(0.00100000005f, (fConst34 / std::max<float>(0.00100000005f, (0.400000006f * fTemp14))));
			float fTempFTZ11 = (fTemp16 + (fTemp19 * ((2.0f * (std::cos((fConst38 * fTemp5)) * fRec14[1])) - (fTemp19 * fRec14[2]))));
			fRec14[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp20 = ((0.5f * (fSlow7 * (fRec1[0] + fRec9[0]))) + (fSlow24 * ((((0.800000012f * fRec11[0]) + (0.5f * fRec12[0])) + (0.300000012f * fRec13[0])) + (0.200000003f * fRec14[0]))));
			float fTempFTZ12 = (fTemp20 - (fSlow31 * ((fSlow32 * fRec16[2]) + (fSlow33 * fRec16[1]))));
			fRec16[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (((fSlow30 * fRec16[0]) + (fSlow34 * fRec16[2])) - (fConst44 * ((fConst45 * fRec15[2]) + (fConst46 * fRec15[1]))));
			fRec15[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = ((4.0f * (fSlow6 * (fTemp20 + (fConst42 * (fRec15[2] + (fRec15[0] + (2.0f * fRec15[1]))))))) - (fConst3 * ((fConst47 * fRec0[2]) + (fConst48 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			output0[i0] = FAUSTFLOAT(std::max<float>(-0.99000001f, std::min<float>(0.99000001f, (fSlow0 * float(tanhf(float((fConst3 * (((fConst5 * fRec0[0]) + (fConst49 * fRec0[1])) + (fConst5 * fRec0[2]))))))))));
			fRec2[1] = fRec2[0];
			iRec5[1] = iRec5[0];
			fVec0[1] = fVec0[0];
			iRec6[1] = iRec6[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
