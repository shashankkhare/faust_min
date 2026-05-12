/* ------------------------------------------------------------
name: "bowl"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustBowlDSP_H__
#define  __FaustBowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustBowlDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustBowlDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustBowlDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	FAUSTFLOAT fHslider1;
	int iRec1[2];
	float fRec0[3];
	float fConst2;
	float fRec2[3];
	float fConst3;
	float fRec3[3];
	float fConst4;
	float fRec4[3];
	float fConst5;
	float fRec5[3];
	float fConst6;
	float fRec6[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("filename", "bowl.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
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
		m->declare("name", "bowl");
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
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (16.3676987f / fConst0);
		fConst2 = (16.3834057f / fConst0);
		fConst3 = (8.73362732f / fConst0);
		fConst4 = (8.74933529f / fConst0);
		fConst5 = (3.14787579f / fConst0);
		fConst6 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(220.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec1[l1] = 0;
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
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
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
	
	virtual FaustBowlDSP* clone() {
		return new FaustBowlDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("bowl");
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(220.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("rub", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("strike", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = std::tan((fConst1 * fSlow0));
		float fSlow2 = (1.0f / fSlow1);
		float fSlow3 = (((fSlow2 + 0.0199999996f) / fSlow1) + 1.0f);
		float fSlow4 = (fSlow1 * fSlow3);
		float fSlow5 = (1.0f / fSlow4);
		float fSlow6 = float(fButton0);
		float fSlow7 = (4.65661277e-12f * float(fHslider1));
		float fSlow8 = (1.0f / fSlow3);
		float fSlow9 = (((fSlow2 + -0.0199999996f) / fSlow1) + 1.0f);
		float fSlow10 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow1))));
		float fSlow11 = std::tan((fConst2 * fSlow0));
		float fSlow12 = (1.0f / fSlow11);
		float fSlow13 = (((fSlow12 + 0.0199999996f) / fSlow11) + 1.0f);
		float fSlow14 = (fSlow11 * fSlow13);
		float fSlow15 = (1.0f / fSlow14);
		float fSlow16 = (1.0f / fSlow13);
		float fSlow17 = (((fSlow12 + -0.0199999996f) / fSlow11) + 1.0f);
		float fSlow18 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow11))));
		float fSlow19 = (0.0f - (0.400000006f / fSlow14));
		float fSlow20 = std::tan((fConst3 * fSlow0));
		float fSlow21 = (1.0f / fSlow20);
		float fSlow22 = (((fSlow21 + 0.0199999996f) / fSlow20) + 1.0f);
		float fSlow23 = (fSlow20 * fSlow22);
		float fSlow24 = (1.0f / fSlow23);
		float fSlow25 = (1.0f / fSlow22);
		float fSlow26 = (((fSlow21 + -0.0199999996f) / fSlow20) + 1.0f);
		float fSlow27 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow20))));
		float fSlow28 = std::tan((fConst4 * fSlow0));
		float fSlow29 = (1.0f / fSlow28);
		float fSlow30 = (((fSlow29 + 0.0199999996f) / fSlow28) + 1.0f);
		float fSlow31 = (fSlow28 * fSlow30);
		float fSlow32 = (1.0f / fSlow31);
		float fSlow33 = (1.0f / fSlow30);
		float fSlow34 = (((fSlow29 + -0.0199999996f) / fSlow28) + 1.0f);
		float fSlow35 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow28))));
		float fSlow36 = (0.0f - (0.600000024f / fSlow31));
		float fSlow37 = std::tan((fConst5 * fSlow0));
		float fSlow38 = (1.0f / fSlow37);
		float fSlow39 = (((fSlow38 + 0.0199999996f) / fSlow37) + 1.0f);
		float fSlow40 = (1.0f / (fSlow37 * fSlow39));
		float fSlow41 = (0.0f - fSlow40);
		float fSlow42 = (1.0f / fSlow39);
		float fSlow43 = (((fSlow38 + -0.0199999996f) / fSlow37) + 1.0f);
		float fSlow44 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow37))));
		float fSlow45 = std::tan((fConst6 * fSlow0));
		float fSlow46 = (1.0f / fSlow45);
		float fSlow47 = (((fSlow46 + 0.0199999996f) / fSlow45) + 1.0f);
		float fSlow48 = (1.0f / (fSlow45 * fSlow47));
		float fSlow49 = (1.0f / fSlow47);
		float fSlow50 = (((fSlow46 + -0.0199999996f) / fSlow45) + 1.0f);
		float fSlow51 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow45))));
		float fSlow52 = (0.0f - fSlow48);
		float fSlow53 = (0.0f - (0.600000024f / fSlow23));
		float fSlow54 = (0.0f - (0.400000006f / fSlow4));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow6;
			float fTemp0 = (fSlow6 - fVec0[1]);
			iRec1[0] = ((1103515245 * iRec1[1]) + 12345);
			float fTemp1 = ((fTemp0 * float((fTemp0 > 0.0f))) + (fSlow7 * float(iRec1[0])));
			fRec0[0] = (fTemp1 - (fSlow8 * ((fSlow9 * fRec0[2]) + (fSlow10 * fRec0[1]))));
			fRec2[0] = (fTemp1 - (fSlow16 * ((fSlow17 * fRec2[2]) + (fSlow18 * fRec2[1]))));
			fRec3[0] = (fTemp1 - (fSlow25 * ((fSlow26 * fRec3[2]) + (fSlow27 * fRec3[1]))));
			fRec4[0] = (fTemp1 - (fSlow33 * ((fSlow34 * fRec4[2]) + (fSlow35 * fRec4[1]))));
			fRec5[0] = (fTemp1 - (fSlow42 * ((fSlow43 * fRec5[2]) + (fSlow44 * fRec5[1]))));
			fRec6[0] = (fTemp1 - (fSlow49 * ((fSlow50 * fRec6[2]) + (fSlow51 * fRec6[1]))));
			output0[i0] = FAUSTFLOAT((0.5f * ((0.400000006f * ((fSlow5 * fRec0[0]) + (fSlow15 * fRec2[0]))) + ((fSlow19 * fRec2[2]) + (((0.600000024f * ((fSlow24 * fRec3[0]) + (fSlow32 * fRec4[0]))) + ((fSlow36 * fRec4[2]) + (((fSlow41 * fRec5[2]) + (((fSlow48 * fRec6[0]) + (fSlow52 * fRec6[2])) + (fSlow40 * fRec5[0]))) + (fSlow53 * fRec3[2])))) + (fSlow54 * fRec0[2]))))));
			fVec0[1] = fVec0[0];
			iRec1[1] = iRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
		}
	}

};

#endif
