import re

with open('test/test_instruments.cpp', 'r') as f:
    content = f.read()

# For arrays
content = re.sub(r'std::vector<double>\s+freqs\s*=\s*\{\s*([0-9.,\s]+)\s*\};', 
                 r'std::vector<double> freqs = getTestFreqsDouble({ \1 });', content)
content = re.sub(r'std::vector<double>\s+notes\s*=\s*\{\s*([0-9.,\s]+)\s*\};', 
                 r'std::vector<double> notes = getTestFreqsDouble({ \1 });', content)
content = re.sub(r'std::vector<float>\s+freqs\s*=\s*\{\s*([0-9.f,\s]+)\s*\};', 
                 r'std::vector<float> freqs = getTestFreqsFloat({ \1 });', content)

# Fix duplicate applications just in case
content = content.replace('getTestFreqsDouble(getTestFreqsDouble(', 'getTestFreqsDouble(').replace('})})', '})')
content = content.replace('getTestFreqsFloat(getTestFreqsFloat(', 'getTestFreqsFloat(').replace('})})', '})')

# For noteOn calls with 0.8f hardcoded velocity, e.g. inst->noteOn(freq, 0.8f) -> inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude)
content = re.sub(r'inst->noteOn\(([^,]+),\s*0\.8f\);', r'inst->noteOn(\1, gTestVelocity, -1.0f, gTestAmplitude);', content)

# For noteOn calls with strike, e.g. inst->noteOn(freq, 0.8f, strike) -> inst->noteOn(freq, gTestVelocity, strike, gTestAmplitude)
content = re.sub(r'inst->noteOn\(([^,]+),\s*0\.8f,\s*([^,]+)\);', r'inst->noteOn(\1, gTestVelocity, \2, gTestAmplitude);', content)

# For noteOn calls with 0.0f, 0.7f, 1.0f -> inst->noteOn(0.0f, gTestVelocity, 1.0f, gTestAmplitude)
content = re.sub(r'inst->noteOn\(([^,]+),\s*0\.[78]f,\s*([^\)]+)\);', r'inst->noteOn(\1, gTestVelocity, \2, gTestAmplitude);', content)

# For noteOn calls with -1.0f, gTestVelocity, -1.0f, gTestAmplitude
# It's already mostly fine if it has gTestVelocity. But if it doesn't have gTestAmplitude:
# There's inst->noteOn(freq, gTestVelocity >= 0.0f ? gTestVelocity : 0.8f)
content = content.replace('inst->noteOn(freq, gTestVelocity >= 0.0f ? gTestVelocity : 0.8f);', 'inst->noteOn(freq, gTestVelocity, -1.0f, gTestAmplitude);')

# Fix direct testChouGong that had noteOn(testFreq, gTestVelocity, -1.0f, gTestAmplitude) -- already fine.

with open('test/test_instruments.cpp', 'w') as f:
    f.write(content)

