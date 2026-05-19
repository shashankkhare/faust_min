/* ------------------------------------------------------------
name: "ride"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustRideDSP_H__
#define  __FaustRideDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

class FaustRideDSPSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec2[2];
	
  public:
	
	int getNumInputsFaustRideDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustRideDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustRideDSPSIG0(int sample_rate) {
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec2[l3] = 0;
		}
	}
	
	void fillFaustRideDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec1[0] = 1;
			iRec2[0] = ((iVec1[1] + iRec2[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec2[0])));
			iVec1[1] = iVec1[0];
			iRec2[1] = iRec2[0];
		}
	}

};

static FaustRideDSPSIG0* newFaustRideDSPSIG0() { return (FaustRideDSPSIG0*)new FaustRideDSPSIG0(); }
static void deleteFaustRideDSPSIG0(FaustRideDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustRideDSPSIG0[65536];
static float FaustRideDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustRideDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustRideDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[2];
	float fConst5;
	float fConst6;
	float fRec3[2];
	float fConst7;
	float fRec4[2];
	float fConst8;
	float fRec5[2];
	float fConst9;
	float fRec6[2];
	float fConst10;
	float fRec7[2];
	float fConst11;
	float fRec8[2];
	float fConst12;
	float fConst13;
	float fConst14;
	float fRec1[3];
	float fConst15;
	float fConst16;
	float fRec9[2];
	float fConst17;
	float fConst18;
	float fConst19;
	FAUSTFLOAT fHslider3;
	float fRec11[2];
	float fRec10[3];
	float fConst23;
	float fConst24;
	float fRec13[2];
	float fConst25;
	float fRec14[2];
	float fRec12[2];
	float fRec15[2];
	float fConst27;
	int iRec17[2];
	float fConst28;
	float fConst29;
	float fConst30;
	float fRec16[3];
	float fConst31;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("filename", "ride.dsp");
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
		m->declare("filters.lib/name", "Faust Filters Library");
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
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "ride");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		FaustRideDSPSIG0* sig0 = newFaustRideDSPSIG0();
		sig0->instanceInitFaustRideDSPSIG0(sample_rate);
		sig0->fillFaustRideDSPSIG0(65536, ftbl0FaustRideDSPSIG0);
		deleteFaustRideDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::exp((0.0f - (24.3902435f / fConst0)));
		float fConst2 = std::tan((31415.9258f / fConst0));
		float fConst3 = (1.0f / fConst2);
		float fConst4 = (((fConst3 + 0.0833333358f) / fConst2) + 1.0f);
		fConst5 = (1.0f / (fConst2 * fConst4));
		fConst6 = (0.0410000011f / fConst0);
		fConst7 = (0.0560000017f / fConst0);
		fConst8 = (0.0829999968f / fConst0);
		fConst9 = (0.104999997f / fConst0);
		fConst10 = (0.166999996f / fConst0);
		fConst11 = (0.245000005f / fConst0);
		fConst12 = (1.0f / fConst4);
		fConst13 = (((fConst3 + -0.0833333358f) / fConst2) + 1.0f);
		fConst14 = (2.0f * (1.0f - (1.0f / FaustRideDSP_faustpower2_f(fConst2))));
		fConst15 = (0.0f - fConst5);
		fConst16 = std::exp((0.0f - (9.61538506f / fConst0)));
		fConst17 = (3.14159274f / fConst0);
		fConst18 = (44.0999985f / fConst0);
		fConst19 = (1.0f - fConst18);
		float fConst20 = std::tan((18849.5566f / fConst0));
		float fConst21 = (1.0f / fConst20);
		float fConst22 = (((fConst21 + 1.41421354f) / fConst20) + 1.0f);
		fConst23 = (2.0f / fConst22);
		fConst24 = std::exp((0.0f - (25.0f / fConst0)));
		fConst25 = std::exp((0.0f - (2.22222233f / fConst0)));
		float fConst26 = FaustRideDSP_faustpower2_f(fConst20);
		fConst27 = (1.0f / fConst26);
		fConst28 = (1.0f / fConst22);
		fConst29 = (((fConst21 + -1.41421354f) / fConst20) + 1.0f);
		fConst30 = (2.0f * (1.0f - fConst27));
		fConst31 = (0.0f - (2.0f / fConst26));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(5500.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec1[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec12[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iRec17[l18] = 0;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec16[l19] = 0.0f;
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
	
	virtual FaustRideDSP* clone() {
		return new FaustRideDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("ride");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(5500.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(10000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider2);
		float fSlow2 = (((fSlow0 * float(fHslider1)) * ((0.100000001f * fSlow0) + 1.0f)) * ((9.99999994e-09f * fSlow1) + 1.0f));
		float fSlow3 = float(fButton0);
		float fSlow4 = (fConst6 * fSlow1);
		float fSlow5 = (fConst7 * fSlow1);
		float fSlow6 = (fConst8 * fSlow1);
		float fSlow7 = (fConst9 * fSlow1);
		float fSlow8 = (fConst10 * fSlow1);
		float fSlow9 = (fConst11 * fSlow1);
		float fSlow10 = float(fHslider3);
		int iSlow11 = (fSlow10 >= 2.0f);
		int iSlow12 = (fSlow10 >= 1.0f);
		int iSlow13 = (fSlow10 >= 3.0f);
		int iThen2 = (iSlow12 ? 2000 : 4000);
		int iElse2 = (iSlow13 ? 20 : 5000);
		float fSlow14 = (fConst18 * float((iSlow11 ? iElse2 : iThen2)));
		float fThen5 = (iSlow12 ? 0.600000024f : 0.200000003f);
		float fElse5 = (iSlow13 ? 0.400000006f : 0.100000001f);
		float fSlow15 = (fConst18 * (iSlow11 ? fElse5 : fThen5));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow3;
			int iTemp0 = ((fSlow3 - fVec0[1]) > 0.0f);
			fRec0[0] = std::max<float>((fConst1 * fRec0[1]), float(iTemp0));
			fRec3[0] = (fSlow4 + (fRec3[1] - std::floor((fSlow4 + fRec3[1]))));
			fRec4[0] = (fSlow5 + (fRec4[1] - std::floor((fSlow5 + fRec4[1]))));
			fRec5[0] = (fSlow6 + (fRec5[1] - std::floor((fSlow6 + fRec5[1]))));
			fRec6[0] = (fSlow7 + (fRec6[1] - std::floor((fSlow7 + fRec6[1]))));
			fRec7[0] = (fSlow8 + (fRec7[1] - std::floor((fSlow8 + fRec7[1]))));
			fRec8[0] = (fSlow9 + (fRec8[1] - std::floor((fSlow9 + fRec8[1]))));
			float fTemp1 = (0.166666672f * (0.0f - (2.0f * (((((1.0f - (float((ftbl0FaustRideDSPSIG0[int((65536.0f * fRec3[0]))] > 0.0f)) + float((ftbl0FaustRideDSPSIG0[int((65536.0f * fRec4[0]))] > 0.0f)))) - float((ftbl0FaustRideDSPSIG0[int((65536.0f * fRec5[0]))] > 0.0f))) + (1.0f - float((ftbl0FaustRideDSPSIG0[int((65536.0f * fRec6[0]))] > 0.0f)))) - float((ftbl0FaustRideDSPSIG0[int((65536.0f * fRec7[0]))] > 0.0f))) + (1.0f - float((ftbl0FaustRideDSPSIG0[int((65536.0f * fRec8[0]))] > 0.0f)))))));
			fRec1[0] = (fTemp1 - (fConst12 * ((fConst13 * fRec1[2]) + (fConst14 * fRec1[1]))));
			float fTemp2 = float(iTemp0);
			fRec9[0] = std::max<float>((fConst16 * fRec9[1]), (0.400000006f * fTemp2));
			fRec11[0] = ((fConst19 * fRec11[1]) + fSlow14);
			float fTemp3 = std::tan((fConst17 * fRec11[0]));
			float fTemp4 = (1.0f / fTemp3);
			float fTemp5 = FaustRideDSP_faustpower2_f(fTemp3);
			float fTemp6 = (((fTemp4 + 1.41421354f) / fTemp3) + 1.0f);
			fRec10[0] = (fTemp1 - (((fRec10[2] * (((fTemp4 + -1.41421354f) / fTemp3) + 1.0f)) + (2.0f * (fRec10[1] * (1.0f - (1.0f / fTemp5))))) / fTemp6));
			fRec13[0] = std::max<float>((fConst24 * fRec13[1]), (2.5f * fTemp2));
			fRec14[0] = std::max<float>((fConst25 * fRec14[1]), fTemp2);
			fRec12[0] = ((fConst19 * fRec12[1]) + (fConst18 * (fRec13[0] + fRec14[0])));
			fRec15[0] = ((fConst19 * fRec15[1]) + fSlow15);
			iRec17[0] = ((1103515245 * iRec17[1]) + 12345);
			fRec16[0] = ((4.65661287e-10f * float(iRec17[0])) - (fConst28 * ((fConst29 * fRec16[2]) + (fConst30 * fRec16[1]))));
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow2 * (((3.0f * (fRec0[0] * ((fConst5 * fRec1[0]) + (fConst15 * fRec1[2])))) + (0.600000024f * ((fRec9[0] * (((fRec10[1] * (0.0f - (2.0f / fTemp5))) + (fRec10[0] / fTemp5)) + (fRec10[2] / fTemp5))) / fTemp6))) + (fConst23 * ((fRec12[0] * fRec15[0]) * (((fConst27 * fRec16[0]) + (fConst31 * fRec16[1])) + (fConst27 * fRec16[2]))))))))));
			fVec0[1] = fVec0[0];
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			iRec17[1] = iRec17[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
		}
	}

};

#endif
