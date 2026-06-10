/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "hihat"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustHihatDSP_H__
#define  __FaustHihatDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustHihatDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustHihatDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustHihatDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[3];
	FAUSTFLOAT fHslider3;
	int iRec3[2];
	float fConst2;
	float fRec2[3];
	float fRec1[3];
	float fConst3;
	float fRec4[2];
	float fConst4;
	int iRec5[2];
	float fRec0[3];
	float fConst5;
	float fRec6[3];
	float fConst6;
	float fRec7[3];
	float fConst7;
	float fRec8[3];
	float fConst8;
	float fRec9[3];
	float fConst9;
	float fRec10[3];
	float fConst10;
	float fRec11[3];
	float fConst11;
	float fRec12[3];
	float fConst14;
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec13[3];
	float fConst19;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "hihat.dsp");
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
		m->declare("name", "hihat");
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
		fConst1 = (105557.516f / fConst0);
		fConst2 = (3.14159274f / fConst0);
		fConst3 = (1.0f / std::max<float>(1.0f, (0.00100000005f * fConst0)));
		fConst4 = (1.0f / std::max<float>(1.0f, (0.0199999996f * fConst0)));
		fConst5 = (79168.1328f / fConst0);
		fConst6 = (57176.9844f / fConst0);
		fConst7 = (39584.0664f / fConst0);
		fConst8 = (26389.3789f / fConst0);
		fConst9 = (15393.8037f / fConst0);
		fConst10 = (7916.81348f / fConst0);
		fConst11 = (3518.58374f / fConst0);
		float fConst12 = std::tan((9424.77832f / fConst0));
		float fConst13 = (1.0f / fConst12);
		fConst14 = (1.0f / (((fConst13 + 1.41421354f) / fConst12) + 1.0f));
		float fConst15 = FaustHihatDSP_faustpower2_f(fConst12);
		fConst16 = (1.0f / fConst15);
		fConst17 = (((fConst13 + -1.41421354f) / fConst12) + 1.0f);
		fConst18 = (2.0f * (1.0f - fConst16));
		fConst19 = (0.0f - (2.0f / fConst15));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(14.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec3[l1] = 0;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec5[l5] = 0;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec0[l6] = 0.0f;
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
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
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
	
	virtual FaustHihatDSP* clone() {
		return new FaustHihatDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("hihat");
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("size", &fHslider2, FAUSTFLOAT(14.0f), FAUSTFLOAT(12.0f), FAUSTFLOAT(16.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("strike", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (6.0f * (float(fHslider0) * float(fHslider1)));
		float fSlow1 = float(fHslider2);
		float fSlow2 = std::tan((fConst1 / fSlow1));
		float fSlow3 = (0.000595238118f * fSlow1);
		float fSlow4 = (1.0f / fSlow2);
		float fSlow5 = (((fSlow3 + fSlow4) / fSlow2) + 1.0f);
		float fSlow6 = (0.0500000007f / (fSlow2 * fSlow5));
		float fSlow7 = (0.0f - fSlow6);
		float fSlow8 = float(fButton0);
		float fSlow9 = float(fHslider3);
		int iSlow10 = (fSlow9 >= 2.0f);
		float fSlow11 = (iSlow10 ? 0.0f : 1.0f);
		int iSlow12 = (fSlow9 >= 1.0f);
		float fThen2 = (iSlow12 ? 0.600000024f : 0.300000012f);
		float fSlow13 = (iSlow10 ? 0.800000012f : fThen2);
		float fThen4 = (iSlow12 ? 50.0f : 2000.0f);
		float fSlow14 = std::tan((fConst2 * (iSlow10 ? 50.0f : fThen4)));
		float fSlow15 = (1.0f / fSlow14);
		float fSlow16 = (((fSlow15 + -1.41421354f) / fSlow14) + 1.0f);
		float fSlow17 = FaustHihatDSP_faustpower2_f(fSlow14);
		float fSlow18 = (1.0f - (1.0f / fSlow17));
		float fSlow19 = (((fSlow15 + 1.41421354f) / fSlow14) + 1.0f);
		float fSlow20 = (0.0f - (2.0f / fSlow17));
		float fSlow21 = std::tan((fConst2 * (iSlow10 ? 400.0f : 20000.0f)));
		float fSlow22 = (1.0f / fSlow21);
		float fSlow23 = (((fSlow22 + -1.41421354f) / fSlow21) + 1.0f);
		float fSlow24 = (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow21)));
		float fSlow25 = (((fSlow22 + 1.41421354f) / fSlow21) + 1.0f);
		int iSlow26 = (fSlow8 == 0.0f);
		float fSlow27 = (1.0f / fSlow5);
		float fSlow28 = (((fSlow4 - fSlow3) / fSlow2) + 1.0f);
		float fSlow29 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow2))));
		float fSlow30 = std::tan((fConst5 / fSlow1));
		float fSlow31 = (0.00119047624f * fSlow1);
		float fSlow32 = (1.0f / fSlow30);
		float fSlow33 = (((fSlow31 + fSlow32) / fSlow30) + 1.0f);
		float fSlow34 = (0.100000001f / (fSlow30 * fSlow33));
		float fSlow35 = (0.0f - fSlow34);
		float fSlow36 = (1.0f / fSlow33);
		float fSlow37 = (((fSlow32 - fSlow31) / fSlow30) + 1.0f);
		float fSlow38 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow30))));
		float fSlow39 = std::tan((fConst6 / fSlow1));
		float fSlow40 = (0.0021978023f * fSlow1);
		float fSlow41 = (1.0f / fSlow39);
		float fSlow42 = (((fSlow40 + fSlow41) / fSlow39) + 1.0f);
		float fSlow43 = (0.200000003f / (fSlow39 * fSlow42));
		float fSlow44 = (0.0f - fSlow43);
		float fSlow45 = (1.0f / fSlow42);
		float fSlow46 = (((fSlow41 - fSlow40) / fSlow39) + 1.0f);
		float fSlow47 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow39))));
		float fSlow48 = std::tan((fConst7 / fSlow1));
		float fSlow49 = (0.0039682542f * fSlow1);
		float fSlow50 = (1.0f / fSlow48);
		float fSlow51 = (((fSlow49 + fSlow50) / fSlow48) + 1.0f);
		float fSlow52 = (0.300000012f / (fSlow48 * fSlow51));
		float fSlow53 = (0.0f - fSlow52);
		float fSlow54 = (1.0f / fSlow51);
		float fSlow55 = (((fSlow50 - fSlow49) / fSlow48) + 1.0f);
		float fSlow56 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow48))));
		float fSlow57 = std::tan((fConst8 / fSlow1));
		float fSlow58 = (0.00714285718f * fSlow1);
		float fSlow59 = (1.0f / fSlow57);
		float fSlow60 = (((fSlow58 + fSlow59) / fSlow57) + 1.0f);
		float fSlow61 = (0.400000006f / (fSlow57 * fSlow60));
		float fSlow62 = (0.0f - fSlow61);
		float fSlow63 = (1.0f / fSlow60);
		float fSlow64 = (((fSlow59 - fSlow58) / fSlow57) + 1.0f);
		float fSlow65 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow57))));
		float fSlow66 = std::tan((fConst9 / fSlow1));
		float fSlow67 = (0.0122448979f * fSlow1);
		float fSlow68 = (1.0f / fSlow66);
		float fSlow69 = (((fSlow67 + fSlow68) / fSlow66) + 1.0f);
		float fSlow70 = (0.5f / (fSlow66 * fSlow69));
		float fSlow71 = (0.0f - fSlow70);
		float fSlow72 = (1.0f / fSlow69);
		float fSlow73 = (((fSlow68 - fSlow67) / fSlow66) + 1.0f);
		float fSlow74 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow66))));
		float fSlow75 = std::tan((fConst10 / fSlow1));
		float fSlow76 = (0.0198412705f * fSlow1);
		float fSlow77 = (1.0f / fSlow75);
		float fSlow78 = (((fSlow76 + fSlow77) / fSlow75) + 1.0f);
		float fSlow79 = (0.600000024f / (fSlow75 * fSlow78));
		float fSlow80 = (0.0f - fSlow79);
		float fSlow81 = (1.0f / fSlow78);
		float fSlow82 = (((fSlow77 - fSlow76) / fSlow75) + 1.0f);
		float fSlow83 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow75))));
		float fSlow84 = std::tan((fConst11 / fSlow1));
		float fSlow85 = (0.0357142873f * fSlow1);
		float fSlow86 = (1.0f / fSlow84);
		float fSlow87 = (((fSlow85 + fSlow86) / fSlow84) + 1.0f);
		float fSlow88 = (0.800000012f / (fSlow84 * fSlow87));
		float fSlow89 = (1.0f / fSlow87);
		float fSlow90 = (((fSlow86 - fSlow85) / fSlow84) + 1.0f);
		float fSlow91 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow84))));
		float fSlow92 = (0.0f - fSlow88);
		float fThen7 = (iSlow12 ? 0.300000012f : 0.0799999982f);
		float fSlow93 = (iSlow10 ? 0.0f : fThen7);
		float fThen9 = (iSlow12 ? 0.850000024f : 0.150000006f);
		float fSlow94 = std::max<float>(1.0f, (fConst0 * ((2.0f * (iSlow10 ? 0.0500000007f : fThen9)) + 0.5f)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow8;
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * (fSlow13 * float(iRec3[0])));
			float fTempFTZ0 = (fTemp0 - (((fRec2[2] * fSlow16) + (2.0f * (fRec2[1] * fSlow18))) / fSlow19));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (((((fRec2[1] * fSlow20) + (fRec2[0] / fSlow17)) + (fRec2[2] / fSlow17)) / fSlow19) - (((fRec1[2] * fSlow23) + (2.0f * (fRec1[1] * fSlow24))) / fSlow25));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = (fSlow8 + (fRec4[1] * float((fVec0[1] >= fSlow8))));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp1 = std::min<float>((fConst3 * fRec4[0]), 1.0f);
			iRec5[0] = (iSlow26 * (iRec5[1] + 1));
			float fTemp2 = float(iRec5[0]);
			float fTemp3 = std::max<float>(0.0f, (fTemp1 - (fConst4 * fTemp2)));
			float fTemp4 = ((std::max<float>(0.0f, (fSlow8 - fVec0[2])) * fSlow11) + (0.5f * (((fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))) * fTemp3) / fSlow25)));
			float fTempFTZ3 = (fTemp4 - (fSlow27 * ((fSlow28 * fRec0[2]) + (fSlow29 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp4 - (fSlow36 * ((fSlow37 * fRec6[2]) + (fSlow38 * fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp4 - (fSlow45 * ((fSlow46 * fRec7[2]) + (fSlow47 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp4 - (fSlow54 * ((fSlow55 * fRec8[2]) + (fSlow56 * fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp4 - (fSlow63 * ((fSlow64 * fRec9[2]) + (fSlow65 * fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp4 - (fSlow72 * ((fSlow73 * fRec10[2]) + (fSlow74 * fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp4 - (fSlow81 * ((fSlow82 * fRec11[2]) + (fSlow83 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fTemp4 - (fSlow89 * ((fSlow90 * fRec12[2]) + (fSlow91 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp0 - (fConst14 * ((fConst17 * fRec13[2]) + (fConst18 * fRec13[1]))));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * ((((fSlow7 * fRec0[2]) + (((fSlow35 * fRec6[2]) + (((fSlow44 * fRec7[2]) + (((fSlow53 * fRec8[2]) + (((fSlow62 * fRec9[2]) + (((fSlow71 * fRec10[2]) + (((fSlow80 * fRec11[2]) + (((fSlow88 * fRec12[0]) + (fSlow92 * fRec12[2])) + (fSlow79 * fRec11[0]))) + (fSlow70 * fRec10[0]))) + (fSlow61 * fRec9[0]))) + (fSlow52 * fRec8[0]))) + (fSlow43 * fRec7[0]))) + (fSlow34 * fRec6[0]))) + (fSlow6 * fRec0[0]))) + (fConst14 * ((fSlow93 * fTemp3) * (((fConst16 * fRec13[0]) + (fConst19 * fRec13[1])) + (fConst16 * fRec13[2]))))) * std::max<float>(0.0f, (fTemp1 - (fTemp2 / fSlow94))))));
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			iRec3[1] = iRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			iRec5[1] = iRec5[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
		}
	}

};

#endif
