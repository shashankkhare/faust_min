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
name: "bayan"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustBayanDSP_H__
#define  __FaustBayanDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBayanDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBayanDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fConst3;
	FAUSTFLOAT fHslider4;
	float fConst4;
	float fRec1[2];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[3];
	float fConst5;
	float fRec2[3];
	float fConst6;
	float fRec3[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("filename", "bayan.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "bayan");
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
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (6.28318548f / fConst0);
		fConst3 = (44.0999985f / fConst0);
		fConst4 = (1.0f - fConst3);
		fConst5 = (13.1946888f / fConst0);
		fConst6 = (20.1061935f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.90000000000000002f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(110.0f);
		fHslider4 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
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
	
	virtual FaustBayanDSP* clone() {
		return new FaustBayanDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bayan");
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(110.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.899999976f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("meend", &fHslider4, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (20.0f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (1.0f - (0.0500000007f * fSlow1));
		float fSlow3 = float(fHslider2);
		int iSlow4 = (fSlow3 >= 2.0f);
		int iSlow5 = (fSlow3 >= 1.0f);
		int iSlow6 = (fSlow3 >= 3.0f);
		float fThen2 = (iSlow5 ? 0.400000006f : 0.0500000007f);
		float fElse2 = (iSlow6 ? 0.0500000007f : 0.400000006f);
		float fSlow7 = (iSlow4 ? fElse2 : fThen2);
		float fSlow8 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (1.79999995f * fSlow7))));
		float fSlow9 = float(fHslider3);
		float fSlow10 = (fConst2 * fSlow9);
		float fSlow11 = (fConst3 * float(fHslider4));
		float fSlow12 = (0.00200000009f * fSlow1);
		float fSlow13 = float(fButton0);
		float fSlow14 = ((0.150000006f * fSlow1) + 1.0f);
		float fSlow15 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, fSlow7)));
		float fSlow16 = (fConst5 * fSlow9);
		float fThen5 = (iSlow5 ? 0.699999988f : 0.5f);
		float fElse5 = (iSlow6 ? 0.5f : 0.699999988f);
		float fSlow17 = (iSlow4 ? fElse5 : fThen5);
		float fSlow18 = ((0.300000012f * fSlow1) + 1.0f);
		float fSlow19 = std::pow(0.00100000005f, (fConst1 / std::max<float>(0.00100000005f, (0.5f * fSlow7))));
		float fSlow20 = (fConst6 * fSlow9);
		float fThen8 = (iSlow5 ? 0.400000006f : 0.200000003f);
		float fElse8 = (iSlow6 ? 0.200000003f : 0.400000006f);
		float fSlow21 = (iSlow4 ? fElse8 : fThen8);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec1[0] = (fSlow11 + (fConst4 * fRec1[1]));
			fVec0[0] = fSlow13;
			float fTemp0 = (fSlow13 - fVec0[1]);
			float fTemp1 = (fSlow12 * (fTemp0 * float((fTemp0 > 0.0f))));
			fRec0[0] = ((fSlow8 * ((2.0f * (std::cos((fSlow10 * fRec1[0])) * fRec0[1])) - (fSlow8 * fRec0[2]))) + fTemp1);
			fRec2[0] = (fTemp1 + (fSlow15 * ((2.0f * (std::cos((fSlow16 * fRec1[0])) * fRec2[1])) - (fSlow15 * fRec2[2]))));
			fRec3[0] = (fTemp1 + (fSlow19 * ((2.0f * (std::cos((fSlow20 * fRec1[0])) * fRec3[1])) - (fSlow19 * fRec3[2]))));
			output0[i0] = FAUSTFLOAT((fSlow0 * float(tanhf(float((1.04999995f * (((fSlow2 * fRec0[0]) + (fSlow14 * (fRec2[0] * fSlow17))) + (fSlow18 * (fRec3[0] * fSlow21)))))))));
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
		}
	}

};

#endif
