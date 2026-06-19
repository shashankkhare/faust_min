# Agent Instructions & Data Integrity Rules

## 3. Test Cleanliness

- **APK Deletion**: Old APK and final executable need to be deleted for testing new ones. Always run `rm build/app/outputs/flutter-apk/app-debug.apk` before a fresh install.

## 4. Multi-Platform Compatibility

- **Platform Invariant**: Ensure Linux, Windows, Android, and iOS compatibility at all times.
- **Isolate Guarding**: On Desktop platforms (Linux, Windows, MacOS), skip redundant background isolate initialization (like `CouchbaseLiteFlutter.init()`) inside `onStart` since it runs in the main isolate.
- **Feature Parity**: Always maintain logic parity between native Android adapters and Desktop Dart adapters.

## 5. Documentation & Comment Integrity

- **Rule**: NEVER delete comments unless the surrounding code is fundamentally changed or the comment is objectively misleading.
- **Why?**: Comments contain critical architectural context and "hard-won" logic notes that prevent regressions.
- **Preservation**: When refactoring or adding features, ensure existing documentation blocks are preserved in their original locations.

## 6. Diagnosis Protocol

- **Log-First Rule**: NEVER look at the code first to diagnose a runtime issue if logs are available. ALWAYS review the application logs (`flutter run` output, system logs, etc.) to pinpoint the exact failure point before exploring the codebase. This prevents "code blindness" and ensures assumptions match reality.
- **Scanning vs. Direct Connect**: If a device is already paired (MAC exists in settings), the adapter should attempt a direct connection or a targeted scan. Do not default to a general scan if the target identity is known.

## 7. Error Log Preservation

- **Rule**: NEVER delete error-related logs (`Log.e`, `print('❌ ...')`) unless they are redundant or the error logic is completely removed.
- **Why?**: Error logs are essential for post-mortem diagnostics in production and for catching regressions during development.
- **Preservation**: When refactoring or "cleaning up" code, ensure all diagnostic error catch blocks and their associated log statements are preserved.

## 8. Veracity & Fact-Checking

- **Rule**: NEVER make a statement about the application's state (e.g., "it is running", "build successful", "device connected") without performing a direct fact-check.
- **Proof**: Claims of success must be backed by direct log inspection (`tail`, `grep`) or process verification (`ps`, `flutter devices`). If an executable fails to appear, do not claim it has launched.

## 9. Design Consistency

- **Rule**: NEVER change the architectural design (e.g., initialization sequences, isolate bootstrap patterns, data-flow models) unless explicitly approved by the USER.
- **Bootstrapping**: Ensure core components (like CBL) are initialized exactly where and when the design requires. Do not introduce arbitrary delays or "hacky" debugging shifts into the production logic.

## 10. Architecture Sacrosanct

- **Rule**: NEVER alter the design mentioned in `docs/architecture.md` under any conditions. The architecture is sacrosanct.
- **Ownership**: Only the USER has the authority to change the design for the code to work. The agent must adapt the implementation to fit the stated architecture, never the reverse.

## 11. Log Timestamp Verification

- **Rule**: NEVER make a statement about the application's runtime state based on logs WITHOUT explicitly verifying that the log's timestamp is post-launch.
- **Why?**: Stale logs from previous sessions can lead to "hallucinations of success" and false stability claims.
- **Protocol**: Claims of isolate spawn, database opening, or session firing MUST be backed by logs generated after the current `flutter run` or `flutter build` invocation.

## 12. Strict Ephemeral Database Pattern (Rule 25)

- **Rule**: NEVER store a Database handle in a static, late, or singleton variable.
- **Protocol**: Every database operation MUST open its own handle, perform its action, and close the handle immediately (Atomic Handshake).
- **Isolate Safety**: All query results MUST be detached (`toPlainMap()`) before the handle is closed or passed across isolates.
- **Why?**: This is the ONLY way to prevent native mutex deadlocks and Fleece memory corruption on Linux Desktop isolates. No hacky delays or retry loops allowed.
- **Desktop Exception (Rule 27)**: On Linux/Windows/MacOS Desktop, Rule 25 is replaced by Rule 27 (Persistent Bridge) to prevent native library initialization collisions across isolates.

## 13. Map-based Persistence (Rule 27 - Linux Stabilization)

- **Rule**: On Linux Desktop, the `DatabaseService` uses a shared persistent connection (`_db`) within each isolate instead of opening/closing on every call.
- **Protocol**:
  - **Persistence**: ALL document updates MUST use `saveMap(id, data)`.
  - **Detachment**: `saveMap` MUST perform a deep clone (e.g., `jsonDecode(jsonEncode(data))`) before calling `saveDocument`.
  - **Retrieval**: ALL query results and document retrievals MUST use `toPlainMap()` immediately to detach from native Fleece memory.
  - **Isolate Safety**: NEVER pass a `Document` or `MutableDocument` instance between isolates. Only pass `Map<String, dynamic>`.
- **Why?**: Couchbase Lite's C-engine (Fleece) memory is strictly isolate-bound on Desktop. Accessing native objects across isolates or through a closed handle triggers a fatal `fleece::FleeceException`. Rule 27 ensures all data in transit is pure Dart memory ($Map$).

## 14. Verification-First Walkthrough

- **Rule**: NEVER present a walkthrough artifact or declare a task as "Complete" unless the fix has been explicitly verified.
- **Protocol**: 
  - Claims of stability must be backed by data from a reproduction script (e.g., `bin/verify_...`) or fresh application logs.
  - Verification logs must be post-launch (Check timestamps).
  - If a bug was reported as a crash/hang, the verification must show a full "Cycle of Success" (e.g., Boot -> Operation -> Shutdown) without the failure recurrences.
- **Why?**: Declaring success without proof leads to "hallucinations of stability" and frustrates the user when regressions are discovered immediately.

## 15. Build-First Command Protocol

- **Rule**: NEVER launch an application until its build has been explicitly verified for success.
- **Protocol**:
  - **Process Cleanup**: Prior to any Desktop build/run (Linux, Windows, MacOS), ensure no old instances are running by executing a kill command (e.g., `pkill -f slumber`).
    - *Exception*: This does not apply to Mobile (Android/iOS) where hot reload/hot restart is the standard development workflow.
  - **Clean Start**: Prior to any build, existing executables (e.g., `.exe`, `.dll`, `.apk`, or Linux bundle binaries) MUST be deleted from the `build/` directory.
  - **Log Verification**: Redirect build output (including `stderr`) to a log file (e.g., `> /tmp/build.log 2>&1`).
  - **Success Check**: Inspect the log file for success indicators (e.g., "Built build/linux...") using `grep` or `tail` BEFORE executing a `run` or `install` command.
  - **Failure Block**: If the build log shows errors, do NOT attempt to launch the stale binary; instead, fix the code and retry the build-first cycle.
- **Why?**: This prevents "ghost successes" where an agent incorrectly reports a task as fixed because it accidentally launched a stale, cached binary or is viewing logs from a zombie process.

## 16. Log Management & Stale State Prevention

- **Rule**: ALWAYS clear existing device logs for exampke in android (`adb logcat -c`) before starting a fresh run for verification.
- **Protocol**:
  - **Clearance**: Before invoking `flutter run` or `adb install`, execute log deletion command like `adb logcat -c` to ensure the buffer is empty.
  - **Validation**: When reviewing logs for "success" indicators, verify that they are originating from the current process ID (PID) and session.
- **Why?**: Stale logs from failed attempts often contain similar keywords as successful ones, leading to "false diagnostics" and the appearance of success when the code is actually stale or failing.
## 17. Git Safety & Local Work Protection

- **Rule**: NEVER call `git checkout` without explicit USER permission.
- **Why?**: This is to prevent accidental overwriting of uncommitted local work that has not yet been synced to origin. Automated reverts can destroy hours of development state that `git` is unaware of.
- **Isolate Safety**: Always maintain architectural isolation between UI and Background isolates. The UI isolate must never touch native health data providers.

## 18. Documentation-First Development & Class Headers

- **Rule**: NEVER overwrite, modify, or delete core functional descriptions or warnings located in a class-level header without explicit USER confirmation.
- **Protocol**: Before performing ANY code change in a primary engine class (e.g., `BackgroundProcessor`), the agent MUST read the class-level header to identify "Functional Pillars" or core constraints.
- **Constraint**: ANY change that alters a stated core functionality MUST be confirmed by the USER first. Documentation of these pillars is sacrosanct and serves as the master contract for the class's behavior.
## 19. Method & Inline Instruction Respect

- **Rule**: ALWAYS respect instructions provided in comments at the top of a method or inline within a code block.
- **Protocol**: Instructions such as "DO NOT MODIFY", "MUST FOLLOW X SEQUENCE", or "DO NOT DELETE COMMENTS" are active constraints. They override general logic or agent-perceived "optimizations".
- **Enforcement**: If a method header contains a specific restriction (like the v2.4.5 Wipe & Re-seed warning), the agent MUST NOT modify that method's logic or documentation without explicit, targeted USER approval for that specific block.

## 20. Test & Verification Integrity

- **Rule**: NEVER make any code changes to production source files (e.g., `lib/`, `slumber_shared/`) for the purpose of testing or verification.
- **Protocol**: 
  - All verification MUST be done via external test scripts (`test/`, `bin/`), diagnostic logs, or live app interaction.
  - DO NOT "accelerate" timings (e.g., changing 15s to 3s), mock constants in source, or add "verification methods" to production classes.
- **Why?**: Modifying production code for testing introduces "test-only" bugs, pollutes the codebase with temporary hacks, and risks shipping sub-optimal performance configurations (like shortened timers) to production.

## 21. Class Structure & Layout Invariance

- **Rule**: NEVER change the structural layout, data member fields, or header declarations of any class without explicit, targeted USER approval.
- **Protocol**: If a feature requires extending class parameters or passing new execution contexts, implement non-invasive function argument overloading or external property mappings. The underlying memory layout and structural header declarations are sacrosanct.
- **Why?**: Modifying object schemas or class memory structures silently breaks binary interface compatibilities, disrupts downstream language bindings (FFI), and introduces severe side-effects without the user's architectural oversight.

## 23. Faust DSP Retrigger Reliability

- **Root Cause**: `en.ar` with `ba.impulsify` gate produces a 1-sample impulse; the envelope barely opens before release, and on retrigger the internal envelope state never properly resets. The feedback loop remaining active during the new excitation lets residual delay-line content interfere.
- **Proven Pattern** (sitar.dsp lines 28–39): Use `(gate - gate') > 0.0` for rising-edge detection, then a counter-based pulse timer instead of `en.ar`:
  ```
  trig_pulse(t) = loop ~ _
  with { loop(cnt) = ba.if(t > 0.0, duration, max(0.0, cnt - 1.0)); };
  ```
- **Feedback Gating**: Gate the feedback loop with `*(exciteActive == 0.0)` so the feedback path is disabled during the excitation burst — prevents residual delay-line content from interfering with the new note.
- **Avoid `select2` chains**: The Faust compiler v2.37.3 inverts `select2` branches in the generated C++. Use arithmetic sums (e.g., `(cond) * a + (1-cond) * b`) or `ba.if` instead.
- **Per-string counter**: Each string needs its own independent counter (inside `pluckExcitation` or `jivariString`'s `with` block) to generate frequency-dependent excitation durations from the lookup table.

## 24. Strict Relative Path Enforcement

- **Rule**: NEVER use absolute file paths in code under any circumstances, not even for temporary testing, logging, or asset resolution.
- **Protocol**: ALL paths MUST be relative to the dynamic execution workspace or derived from configured asset base paths (e.g., `./assets/libraries`).
- **Why?**: Hardcoded absolute paths tightly couple the source code to local workstation environments, breaking CI/CD pipelines, multi-platform runtime isolation, and cross-machine collaborative workflows.

## 26. Explicit User Consent for Code Changes

- **Rule**: DO NOT touch the code or make any code changes (especially DSP) without getting explicit permission from the user first.
- **Protocol**: Always present the exact code change or idea, and WAIT for the user to explicitly say "do it" or approve it before executing any file modification.
- **Why?**: Unapproved changes, even seemingly trivial ones, can severely disrupt the acoustic balance, overwrite delicate physical modeling parameters, or break the user's intended workflow.
