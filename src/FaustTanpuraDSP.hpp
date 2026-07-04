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

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustTanpuraDSPSIG0 {
	
  private:
	
	int iVec4[2];
	int iRec9[2];
	
  public:
	
	int getNumInputsFaustTanpuraDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTanpuraDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTanpuraDSPSIG0(int sample_rate) {
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iVec4[l11] = 0;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec9[l12] = 0;
		}
	}
	
	void fillFaustTanpuraDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec4[0] = 1;
			iRec9[0] = ((iVec4[1] + iRec9[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec9[0])));
			iVec4[1] = iVec4[0];
			iRec9[1] = iRec9[0];
		}
	}

};

static FaustTanpuraDSPSIG0* newFaustTanpuraDSPSIG0() { return (FaustTanpuraDSPSIG0*)new FaustTanpuraDSPSIG0(); }
static void deleteFaustTanpuraDSPSIG0(FaustTanpuraDSPSIG0* dsp) { delete dsp; }

static float FaustTanpuraDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustTanpuraDSPSIG0[65536];

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
	FAUSTFLOAT fHslider1;
	float fConst7;
	float fRec4[2];
	float fVec0[2];
	float fRec3[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst10;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	int iRec6[2];
	float fConst11;
	float fConst12;
	float fRec5[3];
	FAUSTFLOAT fHslider7;
	int iVec2[2];
	int iRec7[2];
	float fConst13;
	int IOTA;
	float fVec3[8192];
	float fRec2[2048];
	float fConst14;
	float fConst15;
	float fRec8[2];
	float fConst16;
	float fRec10[2];
	float fConst17;
	float fConst18;
	float fConst19;
	float fRec1[3];
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec11[3];
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec12[3];
	float fConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec13[3];
	float fVec5[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.1");
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
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
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
		m->declare("fm.lib/copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tanpura");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("options", "[nvoices:4]");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
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
		FaustTanpuraDSPSIG0* sig0 = newFaustTanpuraDSPSIG0();
		sig0->instanceInitFaustTanpuraDSPSIG0(sample_rate);
		sig0->fillFaustTanpuraDSPSIG0(65536, ftbl0FaustTanpuraDSPSIG0);
		deleteFaustTanpuraDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::tan((4555.30957f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.333333343f) / fConst1) + 1.0f);
		fConst4 = (0.0799999982f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		fConst6 = (44.0999985f / fConst0);
		fConst7 = (1.0f - fConst6);
		float fConst8 = std::tan((18849.5566f / fConst0));
		float fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f / (((fConst9 + 1.41421354f) / fConst8) + 1.0f));
		fConst11 = (((fConst9 + -1.41421354f) / fConst8) + 1.0f);
		fConst12 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst8))));
		fConst13 = (0.5f * fConst0);
		fConst14 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst15 = (1.0f - fConst14);
		fConst16 = (1.0f / fConst0);
		fConst17 = (1.0f / fConst3);
		fConst18 = (((fConst2 + -0.333333343f) / fConst1) + 1.0f);
		fConst19 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst1))));
		float fConst20 = std::tan((2261.94678f / fConst0));
		float fConst21 = (1.0f / fConst20);
		float fConst22 = (((fConst21 + 0.200000003f) / fConst20) + 1.0f);
		fConst23 = (0.150000006f / (fConst20 * fConst22));
		fConst24 = (0.0f - fConst23);
		fConst25 = (1.0f / fConst22);
		fConst26 = (((fConst21 + -0.200000003f) / fConst20) + 1.0f);
		fConst27 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst20))));
		float fConst28 = std::tan((785.398193f / fConst0));
		float fConst29 = (1.0f / fConst28);
		float fConst30 = (((fConst29 + 0.333333343f) / fConst28) + 1.0f);
		fConst31 = (0.349999994f / (fConst28 * fConst30));
		fConst32 = (0.0f - fConst31);
		fConst33 = (1.0f / fConst30);
		fConst34 = (((fConst29 + -0.333333343f) / fConst28) + 1.0f);
		fConst35 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst28))));
		float fConst36 = std::tan((329.867218f / fConst0));
		float fConst37 = (1.0f / fConst36);
		float fConst38 = (((fConst37 + 0.333333343f) / fConst36) + 1.0f);
		fConst39 = (0.449999988f / (fConst36 * fConst38));
		fConst40 = (0.0f - fConst39);
		fConst41 = (1.0f / fConst38);
		fConst42 = (((fConst37 + -0.333333343f) / fConst36) + 1.0f);
		fConst43 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst36))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(130.81f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fHslider3 = FAUSTFLOAT(25.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(0.40000000000000002f);
		fHslider6 = FAUSTFLOAT(0.80000000000000004f);
		fHslider7 = FAUSTFLOAT(0.0115f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec4[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec6[l4] = 0;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iVec2[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec7[l7] = 0;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 8192); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2048); l9 = (l9 + 1)) {
			fRec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec1[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec11[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec13[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec5[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
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
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("excDur", &fHslider7, FAUSTFLOAT(0.0115f), FAUSTFLOAT(9.99999975e-05f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excGain", &fHslider5, FAUSTFLOAT(0.400000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(130.809998f), FAUSTFLOAT(130.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stringGainVal", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider3, FAUSTFLOAT(25.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(45.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider6, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (14.5f * float(fHslider0));
		float fSlow1 = (fConst6 * float(fHslider1));
		float fSlow2 = float(fHslider2);
		float fSlow3 = ((20.0f * fSlow2) + 1.0f);
		float fSlow4 = (1.0f / fSlow3);
		float fSlow5 = ((2.0f * fSlow2) + 1.0f);
		float fSlow6 = (1.0f / fSlow5);
		float fSlow7 = (1.0f / std::max<float>(0.400000006f, (float(fHslider3) * (1.0f - (0.349999994f * fSlow2)))));
		float fSlow8 = float(fButton0);
		float fSlow9 = (fConst10 * (((fSlow8 * float(fHslider4)) * float(fHslider5)) * float(fHslider6)));
		float fSlow10 = float(fHslider7);
		float fSlow11 = std::max<float>(1.0f, (fConst0 * fSlow10));
		float fSlow12 = (1.0f / fSlow11);
		float fSlow13 = (1.0f / std::max<float>(1.0f, (fConst13 * fSlow10)));
		float fSlow14 = (1350.0f * fSlow2);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow1 + (fConst7 * fRec4[1]));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = std::max<float>(40.0f, fRec4[0]);
			float fTemp1 = (fConst0 / fTemp0);
			int iTemp2 = int(fTemp1);
			float fTemp3 = float(iTemp2);
			float fTemp4 = (fTemp1 + (-0.499989986f - fTemp3));
			float fTemp5 = fRec2[((IOTA - (std::min<int>(1024, std::max<int>(0, int(fTemp4))) + 1)) & 2047)];
			fVec0[0] = fTemp5;
			float fTemp6 = (fTemp3 + std::floor(fTemp4));
			float fTempFTZ1 = (fVec0[1] - (((fTemp6 + (1.0f - fTemp1)) * (fRec3[1] - fTemp5)) / (fTemp1 + (1.0f - fTemp6))));
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp7 = ((0.00200000009f * fRec3[0]) + (0.998000026f * fRec3[1]));
			float fThen0 = (fSlow4 * float(tanhf(float((fSlow3 * fTemp7)))));
			float fElse0 = (fSlow6 * float(tanhf(float((fSlow5 * fTemp7)))));
			fVec1[0] = fSlow8;
			iRec6[0] = ((1103515245 * iRec6[1]) + 12345);
			float fTempFTZ2 = ((4.65661287e-10f * float(iRec6[0])) - (fConst10 * ((fConst11 * fRec5[2]) + (fConst12 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			int iTemp8 = ((fSlow8 - fVec1[1]) > 0.0f);
			iVec2[0] = iTemp8;
			iRec7[0] = ((iTemp8 > iVec2[1]) + ((iTemp8 <= iVec2[1]) * (iRec7[1] + (iRec7[1] > 0))));
			float fTemp9 = float(iRec7[0]);
			fVec3[(IOTA & 8191)] = ((((fTemp7 > 0.0f) ? fElse0 : fThen0) * std::pow(0.00100000005f, (fSlow7 / fTemp0))) + (fSlow9 * ((fRec5[2] + (fRec5[0] + (2.0f * fRec5[1]))) * std::max<float>(0.0f, std::min<float>((fSlow12 * fTemp9), (1.0f - (fSlow13 * (fTemp9 - fSlow11))))))));
			float fTempFTZ3 = fVec3[((IOTA - std::min<int>(16384, std::max<int>(0, iTemp2))) & 8191)];
			fRec2[(IOTA & 2047)] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp10 = std::fabs(fRec2[((IOTA - 0) & 2047)]);
			float fTempFTZ4 = std::max<float>(fTemp10, ((fConst14 * fRec8[1]) + (fConst15 * fTemp10)));
			fRec8[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp11 = (fRec10[1] + (fConst16 * fRec4[0]));
			float fTempFTZ5 = (fTemp11 - std::floor(fTemp11));
			fRec10[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp12 = std::max<float>(1.0f, ((fSlow14 * ((fRec8[0] * ftbl0FaustTanpuraDSPSIG0[int((65536.0f * fRec10[0]))]) / fTemp0)) + 4.0f));
			float fTemp13 = (fTemp12 + 4.99999987e-06f);
			int iTemp14 = int(fTemp13);
			float fTemp15 = std::floor(fTemp13);
			float fTemp16 = (fSlow0 * ((fRec2[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp14))))) & 2047)] * (0.0f - (fTemp12 + (-1.0f - fTemp15)))) + ((fTemp12 - fTemp15) * fRec2[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp14 + 1)))))) & 2047)])));
			float fTempFTZ6 = (fTemp16 - (fConst17 * ((fConst18 * fRec1[2]) + (fConst19 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp17 = (fConst5 * fRec1[2]);
			float fTemp18 = (fConst4 * fRec1[0]);
			float fTempFTZ7 = (fTemp16 - (fConst25 * ((fConst26 * fRec11[2]) + (fConst27 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp19 = (fConst24 * fRec11[2]);
			float fTemp20 = (fConst23 * fRec11[0]);
			float fTempFTZ8 = (fTemp16 - (fConst33 * ((fConst34 * fRec12[2]) + (fConst35 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp21 = (fConst32 * fRec12[2]);
			float fTemp22 = (fConst31 * fRec12[0]);
			float fTempFTZ9 = (fTemp16 - (fConst41 * ((fConst42 * fRec13[2]) + (fConst43 * fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp23 = (fConst40 * fRec13[2]);
			float fTemp24 = (fConst39 * fRec13[0]);
			fVec5[0] = (fTemp17 + ((fTemp19 + ((fTemp21 + ((fTemp24 + fTemp23) + fTemp22)) + fTemp20)) + fTemp18));
			float fTempFTZ10 = ((fTemp17 + (fTemp18 + (fTemp19 + (fTemp20 + (fTemp21 + (fTemp22 + (fTemp23 + ((0.995000005f * fRec0[1]) + fTemp24)))))))) - fVec5[1]);
			fRec0[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			output0[i0] = FAUSTFLOAT((fRec0[0] / (std::fabs(fRec0[0]) + 1.0f)));
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			fVec1[1] = fVec1[0];
			iRec6[1] = iRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			iVec2[1] = iVec2[0];
			iRec7[1] = iRec7[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fVec5[1] = fVec5[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
