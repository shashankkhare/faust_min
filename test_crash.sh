#!/bin/bash
cd build
echo -e "32\n\n\n" | ./test_instruments > crash_log.txt 2>&1
echo "Exit code: $?"
tail -n 10 crash_log.txt
