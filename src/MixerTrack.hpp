#ifndef MIXER_TRACK_HPP
#define MIXER_TRACK_HPP

#include <vector>
#include <string>
#include <atomic>
#include <memory>
#include <algorithm>
#include <cstdio>
#include "FaustInstrument.hpp"
#include "FaustTrackFxDSP.hpp"

struct EnvelopePoint {
    float timeSec;
    float value;
    uint8_t interpType;
};

// I/O constants used by MixerTrack and FaustMixer.
static constexpr size_t FM_IO_CHUNK_FRAMES         = 4096;
static constexpr size_t FM_IO_RING_CAPACITY_FRAMES  = 96000;
static constexpr size_t FM_REC_RING_CAPACITY_FRAMES  = 48000;

enum class RingBufferMode {
    PLAYBACK, // I/O thread reads from disk, Audio thread reads from buffer
    RECORD    // Audio thread writes to buffer, I/O thread writes to disk
};

// ---------------------------------------------------------------------------
// Lock-free SPSC ring buffer for audio ↔ I/O thread communication.
// Fully encapsulates the FILE handle and file streaming logic.
// ---------------------------------------------------------------------------
class AudioRingBuffer {
private:
    std::vector<float> data;          // interleaved stereo float PCM
    std::atomic<size_t> writePos{0};
    std::atomic<size_t> readPos{0};
    size_t capacity{0};               // in frames (not samples)
    
    FILE* fileHandle = nullptr;
    RingBufferMode mode;
    std::string filePath;
    uint32_t byteCounter = 0; // used for WAV headers during recording

    // Warm-up function for playback buffers
    void warmUp();

public:
    AudioRingBuffer(RingBufferMode m) : mode(m) {}
    ~AudioRingBuffer() { closeFile(); }

    void init(size_t frames) {
        capacity = frames;
        data.assign(frames * 2, 0.0f);
        writePos.store(0, std::memory_order_relaxed);
        readPos.store(0,  std::memory_order_relaxed);
    }

    bool openFile(const std::string& path);
    void closeFile();

    // Called by the background I/O Thread every ~10ms
    void serviceIO();

    // Reset playback position
    void resetPlayback();
    void reset();

    // Lock-free checks
    size_t available() const {
        return writePos.load(std::memory_order_acquire) -
               readPos.load(std::memory_order_relaxed);
    }
    size_t freeSpace() const {
        return capacity - available();
    }

    // Audio thread: read up to `frames` stereo float frames. Returns frames read.
    size_t read(float* dst, size_t frames);
    
    // Audio thread: write up to `frames` stereo float frames. Returns frames written.
    size_t write(const float* src, size_t frames);
};

// ---------------------------------------------------------------------------
// TrackInstrument: instrument + weight, owned by InstrumentTrack.
// ---------------------------------------------------------------------------
struct TrackInstrument {
    FaustInstrument* instrument;
    float instrumentWeight;
    float effectiveWeight = 1.0f;
};

enum class TrackType {
    INSTRUMENT,
    FILE,
    MEMORY
};

// ---------------------------------------------------------------------------
// MixerTrack: Data-Oriented polymorphic base class.
// ---------------------------------------------------------------------------
class MixerTrack {
public:
    virtual ~MixerTrack() = default;
    
    virtual TrackType getType() const = 0;
    
    // Returns the raw data source (e.g., std::vector<TrackInstrument>*, AudioRingBuffer*, etc.)
    virtual void* getSource() = 0;

    // ── Common state ────────────────────────────────────────────────
    int   trackID        = 0;
    float assignedWeight = 1.0f;
    float dynamicWeight  = 1.0f;

    std::vector<EnvelopePoint> envelope;
    float fadeGain            = 1.0f;
    long  envelopeStartSample = 0;
    bool  muted               = false;

    // AGC state
    float agcEnvelope = 1.0f;
    float agcAttack   = 0.005f;
    float agcRelease  = 0.999f;
    float renderWeight = 1.0f;

    // Per-track effects (EQ, reverb sends, etc.)
    float reverbSend = 0.0f;
    std::unique_ptr<FaustTrackFxDSP> fxDSP;
    std::unique_ptr<MapUI>           fxUI;
    std::vector<float> fxInL, fxInR, fxOutL, fxOutR;
    
    // Render buffer where the mixer stores the aggregated audio for this track
    std::vector<float> renderBuf;
};

// ---------------------------------------------------------------------------
// InstrumentTrack: renders Faust DSP instruments via the worker thread pool.
// ---------------------------------------------------------------------------
class InstrumentTrack : public MixerTrack {
public:
    std::vector<TrackInstrument> instruments;

    TrackType getType() const override { return TrackType::INSTRUMENT; }
    void* getSource() override { return &instruments; }
};

// ---------------------------------------------------------------------------
// FileTrack: streams WAV file via an encapsulated lock-free ring buffer.
// ---------------------------------------------------------------------------
class FileTrack : public MixerTrack {
public:
    AudioRingBuffer playbackRing{RingBufferMode::PLAYBACK};
    
    TrackType getType() const override { return TrackType::FILE; }
    void* getSource() override { return &playbackRing; }
};

// ---------------------------------------------------------------------------
// MemoryTrack: plays pre-loaded in-memory float PCM. Zero I/O.
// ---------------------------------------------------------------------------
class MemoryTrack : public MixerTrack {
public:
    std::vector<float> pcmData;  // interleaved stereo float PCM
    size_t readPos = 0;

    TrackType getType() const override { return TrackType::MEMORY; }
    void* getSource() override { return this; }
};

#endif // MIXER_TRACK_HPP
