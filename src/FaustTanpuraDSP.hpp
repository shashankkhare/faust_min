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
	int iRec8[2];
	
  public:
	
	int getNumInputsFaustTanpuraDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustTanpuraDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustTanpuraDSPSIG0(int sample_rate) {
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iVec4[l10] = 0;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iRec8[l11] = 0;
		}
	}
	
	void fillFaustTanpuraDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec4[0] = 1;
			iRec8[0] = ((iVec4[1] + iRec8[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec8[0])));
			iVec4[1] = iVec4[0];
			iRec8[1] = iRec8[0];
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
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fVec0[2];
	float fRec3[2];
	float fConst8;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	int iRec5[2];
	float fConst9;
	float fConst10;
	float fRec4[3];
	FAUSTFLOAT fHslider7;
	int iVec2[2];
	int iRec6[2];
	int IOTA;
	float fVec3[2048];
	float fRec2[2048];
	float fConst11;
	float fConst12;
	float fRec7[2];
	float fConst13;
	float fRec9[2];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec1[3];
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec10[3];
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec11[3];
	float fConst33;
	float fConst37;
	float fConst38;
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec12[3];
	float fConst45;
	float fConst46;
	float fConst47;
	float fConst48;
	float fConst49;
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
		float fConst1 = std::tan((7853.98145f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.285714298f) / fConst1) + 1.0f);
		fConst4 = (0.0500000007f / (fConst1 * fConst3));
		fConst5 = (0.0f - fConst4);
		float fConst6 = std::tan((4712.38916f / fConst0));
		float fConst7 = (1.0f / fConst6);
		fConst8 = (1.0f / (((fConst7 + 1.41421354f) / fConst6) + 1.0f));
		fConst9 = (((fConst7 + -1.41421354f) / fConst6) + 1.0f);
		fConst10 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst6))));
		fConst11 = std::exp((0.0f - (33.3333321f / fConst0)));
		fConst12 = (1.0f - fConst11);
		fConst13 = (1.0f / fConst0);
		fConst14 = (1.0f / fConst3);
		fConst15 = (((fConst2 + -0.285714298f) / fConst1) + 1.0f);
		fConst16 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst1))));
		float fConst17 = std::tan((4555.30957f / fConst0));
		float fConst18 = (1.0f / fConst17);
		float fConst19 = (((fConst18 + 0.333333343f) / fConst17) + 1.0f);
		fConst20 = (0.0799999982f / (fConst17 * fConst19));
		fConst21 = (0.0f - fConst20);
		fConst22 = (1.0f / fConst19);
		fConst23 = (((fConst18 + -0.333333343f) / fConst17) + 1.0f);
		fConst24 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst17))));
		float fConst25 = std::tan((2261.94678f / fConst0));
		float fConst26 = (1.0f / fConst25);
		float fConst27 = (((fConst26 + 0.200000003f) / fConst25) + 1.0f);
		float fConst28 = (fConst25 * fConst27);
		fConst29 = (1.0f / fConst28);
		fConst30 = (1.0f / fConst27);
		fConst31 = (((fConst26 + -0.200000003f) / fConst25) + 1.0f);
		fConst32 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst25))));
		fConst33 = (0.0f - (0.150000006f / fConst28));
		float fConst34 = std::tan((785.398193f / fConst0));
		float fConst35 = (1.0f / fConst34);
		float fConst36 = (((fConst35 + 0.333333343f) / fConst34) + 1.0f);
		fConst37 = (0.349999994f / (fConst34 * fConst36));
		fConst38 = (0.0f - fConst37);
		fConst39 = (1.0f / fConst36);
		fConst40 = (((fConst35 + -0.333333343f) / fConst34) + 1.0f);
		fConst41 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst34))));
		float fConst42 = std::tan((329.867218f / fConst0));
		float fConst43 = (1.0f / fConst42);
		float fConst44 = (((fConst43 + 0.333333343f) / fConst42) + 1.0f);
		fConst45 = (0.449999988f / (fConst42 * fConst44));
		fConst46 = (0.0f - fConst45);
		fConst47 = (1.0f / fConst44);
		fConst48 = (((fConst43 + -0.333333343f) / fConst42) + 1.0f);
		fConst49 = (2.0f * (1.0f - (1.0f / FaustTanpuraDSP_faustpower2_f(fConst42))));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(130.81f);
		fHslider2 = FAUSTFLOAT(24.0f);
		fHslider3 = FAUSTFLOAT(0.75f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fHslider5 = FAUSTFLOAT(0.050000000000000003f);
		fHslider6 = FAUSTFLOAT(0.80000000000000004f);
		fHslider7 = FAUSTFLOAT(0.029999999999999999f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec5[l3] = 0;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec2[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec6[l6] = 0;
		}
		IOTA = 0;
		for (int l7 = 0; (l7 < 2048); l7 = (l7 + 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2048); l8 = (l8 + 1)) {
			fRec2[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec1[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec10[l14] = 0.0f;
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
		ui_interface->addHorizontalSlider("excDur", &fHslider7, FAUSTFLOAT(0.0299999993f), FAUSTFLOAT(9.99999975e-05f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(9.99999975e-05f));
		ui_interface->addHorizontalSlider("excGain", &fHslider5, FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(130.809998f), FAUSTFLOAT(130.0f), FAUSTFLOAT(300.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider3, FAUSTFLOAT(0.75f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stringGainVal", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider2, FAUSTFLOAT(24.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(24.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider6, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (367.5f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::max<float>(40.0f, fSlow1);
		float fSlow3 = float(fHslider3);
		float fSlow4 = std::pow(0.00100000005f, (1.0f / (fSlow2 * std::max<float>(0.400000006f, (float(fHslider2) * (1.0f - (0.349999994f * fSlow3)))))));
		float fSlow5 = (fConst0 / fSlow2);
		int iSlow6 = int(fSlow5);
		float fSlow7 = float(iSlow6);
		float fSlow8 = (fSlow5 + (-0.499989986f - fSlow7));
		int iSlow9 = (std::min<int>(1024, std::max<int>(0, int(fSlow8))) + 1);
		float fSlow10 = (fSlow7 + std::floor(fSlow8));
		float fSlow11 = ((fSlow10 + (1.0f - fSlow5)) / (fSlow5 + (1.0f - fSlow10)));
		float fSlow12 = ((20.0f * fSlow3) + 1.0f);
		float fSlow13 = (1.0f / fSlow12);
		float fSlow14 = ((2.0f * fSlow3) + 1.0f);
		float fSlow15 = (1.0f / fSlow14);
		float fSlow16 = float(fButton0);
		float fSlow17 = (fConst8 * (((fSlow16 * float(fHslider4)) * float(fHslider5)) * float(fHslider6)));
		float fSlow18 = (1.0f / std::max<float>(1.0f, (fConst0 * float(fHslider7))));
		int iSlow19 = std::min<int>(16384, std::max<int>(0, iSlow6));
		float fSlow20 = (1350.0f * (fSlow3 / fSlow2));
		float fSlow21 = (fConst13 * fSlow1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTemp0 = fRec2[((IOTA - iSlow9) & 2047)];
			fVec0[0] = fTemp0;
			float fTempFTZ0 = (fVec0[1] - (fSlow11 * (fRec3[1] - fTemp0)));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp1 = ((0.00200000009f * fRec3[0]) + (0.998000026f * fRec3[1]));
			float fThen0 = (fSlow13 * float(tanhf(float((fSlow12 * fTemp1)))));
			float fElse0 = (fSlow15 * float(tanhf(float((fSlow14 * fTemp1)))));
			fVec1[0] = fSlow16;
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float fTempFTZ1 = ((4.65661287e-10f * float(iRec5[0])) - (fConst8 * ((fConst9 * fRec4[2]) + (fConst10 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			int iTemp2 = ((fSlow16 - fVec1[1]) > 0.0f);
			iVec2[0] = iTemp2;
			iRec6[0] = ((iTemp2 > iVec2[1]) + ((iTemp2 <= iVec2[1]) * (iRec6[1] + (iRec6[1] > 0))));
			float fTemp3 = (fSlow18 * float(iRec6[0]));
			fVec3[(IOTA & 2047)] = ((fSlow4 * ((fTemp1 > 0.0f) ? fElse0 : fThen0)) + (fSlow17 * ((fRec4[2] + (fRec4[0] + (2.0f * fRec4[1]))) * std::max<float>(0.0f, std::min<float>(fTemp3, (2.0f - fTemp3))))));
			float fTempFTZ2 = fVec3[((IOTA - iSlow19) & 2047)];
			fRec2[(IOTA & 2047)] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp4 = std::fabs(fRec2[((IOTA - 0) & 2047)]);
			float fTempFTZ3 = std::max<float>(fTemp4, ((fConst11 * fRec7[1]) + (fConst12 * fTemp4)));
			fRec7[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow21 + (fRec9[1] - std::floor((fSlow21 + fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp5 = std::max<float>(1.0f, ((fSlow20 * (fRec7[0] * ftbl0FaustTanpuraDSPSIG0[int((65536.0f * fRec9[0]))])) + 4.0f));
			float fTemp6 = (fTemp5 + 4.99999987e-06f);
			int iTemp7 = int(fTemp6);
			float fTemp8 = std::floor(fTemp6);
			float fTemp9 = ((fRec2[((IOTA - std::min<int>(1024, int(std::max<int>(0, int(iTemp7))))) & 2047)] * (0.0f - (fTemp5 + (-1.0f - fTemp8)))) + ((fTemp5 - fTemp8) * fRec2[((IOTA - std::min<int>(1024, int(std::max<int>(0, int((iTemp7 + 1)))))) & 2047)]));
			float fTempFTZ5 = (fTemp9 - (fConst14 * ((fConst15 * fRec1[2]) + (fConst16 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp10 = (fConst5 * fRec1[2]);
			float fTemp11 = (fConst4 * fRec1[0]);
			float fTempFTZ6 = (fTemp9 - (fConst22 * ((fConst23 * fRec10[2]) + (fConst24 * fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp12 = (fConst21 * fRec10[2]);
			float fTemp13 = (fConst20 * fRec10[0]);
			float fTempFTZ7 = (fTemp9 - (fConst30 * ((fConst31 * fRec11[2]) + (fConst32 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp14 = (0.150000006f * (fTemp9 + (fConst29 * fRec11[0])));
			float fTemp15 = (fConst33 * fRec11[2]);
			float fTempFTZ8 = (fTemp9 - (fConst39 * ((fConst40 * fRec12[2]) + (fConst41 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp16 = (fConst38 * fRec12[2]);
			float fTemp17 = (fConst37 * fRec12[0]);
			float fTempFTZ9 = (fTemp9 - (fConst47 * ((fConst48 * fRec13[2]) + (fConst49 * fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp18 = (fConst46 * fRec13[2]);
			float fTemp19 = (fConst45 * fRec13[0]);
			fVec5[0] = (fTemp10 + ((fTemp12 + ((fTemp14 + (fTemp15 + (fTemp16 + ((fTemp19 + fTemp18) + fTemp17)))) + fTemp13)) + fTemp11));
			float fTempFTZ10 = ((fTemp10 + (fTemp11 + (fTemp12 + (fTemp13 + (fTemp14 + (fTemp15 + (fTemp16 + (fTemp17 + (fTemp18 + ((0.995000005f * fRec0[1]) + fTemp19)))))))))) - fVec5[1]);
			fRec0[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (fRec0[0] / (std::fabs(fRec0[0]) + 1.0f))));
			fVec0[1] = fVec0[0];
			fRec3[1] = fRec3[0];
			fVec1[1] = fVec1[0];
			iRec5[1] = iRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			iVec2[1] = iVec2[0];
			iRec6[1] = iRec6[0];
			IOTA = (IOTA + 1);
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
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
