/* ------------------------------------------------------------
name: "lagnga"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustLagngaDSP_H__
#define  __FaustLagngaDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustLagngaDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustLagngaDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustLagngaDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fConst5;
	FAUSTFLOAT fHslider2;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fVec1[2];
	int iRec2[2];
	float fConst8;
	float fConst9;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec4[3];
	float fRec3[3];
	float fRec1[3];
	float fConst10;
	float fRec5[3];
	float fConst11;
	float fRec6[3];
	float fConst12;
	float fRec7[3];
	float fConst13;
	float fRec8[3];
	float fConst14;
	float fRec9[3];
	float fVec2[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "lagnga.dsp");
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
		m->declare("name", "lagnga");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = (1.0f / std::tan((691.150391f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = (1.0f - fConst1);
		fConst4 = (1.0f / fConst0);
		fConst5 = (6.28318548f / fConst0);
		fConst6 = std::max<float>(1.0f, (0.00499999989f * fConst0));
		fConst7 = (1.0f / fConst6);
		fConst8 = (1.0f / std::max<float>(1.0f, (0.0250000004f * fConst0)));
		fConst9 = (3.14159274f / fConst0);
		fConst10 = (7.41415882f / fConst0);
		fConst11 = (9.99026489f / fConst0);
		fConst12 = (10.2415924f / fConst0);
		fConst13 = (13.4460163f / fConst0);
		fConst14 = (14.4513264f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1.5f);
		fHslider2 = FAUSTFLOAT(55.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(75.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec0[l12] = 0.0f;
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
	
	virtual FaustLagngaDSP* clone() {
		return new FaustLagngaDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("lagnga");
		ui_interface->addHorizontalSlider("decay_scale", &fHslider1, FAUSTFLOAT(1.5f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.0500000007f));
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(55.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(85.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mallet_softness", &fHslider3, FAUSTFLOAT(75.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(150.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.850000024f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (1.39999998f * fSlow1))));
		float fSlow3 = float(fHslider2);
		float fSlow4 = (fConst5 * fSlow3);
		float fSlow5 = float(fButton0);
		float fSlow6 = (0.999989986f * fSlow2);
		float fSlow7 = std::tan((fConst9 * float(fHslider3)));
		float fSlow8 = (1.0f / fSlow7);
		float fSlow9 = (((fSlow8 + 0.765366852f) / fSlow7) + 1.0f);
		float fSlow10 = (0.00200000009f / fSlow9);
		float fSlow11 = (1.0f / (((fSlow8 + 1.84775901f) / fSlow7) + 1.0f));
		float fSlow12 = (0.00176470587f * (fSlow3 * float(fHslider4)));
		float fSlow13 = (((fSlow8 + -1.84775901f) / fSlow7) + 1.0f);
		float fSlow14 = (2.0f * (1.0f - (1.0f / FaustLagngaDSP_faustpower2_f(fSlow7))));
		float fSlow15 = (1.0f / fSlow9);
		float fSlow16 = (((fSlow8 + -0.765366852f) / fSlow7) + 1.0f);
		float fSlow17 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (1.10000002f * fSlow1))));
		float fSlow18 = (fConst10 * fSlow3);
		float fSlow19 = (0.999989986f * fSlow17);
		float fSlow20 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (0.349999994f * fSlow1))));
		float fSlow21 = (fConst11 * fSlow3);
		float fSlow22 = (0.999989986f * fSlow20);
		float fSlow23 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (0.280000001f * fSlow1))));
		float fSlow24 = (fConst12 * fSlow3);
		float fSlow25 = (0.999989986f * fSlow23);
		float fSlow26 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (0.100000001f * fSlow1))));
		float fSlow27 = (fConst13 * fSlow3);
		float fSlow28 = (0.999989986f * fSlow26);
		float fSlow29 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (0.0500000007f * fSlow1))));
		float fSlow30 = (fConst14 * fSlow3);
		float fSlow31 = (0.999989986f * fSlow29);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow5;
			float fTemp0 = (fSlow5 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			fVec1[0] = fTemp1;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (fTemp1 <= fVec1[1])) + (fTemp1 > fVec1[1]));
			float fTemp2 = float(iRec2[0]);
			float fTemp3 = (1.0f - (0.0799999982f * std::max<float>(0.0f, std::min<float>((fConst7 * fTemp2), (1.0f - (fConst8 * (fTemp2 - fConst6)))))));
			float fTempFTZ0 = ((fSlow12 * fTemp1) - (fSlow11 * ((fSlow13 * fRec4[2]) + (fSlow14 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((fSlow11 * (fRec4[2] + (fRec4[0] + (2.0f * fRec4[1])))) - (fSlow15 * ((fSlow16 * fRec3[2]) + (fSlow14 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp4 = (fSlow10 * (fRec3[2] + (fRec3[0] + (2.0f * fRec3[1]))));
			float fTempFTZ2 = ((fSlow2 * ((1.99998999f * (std::cos((fSlow4 * fTemp3)) * fRec1[1])) - (fSlow6 * fRec1[2]))) + fTemp4);
			fRec1[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp4 + (fSlow17 * ((1.99998999f * (std::cos((fSlow18 * fTemp3)) * fRec5[1])) - (fSlow19 * fRec5[2]))));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp4 + (fSlow20 * ((1.99998999f * (std::cos((fSlow21 * fTemp3)) * fRec6[1])) - (fSlow22 * fRec6[2]))));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp4 + (fSlow23 * ((1.99998999f * (std::cos((fSlow24 * fTemp3)) * fRec7[1])) - (fSlow25 * fRec7[2]))));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp4 + (fSlow26 * ((1.99998999f * (std::cos((fSlow27 * fTemp3)) * fRec8[1])) - (fSlow28 * fRec8[2]))));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp4 + (fSlow29 * ((1.99998999f * (std::cos((fSlow30 * fTemp3)) * fRec9[1])) - (fSlow31 * fRec9[2]))));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp5 = float(tanhf(float((12.0f * (((((fRec1[0] + (0.649999976f * fRec5[0])) + (0.200000003f * fRec6[0])) + (0.150000006f * fRec7[0])) + (0.0500000007f * fRec8[0])) + (0.0199999996f * fRec9[0]))))));
			fVec2[0] = fTemp5;
			float fTempFTZ8 = (0.0f - (fConst2 * ((fConst3 * fRec0[1]) - (fTemp5 + fVec2[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * fRec0[0]));
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			iRec2[1] = iRec2[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec2[1] = fVec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
