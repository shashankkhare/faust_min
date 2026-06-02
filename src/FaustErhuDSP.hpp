/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "erhu"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustErhuDSP_H__
#define  __FaustErhuDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

class FaustErhuDSPSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec35[2];
	
  public:
	
	int getNumInputsFaustErhuDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustErhuDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustErhuDSPSIG0(int sample_rate) {
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iVec2[l17] = 0;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iRec35[l18] = 0;
		}
	}
	
	void fillFaustErhuDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec2[0] = 1;
			iRec35[0] = ((iVec2[1] + iRec35[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec35[0])));
			iVec2[1] = iVec2[0];
			iRec35[1] = iRec35[0];
		}
	}

};

static FaustErhuDSPSIG0* newFaustErhuDSPSIG0() { return (FaustErhuDSPSIG0*)new FaustErhuDSPSIG0(); }
static void deleteFaustErhuDSPSIG0(FaustErhuDSPSIG0* dsp) { delete dsp; }

static float FaustErhuDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustErhuDSPSIG0[65536];
static float FaustErhuDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustErhuDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustErhuDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	int iVec0[2];
	float fRec0[2];
	float fConst6;
	float fConst7;
	float fConst9;
	float fConst11;
	float fConst13;
	float fConst15;
	int iRec10[2];
	float fConst16;
	float fConst17;
	FAUSTFLOAT fHslider1;
	float fRec22[2];
	FAUSTFLOAT fHslider2;
	float fRec23[2];
	float fConst19;
	float fConst20;
	float fConst22;
	float fConst23;
	float fRec30[2];
	float fRec31[2];
	int iRec32[2];
	float fRec29[2];
	float fRec28[2];
	float fRec27[2];
	float fRec26[2];
	float fRec25[2];
	float fRec24[2];
	FAUSTFLOAT fHslider3;
	float fRec33[2];
	float fConst24;
	float fConst25;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec34[2];
	float fConst26;
	FAUSTFLOAT fHslider4;
	float fRec37[2];
	float fRec36[2];
	float fRec19[2];
	FAUSTFLOAT fHslider5;
	float fRec38[2];
	float fRec39[4];
	int IOTA;
	float fRec40[2048];
	float fVec3[2];
	FAUSTFLOAT fHslider6;
	float fRec41[2];
	float fVec4[2048];
	float fRec16[2048];
	float fRec18[2];
	float fRec15[4];
	float fRec6[2048];
	float fRec4[2];
	float fConst29;
	float fConst31;
	FAUSTFLOAT fHslider7;
	float fRec43[2];
	float fConst32;
	float fConst33;
	float fRec42[3];
	float fConst34;
	float fVec5[2];
	float fConst35;
	float fConst36;
	float fRec3[2];
	float fConst37;
	float fConst38;
	float fRec2[3];
	float fConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec1[3];
	float fConst47;
	float fConst48;
	float fConst49;
	float fConst50;
	float fConst51;
	float fRec44[3];
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fConst59;
	float fRec45[3];
	float fConst60;
	float fConst61;
	float fConst62;
	float fRec46[2];
	float fConst63;
	float fConst64;
	int iRec47[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "erhu.dsp");
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
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/resonbp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonbp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonbp:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "erhu");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
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
		FaustErhuDSPSIG0* sig0 = newFaustErhuDSPSIG0();
		sig0->instanceInitFaustErhuDSPSIG0(sample_rate);
		sig0->fillFaustErhuDSPSIG0(65536, ftbl0FaustErhuDSPSIG0);
		deleteFaustErhuDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		float fConst3 = std::tan((8796.45898f / fConst0));
		float fConst4 = (1.0f / fConst3);
		float fConst5 = (((fConst4 + 0.200000003f) / fConst3) + 1.0f);
		fConst6 = (0.400000006f / (fConst3 * fConst5));
		fConst7 = (0.0f - fConst6);
		float fConst8 = std::tan((1884.95557f / fConst0));
		fConst9 = (1.0f / fConst8);
		float fConst10 = (((fConst9 + 1.0f) / fConst8) + 1.0f);
		fConst11 = (1.0f / fConst10);
		float fConst12 = FaustErhuDSP_faustpower2_f(fConst8);
		fConst13 = (1.0f / fConst12);
		float fConst14 = (fConst9 + 1.0f);
		fConst15 = (0.0f - (1.0f / (fConst8 * fConst14)));
		fConst16 = (0.00882352982f * fConst0);
		fConst17 = (0.00147058826f * fConst0);
		float fConst18 = (1.0f / std::tan((6.28318548f / fConst0)));
		fConst19 = (1.0f / (fConst18 + 1.0f));
		fConst20 = (1.0f - fConst18);
		float fConst21 = (12.566371f / fConst0);
		fConst22 = std::sin(fConst21);
		fConst23 = std::cos(fConst21);
		fConst24 = std::exp((0.0f - (5.0f / fConst0)));
		fConst25 = (1.0f - fConst24);
		fConst26 = (1.0f / fConst0);
		float fConst27 = std::tan((7853.98145f / fConst0));
		float fConst28 = (1.0f / fConst27);
		fConst29 = (1.0f / (((fConst28 + 1.41421354f) / fConst27) + 1.0f));
		float fConst30 = FaustErhuDSP_faustpower2_f(fConst27);
		fConst31 = (1.0f / fConst30);
		fConst32 = (((fConst28 + -1.41421354f) / fConst27) + 1.0f);
		fConst33 = (2.0f * (1.0f - fConst31));
		fConst34 = (0.0f - (2.0f / fConst30));
		fConst35 = (1.0f / fConst14);
		fConst36 = (1.0f - fConst9);
		fConst37 = (((fConst9 + -1.0f) / fConst8) + 1.0f);
		fConst38 = (2.0f * (1.0f - fConst13));
		fConst39 = (0.0f - (2.0f / fConst12));
		fConst40 = (0.300000012f / FaustErhuDSP_faustpower2_f(fConst10));
		fConst41 = (1.0f / fConst5);
		fConst42 = (((fConst4 + -0.200000003f) / fConst3) + 1.0f);
		fConst43 = (2.0f * (1.0f - (1.0f / FaustErhuDSP_faustpower2_f(fConst3))));
		float fConst44 = std::tan((4869.46875f / fConst0));
		float fConst45 = (1.0f / fConst44);
		float fConst46 = (((fConst45 + 0.333333343f) / fConst44) + 1.0f);
		fConst47 = (0.600000024f / (fConst44 * fConst46));
		fConst48 = (0.0f - fConst47);
		fConst49 = (1.0f / fConst46);
		fConst50 = (((fConst45 + -0.333333343f) / fConst44) + 1.0f);
		fConst51 = (2.0f * (1.0f - (1.0f / FaustErhuDSP_faustpower2_f(fConst44))));
		float fConst52 = std::tan((2984.51294f / fConst0));
		float fConst53 = (1.0f / fConst52);
		float fConst54 = (((fConst53 + 0.25f) / fConst52) + 1.0f);
		fConst55 = (1.0f / (fConst52 * fConst54));
		fConst56 = (0.0f - fConst55);
		fConst57 = (1.0f / fConst54);
		fConst58 = (((fConst53 + -0.25f) / fConst52) + 1.0f);
		fConst59 = (2.0f * (1.0f - (1.0f / FaustErhuDSP_faustpower2_f(fConst52))));
		fConst60 = (0.150000006f / fConst10);
		fConst61 = std::max<float>(1.0f, (0.100000001f * fConst0));
		fConst62 = (1.0f / fConst61);
		fConst63 = (0.200000003f / std::max<float>(1.0f, (0.200000003f * fConst0)));
		fConst64 = (1.0f / std::max<float>(1.0f, (0.300000012f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.14999999999999999f);
		fHslider2 = FAUSTFLOAT(440.0f);
		fHslider3 = FAUSTFLOAT(0.02f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(6.0f);
		fHslider5 = FAUSTFLOAT(0.29999999999999999f);
		fHslider6 = FAUSTFLOAT(0.59999999999999998f);
		fHslider7 = FAUSTFLOAT(0.02f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec10[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec22[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec23[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec30[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec31[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec32[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec29[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec28[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec27[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec26[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec25[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec24[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec33[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec1[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec34[l16] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec37[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec36[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec19[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec38[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 4); l23 = (l23 + 1)) {
			fRec39[l23] = 0.0f;
		}
		IOTA = 0;
		for (int l24 = 0; (l24 < 2048); l24 = (l24 + 1)) {
			fRec40[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fVec3[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec41[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2048); l27 = (l27 + 1)) {
			fVec4[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2048); l28 = (l28 + 1)) {
			fRec16[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec18[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 4); l30 = (l30 + 1)) {
			fRec15[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2048); l31 = (l31 + 1)) {
			fRec6[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec4[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec43[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec42[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fVec5[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec3[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec2[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec1[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec44[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec45[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec46[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			iRec47[l42] = 0;
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
	
	virtual FaustErhuDSP* clone() {
		return new FaustErhuDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("erhu");
		ui_interface->addHorizontalSlider("bowPosition", &fHslider1, FAUSTFLOAT(0.150000006f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("bowPressure", &fHslider6, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("bowVelocity", &fHslider5, FAUSTFLOAT(0.300000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(440.0f), FAUSTFLOAT(80.0f), FAUSTFLOAT(1400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("noiseLvl", &fHslider7, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider3, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0500000007f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider4, FAUSTFLOAT(6.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(8.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = (fConst1 * float(fHslider1));
		float fSlow2 = (fConst1 * float(fHslider2));
		float fSlow3 = (fConst1 * float(fHslider3));
		float fSlow4 = float(fButton0);
		float fSlow5 = (fConst25 * fSlow4);
		float fSlow6 = (fConst1 * float(fHslider4));
		float fSlow7 = (fConst1 * float(fHslider5));
		float fSlow8 = (4.0f * fSlow4);
		float fSlow9 = (fConst1 * float(fHslider6));
		float fSlow10 = (4.65661287e-10f * fSlow4);
		float fSlow11 = (fConst1 * float(fHslider7));
		int iSlow12 = (fSlow4 == 0.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec10[0] = 0;
			float fTempFTZ1 = (float(iRec10[1]) - (0.989264667f * ((0.600000024f * fRec15[2]) + (0.200000003f * (fRec15[1] + fRec15[3])))));
			float fRec14 = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow1 + (fConst2 * fRec22[1]));
			fRec22[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp0 = (1.0f - fRec22[0]);
			float fTempFTZ3 = (fSlow2 + (fConst2 * fRec23[1]));
			fRec23[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = ((fConst22 * fRec31[1]) + (fConst23 * fRec30[1]));
			fRec30[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = ((float((1 - iVec0[1])) + (fConst23 * fRec31[1])) - (fConst22 * fRec30[1]));
			fRec31[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			int iTemp1 = ((fRec30[1] <= 0.0f) & (fRec30[0] > 0.0f));
			iRec32[0] = ((1103515245 * iRec32[1]) + 12345);
			float fTemp2 = float(iRec32[0]);
			float fTempFTZ6 = ((fRec29[1] * float((1 - iTemp1))) + (4.65661287e-10f * (fTemp2 * float(iTemp1))));
			fRec29[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (0.0f - (fConst19 * ((fConst20 * fRec28[1]) - (fRec29[0] + fRec29[1]))));
			fRec28[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (0.0f - (fConst19 * ((fConst20 * fRec27[1]) - (fRec28[0] + fRec28[1]))));
			fRec27[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (0.0f - (fConst19 * ((fConst20 * fRec26[1]) - (fRec27[0] + fRec27[1]))));
			fRec26[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (0.0f - (fConst19 * ((fConst20 * fRec25[1]) - (fRec26[0] + fRec26[1]))));
			fRec25[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (0.0f - (fConst19 * ((fConst20 * fRec24[1]) - (fRec25[0] + fRec25[1]))));
			fRec24[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp3 = (0.00200000009f * fRec24[0]);
			float fTempFTZ12 = (fSlow3 + (fConst2 * fRec33[1]));
			fRec33[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			fVec1[0] = fSlow4;
			float fTempFTZ13 = (fSlow5 + (fConst24 * fRec34[1]));
			fRec34[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fSlow6 + (fConst2 * fRec37[1]));
			fRec37[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp4 = (fRec36[1] + (fConst26 * fRec37[0]));
			float fTempFTZ15 = (fTemp4 - std::floor(fTemp4));
			fRec36[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp5 = ((fRec33[0] * fRec34[0]) * ftbl0FaustErhuDSPSIG0[int((65536.0f * fRec36[0]))]);
			float fTemp6 = ((340.0f / (fRec23[0] * ((fTemp3 + fTemp5) + 1.0f))) + -0.0799999982f);
			int iTemp7 = int(((fConst17 * (fTemp0 * fTemp6)) + -1.49999499f));
			float fTemp8 = ((340.0f / (fRec23[0] * ((fTemp3 + 1.0f) + fTemp5))) + -0.0799999982f);
			float fTemp9 = (fConst17 * (fTemp0 * fTemp8));
			float fTemp10 = (fTemp9 + -1.49999499f);
			float fTemp11 = std::floor(fTemp10);
			float fTemp12 = (fTemp9 + (-1.0f - fTemp11));
			float fTemp13 = (0.0f - fTemp12);
			float fTemp14 = (fTemp9 + (-2.0f - fTemp11));
			float fTemp15 = (0.0f - (0.5f * fTemp14));
			float fTemp16 = (fTemp9 + (-3.0f - fTemp11));
			float fTemp17 = (0.0f - (0.333333343f * fTemp16));
			float fTemp18 = (fTemp9 + (-4.0f - fTemp11));
			float fTemp19 = (0.0f - (0.25f * fTemp18));
			float fTemp20 = (fTemp9 - fTemp11);
			float fTemp21 = (0.0f - fTemp14);
			float fTemp22 = (0.0f - (0.5f * fTemp16));
			float fTemp23 = (0.0f - (0.333333343f * fTemp18));
			float fTemp24 = (0.0f - fTemp16);
			float fTemp25 = (0.0f - (0.5f * fTemp18));
			float fTemp26 = (fTemp12 * fTemp14);
			float fTemp27 = (0.0f - fTemp18);
			float fTemp28 = (fTemp26 * fTemp16);
			float fTempFTZ16 = (((((fRec6[((IOTA - (int(std::min<float>(fConst16, float(std::max<int>(0, int(iTemp7))))) + 1)) & 2047)] * fTemp13) * fTemp15) * fTemp17) * fTemp19) + (fTemp20 * ((((((fRec6[((IOTA - (int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp7 + 1)))))) + 1)) & 2047)] * fTemp21) * fTemp22) * fTemp23) + (0.5f * (((fTemp12 * fRec6[((IOTA - (int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp7 + 2)))))) + 1)) & 2047)]) * fTemp24) * fTemp25))) + (0.166666672f * ((fTemp26 * fRec6[((IOTA - (int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp7 + 3)))))) + 1)) & 2047)]) * fTemp27))) + (0.0416666679f * (fTemp28 * fRec6[((IOTA - (int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp7 + 4)))))) + 1)) & 2047)])))));
			fRec19[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fSlow7 + (fConst2 * fRec38[1]));
			fRec38[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec4[1];
			fRec39[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (-1.0f * (0.99880147f * ((0.800000012f * fRec39[2]) + (0.100000001f * (fRec39[1] + fRec39[3])))));
			fRec40[(IOTA & 2047)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			int iTemp29 = int(((fConst17 * (fRec22[0] * fTemp6)) + -1.49999499f));
			int iTemp30 = int(std::min<float>(fConst16, float(std::max<int>(0, int(iTemp29)))));
			float fTemp31 = (fConst17 * (fRec22[0] * fTemp8));
			float fTemp32 = std::floor((fTemp31 + -1.49999499f));
			float fTemp33 = (fTemp31 + (-1.0f - fTemp32));
			float fTemp34 = (0.0f - fTemp33);
			float fTemp35 = (fTemp31 + (-2.0f - fTemp32));
			float fTemp36 = (0.0f - (0.5f * fTemp35));
			float fTemp37 = (fTemp31 + (-3.0f - fTemp32));
			float fTemp38 = (0.0f - (0.333333343f * fTemp37));
			float fTemp39 = (fTemp31 + (-4.0f - fTemp32));
			float fTemp40 = (0.0f - (0.25f * fTemp39));
			float fTemp41 = (fTemp31 - fTemp32);
			int iTemp42 = int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp29 + 1))))));
			float fTemp43 = (0.0f - fTemp35);
			float fTemp44 = (0.0f - (0.5f * fTemp37));
			float fTemp45 = (0.0f - (0.333333343f * fTemp39));
			int iTemp46 = int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp29 + 2))))));
			float fTemp47 = (0.0f - fTemp37);
			float fTemp48 = (0.0f - (0.5f * fTemp39));
			float fTemp49 = (fTemp33 * fTemp35);
			int iTemp50 = int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp29 + 3))))));
			float fTemp51 = (0.0f - fTemp39);
			float fTemp52 = (fTemp49 * fTemp37);
			int iTemp53 = int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp29 + 4))))));
			fVec3[0] = (((((fRec40[((IOTA - (iTemp30 + 2)) & 2047)] * fTemp34) * fTemp36) * fTemp38) * fTemp40) + (fTemp41 * ((((((fRec40[((IOTA - (iTemp42 + 2)) & 2047)] * fTemp43) * fTemp44) * fTemp45) + (0.5f * (((fTemp33 * fRec40[((IOTA - (iTemp46 + 2)) & 2047)]) * fTemp47) * fTemp48))) + (0.166666672f * ((fTemp49 * fRec40[((IOTA - (iTemp50 + 2)) & 2047)]) * fTemp51))) + (0.0416666679f * (fTemp52 * fRec40[((IOTA - (iTemp53 + 2)) & 2047)])))));
			float fTemp54 = ((fSlow4 * fRec38[0]) - (fRec19[1] + fVec3[1]));
			float fTempFTZ20 = (fSlow9 + (fConst2 * fRec41[1]));
			fRec41[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTemp55 = (fTemp54 * std::min<float>(1.0f, (1.0f / FaustErhuDSP_faustpower4_f((std::fabs((fTemp54 * (5.0f - (fSlow8 * fRec41[0])))) + 0.75f)))));
			float fTempFTZ21 = (fRec19[1] + fTemp55);
			float fRec20 = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTemp56 = (fVec3[1] + fTemp55);
			fVec4[(IOTA & 2047)] = fTemp56;
			int iTemp57 = int(fTemp10);
			float fTempFTZ22 = (((((fTemp13 * fTemp15) * fTemp17) * fTemp19) * fVec4[((IOTA - int(std::min<float>(fConst16, float(std::max<int>(0, int(iTemp57)))))) & 2047)]) + (fTemp20 * ((((((fTemp21 * fTemp22) * fTemp23) * fVec4[((IOTA - int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp57 + 1))))))) & 2047)]) + (0.5f * (((fTemp12 * fTemp24) * fTemp25) * fVec4[((IOTA - int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp57 + 2))))))) & 2047)]))) + (0.166666672f * ((fTemp26 * fTemp27) * fVec4[((IOTA - int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp57 + 3))))))) & 2047)]))) + (0.0416666679f * (fTemp28 * fVec4[((IOTA - int(std::min<float>(fConst16, float(std::max<int>(0, int((iTemp57 + 4))))))) & 2047)])))));
			float fRec21 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec20;
			fRec16[(IOTA & 2047)] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (((((fTemp34 * fTemp36) * fTemp38) * fTemp40) * fRec16[((IOTA - (iTemp30 + 1)) & 2047)]) + (fTemp41 * ((((((fTemp43 * fTemp44) * fTemp45) * fRec16[((IOTA - (iTemp42 + 1)) & 2047)]) + (0.5f * (((fTemp33 * fTemp47) * fTemp48) * fRec16[((IOTA - (iTemp46 + 1)) & 2047)]))) + (0.166666672f * ((fTemp49 * fTemp51) * fRec16[((IOTA - (iTemp50 + 1)) & 2047)]))) + (0.0416666679f * (fTemp52 * fRec16[((IOTA - (iTemp53 + 1)) & 2047)])))));
			float fRec17 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec21;
			fRec18[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec18[1];
			fRec15[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec14;
			float fRec11 = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = fRec15[0];
			float fTemp58 = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fRec12 = fTemp58;
			float fRec13 = fTemp58;
			float fTempFTZ29 = fRec11;
			fRec6[(IOTA & 2047)] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fTempFTZ30 = fRec17;
			float fRec7 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTempFTZ31 = fRec12;
			float fRec8 = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = fRec13;
			float fRec9 = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = fRec7;
			fRec4[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = fRec9;
			float fRec5 = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (fSlow11 + (fConst2 * fRec43[1]));
			fRec43[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTempFTZ36 = ((fSlow10 * (fRec43[0] * fTemp2)) - (fConst29 * ((fConst32 * fRec42[2]) + (fConst33 * fRec42[1]))));
			fRec42[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTemp59 = (fRec5 + (fConst29 * (((fConst31 * fRec42[0]) + (fConst34 * fRec42[1])) + (fConst31 * fRec42[2]))));
			fVec5[0] = fTemp59;
			float fTempFTZ37 = ((fConst15 * fVec5[1]) - (fConst35 * ((fConst36 * fRec3[1]) - (fConst9 * fTemp59))));
			fRec3[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = (fRec3[0] - (fConst11 * ((fConst37 * fRec2[2]) + (fConst38 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTemp60 = (((fConst13 * fRec2[0]) + (fConst39 * fRec2[1])) + (fConst13 * fRec2[2]));
			float fTemp61 = (fTemp60 * (1.0f - (fConst40 * FaustErhuDSP_faustpower2_f(fTemp60))));
			float fTemp62 = (fConst11 * fTemp61);
			float fTempFTZ39 = (fTemp62 - (fConst41 * ((fConst42 * fRec1[2]) + (fConst43 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = (fTemp62 - (fConst49 * ((fConst50 * fRec44[2]) + (fConst51 * fRec44[1]))));
			fRec44[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = (fTemp62 - (fConst57 * ((fConst58 * fRec45[2]) + (fConst59 * fRec45[1]))));
			fRec45[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = (fSlow4 + (fRec46[1] * float((fVec1[1] >= fSlow4))));
			fRec46[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			iRec47[0] = (iSlow12 * (iRec47[1] + 1));
			output0[i0] = FAUSTFLOAT(std::max<float>(-1.0f, std::min<float>(1.0f, (0.479999989f * ((fRec0[0] * ((fConst7 * fRec1[2]) + ((fConst6 * fRec1[0]) + ((fConst48 * fRec44[2]) + ((fConst47 * fRec44[0]) + ((fConst56 * fRec45[2]) + ((fConst55 * fRec45[0]) + (fConst60 * fTemp61)))))))) * std::max<float>(0.0f, (std::min<float>((fConst62 * fRec46[0]), std::max<float>(((fConst63 * (fConst61 - fRec46[0])) + 1.0f), 0.800000012f)) * (1.0f - (fConst64 * float(iRec47[0]))))))))));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			iRec10[1] = iRec10[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec30[1] = fRec30[0];
			fRec31[1] = fRec31[0];
			iRec32[1] = iRec32[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec33[1] = fRec33[0];
			fVec1[1] = fVec1[0];
			fRec34[1] = fRec34[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec19[1] = fRec19[0];
			fRec38[1] = fRec38[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec39[j0] = fRec39[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec3[1] = fVec3[0];
			fRec41[1] = fRec41[0];
			fRec18[1] = fRec18[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec15[j1] = fRec15[(j1 - 1)];
			}
			fRec4[1] = fRec4[0];
			fRec43[1] = fRec43[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fVec5[1] = fVec5[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[1] = fRec46[0];
			iRec47[1] = iRec47[0];
		}
	}

};

#endif
