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
	float fRec2[2];
	int iRec4[2];
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fConst3;
	float fConst4;
	int iRec6[2];
	float fConst5;
	float fRec5[2];
	float fRec3[3];
	float fConst6;
	float fRec1[3];
	float fConst7;
	float fRec7[3];
	float fConst8;
	float fRec8[3];
	float fConst9;
	float fRec9[3];
	float fConst10;
	float fRec10[3];
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fRec11[3];
	float fConst15;
	float fRec12[3];
	float fConst16;
	float fRec13[3];
	float fConst17;
	float fRec14[3];
	float fConst18;
	float fRec15[3];
	float fConst19;
	float fRec16[3];
	float fConst20;
	float fRec17[3];
	float fConst21;
	float fRec18[3];
	float fConst22;
	float fRec19[3];
	float fVec2[2];
	float fRec0[2];
	
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
		fConst1 = std::exp((0.0f - (16.666666f / fConst0)));
		fConst2 = (12.566371f / fConst0);
		fConst3 = std::max<float>(1.0f, (0.00999999978f * fConst0));
		fConst4 = (1.0f / fConst3);
		fConst5 = (1.0f / std::max<float>(1.0f, (2.0f * fConst0)));
		fConst6 = (20.6716805f / fConst0);
		fConst7 = (25.5411491f / fConst0);
		fConst8 = (17.0274315f / fConst0);
		fConst9 = (13.6659279f / fConst0);
		fConst10 = (11.0584059f / fConst0);
		fConst11 = std::max<float>(1.0f, (0.100000001f * fConst0));
		fConst12 = (1.0f / fConst11);
		fConst13 = (1.0f / std::max<float>(1.0f, (1.20000005f * fConst0)));
		fConst14 = (8.82787514f / fConst0);
		fConst15 = (7.00575161f / fConst0);
		fConst16 = (7.05287552f / fConst0);
		fConst17 = (5.42867231f / fConst0);
		fConst18 = (5.37212324f / fConst0);
		fConst19 = (4.27884912f / fConst0);
		fConst20 = (4.2411499f / fConst0);
		fConst21 = (3.18871665f / fConst0);
		fConst22 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
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
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec4[l3] = 0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec6[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec1[l7] = 0.0f;
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
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec17[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec19[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fVec2[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec0[l22] = 0.0f;
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
		ui_interface->addHorizontalSlider("gain", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.928264022f * (float(fHslider0) * float(fHslider1)));
		float fSlow1 = float(fButton0);
		float fSlow2 = float(fHslider2);
		float fSlow3 = (fConst2 * fSlow2);
		float fSlow4 = (fConst6 * fSlow2);
		float fSlow5 = (0.0815042257f / fSlow2);
		float fSlow6 = (fConst7 * fSlow2);
		float fSlow7 = (0.0965920314f / fSlow2);
		float fSlow8 = (fConst8 * fSlow2);
		float fSlow9 = (0.0737611875f / fSlow2);
		float fSlow10 = (fConst9 * fSlow2);
		float fSlow11 = (0.073257409f / fSlow2);
		float fSlow12 = (fConst10 * fSlow2);
		float fSlow13 = (0.0752608478f / fSlow2);
		float fSlow14 = (fConst14 * fSlow2);
		float fSlow15 = (0.0806699544f / fSlow2);
		float fSlow16 = (fConst15 * fSlow2);
		float fSlow17 = (0.0795176104f / fSlow2);
		float fSlow18 = (fConst16 * fSlow2);
		float fSlow19 = (0.0837119892f / fSlow2);
		float fSlow20 = (fConst17 * fSlow2);
		float fSlow21 = (0.0877562687f / fSlow2);
		float fSlow22 = (fConst18 * fSlow2);
		float fSlow23 = (0.0808717161f / fSlow2);
		float fSlow24 = (fConst19 * fSlow2);
		float fSlow25 = (0.089689225f / fSlow2);
		float fSlow26 = (fConst20 * fSlow2);
		float fSlow27 = (0.0843915194f / fSlow2);
		float fSlow28 = (fConst21 * fSlow2);
		float fSlow29 = (0.0980238095f / fSlow2);
		float fSlow30 = (fConst22 * fSlow2);
		float fSlow31 = (0.0908603743f / fSlow2);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow1;
			int iTemp0 = (fSlow1 > fVec0[1]);
			iVec1[0] = iTemp0;
			float fThen0 = (fConst1 * fRec2[1]);
			float fTempFTZ0 = (iTemp0 ? 1.0f : fThen0);
			fRec2[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			iRec6[0] = ((iTemp0 > iVec1[1]) + ((iTemp0 <= iVec1[1]) * (iRec6[1] + (iRec6[1] > 0))));
			float fTemp1 = float(iRec6[0]);
			float fTempFTZ1 = ((0.999000013f * fRec5[1]) + (0.00100000005f * std::max<float>(0.0f, std::min<float>((fConst4 * fTemp1), (1.0f - (fConst5 * (fTemp1 - fConst3)))))));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp2 = ((0.0399999991f * fRec5[0]) + 1.0f);
			float fTemp3 = std::tan((fSlow3 * fTemp2));
			float fTemp4 = (1.0f / fTemp3);
			float fTemp5 = (((fTemp4 + 1.41421354f) / fTemp3) + 1.0f);
			float fTempFTZ2 = ((4.65661287e-10f * float(iRec4[0])) - (((fRec3[2] * (((fTemp4 + -1.41421354f) / fTemp3) + 1.0f)) + (2.0f * (fRec3[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp3)))))) / fTemp5));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp6 = ((fRec2[0] * (fRec3[2] + (fRec3[0] + (2.0f * fRec3[1])))) / fTemp5);
			float fTemp7 = std::tan((fSlow4 * fTemp2));
			float fTemp8 = (1.0f / fTemp7);
			float fTemp9 = (fSlow5 / fTemp2);
			float fTemp10 = (((fTemp8 + fTemp9) / fTemp7) + 1.0f);
			float fTempFTZ3 = (fTemp6 - (((fRec1[2] * (((fTemp8 - fTemp9) / fTemp7) + 1.0f)) + (2.0f * (fRec1[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp7)))))) / fTemp10));
			fRec1[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp11 = (fTemp7 * fTemp10);
			float fTemp12 = std::tan((fSlow6 * fTemp2));
			float fTemp13 = (1.0f / fTemp12);
			float fTemp14 = (fSlow7 / fTemp2);
			float fTemp15 = (((fTemp13 + fTemp14) / fTemp12) + 1.0f);
			float fTempFTZ4 = (fTemp6 - (((fRec7[2] * (((fTemp13 - fTemp14) / fTemp12) + 1.0f)) + (2.0f * (fRec7[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp12)))))) / fTemp15));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp16 = (fTemp12 * fTemp15);
			float fTemp17 = std::tan((fSlow8 * fTemp2));
			float fTemp18 = (1.0f / fTemp17);
			float fTemp19 = (fSlow9 / fTemp2);
			float fTemp20 = (((fTemp18 + fTemp19) / fTemp17) + 1.0f);
			float fTempFTZ5 = (fTemp6 - (((fRec8[2] * (((fTemp18 - fTemp19) / fTemp17) + 1.0f)) + (2.0f * (fRec8[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp17)))))) / fTemp20));
			fRec8[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTemp21 = (fTemp17 * fTemp20);
			float fTemp22 = std::tan((fSlow10 * fTemp2));
			float fTemp23 = (1.0f / fTemp22);
			float fTemp24 = (fSlow11 / fTemp2);
			float fTemp25 = (((fTemp23 + fTemp24) / fTemp22) + 1.0f);
			float fTempFTZ6 = (fTemp6 - (((fRec9[2] * (((fTemp23 - fTemp24) / fTemp22) + 1.0f)) + (2.0f * (fRec9[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp22)))))) / fTemp25));
			fRec9[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp26 = (fTemp22 * fTemp25);
			float fTemp27 = std::tan((fSlow12 * fTemp2));
			float fTemp28 = (1.0f / fTemp27);
			float fTemp29 = (fSlow13 / fTemp2);
			float fTemp30 = (((fTemp28 + fTemp29) / fTemp27) + 1.0f);
			float fTempFTZ7 = (fTemp6 - (((fRec10[2] * (((fTemp28 - fTemp29) / fTemp27) + 1.0f)) + (2.0f * (fRec10[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp27)))))) / fTemp30));
			fRec10[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp31 = (fTemp27 * fTemp30);
			float fTemp32 = (1.20000005f * (((0.100000001f * ((fRec1[0] / fTemp11) + (fRec7[0] / fTemp16))) + ((fRec7[2] * (0.0f - (0.100000001f / fTemp16))) + (((fRec8[2] * (0.0f - (0.150000006f / fTemp21))) + (((fRec9[2] * (0.0f - (0.200000003f / fTemp26))) + (((0.300000012f * (fRec10[0] / fTemp31)) + (fRec10[2] * (0.0f - (0.300000012f / fTemp31)))) + (0.200000003f * (fRec9[0] / fTemp26)))) + (0.150000006f * (fRec8[0] / fTemp21)))) + (fRec1[2] * (0.0f - (0.100000001f / fTemp11)))))) * std::max<float>(0.0f, std::min<float>((fConst12 * fTemp1), ((fConst13 * (fConst11 - fTemp1)) + 1.0f)))));
			float fTemp33 = std::tan((fSlow14 * fTemp2));
			float fTemp34 = (1.0f / fTemp33);
			float fTemp35 = (fSlow15 / fTemp2);
			float fTemp36 = (((fTemp34 + fTemp35) / fTemp33) + 1.0f);
			float fTempFTZ8 = (fTemp6 - (((fRec11[2] * (((fTemp34 - fTemp35) / fTemp33) + 1.0f)) + (2.0f * (fRec11[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp33)))))) / fTemp36));
			fRec11[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTemp37 = (fTemp33 * fTemp36);
			float fTemp38 = (fRec11[2] * (0.0f - (0.300000012f / fTemp37)));
			float fTemp39 = (0.300000012f * (fRec11[0] / fTemp37));
			float fTemp40 = std::tan((fSlow16 * fTemp2));
			float fTemp41 = (1.0f / fTemp40);
			float fTemp42 = (fSlow17 / fTemp2);
			float fTemp43 = (((fTemp41 + fTemp42) / fTemp40) + 1.0f);
			float fTempFTZ9 = (fTemp6 - (((fRec12[2] * (((fTemp41 - fTemp42) / fTemp40) + 1.0f)) + (2.0f * (fRec12[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp40)))))) / fTemp43));
			fRec12[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTemp44 = (fTemp40 * fTemp43);
			float fTemp45 = std::tan((fSlow18 * fTemp2));
			float fTemp46 = (1.0f / fTemp45);
			float fTemp47 = (fSlow19 / fTemp2);
			float fTemp48 = (((fTemp46 + fTemp47) / fTemp45) + 1.0f);
			float fTempFTZ10 = (fTemp6 - (((fRec13[2] * (((fTemp46 - fTemp47) / fTemp45) + 1.0f)) + (2.0f * (fRec13[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp45)))))) / fTemp48));
			fRec13[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTemp49 = (fTemp45 * fTemp48);
			float fTemp50 = (0.400000006f * ((fRec12[0] / fTemp44) + (fRec13[0] / fTemp49)));
			float fTemp51 = (fRec13[2] * (0.0f - (0.400000006f / fTemp49)));
			float fTemp52 = (fRec12[2] * (0.0f - (0.400000006f / fTemp44)));
			float fTemp53 = std::tan((fSlow20 * fTemp2));
			float fTemp54 = (1.0f / fTemp53);
			float fTemp55 = (fSlow21 / fTemp2);
			float fTemp56 = (((fTemp54 + fTemp55) / fTemp53) + 1.0f);
			float fTempFTZ11 = (fTemp6 - (((fRec14[2] * (((fTemp54 - fTemp55) / fTemp53) + 1.0f)) + (2.0f * (fRec14[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp53)))))) / fTemp56));
			fRec14[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTemp57 = (fTemp53 * fTemp56);
			float fTemp58 = (fRec14[2] * (0.0f - (0.5f / fTemp57)));
			float fTemp59 = (0.5f * (fRec14[0] / fTemp57));
			float fTemp60 = std::tan((fSlow22 * fTemp2));
			float fTemp61 = (1.0f / fTemp60);
			float fTemp62 = (fSlow23 / fTemp2);
			float fTemp63 = (((fTemp61 + fTemp62) / fTemp60) + 1.0f);
			float fTempFTZ12 = (fTemp6 - (((fRec15[2] * (((fTemp61 - fTemp62) / fTemp60) + 1.0f)) + (2.0f * (fRec15[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp60)))))) / fTemp63));
			fRec15[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTemp64 = (fTemp60 * fTemp63);
			float fTemp65 = (fRec15[2] * (0.0f - (0.600000024f / fTemp64)));
			float fTemp66 = (0.600000024f * (fRec15[0] / fTemp64));
			float fTemp67 = std::tan((fSlow24 * fTemp2));
			float fTemp68 = (1.0f / fTemp67);
			float fTemp69 = (fSlow25 / fTemp2);
			float fTemp70 = (((fTemp68 + fTemp69) / fTemp67) + 1.0f);
			float fTempFTZ13 = (fTemp6 - (((fRec16[2] * (((fTemp68 - fTemp69) / fTemp67) + 1.0f)) + (2.0f * (fRec16[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp67)))))) / fTemp70));
			fRec16[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp71 = (fTemp67 * fTemp70);
			float fTemp72 = (fRec16[2] * (0.0f - (0.699999988f / fTemp71)));
			float fTemp73 = (0.699999988f * (fRec16[0] / fTemp71));
			float fTemp74 = std::tan((fSlow26 * fTemp2));
			float fTemp75 = (1.0f / fTemp74);
			float fTemp76 = (fSlow27 / fTemp2);
			float fTemp77 = (((fTemp75 + fTemp76) / fTemp74) + 1.0f);
			float fTempFTZ14 = (fTemp6 - (((fRec17[2] * (((fTemp75 - fTemp76) / fTemp74) + 1.0f)) + (2.0f * (fRec17[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp74)))))) / fTemp77));
			fRec17[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTemp78 = (fTemp74 * fTemp77);
			float fTemp79 = (fRec17[2] * (0.0f - (0.800000012f / fTemp78)));
			float fTemp80 = (0.800000012f * (fRec17[0] / fTemp78));
			float fTemp81 = std::tan((fSlow28 * fTemp2));
			float fTemp82 = (1.0f / fTemp81);
			float fTemp83 = (fSlow29 / fTemp2);
			float fTemp84 = (((fTemp82 + fTemp83) / fTemp81) + 1.0f);
			float fTempFTZ15 = (fTemp6 - (((fRec18[2] * (((fTemp82 - fTemp83) / fTemp81) + 1.0f)) + (2.0f * (fRec18[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp81)))))) / fTemp84));
			fRec18[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTemp85 = (fTemp81 * fTemp84);
			float fTemp86 = (fRec18[2] * (0.0f - (3.5f / fTemp85)));
			float fTemp87 = (3.5f * (fRec18[0] / fTemp85));
			float fTemp88 = std::tan((fSlow30 * fTemp2));
			float fTemp89 = (1.0f / fTemp88);
			float fTemp90 = (fSlow31 / fTemp2);
			float fTemp91 = (((fTemp89 + fTemp90) / fTemp88) + 1.0f);
			float fTempFTZ16 = (fTemp6 - (((fRec19[2] * (((fTemp89 - fTemp90) / fTemp88) + 1.0f)) + (2.0f * (fRec19[1] * (1.0f - (1.0f / FaustChougongDSP_faustpower2_f(fTemp88)))))) / fTemp91));
			fRec19[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTemp92 = (fTemp88 * fTemp91);
			float fTemp93 = (fRec19[2] * (0.0f - (4.0f / fTemp92)));
			float fTemp94 = (4.0f * (fRec19[0] / fTemp92));
			fVec2[0] = ((fTemp38 + ((fTemp50 + (fTemp51 + ((fTemp58 + ((fTemp65 + ((fTemp72 + ((fTemp79 + ((fTemp86 + ((fTemp94 + fTemp93) + fTemp87)) + fTemp80)) + fTemp73)) + fTemp66)) + fTemp59)) + fTemp52))) + fTemp39)) + fTemp32);
			float fTempFTZ17 = ((fTemp32 + (fTemp38 + (fTemp39 + (fTemp50 + (fTemp51 + (fTemp52 + (fTemp58 + (fTemp59 + (fTemp65 + (fTemp66 + (fTemp72 + (fTemp73 + (fTemp79 + (fTemp80 + (fTemp86 + (fTemp87 + (fTemp93 + ((0.995000005f * fRec0[1]) + fTemp94)))))))))))))))))) - fVec2[1]);
			fRec0[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * fRec0[0])))));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec2[1] = fRec2[0];
			iRec4[1] = iRec4[0];
			iRec6[1] = iRec6[0];
			fRec5[1] = fRec5[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
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
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fVec2[1] = fVec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
