/* ------------------------------------------------------------
name: "dhol"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustDholDSP_H__
#define  __FaustDholDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustDholDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustDholDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustDholDSP : public dsp {
	
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
	float fConst16;
	int iRec6[2];
	float fConst17;
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec5[3];
	float fConst22;
	float fConst23;
	float fRec4[3];
	float fConst24;
	float fConst25;
	float fRec3[3];
	float fRec1[3];
	float fConst26;
	float fRec7[3];
	float fConst27;
	float fRec8[3];
	FAUSTFLOAT fHslider5;
	float fRec9[3];
	float fConst28;
	float fRec10[3];
	float fConst29;
	float fRec11[3];
	float fConst30;
	float fRec12[3];
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
		m->declare("filename", "dhol.dsp");
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
		m->declare("name", "dhol");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		float fConst1 = (1.0f / std::tan((6283.18555f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = (1.0f - fConst1);
		fConst4 = (1.0f / fConst0);
		fConst5 = (6.28318548f / fConst0);
		fConst6 = std::max<float>(1.0f, (0.00400000019f * fConst0));
		fConst7 = (1.0f / fConst6);
		fConst8 = (1.0f / std::max<float>(1.0f, (0.180000007f * fConst0)));
		float fConst9 = std::tan((565.486694f / fConst0));
		float fConst10 = (1.0f / fConst9);
		float fConst11 = (((fConst10 + 0.765366852f) / fConst9) + 1.0f);
		fConst12 = (0.00200000009f / fConst11);
		fConst13 = (1.0f / (((fConst10 + 1.84775901f) / fConst9) + 1.0f));
		float fConst14 = std::tan((628.318542f / fConst0));
		float fConst15 = (1.0f / fConst14);
		fConst16 = (1.0f / (((fConst15 + 1.41421354f) / fConst14) + 1.0f));
		fConst17 = std::max<float>(1.0f, (0.00200000009f * fConst0));
		fConst18 = (1.0f / fConst17);
		fConst19 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
		fConst20 = (((fConst15 + -1.41421354f) / fConst14) + 1.0f);
		fConst21 = (2.0f * (1.0f - (1.0f / FaustDholDSP_faustpower2_f(fConst14))));
		fConst22 = (((fConst10 + -1.84775901f) / fConst9) + 1.0f);
		fConst23 = (2.0f * (1.0f - (1.0f / FaustDholDSP_faustpower2_f(fConst9))));
		fConst24 = (1.0f / fConst11);
		fConst25 = (((fConst10 + -0.765366852f) / fConst9) + 1.0f);
		fConst26 = (10.0530968f / fConst0);
		fConst27 = (13.8230076f / fConst0);
		fConst28 = (9.99026489f / fConst0);
		fConst29 = (16.6504402f / fConst0);
		fConst30 = (13.4460163f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(110.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(880.0f);
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
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec6[l3] = 0;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec1[l7] = 0.0f;
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
	
	virtual FaustDholDSP* clone() {
		return new FaustDholDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("dhol");
		ui_interface->addHorizontalSlider("decay_scale", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.0500000007f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(110.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(600.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider5, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq1", &fHslider5, FAUSTFLOAT(880.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1500.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.800000012f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		int iSlow3 = (fSlow2 == 1.0f);
		float fSlow4 = (iSlow3 ? 0.25f : 1.0f);
		float fSlow5 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((1.39999998f * fSlow1) * fSlow4))));
		float fSlow6 = float(fHslider3);
		float fSlow7 = (fConst5 * fSlow6);
		float fSlow8 = float(fHslider4);
		float fSlow9 = (0.280000001f * fSlow8);
		int iSlow10 = (fSlow2 == 4.0f);
		float fSlow11 = float((((fSlow2 == 0.0f) + (iSlow10 + iSlow3)) > 0));
		float fSlow12 = float(fButton0);
		float fSlow13 = (0.219999999f * (fSlow8 * fSlow11));
		float fSlow14 = (3.72529022e-11f * fSlow8);
		float fSlow15 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.5f * fSlow1) * fSlow4))));
		float fSlow16 = (fConst26 * fSlow6);
		float fSlow17 = (0.150000006f * fSlow1);
		float fSlow18 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (fSlow17 * fSlow4))));
		float fSlow19 = (fConst27 * fSlow6);
		int iSlow20 = (fSlow2 == 3.0f);
		int iSlow21 = iSlow20;
		float fSlow22 = (iSlow21 ? 0.150000006f : 1.0f);
		float fSlow23 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.25999999f * fSlow1) * fSlow22))));
		float fSlow24 = float(fHslider5);
		float fSlow25 = (2.0f * std::cos((fConst5 * fSlow24)));
		float fSlow26 = (0.0013f * (fSlow8 * float((((fSlow2 == 2.0f) + (iSlow20 + iSlow10)) > 0))));
		float fSlow27 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, (fSlow17 * fSlow22))));
		float fSlow28 = (2.0f * std::cos((fConst28 * fSlow24)));
		float fSlow29 = (iSlow21 ? 0.800000012f : 0.75f);
		float fSlow30 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.0399999991f * fSlow1) * fSlow22))));
		float fSlow31 = (2.0f * std::cos((fConst29 * fSlow24)));
		float fSlow32 = (iSlow21 ? 0.600000024f : 0.25f);
		float fSlow33 = std::pow(0.00100000005f, (fConst4 / std::max<float>(0.00100000005f, ((0.0900000036f * fSlow1) * fSlow22))));
		float fSlow34 = (2.0f * std::cos((fConst30 * fSlow24)));
		float fSlow35 = (iSlow21 ? 1.0f : 0.5f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow12;
			float fTemp0 = (fSlow12 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			float fTemp2 = (fSlow11 * fTemp1);
			fVec1[0] = fTemp2;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (fTemp2 <= fVec1[1])) + (fTemp2 > fVec1[1]));
			float fTemp3 = float(iRec2[0]);
			float fTemp4 = ((fSlow9 * std::max<float>(0.0f, std::min<float>((fConst7 * fTemp3), (1.0f - (fConst8 * (fTemp3 - fConst6)))))) + 1.0f);
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fTempFTZ0 = ((fSlow14 * (float(iRec6[0]) * std::max<float>(0.0f, std::min<float>((fConst18 * fTemp3), (1.0f - (fConst19 * (fTemp3 - fConst17))))))) - (fConst16 * ((fConst20 * fRec5[2]) + (fConst21 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (((fSlow13 * fTemp1) + (fConst16 * (fRec5[2] + (fRec5[0] + (2.0f * fRec5[1]))))) - (fConst13 * ((fConst22 * fRec4[2]) + (fConst23 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((fConst13 * (fRec4[2] + (fRec4[0] + (2.0f * fRec4[1])))) - (fConst24 * ((fConst25 * fRec3[2]) + (fConst23 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp5 = (fConst12 * (fRec3[2] + (fRec3[0] + (2.0f * fRec3[1]))));
			float fTempFTZ3 = ((fSlow5 * ((2.0f * (std::cos((fSlow7 * fTemp4)) * fRec1[1])) - (fSlow5 * fRec1[2]))) + fTemp5);
			fRec1[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp5 + (fSlow15 * ((2.0f * (std::cos((fSlow16 * fTemp4)) * fRec7[1])) - (fSlow15 * fRec7[2]))));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp5 + (fSlow18 * ((2.0f * (std::cos((fSlow19 * fTemp4)) * fRec8[1])) - (fSlow18 * fRec8[2]))));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp6 = (fSlow26 * fTemp1);
			float fTempFTZ6 = ((fSlow23 * ((fSlow25 * fRec9[1]) - (fSlow23 * fRec9[2]))) + fTemp6);
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp6 + (fSlow27 * ((fSlow28 * fRec10[1]) - (fSlow27 * fRec10[2]))));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp6 + (fSlow30 * ((fSlow31 * fRec11[1]) - (fSlow30 * fRec11[2]))));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp6 + (fSlow33 * ((fSlow34 * fRec12[1]) - (fSlow33 * fRec12[2]))));
			fRec12[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp7 = float(tanhf(float((5.0f * (((fRec1[0] + (0.349999994f * fRec7[0])) + (0.150000006f * fRec8[0])) + (2.20000005f * ((fRec9[0] * fSlow22) + ((fRec10[0] * fSlow29) + ((fRec11[0] * fSlow32) + (fRec12[0] * fSlow35))))))))));
			fVec2[0] = fTemp7;
			float fTempFTZ10 = (0.0f - (fConst2 * ((fConst3 * fRec0[1]) - (fTemp7 + fVec2[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * fRec0[0]));
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			iRec2[1] = iRec2[0];
			iRec6[1] = iRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
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
