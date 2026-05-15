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
name: "sax"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustSaxDSP_H__
#define  __FaustSaxDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

class FaustSaxDSPSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec18[2];
	
  public:
	
	int getNumInputsFaustSaxDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustSaxDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustSaxDSPSIG0(int sample_rate) {
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iVec0[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec18[l5] = 0;
		}
	}
	
	void fillFaustSaxDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			iVec0[0] = 1;
			iRec18[0] = ((iVec0[1] + iRec18[1]) % 65536);
			table[i1] = std::sin((9.58738019e-05f * float(iRec18[0])));
			iVec0[1] = iVec0[0];
			iRec18[1] = iRec18[0];
		}
	}

};

static FaustSaxDSPSIG0* newFaustSaxDSPSIG0() { return (FaustSaxDSPSIG0*)new FaustSaxDSPSIG0(); }
static void deleteFaustSaxDSPSIG0(FaustSaxDSPSIG0* dsp) { delete dsp; }

static float ftbl0FaustSaxDSPSIG0[65536];
static float FaustSaxDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSaxDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSaxDSP : public dsp {
	
 private:
	
	int iRec6[2];
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fButton0;
	float fRec13[2];
	float fRec12[2];
	float fRec14[2];
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fRec19[2];
	float fRec17[3];
	float fVec1[2];
	float fRec16[2];
	int IOTA;
	float fRec15[2048];
	float fConst3;
	float fConst4;
	float fVec2[2];
	float fRec11[2];
	float fRec2[2048];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "sax.dsp");
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
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "sax");
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
		FaustSaxDSPSIG0* sig0 = newFaustSaxDSPSIG0();
		sig0->instanceInitFaustSaxDSPSIG0(sample_rate);
		sig0->fillFaustSaxDSPSIG0(65536, ftbl0FaustSaxDSPSIG0);
		deleteFaustSaxDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (8.29071236f / fConst0);
		fConst2 = (1.0f / fConst0);
		fConst3 = (0.00882352982f * fConst0);
		fConst4 = (0.5f * fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.02f);
		fHslider3 = FAUSTFLOAT(5.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec6[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec13[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec12[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec14[l3] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec19[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec17[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec1[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec16[l9] = 0.0f;
		}
		IOTA = 0;
		for (int l10 = 0; (l10 < 2048); l10 = (l10 + 1)) {
			fRec15[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2048); l13 = (l13 + 1)) {
			fRec2[l13] = 0.0f;
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
	
	virtual FaustSaxDSP* clone() {
		return new FaustSaxDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("sax");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(440.0f), FAUSTFLOAT(50.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("vibrato_depth", &fHslider2, FAUSTFLOAT(0.0199999996f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("vibrato_rate", &fHslider3, FAUSTFLOAT(5.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.00499999989f * (float(fHslider0) * float(fButton0)));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fConst1 * fSlow1);
		float fSlow3 = float(fHslider2);
		float fSlow4 = (fConst2 * float(fHslider3));
		float fSlow5 = (fConst4 / fSlow1);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec6[0] = 0;
			fRec13[0] = (fSlow0 + (0.995000005f * fRec13[1]));
			fRec12[0] = ((fRec13[0] * fRec12[1]) + ((1.0f - fRec13[0]) * fRec11[1]));
			float fRec10 = (fRec12[0] + float(iRec6[1]));
			fRec14[0] = fRec0[1];
			fRec19[0] = (fSlow4 + (fRec19[1] - std::floor((fSlow4 + fRec19[1]))));
			float fTemp0 = ((fSlow3 * ftbl0FaustSaxDSPSIG0[int((65536.0f * fRec19[0]))]) + 1.0f);
			fRec17[0] = ((0.0299999993f * (0.150000006f - (0.850000024f * fRec14[1]))) - ((fRec17[1] * (0.0f - (1.99399996f * std::cos((fSlow2 * fTemp0))))) + (0.994009018f * fRec17[2])));
			float fTemp1 = std::max<float>(-1.0f, std::min<float>(1.0f, FaustSaxDSP_faustpower2_f(fRec17[0])));
			float fTemp2 = (0.850000024f * (fRec14[1] * (1.0f - fTemp1)));
			float fTemp3 = (0.150000006f * fTemp1);
			fVec1[0] = (fTemp3 + fTemp2);
			fRec16[0] = ((fTemp2 + ((0.995000005f * fRec16[1]) + fTemp3)) - fVec1[1]);
			fRec15[(IOTA & 2047)] = fRec16[0];
			float fTemp4 = (fSlow5 / fTemp0);
			float fTemp5 = (fTemp4 + -1.49999499f);
			int iTemp6 = int(fTemp5);
			int iTemp7 = (int(std::min<float>(fConst3, float(std::max<int>(0, iTemp6)))) + 1);
			float fTemp8 = std::floor(fTemp5);
			float fTemp9 = (fTemp4 + (-1.0f - fTemp8));
			float fTemp10 = (0.0f - fTemp9);
			float fTemp11 = (fTemp4 + (-2.0f - fTemp8));
			float fTemp12 = (0.0f - (0.5f * fTemp11));
			float fTemp13 = (fTemp4 + (-3.0f - fTemp8));
			float fTemp14 = (0.0f - (0.333333343f * fTemp13));
			float fTemp15 = (fTemp4 + (-4.0f - fTemp8));
			float fTemp16 = (0.0f - (0.25f * fTemp15));
			float fTemp17 = (fTemp4 - fTemp8);
			int iTemp18 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp6 + 1))))) + 1);
			float fTemp19 = (0.0f - fTemp11);
			float fTemp20 = (0.0f - (0.5f * fTemp13));
			float fTemp21 = (0.0f - (0.333333343f * fTemp15));
			int iTemp22 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp6 + 2))))) + 1);
			float fTemp23 = (0.0f - fTemp13);
			float fTemp24 = (0.0f - (0.5f * fTemp15));
			float fTemp25 = (fTemp9 * fTemp11);
			int iTemp26 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp6 + 3))))) + 1);
			float fTemp27 = (0.0f - fTemp15);
			float fTemp28 = (fTemp25 * fTemp13);
			int iTemp29 = (int(std::min<float>(fConst3, float(std::max<int>(0, (iTemp6 + 4))))) + 1);
			fVec2[0] = (((((fRec15[((IOTA - iTemp7) & 2047)] * fTemp10) * fTemp12) * fTemp14) * fTemp16) + (fTemp17 * ((((((fRec15[((IOTA - iTemp18) & 2047)] * fTemp19) * fTemp20) * fTemp21) + (0.5f * (((fTemp9 * fRec15[((IOTA - iTemp22) & 2047)]) * fTemp23) * fTemp24))) + (0.166666672f * ((fTemp25 * fRec15[((IOTA - iTemp26) & 2047)]) * fTemp27))) + (0.0416666679f * (fTemp28 * fRec15[((IOTA - iTemp29) & 2047)])))));
			fRec11[0] = fVec2[1];
			float fRec7 = fRec10;
			float fRec8 = fRec11[0];
			float fRec9 = fRec11[0];
			fRec2[(IOTA & 2047)] = fRec7;
			float fRec3 = (((((fTemp10 * fTemp12) * fTemp14) * fTemp16) * fRec2[((IOTA - iTemp7) & 2047)]) + (fTemp17 * ((((((fTemp19 * fTemp20) * fTemp21) * fRec2[((IOTA - iTemp18) & 2047)]) + (0.5f * (((fTemp9 * fTemp23) * fTemp24) * fRec2[((IOTA - iTemp22) & 2047)]))) + (0.166666672f * ((fTemp25 * fTemp27) * fRec2[((IOTA - iTemp26) & 2047)]))) + (0.0416666679f * (fTemp28 * fRec2[((IOTA - iTemp29) & 2047)])))));
			float fRec4 = fRec8;
			float fRec5 = fRec9;
			fRec0[0] = fRec3;
			float fRec1 = fRec5;
			output0[i0] = FAUSTFLOAT((0.5f * fRec1));
			iRec6[1] = iRec6[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec19[1] = fRec19[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fVec1[1] = fVec1[0];
			fRec16[1] = fRec16[0];
			IOTA = (IOTA + 1);
			fVec2[1] = fVec2[0];
			fRec11[1] = fRec11[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
