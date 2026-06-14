#!/bin/bash
gh issue create --title "Testing Polyphone Support" --body "Thoroughly test the new multi-voice polyphony implementation for stability under heavy chord loads."
gh issue create --title "Add Polyphony in Piano and Guitars" --body "Extend native polyphonic support to Piano, ElectricGuitar, and BassGuitar instrument models."
gh issue create --title "Support Different Playing Techniques in Bass Guitar" --body "Support enhanced playing techniques for the Bass Guitar model, specifically focusing on strikes."
gh issue create --title "Support Strike Techniques in All Guitars" --body "Support different playing techniques across all guitar models (e.g., hitting with fingers, pull and release with finger). Document these specific techniques and assign a standardized strike number to each for the LUT mapping."
gh issue create --title "Support Enhanced Playing Techniques" --body "Support enhanced playing techniques universally across all physical models and instruments."
gh issue create --title "Enhanced Mixer Chaining (Parallel/Serial)" --body "Enhance the mixer architecture to support chaining various DSP elements like echo, bandpass filters, etc., in both parallel and serial configurations."
