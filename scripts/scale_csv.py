# Copyright (c) 2026 Shashank Khare
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import csv
import math
import os

def scale_csv(filename):
    print(f"Scaling CSV: {filename}")
    if not os.path.exists(filename):
        print(f"File not found: {filename}")
        return

    rows = []
    with open(filename, mode='r') as f:
        reader = csv.reader(f)
        header = next(reader)
        
        # Determine column indices
        try:
            p_idx = header.index("pressure")
        except ValueError:
            p_idx = -1
        try:
            m_idx = header.index("mouthPosition")
        except ValueError:
            m_idx = -1
        try:
            b_idx = header.index("breath_noise")
        except ValueError:
            b_idx = -1

        for row in reader:
            if not row:
                continue
            # Scale pressure
            if p_idx != -1:
                val = float(row[p_idx])
                # We want a minimum pressure of 0.72 to ensure stable oscillation across all registers, scaling to 0.95
                scaled_p = 0.72 + 0.23 * math.sqrt(val)
                row[p_idx] = f"{min(0.98, max(0.0, scaled_p)):.4f}"
            
            # Scale mouthPosition
            if m_idx != -1:
                val = float(row[m_idx])
                # Scale from [0, 1] to blow hole position sweet spot [0.50, 0.55]
                scaled_m = 0.50 + 0.05 * val
                row[m_idx] = f"{min(1.0, max(0.0, scaled_m)):.4f}"
            
            # Scale breath_noise
            if b_idx != -1:
                val = float(row[b_idx])
                # Scale average noise output to breath turbulence level [0.02, 0.12]
                scaled_b = 0.02 + 0.10 * val
                row[b_idx] = f"{min(1.0, max(0.0, scaled_b)):.4f}"

            rows.append(row)

    with open(filename, mode='w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(header)
        writer.writerows(rows)
    print("Successfully scaled.")

if __name__ == "__main__":
    scale_csv("assets/dsp/flute.csv")
    scale_csv("assets/dsp/bansuri.csv")
    scale_csv("assets/dsp/shakuhachi.csv")
