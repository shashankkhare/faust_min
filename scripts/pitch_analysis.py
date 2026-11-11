import os
import sys
import numpy as np
import librosa
import librosa.display
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def analyze_audio(wav_path, output_img_path):
    print("Loading audio file:", wav_path)
    y, sr = librosa.load(wav_path, sr=None)
    
    # Calculate fundamental frequency (F0) using YIN or PYIN
    # YIN is very fast and reliable for clean vocals
    fmin = 100 # Hz
    fmax = 1200 # Hz
    
    f0, voiced_flag, voiced_probs = librosa.pyin(y, fmin=fmin, fmax=fmax, sr=sr)
    times = librosa.times_like(f0, sr=sr)
    
    # Let's filter out transient / unvoiced frames
    # Let's also print statistics of the detected notes
    detected_freqs = f0[~np.isnan(f0)]
    detected_times = times[~np.isnan(f0)]
    
    if len(detected_freqs) == 0:
        print("No pitch detected.")
        return
        
    print(f"Detected pitch range: {np.nanmin(f0):.2f} Hz to {np.nanmax(f0):.2f} Hz")
    
    plt.figure(figsize=(10, 6))
    
    # Plot spectrogram in the background
    D = librosa.amplitude_to_db(np.abs(librosa.stft(y)), ref=np.max)
    librosa.display.specshow(D, x_axis='time', y_axis='hz', sr=sr, cmap='magma', vmin=-60, vmax=0)
    
    # Overplot the pitch
    plt.plot(times, f0, label='Pitch F0 (Hz)', color='cyan', linewidth=3)
    
    plt.title('Acoustic Pitch Tracking (F0) vs. Time', fontsize=14)
    plt.xlabel('Time (seconds)', fontsize=12)
    plt.ylabel('Frequency (Hz)', fontsize=12)
    plt.ylim(200, 1000) # zoom to typical cuckoo vocal range
    plt.grid(True, which='both', linestyle='--', alpha=0.5)
    plt.legend(loc='upper right')
    
    # Print the notes at various times to stdout
    print("\nApproximate Note Sequence Analysis:")
    # Group neighboring voiced frames
    in_note = False
    note_freqs = []
    note_times = []
    
    for t, freq in zip(times, f0):
        if not np.isnan(freq):
            note_freqs.append(freq)
            note_times.append(t)
            in_note = True
        else:
            if in_note:
                avg_freq = np.mean(note_freqs)
                start_t = note_times[0]
                end_t = note_times[-1]
                duration = end_t - start_t
                if duration > 0.05: # ignore very short glitches
                    note_name = librosa.hz_to_note(avg_freq)
                    print(f"  Note: {note_name} (~{avg_freq:.1f} Hz) | Time: {start_t:.2f}s to {end_t:.2f}s | Duration: {duration:.2f}s")
                note_freqs = []
                note_times = []
                in_note = False
                
    if in_note:
        avg_freq = np.mean(note_freqs)
        start_t = note_times[0]
        end_t = note_times[-1]
        duration = end_t - start_t
        if duration > 0.05:
            note_name = librosa.hz_to_note(avg_freq)
            print(f"  Note: {note_name} (~{avg_freq:.1f} Hz) | Time: {start_t:.2f}s to {end_t:.2f}s | Duration: {duration:.2f}s")
            
    plt.tight_layout()
    plt.savefig(output_img_path, dpi=150)
    print("Graph saved to:", output_img_path)

if __name__ == '__main__':
    wav = '/home/shashankkhare/.gemini/antigravity/brain/a1fbdf2a-e552-498b-92f7-34f1a526887b/uploaded_media.wav'
    img = '/home/shashankkhare/.gemini/antigravity/brain/a1fbdf2a-e552-498b-92f7-34f1a526887b/pitch_graph.png'
    analyze_audio(wav, img)
