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
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fConst9;
	float fConst10;
	float fRec3[3];
	float fConst11;
	float fConst12;
	float fRec2[3];
	float fConst13;
	FAUSTFLOAT fHslider3;
	float fConst14;
	FAUSTFLOAT fHslider4;
	float fRec1[3];
	float fConst15;
	float fRec4[3];
	float fConst16;
	float fRec5[3];
	float fConst17;
	float fRec6[3];
	FAUSTFLOAT fHslider5;
	float fConst18;
	float fConst19;
	float fVec1[2];
	int iRec8[2];
	float fConst20;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec10[3];
	float fConst28;
	float fConst29;
	float fRec9[3];
	float fRec7[3];
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
		float fConst1 = (1.0f / std::tan((1413.71667f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = (1.0f - fConst1);
		float fConst4 = std::tan((942.477783f / fConst0));
		float fConst5 = (1.0f / fConst4);
		float fConst6 = (((fConst5 + 0.765366852f) / fConst4) + 1.0f);
		fConst7 = (0.00200000009f / fConst6);
		fConst8 = (1.0f / (((fConst5 + 1.84775901f) / fConst4) + 1.0f));
		fConst9 = (((fConst5 + -1.84775901f) / fConst4) + 1.0f);
		fConst10 = (2.0f * (1.0f - (1.0f / FaustDholakDSP_faustpower2_f(fConst4))));
		fConst11 = (1.0f / fConst6);
		fConst12 = (((fConst5 + -0.765366852f) / fConst4) + 1.0f);
		fConst13 = (1.0f / fConst0);
		fConst14 = (14.4513264f / fConst0);
		fConst15 = (13.4460163f / fConst0);
		fConst16 = (9.99026489f / fConst0);
		fConst17 = (6.28318548f / fConst0);
		fConst18 = std::max<float>(1.0f, (0.00999999978f * fConst0));
		fConst19 = (1.0f / fConst18);
		fConst20 = (1.0f / std::max<float>(1.0f, (0.25f * fConst0)));
		float fConst21 = std::tan((251.327408f / fConst0));
		float fConst22 = (1.0f / fConst21);
		float fConst23 = (((fConst22 + 0.765366852f) / fConst21) + 1.0f);
		fConst24 = (0.00200000009f / fConst23);
		fConst25 = (1.0f / (((fConst22 + 1.84775901f) / fConst21) + 1.0f));
		fConst26 = (((fConst22 + -1.84775901f) / fConst21) + 1.0f);
		fConst27 = (2.0f * (1.0f - (1.0f / FaustDholakDSP_faustpower2_f(fConst21))));
		fConst28 = (1.0f / fConst23);
		fConst29 = (((fConst22 + -0.765366852f) / fConst21) + 1.0f);
		fConst30 = (11.3097334f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(277.19999999999999f);
		fHslider5 = FAUSTFLOAT(98.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec8[l8] = 0;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0f;
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
		ui_interface->addHorizontalSlider("decay_scale", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.0500000007f));
		ui_interface->declare(&fHslider5, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider5, FAUSTFLOAT(98.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq1", &fHslider4, FAUSTFLOAT(277.200012f), FAUSTFLOAT(100.0f), FAUSTFLOAT(800.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.850000024f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		int iSlow3 = (fSlow2 == 4.0f);
		int iSlow4 = (fSlow2 == 3.0f);
		float fSlow5 = (0.150000006f * (fSlow1 * float((((fSlow2 == 2.0f) + (iSlow3 + iSlow4)) > 0))));
		float fSlow6 = float(fButton0);
		float fSlow7 = float(fHslider3);
		float fSlow8 = (iSlow4 ? 0.25f : 1.0f);
		float fSlow9 = std::pow(0.00100000005f, (fConst13 / std::max<float>(0.00100000005f, ((0.0399999991f * fSlow7) * fSlow8))));
		float fSlow10 = float(fHslider4);
		float fSlow11 = (2.0f * std::cos((fConst14 * fSlow10)));
		float fSlow12 = std::pow(0.00100000005f, (fConst13 / std::max<float>(0.00100000005f, ((0.0799999982f * fSlow7) * fSlow8))));
		float fSlow13 = (2.0f * std::cos((fConst15 * fSlow10)));
		float fSlow14 = std::pow(0.00100000005f, (fConst13 / std::max<float>(0.00100000005f, ((0.180000007f * fSlow7) * fSlow8))));
		float fSlow15 = (2.0f * std::cos((fConst16 * fSlow10)));
		float fSlow16 = std::pow(0.00100000005f, (fConst13 / std::max<float>(0.00100000005f, ((0.349999994f * fSlow7) * fSlow8))));
		float fSlow17 = (2.0f * std::cos((fConst17 * fSlow10)));
		int iSlow18 = (fSlow2 == 1.0f);
		float fSlow19 = (iSlow18 ? 0.300000012f : 1.0f);
		float fSlow20 = std::pow(0.00100000005f, (fConst13 / std::max<float>(0.00100000005f, ((0.899999976f * fSlow7) * fSlow19))));
		float fSlow21 = float(fHslider5);
		float fSlow22 = (fConst17 * fSlow21);
		float fSlow23 = (0.25f * fSlow1);
		float fSlow24 = float((((fSlow2 == 0.0f) + (iSlow3 + iSlow18)) > 0));
		float fSlow25 = (0.150000006f * (fSlow1 * fSlow24));
		float fSlow26 = std::pow(0.00100000005f, (fConst13 / std::max<float>(0.00100000005f, ((0.5f * fSlow7) * fSlow19))));
		float fSlow27 = (fConst30 * fSlow21);
		float fSlow28 = std::pow(0.00100000005f, (fConst13 / std::max<float>(0.00100000005f, ((0.25f * fSlow7) * fSlow19))));
		float fSlow29 = (fConst14 * fSlow21);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow6;
			float fTemp0 = (fSlow6 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			fRec3[0] = ((fSlow5 * fTemp1) - (fConst8 * ((fConst9 * fRec3[2]) + (fConst10 * fRec3[1]))));
			fRec2[0] = ((fConst8 * (fRec3[2] + (fRec3[0] + (2.0f * fRec3[1])))) - (fConst11 * ((fConst12 * fRec2[2]) + (fConst10 * fRec2[1]))));
			float fTemp2 = (fConst7 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))));
			fRec1[0] = (fTemp2 + (fSlow9 * ((fSlow11 * fRec1[1]) - (fSlow9 * fRec1[2]))));
			fRec4[0] = (fTemp2 + (fSlow12 * ((fSlow13 * fRec4[1]) - (fSlow12 * fRec4[2]))));
			fRec5[0] = (fTemp2 + (fSlow14 * ((fSlow15 * fRec5[1]) - (fSlow14 * fRec5[2]))));
			fRec6[0] = ((fSlow16 * ((fSlow17 * fRec6[1]) - (fSlow16 * fRec6[2]))) + fTemp2);
			float fTemp3 = (fSlow24 * fTemp1);
			fVec1[0] = fTemp3;
			iRec8[0] = (((iRec8[1] + (iRec8[1] > 0)) * (fTemp3 <= fVec1[1])) + (fTemp3 > fVec1[1]));
			float fTemp4 = float(iRec8[0]);
			float fTemp5 = ((fSlow23 * std::max<float>(0.0f, std::min<float>((fConst19 * fTemp4), (1.0f - (fConst20 * (fTemp4 - fConst18)))))) + 1.0f);
			fRec10[0] = ((fSlow25 * fTemp1) - (fConst25 * ((fConst26 * fRec10[2]) + (fConst27 * fRec10[1]))));
			fRec9[0] = ((fConst25 * (fRec10[2] + (fRec10[0] + (2.0f * fRec10[1])))) - (fConst28 * ((fConst29 * fRec9[2]) + (fConst27 * fRec9[1]))));
			float fTemp6 = (fConst24 * (fRec9[2] + (fRec9[0] + (2.0f * fRec9[1]))));
			fRec7[0] = ((fSlow20 * ((2.0f * (std::cos((fSlow22 * fTemp5)) * fRec7[1])) - (fSlow20 * fRec7[2]))) + fTemp6);
			fRec11[0] = (fTemp6 + (fSlow26 * ((2.0f * (std::cos((fSlow27 * fTemp5)) * fRec11[1])) - (fSlow26 * fRec11[2]))));
			fRec12[0] = (fTemp6 + (fSlow28 * ((2.0f * (std::cos((fSlow29 * fTemp5)) * fRec12[1])) - (fSlow28 * fRec12[2]))));
			float fTemp7 = float(tanhf(float((12.0f * ((0.100000001f * fRec1[0]) + ((0.25f * fRec4[0]) + ((0.550000012f * fRec5[0]) + (fRec6[0] + ((fRec7[0] + (0.5f * fRec11[0])) + (0.200000003f * fRec12[0]))))))))));
			fVec2[0] = fTemp7;
			fRec0[0] = (0.0f - (fConst2 * ((fConst3 * fRec0[1]) - (fTemp7 + fVec2[1]))));
			output0[i0] = FAUSTFLOAT((fSlow0 * fRec0[0]));
			fVec0[1] = fVec0[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			iRec8[1] = iRec8[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
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
