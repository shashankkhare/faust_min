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
name: "cowbell"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustCowbellDSP_H__
#define  __FaustCowbellDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustCowbellDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustCowbellDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustCowbellDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst1;
	float fConst2;
	int iVec0[2];
	FAUSTFLOAT fHslider3;
	float fConst3;
	float fRec1[2];
	float fVec1[2];
	float fRec2[2];
	float fVec2[2];
	float fConst4;
	int IOTA;
	float fVec3[512];
	float fVec4[512];
	float fConst5;
	float fConst6;
	FAUSTFLOAT fButton0;
	float fVec5[2];
	int iRec3[2];
	float fConst7;
	float fRec0[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "cowbell.dsp");
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
		m->declare("name", "cowbell");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (0.25f * fConst0);
		fConst3 = (1.0f / fConst0);
		fConst4 = (0.5f * fConst0);
		fConst5 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst6 = (1.0f / fConst5);
		fConst7 = (1.0f / std::max<float>(1.0f, (0.300000012f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fHslider3 = FAUSTFLOAT(560.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec2[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 512); l5 = (l5 + 1)) {
			fVec3[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 512); l6 = (l6 + 1)) {
			fVec4[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec5[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec3[l8] = 0;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec0[l9] = 0.0f;
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
	
	virtual FaustCowbellDSP* clone() {
		return new FaustCowbellDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("cowbell");
		ui_interface->addHorizontalSlider("clang_intensity", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(560.0f), FAUSTFLOAT(200.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = std::tan((fConst1 * ((200.0f * fSlow0) + 500.0f)));
		float fSlow2 = (1.0f / fSlow1);
		float fSlow3 = (((fSlow2 + 1.41421354f) / fSlow1) + 1.0f);
		float fSlow4 = (((fSlow0 * float(fHslider1)) * (((0.300000012f * fSlow0) + float(fHslider2)) + 1.0f)) / fSlow3);
		float fSlow5 = FaustCowbellDSP_faustpower2_f(fSlow1);
		float fSlow6 = (1.0f / fSlow5);
		float fSlow7 = float(fHslider3);
		float fSlow8 = std::max<float>(fSlow7, 23.4489498f);
		float fSlow9 = std::max<float>(20.0f, std::fabs(fSlow8));
		float fSlow10 = (1.0f / fSlow9);
		float fSlow11 = (fConst3 * fSlow9);
		float fSlow12 = std::max<float>((1.48000002f * fSlow7), 23.4489498f);
		float fSlow13 = std::max<float>(20.0f, std::fabs(fSlow12));
		float fSlow14 = (1.0f / fSlow13);
		float fSlow15 = (fConst3 * fSlow13);
		float fSlow16 = std::max<float>(0.0f, std::min<float>(2047.0f, (fConst4 / fSlow12)));
		float fSlow17 = std::floor(fSlow16);
		float fSlow18 = (fSlow16 - fSlow17);
		float fSlow19 = (fConst2 / fSlow13);
		int iSlow20 = int(fSlow16);
		int iSlow21 = (iSlow20 + 1);
		float fSlow22 = std::max<float>(0.0f, std::min<float>(2047.0f, (fConst4 / fSlow8)));
		float fSlow23 = std::floor(fSlow22);
		float fSlow24 = (fSlow23 + (1.0f - fSlow22));
		float fSlow25 = (fConst2 / fSlow9);
		int iSlow26 = int(fSlow22);
		float fSlow27 = (fSlow22 - fSlow23);
		int iSlow28 = (iSlow26 + 1);
		float fSlow29 = (fSlow17 + (1.0f - fSlow16));
		float fSlow30 = float(fButton0);
		float fSlow31 = (1.0f / fSlow3);
		float fSlow32 = (((fSlow2 + -1.41421354f) / fSlow1) + 1.0f);
		float fSlow33 = (2.0f * (1.0f - fSlow6));
		float fSlow34 = (0.0f - (2.0f / fSlow5));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			float fTemp0 = float(iVec0[1]);
			fRec1[0] = (fSlow11 + (fRec1[1] - std::floor((fSlow11 + fRec1[1]))));
			float fTemp1 = FaustCowbellDSP_faustpower2_f(((2.0f * fRec1[0]) + -1.0f));
			fVec1[0] = fTemp1;
			float fTemp2 = (fTemp1 - fVec1[1]);
			fRec2[0] = (fSlow15 + (fRec2[1] - std::floor((fSlow15 + fRec2[1]))));
			float fTemp3 = FaustCowbellDSP_faustpower2_f(((2.0f * fRec2[0]) + -1.0f));
			fVec2[0] = fTemp3;
			float fTemp4 = (fTemp3 - fVec2[1]);
			float fTemp5 = (fSlow19 * (fTemp0 * fTemp4));
			fVec3[(IOTA & 511)] = fTemp5;
			float fTemp6 = (fSlow25 * (fTemp0 * fTemp2));
			fVec4[(IOTA & 511)] = fTemp6;
			fVec5[0] = fSlow30;
			iRec3[0] = (((iRec3[1] + (iRec3[1] > 0)) * (fSlow30 <= fVec5[1])) + (fSlow30 > fVec5[1]));
			float fTemp7 = float(iRec3[0]);
			fRec0[0] = ((((fConst2 * (fTemp0 * ((fSlow10 * fTemp2) + (fSlow14 * fTemp4)))) - ((fSlow18 * fVec3[((IOTA - iSlow21) & 511)]) + (((fSlow24 * fVec4[((IOTA - iSlow26) & 511)]) + (fSlow27 * fVec4[((IOTA - iSlow28) & 511)])) + (fSlow29 * fVec3[((IOTA - iSlow20) & 511)])))) * std::max<float>(0.0f, std::min<float>((fConst6 * fTemp7), ((fConst7 * (fConst5 - fTemp7)) + 1.0f)))) - (fSlow31 * ((fSlow32 * fRec0[2]) + (fSlow33 * fRec0[1]))));
			output0[i0] = FAUSTFLOAT((fSlow4 * (((fSlow6 * fRec0[0]) + (fSlow34 * fRec0[1])) + (fSlow6 * fRec0[2]))));
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fVec1[1] = fVec1[0];
			fRec2[1] = fRec2[0];
			fVec2[1] = fVec2[0];
			IOTA = (IOTA + 1);
			fVec5[1] = fVec5[0];
			iRec3[1] = iRec3[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
