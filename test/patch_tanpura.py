import re

with open("test_instruments.cpp", "r") as f:
    content = f.read()

pattern = r"(void testTanpura\(FaustMixer& mixer, DSPExecutionType execType\) \{[\s\S]*?)(    // Fire all three notes sequentially)"
replacement = r"""\1    std::vector<double> freqs = getTestFreqsDouble(inst.get(), { 130.00, 180.50, 231.00 });
    for (double freq : freqs) {
        inst->clearDiagnosticLogs();
        inst->noteOn(freq, gTestVelocity, gTestAmplitude);
        usleep(2000000);
        inst->noteOff();
        usleep(300000);
        printEnergy(inst.get(), freq);
        if (&freq != &freqs.back()) std::cout << " , ";
        std::cout << std::flush;
    }
    std::cout << std::endl;

\2"""

content = re.sub(pattern, replacement, content)

with open("test_instruments.cpp", "w") as f:
    f.write(content)

