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

struct ModelPoint {
    float note;
    float velocity;
    std::map<std::string, float> params;
};

class CSVModelLoader {
public:
    static bool load(const std::string& filePath, std::vector<ModelPoint>& points, std::vector<std::string>& paramNames) {
        std::ifstream file(filePath);
        if (!file.is_open()) return false;

        std::string line, header;
        if (!std::getline(file, header)) return false;

        // Parse Header
        std::stringstream ssHeader(header);
        std::string col;
        std::getline(ssHeader, col, ','); // note
        std::getline(ssHeader, col, ','); // velocity
        while (std::getline(ssHeader, col, ',')) {
            paramNames.push_back(col);
        }

        // Parse Data
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            ModelPoint p;
            std::string val;
            
            std::getline(ss, val, ','); p.note = std::stof(val);
            std::getline(ss, val, ','); p.velocity = std::stof(val);
            
            for (const auto& name : paramNames) {
                if (std::getline(ss, val, ',')) {
                    p.params[name] = std::stof(val);
                }
            }
            points.push_back(p);
        }
        return true;
    }

    static void interpolate(const std::vector<ModelPoint>& points, float targetNote, float targetVel, std::map<std::string, float>& results) {
        // Simple nearest neighbor or linear interpolation placeholder
        // For performance, points should be sorted by note/velocity
        if (points.empty()) return;

        const ModelPoint* best = &points[0];
        float minDist = 1000000.0f;

        for (const auto& p : points) {
            float d = std::abs(p.note - targetNote) + std::abs(p.velocity - targetVel) * 0.1f;
            if (d < minDist) {
                minDist = d;
                best = &p;
            }
        }
        results = best->params;
    }
};

#endif // CSV_MODEL_LOADER_HPP
