echo "| Instrument | freq | velocity | pressure | strike | position |"
echo "|---|---|---|---|---|---|"
for f in assets/dsp/*.dsp; do
    inst=$(basename "$f" .dsp)
    
    has_freq="-"
    has_velocity="-"
    has_pressure="-"
    has_strike="-"
    has_position="-"
    
    if grep -q -i "hslider.*freq" "$f"; then has_freq="✅"; fi
    if grep -q -i "hslider.*velocity" "$f"; then has_velocity="✅"; fi
    if grep -q -iE "hslider.*pressure" "$f"; then has_pressure="✅"; fi
    if grep -q -i "hslider.*strike" "$f"; then has_strike="✅"; fi
    if grep -q -iE "hslider.*position" "$f"; then has_position="✅"; fi
    
    # special handling for ai_flute
    if grep -q -i "hslider.*ai_pressure" "$f"; then has_pressure="✅"; fi
    
    echo "| \`$inst\` | $has_freq | $has_velocity | $has_pressure | $has_strike | $has_position |"
done
