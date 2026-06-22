/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "chougong"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustChougongDSP_H__
#define  __FaustChougongDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustChougongDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustChougongDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustChougongDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	int fSampleRate;
	float fConst1;
	float fRec1[2];
	int iRec3[2];
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fConst3;
	float fConst4;
	int iRec5[2];
	float fConst5;
	float fRec4[2];
	float fRec2[3];
	float fConst6;
	float fRec0[3];
	float fConst7;
	float fRec6[3];
	float fConst8;
	float fRec7[3];
	float fConst9;
	float fRec8[3];
	float fConst10;
	float fRec9[3];
	float fConst11;
	float fRec10[3];
	float fConst12;
	float fRec11[3];
	float fConst13;
	float fRec12[3];
	float fConst14;
	float fRec13[3];
	float fConst15;
	float fRec14[3];
	float fConst16;
	float fRec15[3];
	float fConst17;
	float fRec16[3];
	float fConst18;
	float fRec17[3];
	float fConst19;
	float fRec18[3];
	float fConst20;
	float fConst21;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "chougong.dsp");
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
		m->declare("name", "chougong");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
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
		fConst1 = std::exp((0.0f - (50.0f / fConst0)));
		fConst2 = (12.566371f / fConst0);
		fConst3 = std::max<float>(1.0f, (0.00999999978f * fConst0));
		fConst4 = (1.0f / fConst3);
		fConst5 = (1.0f / std::max<float>(1.0f, (2.0f * fConst0)));
		fConst6 = (8.82787514f / fConst0);
		fConst7 = (7.00575161f / fConst0);
		fConst8 = (7.05287552f / fConst0);
		fConst9 = (5.42867231f / fConst0);
		fConst10 = (5.37212324f / fConst0);
		fConst11 = (4.27884912f / fConst0);
		fConst12 = (4.2411499f / fConst0);
		fConst13 = (3.18871665f / fConst0);
		fConst14 = (3.14159274f / fConst0);
		fConst15 = (20.6716805f / fConst0);
		fConst16 = (25.5411491f / fConst0);
		fConst17 = (17.0274315f / fConst0);
		fConst18 = (13.6659279f / fConst0);
		fConst19 = (11.0584059f / fConst0);
		fConst20 = std::max<float>(1.0f, (0.100000001f * fConst0));
		fConst21 = (1.0f / fConst20);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.59999999999999998f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(100.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec3[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec5[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec2[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec0[l7] = 0.0f;
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
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec13[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec17[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec18[l20] = 0.0f;
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
	
	virtual FaustChougongDSP* clone() {
		return new FaustChougongDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("chougong");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider2, FAUSTFLOAT(100.0f), FAUSTFLOAT(80.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.100000001f * (float(fHslider0) * float(fHslider1)));
		float fSlow1 = float(fButton0);
		float fSlow2 = float(fHslider2);
		float fSlow3 = (fConst2 * fSlow2);
		float fSlow4 = (fConst6 * fSlow2);
		float fSlow5 = (0.0323650129f / fSlow2);
		float fSlow6 = (fConst7 * fSlow2);
		float fSlow7 = (0.0285479724f / fSlow2);
		float fSlow8 = (fConst8 * fSlow2);
		float fSlow9 = (0.0295387786f / fSlow2);
		float fSlow10 = (fConst9 * fSlow2);
		float fSlow11 = (0.0307011846f / fSlow2);
		float fSlow12 = (fConst10 * fSlow2);
		float fSlow13 = (0.0286378674f / fSlow2);
		float fSlow14 = (fConst11 * fSlow2);
		float fSlow15 = (0.031161027f / fSlow2);
		float fSlow16 = (fConst12 * fSlow2);
		float fSlow17 = (0.0294731371f / fSlow2);
		float fSlow18 = (fConst13 * fSlow2);
		float fSlow19 = (0.0348450877f / fSlow2);
		float fSlow20 = (fConst14 * fSlow2);
		float fSlow21 = (0.0318309888f / fSlow2);
		float fSlow22 = (fConst15 * fSlow2);
		float fSlow23 = (0.0322502404f / fSlow2);
		float fSlow24 = (fConst16 * fSlow2);
		float fSlow25 = (0.0391525067f / fSlow2);
		float fSlow26 = (fConst17 * fSlow2);
		float fSlow27 = (0.029364381f / fSlow2);
		float fSlow28 = (fConst18 * fSlow2);
		float fSlow29 = (0.0292698741f / fSlow2);
		float fSlow30 = (fConst19 * fSlow2);
		float fSlow31 = (0.0301429816f / fSlow2);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow1;
			int iTemp0 = (fSlow1 > fVec0[1]);
			iVec1[0] = iTemp0;
			float fThen0 = (fConst1 * fRec1[1]);
			float fTempFTZ0 = (iTemp0 ? 2.5f : fThen0);
			fRec1[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			iRec5[0] = ((iTemp0 > iVec1[1]) + ((iTemp0 <= iVec1[1]) * (iRec5[1] + (iRec5[1] > 0))));
			float fTemp1 = float(iRec5[0]);
			float fTempFTZ1 = ((0.999000013f * fRec4[1]) + (0.00100000005f * std::max<float>(0.0f, std::min<float>((fConst4 * fTemp1), (1.0f - (fConst5 * (fTemp1 - fConst3)))))));
			fRec4[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp2 = ((0.0399999991f * fRec4[0]) + 1.0f);
			float fTemp3 = std::tan((fSlow3 * fTemp2));
			float fTemp4 = (1.0f / fTemp3);
			float fTemp5 = (((fTemp4 + 1.41421354f) / fTemp3) + 1.0f);
			float fTempFTZ2 = ((4.65661287e-10f * float(iRec3[0])) - (((fRec2[2] * (((fTemp4 + -1.41421354f) / fTemp3) + 1.0f)) + (2.0f * (fRec2[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp3)))))) / fTemp5));
			fRec2[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp6 = ((fRec1[0] * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1])))) / fTemp5);
			float fTemp7 = std::tan((fSlow4 * fTemp2));
			float fTemp8 = (1.0f / fTemp7);
			float fTemp9 = (fSlow5 / fTemp2);
			float fTemp10 = (((fTemp8 + fTemp9) / fTemp7) + 1.0f);
			float fTempFTZ3 = (fTemp6 - (((fRec0[2] * (((fTemp8 - fTemp9) / fTemp7) + 1.0f)) + (2.0f * (fRec0[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp7)))))) / fTemp10));
			fRec0[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp11 = (fTemp7 * fTemp10);
			float fTemp12 = std::tan((fSlow6 * fTemp2));
			float fTemp13 = (1.0f / fTemp12);
			float fTemp14 = (fSlow7 / fTemp2);
			float fTemp15 = (((fTemp13 + fTemp14) / fTemp12) + 1.0f);
			float fTempFTZ4 = (fTemp6 - (((fRec6[2] * (((fTemp13 - fTemp14) / fTemp12) + 1.0f)) + (2.0f * (fRec6[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp12)))))) / fTemp15));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp16 = (fTemp12 * fTemp15);
			float fTemp17 = std::tan((fSlow8 * fTemp2));
			float fTemp18 = (1.0f / fTemp17);
			float fTemp19 = (fSlow9 / fTemp2);
			float fTemp20 = (((fTemp18 + fTemp19) / fTemp17) + 1.0f);
			float fTempFTZ5 = (fTemp6 - (((fRec7[2] * (((fTemp18 - fTemp19) / fTemp17) + 1.0f)) + (2.0f * (fRec7[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp17)))))) / fTemp20));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp21 = (fTemp17 * fTemp20);
			float fTemp22 = std::tan((fSlow10 * fTemp2));
			float fTemp23 = (1.0f / fTemp22);
			float fTemp24 = (fSlow11 / fTemp2);
			float fTemp25 = (((fTemp23 + fTemp24) / fTemp22) + 1.0f);
			float fTempFTZ6 = (fTemp6 - (((fRec8[2] * (((fTemp23 - fTemp24) / fTemp22) + 1.0f)) + (2.0f * (fRec8[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp22)))))) / fTemp25));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp26 = (fTemp22 * fTemp25);
			float fTemp27 = std::tan((fSlow12 * fTemp2));
			float fTemp28 = (1.0f / fTemp27);
			float fTemp29 = (fSlow13 / fTemp2);
			float fTemp30 = (((fTemp28 + fTemp29) / fTemp27) + 1.0f);
			float fTempFTZ7 = (fTemp6 - (((fRec9[2] * (((fTemp28 - fTemp29) / fTemp27) + 1.0f)) + (2.0f * (fRec9[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp27)))))) / fTemp30));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp31 = (fTemp27 * fTemp30);
			float fTemp32 = std::tan((fSlow14 * fTemp2));
			float fTemp33 = (1.0f / fTemp32);
			float fTemp34 = (fSlow15 / fTemp2);
			float fTemp35 = (((fTemp33 + fTemp34) / fTemp32) + 1.0f);
			float fTempFTZ8 = (fTemp6 - (((fRec10[2] * (((fTemp33 - fTemp34) / fTemp32) + 1.0f)) + (2.0f * (fRec10[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp32)))))) / fTemp35));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp36 = (fTemp32 * fTemp35);
			float fTemp37 = std::tan((fSlow16 * fTemp2));
			float fTemp38 = (1.0f / fTemp37);
			float fTemp39 = (fSlow17 / fTemp2);
			float fTemp40 = (((fTemp38 + fTemp39) / fTemp37) + 1.0f);
			float fTempFTZ9 = (fTemp6 - (((fRec11[2] * (((fTemp38 - fTemp39) / fTemp37) + 1.0f)) + (2.0f * (fRec11[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp37)))))) / fTemp40));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp41 = (fTemp37 * fTemp40);
			float fTemp42 = std::tan((fSlow18 * fTemp2));
			float fTemp43 = (1.0f / fTemp42);
			float fTemp44 = (fSlow19 / fTemp2);
			float fTemp45 = (((fTemp43 + fTemp44) / fTemp42) + 1.0f);
			float fTempFTZ10 = (fTemp6 - (((fRec12[2] * (((fTemp43 - fTemp44) / fTemp42) + 1.0f)) + (2.0f * (fRec12[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp42)))))) / fTemp45));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp46 = (fTemp42 * fTemp45);
			float fTemp47 = std::tan((fSlow20 * fTemp2));
			float fTemp48 = (1.0f / fTemp47);
			float fTemp49 = (fSlow21 / fTemp2);
			float fTemp50 = (((fTemp48 + fTemp49) / fTemp47) + 1.0f);
			float fTempFTZ11 = (fTemp6 - (((fRec13[2] * (((fTemp48 - fTemp49) / fTemp47) + 1.0f)) + (2.0f * (fRec13[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp47)))))) / fTemp50));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp51 = (fTemp47 * fTemp50);
			float fTemp52 = std::tan((fSlow22 * fTemp2));
			float fTemp53 = (1.0f / fTemp52);
			float fTemp54 = (fSlow23 / fTemp2);
			float fTemp55 = (((fTemp53 + fTemp54) / fTemp52) + 1.0f);
			float fTempFTZ12 = (fTemp6 - (((fRec14[2] * (((fTemp53 - fTemp54) / fTemp52) + 1.0f)) + (2.0f * (fRec14[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp52)))))) / fTemp55));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp56 = (fTemp52 * fTemp55);
			float fTemp57 = std::tan((fSlow24 * fTemp2));
			float fTemp58 = (1.0f / fTemp57);
			float fTemp59 = (fSlow25 / fTemp2);
			float fTemp60 = (((fTemp58 + fTemp59) / fTemp57) + 1.0f);
			float fTempFTZ13 = (fTemp6 - (((fRec15[2] * (((fTemp58 - fTemp59) / fTemp57) + 1.0f)) + (2.0f * (fRec15[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp57)))))) / fTemp60));
			fRec15[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp61 = (fTemp57 * fTemp60);
			float fTemp62 = std::tan((fSlow26 * fTemp2));
			float fTemp63 = (1.0f / fTemp62);
			float fTemp64 = (fSlow27 / fTemp2);
			float fTemp65 = (((fTemp63 + fTemp64) / fTemp62) + 1.0f);
			float fTempFTZ14 = (fTemp6 - (((fRec16[2] * (((fTemp63 - fTemp64) / fTemp62) + 1.0f)) + (2.0f * (fRec16[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp62)))))) / fTemp65));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp66 = (fTemp62 * fTemp65);
			float fTemp67 = std::tan((fSlow28 * fTemp2));
			float fTemp68 = (1.0f / fTemp67);
			float fTemp69 = (fSlow29 / fTemp2);
			float fTemp70 = (((fTemp68 + fTemp69) / fTemp67) + 1.0f);
			float fTempFTZ15 = (fTemp6 - (((fRec17[2] * (((fTemp68 - fTemp69) / fTemp67) + 1.0f)) + (2.0f * (fRec17[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp67)))))) / fTemp70));
			fRec17[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp71 = (fTemp67 * fTemp70);
			float fTemp72 = std::tan((fSlow30 * fTemp2));
			float fTemp73 = (1.0f / fTemp72);
			float fTemp74 = (fSlow31 / fTemp2);
			float fTemp75 = (((fTemp73 + fTemp74) / fTemp72) + 1.0f);
			float fTempFTZ16 = (fTemp6 - (((fRec18[2] * (((fTemp73 - fTemp74) / fTemp72) + 1.0f)) + (2.0f * (fRec18[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp72)))))) / fTemp75));
			fRec18[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp76 = (fTemp72 * fTemp75);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * (((fRec0[2] * (0.0f - (0.300000012f / fTemp11))) + (((0.400000006f * ((fRec6[0] / fTemp16) + (fRec7[0] / fTemp21))) + ((fRec7[2] * (0.0f - (0.400000006f / fTemp21))) + (((fRec8[2] * (0.0f - (0.5f / fTemp26))) + (((fRec9[2] * (0.0f - (0.600000024f / fTemp31))) + (((fRec10[2] * (0.0f - (0.699999988f / fTemp36))) + (((fRec11[2] * (0.0f - (0.800000012f / fTemp41))) + (((fRec12[2] * (0.0f - (3.5f / fTemp46))) + (((4.0f * (fRec13[0] / fTemp51)) + (fRec13[2] * (0.0f - (4.0f / fTemp51)))) + (3.5f * (fRec12[0] / fTemp46)))) + (0.800000012f * (fRec11[0] / fTemp41)))) + (0.699999988f * (fRec10[0] / fTemp36)))) + (0.600000024f * (fRec9[0] / fTemp31)))) + (0.5f * (fRec8[0] / fTemp26)))) + (fRec6[2] * (0.0f - (0.400000006f / fTemp16)))))) + (0.300000012f * (fRec0[0] / fTemp11)))) + (1.5f * (((0.100000001f * ((fRec14[0] / fTemp56) + (fRec15[0] / fTemp61))) + ((fRec15[2] * (0.0f - (0.100000001f / fTemp61))) + (((fRec16[2] * (0.0f - (0.150000006f / fTemp66))) + (((fRec17[2] * (0.0f - (0.200000003f / fTemp71))) + (((0.300000012f * (fRec18[0] / fTemp76)) + (fRec18[2] * (0.0f - (0.300000012f / fTemp76)))) + (0.200000003f * (fRec17[0] / fTemp71)))) + (0.150000006f * (fRec16[0] / fTemp66)))) + (fRec14[2] * (0.0f - (0.100000001f / fTemp56)))))) * std::max<float>(0.0f, std::min<float>((fConst21 * fTemp1), (1.0f - (fConst5 * (fTemp1 - fConst20)))))))))))));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec1[1] = fRec1[0];
			iRec3[1] = iRec3[0];
			iRec5[1] = iRec5[0];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
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
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
		}
	}

};

#endif
