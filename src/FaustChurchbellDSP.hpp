/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "churchbell"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -a minimal.cpp -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustChurchbellDSP_H__
#define  __FaustChurchbellDSP_H__

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

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float FaustChurchbellDSP_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustChurchbellDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustChurchbellDSP : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fVec1[2];
	float fRec2[2];
	float fRec1[3];
	float fConst5;
	float fRec3[3];
	float fConst6;
	float fRec4[3];
	float fConst7;
	float fRec5[3];
	float fConst8;
	float fRec6[3];
	float fConst9;
	float fRec7[3];
	float fConst10;
	float fRec8[3];
	float fVec2[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-a minimal.cpp -lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "Copyright (c) 2026 Shashank Khare, MIT License");
		m->declare("filename", "churchbell.dsp");
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
		m->declare("name", "churchbell");
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
		fConst1 = (9.42477798f / fConst0);
		float fConst2 = (1.0f / std::tan((4712.38916f / fConst0)));
		fConst3 = (1.0f / (fConst2 + 1.0f));
		fConst4 = (1.0f - fConst2);
		fConst5 = (7.88539743f / fConst0);
		fConst6 = (6.28318548f / fConst0);
		fConst7 = (4.90088463f / fConst0);
		fConst8 = (3.73849535f / fConst0);
		fConst9 = (3.14159274f / fConst0);
		fConst10 = (1.57079637f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.59999999999999998f);
		fHslider1 = FAUSTFLOAT(200.0f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fButton0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
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
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec2[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec0[l11] = 0.0f;
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
	
	virtual FaustChurchbellDSP* clone() {
		return new FaustChurchbellDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("churchbell");
		ui_interface->addHorizontalSlider("freq", &fHslider1, FAUSTFLOAT(200.0f), FAUSTFLOAT(100.0f), FAUSTFLOAT(1000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider0, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (12.25f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		float fSlow2 = std::tan((fConst1 * fSlow1));
		float fSlow3 = (1.0f / std::max<float>(1.0f, (1.7045455f * fSlow1)));
		float fSlow4 = (1.0f / fSlow2);
		float fSlow5 = (((fSlow3 + fSlow4) / fSlow2) + 1.0f);
		float fSlow6 = (0.200000003f / (fSlow2 * fSlow5));
		float fSlow7 = (0.0f - fSlow6);
		float fSlow8 = (50.0f * float(fHslider2));
		float fSlow9 = float(fButton0);
		float fSlow10 = (1.0f / fSlow5);
		float fSlow11 = (((fSlow4 - fSlow3) / fSlow2) + 1.0f);
		float fSlow12 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow2))));
		float fSlow13 = std::tan((fConst5 * fSlow1));
		float fSlow14 = (1.0f / std::max<float>(1.0f, (2.85227275f * fSlow1)));
		float fSlow15 = (1.0f / fSlow13);
		float fSlow16 = (((fSlow14 + fSlow15) / fSlow13) + 1.0f);
		float fSlow17 = (0.400000006f / (fSlow13 * fSlow16));
		float fSlow18 = (0.0f - fSlow17);
		float fSlow19 = (1.0f / fSlow16);
		float fSlow20 = (((fSlow15 - fSlow14) / fSlow13) + 1.0f);
		float fSlow21 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow13))));
		float fSlow22 = std::tan((fConst6 * fSlow1));
		float fSlow23 = (1.0f / std::max<float>(1.0f, (3.409091f * fSlow1)));
		float fSlow24 = (1.0f / fSlow22);
		float fSlow25 = (((fSlow23 + fSlow24) / fSlow22) + 1.0f);
		float fSlow26 = (1.0f / (fSlow22 * fSlow25));
		float fSlow27 = (0.0f - fSlow26);
		float fSlow28 = (1.0f / fSlow25);
		float fSlow29 = (((fSlow24 - fSlow23) / fSlow22) + 1.0f);
		float fSlow30 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow22))));
		float fSlow31 = std::tan((fConst7 * fSlow1));
		float fSlow32 = (1.0f / std::max<float>(1.0f, (3.5454545f * fSlow1)));
		float fSlow33 = (1.0f / fSlow31);
		float fSlow34 = (((fSlow32 + fSlow33) / fSlow31) + 1.0f);
		float fSlow35 = (0.600000024f / (fSlow31 * fSlow34));
		float fSlow36 = (0.0f - fSlow35);
		float fSlow37 = (1.0f / fSlow34);
		float fSlow38 = (((fSlow33 - fSlow32) / fSlow31) + 1.0f);
		float fSlow39 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow31))));
		float fSlow40 = std::tan((fConst8 * fSlow1));
		float fSlow41 = (1.0f / std::max<float>(1.0f, (4.05681801f * fSlow1)));
		float fSlow42 = (1.0f / fSlow40);
		float fSlow43 = (((fSlow41 + fSlow42) / fSlow40) + 1.0f);
		float fSlow44 = (0.800000012f / (fSlow40 * fSlow43));
		float fSlow45 = (0.0f - fSlow44);
		float fSlow46 = (1.0f / fSlow43);
		float fSlow47 = (((fSlow42 - fSlow41) / fSlow40) + 1.0f);
		float fSlow48 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow40))));
		float fSlow49 = std::tan((fConst9 * fSlow1));
		float fSlow50 = (1.0f / std::max<float>(1.0f, (4.5454545f * fSlow1)));
		float fSlow51 = (1.0f / fSlow49);
		float fSlow52 = (((fSlow50 + fSlow51) / fSlow49) + 1.0f);
		float fSlow53 = (1.0f / (fSlow49 * fSlow52));
		float fSlow54 = (0.0f - fSlow53);
		float fSlow55 = (1.0f / fSlow52);
		float fSlow56 = (((fSlow51 - fSlow50) / fSlow49) + 1.0f);
		float fSlow57 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow49))));
		float fSlow58 = std::tan((fConst10 * fSlow1));
		float fSlow59 = (1.0f / std::max<float>(1.0f, (2.840909f * fSlow1)));
		float fSlow60 = (1.0f / fSlow58);
		float fSlow61 = (((fSlow59 + fSlow60) / fSlow58) + 1.0f);
		float fSlow62 = (1.0f / (fSlow58 * fSlow61));
		float fSlow63 = (1.0f / fSlow61);
		float fSlow64 = (((fSlow60 - fSlow59) / fSlow58) + 1.0f);
		float fSlow65 = (2.0f * (1.0f - (1.0f / FaustChurchbellDSP_faustpower2_f(fSlow58))));
		float fSlow66 = (0.0f - fSlow62);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			fVec0[0] = fSlow9;
			float fTemp0 = (fSlow9 - fVec0[1]);
			float fTemp1 = (fSlow8 * (fTemp0 * float((fTemp0 > 0.0f))));
			fVec1[0] = fTemp1;
			fRec2[0] = (0.0f - (fConst3 * ((fConst4 * fRec2[1]) - (fTemp1 + fVec1[1]))));
			fRec1[0] = (fRec2[0] - (fSlow10 * ((fSlow11 * fRec1[2]) + (fSlow12 * fRec1[1]))));
			fRec3[0] = (fRec2[0] - (fSlow19 * ((fSlow20 * fRec3[2]) + (fSlow21 * fRec3[1]))));
			fRec4[0] = (fRec2[0] - (fSlow28 * ((fSlow29 * fRec4[2]) + (fSlow30 * fRec4[1]))));
			fRec5[0] = (fRec2[0] - (fSlow37 * ((fSlow38 * fRec5[2]) + (fSlow39 * fRec5[1]))));
			fRec6[0] = (fRec2[0] - (fSlow46 * ((fSlow47 * fRec6[2]) + (fSlow48 * fRec6[1]))));
			fRec7[0] = (fRec2[0] - (fSlow55 * ((fSlow56 * fRec7[2]) + (fSlow57 * fRec7[1]))));
			fRec8[0] = (fRec2[0] - (fSlow63 * ((fSlow64 * fRec8[2]) + (fSlow65 * fRec8[1]))));
			float fTemp2 = ((fSlow7 * fRec1[2]) + (((fSlow18 * fRec3[2]) + (((fSlow27 * fRec4[2]) + (((fSlow36 * fRec5[2]) + (((fSlow45 * fRec6[2]) + (((fSlow54 * fRec7[2]) + (((fSlow62 * fRec8[0]) + (fSlow66 * fRec8[2])) + (fSlow53 * fRec7[0]))) + (fSlow44 * fRec6[0]))) + (fSlow35 * fRec5[0]))) + (fSlow26 * fRec4[0]))) + (fSlow17 * fRec3[0]))) + (fSlow6 * fRec1[0])));
			fVec2[0] = fTemp2;
			fRec0[0] = ((0.995000005f * fRec0[1]) + (0.142857149f * (fTemp2 - fVec2[1])));
			output0[i0] = FAUSTFLOAT(float(tanhf(float((fSlow0 * fRec0[0])))));
			fVec0[1] = fVec0[0];
			fVec1[1] = fVec1[0];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
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
			fVec2[1] = fVec2[0];
			fRec0[1] = fRec0[0];
		}
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

using namespace std;

int main(int argc, char* argv[])
{
    FaustChurchbellDSP DSP;
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
