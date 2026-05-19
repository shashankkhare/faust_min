/* ------------------------------------------------------------
name: "bowl"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBowlDSP_H__
#define  __FaustBowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustBowlDSP_faustpower2_f(float value) {
	return (value * value);
}
static float FaustBowlDSP_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float FaustBowlDSP_faustpower4_f(float value) {
	return (((value * value) * value) * value);
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
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	int iRec2[2];
	float fVec0[2];
	float fRec1[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fConst3;
	float fRec3[2];
	float fConst4;
	float fConst5;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	FAUSTFLOAT fHslider3;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec4[5];
	float fRec0[3];
	float fConst17;
	float fRec5[3];
	float fConst18;
	float fRec6[3];
	float fConst19;
	float fRec7[3];
	float fConst20;
	float fRec8[3];
	float fConst21;
	float fRec9[3];
	float fConst22;
	float fRec10[3];
	float fRec11[3];
	float fConst23;
	float fRec12[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("filename", "bowl.dsp");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
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
		fConst1 = (26.3893776f / fConst0);
		fConst2 = (4.71238899f / fConst0);
		fConst3 = std::exp((0.0f - (66.6666641f / fConst0)));
		fConst4 = (1.0f / fConst0);
		fConst5 = FaustBowlDSP_faustpower2_f(fConst4);
		float fConst6 = std::tan((6.28318548f / fConst0));
		float fConst7 = (fConst0 * fConst6);
		fConst8 = (2.0f * fConst7);
		fConst9 = (0.5f / fConst7);
		fConst10 = (4.0f * (FaustBowlDSP_faustpower2_f(fConst0) * fConst6));
		fConst11 = (3.14159274f / fConst0);
		fConst12 = (11.3137083f / fConst0);
		fConst13 = FaustBowlDSP_faustpower3_f(fConst4);
		fConst14 = (4.0f * fConst4);
		fConst15 = (22.6274166f / fConst0);
		fConst16 = (6.0f * fConst5);
		fConst17 = (26.4207935f / fConst0);
		fConst18 = (16.3676987f / fConst0);
		fConst19 = (16.3834057f / fConst0);
		fConst20 = (8.73362732f / fConst0);
		fConst21 = (8.74933529f / fConst0);
		fConst22 = (3.14787579f / fConst0);
		fConst23 = (3.76991129f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.59999999999999998f);
		fHslider2 = FAUSTFLOAT(220.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec2[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 5); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec5[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec7[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec9[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec11[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0f;
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
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(220.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("rub", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.850000024f * (float(fHslider0) * float(fHslider1)));
		float fSlow1 = float(fHslider2);
		float fSlow2 = std::tan((fConst1 * fSlow1));
		float fSlow3 = (0.031578362f / fSlow1);
		float fSlow4 = (1.0f / fSlow2);
		float fSlow5 = (((fSlow3 + fSlow4) / fSlow2) + 1.0f);
		float fSlow6 = (fSlow2 * fSlow5);
		float fSlow7 = (1.0f / fSlow6);
		float fSlow8 = (1.0f / std::tan((fConst2 * fSlow1)));
		float fSlow9 = (1.0f / (fSlow8 + 1.0f));
		float fSlow10 = (1.0f - fSlow8);
		float fSlow11 = float(fButton0);
		float fSlow12 = std::tan((fConst11 * fSlow1));
		float fSlow13 = std::sqrt((fConst10 * fSlow12));
		float fSlow14 = FaustBowlDSP_faustpower2_f(fSlow13);
		float fSlow15 = (fConst8 - (fConst9 * fSlow14));
		float fSlow16 = FaustBowlDSP_faustpower2_f(fSlow15);
		float fSlow17 = (4.0f * fSlow16);
		float fSlow18 = (fSlow17 + (8.0f * fSlow14));
		float fSlow19 = (fConst4 * fSlow14);
		float fSlow20 = (2.82842708f * fSlow15);
		float fSlow21 = (fConst12 * fSlow15);
		float fSlow22 = (((fConst5 * (fSlow18 + (fConst4 * (fSlow14 * (fSlow19 + fSlow20))))) + fSlow21) + 16.0f);
		float fSlow23 = (fConst5 / fSlow22);
		float fSlow24 = (8.0f * fSlow16);
		float fSlow25 = (0.0f - fSlow24);
		float fSlow26 = (1.86264511e-11f * float(fHslider3));
		float fSlow27 = (1.0f / fSlow22);
		float fSlow28 = (fConst14 * fSlow14);
		float fSlow29 = (5.65685415f * fSlow15);
		float fSlow30 = (fConst15 * fSlow15);
		float fSlow31 = ((fConst13 * (fSlow14 * (fSlow28 + fSlow29))) + (-64.0f - fSlow30));
		float fSlow32 = ((fConst5 * ((0.0f - (fSlow24 + (16.0f * fSlow14))) + (fConst16 * FaustBowlDSP_faustpower4_f(fSlow13)))) + 96.0f);
		float fSlow33 = ((fSlow30 + (fConst13 * (fSlow14 * (fSlow28 - fSlow29)))) + -64.0f);
		float fSlow34 = ((fConst5 * (fSlow18 + (fConst4 * (fSlow14 * (fSlow19 - fSlow20))))) + (16.0f - fSlow21));
		float fSlow35 = (1.0f / fSlow5);
		float fSlow36 = (((fSlow4 - fSlow3) / fSlow2) + 1.0f);
		float fSlow37 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow2))));
		float fSlow38 = std::tan((fConst17 * fSlow1));
		float fSlow39 = (0.0378489755f / fSlow1);
		float fSlow40 = (1.0f / fSlow38);
		float fSlow41 = (((fSlow39 + fSlow40) / fSlow38) + 1.0f);
		float fSlow42 = (fSlow38 * fSlow41);
		float fSlow43 = (1.0f / fSlow42);
		float fSlow44 = (1.0f / fSlow41);
		float fSlow45 = (((fSlow40 - fSlow39) / fSlow38) + 1.0f);
		float fSlow46 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow38))));
		float fSlow47 = (0.0f - (0.100000001f / fSlow42));
		float fSlow48 = std::tan((fConst18 * fSlow1));
		float fSlow49 = (0.0218199808f / fSlow1);
		float fSlow50 = (1.0f / fSlow48);
		float fSlow51 = (((fSlow49 + fSlow50) / fSlow48) + 1.0f);
		float fSlow52 = (fSlow48 * fSlow51);
		float fSlow53 = (1.0f / fSlow52);
		float fSlow54 = (1.0f / fSlow51);
		float fSlow55 = (((fSlow50 - fSlow49) / fSlow48) + 1.0f);
		float fSlow56 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow48))));
		float fSlow57 = std::tan((fConst19 * fSlow1));
		float fSlow58 = (0.0234759115f / fSlow1);
		float fSlow59 = (1.0f / fSlow57);
		float fSlow60 = (((fSlow58 + fSlow59) / fSlow57) + 1.0f);
		float fSlow61 = (fSlow57 * fSlow60);
		float fSlow62 = (1.0f / fSlow61);
		float fSlow63 = (1.0f / fSlow60);
		float fSlow64 = (((fSlow59 - fSlow58) / fSlow57) + 1.0f);
		float fSlow65 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow57))));
		float fSlow66 = (0.0f - (0.25f / fSlow61));
		float fSlow67 = std::tan((fConst20 * fSlow1));
		float fSlow68 = (0.025444435f / fSlow1);
		float fSlow69 = (1.0f / fSlow67);
		float fSlow70 = (((fSlow68 + fSlow69) / fSlow67) + 1.0f);
		float fSlow71 = (fSlow67 * fSlow70);
		float fSlow72 = (1.0f / fSlow71);
		float fSlow73 = (1.0f / fSlow70);
		float fSlow74 = (((fSlow69 - fSlow68) / fSlow67) + 1.0f);
		float fSlow75 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow67))));
		float fSlow76 = std::tan((fConst21 * fSlow1));
		float fSlow77 = (0.0265800916f / fSlow1);
		float fSlow78 = (1.0f / fSlow76);
		float fSlow79 = (((fSlow77 + fSlow78) / fSlow76) + 1.0f);
		float fSlow80 = (fSlow76 * fSlow79);
		float fSlow81 = (1.0f / fSlow80);
		float fSlow82 = (1.0f / fSlow79);
		float fSlow83 = (((fSlow78 - fSlow77) / fSlow76) + 1.0f);
		float fSlow84 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow76))));
		float fSlow85 = (0.0f - (0.5f / fSlow80));
		float fSlow86 = std::tan((fConst22 * fSlow1));
		float fSlow87 = (0.0467168428f / fSlow1);
		float fSlow88 = (1.0f / fSlow86);
		float fSlow89 = (((fSlow87 + fSlow88) / fSlow86) + 1.0f);
		float fSlow90 = (1.0f / (fSlow86 * fSlow89));
		float fSlow91 = (0.0f - fSlow90);
		float fSlow92 = (1.0f / fSlow89);
		float fSlow93 = (((fSlow88 - fSlow87) / fSlow86) + 1.0f);
		float fSlow94 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow86))));
		float fSlow95 = (0.0454728417f / fSlow1);
		float fSlow96 = (1.0f / fSlow12);
		float fSlow97 = (((fSlow95 + fSlow96) / fSlow12) + 1.0f);
		float fSlow98 = (1.0f / (fSlow12 * fSlow97));
		float fSlow99 = (1.0f / fSlow97);
		float fSlow100 = (((fSlow96 - fSlow95) / fSlow12) + 1.0f);
		float fSlow101 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow12))));
		float fSlow102 = (0.0f - fSlow98);
		float fSlow103 = (0.0f - (0.5f / fSlow71));
		float fSlow104 = (0.0f - (0.25f / fSlow52));
		float fSlow105 = (0.0f - (0.100000001f / fSlow6));
		float fSlow106 = std::tan((fConst23 * fSlow1));
		float fSlow107 = (1.0f / fSlow106);
		float fSlow108 = (((fSlow107 + 1.41421354f) / fSlow106) + 1.0f);
		float fSlow109 = (0.150000006f / fSlow108);
		float fSlow110 = (1.0f / fSlow108);
		float fSlow111 = (((fSlow107 + -1.41421354f) / fSlow106) + 1.0f);
		float fSlow112 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fSlow106))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec2[0] = ((1103515245 * iRec2[1]) + 12345);
			float fTemp0 = float(iRec2[0]);
			fVec0[0] = fTemp0;
			float fTempFTZ0 = (fSlow9 * ((4.65661287e-10f * (fTemp0 + fVec0[1])) - (fSlow10 * fRec1[1])));
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			fVec1[0] = fSlow11;
			float fThen0 = (fConst3 * fRec3[1]);
			float fTempFTZ1 = ((fSlow11 > fVec1[1]) ? 4.5f : fThen0);
			fRec3[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((fSlow26 * fTemp0) - (fSlow27 * ((((fSlow31 * fRec4[1]) + (fSlow32 * fRec4[2])) + (fSlow33 * fRec4[3])) + (fSlow34 * fRec4[4]))));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp1 = ((fRec1[0] * fRec3[0]) + (fSlow23 * (((fSlow25 * fRec4[2]) + (fSlow17 * fRec4[0])) + (fSlow17 * fRec4[4]))));
			float fTempFTZ3 = (fTemp1 - (fSlow35 * ((fSlow36 * fRec0[2]) + (fSlow37 * fRec0[1]))));
			fRec0[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fTemp1 - (fSlow44 * ((fSlow45 * fRec5[2]) + (fSlow46 * fRec5[1]))));
			fRec5[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp1 - (fSlow54 * ((fSlow55 * fRec6[2]) + (fSlow56 * fRec6[1]))));
			fRec6[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp1 - (fSlow63 * ((fSlow64 * fRec7[2]) + (fSlow65 * fRec7[1]))));
			fRec7[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp1 - (fSlow73 * ((fSlow74 * fRec8[2]) + (fSlow75 * fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp1 - (fSlow82 * ((fSlow83 * fRec9[2]) + (fSlow84 * fRec9[1]))));
			fRec9[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp1 - (fSlow92 * ((fSlow93 * fRec10[2]) + (fSlow94 * fRec10[1]))));
			fRec10[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fTemp1 - (fSlow99 * ((fSlow100 * fRec11[2]) + (fSlow101 * fRec11[1]))));
			fRec11[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp1 - (fSlow110 * ((fSlow111 * fRec12[2]) + (fSlow112 * fRec12[1]))));
			fRec12[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			output0[i0] = FAUSTFLOAT((fSlow0 * (((0.100000001f * ((fSlow7 * fRec0[0]) + (fSlow43 * fRec5[0]))) + ((fSlow47 * fRec5[2]) + (((0.25f * ((fSlow53 * fRec6[0]) + (fSlow62 * fRec7[0]))) + ((fSlow66 * fRec7[2]) + (((0.5f * ((fSlow72 * fRec8[0]) + (fSlow81 * fRec9[0]))) + ((fSlow85 * fRec9[2]) + (((fSlow91 * fRec10[2]) + (((fSlow98 * fRec11[0]) + (fSlow102 * fRec11[2])) + (fSlow90 * fRec10[0]))) + (fSlow103 * fRec8[2])))) + (fSlow104 * fRec6[2])))) + (fSlow105 * fRec0[2])))) + (fSlow109 * (fRec12[2] + (fRec12[0] + (2.0f * fRec12[1])))))));
			iRec2[1] = iRec2[0];
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fVec1[1] = fVec1[0];
			fRec3[1] = fRec3[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec4[j0] = fRec4[(j0 - 1)];
			}
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
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
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
		}
	}

};

#endif
