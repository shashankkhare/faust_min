#!/bin/bash
# Iteratively tune NAF parameters and check energy levels
# Usage: ./tune_naf.sh [freq]

FREQ=${1:-440}
BUILD_DIR="/home/shashankkhare/AndroidStudioProjects/faust_min/build"
DSP_FILE="/home/shashankkhare/AndroidStudioProjects/faust_min/assets/dsp/nativeamericanflute.dsp"
TEST_BIN="$BUILD_DIR/test_instruments"

echo "NAF Tuning Loop"
echo "  Freq: $FREQ Hz"
echo "  Edit $DSP_FILE, then press ENTER to rebuild/test"
echo "  Type 'quit' to exit"
echo ""

while true; do
    read -p "> " cmd
    if [ "$cmd" = "quit" ]; then break; fi

    # Build
    make -j$(nproc) -C "$BUILD_DIR" 2>&1 | tail -5
    if [ $? -ne 0 ]; then
        echo "BUILD FAILED"
        continue
    fi

    # Test at multiple freqs
    for f in 110 220 440 880; do
        output=$("$TEST_BIN" 52 f=$f 2>/dev/null | grep "^$f,")
        echo "$output"
    done
done
