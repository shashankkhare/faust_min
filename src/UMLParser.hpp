#ifndef UML_PARSER_HPP
#define UML_PARSER_HPP

#include <string>
#include <vector>
#include <map>

enum class UMLEventType {
    NoteOn,
    NoteOff,
    Glide
};

struct UMLEvent {
    long sampleOffset;
    UMLEventType type;
    float frequency;
    float velocity;
    std::string note;
    long durationSamples; // For glides
    float targetFrequency; // For glides
    float targetVelocity;  // For glides
};

class UMLSequence {
public:
    std::string name;
    std::string instrument;
    std::map<std::string, float> initialParams;
    std::vector<UMLEvent> events;
    double bpm;
    double baseFreq;
    double gain;
    long totalDurationSamples;
    std::string notation;

    UMLSequence() : bpm(120.0), baseFreq(261.63), gain(1.0), totalDurationSamples(0), notation("Indian") {}
};

class UMLParser {
public:
    static UMLSequence parse(const std::string& name, const std::string& input, double sampleRate);

private:
    static double getFrequency(const std::string& token, const std::string& notation, double baseFreq, const std::string& instrument);
    static const std::map<std::string, double> indianRatios;
    static const std::map<std::string, double> westernPitches;
    static const std::map<std::string, double> percussionBols;
};

#endif // UML_PARSER_HPP
