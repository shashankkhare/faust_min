/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "ngachen"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustNgachenDSP_H__
#define  __FaustNgachenDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustNgachenDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustNgachenDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustNgachenDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst5;
	FAUSTFLOAT fHslider1;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fVec1[2];
	int iRec3[2];
	float fConst10;
	float fConst11;
	float fConst12;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fRec5[3];
	float fRec4[3];
	float fRec2[3];
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec6[3];
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec7[3];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec8[3];
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec9[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec10[3];
	float fConst28;
	float fConst29;
	float fRec11[3];
	float fVec2[2];
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec1[2];
	float fRec0[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "ngachen.dsp");
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
		m->declare("name", "ngachen");
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
		fConst1 = (14.137167f / fConst0);
		float fConst2 = std::tan((56.5486679f / fConst0));
		float fConst3 = (1.0f / fConst2);
		float fConst4 = (fConst3 + 1.0f);
		fConst5 = (0.0f - (1.0f / (fConst2 * fConst4)));
		fConst6 = std::pow(0.00100000005f, (0.384615391f / fConst0));
		fConst7 = (6.28318548f / fConst0);
		fConst8 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f / std::max<float>(1.0f, (0.0250000004f * fConst0)));
		fConst11 = (0.999979973f * fConst6);
		fConst12 = (3.14159274f / fConst0);
		fConst13 = std::pow(0.00100000005f, (2.0f / fConst0));
		fConst14 = (10.0091143f / fConst0);
		fConst15 = (0.999979973f * fConst13);
		fConst16 = std::pow(0.00100000005f, (4.5454545f / fConst0));
		fConst17 = (13.4208841f / fConst0);
		fConst18 = (0.999979973f * fConst16);
		fConst19 = std::pow(0.00100000005f, (7.14285707f / fConst0));
		fConst20 = (14.4199104f / fConst0);
		fConst21 = (0.999979973f * fConst19);
		fConst22 = std::pow(0.00100000005f, (14.2857141f / fConst0));
		fConst23 = (16.6692905f / fConst0);
		fConst24 = (0.999979973f * fConst22);
		fConst25 = std::pow(0.00100000005f, (0.285714298f / fConst0));
		fConst26 = (5.84336233f / fConst0);
		fConst27 = (0.999979973f * fConst25);
		fConst28 = std::pow(0.00100000005f, (0.714285731f / fConst0));
		fConst29 = (0.999979973f * fConst28);
		fConst30 = (1.0f / fConst4);
		fConst31 = (0.779999971f / fConst2);
		fConst32 = (1.0f - fConst3);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(75.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec3[l2] = 0;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec2[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec1[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec0[l14] = 0.0f;
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
	
	virtual FaustNgachenDSP* clone() {
		return new FaustNgachenDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ngachen");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(75.0f), FAUSTFLOAT(60.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mallet_softness", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = std::tan((fConst1 * fSlow0));
		float fSlow2 = (1.0f / fSlow1);
		float fSlow3 = (1.0f / (((fSlow2 + 1.41421354f) / fSlow1) + 1.0f));
		float fSlow4 = float(fHslider1);
		float fSlow5 = (0.779999971f * fSlow4);
		float fSlow6 = (fConst7 * fSlow0);
		float fSlow7 = float(fButton0);
		float fSlow8 = std::tan((fConst12 * std::max<float>(50.0f, (450.0f - (400.0f * float(fHslider2))))));
		float fSlow9 = (1.0f / fSlow8);
		float fSlow10 = (((fSlow9 + 0.765366852f) / fSlow8) + 1.0f);
		float fSlow11 = (0.150000006f / fSlow10);
		float fSlow12 = (1.0f / (((fSlow9 + 1.84775901f) / fSlow8) + 1.0f));
		float fSlow13 = (0.00213333336f * (fSlow0 * float(fHslider3)));
		float fSlow14 = (((fSlow9 + -1.84775901f) / fSlow8) + 1.0f);
		float fSlow15 = (2.0f * (1.0f - (1.0f / FaustNgachenDSP_faustpower2_f(fSlow8))));
		float fSlow16 = (1.0f / fSlow10);
		float fSlow17 = (((fSlow9 + -0.765366852f) / fSlow8) + 1.0f);
		float fSlow18 = (fConst14 * fSlow0);
		float fSlow19 = (fConst17 * fSlow0);
		float fSlow20 = (fConst20 * fSlow0);
		float fSlow21 = (fConst23 * fSlow0);
		float fSlow22 = (1.99997997f * std::cos((fConst26 * fSlow0)));
		float fSlow23 = (fConst12 * fSlow0);
		float fSlow24 = (fConst31 * fSlow4);
		float fSlow25 = (((fSlow2 + -1.41421354f) / fSlow1) + 1.0f);
		float fSlow26 = (2.0f * (1.0f - (1.0f / FaustNgachenDSP_faustpower2_f(fSlow1))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow7;
			float fTemp0 = (fSlow7 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			fVec1[0] = fTemp1;
			iRec3[0] = (((iRec3[1] + (iRec3[1] > 0)) * (fTemp1 <= fVec1[1])) + (fTemp1 > fVec1[1]));
			float fTemp2 = float(iRec3[0]);
			float fTemp3 = (1.0f - (0.0149999997f * std::max<float>(0.0f, std::min<float>((fConst9 * fTemp2), (1.0f - (fConst10 * (fTemp2 - fConst8)))))));
			float fTempFTZ0 = ((fSlow13 * fTemp1) - (fSlow12 * ((fSlow14 * fRec5[2]) + (fSlow15 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = ((fSlow12 * (fRec5[2] + (fRec5[0] + (2.0f * fRec5[1])))) - (fSlow16 * ((fSlow17 * fRec4[2]) + (fSlow15 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp4 = (fSlow11 * (fRec4[2] + (fRec4[0] + (2.0f * fRec4[1]))));
			float fTempFTZ2 = ((fConst6 * ((1.99997997f * (std::cos((fSlow6 * fTemp3)) * fRec2[1])) - (fConst11 * fRec2[2]))) + fTemp4);
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp4 + (fConst13 * ((1.99997997f * (std::cos((fSlow18 * fTemp3)) * fRec6[1])) - (fConst15 * fRec6[2]))));
			fRec6[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp4 + (fConst16 * ((1.99997997f * (std::cos((fSlow19 * fTemp3)) * fRec7[1])) - (fConst18 * fRec7[2]))));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp4 + (fConst19 * ((1.99997997f * (std::cos((fSlow20 * fTemp3)) * fRec8[1])) - (fConst21 * fRec8[2]))));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp4 + (fConst22 * ((1.99997997f * (std::cos((fSlow21 * fTemp3)) * fRec9[1])) - (fConst24 * fRec9[2]))));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp4 + (fConst25 * ((fSlow22 * fRec10[1]) - (fConst27 * fRec10[2]))));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp4 + (fConst28 * ((1.99997997f * (std::cos((fSlow23 * fTemp3)) * fRec11[1])) - (fConst29 * fRec11[2]))));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp5 = ((((((fRec2[0] + (0.150000006f * fRec6[0])) + (0.0599999987f * fRec7[0])) + (0.0299999993f * fRec8[0])) + (0.00999999978f * fRec9[0])) + (0.699999988f * fRec10[0])) + (0.219999999f * fRec11[0]));
			fVec2[0] = (fSlow5 * fTemp5);
			float fTempFTZ9 = ((fConst5 * fVec2[1]) + (fConst30 * ((fSlow24 * fTemp5) - (fConst32 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fRec1[0] - (fSlow3 * ((fSlow25 * fRec0[2]) + (fSlow26 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow3 * (fRec0[2] + (fRec0[0] + (2.0f * fRec0[1]))))))));
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			iRec3[1] = iRec3[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
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
			fVec2[1] = fVec2[0];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
