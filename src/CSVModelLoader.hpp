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

#ifndef CSV_MODEL_LOADER_HPP
#define CSV_MODEL_LOADER_HPP

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

struct VoiceTransition {
    std::string sourcePhoneme;
    std::string targetPhoneme;
    std::map<std::string, float> targetParams; // f1_freq, f1_amp, f1_bw, etc.
    float bez_p1x, bez_p1y, bez_p2x, bez_p2y;
};

class CSVModelLoader {
public:
    static bool loadVoiceMatrix(const std::string& filePath, std::map<std::pair<std::string, std::string>, VoiceTransition>& matrix) {
        std::ifstream file(filePath);
        if (!file.is_open()) return false;

        std::string line, header;
        if (!std::getline(file, header)) return false;

        std::vector<std::string> headers;
        std::stringstream ssHeader(header);
        std::string col;
        while (std::getline(ssHeader, col, ',')) {
            // Trim carriage returns
            if (!col.empty() && col.back() == '\r') col.pop_back();
            headers.push_back(col);
        }

        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '\r') continue;
            std::stringstream ss(line);
            VoiceTransition trans;
            std::string val;

            std::getline(ss, val, ','); trans.sourcePhoneme = val;
            std::getline(ss, val, ','); trans.targetPhoneme = val;

            for (size_t i = 2; i < headers.size(); ++i) {
                if (std::getline(ss, val, ',')) {
                    if (!val.empty() && val.back() == '\r') val.pop_back();
                    if (headers[i] == "bez_p1x") trans.bez_p1x = std::stof(val);
                    else if (headers[i] == "bez_p1y") trans.bez_p1y = std::stof(val);
                    else if (headers[i] == "bez_p2x") trans.bez_p2x = std::stof(val);
                    else if (headers[i] == "bez_p2y") trans.bez_p2y = std::stof(val);
                    else trans.targetParams[headers[i]] = std::stof(val);
                }
            }
            matrix[{trans.sourcePhoneme, trans.targetPhoneme}] = trans;
        }
        return true;
    }
};

#endif // CSV_MODEL_LOADER_HPP
