import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

fs = 44100.0

def resonbp(f0, Q, gain):
    w0 = 2 * np.pi * f0 / fs
    alpha = np.sin(w0) / (2 * Q)
    b0 = gain * alpha
    b1 = 0
    b2 = -gain * alpha
    a0 = 1 + alpha
    a1 = -2 * np.cos(w0)
    a2 = 1 - alpha
    return [b0/a0, b1/a0, b2/a0], [1.0, a1/a0, a2/a0]

modes = [
    (150.0,   4.0, 0.50),
    (236.7,   4.0, 0.25),
    (240.2,   4.0, 0.25),
    (315.4,   4.0, 0.45),
    (320.7,   4.0, 0.45),
    (342.3,   4.0, 0.40),
    (386.4,   4.0, 0.35),
    (402.7,   4.0, 0.35),
    (423.0,   4.0, 0.30),
    (438.7,   4.0, 0.30),
    (465.3,   4.0, 0.25),
    (477.4,   4.0, 0.25),
    (498.4,   4.0, 0.20),
    (522.9,   4.0, 0.20),
    (535.9,   4.0, 0.15),
    (544.2,   4.0, 0.15),
    (553.6,   4.0, 0.12),
    (573.3,   4.0, 0.10),
    (606.6,   4.0, 0.08),
    (610.3,   4.0, 0.08),
    (850.0,   5.0, 0.06),
    (1200.0,  5.0, 0.05),
    (1800.0,  6.0, 0.04),
    (2600.0,  6.0, 0.03),
    (3500.0,  8.0, 0.02)
]

freqs = np.linspace(10, 5000, 4000)
w = 2 * np.pi * freqs / fs

h_total = np.full(4000, 0.5, dtype=complex)

for f0, Q, G in modes:
    b, a = resonbp(f0, Q, G)
    _, h = signal.freqz(b, a, worN=w)
    h_total += h

# Apply lowpass (2nd order, 8000 Hz)
b_lp, a_lp = signal.butter(2, 8000.0 / (fs/2), btype='low')
_, h_lp = signal.freqz(b_lp, a_lp, worN=w)
h_total *= h_lp

plt.figure(figsize=(12, 6))
plt.plot(freqs, 20 * np.log10(np.abs(h_total) + 1e-6), color='#1E88E5', linewidth=2)
for f0, _, _ in modes:
    plt.axvline(f0, color='r', linestyle='--', alpha=0.3, linewidth=1)

plt.title('Sarod Membrane (Goatskin) Frequency Response with High-Freq Extension', fontsize=16)
plt.xlabel('Frequency (Hz)', fontsize=12)
plt.ylabel('Magnitude (dB)', fontsize=12)
plt.grid(True, alpha=0.3)
plt.xlim(10, 5000)
plt.tight_layout()
plt.savefig('/home/shashankkhare/.gemini/antigravity/brain/0dfab3ad-819b-4460-822f-d038691e83eb/membrane_response.png', dpi=150)
print("Plot saved.")
