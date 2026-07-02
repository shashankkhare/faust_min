/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tanpura"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustTanpuraDSP_H__
#define  __FaustTanpuraDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustTanpuraDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float FaustTanpuraDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTanpuraDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTanpuraDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	FAUSTFLOAT fHslider3;
	float fVec2[2];
	float fRec3[2];
	FAUSTFLOAT fHslider4;
	float fConst8;
	float fConst9;
	float fRec4[2];
	FAUSTFLOAT fHslider5;
	float fRec5[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	int iRec6[2];
	FAUSTFLOAT fHslider9;
	float fRec8[2];
	int iVec3[2];
	int iRec7[2];
	float fConst10;
	int IOTA;
	float fRec2[16384];
	float fConst11;
	float fConst12;
	float fConst13;
	float fRec1[3];
	float fConst17;
	float fConst18;
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec9[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec10[3];
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec11[3];
	float fVec4[2];
	float fRec0[2];
	
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
		m->declare("filename", "tanpura.dsp");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tanpura");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("options", "[nvoices:4]");
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
		float fConst1 = std::tan((4555.30957f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.333333343f) / fConst1) + 1.0f);
		fConst4 = (0.0799999982f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		fConst6 = std::exp((0.0f - (125.0f / fConst0)));
		fConst7 = (1.0f - fConst6);
		fConst8 = (44.0999985f / fConst0);
		fConst9 = (1.0f - fConst8);
		fConst10 = (0.5f * fConst0);
		fConst11 = (1.0f / fConst3);
		fConst12 = (((fConst2 + -0.333333343f) / fConst1) + 1.0f);
		fConst13 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst1))));
		float fConst14 = std::tan((2261.94678f / fConst0));
		float fConst15 = (1.0f / fConst14);
		float fConst16 = (((fConst15 + 0.200000003f) / fConst14) + 1.0f);
		fConst17 = (0.150000006f / (fConst14 * fConst16));
		fConst18 = (0.0f - fConst17);
		fConst19 = (1.0f / fConst16);
		fConst20 = (((fConst15 + -0.200000003f) / fConst14) + 1.0f);
		fConst21 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst14))));
		float fConst22 = std::tan((785.398193f / fConst0));
		float fConst23 = (1.0f / fConst22);
		float fConst24 = (((fConst23 + 0.333333343f) / fConst22) + 1.0f);
		fConst25 = (0.349999994f / (fConst22 * fConst24));
		fConst26 = (0.0f - fConst25);
		fConst27 = (1.0f / fConst24);
		fConst28 = (((fConst23 + -0.333333343f) / fConst22) + 1.0f);
		fConst29 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst22))));
		float fConst30 = std::tan((329.867218f / fConst0));
		float fConst31 = (1.0f / fConst30);
		float fConst32 = (((fConst31 + 0.333333343f) / fConst30) + 1.0f);
		fConst33 = (0.449999988f / (fConst30 * fConst32));
		fConst34 = (0.0f - fConst33);
		fConst35 = (1.0f / fConst32);
		fConst36 = (((fConst31 + -0.333333343f) / fConst30) + 1.0f);
		fConst37 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst30))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(130.81f);
		fHslider4 = FAUSTFLOAT(0.070000000000000007f);
		fHslider5 = FAUSTFLOAT(0.014999999999999999f);
		fHslider6 = FAUSTFLOAT(25.0f);
		fHslider7 = FAUSTFLOAT(0.80000000000000004f);
		fHslider8 = FAUSTFLOAT(0.40000000000000002f);
		fHslider9 = FAUSTFLOAT(0.0115f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec6[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec8[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iVec3[l8] = 0;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec7[l9] = 0;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 16384); l10 = (l10 + 1)) {
			fRec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec1[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec11[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec0[l16] = 0.0f;
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
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("dispersion", &fHslider4, FAUSTFLOAT(0.0700000003f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excDur", &fHslider9, FAUSTFLOAT(0.0115f), FAUSTFLOAT(9.99999975e-05f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excGain", &fHslider8, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(130.809998f), FAUSTFLOAT(130.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("jivariThreshold", &fHslider5, FAUSTFLOAT(0.0149999997f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("stringGainVal", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider6, FAUSTFLOAT(25.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(45.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider7, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (14.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = float(fHslider2);
		float fSlow3 = (fSlow1 * (1.0f - fSlow2));
		float fSlow4 = float(fButton0);
		float fSlow5 = float(fHslider3);
		float fSlow6 = float(fHslider4);
		float fSlow7 = std::sin(fSlow6);
		float fSlow8 = (fConst8 * fSlow5);
		float fSlow9 = float(fHslider5);
		float fSlow10 = (0.0f - fSlow9);
		float fSlow11 = (-1.0f * fSlow9);
		float fSlow12 = std::cos(fSlow6);
		float fSlow13 = (3.0f / std::max<float>(0.00100000005f, float(fHslider6)));
		float fSlow14 = (4.65661287e-10f * ((fSlow5 * float(fHslider7)) * float(fHslider8)));
		float fSlow15 = float(fHslider9);
		float fSlow16 = (fConst0 * fSlow15);
		float fSlow17 = std::max<float>(1.0f, fSlow16);
		float fSlow18 = (1.0f / fSlow17);
		float fSlow19 = (1.0f / std::max<float>(1.0f, (fConst10 * fSlow15)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow4;
			int iTemp0 = ((fSlow4 - fVec0[1]) > 0.0f);
			iVec1[0] = iTemp0;
			fVec2[0] = fSlow5;
			float fTempFTZ0 = ((fConst6 * fRec3[1]) + (fConst7 * float((float((iTemp0 + (fSlow5 != fVec2[1]))) > 0.0f))));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow8 + (fConst9 * fRec4[1]));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp1 = std::max<float>(20.0f, fRec4[0]);
			float fTemp2 = (fConst0 / fTemp1);
			float fTemp3 = fRec2[((IOTA - 1) & 16383)];
			int iTemp4 = int((std::max<float>(6.0f, (fTemp2 + (-2.0f - ((fTemp3 < fSlow10) ? 2.79999995f : 0.0f)))) + -0.999994993f));
			float fTemp5 = std::max<float>(6.0f, (fTemp2 + (-2.0f - ((fTemp3 < fSlow11) ? 2.79999995f : 0.0f))));
			float fTemp6 = std::floor((fTemp5 + -0.999994993f));
			float fTemp7 = (fTemp5 + (-1.0f - fTemp6));
			float fTemp8 = (fTemp5 + (-2.0f - fTemp6));
			float fTemp9 = (fTemp5 + (-3.0f - fTemp6));
			float fTemp10 = ((((fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, iTemp4)) + 1)) & 16383)] * (0.0f - fTemp7)) * (0.0f - (0.5f * fTemp8))) * (0.0f - (0.333333343f * fTemp9))) + ((fTemp5 - fTemp6) * ((((fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, (iTemp4 + 1))) + 1)) & 16383)] * (0.0f - fTemp8)) * (0.0f - (0.5f * fTemp9))) + (0.5f * ((fTemp7 * fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, (iTemp4 + 2))) + 1)) & 16383)]) * (0.0f - fTemp9)))) + (0.166666672f * ((fTemp7 * fTemp8) * fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, (iTemp4 + 3))) + 1)) & 16383)])))));
			float fTempFTZ2 = ((fSlow12 * fTemp10) - (fSlow7 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fThen2 = std::max<float>(0.0f, (fRec8[1] + -1.0f));
			float fTempFTZ3 = ((float((float((iTemp0 - iVec1[1])) > 0.0f)) > 0.0f) ? fSlow16 : fThen2);
			fRec8[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			int iTemp11 = (fRec8[0] > 0.0f);
			iVec3[0] = iTemp11;
			iRec7[0] = (((iRec7[1] + (iRec7[1] > 0)) * (iTemp11 <= iVec3[1])) + (iTemp11 > iVec3[1]));
			float fTemp12 = float(iRec7[0]);
			float fTempFTZ4 = ((0.999599993f * (((1.0f - fRec3[0]) * ((fSlow7 * fTemp10) + (fSlow12 * fRec5[1]))) * std::exp((0.0f - (fSlow13 / fTemp1))))) + (fSlow14 * ((float(iRec6[0]) * std::max<float>(0.0f, std::min<float>((fSlow18 * fTemp12), ((fSlow19 * (fSlow17 - fTemp12)) + 1.0f)))) / fTemp1)));
			fRec2[(IOTA & 16383)] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp13 = fRec2[((IOTA - 0) & 16383)];
			float fTemp14 = (fSlow1 * fTemp13);
			float fTemp15 = std::max<float>(0.0f, (0.0f - (fSlow9 + fTemp14)));
			float fTemp16 = (fSlow0 * ((fSlow3 * fTemp13) + (fSlow2 * (fTemp14 - (FaustTanpuraDSP_faustpower3_f(fTemp15) * ((52.5218735f * FaustTanpuraDSP_faustpower2_f(fTemp15)) + 9.43249989f))))));
			float fTempFTZ5 = (fTemp16 - (fConst11 * ((fConst12 * fRec1[2]) + (fConst13 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp17 = (fConst5 * fRec1[2]);
			float fTemp18 = (fConst4 * fRec1[0]);
			float fTempFTZ6 = (fTemp16 - (fConst19 * ((fConst20 * fRec9[2]) + (fConst21 * fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp19 = (fConst18 * fRec9[2]);
			float fTemp20 = (fConst17 * fRec9[0]);
			float fTempFTZ7 = (fTemp16 - (fConst27 * ((fConst28 * fRec10[2]) + (fConst29 * fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp21 = (fConst26 * fRec10[2]);
			float fTemp22 = (fConst25 * fRec10[0]);
			float fTempFTZ8 = (fTemp16 - (fConst35 * ((fConst36 * fRec11[2]) + (fConst37 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp23 = (fConst34 * fRec11[2]);
			float fTemp24 = (fConst33 * fRec11[0]);
			fVec4[0] = (fTemp17 + ((fTemp19 + ((fTemp21 + ((fTemp24 + fTemp23) + fTemp22)) + fTemp20)) + fTemp18));
			float fTempFTZ9 = ((fTemp17 + (fTemp18 + (fTemp19 + (fTemp20 + (fTemp21 + (fTemp22 + (fTemp23 + ((0.995000005f * fRec0[1]) + fTemp24)))))))) - fVec4[1]);
			fRec0[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] / (std::fabs(fRec0[0]) + 1.0f)));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fVec2[1] = fVec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			iRec6[1] = iRec6[0];
			fRec8[1] = fRec8[0];
			iVec3[1] = iVec3[0];
			iRec7[1] = iRec7[0];
			IOTA = (IOTA + 1);
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fVec4[1] = fVec4[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
