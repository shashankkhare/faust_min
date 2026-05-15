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
name: "piano"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustPianoDSP_H__
#define  __FaustPianoDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustPianoDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustPianoDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fVec1[2];
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fVec2[2];
	float fRec2[2];
	int IOTA;
	float fRec0[8192];
	float fConst2;
	float fConst3;
	float fRec3[2];
	float fConst4;
	FAUSTFLOAT fHslider4;
	float fConst5;
	int iRec4[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "piano.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "piano");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = std::max<float>(1.0f, (0.00499999989f * fConst0));
		fConst3 = (1.0f / fConst2);
		fConst4 = (1.0f / std::max<float>(1.0f, (0.200000003f * fConst0)));
		fConst5 = (1.0f / std::max<float>(1.0f, fConst0));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.10000000000000001f);
		fHslider3 = FAUSTFLOAT(440.0f);
		fHslider4 = FAUSTFLOAT(0.80000000000000004f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 8192); l5 = (l5 + 1)) {
			fRec0[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec4[l7] = 0;
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
	
	virtual FaustPianoDSP* clone() {
		return new FaustPianoDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("piano");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(4000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("hardness", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("stiffness", &fHslider2, FAUSTFLOAT(0.100000001f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("sustain", &fHslider4, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (2.0f * float(fHslider0));
		float fSlow1 = (1.0f / std::tan((fConst1 * ((6000.0f * float(fHslider1)) + 2000.0f))));
		float fSlow2 = (1.0f / (fSlow1 + 1.0f));
		float fSlow3 = (1.0f - fSlow1);
		float fSlow4 = float(fButton0);
		float fSlow5 = (1.0f / std::tan((fConst1 * (4000.0f - (1000.0f * float(fHslider2))))));
		float fSlow6 = (1.0f / (fSlow5 + 1.0f));
		float fSlow7 = (1.0f - fSlow5);
		float fSlow8 = (fConst0 / float(fHslider3));
		float fSlow9 = std::floor(fSlow8);
		float fSlow10 = (fSlow9 + (1.0f - fSlow8));
		int iSlow11 = int(fSlow8);
		int iSlow12 = (std::min<int>(4097, std::max<int>(0, iSlow11)) + 1);
		float fSlow13 = (fSlow8 - fSlow9);
		int iSlow14 = (std::min<int>(4097, std::max<int>(0, (iSlow11 + 1))) + 1);
		float fSlow15 = float(fHslider4);
		float fSlow16 = (fConst4 * (1.0f - fSlow15));
		int iSlow17 = (fSlow4 == 0.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow4;
			float fTemp0 = (fSlow4 - fVec0[1]);
			float fTemp1 = (fTemp0 * float((fTemp0 > 0.0f)));
			fVec1[0] = fTemp1;
			fRec1[0] = (0.0f - (fSlow2 * ((fSlow3 * fRec1[1]) - (fTemp1 + fVec1[1]))));
			float fTemp2 = ((fSlow10 * fRec0[((IOTA - iSlow12) & 8191)]) + (fSlow13 * fRec0[((IOTA - iSlow14) & 8191)]));
			fVec2[0] = fTemp2;
			fRec2[0] = (0.0f - (fSlow6 * ((fSlow7 * fRec2[1]) - (fTemp2 + fVec2[1]))));
			fRec0[(IOTA & 8191)] = (fRec1[0] + (0.99000001f * fRec2[0]));
			fRec3[0] = (fSlow4 + (fRec3[1] * float((fVec0[1] >= fSlow4))));
			iRec4[0] = (iSlow17 * (iRec4[1] + 1));
			output0[i0] = FAUSTFLOAT((fSlow0 * (fRec0[((IOTA - 0) & 8191)] * std::max<float>(0.0f, (std::min<float>((fConst3 * fRec3[0]), std::max<float>(((fSlow16 * (fConst2 - fRec3[0])) + 1.0f), fSlow15)) * (1.0f - (fConst5 * float(iRec4[0]))))))));
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fVec2[1] = fVec2[0];
			fRec2[1] = fRec2[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			iRec4[1] = iRec4[0];
		}
	}

};

#endif
