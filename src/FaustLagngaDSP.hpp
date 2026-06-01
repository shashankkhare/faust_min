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
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fConst6;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fVec1[2];
	float fVec2[2];
	float fConst7;
	float fConst8;
	float fConst9;
	float fRec3[2];
	float fRec2[3];
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	int iRec4[2];
	float fConst15;
	float fConst16;
	float fRec1[3];
	float fConst18;
	float fConst19;
	float fConst20;
	float fRec5[3];
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec6[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec7[3];
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec8[3];
	float fConst34;
	float fConst35;
	float fConst36;
	float fRec9[3];
	float fConst38;
	float fConst39;
	float fConst40;
	float fRec10[3];
	float fVec3[2];
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
		m->declare("name", "lagnga");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
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
		fConst1 = (25.1327419f / fConst0);
		fConst2 = (3.14159274f / fConst0);
		float fConst3 = std::tan((471.238892f / fConst0));
		float fConst4 = (1.0f / fConst3);
		float fConst5 = (fConst4 + 1.0f);
		fConst6 = (0.0f - (1.0f / (fConst3 * fConst5)));
		fConst7 = (1.0f / fConst5);
		fConst8 = (0.000818181841f / fConst3);
		fConst9 = (1.0f - fConst4);
		float fConst10 = std::pow(0.00100000005f, (1.17647064f / fConst0));
		fConst11 = (0.0f - (2.0f * fConst10));
		fConst12 = (6.28318548f / fConst0);
		fConst13 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst14 = (1.0f / fConst13);
		fConst15 = (1.0f / std::max<float>(1.0f, (0.00800000038f * fConst0)));
		fConst16 = FaustLagngaDSP_faustpower2_f(fConst10);
		float fConst17 = std::pow(0.00100000005f, (2.22222233f / fConst0));
		fConst18 = (0.0f - (2.0f * fConst17));
		fConst19 = (10.0091143f / fConst0);
		fConst20 = FaustLagngaDSP_faustpower2_f(fConst17);
		float fConst21 = std::pow(0.00100000005f, (4.0f / fConst0));
		fConst22 = (0.0f - (2.0f * fConst21));
		fConst23 = (13.4208841f / fConst0);
		fConst24 = FaustLagngaDSP_faustpower2_f(fConst21);
		float fConst25 = std::pow(0.00100000005f, (5.55555534f / fConst0));
		fConst26 = (0.0f - (2.0f * fConst25));
		fConst27 = (14.4199104f / fConst0);
		fConst28 = FaustLagngaDSP_faustpower2_f(fConst25);
		float fConst29 = std::pow(0.00100000005f, (1.66666663f / fConst0));
		fConst30 = (0.0f - (2.0f * fConst29));
		fConst31 = (7.41415882f / fConst0);
		fConst32 = FaustLagngaDSP_faustpower2_f(fConst29);
		float fConst33 = std::pow(0.00100000005f, (4.5454545f / fConst0));
		fConst34 = (0.0f - (2.0f * fConst33));
		fConst35 = (10.8070784f / fConst0);
		fConst36 = FaustLagngaDSP_faustpower2_f(fConst33);
		float fConst37 = std::pow(0.00100000005f, (3.33333325f / fConst0));
		fConst38 = (0.0f - (2.0f * fConst37));
		fConst39 = (23.8761044f / fConst0);
		fConst40 = FaustLagngaDSP_faustpower2_f(fConst37);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(220.0f);
		fHslider2 = FAUSTFLOAT(0.29999999999999999f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec4[l5] = 0;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fVec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
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
	
	virtual FaustLagngaDSP* clone() {
		return new FaustLagngaDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("lagnga");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(220.0f), FAUSTFLOAT(120.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mallet_softness", &fHslider2, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (6.0f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (1.0f / std::tan((fConst1 * fSlow1)));
		float fSlow3 = (1.0f / (fSlow2 + 1.0f));
		float fSlow4 = (1.0f - fSlow2);
		float fSlow5 = std::tan((fConst2 * std::max<float>(400.0f, (2800.0f - (2100.0f * float(fHslider2))))));
		float fSlow6 = (1.0f / fSlow5);
		float fSlow7 = (1.0f / (((fSlow6 + 1.41421354f) / fSlow5) + 1.0f));
		float fSlow8 = (fSlow1 * float(fHslider3));
		float fSlow9 = (0.000818181841f * fSlow8);
		float fSlow10 = float(fButton0);
		float fSlow11 = (fConst8 * fSlow8);
		float fSlow12 = (((fSlow6 + -1.41421354f) / fSlow5) + 1.0f);
		float fSlow13 = (2.0f * (1.0f - (1.0f / FaustLagngaDSP_faustpower2_f(fSlow5))));
		float fSlow14 = (fConst12 * fSlow1);
		float fSlow15 = (fConst19 * fSlow1);
		float fSlow16 = (fConst23 * fSlow1);
		float fSlow17 = (fConst27 * fSlow1);
		float fSlow18 = (fConst31 * fSlow1);
		float fSlow19 = (fConst35 * fSlow1);
		float fSlow20 = (fConst39 * fSlow1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow10;
			float fTemp0 = (fSlow10 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			fVec1[0] = fTemp1;
			fVec2[0] = (fSlow9 * fTemp1);
			float fTempFTZ0 = ((fConst6 * fVec2[1]) + (fConst7 * ((fSlow11 * fTemp1) - (fConst9 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fRec3[0] - (fSlow7 * ((fSlow12 * fRec2[2]) + (fSlow13 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp2 = (fSlow7 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))));
			iRec4[0] = (((iRec4[1] + (iRec4[1] > 0)) * (fTemp1 <= fVec1[1])) + (fTemp1 > fVec1[1]));
			float fTemp3 = float(iRec4[0]);
			float fTemp4 = (1.0f - (0.0199999996f * std::max<float>(0.0f, std::min<float>((fConst14 * fTemp3), (1.0f - (fConst15 * (fTemp3 - fConst13)))))));
			float fTempFTZ2 = (fTemp2 - ((fConst11 * (fRec1[1] * std::cos((fSlow14 * fTemp4)))) + (fConst16 * fRec1[2])));
			fRec1[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp2 - ((fConst18 * (fRec5[1] * std::cos((fSlow15 * fTemp4)))) + (fConst20 * fRec5[2])));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp2 - ((fConst22 * (fRec6[1] * std::cos((fSlow16 * fTemp4)))) + (fConst24 * fRec6[2])));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp2 - ((fConst26 * (fRec7[1] * std::cos((fSlow17 * fTemp4)))) + (fConst28 * fRec7[2])));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp2 - ((fConst30 * (fRec8[1] * std::cos((fSlow18 * fTemp4)))) + (fConst32 * fRec8[2])));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp2 - ((fConst34 * (fRec9[1] * std::cos((fSlow19 * fTemp4)))) + (fConst36 * fRec9[2])));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp2 - ((fConst38 * (fRec10[1] * std::cos((fSlow20 * fTemp4)))) + (fConst40 * fRec10[2])));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp5 = float(tanhf(float((2.0f * (((((((fRec1[0] + (0.319999993f * (fRec5[0] - fRec5[2]))) + (0.119999997f * (fRec6[0] - fRec6[2]))) + (0.0700000003f * (fRec7[0] - fRec7[2]))) + (0.600000024f * (fRec8[0] - fRec8[2]))) + (0.180000007f * (fRec9[0] - fRec9[2]))) + (0.25f * (fRec10[0] - fRec10[2]))) - fRec1[2])))));
			fVec3[0] = fTemp5;
			float fTempFTZ9 = (0.0f - (fSlow3 * ((fSlow4 * fRec0[1]) - (fTemp5 + fVec3[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * fRec0[0]));
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			fVec2[1] = fVec2[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			iRec4[1] = iRec4[0];
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
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
