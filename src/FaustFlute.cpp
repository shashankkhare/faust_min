#include "FaustFlute.hpp"
#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

FaustFlute::FaustFlute(float sampleRate) 
    : mSampleRate(sampleRate), mFreq(440.0f), mPressure(0.0f), 
      mVibratoRate(5.0f), mVibratoDepth(0.0f), mPhase(0.0f),
      mBoreWriteIdx(0), mJetWriteIdx(0), mFilterState(0.0f), 
      mDCState(0.0f), mPrevIn(0.0f),
      mBoreAP_X1(0.0f), mBoreAP_Y1(0.0f),
      mJetAP_X1(0.0f), mJetAP_Y1(0.0f) {
    
    // Initialize delay lines
    size_t size = (size_t)(sampleRate / 20.0f) + 2;
    mBoreDelay.assign(size, 0.0f);
    mJetDelay.assign(size / 2, 0.0f); // Jet is typically smaller
    
    mPRNG.seed(42); // Consistent seed for initialization
    mDist = std::uniform_real_distribution<float>(-1.0f, 1.0f);
    
    setFrequency(440.0f);
}

FaustFlute::~FaustFlute() {}

void FaustFlute::setFrequency(float freq) {
    mFreq = std::max(freq, 20.0f);
}

void FaustFlute::setPressure(float pressure) {
    // Michon models are sensitive; clamp to safe range
    mPressure = std::max(0.0f, std::min(1.0f, pressure));
}

void FaustFlute::setVibrato(float rate, float depth) {
    mVibratoRate = rate;
    mVibratoDepth = depth;
}

float FaustFlute::tick() {
    float boreLength = mSampleRate / mFreq;
    // Jet length is typically a fraction $(0.3-0.5)$ of the bore
    // For low register stability (C3/C4), we use a slightly longer jet
    float jetLength = boreLength * 0.45f;

    // 1. Vibrato & Breath Noise
    mPhase += 2.0f * (float)M_PI * mVibratoRate / mSampleRate;
    if (mPhase > 2.0f * (float)M_PI) mPhase -= 2.0f * (float)M_PI;
    float vibrato = sinf(mPhase) * mVibratoDepth;
    // INCREASED: Adjusted from 0.005f to 0.01f to bring back a touch of breath character
    float noise = mDist(mPRNG) * 0.01f * mPressure;
    float currentPressure = mPressure + vibrato + noise;

    // 2. Fractional Delay Read (Bore)
    // We use All-pass fractional delay for perfect phase at low frequencies
    float boreReadPos = (float)mBoreWriteIdx - boreLength;
    while (boreReadPos < 0) boreReadPos += (float)mBoreDelay.size();
    int b1 = (int)boreReadPos;
    float deltaB = boreReadPos - b1;
    float alphaB = (1.0f - deltaB) / (1.0f + deltaB);
    float boreIn = mBoreDelay[b1];
    float boreOut = alphaB * boreIn + mBoreAP_X1 - alphaB * mBoreAP_Y1;
    mBoreAP_X1 = boreIn; mBoreAP_Y1 = boreOut;

    // 3. Jet Nonlinearity (The Michon Jet Interaction)
    float jetIn = currentPressure - boreOut;
    // Strict clamp to stable cubic region
    if (jetIn > 1.0f) jetIn = 1.0f;
    if (jetIn < -1.0f) jetIn = -1.0f;
    float jetCubic = jetIn - (jetIn * jetIn * jetIn);

    // 4. Fractional Delay Read (Jet)
    float jetReadPos = (float)mJetWriteIdx - jetLength;
    while (jetReadPos < 0) jetReadPos += (float)mJetDelay.size();
    int j1 = (int)jetReadPos;
    float deltaJ = jetReadPos - j1;
    float alphaJ = (1.0f - deltaJ) / (1.0f + deltaJ);
    float jetSampIn = mJetDelay[j1];
    float jetOut = alphaJ * jetSampIn + mJetAP_X1 - alphaJ * mJetAP_Y1;
    mJetAP_X1 = jetSampIn; mJetAP_Y1 = jetOut;

    // 5. Update Jet Delay
    mJetDelay[mJetWriteIdx] = jetCubic;
    mJetWriteIdx = (mJetWriteIdx + 1) % mJetDelay.size();

    // 6. Bore Reflection Filter (Damping)
    mFilterState = 0.85f * mFilterState + 0.15f * jetOut;
    float reflection = -mFilterState; // Phase inversion at open end

    // 7. DC Blocker
    float dcBlockOut = reflection - mPrevIn + 0.995f * mDCState;
    mPrevIn = reflection;
    mDCState = dcBlockOut;

    // 8. Update Bore Delay
    mBoreDelay[mBoreWriteIdx] = dcBlockOut;
    mBoreWriteIdx = (mBoreWriteIdx + 1) % mBoreDelay.size();

    return dcBlockOut * 0.4f;
}

void FaustFlute::render(int numFrames, float* buffer) {
    for (int i = 0; i < numFrames; ++i) {
        buffer[i] = tick();
    }
}
