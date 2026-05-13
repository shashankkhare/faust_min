#ifndef INSTRUMENT_MAPPER_HPP
#define INSTRUMENT_MAPPER_HPP

#include <string>

class dsp;

class __attribute__((visibility("default"))) InstrumentMapper {
public:
    // Resolves target patch identifier string from concrete integer ID
    static std::string getNameFromID(int id);

    // Resolves definitive numeric integer ID from short layout code or full patch name
    static int getIDFromName(const std::string& name);

    // Resolves absolute/relative target source file URI based on numeric ID
    static std::string getDSPPathForID(int id, const std::string& assetBasePath);

    // Acts as central static factory instantiating concrete auto-generated C++ DSP classes
    static dsp* createStaticDSPForID(int id);
};

#endif // INSTRUMENT_MAPPER_HPP
