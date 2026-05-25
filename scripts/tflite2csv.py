#!/usr/bin/env python3
"""
TFLite to Faust CSV Parameter Exporter
Usage:
  python3 scripts/tflite2csv.py \
    --model_path assets/models/flute.tflite \
    --output_csv assets/dsp/shakuhachi.csv \
    --mapping '{"pressure": "StatefulPartitionedCall:0", "mouthPosition": "StatefulPartitionedCall:1[0]", "breath_noise": "StatefulPartitionedCall:2[mean]"}' \
    --freq_range "200,800,15" \
    --vel_range "0.1,1.0,5"
"""

import csv
import json
import argparse
import os
import numpy as np

try:
    import tflite_runtime.interpreter as tflite
except ImportError:
    try:
        import tensorflow as tf
        tflite = tf.lite
    except ImportError:
        print("Error: Please install tensorflow or tflite_runtime:")
        print("  pip install tflite-runtime")
        exit(1)

def hz_to_midi(hz):
    return 69.0 + 12.0 * np.log2(hz / 440.0)

def main():
    parser = argparse.ArgumentParser(description="Export TFLite predictions to a Faust parameter CSV file.")
    parser.add_argument("--model_path", required=True, help="Path to the .tflite model file")
    parser.add_argument("--output_csv", required=True, help="Path to save the generated CSV file")
    parser.add_argument("--mapping", required=True, type=json.loads, 
                        help="JSON dictionary mapping CSV headers to TFLite output tensor names. "
                             "Example: '{\"pressure\": \"StatefulPartitionedCall:0\", \"mouthPosition\": \"StatefulPartitionedCall:1[0]\"}'")
    parser.add_argument("--freq_range", default="200,800,15", 
                        help="Frequency grid as 'start,end,steps'. Default: '200,800,15'")
    parser.add_argument("--vel_range", default="0.1,1.0,5", 
                        help="Velocity grid as 'start,end,steps'. Default: '0.1,1.0,5'")
    
    args = parser.parse_args()

    # Load metadata.json if it exists in the same directory
    min_pitch = 62.84
    max_pitch = 78.82
    model_dir = os.path.dirname(args.model_path)
    metadata_path = os.path.join(model_dir, "metadata.json")
    
    # Try sibling metadata first, otherwise check if model filename gives a clue
    if os.path.exists(metadata_path):
        try:
            with open(metadata_path, 'r') as f:
                meta = json.load(f)
                min_pitch = meta.get("mean_min_pitch_note", min_pitch)
                max_pitch = meta.get("mean_max_pitch_note", max_pitch)
                print(f"Loaded pitch scaling from metadata.json: min={min_pitch:.2f}, max={max_pitch:.2f}")
        except Exception as e:
            print(f"Warning: Failed to load sibling metadata.json: {e}")
    else:
        # Fallback based on model filename
        fname = os.path.basename(args.model_path).lower()
        if "sax" in fname:
            min_pitch = 52.52
            max_pitch = 63.65
            print("Using fallback Saxophone pitch scaling")
        elif "violin" in fname:
            min_pitch = 56.63
            max_pitch = 74.44
            print("Using fallback Violin pitch scaling")
        elif "flute" in fname or "bansuri" in fname or "shakuhachi" in fname:
            min_pitch = 62.84
            max_pitch = 78.82
            print("Using fallback Flute/Bansuri/Shakuhachi pitch scaling")

    # Parse ranges
    try:
        f_start, f_end, f_steps = map(float, args.freq_range.split(','))
        f_steps = int(f_steps)
        frequencies = np.linspace(f_start, f_end, f_steps).tolist()
    except Exception as e:
        print(f"Error parsing freq_range '{args.freq_range}': {e}")
        exit(1)

    try:
        v_start, v_end, v_steps = map(float, args.vel_range.split(','))
        v_steps = int(v_steps)
        velocities = np.linspace(v_start, v_end, v_steps).tolist()
    except Exception as e:
        print(f"Error parsing vel_range '{args.vel_range}': {e}")
        exit(1)

    print(f"Loading TFLite model from: {args.model_path}")
    interpreter = tflite.Interpreter(model_path=args.model_path)
    interpreter.allocate_tensors()

    # Get input/output details
    input_details = interpreter.get_input_details()
    output_details = interpreter.get_output_details()

    # Map input names to indices
    freq_input_idx = None
    vel_input_idx = None
    state_input_idx = None

    for x in input_details:
        name = x['name'].lower()
        if "f0" in name:
            freq_input_idx = x['index']
        elif "pw" in name or "power" in name or "loudness" in name:
            vel_input_idx = x['index']
        elif "state" in name:
            state_input_idx = x['index']

    # Fallback to order if names don't match
    if freq_input_idx is None:
        freq_input_idx = input_details[1]['index'] if len(input_details) > 1 else input_details[0]['index']
    if vel_input_idx is None:
        vel_input_idx = input_details[2]['index'] if len(input_details) > 2 else input_details[1]['index']
    if state_input_idx is None and len(input_details) > 0:
        state_input_idx = input_details[0]['index']

    # Parse outputs mapping
    output_name_to_index = {detail['name']: detail['index'] for detail in output_details}

    # Setup CSV header
    header = ["frequency", "velocity"] + list(args.mapping.keys())

    print(f"Generating CSV with frequency range [{f_start:.1f} - {f_end:.1f}] ({f_steps} steps) "
          f"and velocity range [{v_start:.1f} - {v_end:.1f}] ({v_steps} steps)...")

    # Generate grid data
    records = []
    for freq in frequencies:
        for vel in velocities:
            # Scale pitch
            midi = hz_to_midi(freq)
            f0_scaled = (midi - min_pitch) / (max_pitch - min_pitch)
            f0_scaled = np.clip(f0_scaled, 0.0, 1.0)

            # Set input tensors
            if state_input_idx is not None:
                interpreter.set_tensor(state_input_idx, np.zeros((512,), dtype=np.float32))
            
            interpreter.set_tensor(freq_input_idx, np.array([f0_scaled], dtype=np.float32))
            interpreter.set_tensor(vel_input_idx, np.array([vel], dtype=np.float32))

            # Run inference
            interpreter.invoke()

            # Retrieve outputs
            row = [round(freq, 2), round(vel, 2)]
            for col_name, expr in args.mapping.items():
                # Parse expression like StatefulPartitionedCall:1[0] or StatefulPartitionedCall:2[mean]
                if '[' in expr:
                    base_name = expr.split('[')[0]
                    op = expr.split('[')[1].split(']')[0]
                else:
                    base_name = expr
                    op = None

                # Find correct output index
                idx = None
                for name, o_idx in output_name_to_index.items():
                    if base_name in name:
                        idx = o_idx
                        break
                
                if idx is None:
                    print(f"Error: Output tensor matching '{base_name}' not found.")
                    print(f"Available output tensor names: {list(output_name_to_index.keys())}")
                    exit(1)

                arr = interpreter.get_tensor(idx)
                
                # Apply operation
                if op is not None:
                    if op.isdigit():
                        val = float(arr[int(op)])
                    elif op == 'mean':
                        val = float(np.mean(arr))
                    elif op == 'sum':
                        val = float(np.sum(arr))
                    else:
                        val = float(arr[0])
                else:
                    val = float(arr[0])

                # The CSV will store the raw normalized model output in [0.0, 1.0]
                # Scaling/calibration to physical ranges is handled directly inside the Faust DSP.
                scaled_val = val

                row.append(round(np.clip(scaled_val, 0.0, 1.0), 4))
            
            records.append(row)

    # Write to CSV
    with open(args.output_csv, mode="w", newline="") as file:
        writer = csv.writer(file)
        writer.writerow(header)
        writer.writerows(records)

    print(f"Success: Parameter mapping successfully saved to: {args.output_csv}")

if __name__ == "__main__":
    main()
