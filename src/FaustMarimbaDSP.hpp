/* ------------------------------------------------------------
copyright: "Copyright (c) 2026 Shashank Khare, MIT License"
name: "marimba"
Code generated with Faust 2.37.3 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 1
------------------------------------------------------------ */

#ifndef  __FaustMarimbaDSP_H__
#define  __FaustMarimbaDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <float.h>
#include <math.h>

const static float fFaustMarimbaDSPSIG0Wave0[250] = {1.0f,0.776724994f,0.625723004f,0.855223f,0.760159016f,0.69837302f,0.768010974f,0.64112699f,0.244034007f,0.707754016f,0.634012997f,0.247527003f,0.660848975f,0.450396001f,0.567782998f,0.106361002f,0.716813982f,0.663919985f,0.291207999f,0.310598999f,0.801495016f,0.635291994f,0.307435006f,0.874123991f,0.497667998f,0.487087995f,0.459114999f,0.733455002f,0.541818023f,0.441318005f,0.313919991f,0.40309f,0.685352981f,0.603139997f,0.400552005f,0.453511f,0.634386003f,0.291547f,0.131604999f,0.368506998f,0.839906991f,0.602159977f,0.288296014f,0.579670012f,0.0242493004f,0.262746006f,0.368588001f,0.890284002f,0.408962995f,0.556071997f,0.884427011f,0.832109988f,0.612015009f,0.757175982f,0.919476986f,1.0f,0.827962995f,0.89240998f,0.0357408002f,0.480789006f,0.75287199f,0.0546301007f,0.235936999f,0.362937987f,0.444471985f,0.101751f,0.703418016f,0.453135997f,0.316628993f,0.490393996f,0.982508004f,0.551621974f,0.602008998f,0.666957021f,0.776830018f,0.905662f,0.0987197012f,0.402967989f,0.829451978f,0.307644993f,0.640479982f,0.983971f,0.584204972f,0.650364995f,0.334446996f,0.583570004f,0.540190995f,0.672533989f,0.245711997f,0.687298f,0.883058012f,0.792949975f,0.600619018f,0.572682023f,0.122612f,0.388247997f,0.290657997f,0.380255014f,0.290966988f,0.567818999f,0.0737721026f,0.42098999f,0.0786577985f,0.393994987f,0.268983006f,0.260614008f,0.494085997f,0.238025993f,0.0987823978f,0.277879f,0.440562993f,0.0770211965f,0.450590998f,0.128137007f,0.0368275009f,0.128699005f,0.329605013f,0.374511987f,0.363590002f,0.272594005f,0.379052013f,0.305240989f,0.0741128996f,0.34572801f,0.299349993f,0.221284002f,0.0261390992f,0.293202013f,0.361885011f,0.114330001f,0.239004999f,0.434156001f,0.329582989f,0.219459996f,0.284175009f,0.198554993f,0.431975991f,0.302985013f,1.0f,0.146220997f,0.140700996f,0.264243007f,0.185996994f,0.426322013f,0.304780006f,0.343989998f,0.195429996f,0.386954993f,0.187600002f,0.172812f,0.0434115008f,0.303761005f,0.0694539994f,0.453943014f,0.832450986f,0.317817003f,0.940600991f,1.0f,0.180657998f,0.737921f,0.832297027f,0.402352005f,0.126785994f,0.594398022f,0.485455006f,0.324470013f,0.365101993f,0.777921975f,0.588271976f,0.401353002f,0.610734999f,0.158693001f,0.0746072009f,0.825098991f,0.925459027f,0.65377003f,0.260791987f,0.719384015f,0.559907973f,0.372590005f,0.360035002f,0.622938991f,0.210271001f,0.444595009f,0.311286002f,0.464309007f,0.557231009f,0.524079978f,0.0701055974f,0.320749015f,0.194460005f,0.727608979f,0.522062004f,0.394003987f,0.235035002f,0.395646006f,0.494796008f,0.51731801f,0.109751999f,0.69284898f,0.00632009003f,0.0207582992f,0.00306107011f,0.0637191013f,0.0816610008f,0.0351100005f,0.127813995f,0.202294007f,0.0764145032f,0.263126999f,0.400198996f,0.267277986f,0.633385003f,1.0f,0.73990202f,0.413762987f,0.418110013f,0.612715006f,0.67237401f,0.339673996f,0.211720005f,0.459645003f,0.102499999f,0.325890005f,0.148154005f,0.265442014f,0.0974304974f,0.286437988f,0.275213003f,0.109111004f,0.575088978f,0.370283008f,0.29411f,0.259826005f,0.0648718998f,0.583418012f,0.282662988f,0.182004005f,0.117421001f,0.417726994f,0.169650003f,0.24853f,0.122818999f,0.185486004f,0.0433618017f,0.373849005f,0.25276801f,0.195103005f,0.0927835032f,0.166543007f};
class FaustMarimbaDSPSIG0 {
	
  private:
	
	int fFaustMarimbaDSPSIG0Wave0_idx;
	
  public:
	
	int getNumInputsFaustMarimbaDSPSIG0() {
		return 0;
	}
	int getNumOutputsFaustMarimbaDSPSIG0() {
		return 1;
	}
	
	void instanceInitFaustMarimbaDSPSIG0(int sample_rate) {
		fFaustMarimbaDSPSIG0Wave0_idx = 0;
	}
	
	void fillFaustMarimbaDSPSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			table[i1] = fFaustMarimbaDSPSIG0Wave0[fFaustMarimbaDSPSIG0Wave0_idx];
			fFaustMarimbaDSPSIG0Wave0_idx = ((1 + fFaustMarimbaDSPSIG0Wave0_idx) % 250);
		}
	}

};

static FaustMarimbaDSPSIG0* newFaustMarimbaDSPSIG0() { return (FaustMarimbaDSPSIG0*)new FaustMarimbaDSPSIG0(); }
static void deleteFaustMarimbaDSPSIG0(FaustMarimbaDSPSIG0* dsp) { delete dsp; }

static float FaustMarimbaDSP_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FaustMarimbaDSPSIG0[250];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustMarimbaDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FaustMarimbaDSP : public dsp {
	
 private:
	
	int iRec0[2];
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider0;
	float fRec4[2];
	int IOTA;
	float fVec0[1024];
	float fConst2;
	float fRec2[2];
	float fRec5[2];
	FAUSTFLOAT fHslider1;
	float fConst5;
	float fConst7;
	int iRec9[2];
	float fConst8;
	float fConst9;
	float fRec8[3];
	float fConst10;
	float fConst11;
	float fConst12;
	FAUSTFLOAT fHslider2;
	float fConst13;
	float fRec10[2];
	float fRec7[3];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iVec2[2];
	int iRec11[2];
	float fConst14;
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec6[3];
	float fConst19;
	FAUSTFLOAT fHslider3;
	float fRec12[2];
	float fConst21;
	float fConst22;
	float fConst23;
	float fRec13[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec14[3];
	float fConst29;
	float fConst30;
	float fConst31;
	float fRec15[3];
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec16[3];
	float fConst37;
	float fConst38;
	float fConst39;
	float fRec17[3];
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec18[3];
	float fConst45;
	float fConst46;
	float fConst47;
	float fRec19[3];
	float fConst49;
	float fConst50;
	float fConst51;
	float fRec20[3];
	float fConst53;
	float fConst54;
	float fConst55;
	float fRec21[3];
	float fConst57;
	float fConst58;
	float fConst59;
	float fRec22[3];
	float fConst61;
	float fConst62;
	float fConst63;
	float fRec23[3];
	float fConst65;
	float fConst66;
	float fConst67;
	float fRec24[3];
	float fConst69;
	float fConst70;
	float fConst71;
	float fRec25[3];
	float fConst73;
	float fConst74;
	float fConst75;
	float fRec26[3];
	float fConst77;
	float fConst78;
	float fConst79;
	float fRec27[3];
	float fConst81;
	float fConst82;
	float fConst83;
	float fRec28[3];
	float fConst85;
	float fConst86;
	float fConst87;
	float fRec29[3];
	float fConst89;
	float fConst90;
	float fConst91;
	float fRec30[3];
	float fConst93;
	float fConst94;
	float fConst95;
	float fRec31[3];
	float fConst97;
	float fConst98;
	float fConst99;
	float fRec32[3];
	float fConst101;
	float fConst102;
	float fConst103;
	float fRec33[3];
	float fConst105;
	float fConst106;
	float fConst107;
	float fRec34[3];
	float fConst109;
	float fConst110;
	float fConst111;
	float fRec35[3];
	float fConst113;
	float fConst114;
	float fConst115;
	float fRec36[3];
	float fConst117;
	float fConst118;
	float fConst119;
	float fRec37[3];
	float fConst121;
	float fConst122;
	float fConst123;
	float fRec38[3];
	float fConst125;
	float fConst126;
	float fConst127;
	float fRec39[3];
	float fConst129;
	float fConst130;
	float fConst131;
	float fRec40[3];
	float fConst133;
	float fConst134;
	float fConst135;
	float fRec41[3];
	float fConst137;
	float fConst138;
	float fConst139;
	float fRec42[3];
	float fConst141;
	float fConst142;
	float fConst143;
	float fRec43[3];
	float fConst145;
	float fConst146;
	float fConst147;
	float fRec44[3];
	float fConst149;
	float fConst150;
	float fConst151;
	float fRec45[3];
	float fConst153;
	float fConst154;
	float fConst155;
	float fRec46[3];
	float fConst157;
	float fConst158;
	float fConst159;
	float fRec47[3];
	float fConst161;
	float fConst162;
	float fConst163;
	float fRec48[3];
	float fConst165;
	float fConst166;
	float fConst167;
	float fRec49[3];
	float fConst169;
	float fConst170;
	float fConst171;
	float fRec50[3];
	float fConst173;
	float fConst174;
	float fConst175;
	float fRec51[3];
	float fConst177;
	float fConst178;
	float fConst179;
	float fRec52[3];
	float fConst181;
	float fConst182;
	float fConst183;
	float fRec53[3];
	float fConst185;
	float fConst186;
	float fConst187;
	float fRec54[3];
	float fConst189;
	float fConst190;
	float fConst191;
	float fRec55[3];
	float fConst193;
	float fConst194;
	float fConst195;
	float fRec56[3];
	float fConst197;
	float fConst198;
	float fConst199;
	float fRec57[3];
	float fConst201;
	float fConst202;
	float fConst203;
	float fRec58[3];
	float fConst205;
	float fConst206;
	float fConst207;
	float fRec59[3];
	float fConst209;
	float fConst210;
	float fConst211;
	float fRec60[3];
	float fConst213;
	float fConst214;
	float fConst215;
	float fRec61[3];
	float fVec3[2];
	float fVec4[1024];
	float fRec3[2];
	FAUSTFLOAT fHslider4;
	float fRec62[2];
	
 public:
	
	void metadata(Meta* m) { 
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
		m->declare("filename", "marimba.dsp");
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
		m->declare("name", "marimba");
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
		FaustMarimbaDSPSIG0* sig0 = newFaustMarimbaDSPSIG0();
		sig0->instanceInitFaustMarimbaDSPSIG0(sample_rate);
		sig0->fillFaustMarimbaDSPSIG0(250, ftbl0FaustMarimbaDSPSIG0);
		deleteFaustMarimbaDSPSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (0.00147058826f * fConst0);
		fConst2 = (0.00882352982f * fConst0);
		float fConst3 = std::tan((31.415926f / fConst0));
		float fConst4 = (1.0f / fConst3);
		fConst5 = (1.0f / (((fConst4 + 1.41421354f) / fConst3) + 1.0f));
		float fConst6 = FaustMarimbaDSP_faustpower2_f(fConst3);
		fConst7 = (1.0f / fConst6);
		fConst8 = (((fConst4 + -1.41421354f) / fConst3) + 1.0f);
		fConst9 = (2.0f * (1.0f - fConst7));
		fConst10 = (0.0f - (2.0f / fConst6));
		fConst11 = (3.14159274f / fConst0);
		fConst12 = (44.0999985f / fConst0);
		fConst13 = (1.0f - fConst12);
		fConst14 = (0.00200000009f * fConst0);
		float fConst15 = std::pow(0.00100000005f, (10.2591143f / fConst0));
		fConst16 = (0.0f - (2.0f * fConst15));
		fConst17 = (6.28318548f / fConst0);
		fConst18 = FaustMarimbaDSP_faustpower2_f(fConst15);
		fConst19 = ((0.5f * fConst0) + -1.0f);
		float fConst20 = std::pow(0.00100000005f, (10.8901329f / fConst0));
		fConst21 = (0.0f - (2.0f * fConst20));
		fConst22 = (20.8197117f / fConst0);
		fConst23 = FaustMarimbaDSP_faustpower2_f(fConst20);
		float fConst24 = std::pow(0.00100000005f, (11.0386343f / fConst0));
		fConst25 = (0.0f - (2.0f * fConst24));
		fConst26 = (24.0940685f / fConst0);
		fConst27 = FaustMarimbaDSP_faustpower2_f(fConst24);
		float fConst28 = std::pow(0.00100000005f, (12.3379154f / fConst0));
		fConst29 = (0.0f - (2.0f * fConst28));
		fConst30 = (50.6621399f / fConst0);
		fConst31 = FaustMarimbaDSP_faustpower2_f(fConst28);
		float fConst32 = std::pow(0.00100000005f, (12.8027573f / fConst0));
		fConst33 = (0.0f - (2.0f * fConst32));
		fConst34 = (59.3621521f / fConst0);
		fConst35 = FaustMarimbaDSP_faustpower2_f(fConst32);
		float fConst36 = std::pow(0.00100000005f, (14.5330687f / fConst0));
		fConst37 = (0.0f - (2.0f * fConst36));
		fConst38 = (88.6990967f / fConst0);
		fConst39 = FaustMarimbaDSP_faustpower2_f(fConst36);
		float fConst40 = std::pow(0.00100000005f, (16.3652077f / fConst0));
		fConst41 = (0.0f - (2.0f * fConst40));
		fConst42 = (115.510078f / fConst0);
		fConst43 = FaustMarimbaDSP_faustpower2_f(fConst40);
		float fConst44 = std::pow(0.00100000005f, (17.6309834f / fConst0));
		fConst45 = (0.0f - (2.0f * fConst44));
		fConst46 = (132.010986f / fConst0);
		fConst47 = FaustMarimbaDSP_faustpower2_f(fConst44);
		float fConst48 = std::pow(0.00100000005f, (20.4824104f / fConst0));
		fConst49 = (0.0f - (2.0f * fConst48));
		fConst50 = (164.478088f / fConst0);
		fConst51 = FaustMarimbaDSP_faustpower2_f(fConst48);
		float fConst52 = std::pow(0.00100000005f, (22.2695656f / fConst0));
		fConst53 = (0.0f - (2.0f * fConst52));
		fConst54 = (182.177185f / fConst0);
		fConst55 = FaustMarimbaDSP_faustpower2_f(fConst52);
		float fConst56 = std::pow(0.00100000005f, (28.5368156f / fConst0));
		fConst57 = (0.0f - (2.0f * fConst56));
		fConst58 = (232.935272f / fConst0);
		fConst59 = FaustMarimbaDSP_faustpower2_f(fConst56);
		float fConst60 = std::pow(0.00100000005f, (29.2639236f / fConst0));
		fConst61 = (0.0f - (2.0f * fConst60));
		fConst62 = (237.946106f / fConst0);
		fConst63 = FaustMarimbaDSP_faustpower2_f(fConst60);
		float fConst64 = std::pow(0.00100000005f, (31.3811016f / fConst0));
		fConst65 = (0.0f - (2.0f * fConst64));
		fConst66 = (251.725769f / fConst0);
		fConst67 = FaustMarimbaDSP_faustpower2_f(fConst64);
		float fConst68 = std::pow(0.00100000005f, (40.2636795f / fConst0));
		fConst69 = (0.0f - (2.0f * fConst68));
		fConst70 = (299.355438f / fConst0);
		fConst71 = FaustMarimbaDSP_faustpower2_f(fConst68);
		float fConst72 = std::pow(0.00100000005f, (45.1752319f / fConst0));
		fConst73 = (0.0f - (2.0f * fConst72));
		fConst74 = (320.561829f / fConst0);
		fConst75 = FaustMarimbaDSP_faustpower2_f(fConst72);
		float fConst76 = std::pow(0.00100000005f, (47.4399223f / fConst0));
		fConst77 = (0.0f - (2.0f * fConst76));
		fConst78 = (329.427399f / fConst0);
		fConst79 = FaustMarimbaDSP_faustpower2_f(fConst76);
		float fConst80 = std::pow(0.00100000005f, (58.4253006f / fConst0));
		fConst81 = (0.0f - (2.0f * fConst80));
		fConst82 = (366.221741f / fConst0);
		fConst83 = FaustMarimbaDSP_faustpower2_f(fConst80);
		float fConst84 = std::pow(0.00100000005f, (70.9964905f / fConst0));
		fConst85 = (0.0f - (2.0f * fConst84));
		fConst86 = (399.287628f / fConst0);
		fConst87 = FaustMarimbaDSP_faustpower2_f(fConst84);
		float fConst88 = std::pow(0.00100000005f, (76.0668716f / fConst0));
		fConst89 = (0.0f - (2.0f * fConst88));
		fConst90 = (410.686584f / fConst0);
		fConst91 = FaustMarimbaDSP_faustpower2_f(fConst88);
		float fConst92 = std::pow(0.00100000005f, (80.8901215f / fConst0));
		fConst93 = (0.0f - (2.0f * fConst92));
		fConst94 = (420.713928f / fConst0);
		fConst95 = FaustMarimbaDSP_faustpower2_f(fConst92);
		float fConst96 = std::pow(0.00100000005f, (109.456856f / fConst0));
		fConst97 = (0.0f - (2.0f * fConst96));
		fConst98 = (468.286438f / fConst0);
		fConst99 = FaustMarimbaDSP_faustpower2_f(fConst96);
		float fConst100 = std::pow(0.00100000005f, (130.309692f / fConst0));
		fConst101 = (0.0f - (2.0f * fConst100));
		fConst102 = (494.436432f / fConst0);
		fConst103 = FaustMarimbaDSP_faustpower2_f(fConst100);
		float fConst104 = std::pow(0.00100000005f, (142.914078f / fConst0));
		fConst105 = (0.0f - (2.0f * fConst104));
		fConst106 = (507.916992f / fConst0);
		fConst107 = FaustMarimbaDSP_faustpower2_f(fConst104);
		float fConst108 = std::pow(0.00100000005f, (216.134277f / fConst0));
		fConst109 = (0.0f - (2.0f * fConst108));
		fConst110 = (565.34845f / fConst0);
		fConst111 = FaustMarimbaDSP_faustpower2_f(fConst108);
		float fConst112 = std::pow(0.00100000005f, (249.361649f / fConst0));
		fConst113 = (0.0f - (2.0f * fConst112));
		fConst114 = (584.12323f / fConst0);
		fConst115 = FaustMarimbaDSP_faustpower2_f(fConst112);
		float fConst116 = std::pow(0.00100000005f, (278.139954f / fConst0));
		fConst117 = (0.0f - (2.0f * fConst116));
		fConst118 = (598.105225f / fConst0);
		fConst119 = FaustMarimbaDSP_faustpower2_f(fConst116);
		float fConst120 = std::pow(0.00100000005f, (312.009094f / fConst0));
		fConst121 = (0.0f - (2.0f * fConst120));
		fConst122 = (612.489319f / fConst0);
		fConst123 = FaustMarimbaDSP_faustpower2_f(fConst120);
		float fConst124 = std::pow(0.00100000005f, (638.477783f / fConst0));
		fConst125 = (0.0f - (2.0f * fConst124));
		fConst126 = (695.045959f / fConst0);
		fConst127 = FaustMarimbaDSP_faustpower2_f(fConst124);
		float fConst128 = std::pow(0.00100000005f, (695.55957f / fConst0));
		fConst129 = (0.0f - (2.0f * fConst128));
		fConst130 = (704.150269f / fConst0);
		fConst131 = FaustMarimbaDSP_faustpower2_f(fConst128);
		float fConst132 = std::pow(0.00100000005f, (773.212891f / fConst0));
		fConst133 = (0.0f - (2.0f * fConst132));
		fConst134 = (715.18988f / fConst0);
		fConst135 = FaustMarimbaDSP_faustpower2_f(fConst132);
		float fConst136 = std::pow(0.00100000005f, (1095.63586f / fConst0));
		fConst137 = (0.0f - (2.0f * fConst136));
		fConst138 = (749.935852f / fConst0);
		fConst139 = FaustMarimbaDSP_faustpower2_f(fConst136);
		float fConst140 = std::pow(0.00100000005f, (1859.39001f / fConst0));
		fConst141 = (0.0f - (2.0f * fConst140));
		fConst142 = (798.247253f / fConst0);
		fConst143 = FaustMarimbaDSP_faustpower2_f(fConst140);
		float fConst144 = std::pow(0.00100000005f, (2311.80176f / fConst0));
		fConst145 = (0.0f - (2.0f * fConst144));
		fConst146 = (816.700989f / fConst0);
		fConst147 = FaustMarimbaDSP_faustpower2_f(fConst144);
		float fConst148 = std::pow(0.00100000005f, (2755.63037f / fConst0));
		fConst149 = (0.0f - (2.0f * fConst148));
		fConst150 = (831.007812f / fConst0);
		fConst151 = FaustMarimbaDSP_faustpower2_f(fConst148);
		float fConst152 = std::pow(0.00100000005f, (3034.91235f / fConst0));
		fConst153 = (0.0f - (2.0f * fConst152));
		fConst154 = (838.660706f / fConst0);
		fConst155 = FaustMarimbaDSP_faustpower2_f(fConst152);
		float fConst156 = std::pow(0.00100000005f, (8048.45801f / fConst0));
		fConst157 = (0.0f - (2.0f * fConst156));
		fConst158 = (908.228149f / fConst0);
		fConst159 = FaustMarimbaDSP_faustpower2_f(fConst156);
		float fConst160 = std::pow(0.00100000005f, (13265.4883f / fConst0));
		fConst161 = (0.0f - (2.0f * fConst160));
		fConst162 = (938.946655f / fConst0);
		fConst163 = FaustMarimbaDSP_faustpower2_f(fConst160);
		float fConst164 = std::pow(0.00100000005f, (17675.4805f / fConst0));
		fConst165 = (0.0f - (2.0f * fConst164));
		fConst166 = (955.251526f / fConst0);
		fConst167 = FaustMarimbaDSP_faustpower2_f(fConst164);
		float fConst168 = std::pow(0.00100000005f, (20142.8574f / fConst0));
		fConst169 = (0.0f - (2.0f * fConst168));
		fConst170 = (962.370361f / fConst0);
		fConst171 = FaustMarimbaDSP_faustpower2_f(fConst168);
		float fConst172 = std::pow(0.00100000005f, (26985.6934f / fConst0));
		fConst173 = (0.0f - (2.0f * fConst172));
		fConst174 = (977.644775f / fConst0);
		fConst175 = FaustMarimbaDSP_faustpower2_f(fConst172);
		float fConst176 = std::pow(0.00100000005f, (37577.8438f / fConst0));
		fConst177 = (0.0f - (2.0f * fConst176));
		fConst178 = (993.893127f / fConst0);
		fConst179 = FaustMarimbaDSP_faustpower2_f(fConst176);
		float fConst180 = std::pow(0.00100000005f, (172447.047f / fConst0));
		fConst181 = (0.0f - (2.0f * fConst180));
		fConst182 = (1056.23486f / fConst0);
		fConst183 = FaustMarimbaDSP_faustpower2_f(fConst180);
		float fConst184 = std::pow(0.00100000005f, (355973.344f / fConst0));
		fConst185 = (0.0f - (2.0f * fConst184));
		fConst186 = (1079.84705f / fConst0);
		fConst187 = FaustMarimbaDSP_faustpower2_f(fConst184);
		float fConst188 = std::pow(0.00100000005f, (630229.375f / fConst0));
		fConst189 = (0.0f - (2.0f * fConst188));
		fConst190 = (1096.1897f / fConst0);
		fConst191 = FaustMarimbaDSP_faustpower2_f(fConst188);
		float fConst192 = std::pow(0.00100000005f, (2024133.5f / fConst0));
		fConst193 = (0.0f - (2.0f * fConst192));
		fConst194 = (1124.29431f / fConst0);
		fConst195 = FaustMarimbaDSP_faustpower2_f(fConst192);
		float fConst196 = std::pow(0.00100000005f, (4549764.5f / fConst0));
		fConst197 = (0.0f - (2.0f * fConst196));
		fConst198 = (1140.28503f / fConst0);
		fConst199 = FaustMarimbaDSP_faustpower2_f(fConst196);
		float fConst200 = std::pow(0.00100000005f, (22033280.0f / fConst0));
		fConst201 = (0.0f - (2.0f * fConst200));
		fConst202 = (1164.89001f / fConst0);
		fConst203 = FaustMarimbaDSP_faustpower2_f(fConst200);
		float fConst204 = std::pow(0.00100000005f, (531223264.0f / fConst0));
		fConst205 = (0.0f - (2.0f * fConst204));
		fConst206 = (1196.12366f / fConst0);
		fConst207 = FaustMarimbaDSP_faustpower2_f(fConst204);
		float fConst208 = std::pow(0.00100000005f, (3.8190633e+09f / fConst0));
		fConst209 = (0.0f - (2.0f * fConst208));
		fConst210 = (1207.56543f / fConst0);
		fConst211 = FaustMarimbaDSP_faustpower2_f(fConst208);
		float fConst212 = std::pow(0.00100000005f, (1.56573838e+14f / fConst0));
		fConst213 = (0.0f - (2.0f * fConst212));
		fConst214 = (1228.39417f / fConst0);
		fConst215 = FaustMarimbaDSP_faustpower2_f(fConst212);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(220.0f);
		fHslider1 = FAUSTFLOAT(0.80000000000000004f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(2.0f);
		fHslider4 = FAUSTFLOAT(0.80000000000000004f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec4[l1] = 0.0f;
		}
		IOTA = 0;
		for (int l2 = 0; (l2 < 1024); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec9[l5] = 0;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec8[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec10[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iVec2[l10] = 0;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			iRec11[l11] = 0;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec6[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
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
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec20[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec21[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec23[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec24[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec25[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec26[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec27[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec29[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec30[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec31[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec32[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec33[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec34[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec35[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec36[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec37[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec38[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec39[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec40[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec41[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec42[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec43[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec44[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec45[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec46[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec47[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec48[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec49[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec50[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec51[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec52[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec53[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec54[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec55[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec56[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec57[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec58[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec59[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec60[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec61[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fVec3[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 1024); l64 = (l64 + 1)) {
			fVec4[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec3[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec62[l66] = 0.0f;
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
	
	virtual FaustMarimbaDSP* clone() {
		return new FaustMarimbaDSP();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("marimba");
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(220.0f), FAUSTFLOAT(130.0f), FAUSTFLOAT(2093.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->addHorizontalSlider("gain", &fHslider4, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("position", &fHslider3, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("strike", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addHorizontalSlider("velocity", &fHslider1, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (fConst1 * ((340.0f / fSlow0) + -0.0399999991f));
		float fSlow2 = (fSlow1 + -1.49999499f);
		float fSlow3 = std::floor(fSlow2);
		float fSlow4 = (fSlow1 + (-1.0f - fSlow3));
		float fSlow5 = (fSlow1 + (-2.0f - fSlow3));
		float fSlow6 = (fSlow1 + (-3.0f - fSlow3));
		float fSlow7 = (fSlow1 + (-4.0f - fSlow3));
		float fSlow8 = ((((0.0f - fSlow4) * (0.0f - (0.5f * fSlow5))) * (0.0f - (0.333333343f * fSlow6))) * (0.0f - (0.25f * fSlow7)));
		int iSlow9 = int(fSlow2);
		int iSlow10 = int(std::min<float>(fConst2, float(std::max<int>(0, iSlow9))));
		float fSlow11 = (fSlow1 - fSlow3);
		float fSlow12 = (((0.0f - fSlow5) * (0.0f - (0.5f * fSlow6))) * (0.0f - (0.333333343f * fSlow7)));
		int iSlow13 = int(std::min<float>(fConst2, float(std::max<int>(0, (iSlow9 + 1)))));
		float fSlow14 = (0.5f * ((fSlow4 * (0.0f - fSlow6)) * (0.0f - (0.5f * fSlow7))));
		int iSlow15 = int(std::min<float>(fConst2, float(std::max<int>(0, (iSlow9 + 2)))));
		float fSlow16 = (fSlow4 * fSlow5);
		float fSlow17 = (0.166666672f * (fSlow16 * (0.0f - fSlow7)));
		int iSlow18 = int(std::min<float>(fConst2, float(std::max<int>(0, (iSlow9 + 3)))));
		float fSlow19 = (0.0416666679f * (fSlow16 * fSlow6));
		int iSlow20 = int(std::min<float>(fConst2, float(std::max<int>(0, (iSlow9 + 4)))));
		float fSlow21 = float(fHslider1);
		float fSlow22 = (fConst12 * float(fHslider2));
		float fSlow23 = float(fButton0);
		int iSlow24 = (fSlow23 > 0.0f);
		float fSlow25 = (fConst16 * std::cos((fConst17 * fSlow0)));
		int iSlow26 = (fSlow0 < fConst19);
		float fSlow27 = (fConst12 * float(fHslider3));
		float fSlow28 = (fConst21 * std::cos((fConst22 * fSlow0)));
		int iSlow29 = ((3.31356001f * fSlow0) < fConst19);
		float fSlow30 = (fConst25 * std::cos((fConst26 * fSlow0)));
		int iSlow31 = ((3.83469009f * fSlow0) < fConst19);
		float fSlow32 = (fConst29 * std::cos((fConst30 * fSlow0)));
		int iSlow33 = ((8.06313038f * fSlow0) < fConst19);
		float fSlow34 = (fConst33 * std::cos((fConst34 * fSlow0)));
		int iSlow35 = ((9.44777966f * fSlow0) < fConst19);
		float fSlow36 = (fConst37 * std::cos((fConst38 * fSlow0)));
		int iSlow37 = ((14.1169004f * fSlow0) < fConst19);
		float fSlow38 = (fConst41 * std::cos((fConst42 * fSlow0)));
		int iSlow39 = ((18.3840008f * fSlow0) < fConst19);
		float fSlow40 = (fConst45 * std::cos((fConst46 * fSlow0)));
		int iSlow41 = ((21.0102005f * fSlow0) < fConst19);
		float fSlow42 = (fConst49 * std::cos((fConst50 * fSlow0)));
		int iSlow43 = ((26.1774998f * fSlow0) < fConst19);
		float fSlow44 = (fConst53 * std::cos((fConst54 * fSlow0)));
		int iSlow45 = ((28.9944f * fSlow0) < fConst19);
		float fSlow46 = (fConst57 * std::cos((fConst58 * fSlow0)));
		int iSlow47 = ((37.0727997f * fSlow0) < fConst19);
		float fSlow48 = (fConst61 * std::cos((fConst62 * fSlow0)));
		int iSlow49 = ((37.8703003f * fSlow0) < fConst19);
		float fSlow50 = (fConst65 * std::cos((fConst66 * fSlow0)));
		int iSlow51 = ((40.0634003f * fSlow0) < fConst19);
		float fSlow52 = (fConst69 * std::cos((fConst70 * fSlow0)));
		int iSlow53 = ((47.6439018f * fSlow0) < fConst19);
		float fSlow54 = (fConst73 * std::cos((fConst74 * fSlow0)));
		int iSlow55 = ((51.019001f * fSlow0) < fConst19);
		float fSlow56 = (fConst77 * std::cos((fConst78 * fSlow0)));
		int iSlow57 = ((52.4300003f * fSlow0) < fConst19);
		float fSlow58 = (fConst81 * std::cos((fConst82 * fSlow0)));
		int iSlow59 = ((58.2859993f * fSlow0) < fConst19);
		float fSlow60 = (fConst85 * std::cos((fConst86 * fSlow0)));
		int iSlow61 = ((63.5485992f * fSlow0) < fConst19);
		float fSlow62 = (fConst89 * std::cos((fConst90 * fSlow0)));
		int iSlow63 = ((65.3628006f * fSlow0) < fConst19);
		float fSlow64 = (fConst93 * std::cos((fConst94 * fSlow0)));
		int iSlow65 = ((66.9587021f * fSlow0) < fConst19);
		float fSlow66 = (fConst97 * std::cos((fConst98 * fSlow0)));
		int iSlow67 = ((74.530098f * fSlow0) < fConst19);
		float fSlow68 = (fConst101 * std::cos((fConst102 * fSlow0)));
		int iSlow69 = ((78.6920013f * fSlow0) < fConst19);
		float fSlow70 = (fConst105 * std::cos((fConst106 * fSlow0)));
		int iSlow71 = ((80.8375015f * fSlow0) < fConst19);
		float fSlow72 = (fConst109 * std::cos((fConst110 * fSlow0)));
		int iSlow73 = ((89.9779968f * fSlow0) < fConst19);
		float fSlow74 = (fConst113 * std::cos((fConst114 * fSlow0)));
		int iSlow75 = ((92.9661026f * fSlow0) < fConst19);
		float fSlow76 = (fConst117 * std::cos((fConst118 * fSlow0)));
		int iSlow77 = ((95.1913986f * fSlow0) < fConst19);
		float fSlow78 = (fConst121 * std::cos((fConst122 * fSlow0)));
		int iSlow79 = ((97.4806976f * fSlow0) < fConst19);
		float fSlow80 = (fConst125 * std::cos((fConst126 * fSlow0)));
		int iSlow81 = ((110.620003f * fSlow0) < fConst19);
		float fSlow82 = (fConst129 * std::cos((fConst130 * fSlow0)));
		int iSlow83 = ((112.069f * fSlow0) < fConst19);
		float fSlow84 = (fConst133 * std::cos((fConst134 * fSlow0)));
		int iSlow85 = ((113.825996f * fSlow0) < fConst19);
		float fSlow86 = (fConst137 * std::cos((fConst138 * fSlow0)));
		int iSlow87 = ((119.356003f * fSlow0) < fConst19);
		float fSlow88 = (fConst141 * std::cos((fConst142 * fSlow0)));
		int iSlow89 = ((127.044998f * fSlow0) < fConst19);
		float fSlow90 = (fConst145 * std::cos((fConst146 * fSlow0)));
		int iSlow91 = ((129.981995f * fSlow0) < fConst19);
		float fSlow92 = (fConst149 * std::cos((fConst150 * fSlow0)));
		int iSlow93 = ((132.259003f * fSlow0) < fConst19);
		float fSlow94 = (fConst153 * std::cos((fConst154 * fSlow0)));
		int iSlow95 = ((133.477005f * fSlow0) < fConst19);
		float fSlow96 = (fConst157 * std::cos((fConst158 * fSlow0)));
		int iSlow97 = ((144.548996f * fSlow0) < fConst19);
		float fSlow98 = (fConst161 * std::cos((fConst162 * fSlow0)));
		int iSlow99 = ((149.438004f * fSlow0) < fConst19);
		float fSlow100 = (fConst165 * std::cos((fConst166 * fSlow0)));
		int iSlow101 = ((152.033005f * fSlow0) < fConst19);
		float fSlow102 = (fConst169 * std::cos((fConst170 * fSlow0)));
		int iSlow103 = ((153.166f * fSlow0) < fConst19);
		float fSlow104 = (fConst173 * std::cos((fConst174 * fSlow0)));
		int iSlow105 = ((155.597f * fSlow0) < fConst19);
		float fSlow106 = (fConst177 * std::cos((fConst178 * fSlow0)));
		int iSlow107 = ((158.182999f * fSlow0) < fConst19);
		float fSlow108 = (fConst181 * std::cos((fConst182 * fSlow0)));
		int iSlow109 = ((168.104996f * fSlow0) < fConst19);
		float fSlow110 = (fConst185 * std::cos((fConst186 * fSlow0)));
		int iSlow111 = ((171.863007f * fSlow0) < fConst19);
		float fSlow112 = (fConst189 * std::cos((fConst190 * fSlow0)));
		int iSlow113 = ((174.464005f * fSlow0) < fConst19);
		float fSlow114 = (fConst193 * std::cos((fConst194 * fSlow0)));
		int iSlow115 = ((178.936996f * fSlow0) < fConst19);
		float fSlow116 = (fConst197 * std::cos((fConst198 * fSlow0)));
		int iSlow117 = ((181.481995f * fSlow0) < fConst19);
		float fSlow118 = (fConst201 * std::cos((fConst202 * fSlow0)));
		int iSlow119 = ((185.397995f * fSlow0) < fConst19);
		float fSlow120 = (fConst205 * std::cos((fConst206 * fSlow0)));
		int iSlow121 = ((190.369003f * fSlow0) < fConst19);
		float fSlow122 = (fConst209 * std::cos((fConst210 * fSlow0)));
		int iSlow123 = ((192.190002f * fSlow0) < fConst19);
		float fSlow124 = (fConst213 * std::cos((fConst214 * fSlow0)));
		int iSlow125 = ((195.505005f * fSlow0) < fConst19);
		float fSlow126 = (fConst12 * float(fHslider4));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec0[0] = 0;
			float fTempFTZ0 = ((0.949999988f * fRec4[1]) + (0.0500000007f * fRec3[1]));
			fRec4[0] = ((std::fabs(fTempFTZ0) > 1.17549435e-38f) ? fTempFTZ0 : 0.0f);
			float fTemp0 = ((0.99000001f * fRec4[0]) + float(iRec0[1]));
			fVec0[(IOTA & 1023)] = fTemp0;
			float fTempFTZ1 = ((fSlow8 * fVec0[((IOTA - iSlow10) & 1023)]) + (fSlow11 * ((((fSlow12 * fVec0[((IOTA - iSlow13) & 1023)]) + (fSlow14 * fVec0[((IOTA - iSlow15) & 1023)])) + (fSlow17 * fVec0[((IOTA - iSlow18) & 1023)])) + (fSlow19 * fVec0[((IOTA - iSlow20) & 1023)]))));
			fRec2[0] = ((std::fabs(fTempFTZ1) > 1.17549435e-38f) ? fTempFTZ1 : 0.0f);
			float fTempFTZ2 = ((0.949999988f * fRec5[1]) + (0.0500000007f * fRec2[1]));
			fRec5[0] = ((std::fabs(fTempFTZ2) > 1.17549435e-38f) ? fTempFTZ2 : 0.0f);
			iRec9[0] = ((1103515245 * iRec9[1]) + 12345);
			float fTempFTZ3 = ((4.65661287e-10f * float(iRec9[0])) - (fConst5 * ((fConst8 * fRec8[2]) + (fConst9 * fRec8[1]))));
			fRec8[0] = ((std::fabs(fTempFTZ3) > 1.17549435e-38f) ? fTempFTZ3 : 0.0f);
			float fTempFTZ4 = (fSlow22 + (fConst13 * fRec10[1]));
			fRec10[0] = ((std::fabs(fTempFTZ4) > 1.17549435e-38f) ? fTempFTZ4 : 0.0f);
			float fTemp1 = std::tan((fConst11 * ((15000.0f * fRec10[0]) + 1000.0f)));
			float fTemp2 = (1.0f / fTemp1);
			float fTemp3 = (((fTemp2 + 1.41421354f) / fTemp1) + 1.0f);
			float fTempFTZ5 = ((fConst5 * (((fConst7 * fRec8[0]) + (fConst10 * fRec8[1])) + (fConst7 * fRec8[2]))) - (((fRec7[2] * (((fTemp2 + -1.41421354f) / fTemp1) + 1.0f)) + (2.0f * (fRec7[1] * (1.0f - (1.0f / FaustMarimbaDSP_faustpower2_f(fTemp1)))))) / fTemp3));
			fRec7[0] = ((std::fabs(fTempFTZ5) > 1.17549435e-38f) ? fTempFTZ5 : 0.0f);
			fVec1[0] = fSlow23;
			int iTemp4 = (iSlow24 & (fVec1[1] <= 0.0f));
			iVec2[0] = iTemp4;
			iRec11[0] = (((iRec11[1] + (iRec11[1] > 0)) * (iTemp4 <= iVec2[1])) + (iTemp4 > iVec2[1]));
			float fTemp5 = (float(iRec11[0]) / std::max<float>(1.0f, (fConst14 * ((0.899999976f * fRec10[0]) + 0.100000001f))));
			float fTemp6 = (fSlow21 * (((fRec7[2] + (fRec7[0] + (2.0f * fRec7[1]))) * std::max<float>(0.0f, std::min<float>(fTemp5, (2.0f - fTemp5)))) / fTemp3));
			float fTempFTZ6 = (fTemp6 - ((fSlow25 * fRec6[1]) + (fConst18 * fRec6[2])));
			fRec6[0] = ((std::fabs(fTempFTZ6) > 1.17549435e-38f) ? fTempFTZ6 : 0.0f);
			float fTempFTZ7 = (fSlow27 + (fConst13 * fRec12[1]));
			fRec12[0] = ((std::fabs(fTempFTZ7) > 1.17549435e-38f) ? fTempFTZ7 : 0.0f);
			int iTemp7 = (50 * int(fRec12[0]));
			float fElse0 = ftbl0FaustMarimbaDSPSIG0[iTemp7];
			float fTempFTZ8 = (fTemp6 - ((fSlow28 * fRec13[1]) + (fConst23 * fRec13[2])));
			fRec13[0] = ((std::fabs(fTempFTZ8) > 1.17549435e-38f) ? fTempFTZ8 : 0.0f);
			float fElse1 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 1)];
			float fTempFTZ9 = (fTemp6 - ((fSlow30 * fRec14[1]) + (fConst27 * fRec14[2])));
			fRec14[0] = ((std::fabs(fTempFTZ9) > 1.17549435e-38f) ? fTempFTZ9 : 0.0f);
			float fElse2 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 2)];
			float fTempFTZ10 = (fTemp6 - ((fSlow32 * fRec15[1]) + (fConst31 * fRec15[2])));
			fRec15[0] = ((std::fabs(fTempFTZ10) > 1.17549435e-38f) ? fTempFTZ10 : 0.0f);
			float fElse3 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 3)];
			float fTempFTZ11 = (fTemp6 - ((fSlow34 * fRec16[1]) + (fConst35 * fRec16[2])));
			fRec16[0] = ((std::fabs(fTempFTZ11) > 1.17549435e-38f) ? fTempFTZ11 : 0.0f);
			float fElse4 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 4)];
			float fTempFTZ12 = (fTemp6 - ((fSlow36 * fRec17[1]) + (fConst39 * fRec17[2])));
			fRec17[0] = ((std::fabs(fTempFTZ12) > 1.17549435e-38f) ? fTempFTZ12 : 0.0f);
			float fElse5 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 5)];
			float fTempFTZ13 = (fTemp6 - ((fSlow38 * fRec18[1]) + (fConst43 * fRec18[2])));
			fRec18[0] = ((std::fabs(fTempFTZ13) > 1.17549435e-38f) ? fTempFTZ13 : 0.0f);
			float fElse6 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 6)];
			float fTempFTZ14 = (fTemp6 - ((fSlow40 * fRec19[1]) + (fConst47 * fRec19[2])));
			fRec19[0] = ((std::fabs(fTempFTZ14) > 1.17549435e-38f) ? fTempFTZ14 : 0.0f);
			float fElse7 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 7)];
			float fTempFTZ15 = (fTemp6 - ((fSlow42 * fRec20[1]) + (fConst51 * fRec20[2])));
			fRec20[0] = ((std::fabs(fTempFTZ15) > 1.17549435e-38f) ? fTempFTZ15 : 0.0f);
			float fElse8 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 8)];
			float fTempFTZ16 = (fTemp6 - ((fSlow44 * fRec21[1]) + (fConst55 * fRec21[2])));
			fRec21[0] = ((std::fabs(fTempFTZ16) > 1.17549435e-38f) ? fTempFTZ16 : 0.0f);
			float fElse9 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 9)];
			float fTempFTZ17 = (fTemp6 - ((fSlow46 * fRec22[1]) + (fConst59 * fRec22[2])));
			fRec22[0] = ((std::fabs(fTempFTZ17) > 1.17549435e-38f) ? fTempFTZ17 : 0.0f);
			float fElse10 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 10)];
			float fTempFTZ18 = (fTemp6 - ((fSlow48 * fRec23[1]) + (fConst63 * fRec23[2])));
			fRec23[0] = ((std::fabs(fTempFTZ18) > 1.17549435e-38f) ? fTempFTZ18 : 0.0f);
			float fElse11 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 11)];
			float fTempFTZ19 = (fTemp6 - ((fSlow50 * fRec24[1]) + (fConst67 * fRec24[2])));
			fRec24[0] = ((std::fabs(fTempFTZ19) > 1.17549435e-38f) ? fTempFTZ19 : 0.0f);
			float fElse12 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 12)];
			float fTempFTZ20 = (fTemp6 - ((fSlow52 * fRec25[1]) + (fConst71 * fRec25[2])));
			fRec25[0] = ((std::fabs(fTempFTZ20) > 1.17549435e-38f) ? fTempFTZ20 : 0.0f);
			float fElse13 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 13)];
			float fTempFTZ21 = (fTemp6 - ((fSlow54 * fRec26[1]) + (fConst75 * fRec26[2])));
			fRec26[0] = ((std::fabs(fTempFTZ21) > 1.17549435e-38f) ? fTempFTZ21 : 0.0f);
			float fElse14 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 14)];
			float fTempFTZ22 = (fTemp6 - ((fSlow56 * fRec27[1]) + (fConst79 * fRec27[2])));
			fRec27[0] = ((std::fabs(fTempFTZ22) > 1.17549435e-38f) ? fTempFTZ22 : 0.0f);
			float fElse15 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 15)];
			float fTempFTZ23 = (fTemp6 - ((fSlow58 * fRec28[1]) + (fConst83 * fRec28[2])));
			fRec28[0] = ((std::fabs(fTempFTZ23) > 1.17549435e-38f) ? fTempFTZ23 : 0.0f);
			float fElse16 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 16)];
			float fTempFTZ24 = (fTemp6 - ((fSlow60 * fRec29[1]) + (fConst87 * fRec29[2])));
			fRec29[0] = ((std::fabs(fTempFTZ24) > 1.17549435e-38f) ? fTempFTZ24 : 0.0f);
			float fElse17 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 17)];
			float fTempFTZ25 = (fTemp6 - ((fSlow62 * fRec30[1]) + (fConst91 * fRec30[2])));
			fRec30[0] = ((std::fabs(fTempFTZ25) > 1.17549435e-38f) ? fTempFTZ25 : 0.0f);
			float fElse18 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 18)];
			float fTempFTZ26 = (fTemp6 - ((fSlow64 * fRec31[1]) + (fConst95 * fRec31[2])));
			fRec31[0] = ((std::fabs(fTempFTZ26) > 1.17549435e-38f) ? fTempFTZ26 : 0.0f);
			float fElse19 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 19)];
			float fTempFTZ27 = (fTemp6 - ((fSlow66 * fRec32[1]) + (fConst99 * fRec32[2])));
			fRec32[0] = ((std::fabs(fTempFTZ27) > 1.17549435e-38f) ? fTempFTZ27 : 0.0f);
			float fElse20 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 20)];
			float fTempFTZ28 = (fTemp6 - ((fSlow68 * fRec33[1]) + (fConst103 * fRec33[2])));
			fRec33[0] = ((std::fabs(fTempFTZ28) > 1.17549435e-38f) ? fTempFTZ28 : 0.0f);
			float fElse21 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 21)];
			float fTempFTZ29 = (fTemp6 - ((fSlow70 * fRec34[1]) + (fConst107 * fRec34[2])));
			fRec34[0] = ((std::fabs(fTempFTZ29) > 1.17549435e-38f) ? fTempFTZ29 : 0.0f);
			float fElse22 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 22)];
			float fTempFTZ30 = (fTemp6 - ((fSlow72 * fRec35[1]) + (fConst111 * fRec35[2])));
			fRec35[0] = ((std::fabs(fTempFTZ30) > 1.17549435e-38f) ? fTempFTZ30 : 0.0f);
			float fElse23 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 23)];
			float fTempFTZ31 = (fTemp6 - ((fSlow74 * fRec36[1]) + (fConst115 * fRec36[2])));
			fRec36[0] = ((std::fabs(fTempFTZ31) > 1.17549435e-38f) ? fTempFTZ31 : 0.0f);
			float fElse24 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 24)];
			float fTempFTZ32 = (fTemp6 - ((fSlow76 * fRec37[1]) + (fConst119 * fRec37[2])));
			fRec37[0] = ((std::fabs(fTempFTZ32) > 1.17549435e-38f) ? fTempFTZ32 : 0.0f);
			float fElse25 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 25)];
			float fTempFTZ33 = (fTemp6 - ((fSlow78 * fRec38[1]) + (fConst123 * fRec38[2])));
			fRec38[0] = ((std::fabs(fTempFTZ33) > 1.17549435e-38f) ? fTempFTZ33 : 0.0f);
			float fElse26 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 26)];
			float fTempFTZ34 = (fTemp6 - ((fSlow80 * fRec39[1]) + (fConst127 * fRec39[2])));
			fRec39[0] = ((std::fabs(fTempFTZ34) > 1.17549435e-38f) ? fTempFTZ34 : 0.0f);
			float fElse27 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 27)];
			float fTempFTZ35 = (fTemp6 - ((fSlow82 * fRec40[1]) + (fConst131 * fRec40[2])));
			fRec40[0] = ((std::fabs(fTempFTZ35) > 1.17549435e-38f) ? fTempFTZ35 : 0.0f);
			float fElse28 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 28)];
			float fTempFTZ36 = (fTemp6 - ((fSlow84 * fRec41[1]) + (fConst135 * fRec41[2])));
			fRec41[0] = ((std::fabs(fTempFTZ36) > 1.17549435e-38f) ? fTempFTZ36 : 0.0f);
			float fElse29 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 29)];
			float fTempFTZ37 = (fTemp6 - ((fSlow86 * fRec42[1]) + (fConst139 * fRec42[2])));
			fRec42[0] = ((std::fabs(fTempFTZ37) > 1.17549435e-38f) ? fTempFTZ37 : 0.0f);
			float fElse30 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 30)];
			float fTempFTZ38 = (fTemp6 - ((fSlow88 * fRec43[1]) + (fConst143 * fRec43[2])));
			fRec43[0] = ((std::fabs(fTempFTZ38) > 1.17549435e-38f) ? fTempFTZ38 : 0.0f);
			float fElse31 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 31)];
			float fTempFTZ39 = (fTemp6 - ((fSlow90 * fRec44[1]) + (fConst147 * fRec44[2])));
			fRec44[0] = ((std::fabs(fTempFTZ39) > 1.17549435e-38f) ? fTempFTZ39 : 0.0f);
			float fElse32 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 32)];
			float fTempFTZ40 = (fTemp6 - ((fSlow92 * fRec45[1]) + (fConst151 * fRec45[2])));
			fRec45[0] = ((std::fabs(fTempFTZ40) > 1.17549435e-38f) ? fTempFTZ40 : 0.0f);
			float fElse33 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 33)];
			float fTempFTZ41 = (fTemp6 - ((fSlow94 * fRec46[1]) + (fConst155 * fRec46[2])));
			fRec46[0] = ((std::fabs(fTempFTZ41) > 1.17549435e-38f) ? fTempFTZ41 : 0.0f);
			float fElse34 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 34)];
			float fTempFTZ42 = (fTemp6 - ((fSlow96 * fRec47[1]) + (fConst159 * fRec47[2])));
			fRec47[0] = ((std::fabs(fTempFTZ42) > 1.17549435e-38f) ? fTempFTZ42 : 0.0f);
			float fElse35 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 35)];
			float fTempFTZ43 = (fTemp6 - ((fSlow98 * fRec48[1]) + (fConst163 * fRec48[2])));
			fRec48[0] = ((std::fabs(fTempFTZ43) > 1.17549435e-38f) ? fTempFTZ43 : 0.0f);
			float fElse36 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 36)];
			float fTempFTZ44 = (fTemp6 - ((fSlow100 * fRec49[1]) + (fConst167 * fRec49[2])));
			fRec49[0] = ((std::fabs(fTempFTZ44) > 1.17549435e-38f) ? fTempFTZ44 : 0.0f);
			float fElse37 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 37)];
			float fTempFTZ45 = (fTemp6 - ((fSlow102 * fRec50[1]) + (fConst171 * fRec50[2])));
			fRec50[0] = ((std::fabs(fTempFTZ45) > 1.17549435e-38f) ? fTempFTZ45 : 0.0f);
			float fElse38 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 38)];
			float fTempFTZ46 = (fTemp6 - ((fSlow104 * fRec51[1]) + (fConst175 * fRec51[2])));
			fRec51[0] = ((std::fabs(fTempFTZ46) > 1.17549435e-38f) ? fTempFTZ46 : 0.0f);
			float fElse39 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 39)];
			float fTempFTZ47 = (fTemp6 - ((fSlow106 * fRec52[1]) + (fConst179 * fRec52[2])));
			fRec52[0] = ((std::fabs(fTempFTZ47) > 1.17549435e-38f) ? fTempFTZ47 : 0.0f);
			float fElse40 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 40)];
			float fTempFTZ48 = (fTemp6 - ((fSlow108 * fRec53[1]) + (fConst183 * fRec53[2])));
			fRec53[0] = ((std::fabs(fTempFTZ48) > 1.17549435e-38f) ? fTempFTZ48 : 0.0f);
			float fElse41 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 41)];
			float fTempFTZ49 = (fTemp6 - ((fSlow110 * fRec54[1]) + (fConst187 * fRec54[2])));
			fRec54[0] = ((std::fabs(fTempFTZ49) > 1.17549435e-38f) ? fTempFTZ49 : 0.0f);
			float fElse42 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 42)];
			float fTempFTZ50 = (fTemp6 - ((fSlow112 * fRec55[1]) + (fConst191 * fRec55[2])));
			fRec55[0] = ((std::fabs(fTempFTZ50) > 1.17549435e-38f) ? fTempFTZ50 : 0.0f);
			float fElse43 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 43)];
			float fTempFTZ51 = (fTemp6 - ((fSlow114 * fRec56[1]) + (fConst195 * fRec56[2])));
			fRec56[0] = ((std::fabs(fTempFTZ51) > 1.17549435e-38f) ? fTempFTZ51 : 0.0f);
			float fElse44 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 44)];
			float fTempFTZ52 = (fTemp6 - ((fSlow116 * fRec57[1]) + (fConst199 * fRec57[2])));
			fRec57[0] = ((std::fabs(fTempFTZ52) > 1.17549435e-38f) ? fTempFTZ52 : 0.0f);
			float fElse45 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 45)];
			float fTempFTZ53 = (fTemp6 - ((fSlow118 * fRec58[1]) + (fConst203 * fRec58[2])));
			fRec58[0] = ((std::fabs(fTempFTZ53) > 1.17549435e-38f) ? fTempFTZ53 : 0.0f);
			float fElse46 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 46)];
			float fTempFTZ54 = (fTemp6 - ((fSlow120 * fRec59[1]) + (fConst207 * fRec59[2])));
			fRec59[0] = ((std::fabs(fTempFTZ54) > 1.17549435e-38f) ? fTempFTZ54 : 0.0f);
			float fElse47 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 47)];
			float fTempFTZ55 = (fTemp6 - ((fSlow122 * fRec60[1]) + (fConst211 * fRec60[2])));
			fRec60[0] = ((std::fabs(fTempFTZ55) > 1.17549435e-38f) ? fTempFTZ55 : 0.0f);
			float fElse48 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 48)];
			float fTempFTZ56 = (fTemp6 - ((fSlow124 * fRec61[1]) + (fConst215 * fRec61[2])));
			fRec61[0] = ((std::fabs(fTempFTZ56) > 1.17549435e-38f) ? fTempFTZ56 : 0.0f);
			float fElse49 = ftbl0FaustMarimbaDSPSIG0[(iTemp7 + 49)];
			fVec3[0] = (((((((((((((((((((((((((((((((((((((((((((((((((((fRec6[0] - fRec6[2]) * (iSlow26 ? fElse0 : 0.0f)) + ((fRec13[0] - fRec13[2]) * (iSlow29 ? fElse1 : 0.0f))) + ((fRec14[0] - fRec14[2]) * (iSlow31 ? fElse2 : 0.0f))) + ((fRec15[0] - fRec15[2]) * (iSlow33 ? fElse3 : 0.0f))) + ((fRec16[0] - fRec16[2]) * (iSlow35 ? fElse4 : 0.0f))) + ((fRec17[0] - fRec17[2]) * (iSlow37 ? fElse5 : 0.0f))) + ((fRec18[0] - fRec18[2]) * (iSlow39 ? fElse6 : 0.0f))) + ((fRec19[0] - fRec19[2]) * (iSlow41 ? fElse7 : 0.0f))) + ((fRec20[0] - fRec20[2]) * (iSlow43 ? fElse8 : 0.0f))) + ((fRec21[0] - fRec21[2]) * (iSlow45 ? fElse9 : 0.0f))) + ((fRec22[0] - fRec22[2]) * (iSlow47 ? fElse10 : 0.0f))) + ((fRec23[0] - fRec23[2]) * (iSlow49 ? fElse11 : 0.0f))) + ((fRec24[0] - fRec24[2]) * (iSlow51 ? fElse12 : 0.0f))) + ((fRec25[0] - fRec25[2]) * (iSlow53 ? fElse13 : 0.0f))) + ((fRec26[0] - fRec26[2]) * (iSlow55 ? fElse14 : 0.0f))) + ((fRec27[0] - fRec27[2]) * (iSlow57 ? fElse15 : 0.0f))) + ((fRec28[0] - fRec28[2]) * (iSlow59 ? fElse16 : 0.0f))) + ((fRec29[0] - fRec29[2]) * (iSlow61 ? fElse17 : 0.0f))) + ((fRec30[0] - fRec30[2]) * (iSlow63 ? fElse18 : 0.0f))) + ((fRec31[0] - fRec31[2]) * (iSlow65 ? fElse19 : 0.0f))) + ((fRec32[0] - fRec32[2]) * (iSlow67 ? fElse20 : 0.0f))) + ((fRec33[0] - fRec33[2]) * (iSlow69 ? fElse21 : 0.0f))) + ((fRec34[0] - fRec34[2]) * (iSlow71 ? fElse22 : 0.0f))) + ((fRec35[0] - fRec35[2]) * (iSlow73 ? fElse23 : 0.0f))) + ((fRec36[0] - fRec36[2]) * (iSlow75 ? fElse24 : 0.0f))) + ((fRec37[0] - fRec37[2]) * (iSlow77 ? fElse25 : 0.0f))) + ((fRec38[0] - fRec38[2]) * (iSlow79 ? fElse26 : 0.0f))) + ((fRec39[0] - fRec39[2]) * (iSlow81 ? fElse27 : 0.0f))) + ((fRec40[0] - fRec40[2]) * (iSlow83 ? fElse28 : 0.0f))) + ((fRec41[0] - fRec41[2]) * (iSlow85 ? fElse29 : 0.0f))) + ((fRec42[0] - fRec42[2]) * (iSlow87 ? fElse30 : 0.0f))) + ((fRec43[0] - fRec43[2]) * (iSlow89 ? fElse31 : 0.0f))) + ((fRec44[0] - fRec44[2]) * (iSlow91 ? fElse32 : 0.0f))) + ((fRec45[0] - fRec45[2]) * (iSlow93 ? fElse33 : 0.0f))) + ((fRec46[0] - fRec46[2]) * (iSlow95 ? fElse34 : 0.0f))) + ((fRec47[0] - fRec47[2]) * (iSlow97 ? fElse35 : 0.0f))) + ((fRec48[0] - fRec48[2]) * (iSlow99 ? fElse36 : 0.0f))) + ((fRec49[0] - fRec49[2]) * (iSlow101 ? fElse37 : 0.0f))) + ((fRec50[0] - fRec50[2]) * (iSlow103 ? fElse38 : 0.0f))) + ((fRec51[0] - fRec51[2]) * (iSlow105 ? fElse39 : 0.0f))) + ((fRec52[0] - fRec52[2]) * (iSlow107 ? fElse40 : 0.0f))) + ((fRec53[0] - fRec53[2]) * (iSlow109 ? fElse41 : 0.0f))) + ((fRec54[0] - fRec54[2]) * (iSlow111 ? fElse42 : 0.0f))) + ((fRec55[0] - fRec55[2]) * (iSlow113 ? fElse43 : 0.0f))) + ((fRec56[0] - fRec56[2]) * (iSlow115 ? fElse44 : 0.0f))) + ((fRec57[0] - fRec57[2]) * (iSlow117 ? fElse45 : 0.0f))) + ((fRec58[0] - fRec58[2]) * (iSlow119 ? fElse46 : 0.0f))) + ((fRec59[0] - fRec59[2]) * (iSlow121 ? fElse47 : 0.0f))) + ((fRec60[0] - fRec60[2]) * (iSlow123 ? fElse48 : 0.0f))) + ((fRec61[0] - fRec61[2]) * (iSlow125 ? fElse49 : 0.0f)));
			float fTemp8 = ((0.99000001f * fRec5[0]) + (0.0199999996f * fVec3[1]));
			fVec4[(IOTA & 1023)] = fTemp8;
			float fTempFTZ57 = ((fSlow8 * fVec4[((IOTA - iSlow10) & 1023)]) + (fSlow11 * ((((fSlow12 * fVec4[((IOTA - iSlow13) & 1023)]) + (fSlow14 * fVec4[((IOTA - iSlow15) & 1023)])) + (fSlow17 * fVec4[((IOTA - iSlow18) & 1023)])) + (fSlow19 * fVec4[((IOTA - iSlow20) & 1023)]))));
			fRec3[0] = ((std::fabs(fTempFTZ57) > 1.17549435e-38f) ? fTempFTZ57 : 0.0f);
			float fTempFTZ58 = fRec3[0];
			float fTemp9 = ((std::fabs(fTempFTZ58) > 1.17549435e-38f) ? fTempFTZ58 : 0.0f);
			float fRec1 = fTemp9;
			float fTempFTZ59 = fRec1;
			float fTempFTZ60 = (fSlow126 + (fConst13 * fRec62[1]));
			fRec62[0] = ((std::fabs(fTempFTZ60) > 1.17549435e-38f) ? fTempFTZ60 : 0.0f);
			output0[i0] = FAUSTFLOAT((((std::fabs(fTempFTZ59) > 1.17549435e-38f) ? fTempFTZ59 : 0.0f) * fRec62[0]));
			iRec0[1] = iRec0[0];
			fRec4[1] = fRec4[0];
			IOTA = (IOTA + 1);
			fRec2[1] = fRec2[0];
			fRec5[1] = fRec5[0];
			iRec9[1] = iRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec1[1] = fVec1[0];
			iVec2[1] = iVec2[0];
			iRec11[1] = iRec11[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
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
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fVec3[1] = fVec3[0];
			fRec3[1] = fRec3[0];
			fRec62[1] = fRec62[0];
		}
	}

};

#endif
