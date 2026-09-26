#!/usr/bin/env bash
set -euo pipefail

# verify.sh — Pre-release memory & CPU sanity check for faust_min
# Called from publish.md step 1 (Pre-Release). Exits non-zero on failure.
#
# CPU budget: at most 0.5 core per instrument (ideal ≤ 0.3).
#   On a 6-core system: 12 instruments minimum, 20 ideal.
# Memory budget: peak RSS ≤ 512 MB, growth ≤ 100 MB.

BUILD_DIR="${1:-build-release}"
RESULTS_DIR="${BUILD_DIR}/verify-results"
mkdir -p "$RESULTS_DIR"

echo "=== faust_min verify: build=$BUILD_DIR ==="

# ---- 1. Build (if needed) ----
# CMake emits binaries into $BUILD_DIR/shared/ (see src/CMakeLists.txt RUNTIME_OUTPUT_DIRECTORY).
if [ ! -f "$BUILD_DIR/shared/test_sequence" ] && [ ! -f "$BUILD_DIR/test_sequence" ]; then
    echo "[verify] Building Release targets..."
    cmake -S src -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release
    cmake --build "$BUILD_DIR" -j"$(nproc)" --target test_sequence
fi

if [ -f "$BUILD_DIR/shared/test_sequence" ]; then
    TEST_SEQ="$BUILD_DIR/shared/test_sequence"
else
    TEST_SEQ="$BUILD_DIR/test_sequence"
fi
export LD_LIBRARY_PATH="$BUILD_DIR/shared:${LD_LIBRARY_PATH:-}"

# ---- 2. Check no debug flags leak into release code ----
echo ""
echo "[verify] Checking debug flags in source..."
# Every DEBUG_* switch must be #define'd to 0. Guarded uses (#if DEBUG_X) are fine.
DEBUG_ON=$(grep -rnE "^[[:space:]]*#define[[:space:]]+DEBUG_[A-Z_]+[[:space:]]+[^0]" src/ --include="*.cpp" --include="*.hpp" || true)
if [ -n "$DEBUG_ON" ]; then
    echo "FAIL: Debug switches not set to 0:"
    echo "$DEBUG_ON"
    exit 1
fi
grep -rnE "^[[:space:]]*#define[[:space:]]+DEBUG_[A-Z_]+" src/ --include="*.cpp" --include="*.hpp" | sed 's/^/[verify] /'

# ---- 3. Run test_sequence with timeout ----
# Sequence 2 (Jazz Ensemble): Piano, Sax, Bass, Kick, Snare, Ride = 6 inst
SEQ_ID=2
NUM_INST=6
PLAY_SEC=8

echo ""
echo "[verify] Running: $TEST_SEQ -t $PLAY_SEC -s $SEQ_ID"

OUT_LOG="$RESULTS_DIR/output.log"
"$TEST_SEQ" -t "$PLAY_SEC" -s "$SEQ_ID" > "$OUT_LOG" 2>&1

# ---- 4. Parse [PERF] line ----
PERF=$(grep "^\[PERF\]" "$OUT_LOG" || true)
if [ -z "$PERF" ]; then
    echo "FAIL: No [PERF] line in output"
    cat "$OUT_LOG"
    exit 1
fi
echo "[verify] $PERF"

# Extract fields: wall=4s cpu=591% rss=48MB rss_delta=0MB seqs=6
WALL_SEC=$(echo "$PERF" | grep -oP 'wall=\K\d+')
CPU_PCT=$(echo "$PERF" | grep -oP 'cpu=\K\d+')
RSS_MB=$(echo "$PERF" | grep -oP 'rss=\K\d+')
RSS_DELTA_MB=$(echo "$PERF" | grep -oP 'rss_delta=\K\d+')
SEQS=$(echo "$PERF" | grep -oP 'seqs=\K\d+')

# ---- 5. Check for crashes ----
echo ""
echo "[verify] Checking output for errors..."
if grep -qi "SEGV\|SIGABRT\|SIGSEGV\|assertion\|FATAL\|CRASH\|std::bad_alloc" "$OUT_LOG" 2>/dev/null; then
    echo "FAIL: Crash detected"
    grep -n "SEGV\|SIGABRT\|SIGSEGV\|assertion\|FATAL\|CRASH\|bad_alloc" "$OUT_LOG"
    exit 1
fi
echo "[verify] No crashes detected."

# ---- 6. Thresholds ----
MAX_RSS_MB=512
MAX_RSS_DELTA_MB=100
MAX_CPU_PCT_PER_INST=50
IDEAL_CPU_PCT_PER_INST=30

NCPU=$(nproc)
CPU_PER_INST=$(echo "scale=1; $CPU_PCT / $SEQS" | bc)
INST_LIMIT=$(echo "scale=0; $NCPU * 100 / $MAX_CPU_PCT_PER_INST" | bc)
INST_IDEAL=$(echo "scale=0; $NCPU * 100 / $IDEAL_CPU_PCT_PER_INST" | bc)

echo ""
echo "[verify] Budget check:"
echo "  System cores: $NCPU"
echo "  Min instruments supported (≤50%/inst): $INST_LIMIT"
echo "  Ideal instruments supported (≤30%/inst): $INST_IDEAL"
echo "  This test: ${SEQS} inst @ ${CPU_PER_INST}%/inst (total ${CPU_PCT}%)"
echo ""

# Memory
if [ "$RSS_MB" -gt "$MAX_RSS_MB" ]; then
    echo "FAIL: RSS ${RSS_MB}MB exceeds ${MAX_RSS_MB}MB limit"
    exit 1
fi

if [ "$RSS_DELTA_MB" -gt "$MAX_RSS_DELTA_MB" ]; then
    echo "WARN: RSS grew by ${RSS_DELTA_MB}MB (limit ${MAX_RSS_DELTA_MB}MB) — possible leak"
fi

# CPU
if [ "$(echo "$CPU_PER_INST > $MAX_CPU_PCT_PER_INST" | bc)" -eq 1 ]; then
    echo "FAIL: ${CPU_PER_INST}% CPU per instrument exceeds ${MAX_CPU_PCT_PER_INST}% limit"
    echo "  At this rate only $(echo "scale=0; $NCPU * 100 / $CPU_PCT" | bc) instruments fit on ${NCPU} cores"
    exit 1
fi

if [ "$(echo "$CPU_PER_INST > $IDEAL_CPU_PCT_PER_INST" | bc)" -eq 1 ]; then
    echo "WARN: ${CPU_PER_INST}% CPU per instrument exceeds ideal ${IDEAL_CPU_PCT_PER_INST}%"
fi

echo ""
echo "=== verify: PASSED ==="
