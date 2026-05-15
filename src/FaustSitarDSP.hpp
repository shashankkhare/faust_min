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
name: "sitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustSitarDSP_H__
#define  __FaustSitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustSitarDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSitarDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fVec0[2];
	float fRec1[2];
	FAUSTFLOAT fHslider1;
	int iRec2[2];
	float fConst4;
	float fConst5;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec3[2];
	float fConst6;
	int IOTA;
	float fRec0[8192];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "sitar.dsp");
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
		m->declare("name", "sitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		float fConst1 = (1.0f / std::tan((12566.3711f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = (1.0f - fConst1);
		fConst4 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst5 = (1.0f / fConst4);
		fConst6 = (1.0f / std::max<float>(1.0f, (0.0500000007f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(146.83000000000001f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec3[l4] = 0;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 8192); l5 = (l5 + 1)) {
			fRec0[l5] = 0.0f;
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
	
	virtual FaustSitarDSP* clone() {
		return new FaustSitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("sitar");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(146.830002f), FAUSTFLOAT(40.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("jivari", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("pluck", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst0 / float(fHslider0));
		float fSlow1 = std::floor(fSlow0);
		float fSlow2 = (fSlow1 + (1.0f - fSlow0));
		int iSlow3 = int(fSlow0);
		int iSlow4 = (std::min<int>(4097, std::max<int>(0, iSlow3)) + 1);
		float fSlow5 = (fSlow0 - fSlow1);
		int iSlow6 = (std::min<int>(4097, std::max<int>(0, (iSlow3 + 1))) + 1);
		float fSlow7 = float(fHslider1);
		float fSlow8 = float(fButton0);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTemp0 = ((fSlow2 * fRec0[((IOTA - iSlow4) & 8191)]) + (fSlow5 * fRec0[((IOTA - iSlow6) & 8191)]));
			fVec0[0] = fTemp0;
			fRec1[0] = (0.0f - (fConst2 * ((fConst3 * fRec1[1]) - (fTemp0 + fVec0[1]))));
			iRec2[0] = ((1103515245 * iRec2[1]) + 12345);
			fVec1[0] = fSlow8;
			iRec3[0] = (((iRec3[1] + (iRec3[1] > 0)) * (fSlow8 <= fVec1[1])) + (fSlow8 > fVec1[1]));
			float fTemp1 = float(iRec3[0]);
			fRec0[(IOTA & 8191)] = ((0.99000001f * (fRec1[0] * (1.0f - (fSlow7 * FaustSitarDSP_faustpower2_f(fRec1[0]))))) + (4.65661287e-10f * (float(iRec2[0]) * std::max<float>(0.0f, std::min<float>((fConst5 * fTemp1), ((fConst6 * (fConst4 - fTemp1)) + 1.0f))))));
			output0[i0] = FAUSTFLOAT((0.5f * fRec0[((IOTA - 0) & 8191)]));
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			fVec1[1] = fVec1[0];
			iRec3[1] = iRec3[0];
			IOTA = (IOTA + 1);
		}
	}

};

#endif
