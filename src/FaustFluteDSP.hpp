/* ------------------------------------------------------------
name: "flute"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustFluteDSP_H__
#define  __FaustFluteDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustFluteDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustFluteDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustFluteDSP : public dsp {
	
 private:
	
	int iRec15[2];
	float fRec21[2];
	FAUSTFLOAT fButton0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec23[2];
	float fRec22[2];
	float fRec24[2];
	int IOTA;
	float fRec25[2048];
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fRec26[2];
	float fVec0[2];
	float fVec1[2048];
	float fConst5;
	float fVec2[2];
	float fRec20[2];
	float fRec11[2048];
	float fRec7[2];
	float fRec3[2048];
	float fRec1[2];
	float fRec2[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "flute.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "flute");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (0.00882352982f * fConst0);
		fConst4 = (0.000397058815f * fConst0);
		fConst5 = (0.00107352936f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(440.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec15[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec21[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec23[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec22[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec24[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 2048); l5 = (l5 + 1)) {
			fRec25[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec26[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec0[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2048); l8 = (l8 + 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec2[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec20[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2048); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec7[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2048); l13 = (l13 + 1)) {
			fRec3[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec1[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec2[l15] = 0.0f;
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
	
	virtual FaustFluteDSP* clone() {
		return new FaustFluteDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("flute");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(440.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.00100000005f * float(fButton0));
		float fSlow1 = (fConst1 * float(fHslider0));
		float fSlow2 = (fConst1 * float(fHslider1));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec15[0] = 0;
			fRec21[0] = ((0.699999988f * fRec21[1]) + (0.284999996f * fRec20[1]));
			float fRec19 = (fRec21[0] + float(iRec15[1]));
			fRec23[0] = (fSlow1 + (fConst2 * fRec23[1]));
			fRec22[0] = ((0.999000013f * fRec22[1]) + (fSlow0 * fRec23[0]));
			fRec24[0] = fRec1[1];
			fRec25[(IOTA & 2047)] = (0.949999988f * fRec24[1]);
			fRec26[0] = (fSlow2 + (fConst2 * fRec26[1]));
			float fTemp0 = ((340.0f / fRec26[0]) + 0.270000011f);
			float fTemp1 = (fConst4 * fTemp0);
			float fTemp2 = (fTemp1 + -1.49999499f);
			int iTemp3 = int(fTemp2);
			int iTemp4 = (int(std::min<float>(fConst3, float(std::max<int>(0, iTemp3)))) + 1);
			float fTemp5 = std::floor(fTemp2);
			float fTemp6 = (fTemp1 + (-1.0f - fTemp5));
			float fTemp7 = (0.0f - fTemp6);
			float fTemp8 = (fTemp1 + (-2.0f - fTemp5));
			float fTemp9 = (0.0f - (0.5f * fTemp8));
			float fTemp10 = (fTemp1 + (-3.0f - fTemp5));
			float fTemp11 = (0.0f - (0.333333343f * fTemp10));
			float fTemp12 = (fTemp1 + (-4.0f - fTemp5));
			float fTemp13 = (0.0f - (0.25f * fTemp12));
			float fTemp14 = (fTemp1 - fTemp5);
			int iTemp15 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp3 + 1))))) + 1);
			float fTemp16 = (0.0f - fTemp8);
			float fTemp17 = (0.0f - (0.5f * fTemp10));
			float fTemp18 = (0.0f - (0.333333343f * fTemp12));
			int iTemp19 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp3 + 2))))) + 1);
			float fTemp20 = (0.0f - fTemp10);
			float fTemp21 = (0.0f - (0.5f * fTemp12));
			float fTemp22 = (fTemp6 * fTemp8);
			int iTemp23 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp3 + 3))))) + 1);
			float fTemp24 = (0.0f - fTemp12);
			float fTemp25 = (fTemp22 * fTemp10);
			int iTemp26 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp3 + 4))))) + 1);
			fVec0[0] = (((((fRec25[((IOTA - iTemp4) & 2047)] * fTemp7) * fTemp9) * fTemp11) * fTemp13) + (fTemp14 * ((((((fRec25[((IOTA - iTemp15) & 2047)] * fTemp16) * fTemp17) * fTemp18) + (0.5f * (((fTemp6 * fRec25[((IOTA - iTemp19) & 2047)]) * fTemp20) * fTemp21))) + (0.166666672f * ((fTemp22 * fRec25[((IOTA - iTemp23) & 2047)]) * fTemp24))) + (0.0416666679f * (fTemp25 * fRec25[((IOTA - iTemp26) & 2047)])))));
			float fTemp27 = (fRec22[0] - (0.5f * fVec0[1]));
			float fTemp28 = ((0.5f * fRec7[1]) + std::max<float>(-1.0f, std::min<float>(1.0f, (fTemp27 * (FaustFluteDSP_faustpower2_f(fTemp27) + -1.0f)))));
			fVec1[(IOTA & 2047)] = fTemp28;
			float fTemp29 = (fConst5 * fTemp0);
			float fTemp30 = (fTemp29 + -1.49999499f);
			int iTemp31 = int(fTemp30);
			int iTemp32 = (int(std::min<float>(fConst3, float(std::max<int>(0, iTemp31)))) + 1);
			float fTemp33 = std::floor(fTemp30);
			float fTemp34 = (fTemp29 + (-1.0f - fTemp33));
			float fTemp35 = (0.0f - fTemp34);
			float fTemp36 = (fTemp29 + (-2.0f - fTemp33));
			float fTemp37 = (0.0f - (0.5f * fTemp36));
			float fTemp38 = (fTemp29 + (-3.0f - fTemp33));
			float fTemp39 = (0.0f - (0.333333343f * fTemp38));
			float fTemp40 = (fTemp29 + (-4.0f - fTemp33));
			float fTemp41 = (0.0f - (0.25f * fTemp40));
			float fTemp42 = (fTemp29 - fTemp33);
			int iTemp43 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp31 + 1))))) + 1);
			float fTemp44 = (0.0f - fTemp36);
			float fTemp45 = (0.0f - (0.5f * fTemp38));
			float fTemp46 = (0.0f - (0.333333343f * fTemp40));
			int iTemp47 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp31 + 2))))) + 1);
			float fTemp48 = (0.0f - fTemp38);
			float fTemp49 = (0.0f - (0.5f * fTemp40));
			float fTemp50 = (fTemp34 * fTemp36);
			int iTemp51 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp31 + 3))))) + 1);
			float fTemp52 = (0.0f - fTemp40);
			float fTemp53 = (fTemp50 * fTemp38);
			int iTemp54 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp31 + 4))))) + 1);
			fVec2[0] = (((((fVec1[((IOTA - iTemp32) & 2047)] * fTemp35) * fTemp37) * fTemp39) * fTemp41) + (fTemp42 * ((((((fVec1[((IOTA - iTemp43) & 2047)] * fTemp44) * fTemp45) * fTemp46) + (0.5f * (((fTemp34 * fVec1[((IOTA - iTemp47) & 2047)]) * fTemp48) * fTemp49))) + (0.166666672f * ((fTemp50 * fVec1[((IOTA - iTemp51) & 2047)]) * fTemp52))) + (0.0416666679f * (fTemp53 * fVec1[((IOTA - iTemp54) & 2047)])))));
			fRec20[0] = fVec2[1];
			float fRec16 = fRec19;
			float fRec17 = fRec20[0];
			float fRec18 = fRec20[0];
			fRec11[(IOTA & 2047)] = fRec16;
			float fRec12 = (((((fTemp35 * fTemp37) * fTemp39) * fTemp41) * fRec11[((IOTA - iTemp32) & 2047)]) + (fTemp42 * ((((((fTemp44 * fTemp45) * fTemp46) * fRec11[((IOTA - iTemp43) & 2047)]) + (0.5f * (((fTemp34 * fTemp48) * fTemp49) * fRec11[((IOTA - iTemp47) & 2047)]))) + (0.166666672f * ((fTemp50 * fTemp52) * fRec11[((IOTA - iTemp51) & 2047)]))) + (0.0416666679f * (fTemp53 * fRec11[((IOTA - iTemp54) & 2047)])))));
			float fRec13 = fRec17;
			float fRec14 = fRec18;
			fRec7[0] = fRec12;
			float fRec8 = fRec7[1];
			float fRec9 = fRec13;
			float fRec10 = fRec14;
			fRec3[(IOTA & 2047)] = fRec8;
			float fRec4 = (((((fTemp7 * fTemp9) * fTemp11) * fTemp13) * fRec3[((IOTA - iTemp4) & 2047)]) + (fTemp14 * ((((((fTemp16 * fTemp17) * fTemp18) * fRec3[((IOTA - iTemp15) & 2047)]) + (0.5f * (((fTemp6 * fTemp20) * fTemp21) * fRec3[((IOTA - iTemp19) & 2047)]))) + (0.166666672f * ((fTemp22 * fTemp24) * fRec3[((IOTA - iTemp23) & 2047)]))) + (0.0416666679f * (fTemp25 * fRec3[((IOTA - iTemp26) & 2047)])))));
			float fRec5 = fRec9;
			float fRec6 = fRec10;
			fRec1[0] = fRec4;
			fRec2[0] = fRec6;
			fRec0[0] = ((fRec2[0] + (0.995000005f * fRec0[1])) - fRec2[1]);
			output0[i0] = FAUSTFLOAT((0.5f * fRec0[0]));
			iRec15[1] = iRec15[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			IOTA = (IOTA + 1);
			fRec26[1] = fRec26[0];
			fVec0[1] = fVec0[0];
			fVec2[1] = fVec2[0];
			fRec20[1] = fRec20[0];
			fRec7[1] = fRec7[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
