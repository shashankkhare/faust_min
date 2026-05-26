# Faust Audio Engine: Pure Controller-Sink Architecture

## 1. Core Philosophy: Separation of Timeline and Signal
The `faust_min` engine is built on a "Pure Controller-Sink" model. This ensures that the high-level musical logic (timeline, UML sequences) is strictly decoupled from the low-level audio rendering and hardware interrupts.

*   **Controller (SequenceOrchestrator)**: The "Brain." It manages the UML timeline, evaluates musical events, and manipulates DSP parameters. It is unaware of how the audio is summed or which hardware is used.
*   **Sink (FaustMixer)**: The "Muscle." It is a high-performance audio bus that renders registered `FaustInstrument` objects in parallel. It is unaware of UML, sequences, or musical notation.

## 2. Block-Synchronized Communication
To maintain architectural purity while ensuring sample-accurate timing (at the block level), the engine uses a generic **Pre-Render Callback** mechanism.

1.  **Hardware Trigger**: The audio driver (miniaudio/Oboe) triggers the `FaustMixer`.
2.  **Sync Phase**: The Mixer invokes a generic `PreRenderCallback`.
3.  **Controller Update**: The `SequenceOrchestrator` (registered as the callback) evaluates all UML events for the upcoming block (e.g., NoteOn, Parameter Glides) and updates the state of the relevant instruments.
4.  **Parallel Render Phase**: The Mixer dispatches all registered instruments to a persistent worker thread pool for simultaneous signal generation.
5.  **Summation Phase**: The Mixer sums the parallel results into the hardware output buffer.

## 3. Class Hierarchy

### 3.1 FaustMixer (The Sink)
*   **Role**: Master Bus and Hardware Driver.
*   **Privacy**: The `onAudioReady` handler is private. External access is only allowed via the official `hardwareCallback` static wrapper.
*   **Responsibilities**:
    *   Hardware lifecycle management (miniaudio/Oboe).
    *   Parallel thread-pool dispatch for instruments.
    *   Master gain and peak limiting.
    *   Generic synchronization hooks (PreRenderCallback).

### 3.2 SequenceOrchestrator (The Controller)
*   **Role**: Timeline Manager and Event Scheduler.
*   **Responsibilities**:
    *   UML Parsing and Sequence state management.
    *   Evaluating musical events at block boundaries.
    *   Pushing state changes (NoteOn/Off, Glides) to instruments.
    *   Signaling sequence completion back to the Dart FFI layer.

### 3.3 FaustInstrument (The DSP Wrapper)
*   **Role**: Atomic Synthesis Engine.
*   **Responsibilities**:
    *   Wrapping Faust C++ classes.
    *   Internal parameter interpolation (Glides).
    *   Thread-safe state protection via `std::recursive_mutex`.

## 4. Sequence Diagram: The Audio Loop

```mermaid
sequenceDiagram
    participant HW as Hardware Driver
    participant MX as FaustMixer
    participant SO as SequenceOrchestrator
    participant FI as FaustInstrument
    participant WP as Worker Pool

    HW->>MX: hardwareCallback(numFrames)
    MX->>SO: PreRenderCallback(numFrames)
    loop Timeline Evaluation
        SO->>SO: Check UML Timeline
        opt Event Hit (NoteOn)
            SO->>FI: noteOn(freq, velocity)
        end
    end
    MX->>WP: Dispatch Parallel Render Tasks
    parallel
        WP->>FI: processRealtimeStream(block)
    end
    MX->>MX: Sum & Apply Master Gain
    MX->>HW: Return Buffer
```

## 5. Threading Model
*   **Audio Thread**: Executes the hardware callback, triggers the orchestrator update, and manages the worker pool barrier.
*   **Worker Threads**: Execute the heavy `compute()` logic of individual Faust instruments in parallel.
*   **UI/FFI Thread**: Asynchronously triggers `play()`, `stop()`, or parameter changes, which are safely absorbed by the audio thread via recursive locks.

## 6. Implementation Constraints
*   **No Hacking**: `onAudioReady` must never be called directly for verification.
*   **Pure Sink**: `FaustMixer` must never hold a reference to `SequenceOrchestrator`.
*   **Synchronous State**: All musical events for a block must be resolved before the `compute()` phase of that block begins.
