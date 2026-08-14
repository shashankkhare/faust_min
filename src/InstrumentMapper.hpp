/*
 * Copyright (c) 2026 Shashank Khare
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef INSTRUMENT_MAPPER_HPP
#define INSTRUMENT_MAPPER_HPP

#include <string>
#include "PlatformCompat.hpp"

class dsp;

class FAUST_API InstrumentMapper {
public:
    static constexpr float DEFAULT_SAMPLE_RATE = 48000.0f;

    static constexpr const char* DEFAULT_DSP_DIR = "./assets/dsp/";
    static constexpr const char* DEFAULT_LIB_DIR = "./assets/libraries";

    // Maximum simultaneous instruments the parallel engine supports
    static constexpr int MAX_INSTRUMENTS = 299;
    // Pre-allocated scratch buffer size per instrument — never reallocated at runtime
    static constexpr int MAX_FRAMES_PER_BUFFER = 8192;

    // Resolves target patch identifier string from concrete integer ID
    static std::string getNameFromID(int id);

    // Resolves definitive numeric integer ID from short layout code or full patch name
    static int getIDFromName(const std::string& name);

    // Determines if the given numeric patch ID belongs to an unpitched/percussion domain model
    static bool isPercussionID(int id);

    // Returns true for membrane-based percussion (drums with skin heads)
    static bool isMembraneophone(int id);

    // Returns true for solid-body percussion (bells, bowls, gongs, shakers)
    static bool isIdiophone(int id);

    // Retrieves the number of polyphonic voices supported by a given instrument ID
    static int getPolyphonyVoices(int id);

    // Returns the broad instrument class (e.g. "Melody", "Percussion", "Ambience")
    static std::string getInstrumentClass(int id);

    // Returns the geographical origin/category (e.g. "Indian", "Western", "Chinese", "Arabic")
    static std::string getInstrumentOrigin(int id);

    // Global static asset base path set by Flutter / FFI layer
    static void setAssetBasePath(const std::string& path);
    static std::string getAssetBasePath();

    // Resolves absolute/relative target source file URI based on numeric ID
    static std::string getDSPPathForID(int id, const std::string& assetBasePath = "");

    // Returns true for instruments where note-off should be suppressed between
    // consecutive strikes (drone/polyphonic instruments like tanpura, sarod)
    static bool isPolyphonic(int id);

    // Returns true for sustained monophonic instruments (flute, violin, bansuri)
    // where notes should connect legato without re-articulating the gate.
    static bool isLegato(int id);

    // Returns the start offset (seconds) for energy measurement, skipping the attack transient
    static float getMeasureStart(int id);

    // Returns the measurement duration (seconds) for energy measurement
    static float getMeasureDuration(int id);

};

#endif // INSTRUMENT_MAPPER_HPP
