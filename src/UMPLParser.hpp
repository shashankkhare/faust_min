#ifndef UMPL_PARSER_HPP
#define UMPL_PARSER_HPP

#include <string>
#include <vector>
#include <map>

enum class EventType {
    NoteOn,
    NoteOff,
    ParamChange
};

struct SequenceEvent {
    long sampleOffset;
    EventType type;
    int instrumentId;
    float value;
    long durationSamples;
    bool legato;
};

class UMPLSequence {
public:
    std::string name;
    std::vector<SequenceEvent> events;
    double bpm;
    double baseFreq;
    long totalDurationSamples;

    UMPLSequence() : bpm(120.0), baseFreq(261.63), totalDurationSamples(0) {}
};

class UMPLParser {
public:
    static UMPLSequence parse(const std::string& name, const std::string& input, double sampleRate);

private:
    static double evaluateExpression(const std::string& expr);
    static double getRatio(const std::string& note);
    static const std::map<std::string, double> ratios;
};

#endif // UMPL_PARSER_HPP
