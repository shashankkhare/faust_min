/* ------------------------------------------------------------
name: "test_override"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float mydsp_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	int iRec10[2];
	int fSampleRate;
	float fConst8;
	int iConst11;
	int iConst12;
	float fConst13;
	float fConst14;
	int iConst15;
	int iConst16;
	float fConst17;
	int iConst18;
	int iConst19;
	float fConst21;
	int iConst22;
	int iConst23;
	float fConst24;
	int iConst25;
	int iConst26;
	float fRec22[2];
	float fRec25[2];
	float fConst34;
	float fRec27[4];
	int IOTA;
	float fRec28[2048];
	int iConst37;
	float fConst38;
	float fConst39;
	int iConst41;
	float fConst42;
	int iConst44;
	float fConst46;
	int iConst48;
	float fConst49;
	int iConst51;
	float fVec0[2];
	float fConst55;
	int iRec30[2];
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec29[3];
	float fConst59;
	int iRec31[2];
	float fVec1[2];
	float fRec26[1024];
	float fRec19[2];
	float fRec16[2048];
	int iConst60;
	int iConst61;
	int iConst62;
	int iConst63;
	int iConst64;
	float fRec18[2];
	float fRec15[4];
	int iRec6[2];
	float fRec2[1024];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "test_override.dsp");
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
		m->declare("name", "test_override");
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
		float fConst1 = (0.00291176466f * fConst0);
		float fConst2 = (fConst1 + -1.49999499f);
		float fConst3 = std::floor(fConst2);
		float fConst4 = (fConst1 + (-1.0f - fConst3));
		float fConst5 = (fConst1 + (-2.0f - fConst3));
		float fConst6 = (fConst1 + (-3.0f - fConst3));
		float fConst7 = (fConst1 + (-4.0f - fConst3));
		fConst8 = ((((0.0f - fConst4) * (0.0f - (0.5f * fConst5))) * (0.0f - (0.333333343f * fConst6))) * (0.0f - (0.25f * fConst7)));
		float fConst9 = (0.00882352982f * fConst0);
		int iConst10 = int(fConst2);
		iConst11 = int(std::min<float>(fConst9, float(std::max<int>(0, iConst10))));
		iConst12 = (iConst11 + 1);
		fConst13 = (fConst1 - fConst3);
		fConst14 = (((0.0f - fConst5) * (0.0f - (0.5f * fConst6))) * (0.0f - (0.333333343f * fConst7)));
		iConst15 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst10 + 1)))));
		iConst16 = (iConst15 + 1);
		fConst17 = (0.5f * ((fConst4 * (0.0f - fConst6)) * (0.0f - (0.5f * fConst7))));
		iConst18 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst10 + 2)))));
		iConst19 = (iConst18 + 1);
		float fConst20 = (fConst4 * fConst5);
		fConst21 = (0.166666672f * (fConst20 * (0.0f - fConst7)));
		iConst22 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst10 + 3)))));
		iConst23 = (iConst22 + 1);
		fConst24 = (0.0416666679f * (fConst20 * fConst6));
		iConst25 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst10 + 4)))));
		iConst26 = (iConst25 + 1);
		float fConst27 = (0.0116470587f * fConst0);
		float fConst28 = (fConst27 + -1.49999499f);
		float fConst29 = std::floor(fConst28);
		float fConst30 = (fConst27 + (-1.0f - fConst29));
		float fConst31 = (fConst27 + (-2.0f - fConst29));
		float fConst32 = (fConst27 + (-3.0f - fConst29));
		float fConst33 = (fConst27 + (-4.0f - fConst29));
		fConst34 = ((((0.0f - fConst30) * (0.0f - (0.5f * fConst31))) * (0.0f - (0.333333343f * fConst32))) * (0.0f - (0.25f * fConst33)));
		int iConst35 = int(fConst28);
		int iConst36 = int(std::min<float>(fConst9, float(std::max<int>(0, iConst35))));
		iConst37 = (iConst36 + 2);
		fConst38 = (fConst27 - fConst29);
		fConst39 = (((0.0f - fConst31) * (0.0f - (0.5f * fConst32))) * (0.0f - (0.333333343f * fConst33)));
		int iConst40 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst35 + 1)))));
		iConst41 = (iConst40 + 2);
		fConst42 = (0.5f * ((fConst30 * (0.0f - fConst32)) * (0.0f - (0.5f * fConst33))));
		int iConst43 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst35 + 2)))));
		iConst44 = (iConst43 + 2);
		float fConst45 = (fConst30 * fConst31);
		fConst46 = (0.166666672f * (fConst45 * (0.0f - fConst33)));
		int iConst47 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst35 + 3)))));
		iConst48 = (iConst47 + 2);
		fConst49 = (0.0416666679f * (fConst45 * fConst32));
		int iConst50 = int(std::min<float>(fConst9, float(std::max<int>(0, (iConst35 + 4)))));
		iConst51 = (iConst50 + 2);
		float fConst52 = std::tan((534.07074f / fConst0));
		float fConst53 = (1.0f / fConst52);
		float fConst54 = (((fConst53 + 1.41421354f) / fConst52) + 1.0f);
		fConst55 = (0.5f / fConst54);
		fConst56 = (1.0f / fConst54);
		fConst57 = (((fConst53 + -1.41421354f) / fConst52) + 1.0f);
		fConst58 = (2.0f * (1.0f - (1.0f / mydsp_faustpower2_f(fConst52))));
		fConst59 = (1.0f / std::max<float>(1.0f, (0.00195492362f * fConst0)));
		iConst60 = (iConst36 + 1);
		iConst61 = (iConst40 + 1);
		iConst62 = (iConst43 + 1);
		iConst63 = (iConst47 + 1);
		iConst64 = (iConst50 + 1);
	}
	
	virtual void instanceResetUserInterface() {
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec10[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec22[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec25[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 4); l3 = (l3 + 1)) {
			fRec27[l3] = 0.0f;
		}
		IOTA = 0;
		for (int l4 = 0; (l4 < 2048); l4 = (l4 + 1)) {
			fRec28[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec0[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec30[l6] = 0;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec29[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			iRec31[l8] = 0;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 1024); l10 = (l10 + 1)) {
			fRec26[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec19[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2048); l12 = (l12 + 1)) {
			fRec16[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec18[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 4); l14 = (l14 + 1)) {
			fRec15[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			iRec6[l15] = 0;
		}
		for (int l16 = 0; (l16 < 1024); l16 = (l16 + 1)) {
			fRec2[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec0[l17] = 0.0f;
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
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("test_override");
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec10[0] = 0;
			int iRec11 = iRec10[1];
			float fRec14 = (float(iRec6[1]) - (0.997843683f * ((0.699999988f * fRec15[2]) + (0.150000006f * (fRec15[1] + fRec15[3])))));
			fRec22[0] = ((fConst8 * fRec2[((IOTA - iConst12) & 1023)]) + (fConst13 * ((((fConst14 * fRec2[((IOTA - iConst16) & 1023)]) + (fConst17 * fRec2[((IOTA - iConst19) & 1023)])) + (fConst21 * fRec2[((IOTA - iConst23) & 1023)])) + (fConst24 * fRec2[((IOTA - iConst26) & 1023)]))));
			fRec25[0] = ((0.0500000007f * fRec25[1]) + (0.949999988f * fRec22[1]));
			float fRec23 = fRec25[0];
			fRec27[0] = fRec0[1];
			fRec28[(IOTA & 2047)] = (-1.0f * (0.997843683f * ((0.699999988f * fRec27[2]) + (0.150000006f * (fRec27[1] + fRec27[3])))));
			fVec0[0] = ((fConst34 * fRec28[((IOTA - iConst37) & 2047)]) + (fConst38 * ((((fConst39 * fRec28[((IOTA - iConst41) & 2047)]) + (fConst42 * fRec28[((IOTA - iConst44) & 2047)])) + (fConst46 * fRec28[((IOTA - iConst48) & 2047)])) + (fConst49 * fRec28[((IOTA - iConst51) & 2047)]))));
			iRec30[0] = ((1103515245 * iRec30[1]) + 12345);
			fRec29[0] = ((4.65661287e-10f * float(iRec30[0])) - (fConst56 * ((fConst57 * fRec29[2]) + (fConst58 * fRec29[1]))));
			iRec31[0] = (iRec31[1] + (iRec31[1] > 0));
			float fTemp0 = (fConst59 * float(iRec31[0]));
			float fTemp1 = (fConst55 * ((fRec29[2] + (fRec29[0] + (2.0f * fRec29[1]))) * std::max<float>(0.0f, std::min<float>(fTemp0, (2.0f - fTemp0)))));
			fVec1[0] = (fVec0[1] + fTemp1);
			fRec26[(IOTA & 1023)] = ((0.0500000007f * fRec26[((IOTA - 1) & 1023)]) + (0.949999988f * fVec1[1]));
			float fRec24 = ((fConst8 * fRec26[((IOTA - iConst11) & 1023)]) + (fConst13 * ((((fConst14 * fRec26[((IOTA - iConst15) & 1023)]) + (fConst17 * fRec26[((IOTA - iConst18) & 1023)])) + (fConst21 * fRec26[((IOTA - iConst22) & 1023)])) + (fConst24 * fRec26[((IOTA - iConst25) & 1023)]))));
			fRec19[0] = fRec23;
			float fRec20 = (fTemp1 + fRec19[1]);
			float fRec21 = fRec24;
			fRec16[(IOTA & 2047)] = fRec20;
			float fRec17 = ((fConst34 * fRec16[((IOTA - iConst60) & 2047)]) + (fConst38 * ((((fConst39 * fRec16[((IOTA - iConst61) & 2047)]) + (fConst42 * fRec16[((IOTA - iConst62) & 2047)])) + (fConst46 * fRec16[((IOTA - iConst63) & 2047)])) + (fConst49 * fRec16[((IOTA - iConst64) & 2047)]))));
			fRec18[0] = fRec21;
			fRec15[0] = fRec18[1];
			float fRec12 = fRec15[1];
			float fRec13 = fRec15[1];
			iRec6[0] = iRec11;
			float fRec7 = fRec14;
			float fRec8 = fRec12;
			float fRec9 = fRec13;
			fRec2[(IOTA & 1023)] = fRec7;
			float fRec3 = fRec17;
			float fRec4 = fRec8;
			float fRec5 = fRec9;
			fRec0[0] = fRec3;
			float fRec1 = fRec5;
			output0[i0] = FAUSTFLOAT(fRec1);
			iRec10[1] = iRec10[0];
			fRec22[1] = fRec22[0];
			fRec25[1] = fRec25[0];
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				fRec27[j0] = fRec27[(j0 - 1)];
			}
			IOTA = (IOTA + 1);
			fVec0[1] = fVec0[0];
			iRec30[1] = iRec30[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			iRec31[1] = iRec31[0];
			fVec1[1] = fVec1[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
				fRec15[j1] = fRec15[(j1 - 1)];
			}
			iRec6[1] = iRec6[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
