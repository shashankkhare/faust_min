#include "FaustFlute.hpp"
#include <algorithm>
#include <cmath>
#include <cstdio>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static int gLogCounter = 0;

FaustFlute::FaustFlute(float sampleRate) 
    : mSampleRate(sampleRate), mFreq(440.0f), mPressure(0.0f), 
      mVibratoRate(5.5f), mVibratoDepth(0.015f), mPhase(0.0f),
      mWriteIdxB(0), mWriteIdxJ(0), mFilterState(0.0f), 
      mDCState(0.0f), mBoreOut(0.0f),
      mBoreAP_X1(0.0f), mBoreAP_Y1(0.0f),
      mJetAP_X1(0.0f), mJetAP_Y1(0.0f) {
    
    if (!std::isfinite(mSampleRate) || mSampleRate <= 0.0f) mSampleRate = 44100.0f;

    // Allocate delay lines (enough for 20Hz)
    size_t size = (size_t)(mSampleRate / 20.0f) + 100;
    mBoreDelay.assign(size, 0.0f);
    mJetDelay.assign(size, 0.0f);
    
    mPRNG.seed(std::random_device{}());
    mDist = std::uniform_real_distribution<float>(-1.0f, 1.0f);
    
    reset();
    
    printf("FaustFlute: Physical Model Initialized (SR=%.1f)\n", mSampleRate);
    fflush(stdout);
}

FaustFlute::~FaustFlute() {}

void FaustFlute::setFrequency(float freq) {
    if (std::isfinite(freq)) {
        mFreq = std::max(freq, 20.0f);
    }
}

void FaustFlute::setPressure(float pressure) {
    mPressure = std::isfinite(pressure) ? std::max(0.0f, std::min(1.0f, pressure)) : 0.0f;
}

void FaustFlute::setVibrato(float rate, float depth) {
    if (std::isfinite(rate)) mVibratoRate = rate;
    if (std::isfinite(depth)) mVibratoDepth = depth;
}

void FaustFlute::reset() {
    std::fill(mBoreDelay.begin(), mBoreDelay.end(), 0.0f);
    std::fill(mJetDelay.begin(), mJetDelay.end(), 0.0f);
    mFilterState = 0.0f;
    mDCState = 0.0f;
    mBoreOut = 0.0f;
    mWriteIdxB = 0;
    mWriteIdxJ = 0;
    mPhase = 0.0f;
    mBoreAP_X1 = 0.0f;
    mBoreAP_Y1 = 0.0f;
    mJetAP_X1 = 0.0f;
    mJetAP_Y1 = 0.0f;
}

float FaustFlute::tick(float currentPressure) {
    if (currentPressure < 0.001f) return 0.0f; 

    // --- STEP 1: Excitation ---
    float jetOffset = 0.05f; // Reduced offset for stability
    
    mPhase += 2.0f * (float)M_PI * mVibratoRate / mSampleRate;
    if (mPhase > 2.0f * (float)M_PI) mPhase -= 2.0f * (float)M_PI;
    float vibrato = sinf(mPhase) * mVibratoDepth;
    
    float noise = mDist(mPRNG) * currentPressure; 
    float noiseGain = 0.012f; 
    float flow = currentPressure + (noise * noiseGain) + vibrato;

    // --- STEP 2: Delay Length Calculation ---
    float period = mSampleRate / mFreq;
    // Bounded delay lengths to prevent ultra-short feedback loops
    float embouchureDelayLen = std::max(2.0f, period * 0.5f - 1.0f);
    float boreDelayLen = std::max(2.0f, period - 1.0f);

    // --- STEP 3: The Scattering Junction ---
    float feedback = mBoreOut; 
    
    float jetRefl = 0.5f; 
    float endRefl = -0.75f; // Increased damping for stability

    // --- STEP 4: Bounded Jet Non-linearity ---
    float embouchureIn = flow - (feedback * jetRefl) + jetOffset;
    
    // Strict Input Clamping
    embouchureIn = std::max(-1.0f, std::min(1.0f, embouchureIn));
    
    mJetDelay[mWriteIdxJ] = embouchureIn;
    
    float jetReadPos = (float)mWriteIdxJ - embouchureDelayLen;
    while (jetReadPos < 0) jetReadPos += (float)mJetDelay.size();
    int j1 = (int)jetReadPos % mJetDelay.size();
    int j2 = (j1 + 1) % mJetDelay.size();
    float fJ = jetReadPos - (int)jetReadPos;
    float jetOut = mJetDelay[j1] * (1.0f - fJ) + mJetDelay[j2] * fJ;
    mWriteIdxJ = (mWriteIdxJ + 1) % mJetDelay.size();

    // Cubic Jet Table with hard output clamping
    float jetTableOut = (jetOut * jetOut * jetOut) - jetOut;
    float polyOut = std::max(-0.8f, std::min(0.8f, jetTableOut));

    // --- STEP 5: Reflection Filter ---
    float filterIn = polyOut + (feedback * endRefl);
    float lpCoef = 0.3f; // Stronger high-frequency damping
    mFilterState = (filterIn * lpCoef) + (mFilterState * (1.0f - lpCoef));
    
    // Safety clamp on filter state
    mFilterState = std::max(-1.0f, std::min(1.0f, mFilterState));
    float filteredOut = mFilterState;

    // --- STEP 6: Bore Delay ---
    mBoreDelay[mWriteIdxB] = filteredOut;
    
    float boreReadPos = (float)mWriteIdxB - boreDelayLen;
    while (boreReadPos < 0) boreReadPos += (float)mBoreDelay.size();
    int b1 = (int)boreReadPos % mBoreDelay.size();
    int b2 = (b1 + 1) % mBoreDelay.size();
    float fB = boreReadPos - (int)boreReadPos;
    float boreOutRaw = mBoreDelay[b1] * (1.0f - fB) + mBoreDelay[b2] * fB;
    mWriteIdxB = (mWriteIdxB + 1) % mBoreDelay.size();

    mBoreOut = boreOutRaw;

    // --- STEP 7: DC Blocking & Output ---
    mDCState = 0.995f * mDCState + 0.005f * mBoreOut;
    float out = mBoreOut - mDCState;

    // --- AUTO-RESET ON EXPLOSION ---
    if (!std::isfinite(out)) {
        reset();
        return 0.0f;
    }

    return out * 0.5f; 
}

void FaustFlute::render(int numFrames, float* buffer) {
    // REMOVED EAGER STATE CLEARANCE to allow sustain across chunks
    
    // Smoothly ramp pressure only if it's the start of a block and we were at 0
    // Actually, the sequencer handles envelopes, but a small 10ms ramp helps
    // if the user is just triggering notes.
    
    for (int i = 0; i < numFrames; ++i) {
        buffer[i] = tick(mPressure);
    }
    
    // REMOVED per-chunk normalization to prevent gain jumping
}
