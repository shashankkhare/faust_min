/* ------------------------------------------------------------
name: "tanpura"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustTanpuraDSP_H__
#define  __FaustTanpuraDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustTanpuraDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustTanpuraDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fConst5;
	float fRec3[2];
	FAUSTFLOAT fHslider2;
	float fVec0[2];
	float fRec2[2];
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	float fConst7;
	int iRec5[2];
	float fVec1[2];
	float fConst8;
	float fRec4[2];
	FAUSTFLOAT fButton0;
	float fVec2[2];
	int IOTA;
	float fVec3[262144];
	float fConst9;
	float fRec6[2];
	float fRec0[16384];
	FAUSTFLOAT fHslider4;
	float fRec10[2];
	float fVec4[2];
	float fRec9[2];
	float fRec8[2];
	int iConst10;
	float fRec11[2];
	float fRec7[16384];
	float fVec5[2];
	float fRec14[2];
	float fRec13[2];
	int iConst11;
	float fRec15[2];
	float fRec12[16384];
	float fVec6[2];
	float fRec18[2];
	float fRec17[2];
	int iConst12;
	float fRec19[2];
	float fRec16[16384];
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec20[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "tanpura.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tanpura");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = (1.0f / std::tan((5026.54834f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = (1.0f - fConst1);
		fConst4 = (44.0999985f / fConst0);
		fConst5 = (1.0f - fConst4);
		float fConst6 = (1.0f / std::tan((5654.8667f / fConst0)));
		fConst7 = (1.0f / (fConst6 + 1.0f));
		fConst8 = (1.0f - fConst6);
		fConst9 = (0.0120000001f * fConst0);
		iConst10 = int((0.449999988f * fConst0));
		iConst11 = int((0.899999976f * fConst0));
		iConst12 = int((1.35000002f * fConst0));
		float fConst13 = std::tan((15707.9629f / fConst0));
		float fConst14 = (1.0f / fConst13);
		float fConst15 = (fConst14 + 1.0f);
		fConst16 = (1.0f / (fConst13 * fConst15));
		fConst17 = (0.0f - fConst16);
		fConst18 = ((1.0f - fConst14) / fConst15);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.69999999999999996f);
		fHslider1 = FAUSTFLOAT(130.81f);
		fHslider2 = FAUSTFLOAT(0.34999999999999998f);
		fHslider3 = FAUSTFLOAT(0.69999999999999996f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec3[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec5[l4] = 0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec2[l7] = 0.0f;
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 262144); l8 = (l8 + 1)) {
			fVec3[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec6[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 16384); l10 = (l10 + 1)) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec4[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec9[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec8[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec11[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 16384); l16 = (l16 + 1)) {
			fRec7[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fVec5[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec14[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec13[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec15[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 16384); l21 = (l21 + 1)) {
			fRec12[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fVec6[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec18[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec17[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec19[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 16384); l26 = (l26 + 1)) {
			fRec16[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec20[l27] = 0.0f;
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
	
	virtual FaustTanpuraDSP* clone() {
		return new FaustTanpuraDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("tanpura");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(130.809998f), FAUSTFLOAT(40.0f), FAUSTFLOAT(400.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("freq1", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("jivari", &fHslider2, FAUSTFLOAT(0.349999994f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider3, FAUSTFLOAT(0.699999988f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fConst4 * fSlow1);
		float fSlow3 = (0.119999997f * float(fHslider2));
		float fSlow4 = (0.119999997f * float(fHslider3));
		float fSlow5 = float(fButton0);
		float fSlow6 = float(fHslider4);
		float fThen1 = (1.5f * fSlow1);
		float fSlow7 = (fConst4 * ((fSlow6 > 0.0f) ? fSlow6 : fThen1));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec3[0] = (fSlow2 + (fConst5 * fRec3[1]));
			float fTemp0 = fRec0[((IOTA - (int(std::min<float>(8192.0f, std::max<float>(0.0f, ((fConst0 / std::max<float>(20.0f, fRec3[0])) + -2.0f)))) + 1)) & 16383)];
			float fTemp1 = std::fabs(fTemp0);
			float fTemp2 = (fTemp0 * (1.0f - (fSlow3 * (fTemp1 / (fTemp1 + 1.0f)))));
			fVec0[0] = fTemp2;
			fRec2[0] = (0.0f - (fConst2 * ((fConst3 * fRec2[1]) - (fTemp2 + fVec0[1]))));
			fRec1[0] = ((fRec2[0] + (0.995000005f * fRec1[1])) - fRec2[1]);
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float fTemp3 = float(iRec5[0]);
			fVec1[0] = fTemp3;
			fRec4[0] = (fConst7 * ((4.65661287e-10f * (fTemp3 + fVec1[1])) - (fConst8 * fRec4[1])));
			fVec2[0] = fSlow5;
			float fTemp4 = (fSlow5 - fVec2[1]);
			float fTemp5 = (fTemp4 * float((fTemp4 > 0.0f)));
			fVec3[(IOTA & 262143)] = fTemp5;
			float fThen0 = std::max<float>(0.0f, (fRec6[1] + -1.0f));
			fRec6[0] = ((fTemp5 > 0.0f) ? fConst9 : fThen0);
			fRec0[(IOTA & 16383)] = ((0.99879998f * fRec1[0]) + (fSlow4 * (fRec4[0] * float((fRec6[0] > 0.0f)))));
			fRec10[0] = (fSlow7 + (fConst5 * fRec10[1]));
			float fTemp6 = fRec7[((IOTA - (int(std::min<float>(8192.0f, std::max<float>(0.0f, ((fConst0 / std::max<float>(20.0f, fRec10[0])) + -2.0f)))) + 1)) & 16383)];
			float fTemp7 = std::fabs(fTemp6);
			float fTemp8 = (fTemp6 * (1.0f - (fSlow3 * (fTemp7 / (fTemp7 + 1.0f)))));
			fVec4[0] = fTemp8;
			fRec9[0] = (0.0f - (fConst2 * ((fConst3 * fRec9[1]) - (fTemp8 + fVec4[1]))));
			fRec8[0] = ((fRec9[0] + (0.995000005f * fRec8[1])) - fRec9[1]);
			float fThen2 = std::max<float>(0.0f, (fRec11[1] + -1.0f));
			fRec11[0] = ((fVec3[((IOTA - iConst10) & 262143)] > 0.0f) ? fConst9 : fThen2);
			fRec7[(IOTA & 16383)] = ((0.99879998f * fRec8[0]) + (fSlow4 * (fRec4[0] * float((fRec11[0] > 0.0f)))));
			int iTemp9 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, ((fConst0 / std::max<float>(20.0f, (2.0f * fRec3[0]))) + -2.0f)))) + 1);
			float fTemp10 = fRec12[((IOTA - iTemp9) & 16383)];
			float fTemp11 = std::fabs(fTemp10);
			float fTemp12 = (fTemp10 * (1.0f - (fSlow3 * (fTemp11 / (fTemp11 + 1.0f)))));
			fVec5[0] = fTemp12;
			fRec14[0] = (0.0f - (fConst2 * ((fConst3 * fRec14[1]) - (fTemp12 + fVec5[1]))));
			fRec13[0] = ((fRec14[0] + (0.995000005f * fRec13[1])) - fRec14[1]);
			float fThen3 = std::max<float>(0.0f, (fRec15[1] + -1.0f));
			fRec15[0] = ((fVec3[((IOTA - iConst11) & 262143)] > 0.0f) ? fConst9 : fThen3);
			fRec12[(IOTA & 16383)] = ((0.99879998f * fRec13[0]) + (fSlow4 * (fRec4[0] * float((fRec15[0] > 0.0f)))));
			float fTemp13 = fRec16[((IOTA - iTemp9) & 16383)];
			float fTemp14 = std::fabs(fTemp13);
			float fTemp15 = (fTemp13 * (1.0f - (fSlow3 * (fTemp14 / (fTemp14 + 1.0f)))));
			fVec6[0] = fTemp15;
			fRec18[0] = (0.0f - (fConst2 * ((fConst3 * fRec18[1]) - (fTemp15 + fVec6[1]))));
			fRec17[0] = ((fRec18[0] + (0.995000005f * fRec17[1])) - fRec18[1]);
			float fThen4 = std::max<float>(0.0f, (fRec19[1] + -1.0f));
			fRec19[0] = ((fVec3[((IOTA - iConst12) & 262143)] > 0.0f) ? fConst9 : fThen4);
			fRec16[(IOTA & 16383)] = ((0.99879998f * fRec17[0]) + (fSlow4 * (fRec4[0] * float((fRec19[0] > 0.0f)))));
			fRec20[0] = ((4.65661287e-10f * ((fConst16 * fTemp3) + (fConst17 * fVec1[1]))) - (fConst18 * fRec20[1]));
			output0[i0] = FAUSTFLOAT((fSlow0 * ((0.219999999f * (((fRec0[((IOTA - 0) & 16383)] + fRec7[((IOTA - 0) & 16383)]) + fRec12[((IOTA - 0) & 16383)]) + fRec16[((IOTA - 0) & 16383)])) + (0.00150000001f * fRec20[0]))));
			fRec3[1] = fRec3[0];
			fVec0[1] = fVec0[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			iRec5[1] = iRec5[0];
			fVec1[1] = fVec1[0];
			fRec4[1] = fRec4[0];
			fVec2[1] = fVec2[0];
			IOTA = (IOTA + 1);
			fRec6[1] = fRec6[0];
			fRec10[1] = fRec10[0];
			fVec4[1] = fVec4[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fVec5[1] = fVec5[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fVec6[1] = fVec6[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec19[1] = fRec19[0];
			fRec20[1] = fRec20[0];
		}
	}

};

#endif
