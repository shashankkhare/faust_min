/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "churchbell"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustChurchbellDSP_H__
#define  __FaustChurchbellDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustChurchbellDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustChurchbellDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustChurchbellDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iConst5;
	int iRec3[2];
	int iConst6;
	float fConst7;
	float fConst8;
	float fVec1[2];
	float fRec2[2];
	float fRec1[3];
	float fConst9;
	float fRec4[3];
	float fConst10;
	float fRec5[3];
	float fConst11;
	float fRec6[3];
	float fConst12;
	float fRec7[3];
	float fConst13;
	float fRec8[3];
	float fConst14;
	float fRec9[3];
	float fVec2[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "churchbell.dsp");
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
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
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
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "churchbell");
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
		fConst1 = (9.42477798f / fConst0);
		float fConst2 = (1.0f / std::tan((4712.38916f / fConst0)));
		fConst3 = (1.0f / (fConst2 + 1.0f));
		fConst4 = (1.0f - fConst2);
		iConst5 = int((0.00600000005f * fConst0));
		iConst6 = int((0.00100000005f * fConst0));
		fConst7 = (1.0f / float(std::max<int>(1, (iConst5 - iConst6))));
		fConst8 = (1.0f / float(std::max<int>(1, iConst6)));
		fConst9 = (1.57079637f / fConst0);
		fConst10 = (7.88539743f / fConst0);
		fConst11 = (6.28318548f / fConst0);
		fConst12 = (4.90088463f / fConst0);
		fConst13 = (3.73849535f / fConst0);
		fConst14 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fHslider1 = FAUSTFLOAT(200.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec3[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec1[l4] = 0.0f;
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
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec0[l12] = 0.0f;
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
	
	virtual FaustChurchbellDSP* clone() {
		return new FaustChurchbellDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("churchbell");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(200.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (12.25f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::tan((fConst1 * fSlow1));
		float fSlow3 = (1.0f / std::max<float>(1.0f, (1.7045455f * fSlow1)));
		float fSlow4 = (1.0f / fSlow2);
		float fSlow5 = (((fSlow3 + fSlow4) / fSlow2) + 1.0f);
		float fSlow6 = (0.200000003f / (fSlow2 * fSlow5));
		float fSlow7 = (0.0f - fSlow6);
		float fSlow8 = float(fHslider2);
		float fSlow9 = float(fButton0);
		float fSlow10 = (1.0f / fSlow5);
		float fSlow11 = (((fSlow4 - fSlow3) / fSlow2) + 1.0f);
		float fSlow12 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow2))));
		float fSlow13 = std::tan((fConst9 * fSlow1));
		float fSlow14 = (1.0f / std::max<float>(1.0f, (2.840909f * fSlow1)));
		float fSlow15 = (1.0f / fSlow13);
		float fSlow16 = (((fSlow14 + fSlow15) / fSlow13) + 1.0f);
		float fSlow17 = (fSlow13 * fSlow16);
		float fSlow18 = (1.0f / fSlow17);
		float fSlow19 = (1.0f / fSlow16);
		float fSlow20 = (((fSlow15 - fSlow14) / fSlow13) + 1.0f);
		float fSlow21 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow13))));
		float fSlow22 = std::tan((fConst10 * fSlow1));
		float fSlow23 = (1.0f / std::max<float>(1.0f, (2.85227275f * fSlow1)));
		float fSlow24 = (1.0f / fSlow22);
		float fSlow25 = (((fSlow23 + fSlow24) / fSlow22) + 1.0f);
		float fSlow26 = (fSlow22 * fSlow25);
		float fSlow27 = (1.0f / fSlow26);
		float fSlow28 = (1.0f / fSlow25);
		float fSlow29 = (((fSlow24 - fSlow23) / fSlow22) + 1.0f);
		float fSlow30 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow22))));
		float fSlow31 = (0.0f - (0.400000006f / fSlow26));
		float fSlow32 = std::tan((fConst11 * fSlow1));
		float fSlow33 = (1.0f / std::max<float>(1.0f, (3.409091f * fSlow1)));
		float fSlow34 = (1.0f / fSlow32);
		float fSlow35 = (((fSlow33 + fSlow34) / fSlow32) + 1.0f);
		float fSlow36 = (1.0f / (fSlow32 * fSlow35));
		float fSlow37 = (0.0f - fSlow36);
		float fSlow38 = (1.0f / fSlow35);
		float fSlow39 = (((fSlow34 - fSlow33) / fSlow32) + 1.0f);
		float fSlow40 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow32))));
		float fSlow41 = std::tan((fConst12 * fSlow1));
		float fSlow42 = (1.0f / std::max<float>(1.0f, (3.5454545f * fSlow1)));
		float fSlow43 = (1.0f / fSlow41);
		float fSlow44 = (((fSlow42 + fSlow43) / fSlow41) + 1.0f);
		float fSlow45 = (0.600000024f / (fSlow41 * fSlow44));
		float fSlow46 = (0.0f - fSlow45);
		float fSlow47 = (1.0f / fSlow44);
		float fSlow48 = (((fSlow43 - fSlow42) / fSlow41) + 1.0f);
		float fSlow49 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow41))));
		float fSlow50 = std::tan((fConst13 * fSlow1));
		float fSlow51 = (1.0f / std::max<float>(1.0f, (4.05681801f * fSlow1)));
		float fSlow52 = (1.0f / fSlow50);
		float fSlow53 = (((fSlow51 + fSlow52) / fSlow50) + 1.0f);
		float fSlow54 = (0.800000012f / (fSlow50 * fSlow53));
		float fSlow55 = (0.0f - fSlow54);
		float fSlow56 = (1.0f / fSlow53);
		float fSlow57 = (((fSlow52 - fSlow51) / fSlow50) + 1.0f);
		float fSlow58 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow50))));
		float fSlow59 = std::tan((fConst14 * fSlow1));
		float fSlow60 = (1.0f / std::max<float>(1.0f, (4.5454545f * fSlow1)));
		float fSlow61 = (1.0f / fSlow59);
		float fSlow62 = (((fSlow60 + fSlow61) / fSlow59) + 1.0f);
		float fSlow63 = (1.0f / (fSlow59 * fSlow62));
		float fSlow64 = (0.0f - fSlow63);
		float fSlow65 = (1.0f / fSlow62);
		float fSlow66 = (((fSlow61 - fSlow60) / fSlow59) + 1.0f);
		float fSlow67 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow59))));
		float fSlow68 = (0.0f - (0.400000006f / fSlow17));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow9;
			float fTemp0 = (fSlow9 - fVec0[1]);
			int iThen0 = std::min<int>((iRec3[1] + 1), iConst5);
			iRec3[0] = (int((fTemp0 * float((fTemp0 > 0.0f)))) ? 0 : iThen0);
			float fThen1 = std::max<float>(0.0f, (1.0f - (fConst7 * float((iRec3[0] - iConst6)))));
			float fElse1 = (fConst8 * float(iRec3[0]));
			float fTemp1 = (fSlow8 * ((iRec3[0] < iConst6) ? fElse1 : fThen1));
			fVec1[0] = fTemp1;
			float fTempFTZ0 = (0.0f - (fConst3 * ((fConst4 * fRec2[1]) - (fTemp1 + fVec1[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fRec2[0] - (fSlow10 * ((fSlow11 * fRec1[2]) + (fSlow12 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fRec2[0] - (fSlow19 * ((fSlow20 * fRec4[2]) + (fSlow21 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fRec2[0] - (fSlow28 * ((fSlow29 * fRec5[2]) + (fSlow30 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fRec2[0] - (fSlow38 * ((fSlow39 * fRec6[2]) + (fSlow40 * fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fRec2[0] - (fSlow47 * ((fSlow48 * fRec7[2]) + (fSlow49 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fRec2[0] - (fSlow56 * ((fSlow57 * fRec8[2]) + (fSlow58 * fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fRec2[0] - (fSlow65 * ((fSlow66 * fRec9[2]) + (fSlow67 * fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp2 = ((fSlow7 * fRec1[2]) + (((0.400000006f * ((fSlow18 * fRec4[0]) + (fSlow27 * fRec5[0]))) + ((fSlow31 * fRec5[2]) + ((fSlow37 * fRec6[2]) + ((fSlow36 * fRec6[0]) + ((fSlow46 * fRec7[2]) + ((fSlow45 * fRec7[0]) + ((fSlow55 * fRec8[2]) + ((fSlow54 * fRec8[0]) + ((fSlow64 * fRec9[2]) + ((fSlow68 * fRec4[2]) + (fSlow63 * fRec9[0]))))))))))) + (fSlow6 * fRec1[0])));
			fVec2[0] = fTemp2;
			float fTempFTZ8 = ((0.995000005f * fRec0[1]) + (0.142857149f * (fTemp2 - fVec2[1])));
			fRec0[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * fRec0[0])))));
			fVec0[1] = fVec0[0];
			iRec3[1] = iRec3[0];
			fVec1[1] = fVec1[0];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec2[1] = fVec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
