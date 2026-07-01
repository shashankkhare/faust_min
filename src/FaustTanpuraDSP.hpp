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
	float fConst6;
	float fConst7;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	float fRec3[2];
	float fConst8;
	FAUSTFLOAT fHslider1;
	float fConst9;
	float fRec4[2];
	float fRec5[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	int iRec6[2];
	float fConst10;
	float fConst11;
	float fConst12;
	float fRec8[2];
	int iVec2[2];
	int iRec7[2];
	float fConst13;
	int IOTA;
	float fRec2[16384];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec1[3];
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec9[3];
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec10[3];
	float fConst36;
	float fConst37;
	float fConst38;
	float fConst39;
	float fConst40;
	float fRec11[3];
	float fVec3[2];
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
		m->declare("options", "[midi:on][nvoices:4]");
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
		fConst10 = (0.0115f * fConst0);
		fConst11 = std::max<float>(1.0f, fConst10);
		fConst12 = (1.0f / fConst11);
		fConst13 = (1.0f / std::max<float>(1.0f, (0.00575000001f * fConst0)));
		fConst14 = (1.0f / fConst3);
		fConst15 = (((fConst2 + -0.333333343f) / fConst1) + 1.0f);
		fConst16 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst1))));
		float fConst17 = std::tan((2261.94678f / fConst0));
		float fConst18 = (1.0f / fConst17);
		float fConst19 = (((fConst18 + 0.200000003f) / fConst17) + 1.0f);
		fConst20 = (0.150000006f / (fConst17 * fConst19));
		fConst21 = (0.0f - fConst20);
		fConst22 = (1.0f / fConst19);
		fConst23 = (((fConst18 + -0.200000003f) / fConst17) + 1.0f);
		fConst24 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst17))));
		float fConst25 = std::tan((785.398193f / fConst0));
		float fConst26 = (1.0f / fConst25);
		float fConst27 = (((fConst26 + 0.333333343f) / fConst25) + 1.0f);
		fConst28 = (0.349999994f / (fConst25 * fConst27));
		fConst29 = (0.0f - fConst28);
		fConst30 = (1.0f / fConst27);
		fConst31 = (((fConst26 + -0.333333343f) / fConst25) + 1.0f);
		fConst32 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst25))));
		float fConst33 = std::tan((329.867218f / fConst0));
		float fConst34 = (1.0f / fConst33);
		float fConst35 = (((fConst34 + 0.333333343f) / fConst33) + 1.0f);
		fConst36 = (0.449999988f / (fConst33 * fConst35));
		fConst37 = (0.0f - fConst36);
		fConst38 = (1.0f / fConst35);
		fConst39 = (((fConst34 + -0.333333343f) / fConst33) + 1.0f);
		fConst40 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst33))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(130.81f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(0.40000000000000002f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec6[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec8[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iVec2[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec7[l8] = 0;
		}
		IOTA = 0;
		for (int l9 = 0; (l9 < 16384); l9 = (l9 + 1)) {
			fRec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec1[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fVec3[l14] = 0.0f;
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
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("excGain", &fHslider3, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(130.809998f), FAUSTFLOAT(130.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (14.5f * float(fHslider0));
		float fSlow1 = float(fButton0);
		float fSlow2 = float(fHslider1);
		float fSlow3 = (fConst8 * fSlow2);
		float fSlow4 = (1.39698392e-10f * ((fSlow2 * float(fHslider2)) * float(fHslider3)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow1;
			int iTemp0 = ((fSlow1 - fVec0[1]) > 0.0f);
			iVec1[0] = iTemp0;
			float fTempFTZ0 = ((fConst6 * fRec3[1]) + (fConst7 * float(iTemp0)));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow3 + (fConst9 * fRec4[1]));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp1 = std::max<float>(20.0f, fRec4[0]);
			float fTemp2 = std::max<float>(6.0f, ((fConst0 / fTemp1) + -2.0f));
			float fTemp3 = (fTemp2 + -0.999994993f);
			int iTemp4 = int(fTemp3);
			float fTemp5 = std::floor(fTemp3);
			float fTemp6 = (fTemp2 + (-1.0f - fTemp5));
			float fTemp7 = (fTemp2 + (-2.0f - fTemp5));
			float fTemp8 = (fTemp2 + (-3.0f - fTemp5));
			float fTemp9 = ((((fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, iTemp4)) + 1)) & 16383)] * (0.0f - fTemp6)) * (0.0f - (0.5f * fTemp7))) * (0.0f - (0.333333343f * fTemp8))) + ((fTemp2 - fTemp5) * ((((fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, (iTemp4 + 1))) + 1)) & 16383)] * (0.0f - fTemp7)) * (0.0f - (0.5f * fTemp8))) + (0.5f * ((fTemp6 * fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, (iTemp4 + 2))) + 1)) & 16383)]) * (0.0f - fTemp8)))) + (0.166666672f * ((fTemp6 * fTemp7) * fRec2[((IOTA - (std::min<int>(8192, std::max<int>(0, (iTemp4 + 3))) + 1)) & 16383)])))));
			float fTempFTZ2 = ((0.997551024f * fTemp9) - (0.0699428469f * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fThen0 = std::max<float>(0.0f, (fRec8[1] + -1.0f));
			float fTempFTZ3 = ((float((float((iTemp0 - iVec1[1])) > 0.0f)) > 0.0f) ? fConst10 : fThen0);
			fRec8[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			int iTemp10 = (fRec8[0] > 0.0f);
			iVec2[0] = iTemp10;
			iRec7[0] = (((iRec7[1] + (iRec7[1] > 0)) * (iTemp10 <= iVec2[1])) + (iTemp10 > iVec2[1]));
			float fTemp11 = float(iRec7[0]);
			float fTempFTZ4 = ((0.999599993f * (((1.0f - fRec3[0]) * ((0.0699428469f * fTemp9) + (0.997551024f * fRec5[1]))) * std::exp((0.0f - (0.119999997f / fTemp1))))) + (fSlow4 * ((float(iRec6[0]) * std::max<float>(0.0f, std::min<float>((fConst12 * fTemp11), ((fConst13 * (fConst11 - fTemp11)) + 1.0f)))) / fTemp1)));
			fRec2[(IOTA & 16383)] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp12 = (fSlow0 * fRec2[((IOTA - 0) & 16383)]);
			float fTempFTZ5 = (fTemp12 - (fConst14 * ((fConst15 * fRec1[2]) + (fConst16 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp13 = (fConst5 * fRec1[2]);
			float fTemp14 = (fConst4 * fRec1[0]);
			float fTempFTZ6 = (fTemp12 - (fConst22 * ((fConst23 * fRec9[2]) + (fConst24 * fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp15 = (fConst21 * fRec9[2]);
			float fTemp16 = (fConst20 * fRec9[0]);
			float fTempFTZ7 = (fTemp12 - (fConst30 * ((fConst31 * fRec10[2]) + (fConst32 * fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp17 = (fConst29 * fRec10[2]);
			float fTemp18 = (fConst28 * fRec10[0]);
			float fTempFTZ8 = (fTemp12 - (fConst38 * ((fConst39 * fRec11[2]) + (fConst40 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp19 = (fConst37 * fRec11[2]);
			float fTemp20 = (fConst36 * fRec11[0]);
			fVec3[0] = (fTemp13 + ((fTemp15 + ((fTemp17 + ((fTemp20 + fTemp19) + fTemp18)) + fTemp16)) + fTemp14));
			float fTempFTZ9 = ((fTemp13 + (fTemp14 + (fTemp15 + (fTemp16 + (fTemp17 + (fTemp18 + (fTemp19 + ((0.995000005f * fRec0[1]) + fTemp20)))))))) - fVec3[1]);
			fRec0[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] / (std::fabs(fRec0[0]) + 1.0f)));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			iRec6[1] = iRec6[0];
			fRec8[1] = fRec8[0];
			iVec2[1] = iVec2[0];
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
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
