#ifndef FAUST_TIBETANBOWL_HPP
#define FAUST_TIBETANBOWL_HPP

#include "FaustInstrument.hpp"

class FaustTibetanbowl : public FaustInstrument {
public:
    FaustTibetanbowl(float sampleRate);
    void strike(float velocity);
    int getID() const override { return 47; }
};

#endif
