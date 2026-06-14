/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "churchbell"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustChurchbellDSP_H__
#define  __FaustChurchbellDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustChurchbellDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustChurchbellDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustChurchbellDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst4;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fRec2[3];
	float fConst9;
	float fConst10;
	FAUSTFLOAT fHslider1;
	float fConst11;
	float fRec1[3];
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec3[3];
	float fConst17;
	float fConst18;
	float fConst19;
	float fRec4[3];
	float fConst21;
	float fConst22;
	float fConst23;
	float fRec5[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec6[3];
	float fConst29;
	float fConst30;
	float fConst31;
	float fRec7[3];
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec8[3];
	float fVec1[2];
	float fRec0[2];
	float fConst36;
	FAUSTFLOAT fHslider2;
	float fConst37;
	float fRec9[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "churchbell.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "churchbell");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
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
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((1099.55737f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 1.41421354f) / fConst1) + 1.0f);
		fConst4 = (1.20000005f / fConst3);
		fConst5 = (1.0f / fConst3);
		fConst6 = (((fConst2 + -1.41421354f) / fConst1) + 1.0f);
		fConst7 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fConst1))));
		float fConst8 = std::pow(0.00100000005f, (0.100000001f / fConst0));
		fConst9 = (0.0f - (2.0f * fConst8));
		fConst10 = (18.849556f / fConst0);
		fConst11 = FaustChurchbellDSP_faustpower2_f(fConst8);
		float fConst12 = std::pow(0.00100000005f, (0.0666666701f / fConst0));
		fConst13 = (0.0f - (2.0f * fConst12));
		fConst14 = (15.0796452f / fConst0);
		fConst15 = FaustChurchbellDSP_faustpower2_f(fConst12);
		float fConst16 = std::pow(0.00100000005f, (0.0399999991f / fConst0));
		fConst17 = (0.0f - (2.0f * fConst16));
		fConst18 = (6.28318548f / fConst0);
		fConst19 = FaustChurchbellDSP_faustpower2_f(fConst16);
		float fConst20 = std::pow(0.00100000005f, (0.0500000007f / fConst0));
		fConst21 = (0.0f - (2.0f * fConst20));
		fConst22 = (12.566371f / fConst0);
		fConst23 = FaustChurchbellDSP_faustpower2_f(fConst20);
		float fConst24 = std::pow(0.00100000005f, (0.200000003f / fConst0));
		fConst25 = (0.0f - (2.0f * fConst24));
		fConst26 = (25.1327419f / fConst0);
		fConst27 = FaustChurchbellDSP_faustpower2_f(fConst24);
		float fConst28 = std::pow(0.00100000005f, (0.400000006f / fConst0));
		fConst29 = (0.0f - (2.0f * fConst28));
		fConst30 = (37.6991119f / fConst0);
		fConst31 = FaustChurchbellDSP_faustpower2_f(fConst28);
		float fConst32 = std::pow(0.00100000005f, (1.0f / fConst0));
		fConst33 = (0.0f - (2.0f * fConst32));
		fConst34 = (50.2654839f / fConst0);
		fConst35 = FaustChurchbellDSP_faustpower2_f(fConst32);
		fConst36 = (44.0999985f / fConst0);
		fConst37 = (1.0f - fConst36);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(200.0f);
		fHslider2 = FAUSTFLOAT(0.59999999999999998f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
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
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
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
	
	virtual FaustChurchbellDSP* clone() {
		return new FaustChurchbellDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("churchbell");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(200.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider2, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst4 * float(fHslider0));
		float fSlow1 = float(fButton0);
		int iSlow2 = (fSlow1 > 0.0f);
		float fSlow3 = float(fHslider1);
		float fSlow4 = (fConst9 * std::cos((fConst10 * fSlow3)));
		float fSlow5 = (fConst13 * std::cos((fConst14 * fSlow3)));
		float fSlow6 = (fConst17 * std::cos((fConst18 * fSlow3)));
		float fSlow7 = (fConst21 * std::cos((fConst22 * fSlow3)));
		float fSlow8 = (fConst25 * std::cos((fConst26 * fSlow3)));
		float fSlow9 = (fConst29 * std::cos((fConst30 * fSlow3)));
		float fSlow10 = (fConst33 * std::cos((fConst34 * fSlow3)));
		float fSlow11 = (fConst36 * float(fHslider2));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow1;
			fRec2[0] = (float((iSlow2 & (fVec0[1] <= 0.0f))) - (fConst5 * ((fConst6 * fRec2[2]) + (fConst7 * fRec2[1]))));
			float fTemp0 = (fSlow0 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))));
			fRec1[0] = (fTemp0 - ((fSlow4 * fRec1[1]) + (fConst11 * fRec1[2])));
			fRec3[0] = (fTemp0 - ((fSlow5 * fRec3[1]) + (fConst15 * fRec3[2])));
			fRec4[0] = (fTemp0 - ((fSlow6 * fRec4[1]) + (fConst19 * fRec4[2])));
			fRec5[0] = (fTemp0 - ((fSlow7 * fRec5[1]) + (fConst23 * fRec5[2])));
			fRec6[0] = (fTemp0 - ((fSlow8 * fRec6[1]) + (fConst27 * fRec6[2])));
			fRec7[0] = (fTemp0 - ((fSlow9 * fRec7[1]) + (fConst31 * fRec7[2])));
			fRec8[0] = (fTemp0 - ((fSlow10 * fRec8[1]) + (fConst35 * fRec8[2])));
			float fTemp1 = (((((0.600000024f * (fRec1[0] - fRec1[2])) + ((0.800000012f * (fRec3[0] - fRec3[2])) + ((0.899999976f * (fRec4[0] - fRec4[2])) + (fRec5[0] + fRec6[0])))) + (0.400000006f * (fRec7[0] - fRec7[2]))) + (0.200000003f * (fRec8[0] - fRec8[2]))) - (fRec5[2] + fRec6[2]));
			fVec1[0] = fTemp1;
			fRec0[0] = ((0.995000005f * fRec0[1]) + (0.142857149f * (fTemp1 - fVec1[1])));
			fRec9[0] = (fSlow11 + (fConst37 * fRec9[1]));
			output0[i0] = FAUSTFLOAT((float(tanhf(float(fRec0[0]))) * fRec9[0]));
			fVec0[1] = fVec0[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fVec1[1] = fVec1[0];
			fRec0[1] = fRec0[0];
			fRec9[1] = fRec9[0];
		}
	}

};

#endif
