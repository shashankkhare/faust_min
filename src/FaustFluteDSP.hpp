/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
	FAUSTFLOAT fHslider2;
	float fRec27[2];
	float fVec0[2];
	float fVec1[2048];
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
		fConst4 = (0.00147058826f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.5f);
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
			fRec27[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec0[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2048); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec20[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec7[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2048); l14 = (l14 + 1)) {
			fRec3[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec1[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec0[l17] = 0.0f;
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
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mouthPosition", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("pressure", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fButton0);
		float fSlow1 = (fConst1 * float(fHslider0));
		float fSlow2 = (fConst1 * float(fHslider1));
		float fSlow3 = (fConst1 * float(fHslider2));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec15[0] = 0;
			fRec21[0] = ((0.699999988f * fRec21[1]) + (0.284999996f * fRec20[1]));
			float fRec19 = (fRec21[0] + float(iRec15[1]));
			fRec23[0] = (fSlow1 + (fConst2 * fRec23[1]));
			fRec22[0] = ((0.999000013f * fRec22[1]) + (0.00100000005f * std::min<float>(1.0f, (fSlow0 * fRec23[0]))));
			fRec24[0] = fRec1[1];
			fRec25[(IOTA & 2047)] = (0.949999988f * fRec24[1]);
			fRec26[0] = (fSlow2 + (fConst2 * fRec26[1]));
			float fTemp0 = ((340.0f / fRec26[0]) + 0.270000011f);
			fRec27[0] = (fSlow3 + (fConst2 * fRec27[1]));
			float fTemp1 = (0.400000006f * (fRec27[0] + -0.5f));
			float fTemp2 = (fConst4 * (fTemp0 * (fTemp1 + 0.270000011f)));
			float fTemp3 = (fTemp2 + -1.49999499f);
			int iTemp4 = int(fTemp3);
			int iTemp5 = (int(std::min<float>(fConst3, float(std::max<int>(0, iTemp4)))) + 1);
			float fTemp6 = std::floor(fTemp3);
			float fTemp7 = (fTemp2 + (-1.0f - fTemp6));
			float fTemp8 = (0.0f - fTemp7);
			float fTemp9 = (fTemp2 + (-2.0f - fTemp6));
			float fTemp10 = (0.0f - (0.5f * fTemp9));
			float fTemp11 = (fTemp2 + (-3.0f - fTemp6));
			float fTemp12 = (0.0f - (0.333333343f * fTemp11));
			float fTemp13 = (fTemp2 + (-4.0f - fTemp6));
			float fTemp14 = (0.0f - (0.25f * fTemp13));
			float fTemp15 = (fTemp2 - fTemp6);
			int iTemp16 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp4 + 1))))) + 1);
			float fTemp17 = (0.0f - fTemp9);
			float fTemp18 = (0.0f - (0.5f * fTemp11));
			float fTemp19 = (0.0f - (0.333333343f * fTemp13));
			int iTemp20 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp4 + 2))))) + 1);
			float fTemp21 = (0.0f - fTemp11);
			float fTemp22 = (0.0f - (0.5f * fTemp13));
			float fTemp23 = (fTemp7 * fTemp9);
			int iTemp24 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp4 + 3))))) + 1);
			float fTemp25 = (0.0f - fTemp13);
			float fTemp26 = (fTemp23 * fTemp11);
			int iTemp27 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp4 + 4))))) + 1);
			fVec0[0] = (((((fRec25[((IOTA - iTemp5) & 2047)] * fTemp8) * fTemp10) * fTemp12) * fTemp14) + (fTemp15 * ((((((fRec25[((IOTA - iTemp16) & 2047)] * fTemp17) * fTemp18) * fTemp19) + (0.5f * (((fTemp7 * fRec25[((IOTA - iTemp20) & 2047)]) * fTemp21) * fTemp22))) + (0.166666672f * ((fTemp23 * fRec25[((IOTA - iTemp24) & 2047)]) * fTemp25))) + (0.0416666679f * (fTemp26 * fRec25[((IOTA - iTemp27) & 2047)])))));
			float fTemp28 = (fRec22[0] - (0.5f * fVec0[1]));
			float fTemp29 = ((0.5f * fRec7[1]) + std::max<float>(-1.0f, std::min<float>(1.0f, (fTemp28 * (FaustFluteDSP_faustpower2_f(fTemp28) + -1.0f)))));
			fVec1[(IOTA & 2047)] = fTemp29;
			float fTemp30 = (fConst4 * (fTemp0 * (0.730000019f - fTemp1)));
			float fTemp31 = (fTemp30 + -1.49999499f);
			int iTemp32 = int(fTemp31);
			int iTemp33 = (int(std::min<float>(fConst3, float(std::max<int>(0, iTemp32)))) + 1);
			float fTemp34 = std::floor(fTemp31);
			float fTemp35 = (fTemp30 + (-1.0f - fTemp34));
			float fTemp36 = (0.0f - fTemp35);
			float fTemp37 = (fTemp30 + (-2.0f - fTemp34));
			float fTemp38 = (0.0f - (0.5f * fTemp37));
			float fTemp39 = (fTemp30 + (-3.0f - fTemp34));
			float fTemp40 = (0.0f - (0.333333343f * fTemp39));
			float fTemp41 = (fTemp30 + (-4.0f - fTemp34));
			float fTemp42 = (0.0f - (0.25f * fTemp41));
			float fTemp43 = (fTemp30 - fTemp34);
			int iTemp44 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp32 + 1))))) + 1);
			float fTemp45 = (0.0f - fTemp37);
			float fTemp46 = (0.0f - (0.5f * fTemp39));
			float fTemp47 = (0.0f - (0.333333343f * fTemp41));
			int iTemp48 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp32 + 2))))) + 1);
			float fTemp49 = (0.0f - fTemp39);
			float fTemp50 = (0.0f - (0.5f * fTemp41));
			float fTemp51 = (fTemp35 * fTemp37);
			int iTemp52 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp32 + 3))))) + 1);
			float fTemp53 = (0.0f - fTemp41);
			float fTemp54 = (fTemp51 * fTemp39);
			int iTemp55 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp32 + 4))))) + 1);
			fVec2[0] = (((((fVec1[((IOTA - iTemp33) & 2047)] * fTemp36) * fTemp38) * fTemp40) * fTemp42) + (fTemp43 * ((((((fVec1[((IOTA - iTemp44) & 2047)] * fTemp45) * fTemp46) * fTemp47) + (0.5f * (((fTemp35 * fVec1[((IOTA - iTemp48) & 2047)]) * fTemp49) * fTemp50))) + (0.166666672f * ((fTemp51 * fVec1[((IOTA - iTemp52) & 2047)]) * fTemp53))) + (0.0416666679f * (fTemp54 * fVec1[((IOTA - iTemp55) & 2047)])))));
			fRec20[0] = fVec2[1];
			float fRec16 = fRec19;
			float fRec17 = fRec20[0];
			float fRec18 = fRec20[0];
			fRec11[(IOTA & 2047)] = fRec16;
			float fRec12 = (((((fTemp36 * fTemp38) * fTemp40) * fTemp42) * fRec11[((IOTA - iTemp33) & 2047)]) + (fTemp43 * ((((((fTemp45 * fTemp46) * fTemp47) * fRec11[((IOTA - iTemp44) & 2047)]) + (0.5f * (((fTemp35 * fTemp49) * fTemp50) * fRec11[((IOTA - iTemp48) & 2047)]))) + (0.166666672f * ((fTemp51 * fTemp53) * fRec11[((IOTA - iTemp52) & 2047)]))) + (0.0416666679f * (fTemp54 * fRec11[((IOTA - iTemp55) & 2047)])))));
			float fRec13 = fRec17;
			float fRec14 = fRec18;
			fRec7[0] = fRec12;
			float fRec8 = fRec7[1];
			float fRec9 = fRec13;
			float fRec10 = fRec14;
			fRec3[(IOTA & 2047)] = fRec8;
			float fRec4 = (((((fTemp8 * fTemp10) * fTemp12) * fTemp14) * fRec3[((IOTA - iTemp5) & 2047)]) + (fTemp15 * ((((((fTemp17 * fTemp18) * fTemp19) * fRec3[((IOTA - iTemp16) & 2047)]) + (0.5f * (((fTemp7 * fTemp21) * fTemp22) * fRec3[((IOTA - iTemp20) & 2047)]))) + (0.166666672f * ((fTemp23 * fTemp25) * fRec3[((IOTA - iTemp24) & 2047)]))) + (0.0416666679f * (fTemp26 * fRec3[((IOTA - iTemp27) & 2047)])))));
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
			fRec27[1] = fRec27[0];
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
