import csv

frequencies = [110.0, 146.8, 196.0, 220.0, 246.9, 293.7, 329.6, 392.0, 440.0, 493.9, 523.3, 587.3, 659.3, 783.9, 880.0, 1046.5, 1174.6, 1400.0]
amplitudes = [0.1, 0.4, 0.7, 1.0]
strikes = [0.0, 1.0, 2.0]

with open('assets/dsp/violin.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['frequency','amplitude','strike','bowVelocity','bowPosition','bowPressure','gain','velocity'])
    
    for freq in frequencies:
        for amp in amplitudes:
            for strike in strikes:
                if freq <= 110:
                    base_vel = 0.040
                    base_pos = 0.17
                    base_press = 0.25
                elif freq <= 220:
                    base_vel = 0.050
                    base_pos = 0.15
                    base_press = 0.30
                elif freq <= 440:
                    base_vel = 0.070
                    base_pos = 0.13
                    base_press = 0.40
                elif freq <= 880:
                    base_vel = 0.120
                    base_pos = 0.10
                    base_press = 0.50
                else:
                    base_vel = 0.180
                    base_pos = 0.08
                    base_press = 0.60

                sNorm = (strike - 1.0)
                
                bowVel = base_vel - (sNorm * 0.03) 
                if bowVel < 0.01: bowVel = 0.01
                
                bowPos = base_pos - (sNorm * 0.03)
                if bowPos < 0.02: bowPos = 0.02
                
                bowPress = base_press + (sNorm * 0.25)
                if bowPress < 0.05: bowPress = 0.05
                if bowPress > 0.95: bowPress = 0.95

                bowVel = bowVel + (amp * 0.01)
                bowPress = bowPress + (amp * 0.05)
                
                gain = max(0.1, amp)
                
                # Map velocity based on strike
                if strike == 0.0:
                    velocity = 1.0  # Slowest attack (150ms)
                elif strike == 1.0:
                    velocity = 0.5  # Medium attack (75ms)
                else:
                    velocity = 0.2  # Fastest attack (30ms)
                
                writer.writerow([f"{freq:.1f}", f"{amp:.1f}", f"{strike:.1f}", f"{bowVel:.3f}", f"{bowPos:.2f}", f"{bowPress:.2f}", f"{gain:.2f}", f"{velocity:.2f}"])
