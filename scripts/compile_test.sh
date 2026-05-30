#!/bin/bash
set -e

for dspFile in assets/dsp/*.dsp; do
    basename=$(basename "$dspFile" .dsp)
    # Capitalize first letter for class name
    capName="$(tr '[:lower:]' '[:upper:]' <<< ${basename:0:1})${basename:1}"
    hppFile="src/Faust${capName}DSP.hpp"
    
    if [ "$dspFile" -nt "$hppFile" ]; then
        echo "Faust: Compiling $dspFile to $hppFile..."
        faust -lang cpp -es 1 -single -ftz 0 -I /home/shashankkhare/faust_sdk/faust_src/examples/physicalModeling/faust-stk -cn "Faust${capName}DSP" "$dspFile" -o "$hppFile"
    fi
done

# We must also recompile the object files if headers changed!
cd build
make
cd ..

# Compile the test using the object files from the build directory
# and linking against libfaust.so
g++ -o test/test_orchestrator_new \
    test/test_orchestrator.cpp \
    build/CMakeFiles/faust_min.dir/SequenceOrchestrator.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustMixer.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustInstrument.cpp.o \
    build/CMakeFiles/faust_min.dir/UMLParser.cpp.o \
    build/CMakeFiles/faust_min.dir/UMLSequence.cpp.o \
    build/CMakeFiles/faust_min.dir/InstrumentMapper.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustDayan.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBayan.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustFlute.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustKick.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustSnare.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBell.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBowl.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTibetanbowl.cpp.o \
    -Isrc \
    -I/home/shashankkhare/faust_sdk/faust_src/architecture \
    -L/home/shashankkhare/faust_sdk/lib -lfaust \
    -Wl,-rpath,/home/shashankkhare/faust_sdk/lib \
    -lpthread -ldl -rdynamic -O3 -ffast-math

echo "Compilation successful: test/test_orchestrator_new"

g++ -o test/test_instruments \
    test/test_instruments.cpp \
    build/CMakeFiles/faust_min.dir/FaustMixer.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustInstrument.cpp.o \
    build/CMakeFiles/faust_min.dir/InstrumentMapper.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustDayan.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBayan.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustFlute.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustKick.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustSnare.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBell.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBowl.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTibetanbowl.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustPiano.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTanpura.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustSitar.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustCowbell.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustHiHat.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustRide.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTom.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustSax.cpp.o \
    -Isrc \
    -I/home/shashankkhare/faust_sdk/faust_src/architecture \
    -L/home/shashankkhare/faust_sdk/lib -lfaust \
    -Wl,-rpath,/home/shashankkhare/faust_sdk/lib \
    -lpthread -ldl -rdynamic -O3 -ffast-math

echo "Compilation successful: test/test_instruments"

# Compile test_sequence
g++ -o test/test_sequence \
    test/test_sequence.cpp \
    build/CMakeFiles/faust_min.dir/SequenceOrchestrator.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustMixer.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustInstrument.cpp.o \
    build/CMakeFiles/faust_min.dir/UMLParser.cpp.o \
    build/CMakeFiles/faust_min.dir/UMLSequence.cpp.o \
    build/CMakeFiles/faust_min.dir/InstrumentMapper.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustDayan.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBayan.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustFlute.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustKick.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustSnare.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBell.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBowl.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTibetanbowl.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustPiano.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTanpura.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustSitar.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustCowbell.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustHiHat.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustRide.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTom.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustSax.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustViolin.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustBansuri.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustShakuhachi.cpp.o \
    build/CMakeFiles/faust_min.dir/FaustTrumpet.cpp.o \
    -Isrc \
    -I/home/shashankkhare/faust_sdk/faust_src/architecture \
    -L/home/shashankkhare/faust_sdk/lib -lfaust \
    -Wl,-rpath,/home/shashankkhare/faust_sdk/lib \
    -lpthread -ldl -rdynamic -O3 -ffast-math

echo "Compilation successful: test/test_sequence"

