import csv

frequencies = [50.0, 80.0, 110.0, 150.0, 200.0, 300.0, 400.0, 500.0, 600.0, 800.0, 1000.0]
amplitudes = [0.1, 0.4, 0.7, 1.0]
strikes = [0.0, 1.0, 2.0] # Strike usually doesn't affect voice, but required by LUT system

with open('assets/dsp/voice.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['frequency','amplitude','strike','chest','glottal','nasal'])

    for freq in frequencies:
        for amp in amplitudes:
            for strike in strikes:
                
                # Chest is stronger at lower frequencies
                if freq <= 150.0:
                    chest = 0.8
                elif freq <= 300.0:
                    chest = 0.6
                elif freq <= 500.0:
                    chest = 0.4
                else:
                    chest = 0.1
                
                # Glottal is stronger at higher amplitudes (louder = more vocal fold tension / buzz)
                # and slightly stronger at higher frequencies
                glottal = amp * 0.7 + (freq / 1000.0) * 0.3
                if glottal > 1.0: glottal = 1.0
                if glottal < 0.1: glottal = 0.1
                
                # Nasal can peak slightly in the mid-range for natural vocal tract resonances
                if 300.0 <= freq <= 600.0:
                    nasal = 0.3 + (amp * 0.2)
                else:
                    nasal = 0.1 + (amp * 0.1)

                writer.writerow([f"{freq:.1f}", f"{amp:.1f}", f"{strike:.1f}", f"{chest:.2f}", f"{glottal:.2f}", f"{nasal:.2f}"])

print("Generated assets/dsp/voice.csv")
