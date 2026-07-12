import re

with open("test_instruments.cpp", "r") as f:
    content = f.read()

helper = """
static void testPolyphonicChord(FaustInstrument* inst) {
    if (!inst) return;
    std::cout << "\\n  [Polyphony Test] C4 aug7 Chord (C4, E4, G#4, Bb4) ..." << std::endl;
    std::vector<double> chord = { 261.63, 329.63, 415.30, 466.16 };
    inst->clearDiagnosticLogs();
    for (double f : chord) inst->noteOn(f, gTestVelocity, gTestAmplitude);
    usleep(2000000);
    for (double f : chord) inst->noteOff();
    usleep(500000);
    std::cout << "  Polyphony Energy: ";
    printEnergy(inst, 261.63);
    std::cout << std::endl;
}
"""

if "testPolyphonicChord" not in content:
    content = content.replace("static std::vector<float> getTestFreqsFloat", helper + "\nstatic std::vector<float> getTestFreqsFloat")

poly_funcs = ["testPiano", "testAcousticGuitar", "testElectricGuitar", "testBassGuitar", "testMarimba", "testGuzheng", "testSantoor", "testHarmonium"]

for func in poly_funcs:
    # Find the end of the function: mixer.removeTrack(track);\n}
    pattern = r"(void " + func + r"[\s\S]*?)(mixer\.removeTrack\(track\);\s*\})"
    replacement = r"\1testPolyphonicChord(inst.get());\n    \2"
    content = re.sub(pattern, replacement, content)

with open("test_instruments.cpp", "w") as f:
    f.write(content)
