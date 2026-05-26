import os
import sys
import numpy as np
import librosa
import librosa.display
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def analyze_facebook_audio(wav_path, output_img_path):
    print("Loading facebook audio file:", wav_path)
    y, sr = librosa.load(wav_path, sr=None)
    
    # We want to do a high-resolution pitch analysis for the entire 31 seconds.
    # The video has calls of multiple cuckoos:
    # 1. Common Cuckoo ("cuckoo" - 2 notes)
    # 2. Indian Cuckoo ("one more bottle" - 4 notes)
    # 3. Asian Koel ("koo-Ooo" - rising repeat)
    # etc.
    
    fmin = 150 # Hz
    fmax = 1500 # Hz
    
    # Track F0 using pyin (which handles noise and multiple segments beautifully)
    f0, voiced_flag, voiced_probs = librosa.pyin(y, fmin=fmin, fmax=fmax, sr=sr)
    times = librosa.times_like(f0, sr=sr)
    
    plt.figure(figsize=(15, 8))
    
    # Plot spectrogram in background
    D = librosa.amplitude_to_db(np.abs(librosa.stft(y)), ref=np.max)
    librosa.display.specshow(D, x_axis='time', y_axis='hz', sr=sr, cmap='magma', vmin=-60, vmax=0)
    
    # Overplot detected F0 pitch tracking in cyan
    plt.plot(times, f0, label='Fundamental Pitch (F0)', color='cyan', linewidth=2.5)
    
    plt.title('Facebook Cuckoos Video - Frequency Tracking (F0) vs. Time', fontsize=16)
    plt.xlabel('Time (seconds)', fontsize=12)
    plt.ylabel('Frequency (Hz)', fontsize=12)
    plt.ylim(150, 1500)
    plt.grid(True, which='both', linestyle='--', alpha=0.5)
    plt.legend(loc='upper right', fontsize=12)
    
    plt.tight_layout()
    plt.savefig(output_img_path, dpi=200)
    print("Spectrogram and pitch graph saved to:", output_img_path)
    
    # Print out segment analysis to pinpoint the cuckoo types and their notes
    print("\nAcoustic Note Sequence Events:")
    in_voiced = False
    segment_freqs = []
    segment_times = []
    
    for t, freq in zip(times, f0):
        if not np.isnan(freq):
            segment_freqs.append(freq)
            segment_times.append(t)
            in_voiced = True
        else:
            if in_voiced:
                avg_f = np.mean(segment_freqs)
                start_t = segment_times[0]
                end_t = segment_times[-1]
                duration = end_t - start_t
                if duration > 0.08:
                    note = librosa.hz_to_note(avg_f)
                    print(f"  [{start_t:5.2f}s - {end_t:5.2f}s] Duration: {duration:4.2f}s | Freq: {avg_f:6.1f} Hz | Note: {note}")
                segment_freqs = []
                segment_times = []
                in_voiced = False

if __name__ == '__main__':
    wav = '/home/shashankkhare/.gemini/antigravity/brain/a1fbdf2a-e552-498b-92f7-34f1a526887b/facebook_audio.wav'
    img = '/home/shashankkhare/.gemini/antigravity/brain/a1fbdf2a-e552-498b-92f7-34f1a526887b/facebook_pitch_graph.png'
    analyze_facebook_audio(wav, img)
