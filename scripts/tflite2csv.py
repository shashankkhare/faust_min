import numpy as np
import tensorflow as tf
import csv
import os

def distill_model(tflite_path, output_csv, note_range=(24, 108), vel_range=(1, 127)):
    """
    Sweeps through a TFLite model and extracts parameters into a CSV mapping file.
    """
    if not os.path.exists(tflite_path):
        print(f"Error: {tflite_path} not found.")
        return

    # Load the TFLite model
    interpreter = tf.lite.Interpreter(model_path=tflite_path)
    interpreter.allocate_tensors()

    input_details = interpreter.get_input_details()
    output_details = interpreter.get_output_details()

    # Determine parameter names from model metadata or defaults
    # For this example, we assume 3 synthesis parameters (pressure, vibrato, damping)
    param_names = ['pressure', 'vibrato', 'damping']

    with open(output_csv, 'w', newline='') as f:
        writer = csv.writer(f)
        # Header: note, velocity, followed by parameter names
        writer.writerow(['note', 'velocity'] + param_names)

        print(f"Distilling {tflite_path} into {output_csv}...")
        
        for note in range(note_range[0], note_range[1] + 1):
            for vel in range(vel_range[0], vel_range[1] + 1):
                # Prepare input: [note, velocity]
                input_data = np.array([[note, vel]], dtype=np.float32)
                interpreter.set_tensor(input_details[0]['index'], input_data)
                
                # Run Inference
                interpreter.invoke()
                
                # Get Output
                output_data = interpreter.get_tensor(output_details[0]['index'])[0]
                
                # Write to CSV
                writer.writerow([note, vel] + output_data.tolist())

    print("Success! AI mapping file created.")

if __name__ == "__main__":
    # Example usage:
    # distill_model("models/magenta_flute.tflite", "faust/flute_mapping.csv")
    print("This script is a template. Please update the 'distill_model' call with your specific TFLite file path.")
