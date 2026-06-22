# UML (Universal Music Language) Specification

UML is a text-based format designed for high-fidelity woodwind, string, percussion, and vocal synthesis orchestration. It separates musical performance into two primary components: **Notes** (triggers and pitch) and **Control** (continuous parameter automation).

### Core Design Objectives
1. **Human and Machine Readable**: Unlike MIDI (which is binary and machine-focused) or traditional sheet music (which is visual and human-focused), UML is designed to be easily read and written by both humans and parsers.
2. **AI-Training Optimized**: Because UML is entirely text-based and structured, it makes training LLMs and generative AI models on musical sequences significantly easier and more efficient.
3. **Multilinguistic Support**: Musical traditions use vastly different notations. UML bridges this gap by supporting multiple linguistic frameworks (e.g., Western `C4`, Indian Classical `Sa`, and Percussive Bols `Dha`) within the same unified engine.


## 1. Header Metadata

Global settings that define the temporal and harmonic grid. Parameters fall into two categories:

### 1.1 Sequencing Parameters

Control the temporal layout, timing, and orchestration of the sequence.

| Parameter | Type | Description |
|---|---|---|
| `notation` | `Indian` / `Western` | Notation system. Default: `Indian`. |
| `instrument` | `[Name/Code]` | Instrument identifier. Resolved via `InstrumentMapper`. See §6. |
| `instrumentID` | `int` | Numeric instrument ID (alternative to name). |
| `basefreq` | `Hz` | Base frequency anchor (Sa / C). Default: `261.63`. |
| `bpm` | `Number` | Tempo in beats per minute. Default: `120`. |
| `grid` | `int` | Grid subdivisions per beat. Default: `4` (sixteenth notes). |
| `gain` | `Number` | Global gain multiplier for this sequence. |
| `loop` | `bool` | If `true`, the sequence repeats indefinitely. Default: `false`. |
| `measure` | `int` | Display-only: number of beats per measure (e.g., `4` for 4/4). Not used by the parser. |
| `delay` | `float` (seconds) | Seconds of silence before the first note. The sequence starts with `delay` seconds of rest, then plays normally. Useful for aligning sequences to start at different times (e.g., a voice entry after an instrumental section). Default: `0`. |
| `exectype` | `static` / `interpreter` | DSP execution mode. Default: `static`. |

### 1.2 Instrument-Play Parameters

Passed to the instrument's DSP at note-on and used for continuous modulation during playback. These are instrument-specific — refer to the individual DSP documentation for the full set. Common examples:

| Parameter | Range | Description |
|---|---|---|
| `vibrato` | 0.0–1.0 | Vibrato master enable/amount. |
| `vibrato_rate` | 0–20 Hz | Vibrato LFO rate. |
| `vibrato_depth` | 0.0–1.0 | Vibrato LFO depth. |
| `breathiness` | 0.0–1.0 | Noise/breath component. |
| `pressure` | 0.0–1.0 | Wind pressure (winds). |
| `mouthPosition` | 0.0–1.0 | Embouchure offset (winds). |

Instrument-play parameters are specified on their own header lines, one per parameter:

```
vibrato: 0.6
vibrato_rate: 5.5
vibrato_depth: 0.03
```

### 1.3 Sequencing Parameter Examples

**`loop: false` — one-shot playback (default):**

```
instrument: bansuri
bpm: 60
grid: 4
loop: false
basefreq: 220

5Sa.. 5Re.. 5Ga.. 5Pa..
```

**`loop: true` — drone/ambient sequence repeats indefinitely:**

```
instrument: dhol
bpm: 72
grid: 4
loop: true
basefreq: 111.0

8x.. 8x.. 8x.. 8x..
```

**`delay: 30` — voice enters 30 seconds into the piece:**

```
instrument: voice
bpm: 60
grid: 12
delay: 30
basefreq: 110
vibrato_rate: 5.5
vibrato_depth: 0.04
breathiness: 0.2

5F3... 5E3... 5D3...
```

---

## 2. Notes Component

The notes component handles discrete triggers and melodic movement for the sequence.

### Syntax: `([Amplitude])[NoteToken]` or `([Amplitude][StrikeVal])[NoteToken]` or `[ArticToken]`

- **Amplitude**: Optional single digit `1-9` (Default: 5). Marks the amplitude of the play. Maps as `amplitude = digit / 9.0`.
- **StrikeVal**: Optional second digit immediately following `Amplitude` (e.g. `51Sa` or `90Re`). Used for string/plucked instruments (like Sarod or Sitar) to control the strike/pluck articulation or drone strings:
  - `0`: Normal solo play of the primary melody string.
  - `1`: Plucking the main string along with the 3 accompanying drone/chikari strings.
  - *Note: For percussion instruments (Tabla/Conga), strikeVal continues to map to specific drum strokes (edge, slap, open, closed).*
  - **Indian Notation (22 Shrutis)**:
    - `Sa`, `Pa` (Fixed)
    - `r1`, `r2`, `R1`, `R2` (Re)
    - `g1`, `g2`, `G1`, `G2` (Ga)
    - `M1`, `M2`, `m1`, `m2` (Ma)
    - `d1`, `d2`, `D1`, `D2` (Dha)
    - `n1`, `n2`, `N1`, `N2` (Ni)
    - `SaLow` — one octave below Sa (ratio 0.5)
  - **Western Notation**: `C4`, `C#`, `Db`, `D4`, etc.
  - **Direct Hz**: Any numeric token (e.g. `440.0`) is used as a literal frequency.
  - **Chords (Polyphony)**: Use `|` (Pipe) to join multiple notes to be played simultaneously.
    - Example: `C4|E4|G4` (Plays C major chord).
- `ArticToken`:
  - `.` (Dot): Continuity. Extends the previous state (note or silence) by 1 grid unit.
  - `_` (Underscore): Full Stop. Ends the current note and starts silence.

### 2.1 Note Operators (`^`, `~`, `>`, `|`)

Operators are placed within the sequence of continuity dots to trigger dynamic changes at exact grid offsets.

#### `^` (Delayed Glide / Meend)
Triggers a simultaneous pitch and amplitude sweep toward the **next specified note** in the sequence. It can be placed anywhere in the dot continuity tail to start the glide at that specific moment.
- **Example**: `4Sa . . ^ . 5Re`
  - *Plays Sa for 2 units, starts gliding at the 3rd unit, arrives at Re.*
- *Note: If a `^` is attached directly to the start of a target note (e.g., `^Re`), it is treated as a visual marker and ignored by the parser.*

#### `~` (Vibrato Trigger)
Vibrato is strictly **disabled by default** at the start of any note. Placing a `~` in the dot continuity tail enables vibrato at that exact moment. It ramps up to the `vibratoRate` and `vibratoDepth` defined in the sequence header.
- **Example**: `5Pa . . ~ . . . .`
  - *Plays a flat Pa for 2 units, then vibrato organically swells in starting at the 3rd unit.*

#### `>` (Amplitude Glide)
Triggers an amplitude-only sweep toward the **next note's amplitude**, keeping the current pitch unchanged. Left-associative — the ramp starts at the end of the note the `>` is attached to.
- **Example**: `3Pa . . > . . 9Re`
  - *Plays Pa at amplitude 3, then ramps amplitude up toward 9 during the last 2 grid units.*

#### `|` (Polyphony / Chords)
Used to bind multiple pitches together into a single simultaneous strike (Chord).
- **Example**: `4C4|E4|G4 . . . _`
  - *Plays a C Major chord (C, E, G) for 3 units, then stops.*

#### `%` (NOOP Pitch Modifier)
Triggers the note (with new velocity/strike) but intentionally ignores and preserves the previous frequency. This allows the primary string to continue ringing at its original pitch underneath secondary strikes.
- **Example**: `61%` (instead of `61Sa` for Chikari strings, to prevent the melody string from pitch-bending).

**Complex Example**: `4Sa . ~ . ^ . 5Re`
*(Plays Sa for 1 unit, swells in vibrato at the 2nd unit, starts gliding towards Re at the 4th unit)*

---

## 3. Percussion Component — Tabla Bols

Used when `instrument` resolves to a percussion ID (IDs 0–6). Tokens map to a `strikeVal` controlling physical model articulation. Pitch is not used; `basefreq` passes through as a static tuning reference.

### 3.1 Dayan Bols (ID 0)

| Token(s) | strikeVal | Character |
|---|---|---|
| `Tu`, `tu`, `Tun`, `tun` | 0.0 | Deep bass resonance |
| `tk` | 1.0 | Edge flick |
| `Tit`, `tit` | 1.0 | Sharp muted |
| `Ti`, `ti`, `Tin`, `tin` | 2.0 | Ringing centre |
| `Dhin`, `dhin` | 2.0 | Compound — dayan Tin-style resonance |
| `Na`, `na`, `Ta`, `ta` | 3.0 | Open centre ring |
| `Dha`, `dha` | 3.0 | Compound — dayan open ring component |

### 3.2 Bayan Bols (ID 1)

| Token(s) | strikeVal | Character |
|---|---|---|
| `Ge`, `ge`, `Ghe`, `ghe` | 0.0 | Open resonant bass |
| `Dha`, `dha` | 0.0 | Deep bass press |
| `Ka`, `ka` | 1.0 | Edge stroke / Closed Syahi |
| `Tit`, `tit` | 1.0 | Silent / ghost stroke |
| `Ghi`, `ghi` | 2.0 | Half-open / Muted centre |
| `Dhin`, `dhin` | 2.0 | Half-muffled bass |
| `Ke`, `ke` | 3.0 | Edge stroke / Closed Syahi edge |

### 3.3 Djembe (ID 28)

Djembe uses a continuous `strike` 0–1 mapping (soft/bass → sharp/slap):

| Token(s) | strikeVal | Stroke | Character |
|---|---|---|---|
| `Gu`, `gu` | 0.0 | Gu | Djembe deep bass (West African) |
| `Ba`, `ba` | 0.0 | Bass | Full palm centre — deep resonant boom |
| `Don`, `don` | 0.0 | Don | Dun-dun open bass |
| `Go`, `go` | 1.0 | Go | Djembe open tone (West African) |
| `Pa` | 1.0 | Pa | Djembe mid open tone |
| `Sl`, `sl` | 1.0 | Slap | Sharp edge slap — high crack |
| `De`, `de` | 2.0 | De | Djembe muted / stopped tone |

### 3.4 Conga (ID 30)

Conga uses a discrete `strike` 0–2 mapping (Open Tone → Slap → Muted):

| Token(s) | strikeVal | Stroke | Character |
|---|---|---|---|
| `To`, `to` | 0.0 | Tone | Open finger tone — bright ring |
| `Gh`, `gh` | 0.0 | Ghost | Near-silent brush stroke |
| `Sl`, `sl` | 1.0 | Slap | Sharp edge slap — high crack |
| `Mu`, `mu` | 2.0 | Mute | Muffled / touch stroke |
| `Tap`, `tap` | 2.0 | Tap | Light finger tap |

### 3.5 Bongo (ID 31)

Bongo uses the same `strike` 0–2 mapping as Conga (Open Tone → Slap → Muted), typically tuned higher:

| Token(s) | strikeVal | Stroke | Character |
|---|---|---|---|
| `To`, `to` | 0.0 | Tone | Open finger tone — bright ring |
| `Gh`, `gh` | 0.0 | Ghost | Near-silent brush stroke |
| `Sl`, `sl` | 1.0 | Slap | Sharp edge slap — high crack |
| `Mu`, `mu` | 2.0 | Mute | Muffled / touch stroke |
| `Tap`, `tap` | 2.0 | Tap | Light finger tap |

### 3.6 Ambient Effects & Textures (Rainmaker, Sea Wave, Shaker, Chou Gong)

Ambient instruments operate slightly differently. 
- **Shaker (ID 33)** & **Chou Gong (ID 35)**: Can be triggered using standard General Percussion bols (e.g., `Na`, `Ta`, `Ti`, `Tun`).
- **Sea Wave (ID 34)** & **Rainmaker (ID 19)**: Can be triggered using Indian/Western pitched notes (e.g., `Sa`, `C4`) to set their resonant frequency filters, or using standard General bols to trigger a wash of sound. Their durations should be extended using sustain dots (`.`) to let the physics engine run continuously.

> Generic tabla tokens (`Na`, `tk`, `Ti`, `Tun`) still work as a fallback for all IDs in the 19, 28, 30, 31, 33, 34, 35 range.

### 3.7 Generic Impact / Strike Component (Bells, Bowls, Whistles)

For simple unpitched resonant instruments where humans just strike or rub to produce sound (e.g., Tibetan Bowls, Hand Bells, Gongs, Whistles), use the generic **X** notation.

**Syntax**: `[Amplitude][StrikeVal]X` or `[Amplitude][StrikeVal]x`

- `Amplitude`: (Optional) Single digit `1-9` (Default: `5`). Maps as `amplitude = digit / 9.0`.
- `StrikeVal`: (Optional) Single digit immediately following Amplitude (e.g. `80X`). `0` = mallet strike (default), `1` = rub/bow. No digit after X.
- `X` or `x`: The core generic strike token.

**Examples**:
- `9X`     : Hard mallet strike (amplitude 9, strikeVal defaults to 0).
- `5x`     : Medium mallet strike (amplitude 5).
- `81X`    : Hard rub/bow (amplitude 8, strikeVal 1 = rub).
- `X`      : Medium mallet strike (amplitude 5, strikeVal 0).

**Generic Bowl Example**:
```
instrument: tibetanbowl
basefreq: 111.0
bpm: 60
grid: 4

// Strike hard, let ring for 3 beats, then start a medium rub for 4 beats
9X . . . . . . . 50X . . . . . . . . . . . . . . .
```

### 3.8 General Percussion Fallback (IDs 2–6: Kick, Snare, HiHat, Tom, Ride)

| Token(s) | strikeVal |
|---|---|
| `Tu`, `Tun` | 0.0 |
| `tk`, `Ka` | 1.0 |
| `Ti`, `Tin` | 2.0 |
| `Na`, `Ta` | 3.0 |

**Tabla Example**:
```
instrument: dayan
bpm: 120
grid: 4

Na . Ta . Dhin . Dhin . Na . Ta . Tin .
```

**Djembe Example**:
```
instrument: djembe
bpm: 100
grid: 4

Gu . Go Sl . Gu . Go . Sl Mu . Go Gu .
```

**Conga Example**:
```
instrument: conga
bpm: 110
grid: 4

To . To Sl . Mu . To . To Sl . Mu To .
```

### 3.9 Konnakol (Carnatic Percussion)

Used when `instrument` is a Carnatic instrument (Mridangam, Ghatam) and `notation: konnakol` is specified in the sequence header. If `notation: konnakol` is missing, these instruments will fall back to the generic `x/X<strike>` notation described in §3.7.

| Token(s) (Mridangam) | strikeVal | Stroke |
|---|---|---|
| `Tha`, `tha` | 0.0 | Open bass (Thoppi) |
| `Thom`, `thom` | 1.0 | Closed bass (Thoppi) |
| `Chapu`, `chapu` | 2.0 | Open harmonic (Valanthalai) |
| `Nam`, `nam` | 3.0 | Treble edge ring (Valanthalai) |
| `Dhi`, `dhi` | 4.0 | Treble center mute (Valanthalai) |
| `Ta`, `ta` | 5.0 | Edge click (Valanthalai) |

| Token(s) (Ghatam) | strikeVal | Stroke |
|---|---|---|
| `Tha`, `tha` | 0.0 | Neck stroke |
| `Dhi`, `dhi` | 1.0 | Body/Center |
| `Thom`, `thom` | 2.0 | Belly stroke |
| `Nam`, `nam` | 3.0 | Edge click |
| `Gumki`, `gumki` | 4.0 | Mouth pressed to stomach |

**Mridangam Example**:
```
instrument: mridangam
notation: konnakol
bpm: 100
grid: 4

Tha . Dhi . Thom . Nam . Chapu . . . Ta . . .
```

---

## 4. Voice Component — Vowel Notation (ID 32)

Used when `instrument: voice`. Tokens can be **vowel syllables** (formant morph) or **Indian solfège** (pitch). Both are freely mixed; the orchestrator holds the last vowel across pitch changes.

### 4.1 Vowel Tokens

| Token(s) | vowelVal | Sound | Character |
|---|---|---|---|
| `aa`, `Aa`, `AA`, `a` | 0.0 | "aah" | Open bright — F1≈800 Hz, F2≈1200 Hz |
| `ee`, `Ee`, `EE`, `e` | 1.0 | "eh" | Mid-front — F1≈400 Hz, F2≈1800 Hz |
| `ii`, `Ii`, `II`, `i` | 2.0 | "ee" | Closed front — F1≈300 Hz, F2≈2300 Hz |
| `oo`, `Oo`, `OO`, `o` | 3.0 | "oh" | Back-rounded — F1≈400 Hz, F2≈800 Hz |
| `uu`, `Uu`, `UU`, `u` | 4.0 | "oo" | Closed-back — F1≈300 Hz, F2≈800 Hz |

### 4.2 Voice DSP Parameters

| Parameter | Range | Description |
|---|---|---|
| `freq` | 50–2000 Hz | Sung pitch |
| `amplitude` | 0.0–1.0 | Loudness + attack speed |
| `vowel` | 0.0–4.0 | Continuous formant morph (set by vowel tokens) |
| `breathiness` | 0.0–1.0 | 0 = operatic/pressed, 1 = breathy/whisper |
| `vibrato_rate` | 0–12 Hz | Vibrato speed (default 5.5 Hz) |
| `vibrato_depth` | 0.0–0.08 | Vibrato intensity |

**Example**:

```
instrument: voice
notation: Indian
basefreq: 220
bpm: 50
grid: 4
breathiness: 0.2
vibrato_depth: 0.015

// Sing "aah" on Sa, glide to Pa while morphing to "oo"
aa Sa^ . . oo Pa . . ii Ni . . aa Sa . . .
```

---

## 5. Full Sequence Structure (Notesheet)

```uml
notation: Indian
basefreq: 220
bpm: 90
grid: 4
instrument: বাঁশি // Resolved to bansuri.dsp via InstrumentMapper
pressure: 0.8
vibrato_depth: 0.02

// Notes Section
9Sa..^5R1..7G1.._...
```

**Multi-sequence example with delay**:

```uml
// Sequence 1: bansuri plays first
instrument: bansuri
grid: 4
bpm: 60
basefreq: 220
pressure: 0.8

5Sa.. 5Re.. 5Ga.. 5Pa..

// Sequence 2: voice enters after 30 seconds
instrument: voice
grid: 4
bpm: 60
basefreq: 440
delay: 30
vibrato_rate: 5.5
vibrato_depth: 0.02
breathiness: 0.2
vowel: 0

5Sa.. 5Re.. 5Ga.. 5Pa..
```

*(Plays Sa at amplitude 9, glides to R1 at amplitude 5, sustains, then stops)*

---

## 6. Instrument Registry

| Short Code | Full Name | ID | Notes Body Type |
|---|---|---|---|
| `DA` / `dayan` | Dayan (Tabla) | 0 | Bols §3.1 |
| `BA` / `bayan` | Bayan (Tabla) | 1 | Bols §3.2 |
| `kick` | Kick Drum | 2 | General bols §3.3 |
| `snare` | Snare Drum | 3 | General bols §3.3 |
| `hihat` | Hi-Hat | 4 | General bols §3.3 |
| `tom` | Tom | 5 | General bols §3.3 |
| `ride` | Ride Cymbal | 6 | General bols §3.3 |
| `BE` / `bell` | Bell | 7 | Indian solfège §2 |
| `BO` / `bowl` | Singing Bowl | 8 | Indian solfège §2 |
| `SI` / `sitar` | Sitar | 9 | Indian solfège §2 |
| `FL` / `flute` | Flute | 10 | Indian solfège §2 |
| `TA` / `tanpura` | Tanpura | 11 | Indian solfège §2 |
| `PI` / `piano` | Piano | 12 | Indian solfège §2 |
| `SX` / `sax` | Saxophone | 13 | Indian solfège §2 |
| `CB` / `cowbell` | Cowbell | 14 | Indian solfège §2 |
| `TR` / `trumpet` | Trumpet | 15 | Indian solfège §2 |
| `SH` / `shakuhachi` | Shakuhachi | 16 | Indian solfège §2 |
| `BN` / `bansuri` | Bansuri | 17 | Indian solfège §2 |
| `VI` / `violin` | Violin | 18 | Indian solfège §2 |
| `RM` / `rainmaker` | Rainmaker | 19 | Indian solfège §2 |
| `CH` / `churchbell` | Church Bell | 20 | Indian solfège §2 |
| `AG` / `acoustic_guitar` | Acoustic Guitar | 21 | Indian solfège §2 |
| `EG` / `electric_guitar` | Electric Guitar | 22 | Indian solfège §2 |
| `BS` / `bass` | Bass Guitar | 23 | Indian solfège §2 |
| `CE` / `cello` | Cello | 24 | Indian solfège §2 |
| `CR` / `cricket` | Cricket | 25 | Indian solfège §2 |
| `CU` / `cuckoo` | Cuckoo | 26 | Indian solfège §2 |
| `WF` / `waterfall` | Waterfall | 27 | Indian solfège §2 |
| `DJ` / `djembe` | Djembe | 28 | General bols §3.3 |
| `MA` / `marimba` | Marimba | 29 | Indian solfège §2 |
| `CG` / `conga` | Conga | 30 | General bols §3.3 |
| `BG` / `bongo` | Bongo | 31 | General bols §3.3 |
| `VO` / `voice` / `vocals` / `singing` | Singing Voice | 32 | Vowels + Indian solfège §4 |
| `SK` / `shaker` | Shaker | 33 | General bols §3.8 |
| `SW` / `seawave` | Sea Wave | 34 | General bols §3.8 |
| `CG` / `chougong` | Chou Gong | 35 | General bols §3.8 |
| `TB` / `tibetanbowl` | Tibetan Singing Bowl | 47 | Articulation tokens (s/r) §3.7 |
| `MG` / `mridangam` | Mridangam | 49 | Konnakol bols §3.9 |
| `GH` / `ghatam` | Ghatam | 50 | Konnakol bols §3.9 |
