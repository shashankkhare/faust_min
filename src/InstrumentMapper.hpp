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

class dsp;

class __attribute__((visibility("default"))) InstrumentMapper {
public:
#if defined(__ANDROID__) || defined(__linux__)
    static constexpr float DEFAULT_SAMPLE_RATE = 48000.0f;
#else
    static constexpr float DEFAULT_SAMPLE_RATE = 44100.0f;
#endif

    static constexpr const char* DEFAULT_DSP_DIR = "./assets/dsp/";
    static constexpr const char* DEFAULT_LIB_DIR = "./assets/libraries";

    // Maximum simultaneous instruments the parallel engine supports
    static constexpr int MAX_INSTRUMENTS = 20;
    // Pre-allocated scratch buffer size per instrument — never reallocated at runtime
    static constexpr int MAX_FRAMES_PER_BUFFER = 8192;

    // Resolves target patch identifier string from concrete integer ID
    static std::string getNameFromID(int id);

    // Resolves definitive numeric integer ID from short layout code or full patch name
    static int getIDFromName(const std::string& name);

    // Determines if the given numeric patch ID belongs to an unpitched/percussion domain model
    static bool isPercussionID(int id);

    // Resolves absolute/relative target source file URI based on numeric ID
    static std::string getDSPPathForID(int id, const std::string& assetBasePath = "");

};

#endif // INSTRUMENT_MAPPER_HPP
