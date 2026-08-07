/* ------------------------------------------------------------
author: "Shashank Khare"
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "tibetanBowlMono"
version: "2.4"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustBowlDSP_H__
#define  __FaustBowlDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
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
	
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst4;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fRec3[3];
	float fConst8;
	float fVec2[2];
	float fRec2[2];
	FAUSTFLOAT fEntry1;
	float fConst9;
	float fRec4[3];
	int IOTA;
	float fRec1[2048];
	float fConst10;
	float fConst11;
	float fRec6[3];
	float fRec5[4096];
	float fConst12;
	float fConst13;
	float fRec8[3];
	float fRec7[8192];
	float fConst14;
	float fConst15;
	float fRec10[3];
	float fRec9[2048];
	float fConst16;
	float fConst17;
	float fRec12[3];
	float fRec11[1024];
	float fConst18;
	float fConst19;
	float fRec14[3];
	float fRec13[512];
	float fConst20;
	float fConst21;
	float fRec16[3];
	float fRec15[512];
	float fConst22;
	float fConst23;
	float fRec18[3];
	float fRec17[512];
	float fConst24;
	float fConst25;
	float fRec20[3];
	float fRec19[128];
	float fConst26;
	float fConst27;
	float fRec22[3];
	float fRec21[128];
	float fConst28;
	float fConst29;
	float fRec24[3];
	float fRec23[1024];
	float fConst30;
	float fConst31;
	float fRec26[3];
	float fRec25[512];
	float fConst32;
	float fConst33;
	float fRec28[3];
	float fRec27[256];
	float fVec3[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Shashank Khare");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "Banded Waveguide Tibetan Bowl (Mono - Correct Physical Velocity Mapping)");
		m->declare("filename", "bowl.dsp");
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
		m->declare("licence", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "tibetanBowlMono");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("version", "2.4");
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
		float fConst1 = std::tan((471.238892f / fConst0));
		float fConst2 = (1.0f / fConst1);
		float fConst3 = (((fConst2 + 0.666666687f) / fConst1) + 1.0f);
		fConst4 = (20.0f / (fConst1 * fConst3));
		fConst5 = (1.0f / fConst3);
		fConst6 = (((fConst2 + -0.666666687f) / fConst1) + 1.0f);
		fConst7 = (2.0f * (1.0f - (1.0f / FaustBowlDSP_faustpower2_f(fConst1))));
		fConst8 = (0.0f - fConst4);
		fConst9 = (6.28318548f / fConst0);
		fConst10 = (1.60000002f * fConst0);
		fConst11 = (3.92699075f / fConst0);
		fConst12 = (2.55999994f * fConst0);
		fConst13 = (2.45436931f / fConst0);
		fConst14 = (0.621118009f * fConst0);
		fConst15 = (10.1159286f / fConst0);
		fConst16 = (0.385787576f * fConst0);
		fConst17 = (16.286644f / fConst0);
		fConst18 = (0.239619613f * fConst0);
		fConst19 = (26.2214985f / fConst0);
		fConst20 = (0.148949161f * fConst0);
		fConst21 = (42.1834221f / fConst0);
		fConst22 = (0.142857149f * fConst0);
		fConst23 = (43.982296f / fConst0);
		fConst24 = (0.0574712642f * fConst0);
		fConst25 = (109.327423f / fConst0);
		fConst26 = (0.0625f * fConst0);
		fConst27 = (100.530968f / fConst0);
		fConst28 = (0.5f * fConst0);
		fConst29 = (12.566371f / fConst0);
		fConst30 = (0.25f * fConst0);
		fConst31 = (25.1327419f / fConst0);
		fConst32 = (0.125f * fConst0);
		fConst33 = (50.2654839f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
		fEntry1 = FAUSTFLOAT(220.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
		}
		IOTA = 0;
		for (int l6 = 0; (l6 < 2048); l6 = (l6 + 1)) {
			fRec1[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 4096); l8 = (l8 + 1)) {
			fRec5[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 8192); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fRec9[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 1024); l14 = (l14 + 1)) {
			fRec11[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 512); l16 = (l16 + 1)) {
			fRec13[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 512); l18 = (l18 + 1)) {
			fRec15[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 512); l20 = (l20 + 1)) {
			fRec17[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec20[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 128); l22 = (l22 + 1)) {
			fRec19[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 128); l24 = (l24 + 1)) {
			fRec21[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec24[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 1024); l26 = (l26 + 1)) {
			fRec23[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec26[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 512); l28 = (l28 + 1)) {
			fRec25[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 256); l30 = (l30 + 1)) {
			fRec27[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fVec3[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec0[l32] = 0.0f;
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
		ui_interface->openVerticalBox("tibetanBowlMono");
		ui_interface->addNumEntry("freq", &fEntry1, FAUSTFLOAT(220.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addNumEntry("gain", &fEntry0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (12.5f * float(fEntry0));
		float fSlow1 = float(fHslider0);
		float fSlow2 = float(fButton0);
		float fSlow3 = float(fEntry1);
		int iSlow4 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst0 / fSlow3)))) + 1);
		float fSlow5 = (0.0f - (1.99000001f * std::cos((fConst9 * fSlow3))));
		int iSlow6 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst10 / fSlow3)))) + 1);
		float fSlow7 = (0.0f - (1.99000001f * std::cos((fConst11 * fSlow3))));
		int iSlow8 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst12 / fSlow3)))) + 1);
		float fSlow9 = (0.0f - (1.99000001f * std::cos((fConst13 * fSlow3))));
		int iSlow10 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst14 / fSlow3)))) + 1);
		float fSlow11 = (0.0f - (1.99000001f * std::cos((fConst15 * fSlow3))));
		int iSlow12 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst16 / fSlow3)))) + 1);
		float fSlow13 = (0.0f - (1.99000001f * std::cos((fConst17 * fSlow3))));
		int iSlow14 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst18 / fSlow3)))) + 1);
		float fSlow15 = (0.0f - (1.99000001f * std::cos((fConst19 * fSlow3))));
		int iSlow16 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst20 / fSlow3)))) + 1);
		float fSlow17 = (0.0f - (1.99000001f * std::cos((fConst21 * fSlow3))));
		int iSlow18 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst22 / fSlow3)))) + 1);
		float fSlow19 = (0.0f - (1.99000001f * std::cos((fConst23 * fSlow3))));
		int iSlow20 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst24 / fSlow3)))) + 1);
		float fSlow21 = (0.0f - (1.99000001f * std::cos((fConst25 * fSlow3))));
		int iSlow22 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst26 / fSlow3)))) + 1);
		float fSlow23 = (0.0f - (1.99000001f * std::cos((fConst27 * fSlow3))));
		int iSlow24 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst28 / fSlow3)))) + 1);
		float fSlow25 = (0.0f - (1.99000001f * std::cos((fConst29 * fSlow3))));
		int iSlow26 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst30 / fSlow3)))) + 1);
		float fSlow27 = (0.0f - (1.99000001f * std::cos((fConst31 * fSlow3))));
		int iSlow28 = (int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst32 / fSlow3)))) + 1);
		float fSlow29 = (0.0f - (1.99000001f * std::cos((fConst33 * fSlow3))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow2;
			int iTemp0 = (fSlow2 > fVec0[1]);
			iVec1[0] = iTemp0;
			int iTemp1 = (iTemp0 - iVec1[1]);
			float fTempFTZ0 = (float((iTemp1 * (iTemp1 > 0))) - (fConst5 * ((fConst6 * fRec3[2]) + (fConst7 * fRec3[1]))));
			fRec3[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp2 = (fSlow1 * ((fConst4 * fRec3[0]) + (fConst8 * fRec3[2])));
			fVec2[0] = fTemp2;
			float fTempFTZ1 = (((0.995000005f * fRec2[1]) + fTemp2) - fVec2[1]);
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((0.995999992f * fRec1[((IOTA - iSlow4) & 2047)]) - ((fSlow5 * fRec4[1]) + (0.990024984f * fRec4[2])));
			fRec4[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((1.5f * fRec2[0]) + (0.00499999989f * (fRec4[0] - fRec4[2])));
			fRec1[(IOTA & 2047)] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTemp3 = (0.75f * fRec2[0]);
			float fTempFTZ4 = ((0.995999992f * fRec5[((IOTA - iSlow6) & 4095)]) - ((fSlow7 * fRec6[1]) + (0.990024984f * fRec6[2])));
			fRec6[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = (fTemp3 + (0.00499999989f * (fRec6[0] - fRec6[2])));
			fRec5[(IOTA & 4095)] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = ((0.995999992f * fRec7[((IOTA - iSlow8) & 8191)]) - ((fSlow9 * fRec8[1]) + (0.990024984f * fRec8[2])));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp3 + (0.00499999989f * (fRec8[0] - fRec8[2])));
			fRec7[(IOTA & 8191)] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTemp4 = (3.0f * fRec2[0]);
			float fTempFTZ8 = ((0.995999992f * fRec9[((IOTA - iSlow10) & 2047)]) - ((fSlow11 * fRec10[1]) + (0.990024984f * fRec10[2])));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp4 + (0.00499999989f * (fRec10[0] - fRec10[2])));
			fRec9[(IOTA & 2047)] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = ((0.995999992f * fRec11[((IOTA - iSlow12) & 1023)]) - ((fSlow13 * fRec12[1]) + (0.990024984f * fRec12[2])));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp4 + (0.00499999989f * (fRec12[0] - fRec12[2])));
			fRec11[(IOTA & 1023)] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = ((0.995999992f * fRec13[((IOTA - iSlow14) & 511)]) - ((fSlow15 * fRec14[1]) + (0.990024984f * fRec14[2])));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp4 + (0.00499999989f * (fRec14[0] - fRec14[2])));
			fRec13[(IOTA & 511)] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTemp5 = (4.5f * fRec2[0]);
			float fTempFTZ14 = ((0.995999992f * fRec15[((IOTA - iSlow16) & 511)]) - ((fSlow17 * fRec16[1]) + (0.990024984f * fRec16[2])));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fTemp5 + (0.00499999989f * (fRec16[0] - fRec16[2])));
			fRec15[(IOTA & 511)] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = ((0.995999992f * fRec17[((IOTA - iSlow18) & 511)]) - ((fSlow19 * fRec18[1]) + (0.990024984f * fRec18[2])));
			fRec18[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fTemp5 + (0.00499999989f * (fRec18[0] - fRec18[2])));
			fRec17[(IOTA & 511)] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = ((0.995999992f * fRec19[((IOTA - iSlow20) & 127)]) - ((fSlow21 * fRec20[1]) + (0.990024984f * fRec20[2])));
			fRec20[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = ((6.0f * fRec2[0]) + (0.00499999989f * (fRec20[0] - fRec20[2])));
			fRec19[(IOTA & 127)] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = ((0.995999992f * fRec21[((IOTA - iSlow22) & 127)]) - ((fSlow23 * fRec22[1]) + (0.990024984f * fRec22[2])));
			fRec22[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fTemp5 + (0.00499999989f * (fRec22[0] - fRec22[2])));
			fRec21[(IOTA & 127)] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = ((0.995999992f * fRec23[((IOTA - iSlow24) & 1023)]) - ((fSlow25 * fRec24[1]) + (0.990024984f * fRec24[2])));
			fRec24[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fTemp3 + (0.00499999989f * (fRec24[0] - fRec24[2])));
			fRec23[(IOTA & 1023)] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = ((0.995999992f * fRec25[((IOTA - iSlow26) & 511)]) - ((fSlow27 * fRec26[1]) + (0.990024984f * fRec26[2])));
			fRec26[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = (fTemp3 + (0.00499999989f * (fRec26[0] - fRec26[2])));
			fRec25[(IOTA & 511)] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = ((0.995999992f * fRec27[((IOTA - iSlow28) & 255)]) - ((fSlow29 * fRec28[1]) + (0.990024984f * fRec28[2])));
			fRec28[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = (fTemp3 + (0.00499999989f * (fRec28[0] - fRec28[2])));
			fRec27[(IOTA & 255)] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTemp6 = ((((((((((((fRec1[((IOTA - 0) & 2047)] + fRec5[((IOTA - 0) & 4095)]) + fRec7[((IOTA - 0) & 8191)]) + fRec9[((IOTA - 0) & 2047)]) + fRec11[((IOTA - 0) & 1023)]) + fRec13[((IOTA - 0) & 511)]) + fRec15[((IOTA - 0) & 511)]) + fRec17[((IOTA - 0) & 511)]) + fRec19[((IOTA - 0) & 127)]) + fRec21[((IOTA - 0) & 127)]) + fRec23[((IOTA - 0) & 1023)]) + fRec25[((IOTA - 0) & 511)]) + fRec27[((IOTA - 0) & 255)]);
			fVec3[0] = fTemp6;
			float fTempFTZ28 = ((fTemp6 + (0.995000005f * fRec0[1])) - fVec3[1]);
			fRec0[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * fRec0[0])))));
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fVec2[1] = fVec2[0];
			fRec2[1] = fRec2[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			IOTA = (IOTA + 1);
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fVec3[1] = fVec3[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
