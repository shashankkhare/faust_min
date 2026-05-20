/* ------------------------------------------------------------
name: "singing_bowl"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustSinging_bowlDSP_H__
#define  __FaustSinging_bowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustSinging_bowlDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustSinging_bowlDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float FaustSinging_bowlDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustSinging_bowlDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustSinging_bowlDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec1[2];
	int iRec2[2];
	float fVec1[2];
	float fRec0[3];
	float fConst3;
	float fRec3[3];
	float fConst4;
	float fRec4[3];
	float fConst5;
	float fRec5[3];
	float fConst6;
	float fRec6[3];
	float fConst7;
	float fConst8;
	FAUSTFLOAT fHslider2;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst19;
	float fRec8[5];
	float fRec7[3];
	float fConst23;
	float fConst24;
	float fConst25;
	float fRec9[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("filename", "singing_bowl.dsp");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/tf2sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "singing_bowl");
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
		fConst1 = (3.14159274f / fConst0);
		fConst2 = std::exp((0.0f - (125.0f / fConst0)));
		fConst3 = (7.28849506f / fConst0);
		fConst4 = (12.4092913f / fConst0);
		fConst5 = (17.0588474f / fConst0);
		fConst6 = (3.76991129f / fConst0);
		fConst7 = (1.0f / fConst0);
		fConst8 = FaustSinging_bowlDSP_faustpower2_f(fConst7);
		float fConst9 = std::tan((6.28318548f / fConst0));
		float fConst10 = (fConst0 * fConst9);
		fConst11 = (2.0f * fConst10);
		fConst12 = (0.5f / fConst10);
		fConst13 = (4.0f * (FaustSinging_bowlDSP_faustpower2_f(fConst0) * fConst9));
		fConst14 = (5.6548667f / fConst0);
		fConst15 = (11.3137083f / fConst0);
		fConst16 = FaustSinging_bowlDSP_faustpower3_f(fConst7);
		fConst17 = (4.0f * fConst7);
		fConst18 = (22.6274166f / fConst0);
		fConst19 = (6.0f * fConst8);
		float fConst20 = std::tan((25132.7422f / fConst0));
		float fConst21 = (1.0f / fConst20);
		float fConst22 = (fConst21 + 1.0f);
		fConst23 = (1.0f / (fConst20 * fConst22));
		fConst24 = (0.0f - fConst23);
		fConst25 = ((1.0f - fConst21) / fConst22);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fHslider1 = FAUSTFLOAT(110.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
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
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec0[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec3[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 5); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
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
	
	virtual FaustSinging_bowlDSP* clone() {
		return new FaustSinging_bowlDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("singing_bowl");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(110.0f), FAUSTFLOAT(60.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("rub_intensity", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.800000012f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::tan((fConst1 * fSlow1));
		float fSlow3 = (1.0f / fSlow2);
		float fSlow4 = (((fSlow3 + 0.0250000004f) / fSlow2) + 1.0f);
		float fSlow5 = (1.0f / (fSlow2 * fSlow4));
		float fSlow6 = float(fButton0);
		float fSlow7 = (1.0f / fSlow4);
		float fSlow8 = (((fSlow3 + -0.0250000004f) / fSlow2) + 1.0f);
		float fSlow9 = (2.0f * (1.0f - (1.0f / FaustSinging_bowlDSP_faustpower2_f(fSlow2))));
		float fSlow10 = (0.0f - fSlow5);
		float fSlow11 = std::tan((fConst3 * fSlow1));
		float fSlow12 = (1.0f / fSlow11);
		float fSlow13 = (((fSlow12 + 0.0181818176f) / fSlow11) + 1.0f);
		float fSlow14 = (1.0f / (fSlow11 * fSlow13));
		float fSlow15 = (1.0f / fSlow13);
		float fSlow16 = (((fSlow12 + -0.0181818176f) / fSlow11) + 1.0f);
		float fSlow17 = (2.0f * (1.0f - (1.0f / FaustSinging_bowlDSP_faustpower2_f(fSlow11))));
		float fSlow18 = (0.0f - fSlow14);
		float fSlow19 = std::tan((fConst4 * fSlow1));
		float fSlow20 = (1.0f / fSlow19);
		float fSlow21 = (((fSlow20 + 0.0142857144f) / fSlow19) + 1.0f);
		float fSlow22 = (1.0f / (fSlow19 * fSlow21));
		float fSlow23 = (1.0f / fSlow21);
		float fSlow24 = (((fSlow20 + -0.0142857144f) / fSlow19) + 1.0f);
		float fSlow25 = (2.0f * (1.0f - (1.0f / FaustSinging_bowlDSP_faustpower2_f(fSlow19))));
		float fSlow26 = (0.0f - fSlow22);
		float fSlow27 = std::tan((fConst5 * fSlow1));
		float fSlow28 = (1.0f / fSlow27);
		float fSlow29 = (((fSlow28 + 0.0111111114f) / fSlow27) + 1.0f);
		float fSlow30 = (1.0f / (fSlow27 * fSlow29));
		float fSlow31 = (1.0f / fSlow29);
		float fSlow32 = (((fSlow28 + -0.0111111114f) / fSlow27) + 1.0f);
		float fSlow33 = (2.0f * (1.0f - (1.0f / FaustSinging_bowlDSP_faustpower2_f(fSlow27))));
		float fSlow34 = (0.0f - fSlow30);
		float fSlow35 = std::tan((fConst6 * fSlow1));
		float fSlow36 = (1.0f / fSlow35);
		float fSlow37 = (((fSlow36 + 1.41421354f) / fSlow35) + 1.0f);
		float fSlow38 = (0.150000006f / fSlow37);
		float fSlow39 = (1.0f / fSlow37);
		float fSlow40 = (((fSlow36 + -1.41421354f) / fSlow35) + 1.0f);
		float fSlow41 = (2.0f * (1.0f - (1.0f / FaustSinging_bowlDSP_faustpower2_f(fSlow35))));
		float fSlow42 = (((fSlow3 + 0.0166666675f) / fSlow2) + 1.0f);
		float fSlow43 = (1.0f / (fSlow2 * fSlow42));
		float fSlow44 = std::sqrt((fConst13 * std::tan((fConst14 * fSlow1))));
		float fSlow45 = FaustSinging_bowlDSP_faustpower2_f(fSlow44);
		float fSlow46 = (fConst11 - (fConst12 * fSlow45));
		float fSlow47 = FaustSinging_bowlDSP_faustpower2_f(fSlow46);
		float fSlow48 = (4.0f * fSlow47);
		float fSlow49 = (fSlow48 + (8.0f * fSlow45));
		float fSlow50 = (fConst7 * fSlow45);
		float fSlow51 = (2.82842708f * fSlow46);
		float fSlow52 = (fConst15 * fSlow46);
		float fSlow53 = (((fConst8 * (fSlow49 + (fConst7 * (fSlow45 * (fSlow50 + fSlow51))))) + fSlow52) + 16.0f);
		float fSlow54 = (fConst8 * (float(fHslider2) / fSlow53));
		float fSlow55 = (8.0f * fSlow47);
		float fSlow56 = (0.0f - fSlow55);
		float fSlow57 = (1.0f / fSlow53);
		float fSlow58 = (fConst17 * fSlow45);
		float fSlow59 = (5.65685415f * fSlow46);
		float fSlow60 = (fConst18 * fSlow46);
		float fSlow61 = ((fConst16 * (fSlow45 * (fSlow58 + fSlow59))) + (-64.0f - fSlow60));
		float fSlow62 = ((fConst8 * ((0.0f - (fSlow55 + (16.0f * fSlow45))) + (fConst19 * FaustSinging_bowlDSP_faustpower4_f(fSlow44)))) + 96.0f);
		float fSlow63 = ((fSlow60 + (fConst16 * (fSlow45 * (fSlow58 - fSlow59)))) + -64.0f);
		float fSlow64 = ((fConst8 * (fSlow49 + (fConst7 * (fSlow45 * (fSlow50 - fSlow51))))) + (16.0f - fSlow52));
		float fSlow65 = (1.0f / fSlow42);
		float fSlow66 = (((fSlow3 + -0.0166666675f) / fSlow2) + 1.0f);
		float fSlow67 = (0.0f - fSlow43);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow6;
			float fTempFTZ0 = std::min<float>(1.0f, ((fConst2 * fRec1[1]) + float(((fSlow6 - fVec0[1]) > 0.0f))));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec2[0] = ((1103515245 * iRec2[1]) + 12345);
			float fTemp0 = float(iRec2[0]);
			fVec1[0] = fTemp0;
			float fTemp1 = (1.16415322e-10f * (fRec1[0] * fTemp0));
			float fTempFTZ1 = (fTemp1 - (fSlow7 * ((fSlow8 * fRec0[2]) + (fSlow9 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fTemp1 - (fSlow15 * ((fSlow16 * fRec3[2]) + (fSlow17 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 - (fSlow23 * ((fSlow24 * fRec4[2]) + (fSlow25 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 - (fSlow31 * ((fSlow32 * fRec5[2]) + (fSlow33 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 - (fSlow39 * ((fSlow40 * fRec6[2]) + (fSlow41 * fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = ((4.65661287e-10f * fTemp0) - (fSlow57 * ((((fSlow61 * fRec8[1]) + (fSlow62 * fRec8[2])) + (fSlow63 * fRec8[3])) + (fSlow64 * fRec8[4]))));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = ((fSlow54 * (((fSlow56 * fRec8[2]) + (fSlow48 * fRec8[0])) + (fSlow48 * fRec8[4]))) - (fSlow65 * ((fSlow66 * fRec7[2]) + (fSlow9 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = ((4.65661287e-10f * ((fConst23 * fTemp0) + (fConst24 * fVec1[1]))) - (fConst25 * fRec9[1]));
			fRec9[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * ((((((((fSlow5 * fRec0[0]) + (fSlow10 * fRec0[2])) + (0.449999988f * ((fSlow14 * fRec3[0]) + (fSlow18 * fRec3[2])))) + (0.219999999f * ((fSlow22 * fRec4[0]) + (fSlow26 * fRec4[2])))) + (0.100000001f * ((fSlow30 * fRec5[0]) + (fSlow34 * fRec5[2])))) + (fSlow38 * (fRec6[2] + (fRec6[0] + (2.0f * fRec6[1]))))) + (0.25f * ((fSlow43 * fRec7[0]) + (fSlow67 * fRec7[2])))) + (0.00200000009f * (fRec1[0] * fRec9[0])))));
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			fVec1[1] = fVec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec8[j0] = fRec8[(j0 - 1)];
			}
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
		}
	}

};

#endif
