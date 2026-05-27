/* ------------------------------------------------------------
name: "dholak"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustDholakDSP_H__
#define  __FaustDholakDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustDholakDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustDholakDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustDholakDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst5;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fVec1[2];
	int iRec2[2];
	float fConst8;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec4[3];
	float fConst16;
	float fConst17;
	float fRec3[3];
	float fRec1[3];
	float fConst18;
	float fRec5[3];
	float fConst19;
	float fRec6[3];
	FAUSTFLOAT fHslider5;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fRec9[3];
	float fConst27;
	float fConst28;
	float fRec8[3];
	float fRec7[3];
	float fConst29;
	float fRec10[3];
	float fConst30;
	float fRec11[3];
	float fRec12[3];
	float fVec2[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "dholak.dsp");
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
		m->declare("name", "dholak");
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
		float fConst1 = (1.0f / std::tan((3769.91113f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = (1.0f - fConst1);
		fConst4 = (1.0f / fConst0);
		fConst5 = (6.28318548f / fConst0);
		fConst6 = std::max<float>(1.0f, (0.00999999978f * fConst0));
		fConst7 = (1.0f / fConst6);
		fConst8 = (1.0f / std::max<float>(1.0f, (0.25f * fConst0)));
		float fConst9 = std::tan((345.575195f / fConst0));
		float fConst10 = (1.0f / fConst9);
		float fConst11 = (((fConst10 + 0.765366852f) / fConst9) + 1.0f);
		fConst12 = (0.00200000009f / fConst11);
		fConst13 = (1.0f / (((fConst10 + 1.84775901f) / fConst9) + 1.0f));
		fConst14 = (((fConst10 + -1.84775901f) / fConst9) + 1.0f);
		fConst15 = (2.0f * (1.0f - (1.0f / FaustDholakDSP_faustpower2_f(fConst9))));
		fConst16 = (1.0f / fConst11);
		fConst17 = (((fConst10 + -0.765366852f) / fConst9) + 1.0f);
		fConst18 = (11.3097334f / fConst0);
		fConst19 = (14.4513264f / fConst0);
		float fConst20 = std::tan((2513.27417f / fConst0));
		float fConst21 = (1.0f / fConst20);
		float fConst22 = (((fConst21 + 0.765366852f) / fConst20) + 1.0f);
		fConst23 = (0.00200000009f / fConst22);
		fConst24 = (1.0f / (((fConst21 + 1.84775901f) / fConst20) + 1.0f));
		fConst25 = (((fConst21 + -1.84775901f) / fConst20) + 1.0f);
		fConst26 = (2.0f * (1.0f - (1.0f / FaustDholakDSP_faustpower2_f(fConst20))));
		fConst27 = (1.0f / fConst22);
		fConst28 = (((fConst21 + -0.765366852f) / fConst20) + 1.0f);
		fConst29 = (9.99026489f / fConst0);
		fConst30 = (13.4460163f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(98.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(277.19999999999999f);
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
			fRec9[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0f;
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
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fVec2[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec0[l15] = 0.0f;
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
	
	virtual FaustDholakDSP* clone() {
		return new FaustDholakDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("dholak");
		ui_interface->addHorizontalSlider("decay_scale", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.0500000007f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(98.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider5, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq1", &fHslider5, FAUSTFLOAT(277.200012f), FAUSTFLOAT(100.0f), FAUSTFLOAT(800.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (1.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		int iSlow3 = (fSlow2 == 1.0f);
		float fSlow4 = (iSlow3 ? 0.300000012f : 1.0f);
		float fSlow5 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.899999976f * fSlow1) * fSlow4))));
		float fSlow6 = float(fHslider3);
		float fSlow7 = (fConst5 * fSlow6);
		float fSlow8 = float(fHslider4);
		float fSlow9 = (0.25f * fSlow8);
		int iSlow10 = (fSlow2 == 4.0f);
		float fSlow11 = float((((fSlow2 == 0.0f) + (iSlow10 + iSlow3)) > 0));
		float fSlow12 = float(fButton0);
		float fSlow13 = (0.349999994f * (fSlow8 * fSlow11));
		float fSlow14 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.5f * fSlow1) * fSlow4))));
		float fSlow15 = (fConst18 * fSlow6);
		float fSlow16 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.25f * fSlow1) * fSlow4))));
		float fSlow17 = (fConst19 * fSlow6);
		int iSlow18 = (fSlow2 == 3.0f);
		float fSlow19 = (iSlow18 ? 0.25f : 1.0f);
		float fSlow20 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.349999994f * fSlow1) * fSlow19))));
		float fSlow21 = float(fHslider5);
		float fSlow22 = (2.0f * std::cos((fConst5 * fSlow21)));
		float fSlow23 = (0.349999994f * (fSlow8 * float((((fSlow2 == 2.0f) + (iSlow10 + iSlow18)) > 0))));
		float fSlow24 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.180000007f * fSlow1) * fSlow19))));
		float fSlow25 = (2.0f * std::cos((fConst29 * fSlow21)));
		float fSlow26 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.0799999982f * fSlow1) * fSlow19))));
		float fSlow27 = (2.0f * std::cos((fConst30 * fSlow21)));
		float fSlow28 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.0399999991f * fSlow1) * fSlow19))));
		float fSlow29 = (2.0f * std::cos((fConst19 * fSlow21)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow12;
			float fTemp0 = (fSlow12 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			float fTemp2 = (fSlow11 * fTemp1);
			fVec1[0] = fTemp2;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (fTemp2 <= fVec1[1])) + (fTemp2 > fVec1[1]));
			float fTemp3 = float(iRec2[0]);
			float fTemp4 = ((fSlow9 * std::max<float>(0.0f, std::min<float>((fConst7 * fTemp3), (1.0f - (fConst8 * (fTemp3 - fConst6)))))) + 1.0f);
			fRec4[0] = ((fSlow13 * fTemp1) - (fConst13 * ((fConst14 * fRec4[2]) + (fConst15 * fRec4[1]))));
			fRec3[0] = ((fConst13 * (fRec4[2] + (fRec4[0] + (2.0f * fRec4[1])))) - (fConst16 * ((fConst17 * fRec3[2]) + (fConst15 * fRec3[1]))));
			float fTemp5 = (fConst12 * (fRec3[2] + (fRec3[0] + (2.0f * fRec3[1]))));
			fRec1[0] = ((fSlow5 * ((2.0f * (std::cos((fSlow7 * fTemp4)) * fRec1[1])) - (fSlow5 * fRec1[2]))) + fTemp5);
			fRec5[0] = (fTemp5 + (fSlow14 * ((2.0f * (std::cos((fSlow15 * fTemp4)) * fRec5[1])) - (fSlow14 * fRec5[2]))));
			fRec6[0] = (fTemp5 + (fSlow16 * ((2.0f * (std::cos((fSlow17 * fTemp4)) * fRec6[1])) - (fSlow16 * fRec6[2]))));
			fRec9[0] = ((fSlow23 * fTemp1) - (fConst24 * ((fConst25 * fRec9[2]) + (fConst26 * fRec9[1]))));
			fRec8[0] = ((fConst24 * (fRec9[2] + (fRec9[0] + (2.0f * fRec9[1])))) - (fConst27 * ((fConst28 * fRec8[2]) + (fConst26 * fRec8[1]))));
			float fTemp6 = (fConst23 * (fRec8[2] + (fRec8[0] + (2.0f * fRec8[1]))));
			fRec7[0] = ((fSlow20 * ((fSlow22 * fRec7[1]) - (fSlow20 * fRec7[2]))) + fTemp6);
			fRec10[0] = (fTemp6 + (fSlow24 * ((fSlow25 * fRec10[1]) - (fSlow24 * fRec10[2]))));
			fRec11[0] = (fTemp6 + (fSlow26 * ((fSlow27 * fRec11[1]) - (fSlow26 * fRec11[2]))));
			fRec12[0] = (fTemp6 + (fSlow28 * ((fSlow29 * fRec12[1]) - (fSlow28 * fRec12[2]))));
			float fTemp7 = float(tanhf(float((18.0f * (((fRec1[0] + (0.5f * fRec5[0])) + (0.200000003f * fRec6[0])) + (1.20000005f * (((fRec7[0] + (0.550000012f * fRec10[0])) + (0.25f * fRec11[0])) + (0.100000001f * fRec12[0]))))))));
			fVec2[0] = fTemp7;
			fRec0[0] = (0.0f - (fConst2 * ((fConst3 * fRec0[1]) - (fTemp7 + fVec2[1]))));
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
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fVec2[1] = fVec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
