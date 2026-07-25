#!/bin/bash
# validate_version.sh — Enforce versioning rules before publishing
# RULES:
#   - Minor release: +0.1 MAX (e.g., 0.4.0 → 0.5.0)
#   - Major release: +1.0.0 (e.g., 0.5.0 → 1.0.0)
#   - Patch release: +1 (e.g., 0.5.0 → 0.5.1)

set -e

PUBSPEC="pubspec.yaml"
CHANGELOG="CHANGELOG.md"

if [ ! -f "$PUBSPEC" ]; then
    echo "ERROR: $PUBSPEC not found"
    exit 1
fi

# Extract version from pubspec.yaml
CURRENT_VERSION=$(grep '^version:' "$PUBSPEC" | awk '{print $2}' | tr -d '[:space:]')

if [ -z "$CURRENT_VERSION" ]; then
    echo "ERROR: Could not read version from $PUBSPEC"
    exit 1
fi

echo "Current version in pubspec.yaml: $CURRENT_VERSION"

# Extract major, minor, patch
MAJOR=$(echo "$CURRENT_VERSION" | cut -d. -f1)
MINOR=$(echo "$CURRENT_VERSION" | cut -d. -f2)
PATCH=$(echo "$CURRENT_VERSION" | cut -d. -f3)

# Check for forbidden versions (too high)
if [ "$MAJOR" -gt 10 ]; then
    echo "ERROR: Major version $MAJOR is suspiciously high. Max major is 10. Found version: $CURRENT_VERSION"
    echo "       Did you mean 0.$MAJOR.0 or similar?"
    exit 1
fi

# Check CHANGELOG has matching version entry
if [ -f "$CHANGELOG" ]; then
    if ! grep -q "^## $CURRENT_VERSION" "$CHANGELOG"; then
        echo "ERROR: CHANGELOG.md does not have a matching '## $CURRENT_VERSION' entry"
        echo "       Found entries:"
        grep "^## " "$CHANGELOG" | head -5
        exit 1
    fi
fi

echo "Version validation PASSED: $CURRENT_VERSION"
echo ""
echo "Versioning rules:"
echo "  Minor: +0.1 MAX (e.g., 0.4.0 → 0.5.0)"
echo "  Major: +1.0.0   (e.g., 0.5.0 → 1.0.0)"
echo "  Patch: +1       (e.g., 0.5.0 → 0.5.1)"
echo ""
echo "Current: $CURRENT_VERSION"
echo "  Major: $MAJOR"
echo "  Minor: $MINOR"
echo "  Patch: $PATCH"
