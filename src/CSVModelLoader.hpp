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
