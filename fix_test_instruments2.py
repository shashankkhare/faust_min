import re

lines = []
with open('test/test_instruments.cpp', 'r') as f:
    for line in f:
        line = line.replace(', ,', ', -1.0f,')
        line = line.replace('mixer.removeTrack(track, gTestAmplitude);', 'mixer.removeTrack(track);')
        lines.append(line)

with open('test/test_instruments.cpp', 'w') as f:
    f.writelines(lines)

