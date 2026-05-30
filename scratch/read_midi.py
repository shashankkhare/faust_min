import mido
import os

def analyze_midi_tuning(file_path):
    if not os.path.exists(file_path):
        print(f"File not found: {file_path}")
        return
        
    mid = mido.MidiFile(file_path)
    print(f"\n=== Tuning and Scale Analysis for {file_path} ===")
    
    sitar_notes = []
    pitch_bends = []
    rpn_nrpn = []
    
    for msg in mid.tracks[0]:
        if msg.type == 'note_on' and msg.velocity > 0:
            if msg.channel in [0, 1, 4]: # Sitar channels
                sitar_notes.append(msg.note)
        elif msg.type == 'pitchwheel':
            pitch_bends.append(msg.pitch)
        elif msg.type == 'control_change' and msg.control in [96, 97, 98, 99, 100, 101]: # RPN/NRPN
            rpn_nrpn.append((msg.control, msg.value))
            
    # Unique notes sorted
    unique_sitar_notes = sorted(list(set(sitar_notes)))
    print(f"Sitar Notes Used: {unique_sitar_notes}")
    
    # Map note numbers to note names
    def note_name(n):
        names = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
        octave = (n // 12) - 1
        name = names[n % 12]
        return f"{name}{octave}"
        
    sitar_note_names = [note_name(n) for n in unique_sitar_notes]
    print(f"Sitar Note Names: {sitar_note_names}")
    
    # Calculate note frequency distribution to find the root note (tonic/Sa)
    from collections import Counter
    counts = Counter(sitar_notes)
    most_common = counts.most_common(5)
    print(f"Most Common Notes (Note, count): {[(note_name(n), c) for n, c in most_common]}")
    
    # Pitch bend message count
    print(f"Pitch Bend Messages Count: {len(pitch_bends)}")
    if pitch_bends:
        print(f"Min Pitch Bend: {min(pitch_bends)}")
        print(f"Max Pitch Bend: {max(pitch_bends)}")
        print(f"First 10 Pitch Bend values: {pitch_bends[:10]}")
        
    if rpn_nrpn:
        print(f"RPN/NRPN Messages: {rpn_nrpn[:10]}")

if __name__ == "__main__":
    analyze_midi_tuning("bhangra.mid")
