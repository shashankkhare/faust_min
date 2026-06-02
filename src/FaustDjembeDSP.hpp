/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "djembe"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustDjembeDSP_H__
#define  __FaustDjembeDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustDjembeDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustDjembeDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustDjembeDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fConst2;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	int iRec4[2];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	float fRec3[3];
	float fRec2[3];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iVec1[2];
	int iRec6[2];
	float fConst4;
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider4;
	float fConst8;
	float fRec1[3];
	float fConst10;
	float fConst11;
	float fRec8[3];
	float fConst13;
	float fConst14;
	float fRec9[3];
	float fConst16;
	float fConst17;
	float fRec10[3];
	float fConst19;
	float fConst20;
	float fRec11[3];
	float fConst22;
	float fConst23;
	float fRec12[3];
	float fConst25;
	float fConst26;
	float fRec13[3];
	float fConst28;
	float fConst29;
	float fRec14[3];
	float fConst31;
	float fConst32;
	float fRec15[3];
	float fConst34;
	float fConst35;
	float fRec16[3];
	float fConst37;
	float fConst38;
	float fRec17[3];
	float fConst40;
	float fConst41;
	float fRec18[3];
	float fConst43;
	float fConst44;
	float fRec19[3];
	float fConst46;
	float fConst47;
	float fRec20[3];
	float fConst49;
	float fConst50;
	float fRec21[3];
	float fConst52;
	float fConst53;
	float fRec22[3];
	float fConst55;
	float fConst56;
	float fRec23[3];
	float fConst58;
	float fConst59;
	float fRec24[3];
	float fConst61;
	float fConst62;
	float fRec25[3];
	float fConst64;
	float fConst65;
	float fRec26[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "djembe.dsp");
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
		m->declare("name", "djembe");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
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
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (3.14159274f / fConst0);
		fConst4 = (0.00200000009f * fConst0);
		float fConst5 = std::pow(0.00100000005f, (1.66666663f / fConst0));
		fConst6 = (0.0f - (2.0f * fConst5));
		fConst7 = (6.28318548f / fConst0);
		fConst8 = FaustDjembeDSP_faustpower2_f(fConst5);
		float fConst9 = std::pow(0.00100000005f, (1.75438595f / fConst0));
		fConst10 = (0.0f - (2.0f * fConst9));
		fConst11 = FaustDjembeDSP_faustpower2_f(fConst9);
		float fConst12 = std::pow(0.00100000005f, (1.85185182f / fConst0));
		fConst13 = (0.0f - (2.0f * fConst12));
		fConst14 = FaustDjembeDSP_faustpower2_f(fConst12);
		float fConst15 = std::pow(0.00100000005f, (1.96078432f / fConst0));
		fConst16 = (0.0f - (2.0f * fConst15));
		fConst17 = FaustDjembeDSP_faustpower2_f(fConst15);
		float fConst18 = std::pow(0.00100000005f, (2.08333325f / fConst0));
		fConst19 = (0.0f - (2.0f * fConst18));
		fConst20 = FaustDjembeDSP_faustpower2_f(fConst18);
		float fConst21 = std::pow(0.00100000005f, (2.22222233f / fConst0));
		fConst22 = (0.0f - (2.0f * fConst21));
		fConst23 = FaustDjembeDSP_faustpower2_f(fConst21);
		float fConst24 = std::pow(0.00100000005f, (2.38095236f / fConst0));
		fConst25 = (0.0f - (2.0f * fConst24));
		fConst26 = FaustDjembeDSP_faustpower2_f(fConst24);
		float fConst27 = std::pow(0.00100000005f, (2.56410265f / fConst0));
		fConst28 = (0.0f - (2.0f * fConst27));
		fConst29 = FaustDjembeDSP_faustpower2_f(fConst27);
		float fConst30 = std::pow(0.00100000005f, (2.77777767f / fConst0));
		fConst31 = (0.0f - (2.0f * fConst30));
		fConst32 = FaustDjembeDSP_faustpower2_f(fConst30);
		float fConst33 = std::pow(0.00100000005f, (3.030303f / fConst0));
		fConst34 = (0.0f - (2.0f * fConst33));
		fConst35 = FaustDjembeDSP_faustpower2_f(fConst33);
		float fConst36 = std::pow(0.00100000005f, (3.33333325f / fConst0));
		fConst37 = (0.0f - (2.0f * fConst36));
		fConst38 = FaustDjembeDSP_faustpower2_f(fConst36);
		float fConst39 = std::pow(0.00100000005f, (3.70370364f / fConst0));
		fConst40 = (0.0f - (2.0f * fConst39));
		fConst41 = FaustDjembeDSP_faustpower2_f(fConst39);
		float fConst42 = std::pow(0.00100000005f, (4.16666651f / fConst0));
		fConst43 = (0.0f - (2.0f * fConst42));
		fConst44 = FaustDjembeDSP_faustpower2_f(fConst42);
		float fConst45 = std::pow(0.00100000005f, (4.76190472f / fConst0));
		fConst46 = (0.0f - (2.0f * fConst45));
		fConst47 = FaustDjembeDSP_faustpower2_f(fConst45);
		float fConst48 = std::pow(0.00100000005f, (5.55555534f / fConst0));
		fConst49 = (0.0f - (2.0f * fConst48));
		fConst50 = FaustDjembeDSP_faustpower2_f(fConst48);
		float fConst51 = std::pow(0.00100000005f, (6.66666651f / fConst0));
		fConst52 = (0.0f - (2.0f * fConst51));
		fConst53 = FaustDjembeDSP_faustpower2_f(fConst51);
		float fConst54 = std::pow(0.00100000005f, (8.33333302f / fConst0));
		fConst55 = (0.0f - (2.0f * fConst54));
		fConst56 = FaustDjembeDSP_faustpower2_f(fConst54);
		float fConst57 = std::pow(0.00100000005f, (11.1111107f / fConst0));
		fConst58 = (0.0f - (2.0f * fConst57));
		fConst59 = FaustDjembeDSP_faustpower2_f(fConst57);
		float fConst60 = std::pow(0.00100000005f, (16.666666f / fConst0));
		fConst61 = (0.0f - (2.0f * fConst60));
		fConst62 = FaustDjembeDSP_faustpower2_f(fConst60);
		float fConst63 = std::pow(0.00100000005f, (33.3333321f / fConst0));
		fConst64 = (0.0f - (2.0f * fConst63));
		fConst65 = FaustDjembeDSP_faustpower2_f(fConst63);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.80000000000000004f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(110.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec4[l1] = 0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec5[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec0[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iVec1[l6] = 0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec6[l7] = 0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec1[l9] = 0.0f;
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
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec19[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec20[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec21[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec22[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec23[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec24[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec25[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec26[l28] = 0.0f;
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
	
	virtual FaustDjembeDSP* clone() {
		return new FaustDjembeDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("djembe");
		ui_interface->addHorizontalSlider("freq", &fHslider4, FAUSTFLOAT(110.0f), FAUSTFLOAT(30.0f), FAUSTFLOAT(500.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("position", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = (fConst1 * float(fHslider2));
		float fSlow3 = float(fButton0);
		int iSlow4 = (fSlow3 > 0.0f);
		float fSlow5 = (fConst1 * float(fHslider3));
		float fSlow6 = float(fHslider4);
		float fSlow7 = (fConst6 * std::cos((fConst7 * fSlow6)));
		float fSlow8 = (fConst10 * std::cos((fConst7 * (fSlow6 + 200.0f))));
		float fSlow9 = (fConst13 * std::cos((fConst7 * (fSlow6 + 400.0f))));
		float fSlow10 = (fConst16 * std::cos((fConst7 * (fSlow6 + 600.0f))));
		float fSlow11 = (fConst19 * std::cos((fConst7 * (fSlow6 + 800.0f))));
		float fSlow12 = (fConst22 * std::cos((fConst7 * (fSlow6 + 1000.0f))));
		float fSlow13 = (fConst25 * std::cos((fConst7 * (fSlow6 + 1200.0f))));
		float fSlow14 = (fConst28 * std::cos((fConst7 * (fSlow6 + 1400.0f))));
		float fSlow15 = (fConst31 * std::cos((fConst7 * (fSlow6 + 1600.0f))));
		float fSlow16 = (fConst34 * std::cos((fConst7 * (fSlow6 + 1800.0f))));
		float fSlow17 = (fConst37 * std::cos((fConst7 * (fSlow6 + 2000.0f))));
		float fSlow18 = (fConst40 * std::cos((fConst7 * (fSlow6 + 2200.0f))));
		float fSlow19 = (fConst43 * std::cos((fConst7 * (fSlow6 + 2400.0f))));
		float fSlow20 = (fConst46 * std::cos((fConst7 * (fSlow6 + 2600.0f))));
		float fSlow21 = (fConst49 * std::cos((fConst7 * (fSlow6 + 2800.0f))));
		float fSlow22 = (fConst52 * std::cos((fConst7 * (fSlow6 + 3000.0f))));
		float fSlow23 = (fConst55 * std::cos((fConst7 * (fSlow6 + 3200.0f))));
		float fSlow24 = (fConst58 * std::cos((fConst7 * (fSlow6 + 3400.0f))));
		float fSlow25 = (fConst61 * std::cos((fConst7 * (fSlow6 + 3600.0f))));
		float fSlow26 = (fConst64 * std::cos((fConst7 * (fSlow6 + 3800.0f))));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTempFTZ0 = (fSlow0 + (fConst2 * fRec0[1]));
			fRec0[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float fTempFTZ1 = (fSlow2 + (fConst2 * fRec5[1]));
			fRec5[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = std::tan((fConst3 * ((500.0f * fRec5[0]) + 40.0f)));
			float fTemp1 = (1.0f / fTemp0);
			float fTemp2 = FaustDjembeDSP_faustpower2_f(fTemp0);
			float fTemp3 = (((fTemp1 + 1.41421354f) / fTemp0) + 1.0f);
			float fTempFTZ2 = ((4.65661287e-10f * float(iRec4[0])) - (((fRec3[2] * (((fTemp1 + -1.41421354f) / fTemp0) + 1.0f)) + (2.0f * (fRec3[1] * (1.0f - (1.0f / fTemp2))))) / fTemp3));
			fRec3[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTemp4 = std::tan((fConst3 * ((15000.0f * fRec5[0]) + 500.0f)));
			float fTemp5 = (1.0f / fTemp4);
			float fTemp6 = (((fTemp5 + 1.41421354f) / fTemp4) + 1.0f);
			float fTempFTZ3 = (((((fRec3[1] * (0.0f - (2.0f / fTemp2))) + (fRec3[0] / fTemp2)) + (fRec3[2] / fTemp2)) / fTemp3) - (((fRec2[2] * (((fTemp5 + -1.41421354f) / fTemp4) + 1.0f)) + (2.0f * (fRec2[1] * (1.0f - (1.0f / FaustDjembeDSP_faustpower2_f(fTemp4)))))) / fTemp6));
			fRec2[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			fVec0[0] = fSlow3;
			int iTemp7 = (iSlow4 & (fVec0[1] <= 0.0f));
			iVec1[0] = iTemp7;
			iRec6[0] = (((iRec6[1] + (iRec6[1] > 0)) * (iTemp7 <= iVec1[1])) + (iTemp7 > iVec1[1]));
			float fTempFTZ4 = (fSlow5 + (fConst2 * fRec7[1]));
			fRec7[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp8 = (float(iRec6[0]) / std::max<float>(1.0f, (fConst4 * fRec7[0])));
			float fTemp9 = (fSlow1 * (((fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))) * std::max<float>(0.0f, std::min<float>(fTemp8, (2.0f - fTemp8)))) / fTemp6));
			float fTempFTZ5 = (fTemp9 - ((fSlow7 * fRec1[1]) + (fConst8 * fRec1[2])));
			fRec1[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (fTemp9 - ((fSlow8 * fRec8[1]) + (fConst11 * fRec8[2])));
			fRec8[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fTemp9 - ((fSlow9 * fRec9[1]) + (fConst14 * fRec9[2])));
			fRec9[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp9 - ((fSlow10 * fRec10[1]) + (fConst17 * fRec10[2])));
			fRec10[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = (fTemp9 - ((fSlow11 * fRec11[1]) + (fConst20 * fRec11[2])));
			fRec11[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fTempFTZ10 = (fTemp9 - ((fSlow12 * fRec12[1]) + (fConst23 * fRec12[2])));
			fRec12[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (fTemp9 - ((fSlow13 * fRec13[1]) + (fConst26 * fRec13[2])));
			fRec13[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = (fTemp9 - ((fSlow14 * fRec14[1]) + (fConst29 * fRec14[2])));
			fRec14[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp9 - ((fSlow15 * fRec15[1]) + (fConst32 * fRec15[2])));
			fRec15[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = (fTemp9 - ((fSlow16 * fRec16[1]) + (fConst35 * fRec16[2])));
			fRec16[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = (fTemp9 - ((fSlow17 * fRec17[1]) + (fConst38 * fRec17[2])));
			fRec17[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (fTemp9 - ((fSlow18 * fRec18[1]) + (fConst41 * fRec18[2])));
			fRec18[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = (fTemp9 - ((fSlow19 * fRec19[1]) + (fConst44 * fRec19[2])));
			fRec19[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = (fTemp9 - ((fSlow20 * fRec20[1]) + (fConst47 * fRec20[2])));
			fRec20[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = (fTemp9 - ((fSlow21 * fRec21[1]) + (fConst50 * fRec21[2])));
			fRec21[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fTempFTZ20 = (fTemp9 - ((fSlow22 * fRec22[1]) + (fConst53 * fRec22[2])));
			fRec22[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = (fTemp9 - ((fSlow23 * fRec23[1]) + (fConst56 * fRec23[2])));
			fRec23[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = (fTemp9 - ((fSlow24 * fRec24[1]) + (fConst59 * fRec24[2])));
			fRec24[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = (fTemp9 - ((fSlow25 * fRec25[1]) + (fConst62 * fRec25[2])));
			fRec25[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = (fTemp9 - ((fSlow26 * fRec26[1]) + (fConst65 * fRec26[2])));
			fRec26[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			output0[i0] = FAUSTFLOAT((0.0500000007f * (fRec0[0] * ((((((((((((((((((((fRec1[0] + (0.25f * (fRec8[0] - fRec8[2]))) + (0.111111112f * (fRec9[0] - fRec9[2]))) + (0.0625f * (fRec10[0] - fRec10[2]))) + (0.0399999991f * (fRec11[0] - fRec11[2]))) + (0.027777778f * (fRec12[0] - fRec12[2]))) + (0.0204081628f * (fRec13[0] - fRec13[2]))) + (0.015625f * (fRec14[0] - fRec14[2]))) + (0.0123456791f * (fRec15[0] - fRec15[2]))) + (0.00999999978f * (fRec16[0] - fRec16[2]))) + (0.00826446246f * (fRec17[0] - fRec17[2]))) + (0.0069444445f * (fRec18[0] - fRec18[2]))) + (0.00591715984f * (fRec19[0] - fRec19[2]))) + (0.00510204071f * (fRec20[0] - fRec20[2]))) + (0.00444444455f * (fRec21[0] - fRec21[2]))) + (0.00390625f * (fRec22[0] - fRec22[2]))) + (0.00346020772f * (fRec23[0] - fRec23[2]))) + (0.00308641978f * (fRec24[0] - fRec24[2]))) + (0.00277008303f * (fRec25[0] - fRec25[2]))) + (0.00249999994f * (fRec26[0] - fRec26[2]))) - fRec1[2]))));
			fRec0[1] = fRec0[0];
			iRec4[1] = iRec4[0];
			fRec5[1] = fRec5[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fVec0[1] = fVec0[0];
			iVec1[1] = iVec1[0];
			iRec6[1] = iRec6[0];
			fRec7[1] = fRec7[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
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
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
		}
	}

};

#endif
