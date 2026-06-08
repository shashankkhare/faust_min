# Publishing Guide for FaustMin

Follow these steps to safely publish a new version of the project:

## 1. Disable Debug Mode
Before compiling a release build, ensure that debug logging is disabled.
- Open the relevant source files (e.g., `src/FaustInstrument.cpp`).
- Comment out any `#define DEBUG` macros.
- Example: `// #define DEBUG`

## 2. Clean and Rebuild
Ensure there are no lingering artifacts from previous debug builds by doing a completely fresh compile of the entire project.
```bash
make clean
make -C build
```

## 3. Version Bump
Determine the scope of the recent changes to pump up the version number:
- **Major/Significant Changes:** Increment the version by **0.1** (e.g., v1.1 -> v1.2) if you added large features, new DSP instruments, or major architecture refactors.
- **Minor Changes:** Increment the version by **0.01** (e.g., v1.10 -> v1.11) if the changes were mostly bug fixes, LUT adjustments, or minor optimizations.

*Update the version number in your build scripts, CMakeLists.txt, or wherever the version is officially tracked.*

## 4. Update Documentation
Check if the `README.md` needs to be altered to reflect the new changes. 
- Are there new features the user needs to know about?
- Did any configuration or CSV formats (like the LUT format) change?
- Update the `README.md` accordingly before committing.

## 5. Commit and Push
If the clean compilation was successful and the program runs as expected, commit and push the changes to the repository.
```bash
git add .
git commit -m "Bump version to vX.X: [Brief description of changes]"
git push origin main
```
