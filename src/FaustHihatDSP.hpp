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
	float fRec0[3];
	float fConst3;
	float fRec4[3];
	float fConst4;
	float fRec5[3];
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
	float fConst12;
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec11[3];
	float fConst17;
	float fConst18;
	float fConst19;
	float fRec12[2];
	int iRec13[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
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
		fConst3 = (79168.1328f / fConst0);
		fConst4 = (57176.9844f / fConst0);
		fConst5 = (39584.0664f / fConst0);
		fConst6 = (26389.3789f / fConst0);
		fConst7 = (15393.8037f / fConst0);
		fConst8 = (7916.81348f / fConst0);
		fConst9 = (3518.58374f / fConst0);
		float fConst10 = std::tan((9424.77832f / fConst0));
		float fConst11 = (1.0f / fConst10);
		fConst12 = (1.0f / (((fConst11 + 1.41421354f) / fConst10) + 1.0f));
		float fConst13 = FaustHihatDSP_faustpower2_f(fConst10);
		fConst14 = (1.0f / fConst13);
		fConst15 = (((fConst11 + -1.41421354f) / fConst10) + 1.0f);
		fConst16 = (2.0f * (1.0f - fConst14));
		fConst17 = (0.0f - (2.0f / fConst13));
		fConst18 = std::max<float>(1.0f, (0.00100000005f * fConst0));
		fConst19 = (1.0f / fConst18);
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
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec0[l4] = 0.0f;
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
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iRec13[l14] = 0;
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
		float fSlow26 = (1.0f / fSlow5);
		float fSlow27 = (((fSlow4 - fSlow3) / fSlow2) + 1.0f);
		float fSlow28 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow2))));
		float fSlow29 = std::tan((fConst3 / fSlow1));
		float fSlow30 = (0.00119047624f * fSlow1);
		float fSlow31 = (1.0f / fSlow29);
		float fSlow32 = (((fSlow30 + fSlow31) / fSlow29) + 1.0f);
		float fSlow33 = (0.100000001f / (fSlow29 * fSlow32));
		float fSlow34 = (0.0f - fSlow33);
		float fSlow35 = (1.0f / fSlow32);
		float fSlow36 = (((fSlow31 - fSlow30) / fSlow29) + 1.0f);
		float fSlow37 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow29))));
		float fSlow38 = std::tan((fConst4 / fSlow1));
		float fSlow39 = (0.0021978023f * fSlow1);
		float fSlow40 = (1.0f / fSlow38);
		float fSlow41 = (((fSlow39 + fSlow40) / fSlow38) + 1.0f);
		float fSlow42 = (0.200000003f / (fSlow38 * fSlow41));
		float fSlow43 = (0.0f - fSlow42);
		float fSlow44 = (1.0f / fSlow41);
		float fSlow45 = (((fSlow40 - fSlow39) / fSlow38) + 1.0f);
		float fSlow46 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow38))));
		float fSlow47 = std::tan((fConst5 / fSlow1));
		float fSlow48 = (0.0039682542f * fSlow1);
		float fSlow49 = (1.0f / fSlow47);
		float fSlow50 = (((fSlow48 + fSlow49) / fSlow47) + 1.0f);
		float fSlow51 = (0.300000012f / (fSlow47 * fSlow50));
		float fSlow52 = (0.0f - fSlow51);
		float fSlow53 = (1.0f / fSlow50);
		float fSlow54 = (((fSlow49 - fSlow48) / fSlow47) + 1.0f);
		float fSlow55 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow47))));
		float fSlow56 = std::tan((fConst6 / fSlow1));
		float fSlow57 = (0.00714285718f * fSlow1);
		float fSlow58 = (1.0f / fSlow56);
		float fSlow59 = (((fSlow57 + fSlow58) / fSlow56) + 1.0f);
		float fSlow60 = (0.400000006f / (fSlow56 * fSlow59));
		float fSlow61 = (0.0f - fSlow60);
		float fSlow62 = (1.0f / fSlow59);
		float fSlow63 = (((fSlow58 - fSlow57) / fSlow56) + 1.0f);
		float fSlow64 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow56))));
		float fSlow65 = std::tan((fConst7 / fSlow1));
		float fSlow66 = (0.0122448979f * fSlow1);
		float fSlow67 = (1.0f / fSlow65);
		float fSlow68 = (((fSlow66 + fSlow67) / fSlow65) + 1.0f);
		float fSlow69 = (0.5f / (fSlow65 * fSlow68));
		float fSlow70 = (0.0f - fSlow69);
		float fSlow71 = (1.0f / fSlow68);
		float fSlow72 = (((fSlow67 - fSlow66) / fSlow65) + 1.0f);
		float fSlow73 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow65))));
		float fSlow74 = std::tan((fConst8 / fSlow1));
		float fSlow75 = (0.0198412705f * fSlow1);
		float fSlow76 = (1.0f / fSlow74);
		float fSlow77 = (((fSlow75 + fSlow76) / fSlow74) + 1.0f);
		float fSlow78 = (0.600000024f / (fSlow74 * fSlow77));
		float fSlow79 = (0.0f - fSlow78);
		float fSlow80 = (1.0f / fSlow77);
		float fSlow81 = (((fSlow76 - fSlow75) / fSlow74) + 1.0f);
		float fSlow82 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow74))));
		float fSlow83 = std::tan((fConst9 / fSlow1));
		float fSlow84 = (0.0357142873f * fSlow1);
		float fSlow85 = (1.0f / fSlow83);
		float fSlow86 = (((fSlow84 + fSlow85) / fSlow83) + 1.0f);
		float fSlow87 = (0.800000012f / (fSlow83 * fSlow86));
		float fSlow88 = (1.0f / fSlow86);
		float fSlow89 = (((fSlow85 - fSlow84) / fSlow83) + 1.0f);
		float fSlow90 = (2.0f * (1.0f - (1.0f / FaustHihatDSP_faustpower2_f(fSlow83))));
		float fSlow91 = (0.0f - fSlow87);
		float fThen7 = (iSlow12 ? 0.300000012f : 0.0799999982f);
		float fSlow92 = (iSlow10 ? 0.0f : fThen7);
		float fThen9 = (iSlow12 ? 2.20000005f : 0.25f);
		float fSlow93 = std::max<float>(1.0f, (fConst0 * (iSlow10 ? 0.0599999987f : fThen9)));
		int iSlow94 = (fSlow8 == 0.0f);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow8;
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			float fTemp0 = (4.65661287e-10f * (fSlow13 * float(iRec3[0])));
			float fTempFTZ0 = (fTemp0 - (((fRec2[2] * fSlow16) + (2.0f * (fRec2[1] * fSlow18))) / fSlow19));
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (((((fRec2[1] * fSlow20) + (fRec2[0] / fSlow17)) + (fRec2[2] / fSlow17)) / fSlow19) - (((fRec1[2] * fSlow23) + (2.0f * (fRec1[1] * fSlow24))) / fSlow25));
			fRec1[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp1 = ((std::max<float>(0.0f, (fSlow8 - fVec0[2])) * fSlow11) + (0.5f * ((fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))) / fSlow25)));
			float fTempFTZ2 = (fTemp1 - (fSlow26 * ((fSlow27 * fRec0[2]) + (fSlow28 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = (fTemp1 - (fSlow35 * ((fSlow36 * fRec4[2]) + (fSlow37 * fRec4[1]))));
			fRec4[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 - (fSlow44 * ((fSlow45 * fRec5[2]) + (fSlow46 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 - (fSlow53 * ((fSlow54 * fRec6[2]) + (fSlow55 * fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp1 - (fSlow62 * ((fSlow63 * fRec7[2]) + (fSlow64 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp1 - (fSlow71 * ((fSlow72 * fRec8[2]) + (fSlow73 * fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp1 - (fSlow80 * ((fSlow81 * fRec9[2]) + (fSlow82 * fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp1 - (fSlow88 * ((fSlow89 * fRec10[2]) + (fSlow90 * fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fTemp0 - (fConst12 * ((fConst15 * fRec11[2]) + (fConst16 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fSlow8 + (fRec12[1] * float((fVec0[1] >= fSlow8))));
			fRec12[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			iRec13[0] = (iSlow94 * (iRec13[1] + 1));
			output0[i0] = FAUSTFLOAT((fSlow0 * ((((fSlow7 * fRec0[2]) + (((fSlow34 * fRec4[2]) + (((fSlow43 * fRec5[2]) + (((fSlow52 * fRec6[2]) + (((fSlow61 * fRec7[2]) + (((fSlow70 * fRec8[2]) + (((fSlow79 * fRec9[2]) + (((fSlow87 * fRec10[0]) + (fSlow91 * fRec10[2])) + (fSlow78 * fRec9[0]))) + (fSlow69 * fRec8[0]))) + (fSlow60 * fRec7[0]))) + (fSlow51 * fRec6[0]))) + (fSlow42 * fRec5[0]))) + (fSlow33 * fRec4[0]))) + (fSlow6 * fRec0[0]))) + (fConst12 * (fSlow92 * (((fConst14 * fRec11[0]) + (fConst17 * fRec11[1])) + (fConst14 * fRec11[2]))))) * std::max<float>(0.0f, (std::min<float>((fConst19 * fRec12[0]), std::max<float>((((fConst18 - fRec12[0]) / fSlow93) + 1.0f), 0.0f)) * (1.0f - (fConst19 * float(iRec13[0]))))))));
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			iRec3[1] = iRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
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
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			iRec13[1] = iRec13[0];
		}
	}

};

#endif
