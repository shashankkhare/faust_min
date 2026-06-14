/* ------------------------------------------------------------
name: "test_chikari"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -a minimal.cpp -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/

/******************* BEGIN minimal.cpp ****************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/

#include <iostream>

#include "faust/gui/PrintUI.h"
#include "faust/gui/meta.h"
#include "faust/audio/dummy-audio.h"
#include "faust/dsp/one-sample-dsp.h"

// faust -a minimal.cpp noise.dsp -o noise.cpp && c++ -std=c++11 noise.cpp -o noise && ./noise

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

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
static float mydsp_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float mydsp_faustpower4_f(float value) {
	return (((value * value) * value) * value);
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
	
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	float fConst9;
	float fConst16;
	FAUSTFLOAT fHslider1;
	float fConst18;
	int iRec3[2];
	float fConst19;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec2[5];
	float fConst28;
	float fConst29;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec5[2];
	int iVec1[2];
	int iRec4[2];
	float fConst30;
	int IOTA;
	float fVec2[8192];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-a minimal.cpp -lang cpp -es 1 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "test_chikari.dsp");
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
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "test_chikari");
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
		float fConst1 = (1.0f / fConst0);
		float fConst2 = mydsp_faustpower2_f(fConst1);
		float fConst3 = std::tan((5026.54834f / fConst0));
		float fConst4 = (fConst0 * fConst3);
		float fConst5 = std::sqrt((4.0f * ((mydsp_faustpower2_f(fConst0) * fConst3) * std::tan((2513.27417f / fConst0)))));
		float fConst6 = mydsp_faustpower2_f(fConst5);
		float fConst7 = ((2.0f * fConst4) - (0.5f * (fConst6 / fConst4)));
		float fConst8 = mydsp_faustpower2_f(fConst7);
		fConst9 = (4.0f * fConst8);
		float fConst10 = (fConst9 + (8.0f * fConst6));
		float fConst11 = (fConst1 * fConst6);
		float fConst12 = (2.82842708f * fConst7);
		float fConst13 = (fConst7 / fConst0);
		float fConst14 = (11.3137083f * fConst13);
		float fConst15 = (((fConst2 * (fConst10 + (fConst11 * (fConst11 + fConst12)))) + fConst14) + 16.0f);
		fConst16 = (0.600000024f * (fConst2 / fConst15));
		float fConst17 = (8.0f * fConst8);
		fConst18 = (0.0f - fConst17);
		fConst19 = (1.0f / fConst15);
		float fConst20 = (mydsp_faustpower3_f(fConst1) * fConst6);
		float fConst21 = (4.0f * fConst11);
		float fConst22 = (5.65685415f * fConst7);
		float fConst23 = (22.6274166f * fConst13);
		fConst24 = ((fConst20 * (fConst21 + fConst22)) + (-64.0f - fConst23));
		fConst25 = ((fConst2 * ((0.0f - (fConst17 + (16.0f * fConst6))) + (6.0f * (fConst2 * mydsp_faustpower4_f(fConst5))))) + 96.0f);
		fConst26 = ((fConst23 + (fConst20 * (fConst21 - fConst22))) + -64.0f);
		fConst27 = ((fConst2 * (fConst10 + (fConst11 * (fConst11 - fConst12)))) + (16.0f - fConst14));
		fConst28 = std::max<float>(1.0f, (0.00300000003f * fConst0));
		fConst29 = (1.0f / fConst28);
		fConst30 = (1.0f / std::max<float>(1.0f, (0.0149999997f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(880.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			iRec3[l1] = 0;
		}
		for (int l2 = 0; (l2 < 5); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iVec1[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec4[l6] = 0;
		}
		IOTA = 0;
		for (int l7 = 0; (l7 < 8192); l7 = (l7 + 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec0[l8] = 0.0f;
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
		ui_interface->openVerticalBox("test_chikari");
		ui_interface->addHorizontalSlider("chikari_freq", &fHslider0, FAUSTFLOAT(880.0f), FAUSTFLOAT(40.0f), FAUSTFLOAT(2000.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("strike", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (fConst0 / fSlow0);
		int iSlow2 = int((fSlow1 + -1.0f));
		float fSlow3 = float(iSlow2);
		float fSlow4 = (fSlow3 + (2.0f - fSlow1));
		float fSlow5 = std::pow(0.00100000005f, (4.0f / fSlow0));
		float fSlow6 = (fConst16 * float((float(fHslider1) > 0.5f)));
		float fSlow7 = float(fButton0);
		int iSlow8 = std::min<int>(16384, std::max<int>(0, iSlow2));
		float fSlow9 = (fSlow1 + (-1.0f - fSlow3));
		int iSlow10 = std::min<int>(16384, std::max<int>(0, (iSlow2 + 1)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fRec1[0] = ((0.0399999991f * fRec1[1]) + (0.959999979f * fRec0[1]));
			iRec3[0] = ((1103515245 * iRec3[1]) + 12345);
			fRec2[0] = ((4.65661287e-10f * float(iRec3[0])) - (fConst19 * ((((fConst24 * fRec2[1]) + (fConst25 * fRec2[2])) + (fConst26 * fRec2[3])) + (fConst27 * fRec2[4]))));
			fVec0[0] = fSlow7;
			float fThen0 = std::max<float>(0.0f, (fRec5[1] + -1.0f));
			fRec5[0] = ((fSlow7 > fVec0[1]) ? 150.0f : fThen0);
			int iTemp0 = (fRec5[0] > 0.0f);
			iVec1[0] = iTemp0;
			iRec4[0] = (((iRec4[1] + (iRec4[1] > 0)) * (iTemp0 <= iVec1[1])) + (iTemp0 > iVec1[1]));
			float fTemp1 = float(iRec4[0]);
			float fTemp2 = ((fSlow5 * fRec1[0]) + (fSlow6 * ((((fConst18 * fRec2[2]) + (fConst9 * fRec2[0])) + (fConst9 * fRec2[4])) * std::max<float>(0.0f, std::min<float>((fConst29 * fTemp1), ((fConst30 * (fConst28 - fTemp1)) + 1.0f))))));
			fVec2[(IOTA & 8191)] = fTemp2;
			fRec0[0] = ((fSlow4 * fVec2[((IOTA - iSlow8) & 8191)]) + (fSlow9 * fVec2[((IOTA - iSlow10) & 8191)]));
			output0[i0] = FAUSTFLOAT(fRec0[0]);
			fRec1[1] = fRec1[0];
			iRec3[1] = iRec3[0];
			for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
				fRec2[j0] = fRec2[(j0 - 1)];
			}
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			iVec1[1] = iVec1[0];
			iRec4[1] = iRec4[0];
			IOTA = (IOTA + 1);
			fRec0[1] = fRec0[0];
		}
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

using namespace std;

int main(int argc, char* argv[])
{
    mydsp DSP;
    cout << "DSP size: " << sizeof(DSP) << " bytes\n";
    
    // Activate the UI, here that only print the control paths
    PrintUI ui;
    DSP.buildUserInterface(&ui);

    // Allocate the audio driver to render 5 buffers of 512 frames
    dummyaudio audio(5);
    audio.init("Test", static_cast<dsp*>(&DSP));
    
    // Render buffers...
    audio.start();
    audio.stop();
}

/******************* END minimal.cpp ****************/


#endif
