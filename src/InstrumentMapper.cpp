#include "InstrumentMapper.hpp"
#include "FaustDayanDSP.hpp"
#include "FaustBayanDSP.hpp"
#include "FaustKickDSP.hpp"
#include "FaustSnareDSP.hpp"
#include "FaustHihatDSP.hpp"
#include "FaustTomDSP.hpp"
#include "FaustRideDSP.hpp"
#include "FaustBellDSP.hpp"
#include "FaustBowlDSP.hpp"
#include "FaustSitarDSP.hpp"
#include "FaustFluteDSP.hpp"
#include "FaustTanpuraDSP.hpp"
#include "FaustPianoDSP.hpp"
#include "FaustSaxDSP.hpp"
#include <faust/dsp/dsp.h>
#include <algorithm>

std::string InstrumentMapper::getNameFromID(int id) {
    switch (id) {
        case 0:  return "DA";
        case 1:  return "BA";
        case 2:  return "kick";
        case 3:  return "snare";
        case 4:  return "hihat";
        case 5:  return "tom";
        case 6:  return "ride";
        case 7:  return "BE";
        case 8:  return "BO";
        case 9:  return "SI";
        case 10: return "FL";
        case 11: return "TA";
        case 12: return "PI";
        case 13: return "SX";
        default: return "DA";
    }
}

int InstrumentMapper::getIDFromName(const std::string& name) {
    if (name.empty()) return -1;
    
    // Support direct numeric string checks
    if (std::all_of(name.begin(), name.end(), ::isdigit)) {
        return std::stoi(name);
    }

    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    if (lowerName == "da" || lowerName == "dayan") return 0;
    if (lowerName == "ba" || lowerName == "bayan") return 1;
    if (lowerName == "kick") return 2;
    if (lowerName == "snare") return 3;
    if (lowerName == "hihat") return 4;
    if (lowerName == "tom") return 5;
    if (lowerName == "ride") return 6;
    if (lowerName == "be" || lowerName == "bell") return 7;
    if (lowerName == "bo" || lowerName == "bowl") return 8;
    if (lowerName == "si" || lowerName == "sitar") return 9;
    if (lowerName == "fl" || lowerName == "flute") return 10;
    if (lowerName == "ta" || lowerName == "tanpura") return 11;
    if (lowerName == "pi" || lowerName == "piano") return 12;
    if (lowerName == "sx" || lowerName == "sax") return 13;

    return -1;
}

std::string InstrumentMapper::getDSPPathForID(int id, const std::string& assetBasePath) {
    std::string base = assetBasePath.empty() ? "./assets/dsp/" : (assetBasePath + "/dsp/");
    switch (id) {
        case 0:  return base + "dayan.dsp";
        case 1:  return base + "bayan.dsp";
        case 2:  return base + "kick.dsp";
        case 3:  return base + "snare.dsp";
        case 4:  return base + "hihat.dsp";
        case 5:  return base + "tom.dsp";
        case 6:  return base + "ride.dsp";
        case 7:  return base + "bell.dsp";
        case 8:  return base + "bowl.dsp";
        case 9:  return base + "sitar.dsp";
        case 10: return base + "flute.dsp";
        case 11: return base + "tanpura.dsp";
        case 12: return base + "piano.dsp";
        case 13: return base + "sax.dsp";
        default: return base + "dayan.dsp";
    }
}

dsp* InstrumentMapper::createStaticDSPForID(int id) {
    switch (id) {
        case 0:  return new FaustDayanDSP();
        case 1:  return new FaustBayanDSP();
        case 2:  return new FaustKickDSP();
        case 3:  return new FaustSnareDSP();
        case 4:  return new FaustHihatDSP();
        case 5:  return new FaustTomDSP();
        case 6:  return new FaustRideDSP();
        case 7:  return new FaustBellDSP();
        case 8:  return new FaustBowlDSP();
        case 9:  return new FaustSitarDSP();
        case 10: return new FaustFluteDSP();
        case 11: return new FaustTanpuraDSP();
        case 12: return new FaustPianoDSP();
        case 13: return new FaustSaxDSP();
        default: return new FaustDayanDSP();
    }
}
