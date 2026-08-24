#include "MixerTrack.hpp"
#include <android/log.h>
#include <algorithm>
#include <cstring>

#define MT_LOGI(...) __android_log_print(ANDROID_LOG_INFO, "MixerTrack", __VA_ARGS__)
#define MT_LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "MixerTrack", __VA_ARGS__)

bool AudioRingBuffer::openFile(const std::string& path) {
    closeFile();
    filePath = path;

    if (mode == RingBufferMode::PLAYBACK) {
        fileHandle = fopen(path.c_str(), "rb");
        if (!fileHandle) {
            MT_LOGE("Failed to open playback file: %s", path.c_str());
            return false;
        }
        // Skip WAV header
        fseek(fileHandle, 44, SEEK_SET);
        warmUp();
        MT_LOGI("Opened and warmed up playback file: %s", path.c_str());
    } else {
        fileHandle = fopen(path.c_str(), "wb");
        if (!fileHandle) {
            MT_LOGE("Failed to open record file: %s", path.c_str());
            return false;
        }
        // Write empty WAV header placeholder
        uint8_t header[44] = {0};
        fwrite(header, 1, 44, fileHandle);
        byteCounter = 0;
        MT_LOGI("Opened record file: %s", path.c_str());
    }
    return true;
}

void AudioRingBuffer::closeFile() {
    if (fileHandle) {
        if (mode == RingBufferMode::RECORD) {
            // Finalize WAV header
            uint32_t sampleRate = 48000; // Hardcoded for simplicity in this demo, adjust if needed
            uint16_t channels = 2;
            uint16_t bitsPerSample = 16;
            uint32_t byteRate = sampleRate * channels * (bitsPerSample / 8);
            uint16_t blockAlign = channels * (bitsPerSample / 8);
            uint32_t dataBytes = byteCounter;
            uint32_t fileSize = 36 + dataBytes;

            fseek(fileHandle, 0, SEEK_SET);
            fwrite("RIFF", 1, 4, fileHandle);
            fwrite(&fileSize, 4, 1, fileHandle);
            fwrite("WAVE", 1, 4, fileHandle);
            fwrite("fmt ", 1, 4, fileHandle);
            uint32_t fmtLen = 16;
            fwrite(&fmtLen, 4, 1, fileHandle);
            uint16_t formatPCM = 1;
            fwrite(&formatPCM, 2, 1, fileHandle);
            fwrite(&channels, 2, 1, fileHandle);
            fwrite(&sampleRate, 4, 1, fileHandle);
            fwrite(&byteRate, 4, 1, fileHandle);
            fwrite(&blockAlign, 2, 1, fileHandle);
            fwrite(&bitsPerSample, 2, 1, fileHandle);
            fwrite("data", 1, 4, fileHandle);
            fwrite(&dataBytes, 4, 1, fileHandle);
        }
        fclose(fileHandle);
        fileHandle = nullptr;
    }
}

void AudioRingBuffer::warmUp() {
    if (!fileHandle || mode != RingBufferMode::PLAYBACK) return;
    
    // Fill the buffer synchronously on the main thread to prevent initial underruns
    float tmp[FM_IO_CHUNK_FRAMES * 2];
    int16_t raw[FM_IO_CHUNK_FRAMES * 2];
    
    while (freeSpace() >= FM_IO_CHUNK_FRAMES) {
        size_t bytesRead = fread(raw, sizeof(int16_t), FM_IO_CHUNK_FRAMES * 2, fileHandle);
        if (bytesRead == 0) break; // EOF
        
        size_t framesRead = bytesRead / 2;
        for (size_t i = 0; i < framesRead * 2; ++i) {
            tmp[i] = raw[i] / 32768.0f;
        }
        write(tmp, framesRead);
    }
}

void AudioRingBuffer::serviceIO() {
    if (!fileHandle) return;

    float tmp[FM_IO_CHUNK_FRAMES * 2];
    int16_t raw[FM_IO_CHUNK_FRAMES * 2];

    if (mode == RingBufferMode::PLAYBACK) {
        // I/O thread writes to buffer
        while (freeSpace() >= FM_IO_CHUNK_FRAMES) {
            size_t bytesRead = fread(raw, sizeof(int16_t), FM_IO_CHUNK_FRAMES * 2, fileHandle);
            if (bytesRead == 0) {
                // Loop audio for demo purposes (optional)
                fseek(fileHandle, 44, SEEK_SET);
                break; 
            }
            size_t framesRead = bytesRead / 2;
            for (size_t i = 0; i < framesRead * 2; ++i) {
                tmp[i] = raw[i] / 32768.0f;
            }
            write(tmp, framesRead);
        }
    } else if (mode == RingBufferMode::RECORD) {
        // I/O thread reads from buffer and writes to disk
        size_t n = read(tmp, FM_IO_CHUNK_FRAMES);
        while (n > 0) {
            for (size_t i = 0; i < n * 2; ++i) {
                float s = std::max(-1.0f, std::min(1.0f, tmp[i]));
                raw[i] = static_cast<int16_t>(s < 0.0f ? s * 32768.0f : s * 32767.0f);
            }
            fwrite(raw, sizeof(int16_t), n * 2, fileHandle);
            byteCounter += static_cast<uint32_t>(n * 2 * sizeof(int16_t));
            n = read(tmp, FM_IO_CHUNK_FRAMES);
        }
    }
}

void AudioRingBuffer::resetPlayback() {
    if (fileHandle && mode == RingBufferMode::PLAYBACK) {
        fseek(fileHandle, 44, SEEK_SET);
        reset();
        warmUp();
    }
}

void AudioRingBuffer::reset() {
    writePos.store(0, std::memory_order_release);
    readPos.store(0,  std::memory_order_release);
    std::fill(data.begin(), data.end(), 0.0f);
}

size_t AudioRingBuffer::write(const float* src, size_t frames) {
    size_t w = writePos.load(std::memory_order_relaxed);
    size_t r = readPos.load(std::memory_order_acquire);
    size_t free = capacity - (w - r);
    frames = std::min(frames, free);
    for (size_t i = 0; i < frames * 2; ++i)
        data[(w * 2 + i) % (capacity * 2)] = src[i];
    writePos.fetch_add(frames, std::memory_order_release);
    return frames;
}

size_t AudioRingBuffer::read(float* dst, size_t frames) {
    size_t r = readPos.load(std::memory_order_relaxed);
    size_t w = writePos.load(std::memory_order_acquire);
    size_t avail = w - r;
    frames = std::min(frames, avail);
    for (size_t i = 0; i < frames * 2; ++i)
        dst[i] = data[(r * 2 + i) % (capacity * 2)];
    readPos.fetch_add(frames, std::memory_order_release);
    return frames;
}
