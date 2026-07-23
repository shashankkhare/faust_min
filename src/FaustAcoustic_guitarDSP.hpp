/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "acoustic_guitar"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustAcoustic_guitarDSP_H__
#define  __FaustAcoustic_guitarDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

static float FaustAcoustic_guitarDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustAcoustic_guitarDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustAcoustic_guitarDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst4;
	int iRec13[2];
	float fConst5;
	float fConst6;
	float fConst7;
	FAUSTFLOAT fHslider3;
	float fConst8;
	float fRec28[2];
	float fRec25[2];
	float fRec29[2];
	float fRec31[4];
	int IOTA;
	float fRec32[2048];
	float fVec0[2];
	FAUSTFLOAT fHslider4;
	float fConst9;
	int iRec34[2];
	float fRec33[3];
	float fConst10;
	float fConst13;
	float fConst16;
	float fConst18;
	float fConst19;
	float fConst20;
	float fRec37[3];
	float fConst21;
	float fConst22;
	float fConst23;
	float fRec36[3];
	float fConst24;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec38[2];
	float fVec2[2];
	int iRec35[2];
	float fVec3[2];
	float fRec30[2048];
	float fRec22[2];
	float fRec19[2048];
	float fRec21[2];
	float fRec18[4];
	int iRec9[2];
	float fRec5[2048];
	float fRec3[2];
	float fRec4[2];
	float fConst25;
	float fConst26;
	float fRec2[3];
	float fConst28;
	float fConst29;
	int iRec50[2];
	float fRec62[2];
	float fRec65[2];
	float fRec67[4];
	float fRec68[2048];
	float fVec4[2];
	float fVec5[2];
	float fRec66[2048];
	float fRec59[2];
	float fRec56[2048];
	float fRec58[2];
	float fRec55[4];
	int iRec46[2];
	float fRec42[2048];
	float fRec40[2];
	float fRec41[2];
	float fRec39[2];
	float fConst31;
	float fConst33;
	float fConst34;
	float fRec69[2];
	float fConst35;
	float fRec70[2];
	float fRec1[3];
	float fConst36;
	float fRec71[3];
	float fConst37;
	float fRec72[3];
	float fConst38;
	float fRec73[3];
	float fVec6[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.1");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 1");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "acoustic_guitar.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:author", "Julius O. Smith III");
		m->declare("filters.lib/highshelf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highshelf:license", "MIT-style STK-4.3 license");
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
		m->declare("name", "acoustic_guitar");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.1");
		m->declare("physmodels.lib/name", "Faust Physical Models Library");
		m->declare("physmodels.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
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
		fConst1 = (12.566371f / fConst0);
		float fConst2 = std::tan((2356.19458f / fConst0));
		float fConst3 = (1.0f / fConst2);
		fConst4 = (1.0f / (((fConst3 + 1.41421354f) / fConst2) + 1.0f));
		fConst5 = (0.00882352982f * fConst0);
		fConst6 = (0.00147058826f * fConst0);
		fConst7 = (44.0999985f / fConst0);
		fConst8 = (1.0f - fConst7);
		fConst9 = (15.707963f / fConst0);
		fConst10 = (0.00200000009f * fConst0);
		float fConst11 = std::tan((12566.3711f / fConst0));
		float fConst12 = (1.0f / fConst11);
		fConst13 = (1.0f / (((fConst12 + 1.41421354f) / fConst11) + 1.0f));
		float fConst14 = std::tan((314.159271f / fConst0));
		float fConst15 = (1.0f / fConst14);
		fConst16 = (1.0f / (((fConst15 + 1.41421354f) / fConst14) + 1.0f));
		float fConst17 = FaustAcoustic_guitarDSP_faustpower2_f(fConst14);
		fConst18 = (1.0f / fConst17);
		fConst19 = (((fConst15 + -1.41421354f) / fConst14) + 1.0f);
		fConst20 = (2.0f * (1.0f - fConst18));
		fConst21 = (0.0f - (2.0f / fConst17));
		fConst22 = (((fConst12 + -1.41421354f) / fConst11) + 1.0f);
		fConst23 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fConst11))));
		fConst24 = (1.0f / std::max<float>(1.0f, (0.000600000028f * fConst0)));
		fConst25 = (((fConst3 + -1.41421354f) / fConst2) + 1.0f);
		fConst26 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fConst2))));
		float fConst27 = (1.0f / std::tan((6911.50391f / fConst0)));
		fConst28 = (1.0f / (fConst27 + 1.0f));
		fConst29 = (1.0f - fConst27);
		float fConst30 = std::tan((9424.77832f / fConst0));
		fConst31 = (1.0f / fConst30);
		float fConst32 = (fConst31 + 1.0f);
		fConst33 = (1.0f / fConst32);
		fConst34 = (1.0f - fConst31);
		fConst35 = (0.0f - (1.0f / (fConst30 * fConst32)));
		fConst36 = (9.42477798f / fConst0);
		fConst37 = (6.28318548f / fConst0);
		fConst38 = (3.14159274f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(196.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.80000000000000004f);
		fHslider4 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec13[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec28[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec25[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec29[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 4); l4 = (l4 + 1)) {
			fRec31[l4] = 0.0f;
		}
		IOTA = 0;
		for (int l5 = 0; (l5 < 2048); l5 = (l5 + 1)) {
			fRec32[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			iRec34[l7] = 0;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec33[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec37[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec36[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec1[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec38[l12] = 0;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fVec2[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			iRec35[l14] = 0;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec3[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2048); l16 = (l16 + 1)) {
			fRec30[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec22[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2048); l18 = (l18 + 1)) {
			fRec19[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec21[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 4); l20 = (l20 + 1)) {
			fRec18[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			iRec9[l21] = 0;
		}
		for (int l22 = 0; (l22 < 2048); l22 = (l22 + 1)) {
			fRec5[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec3[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec4[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec2[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			iRec50[l26] = 0;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec62[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec65[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 4); l29 = (l29 + 1)) {
			fRec67[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2048); l30 = (l30 + 1)) {
			fRec68[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fVec4[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fVec5[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2048); l33 = (l33 + 1)) {
			fRec66[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec59[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2048); l35 = (l35 + 1)) {
			fRec56[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec58[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 4); l37 = (l37 + 1)) {
			fRec55[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			iRec46[l38] = 0;
		}
		for (int l39 = 0; (l39 < 2048); l39 = (l39 + 1)) {
			fRec42[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec40[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec41[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec39[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec69[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec70[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec1[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec71[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec72[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec73[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fVec6[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec0[l50] = 0.0f;
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
	
	virtual FaustAcoustic_guitarDSP* clone() {
		return new FaustAcoustic_guitarDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("acoustic_guitar");
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(196.0f), FAUSTFLOAT(82.0f), FAUSTFLOAT(1046.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("pluckPosition", &fHslider3, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.99000001f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("stringType", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("velocity", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (60.2000008f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::tan((fConst1 * fSlow1));
		float fSlow3 = (1.0f / fSlow2);
		float fSlow4 = (((fSlow3 + 0.125f) / fSlow2) + 1.0f);
		float fSlow5 = (0.600000024f / (fSlow2 * fSlow4));
		float fSlow6 = (0.0f - fSlow5);
		int iSlow7 = int(float(fHslider2));
		int iSlow8 = (iSlow7 == 0);
		int iSlow9 = (iSlow7 == 1);
		float fSlow10 = (340.0f / fSlow1);
		float fSlow11 = (fConst6 * (fSlow10 + -0.100000001f));
		float fSlow12 = (fConst7 * float(fHslider3));
		float fSlow13 = std::tan((fConst9 * fSlow1));
		float fSlow14 = (1.0f / fSlow13);
		float fSlow15 = (((fSlow14 + 1.41421354f) / fSlow13) + 1.0f);
		float fSlow16 = (0.100000001f * (float(fHslider4) / fSlow15));
		float fSlow17 = (1.0f / fSlow15);
		float fSlow18 = (((fSlow14 + -1.41421354f) / fSlow13) + 1.0f);
		float fSlow19 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fSlow13))));
		float fSlow20 = (1.0f / std::max<float>(1.0f, (fConst10 * FaustAcoustic_guitarDSP_faustpower2_f((1.0f - (0.00033333333f * fSlow1))))));
		float fSlow21 = float(fButton0);
		float fSlow22 = (fConst6 * (fSlow10 + -0.109999999f));
		float fSlow23 = (1.0f / fSlow4);
		float fSlow24 = (((fSlow3 + -0.125f) / fSlow2) + 1.0f);
		float fSlow25 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fSlow2))));
		float fSlow26 = std::tan((fConst36 * fSlow1));
		float fSlow27 = (1.0f / fSlow26);
		float fSlow28 = (((fSlow27 + 0.100000001f) / fSlow26) + 1.0f);
		float fSlow29 = (0.800000012f / (fSlow26 * fSlow28));
		float fSlow30 = (0.0f - fSlow29);
		float fSlow31 = (1.0f / fSlow28);
		float fSlow32 = (((fSlow27 + -0.100000001f) / fSlow26) + 1.0f);
		float fSlow33 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fSlow26))));
		float fSlow34 = std::tan((fConst37 * fSlow1));
		float fSlow35 = (1.0f / fSlow34);
		float fSlow36 = (((fSlow35 + 0.0833333358f) / fSlow34) + 1.0f);
		float fSlow37 = (1.0f / (fSlow34 * fSlow36));
		float fSlow38 = (1.0f / fSlow36);
		float fSlow39 = (((fSlow35 + -0.0833333358f) / fSlow34) + 1.0f);
		float fSlow40 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fSlow34))));
		float fSlow41 = (0.0f - fSlow37);
		float fSlow42 = std::tan((fConst38 * fSlow1));
		float fSlow43 = (1.0f / fSlow42);
		int iSlow44 = (iSlow7 > 0);
		int iSlow45 = (iSlow7 > 1);
		float fElse3 = (iSlow45 ? 20.0f : 10.0f);
		float fSlow46 = (1.0f / (iSlow44 ? fElse3 : 15.0f));
		float fSlow47 = ((fSlow43 * (fSlow43 - fSlow46)) + 1.0f);
		float fSlow48 = (2.0f * (1.0f - (1.0f / FaustAcoustic_guitarDSP_faustpower2_f(fSlow42))));
		float fSlow49 = ((fSlow43 * (fSlow43 + fSlow46)) + 1.0f);
		float fElse5 = (iSlow45 ? 2.0f : 1.5f);
		float fSlow50 = (iSlow44 ? fElse5 : 1.20000005f);
		float fSlow51 = (0.0f - (fSlow43 * (fSlow50 / fSlow49)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec13[0] = 0;
			int iRec14 = iRec13[1];
			float fTempFTZ0 = (float(iRec9[1]) - (0.997843683f * ((0.699999988f * fRec18[2]) + (0.150000006f * (fRec18[1] + fRec18[3])))));
			float fRec17 = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTempFTZ1 = (fSlow12 + (fConst8 * fRec28[1]));
			fRec28[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTemp0 = (1.0f - fRec28[0]);
			float fTemp1 = (fSlow11 * fTemp0);
			float fTemp2 = (fTemp1 + -1.49999499f);
			int iTemp3 = int(fTemp2);
			int iTemp4 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp3))));
			float fTemp5 = std::floor(fTemp2);
			float fTemp6 = (fTemp1 + (-1.0f - fTemp5));
			float fTemp7 = (0.0f - fTemp6);
			float fTemp8 = (fTemp1 + (-2.0f - fTemp5));
			float fTemp9 = (0.0f - (0.5f * fTemp8));
			float fTemp10 = (fTemp1 + (-3.0f - fTemp5));
			float fTemp11 = (0.0f - (0.333333343f * fTemp10));
			float fTemp12 = (fTemp1 + (-4.0f - fTemp5));
			float fTemp13 = (0.0f - (0.25f * fTemp12));
			float fTemp14 = (fTemp1 - fTemp5);
			int iTemp15 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp3 + 1)))));
			float fTemp16 = (0.0f - fTemp8);
			float fTemp17 = (0.0f - (0.5f * fTemp10));
			float fTemp18 = (0.0f - (0.333333343f * fTemp12));
			int iTemp19 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp3 + 2)))));
			float fTemp20 = (0.0f - fTemp10);
			float fTemp21 = (0.0f - (0.5f * fTemp12));
			float fTemp22 = (fTemp6 * fTemp8);
			int iTemp23 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp3 + 3)))));
			float fTemp24 = (0.0f - fTemp12);
			float fTemp25 = (fTemp22 * fTemp10);
			int iTemp26 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp3 + 4)))));
			float fTempFTZ2 = (((((fRec5[((IOTA - (iTemp4 + 1)) & 2047)] * fTemp7) * fTemp9) * fTemp11) * fTemp13) + (fTemp14 * ((((((fRec5[((IOTA - (iTemp15 + 1)) & 2047)] * fTemp16) * fTemp17) * fTemp18) + (0.5f * (((fTemp6 * fRec5[((IOTA - (iTemp19 + 1)) & 2047)]) * fTemp20) * fTemp21))) + (0.166666672f * ((fTemp22 * fRec5[((IOTA - (iTemp23 + 1)) & 2047)]) * fTemp24))) + (0.0416666679f * (fTemp25 * fRec5[((IOTA - (iTemp26 + 1)) & 2047)])))));
			fRec25[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			float fTempFTZ3 = ((0.0500000007f * fRec29[1]) + (0.949999988f * fRec25[1]));
			fRec29[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = fRec29[0];
			float fRec26 = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTempFTZ5 = fRec3[1];
			fRec31[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			float fTempFTZ6 = (-1.0f * (0.997843683f * ((0.699999988f * fRec31[2]) + (0.150000006f * (fRec31[1] + fRec31[3])))));
			fRec32[(IOTA & 2047)] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTemp27 = (fSlow11 * fRec28[0]);
			float fTemp28 = (fTemp27 + -1.49999499f);
			int iTemp29 = int(fTemp28);
			int iTemp30 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp29))));
			float fTemp31 = std::floor(fTemp28);
			float fTemp32 = (fTemp27 + (-1.0f - fTemp31));
			float fTemp33 = (0.0f - fTemp32);
			float fTemp34 = (fTemp27 + (-2.0f - fTemp31));
			float fTemp35 = (0.0f - (0.5f * fTemp34));
			float fTemp36 = (fTemp27 + (-3.0f - fTemp31));
			float fTemp37 = (0.0f - (0.333333343f * fTemp36));
			float fTemp38 = (fTemp27 + (-4.0f - fTemp31));
			float fTemp39 = (0.0f - (0.25f * fTemp38));
			float fTemp40 = (fTemp27 - fTemp31);
			int iTemp41 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp29 + 1)))));
			float fTemp42 = (0.0f - fTemp34);
			float fTemp43 = (0.0f - (0.5f * fTemp36));
			float fTemp44 = (0.0f - (0.333333343f * fTemp38));
			int iTemp45 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp29 + 2)))));
			float fTemp46 = (0.0f - fTemp36);
			float fTemp47 = (0.0f - (0.5f * fTemp38));
			float fTemp48 = (fTemp32 * fTemp34);
			int iTemp49 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp29 + 3)))));
			float fTemp50 = (0.0f - fTemp38);
			float fTemp51 = (fTemp48 * fTemp36);
			int iTemp52 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp29 + 4)))));
			fVec0[0] = (((((fRec32[((IOTA - (iTemp30 + 2)) & 2047)] * fTemp33) * fTemp35) * fTemp37) * fTemp39) + (fTemp40 * ((((((fRec32[((IOTA - (iTemp41 + 2)) & 2047)] * fTemp42) * fTemp43) * fTemp44) + (0.5f * (((fTemp32 * fRec32[((IOTA - (iTemp45 + 2)) & 2047)]) * fTemp46) * fTemp47))) + (0.166666672f * ((fTemp48 * fRec32[((IOTA - (iTemp49 + 2)) & 2047)]) * fTemp50))) + (0.0416666679f * (fTemp51 * fRec32[((IOTA - (iTemp52 + 2)) & 2047)])))));
			iRec34[0] = ((1103515245 * iRec34[1]) + 12345);
			float fTemp53 = (4.65661287e-10f * float(iRec34[0]));
			float fTempFTZ7 = (fTemp53 - (fSlow17 * ((fSlow18 * fRec33[2]) + (fSlow19 * fRec33[1]))));
			fRec33[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			float fTempFTZ8 = (fTemp53 - (fConst16 * ((fConst19 * fRec37[2]) + (fConst20 * fRec37[1]))));
			fRec37[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fTempFTZ9 = ((fConst16 * (((fConst18 * fRec37[0]) + (fConst21 * fRec37[1])) + (fConst18 * fRec37[2]))) - (fConst13 * ((fConst22 * fRec36[2]) + (fConst23 * fRec36[1]))));
			fRec36[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			fVec1[0] = fSlow21;
			iRec38[0] = ((fSlow21 > fVec1[1]) + ((fSlow21 <= fVec1[1]) * (iRec38[1] + (iRec38[1] > 0))));
			float fTemp54 = (fConst24 * float(iRec38[0]));
			float fTemp55 = ((fRec36[2] + (fRec36[0] + (2.0f * fRec36[1]))) * std::max<float>(0.0f, std::min<float>(fTemp54, (2.0f - fTemp54))));
			fVec2[0] = fTemp55;
			float fTemp56 = (fConst13 * fTemp55);
			float fTemp57 = (fConst13 * fVec2[1]);
			iRec35[0] = (((iRec35[1] + (iRec35[1] > 0)) * (fTemp56 <= fTemp57)) + (fTemp56 > fTemp57));
			float fTemp58 = (fSlow20 * float(iRec35[0]));
			float fTemp59 = (fSlow16 * ((fRec33[2] + (fRec33[0] + (2.0f * fRec33[1]))) * std::max<float>(0.0f, std::min<float>(fTemp58, (2.0f - fTemp58)))));
			fVec3[0] = (fVec0[1] + fTemp59);
			float fTempFTZ10 = ((0.0500000007f * fRec30[((IOTA - 1) & 2047)]) + (0.949999988f * fVec3[1]));
			fRec30[(IOTA & 2047)] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fTempFTZ11 = (((((fTemp7 * fTemp9) * fTemp11) * fTemp13) * fRec30[((IOTA - iTemp4) & 2047)]) + (fTemp14 * ((((((fTemp16 * fTemp17) * fTemp18) * fRec30[((IOTA - iTemp15) & 2047)]) + (0.5f * (((fTemp6 * fTemp20) * fTemp21) * fRec30[((IOTA - iTemp19) & 2047)]))) + (0.166666672f * ((fTemp22 * fTemp24) * fRec30[((IOTA - iTemp23) & 2047)]))) + (0.0416666679f * (fTemp25 * fRec30[((IOTA - iTemp26) & 2047)])))));
			float fRec27 = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fTempFTZ12 = fRec26;
			fRec22[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fTempFTZ13 = (fTemp59 + fRec22[1]);
			float fRec23 = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fTempFTZ14 = fRec27;
			float fRec24 = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fTempFTZ15 = fRec23;
			fRec19[(IOTA & 2047)] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fTempFTZ16 = (((((fTemp33 * fTemp35) * fTemp37) * fTemp39) * fRec19[((IOTA - (iTemp30 + 1)) & 2047)]) + (fTemp40 * ((((((fTemp42 * fTemp43) * fTemp44) * fRec19[((IOTA - (iTemp41 + 1)) & 2047)]) + (0.5f * (((fTemp32 * fTemp46) * fTemp47) * fRec19[((IOTA - (iTemp45 + 1)) & 2047)]))) + (0.166666672f * ((fTemp48 * fTemp50) * fRec19[((IOTA - (iTemp49 + 1)) & 2047)]))) + (0.0416666679f * (fTemp51 * fRec19[((IOTA - (iTemp52 + 1)) & 2047)])))));
			float fRec20 = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fTempFTZ17 = fRec24;
			fRec21[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fTempFTZ18 = fRec21[1];
			fRec18[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fTempFTZ19 = fRec18[1];
			float fTemp60 = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fRec15 = fTemp60;
			float fRec16 = fTemp60;
			iRec9[0] = iRec14;
			float fTempFTZ20 = fRec17;
			float fRec10 = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fTempFTZ21 = fRec15;
			float fRec11 = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fTempFTZ22 = fRec16;
			float fRec12 = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fTempFTZ23 = fRec10;
			fRec5[(IOTA & 2047)] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fTempFTZ24 = fRec20;
			float fRec6 = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fTempFTZ25 = fRec11;
			float fRec7 = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fTempFTZ26 = fRec12;
			float fRec8 = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fTempFTZ27 = fRec6;
			fRec3[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fTempFTZ28 = fRec8;
			fRec4[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fTempFTZ29 = (fRec4[0] - (fConst4 * ((fConst25 * fRec2[2]) + (fConst26 * fRec2[1]))));
			fRec2[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			iRec50[0] = 0;
			int iRec51 = iRec50[1];
			float fTempFTZ30 = (float(iRec46[1]) - (0.997843683f * ((0.699999988f * fRec55[2]) + (0.150000006f * (fRec55[1] + fRec55[3])))));
			float fRec54 = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fTemp61 = (fSlow22 * fTemp0);
			float fTemp62 = (fTemp61 + -1.49999499f);
			int iTemp63 = int(fTemp62);
			int iTemp64 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp63))));
			float fTemp65 = std::floor(fTemp62);
			float fTemp66 = (fTemp61 + (-1.0f - fTemp65));
			float fTemp67 = (0.0f - fTemp66);
			float fTemp68 = (fTemp61 + (-2.0f - fTemp65));
			float fTemp69 = (0.0f - (0.5f * fTemp68));
			float fTemp70 = (fTemp61 + (-3.0f - fTemp65));
			float fTemp71 = (0.0f - (0.333333343f * fTemp70));
			float fTemp72 = (fTemp61 + (-4.0f - fTemp65));
			float fTemp73 = (0.0f - (0.25f * fTemp72));
			float fTemp74 = (fTemp61 - fTemp65);
			int iTemp75 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp63 + 1)))));
			float fTemp76 = (0.0f - fTemp68);
			float fTemp77 = (0.0f - (0.5f * fTemp70));
			float fTemp78 = (0.0f - (0.333333343f * fTemp72));
			int iTemp79 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp63 + 2)))));
			float fTemp80 = (0.0f - fTemp70);
			float fTemp81 = (0.0f - (0.5f * fTemp72));
			float fTemp82 = (fTemp66 * fTemp68);
			int iTemp83 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp63 + 3)))));
			float fTemp84 = (0.0f - fTemp72);
			float fTemp85 = (fTemp82 * fTemp70);
			int iTemp86 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp63 + 4)))));
			float fTempFTZ31 = (((((fRec42[((IOTA - (iTemp64 + 1)) & 2047)] * fTemp67) * fTemp69) * fTemp71) * fTemp73) + (fTemp74 * ((((((fRec42[((IOTA - (iTemp75 + 1)) & 2047)] * fTemp76) * fTemp77) * fTemp78) + (0.5f * (((fTemp66 * fRec42[((IOTA - (iTemp79 + 1)) & 2047)]) * fTemp80) * fTemp81))) + (0.166666672f * ((fTemp82 * fRec42[((IOTA - (iTemp83 + 1)) & 2047)]) * fTemp84))) + (0.0416666679f * (fTemp85 * fRec42[((IOTA - (iTemp86 + 1)) & 2047)])))));
			fRec62[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fTempFTZ32 = ((0.400000006f * fRec65[1]) + (0.600000024f * fRec62[1]));
			fRec65[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fTempFTZ33 = fRec65[0];
			float fRec63 = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fTempFTZ34 = fRec40[1];
			fRec67[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fTempFTZ35 = (-1.0f * (0.997843683f * ((0.699999988f * fRec67[2]) + (0.150000006f * (fRec67[1] + fRec67[3])))));
			fRec68[(IOTA & 2047)] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fTemp87 = (fSlow22 * fRec28[0]);
			float fTemp88 = (fTemp87 + -1.49999499f);
			int iTemp89 = int(fTemp88);
			int iTemp90 = int(std::min<float>(fConst5, float(std::max<int>(0, iTemp89))));
			float fTemp91 = std::floor(fTemp88);
			float fTemp92 = (fTemp87 + (-1.0f - fTemp91));
			float fTemp93 = (0.0f - fTemp92);
			float fTemp94 = (fTemp87 + (-2.0f - fTemp91));
			float fTemp95 = (0.0f - (0.5f * fTemp94));
			float fTemp96 = (fTemp87 + (-3.0f - fTemp91));
			float fTemp97 = (0.0f - (0.333333343f * fTemp96));
			float fTemp98 = (fTemp87 + (-4.0f - fTemp91));
			float fTemp99 = (0.0f - (0.25f * fTemp98));
			float fTemp100 = (fTemp87 - fTemp91);
			int iTemp101 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp89 + 1)))));
			float fTemp102 = (0.0f - fTemp94);
			float fTemp103 = (0.0f - (0.5f * fTemp96));
			float fTemp104 = (0.0f - (0.333333343f * fTemp98));
			int iTemp105 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp89 + 2)))));
			float fTemp106 = (0.0f - fTemp96);
			float fTemp107 = (0.0f - (0.5f * fTemp98));
			float fTemp108 = (fTemp92 * fTemp94);
			int iTemp109 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp89 + 3)))));
			float fTemp110 = (0.0f - fTemp98);
			float fTemp111 = (fTemp108 * fTemp96);
			int iTemp112 = int(std::min<float>(fConst5, float(std::max<int>(0, (iTemp89 + 4)))));
			fVec4[0] = (((((fRec68[((IOTA - (iTemp90 + 2)) & 2047)] * fTemp93) * fTemp95) * fTemp97) * fTemp99) + (fTemp100 * ((((((fRec68[((IOTA - (iTemp101 + 2)) & 2047)] * fTemp102) * fTemp103) * fTemp104) + (0.5f * (((fTemp92 * fRec68[((IOTA - (iTemp105 + 2)) & 2047)]) * fTemp106) * fTemp107))) + (0.166666672f * ((fTemp108 * fRec68[((IOTA - (iTemp109 + 2)) & 2047)]) * fTemp110))) + (0.0416666679f * (fTemp111 * fRec68[((IOTA - (iTemp112 + 2)) & 2047)])))));
			fVec5[0] = (fTemp59 + fVec4[1]);
			float fTempFTZ36 = ((0.400000006f * fRec66[((IOTA - 1) & 2047)]) + (0.600000024f * fVec5[1]));
			fRec66[(IOTA & 2047)] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fTempFTZ37 = (((((fTemp67 * fTemp69) * fTemp71) * fTemp73) * fRec66[((IOTA - iTemp64) & 2047)]) + (fTemp74 * ((((((fTemp76 * fTemp77) * fTemp78) * fRec66[((IOTA - iTemp75) & 2047)]) + (0.5f * (((fTemp66 * fTemp80) * fTemp81) * fRec66[((IOTA - iTemp79) & 2047)]))) + (0.166666672f * ((fTemp82 * fTemp84) * fRec66[((IOTA - iTemp83) & 2047)]))) + (0.0416666679f * (fTemp85 * fRec66[((IOTA - iTemp86) & 2047)])))));
			float fRec64 = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fTempFTZ38 = fRec63;
			fRec59[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fTempFTZ39 = (fTemp59 + fRec59[1]);
			float fRec60 = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fTempFTZ40 = fRec64;
			float fRec61 = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fTempFTZ41 = fRec60;
			fRec56[(IOTA & 2047)] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fTempFTZ42 = (((((fTemp93 * fTemp95) * fTemp97) * fTemp99) * fRec56[((IOTA - (iTemp90 + 1)) & 2047)]) + (fTemp100 * ((((((fTemp102 * fTemp103) * fTemp104) * fRec56[((IOTA - (iTemp101 + 1)) & 2047)]) + (0.5f * (((fTemp92 * fTemp106) * fTemp107) * fRec56[((IOTA - (iTemp105 + 1)) & 2047)]))) + (0.166666672f * ((fTemp108 * fTemp110) * fRec56[((IOTA - (iTemp109 + 1)) & 2047)]))) + (0.0416666679f * (fTemp111 * fRec56[((IOTA - (iTemp112 + 1)) & 2047)])))));
			float fRec57 = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fTempFTZ43 = fRec61;
			fRec58[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fTempFTZ44 = fRec58[1];
			fRec55[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fTempFTZ45 = fRec55[1];
			float fTemp113 = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fRec52 = fTemp113;
			float fRec53 = fTemp113;
			iRec46[0] = iRec51;
			float fTempFTZ46 = fRec54;
			float fRec47 = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fTempFTZ47 = fRec52;
			float fRec48 = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fTempFTZ48 = fRec53;
			float fRec49 = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fTempFTZ49 = fRec47;
			fRec42[(IOTA & 2047)] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fTempFTZ50 = fRec57;
			float fRec43 = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fTempFTZ51 = fRec48;
			float fRec44 = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fTempFTZ52 = fRec49;
			float fRec45 = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fTempFTZ53 = fRec43;
			fRec40[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fTempFTZ54 = fRec45;
			fRec41[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fTempFTZ55 = (0.0f - (fConst28 * ((fConst29 * fRec39[1]) - (fRec41[0] + fRec41[1]))));
			fRec39[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fThen0 = (fConst4 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))));
			float fTempFTZ56 = (0.0f - (fConst33 * ((fConst34 * fRec69[1]) - (fRec4[0] + fRec4[1]))));
			fRec69[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fTempFTZ57 = ((fConst35 * fRec4[1]) - (fConst33 * ((fConst34 * fRec70[1]) - (fConst31 * fRec4[0]))));
			fRec70[0] = ((std::fabs(fTempFTZ57) > 1.17549435e-38f) ? fTempFTZ57 : 0.0f);
			float fThen1 = (iSlow9 ? fRec39[0] : fThen0);
			float fElse1 = (fRec69[0] + (1.41253757f * fRec70[0]));
			float fTemp114 = (iSlow8 ? fElse1 : fThen1);
			float fTempFTZ58 = (fTemp114 - (fSlow23 * ((fSlow24 * fRec1[2]) + (fSlow25 * fRec1[1]))));
			fRec1[0] = ((std::fabs(fTempFTZ58) > 1.17549435e-38f) ? fTempFTZ58 : 0.0f);
			float fTempFTZ59 = (fTemp114 - (fSlow31 * ((fSlow32 * fRec71[2]) + (fSlow33 * fRec71[1]))));
			fRec71[0] = ((std::fabs(fTempFTZ59) > 1.17549435e-38f) ? fTempFTZ59 : 0.0f);
			float fTempFTZ60 = (fTemp114 - (fSlow38 * ((fSlow39 * fRec72[2]) + (fSlow40 * fRec72[1]))));
			fRec72[0] = ((std::fabs(fTempFTZ60) > 1.17549435e-38f) ? fTempFTZ60 : 0.0f);
			float fTemp115 = (0.333333343f * ((fSlow6 * fRec1[2]) + (((fSlow30 * fRec71[2]) + (((fSlow37 * fRec72[0]) + (fSlow41 * fRec72[2])) + (fSlow29 * fRec71[0]))) + (fSlow5 * fRec1[0]))));
			float fTempFTZ61 = (fTemp114 - (((fRec73[2] * fSlow47) + (fSlow48 * fRec73[1])) / fSlow49));
			fRec73[0] = ((std::fabs(fTempFTZ61) > 1.17549435e-38f) ? fTempFTZ61 : 0.0f);
			float fTemp116 = (fRec73[2] * fSlow51);
			float fTemp117 = (fSlow43 * ((fSlow50 * fRec73[0]) / fSlow49));
			fVec6[0] = ((fTemp117 + fTemp116) + fTemp115);
			float fTempFTZ62 = ((fTemp115 + (fTemp116 + ((0.995000005f * fRec0[1]) + fTemp117))) - fVec6[1]);
			fRec0[0] = ((std::fabs(fTempFTZ62) > 1.17549435e-38f) ? fTempFTZ62 : 0.0f);
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * fRec0[0])))));
			iRec13[1] = iRec13[0];
			fRec28[1] = fRec28[0];
			fRec25[1] = fRec25[0];
			fRec29[1] = fRec29[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec31[j0] = fRec31[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec0[1] = fVec0[0];
			iRec34[1] = iRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fVec1[1] = fVec1[0];
			iRec38[1] = iRec38[0];
			fVec2[1] = fVec2[0];
			iRec35[1] = iRec35[0];
			fVec3[1] = fVec3[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec18[j1] = fRec18[(j1 - 1)];
			}
			iRec9[1] = iRec9[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			iRec50[1] = iRec50[0];
			fRec62[1] = fRec62[0];
			fRec65[1] = fRec65[0];
			for (int j2 = 3; (j2 > 0); j2 = (j2 - 1)) {
				fRec67[j2] = fRec67[(j2 - 1)];
			}
			fVec4[1] = fVec4[0];
			fVec5[1] = fVec5[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			for (int j3 = 3; (j3 > 0); j3 = (j3 - 1)) {
				fRec55[j3] = fRec55[(j3 - 1)];
			}
			iRec46[1] = iRec46[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec69[1] = fRec69[0];
			fRec70[1] = fRec70[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fVec6[1] = fVec6[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
